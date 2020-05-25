# This script is only for help to build for ONNC
# Automatically build and copy bin files to designated folder
# Not recommend for other purpose

CIMHWSIM_BUILD_DIR=/onnc/skysim/cimHWSim/build.docker
CIMHWSIM_INSTALL_DIR=${CIMHWSIM_BUILD_DIR}/install
ONNC_CIMHWSIM_PATH=/onnc/onnc/lib/Target/CIM/cimHWSim
NOW_WHERE=`pwd`

# change to build directory
if [ ! -d ${CIMHWSIM_BUILD_DIR} ]
then
  echo "Directory ${CIMHWSIM_BUILD_DIR} doesn't exist"
  exit 1 # die with error code 1
fi
cd ${CIMHWSIM_BUILD_DIR}

# clean destination to ensure latest version after copy
rm -rf ${ONNC_CIMHWSIM_PATH}
rm -rf ${CIMHWSIM_INSTALL_DIR}

# start build bin
make -j8 install

# copy bin to designated folder
mkdir -p ${ONNC_CIMHWSIM_PATH}
cp -a ${CIMHWSIM_INSTALL_DIR}/include ${ONNC_CIMHWSIM_PATH}
cp -a ${CIMHWSIM_INSTALL_DIR}/lib ${ONNC_CIMHWSIM_PATH}
cp -a ${CIMHWSIM_INSTALL_DIR}/share ${ONNC_CIMHWSIM_PATH}

# switch back the folder where starts at
cd ${NOW_WHERE}
