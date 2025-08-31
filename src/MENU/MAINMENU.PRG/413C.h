#pragma once

void func_800FFA88(int);
void func_800FFA94();
void func_800FFB68(int);
void func_800FFB90(int);
void func_800FFBA8();
void func_800FFBC8();
void func_800FFC68(int, int, int, u_long*);
void vs_mainmenu_setMessage(char*);
void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int);
void func_80100164();
void func_80100414(int, int);
void vs_mainmenu_setMenuRows(int rowCount, int, char* strings[], int rowtypes[]);
int func_801008B0();
int vs_mainmenu_getSelectedRow();
void func_80100A5C();
void func_80101118(int);

extern char vs_mainMenu_isLevelledSpell;
