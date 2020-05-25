# the installation path
install(DIRECTORY ./
  DESTINATION ${CMAKE_BINARY_DIR}/share
  PATTERN     "CMakeLists.txt" EXCLUDE     
)