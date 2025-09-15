#include "common.h"

void ExitCriticalSection(void) { SYSCALL(2) }
