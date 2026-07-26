#pragma once
#include <stddef.h>

typedef struct {
    u_int unk0 : 8;
    u_int unk1 : 8;
    u_int unk2 : 8;
    u_int unk3 : 8;
} func_800C1564_flags;

typedef struct {
    short unk0[4];
} func_800C1564_t2;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    union {
        func_800C1564_flags flags;
        u_char values[4];
    } unk4;
    func_800C1564_t2 unk8;
} func_800C1564_t;

int vs_battle_mapStickDeadZone(int);
int func_800C1564(func_800C1564_t* arg0, u_short* arg1);
void func_800C16DC();
int func_800C4734(void);
