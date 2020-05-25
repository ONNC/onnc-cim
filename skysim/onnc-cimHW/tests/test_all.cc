#include "configFile.hh"
#include <gtest/gtest.h>

std::string configFilePath;

int main(int argc, char **argv) {
  if(argc != 2)
  {
    std::cout << "Usage: ./test_all <cimConfigFile>" << std::endl;
    exit(1);
  }
  configFilePath = argv[1];
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS();
}
