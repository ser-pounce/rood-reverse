.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800F9BD8
    addiu   $sp, $sp, -0x8
    lui     $t5, (0x1F800088 >> 16)
    ori     $t5, $t5, (0x1F800088 & 0xFFFF)
    addu    $t1, $zero, $zero
    addu    $a3, $t1, $zero
    lui     $a1, (0x1F800088 >> 16)
    lui     $v0, (0x1F800004 >> 16)
    lw      $t3, (0x1F800004 & 0xFFFF)($v0)
    ori     $a1, $a1, (0x1F800088 & 0xFFFF)
    sw      $s0, 0x0($sp)
    lw      $t9, 0x0($t3)
    addiu   $v0, $zero, -0x1
    sw      $v0, 0x0($t3)
    lui     $v0, %hi(D_800EB9B4)
    lw      $v0, %lo(D_800EB9B4)($v0)
    addiu   $t2, $t3, 0x1FF8
    lhu     $v1, 0x4($v0)
    lh      $v0, 0x6($v0)
    sll     $a2, $v1, 4
    addiu   $a0, $v0, 0x1000
.L800F9C28:
    mult    $a2, $a0
    sra     $v0, $a2, 3
    sh      $v0, 0x0($a1)
    addiu   $a1, $a1, 0x2
    addiu   $a3, $a3, 0x1
    sltiu   $v0, $a3, 0x1BC
    mflo    $s0
    bnez    $v0, .L800F9C28
    sra     $a2, $s0, 12
    addiu   $t8, $zero, -0x2
    addiu   $t7, $zero, 0x1F
    lui     $v0, %hi(D_80040C18)
    addiu   $t6, $v0, %lo(D_80040C18)
.L800F9C5C:
    addiu   $a0, $zero, 0x1
    lbu     $a3, 0x3($t2)
    addiu   $v1, $t2, 0x4
.L800F9C68:
    lw      $v0, 0x0($v1)
    addiu   $v1, $v1, 0x4
    srl     $v0, $v0, 26
    addiu   $a2, $v0, -0x8
    sltiu   $v0, $a2, 0x30
    bnez    $v0, .L800F9C90
    addiu   $a0, $a0, 0x1
    slt     $v0, $a3, $a0
    beqz    $v0, .L800F9C68
    nop
.L800F9C90:
    sltiu   $v0, $a2, 0x8
    beqz    $v0, .L800F9CB8
    andi    $v0, $a2, 0x1
    sra     $v1, $a2, 2
    andi    $v1, $v1, 0x1
    addu    $v0, $v0, $v1
    addiu   $t4, $v0, 0x1
    sra     $v0, $a2, 1
    andi    $v0, $v0, 0x1
    addiu   $t1, $v0, 0x3
.L800F9CB8:
    beqz    $t1, .L800F9DAC
    sll     $v0, $a0, 2
    addu    $t0, $v0, $t2
.L800F9CC4:
    lw      $a3, 0x0($t0)
    nop
    sra     $v0, $a3, 16
    addiu   $a2, $v0, -0x70
    sll     $v0, $a3, 16
    sra     $v0, $v0, 16
    addiu   $a3, $v0, -0xA0
    mtc2    $a3, $9
    mtc2    $a2, $10
    addiu   $t1, $t1, -0x1
    nop
    sqr     0
    mfc2    $v1, $25
    mfc2    $v0, $26
    nop
    addu    $a0, $v1, $v0
    mtc2    $a0, $30
    beqz    $a0, .L800F9D5C
    sll     $v0, $a0, 1
    mfc2    $v1, $31
    nop
    and     $a1, $v1, $t8
    subu    $v1, $t7, $a1
    addiu   $v0, $zero, 0x18
    subu    $v0, $v0, $a1
    srav    $v0, $a0, $v0
    addiu   $v0, $v0, -0x40
    sll     $v0, $v0, 1
    addu    $v0, $v0, $t6
    lhu     $a1, 0x0($v0)
    sra     $v0, $v1, 1
    sllv    $v0, $a1, $v0
    sra     $a0, $v0, 12
    sltiu   $v0, $a0, 0x1BC
    bnez    $v0, .L800F9D5C
    sll     $v0, $a0, 1
    addiu   $a0, $zero, 0x1BB
    sll     $v0, $a0, 1
.L800F9D5C:
    addu    $v0, $v0, $t5
    lhu     $a0, 0x0($v0)
    nop
    mult    $a3, $a0
    mflo    $v1
    nop
    nop
    mult    $a2, $a0
    sra     $v1, $v1, 13
    addiu   $v1, $v1, 0xA0
    andi    $v1, $v1, 0xFFFF
    mflo    $v0
    sra     $v0, $v0, 13
    addiu   $v0, $v0, 0x70
    sll     $v0, $v0, 16
    or      $v1, $v1, $v0
    sll     $v0, $t4, 2
    sw      $v1, 0x0($t0)
    bnez    $t1, .L800F9CC4
    addu    $t0, $t0, $v0
.L800F9DAC:
    lui     $a0, (0xFFFFFF >> 16)
    ori     $a0, $a0, (0xFFFFFF & 0xFFFF)
    lw      $v1, 0x0($t2)
    lui     $v0, 0x8000
    and     $v1, $v1, $a0
    or      $t2, $v1, $v0
    lw      $v0, 0x0($t2)
    nop
    and     $v0, $v0, $a0
    bne     $v0, $a0, .L800F9C5C
    nop
    sw      $t9, 0x0($t3)
    lw      $s0, 0x0($sp)
    jr      $ra
    addiu   $sp, $sp, 0x8
endlabel func_800F9BD8
