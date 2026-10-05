#include "common.h"

extern void* InterruptCallback(int irq, void (*func)(void));

void _SpuCallback(void (*func)(void)) { InterruptCallback(9, func); }
