#pragma once
#include "common.h"
#include "146C.h"

void func_80069C6C(int);
VS_HIDDEN(func_80069C6C);

void func_8006CD60(u_int*, int, int);
VS_HIDDEN(func_8006CD60);

void func_8006CDB8(int);
VS_HIDDEN(func_8006CDB8);

void func_8006CA20(int, SVECTOR*);
VS_HIDDEN(func_8006CA20);

void func_8006CB04(int, SVECTOR*);
VS_HIDDEN(func_8006CB04);

void func_8006C480(int, int);
VS_HIDDEN(func_8006C480);

void func_8006C4A4(int, int);
VS_HIDDEN(func_8006C4A4);

int func_8006C84C(int);
VS_HIDDEN(func_8006C84C);

void func_8006CDD8(SVECTOR*);
VS_HIDDEN(func_8006CDD8);

void func_8006CE50(void);
VS_HIDDEN(func_8006CE50);

void func_8006CE70(SVECTOR*);
VS_HIDDEN(func_8006CE70);

int func_8007BD8C(int);
VS_HIDDEN(func_8007BD8C);

void func_8007A824(void* prim);
VS_HIDDEN(func_8007A824);

void func_8007B0FC(void);
VS_HIDDEN(func_8007B0FC);

void func_8007B104(void);
VS_HIDDEN(func_8007B104);

void func_8007B1B8(int, int, short, short, short);
VS_HIDDEN(func_8007B1B8);

void func_8007B29C(int, int, int, short, short, short);
VS_HIDDEN(func_8007B29C);

void func_8007B344(int, int, short, short, short);
VS_HIDDEN(func_8007B344);

void func_8007B9A0(void);
VS_HIDDEN(func_8007B9A0);

void func_8007B9CC(void);
VS_HIDDEN(func_8007B9CC);

int func_8007B9FC(void);
VS_HIDDEN(func_8007B9FC);

void func_8007BA98(int, int, int, int);
VS_HIDDEN(func_8007BA98);

void vs_battle_forgetZoneEnemies(int, int);
VS_HIDDEN(vs_battle_forgetZoneEnemies);

void func_8007BBD8(int, int, int);
VS_HIDDEN(func_8007BBD8);

void func_8007C4D4(void);
VS_HIDDEN(func_8007C4D4);

int func_8007C8F8(int);
VS_HIDDEN(func_8007C8F8);

void func_8007CE74(int);
VS_HIDDEN(func_8007CE74);

void func_8007CEC0(void);
VS_HIDDEN(func_8007CEC0);

int func_8007CF80(int);
VS_HIDDEN(func_8007CF80);

void func_8007BCCC(void);
VS_HIDDEN(func_8007BCCC);

void func_8007BD3C(int);
VS_HIDDEN(func_8007BD3C);

int func_8007BDD8(int);
VS_HIDDEN(func_8007BDD8);

int func_8007BE10(int);
VS_HIDDEN(func_8007BE10);

void func_8007BE20(int, int);
VS_HIDDEN(func_8007BE20);

void func_8007BEC4(int);
VS_HIDDEN(func_8007BEC4);

int func_8007BEE4(void);
VS_HIDDEN(func_8007BEE4);

void func_8007BF04(void);
VS_HIDDEN(func_8007BF04);

int func_8007BF0C(void);
VS_HIDDEN(func_8007BF0C);

void func_8007BF2C(void);
VS_HIDDEN(func_8007BF2C);

void func_8007BF4C(void);
VS_HIDDEN(func_8007BF4C);

void func_8007BFC0(void);
VS_HIDDEN(func_8007BFC0);

void func_8007C050(void);
VS_HIDDEN(func_8007C050);

void setWeaponDrawn(int, int);
VS_HIDDEN(setWeaponDrawn);

int func_8007C218(int);
VS_HIDDEN(func_8007C218);

void func_8007C28C(int);
VS_HIDDEN(func_8007C28C);

