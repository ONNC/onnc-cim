//===- Interpreter.h ------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once

#include <onnc/IR/ComputeMemOperand.h>
#include <onnc/IR/ComputeVisitor.h>
#include <onnc/IR/CustomVisitor.h>
#include <onnc/Runtime/BasicComputeEngine.h>
#include <onnc/Runtime/ComputeEngine.h>

namespace onnc {

template <typename OperatorVisitorT = ComputeVisitor>
class InterpreterVisitor : public CustomVisitor<InterpreterVisitor<OperatorVisitorT>, OperatorVisitorT>
{
private:
  std::unique_ptr<ComputeEngine> m_pComputeEngine;

public:
  explicit InterpreterVisitor(std::unique_ptr<ComputeEngine> pEngine) noexcept
    : m_pComputeEngine(std::move(pEngine))
  {}
  ComputeEngine& getComputeEngine() { return *m_pComputeEngine; }

  void visit(Abs& pAbs) override { m_pComputeEngine->compute(pAbs); }
  void visit(Acos& pAcos) override { m_pComputeEngine->compute(pAcos); }
  void visit(Add& pAdd) override { m_pComputeEngine->compute(pAdd); }
  void visit(And& pAnd) override { m_pComputeEngine->compute(pAnd); }
  void visit(ArgMax& pArgMax) override { m_pComputeEngine->compute(pArgMax); }
  void visit(ArgMin& pArgMin) override { m_pComputeEngine->compute(pArgMin); }
  void visit(Asin& pAsin) override { m_pComputeEngine->compute(pAsin); }
  void visit(Atan& pAtan) override { m_pComputeEngine->compute(pAtan); }
  void visit(AveragePool& pAveragePool) override { m_pComputeEngine->compute(pAveragePool); }
  void visit(BatchNormalization& pBatchNormalization) override { m_pComputeEngine->compute(pBatchNormalization); }
  void visit(Cast& pCast) override { m_pComputeEngine->compute(pCast); }
  void visit(Ceil& pCeil) override { m_pComputeEngine->compute(pCeil); }
  void visit(Clip& pClip) override { m_pComputeEngine->compute(pClip); }
  void visit(Concat& pConcat) override { m_pComputeEngine->compute(pConcat); }
  void visit(Constant& pConstant) override { m_pComputeEngine->compute(pConstant); }
  void visit(Conv& pConv) override { m_pComputeEngine->compute(pConv); }
  void visit(ConvTranspose& pConvTranspose) override { m_pComputeEngine->compute(pConvTranspose); }
  void visit(Cos& pCos) override { m_pComputeEngine->compute(pCos); }
  void visit(DepthToSpace& pDepthToSpace) override { m_pComputeEngine->compute(pDepthToSpace); }
  void visit(Div& pDiv) override { m_pComputeEngine->compute(pDiv); }
  void visit(Dropout& pDropout) override { m_pComputeEngine->compute(pDropout); }
  void visit(Elu& pElu) override { m_pComputeEngine->compute(pElu); }
  void visit(Equal& pEqual) override { m_pComputeEngine->compute(pEqual); }
  void visit(Exp& pExp) override { m_pComputeEngine->compute(pExp); }
  void visit(Expand& pExpand) override { m_pComputeEngine->compute(pExpand); }
  void visit(Flatten& pFlatten) override { m_pComputeEngine->compute(pFlatten); }
  void visit(Floor& pFloor) override { m_pComputeEngine->compute(pFloor); }
  void visit(GRU& pGRU) override { m_pComputeEngine->compute(pGRU); }
  void visit(Gather& pGather) override { m_pComputeEngine->compute(pGather); }
  void visit(Gemm& pGemm) override { m_pComputeEngine->compute(pGemm); }
  void visit(GlobalAveragePool& pGlobalAveragePool) override { m_pComputeEngine->compute(pGlobalAveragePool); }
  void visit(GlobalLpPool& pGlobalLpPool) override { m_pComputeEngine->compute(pGlobalLpPool); }
  void visit(GlobalMaxPool& pGlobalMaxPool) override { m_pComputeEngine->compute(pGlobalMaxPool); }
  void visit(Greater& pGreater) override { m_pComputeEngine->compute(pGreater); }
  void visit(HardSigmoid& pHardSigmoid) override { m_pComputeEngine->compute(pHardSigmoid); }
  void visit(Hardmax& pHardmax) override { m_pComputeEngine->compute(pHardmax); }
  void visit(Identity& pIdentity) override { m_pComputeEngine->compute(pIdentity); }
  void visit(InstanceNormalization& pInstanceNormalization) override
  {
    m_pComputeEngine->compute(pInstanceNormalization);
  }
  void visit(LRN& pLRN) override { m_pComputeEngine->compute(pLRN); }
  void visit(LSTM& pLSTM) override { m_pComputeEngine->compute(pLSTM); }
  void visit(LeakyRelu& pLeakyRelu) override { m_pComputeEngine->compute(pLeakyRelu); }
  void visit(Less& pLess) override { m_pComputeEngine->compute(pLess); }
  void visit(Log& pLog) override { m_pComputeEngine->compute(pLog); }
  void visit(LogSoftmax& pLogSoftmax) override { m_pComputeEngine->compute(pLogSoftmax); }
  void visit(LpNormalization& pLpNormalization) override { m_pComputeEngine->compute(pLpNormalization); }
  void visit(LpPool& pLpPool) override { m_pComputeEngine->compute(pLpPool); }
  void visit(MatMul& pMatMul) override { m_pComputeEngine->compute(pMatMul); }
  void visit(Max& pMax) override { m_pComputeEngine->compute(pMax); }
  void visit(MaxPool& pMaxPool) override { m_pComputeEngine->compute(pMaxPool); }
  void visit(MaxRoiPool& pMaxRoiPool) override { m_pComputeEngine->compute(pMaxRoiPool); }
  void visit(Mean& pMean) override { m_pComputeEngine->compute(pMean); }
  void visit(Min& pMin) override { m_pComputeEngine->compute(pMin); }
  void visit(Mul& pMul) override { m_pComputeEngine->compute(pMul); }
  void visit(Multinomial& pMultinomial) override { m_pComputeEngine->compute(pMultinomial); }
  void visit(Neg& pNeg) override { m_pComputeEngine->compute(pNeg); }
  void visit(Not& pNot) override { m_pComputeEngine->compute(pNot); }
  void visit(Or& pOr) override { m_pComputeEngine->compute(pOr); }
  void visit(PRelu& pPRelu) override { m_pComputeEngine->compute(pPRelu); }
  void visit(Pad& pPad) override { m_pComputeEngine->compute(pPad); }
  void visit(Pow& pPow) override { m_pComputeEngine->compute(pPow); }
  void visit(RNN& pRNN) override { m_pComputeEngine->compute(pRNN); }
  void visit(RandomNormal& pRandomNormal) override { m_pComputeEngine->compute(pRandomNormal); }
  void visit(RandomNormalLike& pRandomNormalLike) override { m_pComputeEngine->compute(pRandomNormalLike); }
  void visit(RandomUniform& pRandomUniform) override { m_pComputeEngine->compute(pRandomUniform); }
  void visit(RandomUniformLike& pRandomUniformLike) override { m_pComputeEngine->compute(pRandomUniformLike); }
  void visit(Reciprocal& pReciprocal) override { m_pComputeEngine->compute(pReciprocal); }
  void visit(ReduceL1& pReduceL1) override { m_pComputeEngine->compute(pReduceL1); }
  void visit(ReduceL2& pReduceL2) override { m_pComputeEngine->compute(pReduceL2); }
  void visit(ReduceLogSum& pReduceLogSum) override { m_pComputeEngine->compute(pReduceLogSum); }
  void visit(ReduceLogSumExp& pReduceLogSumExp) override { m_pComputeEngine->compute(pReduceLogSumExp); }
  void visit(ReduceMax& pReduceMax) override { m_pComputeEngine->compute(pReduceMax); }
  void visit(ReduceMean& pReduceMean) override { m_pComputeEngine->compute(pReduceMean); }
  void visit(ReduceMin& pReduceMin) override { m_pComputeEngine->compute(pReduceMin); }
  void visit(ReduceProd& pReduceProd) override { m_pComputeEngine->compute(pReduceProd); }
  void visit(ReduceSum& pReduceSum) override { m_pComputeEngine->compute(pReduceSum); }
  void visit(ReduceSumSquare& pReduceSumSquare) override { m_pComputeEngine->compute(pReduceSumSquare); }
  void visit(Relu& pRelu) override { m_pComputeEngine->compute(pRelu); }
  void visit(Reshape& pReshape) override { m_pComputeEngine->compute(pReshape); }
  void visit(Selu& pSelu) override { m_pComputeEngine->compute(pSelu); }
  void visit(Shape& pShape) override { m_pComputeEngine->compute(pShape); }
  void visit(Sigmoid& pSigmoid) override { m_pComputeEngine->compute(pSigmoid); }
  void visit(Sin& pSin) override { m_pComputeEngine->compute(pSin); }
  void visit(Size& pSize) override { m_pComputeEngine->compute(pSize); }
  void visit(Slice& pSlice) override { m_pComputeEngine->compute(pSlice); }
  void visit(Softmax& pSoftmax) override { m_pComputeEngine->compute(pSoftmax); }
  void visit(Softplus& pSoftplus) override { m_pComputeEngine->compute(pSoftplus); }
  void visit(Softsign& pSoftsign) override { m_pComputeEngine->compute(pSoftsign); }
  void visit(SpaceToDepth& pSpaceToDepth) override { m_pComputeEngine->compute(pSpaceToDepth); }
  void visit(Split& pSplit) override { m_pComputeEngine->compute(pSplit); }
  void visit(Sqrt& pSqrt) override { m_pComputeEngine->compute(pSqrt); }
  void visit(Squeeze& pSqueeze) override { m_pComputeEngine->compute(pSqueeze); }
  void visit(Sub& pSub) override { m_pComputeEngine->compute(pSub); }
  void visit(Sum& pSum) override { m_pComputeEngine->compute(pSum); }
  void visit(Tan& pTan) override { m_pComputeEngine->compute(pTan); }
  void visit(Tanh& pTanh) override { m_pComputeEngine->compute(pTanh); }
  void visit(Tile& pTile) override { m_pComputeEngine->compute(pTile); }
  void visit(TopK& pTopK) override { m_pComputeEngine->compute(pTopK); }
  void visit(Transpose& pTranspose) override { m_pComputeEngine->compute(pTranspose); }
  void visit(Unsqueeze& pUnsqueeze) override { m_pComputeEngine->compute(pUnsqueeze); }
  void visit(Upsample& pUpsample) override { m_pComputeEngine->compute(pUpsample); }
  void visit(Xor& pXor) override { m_pComputeEngine->compute(pXor); }
  void visit(ATen& pATen) override { m_pComputeEngine->compute(pATen); }
  void visit(Affine& pAffine) override { m_pComputeEngine->compute(pAffine); }
  void visit(ConstantFill& pConstantFill) override { m_pComputeEngine->compute(pConstantFill); }
  void visit(Crop& pCrop) override { m_pComputeEngine->compute(pCrop); }
  void visit(GRUUnit& pGRUUnit) override { m_pComputeEngine->compute(pGRUUnit); }
  void visit(GivenTensorFill& pGivenTensorFill) override { m_pComputeEngine->compute(pGivenTensorFill); }
  void visit(ImageScaler& pImageScaler) override { m_pComputeEngine->compute(pImageScaler); }
  void visit(MeanVarianceNormalization& pMeanVarianceNormalization) override
  {
    m_pComputeEngine->compute(pMeanVarianceNormalization);
  }
  void visit(ParametricSoftplus& pParametricSoftplus) override { m_pComputeEngine->compute(pParametricSoftplus); }
  void visit(Scale& pScale) override { m_pComputeEngine->compute(pScale); }
  void visit(ScaledTanh& pScaledTanh) override { m_pComputeEngine->compute(pScaledTanh); }
  void visit(ThresholdedRelu& pThresholdedRelu) override { m_pComputeEngine->compute(pThresholdedRelu); }
};

/** \class Interpreter
 *  \brief Interpreter dispatch compute ir to runtime.
 */
class Interpreter
{
protected:
  explicit Interpreter(std::unique_ptr<ComputeVisitor> pIV) noexcept
    : m_pIV(std::move(pIV))
  {}

public:
  Interpreter() noexcept
    : Interpreter(std::make_unique<InterpreterVisitor<>>(std::make_unique<BasicComputeEngine>()))
  {}
  explicit Interpreter(std::unique_ptr<ComputeEngine> pEngine) noexcept
    : Interpreter(std::make_unique<InterpreterVisitor<>>(std::move(pEngine)))
  {}
  Interpreter(Interpreter&) = delete;
  virtual ~Interpreter()    = default;

  // XXX(a127a127):
  //   Temporary hack, should use something like "Context" or "Environment",
  //   should not expose Interpreter visitor implementation.
  virtual ComputeEngine& getComputeEngine()
  {
    auto p_IV = static_cast<InterpreterVisitor<>*>(m_pIV.get());
    return p_IV->getComputeEngine();
  }

  ComputeVisitor& getVisitor() { return *m_pIV; }

private:
  std::unique_ptr<ComputeVisitor> m_pIV;
};

} // namespace onnc