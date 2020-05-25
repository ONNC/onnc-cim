//===- ComputeUnit.cc -----------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "ComputeUnit.hh"
#include "../diagnostic/msgHandling.hh"
#include <fstream>
#include <exception>

namespace cimHW {

ComputeUnit::ComputeUnit(const std::string &configFilePath) noexcept
{
  // load main config, it must exist
  std::ifstream configFile(configFilePath);
  std::string   errorModelFile;
  if(configFile.is_open())
  {
    verbose2(std::string("CIM Config: " + configFilePath + "\n"));
    m_cimConfig = std::make_unique<nlohmann::json>();
    configFile >> *m_cimConfig;

    try {
      // load all cim devide related parameters
      m_xbarNum       = (*m_cimConfig)["xbarNum"];
      m_OUSize        = (*m_cimConfig)["xbarSize"]["OUSize"];
      m_wordlines     = (*m_cimConfig)["xbarSize"]["wordlines"];
      m_xIntegerLen   = (*m_cimConfig)["QuantizeLength"]["X"]["Int"];
      m_xFractionLen  = (*m_cimConfig)["QuantizeLength"]["X"]["Fraction"];
      m_wIntegerLen   = (*m_cimConfig)["QuantizeLength"]["W"]["Int"];
      m_wFractionLen  = (*m_cimConfig)["QuantizeLength"]["W"]["Fraction"];
      m_Verbose       = (*m_cimConfig)["Verbose"];
      errorModelFile  = (*m_cimConfig)["ErrorModel"];
    }
    catch(const std::exception& e)
    {
      error(std::string("CIM Config file parsed error: ") + e.what());
    }

    // set verbose level
    DiagEngine::getEngine().setVerboseLevel(m_Verbose);

    // load errorModel if there exists
    std::size_t found  = configFilePath.find_last_of("/\\");
    std::string folder;
    if(found != std::string::npos)
      folder = configFilePath.substr(0,found+1);
    std::ifstream jsonFile(folder + errorModelFile);
    if(errorModelFile.size() != 0 && jsonFile.is_open())
    {
      verbose2(std::string("Error Model: " + folder + errorModelFile + "\n"));
      m_errorTable = std::make_shared<nlohmann::json>();
      jsonFile >> *m_errorTable;
    }
    else
      m_errorTable.reset();

    // allocate CrossBarUnit
    m_xBarUnits.reserve(m_xbarNum);
    for(int i=0; i<m_xbarNum; i++)
    {
      m_xBarUnits.push_back(std::make_unique<CrossBarUnit>(
                      m_wordlines, m_errorTable,
                      m_xIntegerLen, m_xFractionLen,
                      m_wIntegerLen, m_wFractionLen));
    }
  }
  else
    error("could not load cim config file");
}

#pragma omp declare reduction (+: RowVectorXf: omp_out=omp_out+omp_in)\
     initializer(omp_priv=RowVectorXf::Zero(omp_orig.size()))

RowVectorXf ComputeUnit::compute(const MatrixXfRowMajor &data, const VectorXnum &kernel)
{
  verbose1(".");
  unsigned kernelSize = kernel.size();
  // Iterate to rewrite cell if a compute unit is not enough for one time
  RowVectorXf result = RowVectorXf::Zero(data.cols());
  for(unsigned cuBase=0; cuBase<kernelSize; cuBase += getMaxWordLine())
  {
    // distribute to all xbar units
    #pragma omp parallel for reduction(+:result)
    for(unsigned ixbar = 0; ixbar<m_xbarNum; ixbar++)
    {
      auto base = cuBase + ixbar*m_wordlines;
      // check if all element are dispatched already, break is not allowed in openmp, use flag instead
      bool flag = true;
      if(base >= kernelSize)
        flag = false;
      if(flag)
      {
        // check if the last step
        auto width = (base + m_wordlines > kernelSize)? (kernelSize-base):m_wordlines;
        m_xBarUnits[ixbar]->setCell(kernel.segment(base, width));
        result += m_xBarUnits[ixbar]->compute(data.block(base, 0, width, data.cols()), m_OUSize);
      }
    }
  }
  return result;
}

unsigned ComputeUnit::getMaxWordLine()
{
  return m_xbarNum * m_wordlines;
}

} // namespace cimHW