#pragma once

typedef struct {
    u_int unk0_0 : 8;
    u_int unk0_8 : 8;
    u_int unk0_16 : 8;
    u_int unk0_24 : 8;
} func_8007C8F8_t_flags;

typedef struct {
    char unk0;
    char unk1;
    short wepId;
    void* unk4;
    int unk8;
    func_8007C8F8_t_flags unkC;
    char actorId;
    char unk11;
    char material;
    char unk13;
} func_8007C8F8_t;

int vs_battle_clamp(short arg0, int arg1, int arg2);
void func_80091314(int);
void func_80091320(int);
void func_8009134C(int, int);
int func_800913BC(int);
void func_80091468(int, int);
void func_800918E8(int);
int func_80091998(int);
int func_800919D8(int);
int func_80091A1C(int, int);
int func_80091A78(int, int);
void func_80092548(void);
void func_8009291C(int);
int func_800936F8(int);
int func_80093764(int);
void func_80093788(int);
void func_800938AC(int);
void func_80093A70(void);
void func_80093AB4(void);
void func_80095B70(int);
void func_8009722C(void);
void func_80098160(int);
void func_80098194(int);
int func_800995B0(void);
void func_80098B38(int, int);
int func_800995E8(func_8007C8F8_t*);
int func_8009967C(void);
void func_8009CC20(int, int);
void func_8009CE9C(int);
int func_8009CFA0(void);
void func_8009CFB0(int);
void func_8009D208(int);
void func_8009D468(int, int);
void func_8009D854(int);
void func_8009E5C4(int);
void func_8009E634(void*, int);
void func_8009F314(int, void*, int);
void func_8009F940(int, int, int*, char*);
void func_8009FD5C(int);
void func_8009FE74(int);
void func_800A0768(int, char*);
void func_800A07FC(int, void*);
void func_800A0A1C(int, int);
