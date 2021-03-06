#include "fr.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <assert.h>
#include <string>
#include <iostream>

/*
FrElement Fr_q = {0, 0x80000000, {0x43e1f593f0000001,
                                  0x2833e84879b97091,
                                  0xb85045b68181585d,
                                  0x30644e72e131a029}};

FrRawElement Fr_rawq  = {0x43e1f593f0000001,
                         0x2833e84879b97091,
                         0xb85045b68181585d,
                         0x30644e72e131a029};

FrElement Fr_R3 = {0, 0x80000000, {0x5e94d8e1b4bf0040,
                                   0x2a489cbe1cfbb6b8,
                                   0x893cc664a19fcfed,
                                   0x0cf8594b7fcc657c}};

FrRawElement Fr_rawR3 = {0x5e94d8e1b4bf0040,
                         0x2a489cbe1cfbb6b8,
                         0x893cc664a19fcfed,
                         0x0cf8594b7fcc657c};

FrRawElement q = {0x43e1f593f0000001,
                  0x2833e84879b97091,
                  0xb85045b68181585d,
                  0x30644e72e131a029};

FrRawElement half = {0xa1f0fac9f8000000,
                     0x9419f4243cdcb848,
                     0xdc2822db40c0ac2e,
                     0x183227397098d014};

FrRawElement R2 = {0x1bb8e645ae216da7,
                   0x53fe3ab1e35c59e3,
                   0x8c49833d53bb8085,
                   0x0216d0b17f4e44a5};

FrRawElement R3 = {0x5e94d8e1b4bf0040,
                   0x2a489cbe1cfbb6b8,
                   0x893cc664a19fcfed,
                   0x0cf8594b7fcc657c};

uint64_t lboMask = {0x3fffffffffffffff};
uint64_t np  = {0xc2e1f593efffffff};
*/
extern "C"
{
    extern FrElement Fr_q;
    extern FrElement Fr_R3;
    extern FrRawElement Fr_rawq;
    extern FrRawElement Fr_rawR3;
    extern FrRawElement q;
    extern FrRawElement half;
    extern FrRawElement R2;
    extern FrRawElement R3;
    extern FrRawElement lboMask;
    extern FrRawElement np;
}



static mpz_t mq;
static mpz_t zero;
static mpz_t one;
static mpz_t mask;
static size_t nBits;
static bool initialized = false;


void Fr_toMpz(mpz_t r, PFrElement pE) {
    FrElement tmp;
    Fr_toNormal(&tmp, pE);
    if (!(tmp.type & Fr_LONG)) {
        mpz_set_si(r, tmp.shortVal);
        if (tmp.shortVal<0) {
            mpz_add(r, r, mq);
        }
    } else {
        mpz_import(r, Fr_N64, -1, 8, -1, 0, (const void *)tmp.longVal);
    }
}

void Fr_fromMpz(PFrElement pE, mpz_t v) {
    if (mpz_fits_sint_p(v)) {
        pE->type = Fr_SHORT;
        pE->shortVal = mpz_get_si(v);
    } else {
        pE->type = Fr_LONG;
        for (int i=0; i<Fr_N64; i++) pE->longVal[i] = 0;
        mpz_export((void *)(pE->longVal), NULL, -1, 8, -1, 0, v);
    }
}


bool Fr_init() {
    if (initialized) return false;
    initialized = true;
    mpz_init(mq);
    mpz_import(mq, Fr_N64, -1, 8, -1, 0, (const void *)Fr_q.longVal);
    mpz_init_set_ui(zero, 0);
    mpz_init_set_ui(one, 1);
    nBits = mpz_sizeinbase (mq, 2);
    mpz_init(mask);
    mpz_mul_2exp(mask, one, nBits);
    mpz_sub(mask, mask, one);
    return true;
}

void Fr_str2element(PFrElement pE, char const *s) {
    mpz_t mr;
    mpz_init_set_str(mr, s, 10);
    mpz_fdiv_r(mr, mr, mq);
    Fr_fromMpz(pE, mr);
    mpz_clear(mr);
}

char *Fr_element2str(PFrElement pE) {
    FrElement tmp;
    mpz_t r;
    if (!(pE->type & Fr_LONG)) {
        if (pE->shortVal>=0) {
            char *r = new char[32];
            sprintf(r, "%d", pE->shortVal);
            return r;
        } else {
            mpz_init_set_si(r, pE->shortVal);
            mpz_add(r, r, mq);
        }
    } else {
        Fr_toNormal(&tmp, pE);
        mpz_init(r);
        mpz_import(r, Fr_N64, -1, 8, -1, 0, (const void *)tmp.longVal);
    }
    char *res = mpz_get_str (0, 10, r);
    mpz_clear(r);
    return res;
}

