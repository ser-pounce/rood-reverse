#pragma once
#include "loot.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    u_short currentManual;
    u_short unk2;
    u_short scrollPositions[14];
    u_short unk20;
    char unk22;
    char unk23;
} vs_battle_manualDisplayState_t;

typedef struct {
    u_char titlePage;
    u_char titleRow;
    u_char encyclopaediaPage;
    u_char encyclopaediaRow;
    u_char recordTimePage;
    u_char recordTimeRow;
    u_char gazettePage;
    u_char gazetteRow;
} vs_battle_menu9CursorMemory_t;

typedef struct vs_battle_lootListNode {
    struct vs_battle_lootListNode* next;
    int actorId;
    vs_battle_loot loot;
} vs_battle_lootListNode;

void func_8008A4DC(int arg0);
int func_8008A4FC(void);
void func_8008A6FC(void);
void vs_battle_parseTim(u_long*, TIM_IMAGE*);
extern vs_battle_lootListNode* _lootListHead;
extern vs_battle_manualDisplayState_t vs_battle_manualDisplayState;
extern vs_battle_menu9CursorMemory_t vs_battle_menu9CursorMemory;
extern int vs_battle_submenuState;
