.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_8009723C
    lui     $a3, (0x1F8003FC >> 16)
    sw      $fp, (0x1F8003D4 & 0xFFFF)($a3)
    sw      $gp, (0x1F8003D8 & 0xFFFF)($a3)
    sw      $ra, (0x1F8003DC & 0xFFFF)($a3)
    sw      $s0, (0x1F8003E0 & 0xFFFF)($a3)
    sw      $s1, (0x1F8003E4 & 0xFFFF)($a3)
    sw      $s2, (0x1F8003E8 & 0xFFFF)($a3)
    or      $s0, $zero, $a0
    sw      $s3, (0x1F8003EC & 0xFFFF)($a3)
    or      $s1, $zero, $a0
    sw      $s4, (0x1F8003F0 & 0xFFFF)($a3)
    lw      $s2, 0x0($s1)
    sw      $s5, (0x1F8003F4 & 0xFFFF)($a3)
    addiu   $s1, $s1, 0x4
    sw      $s6, (0x1F8003F8 & 0xFFFF)($a3)
    sw      $s7, (0x1F8003FC & 0xFFFF)($a3)
    addu    $s6, $a1, $zero
    lw      $a1, (0x1F800000 & 0xFFFF)($a3)
    lw      $a2, (0x1F800004 & 0xFFFF)($a3)
.L80097288:
    lw      $at, (0x1F800000 & 0xFFFF)($a3)
    lui     $t0, (0x10000 >> 16)
    lw      $v0, 0x0($s1)
    subu    $at, $a1, $at
    lw      $a0, 0x1C($s1)
    subu    $at, $at, $t0
    lw      $v1, (0x1F800010 & 0xFFFF)($a3)
    bgez    $at, .L80097354
    addiu   $s3, $s1, 0x20
    andi    $at, $v0, 0x1100
    bnez    $at, .L80097348
    srl     $at, $v0, 15
    andi    $at, $at, 0x1
    and     $at, $at, $s6
    bnez    $at, .L80097348
    lui     $t0, (0xFFFF6000 >> 16)
    ori     $t0, $t0, (0xFFFF6000 & 0xFFFF)
    xori    $gp, $v0, 0x800
    andi    $gp, $gp, 0x800
    srl     $at, $gp, 11
    srl     $gp, $gp, 10
    or      $gp, $gp, $at
    and     $t0, $t0, $v0
    or      $gp, $gp, $t0
    andi    $at, $v1, 0xFF
    srl     $v1, $v1, 16
    bnez    $v1, .L80097300
    xori    $v0, $v0, 0xFF
    and     $v0, $v0, $at
    bnez    $v0, .L80097348
.L80097300:
    lw      $t0, 0x0($s3)
    lw      $t1, 0x4($s3)
    lw      $t2, 0x8($s3)
    lw      $t3, 0xC($s3)
    ctc2    $t0, $0
    lw      $t4, 0x10($s3)
    ctc2    $t1, $1
    lw      $t5, 0x14($s3)
    ctc2    $t2, $2
    lw      $t6, 0x18($s3)
    ctc2    $t3, $3
    lw      $t7, 0x1C($s3)
    ctc2    $t4, $4
    ctc2    $t5, $5
    ctc2    $t6, $6
    ctc2    $t7, $7
    addu    $a0, $a0, $s0
    jal     func_80097388
.L80097348:
    addiu   $s2, $s2, -0x1
    bnez    $s2, .L80097288
    addiu   $s1, $s1, 0x40
.L80097354:
    sw      $a1, (0x1F800000 & 0xFFFF)($a3)
    lw      $fp, (0x1F8003D4 & 0xFFFF)($a3)
    lw      $gp, (0x1F8003D8 & 0xFFFF)($a3)
    lw      $ra, (0x1F8003DC & 0xFFFF)($a3)
    lw      $s0, (0x1F8003E0 & 0xFFFF)($a3)
    lw      $s1, (0x1F8003E4 & 0xFFFF)($a3)
    lw      $s2, (0x1F8003E8 & 0xFFFF)($a3)
    lw      $s3, (0x1F8003EC & 0xFFFF)($a3)
    lw      $s4, (0x1F8003F0 & 0xFFFF)($a3)
    lw      $s5, (0x1F8003F4 & 0xFFFF)($a3)
    lw      $s6, (0x1F8003F8 & 0xFFFF)($a3)
    jr      $ra
    lw      $s7, (0x1F8003FC & 0xFFFF)($a3)
endlabel func_8009723C

# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_80097388
    sw      $ra, 0x3C4($a3)
    sw      $s0, 0x3C8($a3)
    sw      $s1, 0x3CC($a3)
    sw      $s2, 0x3D0($a3)
    lw      $at, 0x4($a0)
    lw      $v0, 0x0($a0)
    sll     $at, $at, 16
    or      $v0, $v0, $at
    jal     func_8009797C
    addiu   $a0, $a0, 0x8
    andi    $at, $v0, 0xFFFF
    beqz    $at, .L800975F0
    addu    $a3, $a0, $zero
.L800973BC:
    lw      $s7, 0xC($a0)
    jal     func_80097A10
    addiu   $a3, $a3, 0x20
    bgez    $at, .L800973DC
    lui     $t0, (0x1000000 >> 16)
    and     $t0, $t0, $s7
    beqz    $t0, .L800975E0
    negu    $at, $at
.L800973DC:
    addu    $fp, $at, $zero
    mfc2    $t0, $12
    mfc2    $t1, $13
    mfc2    $t2, $14
    jal     func_80098014
    addu    $t3, $t2, $zero
    beqz    $at, .L800975E0
    andi    $at, $s6, 0x1
    beqz    $at, .L80097544
    sltiu   $at, $fp, 0x200
    bnez    $at, .L80097544
    srl     $t4, $gp, 13
    andi    $t4, $t4, 0x3
    srl     $at, $t9, 9
    subu    $at, $t4, $at
    blez    $at, .L80097544
    lui     $fp, (0x1F800390 >> 16)
    ori     $fp, $fp, (0x1F800390 & 0xFFFF)
    sw      $s0, 0x0($fp)
    sw      $s1, 0x4($fp)
    sw      $s2, 0x8($fp)
    sw      $s3, 0xC($fp)
    sw      $s4, 0x10($fp)
    sw      $s5, 0x14($fp)
    addiu   $fp, $fp, -0x4C
    addiu   $s0, $fp, 0x10
    addiu   $s1, $fp, 0x24
    addiu   $s2, $fp, 0x38
    sw      $at, 0x0($fp)
    sw      $s0, 0x4($fp)
    sw      $s1, 0x8($fp)
    sw      $s2, 0xC($fp)
    swc2    $0, 0x0($s0)
    swc2    $2, 0x0($s1)
    swc2    $4, 0x0($s2)
    mfc2    $t4, $1
    mfc2    $t5, $3
    mfc2    $t6, $5
    sh      $t4, 0x4($s0)
    sh      $t5, 0x4($s1)
    sh      $t6, 0x4($s2)
    lw      $t4, 0x10($a0)
    lw      $t5, 0x14($a0)
    lw      $t6, 0x18($a0)
    lw      $t7, 0x1C($a0)
    sw      $t0, 0xC($s0)
    sw      $t1, 0xC($s1)
    sw      $t2, 0xC($s2)
    swc2    $17, 0x10($s0)
    swc2    $18, 0x10($s1)
    swc2    $19, 0x10($s2)
    lui     $t8, (0xFFFFFF >> 16)
    ori     $t8, $t8, (0xFFFFFF & 0xFFFF)
    lui     $t9, (0x1000000 >> 16)
    and     $at, $s7, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s0)
    and     $at, $t4, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s1)
    and     $at, $t5, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s2)
    lui     $t8, (0xFE000000 >> 16)
    lui     $t9, (0x1F8003BC >> 16)
    and     $at, $s7, $t8
    sw      $at, (0x1F8003B8 & 0xFFFF)($t9)
    lui     $t8, (0xFFFF0000 >> 16)
    and     $at, $t6, $t8
    sw      $at, (0x1F8003C0 & 0xFFFF)($t9)
    and     $at, $t7, $t8
    sw      $at, (0x1F8003BC & 0xFFFF)($t9)
    andi    $t6, $t6, 0xFFFF
    sh      $t6, 0x6($s0)
    andi    $t7, $t7, 0xFFFF
    sh      $t7, 0x6($s1)
    srl     $t4, $t4, 24
    srl     $t5, $t5, 24
    sll     $t5, $t5, 8
    or      $t4, $t4, $t5
    jal     func_80097AEC
    sh      $t4, 0x6($s2)
    addiu   $fp, $fp, 0x4C
    lw      $s0, 0x0($fp)
    lw      $s1, 0x4($fp)
    lw      $s2, 0x8($fp)
    lw      $s3, 0xC($fp)
    lw      $s4, 0x10($fp)
    b       .L800975E0
    lw      $s5, 0x14($fp)
.L80097544:
    sw      $t0, 0x8($a1)
    jal     func_800980F8
    lui     $v1, (0x9000000 >> 16)
    sw      $t1, 0x14($a1)
    beqz    $at, .L800975E0
    sw      $t2, 0x20($a1)
    lw      $t0, 0x10($a0)
    lw      $t1, 0x14($a0)
    lw      $t2, 0x18($a0)
    lw      $t3, 0x1C($a0)
    lui     $at, (0xFEFFFFFF >> 16)
    ori     $at, $at, (0xFEFFFFFF & 0xFFFF)
    and     $s7, $s7, $at
    sw      $s7, 0x4($a1)
    srl     $t4, $t0, 24
    sw      $t0, 0x10($a1)
    srl     $t5, $t1, 24
    sw      $t1, 0x1C($a1)
    sll     $t5, $t5, 8
alabel D_80097590
    sltiu   $at, $t9, 0x200
    bnez    $at, .L800975D0
    or      $t4, $t4, $t5
    lui     $t9, (0xFFFF0000 >> 16)
    srl     $t8, $t2, 1
    andi    $t8, $t8, 0x7F7F
    and     $t2, $t2, $t9
    or      $t2, $t2, $t8
    srl     $t8, $t3, 1
    andi    $t8, $t8, 0x7F7F
    srl     $t3, $t3, 16
    addiu   $t3, $t3, -0x1
    sll     $t3, $t3, 16
    or      $t3, $t3, $t8
    srl     $t4, $t4, 1
    andi    $t4, $t4, 0x7F7F
.L800975D0:
    sw      $t2, 0xC($a1)
    sw      $t3, 0x18($a1)
    sw      $t4, 0x24($a1)
    addiu   $a1, $a1, 0x28
.L800975E0:
    addiu   $v0, $v0, -0x1
    andi    $at, $v0, 0xFFFF
    bnez    $at, .L800973BC
    addiu   $a0, $a0, 0x20
.L800975F0:
    srl     $v0, $v0, 16
    beqz    $v0, .L80097960
.L800975F8:
    lw      $s7, 0xC($a0)
    jal     func_80097A10
    addiu   $a3, $a3, 0x28
    bltz    $at, .L80097610
    lui     $t0, (0x1000000 >> 16)
    or      $s7, $s7, $t0
