#pragma once
#include "mpd.h"
#include "entity.h"
#include "func_8006EBF8_t.h"
#include <stddef.h>
#include <libgte.h>
#include <libgpu.h>

_mpdRoomSection3* func_800A8D64(SVECTOR* arg0, int arg1);
int func_800A8E84(D_800F4538_t* actor, SVECTOR* position);
int func_800A91DC(int arg0, int arg1, int arg2);
inline int func_800A92B8(int arg0, int arg1);
void func_800A97EC(int, vs_battle_movementPosition*, int, int);
void func_800A9988(int, SVECTOR*, int, int);
void func_800A9C54(int, vs_battle_movementPosition*, int);
void func_800A9CDC(int, vs_battle_movementPosition*, int);
void func_800A9D24(int, SVECTOR*, int);
void func_800A9D90(int, SVECTOR*, int);
void func_800A9E38(int, short, int);
void func_800A9EB4(int, short, int);
void func_800A9F64(int, SVECTOR*, int);
void func_800A9FD0(int, SVECTOR*, int);
void func_800AA850(int, short, int);
void func_800AABD0(int, SVECTOR*, int);
void func_800AACDC(void);
int func_800AAD4C(int, int, int, int);
int func_800AAE9C(D_800F4538_t* actor);
void func_800AB098(D_800F4538_t* actor, int index, int frame);
void func_800AB2AC(int arg0);
void func_800AB358(int index, u_char* script);
void func_800AB4F0(D_800F4538_t*);
void func_800AB788(D_800F4538_t* actor, D_800F45E0_t* object, int arg2);
void func_800AC37C(int, int);
void func_800AC440(D_800F4538_t* arg0, int arg1, int arg2);
void func_800AC500(D_800F4538_t* arg0);
void func_800AC540(int arg0, D_800F4538_t* arg1);
void func_800AC690(int, D_800F4538_t*);
void func_800AD008(D_800F4538_t*, D_800F4538_unkC54*);
void* func_800AD494(void*, int, u_short**);
void func_800AD62C(int actorId, int* pan, int* volume, int arg3 __attribute__((unused)));
