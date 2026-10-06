.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800E45D4
    lui     $a1, (0x1F8003F8 >> 16)
    lh      $t0, (0x1F8003F8 & 0xFFFF)($a1)
    lw      $t1, (0x1F8003FC & 0xFFFF)($a1)
    addiu   $a0, $a0, -0x1
    add     $t0, $t0, $t1 /* handwritten instruction */
    sw      $t0, (0x1F8003F8 & 0xFFFF)($a1)
    jr      $ra
    and     $v0, $t0, $a0
endlabel func_800E45D4

glabel func_800E45F4
    sll     $t0, $a0, 24
    srl     $t0, $t0, 24
    sll     $t1, $a0, 8
    srl     $t1, $t1, 24
endlabel func_800E45F4

glabel func_800E4604
    sll     $t2, $a1, 24
    srl     $t2, $t2, 24
    sll     $t3, $a1, 8
    srl     $t3, $t3, 24
    sub     $a0, $t0, $t2 /* handwritten instruction */
    sub     $a2, $t1, $t3 /* handwritten instruction */
    bgez    $zero, func_800E4660
    addu    $a1, $zero, $zero
endlabel func_800E4604

glabel func_800E4624
    lw      $t6, 0x0($a0)
    lh      $t2, 0x4($a0)
    sll     $t0, $t6, 16
    sra     $t0, $t0, 16
    sra     $t1, $t6, 16
    lw      $t6, 0x0($a1)
    lh      $t5, 0x4($a1)
    sll     $t3, $t6, 16
    sra     $t3, $t3, 16
    sra     $t4, $t6, 16
    add     $t1, $t1, $a2 /* handwritten instruction */
    add     $t4, $t4, $a3 /* handwritten instruction */
    sub     $a0, $t0, $t3 /* handwritten instruction */
    sub     $a1, $t1, $t4 /* handwritten instruction */
    sub     $a2, $t2, $t5 /* handwritten instruction */
endlabel func_800E4624

glabel func_800E4660
    mtc2    $a0, $9 /* handwritten instruction */
    mtc2    $a1, $10 /* handwritten instruction */
    mtc2    $a2, $11 /* handwritten instruction */
    nop
    nop
    sqr     0
    mfc2    $a0, $25 /* handwritten instruction */
    mfc2    $a1, $26 /* handwritten instruction */
    mfc2    $a2, $27 /* handwritten instruction */
    addu    $v0, $a0, $a1
    jr      $ra
    add     $v0, $v0, $a2 /* handwritten instruction */
endlabel func_800E4660

glabel func_800E4690
    addiu   $sp, $sp, -0x20
    sw      $t0, 0x0($sp)
    sw      $t1, 0x4($sp)
    sw      $t2, 0x8($sp)
    sw      $t3, 0xC($sp)
    sw      $t4, 0x10($sp)
    sw      $t5, 0x14($sp)
    sw      $v1, 0x18($sp)
    addu    $a3, $ra, $zero
    addu    $t1, $a0, $zero
    addu    $t2, $a1, $zero
    andi    $a0, $a0, 0xFF
    srl     $a1, $t1, 16
    andi    $a1, $a1, 0xFF
    addu    $t3, $a0, $zero
    jal     func_800E4320
    addu    $t4, $a1, $zero
    lui     $a0, (0x1F8003EC >> 16)
    addu    $a0, $a0, $t2
    lb      $t2, (0x1F8003EC & 0xFFFF)($a0)
    sll     $t5, $v0, 17
    sra     $t5, $t5, 17
    sll     $a0, $t2, 30
    sra     $a0, $a0, 30
    sll     $a1, $t2, 26
    sra     $a1, $a1, 30
    add     $a0, $t3, $a0 /* handwritten instruction */
    jal     func_800E4320
    add     $a1, $t4, $a1 /* handwritten instruction */
    sll     $t2, $v0, 17
    sra     $t2, $t2, 17
    srl     $t0, $v0, 31
    bnez    $t0, .L800E473C
    addi    $v0, $zero, 0x1 /* handwritten instruction */
    sub     $t5, $t5, $t2 /* handwritten instruction */
    srl     $a0, $t5, 31
    beqz    $a0, .L800E472C
    nop
    neg     $t5, $t5 /* handwritten instruction */