.L80097610:
    addu    $fp, $at, $zero
    lw      $t8, 0x20($a0)
    mfc2    $t0, $0
    mfc2    $t2, $1
    mthi    $t0
    mtlo    $t2
    sra     $t1, $t0, 16
    sll     $t0, $t0, 16
    sra     $t0, $t0, 16
    sll     $t3, $t8, 24
    sll     $t4, $t8, 16
    sll     $t5, $t8, 8
    sra     $t3, $t3, 24
    sra     $t4, $t4, 24
    sra     $t5, $t5, 24
    sllv    $t3, $t3, $gp
    sllv    $t4, $t4, $gp
    sllv    $t5, $t5, $gp
    addu    $t0, $t0, $t3
    addu    $t1, $t1, $t4
    addu    $t2, $t2, $t5
    andi    $t0, $t0, 0xFFFF
    sll     $t1, $t1, 16
    or      $t0, $t0, $t1
    mtc2    $t0, $0
    mtc2    $t2, $1
    lui     $at, (0x1F8003B4 >> 16)
    mfc2    $t0, $12
    mfc2    $t1, $13
    mfc2    $t2, $14
    swc2    $17, (0x1F8003AC & 0xFFFF)($at)
    swc2    $18, (0x1F8003B0 & 0xFFFF)($at)
    swc2    $19, (0x1F8003B4 & 0xFFFF)($at)
    rtps
    mfc2    $t3, $14
    jal     func_80098014
    .nop
    beqz    $at, .L80097954
    lui     $t4, (0x1000000 >> 16)
    and     $t4, $t4, $s7
    bnez    $t4, .L800976DC
    .nop
    mtc2    $t3, $12
    mtc2    $t2, $13
    mtc2    $t1, $14
    .nop
    .nop
    nclip
    mfc2    $fp, $24
    .nop
    bltz    $fp, .L80097954
.L800976DC:
    andi    $at, $s6, 0x1
    beqz    $at, .L8009787C
    sltiu   $at, $fp, 0x200
    bnez    $at, .L8009787C
    srl     $t4, $gp, 13
    andi    $t4, $t4, 0x3
    srl     $at, $t9, 9
    subu    $at, $t4, $at
    blez    $at, .L8009787C
    lui     $fp, (0x1F800390 >> 16)
    ori     $fp, $fp, (0x1F800390 & 0xFFFF)
    sw      $s0, 0x0($fp)
    sw      $s1, 0x4($fp)
    sw      $s2, 0x8($fp)
    sw      $s3, 0xC($fp)
    sw      $s4, 0x10($fp)
    sw      $s5, 0x14($fp)
    addiu   $fp, $fp, -0x64
    addiu   $s0, $fp, 0x14
    addiu   $s1, $fp, 0x28
    addiu   $s2, $fp, 0x3C
    addiu   $s3, $fp, 0x50
    sw      $at, 0x0($fp)
    sw      $s0, 0x4($fp)
    sw      $s1, 0x8($fp)
    sw      $s2, 0xC($fp)
    sw      $s3, 0x10($fp)
    mfhi    $at
    swc2    $2, 0x0($s1)
    swc2    $4, 0x0($s2)
    swc2    $0, 0x0($s3)
    sw      $at, 0x0($s0)
    mflo    $at
    mfc2    $t7, $1
    mfc2    $t5, $3
    mfc2    $t6, $5
    sh      $at, 0x4($s0)
    sh      $t7, 0x4($s3)
    sh      $t6, 0x4($s2)
    sh      $t5, 0x4($s1)
    lw      $t4, 0x10($a0)
    lw      $t5, 0x14($a0)
    lw      $t6, 0x18($a0)
    lw      $t7, 0x1C($a0)
    sw      $t0, 0xC($s0)
    sw      $t1, 0xC($s1)
    sw      $t2, 0xC($s2)
    sw      $t3, 0xC($s3)
    lui     $at, (0x1F8003B4 >> 16)
    lw      $t3, 0x24($a0)
    lw      $t0, (0x1F8003AC & 0xFFFF)($at)
    lw      $t1, (0x1F8003B0 & 0xFFFF)($at)
    lw      $t2, (0x1F8003B4 & 0xFFFF)($at)
    sw      $t0, 0x10($s0)
    sw      $t1, 0x10($s1)
    sw      $t2, 0x10($s2)
    swc2    $19, 0x10($s3)
    srl     $t0, $t8, 24
    srl     $t1, $t3, 24
    sll     $t1, $t1, 8
    or      $t0, $t0, $t1
    sh      $t0, 0x6($s3)
    lui     $t9, (0x1000000 >> 16)
    lui     $t8, (0xFFFFFF >> 16)
    ori     $t8, $t8, (0xFFFFFF & 0xFFFF)
    and     $at, $s7, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s0)
    and     $at, $t4, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s1)
    and     $at, $t5, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s2)
    and     $at, $t3, $t8
    or      $at, $at, $t9
    sw      $at, 0x8($s3)
    lui     $t9, (0x1F8003BC >> 16)
    lui     $t8, (0xFE000000 >> 16)
    and     $at, $s7, $t8
    sw      $at, (0x1F8003B8 & 0xFFFF)($t9)
    lui     $t8, (0xFFFF0000 >> 16)
    and     $at, $t6, $t8
    sw      $at, (0x1F8003C0 & 0xFFFF)($t9)
    and     $at, $t7, $t8
    sw      $at, (0x1F8003BC & 0xFFFF)($t9)
    andi    $t6, $t6, 0xFFFF
    sh      $t6, 0x6($s0)
    andi    $t7, $t7, 0xFFFF
    sh      $t7, 0x6($s1)
    srl     $t4, $t4, 24
    srl     $t5, $t5, 24
    sll     $t5, $t5, 8
    or      $t4, $t4, $t5
    jal     func_80097CF0
    sh      $t4, 0x6($s2)
    addiu   $fp, $fp, 0x64
    lw      $s0, 0x0($fp)
    lw      $s1, 0x4($fp)
    lw      $s2, 0x8($fp)
    lw      $s3, 0xC($fp)
    lw      $s4, 0x10($fp)
    b       .L80097954
    lw      $s5, 0x14($fp)
.L8009787C:
    mfc2    $v1, $19
    sw      $t0, 0x8($a1)
    slt     $at, $v1, $t9
    bnez    $at, .L80097894
    .nop
    or      $t9, $zero, $v1
.L80097894:
    jal     func_800980F8
    lui     $v1, (0xC000000 >> 16)
    sw      $t1, 0x14($a1)
    beqz    $at, .L80097954
    sw      $t2, 0x20($a1)
    sw      $t3, 0x2C($a1)
    lw      $t0, 0x10($a0)
    lw      $t1, 0x14($a0)
    lw      $t2, 0x18($a0)
    lw      $t3, 0x1C($a0)
    lw      $t7, 0x24($a0)
    lui     $at, (0xFEFFFFFF >> 16)
    ori     $at, $at, (0xFEFFFFFF & 0xFFFF)
    sw      $t7, 0x28($a1)
    srl     $t7, $t7, 24
    sll     $t7, $t7, 8
    srl     $t8, $t8, 24
    or      $t7, $t7, $t8
    and     $s7, $s7, $at
    sw      $s7, 0x4($a1)
    srl     $t4, $t0, 24
    sw      $t0, 0x10($a1)
    srl     $t5, $t1, 24
    sw      $t1, 0x1C($a1)
    sll     $t5, $t5, 8
alabel D_800978F8
    sltiu   $at, $t9, 0x200
    bnez    $at, .L80097940
    or      $t4, $t4, $t5
    lui     $t9, (0xFFFF0000 >> 16)
    srl     $t8, $t2, 1
    andi    $t8, $t8, 0x7F7F
    and     $t2, $t2, $t9
    or      $t2, $t2, $t8
    srl     $t8, $t3, 1
    andi    $t8, $t8, 0x7F7F
    srl     $t3, $t3, 16
    addiu   $t3, $t3, -0x1
    sll     $t3, $t3, 16
    or      $t3, $t3, $t8
    srl     $t4, $t4, 1
    andi    $t4, $t4, 0x7F7F
    srl     $t7, $t7, 1
    andi    $t7, $t7, 0x7F7F
.L80097940:
    sw      $t2, 0xC($a1)
    sw      $t3, 0x18($a1)
    sw      $t4, 0x24($a1)
    sw      $t7, 0x30($a1)
    addiu   $a1, $a1, 0x34
.L80097954:
    addiu   $v0, $v0, -0x1
    bnez    $v0, .L800975F8
    addiu   $a0, $a0, 0x28
.L80097960:
    lui     $a3, (0x1F8003D0 >> 16)
    lw      $ra, (0x1F8003C4 & 0xFFFF)($a3)
    lw      $s0, (0x1F8003C8 & 0xFFFF)($a3)
    lw      $s1, (0x1F8003CC & 0xFFFF)($a3)
    lw      $s2, (0x1F8003D0 & 0xFFFF)($a3)
    jr      $ra
    .nop
endlabel func_80097388

# hasm: reserved register usage
# hasm: temp register usage
glabel func_8009797C
    lw      $s0, 0x0($a0)
    lw      $s4, 0x4($a0)
    lw      $s5, 0x8($a0)
    sll     $t9, $s0, 16
    sra     $t9, $t9, 16
    sra     $t8, $s0, 16
    sll     $s1, $s4, 16
    sra     $s1, $s1, 16
    sll     $t7, $s4, 8
    sra     $t7, $t7, 24
    sllv    $t7, $t7, $gp
    addu    $t7, $t7, $t9
    sra     $at, $s4, 24
    sllv    $at, $at, $gp
    addu    $at, $at, $t8
    andi    $t7, $t7, 0xFFFF
    sll     $at, $at, 16
    or      $s2, $at, $t7
    sll     $s3, $s5, 24
    sra     $s3, $s3, 24
    sllv    $s3, $s3, $gp
    addu    $s3, $s3, $s1
    sll     $t7, $s5, 16
    sra     $t7, $t7, 24
    sllv    $t7, $t7, $gp
    addu    $t7, $t7, $t9
    sll     $at, $s5, 8
    sra     $at, $at, 24
    sllv    $at, $at, $gp
    addu    $at, $at, $t8
    andi    $t7, $t7, 0xFFFF
    sll     $at, $at, 16
    or      $s4, $at, $t7
    sra     $s5, $s5, 24
    sllv    $s5, $s5, $gp
    jr      $ra
    addu    $s5, $s5, $s1
endlabel func_8009797C

# hasm: reserved register usage
# hasm: temp register usage
glabel func_80097A10
    mtc2    $s0, $0
    mtc2    $s1, $1
    mtc2    $s2, $2
    mtc2    $s3, $3
    mtc2    $s4, $4
    mtc2    $s5, $5
    lw      $s0, 0x0($a3)
    lw      $s4, 0x4($a3)
    rtpt
    lw      $s5, 0x8($a3)
    sll     $t9, $s0, 16
    sra     $t9, $t9, 16
    sra     $t8, $s0, 16
    sll     $s1, $s4, 16
    sra     $s1, $s1, 16
    sll     $t7, $s4, 8
    sra     $t7, $t7, 24
    sllv    $t7, $t7, $gp
    addu    $t7, $t7, $t9
    sra     $at, $s4, 24
    sllv    $at, $at, $gp
    addu    $at, $at, $t8
    andi    $t7, $t7, 0xFFFF
    sll     $at, $at, 16
    or      $s2, $at, $t7
    sll     $s3, $s5, 24
    sra     $s3, $s3, 24
    sllv    $s3, $s3, $gp
    addu    $s3, $s3, $s1
    sll     $t7, $s5, 16
    sra     $t7, $t7, 24
    sllv    $t7, $t7, $gp
    nclip
    addu    $t7, $t7, $t9
    sll     $at, $s5, 8
    sra     $at, $at, 24
    sllv    $at, $at, $gp
    addu    $at, $at, $t8
    andi    $t7, $t7, 0xFFFF
    sll     $at, $at, 16
    or      $s4, $at, $t7
    mfc2    $t9, $17
    mfc2    $t8, $18
    mfc2    $t7, $19
    slt     $at, $t8, $t9
    bnez    $at, .L80097AD0
    sra     $s5, $s5, 24
    or      $t9, $zero, $t8
.L80097AD0:
    slt     $at, $t7, $t9
    bnez    $at, .L80097AE0
    sllv    $s5, $s5, $gp
    or      $t9, $zero, $t7
