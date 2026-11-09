#pragma once
#include "camera.h"

int vs_battle_getCameraRoll(void);
int vs_battle_syncCameraAnglesFromPosition(SphericalCamera*);
void vs_battle_setCameraRoll(int arg0);
void vs_battle_setFarClip(int arg0, int arg1);
void vs_battle_initialiseCameraFromSpherical(VECTOR*, VECTOR*, int, int);
void vs_battle_getCameraPosition(VECTOR* outPosition);
void vs_battle_setCameraPosition(VECTOR* inPosition);
void vs_battle_getCameraLookAt(VECTOR* outLookAt);
void vs_battle_setCameraLookAt(VECTOR* inLookAt);
void vs_battle_setNearClip(int arg0);