void Fr_idiv(PFrElement r, PFrElement a, PFrElement b) {
    mpz_t ma;
    mpz_t mb;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr);

    Fr_toMpz(ma, a);
    // char *s1 = mpz_get_str (0, 10, ma);
    // printf("s1 %s\n", s1);
    Fr_toMpz(mb, b);
    // char *s2 = mpz_get_str (0, 10, mb);
    // printf("s2 %s\n", s2);
    mpz_fdiv_q(mr, ma, mb);
    // char *sr = mpz_get_str (0, 10, mr);
    // printf("r %s\n", sr);
    Fr_fromMpz(r, mr);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

void Fr_mod(PFrElement r, PFrElement a, PFrElement b) {
    mpz_t ma;
    mpz_t mb;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr);

    Fr_toMpz(ma, a);
    Fr_toMpz(mb, b);
    mpz_fdiv_r(mr, ma, mb);
    Fr_fromMpz(r, mr);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

void Fr_pow(PFrElement r, PFrElement a, PFrElement b) {
    mpz_t ma;
    mpz_t mb;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr);

    Fr_toMpz(ma, a);
    Fr_toMpz(mb, b);
    mpz_powm(mr, ma, mb, mq);
    Fr_fromMpz(r, mr);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

void Fr_inv(PFrElement r, PFrElement a) {
    mpz_t ma;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mr);

    Fr_toMpz(ma, a);
    mpz_invert(mr, ma, mq);
    Fr_fromMpz(r, mr);
    mpz_clear(ma);
    mpz_clear(mr);
}

void Fr_div(PFrElement r, PFrElement a, PFrElement b) {
    FrElement tmp;
    Fr_inv(&tmp, b);
    Fr_mul(r, a, &tmp);
}

void Fr_fail() {
    assert(false);
}


RawFr::RawFr() {
    Fr_init();
    fromString(fZero, "0");
    fromString(fOne, "1");
    neg(fNegOne, fOne);
}

RawFr::~RawFr() {
}

void RawFr::fromString(Element &r, std::string s) {
    mpz_t mr;
    mpz_init_set_str(mr, s.c_str(), 10);
    mpz_fdiv_r(mr, mr, mq);
    for (int i=0; i<Fr_N64; i++) r.v[i] = 0;
    mpz_export((void *)(r.v), NULL, -1, 8, -1, 0, mr);
    Fr_rawToMontgomery(r.v,r.v);
    mpz_clear(mr);
}

void RawFr::fromUI(Element &r, unsigned long int v) {
    mpz_t mr;
    mpz_init(mr);
    mpz_set_ui(mr, v);
    for (int i=0; i<Fr_N64; i++) r.v[i] = 0;
    mpz_export((void *)(r.v), NULL, -1, 8, -1, 0, mr);
    Fr_rawToMontgomery(r.v,r.v);
    mpz_clear(mr);
}



std::string RawFr::toString(Element &a, uint32_t radix) {
    Element tmp;
    mpz_t r;
    Fr_rawFromMontgomery(tmp.v, a.v);
    mpz_init(r);
    mpz_import(r, Fr_N64, -1, 8, -1, 0, (const void *)(tmp.v));
    char *res = mpz_get_str (0, radix, r);
    mpz_clear(r);
    std::string resS(res);
    free(res);
    return resS;
}

void RawFr::inv(Element &r, Element &a) {
    mpz_t mr;
    mpz_init(mr);
    mpz_import(mr, Fr_N64, -1, 8, -1, 0, (const void *)(a.v));
    mpz_invert(mr, mr, mq);


    for (int i=0; i<Fr_N64; i++) r.v[i] = 0;
    mpz_export((void *)(r.v), NULL, -1, 8, -1, 0, mr);

    Fr_rawMMul(r.v, r.v,Fr_rawR3);
    mpz_clear(mr);
}

void RawFr::div(Element &r, Element &a, Element &b) {
    Element tmp;
    inv(tmp, b);
    mul(r, a, tmp);
}

#define BIT_IS_SET(s, p) (s[p>>3] & (1 << (p & 0x7)))
void RawFr::exp(Element &r, Element &base, uint8_t* scalar, unsigned int scalarSize) {
    bool oneFound = false;
    Element copyBase;
    copy(copyBase, base);
    for (int i=scalarSize*8-1; i>=0; i--) {
        if (!oneFound) {
            if ( !BIT_IS_SET(scalar, i) ) continue;
            copy(r, copyBase);
            oneFound = true;
            continue;
        }
        square(r, r);
        if ( BIT_IS_SET(scalar, i) ) {
            mul(r, r, copyBase);
        }
    }
    if (!oneFound) {
        copy(r, fOne);
    }
}

void RawFr::toMpz(mpz_t r, Element &a) {
    Element tmp;
    Fr_rawFromMontgomery(tmp.v, a.v);
    mpz_import(r, Fr_N64, -1, 8, -1, 0, (const void *)tmp.v);
}

