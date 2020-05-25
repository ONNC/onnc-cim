//===- diagEngine.cc ------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "diagEngine.hh"
#include <iostream>

namespace cimHW {

DiagEngine::DiagEngine() noexcept
{
  // defautl verbose level -- none
  setVerboseLevel(0);
}

DiagEngine& DiagEngine::getEngine()
{
  // singleton pattern
  static DiagEngine instance;
  return instance;
}

void DiagEngine::setVerboseLevel(const unsigned level)
{
  // the lowest level of verbose to display in enum
  m_verboseLevel = LevelType::Verbose1 + level;
}

void DiagEngine::report(const LevelType level, const std::string &message) const
{
  // dispatch to various LevelType
  switch(level)
  {
    case Error:
      std::cerr << "Error: " << message << std::endl;
      std::exit(EXIT_FAILURE);
      break;
    case Warning:
      std::cout << "Warning: " << message << std::endl;
      break;
    case Info:
      std::cout << "Info: " << message << std::endl;
      break;
    case Verbose1:
    case Verbose2:
      if(level < m_verboseLevel)
        std::cout << message << std::flush;
      break;
    default:
    // do nothing
    ;
  }
}

} // namesapce cimHW
