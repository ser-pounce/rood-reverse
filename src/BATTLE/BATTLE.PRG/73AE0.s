.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: temp register usage
glabel func_800DC2E0
    lw      $t0, 0x0($a1)
    lw      $t1, 0x4($a1)
    lw      $t2, 0x8($a1)
    lw      $t3, 0xC($a1)
    lw      $t4, 0x10($a1)
    sw      $t0, 0x0($a0)
    sw      $t1, 0x4($a0)
    sw      $t2, 0x8($a0)
    sw      $t3, 0xC($a0)
    jr      $ra
    sw      $t4, 0x10($a0)
endlabel func_800DC2E0
