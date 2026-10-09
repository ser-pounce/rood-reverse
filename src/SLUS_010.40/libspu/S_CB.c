#include "common.h"
#include "src/SLUS_010.40/libetc/INTR.h"
#include <libetc.h>

void _SpuCallback(void (*func)(void)) { InterruptCallback(9, func); }
