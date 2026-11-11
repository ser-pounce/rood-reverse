#pragma once
#include "common.h"
#include "camera.h"

int getCameraRoll(void);
VS_HIDDEN(getCameraRoll);

int syncCameraAnglesFromPosition(SphericalCamera*);
VS_HIDDEN(syncCameraAnglesFromPosition);

void setCameraRoll(int arg0);
VS_HIDDEN(setCameraRoll);

void setFarClip(int arg0, int arg1);
VS_HIDDEN(setFarClip);

void initialiseCameraFromSpherical(VECTOR*, VECTOR*, int, int);
VS_HIDDEN(initialiseCameraFromSpherical);

void getCameraPosition(VECTOR* outPosition);
VS_HIDDEN(getCameraPosition);

void setCameraPosition(VECTOR* inPosition);
VS_HIDDEN(setCameraPosition);

void getCameraLookAt(VECTOR* outLookAt);
VS_HIDDEN(getCameraLookAt);

void setCameraLookAt(VECTOR* inLookAt);
VS_HIDDEN(setCameraLookAt);

void setNearClip(int arg0);
VS_HIDDEN(setNearClip);
