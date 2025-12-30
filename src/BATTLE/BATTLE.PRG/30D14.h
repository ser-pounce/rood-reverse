#pragma once
#include <libgte.h>

typedef struct {
    void* unk0;
    void* unk4;
    char unk8[0x78F8];
} func_8009C378_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char unk10;
    char unk11;
} D_800F4590_t;

typedef struct {
    int unk0;
    int unk4;
    u_short unk8_0 : 1;
    u_short unk8_1 : 15;
} D_800F4578_t;

extern void* D_800F4538[];
extern D_800F4578_t* D_800F4578;
extern void* D_800F4588[];
extern D_800F4590_t* D_800F4590[];
extern int D_800F4594;
extern char D_800F49DC;

char func_80099514(u_int, int, int);
void func_80099D6C(int);
void func_8009AA84(int);
void func_8009C378(func_8009C378_t*, func_8009C378_t*);
void func_8009D934(int, int, int);
void func_8009DC38(int);
void func_8009DD00(char, SVECTOR*, int);
void func_8009E2E0(char, SVECTOR*, int);
void func_8009EC9C(char, SVECTOR*, int, int);
void func_8009EE9C(char, SVECTOR*, int);
void func_8009EFEC(char, SVECTOR*, int);
void func_8009F298(char, SVECTOR*, int);
int func_8009F8DC(int);
void func_8009F530(int);
void func_800A0204(int, int, int, int);
void func_800A0768(int, char*);
void func_800A0870(int);
void func_800A087C(int, int);
void func_800A09D8(int, int);
int func_800A0A74(int);
void func_800A0AFC(int, int, int);
u_int func_800A0BE0(int actor);
void func_800A13EC(int, char, int*, int);
