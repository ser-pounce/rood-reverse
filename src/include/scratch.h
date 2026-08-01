#pragma once
#include <stddef.h>
#include <libgte.h>

typedef struct {
    /* 0x00 */ VECTOR position;
    /* 0x10 */ VECTOR lookAt;
    /* 0x20 */ VECTOR angles;
    /* 0x30 */ int farClip;
} vs_camera_t;

typedef struct {
    /* 0x00 */ void* unk0;
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ void* unkC;
    /* 0x10 */ u_int firstPersonViewFacing;
    /* 0x14 */ MATRIX viewMatrix;
    /* 0x34 */ vs_camera_t camera;
} vs_scratch_t;

extern vs_scratch_t vs_scratch;
