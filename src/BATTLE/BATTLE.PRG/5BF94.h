#pragma once
#include "../SLUS_010.40/main.h"

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    signed char selected;
    signed char unk7;
    int unk8;
    char unkC;
    char unkD;
    short unkE;
    int unk10;
    short animSpeed;
    short y;
    short x;
    short unk1A;
    char text[36];
} vs_battle_menuItem_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_main_CdQueueSlot* unk4;
} D_800F51C0_t;

typedef struct {
    int unk0;
    char unk4[0x2C];
} D_800F4FE0_t;

void func_800C6828(char const*, int, u_int*);
void func_800C6BF0(int, void*, void*);
void func_800C8E04(int);
vs_battle_menuItem_t* vs_battle_getMenuItem(int id);
vs_battle_menuItem_t* vs_battle_setMenuItem(
    int id, int animSpeed, int y, int arg3, int arg4, char* text);
void func_800C9078(vs_battle_menuItem_t*);
int func_800C930C(int);
void func_800C97BC();
int func_800CABE0(int);
short* func_800CB66C();
void func_800CB114();
int func_800CB45C();
void func_800CB50C();
void func_800CB654(int);
void vs_battle_rMemzero(void* arg0, int arg1);
void vs_battle_rMemcpy(void* dest, void const* src, int size);
int vs_battle_toBCD(int);
char vs_battle_drawCursor(char animStep, int position);
u_int vs_battle_encode(int value);
int func_800CD064(int);
void vs_battle_drawImage(int xy, void* buffer, int wh);
int func_800CEEBC();
void func_800CEF74();
int func_800CF48C();
void func_800CF7A8(int, int, int, int);
void func_800CF830(int, int);
void func_800CF920();

extern u_short D_800EB9DC[];
extern int D_800EB9B0;
extern vs_battle_menuItem_t* vs_battle_menuItems;
extern char D_800EBBC8[];
extern char D_800F4E6A;
extern char D_800F4E6B;
extern void* D_800F4E84;
extern void* D_800F4E8C;
extern short D_800F4E98[4];
extern int D_800F4EA0;
extern char D_800F4F70;
extern char D_800F4FDB;
extern D_800F4FE0_t D_800F4FE0[];
extern short D_800F514C;
extern D_800F51C0_t D_800F51C0;