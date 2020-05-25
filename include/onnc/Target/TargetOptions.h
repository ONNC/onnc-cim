//===- TargetOptions.h ---------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_TARGET_TARGET_OPTIONS_H
#define ONNC_TARGET_TARGET_OPTIONS_H

#include <onnc/Support/Path.h>

#include <string>
#include <utility>

namespace onnc {
namespace nvdla {

enum class ConfigSet : unsigned
{
  nv_full = 0,
};

enum class ExecutionMode : unsigned
{
  direct = 0,
};

} // namespace nvdla

enum class RunMode : unsigned
{
  normal = 0,
};

/** \class TargetOptions
 *  \brief TargetOptions stores settings of a compiler
 */
class TargetOptions
{
public:
  TargetOptions()                           = default;
  TargetOptions(const TargetOptions& pCopy) = default;

  TargetOptions& operator=(const TargetOptions& pCopy) = default;

  /// The property holds whether printing module before tensor selection
  bool shouldPrintBeforeTensorSel() const { return m_PrintModuleBeforeSel; }

  void printBeforeTensorSel(bool pEnable = true) { m_PrintModuleBeforeSel = pEnable; }

  /// This property holds whether ignoring calibration step
  bool shouldIgnoreCalibrationStep() const { return m_IgnoreCalibrationStep; }

  void ignoreCalibrationStep(bool pEnable = true) {
    m_IgnoreCalibrationStep = pEnable;
  }

  /// This property holds whether adding dummy CTable
  bool shouldUseDummyCTable() const { return m_AddDummyCTable; }

  void useDummyCTable(bool pEnable = true) { m_AddDummyCTable = pEnable; }

  /// This property holds whether adding dummy weight
  bool shouldUseDummyWeight() const { return m_AddDummyWeight; }

  void useDummyWeight(bool pEnable = true) { m_AddDummyWeight = pEnable; }

  /// This property holds the output file name for optimized onnx model
  /// in backend
  std::string optOnnxModel() const { return m_OptOnnxModel; }

  void optOnnxModel(std::string pFileName) { m_OptOnnxModel = pFileName; }

  unsigned getVerboseLevel() const noexcept { return m_VerboseLevel; }

  void setVerboseLevel(unsigned verboseLevel) noexcept { m_VerboseLevel = verboseLevel; }

  // cim backend related methods
  void setCIMRunInterpreter(bool bEnable) noexcept { m_cim_run_interpreter = bEnable; }
  bool getCIMRunInterpreter() const noexcept { return m_cim_run_interpreter; }

  void setCIMInterpreterInput(const onnc::Path& pFilePath) noexcept { m_cim_interpreter_input = pFilePath; }
  const onnc::Path& getCIMInterpreterInput() const noexcept { return m_cim_interpreter_input; }

  static constexpr const char* CIMInterpreterDefaultOutputName = "out.tsr";
  void setCIMInterpreterOutput(const onnc::Path& pFilePath) noexcept { m_cim_interpreter_output = pFilePath; }
  const onnc::Path& getCIMInterpreterOutput() const noexcept { return m_cim_interpreter_output; }

  void setCIMConfig(const onnc::Path& pFilePath) noexcept { m_cim_config = pFilePath; }
  const onnc::Path& getCIMConfig() const noexcept { return m_cim_config; }
  // end of cim backend related methods

private:
  bool        m_PrintModuleBeforeSel  = false;
  bool        m_IgnoreCalibrationStep = false;
  bool        m_AddDummyCTable        = false;
  bool        m_AddDummyWeight        = false;
  unsigned    m_VerboseLevel          = 0;
  std::string m_OptOnnxModel          = "";

  // cim backend related options
  bool        m_cim_run_interpreter         = false;
  onnc::Path  m_cim_interpreter_input;
  onnc::Path  m_cim_interpreter_output      = CIMInterpreterDefaultOutputName;
  onnc::Path  m_cim_config                  = "";
  // end of cim backend related options
};

} // namespace onnc

#endif
