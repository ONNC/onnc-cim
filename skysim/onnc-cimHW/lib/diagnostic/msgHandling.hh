//===- msgHandling.hh -----------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <iostream>
#include <string>
#include "diagEngine.hh"

namespace cimHW {

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

inline void error      (const std::string &message)
{
  DiagEngine::getEngine().report(DiagEngine::LevelType::Error, message);
}

inline void warning    (const std::string &message)
{
  DiagEngine::getEngine().report(DiagEngine::LevelType::Warning, message);
}

inline void info       (const std::string &message)
{
  DiagEngine::getEngine().report(DiagEngine::LevelType::Info, message);
}

inline void verbose1   (const std::string &message)
{
  DiagEngine::getEngine().report(DiagEngine::LevelType::Verbose1, message);
}

inline void verbose2   (const std::string &message)
{
  DiagEngine::getEngine().report(DiagEngine::LevelType::Verbose2, message);
}

} // namespace cimHW