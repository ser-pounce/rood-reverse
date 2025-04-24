#include "common.h"

__asm__(".word 0x00017350; .word 0x00450000");

BIOS_STUB(std_out_puts, 0xB0, 0x3F)
