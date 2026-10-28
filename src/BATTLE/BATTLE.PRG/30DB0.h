#pragma once
#include "2842C.h"
#include "entity.h"
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
    u_char unk0[0x1FD0];
    int unk1FD0[3];
    int unk1FDC;
    u_short unk1FE0;
} D_800F2458_t;

typedef struct {
    u_char unk0[0x34];
    u_short tpage;
    u_short clut;
    u_short unk38;
    u_short unk3A;
    u_short unk3C;
    u_char unk3E[0xE];
    SVECTOR position;
    SVECTOR offset;
    MATRIX* parent;
    int unk60;
    MATRIX matrix;
    SVECTOR rotation;
    VECTOR scale;
    D_800F4538_unk68* model;
} D_1F80035C_t;

typedef struct {
    short tpage;
    short clut0;
    short clut1;
    u_char refCount;
} vs_battle_texInfo_t;

extern D_800F2458_t D_800F2458;
extern D_800F4590_t* D_800F4590[];
extern int D_800F4594;
extern _wepModelOffsets* vs_battle_commonWepBuffs[];
extern vs_battle_texInfo_t D_800F46A8[];
extern vs_battle_texInfo_t vs_battle_wepTextures[20];
extern char D_800F49DC;

u_char func_80099514(u_int, int, int);
void func_80099960(void* arg0);
int func_80099D6C(int);
int func_8009AA84(int);
void func_8009C378(func_8009C378_t*, func_8009C378_t*);
int func_8009CC20(int, int);
int func_8009CE9C(u_int arg0);
int func_8009CFA0(void);
int func_8009CFB0(int);
int func_8009D208(int);
void func_8009D458(void);
void func_8009D468(int);
void func_8009D6F4(void);
void func_8009D7E8(int, int);
void func_8009D854(int);
void func_8009D88C(int);
void func_8009D934(int, int, int);
void func_8009DBDC(int, int);
void func_8009DC38(int);
void func_8009DC8C(int);
void func_8009DD00(int, SVECTOR*, int);
void func_8009DF3C(int arg0, int arg1);
void func_8009E070(int arg0, SVECTOR* arg1, int arg2);
int func_8009E180(D_800F4538_t* arg0, SVECTOR* arg1);
void func_8009E2E0(int, SVECTOR*, int);
int func_8009E480(void);
int func_8009E4B0(int arg0);
void func_8009E5C4(int);
void func_8009E634(D_800F4538_t*);
void func_8009EA14(int arg0, SVECTOR* arg1);
void func_8009EC9C(int, SVECTOR*, int, int);
void func_8009EE9C(int, SVECTOR*, int);
void func_8009EFEC(int, SVECTOR*, int);
void func_8009F298(int, SVECTOR*, int);
void func_8009F314(int, void*, int);
void func_8009F530(int);
int func_8009F858(int);
void func_8009F898(int arg0, int arg1, int arg2);
int func_8009F8DC(int);
void func_8009F940(int, int, D_800F4538_unk58_2*, D_800F4538_unk58_2*);
void func_8009F990(int, D_800F4538_unk64*);
void func_8009FB64(VECTOR*);
int func_8009FBD8(int, int);
int func_8009FC60(int, int, SVECTOR*, int);
int func_8009FD5C(int, int, int);
int func_8009FE74(int arg0, int arg1);
void func_8009FF08(int, int, int, int);
int func_8009FFA8(int arg0, int arg1);
int func_800A0024(int arg0, func_8006EBF8_t3* arg1);
int func_800A0104(int index, int material);
int func_800A01C8(int, int, int, int);
int func_800A0204(int, int, int, int);
int func_800A0618(int, int, int, int);
int func_800A0768(int, D_800F4538_unk58_2*);
int func_800A07FC(int, D_800F4538_unk58_2*);
void func_800A0870(int);
void func_800A087C(int actorId, int);
void func_800A09D8(int, int);
void func_800A0A1C(int, int);
int func_800A0A74(int);
void func_800A0ABC(int);
void func_800A0AFC(int, int, int);
u_int func_800A0BE0(int actorId);
int func_800A1108(int, void*);
int func_800A1178(int arg0, int arg1, MATRIX* arg2, u_long* arg3);
int func_800A1280(int, int, SVECTOR*, int);
int func_800A13EC(int, int, int*, int);
void func_8009E614(int arg0);
int vs_battle_getEmptyObjectDataSlot(void);
int vs_battle_populateDataSlot(vs_battle_objectData*);
int vs_battle_processObjectDataQueue(void);
