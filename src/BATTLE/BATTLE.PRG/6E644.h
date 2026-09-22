#pragma once
#include "146C.h"

typedef struct {
    u_short lba;
    u_short size;
} _loadFileContext;

typedef struct {
    u_short effectId;
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
    SVECTOR unkE0;
} func_800CF0E8_t;

typedef struct func_800D4910_t func_800D4910_t;

typedef int (*effectExec)(func_800D4910_t*, u_int, int);

struct func_800D4910_t {
    struct func_800D4910_t* next;
    effectExec renderer;
    void* unk8;
};

void func_800D2698(int);
void func_800D8038(int);
void func_800D6E44(void);
void func_800D7814(void);
void func_800D78F0(void);
void vs_battle_configurePlg(int, int, int);
void vs_battle_setEffectExec(effectExec arg0, int arg1);
void func_800D7FFC(int arg0);
void vs_battle_setPlgLoadState(int);
void vs_battle_configureEffectFbLoad(
    int lba, int size, int suffix, int isClut, int index);
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
extern void* vs_battle_pfileBuf;
extern _loadFileContext vs_battle_pFileLoadContext;
extern func_800CF0E8_t D_800F5230;