.L80097AE0:
    mfc2    $at, $24
    jr      $ra
    addu    $s5, $s5, $s1
endlabel func_80097A10

# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_80097AEC
    addiu   $fp, $fp, -0x2C
    sw      $ra, 0x0($fp)
    sw      $t0, 0x4($fp)
    sw      $t1, 0x8($fp)
    sw      $t2, 0xC($fp)
    sw      $t3, 0x10($fp)
    sw      $t4, 0x14($fp)
    sw      $t5, 0x18($fp)
    sw      $t6, 0x1C($fp)
    sw      $t7, 0x20($fp)
    sw      $t9, 0x28($fp)
    lw      $t9, 0x2C($fp)
    lw      $t0, 0x30($fp)
    lw      $t1, 0x34($fp)
    lw      $t2, 0x38($fp)
    addu    $s0, $t0, $zero
    bnez    $t9, .L80097BF4
    addu    $s1, $t1, $zero
    addu    $s2, $t2, $zero
    lw      $t0, 0xC($s0)
    lw      $t1, 0xC($s1)
    lw      $t2, 0xC($s2)
    jal     func_80098014
    addu    $t3, $t2, $zero
    beqz    $at, .L80097CC0
    lh      $t9, 0x10($s0)
    lh      $t4, 0x10($s1)
    lh      $t5, 0x10($s2)
    sw      $t0, 0x8($a1)
    slt     $at, $t4, $t9
    bnez    $at, .L80097B70
    sw      $t1, 0x14($a1)
    or      $t9, $zero, $t4
.L80097B70:
    slt     $at, $t5, $t9
    bnez    $at, .L80097B80
    sw      $t2, 0x20($a1)
    or      $t9, $zero, $t5
.L80097B80:
    jal     func_800980F8
    lui     $v1, (0x9000000 >> 16)
    beqz    $at, .L80097CC0
    lui     $v1, (0x1F8003B8 >> 16)
    lhu     $t0, 0x6($s0)
    lw      $t3, (0x1F8003C0 & 0xFFFF)($v1)
    lhu     $t1, 0x6($s1)
    lw      $t4, (0x1F8003BC & 0xFFFF)($v1)
    lhu     $t2, 0x6($s2)
    or      $t0, $t0, $t3
    or      $t1, $t1, $t4
    sw      $t0, 0xC($a1)
    sw      $t1, 0x18($a1)
    sw      $t2, 0x24($a1)
    lw      $t3, (0x1F8003B8 & 0xFFFF)($v1)
    lui     $t4, (0xF7000000 >> 16)
    lui     $t5, (0xFFFFFF >> 16)
    ori     $t5, $t5, (0xFFFFFF & 0xFFFF)
    lw      $t0, 0x8($s0)
    lw      $t1, 0x8($s1)
    lw      $t2, 0x8($s2)
    and     $t3, $t3, $t4
    and     $t0, $t0, $t5
    or      $t0, $t0, $t3
    sw      $t0, 0x4($a1)
    sw      $t1, 0x10($a1)
    sw      $t2, 0x1C($a1)
    b       .L80097CC0
    addiu   $a1, $a1, 0x28
.L80097BF4:
    addiu   $fp, $fp, -0x4C
    addiu   $t4, $fp, 0x10
    addiu   $t5, $fp, 0x24
    addiu   $t6, $fp, 0x38
    jal     func_80097F70
    addu    $s2, $t4, $zero
    lwc2    $0, 0x0($t4)
    lwc2    $1, 0x4($t4)
    addu    $s0, $t2, $zero
    jal     func_80097F70
    addu    $s2, $t5, $zero
    lwc2    $2, 0x0($t5)
    lwc2    $3, 0x4($t5)
    addu    $s1, $t0, $zero
    jal     func_80097F70
    addu    $s2, $t6, $zero
    lwc2    $4, 0x0($t6)
    lwc2    $5, 0x4($t6)
    addiu   $t9, $t9, -0x1
    sw      $t9, 0x0($fp)
    rtpt
    sw      $t0, 0x4($fp)
    sw      $t4, 0x8($fp)
    swc2    $12, 0xC($t4)
    swc2    $13, 0xC($t5)
    swc2    $14, 0xC($t6)
    swc2    $17, 0x10($t4)
    swc2    $18, 0x10($t5)
    swc2    $19, 0x10($t6)
    jal     func_80097AEC
    sw      $t6, 0xC($fp)
    sw      $t5, 0x4($fp)
    jal     func_80097AEC
    sw      $t1, 0xC($fp)
    sw      $t2, 0x8($fp)
    jal     func_80097AEC
    sw      $t6, 0xC($fp)
    sw      $t4, 0x4($fp)
    jal     func_80097AEC
    sw      $t5, 0x8($fp)
    sw      $zero, 0x0($fp)
    sw      $t2, 0x4($fp)
    jal     func_80097AEC
    sw      $t0, 0x8($fp)
    sw      $t5, 0x8($fp)
    jal     func_80097AEC
    sw      $t1, 0xC($fp)
    sw      $t4, 0x4($fp)
    jal     func_80097AEC
    sw      $t0, 0x8($fp)
    addiu   $fp, $fp, 0x4C
.L80097CC0:
    lw      $ra, 0x0($fp)
    lw      $t0, 0x4($fp)
    lw      $t1, 0x8($fp)
    lw      $t2, 0xC($fp)
    lw      $t3, 0x10($fp)
    lw      $t4, 0x14($fp)
    lw      $t5, 0x18($fp)
    lw      $t6, 0x1C($fp)
    lw      $t7, 0x20($fp)
    lw      $t9, 0x28($fp)
    jr      $ra
    addiu   $fp, $fp, 0x2C
endlabel func_80097AEC

# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_80097CF0
    addiu   $fp, $fp, -0x2C
    sw      $ra, 0x0($fp)
    sw      $t0, 0x4($fp)
    sw      $t1, 0x8($fp)
    sw      $t2, 0xC($fp)
    sw      $t3, 0x10($fp)
    sw      $t4, 0x14($fp)
    sw      $t5, 0x18($fp)
    sw      $t6, 0x1C($fp)
    sw      $t7, 0x20($fp)
    sw      $t8, 0x24($fp)
    sw      $t9, 0x28($fp)
    lw      $t9, 0x2C($fp)
    lw      $t0, 0x30($fp)
    lw      $t1, 0x34($fp)
    lw      $t2, 0x38($fp)
    lw      $t3, 0x3C($fp)
    addu    $s0, $t0, $zero
    bnez    $t9, .L80097E20
    addu    $s1, $t1, $zero
    addu    $s2, $t2, $zero
    addu    $s3, $t3, $zero
    lw      $t0, 0xC($s0)
    lw      $t1, 0xC($s1)
    lw      $t2, 0xC($s2)
    jal     func_80098014
    lw      $t3, 0xC($s3)
    beqz    $at, .L80097F3C
    lh      $t9, 0x10($s0)
    lh      $t4, 0x10($s1)
    lh      $t5, 0x10($s2)
    lh      $t6, 0x10($s3)
    sw      $t0, 0x8($a1)
    slt     $at, $t4, $t9
    bnez    $at, .L80097D84
    sw      $t1, 0x14($a1)
    or      $t9, $zero, $t4
.L80097D84:
    slt     $at, $t5, $t9
    bnez    $at, .L80097D94
    sw      $t2, 0x20($a1)
    or      $t9, $zero, $t5
.L80097D94:
    slt     $at, $t6, $t9
    bnez    $at, .L80097DA4
    sw      $t3, 0x2C($a1)
    or      $t9, $zero, $t6
.L80097DA4:
    jal     func_800980F8
    lui     $v1, (0xC000000 >> 16)
    beqz    $at, .L80097F3C
    lui     $v1, (0x1F8003B8 >> 16)
    lw      $t4, (0x1F8003C0 & 0xFFFF)($v1)
    lw      $t5, (0x1F8003BC & 0xFFFF)($v1)
    lhu     $t0, 0x6($s0)
    lhu     $t1, 0x6($s1)
    lhu     $t2, 0x6($s2)
    lhu     $t3, 0x6($s3)
    or      $t0, $t0, $t4
    or      $t1, $t1, $t5
    sw      $t0, 0xC($a1)
    sw      $t1, 0x18($a1)
    sw      $t2, 0x24($a1)
    sw      $t3, 0x30($a1)
    lw      $t4, (0x1F8003B8 & 0xFFFF)($v1)
    lui     $t5, (0xFFFFFF >> 16)
    ori     $t5, $t5, (0xFFFFFF & 0xFFFF)
    lw      $t0, 0x8($s0)
    lw      $t1, 0x8($s1)
    lw      $t2, 0x8($s2)
    lw      $t3, 0x8($s3)
    and     $t0, $t0, $t5
    or      $t0, $t0, $t4
    sw      $t0, 0x4($a1)
    sw      $t1, 0x10($a1)
    sw      $t2, 0x1C($a1)
    sw      $t3, 0x28($a1)
    b       .L80097F3C
    addiu   $a1, $a1, 0x34
.L80097E20:
    addiu   $fp, $fp, -0x78
    addiu   $t4, $fp, 0x14
    addiu   $t5, $fp, 0x28
    addiu   $t6, $fp, 0x3C
    addiu   $t7, $fp, 0x50
    addiu   $t8, $fp, 0x64
    jal     func_80097F70
    addu    $s2, $t4, $zero
    lwc2    $0, 0x0($t4)
    lwc2    $1, 0x4($t4)
    addu    $s0, $t2, $zero
    jal     func_80097F70
    addu    $s2, $t8, $zero
    lwc2    $2, 0x0($t8)
    lwc2    $3, 0x4($t8)
    addu    $s0, $t3, $zero
    jal     func_80097F70
    addu    $s2, $t5, $zero
    lwc2    $4, 0x0($t5)
    lwc2    $5, 0x4($t5)
    addiu   $t9, $t9, -0x1
    addu    $s1, $t2, $zero
    rtpt
    jal     func_80097F70
    addu    $s2, $t6, $zero
    lwc2    $0, 0x0($t6)
    lwc2    $1, 0x4($t6)
    swc2    $12, 0xC($t4)
    swc2    $13, 0xC($t8)
    swc2    $14, 0xC($t5)
    swc2    $17, 0x10($t4)
    swc2    $18, 0x10($t8)
    swc2    $19, 0x10($t5)
    addu    $s0, $t0, $zero
    jal     func_80097F70
    addu    $s2, $t7, $zero
    lwc2    $2, 0x0($t7)
    lwc2    $3, 0x4($t7)
    sw      $t9, 0x0($fp)
    sw      $t0, 0x4($fp)
    rtpt
    sw      $t4, 0x8($fp)
    sw      $t7, 0xC($fp)
    swc2    $12, 0xC($t6)
    swc2    $13, 0xC($t7)
    swc2    $17, 0x10($t6)
    swc2    $18, 0x10($t7)
    jal     func_80097CF0
    sw      $t8, 0x10($fp)
    sw      $t1, 0x4($fp)
    jal     func_80097CF0
    sw      $t5, 0xC($fp)
    sw      $t3, 0x4($fp)
    jal     func_80097CF0
    sw      $t6, 0x8($fp)
    sw      $t2, 0x4($fp)
    jal     func_80097CF0
    sw      $t7, 0xC($fp)
    sw      $zero, 0x0($fp)
    jal     func_80097AEC
    sw      $t3, 0xC($fp)
    sw      $t0, 0x8($fp)
    jal     func_80097AEC
    sw      $t7, 0xC($fp)
    sw      $t4, 0x4($fp)
    jal     func_80097AEC
    sw      $t1, 0xC($fp)
    sw      $t3, 0x4($fp)
    jal     func_80097AEC
    sw      $t5, 0x8($fp)
    addiu   $fp, $fp, 0x78
