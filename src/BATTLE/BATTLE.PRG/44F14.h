#pragma once
#include "entity.h"

typedef struct {
    MATRIX bones[63];
    VECTOR scale;
} D_800F3C58_t;

extern D_800F3C58_t D_800F3C58;

int func_800AD714(D_800F4538_t* actor, D_800F4538_unkC54* state, int mode);
void func_800AE47C(D_800F4538_t*);
void func_800AE4FC(D_800F4538_t*, int);
void func_800AE68C(int arg0, int arg1);
void func_800AE6C0(D_800F4538_t*, int, int);
void func_800AE7D8(void* arg0, int arg1, int arg2);
void func_800AEAE8(D_800F4538_t*);
void func_800AECA0(MATRIX*);
void func_800AF6E8(D_800F4538_t*);
void func_800AFA28(D_800F4538_t*, D_800F4538_unkC54*, int);
void func_800B002C(D_800F4538_t*, int);
void func_800B07DC(D_800F4538_t*);
void func_800B0908(D_800F45E0_t* object, int arg1 __attribute__((unused)));
int func_800B13CC(int arg0, int arg1, int arg2);
void func_800B217C(vs_battle_wepModels_t*, MATRIX*);
void func_800AEF94(MATRIX*);
