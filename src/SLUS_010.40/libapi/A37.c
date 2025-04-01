#include "common.h"

void ExitCriticalSection() { SYSCALL(2) }
