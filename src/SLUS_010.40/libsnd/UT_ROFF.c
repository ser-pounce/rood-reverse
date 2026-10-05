#include "common.h"

extern void _SpuInit(int mode);

void SsUtReverbOff(void) { _SpuInit(0); }
