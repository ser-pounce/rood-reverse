#include "common.h"

extern void _SpuInit(int mode);

void SsUtReverbOn(void) { _SpuInit(1); }
