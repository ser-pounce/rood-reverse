.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800DBD80
    lw      $t4, 0xC($a1)
    addu    $t7, $ra, $zero
    srl     $v0, $t4, 19
    andi    $v0, $v0, 0xFF
    beqz    $v0, .L800DBEF0
    lui     $v1, %hi(D_800F58BC)
    lw      $v1, %lo(D_800F58BC)($v1)
    lw      $v0, 0x4($a1)
    lhu     $v1, 0x18($v1)
    srl     $v0, $v0, 13
    andi    $v0, $v0, 0xFFFF
    sltu    $v0, $v1, $v0
    bnez    $v0, .L800DBEF0
    nop
    jal     func_800DBCB4
    nop
    beqz    $v0, .L800DBEF0
    andi    $v0, $t4, 0xF
    sll     $v0, $v0, 2
    addu    $t0, $v0, $a0
    lw      $t5, 0x1E4($t0)
    lui     $v1, %hi(D_800F45E0)
    addiu   $v1, $v1, %lo(D_800F45E0)
    addu    $v1, $v1, $v0
    lw      $v1, 0x0($v1)
    nop
    beqz    $v1, .L800DBE28
    addu    $v1, $v0, $zero
    lui     $v0, (0x19000 >> 16)
    ori     $v0, $v0, (0x19000 & 0xFFFF)
    slt     $v0, $v0, $t5
    bnez    $v0, .L800DBEF0
    nop
    lbu     $t1, 0x13($a0)
    nop
    bnez    $t1, .L800DBEF0
    addu    $t6, $a1, $zero
    jal     func_800DBCEC
    srl     $a1, $v1, 2
    addu    $a1, $t6, $zero
    bnez    $v0, .L800DBEF0
    nop
.L800DBE28:
    lw      $t0, 0x8($a1)
    andi    $v0, $t4, 0xF
    sll     $v0, $v0, 2
    addu    $t6, $a0, $v0
    lw      $t6, 0x1A4($t6)
    slt     $v0, $t0, $t5
    bnez    $v0, .L800DBEF0
    addu    $t9, $a1, $zero
    jal     vs_gte_rsqrt
    addu    $a0, $t0, $zero
    addu    $a1, $t9, $zero
    lw      $t9, 0x10($t9)
    nop
    sll     $v1, $t9, 10
    srl     $v1, $v1, 16
    addu    $v0, $v1, $zero
    mult    $v0, $v0
    blez    $v0, .L800DBE88
    sll     $v1, $t9, 30
    mflo    $v0
    bgez    $v1, .L800DBE88
    slt     $v1, $t5, $v0
    bnez    $v1, .L800DBEF0
    nop
.L800DBE88:
    bgez    $t6, .L800DBEF0
    lui     $v1, %hi(D_800F4538)
    addiu   $v1, $v1, %lo(D_800F4538)
    lw      $v1, 0x0($v1)
    sll     $a0, $t9, 29
    srl     $a0, $a0, 31
    lbu     $v1, 0xA($v1)
    srl     $a1, $t6, 2
    andi    $a1, $a1, 0x1
    andi    $t0, $v1, 0x7
    bnez    $t0, .L800DBEF0
    andi    $t0, $v1, 0x18
    addiu   $v1, $zero, 0x8
    beq     $t0, $v1, .L800DBEF0
    or      $a0, $a0, $a1
    beqz    $a0, .L800DBEF0
    srl     $a0, $t9, 3
    andi    $a0, $a0, 0x1
    srl     $a1, $t6, 27
    andi    $a1, $a1, 0x1
    xori    $a1, $a1, 0x1
    or      $a0, $a0, $a1
    beqz    $a0, .L800DBEF0
    nop
    bgez    $zero, .L800DBEF4
    addiu   $v0, $zero, 0x1
.L800DBEF0:
    addu    $v0, $zero, $zero
.L800DBEF4:
    addu    $ra, $t7, $zero
    jr      $ra
    nop
endlabel func_800DBD80
