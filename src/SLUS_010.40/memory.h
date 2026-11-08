#pragma once
#include <sys/types.h>

void vs_main_freeHeapR(void* block);
void vs_main_freeHeap(void* block);
void* vs_main_allocHeapR(u_int size);
void* vs_main_allocHeap(u_int size);
void vs_main_bzero(void* dest, int sz);
void vs_main_memcpy(void* dest, void* src, u_int sz);
void vs_main_initHeap(void* heap, u_int size);
