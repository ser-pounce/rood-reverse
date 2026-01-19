#pragma once
#include <stddef.h>
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

typedef struct {
    u_short weapons[32];
    u_short blades[64];
    u_short grips[64];
    u_short shields[32];
    u_short armor[64];
    u_short gems[192];
    u_short items[256];
} vs_menu_containerIndices;

typedef struct {
    char unk0[15][256];
    D_800619D8_t unkF00;
    vs_menu_containerData unkFB0;
    vs_menu_containerData unk4BB0;
    vs_menu_containerData unk87B0;
    u_short unkC3B0[0x40];
    vs_menu_containerData unkC430;
    vs_menu_containerIndices indices;
    int unk105B0[0x1060];
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
void func_800FA854(int arg0);
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
void vs_mainMenu_setWeaponStrings(vs_battle_equippedWeapon*, char**, int*, char*);
void func_800FC510(int, int, int);
void func_800FCA08(vs_battle_inventoryWeapon* arg0, char** arg1, int* arg2, char* arg3);
void func_800FCAA4(vs_battle_inventoryBlade*, func_800FD0E0_t*, int*, char*);
void func_800FCC0C(vs_battle_inventoryGrip*, func_800FD0E0_t*, int*, char*);
void func_800FCE40(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3);
void vs_mainMenu_setShieldStrings(vs_battle_equippedShield*, char**, int*, char*);
void vs_mainMenu_setArmorStrings(vs_battle_equippedArmor*, char**, int*, char*);
void vs_mainMenu_setAccessoryStrings(
    vs_battle_inventoryArmor* arg0, char** arg1, int* arg2, char* arg3);
void func_800FD0E0(
    vs_battle_inventoryGem* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3);
void func_800FD17C(
    vs_battle_inventoryGem* arg0, func_800FD0E0_t* arg1, int* arg2, void* arg3);
void func_800FD270(int);
void func_800FD404(int);
void func_800FD700(int);
void func_800FD878(int);
void vs_mainMenu_resetStats(void);
void func_8010044C(u_int*);

extern char vs_mainMenu_weaponHands[];
extern char (*vs_mainMenu_itemNames)[24];
extern char D_801022A0[];
extern char* D_801022A8[];
extern char D_801023D0;
extern D_8010245C_t* D_8010245C;
extern vs_mainMenu_strIntAgi_t vs_mainMenu_strIntAgi[2];
extern char D_801024B9;
extern short vs_mainMenu_equipmentStats[0x40];
extern short D_80102508;
extern u_short* vs_mainMenu_itemHelp;
extern char D_80102544;
extern char vs_mainMenu_equipmentSubtype;
extern char D_80102578;
