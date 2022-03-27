#include <iostream>
#include <fstream>
#include <string>

#define TEST_C_FUNCTIONS

#ifdef TEST_C_FUNCTIONS
#include "fr.hpp"
#else
#include "fr_asm.hpp"
#endif
#include <assert.h>
using namespace std;

//#define Fr_N64 4
//typedef uint64_t FrRawElement[Fr_N64];

#ifdef TEST_C_FUNCTIONS
//void Fr_fail() {
//    assert(false);
//}
#endif

uint64_t uRawResult = 0;
uint64_t uRawResult1 = 0;
uint64_t uRawResult2 = 0;
uint64_t uRawResult3 = 0;
FrRawElement pRawResult = {0,0,0,0};
FrRawElement pRawA = {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
FrRawElement pRawB = {0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5};

FrRawElement pRawResult1 = {0,0,0,0};
FrRawElement pRawA1      = {0x1,0,0,0};
FrRawElement pRawB1      = {0x2,0,0,0};

FrRawElement pRawResult2 = {0,0,0,0};
FrRawElement pRawA2      = {0xfffffffffffffffe,0,0,0};
FrRawElement pRawB2      = {0xffffffffffffffff,0,0,0};

FrRawElement pRawResult3 = {0,0,0,0};
FrRawElement pRawA3      = {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
FrRawElement pRawB3      = {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};

FrRawElement pRawResult4 = {0,0,0,0};
FrRawElement pRawA4      = {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
FrRawElement pRawB4      = {0xffffffffffffffff,0,0,0};


//#define Fr_SHORT 0x00000000
//#define Fr_SHORTMONTGOMERY 0x40000000
//#define Fr_LONG 0x80000000
//#define Fr_LONGMONTGOMERY 0xC0000000

FrElement RawResult = {0,0,{0,0,0,0}};
FrElement RawA = {0xa1f0, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement RawB = {0x1bb8, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement RawResult1 = {0,0,{0,0,0,0}};
FrElement RawA1 = {0xa1f0, Fr_SHORTMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement RawB1 = {0x1bb8, Fr_SHORTMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement RawResult2 = {0,0,{0,0,0,0}};
FrElement RawA2 = {0xa1f0, Fr_LONG,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement RawB2 = {0x1bb8, Fr_LONG,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement RawResult3 = {0,0,{0,0,0,0}};
FrElement RawA3 = {0xa1f0, Fr_LONGMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement RawB3 = {0x1bb8, Fr_LONGMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};



// mul_s1s2
FrElement Result_s1s2 = {0,0,{0,0,0,0}};
FrElement A_s1s2 = {0x1, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B_s1s2 = {0x2, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result1_s1s2 = {0,0,{0,0,0,0}};
FrElement A1_s1s2 = {0x0, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B1_s1s2 = {0x2, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result2_s1s2 = {0,0,{0,0,0,0}};
FrElement A2_s1s2 = {0xa1f0, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_s1s2 = {0x1bb8, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_s1s2 = {0,0,{0,0,0,0}};
FrElement A3_s1s2 = {0xffff, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B3_s1s2 = {0xffff, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

// mul_l1nl2n
FrElement Result_l1nl2n = {0,0,{0,0,0,0}};
FrElement A_l1nl2n = {0x1, Fr_LONG,{0x01,0,0,0}};
FrElement B_l1nl2n = {0x2, Fr_LONG,{0x02,0,0,0}};

FrElement Result1_l1nl2n = {0,0,{0,0,0,0}};
FrElement A1_l1nl2n = {0x0, Fr_LONG,{0x0,0,0,0}};
FrElement B1_l1nl2n = {0x2, Fr_LONG,{0x2,0,0,0}};

FrElement Result2_l1nl2n = {0,0,{0,0,0,0}};
FrElement A2_l1nl2n = {0xa1f0, Fr_LONG,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1nl2n= {0x1bb8, Fr_LONG,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1nl2n = {0,0,{0,0,0,0}};
FrElement A3_l1nl2n = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1nl2n = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

// mul_l1ml2n
FrElement Result_l1ml2n = {0,0,{0,0,0,0}};
FrElement A_l1ml2n = {0x1, Fr_LONGMONTGOMERY,{0x01,0,0,0}};
FrElement B_l1ml2n = {0x2, Fr_LONG,{0x02,0,0,0}};

FrElement Result1_l1ml2n = {0,0,{0,0,0,0}};
FrElement A1_l1ml2n = {0x0, Fr_LONGMONTGOMERY,{0x0,0,0,0}};
FrElement B1_l1ml2n = {0x2, Fr_LONG,{0x2,0,0,0}};

FrElement Result2_l1ml2n = {0,0,{0,0,0,0}};
FrElement A2_l1ml2n = {0xa1f0, Fr_LONGMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1ml2n= {0x1bb8, Fr_LONG,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1ml2n = {0,0,{0,0,0,0}};
FrElement A3_l1ml2n = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1ml2n = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

// mul_l1nl2m
FrElement Result_l1nl2m = {0,0,{0,0,0,0}};
FrElement A_l1nl2m = {0x1, Fr_LONG,{0x01,0,0,0}};
FrElement B_l1nl2m = {0x2, Fr_LONGMONTGOMERY,{0x02,0,0,0}};

FrElement Result1_l1nl2m = {0,0,{0,0,0,0}};
FrElement A1_l1nl2m = {0x0, Fr_LONG,{0x0,0,0,0}};
FrElement B1_l1nl2m = {0x2, Fr_LONGMONTGOMERY,{0x2,0,0,0}};

FrElement Result2_l1nl2m = {0,0,{0,0,0,0}};
FrElement A2_l1nl2m = {0xa1f0, Fr_LONG,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1nl2m= {0x1bb8, Fr_LONGMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1nl2m = {0,0,{0,0,0,0}};
FrElement A3_l1nl2m = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1nl2m = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

// mul_l1ml2m
FrElement Result_l1ml2m = {0,0,{0,0,0,0}};
FrElement A_l1ml2m = {0x1, Fr_LONGMONTGOMERY,{0x01,0,0,0}};
FrElement B_l1ml2m = {0x2, Fr_LONGMONTGOMERY,{0x02,0,0,0}};

FrElement Result1_l1ml2m = {0,0,{0,0,0,0}};
FrElement A1_l1ml2m = {0x0, Fr_LONGMONTGOMERY,{0x0,0,0,0}};
FrElement B1_l1ml2m = {0x2, Fr_LONGMONTGOMERY,{0x2,0,0,0}};

FrElement Result2_l1ml2m = {0,0,{0,0,0,0}};
FrElement A2_l1ml2m = {0xa1f0, Fr_LONGMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1ml2m= {0x1bb8, Fr_LONGMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1ml2m = {0,0,{0,0,0,0}};
FrElement A3_l1ml2m = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1ml2m = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

// mul_l1ns2n
FrElement Result_l1ns2n = {0,0,{0,0,0,0}};
FrElement A_l1ns2n = {0x1, Fr_LONG,{0x01,0,0,0}};
FrElement B_l1ns2n = {0x2, Fr_SHORT,{0x02,0,0,0}};

FrElement Result1_l1ns2n = {0,0,{0,0,0,0}};
FrElement A1_l1ns2n = {0x0, Fr_LONG,{0x0,0,0,0}};
FrElement B1_l1ns2n = {0x2, Fr_SHORT,{0x2,0,0,0}};

FrElement Result2_l1ns2n = {0,0,{0,0,0,0}};
FrElement A2_l1ns2n = {0xa1f0, Fr_LONG,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1ns2n= {0x1bb8, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1ns2n = {0,0,{0,0,0,0}};
FrElement A3_l1ns2n = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1ns2n = {0xffff, Fr_SHORT,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_s1nl2n
FrElement Result_s1nl2n = {0,0,{0,0,0,0}};
FrElement A_s1nl2n = {0x1, Fr_SHORT,{0x01,0,0,0}};
FrElement B_s1nl2n = {0x2, Fr_LONG,{0x02,0,0,0}};

FrElement Result1_s1nl2n = {0,0,{0,0,0,0}};
FrElement A1_s1nl2n = {0x0, Fr_SHORT,{0x0,0,0,0}};
FrElement B1_s1nl2n = {0x2, Fr_LONG,{0x2,0,0,0}};

FrElement Result2_s1nl2n = {0,0,{0,0,0,0}};
FrElement A2_s1nl2n = {0xa1f0, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_s1nl2n= {0x1bb8, Fr_LONG,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_s1nl2n = {0,0,{0,0,0,0}};
FrElement A3_s1nl2n = {0xffff, Fr_SHORT,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_s1nl2n = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_s1nl2m
FrElement Result_s1nl2m = {0,0,{0,0,0,0}};
FrElement A_s1nl2m = {0x1, Fr_SHORT,{0x01,0,0,0}};
FrElement B_s1nl2m = {0x2, Fr_LONGMONTGOMERY,{0x02,0,0,0}};

FrElement Result1_s1nl2m = {0,0,{0,0,0,0}};
FrElement A1_s1nl2m = {0x0, Fr_SHORT,{0x0,0,0,0}};
FrElement B1_s1nl2m = {0x2, Fr_LONGMONTGOMERY,{0x2,0,0,0}};

FrElement Result2_s1nl2m = {0,0,{0,0,0,0}};
FrElement A2_s1nl2m = {0xa1f0, Fr_SHORT,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_s1nl2m = {0x1bb8, Fr_LONGMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_s1nl2m = {0,0,{0,0,0,0}};
FrElement A3_s1nl2m = {0xffff, Fr_SHORT,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_s1nl2m = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_l1ms2n
FrElement Result_l1ms2n = {0,0,{0,0,0,0}};
FrElement A_l1ms2n = {0x1, Fr_LONGMONTGOMERY,{0x01,0,0,0}};
FrElement B_l1ms2n = {0x2, Fr_SHORT,{0x02,0,0,0}};

FrElement Result1_l1ms2n = {0,0,{0,0,0,0}};
FrElement A1_l1ms2n = {0x0, Fr_LONGMONTGOMERY,{0x0,0,0,0}};
FrElement B1_l1ms2n = {0x2, Fr_SHORT,{0x2,0,0,0}};

FrElement Result2_l1ms2n = {0,0,{0,0,0,0}};
FrElement A2_l1ms2n = {0xa1f0, Fr_LONGMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1ms2n= {0x1bb8, Fr_SHORT,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1ms2n = {0,0,{0,0,0,0}};
FrElement A3_l1ms2n = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1ms2n = {0xffff, Fr_SHORT,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_l1ns2m
FrElement Result_l1ns2m = {0,0,{0,0,0,0}};
FrElement A_l1ns2m = {0x1, Fr_LONG,{0x01,0,0,0}};
FrElement B_l1ns2m = {0x2, Fr_SHORTMONTGOMERY,{0x02,0,0,0}};

FrElement Result1_l1ns2m = {0,0,{0,0,0,0}};
FrElement A1_l1ns2m = {0x0, Fr_LONG,{0x0,0,0,0}};
FrElement B1_l1ns2m = {0x2, Fr_SHORTMONTGOMERY,{0x2,0,0,0}};

FrElement Result2_l1ns2m = {0,0,{0,0,0,0}};
FrElement A2_l1ns2m = {0xa1f0, Fr_LONG,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1ns2m= {0x1bb8, Fr_SHORTMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1ns2m = {0,0,{0,0,0,0}};
FrElement A3_l1ns2m = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1ns2m = {0xffff, Fr_SHORTMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_l1ms2m
FrElement Result_l1ms2m = {0,0,{0,0,0,0}};
FrElement A_l1ms2m = {0x1, Fr_LONGMONTGOMERY,{0x01,0,0,0}};
FrElement B_l1ms2m = {0x2, Fr_SHORTMONTGOMERY,{0x02,0,0,0}};

FrElement Result1_l1ms2m = {0,0,{0,0,0,0}};
FrElement A1_l1ms2m = {0x0, Fr_LONGMONTGOMERY,{0x0,0,0,0}};
FrElement B1_l1ms2m = {0x2, Fr_SHORTMONTGOMERY,{0x2,0,0,0}};

FrElement Result2_l1ms2m = {0,0,{0,0,0,0}};
FrElement A2_l1ms2m = {0xa1f0, Fr_LONGMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_l1ms2m= {0x1bb8, Fr_SHORTMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_l1ms2m = {0,0,{0,0,0,0}};
FrElement A3_l1ms2m = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_l1ms2m = {0xffff, Fr_SHORTMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_s1ml2m
FrElement Result_s1ml2m = {0,0,{0,0,0,0}};
FrElement A_s1ml2m = {0x1, Fr_SHORTMONTGOMERY,{0x01,0,0,0}};
FrElement B_s1ml2m = {0x2, Fr_LONGMONTGOMERY,{0x02,0,0,0}};

FrElement Result1_s1ml2m = {0,0,{0,0,0,0}};
FrElement A1_s1ml2m = {0x0, Fr_SHORTMONTGOMERY,{0x0,0,0,0}};
FrElement B1_s1ml2m = {0x2, Fr_LONGMONTGOMERY,{0x2,0,0,0}};

FrElement Result2_s1ml2m = {0,0,{0,0,0,0}};
FrElement A2_s1ml2m = {0xa1f0, Fr_SHORTMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_s1ml2m = {0x1bb8, Fr_LONGMONTGOMERY,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_s1ml2m = {0,0,{0,0,0,0}};
FrElement A3_s1ml2m = {0xffff, Fr_SHORTMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_s1ml2m = {0xffff, Fr_LONGMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};

//mul_s1ml2n
FrElement Result_s1ml2n = {0,0,{0,0,0,0}};
FrElement A_s1ml2n = {0x1, Fr_SHORTMONTGOMERY,{0x01,0,0,0}};
FrElement B_s1ml2n = {0x2, Fr_LONG,{0x02,0,0,0}};

FrElement Result1_s1ml2n = {0,0,{0,0,0,0}};
FrElement A1_s1ml2n = {0x0, Fr_SHORTMONTGOMERY,{0x0,0,0,0}};
FrElement B1_s1ml2n = {0x2, Fr_LONG,{0x2,0,0,0}};

FrElement Result2_s1ml2n = {0,0,{0,0,0,0}};
FrElement A2_s1ml2n = {0xa1f0, Fr_SHORTMONTGOMERY,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
FrElement B2_s1ml2n = {0x1bb8, Fr_LONG,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x0216d0b17f4e44a5}};

FrElement Result3_s1ml2n = {0,0,{0,0,0,0}};
FrElement A3_s1ml2n = {0xffff, Fr_SHORTMONTGOMERY,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
FrElement B3_s1ml2n = {0xffff, Fr_LONG,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};



//FrElement Fr_q = {0, 0x80000000, {0x43e1f593f0000001,
//                                  0x2833e84879b97091,
//                                  0xb85045b68181585d,
//                                  0x30644e72e131a029}};

//FrRawElement Fr_rawq  = {0x43e1f593f0000001,
//                         0x2833e84879b97091,
//                         0xb85045b68181585d,
//                         0x30644e72e131a029};

//extern FrElement Fr_q;
//extern FrRawElement Fr_rawq;

/*
void show_extern_vars()
{
    std::cout << "Fr_q.shortVal= "    << std::hex  << Fr_q.shortVal << '\n';
    std::cout << "Fr_q.type= "        << std::hex  << Fr_q.type << '\n';
    std::cout << "Fr_q.longVal= "     << std::hex  << Fr_q.longVal[0] << '\n';
    std::cout << "Fr_q.longVal= "     << std::hex  << Fr_q.longVal[1] << '\n';
    std::cout << "Fr_q.longVal= "     << std::hex  << Fr_q.longVal[2] << '\n';
    std::cout << "Fr_q.longVal= "     << std::hex  << Fr_q.longVal[3] << '\n';

    std::cout << "Fr_R3.shortVal= "   << std::hex  << Fr_R3.shortVal << '\n';
    std::cout << "Fr_R3.type= "       << std::hex  << Fr_R3.type << '\n';
    std::cout << "Fr_R3.longVal= "    << std::hex  << Fr_R3.longVal[0] << '\n';
    std::cout << "Fr_R3.longVal= "    << std::hex  << Fr_R3.longVal[1] << '\n';
    std::cout << "Fr_R3.longVal= "    << std::hex  << Fr_R3.longVal[2] << '\n';
    std::cout << "Fr_R3.longVal= "    << std::hex  << Fr_R3.longVal[3] << '\n';

    std::cout << "Fr_rawq= " << std::hex << Fr_rawq[0] << '\n';
    std::cout << "Fr_rawq= " << std::hex << Fr_rawq[1] << '\n';
    std::cout << "Fr_rawq= " << std::hex << Fr_rawq[2] << '\n';
    std::cout << "Fr_rawq= " << std::hex << Fr_rawq[3] << '\n';

    std::cout << "Fr_rawR3= " << std::hex << Fr_rawR3[0] << '\n';
    std::cout << "Fr_rawR3= " << std::hex << Fr_rawR3[1] << '\n';
    std::cout << "Fr_rawR3= " << std::hex << Fr_rawR3[2] << '\n';
    std::cout << "Fr_rawR3= " << std::hex << Fr_rawR3[3] << '\n';

    std::cout << "q= " << std::hex << q[0] << '\n';
    std::cout << "q= " << std::hex << q[1] << '\n';
    std::cout << "q= " << std::hex << q[2] << '\n';
    std::cout << "q= " << std::hex << q[3] << '\n';

    std::cout << "half= " << std::hex << half[0] << '\n';
    std::cout << "half= " << std::hex << half[1] << '\n';
    std::cout << "half= " << std::hex << half[2] << '\n';
    std::cout << "half= " << std::hex << half[3] << '\n';

    std::cout << "R2= " << std::hex << R2[0] << '\n';
    std::cout << "R2= " << std::hex << R2[1] << '\n';
    std::cout << "R2= " << std::hex << R2[2] << '\n';
    std::cout << "R2= " << std::hex << R2[3] << '\n';

    std::cout << "R3= " << std::hex << R3[0] << '\n';
    std::cout << "R3= " << std::hex << R3[1] << '\n';
    std::cout << "R3= " << std::hex << R3[2] << '\n';
    std::cout << "R3= " << std::hex << R3[3] << '\n';

    std::cout << "lbomask= " << std::hex << lboMask[0] << '\n';
    std::cout << "lbomask= " << std::hex << lboMask[1] << '\n';
    std::cout << "lbomask= " << std::hex << lboMask[2] << '\n';
    std::cout << "lbomask= " << std::hex << lboMask[3] << '\n';

    std::cout << "np= " << std::hex << np << '\n';

    std::cout << "np= "  << std::dec << np << '\n';
//    std::cout << "np= " << std::hex << np[1] << '\n';
//    std::cout << "np= " << std::hex << np[2] << '\n';
//    std::cout << "np= " << std::hex << np[3] << '\n';
}
*/

void compare_rawResult(FrRawElement pRawResult_asm, FrRawElement pRawResult_c, int idx, std::string TestName)
{
    if (pRawResult_asm[0] != pRawResult_c[0] ||
        pRawResult_asm[1] != pRawResult_c[1] ||
        pRawResult_asm[2] != pRawResult_c[2] ||
        pRawResult_asm[3] != pRawResult_c[3])
    {
        std::cout << TestName << idx << " failed!" << "\n";
    }
    else
    {
        std::cout << TestName << idx << " succeed!" << "\n";
    }
}

void compare_Result(PFrElement pResult_asm, PFrElement pResult_c, int idx, std::string TestName)
{
    if (pResult_asm->shortVal != pResult_c->shortVal     ||
        pResult_asm->longVal[0] != pResult_c->longVal[0] ||
        pResult_asm->longVal[1] != pResult_c->longVal[1] ||
        pResult_asm->longVal[2] != pResult_c->longVal[2] ||
        pResult_asm->longVal[3] != pResult_c->longVal[3])
    {
        std::cout << TestName << idx << " failed!" << "\n";
    }
    else
    {
        std::cout << TestName << idx << " succeed!" << "\n";
    }
}

void Fr_Rw_Neg_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_Neg_test " << idx << ": " <<  '\n';
    Fr_rawNeg(pRawResult, pRawA);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    //std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_Rw_Neg_unit_test()
{
    //Fr_Rw_Neg_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawResult0= {0xa1f0fac9f8000001,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    //Fr_Rw_Neg_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0x43e1f593f0000000,0x2833e84879b97091,0xb85045b68181585d,0x30644e72e131a029};
    //Fr_Rw_Neg_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x43e1f593f0000003,0x2833e84879b97090,0xb85045b68181585d,0x30644e72e131a029};
    //Fr_Rw_Neg_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawResult3= {0x43e1f593f0000003,0x2833e84879b97092,0xb85045b68181585e,0x30644e72e131a02a};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawNeg(pRawResult0_c, pRawA0);
    Fr_rawNeg(pRawResult1_c, pRawA1);
    Fr_rawNeg(pRawResult2_c, pRawA2);
    Fr_rawNeg(pRawResult3_c, pRawA3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_Neg_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_Neg_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_Neg_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_Neg_unit_test");
}


void Fr_Rw_copy_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_copy_test " << idx << ": " <<  '\n';
    Fr_rawCopy(pRawResult, pRawA);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    //std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_Rw_copy_unit_test()
{
    //Fr_Rw_copy_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawResult0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    //Fr_Rw_copy_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0x1,0x0,0x0,0x0};
    //Fr_Rw_copy_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0xfffffffffffffffe,0x0,0x0,0x0};
    //Fr_Rw_copy_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawResult3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawCopy(pRawResult0_c, pRawA0);
    Fr_rawCopy(pRawResult1_c, pRawA1);
    Fr_rawCopy(pRawResult2_c, pRawA2);
    Fr_rawCopy(pRawResult3_c, pRawA3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_copy_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_copy_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_copy_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_copy_unit_test");
}


void Fr_Rw_add_unit_test()
{
    //Fr_rawAdd Test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawB0= {0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5};
    FrRawElement pRawResult0= {0xbda9e10fa6216da7,0xe8182ed62039122b,0x6871a618947c2cb3,0x1a48f7eaefe714ba};
    //Fr_rawAdd Test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawB1= {0x2,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0x3,0x0,0x0,0x0};
    //Fr_rawAdd Test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawB2= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0xfffffffffffffffd,0x1,0x0,0x0};
    //Fr_rawAdd Test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawB3= {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
    FrRawElement pRawResult3= {0xbc1e0a6c0ffffffc,0xd7cc17b786468f6d,0x47afba497e7ea7a1,0xcf9bb18d1ece5fd5};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawAdd(pRawResult0_c, pRawA0, pRawB0);
    Fr_rawAdd(pRawResult1_c, pRawA1, pRawB1);
    Fr_rawAdd(pRawResult2_c, pRawA2, pRawB2);
    Fr_rawAdd(pRawResult3_c, pRawA3, pRawB3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_add_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_add_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_add_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_add_unit_test");
}

void Fr_Rw_sub_unit_test()
{
    //Fr_Rw_sub_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawB0= {0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5};
    FrRawElement pRawResult0= {0x8638148449de9259,0x401bb97259805e65,0x4fde9f9ded052ba9,0x161b5687f14a8b6f};
    //Fr_Rw_sub_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawB1= {0x2,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0x43e1f593f0000000,0x2833e84879b97091,0xb85045b68181585d,0x30644e72e131a029};
    //Fr_Rw_sub_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawB2= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x43e1f593f0000000,0x2833e84879b97091,0xb85045b68181585d,0x30644e72e131a029};
    //Fr_Rw_sub_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawB3= {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
    FrRawElement pRawResult3= {0x43e1f593f0000000,0x2833e84879b97090,0xb85045b68181585c,0x30644e72e131a028};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawSub(pRawResult0_c, pRawA0, pRawB0);
    Fr_rawSub(pRawResult1_c, pRawA1, pRawB1);
    Fr_rawSub(pRawResult2_c, pRawA2, pRawB2);
    Fr_rawSub(pRawResult3_c, pRawA3, pRawB3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_sub_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_sub_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_sub_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_sub_unit_test");


}

void Fr_Rw_add_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_rawAdd Test " << idx << ": " <<  '\n';
    Fr_rawAdd(pRawResult, pRawA, pRawB);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}


void Fr_Rw_sub_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_sub_test " << idx << ": " <<  '\n';
    Fr_rawSub(pRawResult, pRawA, pRawB);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_Rw_mul_unit_test()
{
    //Fr_Rw_mul_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawB0= {0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5};
    FrRawElement pRawResult0= {0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d};
    //Fr_Rw_mul_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawB1= {0x2,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39};
    //Fr_Rw_mul_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawB2= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x8663902cfae5d423,0x95d2440ac403ddd3,0x1ad411b88e349a0f,0x1ebf106109e4fa8d};
    //Fr_Rw_mul_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawB3= {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
    FrRawElement pRawResult3= {0xd13604f1e300865c,0xba58b3d2a99f4ba5,0x1b4e415146d47f95,0x55c593ff9cfbf0a};
    //Fr_Rw_mul_test 4:
    FrRawElement pRawA4= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawB4= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawResult4= {0x1d0a8ff4c8e5744c,0x6fd9959908f97ec,0xdfe72d24fcdef34e,0xd1c7f8bb929dbb};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;
    FrRawElement pRawResult4_c;

    Fr_rawMMul(pRawResult0_c, pRawA0, pRawB0);
    Fr_rawMMul(pRawResult1_c, pRawA1, pRawB1);
    Fr_rawMMul(pRawResult2_c, pRawA2, pRawB2);
    Fr_rawMMul(pRawResult3_c, pRawA3, pRawB3);
    Fr_rawMMul(pRawResult4_c, pRawA4, pRawB4);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_mul_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_mul_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_mul_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_mul_unit_test");
    compare_rawResult(pRawResult4, pRawResult4_c, 4, "Fr_Rw_mul_unit_test");
}

void Fr_Rw_mul_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_mul_test " << idx << ": " <<  '\n';
    Fr_rawMMul(pRawResult, pRawA, pRawB);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << '\n';
}


void Fr_Rw_Msquare_unit_test()
{
    //Fr_Rw_Msquare_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawResult0= {0x9907e2cb536c4654,0xd65db18eb521336a,0xe31a6546c6ec385,0x1dad258dd14a255c};
    //Fr_Rw_Msquare_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0xdc5ba0056db1194e,0x90ef5a9e111ec87,0xc8260de4aeb85d5d,0x15ebf95182c5551c};
    //Fr_Rw_Msquare_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0xa36e2021c3cb4871,0x9ccfdd64549375be,0xfabb3edd8b138d5d,0x1f90d859c5779848};
    //Fr_Rw_Msquare_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawResult3= {0x3ff409a0d3b30d18,0xca2027949dd16d47,0x6c8c4187ce125dad,0x3b5af5c48558e40};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawMSquare(pRawResult0_c, pRawA0);
    Fr_rawMSquare(pRawResult1_c, pRawA1);
    Fr_rawMSquare(pRawResult2_c, pRawA2);
    Fr_rawMSquare(pRawResult3_c, pRawA3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_Msquare_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_Msquare_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_Msquare_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_Msquare_unit_test");
}

void Fr_Rw_Msquare_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_Msquare_test " << idx << ": " <<  '\n';
    Fr_rawMSquare(pRawResult, pRawA);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    //std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_Rw_mul1_unit_test()
{
    //Fr_Rw_mul1_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawB0= {0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5};
    FrRawElement pRawResult0= {0xf599ddfbad86bc06,0xec1c0a17893c85cd,0x5d482c29ab80ec64,0x4d4face96bf58f3};
    //Fr_Rw_mul1_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawB1= {0x2,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39};
    //Fr_Rw_mul1_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawB2= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x8663902cfae5d423,0x95d2440ac403ddd3,0x1ad411b88e349a0f,0x1ebf106109e4fa8d};
    //Fr_Rw_mul1_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawB3= {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
    FrRawElement pRawResult3= {0x35f905313fdf50bb,0x5bab176e33b97efa,0xafd63944c55782d,0x1402c8cfdb71d335};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawMMul1(pRawResult0_c, pRawA0, pRawB0[0]);
    Fr_rawMMul1(pRawResult1_c, pRawA1, pRawB1[0]);
    Fr_rawMMul1(pRawResult2_c, pRawA2, pRawB2[0]);
    Fr_rawMMul1(pRawResult3_c, pRawA3, pRawB3[0]);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_mul1_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_mul1_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_mul1_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_mul1_unit_test");
}

void Fr_Rw_mul1_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_mul1_test " << idx << ": " <<  '\n';
    Fr_rawMMul1(pRawResult, pRawA, pRawB[0]);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_Rw_ToMontgomery_unit_test()
{
    //Fr_Rw_ToMontgomery_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawResult0= {0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d};
    //Fr_Rw_ToMontgomery_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0xac96341c4ffffffb,0x36fc76959f60cd29,0x666ea36f7879462e,0xe0a77c19a07df2f};
    //Fr_Rw_ToMontgomery_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x5b9a85c0dc5fb590,0x293a0258129f96b,0xd31fd70514055493,0x546132966296a07};
    //Fr_Rw_ToMontgomery_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawResult3= {0x8eaddd03c0bcc45a,0x1d0775cf53f57853,0xacb9a1fdb8079310,0x1b7838d45d9b3577};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawToMontgomery(pRawResult0_c, pRawA0);
    Fr_rawToMontgomery(pRawResult1_c, pRawA1);
    Fr_rawToMontgomery(pRawResult2_c, pRawA2);
    Fr_rawToMontgomery(pRawResult3_c, pRawA3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_ToMontgomery_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_ToMontgomery_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_ToMontgomery_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_ToMontgomery_unit_test");
}

void Fr_Rw_ToMontgomery_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_ToMontgomery_test " << idx << ": " <<  '\n';
    Fr_rawToMontgomery(pRawResult, pRawA);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    //std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_rawIsEq_test(uint64_t uRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_rawIsEq " << idx << ": " <<  '\n';
    uRawResult = Fr_rawIsEq(pRawA, pRawB);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< uRawResult << "};"<< '\n';// << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}


void Fr_Rw_IsEq_unit_test()
{
    //Fr_rawIsEq 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawB0= {0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5};
    FrRawElement pRawResult0= {0x0};
    //Fr_rawIsEq 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawB1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0x1};
    //Fr_rawIsEq 2:
    FrRawElement pRawA2= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawB2= {0xffffffffffffffff,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x1};
    //Fr_rawIsEq 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawB3= {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
    FrRawElement pRawResult3= {0x0};

    FrRawElement pRawResult0_c = {0};
    FrRawElement pRawResult1_c = {0};
    FrRawElement pRawResult2_c = {0};
    FrRawElement pRawResult3_c = {0};

    pRawResult0_c[0] = Fr_rawIsEq(pRawA0, pRawB0);
    pRawResult1_c[0] = Fr_rawIsEq(pRawA1, pRawB1);
    pRawResult2_c[0] = Fr_rawIsEq(pRawA2, pRawB2);
    pRawResult3_c[0] = Fr_rawIsEq(pRawA3, pRawB3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_IsEq_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_IsEq_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_IsEq_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_IsEq_unit_test");
}


void Fr_rawIsZero_test(uint64_t uRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_rawIsZero_test " << idx << ": " <<  '\n';
    uRawResult = Fr_rawIsZero(pRawA);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    //std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< uRawResult << "};"<< '\n';// << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}


void Fr_rawIsZero_unit_test()
{
    //Fr_rawIsZero_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawResult0= {0x0};
    //Fr_rawIsZero_test 1:
    FrRawElement pRawA1= {0x0,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0x1};
    //Fr_rawIsZero_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x0};
    //Fr_rawIsZero_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawResult3= {0x0};

    FrRawElement pRawResult0_c = {0};
    FrRawElement pRawResult1_c = {0};
    FrRawElement pRawResult2_c = {0};
    FrRawElement pRawResult3_c = {0};

    pRawResult0_c[0] = Fr_rawIsZero(pRawA0);
    pRawResult1_c[0] = Fr_rawIsZero(pRawA1);
    pRawResult2_c[0] = Fr_rawIsZero(pRawA2);
    pRawResult3_c[0] = Fr_rawIsZero(pRawA3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_rawIsZero_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_rawIsZero_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_rawIsZero_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_rawIsZero_unit_test");
}

void Fr_Rw_FromMontgomery_unit_test()
{
    //Fr_Rw_FromMontgomery_test 0:
    FrRawElement pRawA0= {0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014};
    FrRawElement pRawResult0= {0x55b425913927735a,0xa3ac6d7389307a4d,0x543d3ec42a2529ae,0x256e51ca1fcef59b};
    //Fr_Rw_FromMontgomery_test 1:
    FrRawElement pRawA1= {0x1,0x0,0x0,0x0};
    FrRawElement pRawResult1= {0xdc5ba0056db1194e,0x90ef5a9e111ec87,0xc8260de4aeb85d5d,0x15ebf95182c5551c};
    //Fr_Rw_FromMontgomery_test 2:
    FrRawElement pRawA2= {0xfffffffffffffffe,0x0,0x0,0x0};
    FrRawElement pRawResult2= {0x26d7659f271a8bb3,0x21364eeee929d8a6,0xd869189184a2650f,0x2f92867a259f026d};
    //Fr_Rw_FromMontgomery_test 3:
    FrRawElement pRawA3= {0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe,0xfffffffffffffffe};
    FrRawElement pRawResult3= {0x3114fb0a8790445e,0x3c686fb82b0dbda3,0xa509fd6ff15d77e,0x247132c3c886548};

    FrRawElement pRawResult0_c;
    FrRawElement pRawResult1_c;
    FrRawElement pRawResult2_c;
    FrRawElement pRawResult3_c;

    Fr_rawFromMontgomery(pRawResult0_c, pRawA0);
    Fr_rawFromMontgomery(pRawResult1_c, pRawA1);
    Fr_rawFromMontgomery(pRawResult2_c, pRawA2);
    Fr_rawFromMontgomery(pRawResult3_c, pRawA3);

    compare_rawResult(pRawResult0, pRawResult0_c, 0, "Fr_Rw_FromMontgomery_unit_test");
    compare_rawResult(pRawResult1, pRawResult1_c, 1, "Fr_Rw_FromMontgomery_unit_test");
    compare_rawResult(pRawResult2, pRawResult2_c, 2, "Fr_Rw_FromMontgomery_unit_test");
    compare_rawResult(pRawResult3, pRawResult3_c, 3, "Fr_Rw_FromMontgomery_unit_test");
}

void Fr_Rw_FromMontgomery_test(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB, int idx)
{
    std::cout << "//Fr_Rw_FromMontgomery_test " << idx << ": " <<  '\n';
    Fr_rawFromMontgomery(pRawResult, pRawA);
    std::cout << "FrRawElement pRawA" << idx << "= " << std::hex << "{0x" << pRawA[0] << ",0x" << pRawA[1] << ",0x" << pRawA[2] << ",0x" << pRawA[3] << "};"<< '\n';
    //std::cout << "FrRawElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrRawElement pRawResult" << idx << "= " << std::hex << "{0x"<< pRawResult[0] << ",0x" << pRawResult[1] << ",0x" << pRawResult[2] << ",0x" << pRawResult[3] << "};"<< '\n';
}

void Fr_toNormal_unit_test()
{
    //Fr_toNormal_test 0:
    FrElement pA0= {0xa1f0,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pResult0= {0xa1f0,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    //Fr_toNormal_test 1:
    FrElement pA1= {0xa1f0,0x40000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pResult1= {0xa1f0,0x40000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    //Fr_toNormal_test 2:
    FrElement pA2= {0xa1f0,0x80000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pResult2= {0xa1f0,0x80000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    //Fr_toNormal_test 3:
    FrElement pA3= {0xa1f0,0xc0000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pResult3= {0x0,0x80000000,{0x55b425913927735a,0xa3ac6d7389307a4d,0x543d3ec42a2529ae,0x256e51ca1fcef59b}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_toNormal(&Result0_c, &pA0);
    Fr_toNormal(&Result1_c, &pA1);
    Fr_toNormal(&Result2_c, &pA2);
    Fr_toNormal(&Result3_c, &pA3);

    compare_Result(&pResult0, &Result0_c, 0, "Fr_toNormal_unit_test");
    compare_Result(&pResult1, &Result1_c, 1, "Fr_toNormal_unit_test");
    compare_Result(&pResult2, &Result2_c, 2, "Fr_toNormal_unit_test");
    compare_Result(&pResult3, &Result3_c, 3, "Fr_toNormal_unit_test");
}

void Fr_toNormal_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_toNormal_test " << idx << ": " <<  '\n';
    Fr_toNormal(pResult, pA);
    std::cout << "FrElement pA" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    //std::cout << "FrElement pRawB" << idx << "= " << std::hex << "{0x" << pRawB[0] << ",0x" << pRawB[1] << ",0x" << pRawB[2] << ",0x" << pRawB[3] << "};"<< '\n';
    std::cout << "FrElement pResult" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_s1s2_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_s1s2_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_s1s2" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_s1s2" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_s1s2" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_s1s2_unit_test()
{
    //Fr_mul_s1s2_test 0:
    FrElement pA_s1s20= {0x1,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1s20= {0x2,0x0,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1s20= {0x0,0x80000000,{0x2,0x0,0x0,0x0}};
    //Fr_mul_s1s2_test 1:
    FrElement pA_s1s21= {0x0,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1s21= {0x2,0x0,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1s21= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_s1s2_test 2:
    FrElement pA_s1s22= {0xa1f0,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1s22= {0x1bb8,0x0,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1s22= {0x0,0x80000000,{0x1188b480,0x0,0x0,0x0}};
    //Fr_mul_s1s2_test 3:
    FrElement pA_s1s23= {0xffff,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1s23= {0xffff,0x0,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1s23= {0x0,0x80000000,{0xfffe0001,0x0,0x0,0x0}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_s1s20, &pB_s1s20);
    Fr_mul(&Result1_c, &pA_s1s21, &pB_s1s21);
    Fr_mul(&Result2_c, &pA_s1s22, &pB_s1s22);
    Fr_mul(&Result3_c, &pA_s1s23, &pB_s1s23);

    compare_Result(&pResult_s1s20, &Result0_c, 0, "Fr_mul_s1s2_unit_test");
    compare_Result(&pResult_s1s21, &Result1_c, 1, "Fr_mul_s1s2_unit_test");
    compare_Result(&pResult_s1s22, &Result2_c, 2, "Fr_mul_s1s2_unit_test");
    compare_Result(&pResult_s1s23, &Result3_c, 3, "Fr_mul_s1s2_unit_test");
}

void Fr_mul_l1nl2n_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1nl2n_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1nl2n" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1nl2n" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1nl2n" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_l1nl2n_unit_test()
{
    //Fr_mul_l1nl2n_test 0:
    FrElement pA_l1nl2n0= {0x1,0x80000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1nl2n0= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1nl2n0= {0x0,0xc0000000,{0x592c68389ffffff6,0x6df8ed2b3ec19a53,0xccdd46def0f28c5c,0x1c14ef83340fbe5e}};
    //Fr_mul_l1nl2n_test 1:
    FrElement pA_l1nl2n1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1nl2n1= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1nl2n1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1nl2n_test 2:
    FrElement pA_l1nl2n2= {0xa1f0,0x80000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1nl2n2= {0x1bb8,0x80000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1nl2n2= {0x0,0xc0000000,{0x1497892315a07fe1,0x930f99e96b3b9535,0x73b1e28430b17066,0x29e821cd214b6d6b}};
    //Fr_mul_l1nl2n_test 3:
    FrElement pA_l1nl2n3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1nl2n3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1nl2n3= {0x0,0xc0000000,{0x19094ca438fc19d0,0x4f1502bc99846068,0x5cc3236f2303a977,0x17808a731cd75a48}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1nl2n0, &pB_l1nl2n0);
    Fr_mul(&Result1_c, &pA_l1nl2n1, &pB_l1nl2n1);
    Fr_mul(&Result2_c, &pA_l1nl2n2, &pB_l1nl2n2);
    Fr_mul(&Result3_c, &pA_l1nl2n3, &pB_l1nl2n3);

    compare_Result(&pResult_l1nl2n0, &Result0_c, 0, "Fr_mul_l1nl2n_unit_test");
    compare_Result(&pResult_l1nl2n1, &Result1_c, 1, "Fr_mul_l1nl2n_unit_test");
    compare_Result(&pResult_l1nl2n2, &Result2_c, 2, "Fr_mul_l1nl2n_unit_test");
    compare_Result(&pResult_l1nl2n3, &Result3_c, 3, "Fr_mul_l1nl2n_unit_test");
}

void Fr_mul_l1ml2n_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1ml2n_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1ml2n" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1ml2n" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1ml2n" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_l1ml2n_unit_test()
{
    //Fr_mul_l1ml2n_test 0:
    FrElement pA_l1ml2n0= {0x1,0xc0000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1ml2n0= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ml2n0= {0x0,0x80000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_l1ml2n_test 1:
    FrElement pA_l1ml2n1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1ml2n1= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ml2n1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1ml2n_test 2:
    FrElement pA_l1ml2n2= {0xa1f0,0xc0000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1ml2n2= {0x1bb8,0x80000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1ml2n2= {0x0,0x80000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_l1ml2n_test 3:
    FrElement pA_l1ml2n3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1ml2n3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1ml2n3= {0x0,0x80000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1ml2n0, &pB_l1ml2n0);
    Fr_mul(&Result1_c, &pA_l1ml2n1, &pB_l1ml2n1);
    Fr_mul(&Result2_c, &pA_l1ml2n2, &pB_l1ml2n2);
    Fr_mul(&Result3_c, &pA_l1ml2n3, &pB_l1ml2n3);

    compare_Result(&pResult_l1ml2n0, &Result0_c, 0, "Fr_mul_l1ml2n_unit_test");
    compare_Result(&pResult_l1ml2n1, &Result1_c, 1, "Fr_mul_l1ml2n_unit_test");
    compare_Result(&pResult_l1ml2n2, &Result2_c, 2, "Fr_mul_l1ml2n_unit_test");
    compare_Result(&pResult_l1ml2n3, &Result3_c, 3, "Fr_mul_l1ml2n_unit_test");
}


void Fr_mul_l1ml2m_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1ml2m_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1ml2m" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1ml2m" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1ml2m" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_l1ml2m_unit_test()
{
    //Fr_mul_l1ml2m_test 0:
    FrElement pA_l1ml2m0= {0x1,0xc0000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1ml2m0= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ml2m0= {0x0,0xc0000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_l1ml2m_test 1:
    FrElement pA_l1ml2m1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1ml2m1= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ml2m1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1ml2m_test 2:
    FrElement pA_l1ml2m2= {0xa1f0,0xc0000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1ml2m2= {0x1bb8,0xc0000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1ml2m2= {0x0,0xc0000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_l1ml2m_test 3:
    FrElement pA_l1ml2m3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1ml2m3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1ml2m3= {0x0,0xc0000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1ml2m0, &pB_l1ml2m0);
    Fr_mul(&Result1_c, &pA_l1ml2m1, &pB_l1ml2m1);
    Fr_mul(&Result2_c, &pA_l1ml2m2, &pB_l1ml2m2);
    Fr_mul(&Result3_c, &pA_l1ml2m3, &pB_l1ml2m3);

    compare_Result(&pResult_l1ml2m0, &Result0_c, 0, "Fr_mul_l1ml2m_unit_test");
    compare_Result(&pResult_l1ml2m1, &Result1_c, 1, "Fr_mul_l1ml2m_unit_test");
    compare_Result(&pResult_l1ml2m2, &Result2_c, 2, "Fr_mul_l1ml2m_unit_test");
    compare_Result(&pResult_l1ml2m3, &Result3_c, 3, "Fr_mul_l1ml2m_unit_test");
}

void Fr_mul_l1nl2m_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1nl2m_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1nl2m" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1nl2m" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1nl2m" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_l1nl2m_unit_test()
{
    //Fr_mul_l1nl2m_test 0:
    FrElement pA_l1nl2m0= {0x1,0x80000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1nl2m0= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1nl2m0= {0x0,0x80000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_l1nl2m_test 1:
    FrElement pA_l1nl2m1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1nl2m1= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1nl2m1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1nl2m_test 2:
    FrElement pA_l1nl2m2= {0xa1f0,0x80000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1nl2m2= {0x1bb8,0xc0000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1nl2m2= {0x0,0x80000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_l1nl2m_test 3:
    FrElement pA_l1nl2m3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1nl2m3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1nl2m3= {0x0,0x80000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};
    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1nl2m0, &pB_l1nl2m0);
    Fr_mul(&Result1_c, &pA_l1nl2m1, &pB_l1nl2m1);
    Fr_mul(&Result2_c, &pA_l1nl2m2, &pB_l1nl2m2);
    Fr_mul(&Result3_c, &pA_l1nl2m3, &pB_l1nl2m3);

    compare_Result(&pResult_l1nl2m0, &Result0_c, 0, "Fr_mul_l1nl2m_unit_test");
    compare_Result(&pResult_l1nl2m1, &Result1_c, 1, "Fr_mul_l1nl2m_unit_test");
    compare_Result(&pResult_l1nl2m2, &Result2_c, 2, "Fr_mul_l1nl2m_unit_test");
    compare_Result(&pResult_l1nl2m3, &Result3_c, 3, "Fr_mul_l1nl2m_unit_test");
}

void Fr_mul_l1ns2n_unit_test()
{
    //Fr_mul_l1ns2n_test 0:
    FrElement pA_l1ns2n0= {0x1,0x80000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1ns2n0= {0x2,0x0,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ns2n0= {0x0,0xc0000000,{0x592c68389ffffff6,0x6df8ed2b3ec19a53,0xccdd46def0f28c5c,0x1c14ef83340fbe5e}};
    //Fr_mul_l1ns2n_test 1:
    FrElement pA_l1ns2n1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1ns2n1= {0x2,0x0,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ns2n1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1ns2n_test 2:
    FrElement pA_l1ns2n2= {0xa1f0,0x80000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1ns2n2= {0x1bb8,0x0,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1ns2n2= {0x0,0xc0000000,{0x2d67d8d2e0004952,0xaddd11ecde7f7ae3,0xed975f635da0de4d,0x1a7fe303489132eb}};
    //Fr_mul_l1ns2n_test 3:
    FrElement pA_l1ns2n3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1ns2n3= {0xffff,0x0,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1ns2n3= {0x0,0xc0000000,{0x3fa7b78c6f8ad18e,0x8906f63f7f752307,0x3d4ab0ac8b21d4aa,0xaeb97c8bbd84e34}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1ns2n0, &pB_l1ns2n0);
    Fr_mul(&Result1_c, &pA_l1ns2n1, &pB_l1ns2n1);
    Fr_mul(&Result2_c, &pA_l1ns2n2, &pB_l1ns2n2);
    Fr_mul(&Result3_c, &pA_l1ns2n3, &pB_l1ns2n3);

    compare_Result(&pResult_l1ns2n0, &Result0_c, 0, "Fr_mul_l1ns2n_unit_test");
    compare_Result(&pResult_l1ns2n1, &Result1_c, 1, "Fr_mul_l1ns2n_unit_test");
    compare_Result(&pResult_l1ns2n2, &Result2_c, 2, "Fr_mul_l1ns2n_unit_test");
    compare_Result(&pResult_l1ns2n3, &Result3_c, 3, "Fr_mul_l1ns2n_unit_test");
}

void Fr_mul_l1ns2n_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1ns2n_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1ns2n" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1ns2n" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1ns2n" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_s1nl2n_unit_test()
{
    //Fr_mul_s1nl2n_test 0:
    FrElement pA_s1nl2n0= {0x1,0x0,{0x1,0x0,0x0,0x0}};
    FrElement pB_s1nl2n0= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1nl2n0= {0x0,0xc0000000,{0x592c68389ffffff6,0x6df8ed2b3ec19a53,0xccdd46def0f28c5c,0x1c14ef83340fbe5e}};
    //Fr_mul_s1nl2n_test 1:
    FrElement pA_s1nl2n1= {0x0,0x0,{0x0,0x0,0x0,0x0}};
    FrElement pB_s1nl2n1= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1nl2n1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_s1nl2n_test 2:
    FrElement pA_s1nl2n2= {0xa1f0,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1nl2n2= {0x1bb8,0x80000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1nl2n2= {0x0,0xc0000000,{0x3c79e7002385099,0x69bfe0da5a608f7b,0x3dbd93ce32b4e2b3,0x773561b6a940451}};
    //Fr_mul_s1nl2n_test 3:
    FrElement pA_s1nl2n3= {0xffff,0x0,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_s1nl2n3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_s1nl2n3= {0x0,0xc0000000,{0x3fa7b78c6f8ad18e,0x8906f63f7f752307,0x3d4ab0ac8b21d4aa,0xaeb97c8bbd84e34}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_s1nl2n0, &pB_s1nl2n0);
    Fr_mul(&Result1_c, &pA_s1nl2n1, &pB_s1nl2n1);
    Fr_mul(&Result2_c, &pA_s1nl2n2, &pB_s1nl2n2);
    Fr_mul(&Result3_c, &pA_s1nl2n3, &pB_s1nl2n3);

    compare_Result(&pResult_s1nl2n0, &Result0_c, 0, "Fr_mul_s1nl2n_unit_test");
    compare_Result(&pResult_s1nl2n1, &Result1_c, 1, "Fr_mul_s1nl2n_unit_test");
    compare_Result(&pResult_s1nl2n2, &Result2_c, 2, "Fr_mul_s1nl2n_unit_test");
    compare_Result(&pResult_s1nl2n3, &Result3_c, 3, "Fr_mul_s1nl2n_unit_test");
}

void Fr_mul_s1nl2n_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_s1nl2n_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_s1nl2n" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_s1nl2n" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_s1nl2n" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_s1nl2m_unit_test()
{
    //Fr_mul_s1nl2m_test 0:
    FrElement pA_s1nl2m0= {0x1,0x0,{0x1,0x0,0x0,0x0}};
    FrElement pB_s1nl2m0= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1nl2m0= {0x0,0x80000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_s1nl2m_test 1:
    FrElement pA_s1nl2m1= {0x0,0x0,{0x0,0x0,0x0,0x0}};
    FrElement pB_s1nl2m1= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1nl2m1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_s1nl2m_test 2:
    FrElement pA_s1nl2m2= {0xa1f0,0x0,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1nl2m2= {0x1bb8,0xc0000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1nl2m2= {0x0,0x80000000,{0xd708561abffca754,0x6c6d984a2702a36a,0xc0f6e8587da122fb,0x164b29d2c31ce3ab}};
    //Fr_mul_s1nl2m_test 3:
    FrElement pA_s1nl2m3= {0xffff,0x0,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_s1nl2m3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_s1nl2m3= {0x0,0x80000000,{0x808d8e74d4648d45,0x5706a97c2dc05e64,0x5755e426e15ac79c,0xd0410ffa0ae732d}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_s1nl2m0, &pB_s1nl2m0);
    Fr_mul(&Result1_c, &pA_s1nl2m1, &pB_s1nl2m1);
    Fr_mul(&Result2_c, &pA_s1nl2m2, &pB_s1nl2m2);
    Fr_mul(&Result3_c, &pA_s1nl2m3, &pB_s1nl2m3);

    compare_Result(&pResult_s1nl2m0, &Result0_c, 0, "Fr_mul_s1nl2m_unit_test");
    compare_Result(&pResult_s1nl2m1, &Result1_c, 1, "Fr_mul_s1nl2m_unit_test");
    compare_Result(&pResult_s1nl2m2, &Result2_c, 2, "Fr_mul_s1nl2m_unit_test");
    compare_Result(&pResult_s1nl2m3, &Result3_c, 3, "Fr_mul_s1nl2m_unit_test");
}

void Fr_mul_s1nl2m_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_s1nl2m_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_s1nl2m" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_s1nl2m" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_s1nl2m" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}


void Fr_mul_l1ms2n_unit_test()
{
    //Fr_mul_l1ms2n_test 0:
    FrElement pA_l1ms2n0= {0x1,0xc0000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1ms2n0= {0x2,0x0,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ms2n0= {0x0,0x80000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_l1ms2n_test 1:
    FrElement pA_l1ms2n1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1ms2n1= {0x2,0x0,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ms2n1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1ms2n_test 2:
    FrElement pA_l1ms2n2= {0xa1f0,0xc0000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1ms2n2= {0x1bb8,0x0,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1ms2n2= {0x0,0x80000000,{0x5d70bdff3d855140,0xfab648d14060e580,0xc8cd54f7f14513ba,0x23995be618ce6b27}};
    //Fr_mul_l1ms2n_test 3:
    FrElement pA_l1ms2n3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1ms2n3= {0xffff,0x0,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1ms2n3= {0x0,0x80000000,{0x808d8e74d4648d45,0x5706a97c2dc05e64,0x5755e426e15ac79c,0xd0410ffa0ae732d}};
    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1ms2n0, &pB_l1ms2n0);
    Fr_mul(&Result1_c, &pA_l1ms2n1, &pB_l1ms2n1);
    Fr_mul(&Result2_c, &pA_l1ms2n2, &pB_l1ms2n2);
    Fr_mul(&Result3_c, &pA_l1ms2n3, &pB_l1ms2n3);

    compare_Result(&pResult_l1ms2n0, &Result0_c, 0, "Fr_mul_l1ms2n_unit_test");
    compare_Result(&pResult_l1ms2n1, &Result1_c, 1, "Fr_mul_l1ms2n_unit_test");
    compare_Result(&pResult_l1ms2n2, &Result2_c, 2, "Fr_mul_l1ms2n_unit_test");
    compare_Result(&pResult_l1ms2n3, &Result3_c, 3, "Fr_mul_l1ms2n_unit_test");
}

void Fr_mul_l1ms2n_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1ms2n_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1ms2n" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1ms2n" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1ms2n" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}


void Fr_mul_l1ns2m_unit_test()
{
    //Fr_mul_l1ns2m_test 0:
    FrElement pA_l1ns2m0= {0x1,0x80000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1ns2m0= {0x2,0x40000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ns2m0= {0x0,0x80000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_l1ns2m_test 1:
    FrElement pA_l1ns2m1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1ns2m1= {0x2,0x40000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ns2m1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1ns2m_test 2:
    FrElement pA_l1ns2m2= {0xa1f0,0x80000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1ns2m2= {0x1bb8,0x40000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1ns2m2= {0x0,0x80000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_l1ns2m_test 3:
    FrElement pA_l1ns2m3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1ns2m3= {0xffff,0x40000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1ns2m3= {0x0,0x80000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1ns2m0, &pB_l1ns2m0);
    Fr_mul(&Result1_c, &pA_l1ns2m1, &pB_l1ns2m1);
    Fr_mul(&Result2_c, &pA_l1ns2m2, &pB_l1ns2m2);
    Fr_mul(&Result3_c, &pA_l1ns2m3, &pB_l1ns2m3);

    compare_Result(&pResult_l1ns2m0, &Result0_c, 0, "Fr_mul_l1ns2m_unit_test");
    compare_Result(&pResult_l1ns2m1, &Result1_c, 1, "Fr_mul_l1ns2m_unit_test");
    compare_Result(&pResult_l1ns2m2, &Result2_c, 2, "Fr_mul_l1ns2m_unit_test");
    compare_Result(&pResult_l1ns2m3, &Result3_c, 3, "Fr_mul_l1ns2m_unit_test");
}

void Fr_mul_l1ns2m_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1ns2m_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1ns2m" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1ns2m" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1ns2m" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_l1ms2m_unit_test()
{
    //Fr_mul_l1ms2m_test 0:
    FrElement pA_l1ms2m0= {0x1,0xc0000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_l1ms2m0= {0x2,0x40000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ms2m0= {0x0,0xc0000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_l1ms2m_test 1:
    FrElement pA_l1ms2m1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_l1ms2m1= {0x2,0x40000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_l1ms2m1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_l1ms2m_test 2:
    FrElement pA_l1ms2m2= {0xa1f0,0xc0000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_l1ms2m2= {0x1bb8,0x40000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_l1ms2m2= {0x0,0xc0000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_l1ms2m_test 3:
    FrElement pA_l1ms2m3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_l1ms2m3= {0xffff,0x40000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_l1ms2m3= {0x0,0xc0000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_l1ms2m0, &pB_l1ms2m0);
    Fr_mul(&Result1_c, &pA_l1ms2m1, &pB_l1ms2m1);
    Fr_mul(&Result2_c, &pA_l1ms2m2, &pB_l1ms2m2);
    Fr_mul(&Result3_c, &pA_l1ms2m3, &pB_l1ms2m3);

    compare_Result(&pResult_l1ms2m0, &Result0_c, 0, "Fr_mul_l1ms2m_unit_test");
    compare_Result(&pResult_l1ms2m1, &Result1_c, 1, "Fr_mul_l1ms2m_unit_test");
    compare_Result(&pResult_l1ms2m2, &Result2_c, 2, "Fr_mul_l1ms2m_unit_test");
    compare_Result(&pResult_l1ms2m3, &Result3_c, 3, "Fr_mul_l1ms2m_unit_test");
}

void Fr_mul_l1ms2m_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_l1ms2m_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_l1ms2m" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_l1ms2m" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_l1ms2m" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}


void Fr_mul_s1ml2m_unit_test()
{
    //Fr_mul_s1ml2m_test 0:
    FrElement pA_s1ml2m0= {0x1,0x40000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_s1ml2m0= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1ml2m0= {0x0,0xc0000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_s1ml2m_test 1:
    FrElement pA_s1ml2m1= {0x0,0x40000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_s1ml2m1= {0x2,0xc0000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1ml2m1= {0x0,0xc0000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_s1ml2m_test 2:
    FrElement pA_s1ml2m2= {0xa1f0,0x40000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1ml2m2= {0x1bb8,0xc0000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1ml2m2= {0x0,0xc0000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_s1ml2m_test 3:
    FrElement pA_s1ml2m3= {0xffff,0x40000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_s1ml2m3= {0xffff,0xc0000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_s1ml2m3= {0x0,0xc0000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_s1ml2m0, &pB_s1ml2m0);
    Fr_mul(&Result1_c, &pA_s1ml2m1, &pB_s1ml2m1);
    Fr_mul(&Result2_c, &pA_s1ml2m2, &pB_s1ml2m2);
    Fr_mul(&Result3_c, &pA_s1ml2m3, &pB_s1ml2m3);

    compare_Result(&pResult_s1ml2m0, &Result0_c, 0, "Fr_mul_s1ml2m_unit_test");
    compare_Result(&pResult_s1ml2m1, &Result1_c, 1, "Fr_mul_s1ml2m_unit_test");
    compare_Result(&pResult_s1ml2m2, &Result2_c, 2, "Fr_mul_s1ml2m_unit_test");
    compare_Result(&pResult_s1ml2m3, &Result3_c, 3, "Fr_mul_s1ml2m_unit_test");
}

void Fr_mul_s1ml2m_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_s1ml2m_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_s1ml2m" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_s1ml2m" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_s1ml2m" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}

void Fr_mul_s1ml2n_unit_test()
{
    //Fr_mul_s1ml2n_test 0:
    FrElement pA_s1ml2n0= {0x1,0x40000000,{0x1,0x0,0x0,0x0}};
    FrElement pB_s1ml2n0= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1ml2n0= {0x0,0x80000000,{0xb8b7400adb62329c,0x121deb53c223d90f,0x904c1bc95d70baba,0x2bd7f2a3058aaa39}};
    //Fr_mul_s1ml2n_test 1:
    FrElement pA_s1ml2n1= {0x0,0x40000000,{0x0,0x0,0x0,0x0}};
    FrElement pB_s1ml2n1= {0x2,0x80000000,{0x2,0x0,0x0,0x0}};
    FrElement pResult_s1ml2n1= {0x0,0x80000000,{0x0,0x0,0x0,0x0}};
    //Fr_mul_s1ml2n_test 2:
    FrElement pA_s1ml2n2= {0xa1f0,0x40000000,{0xa1f0fac9f8000000,0x9419f4243cdcb848,0xdc2822db40c0ac2e,0x183227397098d014}};
    FrElement pB_s1ml2n2= {0x1bb8,0x80000000,{0x1bb8e645ae216da7,0x53fe3ab1e35c59e3,0x8c49833d53bb8085,0x216d0b17f4e44a5}};
    FrElement pResult_s1ml2n2= {0x0,0x80000000,{0xcba5e0bbd0000003,0x789bb8d96d2c51b3,0x28f0d12384840917,0x112ceb58a394e07d}};
    //Fr_mul_s1ml2n_test 3:
    FrElement pA_s1ml2n3= {0xffff,0x40000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pB_s1ml2n3= {0xffff,0x80000000,{0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff}};
    FrElement pResult_s1ml2n3= {0x0,0x80000000,{0xdea6a001d841e408,0xffd01934b5bef5d1,0xedc4ef0cf4a2b471,0x1d8f65bdb91d796f}};

    FrElement Result0_c = {0,0,{0,0,0,0}};
    FrElement Result1_c = {0,0,{0,0,0,0}};
    FrElement Result2_c= {0,0,{0,0,0,0}};
    FrElement Result3_c= {0,0,{0,0,0,0}};

    Fr_mul(&Result0_c, &pA_s1ml2n0, &pB_s1ml2n0);
    Fr_mul(&Result1_c, &pA_s1ml2n1, &pB_s1ml2n1);
    Fr_mul(&Result2_c, &pA_s1ml2n2, &pB_s1ml2n2);
    Fr_mul(&Result3_c, &pA_s1ml2n3, &pB_s1ml2n3);

    compare_Result(&pResult_s1ml2n0, &Result0_c, 0, "Fr_mul_s1ml2n_unit_test");
    compare_Result(&pResult_s1ml2n1, &Result1_c, 1, "Fr_mul_s1ml2n_unit_test");
    compare_Result(&pResult_s1ml2n2, &Result2_c, 2, "Fr_mul_s1ml2n_unit_test");
    compare_Result(&pResult_s1ml2n3, &Result3_c, 3, "Fr_mul_s1ml2n_unit_test");
}

void Fr_mul_s1ml2n_test(PFrElement pResult, PFrElement pA, PFrElement pB, int idx)
{
    std::cout << "//Fr_mul_s1ml2n_test " << idx << ": " <<  '\n';
    Fr_mul(pResult, pA, pB);
    std::cout << "FrElement pA_s1ml2n" << idx << "= " << std::hex << "{0x" << pA->shortVal << ",0x" << pA->type << ",{0x" << pA->longVal[0] << ",0x" << pA->longVal[1] << ",0x" << pA->longVal[2] << ",0x" << pA->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pB_s1ml2n" << idx << "= " << std::hex << "{0x" << pB->shortVal << ",0x" << pB->type << ",{0x" << pB->longVal[0] << ",0x" << pB->longVal[1] << ",0x" << pB->longVal[2] << ",0x" << pB->longVal[3] << "}};"<< '\n';
    std::cout << "FrElement pResult_s1ml2n" << idx << "= " << std::hex << "{0x" << pResult->shortVal << ",0x" << pResult->type << ",{0x" << pResult->longVal[0] << ",0x" << pResult->longVal[1] << ",0x" << pResult->longVal[2] << ",0x" << pResult->longVal[3] << "}};"<< '\n';
}


void Fr_Copy_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    AEl.shortVal = -1;
    AEl.type =1;
    AEl.longVal[0] = 0xa1f0fac9f8000000;
    AEl.longVal[1] = 0x9419f4243cdcb848;
    AEl.longVal[2] = 0xdc2822db40c0ac2e;
    AEl.longVal[3] = 0x183227397098d014;
    Fr_copy(&ResultEl, &AEl);
    std::cout << "Fr_copy Test: " <<  '\n';

    std::cout << "pAEl.shortVal = " << std::hex << AEl.shortVal  << '\n';
    std::cout << "pResultEl.shortVal = " << std::hex << ResultEl.shortVal  << '\n';

    std::cout << "pAEl.type = " << std::hex << AEl.type  << '\n';
    std::cout << "pResultEl.type = " << std::hex << ResultEl.type  << '\n';

    std::cout << "AEl.longVal= " << std::hex << AEl.longVal[0] << ", " << AEl.longVal[1]<< ", " << AEl.longVal[2] << ", " << AEl.longVal[3] << '\n';
    std::cout << "ResultEl.longVal= " << std::hex << ResultEl.longVal[0] << ", " << ResultEl.longVal[1]<< ", " << ResultEl.longVal[2] << ", " << ResultEl.longVal[3] << '\n';
}

void Fr_copyn_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    AEl.shortVal = -1;
    AEl.type =1;
    AEl.longVal[0] = 0xa1f0fac9f8000000;
    AEl.longVal[1] = 0x9419f4243cdcb848;
    AEl.longVal[2] = 0xdc2822db40c0ac2e;
    AEl.longVal[3] = 0x183227397098d014;
    Fr_copyn(&ResultEl, &AEl, 1);
    std::cout << "Fr_copyn Test: " <<  '\n';

    std::cout << "pAEl.shortVal = " << std::hex << AEl.shortVal  << '\n';
    std::cout << "pResultEl.shortVal = " << std::hex << ResultEl.shortVal  << '\n';

    std::cout << "pAEl.type = " << std::hex << AEl.type  << '\n';
    std::cout << "pResultEl.type = " << std::hex << ResultEl.type  << '\n';

    std::cout << "AEl.longVal= " << std::hex << AEl.longVal[0] << ", " << AEl.longVal[1]<< ", " << AEl.longVal[2] << ", " << AEl.longVal[3] << '\n';
    std::cout << "ResultEl.longVal= " << std::hex << ResultEl.longVal[0] << ", " << ResultEl.longVal[1]<< ", " << ResultEl.longVal[2] << ", " << ResultEl.longVal[3] << '\n';
}

void Fr_toLongNormal_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    AEl.shortVal = 0xa1f0;
    AEl.type = 0x9419;
//    AEl.longVal[0] = 0xa1f0fac9f8000000;
//    AEl.longVal[1] = 0x9419f4243cdcb848;
//    AEl.longVal[2] = 0xdc2822db40c0ac2e;
//    AEl.longVal[3] = 0x183227397098d014;
//    AEl.longVal[0] = 0;
//    AEl.longVal[1] = 0;
//    AEl.longVal[2] = 0;
//    AEl.longVal[3] = 0;
    //Fr_rawToMontgomery(FrRawElement pRawResult, FrRawElement pRawA);
    Fr_toLongNormal(&ResultEl, &AEl);
    std::cout << "Fr_toLongNormal Test: " <<  '\n';

    std::cout << "pAEl.shortVal = " << std::hex << AEl.shortVal  << '\n';
    std::cout << "pResultEl.shortVal = " << std::hex << ResultEl.shortVal  << '\n';

    std::cout << "pAEl.type = " << std::hex << AEl.type  << '\n';
    std::cout << "pResultEl.type = " << std::hex << ResultEl.type  << '\n';

    std::cout << "AEl.longVal= " << std::hex << AEl.longVal[0] << ", " << AEl.longVal[1]<< ", " << AEl.longVal[2] << ", " << AEl.longVal[3] << '\n';
    std::cout << "ResultEl.longVal= " << std::hex << ResultEl.longVal[0] << ", " << ResultEl.longVal[1]<< ", " << ResultEl.longVal[2] << ", " << ResultEl.longVal[3] << '\n';
}

void Fr_toNormal_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    FrElement BEl = {0};
//    AEl.shortVal = 0xa1f0;
//    AEl.type = 0x9419;
    AEl.shortVal = 0;
    //AEl.type = Fr_LONG;
    AEl.type = Fr_LONGMONTGOMERY;
    AEl.longVal[0] = 0xa1f0fac9f8000000;
    AEl.longVal[1] = 0x9419f4243cdcb848;
    AEl.longVal[2] = 0xdc2822db40c0ac2e;
    AEl.longVal[3] = 0x183227397098d014;
//    AEl.longVal[0] = 0;
//    AEl.longVal[1] = 0;
//    AEl.longVal[2] = 0;
//    AEl.longVal[3] = 0;
    //Fr_rawToMontgomery(FrRawElement pRawResult, FrRawElement pRawA);


    Fr_toNormal(&ResultEl, &AEl);
    std::cout << "Fr_toNormal Test: " <<  '\n';

    std::cout << "pAEl.shortVal = " << std::hex << AEl.shortVal  << '\n';
    std::cout << "pResultEl.shortVal = " << std::hex << ResultEl.shortVal  << '\n';

    std::cout << "pAEl.type = " << std::hex << AEl.type  << '\n';
    std::cout << "pResultEl.type = " << std::hex << ResultEl.type  << '\n';

    std::cout << "AEl.longVal= " << std::hex << AEl.longVal[0] << ", " << AEl.longVal[1]<< ", " << AEl.longVal[2] << ", " << AEl.longVal[3] << '\n';
    std::cout << "ResultEl.longVal= " << std::hex << ResultEl.longVal[0] << ", " << ResultEl.longVal[1]<< ", " << ResultEl.longVal[2] << ", " << ResultEl.longVal[3] << '\n';
}

void Fr_toMontgomery_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    FrElement BEl = {0};
    AEl.shortVal = 0;
    AEl.type = Fr_LONG;
//    AEl.shortVal = 0;
//    AEl.type = 0;
    AEl.longVal[0] = 0xa1f0fac9f8000000;
    AEl.longVal[1] = 0x9419f4243cdcb848;
    AEl.longVal[2] = 0xdc2822db40c0ac2e;
    AEl.longVal[3] = 0x183227397098d014;
//    AEl.longVal[0] = 0;
//    AEl.longVal[1] = 0;
//    AEl.longVal[2] = 0;
//    AEl.longVal[3] = 0;
    //Fr_rawToMontgomery(FrRawElement pRawResult, FrRawElement pRawA);


    Fr_toMontgomery(&ResultEl, &AEl);
    std::cout << "Fr_toMontgomery Test: " <<  '\n';

    std::cout << "AEl.shortVal = " << std::hex << AEl.shortVal  << '\n';
    std::cout << "ResultEl.shortVal = " << std::hex << ResultEl.shortVal  << '\n';

    std::cout << "AEl.type = " << std::hex << AEl.type  << '\n';
    std::cout << "ResultEl.type = " << std::hex << ResultEl.type  << '\n';

    std::cout << "AEl.longVal= " << std::hex << AEl.longVal[0] << ", " << AEl.longVal[1]<< ", " << AEl.longVal[2] << ", " << AEl.longVal[3] << '\n';
    std::cout << "ResultEl.longVal= " << std::hex << ResultEl.longVal[0] << ", " << ResultEl.longVal[1]<< ", " << ResultEl.longVal[2] << ", " << ResultEl.longVal[3] << '\n';
}

//#define Fr_SHORT 0x00000000
//#define Fr_LONG 0x80000000
//#define Fr_LONGMONTGOMERY 0xC0000000

void Fr_mul_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    FrElement BEl = {0};
    //AEl.shortVal = -1;
    AEl.shortVal = 0xa1f0fac9;
    //AEl.shortVal = 2;
    AEl.type = Fr_SHORTMONTGOMERY;
    //BEl.shortVal = -2;
    BEl.shortVal = 0x1bb8e645;
    //BEl.shortVal = 0;
    BEl.type = Fr_LONGMONTGOMERY;
    AEl.longVal[0] = 0xa1f0fac9f8000000;
    AEl.longVal[1] = 0x9419f4243cdcb848;
    AEl.longVal[2] = 0xdc2822db40c0ac2e;
    AEl.longVal[3] = 0x183227397098d014;

    BEl.longVal[0]  = 0x1bb8e645ae216da7;
    BEl.longVal[1]  = 0x53fe3ab1e35c59e3;
    BEl.longVal[2]  = 0x8c49833d53bb8085;
    BEl.longVal[3]  = 0x0216d0b17f4e44a5;
//    AEl.longVal[0] = 0;
//    AEl.longVal[1] = 0;
//    AEl.longVal[2] = 0;
//    AEl.longVal[3] = 0;

//    BEl.longVal[0]  = 0;
//    BEl.longVal[1]  = 0;
//    BEl.longVal[2]  = 0;
//    BEl.longVal[3]  = 0;

    Fr_mul(&ResultEl, &AEl, &BEl);
    std::cout << "Fr_mul Test: " <<  '\n';

    std::cout << "AEl.shortVal = " << std::hex << AEl.shortVal  << '\n';
    std::cout << "BEl.shortVal = " << std::hex << BEl.shortVal  << '\n';
    std::cout << "ResultEl.shortVal = " << std::hex << ResultEl.shortVal  << '\n';

    std::cout << "AEl.type = " << std::hex << AEl.type  << '\n';
    std::cout << "BEl.type = " << std::hex << BEl.type  << '\n';
    std::cout << "ResultEl.type = " << std::hex << ResultEl.type  << '\n';

    std::cout << "AEl.longVal= " << std::hex << AEl.longVal[0] << ", " << AEl.longVal[1]<< ", " << AEl.longVal[2] << ", " << AEl.longVal[3] << '\n';
    std::cout << "BEl.longVal= " << std::hex << BEl.longVal[0] << ", " << BEl.longVal[1]<< ", " << BEl.longVal[2] << ", " << BEl.longVal[3] << '\n';
    std::cout << "ResultEl.longVal= " << std::hex << ResultEl.longVal[0] << ", " << ResultEl.longVal[1]<< ", " << ResultEl.longVal[2] << ", " << ResultEl.longVal[3] << '\n';
}


void Fr_rawSwap_test()
{
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[0] << ", " << pRawB[1] << ", " << pRawB[2] << ", " << pRawB[3] << '\n';
    Fr_rawSwap(pRawB, pRawA);
    std::cout << "pRawAafterSwap= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawBafterSwap= " << std::hex << pRawB[0] << ", " << pRawB[1] << ", " << pRawB[2] << ", " << pRawB[3] << '\n';
}

int main()
{

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_add_unit_test();
//    Fr_Rw_add_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_add_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_add_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_add_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_add_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_add_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_add_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_add_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_sub_unit_test();
//    Fr_Rw_sub_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_sub_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_sub_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_sub_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_sub_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_sub_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_sub_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_sub_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_copy_unit_test();
//    Fr_Rw_copy_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_copy_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_copy_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_copy_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_copy_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_copy_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_copy_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_copy_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_Neg_unit_test();
//    Fr_Rw_Neg_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_Neg_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_Neg_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_Neg_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_Neg_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_Neg_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_Neg_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_Neg_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_mul_unit_test();
//    Fr_Rw_mul_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_mul_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_mul_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_mul_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_mul_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_mul_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_mul_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_mul_test(pRawResult3, pRawA3, pRawB3, 3);
    Fr_Rw_mul_test(pRawResult4, pRawA4, pRawB4, 4);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_Msquare_unit_test();
//    Fr_Rw_Msquare_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_Msquare_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_Msquare_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_Msquare_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_Msquare_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_Msquare_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_Msquare_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_Msquare_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_mul1_unit_test();
//    Fr_Rw_mul1_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_mul1_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_mul1_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_mul1_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_mul1_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_mul1_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_mul1_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_mul1_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_ToMontgomery_unit_test();
//    Fr_Rw_ToMontgomery_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_ToMontgomery_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_ToMontgomery_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_ToMontgomery_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_ToMontgomery_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_ToMontgomery_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_ToMontgomery_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_ToMontgomery_test(pRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_IsEq_unit_test();
//    Fr_rawIsEq_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_rawIsEq_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_rawIsEq_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_rawIsEq_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_rawIsEq_test(uRawResult,  pRawA,  pRawB, 0);
    Fr_rawIsEq_test(uRawResult1, pRawA1, pRawB1, 1);
    Fr_rawIsEq_test(uRawResult2, pRawA2, pRawB2, 2);
    Fr_rawIsEq_test(uRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_rawIsZero_unit_test();
//    Fr_rawIsZero_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_rawIsZero_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_rawIsZero_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_rawIsZero_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_rawIsZero_test(uRawResult,  pRawA,  pRawB, 0);
    Fr_rawIsZero_test(uRawResult1, pRawA1, pRawB1, 1);
    Fr_rawIsZero_test(uRawResult2, pRawA2, pRawB2, 2);
    Fr_rawIsZero_test(uRawResult3, pRawA3, pRawB3, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_Rw_FromMontgomery_unit_test();
//    Fr_Rw_FromMontgomery_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_FromMontgomery_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_FromMontgomery_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_FromMontgomery_test(pRawResult3, pRawA3, pRawB3, 3);
#else
    Fr_Rw_FromMontgomery_test(pRawResult,  pRawA,  pRawB, 0);
    Fr_Rw_FromMontgomery_test(pRawResult1, pRawA1, pRawB1, 1);
    Fr_Rw_FromMontgomery_test(pRawResult2, pRawA2, pRawB2, 2);
    Fr_Rw_FromMontgomery_test(pRawResult3, pRawA3, pRawB3, 3);
#endif
/*
#ifdef TEST_C_FUNCTIONS
    Fr_toNormal_unit_test();
//    Fr_toNormal_test(&RawResult,  &RawA,  &RawB, 0);
//    Fr_toNormal_test(&RawResult1, &RawA1, &RawB1, 1);
//    Fr_toNormal_test(&RawResult2, &RawA2, &RawB2, 2);
//    Fr_toNormal_test(&RawResult3, &RawA3, &RawB3, 3);
#else
    Fr_toNormal_test(&RawResult,  &RawA,  &RawB, 0);
    Fr_toNormal_test(&RawResult1, &RawA1, &RawB1, 1);
    Fr_toNormal_test(&RawResult2, &RawA2, &RawB2, 2);
    Fr_toNormal_test(&RawResult3, &RawA3, &RawB3, 3);
#endif


#ifdef TEST_C_FUNCTIONS
    Fr_mul_s1s2_unit_test();
//    Fr_mul_s1s2_test(&Result_s1s2,  &A_s1s2,  &B_s1s2, 0);
//    Fr_mul_s1s2_test(&Result1_s1s2, &A1_s1s2, &B1_s1s2, 1);
//    Fr_mul_s1s2_test(&Result2_s1s2, &A2_s1s2, &B2_s1s2, 2);
//    Fr_mul_s1s2_test(&Result3_s1s2, &A3_s1s2, &B3_s1s2, 3);
#else
    Fr_mul_s1s2_test(&Result_s1s2,  &A_s1s2,  &B_s1s2, 0);
    Fr_mul_s1s2_test(&Result1_s1s2, &A1_s1s2, &B1_s1s2, 1);
    Fr_mul_s1s2_test(&Result2_s1s2, &A2_s1s2, &B2_s1s2, 2);
    Fr_mul_s1s2_test(&Result3_s1s2, &A3_s1s2, &B3_s1s2, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1nl2n_unit_test();
//    Fr_mul_l1nl2n_test(&Result_l1nl2n, &A_l1nl2n,  &B_l1nl2n, 0);
//    Fr_mul_l1nl2n_test(&Result1_l1nl2n, &A1_l1nl2n, &B1_l1nl2n, 1);
//    Fr_mul_l1nl2n_test(&Result2_l1nl2n, &A2_l1nl2n, &B2_l1nl2n, 2);
//    Fr_mul_l1nl2n_test(&Result3_l1nl2n, &A3_l1nl2n, &B3_l1nl2n, 3);
#else
    Fr_mul_l1nl2n_test(&Result_l1nl2n,  &A_l1nl2n,  &B_l1nl2n, 0);
    Fr_mul_l1nl2n_test(&Result1_l1nl2n, &A1_l1nl2n, &B1_l1nl2n, 1);
    Fr_mul_l1nl2n_test(&Result2_l1nl2n, &A2_l1nl2n, &B2_l1nl2n, 2);
    Fr_mul_l1nl2n_test(&Result3_l1nl2n, &A3_l1nl2n, &B3_l1nl2n, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1ml2n_unit_test();
//    Fr_mul_l1ml2n_test(&Result_l1ml2n, &A_l1ml2n,  &B_l1ml2n, 0);
//    Fr_mul_l1ml2n_test(&Result1_l1ml2n, &A1_l1ml2n, &B1_l1ml2n, 1);
//    Fr_mul_l1ml2n_test(&Result2_l1ml2n, &A2_l1ml2n, &B2_l1ml2n, 2);
//    Fr_mul_l1ml2n_test(&Result3_l1ml2n, &A3_l1ml2n, &B3_l1ml2n, 3);
#else
    Fr_mul_l1ml2n_test(&Result_l1ml2n, &A_l1ml2n,  &B_l1ml2n, 0);
    Fr_mul_l1ml2n_test(&Result1_l1ml2n, &A1_l1ml2n, &B1_l1ml2n, 1);
    Fr_mul_l1ml2n_test(&Result2_l1ml2n, &A2_l1ml2n, &B2_l1ml2n, 2);
    Fr_mul_l1ml2n_test(&Result3_l1ml2n, &A3_l1ml2n, &B3_l1ml2n, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1ml2m_unit_test();
//    Fr_mul_l1ml2n_test(&Result_l1ml2n, &A_l1ml2n,  &B_l1ml2n, 0);
//    Fr_mul_l1ml2n_test(&Result1_l1ml2n, &A1_l1ml2n, &B1_l1ml2n, 1);
//    Fr_mul_l1ml2n_test(&Result2_l1ml2n, &A2_l1ml2n, &B2_l1ml2n, 2);
//    Fr_mul_l1ml2n_test(&Result3_l1ml2n, &A3_l1ml2n, &B3_l1ml2n, 3);
#else
    Fr_mul_l1ml2m_test(&Result_l1ml2m, &A_l1ml2m,  &B_l1ml2m, 0);
    Fr_mul_l1ml2m_test(&Result1_l1ml2m, &A1_l1ml2m, &B1_l1ml2m, 1);
    Fr_mul_l1ml2m_test(&Result2_l1ml2m, &A2_l1ml2m, &B2_l1ml2m, 2);
    Fr_mul_l1ml2m_test(&Result3_l1ml2m, &A3_l1ml2m, &B3_l1ml2m, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1nl2m_unit_test();
//    Fr_mul_l1nl2n_test(&Result_l1nl2n, &A_l1ml2n,  &B_l1ml2n, 0);
//    Fr_mul_l1nl2n_test(&Result1_l1nl2n, &A1_l1ml2n, &B1_l1ml2n, 1);
//    Fr_mul_l1nl2n_test(&Result2_l1nl2n, &A2_l1ml2n, &B2_l1ml2n, 2);
//    Fr_mul_l1nl2n_test(&Result3_l1nl2n, &A3_l1ml2n, &B3_l1ml2n, 3);
#else
    Fr_mul_l1nl2m_test(&Result_l1nl2m, &A_l1nl2m,  &B_l1nl2m, 0);
    Fr_mul_l1nl2m_test(&Result1_l1nl2m, &A1_l1nl2m, &B1_l1nl2m, 1);
    Fr_mul_l1nl2m_test(&Result2_l1nl2m, &A2_l1nl2m, &B2_l1nl2m, 2);
    Fr_mul_l1nl2m_test(&Result3_l1nl2m, &A3_l1nl2m, &B3_l1nl2m, 3);
#endif


#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1ns2n_unit_test();
//    Fr_mul_l1ns2n_test(&Result_l1ns2n,  &A_l1ns2n,  &B_l1ns2n, 0);
//    Fr_mul_l1ns2n_test(&Result1_l1ns2n, &A1_l1ns2n, &B1_l1ns2n, 1);
//    Fr_mul_l1ns2n_test(&Result2_l1ns2n, &A2_l1ns2n, &B2_l1ns2n, 2);
//    Fr_mul_l1ns2n_test(&Result3_l1ns2n, &A3_l1ns2n, &B3_l1ns2n, 3);
#else
    Fr_mul_l1ns2n_test(&Result_l1ns2n,  &A_l1ns2n,  &B_l1ns2n, 0);
    Fr_mul_l1ns2n_test(&Result1_l1ns2n, &A1_l1ns2n, &B1_l1ns2n, 1);
    Fr_mul_l1ns2n_test(&Result2_l1ns2n, &A2_l1ns2n, &B2_l1ns2n, 2);
    Fr_mul_l1ns2n_test(&Result3_l1ns2n, &A3_l1ns2n, &B3_l1ns2n, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_s1nl2n_unit_test();
//    Fr_mul_s1nl2n_test(&Result_s1nl2n,   &A_s1nl2n,   &B_s1nl2n, 0);
//    Fr_mul_s1nl2n_test(&Result1_s1nl2n,  &A1_s1nl2n,  &B1_s1nl2n, 1);
//    Fr_mul_s1nl2n_test(&Result2_s1nl2n,  &A2_s1nl2n,  &B2_s1nl2n, 2);
//    Fr_mul_s1nl2n_test(&Result3_s1nl2n,  &A3_s1nl2n,  &B3_s1nl2n, 3);
#else
    Fr_mul_s1nl2n_test(&Result_s1nl2n,   &A_s1nl2n,   &B_s1nl2n, 0);
    Fr_mul_s1nl2n_test(&Result1_s1nl2n,  &A1_s1nl2n,  &B1_s1nl2n, 1);
    Fr_mul_s1nl2n_test(&Result2_s1nl2n,  &A2_s1nl2n,  &B2_s1nl2n, 2);
    Fr_mul_s1nl2n_test(&Result3_s1nl2n,  &A3_s1nl2n,  &B3_s1nl2n, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_s1nl2m_unit_test();
//    Fr_mul_s1nl2m_test(&Result_s1nl2m,   &A_s1nl2m,   &B_s1nl2m, 0);
//    Fr_mul_s1nl2m_test(&Result1_s1nl2m,  &A1_s1nl2m,  &B1_s1nl2m, 1);
//    Fr_mul_s1nl2m_test(&Result2_s1nl2m,  &A2_s1nl2m,  &B2_s1nl2m, 2);
//    Fr_mul_s1nl2m_test(&Result3_s1nl2m,  &A3_s1nl2m,  &B3_s1nl2m, 3);
#else
    Fr_mul_s1nl2m_test(&Result_s1nl2m,   &A_s1nl2m,   &B_s1nl2m, 0);
    Fr_mul_s1nl2m_test(&Result1_s1nl2m,  &A1_s1nl2m,  &B1_s1nl2m, 1);
    Fr_mul_s1nl2m_test(&Result2_s1nl2m,  &A2_s1nl2m,  &B2_s1nl2m, 2);
    Fr_mul_s1nl2m_test(&Result3_s1nl2m,  &A3_s1nl2m,  &B3_s1nl2m, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1ms2n_unit_test();
//    Fr_mul_l1ms2n_test(&Result_l1ms2n,  &A_l1ms2n,  &B_l1ns2n, 0);
//    Fr_mul_l1ms2n_test(&Result1_l1ms2n, &A1_l1ms2n, &B1_l1ns2n, 1);
//    Fr_mul_l1ms2n_test(&Result2_l1ms2n, &A2_l1ms2n, &B2_l1ns2n, 2);
//    Fr_mul_l1ms2n_test(&Result3_l1ms2n, &A3_l1ms2n, &B3_l1ns2n, 3);
#else
    Fr_mul_l1ms2n_test(&Result_l1ms2n,  &A_l1ms2n,  &B_l1ms2n, 0);
    Fr_mul_l1ms2n_test(&Result1_l1ms2n, &A1_l1ms2n, &B1_l1ms2n, 1);
    Fr_mul_l1ms2n_test(&Result2_l1ms2n, &A2_l1ms2n, &B2_l1ms2n, 2);
    Fr_mul_l1ms2n_test(&Result3_l1ms2n, &A3_l1ms2n, &B3_l1ms2n, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1ns2m_unit_test();
//    Fr_mul_l1ns2m_test(&Result_l1ns2m,  &A_l1ns2m,  &B_l1ns2m, 0);
//    Fr_mul_l1ns2m_test(&Result1_l1ns2m, &A1_l1ns2m, &B1_l1ns2m, 1);
//    Fr_mul_l1ns2m_test(&Result2_l1ns2m, &A2_l1ns2m, &B2_l1ns2m, 2);
//    Fr_mul_l1ns2m_test(&Result3_l1ns2m, &A3_l1ns2m, &B3_l1ns2m, 3);
#else
    Fr_mul_l1ns2m_test(&Result_l1ns2m,  &A_l1ns2m,  &B_l1ns2m, 0);
    Fr_mul_l1ns2m_test(&Result1_l1ns2m, &A1_l1ns2m, &B1_l1ns2m, 1);
    Fr_mul_l1ns2m_test(&Result2_l1ns2m, &A2_l1ns2m, &B2_l1ns2m, 2);
    Fr_mul_l1ns2m_test(&Result3_l1ns2m, &A3_l1ns2m, &B3_l1ns2m, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_l1ms2m_unit_test();
//    Fr_mul_l1ms2m_test(&Result_l1ms2m,  &A_l1ms2m,  &B_l1ms2m, 0);
//    Fr_mul_l1ms2m_test(&Result1_l1ms2m, &A1_l1ms2m, &B1_l1ms2m, 1);
//    Fr_mul_l1ms2m_test(&Result2_l1ms2m, &A2_l1ms2m, &B2_l1ms2m, 2);
//    Fr_mul_l1ms2m_test(&Result3_l1ms2m, &A3_l1ms2m, &B3_l1ms2m, 3);
#else
    Fr_mul_l1ms2m_test(&Result_l1ms2m,  &A_l1ms2m,  &B_l1ms2m, 0);
    Fr_mul_l1ms2m_test(&Result1_l1ms2m, &A1_l1ms2m, &B1_l1ms2m, 1);
    Fr_mul_l1ms2m_test(&Result2_l1ms2m, &A2_l1ms2m, &B2_l1ms2m, 2);
    Fr_mul_l1ms2m_test(&Result3_l1ms2m, &A3_l1ms2m, &B3_l1ms2m, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_s1ml2m_unit_test();
//    Fr_mul_s1ml2m_test(&Result_s1ml2m,   &A_s1ml2m,   &B_s1ml2m, 0);
//    Fr_mul_s1ml2m_test(&Result1_s1ml2m,  &A1_s1ml2m,  &B1_s1ml2m, 1);
//    Fr_mul_s1ml2m_test(&Result2_s1ml2m,  &A2_s1ml2m,  &B2_s1ml2m, 2);
//    Fr_mul_s1ml2m_test(&Result3_s1ml2m,  &A3_s1ml2m,  &B3_s1ml2m, 3);
#else
    Fr_mul_s1ml2m_test(&Result_s1ml2m,   &A_s1ml2m,   &B_s1ml2m, 0);
    Fr_mul_s1ml2m_test(&Result1_s1ml2m,  &A1_s1ml2m,  &B1_s1ml2m, 1);
    Fr_mul_s1ml2m_test(&Result2_s1ml2m,  &A2_s1ml2m,  &B2_s1ml2m, 2);
    Fr_mul_s1ml2m_test(&Result3_s1ml2m,  &A3_s1ml2m,  &B3_s1ml2m, 3);
#endif

#ifdef TEST_C_FUNCTIONS
    Fr_mul_s1ml2n_unit_test();
//    Fr_mul_s1ml2n_test(&Result_s1ml2n,   &A_s1ml2n,   &B_s1ml2n, 0);
//    Fr_mul_s1ml2n_test(&Result1_s1ml2n,  &A1_s1ml2n,  &B1_s1ml2n, 1);
//    Fr_mul_s1ml2n_test(&Result2_s1ml2n,  &A2_s1ml2n,  &B2_s1ml2n, 2);
//    Fr_mul_s1ml2n_test(&Result3_s1ml2n,  &A3_s1ml2n,  &B3_s1ml2n, 3);
#else
    Fr_mul_s1ml2n_test(&Result_s1ml2n,   &A_s1ml2n,   &B_s1ml2n, 0);
    Fr_mul_s1ml2n_test(&Result1_s1ml2n,  &A1_s1ml2n,  &B1_s1ml2n, 1);
    Fr_mul_s1ml2n_test(&Result2_s1ml2n,  &A2_s1ml2n,  &B2_s1ml2n, 2);
    Fr_mul_s1ml2n_test(&Result3_s1ml2n,  &A3_s1ml2n,  &B3_s1ml2n, 3);
#endif

*/



//    Fr_Rw_sub_test(pRawResult,  pRawA,  pRawB, 0);
//    Fr_Rw_sub_test(pRawResult1, pRawA1, pRawB1, 1);
//    Fr_Rw_sub_test(pRawResult2, pRawA2, pRawB2, 2);
//    Fr_Rw_sub_test(pRawResult3, pRawA3, pRawB3, 3);

//    Fr_Rw_copy_test(pRawResult,  pRawA, 0);
//    Fr_Rw_copy_test(pRawResult1, pRawA1, 1);
//    Fr_Rw_copy_test(pRawResult2, pRawA2, 2);
//    Fr_Rw_copy_test(pRawResult3, pRawA3, 3);



        //Fr_Rw_sub_test();
        //Fr_Rw_neg_test();
        //Fr_Rw_mul_test();
        //Fr_Rw_square_test();
        //Fr_Rw_mul1_test();
        //Fr_Rw_ToMontgomery_test();
        //Fr_rawFromMontgomery_test();
        //Fr_Copy_test();
        //Fr_rawIsEq_test();
        // Fr_copyn_test(); //need to check


        //Fr_toMontgomery_test();
        //Fr_toLongNormal_test();

        //Fr_mul_test();
        //Fr_toNormal_test();
        //Fr_rawIsZero_test();
        //Fr_rawSwap_test();

    //    printf("%d  ", sizeof(FrElement));
    //    printf("%d  ", sizeof(FrRawElement));

    //    std::cout << typeid(uint64_t).name() << '\n';
    //    std::cout << typeid(FrRawElement).name() << '\n';
    return 0;
}