.L800E472C:
    srl     $a1, $t5, 6
    bnez    $a1, .L800E473C
    addi    $v0, $zero, 0x1 /* handwritten instruction */
    addu    $v0, $zero, $zero
.L800E473C:
    lw      $t0, 0x0($sp)
    lw      $t1, 0x4($sp)
    lw      $t2, 0x8($sp)
    lw      $t3, 0xC($sp)
    lw      $t4, 0x10($sp)
    lw      $t5, 0x14($sp)
    lw      $v1, 0x18($sp)
    addiu   $sp, $sp, 0x20
    jr      $a3
    addu    $ra, $a3, $zero
endlabel func_800E4690

glabel func_800E4764
    lw      $t1, 0x224($a0)
    addiu   $v0, $zero, 0xA
    lbu     $t0, 0x1($a0)
    sll     $t2, $t1, 16
    srl     $t2, $t2, 24
    sll     $t3, $t1, 8
    srl     $t3, $t3, 24
    srl     $t4, $t1, 24
    andi    $t1, $t1, 0xFF
    beqz    $t0, .L800E47AC
.L800E478C:
    andi    $v1, $t1, 0x20
    bnez    $v1, .L800E47D0
    addu    $v1, $t3, $zero
    andi    $v1, $t2, 0x20
    bnez    $v1, .L800E47D0
    addu    $v1, $t4, $zero
    beqz    $t0, .L800E47DC
    addu    $v0, $zero, $zero
.L800E47AC:
    addiu   $v0, $zero, 0x9
    andi    $v1, $t1, 0x10
    bnez    $v1, .L800E47D0
    addu    $v1, $t3, $zero
    andi    $v1, $t2, 0x10
    bnez    $v1, .L800E47D0
    addu    $v1, $t4, $zero
    bgez    $zero, .L800E478C
    addiu   $v0, $zero, 0xA
.L800E47D0:
    sw      $v1, 0x0($a1)
    sw      $v0, 0x0($a2)
    addiu   $v0, $zero, 0x1
.L800E47DC:
    jr      $ra
    nop
endlabel func_800E4764

glabel func_800E47E4
    lbu     $a2, 0xC($a0)
    addu    $t6, $ra, $zero
    bnez    $a2, .L800E4BB4
    addu    $v0, $zero, $zero
    lw      $v0, 0x34($a0)
    andi    $a2, $a1, 0xFF
    sll     $a1, $a1, 8
    srl     $a1, $a1, 24
    andi    $t0, $v0, 0xFF
    sll     $t1, $v0, 8
    srl     $t1, $t1, 24
    lbu     $t2, 0x15C($a0)
    lui     $a3, %hi(D_800F4538)
    addiu   $a3, $a3, %lo(D_800F4538)
    slti    $v0, $t2, 0x10
    bnez    $v0, .L800E4844
    sub     $t9, $a1, $t1 /* handwritten instruction */
    lbu     $v1, 0x88($a0)
    sub     $t8, $a2, $t0 /* handwritten instruction */
    sll     $v1, $v1, 2
    addu    $a3, $a3, $v1
    lw      $a3, 0x0($a3)
    bgez    $zero, .L800E4870
    lhu     $v0, 0x26($a3)
.L800E4844:
    sll     $t2, $t2, 2
    addu    $a3, $a3, $t2
    lw      $a3, 0x0($a3)
    sub     $t8, $a2, $t0 /* handwritten instruction */
    lhu     $t0, 0x1C($a3)
    lhu     $t1, 0x20($a3)
    lhu     $t2, 0x4C($a0)
    lhu     $t3, 0x50($a0)
    subu    $a0, $t2, $t0
    jal     ratan2
    subu    $a1, $t3, $t1
.L800E4870:
    addiu   $a0, $zero, 0xC00
    sub     $a0, $a0, $v0 /* handwritten instruction */
    jal     rcos
    addu    $t7, $a0, $zero
    mult    $v0, $t8
    mflo    $t8
    jal     rsin
    addu    $a0, $t7, $zero
    mult    $v0, $t9
    addu    $ra, $t6, $zero
    mflo    $t9
    add     $v0, $t9, $t8 /* handwritten instruction */
    jr      $ra
    slt     $v0, $v0, $zero
endlabel func_800E47E4

