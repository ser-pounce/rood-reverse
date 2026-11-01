#pragma once
#include "entity.h"

typedef struct {
    MATRIX bones[63];
    VECTOR scale;
} D_800F3C58_t;

void func_800B1A68(D_800F45E0_t*, MATRIX*);
void func_800B217C(vs_battle_wepModels_t*, MATRIX*);

extern D_800F3C58_t D_800F3C58;
