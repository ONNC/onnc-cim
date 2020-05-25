### application or test
# Now simply link unitest against cimHWSim and gtest
add_executable(test_all "")
file(GLOB TEST_CPP_FILES *.cc)
target_sources(test_all
  PRIVATE ${TEST_CPP_FILES}
)
target_include_directories(test_all PRIVATE
  ${CIMHWSIM_BASE}/lib
)
target_link_libraries(test_all cimHWSim gtest)
# the installation path
#install(TARGETS test_all
#  RUNTIME  DESTINATION bin
#)
