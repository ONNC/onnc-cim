//===- ComputeEngine.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once

#include <onnc/Diagnostic/MsgHandling.h>
#include <onnc/IR/Compute/ATen.h>
#include <onnc/IR/Compute/Abs.h>
#include <onnc/IR/Compute/Acos.h>
#include <onnc/IR/Compute/Add.h>
#include <onnc/IR/Compute/Affine.h>
#include <onnc/IR/Compute/And.h>
#include <onnc/IR/Compute/ArgMax.h>
#include <onnc/IR/Compute/ArgMin.h>
#include <onnc/IR/Compute/Asin.h>
#include <onnc/IR/Compute/Atan.h>
#include <onnc/IR/Compute/AveragePool.h>
#include <onnc/IR/Compute/BatchNormalization.h>
#include <onnc/IR/Compute/Cast.h>
#include <onnc/IR/Compute/Ceil.h>
#include <onnc/IR/Compute/Clip.h>
#include <onnc/IR/Compute/Concat.h>
#include <onnc/IR/Compute/Constant.h>
#include <onnc/IR/Compute/ConstantFill.h>
#include <onnc/IR/Compute/Conv.h>
#include <onnc/IR/Compute/ConvTranspose.h>
#include <onnc/IR/Compute/Cos.h>
#include <onnc/IR/Compute/Crop.h>
#include <onnc/IR/Compute/DepthToSpace.h>
#include <onnc/IR/Compute/Div.h>
#include <onnc/IR/Compute/Dropout.h>
#include <onnc/IR/Compute/Elu.h>
#include <onnc/IR/Compute/Equal.h>
#include <onnc/IR/Compute/Exp.h>
#include <onnc/IR/Compute/Expand.h>
#include <onnc/IR/Compute/Flatten.h>
#include <onnc/IR/Compute/Floor.h>
#include <onnc/IR/Compute/GRU.h>
#include <onnc/IR/Compute/GRUUnit.h>
#include <onnc/IR/Compute/Gather.h>
#include <onnc/IR/Compute/Gemm.h>
#include <onnc/IR/Compute/GivenTensorFill.h>
#include <onnc/IR/Compute/GlobalAveragePool.h>
#include <onnc/IR/Compute/GlobalLpPool.h>
#include <onnc/IR/Compute/GlobalMaxPool.h>
#include <onnc/IR/Compute/Greater.h>
#include <onnc/IR/Compute/HardSigmoid.h>
#include <onnc/IR/Compute/Hardmax.h>
#include <onnc/IR/Compute/Identity.h>
#include <onnc/IR/Compute/ImageScaler.h>
#include <onnc/IR/Compute/Initializer.h>
#include <onnc/IR/Compute/InputOperator.h>
#include <onnc/IR/Compute/InstanceNormalization.h>
#include <onnc/IR/Compute/LRN.h>
#include <onnc/IR/Compute/LSTM.h>
#include <onnc/IR/Compute/LeakyRelu.h>
#include <onnc/IR/Compute/Less.h>
#include <onnc/IR/Compute/Log.h>
#include <onnc/IR/Compute/LogSoftmax.h>
#include <onnc/IR/Compute/LpNormalization.h>
#include <onnc/IR/Compute/LpPool.h>
#include <onnc/IR/Compute/MatMul.h>
#include <onnc/IR/Compute/Max.h>
#include <onnc/IR/Compute/MaxPool.h>
#include <onnc/IR/Compute/MaxRoiPool.h>
#include <onnc/IR/Compute/Mean.h>
#include <onnc/IR/Compute/MeanVarianceNormalization.h>
#include <onnc/IR/Compute/Min.h>
#include <onnc/IR/Compute/Mul.h>
#include <onnc/IR/Compute/Multinomial.h>
#include <onnc/IR/Compute/Neg.h>
#include <onnc/IR/Compute/Not.h>
#include <onnc/IR/Compute/Or.h>
#include <onnc/IR/Compute/OutputOperator.h>
#include <onnc/IR/Compute/PRelu.h>
#include <onnc/IR/Compute/Pad.h>
#include <onnc/IR/Compute/ParametricSoftplus.h>
#include <onnc/IR/Compute/Pow.h>
#include <onnc/IR/Compute/RNN.h>
#include <onnc/IR/Compute/RandomNormal.h>
#include <onnc/IR/Compute/RandomNormalLike.h>
#include <onnc/IR/Compute/RandomUniform.h>
#include <onnc/IR/Compute/RandomUniformLike.h>
#include <onnc/IR/Compute/Reciprocal.h>
#include <onnc/IR/Compute/ReduceL1.h>
#include <onnc/IR/Compute/ReduceL2.h>
#include <onnc/IR/Compute/ReduceLogSum.h>
#include <onnc/IR/Compute/ReduceLogSumExp.h>
#include <onnc/IR/Compute/ReduceMax.h>
#include <onnc/IR/Compute/ReduceMean.h>
#include <onnc/IR/Compute/ReduceMin.h>
#include <onnc/IR/Compute/ReduceProd.h>
#include <onnc/IR/Compute/ReduceSum.h>
#include <onnc/IR/Compute/ReduceSumSquare.h>
#include <onnc/IR/Compute/Relu.h>
#include <onnc/IR/Compute/Reshape.h>
#include <onnc/IR/Compute/Scale.h>
#include <onnc/IR/Compute/ScaledTanh.h>
#include <onnc/IR/Compute/Selu.h>
#include <onnc/IR/Compute/Shape.h>
#include <onnc/IR/Compute/Sigmoid.h>
#include <onnc/IR/Compute/Sin.h>
#include <onnc/IR/Compute/Size.h>
#include <onnc/IR/Compute/Slice.h>
#include <onnc/IR/Compute/Softmax.h>
#include <onnc/IR/Compute/Softplus.h>
#include <onnc/IR/Compute/Softsign.h>
#include <onnc/IR/Compute/SpaceToDepth.h>
#include <onnc/IR/Compute/Split.h>
#include <onnc/IR/Compute/Sqrt.h>
#include <onnc/IR/Compute/Squeeze.h>
#include <onnc/IR/Compute/Sub.h>
#include <onnc/IR/Compute/Sum.h>
#include <onnc/IR/Compute/Tan.h>
#include <onnc/IR/Compute/Tanh.h>
#include <onnc/IR/Compute/ThresholdedRelu.h>
#include <onnc/IR/Compute/Tile.h>
#include <onnc/IR/Compute/TopK.h>
#include <onnc/IR/Compute/Transpose.h>
#include <onnc/IR/Compute/Unsqueeze.h>
#include <onnc/IR/Compute/Upsample.h>
#include <onnc/IR/Compute/Xor.h>
#include <onnc/IR/ComputeOperator.h>

