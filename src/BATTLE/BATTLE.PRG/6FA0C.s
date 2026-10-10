.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: cross-function control flow
glabel func_800D820C
    beqz    $a0, L800D8278
    addu    $v0, $zero, $zero
    j       func_80095B7C
    nop
endlabel func_800D820C

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800D821C
    addiu   $a1, $zero, 0x0
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x14($sp)
    sw      $ra, 0x18($sp)
    lbu     $a0, 0x88($a0)
    jal     func_800D820C
    addu    $s0, $a0, $zero
    addu    $a0, $s0, $zero
    jal     func_800D820C
    addiu   $a1, $zero, 0x40
    lw      $ra, 0x18($sp)
    lw      $s0, 0x14($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
alabel L800D8254
    lbu     $a0, 0x88($a0)
    bgez    $zero, func_800D820C
    addiu   $a1, $zero, 0x0
endlabel func_800D821C
