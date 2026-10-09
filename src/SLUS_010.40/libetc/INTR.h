#pragma once

int DMACallback(int dma, void (*func)(void));
void* InterruptCallback(int irq, void (*func)(void));
