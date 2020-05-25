//===- diagEngine.hh ------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <string>

namespace cimHW {

class DiagEngine {
public:
  enum LevelType {
    Error,
    Warning,
    Info,
    Verbose1,
    Verbose2,
  };

public:
  DiagEngine() noexcept;
  DiagEngine(DiagEngine&) = delete;
  void operator=(const DiagEngine &) = delete;

  static DiagEngine&  getEngine();
  void                setVerboseLevel(const unsigned level);
  void                report(const LevelType level, const std::string &message) const;

private:
  unsigned            m_verboseLevel;
};

} // namespace cimHW