void RawFr::fromMpz(Element &r, mpz_t a) {
    for (int i=0; i<Fr_N64; i++) r.v[i] = 0;
    mpz_export((void *)(r.v), NULL, -1, 8, -1, 0, a);
    Fr_rawToMontgomery(r.v, r.v);
}
/*****************************************************************************************
 * ASM Functions to C/C++ using GNU MP Lib Begin
******************************************************************************************/
void Fr_rawAdd(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB)
{
    mpz_t ma;
    mpz_t mb;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr);

    mpz_import(ma, Fr_N64, -1, 8, -1, 0, (const void *)pRawA);
    mpz_import(mb, Fr_N64, -1, 8, -1, 0, (const void *)pRawB);
    mpz_add(mr, ma, mb);
    for (int i=0; i<Fr_N64; i++) pRawResult[i] = 0;
    //mpz_export((void *)pRawResult, NULL, -1, 8, -1, 0, mr);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

void Fr_rawSub(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB)
{
    mpz_t ma;
    mpz_t mb;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr);

    mpz_import(ma, Fr_N64, -1, 8, -1, 0, (const void *)pRawA);
    mpz_import(mb, Fr_N64, -1, 8, -1, 0, (const void *)pRawB);
    mpz_sub(mr, ma, mb);
    for (int i=0; i<Fr_N64; i++) pRawResult[i] = 0;
    mpz_export((void *)pRawResult, NULL, -1, 8, -1, 0, mr);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

void Fr_rawNeg(FrRawElement pRawResult, FrRawElement pRawA)
{
    mpz_t ma;
    mpz_t mq;
    mpz_t mr;
    mpz_init(ma);
    mpz_init(mq);
    mpz_init(mr);

    mpz_import(ma, Fr_N64, -1, sizeof(pRawA[0]), -1, 0, (const void *)pRawA);
    mpz_import(mq, Fr_N64, -1, sizeof(pRawA[0]), -1, 0, (const void *)q);
    mpz_sub(mr, mq, ma);
    for (int i=0; i<Fr_N64; i++) pRawResult[i] = 0;
    mpz_export((void *)pRawResult, NULL, -1, sizeof(pRawResult[0]), -1, 0, mr);

    mpz_clear(ma);
    mpz_clear(mr);

}

void Fr_rawCopy(FrRawElement pRawResult, FrRawElement pRawA)
{
    for (int i=0; i<Fr_N64; i++)
        pRawResult[i] = pRawA[i];
}

void Fr_copy(PFrElement r, PFrElement a)
{
    r->shortVal = a->shortVal;
    r->type = a->type;
    for (int i=0; i<Fr_N64; i++)
        r->longVal[i] = a->longVal[i];
}

void Fr_copyn(PFrElement r, PFrElement a, int n)
{
    for (int i=0; i<n; i++)
        r->longVal[i] = a->longVal[i];
}

int Fr_rawIsEq(FrRawElement pRawA, FrRawElement pRawB)
{
    for (int i=0; i<Fr_N64; i++)
    {
        if (pRawA[i] != pRawB[i])
            return 0;
    }
    return 1;
}

