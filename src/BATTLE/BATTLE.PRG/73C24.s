.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800DC424
    lui     $t0, %hi(vs_battle_actors)
    lw      $t0, %lo(vs_battle_actors)($t0)
    addiu   $a1, $zero, 0x18
.L800DC430:
    lw      $t1, 0x4($t0)
    lw      $t2, 0x3C($t0)
    mult    $a1, $t1
    lw      $t3, 0x18($t2)
    lw      $t4, 0x1C($t2)
    lw      $t5, 0x150($t2)
    lw      $t6, 0x2B4($t2)
    lw      $t0, 0x0($t0)
    mflo    $v0
    lw      $t7, 0x948($t2)
    addu    $v0, $v0, $a0
    sw      $t1, 0x0($v0)
    sw      $t3, 0x4($v0)
    sw      $t4, 0x8($v0)
    sw      $t5, 0x10($v0)
    sw      $t6, 0x14($v0)
    sw      $t7, 0xC($v0)
    bnez    $t0, .L800DC430
    addiu   $a1, $zero, 0x18
    jr      $ra
    nop
endlabel func_800DC424
