#pragma once
#include "scratch.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    int yaw;
    int pitch;
    int distance;
    int mode;
} SphericalValues;

typedef struct {
    SphericalValues values;
    SphericalValues delta;
    int initialDistance;
    int unk24;
    int speed;
} SphericalCamera;

typedef struct {
    POLY_F4 covered;
    POLY_F4 edge;
} vs_battle_ScreenTransitionWipePoly;

typedef struct {
    vs_Camera fromCameraState;
    SphericalCamera fromSpherical;
    int fromNearClip;
    int fromProjectionDistance;
    int fromFarClip;
    SphericalCamera toSpherical;
    int toNearClip;
    int toProjectionDistance;
    int toFarClip;
    VECTOR targetPosition;
    VECTOR targetLookAt;
    VECTOR direction;
    VECTOR lookAtStep;
    int farClipStep;
    int nearClipStep;
    int projectionDistanceStep;
    int transitionSpeed;
    int transitionFrames;
} vs_battle_CameraTransition;

int vs_battle_getCameraRoll(void);
void vs_battle_lookAt(VECTOR* from, VECTOR* to, MATRIX* mat);
int vs_battle_syncCameraAnglesFromPosition(SphericalCamera*);
void vs_battle_setCameraRoll(int arg0);
void vs_battle_setFarClip(int arg0, int arg1);
void vs_battle_initialiseCameraFromSpherical(VECTOR*, VECTOR*, int, int);
void vs_battle_setProjectionDistance(int);
void vs_battle_getCameraPosition(VECTOR* outPosition);
void vs_battle_setCameraPosition(VECTOR* inPosition);
void vs_battle_getCameraLookAt(VECTOR* outLookAt);
void vs_battle_setCameraLookAt(VECTOR* inLookAt);
void vs_battle_setNearClip(int arg0);
extern SphericalCamera vs_battle_cameraCurrentSpherical;
extern DR_MODE vs_battle_screenTransitionDrMode[];
extern int vs_battle_screenTransitionAlpha;
extern vs_battle_ScreenTransitionWipePoly vs_battle_screenTransitionWipePolyF4[];
extern POLY_G4 vs_battle_screenTransitionEdgePolyG4[];
extern POLY_F4 vs_battle_screenTransitionPolyF4[];
extern vs_battle_CameraTransition* vs_battle_cameraTransition;
extern u_int vs_battle_screenTransitionStep;
extern int vs_battle_screenTransitionEffect;
extern int vs_battle_screenTransitionWipeAngle;
extern int vs_battle_screenTransitionSpeed;