void Fr_rawMMul(FrRawElement pRawResult, FrRawElement pRawA, FrRawElement pRawB)
{
    mpz_t ma;
    mpz_t mb;
    mpz_t mnp;
    mpz_t mq;
    mpz_t mr1;
    mpz_t mr2;
    mpz_t mr3;
    mpz_t mr4;

    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr1);
    mpz_init(mr2);
    mpz_init(mr3);
    mpz_init(mr4);
    mpz_init(mnp);
    mpz_init(mq);

    mpz_import(ma, Fr_N64, -1, 8, -1, 0, (const void *)pRawA);
    mpz_import(mb, Fr_N64, -1, 8, -1, 0, (const void *)pRawB);
    mpz_import(mnp, 1, -1, 8, -1, 0, (const void *)&np);
    mpz_import(mq, Fr_N64, -1, 8, -1, 0, (const void *)q);

    // FirstLoop
    mpz_mul_ui(mr1, mb, pRawA[0]);
    // Second Loop
    mpz_mul_ui(mr2, mnp, mr1->_mp_d[0]);
    mpz_mul_ui(mr3, mq, mr2->_mp_d[0]);
    mpz_add(mr4, mr3, mr1);
    mr4->_mp_d[0] = mr4->_mp_d[1];
    mr4->_mp_d[1] = mr4->_mp_d[2];
    mr4->_mp_d[2] = mr4->_mp_d[3];
    mr4->_mp_d[3] = mr4->_mp_d[4];
    mr4->_mp_d[4] = 0;

    // FirstLoop
    mpz_mul_ui(mr1, mb, pRawA[1]);
    // Second Loop
    mpz_add(mr1, mr4, mr1);
    mpz_mul_ui(mr2, mnp, mr1->_mp_d[0]);
    mpz_mul_ui(mr3, mq, mr2->_mp_d[0]);
    mpz_add(mr4, mr3, mr1);
    mr4->_mp_d[0] = mr4->_mp_d[1];
    mr4->_mp_d[1] = mr4->_mp_d[2];
    mr4->_mp_d[2] = mr4->_mp_d[3];
    mr4->_mp_d[3] = mr4->_mp_d[4];
    mr4->_mp_d[4] = 0;

    // FirstLoop
    mpz_mul_ui(mr1, mb, pRawA[2]);
    // Second Loop
    mpz_add(mr1, mr4, mr1);
    mpz_mul_ui(mr2, mnp, mr1->_mp_d[0]);
    mpz_mul_ui(mr3, mq, mr2->_mp_d[0]);
    mpz_add(mr4, mr3, mr1);
    mr4->_mp_d[0] = mr4->_mp_d[1];
    mr4->_mp_d[1] = mr4->_mp_d[2];
    mr4->_mp_d[2] = mr4->_mp_d[3];
    mr4->_mp_d[3] = mr4->_mp_d[4];
    mr4->_mp_d[4] = 0;

    // FirstLoop
    mpz_mul_ui(mr1, mb, pRawA[3]);
    // Second Loop
    mpz_add(mr1, mr4, mr1);
    mpz_mul_ui(mr2, mnp, mr1->_mp_d[0]);
    mpz_mul_ui(mr3, mq, mr2->_mp_d[0]);
    mpz_add(mr4, mr3, mr1);
    mr4->_mp_d[0] = mr4->_mp_d[1];
    mr4->_mp_d[1] = mr4->_mp_d[2];
    mr4->_mp_d[2] = mr4->_mp_d[3];
    mr4->_mp_d[3] = mr4->_mp_d[4];
    mr4->_mp_d[4] = 0;

    if (!mpz_cmp(mr4,mq))
    {
        mpz_sub(mr4,mr4,mq);
    }

    for (int i=0; i<Fr_N64; i++) pRawResult[i] = mr4->_mp_d[i];
//     for (int i=0; i<Fr_N64; i++) pRawResult[i] = 0;
//     mpz_export((void *)pRawResult, NULL, -1, 8, -1, 0, mr4);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr1);
    mpz_clear(mr2);
    mpz_clear(mr3);
    mpz_clear(mr4);
    mpz_clear(mnp);
    mpz_clear(mq);
}

void Fr_rawMSquare(FrRawElement pRawResult, FrRawElement pRawA)
{
    Fr_rawMMul(pRawResult, pRawA, pRawA);
}

void Fr_rawMMul1(FrRawElement pRawResult, FrRawElement pRawA, uint64_t pRawB)
{
    FrRawElement pRawBtmp = {0};
    pRawBtmp[0] = pRawB;
    Fr_rawMMul(pRawResult, pRawA, pRawBtmp);
}

void Fr_rawToMontgomery(FrRawElement pRawResult, FrRawElement pRawA)
{
    Fr_rawMMul(pRawResult, pRawA, R2);
}

void Fr_rawFromMontgomery(FrRawElement pRawResult, FrRawElement pRawA)
{
    mpz_t ma;
    mpz_t mnp;
    mpz_t mq;
    mpz_t mr1;
    mpz_t mr2;

    mpz_init(ma);
    mpz_init(mr1);
    mpz_init(mr2);
    mpz_init(mnp);
    mpz_init(mq);

    mpz_import(ma, Fr_N64, -1, 8, -1, 0, (const void *)pRawA);
    mpz_import(mnp, 1, -1, 8, -1, 0, (const void *)&np);
    mpz_import(mq, Fr_N64, -1, 8, -1, 0, (const void *)q);

    // Second Loop
    mpz_mul_ui(mr1, mnp, ma->_mp_d[0]);
    mpz_mul_ui(mr2, mq, mr1->_mp_d[0]);
    mpz_add(mr2, mr2, ma);
    mr2->_mp_d[0] = mr2->_mp_d[1];
    mr2->_mp_d[1] = mr2->_mp_d[2];
    mr2->_mp_d[2] = mr2->_mp_d[3];
    mr2->_mp_d[3] = mr2->_mp_d[4];
    mr2->_mp_d[4] = 0;

    // Second Loop
    mpz_mul_ui(mr1, mnp, mr2->_mp_d[0]);
    mpz_mul_ui(mr1, mq, mr1->_mp_d[0]);
    mpz_add(mr2, mr1, mr2);
    mr2->_mp_d[0] = mr2->_mp_d[1];
    mr2->_mp_d[1] = mr2->_mp_d[2];
    mr2->_mp_d[2] = mr2->_mp_d[3];
    mr2->_mp_d[3] = mr2->_mp_d[4];
    mr2->_mp_d[4] = 0;

    // Second Loop
    mpz_mul_ui(mr1, mnp, mr2->_mp_d[0]);
    mpz_mul_ui(mr1, mq, mr1->_mp_d[0]);
    mpz_add(mr2, mr1, mr2);
    mr2->_mp_d[0] = mr2->_mp_d[1];
    mr2->_mp_d[1] = mr2->_mp_d[2];
    mr2->_mp_d[2] = mr2->_mp_d[3];
    mr2->_mp_d[3] = mr2->_mp_d[4];
    mr2->_mp_d[4] = 0;

    // Second Loop
    mpz_mul_ui(mr1, mnp, mr2->_mp_d[0]);
    mpz_mul_ui(mr1, mq, mr1->_mp_d[0]);
    mpz_add(mr2, mr1, mr2);
    mr2->_mp_d[0] = mr2->_mp_d[1];
    mr2->_mp_d[1] = mr2->_mp_d[2];
    mr2->_mp_d[2] = mr2->_mp_d[3];
    mr2->_mp_d[3] = mr2->_mp_d[4];
    mr2->_mp_d[4] = 0;

    if (!mpz_cmp(mr2,mq))
    {
        mpz_sub(mr2,mr2,mq);
    }

    for (int i=0; i<Fr_N64; i++) pRawResult[i] = mr2->_mp_d[i];

    mpz_clear(ma);
    mpz_clear(mr1);
    mpz_clear(mr2);
    mpz_clear(mnp);
    mpz_clear(mq);
}

