#include <iostream>

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
//FrRawElement pRawA = {0x0,0x0,0x1,0x1};
//FrRawElement pRawB = {0x0,0x0,0x1,0x1};

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

void Fr_Rw_copy_test()
{
    Fr_rawCopy(pRawResult, pRawA);
    std::cout << "Fr_rawCopy Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[1] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[2] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[3] << '\n';

    std::cout << "pRawResult= " << std::hex << pRawResult[0] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[1] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[2] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[3] << '\n';
}

void Fr_Rw_add_test()
{
    Fr_rawAdd(pRawResult, pRawA, pRawB);
    std::cout << "Fr_rawAdd Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[1] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[2] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[3] << '\n';

    std::cout << "pRawB= " << std::hex << pRawB[0] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[1] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[2] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[3] << '\n';

    std::cout << "pRawResult= " << std::hex << pRawResult[0] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[1] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[2] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[3] << '\n';
}

void Fr_Rw_sub_test()
{
    Fr_rawSub(pRawResult, pRawA, pRawB);
    std::cout << "Fr_rawSub Test: " <<  '\n';
    std::cout << "pRawA= " << std::hex << pRawA[0] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[1] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[2] << '\n';
    std::cout << "pRawA= " << std::hex << pRawA[3] << '\n';

    std::cout << "pRawB= " << std::hex << pRawB[0] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[1] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[2] << '\n';
    std::cout << "pRawB= " << std::hex << pRawB[3] << '\n';

    std::cout << "pRawResult= " << std::hex << pRawResult[0] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[1] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[2] << '\n';
    std::cout << "pRawResult= " << std::hex << pRawResult[3] << '\n';
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





int main()
{
    //typedef uint64_t unit64_t;

    //show_extern_vars();
    //Fr_Rw_copy_test();
    //Fr_Rw_add_test();
    //Fr_Rw_sub_test();
    //Fr_Rw_neg_test();
    //Fr_Rw_mul_test();
    //Fr_Rw_square_test();
    //Fr_Rw_mul1_test();
    Fr_Rw_ToMontgomery_test();

//    std::cout << typeid(uint64_t).name() << '\n';
//    std::cout << typeid(FrRawElement).name() << '\n';
    cout << "Hello World!" << endl;
    return 0;
}