namespace onnc {

class ComputeEngine
{
public:
  typedef std::unordered_map<const Value*, void*> AddressTable;
  AddressTable                                    m_ATable;
  void*                                           m_pContext;

public:
  virtual ~ComputeEngine() = default;

public:
  // Default assertion when invoking undefined operators
  virtual void defaultHandler(const ComputeOperator& co)
  {
    fatal(no_support_compute) << co.name();
  }

  // By default, no inference is needed in these operators
  virtual void compute(const Initializer& co) { this->defaultHandler(co); }
  virtual void compute(const InputOperator& co) { this->defaultHandler(co); }
  virtual void compute(const OutputOperator& co) { this->defaultHandler(co); }

  // By default, these are the operators must be defined
  virtual void compute(const Add& co) { this->defaultHandler(co); }
  virtual void compute(const AveragePool& co) { this->defaultHandler(co); }
  virtual void compute(const BatchNormalization& co) { this->defaultHandler(co); }
  virtual void compute(const Concat& co) { this->defaultHandler(co); }
  virtual void compute(const Conv& co) { this->defaultHandler(co); }
  virtual void compute(const Gemm& co) { this->defaultHandler(co); }
  virtual void compute(const GlobalAveragePool& co) { this->defaultHandler(co); }
  virtual void compute(const LRN& co) { this->defaultHandler(co); }
  virtual void compute(const MaxPool& co) { this->defaultHandler(co); }
  virtual void compute(const Mul& co) { this->defaultHandler(co); }
  virtual void compute(const Relu& co) { this->defaultHandler(co); }
  virtual void compute(const Reshape& co) { this->defaultHandler(co); }
  virtual void compute(const Softmax& co) { this->defaultHandler(co); }
  virtual void compute(const Sum& co) { this->defaultHandler(co); }
  virtual void compute(const Transpose& co) { this->defaultHandler(co); }
  virtual void compute(const Unsqueeze& co) { this->defaultHandler(co); }

