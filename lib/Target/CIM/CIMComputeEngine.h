//===- CIMComputeEngine.h -----------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <onnc/Runtime/ComputeEngine.h>
#include <onnc/Support/Path.h>
#include <cimHWSimulator.hh>
#include <string>

namespace onnc {

class CIMComputeEngine : public ComputeEngine
{
public:
  explicit CIMComputeEngine(const onnc::Path &configFilePath) noexcept;
public:
  void compute(const Initializer& co) override;
  void compute(const InputOperator& co) override;
  void compute(const OutputOperator& co) override;

  void compute(const Abs& pAbs) override;
  void compute(const Acos& pAcos) override;
  void compute(const Add& pAdd) override;
  void compute(const And& pAnd) override;
  void compute(const ArgMax& pArgMax) override;
  void compute(const ArgMin& pArgMin) override;
  void compute(const Asin& pAsin) override;
  void compute(const Atan& pAtan) override;
  void compute(const AveragePool& pAveragePool) override;
  void compute(const BatchNormalization& pBatchNormalization) override;
  void compute(const Cast& pCast) override;
  void compute(const Ceil& pCeil) override;
  void compute(const Clip& pClip) override;
  void compute(const Concat& pConcat) override;
  void compute(const Constant& pConstant) override;
  void compute(const Conv& pConv) override;
  void compute(const ConvTranspose& pConvTranspose) override;
  void compute(const Cos& pCos) override;
  void compute(const DepthToSpace& pDepthToSpace) override;
  void compute(const Div& pDiv) override;
  void compute(const Dropout& pDropout) override;
  void compute(const Elu& pElu) override;
  void compute(const Equal& pEqual) override;
  void compute(const Exp& pExp) override;
  void compute(const Expand& pExpand) override;
  void compute(const Flatten& pFlatten) override;
  void compute(const Floor& pFloor) override;
  void compute(const GRU& pGRU) override;
  void compute(const Gather& pGather) override;
  void compute(const Gemm& pGemm) override;
  void compute(const GlobalAveragePool& pGlobalAveragePool) override;
  void compute(const GlobalLpPool& pGlobalLpPool) override;
  void compute(const GlobalMaxPool& pGlobalMaxPool) override;
  void compute(const Greater& pGreater) override;
  void compute(const HardSigmoid& pHardSigmoid) override;
  void compute(const Hardmax& pHardmax) override;
  void compute(const Identity& pIdentity) override;
  void compute(const InstanceNormalization& pInstanceNormalization) override;
  void compute(const LRN& pLRN) override;
  void compute(const LSTM& pLSTM) override;
  void compute(const LeakyRelu& pLeakyRelu) override;
  void compute(const Less& pLess) override;
  void compute(const Log& pLog) override;
  void compute(const LogSoftmax& pLogSoftmax) override;
  void compute(const LpNormalization& pLpNormalization) override;
  void compute(const LpPool& pLpPool) override;
  void compute(const MatMul& pMatMul) override;
  void compute(const Max& pMax) override;
  void compute(const MaxPool& pMaxPool) override;
  void compute(const MaxRoiPool& pMaxRoiPool) override;
  void compute(const Mean& pMean) override;
  void compute(const Min& pMin) override;
  void compute(const Mul& pMul) override;
  void compute(const Multinomial& pMultinomial) override;
  void compute(const Neg& pNeg) override;
  void compute(const Not& pNot) override;
  void compute(const Or& pOr) override;
  void compute(const PRelu& pPRelu) override;
  void compute(const Pad& pPad) override;
  void compute(const Pow& pPow) override;
  void compute(const RNN& pRNN) override;
  void compute(const RandomNormal& pRandomNormal) override;
  void compute(const RandomNormalLike& pRandomNormalLike) override;
  void compute(const RandomUniform& pRandomUniform) override;
  void compute(const RandomUniformLike& pRandomUniformLike) override;
  void compute(const Reciprocal& pReciprocal) override;
  void compute(const ReduceL1& pReduceL1) override;
  void compute(const ReduceL2& pReduceL2) override;
  void compute(const ReduceLogSum& pReduceLogSum) override;
  void compute(const ReduceLogSumExp& pReduceLogSumExp) override;
  void compute(const ReduceMax& pReduceMax) override;
  void compute(const ReduceMean& pReduceMean) override;
  void compute(const ReduceMin& pReduceMin) override;
  void compute(const ReduceProd& pReduceProd) override;
  void compute(const ReduceSum& pReduceSum) override;
  void compute(const ReduceSumSquare& pReduceSumSquare) override;
  void compute(const Relu& pRelu) override;
  void compute(const Reshape& pReshape) override;
  void compute(const Selu& pSelu) override;
  void compute(const Shape& pShape) override;
  void compute(const Sigmoid& pSigmoid) override;
  void compute(const Sin& pSin) override;
  void compute(const Size& pSize) override;
  void compute(const Slice& pSlice) override;
  void compute(const Softmax& pSoftmax) override;
  void compute(const Softplus& pSoftplus) override;
  void compute(const Softsign& pSoftsign) override;
  void compute(const SpaceToDepth& pSpaceToDepth) override;
  void compute(const Split& pSplit) override;
  void compute(const Sqrt& pSqrt) override;
  void compute(const Squeeze& pSqueeze) override;
  void compute(const Sub& pSub) override;
  void compute(const Sum& pSum) override;
  void compute(const Tan& pTan) override;
  void compute(const Tanh& pTanh) override;
  void compute(const Tile& pTile) override;
  void compute(const TopK& pTopK) override;
  void compute(const Transpose& pTranspose) override;
  void compute(const Unsqueeze& pUnsqueeze) override;
  void compute(const Upsample& pUpsample) override;
  void compute(const Xor& pXor) override;
  void compute(const ATen& pATen) override;
  void compute(const Affine& pAffine) override;
  void compute(const ConstantFill& pConstantFill) override;
  void compute(const Crop& pCrop) override;
  void compute(const GRUUnit& pGRUUnit) override;
  void compute(const GivenTensorFill& pGivenTensorFill) override;
  void compute(const ImageScaler& pImageScaler) override;
  void compute(const MeanVarianceNormalization& pMeanVarianceNormalization) override;
  void compute(const ParametricSoftplus& pParametricSoftplus) override;
  void compute(const Scale& pScale) override;
  void compute(const ScaledTanh& pScaledTanh) override;
  void compute(const ThresholdedRelu& pThresholdedRelu) override;
  
private:
  // cim backend related options
  cimHW::cimHWSimulator m_cimSim;
  onnc::Path            m_configFilePath;
  // end of cim backend related options
};

} // namespace onnc