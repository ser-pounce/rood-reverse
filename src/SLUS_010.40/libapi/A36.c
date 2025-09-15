#include "common.h"

void EnterCriticalSection(void) { SYSCALL(1) }