.L80097F3C:
    lw      $ra, 0x0($fp)
    lw      $t0, 0x4($fp)
    lw      $t1, 0x8($fp)
    lw      $t2, 0xC($fp)
    lw      $t3, 0x10($fp)
    lw      $t4, 0x14($fp)
    lw      $t5, 0x18($fp)
    lw      $t6, 0x1C($fp)
    lw      $t7, 0x20($fp)
    lw      $t8, 0x24($fp)
    lw      $t9, 0x28($fp)
    jr      $ra
    addiu   $fp, $fp, 0x2C
endlabel func_80097CF0

# hasm: reserved register usage
glabel func_80097F70
    lbu     $s3, 0x8($s0)
    lbu     $s4, 0x8($s1)
    lbu     $s5, 0x9($s0)
    lbu     $at, 0x9($s1)
    addu    $s3, $s3, $s4
    srl     $s3, $s3, 1
    sb      $s3, 0x8($s2)
    lbu     $s3, 0xA($s0)
    lbu     $s4, 0xA($s1)
    addu    $s5, $s5, $at
    srl     $s5, $s5, 1
    sb      $s5, 0x9($s2)
    addu    $s3, $s3, $s4
    srl     $s3, $s3, 1
    sb      $s3, 0xA($s2)
    lh      $s3, 0x0($s0)
    lh      $s4, 0x0($s1)
    lh      $s5, 0x2($s0)
    lh      $at, 0x2($s1)
    addu    $s3, $s3, $s4
    sra     $s3, $s3, 1
    addu    $s5, $s5, $at
    sra     $s5, $s5, 1
    sh      $s3, 0x0($s2)
    sh      $s5, 0x2($s2)
    lh      $s3, 0x4($s0)
    lh      $s4, 0x4($s1)
    lbu     $s5, 0x6($s0)
    lbu     $at, 0x6($s1)
    addu    $s3, $s3, $s4
    sra     $s3, $s3, 1
    lbu     $s4, 0x7($s0)
    addu    $s5, $s5, $at
    lbu     $at, 0x7($s1)
    sra     $s5, $s5, 1
    sh      $s3, 0x4($s2)
    sb      $s5, 0x6($s2)
    addu    $s4, $s4, $at
    sra     $s4, $s4, 1
    jr      $ra
    sb      $s4, 0x7($s2)
endlabel func_80097F70

# hasm: unconditional b branch
# hasm: custom register abi
# hasm: reserved register usage
# hasm: temp register usage
glabel func_80098014
    sra     $t4, $t0, 16
    sra     $t5, $t1, 16
    sra     $t6, $t2, 16
    sra     $t7, $t3, 16
    slti    $at, $t4, 0xE0
    bnez    $at, .L8009804C
    slti    $at, $t5, 0xE0
    bnez    $at, .L8009804C
    slti    $at, $t6, 0xE0
    bnez    $at, .L8009804C
    slti    $at, $t7, 0xE0
    bnez    $at, .L8009804C
    .nop
    b       .L800980F0
.L8009804C:
    slti    $at, $t4, 0x0
    beqz    $at, .L80098074
    slti    $at, $t5, 0x0
    beqz    $at, .L80098074
    slti    $at, $t6, 0x0
    beqz    $at, .L80098074
    slti    $at, $t7, 0x0
    beqz    $at, .L80098074
    .nop
    b       .L800980F0
.L80098074:
    sll     $t4, $t0, 16
    sll     $t5, $t1, 16
    sll     $t6, $t2, 16
    sll     $t7, $t3, 16
    sra     $t4, $t4, 16
    sra     $t5, $t5, 16
    sra     $t6, $t6, 16
    sra     $t7, $t7, 16
    slti    $at, $t4, 0x0
    beqz    $at, .L800980BC
    slti    $at, $t5, 0x0
    beqz    $at, .L800980BC
    slti    $at, $t6, 0x0
    beqz    $at, .L800980BC
    slti    $at, $t7, 0x0
    beqz    $at, .L800980BC
    .nop
    b       .L800980F0
.L800980BC:
    slti    $at, $t4, 0x140
    bnez    $at, .L800980E8
    slti    $at, $t5, 0x140
    bnez    $at, .L800980E8
    slti    $at, $t6, 0x140
    bnez    $at, .L800980E8
    slti    $at, $t7, 0x140
    bnez    $at, .L800980E8
    .nop
    b       .L800980F0
    .nop
.L800980E8:
    jr      $ra
    ori     $at, $zero, 0x1
.L800980F0:
    jr      $ra
    or      $at, $zero, $zero
endlabel func_80098014

# hasm: custom register abi
# hasm: reserved register usage
glabel func_800980F8
    srl     $t9, $t9, 2
    slti    $at, $t9, 0x8
    bnez    $at, .L80098158
    sra     $at, $gp, 16
    addu    $t9, $t9, $at
    slti    $at, $t9, 0x7FF
    beqz    $at, .L80098158
    slti    $at, $t9, 0x8
    bnez    $at, .L80098158
    sll     $t6, $t9, 2
    lui     $t4, (0xFFFFFF >> 16)
    addu    $t6, $t6, $a2
    lw      $t7, 0x0($t6)
    ori     $t4, $t4, (0xFFFFFF & 0xFFFF)
    lui     $t5, (0xFF000000 >> 16)
    and     $at, $t7, $t4
    or      $at, $at, $v1
    sw      $at, 0x0($a1)
    and     $at, $a1, $t4
    and     $t7, $t7, $t5
    or      $t7, $t7, $at
    sw      $t7, 0x0($t6)
    jr      $ra
    ori     $at, $zero, 0x1
.L80098158:
    jr      $ra
    or      $at, $zero, $zero
endlabel func_800980F8

# hasm: code patching
glabel func_80098160
    lui     $v0, %hi(func_800980F8)
    addiu   $v0, $v0, %lo(func_800980F8)
    .nop
    sh      $a0, 0x4($v0)
    sh      $a0, 0x1C($v0)
    jr      $ra
    .nop
endlabel func_80098160

# hasm: code patching
glabel func_8009817C
    lui     $v0, %hi(func_800980F8)
    addiu   $v0, $v0, %lo(func_800980F8)
    .nop
    sh      $a0, 0x14($v0)
    jr      $ra
    .nop
endlabel func_8009817C

# hasm: code patching
glabel func_80098194
    lui     $v0, %hi(D_80097590)
    addiu   $v0, $v0, %lo(D_80097590)
    lui     $v1, %hi(D_800978F8)
    addiu   $v1, $v1, %lo(D_800978F8)
    .nop
    sh      $a0, 0x0($v0)
    sh      $a0, 0x0($v1)
    jr      $ra
    .nop
endlabel func_80098194

# hasm: code patching
glabel func_800981B8
    lui     $v0, %hi(func_80098014)
    addiu   $v0, $v0, %lo(func_80098014)
    .nop
    sh      $a3, 0x10($v0)
    sh      $a3, 0x18($v0)
    sh      $a3, 0x20($v0)
    sh      $a3, 0x28($v0)
    sh      $a1, 0x38($v0)
    sh      $a1, 0x40($v0)
    sh      $a1, 0x48($v0)
    sh      $a1, 0x50($v0)
    sh      $a0, 0x80($v0)
    sh      $a0, 0x88($v0)
    sh      $a0, 0x90($v0)
    sh      $a0, 0x98($v0)
    sh      $a2, 0xA8($v0)
    sh      $a2, 0xB0($v0)
    sh      $a2, 0xB8($v0)
    sh      $a2, 0xC0($v0)
    jr      $ra
    .nop
endlabel func_800981B8

# hasm: unconditional b branch
# hasm: reserved register usage
glabel func_8009820C
    lui     $a3, (0x1F800100 >> 16)
    ori     $t1, $a3, (0x1F800100 & 0xFFFF)
    lw      $a1, (0x1F800004 & 0xFFFF)($a3)
    lw      $a2, (0x1F800000 & 0xFFFF)($a3)
    addiu   $a1, $a1, 0x1FFC
    ori     $t0, $zero, 0x22
.L80098224:
    lwc2    $0, 0x0($a0)
    lwc2    $1, 0x4($a0)
    lw      $t9, 0x8($a0)
    addiu   $t0, $t0, -0x1
    rtv0tr
    sw      $t9, 0xC($t1)
    swc2    $25, 0x0($t1)
    swc2    $26, 0x4($t1)
    swc2    $27, 0x8($t1)
    addiu   $a0, $a0, 0xC
    bgtz    $t0, .L80098224
    addiu   $t1, $t1, 0x10
    ori     $t1, $a3, (0x1F800100 & 0xFFFF)
    ori     $t0, $zero, 0x40
    lw      $a3, 0x0($a1)
.L80098260:
    lw      $t2, 0x0($a0)
    .nop
    srl     $t4, $t2, 8
    srl     $t5, $t2, 16
    andi    $t3, $t2, 0xFF
    andi    $t4, $t4, 0xFF
    andi    $t5, $t5, 0xFF
    sll     $t3, $t3, 4
    sll     $t4, $t4, 4
    sll     $t5, $t5, 4
    addu    $t3, $t3, $t1
    addu    $t4, $t4, $t1
    addu    $t5, $t5, $t1
    lw      $t6, 0x8($t3)
    lw      $t7, 0x8($t4)
    bgtz    $t6, .L800982B4
    lw      $t8, 0x8($t5)
    bgtz    $t7, .L800982B4
    .nop
    blez    $t8, .L800983DC
    .nop
.L800982B4:
    lw      $t6, 0x0($t3)
    lw      $t7, 0x0($t4)
    lw      $t8, 0x0($t5)
    lw      $t9, 0x4($t3)
    lw      $v0, 0x4($t4)
    lw      $v1, 0x4($t5)
    addiu   $t6, $t6, 0xA0
    addiu   $t7, $t7, 0xA0
    addiu   $t8, $t8, 0xA0
    addiu   $t9, $t9, 0x78
    addiu   $v0, $v0, 0x78
    addiu   $v1, $v1, 0x78
    slti    $at, $t6, 0x0
    beqz    $at, .L80098304
    slti    $at, $t7, 0x0
    beqz    $at, .L80098304
    slti    $at, $t8, 0x0
    beqz    $at, .L80098304
    .nop
    b       .L800983DC
.L80098304:
    slti    $at, $t6, 0x140
    bnez    $at, .L80098328
    slti    $at, $t7, 0x140
    bnez    $at, .L80098328
    slti    $at, $t8, 0x140
    bnez    $at, .L80098328
    .nop
    b       .L800983DC
    .nop
.L80098328:
    slti    $at, $t9, 0x0
    beqz    $at, .L80098348
    slti    $at, $v0, 0x0
    beqz    $at, .L80098348
    slti    $at, $v1, 0x0
    beqz    $at, .L80098348
    .nop
    b       .L800983DC
.L80098348:
    slti    $at, $t9, 0xE0
    bnez    $at, .L80098368
    slti    $at, $v0, 0xE0
    bnez    $at, .L80098368
    slti    $at, $v1, 0xE0
    bnez    $at, .L80098368
    .nop
    b       .L800983DC
