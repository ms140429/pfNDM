/**
  ******************************************************************************
  * @file    network_f01_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Nov  1 15:45:43 2023
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

#include "network_f01_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_f01_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_f01_weights_array_u64[52] = {
  0x3eca6e293ea0f8e0U, 0xbd8826e6bda25a0dU, 0x3ed045633e93dafdU, 0xbd81c8dbbe872598U,
  0x3dfa2c883dd941c7U, 0x3d4c8db83e9e7d0cU, 0xbeb965533f19cf24U, 0x3e5064a6bdb844cfU,
  0x3dd350a03e6c61d3U, 0xbcf39ee0bd8091a1U, 0xbe59464c3ed20092U, 0x3d52d96e3e52bce8U,
  0xbdf556893d54e587U, 0xbd2b603a3e66103fU, 0xbdc828adbe78966eU, 0xbe1a7e9e3cecc609U,
  0xbe02239f3e6a3879U, 0x3db1b19e3dbb1a6bU, 0xbdc4f71bbe880cb9U, 0x3e8b6d373e800782U,
  0xbda5be873e65a6c9U, 0xbe764e6cbe0fc659U, 0x3e5dc81a3e7c5658U, 0xbe7319a6be71f96aU,
  0x3cbde9cabd8a5d9aU, 0x3eebced9be1de28eU, 0xbdb0b5c1bd8645f2U, 0xbcdbb9403db6a464U,
  0xbe061d10bcb6490eU, 0x3f03486bbdb6c4b4U, 0x3c6fa47c3f169c0eU, 0x3dff8379bda5a23eU,
  0xbe680d703e5074cfU, 0x3d6502f93d0640aeU, 0x3e03f3cdbe012803U, 0x3c030854be02f81eU,
  0xbea062db3ca2540fU, 0xbe6d4b20be65babeU, 0x3e7246063e688083U, 0xbea0860d3e78d4edU,
  0x3c1493ec3e2cb639U, 0xbd459af4bd8611b0U, 0x3eae07a83e29a46fU, 0x3d577cffbe74d6d8U,
  0xbe8e0bc73cb67eabU, 0xbea2e2a9bd662e3bU, 0xbd8beaa03df698baU, 0x3ee2315ebdb2d977U,
  0x3e73a599bdf61bfdU, 0x3fce9384be5185f7U, 0x3f127671be9e2abcU, 0x3b40be313cc02ceeU,
};


ai_handle g_network_f01_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_f01_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

