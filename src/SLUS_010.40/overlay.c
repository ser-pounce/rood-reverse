#include "overlay.h"

void* const vs_overlay_slots[5] = { (void*)0x80068800, (void*)0x800F9800,
    (void*)0x80102800, (void*)0x800F9800, (void*)0x800F9800 };

void vs_overlay_getSp(int* sp)
{
    __asm__("addu $t0, %0, $0;"
            "sw   $sp, 0x0($t0);" ::"r"(sp));
}

__asm__("jumpFunc vs_overlay_jumpToTitle, vs_main_execTitle;"
        "jumpFunc vs_overlay_jumpToBattle, execBattle;");

void vs_overlay_wait() { __asm__(".nop 4096;"); }
