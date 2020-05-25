fastsim${OperatorName}Op::fastsim${OperatorName}Op(
	void* context
	${input_parameters_float}
	${output_parameters_float}
	${attribute_paprameters_float}
)
: cimHWOp("${OperatorName}")
, m_op(
	${visitor_pass_fastsim_argument})
{
}

void fastsim${OperatorName}Op::simulate()
{
	m_op.inference();
}