void Fr_toLongNormal(PFrElement r, PFrElement a)
{
    mpz_t ma;
    mpz_t mb;
    mpz_t mc;
    mpz_t mr;
    mpz_t mq;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mc);
    mpz_init(mr);
    mpz_init(mq);
    FrRawElement pRawResult = {0};
    FrRawElement pRawA = {0};
    uint64_t rax = 0;
    Fr_toMpz(ma, a);
    //mpz_fdiv_q(mr, ma, mb);

    //Test bit bit index in op and return 0 or 1 accordingly.
    if (mpz_tstbit (ma, 63)) // ; check if long
    {
        mpz_set(mb, ma); // ; save rsi
        ma->_mp_d[0] = ma->_mp_d[0];
        ma->_mp_d[1] = ma->_mp_d[1];
        ma->_mp_d[2] = 0;
        ma->_mp_d[3] = 0;

        //rawCopyS2L:
        mpz_setbit(mc,7); //al, 0x80
        for(int i=0; i<55; i++) //shl     rax, 56
            mpz_mul_ui(mc,mc,2);

        mpz_set(mr, mc); // mov     [rdi], rax    ; set the result to LONG normal


        //u64toLong_adjust_neg:
        if (mpz_cmp_ui(ma, 0) < 0)
        {
            mpz_import(mq, Fr_N64, -1, 8, -1, 0, (const void *)q);
            mpz_add_ui(ma, ma, mq->_mp_d[0]); //add    rsi, [q]         ; Set the first digit
            mr->_mp_d[1] = ma->_mp_d[0]; //mov    [rdi + 8], rsi   ;
            ma->_mp_d[0] = -1; //mov    rsi, -1          ; all ones
            rax = ma->_mp_d[0];
            rax += mq->_mp_d[1];
            mr->_mp_d[2] = rax;

            rax = ma->_mp_d[0];
            rax += mq->_mp_d[2];
            mr->_mp_d[3] = rax;

            rax = ma->_mp_d[0];
            rax += mq->_mp_d[3];
            mr->_mp_d[4] = rax;
        }
        else
        {
            mpz_set(mr, ma);
        } // end of rawCopyS2L

        mpz_set(ma, mb); // ; recover rsi
        mb->_mp_d[0] = 0;
        mb->_mp_d[1] = 0;
        mb->_mp_d[2] = 0;
        mb->_mp_d[3] = 0;
        mpz_setbit(mb,7); //mov r11b, 0x80
        for(int i=0; i<23; i++) //shl r11d, 24
            mb->_mp_d[0] = mb->_mp_d[0]*2;

        mr->_mp_d[0] = mb->_mp_d[0]; //mov [rdi+4], r11d

    }
    else if (mpz_tstbit (ma, 62)) //; check if montgomery
    {
        mpz_add_ui(mr, mr, 8);
        mpz_add_ui(ma, ma, 8);
        mpz_export((void *)pRawResult, NULL, -1, 8, -1, 0, mr);
        mpz_export((void *)pRawA, NULL, -1, 8, -1, 0, ma);
        Fr_rawFromMontgomery(pRawResult, pRawA);
        mpz_import(ma, Fr_N64, -1, 8, -1, 0, (const void *)pRawA);
        mpz_import(mr, Fr_N64, -1, 8, -1, 0, (const void *)pRawResult);
        mpz_sub_ui(mr, mr, 8);
        mpz_sub_ui(ma, ma, 8);

        mpz_setbit(mb,7); //mov r11b, 0x80
        for(int i=0; i<23; i++) //shl r11d, 24
            mb->_mp_d[0] = mb->_mp_d[0]*2;

        mr->_mp_d[0] = mb->_mp_d[0]; //mov [rdi+4], r11d
    }
    else
    {
        Fr_copy(r, a);
    }
    Fr_fromMpz(r, mr);

    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

