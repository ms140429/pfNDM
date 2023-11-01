/**
  ******************************************************************************
  * @file    network_fu.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Nov  1 15:45:54 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network_fu.h"
#include "network_fu_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_fu
 
#undef AI_NETWORK_FU_MODEL_SIGNATURE
#define AI_NETWORK_FU_MODEL_SIGNATURE     "c01ff3e8164259be14fa1b2652f9e00c"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Nov  1 15:45:54 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_FU_N_BATCHES
#define AI_NETWORK_FU_N_BATCHES         (1)

static ai_ptr g_network_fu_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_fu_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_27_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_27_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  output_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  output_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  input_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  onnxErf_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  onnxAdd_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  onnxGemm_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_18_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  onnxErf_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  onnxAdd_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_23_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_24_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  onnxGemm_26_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_27_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  onnxErf_29_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  onnxAdd_30_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_32_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_33_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  onnxGemm_35_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  output_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 48, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 480, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_34_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  onnxAdd_31_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_28_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_25_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  onnxAdd_22_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_19_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  onnxMul_16_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  onnxAdd_13_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_10_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_18_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)
/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  onnxDiv_18_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_27_weights, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 48, 48, 1, 1), AI_STRIDE_INIT(4, 4, 192, 9216, 9216),
  1, &onnxDiv_27_weights_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_27_bias, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxDiv_27_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  output_weights, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 48, 48, 1, 1), AI_STRIDE_INIT(4, 4, 192, 9216, 9216),
  1, &output_weights_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  output_bias, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &output_bias_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  input_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &input_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_9_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxDiv_9_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  onnxErf_11_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxErf_11_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  onnxAdd_12_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxAdd_12_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_14_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxMul_14_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_15_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxMul_15_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  onnxGemm_17_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxGemm_17_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_18_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxDiv_18_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  onnxErf_20_output, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxErf_20_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  onnxAdd_21_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxAdd_21_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_23_output, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxMul_23_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_24_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxMul_24_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  onnxGemm_26_output, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxGemm_26_output_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_27_output, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxDiv_27_output_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  onnxErf_29_output, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxErf_29_output_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  onnxAdd_30_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxAdd_30_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_32_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxMul_32_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_33_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxMul_33_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  onnxGemm_35_output, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxGemm_35_output_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  output_output, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &output_output_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_9_weights, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 10, 48, 1, 1), AI_STRIDE_INIT(4, 4, 40, 1920, 1920),
  1, &onnxDiv_9_weights_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_9_bias, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxDiv_9_bias_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_34, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxMul_34_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  onnxAdd_31, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxAdd_31_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_28, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxDiv_28_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_25, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxMul_25_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  onnxAdd_22, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxAdd_22_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_19, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxDiv_19_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  onnxMul_16, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxMul_16_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  onnxAdd_13, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxAdd_13_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_10, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &onnxDiv_10_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_18_weights, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 48, 48, 1, 1), AI_STRIDE_INIT(4, 4, 192, 9216, 9216),
  1, &onnxDiv_18_weights_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  onnxDiv_18_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &onnxDiv_18_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  output_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxGemm_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &output_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &output_weights, &output_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  output_layer, 28,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &output_chain,
  NULL, &output_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxGemm_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxMul_33_output, &onnxMul_34),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxGemm_35_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxGemm_35_layer, 27,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxGemm_35_chain,
  NULL, &output_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxMul_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_27_output, &onnxMul_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxMul_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxMul_33_layer, 25,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxMul_33_chain,
  NULL, &onnxGemm_35_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxMul_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxAdd_30_output, &onnxAdd_31),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxMul_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxMul_32_layer, 24,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxMul_32_chain,
  NULL, &onnxMul_33_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxAdd_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxErf_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxAdd_30_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxAdd_30_layer, 22,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &onnxAdd_30_chain,
  NULL, &onnxMul_32_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxErf_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_27_output, &onnxDiv_28),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxErf_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxErf_29_layer, 21,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxErf_29_chain,
  NULL, &onnxAdd_30_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxDiv_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxGemm_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxDiv_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_27_weights, &onnxDiv_27_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxDiv_27_layer, 19,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &onnxDiv_27_chain,
  NULL, &onnxErf_29_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxGemm_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxMul_24_output, &onnxMul_25),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxGemm_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxGemm_26_layer, 18,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxGemm_26_chain,
  NULL, &onnxDiv_27_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxMul_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_18_output, &onnxMul_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxMul_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxMul_24_layer, 16,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxMul_24_chain,
  NULL, &onnxGemm_26_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxMul_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxAdd_21_output, &onnxAdd_22),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxMul_23_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxMul_23_layer, 15,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxMul_23_chain,
  NULL, &onnxMul_24_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxAdd_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxErf_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxAdd_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxAdd_21_layer, 13,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &onnxAdd_21_chain,
  NULL, &onnxMul_23_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxErf_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_18_output, &onnxDiv_19),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxErf_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxErf_20_layer, 12,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxErf_20_chain,
  NULL, &onnxAdd_21_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxDiv_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxGemm_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxDiv_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_18_weights, &onnxDiv_18_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxDiv_18_layer, 10,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &onnxDiv_18_chain,
  NULL, &onnxErf_20_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxGemm_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxMul_15_output, &onnxMul_16),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxGemm_17_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxGemm_17_layer, 9,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxGemm_17_chain,
  NULL, &onnxDiv_18_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxMul_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_9_output, &onnxMul_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxMul_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxMul_15_layer, 7,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxMul_15_chain,
  NULL, &onnxGemm_17_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxMul_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxAdd_12_output, &onnxAdd_13),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxMul_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxMul_14_layer, 6,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxMul_14_chain,
  NULL, &onnxMul_15_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxAdd_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxErf_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxAdd_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxAdd_12_layer, 4,
  NL_TYPE, 0x0, NULL,
  nl, forward_erf,
  &onnxAdd_12_chain,
  NULL, &onnxMul_14_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxErf_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_9_output, &onnxDiv_10),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxErf_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxErf_11_layer, 3,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &onnxErf_11_chain,
  NULL, &onnxAdd_12_layer, AI_STATIC, 
  .operation = ai_div_f32, 
  .buffer_operation = ai_div_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  onnxDiv_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &onnxDiv_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &onnxDiv_9_weights, &onnxDiv_9_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  onnxDiv_9_layer, 1,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &onnxDiv_9_chain,
  NULL, &onnxErf_11_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 30372, 1, 1),
    30372, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
    384, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_FU_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_FU_OUT_NUM, &output_output),
  &onnxDiv_9_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 30372, 1, 1),
      30372, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 384, 1, 1),
      384, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_FU_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_FU_OUT_NUM, &output_output),
  &onnxDiv_9_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_fu_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_fu_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 152);
    input_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 152);
    
    onnxDiv_9_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    onnxDiv_9_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    onnxErf_11_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxErf_11_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxAdd_12_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxAdd_12_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxMul_14_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxMul_14_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxMul_15_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    onnxMul_15_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    onnxGemm_17_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxGemm_17_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxDiv_18_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    onnxDiv_18_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    onnxErf_20_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxErf_20_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxAdd_21_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxAdd_21_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxMul_23_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxMul_23_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxMul_24_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    onnxMul_24_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    onnxGemm_26_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxGemm_26_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxDiv_27_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    onnxDiv_27_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    onnxErf_29_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxErf_29_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxAdd_30_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxAdd_30_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxMul_32_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxMul_32_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    onnxMul_33_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    onnxMul_33_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    onnxGemm_35_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 0);
    onnxGemm_35_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 0);
    
    output_output_array.data = AI_PTR(g_network_fu_activations_map[0] + 192);
    output_output_array.data_start = AI_PTR(g_network_fu_activations_map[0] + 192);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_fu_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_fu_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    onnxDiv_27_weights_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_27_weights_array.data = AI_PTR(g_network_fu_weights_map[0] + 0);
    onnxDiv_27_weights_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 0);
    
    onnxDiv_27_bias_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_27_bias_array.data = AI_PTR(g_network_fu_weights_map[0] + 9216);
    onnxDiv_27_bias_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 9216);
    
    output_weights_array.format |= AI_FMT_FLAG_CONST;
    output_weights_array.data = AI_PTR(g_network_fu_weights_map[0] + 9408);
    output_weights_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 9408);
    
    output_bias_array.format |= AI_FMT_FLAG_CONST;
    output_bias_array.data = AI_PTR(g_network_fu_weights_map[0] + 18624);
    output_bias_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 18624);
    
    onnxDiv_9_weights_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_9_weights_array.data = AI_PTR(g_network_fu_weights_map[0] + 18816);
    onnxDiv_9_weights_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 18816);
    
    onnxDiv_9_bias_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_9_bias_array.data = AI_PTR(g_network_fu_weights_map[0] + 20736);
    onnxDiv_9_bias_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20736);
    
    onnxMul_34_array.format |= AI_FMT_FLAG_CONST;
    onnxMul_34_array.data = AI_PTR(g_network_fu_weights_map[0] + 20928);
    onnxMul_34_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20928);
    
    onnxAdd_31_array.format |= AI_FMT_FLAG_CONST;
    onnxAdd_31_array.data = AI_PTR(g_network_fu_weights_map[0] + 20932);
    onnxAdd_31_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20932);
    
    onnxDiv_28_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_28_array.data = AI_PTR(g_network_fu_weights_map[0] + 20936);
    onnxDiv_28_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20936);
    
    onnxMul_25_array.format |= AI_FMT_FLAG_CONST;
    onnxMul_25_array.data = AI_PTR(g_network_fu_weights_map[0] + 20940);
    onnxMul_25_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20940);
    
    onnxAdd_22_array.format |= AI_FMT_FLAG_CONST;
    onnxAdd_22_array.data = AI_PTR(g_network_fu_weights_map[0] + 20944);
    onnxAdd_22_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20944);
    
    onnxDiv_19_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_19_array.data = AI_PTR(g_network_fu_weights_map[0] + 20948);
    onnxDiv_19_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20948);
    
    onnxMul_16_array.format |= AI_FMT_FLAG_CONST;
    onnxMul_16_array.data = AI_PTR(g_network_fu_weights_map[0] + 20952);
    onnxMul_16_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20952);
    
    onnxAdd_13_array.format |= AI_FMT_FLAG_CONST;
    onnxAdd_13_array.data = AI_PTR(g_network_fu_weights_map[0] + 20956);
    onnxAdd_13_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20956);
    
    onnxDiv_10_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_10_array.data = AI_PTR(g_network_fu_weights_map[0] + 20960);
    onnxDiv_10_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20960);
    
    onnxDiv_18_weights_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_18_weights_array.data = AI_PTR(g_network_fu_weights_map[0] + 20964);
    onnxDiv_18_weights_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 20964);
    
    onnxDiv_18_bias_array.format |= AI_FMT_FLAG_CONST;
    onnxDiv_18_bias_array.data = AI_PTR(g_network_fu_weights_map[0] + 30180);
    onnxDiv_18_bias_array.data_start = AI_PTR(g_network_fu_weights_map[0] + 30180);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_fu_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_FU_MODEL_NAME,
      .model_signature   = AI_NETWORK_FU_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 9024,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_fu_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_FU_MODEL_NAME,
      .model_signature   = AI_NETWORK_FU_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 9024,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_fu_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_fu_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_fu_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_fu_create(network, AI_NETWORK_FU_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_fu_data_params_get(&params) != true) {
        err = ai_network_fu_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_FU_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_FU_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_fu_init(*network, &params) != true) {
        err = ai_network_fu_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_fu_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_fu_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_fu_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_fu_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_fu_configure_weights(net_ctx, params);
  ok &= network_fu_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_fu_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_fu_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_FU_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

