#pragma once
#include "common.h"
#include "5BF94.h"

int func_800C4794(SVECTOR*);
VS_HIDDEN(func_800C4794);

int func_800C58F8(u_char*);
VS_HIDDEN(func_800C58F8);

int selectTextBox(u_char);
VS_HIDDEN(selectTextBox);

void loadGim(int, int);
VS_HIDDEN(loadGim);

void func_800C64D0(u_long* arg0, int* arg1);
VS_HIDDEN(func_800C64D0);

void activateGimImage(u_int, void*, u_char*);
VS_HIDDEN(activateGimImage);

void func_800C86AC(void);
VS_HIDDEN(func_800C86AC);

void func_800C97BC(void);
VS_HIDDEN(func_800C97BC);

void func_800CAB40(void);
VS_HIDDEN(func_800CAB40);

void func_800CB23C(void);
VS_HIDDEN(func_800CB23C);

D_800F18EC_t* func_800CB66C(void);
VS_HIDDEN(func_800CB66C);

void func_800CB114(void);
VS_HIDDEN(func_800CB114);

void func_800CB158(vs_LootListNode*);
VS_HIDDEN(func_800CB158);

void func_800CB18C(vs_Loot*);
VS_HIDDEN(func_800CB18C);

void func_800CB1C0(int);
VS_HIDDEN(func_800CB1C0);

void setArtAndAbilityToUnlock(int art, int battleAbility);
VS_HIDDEN(setArtAndAbilityToUnlock);

void displaySceneMessage(int, int, int);
VS_HIDDEN(displaySceneMessage);

int func_800CB45C(void);
VS_HIDDEN(func_800CB45C);

void func_800CB50C(void);
VS_HIDDEN(func_800CB50C);

void func_800CB550(void);
VS_HIDDEN(func_800CB550);

void func_800CB560(void);
VS_HIDDEN(func_800CB560);

void func_800CB79C(void);
VS_HIDDEN(func_800CB79C);

void func_800CB7DC(void);
VS_HIDDEN(func_800CB7DC);

TextOffset func_800CCE10(int arg0, int arg1, int arg2, int arg3);
VS_HIDDEN(func_800CCE10);

int decreaseMiscCount(int);
VS_HIDDEN(decreaseMiscCount);

int func_800CEEBC(void);
VS_HIDDEN(func_800CEEBC);

void func_800CEF38(int arg0);
VS_HIDDEN(func_800CEF38);

int func_800CEF74(int);
VS_HIDDEN(func_800CEF74);

int func_800CF0E8(ActionEffectRequest*, int, int);
VS_HIDDEN(func_800CF0E8);

void func_800CF1A8(void);
VS_HIDDEN(func_800CF1A8);

int func_800CF3F8(ActionEffectRequest*, int);
VS_HIDDEN(func_800CF3F8);

int func_800CF48C(void);
VS_HIDDEN(func_800CF48C);

void func_800CF7A8(int, int, int, int);
VS_HIDDEN(func_800CF7A8);

void func_800CF830(int, int);
VS_HIDDEN(func_800CF830);

void func_800CF8BC(void);
VS_HIDDEN(func_800CF8BC);

void func_800CF920(void);
VS_HIDDEN(func_800CF920);

int validateShortcutSelection(int shortcut);
VS_HIDDEN(validateShortcutSelection);

void func_800C8778(void);
VS_HIDDEN(func_800C8778);

void func_800C9F88(void);
VS_HIDDEN(func_800C9F88);

void func_800CA2DC(void);
VS_HIDDEN(func_800CA2DC);

int func_800CACD0(int menuState, int arg1);
VS_HIDDEN(func_800CACD0);

void func_800CB83C(void);
VS_HIDDEN(func_800CB83C);

int func_800CF060(void);
VS_HIDDEN(func_800CF060);

void func_800D5260(VECTOR* arg0);
VS_HIDDEN(func_800D5260);

void func_800D5294(int* arg0);
VS_HIDDEN(func_800D5294);

extern effectExec effectRenderers[];
VS_HIDDEN(effectRenderers);

extern int D_800F5330[];
VS_HIDDEN(D_800F5330);

extern u_char D_800EB9AC;
VS_HIDDEN(D_800EB9AC);

extern u_char D_800F4CB4;
VS_HIDDEN(D_800F4CB4);

extern ActionEffectRequest D_800F53C0;
VS_HIDDEN(D_800F53C0);
