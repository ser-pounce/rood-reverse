.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800E45B4
    lui     $t0, (0x1F801110 >> 16)
    lw      $t1, (0x1F801110 & 0xFFFF)($t0)
    lui     $t2, %hi(D_80030FE4)
    lw      $t2, %lo(D_80030FE4)($t2)
    nop
    subu    $v0, $t1, $t2
    jr      $ra
    andi    $v0, $v0, 0xFFFF
endlabel func_800E45B4