.L80098368:
    andi    $t6, $t6, 0xFFFF
    andi    $t7, $t7, 0xFFFF
    andi    $t8, $t8, 0xFFFF
    sll     $t9, $t9, 16
    sll     $v0, $v0, 16
    sll     $v1, $v1, 16
    or      $t6, $t6, $t9
    or      $t7, $t7, $v0
    or      $t8, $t8, $v1
    sw      $t6, 0x8($a2)
    sw      $t7, 0x10($a2)
    sw      $t8, 0x18($a2)
    lw      $t6, 0xC($t3)
    lw      $t7, 0xC($t4)
    lui     $t9, (0x6000000 >> 16)
    lw      $t8, 0xC($t5)
    lui     $v0, (0xFFFFFF >> 16)
    sw      $t6, 0x4($a2)
    ori     $v0, $v0, (0xFFFFFF & 0xFFFF)
    sw      $t7, 0xC($a2)
    lui     $v1, (0xFF000000 >> 16)
    sw      $t8, 0x14($a2)
    and     $t3, $a3, $v0
    or      $t3, $t3, $t9
    sw      $t3, 0x0($a2)
    and     $t4, $a2, $v0
    and     $t3, $a3, $v1
    or      $a3, $t3, $t4
    addiu   $a2, $a2, 0x1C
.L800983DC:
    addiu   $t0, $t0, -0x1
    bgtz    $t0, .L80098260
    addiu   $a0, $a0, 0x4
    sw      $a3, 0x0($a1)
    lui     $a3, (0x1F800000 >> 16)
    jr      $ra
    sw      $a2, (0x1F800000 & 0xFFFF)($a3)
endlabel func_8009820C

# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_800983F8
    lui     $at, (0x1F800030 >> 16)
    sw      $ra, (0x1F8003E0 & 0xFFFF)($at)
    sw      $s0, (0x1F8003E4 & 0xFFFF)($at)
    sw      $s1, (0x1F8003E8 & 0xFFFF)($at)
    sw      $s2, (0x1F8003EC & 0xFFFF)($at)
    sw      $s3, (0x1F800390 & 0xFFFF)($at)
    sw      $s4, (0x1F800394 & 0xFFFF)($at)
    addu    $v1, $a0, $zero
    lw      $s0, (0x1F80005C & 0xFFFF)($at)
    lw      $s1, (0x1F800064 & 0xFFFF)($at)
    addu    $s2, $at, $zero
    jal     func_80098AB8
    addu    $a0, $s0, $zero
    mult    $v0, $s1
    jal     func_80098AB4
    addu    $a0, $s0, $zero
    addu    $a0, $v1, $zero
    mflo    $s3
    sw      $zero, 0x3D0($at)
    sw      $zero, 0x3D4($at)
    mult    $v0, $s1
    sw      $zero, 0x3D8($at)
    sw      $zero, 0x3DC($at)
    lw      $s1, 0x0($a0)
    addiu   $s0, $a0, 0x4
    mflo    $s4
    sra     $s3, $s3, 12
    sra     $s4, $s4, 12
.L80098468:
    lw      $t0, 0x0($s0)
    .nop
    andi    $at, $t0, 0x100
    bnez    $at, .L80098580
    andi    $at, $t0, 0x400
    bnez    $at, .L8009849C
    .nop
    addiu   $a0, $s0, 0x4
    addiu   $a1, $s0, 0x10
    jal     func_800985AC
    addiu   $a2, $s0, 0x20
    b       .L80098580
    .nop
.L8009849C:
    addiu   $a0, $s2, %lo(D_1F8003D0)
    addiu   $a1, $s2, %lo(D_1F8003D0)
    jal     func_800985AC
    addiu   $a2, $s2, %lo(D_1F8003AC)
    .nop
    lw      $t0, (0x1F8003AC & 0xFFFF)($s2)
    lw      $t1, (0x1F8003B0 & 0xFFFF)($s2)
    lw      $t2, (0x1F8003B4 & 0xFFFF)($s2)
    lw      $t3, (0x1F8003B8 & 0xFFFF)($s2)
    ctc2    $t0, $0
    lw      $t4, (0x1F8003BC & 0xFFFF)($s2)
    ctc2    $t1, $1
    lw      $t5, (0x1F8003C0 & 0xFFFF)($s2)
    ctc2    $t2, $2
    lw      $t6, (0x1F8003C4 & 0xFFFF)($s2)
    ctc2    $t3, $3
    lw      $t7, (0x1F8003C8 & 0xFFFF)($s2)
    ctc2    $t4, $4
    ctc2    $t5, $5
    ctc2    $t6, $6
    ctc2    $t7, $7
    lw      $t0, 0x4($s0)
    lw      $t1, 0x8($s0)
    lw      $t2, 0xC($s0)
    andi    $t0, $t0, 0xFFFF
    sll     $t1, $t1, 16
    or      $t0, $t0, $t1
    mtc2    $t0, $0
    mtc2    $t2, $1
    lw      $t0, (0x1F800064 & 0xFFFF)($s2)
    rtv0tr
    .nop
    negu    $t1, $s3
    sh      $s4, 0x20($s0)
    sh      $t1, 0x22($s0)
    sh      $s3, 0x26($s0)
    sh      $s4, 0x28($s0)
    sh      $t0, 0x30($s0)
    swc2    $25, 0x34($s0)
    swc2    $26, 0x38($s0)
    swc2    $27, 0x3C($s0)
    lw      $t0, (0x1F800014 & 0xFFFF)($s2)
    lw      $t1, (0x1F800018 & 0xFFFF)($s2)
    lw      $t2, (0x1F80001C & 0xFFFF)($s2)
    lw      $t3, (0x1F800020 & 0xFFFF)($s2)
    ctc2    $t0, $0
    lw      $t4, (0x1F800024 & 0xFFFF)($s2)
    ctc2    $t1, $1
    lw      $t5, (0x1F800028 & 0xFFFF)($s2)
    ctc2    $t2, $2
    lw      $t6, (0x1F80002C & 0xFFFF)($s2)
    ctc2    $t3, $3
    lw      $t7, (0x1F800030 & 0xFFFF)($s2)
    ctc2    $t4, $4
    ctc2    $t5, $5
    ctc2    $t6, $6
    ctc2    $t7, $7
.L80098580:
    addiu   $s1, $s1, -0x1
    bnez    $s1, .L80098468
    addiu   $s0, $s0, 0x40
    lui     $at, (0x1F8003EC >> 16)
    lw      $ra, (0x1F8003E0 & 0xFFFF)($at)
    lw      $s0, (0x1F8003E4 & 0xFFFF)($at)
    lw      $s1, (0x1F8003E8 & 0xFFFF)($at)
    lw      $s3, (0x1F800398 & 0xFFFF)($at)
    lw      $s4, (0x1F80039C & 0xFFFF)($at)
    jr      $ra
    lw      $s2, (0x1F8003EC & 0xFFFF)($at)
endlabel func_800983F8

# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800985AC
    lui     $a3, (0x1F8003FC >> 16)
    sw      $ra, (0x1F8003F0 & 0xFFFF)($a3)
    sw      $s0, (0x1F8003F4 & 0xFFFF)($a3)
    sw      $s1, (0x1F8003F8 & 0xFFFF)($a3)
    sw      $s2, (0x1F8003FC & 0xFFFF)($a3)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    addu    $s2, $a2, $zero
    lw      $t0, 0x0($s1)
    lw      $t1, 0x4($s1)
    lw      $t8, 0x8($s1)
    andi    $t0, $t0, 0xFFFF
    sll     $t1, $t1, 16
    or      $v0, $t0, $t1
    jal     func_8009874C
    addu    $a1, $s2, $zero
    lui     $a0, (0x1F800014 >> 16)
    ori     $a0, $a0, (0x1F800014 & 0xFFFF)
    jal     func_800989B8
    addu    $a1, $s2, $zero
    lw      $t0, 0x0($s0)
    lw      $t1, 0x4($s0)
    lw      $t2, 0x8($s0)
    andi    $t0, $t0, 0xFFFF
    sll     $t1, $t1, 16
    or      $t0, $t0, $t1
    mtc2    $t0, $0
    mtc2    $t2, $1
    addiu   $t1, $s2, 0x14
    rtv0tr
    lui     $a3, (0x1F8003FC >> 16)
    lw      $ra, (0x1F8003F0 & 0xFFFF)($a3)
    lw      $s0, (0x1F8003F4 & 0xFFFF)($a3)
    lw      $s1, (0x1F8003F8 & 0xFFFF)($a3)
    swc2    $25, 0x0($t1)
    swc2    $26, 0x4($t1)
    swc2    $27, 0x8($t1)
    jr      $ra
    lw      $s2, (0x1F8003FC & 0xFFFF)($a3)
endlabel func_800985AC

# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: split div
# hasm: temp register usage
glabel func_80098648
    lui     $a3, (0x1F8003C0 >> 16)
    lui     $t0, (0x1000000 >> 16)
    lw      $t1, (0x1F800064 & 0xFFFF)($a3)
    sw      $ra, (0x1F8003F0 & 0xFFFF)($a3)
    div     $zero, $t0, $t1
    sw      $s0, (0x1F8003F4 & 0xFFFF)($a3)
    sw      $s1, (0x1F8003F8 & 0xFFFF)($a3)
    sw      $s2, (0x1F8003FC & 0xFFFF)($a3)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    addu    $s2, $a2, $zero
    lw      $t0, (0x1F800014 & 0xFFFF)($a3)
    lw      $t1, (0x1F800018 & 0xFFFF)($a3)
    lw      $t2, (0x1F80001C & 0xFFFF)($a3)
    lw      $t3, (0x1F800020 & 0xFFFF)($a3)
    lw      $t4, (0x1F800024 & 0xFFFF)($a3)
    sw      $t0, (0x1F8003D0 & 0xFFFF)($a3)
    sw      $t1, (0x1F8003D4 & 0xFFFF)($a3)
    sw      $t2, (0x1F8003D8 & 0xFFFF)($a3)
    sw      $t3, (0x1F8003DC & 0xFFFF)($a3)
    sw      $t4, (0x1F8003E0 & 0xFFFF)($a3)
    sw      $zero, (0x1F8003B0 & 0xFFFF)($a3)
    sw      $zero, (0x1F8003B4 & 0xFFFF)($a3)
    sw      $zero, (0x1F8003B8 & 0xFFFF)($a3)
    sw      $zero, (0x1F8003BC & 0xFFFF)($a3)
    sw      $zero, (0x1F8003C0 & 0xFFFF)($a3)
    mflo    $t0
    sh      $t0, (0x1F8003B0 & 0xFFFF)($a3)
    sh      $t0, (0x1F8003B8 & 0xFFFF)($a3)
    sh      $t0, (0x1F8003C0 & 0xFFFF)($a3)
    lw      $t0, 0x0($s1)
    lw      $t1, 0x4($s1)
    lw      $t8, 0x8($s1)
    andi    $t0, $t0, 0xFFFF
    sll     $t1, $t1, 16
    or      $v0, $t0, $t1
    jal     func_8009874C
    addu    $a1, $s2, $zero
    lui     $a3, %hi(D_1F8003B0)
    addiu   $a0, $a3, %lo(D_1F8003B0)
    jal     func_800989B8
    addiu   $a1, $a3, %lo(D_1F8003D0)
    lui     $a0, %hi(D_1F8003D0)
    addiu   $a0, $a0, %lo(D_1F8003D0)
    jal     func_800989B8
    addu    $a1, $s2, $zero
    lw      $t0, 0x0($s0)
    lw      $t1, 0x4($s0)
    lw      $t2, 0x8($s0)
    andi    $t0, $t0, 0xFFFF
    sll     $t1, $t1, 16
    or      $t0, $t0, $t1
    mtc2    $t0, $0
    mtc2    $t2, $1
    addiu   $t1, $s2, 0x14
    rtv0tr
    lui     $a3, (0x1F8003FC >> 16)
    lw      $ra, (0x1F8003F0 & 0xFFFF)($a3)
    lw      $s0, (0x1F8003F4 & 0xFFFF)($a3)
    lw      $s1, (0x1F8003F8 & 0xFFFF)($a3)
    swc2    $25, 0x0($t1)
    swc2    $26, 0x4($t1)
    swc2    $27, 0x8($t1)
    jr      $ra
    lw      $s2, (0x1F8003FC & 0xFFFF)($a3)
