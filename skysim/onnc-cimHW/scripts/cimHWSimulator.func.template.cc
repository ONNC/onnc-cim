void cimHWSimulator::cimHW_${OperatorName}_float(
  void* context
  ${input_parameters_float}
  ${output_parameters_float}
  ${attribute_paprameters_float}
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->create${OperatorName}Op(
  context
  ${visitor_pass_input}
  ${visitor_pass_output}
  ${visitor_pass_attribute}
);
if(op != nullptr)
  op->simulate();
}