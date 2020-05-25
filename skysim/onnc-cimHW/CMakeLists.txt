########################################
# Project information
set(LIB_MAJOR_VERSION "0")
set(LIB_MINOR_VERSION "1")
set(LIB_PATCH_VERSION "0")
set(LIB_VERSION_STRING "${LIB_MAJOR_VERSION}.${LIB_MINOR_VERSION}.${LIB_PATCH_VERSION}")
cmake_minimum_required(VERSION 3.10.2)
cmake_policy(SET CMP0048 NEW)
project(cimHWSim VERSION ${LIB_VERSION_STRING} LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)


########################################
# Main building setting starts here
# set base name to cimHWSim
set(CIMHWSIM_BASE     ${CMAKE_CURRENT_LIST_DIR})
# set base name to skysim
set(SKYSIM_BASE       ${CIMHWSIM_BASE}/..)
set(SKYSIM_INC_DIR    ${SKYSIM_BASE}/include)


########################################
# External libraries
# set up onnc, need onnc src path
set(ONNC_RT_NAME        onnc-rt)
set(ONNC_RT_LIBNAME     lib${ONNC_RT_NAME}.a)
set(ONNC_RT_SRCDIR      ${SKYSIM_BASE}/..)
# if(NOT DEFINED ONNC_RT_SRCDIR)
#   message(FATAL_ERROR   "ONNC's source path must be specifed via ONNC_RT_SRCDIR")
# endif(NOT DEFINED ONNC_RT_SRCDIR)
set(ONNC_RT_BIN_DIR     ${CMAKE_CURRENT_BINARY_DIR}/${ONNC_RT_NAME})
set(ONNC_RT_INST_PREFIX install)
set(ONNC_RT_INC_DIR     ${ONNC_RT_BIN_DIR}/${ONNC_RT_INST_PREFIX}/include/onnc/Runtime)
set(ONNC_RT_LIB         ${ONNC_RT_BIN_DIR}/${ONNC_RT_INST_PREFIX}/lib/${ONNC_RT_LIBNAME})
file(MAKE_DIRECTORY     ${ONNC_RT_BIN_DIR})
add_custom_command(
  OUTPUT                ${ONNC_RT_LIB}
  COMMAND               ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${ONNC_RT_INST_PREFIX} -DCMAKE_BUILD_TYPE=Release -DONNC_RT_ONLY=ON ${ONNC_RT_SRCDIR}
  COMMAND               ${CMAKE_MAKE_PROGRAM} install
  WORKING_DIRECTORY     ${ONNC_RT_BIN_DIR}
  COMMENT               "Building library ${ONNC_RT_NAME}"
)
add_custom_target(      ${ONNC_RT_NAME}
  DEPENDS               ${ONNC_RT_LIB}
)


########################################
# cimHWSim libraries
# build cimHWSim library target
add_subdirectory(lib)
# cimHWSim examples, a.k.a. stand-alone mode
add_subdirectory(example)
# cimHWSim share
add_subdirectory(share)


########################################
# cimHWSim tests
# default not build
option(BUILD_TESTS "Builds the cimHWSim tests" OFF)
if(BUILD_TESTS)
  # Download and unpack googletest at configure time
  configure_file(googletest_CMakeLists.txt.in googletest-download/CMakeLists.txt)
  execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
  if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
  endif()
  execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
  if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
  endif()
  # Add googletest directly to our build. This defines
  # the gtest and gtest_main targets.
  add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                   ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                   EXCLUDE_FROM_ALL
  )
  # add tests subdirectory
  add_subdirectory(tests)
endif(BUILD_TESTS)