endlabel func_80098648

# hasm: cross-function control flow
# hasm: custom register abi
glabel func_8009874C
    lui     $a2, %hi(_trig_table)
    addiu   $a2, $a2, %lo(_trig_table)
    lui     $t7, %hi(func_800988BC)
    addiu   $t7, $t7, %lo(func_800988BC)
    addiu   $a3, $a2, 0x800
alabel D_80098760
    srl     $t1, $t8, 4
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    lui     $t9, %hi(D_80098760)
    addiu   $t9, $t9, %lo(D_80098760)
    sll     $t8, $t8, 2
    jr      $t1
    andi    $t8, $t8, 0x7FC
    sll     $t4, $t0, 1
    sll     $t5, $t1, 1
    srl     $t8, $v0, 14
    srl     $t1, $t8, 6
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    jr      $t1
    andi    $t8, $t8, 0x7FC
    sll     $t2, $t0, 1
    sll     $t3, $t1, 1
    sll     $t8, $v0, 2
    srl     $t1, $t8, 6
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    jr      $t1
    andi    $t8, $t8, 0x7FC
    mtc2    $t4, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    mult    $t1, $t2
    addu    $v0, $zero, $a1
    gpf     1
    negu    $t8, $t0
    sll     $t8, $t8, 16
    mfc2    $a0, $9
    mfc2    $a1, $10
    mfc2    $t4, $11
    mtc2    $t5, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    sra     $t4, $t4, 1
    sll     $t4, $t4, 16
    gpf     1
    mflo    $t7
    sra     $t7, $t7, 13
    andi    $t7, $t7, 0xFFFF
    mult    $t1, $t3
    or      $t4, $t4, $t7
    sw      $t4, 0x4($v0)
    mfc2    $a2, $9
    mfc2    $a3, $10
    mfc2    $t5, $11
    mtc2    $t0, $8
    mtc2    $a0, $9
    mtc2    $a2, $10
    mtc2    $a1, $11
    sra     $t5, $t5, 1
    andi    $t5, $t5, 0xFFFF
    gpf     1
    or      $t5, $t5, $t8
    sw      $t5, 0x8($v0)
    mflo    $t7
    sra     $t7, $t7, 13
    sh      $t7, 0x10($v0)
    mult    $t0, $a3
    mfc2    $t2, $9
    mfc2    $t3, $10
    mfc2    $t4, $11
    addu    $t2, $t2, $a3
    subu    $t3, $t3, $a1
    subu    $t4, $t4, $a2
    sra     $t2, $t2, 2
    andi    $t2, $t2, 0xFFFF
    sra     $t3, $t3, 2
    sll     $t3, $t3, 16
    or      $t2, $t2, $t3
    sw      $t2, 0x0($v0)
    sra     $t4, $t4, 2
    andi    $t4, $t4, 0xFFFF
    mflo    $t5
    sra     $t5, $t5, 12
    addu    $t5, $t5, $a0
    sra     $t5, $t5, 2
    sll     $t5, $t5, 16
    or      $t4, $t4, $t5
    jr      $ra
    sw      $t4, 0xC($v0)
endlabel func_8009874C

# hasm: custom register abi
# hasm: temp register usage
glabel func_800988BC
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    jr      $t9
    andi    $t0, $t0, 0xFFFF
    .nop
    .nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    jr      $t9
    srl     $t0, $t0, 16
    .nop
    .nop
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    negu    $t1, $t1
    jr      $t9
    srl     $t0, $t0, 16
    .nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    negu    $t1, $t1
    jr      $t9
    andi    $t0, $t0, 0xFFFF
    .nop
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    negu    $t1, $t1
    andi    $t0, $t0, 0xFFFF
    jr      $t9
    negu    $t0, $t0
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    negu    $t1, $t1
    srl     $t0, $t0, 16
    jr      $t9
    negu    $t0, $t0
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    srl     $t0, $t0, 16
    jr      $t9
    negu    $t0, $t0
    .nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
    jr      $t9
    negu    $t0, $t0
endlabel func_800988BC

# hasm: temp register usage
glabel func_800989B8
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    lw      $t2, 0x8($a0)
    lw      $t3, 0xC($a0)
    lw      $t4, 0x10($a0)
    ctc2    $t0, $0
    ctc2    $t1, $1
    ctc2    $t2, $2
    ctc2    $t3, $3
    ctc2    $t4, $4
    lw      $t1, 0x4($a1)
    lw      $t2, 0x8($a1)
    lw      $t4, 0x10($a1)
    lui     $t9, (0xFFFF0000 >> 16)
    and     $t5, $t2, $t9
    andi    $t6, $t1, 0xFFFF
    or      $t5, $t5, $t6
    mtc2    $t5, $0
    mtc2    $t4, $1
    sll     $t6, $t2, 16
    rtv0
    lw      $t0, 0x0($a1)
    lw      $t3, 0xC($a1)
    srl     $t5, $t0, 16
    or      $t5, $t5, $t6
    srl     $t6, $t3, 16
    mfc2    $a0, $9
    mfc2    $a2, $10
    mfc2    $a3, $11
    mtc2    $t5, $0
    mtc2    $t6, $1
    sll     $a2, $a2, 16
    rtv0
    and     $t7, $t1, $t9
    andi    $t8, $t0, 0xFFFF
    or      $t7, $t7, $t8
    andi    $a0, $a0, 0xFFFF
    sh      $a3, 0x10($a1)
    mfc2    $t0, $9
    mfc2    $t1, $10
    mfc2    $t2, $11
    mtc2    $t7, $0
    mtc2    $t3, $1
    andi    $t1, $t1, 0xFFFF
    rtv0
    addu    $v0, $zero, $a1
    or      $t1, $t1, $a2
    sw      $t1, 0x8($a1)
    sll     $t0, $t0, 16
    sll     $t2, $t2, 16
    mfc2    $t3, $9
    mfc2    $t4, $10
    mfc2    $t5, $11
    andi    $t3, $t3, 0xFFFF
    or      $t3, $t3, $t0
    sw      $t3, 0x0($a1)
    sll     $t4, $t4, 16
    or      $t4, $t4, $a0
    sw      $t4, 0x4($a1)
    andi    $t5, $t5, 0xFFFF
    or      $t5, $t5, $t2
    jr      $ra
    sw      $t5, 0xC($a1)
endlabel func_800989B8

# hasm: cross-function control flow
glabel func_80098AB4
    addiu   $a0, $a0, 0x400
endlabel func_80098AB4

glabel func_80098AB8
    lui     $v0, %hi(_trig_table)
    addiu   $v0, $v0, %lo(_trig_table)
    andi    $t0, $a0, 0x400
    beqz    $t0, .L80098AE0
    andi    $t1, $a0, 0x3FF
    bnez    $t1, .L80098ADC
    addiu   $t2, $zero, 0x800
    j       .L80098B04
    addiu   $v0, $zero, 0x1000
.L80098ADC:
    subu    $a0, $t2, $a0
.L80098AE0:
    andi    $t1, $a0, 0x200
    beqz    $t1, .L80098AF8
    andi    $t2, $a0, 0x1FF
    addiu   $t0, $zero, 0x200
    subu    $t2, $t0, $t2
    addiu   $v0, $v0, 0x2
.L80098AF8:
    sll     $t2, $t2, 2
    addu    $v0, $v0, $t2
    lhu     $v0, 0x0($v0)
.L80098B04:
    andi    $t0, $a0, 0x800
    beqz    $t0, .L80098B14
    .nop
    negu    $v0, $v0
.L80098B14:
    jr      $ra
    .nop
endlabel func_80098AB8

# hasm: cross-function control flow
# hasm: temp register usage
glabel func_80098B1C
    lui     $t0, %hi(vs_battle_roomData)
    addiu   $t0, $t0, %lo(vs_battle_roomData)
    lw      $t1, 0x98($t0)
    .nop
    addiu   $t1, $t1, 0x14
    jr      $t1
    .nop
endlabel func_80098B1C

# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_80098B38
    lui     $at, (0x1F800218 >> 16)
    sw      $ra, (0x1F800200 & 0xFFFF)($at)
    sw      $s0, (0x1F800204 & 0xFFFF)($at)
    sw      $s1, (0x1F800208 & 0xFFFF)($at)
    sw      $s2, (0x1F80020C & 0xFFFF)($at)
    sw      $s3, (0x1F800210 & 0xFFFF)($at)
    sw      $s4, (0x1F800214 & 0xFFFF)($at)
    sw      $s5, (0x1F800218 & 0xFFFF)($at)
    lui     $s0, %hi(vs_battle_roomData)
    addiu   $s0, $s0, %lo(vs_battle_roomData)
    addu    $s4, $a2, $zero
    lb      $t0, 0x0($s0)
    lui     $s5, (0x808080 >> 16)
    beqz    $t0, .L80098C0C
    ori     $s5, $s5, (0x808080 & 0xFFFF)
    lw      $s1, 0x74($s0)
    sra     $s3, $a0, 16
    beqz    $s1, .L80098C0C
    sll     $s2, $a0, 16
    lw      $s5, 0x0($s1)
    lw      $s0, 0x4($s1)
    beq     $zero, $a1, .L80098BA4
    sra     $s2, $s2, 16
    lw      $t1, 0x8($s1)
    sll     $t0, $s0, 5
    addu    $s1, $s1, $t0
    addu    $s0, $t1, $zero
.L80098BA4:
    beqz    $s0, .L80098C0C
    addiu   $s1, $s1, 0xC
.L80098BAC:
    lw      $t0, 0x0($s1)
    lw      $t1, 0x4($s1)
    sll     $t2, $t0, 16
    sra     $t2, $t2, 16
    subu    $at, $s2, $t2
    bltz    $at, .L80098C00
    sll     $t4, $t1, 16
    sra     $t4, $t4, 16
    subu    $at, $s2, $t4
    bgtz    $at, .L80098C00
    sra     $t3, $t0, 16
    subu    $at, $s3, $t3
    bltz    $at, .L80098C00
    sra     $t5, $t1, 16
    subu    $at, $s3, $t5
    bgtz    $at, .L80098C00
    .nop
    addu    $a2, $s1, $zero
    jal     func_80098C3C
    addu    $a1, $s4, $zero
    bnez    $v0, .L80098C14
.L80098C00:
    addiu   $s0, $s0, -0x1
    bnez    $s0, .L80098BAC
    addiu   $s1, $s1, 0x20
.L80098C0C:
    sw      $s5, 0x0($s4)
    or      $v0, $zero, $zero
.L80098C14:
    lui     $at, (0x1F800218 >> 16)
    lw      $ra, (0x1F800200 & 0xFFFF)($at)
    lw      $s0, (0x1F800204 & 0xFFFF)($at)
    lw      $s1, (0x1F800208 & 0xFFFF)($at)
    lw      $s2, (0x1F80020C & 0xFFFF)($at)
    lw      $s3, (0x1F800210 & 0xFFFF)($at)
    lw      $s4, (0x1F800214 & 0xFFFF)($at)
    lw      $s5, (0x1F800218 & 0xFFFF)($at)
    jr      $ra
    .nop
endlabel func_80098B38

# hasm: reserved register usage
# hasm: split div
glabel func_80098C3C
    lw      $t4, 0x8($a2)
    lw      $t5, 0x10($a2)
    lw      $t6, 0xC($a2)
    mtc2    $t4, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    .nop
    .nop
    nclip
    mfc2    $t0, $24
    .nop
    blez    $t0, .L80098D64
    .nop
    mtc2    $a0, $12
    mtc2    $t5, $13
    mtc2    $t6, $14
    .nop
    .nop
    nclip
    mfc2    $t1, $24
    .nop
    bltz    $t1, .L80098D64
    .nop
    mtc2    $a0, $12
    mtc2    $t6, $13
    mtc2    $t4, $14
    .nop
    .nop
    nclip
    mfc2    $t2, $24
    .nop
    bltz    $t2, .L80098D64
    .nop
    subu    $t3, $t0, $t1
    subu    $t3, $t3, $t2
    bltz    $t3, .L80098D64
    .nop
    lw      $t4, 0x14($a2)
    lw      $t6, 0x18($a2)
    lw      $t5, 0x1C($a2)
    ori     $v0, $zero, 0x2