void Fr_toNormal(PFrElement r, PFrElement a)
{
    if (a->type == Fr_LONGMONTGOMERY)
    {
        Fr_rawFromMontgomery(r->longVal, a->longVal);
    }
    else
    {
        Fr_copy(r, a);
    }
}

void Fr_toMontgomery(PFrElement r, PFrElement a)
{
    mpz_t ma;
    mpz_t mb;
    mpz_t mr;
    mpz_t mq;
    mpz_init(ma);
    mpz_init(mb);
    mpz_init(mr);
    mpz_init(mq);
    FrRawElement pRawResult = {0};
    FrRawElement pRawA = {0};
    uint64_t rax = 0;
    Fr_toMpz(ma, a);
    //mpz_fdiv_q(mr, ma, mb);

    //Test bit bit index in op and return 0 or 1 accordingly.
    if (mpz_tstbit (ma, 63)) // toMontgomeryLong
    {
        mpz_set(mr, ma);       //    mov     [rdi], rax
        mpz_add_ui(mr, mr, 8); //    add     rdi, 8
        mpz_add_ui(ma, ma, 8); //    add     rsi, 8
        mpz_export((void *)pRawResult, NULL, -1, 8, -1, 0, mr);
        mpz_export((void *)pRawA, NULL, -1, 8, -1, 0, ma);
        Fr_rawMMul(pRawResult, pRawA, R2);
        mpz_import(ma, Fr_N64, -1, 8, -1, 0, (const void *)pRawA);
        mpz_import(mr, Fr_N64, -1, 8, -1, 0, (const void *)pRawResult);
        mpz_sub_ui(mr, mr, 8);
        mpz_sub_ui(ma, ma, 8);

        //mov r11b, 0xC0
        mpz_setbit(mb,7);
        mpz_setbit(mb,6);
        for(int i=0; i<23; i++) //shl r11d, 24
            mb->_mp_d[0] = mb->_mp_d[0]*2;

        mr->_mp_d[0] = mb->_mp_d[0]; //mov [rdi+4], r11d
        Fr_fromMpz(r, mr);
    }
    else if (mpz_tstbit (ma, 62))    // toMontgomery_doNothing
    {
        Fr_copy(r, a);
    }


    mpz_clear(ma);
    mpz_clear(mb);
    mpz_clear(mr);
}

int Fr_rawIsZero(FrRawElement pRawB)
{
    for (int i=0; i<Fr_N64; i++)
    {
        if (pRawB[i] != 0)
            return 0;
    }
    return 1;
}

void Fr_rawSwap(FrRawElement pRawResult, FrRawElement pRawA)
{
    FrRawElement tmp = {0};
    for (int i=0; i<Fr_N64; i++)
    {
        tmp[i] = pRawResult[i];
        pRawResult[i] = pRawA[i];
        pRawA[i] = tmp[i];
    }
}

void rawCopyS2L(PFrElement r, int64_t temp);
void mul_s1s2(PFrElement r, PFrElement a, PFrElement b);
void mul_l1nl2n(PFrElement r, PFrElement a, PFrElement b);
void mul_l1ml2n(PFrElement r,PFrElement a,PFrElement b);
void mul_l1nl2m(PFrElement r, PFrElement a, PFrElement b);
void mul_l1ml2m(PFrElement r,PFrElement a,PFrElement b);

void mul_l1ns2n(PFrElement r,PFrElement a,PFrElement b);
void mul_s1nl2n(PFrElement r,PFrElement a,PFrElement b);
void mul_l1ms2n(PFrElement r,PFrElement a,PFrElement b);
void mul_s1nl2m(PFrElement r,PFrElement a,PFrElement b);

void mul_l1ns2m(PFrElement r,PFrElement a,PFrElement b);
void mul_l1ms2m(PFrElement r,PFrElement a,PFrElement b);
void mul_s1ml2n(PFrElement r,PFrElement a,PFrElement b);
void mul_s1ml2m(PFrElement r,PFrElement a,PFrElement b);


