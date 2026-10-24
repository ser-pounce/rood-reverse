.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_800DEEFC
    sll     $a3, $a1, 2
    lui     $a2, (0x1F8003C8 >> 16)
    sw      $a1, (0x1F8003C8 & 0xFFFF)($a2)
    lw      $a1, 0x54($a0)
    lui     $a2, %hi(jtbl_800F16F8)
    addiu   $a2, $a2, %lo(jtbl_800F16F8)
    addu    $a2, $a2, $a3
    lw      $a2, 0x0($a2)
    lb      $a3, 0x15C($a0)
    addiu   $v0, $zero, 0x80
    sb      $v0, 0x8($a1)
    jr      $a2
    sb      $a3, 0xA($a1)
    addu    $t9, $ra, $zero
    addu    $t8, $a0, $zero
    addu    $t7, $a1, $zero
    lw      $t0, 0x34($a0)
    lw      $t1, 0x168($a0)
    andi    $a0, $t0, 0xFF
    srl     $a1, $t0, 8
    sll     $a1, $a1, 24
    andi    $a2, $t1, 0xFF
    srl     $a3, $t1, 8
    sll     $a3, $a3, 24
    sub     $a0, $a0, $a2 /* handwritten instruction */
    jal     ratan2
    sub     $a1, $a1, $a3 /* handwritten instruction */
    addu    $ra, $t9, $zero
    addu    $a0, $t8, $zero
    addu    $a1, $t7, $zero
    bgez    $zero, .L800DEF8C
    addu    $a2, $v0, $zero
    bgez    $zero, .L800DEF8C
    lh      $a2, 0x188($a0)
    bgez    $zero, .L800DEF8C
    sll     $a2, $a2, 9
.L800DEF8C:
    addiu   $sp, $sp, -0x44
    sw      $s7, 0x38($sp)
    sw      $s0, 0x34($sp)
    sw      $s1, 0x30($sp)
    sw      $s2, 0x2C($sp)
    sw      $s3, 0x28($sp)
    sw      $s4, 0x24($sp)
    sw      $s5, 0x20($sp)
    sw      $s6, 0x1C($sp)
    sw      $ra, 0x18($sp)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    lw      $a3, 0x34($s0)
    lhu     $s2, 0x92($s0)
    andi    $s4, $a3, 0xFF
    sll     $s5, $a3, 8
    srl     $s5, $s5, 24
    andi    $a2, $a2, 0xFFF
    sh      $a2, 0xC($s1)
    addi    $a0, $zero, 0xC00 /* handwritten instruction */
    sub     $a2, $a0, $a2 /* handwritten instruction */
    lbu     $a0, 0x1($s0)
    andi    $a2, $a2, 0xFFF
    lw      $v0, 0x224($s0)
    beqz    $a0, .L800DF00C
    lhu     $s6, 0x4C($s0)
    andi    $a0, $v0, 0x84
    bnez    $a0, .L800DF034
    srl     $t9, $v0, 16
    andi    $a0, $v0, 0x8400
    bnez    $a0, .L800DF034
    srl     $t9, $v0, 24
.L800DF00C:
    andi    $a0, $v0, 0x42
    bnez    $a0, .L800DF040
    srl     $t9, $v0, 16
    lui     $at, (0x420000 >> 16)
    and     $a0, $v0, $at
    bnez    $a0, .L800DF040
    srl     $t9, $v0, 24
    addi    $v1, $zero, 0x2 /* handwritten instruction */
    bgez    $zero, .L800DF408
    sb      $v1, 0x9($s1)
.L800DF034:
    addi    $v1, $zero, 0xA /* handwritten instruction */
    bgez    $zero, .L800DF048
    sb      $v1, 0x9($s1)
.L800DF040:
    addi    $v1, $zero, 0x9 /* handwritten instruction */
    sb      $v1, 0x9($s1)
