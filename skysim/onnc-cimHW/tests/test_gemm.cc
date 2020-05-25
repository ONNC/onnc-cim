#include <gtest/gtest.h>
#include <vector>
#include <gemm.hh>
#include "configFile.hh"
using namespace std;

namespace cimHW_test {

using namespace cimHW;

struct cimHWGemmOpAndTestAttributes {
	element_type alpha;
	element_type beta;
	dim_type transA;
	dim_type transB;
};

void TestcimHWGemmOp(cimHWGemmOpAndTestAttributes& attributes,
                    const vector<vector<element_type>>& inputs,
                    const vector<vector<dim_type>>& input_shapes,
                    const vector<element_type>& expected_output,
                    const vector<dim_type>& expected_output_shape,
                    const unsigned int IL_A_ = 4, const unsigned int FL_A_ = 4,
                    const unsigned int IL_B_ = 4, const unsigned int FL_B_ = 4,
                    const float expected_min_diff = 0.1
                    )
{

  const_element_type *intput_A = inputs[0].data();
  const_dim_type input_A_ndim = input_shapes[0].size();
  const_dim_type *input_A_shape = input_shapes[0].data();

  const_element_type *intput_B = inputs[1].data();
  const_dim_type input_B_ndim = input_shapes[1].size();
  const_dim_type *input_B_shape = input_shapes[1].data();

  const_element_type *intput_C = nullptr;
  dim_type input_C_ndim = 0;
  dim_type *input_C_shape = nullptr;
  if(inputs.size() == 3)
  {
    intput_C = const_cast<element_type*>(inputs[2].data());
    input_C_ndim = input_shapes[2].size();
    input_C_shape = const_cast<dim_type*>(input_shapes[2].data());
  }

  const_dim_type output_Y_ndim = expected_output_shape.size();
  const_dim_type *output_Y_shape = expected_output_shape.data();
  size_t output_Y_size = output_Y_shape[0];
  for(int i=1;i<output_Y_ndim;i++)
    output_Y_size *= output_Y_shape[i];
  vector<element_type> output_Y(output_Y_size, 0);

 	cimHWGemmOp op(
    configFilePath,
		intput_A, input_A_ndim, input_A_shape,
		intput_B, input_B_ndim, input_B_shape,
		intput_C, input_C_ndim, input_C_shape,
		output_Y.data(), output_Y_ndim, output_Y_shape,
		attributes.alpha, attributes.beta,
    attributes.transA, attributes.transB
    );
	op.simulate();

  // check if the number of dimensions equals
  ASSERT_TRUE(output_Y_ndim == expected_output_shape.size());
  // check every dims
  for (size_t d = 0; d < output_Y_ndim; ++d) {
      ASSERT_EQ(output_Y_shape[d], expected_output_shape[d])
          << "dim = " << d;
  }
  // check the content within a given of certain diff
  for (size_t d = 0; d < output_Y_ndim; ++d) {
      EXPECT_LE((output_Y[d] - expected_output[d]) * (output_Y[d] - expected_output[d]),
                expected_min_diff * expected_min_diff)
          << "diff = " << output_Y[d] - expected_output[d];
  }
  //EXPECT_EQ(output_Y, expected_output);
}

} // namespace

using namespace cimHW_test;

TEST(GemmTest, SimpleQuantize) {
  cimHWGemmOpAndTestAttributes attrs = {
      1.0,    // alpha
      1.0,    // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.5, 1.0, 0.5
  };
  vector<dim_type> A_shape = {1, 3};

  vector<element_type> B = {
 		 1.0,
 		 1.0,
 		 1.0
  };
  vector<dim_type> B_shape = {3, 1};

  vector<dim_type> expected_shape = {1, 1};
  vector<element_type> expected_vals = {
    3.0
  };

  TestcimHWGemmOp(attrs, {A, B}, {A_shape, B_shape}, expected_vals, expected_shape);
}

TEST(GemmTest, ComplexQuantize1) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
    1.0, 1.0, 1.0
  };
  vector<dim_type> A_shape = {1, 3};

  vector<element_type> B = {
    -0.5918,  0.1812,
    -1.7068, -0.3433,
    -0.1470, -1.1139
  };
  vector<dim_type> B_shape = {3, 2};

  vector<element_type> C = {
 		 0.0
  };
  vector<dim_type> C_shape = {1, 1};

  vector<dim_type> expected_shape = {1, 2};
  vector<element_type> expected_vals = {
    -2.4456, -1.276
  };

  TestcimHWGemmOp(attrs, {A, B, C}, {A_shape, B_shape, C_shape}, expected_vals, expected_shape,
                  16, 16, 16, 16);
}

