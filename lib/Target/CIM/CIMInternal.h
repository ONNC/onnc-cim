//===- CIMInternal.h ------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// interprete related, need to be refactored in the future
#include "InterpreterPass.h"

#include <onnc/ADT/Color.h>
#include <onnc/Config/ONNX.h>
#include <onnc/Support/Path.h>
#include <onnc/Transforms/OnnxOptPass.h>

#include <cstring>
#include <fstream>

namespace onnc {
namespace cim_internal {

class TensorReadResult
{
public:
  TensorReadResult() noexcept
    : m_Success{false}
    , m_Data{}
    , m_Length{0}
  {}

  TensorReadResult(std::unique_ptr<char[]> pData, std::size_t pLength) noexcept
    : m_Success{true}
    , m_Data{std::move(pData)}
    , m_Length{pLength}
  {}

  TensorReadResult(TensorReadResult&&) = default;

  operator bool() const noexcept { return m_Success; }

  const bool              m_Success;
  std::unique_ptr<char[]> m_Data;
  const std::size_t       m_Length;
};

class TensorWriteProxy
{
public:
  TensorWriteProxy() noexcept
    : m_HasFilePath{false}
    , m_FilePath{}
  {}

  explicit TensorWriteProxy(Path pFilePath) noexcept
    : m_HasFilePath{true}
    , m_FilePath{std::move(pFilePath)}
  {}

  TensorWriteProxy(const TensorWriteProxy&) = default;
  TensorWriteProxy(TensorWriteProxy&&)      = default;

  bool operator()(const Tensor& pTensor, const void* pData) const
  {
    assert(pTensor.kind() == Value::Type::kFloat);
    assert(pData != nullptr);

    const auto* const pValues = reinterpret_cast<const float*>(pData);
    if (!m_HasFilePath) {
      return writeTensorToStdout(pTensor, pValues);
    }

    return writeTensorToFile(pTensor, pValues);
  }

private:
  bool writeTensorToStdout(const Tensor& pTensor, const float* pValues) const
  {
    outs() << '[';
    for (std::size_t idx = 0; idx < getTensorSize(pTensor); ++idx) {
      outs() << std::fixed << pValues[idx] << ", ";
    }
    outs() << ']' << std::endl;

    return true;
  }

  bool writeTensorToFile(const Tensor& pTensor, const float* pValues) const
  {
    std::ofstream stream{m_FilePath.native()};
    if (!stream.is_open()) {
      errs() << Color::MAGENTA << "Fatal" << Color::RESET << ": cannot open file to write: " << m_FilePath << std::endl;
      return false;
    }

    xTensorProto writer;

    writer.set_data_type(xTensorProto::FLOAT);
    for (const auto dimension : pTensor.getDimensions()) {
      writer.add_dims(dimension);
    }

    writer.set_raw_data(pValues, getTensorSize(pTensor) * sizeof(*pValues));

    if (!writer.SerializeToOstream(&stream)) {
      errs() << Color::MAGENTA << "Fatal" << Color::RESET << ": fail to write content to file: " << m_FilePath
             << std::endl;
      return false;
    }

    return true;
  }

  static std::size_t getTensorSize(const Tensor& pTensor)
  {
    std::size_t size = 1;
    for (const auto dimension : pTensor.getDimensions()) {
      size *= dimension;
    }

    return size;
  }

private:
  const bool m_HasFilePath;
  const Path m_FilePath;
};

void enableOnnxOptmization(PassManager& passManager)
{
  using Option = OnnxOptPass::Option;

  OnnxOptPass pass;
  pass.add(Option::extract_constant_to_initializer)
    .add(Option::fuse_add_bias_into_conv)
    .add(Option::fuse_bn_into_conv)
    .add(Option::fuse_consecutive_squeezes)
    .add(Option::fuse_consecutive_transposes)
    .add(Option::fuse_transpose_into_gemm)
    .add(Option::eliminate_identity)
    .add(Option::eliminate_nop_pad)
    .add(Option::eliminate_nop_transpose)
    .add(Option::eliminate_unused_initializer);

  passManager.add<OnnxOptPass>(std::move(pass));
}

TensorReadResult readTensor(const Path& pFilePath)
{
  if (!exists(pFilePath)) {
    errs() << Color::MAGENTA << "Fatal" << Color::RESET << ": input file not found: " << pFilePath << std::endl;
    return TensorReadResult{};
  }

  if (!is_regular(pFilePath)) {
    errs() << Color::MAGENTA << "Fatal" << Color::RESET << ": input file is not a regular file: " << pFilePath
           << std::endl;
    return TensorReadResult{};
  }

  std::ifstream stream(pFilePath.native());
  if (!stream.is_open()) {
    errs() << Color::MAGENTA << "Fatal" << Color::RESET << ": cannot open file file: " << pFilePath << std::endl;
    return TensorReadResult{};
  }

  xTensorProto reader;
  reader.ParseFromIstream(&stream);

  assert(reader.has_data_type() && reader.data_type() == xTensorProto::FLOAT);

  const auto& rawData = reader.raw_data();
  const auto  length  = rawData.length();

  auto data = std::make_unique<char[]>(length);
  std::memcpy(data.get(), rawData.data(), length);

  return TensorReadResult{std::move(data), length};
}

} // namespace cim_internal
} // namespace onnc