  // others operator
  virtual void compute(const Abs& co) { this->defaultHandler(co); }
  virtual void compute(const Acos& co) { this->defaultHandler(co); }
  virtual void compute(const And& co) { this->defaultHandler(co); }
  virtual void compute(const ArgMax& co) { this->defaultHandler(co); }
  virtual void compute(const ArgMin& co) { this->defaultHandler(co); }
  virtual void compute(const Asin& co) { this->defaultHandler(co); }
  virtual void compute(const Atan& co) { this->defaultHandler(co); }
  virtual void compute(const Cast& co) { this->defaultHandler(co); }
  virtual void compute(const Ceil& co) { this->defaultHandler(co); }
  virtual void compute(const Clip& co) { this->defaultHandler(co); }
  virtual void compute(const Constant& co) { this->defaultHandler(co); }
  virtual void compute(const ConvTranspose& co) { this->defaultHandler(co); }
  virtual void compute(const Cos& co) { this->defaultHandler(co); }
  virtual void compute(const DepthToSpace& co) { this->defaultHandler(co); }
  virtual void compute(const Div& co) { this->defaultHandler(co); }
  virtual void compute(const Dropout& co) { this->defaultHandler(co); }
  virtual void compute(const Elu& co) { this->defaultHandler(co); }
  virtual void compute(const Equal& co) { this->defaultHandler(co); }
  virtual void compute(const Exp& co) { this->defaultHandler(co); }
  virtual void compute(const Expand& co) { this->defaultHandler(co); }
  virtual void compute(const Flatten& co) { this->defaultHandler(co); }
  virtual void compute(const Floor& co) { this->defaultHandler(co); }
  virtual void compute(const GRU& co) { this->defaultHandler(co); }
  virtual void compute(const Gather& co) { this->defaultHandler(co); }
  virtual void compute(const GlobalLpPool& co) { this->defaultHandler(co); }
  virtual void compute(const GlobalMaxPool& co) { this->defaultHandler(co); }
  virtual void compute(const Greater& co) { this->defaultHandler(co); }
  virtual void compute(const HardSigmoid& co) { this->defaultHandler(co); }
  virtual void compute(const Hardmax& co) { this->defaultHandler(co); }
  virtual void compute(const Identity& co) { this->defaultHandler(co); }
  virtual void compute(const InstanceNormalization& co) { this->defaultHandler(co); }
  virtual void compute(const LSTM& co) { this->defaultHandler(co); }
  virtual void compute(const LeakyRelu& co) { this->defaultHandler(co); }
  virtual void compute(const Less& co) { this->defaultHandler(co); }
  virtual void compute(const Log& co) { this->defaultHandler(co); }
  virtual void compute(const LogSoftmax& co) { this->defaultHandler(co); }
  virtual void compute(const LpNormalization& co) { this->defaultHandler(co); }
  virtual void compute(const LpPool& co) { this->defaultHandler(co); }
  virtual void compute(const MatMul& co) { this->defaultHandler(co); }
  virtual void compute(const Max& co) { this->defaultHandler(co); }
  virtual void compute(const MaxRoiPool& co) { this->defaultHandler(co); }
  virtual void compute(const Mean& co) { this->defaultHandler(co); }
  virtual void compute(const Min& co) { this->defaultHandler(co); }
  virtual void compute(const Multinomial& co) { this->defaultHandler(co); }
  virtual void compute(const Neg& co) { this->defaultHandler(co); }
  virtual void compute(const Not& co) { this->defaultHandler(co); }
  virtual void compute(const Or& co) { this->defaultHandler(co); }
  virtual void compute(const PRelu& co) { this->defaultHandler(co); }
  virtual void compute(const Pad& co) { this->defaultHandler(co); }
  virtual void compute(const Pow& co) { this->defaultHandler(co); }
  virtual void compute(const RNN& co) { this->defaultHandler(co); }
  virtual void compute(const RandomNormal& co) { this->defaultHandler(co); }
  virtual void compute(const RandomNormalLike& co) { this->defaultHandler(co); }
  virtual void compute(const RandomUniform& co) { this->defaultHandler(co); }
  virtual void compute(const RandomUniformLike& co) { this->defaultHandler(co); }
  virtual void compute(const Reciprocal& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceL1& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceL2& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceLogSum& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceLogSumExp& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceMax& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceMean& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceMin& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceProd& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceSum& co) { this->defaultHandler(co); }
  virtual void compute(const ReduceSumSquare& co) { this->defaultHandler(co); }
  virtual void compute(const Selu& co) { this->defaultHandler(co); }
  virtual void compute(const Shape& co) { this->defaultHandler(co); }
  virtual void compute(const Sigmoid& co) { this->defaultHandler(co); }
  virtual void compute(const Sin& co) { this->defaultHandler(co); }
  virtual void compute(const Size& co) { this->defaultHandler(co); }
  virtual void compute(const Slice& co) { this->defaultHandler(co); }
  virtual void compute(const Softplus& co) { this->defaultHandler(co); }
  virtual void compute(const Softsign& co) { this->defaultHandler(co); }
  virtual void compute(const SpaceToDepth& co) { this->defaultHandler(co); }
  virtual void compute(const Split& co) { this->defaultHandler(co); }
  virtual void compute(const Sqrt& co) { this->defaultHandler(co); }
  virtual void compute(const Squeeze& co) { this->defaultHandler(co); }
  virtual void compute(const Sub& co) { this->defaultHandler(co); }
  virtual void compute(const Tan& co) { this->defaultHandler(co); }
  virtual void compute(const Tanh& co) { this->defaultHandler(co); }
  virtual void compute(const Tile& co) { this->defaultHandler(co); }
  virtual void compute(const TopK& co) { this->defaultHandler(co); }
  virtual void compute(const Upsample& co) { this->defaultHandler(co); }
  virtual void compute(const Xor& co) { this->defaultHandler(co); }
  virtual void compute(const ATen& co) { this->defaultHandler(co); }
  virtual void compute(const Affine& co) { this->defaultHandler(co); }
  virtual void compute(const ConstantFill& co) { this->defaultHandler(co); }
  virtual void compute(const Crop& co) { this->defaultHandler(co); }
  virtual void compute(const GRUUnit& co) { this->defaultHandler(co); }
  virtual void compute(const GivenTensorFill& co) { this->defaultHandler(co); }
  virtual void compute(const ImageScaler& co) { this->defaultHandler(co); }
  virtual void compute(const MeanVarianceNormalization& co) { this->defaultHandler(co); }
  virtual void compute(const ParametricSoftplus& co) { this->defaultHandler(co); }
  virtual void compute(const Scale& co) { this->defaultHandler(co); }
  virtual void compute(const ScaledTanh& co) { this->defaultHandler(co); }
  virtual void compute(const ThresholdedRelu& co) { this->defaultHandler(co); }
};

} // namespace onnc