#pragma once
#include "common.h"
#include "camera.h"

int vs_battle_getCameraRoll(void);
VS_HIDDEN(vs_battle_getCameraRoll);

int vs_battle_syncCameraAnglesFromPosition(SphericalCamera*);
VS_HIDDEN(vs_battle_syncCameraAnglesFromPosition);

void vs_battle_setCameraRoll(int arg0);
VS_HIDDEN(vs_battle_setCameraRoll);

void vs_battle_setFarClip(int arg0, int arg1);
VS_HIDDEN(vs_battle_setFarClip);

void vs_battle_initialiseCameraFromSpherical(VECTOR*, VECTOR*, int, int);
VS_HIDDEN(vs_battle_initialiseCameraFromSpherical);

void vs_battle_getCameraPosition(VECTOR* outPosition);
VS_HIDDEN(vs_battle_getCameraPosition);

void vs_battle_setCameraPosition(VECTOR* inPosition);
VS_HIDDEN(vs_battle_setCameraPosition);

void vs_battle_getCameraLookAt(VECTOR* outLookAt);
VS_HIDDEN(vs_battle_getCameraLookAt);

void vs_battle_setCameraLookAt(VECTOR* inLookAt);
VS_HIDDEN(vs_battle_setCameraLookAt);

void vs_battle_setNearClip(int arg0);
VS_HIDDEN(vs_battle_setNearClip);