void func_8007C31C(void);
VS_HIDDEN(func_8007C31C);

void triggerActorDeath(int, int);
VS_HIDDEN(triggerActorDeath);

int func_8007C398(void);
VS_HIDDEN(func_8007C398);

void vs_battle_enableDispMask(void);
VS_HIDDEN(vs_battle_enableDispMask);

void vs_battle_disableDispMask(void);
VS_HIDDEN(vs_battle_disableDispMask);

void setScreenTransition(int, int, int);
VS_HIDDEN(setScreenTransition);

void setScreenTransitionWipeAngle(int);
VS_HIDDEN(setScreenTransitionWipeAngle);

void func_8007C46C(int, int, int);
VS_HIDDEN(func_8007C46C);

void func_8007C4AC(int, int, int);
VS_HIDDEN(func_8007C4AC);

void func_8007C580(vs_Warp*, int, int);
VS_HIDDEN(func_8007C580);

void func_8007C654(vs_Warp*, int, int);
VS_HIDDEN(func_8007C654);

void func_8007C8A4(int, int);
VS_HIDDEN(func_8007C8A4);

int spawnModelActor(u_int slot, int modelId, vs_TilePosition* tile);
VS_HIDDEN(spawnModelActor);

void func_8007CA20(int, int, int);
VS_HIDDEN(func_8007CA20);

void func_8007CAA4(int);
VS_HIDDEN(func_8007CAA4);

void enqueueEsq(int, int);
VS_HIDDEN(enqueueEsq);

void unloadEsqAndEtm(int);
VS_HIDDEN(unloadEsqAndEtm);

void enqueueEsqAndEtm(int, int, int);
VS_HIDDEN(enqueueEsqAndEtm);

void enqueueEtm(int, int, int);
VS_HIDDEN(enqueueEtm);

void unloadEtm(int);
VS_HIDDEN(unloadEtm);

void selectEventData(int);
VS_HIDDEN(selectEventData);

int getEmptyObjectDataSlot(void);
VS_HIDDEN(getEmptyObjectDataSlot);

int func_8007CF18(int);
VS_HIDDEN(func_8007CF18);

int func_8007CFCC(int);
VS_HIDDEN(func_8007CFCC);

void walkActorToCoordinate(int, SVECTOR*);
VS_HIDDEN(walkActorToCoordinate);

int isActorWalkDone(int);
VS_HIDDEN(isActorWalkDone);

int setActorAwake(int, int);
VS_HIDDEN(setActorAwake);

int setActorsAwake(int);
VS_HIDDEN(setActorsAwake);

void setActorInactive(int actorId, int inactive);
VS_HIDDEN(setActorInactive);

int isActionUnlocked(u_int);
VS_HIDDEN(isActionUnlocked);

void setActionUnlocked(u_int);
VS_HIDDEN(setActionUnlocked);

void func_8007D260(int arg0);
VS_HIDDEN(func_8007D260);

void despawnActor(int);
VS_HIDDEN(despawnActor);

int func_8008C458(int, int, CVECTOR*, SVECTOR*);
VS_HIDDEN(func_8008C458);

void func_8007DE88(VECTOR* arg0);
VS_HIDDEN(func_8007DE88);

void func_8007DEA8(CVECTOR* arg0);
VS_HIDDEN(func_8007DEA8);

void func_8007DECC(VECTOR* arg0);
VS_HIDDEN(func_8007DECC);

int func_8007E180(int arg0);
VS_HIDDEN(func_8007E180);

int func_8007E1C0(int arg0);
VS_HIDDEN(func_8007E1C0);

int itemIdIsInInventory(int);
VS_HIDDEN(itemIdIsInInventory);

int func_8008631C(int arg0, int arg1, int targetActor, int targetLimb, void* arg4);
VS_HIDDEN(func_8008631C);

