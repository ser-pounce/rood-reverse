#include "common.h"
#include "src/SLUS_010.40/libetc/INTR.h"
#include <libetc.h>

void _SpuDataCallback(void (*func)(void)) { DMACallback(4, func); }