.L800DF048:
    andi    $t9, $t9, 0xFF
    addu    $t8, $a2, $zero
    jal     rcos
    addu    $a0, $t8, $zero
    mult    $v0, $t9
    jal     rsin
    addu    $a0, $t8, $zero
    mflo    $a0
    lui     $a3, (0x1F8003F4 >> 16)
    lw      $a3, (0x1F8003F4 & 0xFFFF)($a3)
    mult    $v0, $t9
    sra     $t0, $a0, 12
    add     $t0, $s6, $t0 /* handwritten instruction */
    mflo    $a1
    lhu     $s7, 0x50($s0)
    sra     $t1, $a1, 12
    add     $t1, $s7, $t1 /* handwritten instruction */
    sll     $a1, $t1, 16
    or      $s3, $t0, $a1
    sub     $a0, $t0, $s2 /* handwritten instruction */
    sra     $a0, $a0, 7
    sub     $a0, $a0, $s4 /* handwritten instruction */
    addi    $t6, $a0, 0x1 /* handwritten instruction */
    sub     $a0, $t1, $s2 /* handwritten instruction */
    sra     $a0, $a0, 7
    sub     $a0, $a0, $s5 /* handwritten instruction */
    addi    $t7, $a0, 0x1 /* handwritten instruction */
    add     $a0, $t0, $s2 /* handwritten instruction */
    sra     $a0, $a0, 7
    sub     $a0, $a0, $s4 /* handwritten instruction */
    addi    $t8, $a0, 0x1 /* handwritten instruction */
    add     $a0, $t1, $s2 /* handwritten instruction */
    sra     $a0, $a0, 7
    sub     $a0, $a0, $s5 /* handwritten instruction */
    addi    $t9, $a0, 0x1 /* handwritten instruction */
    beqz    $a3, .L800DF2C4
    lui     $a0, (0x1F8003E0 >> 16)
    lbu     $a2, (0x1F8003DC & 0xFFFF)($a0)
    lw      $a3, (0x1F8003BC & 0xFFFF)($a0)
    mult    $a2, $s5
    sll     $t0, $t7, 2
    addu    $t0, $a0, $t0
    mflo    $a2
    lw      $a1, (0x1F8003C4 & 0xFFFF)($a0)
    addu    $t0, $t0, $t6
    addu    $a1, $a1, $a2
    addu    $a1, $a1, $s4
    lbu     $a1, 0x0($a1)
    lb      $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll     $t1, $s5, 6
    bltz    $t0, .L800DF16C
    sll     $t2, $s4, 1
    add     $t1, $t1, $t2 /* handwritten instruction */
    add     $t1, $t1, $a3 /* handwritten instruction */
    lhu     $t1, 0x0($t1)
    add     $t2, $s5, $t7 /* handwritten instruction */
    addi    $t2, $t2, -0x1 /* handwritten instruction */
    sll     $t2, $t2, 6
    add     $t3, $s4, $t6 /* handwritten instruction */
    addi    $t3, $t3, -0x1 /* handwritten instruction */
    sll     $t3, $t3, 1
    add     $t2, $t2, $t3 /* handwritten instruction */
    add     $t2, $t2, $a3 /* handwritten instruction */
    lhu     $t2, 0x0($t2)
    srl     $t1, $t1, 10
    andi    $t1, $t1, 0x7
    srl     $t2, $t2, 10
    andi    $t2, $t2, 0x7
    slt     $t4, $t1, $t2
    srlv    $t3, $a1, $t0
    andi    $t3, $t3, 0x1
    or      $t3, $t3, $t4
    bnez    $t3, .L800DF370
.L800DF16C:
    sll     $t0, $t9, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t6
    lb      $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll     $t1, $s5, 6
    bltz    $t0, .L800DF1DC
    sll     $t2, $s4, 1
    add     $t1, $t1, $t2 /* handwritten instruction */
    add     $t1, $t1, $a3 /* handwritten instruction */
    lhu     $t1, 0x0($t1)
    add     $t2, $s5, $t9 /* handwritten instruction */
    addi    $t2, $t2, -0x1 /* handwritten instruction */
    sll     $t2, $t2, 6
    add     $t3, $s4, $t6 /* handwritten instruction */
    addi    $t3, $t3, -0x1 /* handwritten instruction */
    sll     $t3, $t3, 1
    add     $t2, $t2, $t3 /* handwritten instruction */
    add     $t2, $t2, $a3 /* handwritten instruction */
    lhu     $t2, 0x0($t2)
    srl     $t1, $t1, 10
    andi    $t1, $t1, 0x7
    srl     $t2, $t2, 10
    andi    $t2, $t2, 0x7
    slt     $t4, $t1, $t2
    srlv    $t3, $a1, $t0
    andi    $t3, $t3, 0x1
    or      $t3, $t3, $t4
    bnez    $t3, .L800DF370
