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

extern int D_80075B44[];
extern int D_80075B48[];
extern int D_80075B88[];
extern int D_80075BC8[];
extern int D_80075BCC[];
extern u_int volatile* D_80075C88;

// Commented out functions only match with GCC 2.8.0, but this breaks the others.

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTReset);
/*void DecDCTReset(int mode) {
    if (mode == 0) {
        ResetCallback();
    }
    func_80072050(mode);
}*/

DECDCTENV* DecDCTGetEnv(DECDCTENV* env)
{
    int* var_a2;
    int i;
    int* var_a1;

    var_a2 = (int*)env->iq_y;
    var_a1 = D_80075B48;
    for (i = 15; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    var_a2 = (int*)env->iq_c;
    var_a1 = D_80075B88;
    for (i = 15; i != -1; --i) {
        *var_a2++ = *var_a1++;
    }
    var_a2 = (int*)env->dct;
    var_a1 = D_80075BCC;
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
/*void func_8007239C(char const*);
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
/*void func_8007239C(char const*);
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

int func_8007239C(char const* arg0) {
    printf("%s timeout:\n\0", arg0);
    *D_80075C88 = 0x80000000;
    *D_80075C5C = 0;
    *D_80075C68 = 0;
    *D_80075C68;
    *D_80075C88 = 0x60000000;
    return 0;
}
*/