virtual std::unique_ptr<cimHWOp> create${OperatorName}Op(
  void* context
  ${input_parameters_float}
  ${output_parameters_float}
  ${attribute_paprameters_float}
);