glabel func_800E48A8
    addu    $t3, $a0, $zero
    addu    $t4, $a1, $zero
    addu    $t5, $ra, $zero
    lw      $a3, 0x18C($a0)
    lbu     $t2, 0x155($a0)
    jal     func_800E45D4
    addu    $a0, $a2, $zero
    or      $a3, $t2, $a3
    bnez    $a3, .L800E4BB4
    addu    $ra, $t5, $zero
    slt     $a0, $v0, $a2
    beqz    $a0, .L800E4BB4
    lw      $a1, 0x54($t3)
    addiu   $t0, $zero, 0x1E
    lbu     $t1, 0xB($a1)
    sb      $t0, 0x155($t3)
    andi    $t1, $t1, 0xFC
    or      $t1, $t1, $t4
    jr      $ra
    sb      $t4, 0xB($a1)
endlabel func_800E48A8

glabel func_800E48F8
    lbu     $v0, 0x89($a0)
    addiu   $v1, $zero, 0x1
    bne     $v1, $v0, .L800E4BB4
endlabel func_800E48F8

glabel func_800E4904
    lui     $a1, (0x1F80037C >> 16)
    lbu     $a3, 0xE5($a0)
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x10($sp)
    sw      $s0, 0x14($sp)
    sw      $s1, 0x18($sp)
    addu    $s0, $a0, $zero
    sll     $a3, $a3, 2
    addu    $a0, $a1, $a3
    lw      $a0, (0x1F80037C & 0xFFFF)($a0)
    lui     $a2, %hi(D_800F4538)
    addiu   $a2, $a2, %lo(D_800F4538)
    addu    $a1, $a3, $a2
    lw      $a1, 0x0($a1)
    beqz    $a0, .L800E49D4
    lbu     $a2, 0xA($a1)
    lbu     $a0, 0x5D($a1)
    andi    $a2, $a2, 0x1F
    bnez    $a2, .L800E49A0
    slti    $a3, $a0, 0x2
    beqz    $a3, .L800E4970
    addi    $a0, $a0, -0x2 /* handwritten instruction */
    lh      $a0, 0x1C($a1)
    lh      $a2, 0x20($a1)
    sra     $a0, $a0, 6
    bgez    $zero, .L800E49CC
    sra     $a2, $a2, 6
.L800E4970:
    jal     func_8008E2D4
    addu    $s1, $a0, $zero
    lw      $a1, 0x0($v0)
    lw      $a2, 0x8($v0)
    addiu   $a3, $s0, 0xF4
    jal     func_800DFA54
    addu    $a0, $s1, $zero
    lb      $a0, 0xF4($s0)
    lb      $a2, 0xF6($s0)
    sll     $a0, $a0, 1
    bgez    $zero, .L800E49CC
    sll     $a2, $a2, 1
.L800E49A0:
    lw      $a2, 0x60($a1)
    nop
    andi    $a2, $a2, 0xFF00
    srl     $a2, $a2, 8
    bnez    $a2, .L800E4970
    addi    $a0, $a2, -0x2 /* handwritten instruction */
    lh      $a0, 0x4C($a1)
    lh      $a2, 0x50($a1)
    sra     $a0, $a0, 6
    bgez    $zero, .L800E49CC
    sra     $a2, $a2, 6
.L800E49CC:
    sb      $a0, 0xF4($s0)
    sb      $a2, 0xF6($s0)
.L800E49D4:
    bgez    $zero, .L800E4AFC
endlabel func_800E4904

glabel func_800E49D8
    lui     $t0, (0x1F8003F4 >> 16)
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x10($sp)
    sw      $s0, 0x14($sp)
    sw      $s1, 0x18($sp)
    lw      $t0, (0x1F8003F4 & 0xFFFF)($t0)
    addu    $s0, $a0, $zero
    lw      $a0, 0x34($s0)
    beqz    $t0, .L800E4AF8
    addu    $t9, $a0, $zero
    addu    $t1, $a2, $zero
    jal     func_800E42E0
    addu    $s1, $a1, $zero
    addu    $t2, $v0, $zero
    jal     func_800E4308
    addu    $a0, $s1, $zero
    bltz    $v0, .L800E4AF8
    sll     $a0, $v0, 17
    sra     $a0, $a0, 17
    slt     $a1, $t2, $a0
    beqz    $a1, .L800E4AF8
    addu    $t2, $a0, $zero
    addu    $a0, $a3, $zero
    addi    $t4, $zero, 0x2 /* handwritten instruction */
    beqz    $a0, .L800E4AF8
    addu    $t3, $zero, $zero
    addi    $a0, $a0, -0x1 /* handwritten instruction */
    slt     $a1, $a0, $t4
    beqz    $t4, .L800E4A54
    lui     $t0, (0x1F8003EC >> 16)
    addu    $t4, $a0, $zero
