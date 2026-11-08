#pragma once
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern void* vs_main_ot[2];
extern short vs_main_screenX;
extern short vs_main_screenWidth;
extern short vs_main_screenY;
extern u_short vs_main_screenHeight;
extern void* vs_main_prims[2];
extern int vs_main_nearClip;
extern DRAWENV vs_main_drawEnv[2];
extern DISPENV vs_main_dispEnv[2];
extern u_int vs_main_frameDuration;
extern int vs_main_frameBuf;
extern MATRIX vs_main_cameraBasis;
extern int vs_main_projectionDistance;
#endif
