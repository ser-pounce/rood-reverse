#pragma once
#include <libgte.h>

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} func_8006EBF8_t_fields;

typedef struct {
    union {
        func_8006EBF8_t_fields fields;
        int value;
    } unk0;
    SVECTOR unk4;
} func_8006EBF8_t3;

typedef struct {
    func_8006EBF8_t3 unk0;
    int unkC;
} func_8006EBF8_t;
