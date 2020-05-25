std::unique_ptr<cimHWOp> AbstractOpFactory::create${OperatorName}Op(
  void* context
  ${input_parameters_float}
  ${output_parameters_float}
  ${attribute_paprameters_float}
)
{
return std::make_unique<fastsim${OperatorName}Op>(
  context
  ${visitor_pass_input}
  ${visitor_pass_output}
  ${visitor_pass_attribute}
);
}