TEST(GemmTest, ComplexQuantize2) {
  cimHWGemmOpAndTestAttributes attrs = {
      1.0,    // alpha
      1.0,    // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 0.3, 1.7, 0.9
  };
  vector<dim_type> A_shape = {1, 3};

  vector<element_type> B = {
 		 1.0,
 		 0.2,
 		 1.3
  };
  vector<dim_type> B_shape = {3, 1};

  vector<dim_type> expected_shape = {1, 1};
  vector<element_type> expected_vals = {
    1.81
  };

  TestcimHWGemmOp(attrs, {A, B}, {A_shape, B_shape}, expected_vals, expected_shape,
                  16, 16, 16, 16);
}

TEST(GemmTest, Without_C_Matrix) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    13, 10.0,
    13, 10.0
  };

  TestcimHWGemmOp(attrs, {A, B}, {A_shape, B_shape }, expected_vals, expected_shape);
}

TEST(GemmTest, Transpose1) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      1,      // transA
      0       // transB
  };

  vector<element_type> A = {
    1.0, 1.0,
    1.0, 1.0,
    3.0, 3.0,
    1.0, 1.0,
    1.0, 1.0,
    3.0, 3.0
  };
  vector<dim_type> A_shape = {6, 2};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    13, 10.0,
    13, 10.0
  };

  TestcimHWGemmOp(attrs, {A, B}, {A_shape, B_shape }, expected_vals, expected_shape);
}

TEST(GemmTest, Transpose2) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      1       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
    1.0, 1.0, 1.0, 3.0, 2.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0
  };
  vector<dim_type> B_shape = {2, 6};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    13, 10.0,
    13, 10.0
  };

  TestcimHWGemmOp(attrs, {A, B}, {A_shape, B_shape }, expected_vals, expected_shape);
}

TEST(GemmTest, With_C_Matrix1) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<element_type> C = {
 		 1.0
  };
  vector<dim_type> C_shape = {1, 1};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    14, 11.0,
    14, 11.0
  };

  TestcimHWGemmOp(attrs, {A, B, C}, {A_shape, B_shape, C_shape}, expected_vals, expected_shape);
}

TEST(GemmTest, With_C_Matrix2) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<element_type> C = {
 		 1.0, 2.0
  };
  vector<dim_type> C_shape = {1, 2};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    14, 12.0,
    14, 12.0
  };

  TestcimHWGemmOp(attrs, {A, B, C}, {A_shape, B_shape, C_shape}, expected_vals, expected_shape);
}

TEST(GemmTest, With_C_Matrix3) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<element_type> C = {
 		 1.0,
     3.1
  };
  vector<dim_type> C_shape = {2, 1};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    14.0, 11.0,
    16.1, 13.1
  };

  TestcimHWGemmOp(attrs, {A, B, C}, {A_shape, B_shape, C_shape}, expected_vals, expected_shape);
}

TEST(GemmTest, With_C_Matrix4) {
  cimHWGemmOpAndTestAttributes attrs = {
      1,      // alpha
      1,      // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<element_type> C = {
 		 1.0, 2.0,
     3.1, 0.1
  };
  vector<dim_type> C_shape = {2, 2};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    14.0, 12.0,
    16.1, 10.1
  };

  TestcimHWGemmOp(attrs, {A, B, C}, {A_shape, B_shape, C_shape}, expected_vals, expected_shape);
}

TEST(GemmTest, With_alpha_beta) {
  cimHWGemmOpAndTestAttributes attrs = {
      1.2,    // alpha
      0.5,    // beta
      0,      // transA
      0       // transB
  };

  vector<element_type> A = {
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0,
 		 1.0, 1.0, 3.0, 1.0, 1.0, 3.0
  };
  vector<dim_type> A_shape = {2, 6};

  vector<element_type> B = {
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 1.0, 1.0,
 		 3.0, 1.0,
 		 2.0, 1.0,
 		 1.0, 1.0
  };
  vector<dim_type> B_shape = {6, 2};

  vector<element_type> C = {
 		 1.0, 2.0,
     3.1, 0.1
  };
  vector<dim_type> C_shape = {2, 2};

  vector<dim_type> expected_shape = {2, 2};
  vector<element_type> expected_vals = {
    16.1, 13.0,
    17.15, 12.05
  };

  TestcimHWGemmOp(attrs, {A, B, C}, {A_shape, B_shape, C_shape}, expected_vals, expected_shape);
}