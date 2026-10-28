#pragma once
#include <stddef.h>
#include <libgte.h>

typedef struct {
    u_int unk0 : 8;
    u_int unk1 : 8;
    u_int unk2 : 8;
    u_int unk3 : 8;
} func_800C1564_flags;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    union {
        func_800C1564_flags flags;
        u_char values[4];
    } unk4;
    union {
        SVECTOR vec;
        short xyz[4];
    } unk8;
} func_800C1564_t;

typedef struct {
    SVECTOR unk0;
    u_char unk8;
    u_char unk9;
    signed char unkA;
    char effect;
    short unkC;
    short unkE;
    int unk10;
    char unk14;
    char unk15;
    char unk16;
    char enemyClass;
} D_800F19CC_t5;

typedef struct {
    short xyz[3];
    short flags;
} menuShapeVertex;

short func_800BFBB8(u_char**, short);
void func_800BFD9C(void);
int func_800BFE50(u_short);
int func_800BFEBC(short mode, short frame, short duration);
void func_800C00E8(int, void*);

void func_800C031C(void);
int func_800C0758(int phase, int segments, int index);
MATRIX* func_800C085C(u_char* scale, int angle);
void func_800C05B4(void);
void func_800C06E0(void);
void func_800C05EC(
    func_800C1564_t* arg0, func_800C1564_t* arg1, int arg2, D_800F19CC_t5* arg3);
void func_800C0700(func_800C1564_t* arg0);
void func_800C0738(void);

short vs_battle_getShort(u_char* arg0);
extern short _evtFile;
extern int (**D_800F4C28)(u_char*, short);
