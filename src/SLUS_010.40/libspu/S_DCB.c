#include "common.h"

extern void* DMACallback(int dma, void (*func)(void));

void _SpuDataCallback(void (*func)(void)) { DMACallback(4, func); }