.L800DF1DC:
    sll     $t0, $t7, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t8
    lb      $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll     $t1, $s5, 6
    bltz    $t0, .L800DF24C
    sll     $t2, $s4, 1
    add     $t1, $t1, $t2 /* handwritten instruction */
    add     $t1, $t1, $a3 /* handwritten instruction */
    lhu     $t1, 0x0($t1)
    add     $t2, $s5, $t7 /* handwritten instruction */
    addi    $t2, $t2, -0x1 /* handwritten instruction */
    sll     $t2, $t2, 6
    add     $t3, $s4, $t8 /* handwritten instruction */
    addi    $t3, $t3, -0x1 /* handwritten instruction */
    sll     $t3, $t3, 1
    add     $t2, $t2, $t3 /* handwritten instruction */
    add     $t2, $t2, $a3 /* handwritten instruction */
    lhu     $t2, 0x0($t2)
    srl     $t1, $t1, 10
    andi    $t1, $t1, 0x7
    srl     $t2, $t2, 10
    andi    $t2, $t2, 0x7
    slt     $t4, $t1, $t2
    srlv    $t3, $a1, $t0
    andi    $t3, $t3, 0x1
    or      $t3, $t3, $t4
    bnez    $t3, .L800DF370
.L800DF24C:
    sll     $t0, $t9, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t8
    lb      $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll     $t1, $s5, 6
    bltz    $t0, .L800DF408
    sll     $t2, $s4, 1
    add     $t1, $t1, $t2 /* handwritten instruction */
    add     $t1, $t1, $a3 /* handwritten instruction */
    lhu     $t1, 0x0($t1)
    add     $t2, $s5, $t9 /* handwritten instruction */
    addi    $t2, $t2, -0x1 /* handwritten instruction */
    sll     $t2, $t2, 6
    add     $t3, $s4, $t8 /* handwritten instruction */
    addi    $t3, $t3, -0x1 /* handwritten instruction */
    sll     $t3, $t3, 1
    add     $t2, $t2, $t3 /* handwritten instruction */
    add     $t2, $t2, $a3 /* handwritten instruction */
    lhu     $t2, 0x0($t2)
    srl     $t1, $t1, 10
    andi    $t1, $t1, 0x7
    srl     $t2, $t2, 10
    andi    $t2, $t2, 0x7
    slt     $t4, $t1, $t2
    srlv    $t3, $a1, $t0
    andi    $t3, $t3, 0x1
    or      $t3, $t3, $t4
    bnez    $t3, .L800DF370
    nop
    bgez    $zero, .L800DF408
.L800DF2C4:
    sll     $t0, $t7, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t6
    lb      $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw      $a0, 0x34($s0)
    bltz    $a1, .L800DF2EC
    nop
    jal     func_800E4690
    nop
    bnez    $v0, .L800DF370
.L800DF2EC:
    lui     $a0, (0x1F8003E0 >> 16)
    sll     $t0, $t9, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t6
    lb      $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw      $a0, 0x34($s0)
    bltz    $a1, .L800DF318
    nop
    jal     func_800E4690
    nop
    bnez    $v0, .L800DF370
.L800DF318:
    lui     $a0, (0x1F8003E0 >> 16)
    sll     $t0, $t7, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t8
    lb      $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw      $a0, 0x34($s0)
    bltz    $a1, .L800DF344
    nop
    jal     func_800E4690
    nop
    bnez    $v0, .L800DF370
.L800DF344:
    lui     $a0, (0x1F8003E0 >> 16)
    sll     $t0, $t9, 2
    addu    $t0, $a0, $t0
    addu    $t0, $t0, $t8
    lb      $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw      $a0, 0x34($s0)
    bltz    $a1, .L800DF408
    nop
    jal     func_800E4690
    nop
    beqz    $v0, .L800DF408
.L800DF370:
    sll     $t0, $s4, 7
    sll     $t1, $s5, 7
    addiu   $t0, $t0, 0x40
    addiu   $t1, $t1, 0x40
    andi    $t2, $s3, 0xFFFF
    srl     $t3, $s3, 16
    slt     $a0, $t2, $t0
    bnez    $a0, .L800DF39C
    addi    $t8, $t0, 0x3F /* handwritten instruction */
    bgez    $zero, .L800DF3A4
    sub     $t8, $t8, $s2 /* handwritten instruction */