void Fr_mul(PFrElement r, PFrElement a, PFrElement b)
{
    //mpz_import(mr3, Fr_N64, -1, 8, -1, 0, (const void *)Fr_rawR3);

    if (a->type & Fr_LONG) // if (mpz_tstbit (ma, 63)) // 2267 ; Check if is short first operand
    {
        // jc     mul_l1
        if (b->type & Fr_LONG) //if (mpz_tstbit (mb, 63)) // 2293 ; Check if is short second operand
        {
            // mul_l1l2
            if (a->type == Fr_LONGMONTGOMERY) // if (mpz_tstbit (ma, 62)) // 2511 ; check if montgomery first
            {
                // mul_l1ml2
                if (b->type == Fr_LONGMONTGOMERY) //if (mpz_tstbit (mb, 62)) // 2554 ; check if montgomery second
                {
                    mul_l1ml2m(r, a, b);
                }
                else
                {
                    mul_l1ml2n(r, a, b);
                }
            }
            else if (b->type == Fr_LONGMONTGOMERY) //if (mpz_tstbit (mb, 62)) // 2514 ; check if montgomery second
            {
                mul_l1nl2m(r, a, b);
            }
            else
            {
                mul_l1nl2n(r, a, b);
            }
        }
        //mul_l1s2:
        else if (a->type == Fr_LONGMONTGOMERY) //if (mpz_tstbit (ma, 62)) // 2298 ; check if montgomery first
        {
            // mul_l1ms2
            if (b->type == Fr_LONGMONTGOMERY) //if (mpz_tstbit (mb, 62)) // 2358 ; check if montgomery second
            {
                mul_l1ms2m(r, a, b);
            }
            else
            {
                mul_l1ms2n(r, a, b);
            }

        }
        // mul_l1ns2
        else
        {
            if (b->type == Fr_SHORTMONTGOMERY) //if (mpz_tstbit (mb, 62)) // 2301 ; check if montgomery second
            {
                mul_l1ns2m(r, a, b);
            }
            else
            {
                mul_l1ns2n(r, a, b);
            }
        }
    }
    else if (b->type & Fr_LONG)//if (mpz_tstbit (mb, 63)) // 2269  ; Check if is short second operand
    {
        // mul_s1l2
        if (a->type == Fr_SHORTMONTGOMERY)//if (mpz_tstbit (ma, 62)) // 2406  ; check if montgomery first
        {
            // mul_s1ml2
            if (b->type == Fr_LONGMONTGOMERY)//if (mpz_tstbit (mb, 62)) // 2479  ; check if montgomery second
            {
                mul_s1ml2m(r, a, b);
            }
            else
            {
                mul_s1ml2n(r,a, b);
            }
        }
        // mul_s1nl2
        else if (b->type == Fr_LONGMONTGOMERY) //if (mpz_tstbit (mb, 62)) // 2409; check if montgomery second
        {
            mul_s1nl2m(r, a, b);
        }
        // mul_s1nl2n
        else
        {
            mul_s1nl2n(r, a, b);
        }
    }
    else
    {
         mul_s1s2(r, a, b);
    }
}

void mul_s1s2(PFrElement r, PFrElement a, PFrElement b)
{
    mpz_t rax;
    mpz_init(rax);

    int64_t temp = (int64_t)a->shortVal * (int64_t)b->shortVal;
    r->longVal[0] = temp;
    mpz_import(rax, Fr_N64, -1, 8, -1, 0, (const void *)r);
    // mul_manageOverflow
    if (!mpz_fits_sint_p(rax))
    {
        rawCopyS2L(r, temp);
    }
    else
    {
        r->type = Fr_SHORT;
        r->shortVal = temp;
    }
    mpz_clear(rax);
}

void rawCopyS2L(PFrElement r, int64_t temp)
{
    r->longVal[0] = temp; // ?? ?????????????????????? ?????????? ???? 256 ??????
    r->type = Fr_LONG;      // ?? ?????????????????????? ?????????? ???? 256 ??????

    mpz_t mr;
    mpz_init(mr);
    Fr_toMpz(mr, r);
    mpz_t mq;
    mpz_init(mq);
    Fr_toMpz(mq, &Fr_q);


    if (temp < 0)
    {
       mpz_add(mr, mr, mq);
    }
    Fr_fromMpz(r, mr);
    mpz_clear(mr);
    mpz_clear(mq);
}

void mul_l1nl2n(PFrElement r,PFrElement a,PFrElement b)
{
    FrElement tmp1;
    FrElement tmp2;

    r->type = Fr_LONGMONTGOMERY;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
    tmp1.type = Fr_LONG;
    tmp2.type = Fr_LONG;
    tmp1.shortVal = 0;
    tmp2.shortVal = 0;
    for (int i=0; i<Fr_N64; i++)
    {
        tmp1.longVal[i] = r->longVal[i];
        tmp2.longVal[i] = Fr_R3.longVal[i];
    }
    Fr_rawMMul(&r->longVal[0], &tmp1.longVal[0], &tmp2.longVal[0]);
}

void mul_l1nl2m(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONG;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}

void mul_l1ml2m(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONGMONTGOMERY;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}

void mul_l1ml2n(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONG;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}

