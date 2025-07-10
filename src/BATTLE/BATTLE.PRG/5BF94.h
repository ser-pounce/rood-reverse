#pragma once
#include "../SLUS_010.40/main.h"

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short unk4;
    signed char unk6;
    signed char unk7;
    int unk8;
    char unkC;
    char unkD;
    short unkE;
    int unk10;
    short unk14;
    short unk16;
    short unk18;
    short unk1A;
    char unk1C[36];
} func_800C8E5C_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_main_CdQueueSlot* unk4;
} D_800F51C0_t;

void func_800C6828(char const*, int, u_int*);
void func_800C8E04(int);
func_800C8E5C_t* func_800C8E48(int);
func_800C8E5C_t* func_800C8E5C(int, int, int, int, int, u_short*);
void func_800C9078(func_800C8E5C_t*);
int func_800C930C(int);
void func_800C97BC();
int func_800CABE0(int);
short* func_800CB66C();
void func_800CB114();
int func_800CB45C();
void func_800CB50C();
void func_800CB654(int);
void vs_battle_rMemzero(void* arg0, int arg1);
void vs_battle_rMemcpy(char* dest, char const* src, int size);
int func_800CCC54(int);
char func_800CCD40(char, int);
u_int vs_battle_encode(int value);
int func_800CD064(int);
void func_800CCDA8(int, void*, int);
int func_800CEEBC();
void func_800CEF74();
void func_800CF48C();
void func_800CF7A8(int, int, int, int);
void func_800CF830();
void func_800CF920();

extern u_short D_800EB9DC[];
extern int D_800EB9B0;
extern func_800C8E5C_t* D_800EB9C0;
extern char D_800F4E6A;
extern char D_800F4E6B;
extern void* D_800F4E84;
extern void* D_800F4E8C;
extern short D_800F4E98[4];
extern int D_800F4EA0;
extern char D_800F4F70;
extern char D_800F4FDB;
extern short D_800F514C;
extern D_800F51C0_t D_800F51C0;