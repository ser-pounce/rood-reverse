#pragma once
#include <stddef.h>
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    /* 0x00 */ VECTOR position;
    /* 0x10 */ VECTOR lookAt;
    /* 0x20 */ VECTOR angles;
    /* 0x30 */ int farClip;
} vs_Camera;

typedef struct {
    /* 0x00 */ void* nextPrim; // where the next primitive goes in the frame's buffer
    /* 0x04 */ void* depthOt; // the ordering table slot for depth 0, add a depth to it
    /* 0x08 */ void* frontOt; // the front of the ordering table, drawn after the rest
    /* 0x0C */ void* unkC;
    /* 0x10 */ u_int firstPersonViewFacing;
    /* 0x14 */ MATRIX viewMatrix;
    /* 0x34 */ vs_Camera camera;
} vs_Scratch;

extern vs_Scratch vs_scratch;

/**
 * The scratchpad holds several workspaces over one another, so the type to view it as
 * has to be given.
 * @param type The pointer type to give it, such as `MATRIX*`.
 * @param offset Offset from the start of the scratchpad.
 */
#define VS_SCRATCH_AT(type, offset) ((type)(0x1F800000 + (offset)))

/** The frame state at the start of the scratchpad. */
#define VS_SCRATCH VS_SCRATCH_AT(vs_Scratch*, 0)
