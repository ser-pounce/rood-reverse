#include "common.h"
#include <libetc.h>

void _SpuCallback(void (*func)(void)) { InterruptCallback(9, func); }
