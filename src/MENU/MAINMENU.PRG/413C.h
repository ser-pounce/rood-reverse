#pragma once

int vs_mainMenu_loadItemNames(int);
int func_800FE694(void);
void func_800FFA88(int);
void func_800FFA94(void);
void func_800FFB68(int);
void func_800FFB90(int);
void func_800FFBA8(void);
void func_800FFBC8(void);
void vs_mainmenu_drawButton(int index, int x, int y, u_long* data);
int func_800FFCDC(int, int);
void vs_mainmenu_setMessage(char*);
void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int);
void func_80100164(void);
void func_80100344(int, int, int, int);
void func_80100414(int, int);
void vs_mainmenu_setMenuRows(int rowCount, int, char* strings[], int rowtypes[]);
void func_80100814(void);
int func_801008B0(void);
int vs_mainmenu_getSelectedRow(void);
void func_80100A5C(void);
void func_80101118(int);
void func_801013F8(int);

extern char vs_mainMenu_isLevelledSpell;
extern char vs_mainMenu_equipmentDetailNavigationMap[][4];
extern int D_801021A0[];
extern int D_801021C4;
extern char D_801022D5;
extern char D_801023E3;
