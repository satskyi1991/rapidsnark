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

void Fr_Rw_neg_test()
{
    Fr_rawNeg(pRawResult, pRawA);
    std::cout << "Fr_rawNeg Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[1] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[2] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[3] << '\n';

    std::cout << "pRawResult= " << std::hex << pRawResult[0] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[1] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[2] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[3] << '\n';
}

void Fr_Rw_mul_test()
{
    Fr_rawMMul(pRawResult, pRawA, pRawB);
    std::cout << "Fr_rawMMul Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[0] << ", " << pRawB[1] << ", " << pRawB[2] << ", " << pRawB[3] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[0] << ", " << pRawResult[1] << ", " << pRawResult[2] << ", " << pRawResult[3] << '\n';
}

void Fr_Rw_square_test()
{
    Fr_rawMSquare(pRawResult, pRawA);
    std::cout << "Fr_rawMSquare Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[0] << ", " << pRawResult[1] << ", " << pRawResult[2] << ", " << pRawResult[3] << '\n';
}

void Fr_Rw_mul1_test()
{
    Fr_rawMMul1(pRawResult, pRawA, pRawB[0]);
    std::cout << "Fr_rawMMul1 Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[0] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[0] << ", " << pRawResult[1] << ", " << pRawResult[2] << ", " << pRawResult[3] << '\n';
}

void Fr_Rw_ToMontgomery_test()
{
    Fr_rawToMontgomery(pRawResult, pRawA);
    std::cout << "Fr_rawToMontgomery Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[0] << ", " << pRawResult[1] << ", " << pRawResult[2] << ", " << pRawResult[3] << '\n';
}

void Fr_rawFromMontgomery_test()
{
    Fr_rawFromMontgomery(pRawResult, pRawA);
    std::cout << "Fr_rawFromMontgomery Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[0] << ", " << pRawResult[1] << ", " << pRawResult[2] << ", " << pRawResult[3] << '\n';
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

void Fr_rawIsEq_test()
{
    std::cout << "Fr_rawIsEq(pRawA, pRawB) Test: " <<  Fr_rawIsEq(pRawA, pRawB) << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << ", " << pRawA[1] << ", " << pRawA[2] << ", " << pRawA[3] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawB[0] << ", " << pRawB[1] << ", " << pRawB[2] << ", " << pRawB[3] << '\n';
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

void Fr_rawIsZero_test()
{
    std::cout << "Fr_rawIsZero(pRawB) Test: " <<  Fr_rawIsZero(pRawB) << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[0] << ", " << pRawB[1] << ", " << pRawB[2] << ", " << pRawB[3] << '\n';
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
