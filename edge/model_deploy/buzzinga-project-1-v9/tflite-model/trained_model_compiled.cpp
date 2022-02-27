/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 27.02.2022 20:48:27

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 3440;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,1160 } };
const TfArray<1, float> quant0_scale = { 1, { 0.0028186275158077478, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 29, 40, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 29, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data3[4] = { 1, 1, 15, 8, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data4[4] = { 1, 15, 1, 16, };
const TfArray<1, int> tensor_dimension4 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data5[2] = { -1, 128, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const ALIGN(16) int8_t tensor_data6[8*1*3*40] = { 
  /* [0][0][][] */ -56,-31,29,54,16,6,-9,-38,23,-44,61,0,22,-41,-52,-9,-10,45,-97,-59,-40,-19,-39,-2,7,6,-80,-13,-54,-81,-63,-46,-80,30,18,-51,-102,-127,-85,-81, -20,-36,32,-21,-40,7,14,-68,-72,3,53,19,-45,-86,-15,-7,-14,-22,-42,-41,-16,-10,-4,-91,2,-40,-84,-10,-27,-10,-11,22,0,-36,-86,-71,-16,-37,-72,-93, -97,-68,-12,50,23,11,37,-23,-88,-36,-3,-10,12,-19,-75,23,-10,-33,-56,40,27,2,5,-15,17,-35,-65,4,-22,-16,-1,-49,0,2,33,-23,-4,-40,-76,-115, 
  /* [1][0][][] */ 69,-6,-20,-54,-2,13,-30,-5,-91,7,-31,-26,19,-38,-112,29,-4,-2,-76,-33,-18,40,-32,-46,32,8,9,0,-28,52,7,-14,18,-14,4,44,53,41,29,29, 40,19,12,37,-31,1,37,1,-12,12,6,5,-6,-99,-102,-50,-37,-2,-94,-28,-19,20,38,9,20,-4,-10,-27,-19,10,1,50,41,-8,-1,62,11,40,57,70, 27,-10,-1,28,20,-47,-48,-41,-26,-15,-58,11,-26,-44,-125,58,28,-33,-127,-63,-24,1,-53,-8,-20,-6,38,-17,13,-11,-32,-2,53,33,6,60,71,46,44,18, 
  /* [2][0][][] */ -10,-53,-69,84,8,-3,-32,31,-77,-35,-25,-13,18,-13,-93,-26,-19,21,-65,-10,-15,-3,-38,-16,-64,-29,32,-15,-40,-20,-70,17,40,-21,-36,56,57,71,114,64, -62,-51,-2,26,-19,66,1,-61,-50,-65,37,-14,5,-38,-56,6,23,-18,-61,-7,-78,-41,-29,-16,22,-27,-55,36,-14,-40,-30,11,-23,-24,-21,-5,58,127,70,85, -57,-39,26,25,26,6,-8,29,-10,-31,-6,-55,52,-4,-78,-26,-50,50,-109,-49,17,-64,-2,-30,-6,-42,30,-12,-85,-30,10,38,23,-20,-39,67,59,36,95,23, 
  /* [3][0][][] */ -84,-4,-21,25,16,-52,16,30,52,22,11,-17,-4,90,4,-6,-3,-13,20,-13,40,-10,4,-57,8,-41,-35,2,-54,-22,11,-40,-29,-23,-56,-18,-12,94,90,77, -66,-18,-24,-39,4,63,20,-6,49,14,-12,-5,6,-14,8,16,-14,-2,8,-83,-2,43,11,-58,-23,-35,-65,2,-33,-31,21,-53,-61,45,-84,-10,-36,57,127,82, -62,-61,38,3,-3,-7,40,25,58,1,29,7,43,56,25,8,64,-14,15,-7,-40,-5,-74,-57,-18,-67,-100,1,-26,-40,-20,-94,-74,29,0,15,-19,77,116,109, 
  /* [4][0][][] */ -24,-11,11,28,62,-4,22,-55,-74,2,-17,0,51,6,-66,-35,-1,-45,-26,-56,8,38,37,-91,0,-24,-52,-20,-9,-45,-10,-44,-11,-9,-73,-34,52,119,59,127, -53,0,-26,8,-19,19,-14,-59,-38,-13,28,-76,-27,-71,-66,6,92,-26,-57,-24,-31,-65,-68,-25,14,-23,-73,38,-30,-26,46,-11,-84,28,4,8,31,61,103,96, -87,-59,26,2,22,-40,-54,-35,-9,13,17,-57,14,-17,-9,6,-49,-11,-27,-18,-31,13,57,-65,109,-64,-32,1,-33,-26,-1,-60,-37,-1,-28,65,50,94,93,86, 
  /* [5][0][][] */ 44,38,74,6,65,-8,-15,64,105,-2,-26,84,46,98,36,16,33,-3,41,20,15,55,-24,-63,-53,-89,9,13,-90,-52,101,-52,-109,69,-89,-37,-32,-79,-54,-59, -29,-6,-8,51,-28,-16,-7,44,31,56,-13,-3,-14,73,20,-67,17,-6,92,-78,-21,-70,-80,-53,-37,-23,-88,53,-94,-21,20,-34,-12,35,-22,-24,-117,-55,-22,-34, 7,44,12,-4,23,-18,36,85,103,-30,-51,2,81,125,27,8,96,-7,68,-38,5,-28,-50,-24,5,-38,-74,-53,-40,-44,-48,-108,-127,18,7,-94,-53,-38,-52,34, 
  /* [6][0][][] */ -81,-22,3,-32,-24,-14,2,10,5,32,-19,19,-37,-35,-8,6,-20,-29,-12,-67,17,26,-61,-28,-28,-69,-46,-20,7,-51,-32,-42,-29,20,-17,27,-21,58,82,127, -64,-50,-9,26,28,17,-1,-79,-8,-9,-6,-1,13,-4,-61,39,2,7,-101,-21,25,-3,-2,-53,18,-69,-65,-16,-47,-37,8,-49,-56,-10,-25,17,-13,105,94,115, -88,6,4,4,-25,18,7,27,27,44,26,-7,-15,45,-10,39,-31,-36,36,11,23,-7,-12,-13,-20,-32,5,-44,-38,-21,-1,-22,-34,16,27,51,24,51,102,103, 
  /* [7][0][][] */ 26,-37,-31,5,32,-6,-22,37,5,33,3,-14,31,54,67,-14,-15,3,79,-2,52,2,13,93,55,79,-21,-62,81,55,-40,6,19,-17,8,-55,27,-122,-58,-71, 34,14,42,8,-29,-5,27,43,47,14,-10,16,-12,-11,95,-44,21,-5,91,-9,8,-8,54,26,-2,59,58,18,72,49,-8,50,6,21,-31,-44,-87,-41,-62,-88, 0,-8,-1,40,17,-21,20,38,-3,3,-41,4,-1,38,48,-7,-9,-18,37,34,15,34,-15,46,-2,78,51,-45,16,41,-40,-1,-12,-26,26,-34,-55,-127,-65,-39, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,40 } };
const TfArray<8, float> quant6_scale = { 8, { 0.0042947833426296711, 0.0039395787753164768, 0.0035155718214809895, 0.0042362003587186337, 0.0036150349769741297, 0.0034190628211945295, 0.0039839465171098709, 0.0036875887308269739, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int32_t tensor_data7[8] = { 5530, 14243, 7154, 6177, -782, -2092, 4190, -9857, };
const TfArray<1, int> tensor_dimension7 = { 1, { 8 } };
const TfArray<8, float> quant7_scale = { 8, { 1.2105394489481114e-05, 1.1104205441370141e-05, 9.9090875664842315e-06, 1.194027117890073e-05, 1.0189437489316333e-05, 9.6370649771415628e-06, 1.1229260962863918e-05, 1.039393919199938e-05, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int8_t tensor_data8[16*1*3*8] = { 
  /* [0][0][][] */ -127,6,-5,122,15,-67,106,-67, -36,5,-38,38,3,-67,49,-60, -49,-8,43,84,41,47,66,-43, 
  /* [1][0][][] */ -29,99,-52,-127,-69,-93,-11,4, -67,-8,-37,-122,-127,-51,-108,-3, 46,96,18,-27,6,-71,-81,-16, 
  /* [2][0][][] */ -33,46,-69,-94,-64,63,-123,-40, 50,-2,-50,-28,-42,-36,-90,68, -48,-20,-58,-127,-37,-31,13,2, 
  /* [3][0][][] */ -127,18,41,20,-24,40,-7,23, -51,-23,10,59,22,48,14,-27, -79,-38,28,47,-7,38,56,-38, 
  /* [4][0][][] */ 49,5,9,-75,-18,-44,-82,35, 22,8,-8,-127,-60,-41,-50,66, 82,-6,17,-17,-32,29,-54,71, 
  /* [5][0][][] */ -28,-60,-127,54,-47,97,-52,66, -122,-102,-84,77,-42,106,-71,-53, -64,-90,-38,45,-8,79,-69,47, 
  /* [6][0][][] */ 10,55,62,60,64,-80,-20,1, -12,7,47,-102,26,-23,-9,-93, -44,96,-11,-45,13,-127,-8,-21, 
  /* [7][0][][] */ -65,-101,-13,-19,-108,85,-3,57, -9,-110,-127,24,-9,73,-18,-35, -38,-97,-108,6,-7,73,-69,84, 
  /* [8][0][][] */ -16,-87,32,-71,-108,19,-66,102, 9,-67,-89,41,-15,35,-27,83, 20,-112,-20,-127,-88,-21,1,24, 
  /* [9][0][][] */ -49,-22,78,36,107,-15,-5,-33, -41,85,124,-13,49,-20,127,-37, -89,13,80,49,64,-69,98,-18, 
  /* [10][0][][] */ 31,37,15,-69,-54,-91,-86,26, 115,35,-1,-39,36,-18,21,-18, 54,21,-12,-127,-63,-33,-6,-11, 
  /* [11][0][][] */ 12,-30,-8,-40,-14,-107,3,-8, 3,127,27,-122,-87,-31,-69,1, 68,45,-99,-26,21,-81,31,-4, 
  /* [12][0][][] */ -39,35,-31,32,45,31,82,-121, -127,-9,82,49,61,-61,87,-55, -119,36,-21,40,14,-12,27,-39, 
  /* [13][0][][] */ -24,-4,-58,14,-113,-80,-52,-127, -83,-56,7,-34,40,13,-83,-78, -48,-89,-79,57,-36,59,49,-30, 
  /* [14][0][][] */ 26,78,100,-6,-23,-11,2,-64, 42,66,-23,-25,127,-94,16,-28, 2,106,113,-103,101,-67,59,-25, 
  /* [15][0][][] */ 61,14,-25,48,-106,-127,-81,-55, -43,8,-42,-75,53,27,90,-20, 23,-83,4,-103,-69,15,-77,-7, 
};
const TfArray<4, int> tensor_dimension8 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant8_scale = { 16, { 0.0039833802729845047, 0.003486288245767355, 0.0041976836510002613, 0.004523108247667551, 0.0053886808454990387, 0.0039925151504576206, 0.0030139624141156673, 0.004216264933347702, 0.003584765363484621, 0.0041400589980185032, 0.0044948621653020382, 0.0033506571780890226, 0.0034292880445718765, 0.0028513791039586067, 0.0031136649195104837, 0.0027006089221686125, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int32_t tensor_data9[16] = { -4436, 4128, 2981, -5113, 4373, -1239, -4676, 1429, 769, -666, 4228, 822, -6740, -1016, 3832, -4984, };
const TfArray<1, int> tensor_dimension9 = { 1, { 16 } };
const TfArray<16, float> quant9_scale = { 16, { 3.1750485504744574e-05, 2.7788293664343655e-05, 3.3458640245953575e-05, 3.6052515497431159e-05, 4.2951767682097852e-05, 3.1823296012589708e-05, 2.402350764896255e-05, 3.3606749639147893e-05, 2.8573229428729974e-05, 3.2999330869643018e-05, 3.5827375540975481e-05, 2.6707213692134246e-05, 2.7333961043041199e-05, 2.2727599571226165e-05, 2.481821138644591e-05, 2.1525849660974927e-05, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int8_t tensor_data10[3*128] = { 
  -127, -58, -2, 31, 69, 50, -21, 80, 13, -97, -44, 5, -36, 37, -28, -12, -94, -13, 31, -50, 39, 58, 2, 67, 28, -51, -23, -33, -37, 38, -65, -13, -37, 12, 25, -39, 22, 69, -71, 53, 53, -104, -8, -44, -63, -56, -108, 45, -87, -51, 68, 6, 18, 41, -1, 63, 12, -73, -64, -52, -75, -54, -37, 21, -7, -11, 16, 27, 45, 83, -9, 41, 19, -78, -39, -50, -21, -21, -93, 24, -52, -37, 74, -20, 66, 8, -68, 76, 66, -109, -18, 0, 26, 19, -19, -16, -75, -32, 54, 61, 24, 27, -51, 94, 44, -89, -77, -11, -36, 20, -109, 34, -84, -49, 13, -26, 51, 35, -2, 58, 21, -86, -52, -61, -38, 2, -49, -56, 
  47, -40, -67, -10, -60, 9, 25, -24, -29, 31, -48, -20, 63, 20, -12, 3, 16, 39, -61, 47, -38, 13, -10, -50, -49, 44, -39, 23, 43, -36, 29, -4, 53, 3, -7, 37, -48, 40, 5, 17, -55, 36, 3, -8, -5, 44, 23, 25, 51, -48, -67, 39, -115, -12, 34, -10, -15, 65, -13, -37, 41, -32, 25, 28, 69, 24, -69, -15, -59, 20, 33, 18, -53, 15, 15, -7, 54, -14, -19, -26, 54, 6, -41, 22, -59, 34, 34, 22, -15, 28, -3, -12, 40, 41, 37, 16, 65, 14, -13, 10, -88, 2, 36, 17, -13, 58, -29, 28, 62, 2, 11, 36, -16, -31, -83, 19, -82, 7, 21, 27, -114, 68, -15, -14, 35, -30, 48, 42, 
  -30, 40, 36, 0, 50, -47, -8, -40, 4, -4, 37, 1, -31, -32, 24, -16, -75, 72, 39, -7, 43, -54, -20, -5, -38, 27, 4, 29, 27, 12, 33, 37, -35, 50, 73, -40, 11, -38, 24, -36, -34, 8, 24, 44, -32, -52, 16, 6, -57, 20, -24, -22, -20, -57, -1, -26, -28, 31, 39, -27, -10, 20, 10, -25, -21, 93, 42, -14, 42, -27, -10, -44, -18, 21, 59, 1, 0, -36, 3, 48, -25, 62, 18, -54, 49, -73, 28, -30, -11, 7, 73, 38, -10, -44, 40, -7, -48, 49, 6, -38, 31, -26, 36, -56, -2, 16, 12, 26, 23, 17, 7, 26, -36, 90, 9, 7, 31, -14, 4, -6, -21, 12, 18, 79, 5, 32, 11, -27, 
};
const TfArray<2, int> tensor_dimension10 = { 2, { 3,128 } };
const TfArray<1, float> quant10_scale = { 1, { 0.004217047244310379, } };
const TfArray<1, int> quant10_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const ALIGN(8) int32_t tensor_data11[3] = { -737, -4479, 5298, };
const TfArray<1, int> tensor_dimension11 = { 1, { 3 } };
const TfArray<1, float> quant11_scale = { 1, { 4.3457850551931188e-05, } };
const TfArray<1, int> quant11_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,29,40 } };
const TfArray<1, float> quant12_scale = { 1, { 0.0028186275158077478, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,29,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.0079707391560077667, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,29,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.0079707391560077667, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,15,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.0079707391560077667, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,15,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.0079707391560077667, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,15,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.010305279865860939, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,15,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.010305279865860939, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,8,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.010305279865860939, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,128 } };
const TfArray<1, float> quant20_scale = { 1, { 0.010305279865860939, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,3 } };
const TfArray<1, float> quant21_scale = { 1, { 0.067299015820026398, } };
const TfArray<1, int> quant21_zero = { 1, { 34 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,3 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,7 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,2 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,3 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,8,9 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,4 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,5 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,10,11 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 1168, (TfLiteIntArray*)&tensor_dimension0, 1160, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 12, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 1160, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 1648, (TfLiteIntArray*)&tensor_dimension13, 232, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 232, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 240, (TfLiteIntArray*)&tensor_dimension15, 120, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 120, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 240, (TfLiteIntArray*)&tensor_dimension17, 240, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 240, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 240, (TfLiteIntArray*)&tensor_dimension19, 128, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 128, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 128, (TfLiteIntArray*)&tensor_dimension21, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for(size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 11; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}