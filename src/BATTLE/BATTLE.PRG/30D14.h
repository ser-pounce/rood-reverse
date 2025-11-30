#pragma once

typedef struct {
    void* unk0;
    void* unk4;
    char unk8[0x78F8];
} func_8009C378_t;

extern void* D_800F4538[];
extern void* D_800F4588[];
extern char D_800F49DC;

void func_8009C378(func_8009C378_t*, func_8009C378_t*);
void func_8009D934(int, int, int);
void func_800A0204(int, int, int, int);
void func_800A0768(int, char*);
void func_800A087C(int, int);
int func_800A0BE0(int actor);
void func_800A1108(int, char*);
void func_800A13EC(int, char, int*, int);
