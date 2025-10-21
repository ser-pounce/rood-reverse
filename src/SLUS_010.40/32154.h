#pragma once
#include <stddef.h>
#include <libgte.h>

void func_80041954(int, int);
VECTOR* vs_gte_vectorSquare(VECTOR* v, VECTOR* result);
void vs_gte_crossProduct(VECTOR* v0, VECTOR* v1, VECTOR* result);
void vs_gte_cueDepth(u_int* src, u_int depth, u_int* dst);