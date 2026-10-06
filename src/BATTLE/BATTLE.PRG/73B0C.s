.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800DC30C
    lh      $t0, 0x0($a0)
    addiu   $v0, $zero, 0x2
    bne     $v0, $a3, .L800DC320
    sub     $v1, $t0, $a2 /* handwritten instruction */
    add     $v1, $t0, $a2 /* handwritten instruction */
.L800DC320:
    lh      $t1, 0x0($a1)
    bltz    $v1, .L800DC33C
    addu    $a3, $zero, $zero
    slt     $t2, $t1, $v1
    bnez    $t2, .L800DC33C
    addu    $a3, $t1, $zero
    addu    $a3, $v1, $zero
.L800DC33C:
    jr      $ra
    sh      $a3, 0x0($a0)
endlabel func_800DC30C

glabel func_800DC344
    lw      $v0, 0x470($a0)
    addiu   $t3, $zero, 0x14
    lui     $t0, %hi(D_800F5904)
    addiu   $t0, $t0, %lo(D_800F5904)
    lw      $v1, 0xC($a1)
    mult    $v0, $t3
    slti    $a3, $v0, 0x10
    xori    $a3, $a3, 0x1
    srl     $a2, $v1, 19
    andi    $a2, $a2, 0xFF
    sltiu   $a2, $a2, 0x1
    or      $a3, $a2, $a3
    beqz    $a3, .L800DC380
    lw      $t0, 0x0($t0)
    jr      $ra
.L800DC380:
    addiu   $t2, $zero, 0x1
    lw      $t1, 0x4($a1)
    andi    $v1, $v1, 0xF
    srl     $t1, $t1, 5
    andi    $t1, $t1, 0xFF
    sll     $v1, $v1, 8
    addu    $t1, $t1, $v1
    mflo    $t3
    addu    $t1, $t1, $t0
    sb      $t2, 0x0($t1)
    addu    $v1, $t3, $a0
    addiu   $v1, $v1, 0x2F0
    sll     $t2, $v0, 2
    addu    $t2, $t2, $a0
    sw      $v1, 0x430($t2)
    addiu   $v0, $v0, 0x1
    sw      $v0, 0x470($a0)
    bgez    $zero, func_800DC2E0
    addu    $a0, $v1, $zero
endlabel func_800DC344

glabel func_800DC3CC
    lw      $a2, 0x470($a0)
    addu    $a1, $zero, $zero
    addiu   $a0, $a0, 0x430
    bnez    $a2, L800E6958
    addi    $a2, $a2, -0x1 /* handwritten instruction */
    jr      $ra
    nop
endlabel func_800DC3CC

glabel func_800DC3E8
    lw      $t0, 0x18($a0)
    addiu   $a2, $zero, 0x528
    lw      $t1, 0x1C($a0)
    addu    $v0, $a1, $zero
    lui     $t4, (0x800490B0 >> 16)
    lw      $t2, 0x948($a0)
    ori     $t4, $t4, (0x800490B0 & 0xFFFF)
    lw      $t3, 0x30($a0)
    sw      $t0, 0x18($a1)
    sw      $t1, 0x1C($a1)
    sw      $t2, 0x948($a1)
    sw      $t3, 0x30($a1)
    addiu   $a1, $a0, 0x398
    jr      $t4
    addiu   $a0, $v0, 0x398
endlabel func_800DC3E8
