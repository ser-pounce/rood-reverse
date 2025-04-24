#include "overlay.h"

void* const vs_overlay_slots[5] = { (void*)0x80068800, (void*)0x800F9800,
    (void*)0x80102800, (void*)0x800F9800, (void*)0x800F9800 };

void getSp(int* sp)
{
    __asm__("addu $t0, %0, $0;"
            "sw   $sp, 0x0($t0);" ::"r"(sp));
}

__asm__("jumpFunc vs_overlay_jumpToTitle, execTitle;"
        "jumpFunc jumpToBattle, execBattle;");

void wait() { __asm__(".nop 4096;"); }
