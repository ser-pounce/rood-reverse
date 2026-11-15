#pragma once
#include "common.h"
#include "146C.h"
#include "src/SLUS_010.40/gameState.h"

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

int setUiHidden(int);
VS_HIDDEN(setUiHidden);

void func_8007A824(void* prim);
VS_HIDDEN(func_8007A824);

void func_8007B0FC(void);
VS_HIDDEN(func_8007B0FC);

void func_8007B104(void);
VS_HIDDEN(func_8007B104);

void transformSceneColors(int, int, short, short, short);
VS_HIDDEN(transformSceneColors);

void transformActorColors(int, int, int, short, short, short);
VS_HIDDEN(transformActorColors);

void transformBackgroundColors(int, int, short, short, short);
VS_HIDDEN(transformBackgroundColors);

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

void startBattleTimer(
    enum BattleTimerMode mode, enum BattleTimerLifetime lifetime, int time);
VS_HIDDEN(startBattleTimer);

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

void stopBattleTimer(void);
VS_HIDDEN(stopBattleTimer);

void func_8007BD3C(int);
VS_HIDDEN(func_8007BD3C);

int cullOccludingGeometry(int);
VS_HIDDEN(cullOccludingGeometry);

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

void showCurrentRoom(void);
VS_HIDDEN(showCurrentRoom);

void hideCurrentRoom(void);
VS_HIDDEN(hideCurrentRoom);

void enableAllActors(void);
VS_HIDDEN(enableAllActors);

void disableAllActors(void);
VS_HIDDEN(disableAllActors);

void setWeaponDrawn(int, int);
VS_HIDDEN(setWeaponDrawn);

int func_8007C218(int);
VS_HIDDEN(func_8007C218);

void fullyRestoreActor(int);
VS_HIDDEN(fullyRestoreActor);

void func_8007C31C(void);
VS_HIDDEN(func_8007C31C);

void triggerActorDeath(int, int);
VS_HIDDEN(triggerActorDeath);

// Transitions fade to black or white, or wipe, the screen out and back in
enum ScreenTransitionPhase {
    screenTransitionIdle = 0,
    screenTransitionWarpOut = 1, // a warp has begun, transitioning out
    screenTransitionWarpLoading = 2, // transitioned out, the new room is being set up
    screenTransitionWarpIn = 3, // transitioning in after a warp
    screenTransitionOut = 4, // transitioning out for a script
    screenTransitionOutDone = 5, // transitioned out, held until transitioned in
    screenTransitionIn = 6, // transitioning in for a script
};

int getScreenTransitionPhase(void);
VS_HIDDEN(getScreenTransitionPhase);

void vs_battle_enableDispMask(void);
VS_HIDDEN(vs_battle_enableDispMask);

void vs_battle_disableDispMask(void);
VS_HIDDEN(vs_battle_disableDispMask);

void setScreenTransition(int, int, int);
VS_HIDDEN(setScreenTransition);

void setScreenTransitionWipeAngle(int);
VS_HIDDEN(setScreenTransitionWipeAngle);

void startScreenTransitionOut(int, int, int);
VS_HIDDEN(startScreenTransitionOut);

void startScreenTransitionIn(int, int, int);
VS_HIDDEN(startScreenTransitionIn);

void warpToMapThroughDoor(vs_Warp*, int, int);
VS_HIDDEN(warpToMapThroughDoor);

void warpToZoneThroughDoor(vs_Warp*, int, int);
VS_HIDDEN(warpToZoneThroughDoor);

void func_8007C8A4(int, int);
VS_HIDDEN(func_8007C8A4);

int spawnModelActor(u_int slot, int modelId, vs_TilePosition* tile);
VS_HIDDEN(spawnModelActor);

void setActorWeaponModels(int, int, int);
VS_HIDDEN(setActorWeaponModels);

void restoreActorWeaponModels(int actorId);
VS_HIDDEN(restoreActorWeaponModels);

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

int setTileBlocked(int, int, int, int);
VS_HIDDEN(setTileBlocked);

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

void setCloudstoneMoving(int index, int moving);
VS_HIDDEN(setCloudstoneMoving);

int func_8008E320(int arg0);
VS_HIDDEN(func_8008E320);

int roomHasNoSoundBank(void);
VS_HIDDEN(roomHasNoSoundBank);

void func_8008EAE4(int, int);
VS_HIDDEN(func_8008EAE4);

void setBackgroundVisible(int);
VS_HIDDEN(setBackgroundVisible);

void func_8008EB04(int* arg0, int* arg1);
VS_HIDDEN(func_8008EB04);

int loadBackground(int);
VS_HIDDEN(loadBackground);

int pollBackgroundLoad(void);
VS_HIDDEN(pollBackgroundLoad);

int unloadBackground(void);
VS_HIDDEN(unloadBackground);

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

extern int firstPersonRendering;
VS_HIDDEN(firstPersonRendering);

extern u_short D_800F1CDC;
VS_HIDDEN(D_800F1CDC);

extern short D_800F1D98[];
VS_HIDDEN(D_800F1D98);

extern short backgroundOffsetX;
VS_HIDDEN(backgroundOffsetX);

extern short backgroundOffsetY;
VS_HIDDEN(backgroundOffsetY);

extern short particleEffectSound;
VS_HIDDEN(particleEffectSound);

extern short D_800F1DC0;
VS_HIDDEN(D_800F1DC0);

extern short D_800F1DC2;
VS_HIDDEN(D_800F1DC2);

extern short D_800F1DC4;
VS_HIDDEN(D_800F1DC4);

extern char D_800F1DCA;
VS_HIDDEN(D_800F1DCA);

extern char particleEffectDrift;
VS_HIDDEN(particleEffectDrift);

extern D_800F1DD4_t* D_800F1DD4;
VS_HIDDEN(D_800F1DD4);