.L800E4A54:
    addu    $t0, $t0, $t1
    lbu     $a0, (0x1F8003EC & 0xFFFF)($t0)
    andi    $t7, $s1, 0xFF
    sll     $t8, $s1, 8
    srl     $t8, $t8, 24
    sll     $t5, $a0, 30
    sra     $t5, $t5, 30
    sll     $t6, $a0, 26
    sra     $t6, $t6, 30
.L800E4A78:
    addu    $a0, $t7, $t5
    jal     func_800E42EC
    addu    $a1, $t8, $t6
    slt     $a2, $v0, $t2
    bnez    $a2, .L800E4AA8
    addu    $t7, $a0, $zero
    addi    $t3, $t3, 0x1 /* handwritten instruction */
    slt     $a2, $t3, $t4
    bnez    $a2, .L800E4A78
    addu    $t8, $a1, $zero
    addu    $t2, $v0, $zero
    bgez    $zero, .L800E4AF8
.L800E4AA8:
    addu    $t8, $a1, $zero
    lui     $a0, (0xFF00FF00 >> 16)
    ori     $a0, $a0, (0xFF00FF00 & 0xFFFF)
    sll     $t8, $t8, 16
    or      $t8, $t7, $t8
    and     $s1, $s1, $a0
    or      $s1, $s1, $t8
    addu    $a0, $s0, $zero
    addu    $a1, $t9, $zero
    addu    $a2, $s1, $zero
    jal     func_800D96C8
    addu    $a3, $t1, $zero
    blez    $v0, .L800E4AF8
    addu    $a0, $s0, $zero
    jal     func_800D954C
    addu    $a1, $s1, $zero
    blez    $v0, .L800E4AF8
    nop
    bgez    $zero, .L800E4AFC
    addu    $v0, $s1, $zero
.L800E4AF8:
    addu    $v0, $zero, $zero