.L800DF39C:
    addi    $t8, $t0, -0x40 /* handwritten instruction */
    add     $t8, $t8, $s2 /* handwritten instruction */
.L800DF3A4:
    sub     $t8, $t8, $s6 /* handwritten instruction */
    slt     $a0, $t3, $t1
    bnez    $a0, .L800DF3BC
    addi    $t9, $t1, 0x3F /* handwritten instruction */
    bgez    $zero, .L800DF3C4
    sub     $t9, $t9, $s2 /* handwritten instruction */
.L800DF3BC:
    addi    $t9, $t1, -0x40 /* handwritten instruction */
    add     $t9, $t9, $s2 /* handwritten instruction */
.L800DF3C4:
    sub     $t9, $t9, $s7 /* handwritten instruction */
    or      $a0, $t8, $t9
    lw      $a1, 0x9C($s0)
    beqz    $a0, .L800DF408
    lui     $a3, (0xFF00FF >> 16)
    ori     $a3, $a3, (0xFF00FF & 0xFFFF)
    and     $a2, $a1, $a3
    sll     $t0, $s5, 16
    or      $t0, $t0, $s4
    beq     $t0, $a2, .L800DF408
    addiu   $a0, $zero, 0xD
    sw      $t0, 0x9C($s0)
    sb      $a0, 0x9($s1)
    sll     $t9, $t9, 12
    sll     $t8, $t8, 12
    sw      $t8, 0xC($s1)
    sw      $t9, 0x10($s1)
.L800DF408:
    lw      $ra, 0x18($sp)
    lw      $s7, 0x38($sp)
    lw      $s0, 0x34($sp)
    lw      $s1, 0x30($sp)
    lw      $s2, 0x2C($sp)
    lw      $s3, 0x28($sp)
    lw      $s4, 0x24($sp)
    lw      $s5, 0x20($sp)
    lw      $s6, 0x1C($sp)
    jr      $ra
    addiu   $sp, $sp, 0x44
alabel func_800DF434
    addiu   $a2, $zero, 0x14
    jr      $ra
    sb      $a2, 0x9($a1)
alabel func_800DF440
    addiu   $a2, $zero, 0x1
    jr      $ra
    sb      $a2, 0x9($a1)
alabel func_800DF44C
    addiu   $a2, $zero, 0x2
    jr      $ra
    sb      $a2, 0x9($a1)
alabel func_800DF458
    lw      $a3, 0x170($a0)
    addiu   $a2, $zero, 0x15
    sw      $a3, 0xC($a1)
    sb      $a2, 0x9($a1)
    andi    $a0, $a3, 0xFF
    sll     $a1, $a3, 8
    bgez    $zero, func_800E4C1C
    srl     $a1, $a1, 24
    lw      $a3, 0x170($a0)
    addiu   $a2, $zero, 0x16
    addu    $t9, $ra, $zero
    addu    $t7, $a1, $zero
    lh      $t8, 0xBE($a0)
    sb      $a2, 0x9($a1)
    andi    $a0, $a3, 0xFF
    sll     $a0, $a0, 7
    sll     $a1, $a3, 8
    srl     $a1, $a1, 17
    addiu   $t6, $a0, 0x40
    addiu   $a1, $a1, 0x40
    jal     func_800E42D4
    sh      $a1, 0x10($t7)
    addu    $ra, $t9, $zero
    add     $v0, $v0, $t8 /* handwritten instruction */
    sll     $v0, $v0, 16
    or      $v0, $v0, $t6
    jr      $ra
    sw      $v0, 0xC($t7)
    lhu     $a3, 0xBA($a0)
    lhu     $a0, 0x188($a0)
    sll     $a3, $a3, 16
    addiu   $a2, $zero, 0x3
    andi    $a0, $a0, 0xFFF
    sb      $a2, 0x9($a1)
    or      $a3, $a3, $a0
    jr      $ra
    sw      $a3, 0xC($a1)
