#pragma once
#include "6E644.h"
#include "battleUi.h"
#include "func_8006B57C_t.h"
#include "menuState.h"
#include <sys/types.h>
#include <libgte.h>

int func_800C4794(SVECTOR*);
int func_800C58F8(u_char*);
int vs_battle_selectTextBox(u_char);
void vs_battle_loadGim(int, int);
void func_800C64D0(u_long* arg0, int* arg1);
void func_800C8550(u_int, void*, u_char*);
void func_800C86AC(void);
void func_800C97BC(void);
void vs_battle_initUi(void*);
void func_800CAB40(void);
void func_800CB23C(void);
void func_800CB660(int arg0);
D_800F18EC_t* func_800CB66C(void);
void func_800CB114(void);
void func_800CB158(vs_battle_lootListNode*);
void func_800CB18C(vs_battle_loot*);
void func_800CB1C0(int);
void _setArtAndAbilityToUnlock(int art, int battleAbility);
void vs_battle_displaySceneMessage(int, int, int);
int func_800CB45C(void);
void func_800CB50C(void);
void func_800CB550(void);
void func_800CB560(void);
void func_800CB79C(void);
void func_800CB7DC(void);
textOffset func_800CCE10(int arg0, int arg1, int arg2, int arg3);
int vs_battle_decreaseMiscCount(int);
void func_800CE64C(void);
int func_800CEEBC(void);
void func_800CEF38(int arg0);
int func_800CEF74(int);
int func_800CF0E8(actionEffectRequest*, int, int);
void func_800CF1A8(void);
int func_800CF3F8(actionEffectRequest*, int);
int func_800CF48C(void);
void func_800CF7A8(int, int, int, int);
void func_800CF830(int, int);
void func_800CF8BC(void);
void func_800CF920(void);
int vs_battle_validateShortcutSelection(int shortcut);
void func_800C8778(void);
void func_800C9F88(void);
void func_800CA2DC(void);
int func_800CACD0(int menuState, int arg1);
void func_800CB83C(void);
int func_800CF060(void);
void func_800D2698(int);
void func_800D5260(VECTOR* arg0);
void func_800D5294(int* arg0);
extern effectExec vs_battle_effectRenderers[];
