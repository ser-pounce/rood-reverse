#pragma once
#include "entity.h"
#include <libgte.h>

enum ActorPoint {
    actorPointRaised = 0xFA, // position raised by scaled unk65A, near the root bone
    actorPointAboveHead = 0xFB, // position raised by the actor's height
    actorPointPosition = 0xFD, // the actor's position
};

int getBoneScreenPosition(int actorId, int bone, int* screenXyz, int mode);
int findBoneIndex(int actorId, int id, int lookup);
int func_800A1648(int, int, int);
int func_800A1720(int, int, MATRIX*, int*);
int func_800A1AF8(int, int, SVECTOR*, int);
int getActorPoint(int actorId, int point, SVECTOR* position, int mode);
int func_800A1B9C(int arg0, int arg1, SVECTOR* arg2, int arg3);
void func_800A2574(int arg0, short arg1);
void func_800A25EC(D_800F4538_t*);
void func_800A2790(D_800F4538_t*);
void func_800A291C(D_800F4538_t*);

extern MATRIX D_800F49B8;