.L800DF4EC:
    addiu   $a2, $zero, 0x17
    sb      $a2, 0x9($a1)
    addu    $t5, $ra, $zero
    addu    $t6, $a0, $zero
    lw      $a2, 0x170($t6)
    addu    $t7, $a1, $zero
    mtc2    $a2, $12 /* handwritten instruction */
    sw      $a2, 0xC($t7)
    andi    $a0, $a2, 0xFF
    sll     $a0, $a0, 7
    sll     $a1, $a2, 8
    srl     $a1, $a1, 17
    addiu   $a0, $a0, 0x40
    addu    $t8, $a0, $zero
    addiu   $a1, $a1, 0x40
    addu    $t9, $a1, $zero
    jal     func_800E42D4
    sh      $a1, 0x178($t6)
    sll     $v0, $v0, 16
    or      $v0, $v0, $t8
    sw      $v0, 0x174($t6)
    lhu     $a0, 0x4C($t6)
    lhu     $a1, 0x50($t6)
    sub     $a0, $a0, $t8 /* handwritten instruction */
    jal     ratan2
    sub     $a1, $a1, $t9 /* handwritten instruction */
    addu    $ra, $t5, $zero
    sw      $v0, 0x10($t7)
    mfc2    $a2, $12 /* handwritten instruction */
    sw      $v0, 0x10($t7)
    andi    $a0, $a2, 0xFF
    sll     $a1, $a2, 8
    bgez    $zero, func_800E4C1C
    srl     $a1, $a1, 24
    lw      $t7, 0x17C($a0)
    lw      $t8, 0x184($a0)
    lw      $t9, 0x180($a0)
    addiu   $a2, $zero, 0x13
    sb      $a2, 0x9($a1)
    sw      $t7, 0xC($a1)
    sw      $t8, 0x14($a1)
    jr      $ra
    sw      $t9, 0x10($a1)
    bgez    $zero, .L800DF5A4
    addiu   $a2, $zero, 0x10
    addiu   $a2, $zero, 0x11
.L800DF5A4:
    lw      $t7, 0x17C($a0)
    lw      $t8, 0x184($a0)
    lw      $t9, 0x180($a0)
    sb      $a2, 0x9($a1)
    sll     $t8, $t8, 16
    andi    $t7, $t7, 0xFFFF
    or      $t8, $t8, $t7
    sw      $t8, 0xC($a1)
    jr      $ra
    sh      $t9, 0x10($a1)
    lhu     $a3, 0x188($a0)
    addiu   $a2, $zero, 0x6
    lhu     $t9, 0x13A($a0)
    andi    $a3, $a3, 0xFFFF
    sll     $t9, $t9, 16
    or      $a3, $a3, $t9
    sb      $a2, 0x9($a1)
    jr      $ra
    sw      $a3, 0xC($a1)
    addu    $t5, $ra, $zero
    addu    $t7, $a0, $zero
    addu    $t8, $a1, $zero
    jal     func_800E42E0
    lw      $a0, 0x34($t7)
    addu    $t6, $v0, $zero
    lw      $t9, 0x170($t7)
    jal     func_800E42E0
    addu    $a0, $t9, $zero
    lhu     $a0, 0xB0($t7)
    sub     $v0, $v0, $t6 /* handwritten instruction */
    bgez    $v0, .L800DF628
    lhu     $a3, 0x15E($t7)
    neg     $v0, $v0 /* handwritten instruction */
.L800DF628:
    slt     $v0, $v0, $a0
    addu    $a0, $t7, $zero
    addu    $a1, $t8, $zero
    addu    $ra, $t5, $zero
    bnez    $v0, .L800DF65C
    andi    $t0, $a3, 0x8
    bnez    $t0, .L800DF4EC
    andi    $v0, $a3, 0x30
    bnez    $v0, .L800DF660
    addiu   $a2, $zero, 0x12
    andi    $t0, $a3, 0xC0
    bnez    $t0, .L800DF660
    addiu   $a2, $zero, 0xE
.L800DF65C:
    addiu   $a2, $zero, 0xB
.L800DF660:
    addu    $a3, $t5, $zero
    sb      $a2, 0x9($t8)
    sw      $t9, 0xC($t8)
    andi    $t3, $t9, 0xFF
    sll     $a0, $t3, 7
    sll     $t4, $t9, 8
    srl     $t4, $t4, 24
    sll     $a1, $t4, 7
    addiu   $a0, $a0, 0x40
    addu    $t6, $a0, $zero
    addiu   $a1, $a1, 0x40
    jal     func_800E42D4
    sh      $a1, 0x178($t7)
    sll     $v0, $v0, 16
    or      $v0, $v0, $t6
    sw      $v0, 0x174($t7)
    lbu     $t6, 0x1($t7)
    addu    $ra, $a3, $zero
    lw      $v0, 0x224($t7)
    beqz    $t6, .L800DF6C8
    andi    $v1, $v0, 0x84
    bnez    $v1, .L800DF6EC
    srl     $t6, $v0, 16
    andi    $v1, $v0, 0x8400
    bnez    $v1, .L800DF6EC
    srl     $t6, $v0, 24
