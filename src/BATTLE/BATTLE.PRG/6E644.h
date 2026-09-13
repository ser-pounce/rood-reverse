#pragma once
#include "146C.h"

typedef struct {
    u_short lba;
    u_short size;
} _loadFileContext;

typedef struct {
    u_char unk0[0x8C];
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
} D_800F56C8_t;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
    u_short unk4;
    short unk6;
    union {
        char u8[2];
        short s16;
    } unk8;
    union {
        char u8[2];
        short s16;
    } unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    union {
        char u8[2];
        u_short u16;
    } unk14;
    union {
        char u8[2];
        u_short u16;
    } unk16;
    short unk18;
    short unk1A;
    int unk1C[45];
    char unkD0[16];
    short unkE0;
    short unkE2;
    short unkE4;
} func_800CF0E8_t;

typedef struct func_800D4910_t {
    struct func_800D4910_t* next;
    int (*unk4)(struct func_800D4910_t*, int, int);
    void* unk8;
} func_800D4910_t;

void func_800D2698(int);
void func_800D8038(int);
void func_800D6E44(void);
void func_800D7814(void);
void func_800D78F0(void);
void func_800D7FC8(int, int, int);
void func_800D7FE4(int (*arg0)(func_800D4910_t*, int, int), int arg1);
void func_800D7FFC(int arg0);
void func_800D8054(int);
void func_800D8008(int, int, int, int, int);
void func_800DC638(void);
int func_800DEC88(void*);
void func_800E527C(int, int, int);
void func_800E4C28(int, int, int, int);
int func_800E5154(void);
void func_800E5998(void);
void func_800E6158(void);
void func_800E6178(vs_battle_actor*, int);
short func_800E6694(int);
void func_800E6700(int);
void func_800E68EC(int, int);
void func_800E6EAC(void);
void func_800E6F1C(void);
void func_800E7454(vs_battle_actor*);
void func_800E7608(int);
u_short func_800E45B4(void);
void func_800E511C(void);
void func_800E5308(void);
int vs_battle_getMainMenuLba(void);
int vs_battle_loadEffPurge(void);

extern int D_800F5684;
extern void* _effBuf;
extern _loadFileContext _loadEffContext;
extern func_800CF0E8_t D_800F5230;
extern D_800F56C8_t D_800F56C8;
extern u_char D_800FAE4C[];
extern u_char D_800FAFDC[];
extern _loadFileContext D_800FB16C[];
extern u_char D_800FB7AC[];
extern u_char D_800FB93C[];
extern _loadFileContext D_800FBC30[];
extern _loadFileContext D_800FC7FC[];
extern u_short D_800FCE3C[];
extern int (*D_800FD15C[])(func_800D4910_t*, int, int);
extern _loadFileContext D_800FD6B8[];
