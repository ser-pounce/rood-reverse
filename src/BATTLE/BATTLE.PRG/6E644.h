#pragma once
#include "146C.h"

typedef struct {
    u_short lba;
    u_short size;
} _loadFileContext;

typedef struct {
    u_short type;
    u_short unk2;
    union {
        struct {
            u_int actor : 8;
            u_int unk1 : 8;
            u_int part : 8;
            u_int unk3 : 8;
        } actor;
        SVECTOR position;
    } value;
} actionEffectTarget;

typedef struct {
    u_short effectId;
    u_char count;
    u_char otherCount;
    actionEffectTarget source;
    actionEffectTarget targets[16];
    u_char others[16];
    SVECTOR position;
} actionEffectRequest;

typedef struct func_800D4910_t func_800D4910_t;

typedef int (*effectExec)(func_800D4910_t*, u_int, int);

struct func_800D4910_t {
    struct func_800D4910_t* next;
    effectExec renderer;
    void* unk8;
};

typedef struct {
    int meta;
    u_char data[0];
} p_file_t;

void func_800D2698(int);
void func_800D7890(int arg0);
void func_800D78B8(void);
void func_800D78CC(void);
int func_800D7BF8(void);
void func_800D7C5C(void);
int func_800D7CFC(void);
int func_800D7EF4(void);
void func_800D8038(int);
void func_800D8060(p_file_t* arg0);
void func_800DEEA4(D_800F19CC_t2* arg0);
void func_800D6E44(void*);
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
void func_800E4C1C(int, int);
void func_800E4C28(int, int);
int func_800E5154(void);
void func_800E5998(void);
void func_800E6158(void);
int func_800E6178(vs_battle_actor*, short);
short func_800E6694(int);
void func_800E6700(int);
void func_800E68EC(int, int);
void func_800E6B24(int);
int func_800E6C34(SVECTOR*, SVECTOR*, SVECTOR*, int);
void func_800E6EAC(void);
void func_800E6F1C(void);
void func_800E7454(vs_battle_actor*);
void func_800E7608(int);
u_short func_800E45B4(void);
void func_800E511C(void);
void func_800E5308(void);
int vs_battle_getMainMenuLba(void);
int vs_battle_loadEffPurge(void);

extern actionEffectRequest D_800F5230;
extern actionEffectRequest D_800F53C0;
extern int D_800F5684;
extern void* vs_battle_pfileBuf;
extern _loadFileContext vs_battle_pFileLoadContext;
