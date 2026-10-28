#pragma once
#include <sys/types.h>
#include <libgte.h>
#include "entity.h"

typedef struct {
    u_short unk0_0 : 10;
    u_short unk0_10 : 6;
} D_800F18E8_t;

void func_80069FC4(int, int);
void func_8008B430(D_800F4538_unk58_2*, int);
int* func_8008EB24(void);
void func_8008EB30(int*);
void vs_battle_exec(void);
extern D_800F18E8_t D_800F18E8;
