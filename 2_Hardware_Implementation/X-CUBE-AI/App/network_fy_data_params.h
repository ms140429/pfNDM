/**
  ******************************************************************************
  * @file    network_fy_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Nov  1 15:46:14 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef NETWORK_FY_DATA_PARAMS_H
#define NETWORK_FY_DATA_PARAMS_H
#pragma once

#include "ai_platform.h"

/*
#define AI_NETWORK_FY_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_network_fy_data_weights_params[1]))
*/

#define AI_NETWORK_FY_DATA_CONFIG               (NULL)


#define AI_NETWORK_FY_DATA_ACTIVATIONS_SIZES \
  { 208, }
#define AI_NETWORK_FY_DATA_ACTIVATIONS_SIZE     (208)
#define AI_NETWORK_FY_DATA_ACTIVATIONS_COUNT    (1)
#define AI_NETWORK_FY_DATA_ACTIVATION_1_SIZE    (208)



#define AI_NETWORK_FY_DATA_WEIGHTS_SIZES \
  { 768, }
#define AI_NETWORK_FY_DATA_WEIGHTS_SIZE         (768)
#define AI_NETWORK_FY_DATA_WEIGHTS_COUNT        (1)
#define AI_NETWORK_FY_DATA_WEIGHT_1_SIZE        (768)



#define AI_NETWORK_FY_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_network_fy_activations_table[1])

extern ai_handle g_network_fy_activations_table[1 + 2];



#define AI_NETWORK_FY_DATA_WEIGHTS_TABLE_GET() \
  (&g_network_fy_weights_table[1])

extern ai_handle g_network_fy_weights_table[1 + 2];


#endif    /* NETWORK_FY_DATA_PARAMS_H */
