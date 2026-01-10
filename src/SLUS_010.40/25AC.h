#pragma once
#include <sys/types.h>

typedef struct {
    int unk0;
    int unk4;
    char unk8;
    char unk9;
} vs_main_sfxContext;

int vs_sound_shutdown(void);
int vs_sound_init(void);
int func_80011DEC(int* arg0);
int func_80011EBC(u_int);
int func_80011F08(void);
int func_80011F90(void);
u_int func_80011FB4(void*);
void func_80011FDC(u_int);
void func_80012004(void);
int func_80012024(void);
u_int func_80012080(void*, u_int, int);
u_int func_800120E8(void*);
int func_8001217C(void*, int, int, int);
int func_800121F0(void*, int, int, int);
void func_80012288(int, int);
void* func_80012358(int);
int func_800123C8(vs_main_sfxContext*);
void vs_sound_setMonoSound(int);
void func_80012468(void);
void func_8001264C(int, int, int, int);
void func_80012738(int, int, int, int);
void func_80012824(int, int, int, int);
void func_800128A0(u_int, int, int);
void func_80012918(int);
void func_80012940(int, int);
void func_800129D0(int, int);
int func_80012A6C(int, int);
void func_80012B78(void);
void func_80012B98(void);
void func_80012BB8(void*, int);
int vs_sound_spuTransferring(void);
int func_80012EBC(void);
int func_80013188(void*, int);
int func_800131DC(void*, int, int);
int vs_sound_setCdVol(u_int);
void func_800132C4(void*, int, int);
void func_80013328(void);
void func_80013378(int, int);
