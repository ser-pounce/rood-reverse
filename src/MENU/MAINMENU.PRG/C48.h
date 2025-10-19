#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

typedef struct {
    u_short containerData[0x1C00];
    char unk3800[0x100];
    char unk3900[0x300];
} containerData_t;

typedef struct {
    char unk0[15][256];
    D_800619D8_t unkF00;
    containerData_t unkFB0;
    char unk4BB0[0x7800];
    u_short unkC3B0[0x40];
    containerData_t unkC430;
    signed char unk10030[0x4700];
} D_8010245C_t;

typedef struct {
    char* unk0;
    void* unk4;
} func_800FD0E0_t;

typedef struct {
    short strength;
    short intelligence;
    short agility;
    short unk6;
} vs_mainMenu_strIntAgi_t;

void func_800FA448(void);
void func_800FA8A0(int arg0);
void func_800FA810(int arg0);
void func_800FA8E0(int);
int vs_mainmenu_ready(void);
void func_800FA92C(int arg0, int arg1);
void func_800FAAC8(int);
void func_800FAEBC(int);
void func_800FBB8C(int arg0);
void func_800FBBD4(int);
void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3);
void vs_mainMenu_setStrIntAgi(int, int, int, int);
void func_800FBD80(int);
void func_800FBEA4(int);
void vs_mainMenu_setDpPp(int, int, int, int);
void vs_mainMenu_drawDpPpbars(int);
void vs_mainMenu_setWeaponStrings(vs_battle_weaponInfo*, char**, int*, char*);
void func_800FCAA4(func_8006B57C_t*, func_800FD0E0_t*, int*, char*);
void func_800FCC0C(int*, func_800FD0E0_t*, int*, char*);
void vs_mainMenu_setShieldStrings(void*, char**, int*, char*);
void vs_mainMenu_setArmorStrings(vs_battle_armorInfo*, char**, int*, char*);
void vs_mainMenu_setAccessoryStrings(
    func_8006B7BC_t* arg0, char** arg1, int* arg2, char* arg3);
void func_800FD0E0(func_800FD17C_t* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3);
void vs_mainMenu_resetStats(void);
void func_8010044C(u_int*);

extern char vs_mainMenu_weaponHands[];
extern char (*vs_mainMenu_itemNames)[24];
extern D_8010245C_t* D_8010245C;
extern vs_mainMenu_strIntAgi_t vs_mainMenu_strIntAgi[2];
extern char D_801024B9;
extern short vs_mainMenu_equipmentStats[0x40];
extern short D_80102508;
extern u_short* vs_mainMenu_itemHelp;
extern char D_80102544;
extern char vs_mainMenu_equipmentSubtype;
extern char D_80102578;
