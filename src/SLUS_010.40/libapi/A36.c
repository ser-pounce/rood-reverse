#include "common.h"

void EnterCriticalSection() { SYSCALL(1) }
