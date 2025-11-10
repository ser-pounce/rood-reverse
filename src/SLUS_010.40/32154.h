#pragma once
#include <stddef.h>
#include <libgte.h>

void vs_gte_setDepthCueDefault(int, int);
VECTOR* vs_gte_vectorSquare(VECTOR* v, VECTOR* result);
void vs_gte_crossProduct(VECTOR* v0, VECTOR* v1, VECTOR* result);
void vs_gte_cueDepth(void* src, u_int depth, void* dst);