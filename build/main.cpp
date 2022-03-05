#include <iostream>

//#define TEST_C_FUNCTIONS

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
    AEl.type = 0;
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
    std::cout << "Fr_toLongNormal Test: " <<  '\n';

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
    AEl.type = 0;
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

void Fr_mul_test()
{
    FrElement ResultEl = {0};
    FrElement AEl = {0};
    FrElement BEl = {0};
    AEl.shortVal = 0;
    AEl.type = 0;
    BEl.shortVal = 0;
    BEl.type = 0;
//    AEl.shortVal = 0;
//    AEl.type = 0;
    AEl.longVal[0] = 0xa1f0fac9f8000000;
    AEl.longVal[1] = 0x9419f4243cdcb848;
    AEl.longVal[2] = 0xdc2822db40c0ac2e;
    AEl.longVal[3] = 0x183227397098d014;

    BEl.longVal[0]  = 0x1bb8e645ae216da7;
    BEl.longVal[1]  = 0x53fe3ab1e35c59e3;
    BEl.longVal[2]  = 0x8c49833d53bb8085;
    BEl.longVal[3]  = 0x0216d0b17f4e44a5;

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
    //typedef uint64_t unit64_t;

    //show_extern_vars();
    //Fr_Rw_copy_test();
    //Fr_Rw_add_test();
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
    //Fr_rawIsZero_test();
    Fr_rawSwap_test();

//    printf("%d  ", sizeof(FrElement));
//    printf("%d  ", sizeof(FrRawElement));

//    std::cout << typeid(uint64_t).name() << '\n';
//    std::cout << typeid(FrRawElement).name() << '\n';
    cout << "Hello World!" << endl;
    return 0;
}