.L800E4AFC:
    lw      $ra, 0x10($sp)
    lw      $s0, 0x14($sp)
    lw      $s1, 0x18($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800E49D8

glabel func_800E4B10
    bgez    $zero, .L800E4B1C
    addi    $a1, $zero, 0xB /* handwritten instruction */
endlabel func_800E4B10

glabel func_800E4B18
    addi    $a1, $zero, 0xC /* handwritten instruction */
.L800E4B1C:
    sw      $zero, 0x228($a0)
    lw      $a2, 0x34($a0)
    j       func_800DEEFC
    sw      $a2, 0x170($a0)
endlabel func_800E4B18

glabel func_800E4B2C
    lbu     $t0, 0x19B($a0)
    lw      $t1, 0x168($a0)
    bnez    $t0, L800DF8A4
    lui     $v0, (0xFF00FF >> 16)
    lw      $t2, 0x34($a0)
    ori     $v0, $v0, (0xFF00FF & 0xFFFF)
    and     $t1, $t1, $v0
    and     $t2, $t2, $v0
    beq     $t1, $t2, func_800E2CCC
    srl     $v1, $t1, 9
    andi    $v0, $t1, 0xFF
    sll     $v0, $v0, 7
    addiu   $v0, $v0, 0x40
    addiu   $v1, $v1, 0x40
    sw      $v0, 0x17C($a0)
    bgez    $zero, func_800E19FC
    sw      $v1, 0x180($a0)
endlabel func_800E4B2C

glabel func_800E4B70
    lbu     $v0, 0x1A($a0)
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x10($sp)
    lui     $ra, (0x800E4BAC >> 16)
    bnez    $v0, func_800E1908
    ori     $ra, $ra, (0x800E4BAC & 0xFFFF)
    lbu     $v0, 0x19B($a0)
    andi    $a1, $a1, 0xFFF
    beqz    $v0, .L800E4B9C
    lui     $v1, (0x1F8003D0 >> 16)
    bgez    $zero, L800DF8A4
.L800E4B9C:
    addi    $a2, $zero, 0x1 /* handwritten instruction */
    sb      $a2, 0x2($a0)
    bgez    $zero, func_800E3600
    sb      $zero, (0x1F8003D0 & 0xFFFF)($v1)
    lw      $ra, 0x10($sp)
    addiu   $sp, $sp, 0x20
.L800E4BB4:
    jr      $ra
endlabel func_800E4B70

glabel func_800E4BB8
    addi    $a3, $zero, -0xFE2 /* handwritten instruction */
    lb      $a2, 0x23($a0)
    lw      $a1, 0x190($a0)
    beqz    $a2, .L800E4BD0
    and     $a1, $a1, $a3
    ori     $a1, $a1, 0x3C0
.L800E4BD0:
    jr      $ra
    sw      $a1, 0x190($a0)
endlabel func_800E4BB8

glabel func_800E4BD8
    bgez    $zero, .L800E4BE4
    addiu   $a3, $zero, 0x1
endlabel func_800E4BD8

glabel func_800E4BE0
    addu    $a3, $zero, $zero
.L800E4BE4:
    lui     $a1, %hi(D_800F58BC)
    lw      $a1, %lo(D_800F58BC)($a1)
    addi    $v1, $zero, -0x1 /* handwritten instruction */
    beqz    $a1, .L800E4BB4
    addiu   $v0, $zero, 0x1
    beqz    $a3, .L800E4C04
    sllv    $v0, $v0, $a0
    sub     $v0, $v1, $v0 /* handwritten instruction */
.L800E4C04:
    lbu     $a2, 0xE($a1)
    bltz    $v0, .L800E4C14
    and     $v1, $a2, $v0
    or      $v1, $a2, $v0
.L800E4C14:
    jr      $ra
    sb      $v1, 0xE($a1)
endlabel func_800E4BE0

glabel func_800E4C1C
    addi    $a3, $zero, 0x1 /* handwritten instruction */
    bgez    $zero, .L800E4C30
    ori     $a2, $zero, 0x80
endlabel func_800E4C1C

glabel func_800E4C28
    addu    $a3, $zero, $zero
    ori     $a2, $zero, 0xFF7F
.L800E4C30:
    lui     $t0, %hi(D_800F58B8)
    lw      $t0, %lo(D_800F58B8)($t0)
    sll     $a1, $a1, 6
    beqz    $t0, .L800E4BB4
    sll     $a0, $a0, 1
    addu    $a0, $a0, $a1
    addu    $t0, $t0, $a0
    lhu     $t1, 0x0($t0)
    bnez    $a3, .L800E4C5C
    or      $t2, $t1, $a2
    and     $t2, $t1, $a2
.L800E4C5C:
    jr      $ra
    sh      $t2, 0x0($t0)
endlabel func_800E4C28

glabel func_800E4C64
    beqz    $a0, .L800E4BB4
    lui     $a1, %hi(D_800F5878)
    addiu   $a1, $a1, %lo(D_800F5878)
    sll     $a0, $a0, 2
    addu    $a0, $a0, $a1
    lw      $a0, 0x0($a0)
    nop
    beqz    $a0, .L800E4BB4
    addiu   $a1, $zero, 0x1E
    sb      $a1, 0x13F($a0)
endlabel func_800E4C64

glabel func_800E4C8C
    lui     $a1, %hi(D_800F4538)
    addiu   $a1, $a1, %lo(D_800F4538)
    lw      $v0, 0x470($a0)
    lbu     $t0, 0x19($a0)
    blez    $v0, .L800E4CE4
    lw      $a2, 0x430($a0)
    addiu   $v1, $zero, 0x384
    lw      $a2, 0xC($a2)
    lw      $a3, 0x34($a0)
    andi    $a2, $a2, 0xF
    sll     $v0, $a2, 24
    bnez    $t0, .L800E4CE4
    sll     $a2, $a2, 2
    sll     $a3, $a3, 8
    addu    $a2, $a1, $a2
    lw      $a2, 0x0($a2)
    srl     $a3, $a3, 8
    or      $v0, $v0, $a3
    sw      $v0, 0x38($a0)
    lw      $a2, 0x5C($a2)
    sh      $v1, 0x40($a0)
    sw      $a2, 0x3C($a0)
.L800E4CE4:
    jr      $ra
endlabel func_800E4C8C
