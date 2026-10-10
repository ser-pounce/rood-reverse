.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800E6828
    lhu     $a1, 0x224($a0)
    addiu   $a3, $zero, 0x1
    srl     $a2, $a1, 8
    or      $a1, $a1, $a2
    sh      $a1, 0x15E($a0)
    andi    $a2, $a1, 0x30
    bnez    $a2, .L800E6854
    andi    $a2, $a1, 0x8
    bnez    $a2, .L800E6854
    addiu   $a3, $zero, 0x2
    addiu   $a3, $zero, 0x0
.L800E6854:
    jr      $ra
    sb      $a3, 0x125($a0)
endlabel func_800E6828