int func_800863A4(int arg0, int arg1, int targetActor, int arg3, SVECTOR* arg4,
    SVECTOR* arg5, D_800F19CC_t2* arg6);
VS_HIDDEN(func_800863A4);

int func_80089104(void);
VS_HIDDEN(func_80089104);

int func_8008B808(int, int, int, int);
VS_HIDDEN(func_8008B808);

void setDoorEntered2(int arg0);
VS_HIDDEN(setDoorEntered2);

void func_8008C40C(void);
VS_HIDDEN(func_8008C40C);

int func_8008C49C(int arg0, int arg1);
VS_HIDDEN(func_8008C49C);

int func_8008D2C0(SVECTOR arg0[]);
VS_HIDDEN(func_8008D2C0);

void func_8008D594(int);
VS_HIDDEN(func_8008D594);

void func_8008D5A0(int);
VS_HIDDEN(func_8008D5A0);

short func_8008DA24(int arg0, int arg1);
VS_HIDDEN(func_8008DA24);

short func_8008DC7C(int arg0, int arg1);
VS_HIDDEN(func_8008DC7C);

short func_8008DD0C(int arg0, int arg1);
VS_HIDDEN(func_8008DD0C);

int func_8008DDA8(int arg0, int arg1);
VS_HIDDEN(func_8008DDA8);

void func_8008E224(int, int);
VS_HIDDEN(func_8008E224);

int func_8008E320(int arg0);
VS_HIDDEN(func_8008E320);

int func_8008E470(void);
VS_HIDDEN(func_8008E470);

void func_8008EAE4(int, int);
VS_HIDDEN(func_8008EAE4);

void func_8008EAF8(int);
VS_HIDDEN(func_8008EAF8);

void func_8008EB04(int* arg0, int* arg1);
VS_HIDDEN(func_8008EB04);

int func_8008EFCC(int);
VS_HIDDEN(func_8008EFCC);

int func_8008F0FC(void);
VS_HIDDEN(func_8008F0FC);

int func_8008F234(void);
VS_HIDDEN(func_8008F234);

int getCollisionMapDimensions(UNUSED int arg0);
VS_HIDDEN(getCollisionMapDimensions);

void func_8008F29C(int arg0, int arg1);
VS_HIDDEN(func_8008F29C);

void func_8008F30C(int arg0, int arg1);
VS_HIDDEN(func_8008F30C);

void func_8008F440(void);
VS_HIDDEN(func_8008F440);

void func_8008F9A4(int arg0, int arg1);
VS_HIDDEN(func_8008F9A4);

void func_8008FAC8(void);
VS_HIDDEN(func_8008FAC8);

void func_8008FDC4(void);
VS_HIDDEN(func_8008FDC4);

void func_80090434(void);
VS_HIDDEN(func_80090434);

void func_80090B28(void);
VS_HIDDEN(func_80090B28);

extern int D_800F1868;
VS_HIDDEN(D_800F1868);

extern int D_800F19C8;
VS_HIDDEN(D_800F19C8);

extern u_short D_800F1CDC;
VS_HIDDEN(D_800F1CDC);

extern short D_800F1D98[];
VS_HIDDEN(D_800F1D98);

extern short D_800F1DB4;
VS_HIDDEN(D_800F1DB4);

extern short D_800F1DB6;
VS_HIDDEN(D_800F1DB6);

extern short D_800F1DBC;
VS_HIDDEN(D_800F1DBC);

extern short D_800F1DC0;
VS_HIDDEN(D_800F1DC0);

extern short D_800F1DC2;
VS_HIDDEN(D_800F1DC2);

extern short D_800F1DC4;
VS_HIDDEN(D_800F1DC4);

extern char D_800F1DCA;
VS_HIDDEN(D_800F1DCA);

extern char D_800F1DCB;
VS_HIDDEN(D_800F1DCB);

extern D_800F1DD4_t* D_800F1DD4;
VS_HIDDEN(D_800F1DD4);
