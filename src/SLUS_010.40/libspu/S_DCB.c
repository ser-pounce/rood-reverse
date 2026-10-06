#include "common.h"
#include <libetc.h>

void _SpuDataCallback(void (*func)(void)) { DMACallback(4, func); }
