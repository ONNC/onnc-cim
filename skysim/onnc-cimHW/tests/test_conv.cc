#include <vector>
#include <gtest/gtest.h>
#include <conv.hh>
#include "configFile.hh"

using namespace std;

namespace cimHW_test {

using namespace cimHW;

struct cimHWConvOpAndTestAttributes {
  string auto_pad;
  vector<dim_type> dilations;
  dim_type group;
  vector<dim_type> kernel_shape;
  vector<dim_type> pads;
  vector<dim_type> strides;
};

void TestcimHWConvOp(cimHWConvOpAndTestAttributes& attributes,
                    const vector<vector<element_type>>& inputs,
                    const vector<vector<dim_type>>& input_shapes,
                    const vector<element_type>& expected_output,
                    const vector<dim_type>& expected_output_shape,
                    const unsigned int IL_X_ = 8, const unsigned int FL_X_ = 0,
		                const unsigned int IL_W_ = 8, const unsigned int FL_W_ = 0)
{

  const_element_type *intput_X = inputs[0].data();
  const_dim_type input_X_ndim = input_shapes[0].size();
  const_dim_type *input_X_shape = input_shapes[0].data();

  const_element_type *intput_W = inputs[1].data();
  const_dim_type input_W_ndim = input_shapes[1].size();
  const_dim_type *input_W_shape = input_shapes[1].data();

  element_type *intput_B = nullptr;
  dim_type input_B_ndim = 0;
  dim_type *input_B_shape = nullptr;
  if(inputs.size() == 3)
  {
    intput_B = const_cast<element_type*>(inputs[2].data());
    input_B_ndim = input_shapes[2].size();
    input_B_shape = const_cast<dim_type*>(input_shapes[2].data());
  }

  const_dim_type output_Y_ndim = expected_output_shape.size();
  const_dim_type *output_Y_shape = const_cast<dim_type*>(expected_output_shape.data());
  size_t output_Y_size = output_Y_shape[0];
  for(int i=1;i<output_Y_ndim;i++)
    output_Y_size *= output_Y_shape[i];
  vector<element_type> output_Y(output_Y_size, 0);

 	cimHWConvOp op(
              configFilePath
              , intput_X, input_X_ndim, input_X_shape
              , intput_W, input_W_ndim, input_W_shape
              , intput_B, input_B_ndim, input_B_shape
              , output_Y.data(), output_Y_ndim, output_Y_shape
              , attributes.auto_pad.c_str()
              , attributes.dilations.data(), attributes.dilations.size()
              , attributes.group
              , attributes.kernel_shape.data(), attributes.kernel_shape.size()
              , attributes.pads.data(), attributes.pads.size()
              , attributes.strides.data(), attributes.strides.size()
              );
	op.simulate();

  // check if the number of dimensions equals
  ASSERT_TRUE(output_Y_ndim == expected_output_shape.size());
  // check every dims
  for (size_t d = 0; d < output_Y_ndim; ++d) {
      ASSERT_EQ(output_Y_shape[d], expected_output_shape[d])
          << "dim = " << d;
  }
  // check the content
  EXPECT_EQ(output_Y, expected_output);
}

} // namespace

using namespace cimHW_test;

