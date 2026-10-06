.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800E3D5C
    addu    $v1, $a1, $zero
    mtc2    $ra, $25
    mtc2    $a0, $12
    mtc2    $v1, $13
    jalr    $v1
    addu    $a1, $zero, $zero
    mtc2    $v0, $8
    mfc2    $v1, $13
    mfc2    $a0, $12
    jalr    $v1
    addiu   $a1, $zero, 0x2
    mtc2    $v0, $9
    mfc2    $v1, $13
    mfc2    $a0, $12
    jalr    $v1
    addiu   $a1, $zero, 0x4
    mtc2    $v0, $10
    mfc2    $v1, $13
    mfc2    $a0, $12
    jalr    $v1
    addiu   $a1, $zero, 0x6
    mfc2    $a0, $8
    mfc2    $a1, $9
    mfc2    $a2, $10
    sll     $a0, $a0, 3
    sll     $a1, $a1, 2
    sll     $a2, $a2, 1
    mfc2    $ra, $25
    or      $a0, $a0, $a1
    or      $a0, $a0, $a2
    jr      $ra
    or      $v0, $a0, $v0
endlabel func_800E3D5C
