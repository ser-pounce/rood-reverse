#pragma once
#include <libgte.h>

typedef struct {
    u_int x : 8;
    u_int y : 8;
    u_int z : 8;
    u_int status : 8;
} vs_battle_movementPosition;

typedef struct {
    union {
        vs_battle_movementPosition fields;
        int value;
    } unk0;
    SVECTOR unk4;
} func_8006EBF8_t3;

typedef struct {
    func_8006EBF8_t3 unk0;
    int unkC;
} func_8006EBF8_t;
