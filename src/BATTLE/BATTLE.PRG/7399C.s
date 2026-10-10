.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800DC19C
    lbu     $v0, 0x13($a0)
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    sw      $ra, 0x14($sp)
    sb      $zero, 0x126($a0)
    addu    $s0, $a0, $zero
    beqz    $v0, .L800DC274
    lbu     $a0, 0x88($s0)
    addiu   $a1, $zero, 0x40
    jal     func_800D820C
    sb      $zero, 0x13($s0)
    jal     func_800E7370
    addu    $a0, $s0, $zero
    lw      $a0, 0x6C($s0)
    lbu     $v0, 0x30($s0)
    beqz    $a0, .L800DC1E4
    sw      $zero, 0x6C($s0)
    sw      $a0, 0x68($s0)
.L800DC1E4:
    bnez    $v0, .L800DC274
    addiu   $a1, $zero, 0x6
    addiu   $a2, $zero, 0x28
    jal     func_800D8260
    addu    $a0, $s0, $zero
    addiu   $a1, $zero, 0x2
    addiu   $a2, $zero, 0x80
    lui     $ra, %hi(.L800DC274)
    addiu   $ra, $ra, %lo(.L800DC274)
    bgez    $zero, func_800E48A8
    addu    $a0, $s0, $zero
endlabel func_800DC19C

glabel func_800DC210
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    sw      $ra, 0x14($sp)
    bnez    $a1, .L800DC24C
    addu    $s0, $a0, $zero
    jal     rand
    nop
    lbu     $v1, 0x126($s0)
    andi    $v0, $v0, 0x7F
    slti    $v0, $v0, 0x4C
    beqz    $v0, .L800DC274
    addiu   $v1, $v1, 0x1
    slti    $v0, $v1, 0x2
    bnez    $v0, .L800DC274
    sb      $v1, 0x126($s0)
.L800DC24C:
    addiu   $v0, $zero, 0x1
    sb      $v0, 0x13($s0)
    lw      $v1, 0x68($s0)
    lui     $v0, %hi(D_800DBC0C)
    addiu   $v0, $v0, %lo(D_800DBC0C)
    lbu     $a0, 0x88($s0)
    sw      $v0, 0x68($s0)
    sw      $v1, 0x6C($s0)
    jal     func_800D820C
    addiu   $a1, $zero, 0x80
.L800DC274:
    lw      $ra, 0x14($sp)
    lw      $s0, 0x10($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800DC210

glabel func_800DC284
    addiu   $v0, $zero, 0x6
    mult    $v0, $a0
    sll     $a2, $a2, 16
    andi    $a1, $a1, 0xFFFF
    or      $a1, $a2, $a1
    ctc2    $a1, $0 /* handwritten instruction */
    ctc2    $a3, $1 /* handwritten instruction */
    ctc2    $zero, $2 /* handwritten instruction */
    ctc2    $zero, $3 /* handwritten instruction */
    ctc2    $zero, $4 /* handwritten instruction */
    ori     $t0, $zero, 0x4
    ori     $t1, $zero, 0x1
    ori     $t2, $zero, 0x2
    mtc2    $t0, $9 /* handwritten instruction */
    mtc2    $t1, $10 /* handwritten instruction */
    mtc2    $t2, $11 /* handwritten instruction */
    nop
    nop
    rtir0
    mflo    $a1
    mfc2    $a0, $25 /* handwritten instruction */
    jr      $ra
    add     $v0, $a0, $a1 /* handwritten instruction */
endlabel func_800DC284
