.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800E65DC
    addiu   $v0, $zero, 0x10
    lui     $a3, (0x1F8003DC >> 16)
    lui     $a0, %hi(D_800F5878)
    addiu   $a0, $a0, %lo(D_800F5878)
.L800E65EC:
    sll     $a2, $v0, 2
    addu    $v1, $a0, $a2
    lw      $a1, 0x0($v1)
    addiu   $v0, $v0, -0x1
    addu    $v1, $a3, $a2
    bgez    $v0, .L800E65EC
    sw      $a1, (0x1F80037C & 0xFFFF)($v1)
    lui     $v0, %hi(D_800F58BC)
    lw      $v0, %lo(D_800F58BC)($v0)
    lui     $t0, %hi(D_800F58D0)
    lw      $t0, %lo(D_800F58D0)($t0)
    lui     $t1, %hi(D_800F58B8)
    lw      $t1, %lo(D_800F58B8)($t1)
    lui     $t2, %hi(D_800F58CC)
    lw      $t2, %lo(D_800F58CC)($t2)
    lui     $t3, %hi(D_800F58C0)
    lw      $t3, %lo(D_800F58C0)($t3)
    lui     $t4, %hi(D_800F58C4)
    lw      $t4, %lo(D_800F58C4)($t4)
    lui     $t5, %hi(D_800F16E0)
    lw      $t5, %lo(D_800F16E0)($t5)
    lui     $t6, %hi(D_800F16E4)
    lw      $t6, %lo(D_800F16E4)($t6)
    lui     $t7, %hi(D_800F16E8)
    lw      $t7, %lo(D_800F16E8)($t7)
    lui     $t8, %hi(D_800F16EC)
    lw      $t8, %lo(D_800F16EC)($t8)
    lui     $t9, %hi(D_800F16F0)
    lw      $t9, %lo(D_800F16F0)($t9)
    lw      $v0, 0x4($v0)
    sw      $t0, (0x1F8003BC & 0xFFFF)($a3)
    sw      $t1, (0x1F8003C0 & 0xFFFF)($a3)
    sw      $t2, (0x1F8003C4 & 0xFFFF)($a3)
    sw      $t3, (0x1F8003F4 & 0xFFFF)($a3)
    sw      $t4, (0x1F8003F8 & 0xFFFF)($a3)
    sw      $t5, (0x1F8003E0 & 0xFFFF)($a3)
    sw      $t6, (0x1F8003E4 & 0xFFFF)($a3)
    sw      $t7, (0x1F8003E8 & 0xFFFF)($a3)
    sw      $t8, (0x1F8003EC & 0xFFFF)($a3)
    sw      $t9, (0x1F8003F0 & 0xFFFF)($a3)
    jr      $ra
    sw      $v0, (0x1F8003DC & 0xFFFF)($a3)
endlabel func_800E65DC
