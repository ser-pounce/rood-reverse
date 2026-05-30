#pragma once
#include "3A1A0.h"
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

extern D_800F4590_t* D_800F4590[];
extern int D_800F4594;
extern char D_800F49DC;

u_char func_80099514(u_int, int, int);
int func_80099D6C(int);
void func_8009AA84(int);
void func_8009C378(func_8009C378_t*, func_8009C378_t*);
int func_8009D208(int);
void func_8009D7E8(int, int);
void func_8009D88C(int);
void func_8009D934(int, int, int);
void func_8009DBDC(int, int);
void func_8009DC38(int);
void func_8009DC8C(int);
void func_8009DD00(int, SVECTOR*, int);
void func_8009E2E0(char, SVECTOR*, int);
void func_8009E634(D_800F4538_t*);
void func_8009EC9C(char, SVECTOR*, int, int);
void func_8009EE9C(int, SVECTOR*, int);
void func_8009EFEC(int, SVECTOR*, int);
void func_8009F298(int, SVECTOR*, int);
void func_8009F530(int);
int func_8009F8DC(int);
void func_8009F940(int, int, D_800F4538_unk58_2*, D_800F4538_unk58_2*);
void func_8009F990(int, u_char*);
void func_8009FB64(VECTOR*);
int func_8009FBD8(int, int);
int func_8009FC60(int, int, SVECTOR*, int);
int func_8009FE74(int arg0, int arg1);
void func_8009FF08(int, int, int, int);
int func_8009FFA8(int arg0, int arg1);
int func_800A01C8(int, int, int, int);
int func_800A0204(int, int, int, int);
int func_800A0618(int, int, int, int);
int func_800A0768(int, D_800F4538_unk58_2*);
int func_800A07FC(int, D_800F4538_unk58_2*);
void func_800A0870(int);
void func_800A087C(int actorId, int);
void func_800A09D8(int, int);
int func_800A0A74(int);
void func_800A0AFC(int, int, int);
u_int func_800A0BE0(int actorId);
int func_800A1178(int arg0, int arg1, MATRIX* arg2, u_long* arg3);
void func_800A1280(int, int, SVECTOR*, int);
int func_800A13EC(int, int, int*, int);
