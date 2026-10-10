.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800B396C
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    lw      $t2, 0x8($a0)
    lw      $t3, 0xC($a0)
    lw      $t4, 0x0($a1)
    sll     $t7, $t0, 16
    sra     $t7, 16
    sra     $t8, $t1, 16
    sll     $t9, $t3, 16
    sra     $t9, 16
    mtc2    $t4, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t9, $11
    sra     $t7, $t0, 16
    sra     $t9, $t3, 16
    gpf     1
    lw      $t5, 0x4($a1)
    sll     $t8, $t2, 16
    sra     $t8, 16
    addu    $v0, $zero, $a0
    mfc2    $v1, $9
    mfc2    $a2, $10
    mfc2    $a3, $11
    mtc2    $t5, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t9, $11
    sll     $t7, $t1, 16
    sra     $t7, 16
    gpf     1
    lh      $t4, 0x10($a0)
    lw      $t6, 0x8($a1)
    sra     $t8, $t2, 16
    and     $v1, 0xFFFF
    and     $a3, 0xFFFF
    mfc2    $t1, $9
    mfc2    $t2, $10
    mfc2    $t3, $11
    mtc2    $t6, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t4, $11
    sll     $a2, 16
    sll     $t1, 16
    gpf     1
    and     $t2, 0xFFFF
    sll     $t3, 16
    or      $t1, $v1
    sw      $t1, 0x0($v0)
    or      $t3, $a3
    mfc2    $t4, $9
    mfc2    $t5, $10
    mfc2    $t6, $11
    and     $t4, 0xFFFF
    or      $t4, $a2
    sll     $t5, 16
    or      $t5, $t2
    sw      $t4, 0x4($v0)
    sw      $t5, 0x8($v0)
    sw      $t3, 0xC($v0)
    j       $ra
    sh      $t6, 0x10($v0)
endlabel func_800B396C

glabel func_800B3A68
    or      $t0, $a3, $zero
    lui     $a3, (0x1F800378 >> 16)
    sw      $s0, (0x1F800358 & 0xFFFF)($a3)
    sw      $s1, (0x1F80035C & 0xFFFF)($a3)
    sw      $s2, (0x1F800360 & 0xFFFF)($a3)
    sw      $s3, (0x1F800364 & 0xFFFF)($a3)
    sw      $s4, (0x1F800368 & 0xFFFF)($a3)
    sw      $s5, (0x1F80036C & 0xFFFF)($a3)
    sw      $s6, (0x1F800370 & 0xFFFF)($a3)
    sw      $s7, (0x1F800374 & 0xFFFF)($a3)
    sw      $gp, (0x1F800378 & 0xFFFF)($a3)
    lbu     $a3, 0x1($a0)
    lw      $t2, 0x34($t0)
    lw      $t5, 0x38($t0)
    or      $t6, $zero, $zero
    or      $s6, $t5, $zero
    or      $s7, $zero, $zero
    lw      $s0, 0x0($s6)
    lw      $s1, 0x4($s6)
    lw      $s2, 0x8($s6)
    lw      $s3, 0xC($s6)
    lw      $s4, 0x10($s6)
    lw      $s5, 0x14($s6)
    lw      $t3, 0x0($t2)
    lui     $gp, %hi(D_800F2458)
    addiu   $gp, $gp, %lo(D_800F2458)
.L800B3AD0:
    srl     $t4, $t3, 16
.L800B3AD4:
    addi    $t4, $t4, -0x1
    andi    $t3, $t3, 0xFFFF
    sll     $t3, $t3, 5
.L800B3AE0:
    add     $t3, $t3, $a1
    lw      $v0, 0x0($t3)
    lw      $v1, 0x4($t3)
    lw      $t8, 0x8($t3)
    lw      $t9, 0xC($t3)
    ctc2    $v0, $0
    ctc2    $v1, $1
    ctc2    $t8, $2
    ctc2    $t9, $3
    lw      $v0, 0x10($t3)
    lw      $v1, 0x14($t3)
    lw      $t8, 0x18($t3)
    lw      $t9, 0x1C($t3)
    ctc2    $v0, $4
    ctc2    $v1, $5
    ctc2    $t8, $6
    ctc2    $t9, $7
    sub     $v0, $t4, $t6
.L800B3B28:
    addi    $v0, $v0, -0x2
    bltz    $v0, .L800B3BD0
    mtc2    $s0, $0
    mtc2    $s1, $1
    mtc2    $s2, $2
    mtc2    $s3, $3
    mtc2    $s4, $4
    mtc2    $s5, $5
    sll     $v0, $t6, 2
    addi    $v1, $v0, 0xC00
    rtpt
    add     $t1, $v0, $gp
    lw      $s0, 0x18($s6)
    lw      $s1, 0x1C($s6)
    lw      $s2, 0x20($s6)
    lw      $s3, 0x24($s6)
    lw      $s4, 0x28($s6)
    lw      $s5, 0x2C($s6)
    addi    $t6, $t6, 0x3
    sub     $v0, $t4, $t6
    bgez    $v0, .L800B3B88
    add     $v1, $v1, $gp
    addi    $t2, $t2, 0x4
    lw      $t3, 0x0($t2)
.L800B3B88:
    mfc2    $t7, $17
    mfc2    $t8, $18
    mfc2    $t9, $19
    or      $s7, $s7, $t7
    sw      $t7, 0x0($v1)
    or      $s7, $s7, $t8
    sw      $t8, 0x4($v1)
    or      $s7, $s7, $t9
    sw      $t9, 0x8($v1)
    swc2    $12, 0x0($t1)
    swc2    $13, 0x4($t1)
    swc2    $14, 0x8($t1)
    bgez    $v0, .L800B3B28
    addi    $s6, $s6, 0x18
    addi    $a3, $a3, -0x1
    beqz    $a3, .L800B3CC0
    srl     $t4, $t3, 16
    j       .L800B3AD4
.L800B3BD0:
    addi    $v0, $v0, 0x1
    bltz    $v0, .L800B3C60
    mtc2    $s0, $0
    mtc2    $s1, $1
    mtc2    $s2, $2
    mtc2    $s3, $3
    sll     $v0, $t6, 2
    addi    $v1, $v0, 0xC00
    rtpt
    add     $v0, $v0, $gp
    add     $v1, $v1, $gp
    or      $s0, $s4, $zero
    or      $s1, $s5, $zero
    lw      $s2, 0x18($s6)
    lw      $s3, 0x1C($s6)
    lw      $s4, 0x20($s6)
    lw      $s5, 0x24($s6)
    addi    $t6, $t6, 0x2
    addi    $t2, $t2, 0x4
    lw      $t3, 0x0($t2)
    addi    $s6, $s6, 0x10
    srl     $t4, $t3, 16
    addi    $t4, $t4, -0x1
    andi    $t3, $t3, 0xFFFF
    mfc2    $t7, $17
    mfc2    $t8, $18
    or      $s7, $s7, $t7
    sw      $t7, 0x0($v1)
    or      $s7, $s7, $t8
    sw      $t8, 0x4($v1)
    swc2    $12, 0x0($v0)
    swc2    $13, 0x4($v0)
    addi    $a3, $a3, -0x1
    beqz    $a3, .L800B3CC0
    sll     $t3, $t3, 5
    j       .L800B3AE0
.L800B3C60:
    mtc2    $s0, $0
    mtc2    $s1, $1
    sll     $v0, $t6, 2
    addi    $v1, $v0, 0xC00
    rtps
    add     $v0, $v0, $gp
    add     $v1, $v1, $gp
    or      $s0, $s2, $zero
    or      $s1, $s3, $zero
    or      $s2, $s4, $zero
    or      $s3, $s5, $zero
    lw      $s4, 0x18($s6)
    lw      $s5, 0x1C($s6)
    addi    $t2, $t2, 0x4
    lw      $t3, 0x0($t2)
    mfc2    $t7, $19
    swc2    $14, 0x0($v0)
    or      $s7, $s7, $t7
    sw      $t7, 0x0($v1)
    addi    $a3, $a3, -0x1
    beqz    $a3, .L800B3CC0
    addi    $s6, $s6, 0x8
    j       .L800B3AD0
    addi    $t6, $t6, 0x1
.L800B3CC0:
    or      $v0, $s7, $zero
    lui     $a3, (0x1F800378 >> 16)
    lw      $s0, (0x1F800358 & 0xFFFF)($a3)
    lw      $s1, (0x1F80035C & 0xFFFF)($a3)
    lw      $s2, (0x1F800360 & 0xFFFF)($a3)
    lw      $s3, (0x1F800364 & 0xFFFF)($a3)
    lw      $s4, (0x1F800368 & 0xFFFF)($a3)
    lw      $s5, (0x1F80036C & 0xFFFF)($a3)
    lw      $s6, (0x1F800370 & 0xFFFF)($a3)
    lw      $s7, (0x1F800374 & 0xFFFF)($a3)
    jr      $ra
    lw      $gp, (0x1F800378 & 0xFFFF)($a3)
endlabel func_800B3A68

glabel func_800B3CF0
    lui     $t0, (0x1F800390 >> 16)
    sw      $s0, (0x1F800358 & 0xFFFF)($t0)
    sw      $s1, (0x1F80035C & 0xFFFF)($t0)
    sw      $s2, (0x1F800360 & 0xFFFF)($t0)
    sw      $s3, (0x1F800364 & 0xFFFF)($t0)
    sw      $s4, (0x1F800368 & 0xFFFF)($t0)
    sw      $s5, (0x1F80036C & 0xFFFF)($t0)
    sw      $s6, (0x1F800370 & 0xFFFF)($t0)
    sw      $s7, (0x1F800374 & 0xFFFF)($t0)
    sw      $ra, (0x1F800378 & 0xFFFF)($t0)
    sw      $gp, (0x1F80037C & 0xFFFF)($t0)
    sw      $fp, (0x1F800380 & 0xFFFF)($t0)
    lw      $gp, (0x1F800390 & 0xFFFF)($t0)
    lui     $s4, (0xFFFFFF >> 16)
    ori     $s4, $s4, (0xFFFFFF & 0xFFFF)
    sll     $ra, $gp, 16
    srl     $gp, $gp, 16
    sll     $gp, $gp, 16
    lui     $s5, (0xFF000000 >> 16)
    lui     $s0, (0x1F800004 >> 16)
    lhu     $s3, 0x2($a1)
    lw      $s2, 0x3C($a3)
    addiu   $fp, $a0, 0xC00
    lw      $s1, (0x1F800000 & 0xFFFF)($s0)
    lw      $s7, (0x1F800004 & 0xFFFF)($s0)
    lw      $a2, 0x0($a2)
    addi    $s7, $s7, -0x4
    and     $a2, $a2, $s4
    beqz    $s3, .L800B3E6C
    lui     $t8, (0x7000000 >> 16)
    lui     $v1, (0x24000000 >> 16)
    or      $v1, $v1, $a2
    lw      $t3, 0x4($s2)
