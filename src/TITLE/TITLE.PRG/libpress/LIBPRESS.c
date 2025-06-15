#include "common.h"
#include <libpress.h>
#include <libetc.h>


void func_80072050(int);
void func_80072140(int* arg0, u_int arg1);

extern int D_80075B44[];
extern int D_80075BC8[];
extern int D_80075B48[];
extern int D_80075B88[];
extern int D_80075BCC[];

void DecDCTReset(int mode) {
    if (mode == 0) {
        ResetCallback();
    }
    func_80072050(mode);
}

DECDCTENV* DecDCTGetEnv(DECDCTENV* env) {
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

DECDCTENV* DecDCTPutEnv(DECDCTENV* arg0) {
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
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTin);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTout);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTinSync);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCToutSync);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCTinCallback);

INCLUDE_ASM(
    "build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", DecDCToutCallback);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_80072050);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_80072140);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_800721D0);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_8007225C);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_800722F0);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_80072384);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/libpress/LIBPRESS", func_8007239C);
