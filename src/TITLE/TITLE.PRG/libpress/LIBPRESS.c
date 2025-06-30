#include "common.h"
#include <libpress.h>
#include <libetc.h>
#include <stdio.h>

void func_80072050(int);
void func_80072140(u_long* arg0, u_int arg1);
void func_800721D0(u_long* buf, int size);
int func_8007225C();
int func_800722F0();
u_int func_80072384();
int DMACallback(int, void (*)());

extern u_int volatile* D_80075C88;

// Commented out functions only match with GCC 2.8.0, but this breaks the others.

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTReset);
/*void DecDCTReset(int mode) {
    if (mode == 0) {
        ResetCallback();
    }
    func_80072050(mode);
}*/

static int D_80075B44 = 0x40000001;
static char D_80075B48[] = { 0x02, 0x10, 0x10, 0x13, 0x10, 0x13, 0x16, 0x16, 0x16, 0x16,
    0x16, 0x16, 0x1A, 0x18, 0x1A, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B,
    0x1B, 0x1D, 0x1D, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x1D, 0x1D, 0x1B, 0x1B, 0x1D, 0x1D,
    0x20, 0x20, 0x22, 0x22, 0x25, 0x26, 0x25, 0x23, 0x23, 0x22, 0x23, 0x26, 0x26, 0x28,
    0x28, 0x28, 0x30, 0x30, 0x2E, 0x2E, 0x38, 0x38, 0x3A, 0x45, 0x45, 0x53 };
static char D_80075B88[] = { 0x02, 0x10, 0x10, 0x13, 0x10, 0x13, 0x16, 0x16, 0x16, 0x16,
    0x16, 0x16, 0x1A, 0x18, 0x1A, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B,
    0x1B, 0x1D, 0x1D, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x1D, 0x1D, 0x1B, 0x1B, 0x1D, 0x1D,
    0x20, 0x20, 0x22, 0x22, 0x25, 0x26, 0x25, 0x23, 0x23, 0x22, 0x23, 0x26, 0x26, 0x28,
    0x28, 0x28, 0x30, 0x30, 0x2E, 0x2E, 0x38, 0x38, 0x3A, 0x45, 0x45, 0x53 };
static int D_80075BC8 = 0x60000000;