.L800B3D74:
    lw      $t7, 0x8($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t7, $t7, 16
    add     $t0, $t0, $fp
    nclip
    lw      $t0, 0x0($t0)
    add     $t1, $t1, $fp
    mfc2    $v0, $24
    add     $t2, $t2, $fp
    bgtz    $v0, .L800B3DDC
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B3E6C
    addiu   $s2, $s2, 0x10
    j       .L800B3D74
    lw      $t3, 0x4($s2)
.L800B3DDC:
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    lw      $t3, 0xC($s2)
    sw      $v1, 0x4($s1)
    avsz3
    sw      $t4, 0x8($s1)
    srl     $t1, $t3, 16
    or      $t1, $t1, $ra
    andi    $t0, $t3, 0xFFFF
    or      $t0, $t0, $gp
    sw      $t0, 0xC($s1)
    sw      $t5, 0x10($s1)
    mfc2    $v0, $7
    sw      $t1, 0x14($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B3E5C
    sll     $v0, $v0, 2
    sw      $t6, 0x18($s1)
    add     $v0, $s7, $v0
    sw      $t7, 0x1C($s1)
    lw      $t2, 0x0($v0)
    and     $t1, $s1, $s4
    and     $t0, $t2, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B3E5C:
    beqz    $s3, .L800B3E6C
    addiu   $s2, $s2, 0x10
    j       .L800B3D74
    lw      $t3, 0x4($s2)
.L800B3E6C:
    lhu     $s3, 0x4($a1)
    lui     $t8, (0x9000000 >> 16)
    lui     $v1, (0x2C000000 >> 16)
    beqz    $s3, .L800B3F98
    or      $v1, $v1, $a2
    lw      $t3, 0x4($s2)
.L800B3E84:
    lw      $t7, 0x8($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    nclip
    add     $t0, $t0, $fp
    add     $t1, $t1, $fp
    add     $t2, $t2, $fp
    lw      $t0, 0x0($t0)
    mfc2    $v0, $24
    add     $t3, $t3, $fp
    bgtz    $v0, .L800B3EF4
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B3F98
    addiu   $s2, $s2, 0x14
    j       .L800B3E84
    lw      $t3, 0x4($s2)
.L800B3EF4:
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    lw      $t7, 0x0($t7)
    add     $v0, $v0, $t2
    lw      $t0, 0xC($s2)
    lw      $t2, 0x10($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $t5, 0x10($s1)
    add     $v0, $v0, $t3
    sw      $t1, 0x14($s1)
    srl     $t3, $t2, 16
    sw      $t6, 0x18($s1)
    srl     $v0, $v0, 4
    sw      $t2, 0x1C($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B3F88
    sll     $v0, $v0, 2
    sw      $t7, 0x20($s1)
    add     $v0, $s7, $v0
    sw      $t3, 0x24($s1)
    lw      $t2, 0x0($v0)
    and     $t1, $s1, $s4
    and     $t0, $t2, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B3F88:
    beqz    $s3, .L800B3F98
    addiu   $s2, $s2, 0x14
    j       .L800B3E84
    lw      $t3, 0x4($s2)
.L800B3F98:
    lhu     $s3, 0x6($a1)
    addi    $s7, $s7, -0x10
    beqz    $s3, .L800B455C
    or      $a1, $fp, $zero
    lw      $fp, 0x0($s2)
.L800B3FAC:
    lw      $t3, 0x4($s2)
    srl     $v1, $fp, 16
    andi    $v0, $v1, 0x1
    lw      $t7, 0x8($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    bnez    $v0, .L800B4038
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    or      $s0, $t3, $zero
    nclip
    add     $t7, $a0, $t3
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    andi    $t8, $fp, 0xFF
    srl     $v1, $fp, 8
    mfc2    $v0, $24
    andi    $v1, $v1, 0xFF
    bgtz    $v0, .L800B4068
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B455C
    add     $s2, $s2, $v1
    j       .L800B3FAC
    lw      $fp, 0x0($s2)
.L800B4038:
    addiu   $s3, $s3, -0x1
    srl     $t3, $t7, 16
    or      $s0, $t3, $zero
    add     $t7, $a0, $t3
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    srl     $t9, $fp, 8
    andi    $v1, $v1, 0x2
    bnez    $v1, .L800B4218
    andi    $t8, $fp, 0xFF
.L800B4068:
    lw      $t0, 0x0($t0)
    ori     $v0, $zero, 0x2C
    lw      $t1, 0x0($t1)
    beq     $t8, $v0, .L800B4140
    lw      $t2, 0x0($t2)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    srl     $t2, $fp, 20
    andi    $t2, $t2, 0x1
    sll     $t2, $t2, 25
    lui     $v1, (0x24000000 >> 16)
    or      $v1, $v1, $t2
    or      $v1, $v1, $a2
    avsz3
    srl     $t2, $fp, 16
    andi    $t2, $t2, 0x60
    sll     $t2, $t2, 16
    lw      $t0, 0xC($s2)
    sw      $v1, 0x4($s1)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t2
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    mfc2    $v0, $7
    sw      $t5, 0x10($s1)
    srl     $v1, $fp, 18
    sw      $t1, 0x14($s1)
    andi    $v1, $v1, 0x3
    sw      $t6, 0x18($s1)
    sll     $v1, $v1, 2
    sw      $s0, 0x1C($s1)
    add     $v0, $v0, $v1
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B4130
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B4130:
    beqz    $s3, .L800B455C
    addiu   $s2, $s2, 0x10
    j       .L800B3FAC
    lw      $fp, 0x0($s2)
.L800B4140:
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    lw      $t7, 0x0($t7)
    add     $v0, $v0, $t2
    lw      $t0, 0xC($s2)
    lw      $t2, 0x10($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    srl     $t8, $fp, 20
    andi    $t8, $t8, 0x1
    sll     $t8, $t8, 25
    lui     $v1, (0x2C000000 >> 16)
    or      $v1, $v1, $t8
    or      $v1, $v1, $a2
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    srl     $t8, $fp, 16
    andi    $t8, $t8, 0x60
    sll     $t8, $t8, 16
    sw      $t5, 0x10($s1)
    add     $v0, $v0, $t3
    or      $t1, $t1, $t8
    sw      $t1, 0x14($s1)
    srl     $t3, $t2, 16
    sw      $t6, 0x18($s1)
    srl     $v0, $v0, 4
    sw      $t2, 0x1C($s1)
    srl     $v1, $fp, 18
    sw      $t7, 0x20($s1)
    andi    $v1, $v1, 0x3
    sw      $t3, 0x24($s1)
    sll     $v1, $v1, 2
    add     $v0, $v0, $v1
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B4208
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x9000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B4208:
    beqz    $s3, .L800B455C
    addiu   $s2, $s2, 0x14
    j       .L800B3FAC
    lw      $fp, 0x0($s2)
.L800B4218:
    lw      $t0, 0x0($t0)
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    sll     $v0, $t4, 16
    sll     $v1, $t6, 16
    sra     $v0, $v0, 16
    sra     $v1, $v1, 16
    subu    $t8, $v1, $v0
    ctc2    $t8, $0
    sra     $s0, $t4, 16
    sra     $v1, $t6, 16
    subu    $t8, $v1, $s0
    ctc2    $t8, $2
    subu    $s0, $t2, $t0
    ctc2    $s0, $4
    subu    $s0, $t1, $t0
    mtc2    $s0, $11
    sll     $v1, $t5, 16
    sra     $v1, $v1, 16
    subu    $t8, $v1, $v0
    mtc2    $t8, $9
    sra     $s0, $t4, 16
    sra     $v1, $t5, 16
    subu    $t8, $v1, $s0
    mtc2    $t8, $10
    .nop
    op      0
    lw      $t7, 0x0($t7)
    mfc2    $s6, $25
    sll     $v1, $t7, 16
    sra     $v1, $v1, 16
    subu    $t8, $v1, $v0
    multu   $t8, $s6
    sra     $v1, $t7, 16
    mflo    $t8
    mfc2    $v0, $26
    subu    $s6, $v1, $s0
    multu   $s6, $v0
    lw      $t3, 0x0($t3)
    mflo    $s6
    mfc2    $v0, $27
    subu    $v1, $t3, $t0
    multu   $v0, $v1
    add     $t8, $t8, $s6
    mtc2    $t4, $12
    mtc2    $t5, $13
    mflo    $v0
    add     $v0, $t8, $v0
    negu    $v0, $v0
    bgtz    $v0, .L800B441C
    .nop
    mtc2    $t7, $14
    mtc2    $t0, $17
    mtc2    $t1, $18
    nclip
    mtc2    $t3, $19
    lw      $t0, 0xC($s2)
    lw      $s6, 0x10($s2)
    srl     $t1, $t0, 16
    mfc2    $v0, $24
    andi    $t0, $t0, 0xFFFF
    blez    $v0, .L800B4384
    or      $t0, $t0, $gp
    avsz3
    lui     $v1, (0x24000000 >> 16)
    or      $v1, $v1, $a2
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $t5, 0x10($s1)
    or      $t1, $t1, $ra
    sw      $t1, 0x14($s1)
    srl     $t3, $s6, 16
    sw      $t7, 0x18($s1)
    mfc2    $v0, $7
    sw      $t3, 0x1C($s1)
    addiu   $v0, $v0, 0x4
    sltiu   $s0, $v0, 0x7C0
    beqz    $s0, .L800B4384
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $s0, $v1, $s4
    or      $s0, $s0, $t8
    sw      $s0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $s0, $v1, $s5
    or      $s0, $s0, $t1
    sw      $s0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B4384:
    mtc2    $t7, $13
    mtc2    $t6, $14
    mtc2    $t2, $18
    lui     $v1, (0x24000000 >> 16)
    nclip
    or      $v1, $v1, $a2
    srl     $t3, $s6, 16
    or      $t3, $t3, $ra
    sw      $v1, 0x4($s1)
    mfc2    $v0, $24
    sw      $t4, 0x8($s1)
    blez    $v0, .L800B4408
    sw      $t0, 0xC($s1)
    avsz3
    sw      $t7, 0x10($s1)
    sw      $t3, 0x14($s1)
    sw      $t6, 0x18($s1)
    mfc2    $v0, $7
    sw      $s6, 0x1C($s1)
    addiu   $v0, $v0, 0x4
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B440C
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
.L800B4408:
    addiu   $s1, $s1, 0x20
.L800B440C:
    beqz    $s3, .L800B455C
    addiu   $s2, $s2, 0x14
    j       .L800B3FAC
    lw      $fp, 0x0($s2)
.L800B441C:
    mtc2    $t6, $14
    mtc2    $t0, $17
    mtc2    $t1, $18
    nclip
    mtc2    $t2, $19
    lw      $t0, 0xC($s2)
    lw      $s6, 0x10($s2)
    srl     $t1, $t0, 16
    mfc2    $v0, $24
    lui     $v1, (0x24000000 >> 16)
    blez    $v0, .L800B44B8
    or      $v1, $v1, $a2
    avsz3
    mfc2    $v0, $7
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $t0, 0xC($s1)
    sw      $t5, 0x10($s1)
    or      $t1, $t1, $ra
    sw      $t1, 0x14($s1)
    addiu   $v0, $v0, 0x4
    sw      $t6, 0x18($s1)
    sltiu   $s0, $v0, 0x7C0
    beqz    $s0, .L800B44B8
    sll     $v0, $v0, 2
    sw      $s6, 0x1C($s1)
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $s0, $v1, $s4
    or      $s0, $s0, $t8
    sw      $s0, 0x0($s1)
    and     $t0, $s1, $s4
    and     $s0, $v1, $s5
    or      $s0, $s0, $t0
    sw      $s0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B44B8:
    mtc2    $t5, $12
    mtc2    $t7, $13
    mtc2    $t6, $14
    mtc2    $t3, $17
    lui     $v1, (0x24000000 >> 16)
    nclip
    or      $v1, $v1, $a2
    sw      $v1, 0x4($s1)
    andi    $t1, $t1, 0xFFFF
    or      $t1, $t1, $gp
    mfc2    $v0, $24
    srl     $t3, $s6, 16
    blez    $v0, .L800B454C
    or      $t3, $t3, $ra
    avsz3
    sw      $t5, 0x8($s1)
    sw      $t1, 0xC($s1)
    sw      $t7, 0x10($s1)
    sw      $t3, 0x14($s1)
    mfc2    $v0, $7
    sw      $t6, 0x18($s1)
    addiu   $v0, $v0, 0x4
    sw      $s6, 0x1C($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B454C
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B454C:
    beqz    $s3, .L800B455C
    addiu   $s2, $s2, 0x14
    j       .L800B3FAC
    lw      $fp, 0x0($s2)
.L800B455C:
    lui     $t0, (0x1F800380 >> 16)
    sw      $s1, (0x1F800000 & 0xFFFF)($t0)
    lw      $s0, (0x1F800358 & 0xFFFF)($t0)
    lw      $s1, (0x1F80035C & 0xFFFF)($t0)
    lw      $s2, (0x1F800360 & 0xFFFF)($t0)
    lw      $s3, (0x1F800364 & 0xFFFF)($t0)
    lw      $s4, (0x1F800368 & 0xFFFF)($t0)
    lw      $s5, (0x1F80036C & 0xFFFF)($t0)
    lw      $s6, (0x1F800370 & 0xFFFF)($t0)
    lw      $s7, (0x1F800374 & 0xFFFF)($t0)
    lw      $ra, (0x1F800378 & 0xFFFF)($t0)
    lw      $gp, (0x1F80037C & 0xFFFF)($t0)
    jr      $ra
    lw      $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B3CF0

glabel func_800B4594
    lui     $t0, (0x1F800390 >> 16)
    sw      $s0, (0x1F800358 & 0xFFFF)($t0)
    sw      $s1, (0x1F80035C & 0xFFFF)($t0)
    sw      $s2, (0x1F800360 & 0xFFFF)($t0)
    sw      $s3, (0x1F800364 & 0xFFFF)($t0)
    sw      $s4, (0x1F800368 & 0xFFFF)($t0)
    sw      $s5, (0x1F80036C & 0xFFFF)($t0)
    sw      $s6, (0x1F800370 & 0xFFFF)($t0)
    sw      $s7, (0x1F800374 & 0xFFFF)($t0)
    sw      $ra, (0x1F800378 & 0xFFFF)($t0)
    sw      $gp, (0x1F80037C & 0xFFFF)($t0)
    sw      $fp, (0x1F800380 & 0xFFFF)($t0)
    lw      $gp, (0x1F800390 & 0xFFFF)($t0)
    lui     $s4, (0xFFFFFF >> 16)
    ori     $s4, $s4, (0xFFFFFF & 0xFFFF)
    sll     $ra, $gp, 16
    srl     $gp, $gp, 16
    sll     $gp, $gp, 16
    lui     $s5, (0xFF000000 >> 16)
    lui     $s0, (0x1F800004 >> 16)
    lhu     $s3, 0x2($a1)
    lw      $s2, 0x3C($a3)
    addiu   $fp, $a0, 0xC00
    lw      $s1, (0x1F800000 & 0xFFFF)($s0)
    lw      $s7, (0x1F800004 & 0xFFFF)($s0)
    lw      $a2, 0x0($a2)
    addi    $s7, $s7, -0x4
    beqz    $s3, .L800B4718
    lui     $t8, (0x9000000 >> 16)
    lw      $t3, 0x0($s2)
.L800B460C:
    lw      $t7, 0x4($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t7, $t7, 16
    add     $t0, $t0, $fp
    nclip
    lw      $v1, 0x8($s2)
    add     $t1, $t1, $fp
    mfc2    $v0, $24
    add     $t2, $t2, $fp
    bgtz    $v0, .L800B4674
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B4718
    addiu   $s2, $s2, 0x18
    j       .L800B460C
    lw      $t3, 0x0($s2)
.L800B4674:
    lw      $t0, 0x0($t0)
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    lw      $t0, 0xC($s2)
    lw      $t1, 0x10($s2)
    lw      $t3, 0x14($s2)
    sw      $v1, 0x4($s1)
    avsz3
    sw      $t4, 0x8($s1)
    srl     $v1, $t3, 16
    or      $v1, $v1, $ra
    andi    $v0, $t3, 0xFFFF
    or      $v0, $v0, $gp
    sw      $v0, 0xC($s1)
    sw      $t0, 0x10($s1)
    mfc2    $v0, $7
    sw      $t5, 0x14($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B4708
    sll     $v0, $v0, 2
    sw      $v1, 0x18($s1)
    add     $v0, $s7, $v0
    sw      $t1, 0x1C($s1)
    lw      $t2, 0x0($v0)
    sw      $t6, 0x20($s1)
    and     $t1, $s1, $s4
    sw      $t7, 0x24($s1)
    and     $t0, $t2, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B4708:
    beqz    $s3, .L800B4718
    addiu   $s2, $s2, 0x18
    j       .L800B460C
    lw      $t3, 0x0($s2)
.L800B4718:
    lhu     $s3, 0x4($a1)
    lui     $t8, (0xC000000 >> 16)
    beqz    $s3, .L800B4858
    lw      $t3, 0x0($s2)
.L800B4728:
    lw      $t7, 0x4($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    nclip
    add     $t0, $t0, $fp
    add     $t1, $t1, $fp
    add     $t2, $t2, $fp
    lw      $v1, 0x8($s2)
    mfc2    $v0, $24
    add     $t3, $t3, $fp
    bgtz    $v0, .L800B4798
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B4858
    addiu   $s2, $s2, 0x20
    j       .L800B4728
    lw      $t3, 0x0($s2)
.L800B4798:
    lw      $t0, 0x0($t0)
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    lw      $t7, 0x0($t7)
    add     $v0, $v0, $t2
    lw      $s0, 0xC($s2)
    lw      $s6, 0x10($s2)
    lw      $t9, 0x14($s2)
    lw      $t0, 0x18($s2)
    lw      $t2, 0x1C($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $s0, 0x10($s1)
    add     $v0, $v0, $t3
    sw      $t5, 0x14($s1)
    srl     $t3, $t2, 16
    sw      $t1, 0x18($s1)
    srl     $v0, $v0, 4
    sw      $s6, 0x1C($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B4848
    sll     $v0, $v0, 2
    sw      $t6, 0x20($s1)
    add     $v0, $s7, $v0
    sw      $t2, 0x24($s1)
    lw      $s0, 0x0($v0)
    sw      $t9, 0x28($s1)
    and     $t1, $s1, $s4
    sw      $t7, 0x2C($s1)
    and     $t0, $s0, $s4
    sw      $t3, 0x30($s1)
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $s0, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x34
.L800B4848:
    beqz    $s3, .L800B4858
    addiu   $s2, $s2, 0x20
    j       .L800B4728
    lw      $t3, 0x0($s2)
.L800B4858:
    lhu     $s3, 0x6($a1)
    addi    $s7, $s7, -0x10
    beqz    $s3, .L800B4ADC
    or      $a1, $fp, $zero
    lw      $fp, 0x10($s2)
.L800B486C:
    lw      $t3, 0x0($s2)
    srl     $v1, $fp, 24
    andi    $v0, $v1, 0x1
    lw      $t7, 0x4($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    bnez    $v0, .L800B48F4
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    nclip
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    lw      $t8, 0x8($s2)
    lw      $s0, 0xC($s2)
    mfc2    $v0, $24
    srl     $s0, $s0, 24
    bgtz    $v0, .L800B4918
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B4ADC
    add     $s2, $s2, $s0
    j       .L800B486C
    lw      $fp, 0x0($s2)
.L800B48F4:
    addiu   $s3, $s3, -0x1
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    lw      $t8, 0x8($s2)
    .nop
.L800B4918:
    srl     $s0, $t8, 24
    lw      $t0, 0x0($t0)
    ori     $v0, $zero, 0x3C
    lw      $t1, 0x0($t1)
    beq     $s0, $v0, .L800B49FC
    lw      $t2, 0x0($t2)
    andi    $s0, $v1, 0x10
    sll     $s0, $s0, 21
    or      $t8, $t8, $s0
    sw      $t8, 0x4($s1)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    andi    $v1, $v1, 0x60
    sll     $v1, $v1, 16
    avsz3
    lw      $t0, 0xC($s2)
    lw      $t1, 0x10($s2)
    lw      $t3, 0x14($s2)
    lw      $t8, 0x4($s2)
    srl     $t2, $t3, 16
    srl     $t8, $t8, 16
    or      $t2, $t2, $ra
    or      $t2, $t2, $v1
    andi    $t7, $t3, 0xFFFF
    sw      $t4, 0x8($s1)
    or      $t7, $t7, $gp
    sw      $t7, 0xC($s1)
    mfc2    $v0, $7
    sw      $t0, 0x10($s1)
    srl     $v1, $t1, 26
    sw      $t5, 0x14($s1)
    andi    $v1, $v1, 0x3
    sw      $t2, 0x18($s1)
    sll     $v1, $v1, 2
    sw      $t1, 0x1C($s1)
    add     $v0, $v0, $v1
    sw      $t6, 0x20($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B49EC
    sll     $v0, $v0, 2
    sw      $t8, 0x24($s1)
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x9000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B49EC:
    beqz    $s3, .L800B4ADC
    addiu   $s2, $s2, 0x18
    j       .L800B486C
    lw      $fp, 0x10($s2)
.L800B49FC:
    andi    $s0, $v1, 0x10
    sll     $s0, $s0, 21
    or      $t8, $t8, $s0
    sw      $t8, 0x4($s1)
    andi    $t8, $v1, 0x60
    sll     $t8, $t8, 16
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    lw      $t7, 0x0($t7)
    lw      $v1, 0xC($s2)
    lw      $s0, 0x10($s2)
    lw      $s6, 0x14($s2)
    add     $v0, $v0, $t2
    lw      $t0, 0x18($s2)
    add     $v0, $v0, $t3
    lw      $t2, 0x1C($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t8
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $v1, 0x10($s1)
    srl     $t3, $t2, 16
    sw      $t5, 0x14($s1)
    srl     $v0, $v0, 4
    sw      $t1, 0x18($s1)
    srl     $v1, $s0, 26
    sw      $s0, 0x1C($s1)
    andi    $v1, $v1, 0x3
    sw      $t6, 0x20($s1)
    sll     $v1, $v1, 2
    sw      $t2, 0x24($s1)
    add     $v0, $v0, $v1
    sw      $s6, 0x28($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B4ACC
    sw      $t7, 0x2C($s1)
    sll     $v0, $v0, 2
    sw      $t3, 0x30($s1)
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0xC000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x34
.L800B4ACC:
    beqz    $s3, .L800B4ADC
    addiu   $s2, $s2, 0x20
    j       .L800B486C
    lw      $fp, 0x10($s2)
.L800B4ADC:
    lui     $t0, (0x1F800380 >> 16)
    sw      $s1, (0x1F800000 & 0xFFFF)($t0)
    lw      $s0, (0x1F800358 & 0xFFFF)($t0)
    lw      $s1, (0x1F80035C & 0xFFFF)($t0)
    lw      $s2, (0x1F800360 & 0xFFFF)($t0)
    lw      $s3, (0x1F800364 & 0xFFFF)($t0)
    lw      $s4, (0x1F800368 & 0xFFFF)($t0)
    lw      $s5, (0x1F80036C & 0xFFFF)($t0)
    lw      $s6, (0x1F800370 & 0xFFFF)($t0)
    lw      $s7, (0x1F800374 & 0xFFFF)($t0)
    lw      $ra, (0x1F800378 & 0xFFFF)($t0)
    lw      $gp, (0x1F80037C & 0xFFFF)($t0)
    jr      $ra
    lw      $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B4594

glabel func_800B4B14
    lui     $t0, (0x1F800348 >> 16)
    sw      $s0, (0x1F800320 & 0xFFFF)($t0)
    sw      $s1, (0x1F800324 & 0xFFFF)($t0)
    sw      $s2, (0x1F800328 & 0xFFFF)($t0)
    sw      $s3, (0x1F80032C & 0xFFFF)($t0)
    sw      $s4, (0x1F800330 & 0xFFFF)($t0)
    sw      $s5, (0x1F800334 & 0xFFFF)($t0)
    sw      $s6, (0x1F800338 & 0xFFFF)($t0)
    sw      $s7, (0x1F80033C & 0xFFFF)($t0)
    sw      $ra, (0x1F800340 & 0xFFFF)($t0)
    sw      $gp, (0x1F800344 & 0xFFFF)($t0)
    sw      $fp, (0x1F800348 & 0xFFFF)($t0)
    lui     $s7, (0x1F8003E4 >> 16)
    or      $s0, $zero, $a0
    lw      $s1, 0x1C($a0)
    lh      $s4, 0x20($a0)
    andi    $s3, $s1, 0xFFFF
    addi    $a0, $a0, 0x1C
    or      $a1, $zero, $zero
    or      $a2, $zero, $zero
    jal     func_800A6EE8
    ori     $a3, $zero, 0x3
    or      $fp, $v0, $zero
    sra     $v1, $s1, 16
    sub     $v0, $v1, $v0
    blez    $v0, .L800B4B84
    .nop
    sra     $fp, $s1, 16
.L800B4B84:
    lh      $v0, (0x1F8003B2 & 0xFFFF)($s7)
    lhu     $s2, 0x64C($s0)
    sub     $v0, $v0, $fp
    sra     $v0, $v0, 3
    add     $v0, $v0, $s2
    slti    $v1, $v0, 0x14
    beqz    $v1, .L800B4BA8
    .nop
    ori     $v0, $zero, 0x14
.L800B4BA8:
    lui     $s5, %hi(D_800F49F4)
    addiu   $s5, $s5, %lo(D_800F49F4)
    .nop
    lb      $t0, 0x0($s5)
    sll     $s6, $v0, 7
    bgtz    $t0, .L800B4D20
    srl     $a0, $s3, 7
    srl     $a1, $s4, 7
    sw      $zero, (0x1F8003E4 & 0xFFFF)($s7)
    addi    $a0, $s0, 0x1C
    or      $a1, $s2, $zero
    or      $a2, $zero, $zero
    jal     func_800A6EE8
    ori     $a3, $zero, 0x3
    lb      $t0, 0x0($s5)
    or      $s1, $v0, $zero
    bgtz    $t0, .L800B4D20
    addiu   $a0, $s0, 0x1C
    neg     $a1, $s2
    or      $a2, $zero, $zero
    jal     func_800A6EE8
    ori     $a3, $zero, 0x3
    lb      $t0, 0x0($s5)
    or      $v1, $v0, $zero
    bgtz    $t0, .L800B4D20
    sub     $a0, $v1, $s1
    beqz    $a0, .L800B4C70
    sub     $a0, $fp, $v1
    sub     $a1, $s1, $fp
    bgez    $a0, .L800B4C28
    or      $v0, $zero, $a0
    neg     $v0, $a0
.L800B4C28:
    bgez    $a1, .L800B4C34
    or      $v1, $zero, $a1
    neg     $v1, $a1
.L800B4C34:
    sub     $v0, $v0, $v1
    blez    $v0, .L800B4C44
    .nop
    or      $a0, $zero, $a1
.L800B4C44:
    jal     ratan2
    or      $a1, $zero, $s2
    slti    $v1, $v0, -0x280
    bgtz    $v1, .L800B4C68
    slti    $t0, $v0, 0x280
    beqz    $t0, .L800B4C68
    .nop
    j       .L800B4C70
    sh      $v0, (0x1F8003E4 & 0xFFFF)($s7)
.L800B4C68:
    or      $v0, $zero, $zero
    sh      $v0, (0x1F8003E4 & 0xFFFF)($s7)
.L800B4C70:
    sh      $zero, (0x1F8003E0 & 0xFFFF)($s7)
    addiu   $a0, $s0, 0x1C
    or      $a1, $zero, $zero
    neg     $a2, $s2
    jal     func_800A6EE8
    ori     $a3, $zero, 0x3
    lb      $t0, 0x0($s5)
    or      $s1, $v0, $zero
    bgtz    $t0, .L800B4D20
    addiu   $a0, $s0, 0x1C
    or      $a1, $zero, $zero
    or      $a2, $zero, $s2
    jal     func_800A6EE8
    ori     $a3, $zero, 0x3
    lb      $t0, 0x0($s5)
    or      $v1, $v0, $zero
    bgtz    $t0, .L800B4D20
    sub     $a0, $v1, $s1
    beqz    $a0, .L800B4D18
    sub     $a0, $fp, $v1
    sub     $a1, $s1, $fp
    bgez    $a0, .L800B4CD0
    or      $v0, $zero, $a0
    neg     $v0, $a0
.L800B4CD0:
    bgez    $a1, .L800B4CDC
    or      $v1, $zero, $a1
    neg     $v1, $a1
.L800B4CDC:
    sub     $v0, $v0, $v1
    blez    $v0, .L800B4CEC
    .nop
    or      $a0, $zero, $a1
.L800B4CEC:
    jal     ratan2
    or      $a1, $zero, $s2
    slti    $v1, $v0, -0x280
    bgtz    $v1, .L800B4D10
    slti    $t0, $v0, 0x280
    beqz    $t0, .L800B4D10
    .nop
    j       .L800B4D18
    sh      $v0, (0x1F8003E0 & 0xFFFF)($s7)
.L800B4D10:
    or      $v0, $zero, $zero
    sh      $v0, (0x1F8003E0 & 0xFFFF)($s7)
.L800B4D18:
    j       .L800B4D44
    sh      $zero, (0x1F8003E2 & 0xFFFF)($s7)
.L800B4D20:
    ori     $v0, $zero, 0x1000
    sw      $v0, (0x1F8003C0 & 0xFFFF)($s7)
    sw      $zero, (0x1F8003C4 & 0xFFFF)($s7)
    sw      $v0, (0x1F8003C8 & 0xFFFF)($s7)
    sw      $zero, (0x1F8003CC & 0xFFFF)($s7)
    sw      $zero, (0x1F8003E0 & 0xFFFF)($s7)
    sw      $zero, (0x1F8003E4 & 0xFFFF)($s7)
    j       .L800B4D50
    sw      $v0, (0x1F8003D0 & 0xFFFF)($s7)
.L800B4D44:
    addiu   $a0, $s7, %lo(D_1F8003E0)
    jal     RotMatrixYXZ_gte
    addiu   $a1, $s7, %lo(D_1F8003C0)
.L800B4D50:
    addiu   $a0, $s7, %lo(vs_scratch + 0x14)
    jal     func_800B196C
    addiu   $a1, $s7, %lo(D_1F8003C0)
    lw      $v0, 0x24($s0)
    lw      $a0, 0x28($s0)
    lh      $a2, 0x186C($s0)
    sw      $v0, (0x1F8003E0 & 0xFFFF)($s7)
    sw      $a0, (0x1F8003E4 & 0xFFFF)($s7)
    sra     $a1, $v0, 16
    add     $a1, $a1, $a2
    sh      $a1, (0x1F8003E2 & 0xFFFF)($s7)
    addiu   $a0, $s7, %lo(D_1F8003E0)
    jal     RotMatrixYXZ_gte
    addiu   $a1, $s7, %lo(D_1F800350)
    addiu   $a0, $s7, %lo(D_1F8003C0)
    jal     func_800B196C
    addiu   $a1, $s7, %lo(D_1F800350)
    addiu   $a0, $s7, %lo(D_1F8003C0)
    addiu   $a1, $s7, %lo(D_1F800350)
    jal     vs_main_memcpy
    ori     $a2, $zero, 0x20
    lw      $t0, 0x2C($s0)
    lw      $t1, 0x30($s0)
    srl     $v0, $t0, 16
    multu   $s6, $v0
    lh      $t2, 0x1870($s0)
    lh      $t3, 0x1872($s0)
    srl     $t2, $t2, 1
    srl     $t3, $t3, 1
    sw      $t1, (0x1F8003EC & 0xFFFF)($s7)
    mflo    $v1
    andi    $v0, $t0, 0xFFFF
    srl     $v1, $v1, 12
    multu   $v1, $t3
    mflo    $v1
    .nop
    srl     $v1, $v1, 12
    multu   $s6, $v0
    sw      $v1, (0x1F8003E8 & 0xFFFF)($s7)
    mflo    $v1
    .nop
    srl     $v1, $v1, 12
    multu   $v1, $t2
    .nop
    mflo    $v1
    .nop
    srl     $v1, $v1, 12
    sw      $v1, (0x1F8003F0 & 0xFFFF)($s7)
    addiu   $a0, $s7, %lo(D_1F8003C0)
    jal     func_800B396C
    addiu   $a1, $s7, %lo(D_1F8003E8)
    lw      $t0, (0x1F800014 & 0xFFFF)($s7)
    lw      $t1, (0x1F800018 & 0xFFFF)($s7)
    lw      $t2, (0x1F80001C & 0xFFFF)($s7)
    lw      $t3, (0x1F800020 & 0xFFFF)($s7)
    ctc2    $t0, $0
    ctc2    $t1, $1
    ctc2    $t2, $2
    ctc2    $t3, $3
    lw      $t0, (0x1F800024 & 0xFFFF)($s7)
    lw      $t1, (0x1F800028 & 0xFFFF)($s7)
    lw      $t2, (0x1F80002C & 0xFFFF)($s7)
    lw      $t3, (0x1F800030 & 0xFFFF)($s7)
    ctc2    $t0, $4
    ctc2    $t1, $5
    ctc2    $t2, $6
    ctc2    $t3, $7
    lw      $v0, (0x1F8003B0 & 0xFFFF)($s7)
    lw      $t0, (0x1F8003B4 & 0xFFFF)($s7)
    sll     $v1, $fp, 16
    andi    $v0, $v0, 0xFFFF
    or      $v0, $v0, $v1
    mtc2    $v0, $0
    mtc2    $t0, $1
    lw      $t2, (0x1F8003C0 & 0xFFFF)($s7)
    lw      $t3, (0x1F8003C4 & 0xFFFF)($s7)
    rtv0tr
    lw      $t4, (0x1F8003C8 & 0xFFFF)($s7)
    lw      $t5, (0x1F8003CC & 0xFFFF)($s7)
    lw      $t6, (0x1F8003D0 & 0xFFFF)($s7)
    addiu   $s3, $s7, %lo(D_1F800370)
    addiu   $s4, $s7, %lo(D_1F8003B8)
    ori     $s5, $zero, 0x5
    lui     $s6, %hi(D_800E9A68)
    addiu   $s6, $s6, %lo(D_800E9A68)
    mfc2    $t7, $25
    mfc2    $t8, $26
    mfc2    $t9, $27
    ctc2    $t2, $0
    ctc2    $t3, $1
    ctc2    $t4, $2
    ctc2    $t5, $3
    ctc2    $t6, $4
    ctc2    $t7, $5
    ctc2    $t8, $6
    ctc2    $t9, $7
    lw      $t1, 0x0($s6)
    lw      $t3, 0x4($s6)
    lw      $t5, 0x8($s6)
    andi    $t0, $t1, 0xFFFF
    srl     $t1, $t1, 16
    andi    $t2, $t3, 0xFFFF
    srl     $t3, $t3, 16
    andi    $t4, $t5, 0xFFFF
    srl     $t5, $t5, 16
.L800B4EF4:
    mtc2    $t0, $0
    mtc2    $t1, $1
    mtc2    $t2, $2
    mtc2    $t3, $3
    mtc2    $t4, $4
    mtc2    $t5, $5
    addiu   $s6, $s6, 0xC
    addi    $s5, $s5, -0x1
    rtpt
    lw      $t1, 0x0($s6)
    lw      $t3, 0x4($s6)
    lw      $t5, 0x8($s6)
    lw      $t6, 0x1864($s0)
    andi    $t0, $t1, 0xFFFF
    srl     $t1, $t1, 16
    andi    $t2, $t3, 0xFFFF
    srl     $t3, $t3, 16
    andi    $t4, $t5, 0xFFFF
    srl     $t5, $t5, 16
    srl     $t7, $t6, 8
    andi    $t7, $t7, 0xFF
    sll     $t7, $t7, 1
    srl     $t8, $t6, 16
    andi    $t6, $t6, 0xFF
    swc2    $12, 0x0($s3)
    swc2    $13, 0x4($s3)
    swc2    $14, 0x8($s3)
    swc2    $17, 0x0($s4)
    swc2    $18, 0x4($s4)
    swc2    $19, 0x8($s4)
    addiu   $s3, $s3, 0xC
    bgez    $s5, .L800B4EF4
    addiu   $s4, $s4, 0xC
    lb      $t0, 0x6F2($s0)
    add     $t6, $t6, $t7
    add     $t6, $t6, $t8
    srl     $t6, $t6, 2
    addi    $t6, $t6, 0x40
    sll     $t0, $t0, 2
    sub     $t6, $t6, $t0
    bgtz    $t6, .L800B4FA4
    lui     $t5, (0xFF000000 >> 16)
    or      $t6, $zero, $zero
    j       .L800B4FB4
.L800B4FA4:
    slti    $v0, $t6, 0xFF
    bgtz    $v0, .L800B4FB4
    lui     $t5, (0xFF000000 >> 16)
    ori     $t6, $zero, 0xFF
.L800B4FB4:
    ori     $t7, $t6, 0x3200
    sll     $t7, $t7, 8
    or      $t7, $t7, $t6
    sll     $t7, $t7, 8
    or      $t7, $t7, $t6
    andi    $t8, $t7, 0xFF
    srl     $t8, $t8, 1
    sll     $t6, $t8, 8
    or      $t8, $t8, $t6
    sll     $t6, $t6, 8
    or      $t8, $t8, $t6
    lui     $s2, (0xE1000640 >> 16)
    ori     $s2, $s2, (0xE1000640 & 0xFFFF)
    lui     $t6, (0xFFFFFF >> 16)
    ori     $t6, $t6, (0xFFFFFF & 0xFFFF)
    lui     $s4, (0xFF000000 >> 16)
    lw      $t9, (0x1F800370 & 0xFFFF)($s7)
    lw      $ra, (0x1F8003B8 & 0xFFFF)($s7)
    sw      $t9, 0x6FC($s0)
    sw      $ra, 0x700($s0)
    ori     $s5, $zero, 0x17
    lui     $s6, %hi(D_800E9AD4)
    addiu   $s6, $s6, %lo(D_800E9AD4)
    lw      $s1, (0x1F800000 & 0xFFFF)($s7)
    lw      $fp, (0x1F800004 & 0xFFFF)($s7)
    lui     $gp, (0x7000000 >> 16)
.L800B501C:
    lw      $t9, 0x0($s6)
    addiu   $s6, $s6, 0x4
    andi    $t0, $t9, 0xFF
    srl     $t1, $t9, 8
    andi    $t1, $t1, 0xFF
    srl     $t2, $t9, 16
    andi    $t2, $t2, 0xFF
    add     $t0, $t0, $s7
    add     $t1, $t1, $s7
    add     $t2, $t2, $s7
    lw      $t3, 0x370($t0)
    lw      $t4, 0x370($t1)
    lw      $t5, 0x370($t2)
    mtc2    $t3, $12
    mtc2    $t4, $13
    mtc2    $t5, $14
    lw      $v0, 0x3B8($t0)
    lw      $t1, 0x3B8($t1)
    nclip
    lw      $t2, 0x3B8($t2)
    slt     $v1, $v0, $t1
    bgtz    $v1, .L800B507C
    .nop
    or      $v0, $t1, $zero
.L800B507C:
    slt     $v1, $v0, $t2
    bgtz    $v1, .L800B508C
    .nop
    or      $v0, $t2, $zero
.L800B508C:
    mfc2    $v1, $24
    .nop
    bgtz    $v1, .L800B50F0
    sw      $s2, 0x4($s1)
    sw      $t7, 0x8($s1)
    sw      $t3, 0xC($s1)
    sw      $t8, 0x10($s1)
    sw      $t4, 0x14($s1)
    sw      $t8, 0x18($s1)
    srl     $v0, $v0, 2
    sw      $t5, 0x1C($s1)
    addi    $v0, $v0, -0x2
    sltiu   $v1, $v0, 0x7C0
    beqz    $v1, .L800B50F0
    sll     $v0, $v0, 2
    add     $v0, $fp, $v0
    lw      $t2, 0x0($v0)
    and     $t1, $s1, $t6
    and     $t0, $t2, $t6
    or      $t0, $t0, $gp
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s4
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B50F0:
    addi    $s5, $s5, -0x1
    bltz    $s5, .L800B5134
    addi    $v0, $s5, -0xF
    beqz    $v0, .L800B5114
    addi    $v0, $s5, -0x7
    beqz    $v0, .L800B5128
    .nop
    j       .L800B501C
    .nop
.L800B5114:
    or      $t7, $t8, $zero
    lui     $t8, (0x32000000 >> 16)
    or      $t7, $t7, $t8
    j       .L800B501C
    or      $t8, $zero, $zero
.L800B5128:
    or      $t8, $t7, $zero
    j       .L800B501C
    lui     $t7, (0x32000000 >> 16)
.L800B5134:
    sw      $s1, (0x1F800000 & 0xFFFF)($s7)
    lui     $t0, (0x1F800348 >> 16)
    lw      $s0, (0x1F800320 & 0xFFFF)($t0)
    lw      $s1, (0x1F800324 & 0xFFFF)($t0)
    lw      $s2, (0x1F800328 & 0xFFFF)($t0)
    lw      $s3, (0x1F80032C & 0xFFFF)($t0)
    lw      $s4, (0x1F800330 & 0xFFFF)($t0)
    lw      $s5, (0x1F800334 & 0xFFFF)($t0)
    lw      $s6, (0x1F800338 & 0xFFFF)($t0)
    lw      $s7, (0x1F80033C & 0xFFFF)($t0)
    lw      $ra, (0x1F800340 & 0xFFFF)($t0)
    lw      $gp, (0x1F800344 & 0xFFFF)($t0)
    jr      $ra
    lw      $fp, (0x1F800348 & 0xFFFF)($t0)
endlabel func_800B4B14

glabel func_800B516C
    lui     $t0, (0x1F800390 >> 16)
    sw      $s0, (0x1F800358 & 0xFFFF)($t0)
    sw      $s1, (0x1F80035C & 0xFFFF)($t0)
    sw      $s2, (0x1F800360 & 0xFFFF)($t0)
    sw      $s3, (0x1F800364 & 0xFFFF)($t0)
    sw      $s4, (0x1F800368 & 0xFFFF)($t0)
    sw      $s5, (0x1F80036C & 0xFFFF)($t0)
    sw      $s6, (0x1F800370 & 0xFFFF)($t0)
    sw      $s7, (0x1F800374 & 0xFFFF)($t0)
    sw      $ra, (0x1F800378 & 0xFFFF)($t0)
    sw      $gp, (0x1F80037C & 0xFFFF)($t0)
    sw      $fp, (0x1F800380 & 0xFFFF)($t0)
    lw      $gp, (0x1F800390 & 0xFFFF)($t0)
    lui     $s4, (0xFFFFFF >> 16)
    ori     $s4, $s4, (0xFFFFFF & 0xFFFF)
    sll     $ra, $gp, 16
    srl     $gp, $gp, 16
    sll     $gp, $gp, 16
    lui     $s5, (0xFF000000 >> 16)
    lui     $s0, (0x1F800392 >> 16)
    lhu     $s3, 0x2($a1)
    lw      $s2, 0x3C($a3)
    addiu   $fp, $a0, 0xC00
    lw      $s1, (0x1F800000 & 0xFFFF)($s0)
    lw      $s7, (0x1F800004 & 0xFFFF)($s0)
    lw      $a2, 0x0($a2)
    addi    $s7, $s7, -0x4
    lbu     $s6, 0x64($a1)
    lbu     $v1, 0x9($a1)
    and     $a2, $a2, $s4
    andi    $v1, $v1, 0xF
    beqz    $v1, .L800B5200
    or      $t9, $zero, $zero
    slti    $v1, $v1, 0x7
    bnez    $v1, .L800B5200
    lui     $t9, (0x400000 >> 16)
    lui     $t9, (0x200000 >> 16)
.L800B5200:
    ori     $t0, $zero, 0x9
    sw      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $s3, .L800B5394
    addiu   $a3, $a3, 0x10
    addiu   $a3, $a3, -0x10
    lui     $t8, (0x7000000 >> 16)
.L800B5218:
    lw      $t0, (0x1F80039C & 0xFFFF)($s0)
    .nop
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
.L800B5228:
    addi    $t0, $t0, -0x1
    bltz    $t0, .L800B5394
    sh      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $t0, .L800B5270
    addi    $t3, $t0, -0x1
    lh      $s3, 0x0($a3)
    addiu   $a3, $a3, 0x2
    add     $t1, $t1, $s3
    beqz    $s3, .L800B5228
    sh      $t1, (0x1F80039E & 0xFFFF)($s0)
    srlv    $t2, $s6, $t3
    andi    $t2, $t2, 0x1
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    beqz    $t2, .L800B5280
    .nop
    addiu   $gp, $gp, 0x480
    j       .L800B5284
    sll     $gp, $gp, 16
.L800B5270:
    lhu     $s3, 0x2($a1)
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    sub     $s3, $s3, $t1
    beqz    $s3, .L800B5394
.L800B5280:
    sll     $gp, $gp, 16
.L800B5284:
    lw      $t3, 0x4($s2)
.L800B5288:
    lw      $t7, 0x8($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t7, $t7, 16
    add     $t0, $t0, $fp
    nclip
    lw      $t0, 0x0($t0)
    add     $t1, $t1, $fp
    mfc2    $v0, $24
    add     $t2, $t2, $fp
    bgtz    $v0, .L800B52F0
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B5218
    addiu   $s2, $s2, 0x10
    j       .L800B5288
    lw      $t3, 0x4($s2)
.L800B52F0:
    beqz    $t9, .L800B52FC
    lui     $v1, (0x24000000 >> 16)
    lui     $v1, (0x26000000 >> 16)
.L800B52FC:
    or      $v1, $v1, $a2
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    lw      $t3, 0xC($s2)
    sw      $v1, 0x4($s1)
    avsz3
    sw      $t4, 0x8($s1)
    srl     $t1, $t3, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t9
    andi    $t0, $t3, 0xFFFF
    or      $t0, $t0, $gp
    mfc2    $v0, $7
    sw      $t0, 0xC($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B5384
    sw      $t5, 0x10($s1)
    sw      $t1, 0x14($s1)
    sll     $v0, $v0, 2
    sw      $t6, 0x18($s1)
    add     $v0, $s7, $v0
    sw      $t7, 0x1C($s1)
    lw      $t2, 0x0($v0)
    and     $t1, $s1, $s4
    and     $t0, $t2, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B5384:
    beqz    $s3, .L800B5218
    addiu   $s2, $s2, 0x10
    j       .L800B5288
    lw      $t3, 0x4($s2)
.L800B5394:
    ori     $t0, $zero, 0x9
    sw      $t0, (0x1F80039C & 0xFFFF)($s0)
    lhu     $s3, 0x4($a1)
    lui     $t8, (0x9000000 >> 16)
    beqz    $s3, .L800B5548
    addiu   $a3, $a3, 0x10
    addiu   $a3, $a3, -0x10
.L800B53B0:
    lw      $t0, (0x1F80039C & 0xFFFF)($s0)
    .nop
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
.L800B53C0:
    addi    $t0, $t0, -0x1
    bltz    $t0, .L800B5548
    sh      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $t0, .L800B5408
    addi    $t3, $t0, -0x1
    lh      $s3, 0x0($a3)
    addiu   $a3, $a3, 0x2
    add     $t1, $t1, $s3
    beqz    $s3, .L800B53C0
    sh      $t1, (0x1F80039E & 0xFFFF)($s0)
    srlv    $t2, $s6, $t3
    andi    $t2, $t2, 0x1
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    beqz    $t2, .L800B5418
    .nop
    addiu   $gp, $gp, 0x480
    j       .L800B541C
    sll     $gp, $gp, 16
.L800B5408:
    lhu     $s3, 0x4($a1)
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    sub     $s3, $s3, $t1
    beqz    $s3, .L800B5548
.L800B5418:
    sll     $gp, $gp, 16
.L800B541C:
    lw      $t3, 0x4($s2)
.L800B5420:
    lw      $t7, 0x8($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    nclip
    add     $t0, $t0, $fp
    add     $t1, $t1, $fp
    add     $t2, $t2, $fp
    lw      $t0, 0x0($t0)
    mfc2    $v0, $24
    add     $t3, $t3, $fp
    bgtz    $v0, .L800B5490
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B53B0
    addiu   $s2, $s2, 0x14
    j       .L800B5420
    lw      $t3, 0x4($s2)
.L800B5490:
    beqz    $t9, .L800B549C
    lui     $v1, (0x2C000000 >> 16)
    lui     $v1, (0x2E000000 >> 16)
.L800B549C:
    or      $v1, $v1, $a2
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    add     $v0, $t0, $t1
    lw      $t3, 0x0($t3)
    add     $v0, $v0, $t2
    add     $v0, $v0, $t3
    srl     $v0, $v0, 4
    sltiu   $t1, $v0, 0x7C0
    beqz    $t1, .L800B5538
    lw      $t7, 0x0($t7)
    lw      $t0, 0xC($s2)
    lw      $t2, 0x10($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t9
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $t5, 0x10($s1)
    sw      $t1, 0x14($s1)
    srl     $t3, $t2, 16
    sw      $t6, 0x18($s1)
    sw      $t2, 0x1C($s1)
    sll     $v0, $v0, 2
    sw      $t7, 0x20($s1)
    add     $v0, $s7, $v0
    sw      $t3, 0x24($s1)
    lw      $t2, 0x0($v0)
    and     $t1, $s1, $s4
    and     $t0, $t2, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B5538:
    beqz    $s3, .L800B53B0
    addiu   $s2, $s2, 0x14
    j       .L800B5420
    lw      $t3, 0x4($s2)
.L800B5548:
    ori     $t0, $zero, 0x9
    sw      $t0, (0x1F80039C & 0xFFFF)($s0)
    sw      $a1, (0x1F8003A0 & 0xFFFF)($s0)
    lhu     $s3, 0x6($a1)
    addi    $s7, $s7, -0x10
    beqz    $s3, .L800B5BF8
    or      $a1, $fp, $zero
.L800B5564:
    lui     $s0, (0x1F800392 >> 16)
    lw      $t0, (0x1F80039C & 0xFFFF)($s0)
    lw      $t4, (0x1F8003A0 & 0xFFFF)($s0)
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
.L800B5578:
    addi    $t0, $t0, -0x1
    bltz    $t0, .L800B5BF8
    sh      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $t0, .L800B55C8
    addi    $t3, $t0, -0x1
    lhu     $s3, 0x0($a3)
    addiu   $a3, $a3, 0x2
    add     $t1, $t1, $s3
    beqz    $s3, .L800B5578
    sh      $t1, (0x1F80039E & 0xFFFF)($s0)
    lbu     $s6, 0x64($t4)
    .nop
    srlv    $t2, $s6, $t3
    andi    $t2, $t2, 0x1
    lhu     $gp, (0x1F800392 & 0xFFFF)($s0)
    beqz    $t2, .L800B55D8
    .nop
    addiu   $gp, $gp, 0x480
    j       .L800B55DC
    sll     $gp, $gp, 16
.L800B55C8:
    lhu     $s3, 0x6($t4)
    lhu     $gp, (0x1F800392 & 0xFFFF)($s0)
    sub     $s3, $s3, $t1
    beqz    $s3, .L800B5BF8
.L800B55D8:
    sll     $gp, $gp, 16
.L800B55DC:
    lw      $fp, 0x0($s2)
.L800B55E0:
    lw      $t3, 0x4($s2)
    srl     $v1, $fp, 16
    andi    $v0, $v1, 0x1
    lw      $t7, 0x8($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    bnez    $v0, .L800B566C
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    or      $s0, $t3, $zero
    nclip
    add     $t7, $a0, $t3
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    andi    $t8, $fp, 0xFF
    srl     $v1, $fp, 8
    mfc2    $v0, $24
    andi    $v1, $v1, 0xFF
    bgtz    $v0, .L800B5698
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B5564
    add     $s2, $s2, $v1
    j       .L800B55E0
    lw      $fp, 0x0($s2)
.L800B566C:
    addiu   $s3, $s3, -0x1
    srl     $t3, $t7, 16
    or      $s0, $t3, $zero
    add     $t7, $a0, $t3
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    andi    $v1, $v1, 0x2
    bnez    $v1, .L800B5880
    andi    $t8, $fp, 0xFF
.L800B5698:
    lw      $t0, 0x0($t0)
    ori     $v0, $zero, 0x2C
    lw      $t1, 0x0($t1)
    beq     $t8, $v0, .L800B578C
    lw      $t2, 0x0($t2)
    beqz    $t9, .L800B56C8
    lui     $v1, (0xFF0FFFFF >> 16)
    ori     $v1, $v1, (0xFF0FFFFF & 0xFFFF)
    and     $fp, $fp, $v1
    lui     $v1, (0x100000 >> 16)
    or      $fp, $fp, $v1
    or      $fp, $fp, $t9
.L800B56C8:
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    srl     $t2, $fp, 20
    andi    $t2, $t2, 0x1
    sll     $t2, $t2, 25
    lui     $v1, (0x24000000 >> 16)
    or      $v1, $v1, $t2
    or      $v1, $v1, $a2
    avsz3
    srl     $t2, $fp, 16
    andi    $t2, $t2, 0x60
    sll     $t2, $t2, 16
    lw      $t0, 0xC($s2)
    sw      $v1, 0x4($s1)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t2
    andi    $t0, $t0, 0xFFFF
    mfc2    $v0, $7
    or      $t0, $t0, $gp
    sltiu   $t8, $v0, 0x7C0
    beqz    $t8, .L800B577C
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $t5, 0x10($s1)
    srl     $v1, $fp, 18
    sw      $t1, 0x14($s1)
    andi    $v1, $v1, 0x3
    sw      $t6, 0x18($s1)
    sll     $v1, $v1, 2
    sw      $s0, 0x1C($s1)
    add     $v0, $v0, $v1
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B577C:
    beqz    $s3, .L800B5564
    addiu   $s2, $s2, 0x10
    j       .L800B55E0
    lw      $fp, 0x0($s2)
.L800B578C:
    beqz    $t9, .L800B57A8
    lui     $v1, (0xFF0FFFFF >> 16)
    ori     $v1, $v1, (0xFF0FFFFF & 0xFFFF)
    and     $fp, $fp, $v1
    lui     $v1, (0x100000 >> 16)
    or      $fp, $fp, $v1
    or      $fp, $fp, $t9
.L800B57A8:
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    lw      $t7, 0x0($t7)
    add     $v0, $v0, $t2
    add     $v0, $v0, $t3
    srl     $v0, $v0, 4
    sltiu   $t8, $v0, 0x7C0
    beqz    $t8, .L800B5870
    lw      $t0, 0xC($s2)
    lw      $t2, 0x10($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    srl     $t8, $fp, 20
    andi    $t8, $t8, 0x1
    sll     $t8, $t8, 25
    lui     $v1, (0x2C000000 >> 16)
    or      $v1, $v1, $t8
    or      $v1, $v1, $a2
    sw      $v1, 0x4($s1)
    andi    $t0, $t0, 0xFFFF
    sw      $t4, 0x8($s1)
    or      $t0, $t0, $gp
    sw      $t0, 0xC($s1)
    srl     $t8, $fp, 16
    andi    $t8, $t8, 0x60
    sll     $t8, $t8, 16
    sw      $t5, 0x10($s1)
    or      $t1, $t1, $t8
    sw      $t1, 0x14($s1)
    srl     $t3, $t2, 16
    sw      $t6, 0x18($s1)
    sw      $t2, 0x1C($s1)
    srl     $v1, $fp, 18
    sw      $t7, 0x20($s1)
    andi    $v1, $v1, 0x3
    sw      $t3, 0x24($s1)
    sll     $v1, $v1, 2
    add     $v0, $v0, $v1
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x9000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B5870:
    beqz    $s3, .L800B5564
    addiu   $s2, $s2, 0x14
    j       .L800B55E0
    lw      $fp, 0x0($s2)
.L800B5880:
    lw      $t0, 0x0($t0)
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    sll     $v0, $t4, 16
    sll     $v1, $t6, 16
    sra     $v0, $v0, 16
    sra     $v1, $v1, 16
    subu    $t8, $v1, $v0
    ctc2    $t8, $0
    sra     $s0, $t4, 16
    sra     $v1, $t6, 16
    subu    $t8, $v1, $s0
    ctc2    $t8, $2
    subu    $s0, $t2, $t0
    ctc2    $s0, $4
    subu    $s0, $t1, $t0
    mtc2    $s0, $11
    sll     $v1, $t5, 16
    sra     $v1, $v1, 16
    subu    $t8, $v1, $v0
    mtc2    $t8, $9
    sra     $s0, $t4, 16
    sra     $v1, $t5, 16
    subu    $t8, $v1, $s0
    mtc2    $t8, $10
    .nop
    op      0
    lw      $t7, 0x0($t7)
    mfc2    $s6, $25
    sll     $v1, $t7, 16
    sra     $v1, $v1, 16
    subu    $t8, $v1, $v0
    multu   $t8, $s6
    sra     $v1, $t7, 16
    mflo    $t8
    mfc2    $v0, $26
    subu    $s6, $v1, $s0
    multu   $s6, $v0
    lw      $t3, 0x0($t3)
    mflo    $s6
    mfc2    $v0, $27
    subu    $v1, $t3, $t0
    multu   $v0, $v1
    add     $t8, $t8, $s6
    mtc2    $t4, $12
    mtc2    $t5, $13
    mflo    $v0
    add     $v0, $t8, $v0
    negu    $v0, $v0
    bgtz    $v0, .L800B5AA0
    .nop
    mtc2    $t7, $14
    mtc2    $t0, $17
    mtc2    $t1, $18
    nclip
    mtc2    $t3, $19
    lw      $t0, 0xC($s2)
    lw      $s6, 0x10($s2)
    srl     $t1, $t0, 16
    mfc2    $v0, $24
    andi    $t0, $t0, 0xFFFF
    blez    $v0, .L800B59F8
    or      $t0, $t0, $gp
    avsz3
    beqz    $t9, .L800B598C
    lui     $v1, (0x24000000 >> 16)
    lui     $v1, (0x26000000 >> 16)
.L800B598C:
    or      $v1, $v1, $a2
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    mfc2    $v0, $7
    sw      $t5, 0x10($s1)
    sltiu   $t8, $v0, 0x7C0
    beqz    $t8, .L800B59F8
    or      $t1, $t1, $ra
    or      $t1, $t1, $t9
    sw      $t1, 0x14($s1)
    srl     $t3, $s6, 16
    sw      $t7, 0x18($s1)
    sw      $t3, 0x1C($s1)
    addiu   $v0, $v0, 0x4
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $s0, $v1, $s4
    or      $s0, $s0, $t8
    sw      $s0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $s0, $v1, $s5
    or      $s0, $s0, $t1
    sw      $s0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B59F8:
    mtc2    $t7, $13
    mtc2    $t6, $14
    mtc2    $t2, $18
    lui     $v1, (0x24000000 >> 16)
    nclip
    beqz    $t9, .L800B5A18
    lui     $v1, (0x24000000 >> 16)
    lui     $v1, (0x26000000 >> 16)
.L800B5A18:
    or      $v1, $v1, $a2
    srl     $t3, $s6, 16
    or      $t3, $t3, $ra
    or      $t3, $t3, $t9
    sw      $v1, 0x4($s1)
    mfc2    $v0, $24
    sw      $t4, 0x8($s1)
    blez    $v0, .L800B5A8C
    sw      $t0, 0xC($s1)
    avsz3
    sw      $t7, 0x10($s1)
    sw      $t3, 0x14($s1)
    sw      $t6, 0x18($s1)
    mfc2    $v0, $7
    sw      $s6, 0x1C($s1)
    sltiu   $t8, $v0, 0x7C0
    beqz    $t8, .L800B5A90
    addiu   $v0, $v0, 0x4
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
.L800B5A8C:
    addiu   $s1, $s1, 0x20
.L800B5A90:
    beqz    $s3, .L800B5564
    addiu   $s2, $s2, 0x14
    j       .L800B55E0
    lw      $fp, 0x0($s2)
.L800B5AA0:
    mtc2    $t6, $14
    mtc2    $t0, $17
    mtc2    $t1, $18
    nclip
    mtc2    $t2, $19
    lw      $t0, 0xC($s2)
    lw      $s6, 0x10($s2)
    srl     $t1, $t0, 16
    mfc2    $v0, $24
    beqz    $t9, .L800B5AD0
    lui     $v1, (0x24000000 >> 16)
    lui     $v1, (0x26000000 >> 16)
.L800B5AD0:
    blez    $v0, .L800B5B48
    or      $v1, $v1, $a2
    avsz3
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $t0, 0xC($s1)
    mfc2    $v0, $7
    sw      $t5, 0x10($s1)
    sltiu   $t8, $v0, 0x7C0
    beqz    $t8, .L800B5B48
    or      $t1, $t1, $ra
    or      $t1, $t1, $t9
    sw      $t1, 0x14($s1)
    addiu   $v0, $v0, 0x4
    sw      $t6, 0x18($s1)
    sll     $v0, $v0, 2
    sw      $s6, 0x1C($s1)
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $s0, $v1, $s4
    or      $s0, $s0, $t8
    sw      $s0, 0x0($s1)
    and     $t0, $s1, $s4
    and     $s0, $v1, $s5
    or      $s0, $s0, $t0
    sw      $s0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B5B48:
    mtc2    $t5, $12
    mtc2    $t7, $13
    mtc2    $t6, $14
    mtc2    $t3, $17
    beqz    $t9, .L800B5B64
    lui     $v1, (0x24000000 >> 16)
    lui     $v1, (0x26000000 >> 16)
.L800B5B64:
    nclip
    or      $v1, $v1, $a2
    sw      $v1, 0x4($s1)
    andi    $t1, $t1, 0xFFFF
    or      $t1, $t1, $gp
    mfc2    $v0, $24
    srl     $t3, $s6, 16
    blez    $v0, .L800B5BE8
    or      $t3, $t3, $ra
    or      $t3, $t3, $t9
    avsz3
    sw      $t5, 0x8($s1)
    sw      $t1, 0xC($s1)
    sw      $t7, 0x10($s1)
    sw      $t3, 0x14($s1)
    mfc2    $v0, $7
    sw      $t6, 0x18($s1)
    sltiu   $t8, $v0, 0x7C0
    beqz    $t8, .L800B5BE8
    addiu   $v0, $v0, 0x4
    sw      $s6, 0x1C($s1)
    sll     $v0, $v0, 2
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x7000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x20
.L800B5BE8:
    beqz    $s3, .L800B5564
    addiu   $s2, $s2, 0x14
    j       .L800B55E0
    lw      $fp, 0x0($s2)
.L800B5BF8:
    lui     $t0, (0x1F800380 >> 16)
    sw      $s1, (0x1F800000 & 0xFFFF)($t0)
    lw      $s0, (0x1F800358 & 0xFFFF)($t0)
    lw      $s1, (0x1F80035C & 0xFFFF)($t0)
    lw      $s2, (0x1F800360 & 0xFFFF)($t0)
    lw      $s3, (0x1F800364 & 0xFFFF)($t0)
    lw      $s4, (0x1F800368 & 0xFFFF)($t0)
    lw      $s5, (0x1F80036C & 0xFFFF)($t0)
    lw      $s6, (0x1F800370 & 0xFFFF)($t0)
    lw      $s7, (0x1F800374 & 0xFFFF)($t0)
    lw      $ra, (0x1F800378 & 0xFFFF)($t0)
    lw      $gp, (0x1F80037C & 0xFFFF)($t0)
    jr      $ra
    lw      $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B516C

glabel func_800B5C30
    lui     $t0, (0x1F800390 >> 16)
    sw      $s0, (0x1F800358 & 0xFFFF)($t0)
    sw      $s1, (0x1F80035C & 0xFFFF)($t0)
    sw      $s2, (0x1F800360 & 0xFFFF)($t0)
    sw      $s3, (0x1F800364 & 0xFFFF)($t0)
    sw      $s4, (0x1F800368 & 0xFFFF)($t0)
    sw      $s5, (0x1F80036C & 0xFFFF)($t0)
    sw      $s6, (0x1F800370 & 0xFFFF)($t0)
    sw      $s7, (0x1F800374 & 0xFFFF)($t0)
    sw      $ra, (0x1F800378 & 0xFFFF)($t0)
    sw      $gp, (0x1F80037C & 0xFFFF)($t0)
    sw      $fp, (0x1F800380 & 0xFFFF)($t0)
    lw      $gp, (0x1F800390 & 0xFFFF)($t0)
    lui     $s4, (0xFFFFFF >> 16)
    ori     $s4, $s4, (0xFFFFFF & 0xFFFF)
    sll     $ra, $gp, 16
    srl     $gp, $gp, 16
    sll     $gp, $gp, 16
    lui     $s5, (0xFF000000 >> 16)
    lui     $s0, (0x1F800392 >> 16)
    lhu     $s3, 0x2($a1)
    lw      $s2, 0x3C($a3)
    addiu   $fp, $a0, 0xC00
    lw      $s1, (0x1F800000 & 0xFFFF)($s0)
    lw      $s7, (0x1F800004 & 0xFFFF)($s0)
    lw      $a2, 0x0($a2)
    addi    $s7, $s7, -0x4
    lbu     $s6, 0x64($a1)
    lbu     $v1, 0x9($a1)
    and     $a2, $a2, $s4
    andi    $v1, $v1, 0xF
    beqz    $v1, .L800B5CC4
    or      $t9, $zero, $zero
    slti    $v1, $v1, 0x7
    bnez    $v1, .L800B5CC4
    lui     $t9, (0x400000 >> 16)
    lui     $t9, (0x200000 >> 16)
.L800B5CC4:
    ori     $t0, $zero, 0x9
    sw      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $s3, .L800B5E74
    lui     $t8, (0x9000000 >> 16)
.L800B5CD4:
    lw      $t0, (0x1F80039C & 0xFFFF)($s0)
    .nop
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
.L800B5CE4:
    addi    $t0, $t0, -0x1
    bltz    $t0, .L800B5E74
    sh      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $t0, .L800B5D2C
    addi    $t3, $t0, -0x1
    lh      $s3, 0x0($a3)
    addiu   $a3, $a3, 0x2
    add     $t1, $t1, $s3
    beqz    $s3, .L800B5CE4
    sh      $t1, (0x1F80039E & 0xFFFF)($s0)
    srlv    $t2, $s6, $t3
    andi    $t2, $t2, 0x1
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    beqz    $t2, .L800B5D3C
    .nop
    addiu   $gp, $gp, 0x480
    j       .L800B5D40
    sll     $gp, $gp, 16
.L800B5D2C:
    lhu     $s3, 0x2($a1)
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    sub     $s3, $s3, $t1
    beqz    $s3, .L800B5E74
.L800B5D3C:
    sll     $gp, $gp, 16
.L800B5D40:
    beqz    $s3, .L800B5E74
    lui     $t8, (0x9000000 >> 16)
    lw      $t3, 0x0($s2)
.L800B5D4C:
    lw      $t7, 0x4($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t7, $t7, 16
    add     $t0, $t0, $fp
    nclip
    lw      $v1, 0x8($s2)
    add     $t1, $t1, $fp
    mfc2    $v0, $24
    add     $t2, $t2, $fp
    bgtz    $v0, .L800B5DB4
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B5CD4
    addiu   $s2, $s2, 0x18
    j       .L800B5D4C
    lw      $t3, 0x0($s2)
.L800B5DB4:
    lw      $t0, 0x0($t0)
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    beqz    $t9, .L800B5DE4
    lui     $t3, (0x36000000 >> 16)
    or      $v1, $a2, $t3
    or      $t0, $zero, $a2
    j       .L800B5DEC
    or      $t1, $zero, $a2
.L800B5DE4:
    lw      $t0, 0xC($s2)
    lw      $t1, 0x10($s2)
.L800B5DEC:
    avsz3
    lw      $t3, 0x14($s2)
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    srl     $v1, $t3, 16
    or      $v1, $v1, $ra
    or      $v1, $v1, $t9
    andi    $v0, $t3, 0xFFFF
    or      $v0, $v0, $gp
    sw      $v0, 0xC($s1)
    mfc2    $v0, $7
    sw      $t0, 0x10($s1)
    sltiu   $t0, $v0, 0x7C0
    beqz    $t0, .L800B5E64
    sw      $t5, 0x14($s1)
    sll     $v0, $v0, 2
    sw      $v1, 0x18($s1)
    add     $v0, $s7, $v0
    sw      $t1, 0x1C($s1)
    lw      $t2, 0x0($v0)
    sw      $t6, 0x20($s1)
    and     $t1, $s1, $s4
    sw      $t7, 0x24($s1)
    and     $t0, $t2, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $t2, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B5E64:
    beqz    $s3, .L800B5CD4
    addiu   $s2, $s2, 0x18
    j       .L800B5D4C
    lw      $t3, 0x0($s2)
.L800B5E74:
    ori     $t0, $zero, 0x9
    sw      $t0, (0x1F80039C & 0xFFFF)($s0)
    lhu     $s3, 0x4($a1)
    lui     $t8, (0xC000000 >> 16)
    beqz    $s3, .L800B6050
.L800B5E88:
    lui     $s0, (0x1F800392 >> 16)
    lw      $t0, (0x1F80039C & 0xFFFF)($s0)
    .nop
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
.L800B5E9C:
    addi    $t0, $t0, -0x1
    bltz    $t0, .L800B6050
    sh      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $t0, .L800B5EE8
    addi    $t3, $t0, -0x1
    lh      $s3, 0x0($a3)
    lbu     $s6, 0x64($a1)
    addiu   $a3, $a3, 0x2
    add     $t1, $t1, $s3
    beqz    $s3, .L800B5E9C
    sh      $t1, (0x1F80039E & 0xFFFF)($s0)
    srlv    $t2, $s6, $t3
    andi    $t2, $t2, 0x1
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    beqz    $t2, .L800B5EF8
    .nop
    addiu   $gp, $gp, 0x480
    j       .L800B5EFC
    sll     $gp, $gp, 16
.L800B5EE8:
    lhu     $s3, 0x4($a1)
    lh      $gp, (0x1F800392 & 0xFFFF)($s0)
    sub     $s3, $s3, $t1
    beqz    $s3, .L800B6050
.L800B5EF8:
    sll     $gp, $gp, 16
.L800B5EFC:
    lw      $t3, 0x0($s2)
.L800B5F00:
    lw      $t7, 0x4($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    nclip
    add     $t0, $t0, $fp
    add     $t1, $t1, $fp
    add     $t2, $t2, $fp
    lw      $v1, 0x8($s2)
    mfc2    $v0, $24
    add     $t3, $t3, $fp
    bgtz    $v0, .L800B5F70
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B5E88
    addiu   $s2, $s2, 0x20
    j       .L800B5F00
    lw      $t3, 0x0($s2)
.L800B5F70:
    lw      $t0, 0x0($t0)
    lw      $t1, 0x0($t1)
    lw      $t2, 0x0($t2)
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    add     $v0, $v0, $t2
    add     $v0, $v0, $t3
    srl     $v0, $v0, 4
    sltiu   $s0, $v0, 0x7C0
    beqz    $s0, .L800B6040
    lw      $t7, 0x0($t7)
    beqz    $t9, .L800B5FB8
    lui     $t3, (0x3E000000 >> 16)
    or      $v1, $a2, $t3
    or      $s0, $zero, $a2
    or      $s6, $zero, $a2
    j       .L800B5FC4
    or      $t3, $zero, $a2
.L800B5FB8:
    lw      $s0, 0xC($s2)
    lw      $s6, 0x10($s2)
    lw      $t3, 0x14($s2)
.L800B5FC4:
    lw      $t0, 0x18($s2)
    lw      $t2, 0x1C($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t9
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t0, $gp
    sw      $v1, 0x4($s1)
    sw      $t4, 0x8($s1)
    sw      $t0, 0xC($s1)
    sw      $s0, 0x10($s1)
    sw      $t5, 0x14($s1)
    srl     $v1, $t2, 16
    sw      $t1, 0x18($s1)
    sw      $s6, 0x1C($s1)
    sll     $v0, $v0, 2
    sw      $t6, 0x20($s1)
    add     $v0, $s7, $v0
    sw      $t2, 0x24($s1)
    lw      $s0, 0x0($v0)
    sw      $t3, 0x28($s1)
    and     $t1, $s1, $s4
    sw      $t7, 0x2C($s1)
    and     $t0, $s0, $s4
    sw      $v1, 0x30($s1)
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t0, $s0, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x34
.L800B6040:
    beqz    $s3, .L800B5E88
    addiu   $s2, $s2, 0x20
    j       .L800B5F00
    lw      $t3, 0x0($s2)
.L800B6050:
    ori     $t0, $zero, 0x9
    sw      $t0, (0x1F80039C & 0xFFFF)($s0)
    sw      $a1, (0x1F8003A0 & 0xFFFF)($s0)
    lhu     $s3, 0x6($a1)
    addi    $s7, $s7, -0x10
    beqz    $s3, .L800B6374
    or      $a1, $fp, $zero
.L800B606C:
    lui     $s0, (0x1F800392 >> 16)
    lw      $t0, (0x1F80039C & 0xFFFF)($s0)
    lw      $t4, (0x1F8003A0 & 0xFFFF)($s0)
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
.L800B6080:
    addi    $t0, $t0, -0x1
    bltz    $t0, .L800B6374
    sh      $t0, (0x1F80039C & 0xFFFF)($s0)
    beqz    $t0, .L800B60D0
    addi    $t3, $t0, -0x1
    lhu     $s3, 0x0($a3)
    addiu   $a3, $a3, 0x2
    add     $t1, $t1, $s3
    beqz    $s3, .L800B6080
    sh      $t1, (0x1F80039E & 0xFFFF)($s0)
    lbu     $s6, 0x64($t4)
    .nop
    srlv    $t2, $s6, $t3
    andi    $t2, $t2, 0x1
    lhu     $gp, (0x1F800392 & 0xFFFF)($s0)
    beqz    $t2, .L800B60E0
    .nop
    addiu   $gp, $gp, 0x480
    j       .L800B60E4
    sll     $gp, $gp, 16
.L800B60D0:
    lhu     $s3, 0x6($t4)
    lhu     $gp, (0x1F800392 & 0xFFFF)($s0)
    sub     $s3, $s3, $t1
    beqz    $s3, .L800B6374
.L800B60E0:
    sll     $gp, $gp, 16
.L800B60E4:
    lw      $fp, 0x10($s2)
.L800B60E8:
    lw      $t3, 0x0($s2)
    srl     $v1, $fp, 24
    andi    $v0, $v1, 0x1
    lw      $t7, 0x4($s2)
    andi    $t0, $t3, 0xFFFF
    srl     $t1, $t3, 16
    andi    $t2, $t7, 0xFFFF
    add     $t4, $t0, $a0
    lw      $t4, 0x0($t4)
    add     $t5, $t1, $a0
    lw      $t5, 0x0($t5)
    add     $t6, $t2, $a0
    bnez    $v0, .L800B6170
    lw      $t6, 0x0($t6)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    nclip
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    lw      $t8, 0x8($s2)
    lw      $s0, 0xC($s2)
    mfc2    $v0, $24
    srl     $s0, $s0, 24
    bgtz    $v0, .L800B6194
    addiu   $s3, $s3, -0x1
    beqz    $s3, .L800B606C
    add     $s2, $s2, $s0
    j       .L800B60E8
    lw      $fp, 0x0($s2)
.L800B6170:
    addiu   $s3, $s3, -0x1
    srl     $t3, $t7, 16
    add     $t7, $a0, $t3
    add     $t0, $t0, $a1
    add     $t1, $t1, $a1
    add     $t2, $t2, $a1
    add     $t3, $t3, $a1
    lw      $t8, 0x8($s2)
    .nop
.L800B6194:
    srl     $s0, $t8, 24
    lw      $t0, 0x0($t0)
    ori     $v0, $zero, 0x3C
    lw      $t1, 0x0($t1)
    beq     $s0, $v0, .L800B6284
    lw      $t2, 0x0($t2)
    mtc2    $t0, $17
    mtc2    $t1, $18
    mtc2    $t2, $19
    beqz    $t9, .L800B61D8
    lui     $v1, (0x36000000 >> 16)
    lw      $t1, 0x10($s2)
    or      $t8, $a2, $v1
    or      $t0, $zero, $a2
    and     $t1, $t1, $s5
    j       .L800B61E0
    or      $t1, $t1, $a2
.L800B61D8:
    lw      $t0, 0xC($s2)
    lw      $t1, 0x10($s2)
.L800B61E0:
    avsz3
    sw      $t8, 0x4($s1)
    lw      $t3, 0x14($s2)
    lw      $t8, 0x4($s2)
    srl     $t2, $t3, 16
    srl     $t8, $t8, 16
    or      $t2, $t2, $ra
    or      $t2, $t2, $t9
    andi    $t7, $t3, 0xFFFF
    mfc2    $v0, $7
    sw      $t4, 0x8($s1)
    sltiu   $t4, $v0, 0x7C0
    beqz    $t4, .L800B6274
    or      $t7, $t7, $gp
    sw      $t7, 0xC($s1)
    sw      $t0, 0x10($s1)
    srl     $v1, $t1, 26
    sw      $t5, 0x14($s1)
    andi    $v1, $v1, 0x3
    sw      $t2, 0x18($s1)
    sll     $v1, $v1, 2
    sw      $t1, 0x1C($s1)
    add     $v0, $v0, $v1
    sw      $t6, 0x20($s1)
    sll     $v0, $v0, 2
    sw      $t8, 0x24($s1)
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0x9000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x28
.L800B6274:
    beqz    $s3, .L800B606C
    addiu   $s2, $s2, 0x18
    j       .L800B60E8
    lw      $fp, 0x10($s2)
.L800B6284:
    lw      $t3, 0x0($t3)
    add     $v0, $t0, $t1
    lw      $t7, 0x0($t7)
    add     $v0, $v0, $t2
    add     $v0, $v0, $t3
    srl     $v0, $v0, 4
    sltiu   $s0, $v0, 0x7C0
    beqz    $s0, .L800B6364
    lui     $v1, (0x3E000000 >> 16)
    beqz    $t9, .L800B62C8
    or      $s6, $zero, $a2
    lw      $s0, 0x10($s2)
    or      $t8, $a2, $v1
    or      $v1, $zero, $a2
    and     $s0, $s0, $s5
    j       .L800B62D4
    or      $s0, $s0, $a2
.L800B62C8:
    lw      $v1, 0xC($s2)
    lw      $s0, 0x10($s2)
    lw      $s6, 0x14($s2)
.L800B62D4:
    lw      $t0, 0x18($s2)
    lw      $t2, 0x1C($s2)
    srl     $t1, $t0, 16
    or      $t1, $t1, $ra
    or      $t1, $t1, $t9
    sw      $t8, 0x4($s1)
    andi    $t0, $t0, 0xFFFF
    sw      $t4, 0x8($s1)
    or      $t0, $t0, $gp
    sw      $t0, 0xC($s1)
    sw      $v1, 0x10($s1)
    srl     $t3, $t2, 16
    sw      $t5, 0x14($s1)
    sw      $t1, 0x18($s1)
    srl     $v1, $s0, 26
    sw      $s0, 0x1C($s1)
    andi    $v1, $v1, 0x3
    sw      $t6, 0x20($s1)
    sll     $v1, $v1, 2
    sw      $t2, 0x24($s1)
    add     $v0, $v0, $v1
    sw      $s6, 0x28($s1)
    sw      $t7, 0x2C($s1)
    sll     $v0, $v0, 2
    sw      $t3, 0x30($s1)
    add     $v0, $s7, $v0
    lw      $v1, 0x0($v0)
    lui     $t8, (0xC000000 >> 16)
    and     $t0, $v1, $s4
    or      $t0, $t0, $t8
    sw      $t0, 0x0($s1)
    and     $t1, $s1, $s4
    and     $t0, $v1, $s5
    or      $t0, $t0, $t1
    sw      $t0, 0x0($v0)
    addiu   $s1, $s1, 0x34
.L800B6364:
    beqz    $s3, .L800B606C
    addiu   $s2, $s2, 0x20
    j       .L800B60E8
    lw      $fp, 0x10($s2)
.L800B6374:
    lui     $t0, (0x1F800380 >> 16)
    sw      $s1, (0x1F800000 & 0xFFFF)($t0)
    lw      $s0, (0x1F800358 & 0xFFFF)($t0)
    lw      $s1, (0x1F80035C & 0xFFFF)($t0)
    lw      $s2, (0x1F800360 & 0xFFFF)($t0)
    lw      $s3, (0x1F800364 & 0xFFFF)($t0)
    lw      $s4, (0x1F800368 & 0xFFFF)($t0)
    lw      $s5, (0x1F80036C & 0xFFFF)($t0)
    lw      $s6, (0x1F800370 & 0xFFFF)($t0)
    lw      $s7, (0x1F800374 & 0xFFFF)($t0)
    lw      $ra, (0x1F800378 & 0xFFFF)($t0)
    lw      $gp, (0x1F80037C & 0xFFFF)($t0)
    jr      $ra
    lw      $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B5C30