.L800DF6C8:
    andi    $v1, $v0, 0x42
    bnez    $v1, .L800DF6EC
    srl     $t6, $v0, 16
    andi    $v1, $v0, 0x4200
    bnez    $v1, .L800DF6EC
    srl     $t6, $v0, 24
    addu    $a0, $t7, $zero
    bgez    $zero, func_800DF44C
    addu    $a1, $t8, $zero
.L800DF6EC:
    andi    $t6, $t6, 0xFF
    sw      $t6, 0x10($t8)
    lw      $v0, 0x4($t8)
    andi    $v1, $t9, 0xFF00
    beqz    $v0, .L800DF70C
    addu    $a0, $t3, $zero
    beqz    $v1, func_800E4C1C
    addu    $a1, $t4, $zero
.L800DF70C:
    jr      $ra
    nop
    addiu   $a2, $zero, 0x8
    jr      $ra
    sb      $a2, 0x9($a1)
    lw      $t9, 0x58($a0)
    lhu     $a3, 0x18A($a0)
    lh      $v0, 0x26($t9)
    lh      $v1, 0x14($t9)
    andi    $a3, $a3, 0xFFF
    addu    $t1, $v1, $v0
    sub     $t2, $a3, $t1 /* handwritten instruction */
    andi    $t2, $t2, 0xFFF
    slti    $t3, $t2, 0x800
    bnez    $t3, .L800DF75C
    lbu     $t4, 0x2A($a0)
    addi    $t3, $zero, -0x1 /* handwritten instruction */
    addi    $t5, $zero, -0x320 /* handwritten instruction */
    slt     $t6, $t5, $v1
    bgez    $zero, .L800DF768
.L800DF75C:
    addi    $t5, $zero, 0x320 /* handwritten instruction */
    slt     $t6, $v1, $t5
    addi    $t3, $zero, 0x1 /* handwritten instruction */
.L800DF768:
    and     $t4, $t4, $t6
    bnez    $t4, .L800DF778
    addiu   $a2, $zero, 0x7
    addiu   $a2, $zero, 0x3
.L800DF778:
    lhu     $t4, 0x13A($a0)
    addi    $t7, $zero, 0x1000 /* handwritten instruction */
    sb      $a2, 0x9($a1)
    sub     $t7, $t7, $t2 /* handwritten instruction */
    slti    $t0, $t2, 0x1
    slt     $t6, $t2, $t4
    slt     $t5, $t7, $t4
    or      $t7, $t5, $t6
    or      $t7, $t7, $t0
    beqz    $t7, .L800DF7C8
    nop
    addiu   $t7, $zero, 0x4
    sb      $t7, 0x9($a1)
    bgez    $zero, .L800DF7E0
    addu    $a0, $a3, $zero
    addi    $t0, $zero, 0x3 /* handwritten instruction */
    beq     $a2, $t0, .L800DF7E0
    sub     $a0, $a3, $v1 /* handwritten instruction */
    bgez    $zero, .L800DF7E0
    sub     $a0, $a3, $v0 /* handwritten instruction */
.L800DF7C8:
    mult    $t3, $t4
    addi    $t0, $zero, 0x3 /* handwritten instruction */
    mflo    $t2
    beq     $a2, $t0, .L800DF7E0
    add     $a0, $t2, $v0 /* handwritten instruction */
    add     $a0, $t2, $v1 /* handwritten instruction */
