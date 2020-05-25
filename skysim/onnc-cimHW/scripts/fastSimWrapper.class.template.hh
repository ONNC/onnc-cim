class fastsim${OperatorName}Op : public cimHWOp {
public:
fastsim${OperatorName}Op(
	void* context
	${input_parameters_float}
	${output_parameters_float}
	${attribute_paprameters_float}
);

virtual void simulate() override;

private:
${OperatorName}Op m_op;
};