DECDCTENV* DecDCTGetEnv(DECDCTENV* env)
{
    static short D_80075BCC[] = { 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82, 0x5A82,
        0x5A82, 0x7D8A, 0x6A6D, 0x471C, 0x18F8, 0xE707, 0xB8E3, 0x9592, 0x8275, 0x7641,
        0x30FB, 0xCF04, 0x89BE, 0x89BE, 0xCF04, 0x30FB, 0x7641, 0x6A6D, 0xE707, 0x8275,
        0xB8E3, 0x471C, 0x7D8A, 0x18F8, 0x9592, 0x5A82, 0xA57D, 0xA57D, 0x5A82, 0x5A82,
        0xA57D, 0xA57D, 0x5A82, 0x471C, 0x8275, 0x18F8, 0x6A6D, 0x9592, 0xE707, 0x7D8A,
        0xB8E3, 0x30FB, 0x89BE, 0x7641, 0xCF04, 0xCF04, 0x7641, 0x89BE, 0x30FB, 0x18F8,
        0xB8E3, 0x6A6D, 0x8275, 0x7D8A, 0x9592, 0x471C, 0xE707, 0x7350, 0x000E, 0x0000,
        0x0045 };

    int* var_a2;
    int i;
    int* var_a1;

    var_a2 = (int*)env->iq_y;
    var_a1 = (int*)D_80075B48;
    for (i = 15; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    var_a2 = (int*)env->iq_c;
    var_a1 = (int*)D_80075B88;
    for (i = 15; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    var_a2 = (int*)env->dct;
    var_a1 = (int*)D_80075BCC;
    for (i = 31; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    return env;
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTPutEnv);
/*DECDCTENV* DecDCTPutEnv(DECDCTENV* arg0) {
    int i;
    int *src1, *dst1;
    int *src2, *dst2;

    dst1 = D_80075B48;
    src1 = (int*)&arg0->iq_y;
    for (i = 15; i != -1; i--) {
        *dst1++ = *src1++;
    }

    dst2 = D_80075B88;
    src2 = (int*)&arg0->iq_c;
    for (i = 15; i != -1; i--) {
        *dst2++ = *src2++;
    }

    func_80072140(D_80075B44, 32);
    func_80072140(D_80075BC8, 32);

    return arg0;
}*/

void DecDCTin(u_long* buf, int mode)
{
    if (mode & 1) {
        *buf &= 0xF7FFFFFF;
    } else {
        *buf |= 0x08000000;
    }

    if (mode & 2) {
        *buf |= 0x02000000;
    } else {
        *buf &= 0xFDFFFFFF;
    }

    func_80072140(buf, (u_short)*buf);
}

void DecDCTout(u_long* buf, int size) { func_800721D0(buf, size); }

int DecDCTinSync(int mode)
{
    if (mode != 0) {
        return (func_80072384() >> 0x1D) & 1;
    }
    return func_8007225C();
}

int DecDCToutSync(int mode)
{
    if (mode != 0) {
        return (func_80072384() >> 0x18) & 1;
    }
    return func_800722F0();
}

int DecDCTinCallback(void (*func)()) { return DMACallback(0, func); }

int DecDCToutCallback(void (*func)()) { return DMACallback(1, func); }

static u_int volatile* D_80075C54 = (u_int volatile*)0x1F801080;
static u_int volatile* D_80075C58 = (u_int volatile*)0x1F801084;
static u_int volatile* D_80075C5C = (u_int volatile*)0x1F801088;
static u_int volatile* D_80075C60 = (u_int volatile*)0x1F801090;
static u_int volatile* D_80075C64 = (u_int volatile*)0x1F801094;

static u_int volatile* D_80075C68[] = { (u_int volatile*)0x1F801098,
    (u_int volatile*)0x1F8010A0, (u_int volatile*)0x1F8010A4, (u_int volatile*)0x1F8010A8,
    (u_int volatile*)0x1F8010B0, (u_int volatile*)0x1F8010B4,
    (u_int volatile*)0x1F8010B8 };

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_80072050);
/*extern int* D_80075C5C;
extern int volatile* D_80075C68;
extern int * D_80075C88;

void func_80072050(int arg0) {
    switch (arg0) {
    case 0:
        *D_80075C88 = 0x80000000;
        *D_80075C5C = 0;
        *D_80075C68 = 0;
        *D_80075C88 = 0x60000000;
        func_80072140(D_80075B44, 32);
        func_80072140(D_80075BC8, 32);
        return;
    case 1:
        *D_80075C88 = 0x80000000;
        *D_80075C5C = 0;
        *D_80075C68 = 0;
        *D_80075C68;
        *D_80075C88 = 0x60000000;
        return;
    default:
        printf("MDEC_rest:bad option(%d)\n", arg0);
        return;
    }
}
*/

static u_int volatile* D_80075C84 = (u_int volatile*)0x1F801820;
static u_int volatile* D_80075C88 = (u_int volatile*)0x1F801824;
static u_int volatile* D_80075C8C = (u_int volatile*)0x1F8010F0;

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_80072140);
/*extern int** D_80075C54;
extern int* D_80075C58;
extern int* D_80075C5C;
extern int* D_80075C84;
extern int* D_80075C8C;

void func_80072140(int* arg0, u_int arg1) {
    func_8007225C();
    *D_80075C8C |= 0x88;
    *D_80075C54 = arg0 + 1;
    *D_80075C58 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_80075C84 = *arg0;
    *D_80075C5C = 0x01000201;
}
*/

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_800721D0);
/*extern int* D_80075C60;
extern int* D_80075C64;
extern int* D_80075C68;
extern int* D_80075C8C;

void func_800721D0(int arg0, u_int arg1) {
    func_800722F0();
    *D_80075C8C |= 0x88;
    *D_80075C68 = 0;
    *D_80075C60 = arg0;
    *D_80075C64 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_80075C68 = 0x01000200;
}
*/

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_8007225C);
/*void func_8007239C(signed char const*);
extern int* D_80075C88;

int func_8007225C(void) {
    volatile int sp10;

    sp10 = 0x100000;
    while (*D_80075C88 & 0x20000000) {
        if (--sp10 == -1) {
            func_8007239C("MDEC_in_sync");
            return -1;
        }
    }
    return 0;
}
*/

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_800722F0);
/*void func_8007239C(signed char const*);
extern int* D_80075C68;

int func_800722F0(void) {
    volatile int sp10;

    sp10 = 0x100000;
    while (*D_80075C68 & 0x01000000) {
        if (--sp10 == -1) {
            func_8007239C("MDEC_out_sync");
            return -1;
        }
    }
    return 0;
}
*/

u_int func_80072384() { return *D_80075C88; }

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_8007239C);
/*extern int* D_80075C5C;
extern int volatile* D_80075C68;

int func_8007239C(signed char const* arg0) {
    printf("%s timeout:\n\0", arg0);
    *D_80075C88 = 0x80000000;
    *D_80075C5C = 0;
    *D_80075C68 = 0;
    *D_80075C68;
    *D_80075C88 = 0x60000000;
    return 0;
}
*/