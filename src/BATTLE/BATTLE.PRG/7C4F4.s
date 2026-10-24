.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: reserved register usage
glabel func_800E4CF4
    lw      $t0, 0x4($a1)
    lui     $v0, %hi(D_800F5878)
    addiu   $v0, $v0, %lo(D_800F5878)
    sll     $v1, $a2, 2
    addu    $v0, $v0, $v1
    srl     $t1, $t0, 5
    lw      $at, 0x10($a1)
    andi    $t1, $t1, 0xFF
    addiu   $t2, $zero, 0x34
    mult    $t1, $t2
    addu    $v1, $a0, $v1
    lw      $v0, 0x0($v0)
    andi    $t3, $t0, 0x7
    srl     $t4, $t0, 3
    andi    $t4, $t4, 0x3
    beqz    $v0, .L800E4DF0
    lw      $v1, 0x1A4($v1)
    sll     $t3, $t3, 5
    sll     $t4, $t4, 3
    srl     $v1, $v1, 6
    andi    $v1, $v1, 0x3
    lw      $v0, 0x10($v0)
    lui     $t0, %hi(vs_main_actions)
    addiu   $t0, $t0, %lo(vs_main_actions)
    mflo    $t5
    slti    $a3, $v1, 0x2
    bnez    $a3, .L800E4DF0
    addu    $t3, $t3, $t4
    addu    $t5, $t5, $t0
    lhu     $t5, 0xE($t5)
    srl     $t0, $v0, 7
    andi    $t0, $t0, 0x2
    srl     $t2, $v0, 14
    andi    $t2, $t2, 0x4
    or      $t0, $t0, $t2
    slti    $a3, $v1, 0x3
    sll     $t4, $at, 26
    bgez    $t4, .L800E4DAC
    andi    $v0, $v0, 0x1
    or      $v0, $t0, $v0
    beqz    $a3, .L800E4DF0
    sll     $a3, $t5, 23
    bltz    $a3, .L800E4DAC
    srl     $a3, $t5, 9
    and     $a3, $a3, $v0
    beqz    $a3, .L800E4DF0
.L800E4DAC:
    addu    $t3, $t3, $a0
    lw      $t3, 0x230($t3)
    srl     $t0, $at, 4
    andi    $t0, $t0, 0x1
    slti    $t2, $v1, 0x3
    and     $t0, $t0, $t2
    bnez    $t0, .L800E4DF0
    srl     $t3, $t3, 1
    lbu     $a3, 0x88($a0)
    andi    $t3, $t3, 0x1
    sub     $a2, $a2, $a3 /* handwritten instruction */
    sltiu   $a2, $a2, 0x1
    and     $a2, $a2, $t3
    bnez    $a2, .L800E4DF0
    nop
    jr      $ra
    addiu   $v0, $zero, 0x1
.L800E4DF0:
    jr      $ra
    addu    $v0, $zero, $zero
endlabel func_800E4CF4

# hasm: trapping arithmetic
# hasm: unconditional b branch
glabel func_800E4DF8
    lw      $t0, 0x54($a0)
    addiu   $t1, $zero, 0xDC
    addiu   $t2, $zero, 0x4
    addiu   $t3, $zero, 0x34
    mult    $a1, $t1
    lw      $t0, 0x3C($t0)
    sll     $t5, $a1, 2
    addu    $t5, $t5, $a2
    lui     $t4, %hi(vs_main_actions)
    addiu   $t4, $t4, %lo(vs_main_actions)
    sll     $v0, $t5, 2
    addu    $v0, $t0, $v0
    lhu     $v0, 0x8C0($v0)
    lh      $v1, 0x1C($t0)
    mflo    $a3
    lw      $t6, 0x948($t0)
    addu    $a3, $t0, $a3
    mult    $t3, $v0
    lh      $a3, 0x398($a3)
    andi    $t8, $t6, 0x2000
    lw      $t7, 0x18($t0)
    slti    $a3, $a3, 0x2
    bnez    $a3, .L800E4EEC
    andi    $t2, $t7, 0xFFFF
    mflo    $a2
    srl     $t3, $t7, 16
    addu    $a2, $t4, $a2
    lbu     $a3, 0x2($a2)
    addiu   $t7, $zero, 0x1
    addiu   $t9, $zero, 0x4
    lbu     $a2, 0x3($a2)
    srl     $a3, $a3, 1
    andi    $a3, $a3, 0x7
    beqz    $t8, .L800E4E98
    addiu   $t8, $zero, 0x3
    addiu   $t8, $zero, 0x1
    sllv    $t8, $t8, $a3
    andi    $t8, $t8, 0x6
    beqz    $t8, .L800E4EEC
    addiu   $t8, $zero, 0x3