.L80098CE0:
    andi    $t7, $t4, 0xFF
    multu   $t7, $t1
    srl     $t4, $t4, 8
    mflo    $t7
    .nop
    andi    $t8, $t5, 0xFF
    multu   $t8, $t2
    srl     $t5, $t5, 8
    mflo    $t8
    .nop
    andi    $t9, $t6, 0xFF
    multu   $t9, $t3
    srl     $t6, $t6, 8
    mflo    $t9
    addu    $at, $t7, $t8
    addu    $at, $at, $t9
    divu    $zero, $at, $t0
    .nop
    mflo    $at
    .nop
    bgez    $at, .L80098D3C
    .nop
    or      $at, $zero, $zero
.L80098D3C:
    sltiu   $t9, $at, 0x100
    bnez    $t9, .L80098D4C
    .nop
    ori     $at, $zero, 0xFF
.L80098D4C:
    sb      $at, 0x0($a1)
    addiu   $a1, $a1, 0x1
    bnez    $v0, .L80098CE0
    addiu   $v0, $v0, -0x1
    jr      $ra
    ori     $v0, $zero, 0x1
.L80098D64:
    jr      $ra
    or      $v0, $zero, $zero
endlabel func_80098C3C

# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_80098D6C
    beq     $a0, $a1, .L80098DC0
    addu    $v0, $ra, $zero
    addu    $v1, $a3, $zero
    lb      $t0, 0x0($a2)
    lb      $t1, 0x1($a2)
    lb      $t2, 0x2($a2)
    lh      $t8, 0x4($a2)
    andi    $v1, $v1, 0x2
    sll     $v1, $v1, 2
    ori     $t7, $zero, 0x100
    sll     $t0, $t0, 2
    sll     $t1, $t1, 2
    sll     $t2, $t2, 2
.L80098DA0:
    lw      $t3, 0x0($a0)
    .nop
    srl     $t3, $t3, 24
    addiu   $at, $t3, -0x9
    beqz    $at, .L80098DCC
    addiu   $at, $t3, -0xC
    beqz    $at, .L80098E08
    .nop
.L80098DC0:
    addu    $ra, $v0, $zero
    jr      $ra
    .nop
.L80098DCC:
    jal     func_80098E50
    addiu   $t3, $a0, 0x4
    sw      $t6, 0x4($a0)
    jal     func_80098E50
    addiu   $t3, $a0, 0x10
    sw      $t6, 0x10($a0)
    jal     func_80098E50
    addiu   $t3, $a0, 0x1C
    sw      $t6, 0x1C($a0)
    addiu   $a0, $a0, 0x28
    addu    $a0, $a0, $v1
    bne     $a0, $a1, .L80098DA0
    .nop
    b       .L80098DC0
    .nop
.L80098E08:
    jal     func_80098E50
    addiu   $t3, $a0, 0x4
    sw      $t6, 0x4($a0)
    jal     func_80098E50
    addiu   $t3, $a0, 0x10
    sw      $t6, 0x10($a0)
    jal     func_80098E50
    addiu   $t3, $a0, 0x1C
    sw      $t6, 0x1C($a0)
    jal     func_80098E50
    addiu   $t3, $a0, 0x28
    sw      $t6, 0x28($a0)
    addiu   $a0, $a0, 0x34
    addu    $a0, $a0, $v1
    bne     $a0, $a1, .L80098DA0
    .nop
    b       .L80098DC0
    .nop
endlabel func_80098D6C

# hasm: custom register abi
# hasm: reserved register usage
# hasm: temp register usage
glabel func_80098E50
    .nop
    lw      $t6, 0x0($t3)
    .nop
    srl     $t4, $t6, 8
    srl     $t5, $t6, 16
    andi    $t3, $t6, 0xFF
    andi    $t4, $t4, 0xFF
    beqz    $t8, .L80098ECC
    andi    $t5, $t5, 0xFF
    sll     $at, $t3, 2
    addu    $t3, $t3, $at
    sll     $at, $t4, 3
    addu    $t4, $t4, $at
    sll     $t5, $t5, 1
    addu    $t3, $t3, $t4
    addu    $t3, $t3, $t5
    ctc2    $t3, $21
    ctc2    $t3, $22
    ctc2    $t3, $23
    mtc2    $t6, $6
    mtc2    $t8, $8
    .nop
    .nop
    dpcs
    mfc2    $t6, $22
    .nop
    srl     $t4, $t6, 8
    srl     $t5, $t6, 16
    andi    $t3, $t6, 0xFF
    andi    $t4, $t4, 0xFF
    andi    $t5, $t5, 0xFF
.L80098ECC:
    addu    $t3, $t3, $t0
    addu    $t4, $t4, $t1
    addu    $t5, $t5, $t2
    srl     $t6, $t6, 24
    bgez    $t3, .L80098EE8
    .nop
    or      $t3, $zero, $zero
.L80098EE8:
    slt     $at, $t3, $t7
    bnez    $at, .L80098EF8
    .nop
    addiu   $t3, $t7, -0x1
.L80098EF8:
    bgez    $t4, .L80098F04
    .nop
    or      $t4, $zero, $zero
.L80098F04:
    slt     $at, $t4, $t7
    bnez    $at, .L80098F14
    .nop
    addiu   $t4, $t7, -0x1
.L80098F14:
    bgez    $t5, .L80098F20
    .nop
    or      $t5, $zero, $zero
.L80098F20:
    slt     $at, $t5, $t7
    bnez    $at, .L80098F30
    .nop
    addiu   $t5, $t7, -0x1
.L80098F30:
    sll     $t4, $t4, 8
    sll     $t5, $t5, 16
    sll     $t6, $t6, 24
    or      $t6, $t6, $t3
    or      $t6, $t6, $t4
    jr      $ra
    or      $t6, $t6, $t5
endlabel func_80098E50

# hasm: reserved register usage
glabel vs_battle_initSceneAndGetRoomNames
    lw      $v0, 0x0($a0)
    addiu   $a1, $a0, 0x4
    or      $v1, $zero, $v0
.L80098F58:
    addiu   $v0, $v0, -0x1
    bne     $zero, $v0, .L80098F58
    addiu   $a1, $a1, 0xC
    addiu   $a2, $a0, 0x4
    or      $v0, $zero, $v1
.L80098F6C:
    lw      $at, 0x4($a2)
    addiu   $v0, $v0, -0x1
    sw      $a1, 0x4($a2)
    addu    $a1, $a1, $at
    bne     $zero, $v0, .L80098F6C
    addiu   $a2, $a2, 0xC
    jr      $ra
    addu    $v0, $a1, $zero
endlabel vs_battle_initSceneAndGetRoomNames

# hasm: unconditional b branch
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_80098F8C
    lw      $v0, 0x0($a0)
    lui     $a3, (0x1F8003E8 >> 16)
    sw      $s0, (0x1F8003F0 & 0xFFFF)($a3)
    sw      $s1, (0x1F8003F4 & 0xFFFF)($a3)
    sw      $s2, (0x1F8003F8 & 0xFFFF)($a3)
    sw      $s3, (0x1F8003FC & 0xFFFF)($a3)
    sw      $s4, (0x1F8003EC & 0xFFFF)($a3)
    sw      $s5, (0x1F8003E8 & 0xFFFF)($a3)
    addiu   $a0, $a0, 0x4
    lui     $a3, (0x1F800000 >> 16)
    lui     $t6, (0xFFFFFF >> 16)
    ori     $t6, $t6, (0xFFFFFF & 0xFFFF)
    lui     $t7, (0xFF000000 >> 16)
    lw      $t9, (0x1F800004 & 0xFFFF)($a3)
    lw      $t8, (0x1F800000 & 0xFFFF)($a3)
    or      $a1, $zero, $zero
    lw      $s4, 0x10($t9)
    lw      $v1, 0x14($t9)
    lui     $t9, %hi(D_800F1CDC)
    addiu   $t9, $t9, %lo(D_800F1CDC)
    lui     $s5, %hi(vs_main_stateFlags)
    addiu   $s5, $s5, %lo(vs_main_stateFlags)
    ori     $s0, $zero, 0xFFFF
    or      $s1, $zero, $zero
    ori     $s2, $zero, 0xFFFF
    or      $s3, $zero, $zero
    ori     $at, $zero, 0x100
    ctc2    $zero, $5
    ctc2    $zero, $6
    ctc2    $at, $7
    lw      $t9, 0x0($t9)
.L80099008:
    lw      $at, 0x0($a0)
    lw      $a2, 0x4($a0)
    beqz    $at, .L80099434
    addiu   $v0, $v0, -0x1
    lw      $t0, 0x0($a2)
    addiu   $a2, $a2, 0x4
    beqz    $t0, .L80099434
    lui     $a3, (0x1F800100 >> 16)
    ori     $a3, $a3, (0x1F800100 & 0xFFFF)
    lui     $t4, (0xFFFEFFFE >> 16)
    ori     $t4, $t4, (0xFFFEFFFE & 0xFFFF)
.L80099034:
    lwc2    $0, 0x0($a2)
    lwc2    $1, 0x4($a2)
    lwc2    $2, 0x8($a2)
    lwc2    $3, 0xC($a2)
    lwc2    $4, 0x10($a2)
    lwc2    $5, 0x14($a2)
    addiu   $t0, $t0, -0x3
    addiu   $a2, $a2, 0x18
    rtpt
    swc2    $12, 0x0($a3)
    swc2    $13, 0x4($a3)
    swc2    $14, 0x8($a3)
    bgtz    $t0, .L80099034
    addiu   $a3, $a3, 0xC
    sll     $t0, $t0, 3
    addu    $a2, $a2, $t0
    lui     $a3, (0x1F800100 >> 16)
    ori     $a3, $a3, (0x1F800100 & 0xFFFF)
    lw      $t0, 0x0($a2)
    addiu   $a2, $a2, 0x4
    beqz    $t0, .L80099110
    lui     $t1, (0x4000000 >> 16)
    sll     $at, $t0, 2
    bnez    $a1, .L80099110
    addu    $a2, $a2, $at
    lui     $t2, (0x223F7F00 >> 16)
    subu    $a2, $a2, $at
    ori     $t2, $t2, (0x223F7F00 & 0xFFFF)
.L800990A4:
    lw      $at, 0x0($a2)
    sw      $t2, 0x4($t8)
    sll     $t3, $at, 2
    srl     $t4, $at, 6
    srl     $t5, $at, 14
    andi    $t3, $t3, 0x3FC
    andi    $t4, $t4, 0x3FC
    andi    $t5, $t5, 0x3FC
    addu    $t3, $t3, $a3
    addu    $t4, $t4, $a3
    addu    $t5, $t5, $a3
    lw      $t3, 0x0($t3)
    lw      $t4, 0x0($t4)
    lw      $t5, 0x0($t5)
    sw      $t3, 0x8($t8)
    sw      $t4, 0xC($t8)
    sw      $t5, 0x10($t8)
    and     $at, $v1, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $v1, $v1, $t7
    or      $v1, $v1, $at
    addiu   $t8, $t8, 0x14
    addiu   $t0, $t0, -0x1
    bnez    $t0, .L800990A4
    addiu   $a2, $a2, 0x4