TEST(ConvTest, Conv1D_1_AutoPad_NOTSET) {
  cimHWConvOpAndTestAttributes attrs = {
      "NOTSET",                  // auto_pad
      vector<dim_type>{1},       // dilations
      1,                         // group
      vector<dim_type>{7},       // kernel_shape
      vector<dim_type>{1, 0},    // pads
      vector<dim_type>{1}        // strides
  };

  vector<element_type> X = {
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0
  };
  vector<dim_type> X_shape = {1, 1, 7};

  vector<element_type> W = {
    1.0, 0.0, 1.0
  };
  vector<dim_type> W_shape = {1, 1, 3};

  vector<dim_type> expected_shape = {1, 1, 6};
  vector<element_type> expected_vals = {
    2.0, 4.0, 6.0, 8.0, 10.0, 12.0
  };
  TestcimHWConvOp(attrs, {X, W}, {X_shape, W_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv1D_1_AutoPad_VALID) {
  cimHWConvOpAndTestAttributes attrs = {
      "VALID",                   // auto_pad
      vector<dim_type>{1},       // dilations
      1,                         // group
      vector<dim_type>{0},       // kernel_shape
      vector<dim_type>{3, 8},    // pads
      vector<dim_type>{1}        // strides
  };

  vector<element_type> X = {
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0
  };
  vector<dim_type> X_shape = {1, 1, 7};

  vector<element_type> W = {
    1.0, 0.0, 1.0
  };
  vector<dim_type> W_shape = {1, 1, 3};

  vector<dim_type> expected_shape = {1, 1, 5};
  vector<element_type> expected_vals = {
    4.0, 6.0, 8.0, 10.0, 12.0
  };
  TestcimHWConvOp(attrs, {X, W}, {X_shape, W_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv1D_1_AutoPad_SAME_UPPER) {
  cimHWConvOpAndTestAttributes attrs = {
      "SAME_UPPER",              // auto_pad
      vector<dim_type>{1},       // dilations
      1,                         // group
      vector<dim_type>{7},       // kernel_shape
      vector<dim_type>{5, 10},   // pads
      vector<dim_type>{2}        // strides
  };

  vector<element_type> X = {
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0
  };
  vector<dim_type> X_shape = {1, 1, 7};

  vector<element_type> W = {
    1.0, 0.0, 1.0
  };
  vector<dim_type> W_shape = {1, 1, 3};

  vector<dim_type> expected_shape = {1, 1, 4};
  vector<element_type> expected_vals = {
    2.0, 6.0, 10.0, 6.0
  };
  TestcimHWConvOp(attrs, {X, W}, {X_shape, W_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv1D_1_AutoPad_SAME_LOWER) {
  cimHWConvOpAndTestAttributes attrs = {
      "SAME_LOWER",              // auto_pad
      vector<dim_type>{1},       // dilations
      1,                         // group
      vector<dim_type>{7},       // kernel_shape
      vector<dim_type>{-2, 10},  // pads
      vector<dim_type>{2}        // strides
  };

  vector<element_type> X = {
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0
  };
  vector<dim_type> X_shape = {1, 1, 8};

  vector<element_type> W = {
    1.0, 0.0, 1.0
  };
  vector<dim_type> W_shape = {1, 1, 3};

  vector<dim_type> expected_shape = {1, 1, 4};
  vector<element_type> expected_vals = {
    2.0, 6.0, 10.0, 14.0
  };
  TestcimHWConvOp(attrs, {X, W}, {X_shape, W_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv2D_1) {
  cimHWConvOpAndTestAttributes attrs = {
      "NOTSET",                     // auto_pad
      vector<dim_type>{1,1},        // dilations
      1,                            // group
      vector<dim_type>{2, 3},       // kernel_shape
      vector<dim_type>{1, 1, 1, 1}, // pads
      vector<dim_type>{1, 1}        // strides
  };

  vector<element_type> X = {
 		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0
  };
  vector<dim_type> X_shape = {1, 3, 2, 3};

  vector<element_type> W = {
		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0
  };
  vector<dim_type> W_shape = {2, 3, 3, 3};

  vector<element_type> B = {0,1};
  vector<dim_type> B_shape = {2};

  vector<dim_type> expected_shape = {1, 2, 2, 3};
  vector<element_type> expected_vals = {
    48.0f, 90.0f, 48.0f,
    72.0f, 102.0f, 66.0f,

    49.0f, 91.0f, 49.0f,
    73.0f, 103.0f, 67.0f
  };

  TestcimHWConvOp(attrs, {X, W, B}, {X_shape, W_shape, B_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv2D_1_Strides) {
  cimHWConvOpAndTestAttributes attrs = {
      "NOTSET",                     // auto_pad
      vector<dim_type>{1,1},        // dilations
      1,                            // group
      vector<dim_type>{2, 3},       // kernel_shape
      vector<dim_type>{1, 1, 1, 1}, // pads
      vector<dim_type>{1, 2}        // strides
  };

  vector<element_type> X = {
 		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0
  };
  vector<dim_type> X_shape = {1, 3, 2, 3};

  vector<element_type> W = {
		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0
  };
  vector<dim_type> W_shape = {2, 3, 3, 3};

  vector<element_type> B = {0,1};
  vector<dim_type> B_shape = {2};

  vector<dim_type> expected_shape = {1, 2, 2, 2};
  vector<element_type> expected_vals = {
    48.0f, 48.0f,
    72.0f, 66.0f,

    49.0f, 49.0f,
    73.0f, 67.0f
  };

  TestcimHWConvOp(attrs, {X, W, B}, {X_shape, W_shape, B_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv2D_1_Group) {
  cimHWConvOpAndTestAttributes attrs = {
      "NOTSET",                     // auto_pad
      vector<dim_type>{1,1},        // dilations
      2,                            // group
      vector<dim_type>{2, 3},       // kernel_shape
      vector<dim_type>{1, 1, 1, 1}, // pads
      vector<dim_type>{1, 1}        // strides
  };

  vector<element_type> X = {
 		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 1.0, 2.0, 3.0,
		 3.0, 2.0, 1.0,

		 1.0, 2.0, 3.0,
		 3.0, 2.0, 1.0
  };
  vector<dim_type> X_shape = {1, 4, 2, 3};

  vector<element_type> W = {
		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,
//----------------
		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,  0,1.0,
		1.0,1.0,1.0,
		  0,1.0,1.0,

		1.0,  0,1.0,
		1.0,1.0,1.0,
		  0,1.0,1.0
  };
  vector<dim_type> W_shape = {2, 4, 3, 3};

  vector<element_type> B = {0,0};
  vector<dim_type> B_shape = {2};

  vector<dim_type> expected_shape = {1, 2, 2, 3};
  vector<element_type> expected_vals = {
    32.0f, 60.0f, 32.0f,
    48.0f, 68.0f, 44.0f,

    16.0f, 18.0f, 12.0f,
    14.0f, 20.0f, 10.0f
  };

  TestcimHWConvOp(attrs, {X, W, B}, {X_shape, W_shape, B_shape}, expected_vals, expected_shape);
}

TEST(ConvTest, Conv3D_1) {
  cimHWConvOpAndTestAttributes attrs = {
      "NOTSET",                           // auto_pad
      vector<dim_type>{1,1,1},            // dilations
      1,                                  // group
      vector<dim_type>{3, 3, 3},          // kernel_shape
      vector<dim_type>{1, 1, 1, 1, 1, 1}, // pads
      vector<dim_type>{1, 1, 1}           // strides
  };

  vector<element_type> X = {
 		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0,

		 2.0, 4.0, 6.0,
		 8.0,10.0,12.0
  };
  vector<dim_type> X_shape = {1, 1, 2, 2, 3};

  vector<element_type> W = {
		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0,

		1.0,1.0,1.0,
		  0,1.0,1.0,
		1.0,  0,1.0
  };
  vector<dim_type> W_shape = {1, 1, 3, 3, 3};

  vector<element_type> B = {0};
  vector<dim_type> B_shape = {1};

  vector<dim_type> expected_shape = {1, 1, 2, 2, 3};
  vector<element_type> expected_vals = {
    32.0f, 60.0f, 32.0f,
    48.0f, 68.0f, 44.0f,

    32.0f, 60.0f, 32.0f,
    48.0f, 68.0f, 44.0f,
  };

  TestcimHWConvOp(attrs, {X, W, B}, {X_shape, W_shape, B_shape}, expected_vals, expected_shape);
}