.L800DF7E0:
    andi    $a0, $a0, 0xFFFF
    sll     $t4, $t4, 16
    or      $a0, $a0, $t4
    jr      $ra
    sw      $a0, 0xC($a1)
    lw      $t0, 0x22C($a0)
    lui     $v1, %hi(D_800F4538)
    addiu   $v1, $v1, %lo(D_800F4538)
    lw      $t1, 0x4($t0)
    addiu   $t9, $zero, 0x18
    srl     $a2, $t1, 3
    andi    $a2, $a2, 0x3
    andi    $a3, $t1, 0x7
    sll     $t1, $a2, 16
    or      $t1, $t1, $a3
    sll     $a3, $a3, 5
    sll     $a2, $a2, 3
    add     $a3, $a3, $a2 /* handwritten instruction */
    add     $a3, $a3, $a0 /* handwritten instruction */
    lw      $a2, 0x230($a3)
    sw      $t1, 0xC($a1)
    srl     $a2, $a2, 3
    andi    $a2, $a2, 0x3
    addi    $a3, $zero, 0x1 /* handwritten instruction */
    sllv    $a3, $a3, $a2
    andi    $a3, $a3, 0x6
    lw      $t1, 0xC($t0)
    bnez    $a3, .L800DF884
    andi    $t2, $t1, 0xF
    srl     $a3, $t1, 7
    andi    $a3, $a3, 0xFFF
    sll     $t2, $t2, 2
    addu    $v1, $v1, $t2
    lw      $v1, 0x0($v1)
    sll     $a3, $a3, 16
    lw      $v0, 0x1C($v1)
    lhu     $v1, 0x20($v1)
    sub     $v0, $v0, $a3 /* handwritten instruction */
    sw      $v0, 0x10($a1)
    bgez    $zero, .L800DF89C
    sh      $v1, 0x14($a1)
.L800DF884:
    srl     $v0, $t1, 4
    andi    $v0, $v0, 0x7
    sll     $v0, $v0, 16
    andi    $t1, $t1, 0xF
    or      $v0, $v0, $t1
    sw      $v0, 0x10($a1)
.L800DF89C:
    jr      $ra
    sb      $t9, 0x9($a1)
alabel L800DF8A4
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    addu    $s0, $a0, $zero
    sw      $ra, 0x1C($sp)
    sw      $s2, 0x18($sp)
    sw      $s1, 0x14($sp)
    lbu     $v0, 0x35($s0)
    nop
    sltiu   $v0, $v0, 0x2
    beqz    $v0, .L800DF8E4
    addiu   $v0, $zero, -0x1
    lbu     $a0, 0x19B($s0)
    jal     func_800E4BD8
    sw      $v0, 0x19C($s0)
    j       .L800DF990
    sb      $zero, 0x19B($s0)
.L800DF8E4:
    addu    $a0, $s0, $zero
    lw      $a1, 0x19C($s0)
    jal     func_800DFAF8
    addu    $a2, $zero, $zero
    addu    $s1, $v0, $zero
    bltz    $s1, .L800DF988
    lui     $a2, (0xFF00FFFF >> 16)
    ori     $a2, $a2, (0xFF00FFFF & 0xFFFF)
    lui     $a3, (0xFFFF00FF >> 16)
    ori     $a3, $a3, (0xFFFF00FF & 0xFFFF)
    lui     $v0, %hi(D_800F5910)
    lw      $v1, %lo(D_800F5910)($v0)
    sll     $v0, $s1, 2
    addu    $a0, $s0, $zero
    addu    $v0, $v0, $v1
    lhu     $v1, 0x0($v0)
    addiu   $v0, $zero, -0x100
    and     $v0, $s2, $v0
    andi    $a1, $v1, 0x1F
    or      $v0, $v0, $a1
    srl     $v1, $v1, 5
    andi    $v1, $v1, 0x1F
    sll     $v1, $v1, 16
    and     $v0, $v0, $a2
    or      $v0, $v0, $v1
    and     $s2, $v0, $a3
    jal     func_800D954C
    addu    $a1, $s2, $zero
    blez    $v0, .L800DF988
    sra     $a0, $s1, 1
    addiu   $a0, $a0, 0x2
    addiu   $v0, $zero, -0x1
    sw      $v0, 0x19C($s0)
    jal     func_800E4BD8
    sb      $zero, 0x19B($s0)
    addu    $a0, $s0, $zero
    addiu   $a1, $zero, 0xE
    jal     func_800DEEFC
    sw      $s2, 0x170($a0)
    j       .L800DF990
    nop
.L800DF988:
    jal     func_800E2CCC
    addu    $a0, $s0, $zero
.L800DF990:
    lw      $ra, 0x1C($sp)
    lw      $s2, 0x18($sp)
    lw      $s1, 0x14($sp)
    lw      $s0, 0x10($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800DEEFC
