########################################
# cimHWSim library
add_library(cimHWSim SHARED
cimHWOp.cc
cimHWSimulator.cc
conv.cc
gemm.cc
diagnostic/diagEngine.cc
factory/abstractOpFactory.cc
factory/cimHWOpFactory.cc
hardware/BitlineReceiver.cc
hardware/ComputeUnit.cc
hardware/CrossBarArray.cc
hardware/CrossBarUnit.cc
hardware/WordLineDriver.cc
wrapper/fastSimWrapper.cc
)
# add needed headers and lib
target_include_directories(cimHWSim PUBLIC
  ${CIMHWSIM_BASE}/include
  ${CIMHWSIM_BASE}/external
)
## pack fastsim source into cimHWSim and include needed headers
  # set up skysim/fastsim
  set(FASTSIM_NAME      fastsim)
  set(FASTSIM_SRCDIR    ${SKYSIM_BASE}/${FASTSIM_NAME})
  target_include_directories(cimHWSim PRIVATE
    ${SKYSIM_INC_DIR}
    ${ONNC_RT_INC_DIR}
  )
  target_sources(cimHWSim PRIVATE
    ${FASTSIM_SRCDIR}/operator.cc
  )
## end of pack fastsim

## linking variables
add_dependencies(cimHWSim ${ONNC_RT_NAME})
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  target_link_libraries(cimHWSim PUBLIC ${ONNC_RT_LIB} OpenMP::OpenMP_CXX)
else()
  target_link_libraries(cimHWSim ${ONNC_RT_LIB})
endif()

########################################
# install essentials as library
file(GLOB_RECURSE PUBLIC_HEADER_FILES ${CIMHWSIM_BASE}/include/*.hh)
set_target_properties(cimHWSim PROPERTIES
  SOVERSION     "${LIB_MAJOR_VERSION}.${LIB_MINOR_VERSION}"
  VERSION       "${LIB_MAJOR_VERSION}.${LIB_MINOR_VERSION}.${LIB_PATCH_VERSION}"
  PUBLIC_HEADER "${PUBLIC_HEADER_FILES}"
)
install(TARGETS cimHWSim
   LIBRARY       DESTINATION lib
   RUNTIME       DESTINATION lib
   ARCHIVE       DESTINATION lib
   PUBLIC_HEADER DESTINATION include
)