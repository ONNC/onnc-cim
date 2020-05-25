//===- types.hh -----------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <Eigen/Dense>

namespace cimHW {

// basic element type
typedef unsigned int bitType;
typedef float numType;

// matrix with bitType
typedef Eigen::Matrix<bitType, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> MatrixXuiRowMajor;
typedef Eigen::Matrix<bitType, 1, Eigen::Dynamic, Eigen::RowMajor> RowVectorXui;
typedef Eigen::Matrix<bitType, Eigen::Dynamic, 1> VectorXui;

// matrix with numType
typedef Eigen::Matrix<numType, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> MatrixXfRowMajor;
typedef Eigen::Matrix<numType, 1, Eigen::Dynamic, Eigen::RowMajor> RowVectorXf;
typedef Eigen::Matrix<numType, Eigen::Dynamic, 1> VectorXnum;

} //namespace cimHW