.L80099110:
    lw      $t0, 0x0($a2)
    addiu   $a2, $a2, 0x4
    beqz    $t0, .L800991B8
    lui     $t1, (0x5000000 >> 16)
    sll     $at, $t0, 2
    bnez    $a1, .L800991B8
    addu    $a2, $a2, $at
    lui     $t2, (0x2A3F7F00 >> 16)
    subu    $a2, $a2, $at
    ori     $t2, $t2, (0x2A3F7F00 & 0xFFFF)
.L80099138:
    lw      $at, 0x0($a2)
    sw      $t2, 0x4($t8)
    sll     $t3, $at, 2
    srl     $t4, $at, 6
    srl     $t5, $at, 14
    srl     $at, $at, 22
    andi    $t3, $t3, 0x3FC
    andi    $t4, $t4, 0x3FC
    andi    $t5, $t5, 0x3FC
    andi    $at, $at, 0x3FC
    addu    $t3, $t3, $a3
    addu    $t4, $t4, $a3
    addu    $t5, $t5, $a3
    addu    $at, $at, $a3
    lw      $t3, 0x0($t3)
    lw      $t4, 0x0($t4)
    lw      $t5, 0x0($t5)
    lw      $at, 0x0($at)
    sw      $t3, 0x8($t8)
    sw      $t4, 0xC($t8)
    sw      $at, 0x10($t8)
    sw      $t5, 0x14($t8)
    and     $at, $v1, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $v1, $v1, $t7
    or      $v1, $v1, $at
    addiu   $t8, $t8, 0x18
    addiu   $t0, $t0, -0x1
    bnez    $t0, .L80099138
    addiu   $a2, $a2, 0x4
.L800991B8:
    lw      $t0, 0x0($a2)
    addiu   $a2, $a2, 0x4
    beqz    $t0, .L80099228
    lui     $t1, (0x3000000 >> 16)
    lui     $t2, (0x42FF7F00 >> 16)
    ori     $t2, $t2, (0x42FF7F00 & 0xFFFF)
.L800991D0:
    lw      $at, 0x0($a2)
    sw      $t2, 0x4($t8)
    sll     $t3, $at, 2
    srl     $t4, $at, 6
    andi    $t3, $t3, 0x3FC
    andi    $t4, $t4, 0x3FC
    addu    $t3, $t3, $a3
    addu    $t4, $t4, $a3
    lw      $t3, 0x0($t3)
    lw      $t4, 0x0($t4)
    sw      $t3, 0x8($t8)
    sw      $t4, 0xC($t8)
    and     $at, $v1, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $v1, $v1, $t7
    or      $v1, $v1, $at
    addiu   $t8, $t8, 0x10
    addiu   $t0, $t0, -0x1
    bnez    $t0, .L800991D0
    addiu   $a2, $a2, 0x4
.L80099228:
    bnez    $a1, .L80099434
    lw      $t0, 0x0($a2)
    addiu   $a2, $a2, 0x4
    beqz    $t0, .L8009929C
    lui     $t1, (0x3000000 >> 16)
    lui     $t2, (0x422F5F00 >> 16)
    ori     $t2, $t2, (0x422F5F00 & 0xFFFF)
.L80099244:
    lw      $at, 0x0($a2)
    sw      $t2, 0x4($t8)
    sll     $t3, $at, 2
    srl     $t4, $at, 6
    andi    $t3, $t3, 0x3FC
    andi    $t4, $t4, 0x3FC
    addu    $t3, $t3, $a3
    addu    $t4, $t4, $a3
    lw      $t3, 0x0($t3)
    lw      $t4, 0x0($t4)
    sw      $t3, 0x8($t8)
    sw      $t4, 0xC($t8)
    and     $at, $v1, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $v1, $v1, $t7
    or      $v1, $v1, $at
    addiu   $t8, $t8, 0x10
    addiu   $t0, $t0, -0x1
    bnez    $t0, .L80099244
    addiu   $a2, $a2, 0x4
.L8009929C:
    lw      $t0, 0x0($a2)
    addiu   $a2, $a2, 0x4
    beqz    $t0, .L80099434
    lui     $t1, (0x3000000 >> 16)
.L800992AC:
    lw      $at, 0x0($a2)
    .nop
    sll     $t3, $at, 2
    andi    $t3, $t3, 0x3FC
    srl     $t2, $at, 16
    srl     $t5, $at, 24
    andi    $t5, $t5, 0xFF
    beqz    $t5, .L800992E4
    .nop
    addiu   $t5, $t5, 0x33F
    addu    $t5, $t5, $s5
    lb      $at, 0x0($t5)
    .nop
    beqz    $at, .L800993CC
.L800992E4:
    andi    $t4, $t2, 0x10
    bnez    $t4, .L8009931C
    .nop
    andi    $t4, $t2, 0x4
    bnez    $t4, .L80099310
    .nop
    andi    $t4, $t2, 0x1F
    beqz    $t4, .L80099330
    .nop
    b       .L80099428
    .nop
.L80099310:
    lui     $t2, (0x60FF7F00 >> 16)
    b       .L80099338
    ori     $t2, $t2, (0x60FF7F00 & 0xFFFF)
.L8009931C:
    andi    $at, $t9, 0x20
    beqz    $at, .L80099428
    lui     $t2, (0x607F00FF >> 16)
    b       .L80099338
    ori     $t2, $t2, (0x607F00FF & 0xFFFF)
.L80099330:
    lui     $t2, (0x607F7F7F >> 16)
    ori     $t2, $t2, (0x607F7F7F & 0xFFFF)
.L80099338:
    addu    $t3, $t3, $a3
    lw      $t3, 0x0($t3)
    sw      $t2, 0x4($t8)
    and     $at, $s4, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $s4, $s4, $t7
    or      $s4, $s4, $at
    sra     $at, $t3, 16
    addiu   $at, $at, -0x1
    sll     $at, $at, 16
    andi    $t4, $t3, 0xFFFF
    or      $at, $at, $t4
    lui     $t4, (0x30001 >> 16)
    ori     $t4, $t4, (0x30001 & 0xFFFF)
    sw      $at, 0x8($t8)
    sw      $t4, 0xC($t8)
    addiu   $t8, $t8, 0x10
    sw      $t2, 0x4($t8)
    and     $at, $s4, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $s4, $s4, $t7
    or      $s4, $s4, $at
    addiu   $at, $t3, -0x1
    andi    $at, $at, 0xFFFF
    sra     $t4, $t3, 16
    sll     $t4, $t4, 16
    or      $at, $at, $t4
    lui     $t4, (0x10003 >> 16)
    ori     $t4, $t4, (0x10003 & 0xFFFF)
    sw      $at, 0x8($t8)
    sw      $t4, 0xC($t8)
    b       .L80099428
    addiu   $t8, $t8, 0x10
.L800993CC:
    addu    $t3, $t3, $a3
    lw      $t3, 0x0($t3)
    lui     $t2, (0x74808080 >> 16)
    ori     $t2, $t2, (0x74808080 & 0xFFFF)
    sw      $t2, 0x4($t8)
    and     $at, $s4, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $s4, $s4, $t7
    or      $s4, $s4, $at
    sra     $at, $t3, 16
    addiu   $at, $at, -0x4
    sll     $at, $at, 16
    andi    $t4, $t3, 0xFFFF
    addiu   $t4, $t4, -0x3
    andi    $t4, $t4, 0xFFFF
    or      $at, $at, $t4
    lui     $t4, (0x37F898D8 >> 16)
    ori     $t4, $t4, (0x37F898D8 & 0xFFFF)
    sw      $at, 0x8($t8)
    sw      $t4, 0xC($t8)
    addiu   $t8, $t8, 0x10
.L80099428:
    addiu   $t0, $t0, -0x1
    bnez    $t0, .L800992AC
    addiu   $a2, $a2, 0x4
.L80099434:
    addiu   $a1, $a1, 0x1
    bne     $zero, $v0, .L80099008
    addiu   $a0, $a0, 0xC
    lui     $t1, (0x2000000 >> 16)
    lui     $t2, (0xE100020C >> 16)
    ori     $t2, $t2, (0xE100020C & 0xFFFF)
    and     $at, $v1, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $v1, $v1, $t7
    or      $v1, $v1, $at
    sw      $t2, 0x4($t8)
    sw      $zero, 0x8($t8)
    addiu   $t8, $t8, 0x10
    lui     $t1, (0x2000000 >> 16)
    lui     $t2, (0xE100020C >> 16)
    ori     $t2, $t2, (0xE100020C & 0xFFFF)
    and     $at, $s4, $t6
    or      $at, $at, $t1
    sw      $at, 0x0($t8)
    and     $at, $t8, $t6
    and     $s4, $s4, $t7
    or      $s4, $s4, $at
    sw      $t2, 0x4($t8)
    sw      $zero, 0x8($t8)
    addiu   $t8, $t8, 0x10
    lui     $a3, (0x1F800000 >> 16)
    lw      $t9, (0x1F800004 & 0xFFFF)($a3)
    lw      $s0, (0x1F8003F0 & 0xFFFF)($a3)
    lw      $s1, (0x1F8003F4 & 0xFFFF)($a3)
    lw      $s2, (0x1F8003F8 & 0xFFFF)($a3)
    lw      $s3, (0x1F8003FC & 0xFFFF)($a3)
    sw      $s4, 0x10($t9)
    sw      $v1, 0x14($t9)
    lw      $s4, (0x1F8003EC & 0xFFFF)($a3)
    lw      $s5, (0x1F8003E8 & 0xFFFF)($a3)
    sw      $t8, (0x1F800000 & 0xFFFF)($a3)
    jr      $ra
    .nop
endlabel func_80098F8C

# hasm: temp register usage
glabel vs_battle_getGeomOffset
    cfc2    $t0, $24
    cfc2    $t1, $25
    srl     $t0, $t0, 16
    srl     $t1, $t1, 16
    sw      $t0, 0x0($a0)
    sw      $t1, 0x4($a0)
    jr      $ra
    .nop
endlabel vs_battle_getGeomOffset

# hasm: temp register usage
glabel vs_battle_setGeomOffset
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    sll     $t0, $t0, 16
    sll     $t1, $t1, 16
    ctc2    $t0, $24
    ctc2    $t1, $25
    jr      $ra
    .nop
endlabel vs_battle_setGeomOffset

# hasm: reserved register usage
glabel func_80099514
    lui     $a3, %hi(vs_battle_roomData)
    addiu   $a3, $a3, %lo(vs_battle_roomData)
    lw      $a3, 0x68($a3)
    srl     $t1, $a1, 2
    lh      $t0, 0x0($a3)
    lh      $v0, 0x6($a3)
    mult    $t0, $t1
    addiu   $t0, $a3, 0x8
    beqz    $a2, .L80099548
    sll     $v0, $v0, 1
.L8009953C:
    addiu   $a2, $a2, -0x1
    bnez    $a2, .L8009953C
    addu    $t0, $t0, $v0
.L80099548:
    addiu   $t1, $a3, 0x8
    sll     $at, $v0, 1
    addu    $t1, $t1, $at
    mflo    $v0
    srl     $at, $a0, 2
    addu    $at, $at, $v0
    sll     $at, $at, 1
    addu    $t0, $t0, $at
    lh      $t0, 0x0($t0)
    .nop
    andi    $at, $t0, 0x7FF
    sll     $at, $at, 4
    addu    $t1, $t1, $at
    andi    $at, $a0, 0x3
    addu    $t1, $t1, $at
    andi    $at, $a1, 0x3
    sll     $at, $at, 2
    addu    $t1, $t1, $at
    lb      $t1, 0x0($t1)
    andi    $t0, $t0, 0xF800
    srl     $t0, $t0, 9
    addu    $v0, $t1, $t0
    andi    $v0, $v0, 0x7F
    andi    $t1, $t1, 0x80
    jr      $ra
    or      $v0, $v0, $t1
endlabel func_80099514