.L800E4E98:
    bne     $a3, $t7, .L800E4EB4
    slt     $a1, $v1, $a2
    bnez    $a1, .L800E4EEC
    andi    $a1, $t6, 0x1000
    bnez    $a1, .L800E4EEC
    nop
    bgez    $zero, .L800E4EE4
.L800E4EB4:
    srl     $t3, $t3, 1
    bne     $a3, $t8, .L800E4ED0
    addu    $t3, $a2, $t3
    slt     $a1, $t2, $t3
    bnez    $a1, .L800E4EEC
    nop
    bgez    $zero, .L800E4EE4
.L800E4ED0:
    lh      $a1, 0x14C($t0)
    bne     $a3, $t9, .L800E4EE4
    slt     $a1, $a1, $a2
    bnez    $a1, .L800E4EEC
    nop
.L800E4EE4:
    bgez    $zero, .L800E4EF0
    addiu   $v0, $zero, 0x1
.L800E4EEC:
    addu    $v0, $zero, $zero
.L800E4EF0:
    sll     $t5, $t5, 3
    addu    $a0, $a0, $t5
    lw      $a2, 0x230($a0)
    sll     $v1, $v0, 7
    addi    $a3, $zero, -0x81 /* handwritten instruction */
    and     $a2, $a2, $a3
    or      $a2, $a2, $v1
    jr      $ra
    sw      $a2, 0x230($a0)
endlabel func_800E4DF8

glabel func_800E4F14
    lw      $t0, 0x54($a0)
    lbu     $t1, 0x17($a0)
    lw      $t0, 0x3C($t0)
    addiu   $v0, $zero, 0x2
    lw      $t2, 0x18($t0)
    addiu   $v1, $zero, 0x2
    andi    $t3, $t2, 0xFFFF
    mult    $v0, $t3
    lw      $t4, 0x1C($t0)
    srl     $t2, $t2, 16
    lui     $t5, (0x90000 >> 16)
    andi    $t6, $t4, 0xFFFF
    lw      $t8, 0x948($t0)
    mflo    $v0
    ori     $t5, $zero, 0xE2B0
    srl     $t4, $t4, 16
    mult    $t6, $v1
    slt     $v0, $v0, $t2
    sb      $v0, 0x12($a0)
    beqz    $t1, .L800E4F7C
    addu    $a3, $zero, $zero
    slt     $a3, $t6, $t1
    mflo    $v1
    bnez    $a3, .L800E4F7C
    nop
    slt     $a3, $v1, $t4
.L800E4F7C:
    sb      $a3, 0x11($a0)
    and     $v0, $t8, $t5
    sltiu   $a3, $v0, 0x1
    beqz    $a3, .L800E4FA4
    sltiu   $t2, $t1, 0x1
    andi    $t3, $t8, 0x1000
    sltiu   $t3, $t3, 0x1
    or      $a3, $t2, $t3
    bnez    $a3, .L800E4FA8
    addu    $a3, $zero, $zero
.L800E4FA4:
    xori    $a3, $a3, 0x1
.L800E4FA8:
    jr      $ra
    sb      $a3, 0x10($a0)
endlabel func_800E4F14
