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
} ScreenTransitionWipePoly;

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
} CameraTransition;

void vs_battle_lookAt(VECTOR* from, VECTOR* to, MATRIX* mat);
void vs_battle_setProjectionDistance(int);
extern SphericalCamera vs_battle_cameraCurrentSpherical;
extern DR_MODE vs_battle_screenTransitionDrMode[];
extern int vs_battle_screenTransitionAlpha;
extern ScreenTransitionWipePoly vs_battle_screenTransitionWipePolyF4[];
extern POLY_G4 vs_battle_screenTransitionEdgePolyG4[];
extern POLY_F4 vs_battle_screenTransitionPolyF4[];
extern CameraTransition* vs_battle_cameraTransition;
extern u_int vs_battle_screenTransitionStep;
extern int vs_battle_screenTransitionEffect;
extern int vs_battle_screenTransitionWipeAngle;
extern int vs_battle_screenTransitionSpeed;
