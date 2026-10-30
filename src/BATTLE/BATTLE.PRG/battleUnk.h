#pragma once
#include "entity.h"
#include <sys/types.h>
#include <libgte.h>

void func_8007ACB0(void);
int func_8007C36C(int arg0);
void func_8007DD50(int);
void func_8007DDAC(int arg0);
void func_8007DDB8(VECTOR* arg0);
void func_8007DDD4(CVECTOR* arg0);
void func_8007DDF8(VECTOR* arg0);
void func_8007DE2C(int arg0);
void func_8007DE44(u_int arg0);
void func_8007DE5C(int arg0);
int func_8007DFF0(u_int, u_int, int);
int func_8007E0A8(u_int, u_int, int);

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
void func_8009C378(func_8009C378_t*, func_8009C378_t*);

void func_800B28A8(D_800F4538_t*, MATRIX*, int);