void mul_l1ns2n(PFrElement r,PFrElement a,PFrElement b)
{
    FrElement tmp1;
    FrElement tmp2;
    int32_t   tmp3;

    r->type = Fr_LONGMONTGOMERY;
    if (b->shortVal >= 0)
    {
        // tmp_5:
        Fr_rawMMul1(&r->longVal[0], &a->longVal[0], b->shortVal);
        // tmp_6:
        tmp1.type = Fr_LONG;
        tmp2.type = Fr_LONG;
        tmp1.shortVal = 0;
        tmp2.shortVal = 0;
        for (int i=0; i<Fr_N64; i++)
        {
            tmp1.longVal[i] = r->longVal[i];
            tmp2.longVal[i] = Fr_R3.longVal[i];
        }
        Fr_rawMMul(&r->longVal[0], &tmp1.longVal[0], &tmp2.longVal[0]);
    }
    else
    {
        tmp3 = b->shortVal * (-1);
        Fr_rawMMul1(&r->longVal[0], &a->longVal[0], tmp3);
        Fr_rawNeg(&r->longVal[0], &r->longVal[0]);
        // tmp_6:
        tmp1.type = Fr_LONG;
        tmp2.type = Fr_LONG;
        tmp1.shortVal = 0;
        tmp2.shortVal = 0;
        for (int i=0; i<Fr_N64; i++)
        {
            tmp1.longVal[i] = r->longVal[i];
            tmp2.longVal[i] = Fr_R3.longVal[i];
        }
        Fr_rawMMul(&r->longVal[0], &tmp1.longVal[0], &tmp2.longVal[0]);
    }
}

void mul_s1nl2n(PFrElement r,PFrElement a,PFrElement b)
{
    FrElement tmp1;
    FrElement tmp2;
    int32_t   tmp3;

    r->type = Fr_LONGMONTGOMERY;
    if (a->shortVal >= 0)
    {
        // tmp_9:
        Fr_rawMMul1(&r->longVal[0], &b->longVal[0], a->shortVal);
        // tmp_10:
        tmp1.type = Fr_LONG;
        tmp2.type = Fr_LONG;
        tmp1.shortVal = 0;
        tmp2.shortVal = 0;
        for (int i=0; i<Fr_N64; i++)
        {
            tmp1.longVal[i] = r->longVal[i];
            tmp2.longVal[i] = Fr_R3.longVal[i];
        }
        Fr_rawMMul(&r->longVal[0], &tmp1.longVal[0], &tmp2.longVal[0]);
    }
    else
    {
        tmp3 = a->shortVal * (-1);
        Fr_rawMMul1(&r->longVal[0], &b->longVal[0], tmp3);
        Fr_rawNeg(&r->longVal[0], &r->longVal[0]);
        // tmp_6:
        tmp1.type = Fr_LONG;
        tmp2.type = Fr_LONG;
        tmp1.shortVal = 0;
        tmp2.shortVal = 0;
        for (int i=0; i<Fr_N64; i++)
        {
            tmp1.longVal[i] = r->longVal[i];
            tmp2.longVal[i] = Fr_R3.longVal[i];
        }
        Fr_rawMMul(&r->longVal[0], &tmp1.longVal[0], &tmp2.longVal[0]);
    }
}

void mul_l1ms2n(PFrElement r,PFrElement a,PFrElement b)
{
    FrElement tmp1;
    FrElement tmp2;
    int32_t   tmp3;

    r->type = Fr_LONG;
    if (b->shortVal >= 0)
    {
        // tmp_7:
        Fr_rawMMul1(&r->longVal[0], &a->longVal[0], b->shortVal);
        // tmp_8:
    }
    else
    {
        tmp3 = b->shortVal * (-1);
        Fr_rawMMul1(&r->longVal[0], &a->longVal[0], tmp3);
        Fr_rawNeg(&r->longVal[0], &r->longVal[0]);
        // tmp_8:
    }
}

void mul_s1nl2m(PFrElement r,PFrElement a,PFrElement b)
{
    FrElement tmp1;
    FrElement tmp2;
    int32_t   tmp3;

    r->type = Fr_LONG;
    if (a->shortVal >= 0)
    {
        // tmp_11:
        Fr_rawMMul1(&r->longVal[0], &b->longVal[0], a->shortVal);
        // tmp_12:
    }
    else
    {
        tmp3 = a->shortVal * (-1);
        Fr_rawMMul1(&r->longVal[0], &b->longVal[0], tmp3);
        Fr_rawNeg(&r->longVal[0], &r->longVal[0]);
        // tmp_12:
    }
}

void mul_l1ns2m(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONG;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}

void mul_l1ms2m(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONGMONTGOMERY;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}

void mul_s1ml2m(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONGMONTGOMERY;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}

void mul_s1ml2n(PFrElement r,PFrElement a,PFrElement b)
{
    r->type = Fr_LONG;
    Fr_rawMMul(&r->longVal[0], &a->longVal[0], &b->longVal[0]);
}





/*****************************************************************************************
 * ASM Functions to C/C++ using GNU MP Lib End
******************************************************************************************/

static bool init = Fr_init();

RawFr RawFr::field;

