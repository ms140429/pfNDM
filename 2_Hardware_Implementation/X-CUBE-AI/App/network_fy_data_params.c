/**
  ******************************************************************************
  * @file    network_fy_data_params.c
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

#include "network_fy_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_fy_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_fy_weights_array_u64[96] = {
  0x3e4aeb81bc7cf082U, 0xbd6cd55abd0673ccU, 0x3da98c643e517e5fU, 0x3dcad5213c91e011U,
  0x3dfecbacbd9aaa32U, 0xbd820e623e552671U, 0x3d25194cbd555b67U, 0xbe1cdffa3d17f412U,
  0x3dbe00ab3dee364fU, 0x3e23b1173d8ea702U, 0x3d571dd23e5aa1d0U, 0xbbb1d76a3d5e4799U,
  0x3e48ed093e027b4bU, 0xbcb1a80fbd63e7b8U, 0x3e654f923e3a5d4dU, 0x3defbf593deef087U,
  0xbe4e67c63dfe6b12U, 0xbdd18d863ea80429U, 0xbdba70c63c9256d8U, 0x3e12991bbdbcf150U,
  0x3e09ae7d3e395dccU, 0x3e308052be404d06U, 0xbeba2866bd239726U, 0xbb81d1353dbbd8b8U,
  0xbb841c1fbd30dc69U, 0x3d9c34963dcb1751U, 0x3ebf9788bdf7382aU, 0xbe503f673d214550U,
  0x3cffcfbd3da19cbcU, 0x3e01443dbded9f86U, 0x3e080c363cc75683U, 0x3dbbd7fb3b5038e8U,
  0x3e1371073e4ee711U, 0x3cade960bc587bc4U, 0xbe1cac36bdca1e4dU, 0x3de8b8c0bb6e941cU,
  0x3e0d6fc43d895575U, 0x3e1a3aa03bb3129aU, 0xbd681c5a3db10d2aU, 0x3ddb4ddbbe16aceeU,
  0xbda1fdbcbd129d92U, 0x3e3b1f6bbd1384e6U, 0x3db8bb54bdaa4ed1U, 0xbe12ee7fbe704ee1U,
  0xbd0fb6bf3cca52ddU, 0x3cbde02e3e347cb1U, 0xbf4c56cabd8114ccU, 0xbe1ab650bd61f6f9U,
  0x3da3c389bea9c3f9U, 0x3e0c1b0fbd819fbdU, 0x3e31ebdabd6ee647U, 0x3d05d055bd1e02acU,
  0x3d9802c9bd83c805U, 0x3e3826bbbc6f9f1eU, 0x3dee9c0cbca7e31fU, 0x3e5182cd3e540de8U,
  0x3db471143d41160bU, 0x3e4f5abf3c9998a9U, 0xbe610e68bd5fd2caU, 0x3e571ba03df0cdb6U,
  0x3d503d88bd9e2eb0U, 0xbe071cc53e010585U, 0xbdd5d9823e018216U, 0x3daf8fa7bee00eb3U,
  0xbe97a06a3e5a9d4fU, 0x3d3ccd46bdf1dd25U, 0xbe0ff0eabde17828U, 0xba77c645bed2769bU,
  0x3de9dbc2bd67fc28U, 0x3e2087293bb61a0eU, 0xbea33dfdbe171fd4U, 0x3dd0f9183df20fc6U,
  0x3e2c9d2ebe6e07afU, 0xbcd01090be3fad60U, 0x3e7ff6bfbe1eea8fU, 0x3c4b72833dc59d75U,
  0x3e786912bd33ac15U, 0x3c046b5e3e549664U, 0x3e0e18023d8f9176U, 0x3e5ca1923e83702aU,
  0x3e03cd623e688cc6U, 0xbd1b7bbcbc524ed5U, 0xbe958120bdd3b316U, 0x3ea22cbebd97ad9dU,
  0x3d1f7f043df63c4bU, 0xbcbc7da2bdcda16eU, 0x3cc546fd3e2b3254U, 0x3df8c2ddbe9ccd8eU,
  0xbf1b8375bc090beeU, 0x3e0dbf1dbd4559e1U, 0xbe32202e3d4851b5U, 0x3e3badbb3d51a479U,
  0x3e1c01083ddce5a5U, 0x3e8d02403e53e1f7U, 0x3e84ee38bed8ece4U, 0x3e366ce23e64f28dU,
};


ai_handle g_network_fy_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_fy_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

