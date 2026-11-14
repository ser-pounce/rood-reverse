.include "macro.inc"

.set noat
.set noreorder

.section .rodata, "a"

dlabel jtbl_80069B54
    .word .L800D71EC
    .word .L800D71E0
    .word .L800D71E8
    .word .L800D71D0
    .word .L800D71D8
enddlabel jtbl_80069B54

.section .text, "ax"

# hasm: split div
glabel func_800D6E44
    addiu   $sp, $sp, -0x48
    sw      $s1, 0x24($sp)
    addu    $s1, $a0, $zero
    lui     $v0, %hi(D_800F569C)
    lw      $v0, %lo(D_800F569C)($v0)
    lui     $v1, %hi(vs_main_projectionDistance)
    sw      $ra, 0x44($sp)
    sw      $fp, 0x40($sp)
    sw      $s7, 0x3C($sp)
    sw      $s6, 0x38($sp)
    sw      $s5, 0x34($sp)
    sw      $s4, 0x30($sp)
    sw      $s3, 0x2C($sp)
    sw      $s2, 0x28($sp)
    sw      $s0, 0x20($sp)
    lw      $v0, 0x8C($v0)
    lw      $v1, %lo(vs_main_projectionDistance)($v1)
    addiu   $v0, $v0, 0x4
    sw      $v0, 0x10($sp)
    lui     $v0, %hi(D_800F53BC)
    lw      $v0, %lo(D_800F53BC)($v0)
    sll     $v1, $v1, 10
    sw      $v1, 0x14($sp)
    sw      $v0, 0x18($sp)
    ctc2    $zero, $11
    addiu   $t7, $zero, 0x1000
    ctc2    $t7, $12
    beqz    $s1, .L800D77E4
    lui     $s7, (0x1F800000 >> 16)
    addiu   $fp, $s7, %lo(vs_scratch)
.L800D6EBC:
    lbu     $v0, 0x42($s1)
    nop
    beqz    $v0, .L800D6EDC
    addiu   $v0, $v0, -0x2
    sb      $v0, 0x42($s1)
    andi    $v0, $v0, 0xFF
    bnez    $v0, .L800D6FAC
    nop
.L800D6EDC:
    lw      $a2, 0x54($s1)
    lui     $a0, (0x10000000 >> 16)
    lui     $t0, (0x20000000 >> 16)
    lui     $a3, (0x30000000 >> 16)
.L800D6EEC:
    lhu     $v0, 0x4A($s1)
    nop
    addu    $v0, $a2, $v0
    lw      $a1, 0x0($v0)
    lui     $t7, (0xF0000000 >> 16)
    and     $v1, $a1, $t7
    beq     $v1, $a0, .L800D6F7C
    sltu    $v0, $a0, $v1
    bnez    $v0, .L800D6F24
    nop
    beqz    $v1, .L800D6F3C
    lui     $v1, %hi(D_800F569C)
    j       .L800D6EEC
    nop
.L800D6F24:
    beq     $v1, $t0, .L800D6FA4
    nop
    beq     $v1, $a3, .L800D6FAC
    nop
    j       .L800D6EEC
    nop
.L800D6F3C:
    lbu     $v0, 0x52($s1)
    lw      $v1, %lo(D_800F569C)($v1)
    sll     $v0, $v0, 2
    addu    $v1, $v1, $v0
    sra     $v0, $a1, 16
    lw      $a0, 0x98($v1)
    andi    $v0, $v0, 0x3FFF
    sh      $v0, 0x42($s1)
    andi    $v0, $a1, 0xFFFF
    lhu     $v1, 0x4A($s1)
    sll     $v0, $v0, 2
    addiu   $v1, $v1, 0x4
    addu    $a0, $a0, $v0
    sh      $v1, 0x4A($s1)
    j       .L800D6FAC
    sw      $a0, 0x58($s1)
.L800D6F7C:
    sll     $v0, $a1, 18
    sra     $v0, $v0, 18
    sh      $v0, 0x44($s1)
    sll     $v0, $a1, 4
    lhu     $v1, 0x4A($s1)
    sra     $v0, $v0, 18
    sh      $v0, 0x46($s1)
    addiu   $v1, $v1, 0x4
    j       .L800D6EEC
    sh      $v1, 0x4A($s1)
.L800D6FA4:
    j       .L800D6EEC
    sh      $zero, 0x4A($s1)
.L800D6FAC:
    lw      $v0, 0xC($s1)
    lh      $a0, 0x44($s1)
    lw      $v1, 0x10($s1)
    sra     $v0, $v0, 12
    addu    $t2, $v0, $a0
    sra     $v1, $v1, 12
    lh      $v0, 0x46($s1)
    lw      $a0, 0x14($s1)
    addu    $t1, $v1, $v0
    andi    $v1, $t2, 0xFFFF
    sll     $v0, $t1, 16
    addu    $s2, $v1, $v0
    lw      $v1, 0x5C($s1)
    lui     $v0, (0x20000 >> 16)
    and     $v0, $v1, $v0
    beqz    $v0, .L800D70F8
    sra     $t0, $a0, 12
    lui     $v0, (0x80000 >> 16)
    and     $v0, $v1, $v0
    beqz    $v0, .L800D708C
    nop
    lbu     $v1, 0x6A($s1)
    lw      $t7, 0x18($sp)
    sll     $v0, $v1, 1
    addu    $v0, $v0, $v1
    sll     $v0, $v0, 2
    addu    $v0, $v0, $v1
    sll     $v0, $v0, 4
    addu    $v0, $v0, $t7
    addiu   $v0, $v0, 0x54
    lw      $t4, 0x0($v0)
    lw      $t5, 0x4($v0)
    ctc2    $t4, $0
    ctc2    $t5, $1
    lw      $t4, 0x8($v0)
    lw      $t5, 0xC($v0)
    lw      $t6, 0x10($v0)
    ctc2    $t4, $2
    ctc2    $t5, $3
    ctc2    $t6, $4
    lw      $t4, 0x14($v0)
    lw      $t5, 0x18($v0)
    ctc2    $t4, $5
    lw      $t6, 0x1C($v0)
    ctc2    $t5, $6
    ctc2    $t6, $7
    addu    $s0, $t0, $zero
    mtc2    $s2, $0
    mtc2    $s0, $1
    nop
    nop
    rtv0tr
    mfc2    $s0, $26
    nop
    bgtz    $s0, .L800D77D4
    nop
.L800D708C:
    lbu     $v1, 0x6A($s1)
    lw      $t7, 0x18($sp)
    sll     $v0, $v1, 1
    addu    $v0, $v0, $v1
    sll     $v0, $v0, 2
    addu    $v0, $v0, $v1
    sll     $v0, $v0, 4
    addu    $v0, $v0, $t7
    addiu   $v0, $v0, 0x74
    lw      $t4, 0x0($v0)
    lw      $t5, 0x4($v0)
    ctc2    $t4, $0
    ctc2    $t5, $1
    lw      $t4, 0x8($v0)
    lw      $t5, 0xC($v0)
    lw      $t6, 0x10($v0)
    ctc2    $t4, $2
    ctc2    $t5, $3
    ctc2    $t6, $4
    lw      $t4, 0x14($v0)
    lw      $t5, 0x18($v0)
    ctc2    $t4, $5
    lw      $t6, 0x1C($v0)
    ctc2    $t5, $6
    ctc2    $t6, $7
    j       .L800D7160
    addu    $s0, $t0, $zero
.L800D70F8:
    lui     $v0, (0x80000 >> 16)
    and     $v0, $v1, $v0
    beqz    $v0, .L800D7110
    lui     $t7, %hi(vs_scratch + 0x14)
    bgtz    $t1, .L800D77D4
    nop
.L800D7110:
    addiu   $t7, $t7, %lo(vs_scratch + 0x14)
    lw      $t4, 0x0($t7)
    lw      $t5, 0x4($t7)
    ctc2    $t4, $0
    ctc2    $t5, $1
    lw      $t4, 0x8($t7)
    lw      $t5, 0xC($t7)
    lw      $t6, 0x10($t7)
    ctc2    $t4, $2
    ctc2    $t5, $3
    ctc2    $t6, $4
    lui     $t7, %hi(vs_scratch + 0x14)
    addiu   $t7, $t7, %lo(vs_scratch + 0x14)
    lw      $t4, 0x14($t7)
    lw      $t5, 0x18($t7)
    ctc2    $t4, $5
    lw      $t6, 0x1C($t7)
    ctc2    $t5, $6
    ctc2    $t6, $7
    addu    $s0, $t0, $zero
.L800D7160:
    mtc2    $s2, $0
    mtc2    $s0, $1
    nop
    nop
    rtps
    mfc2    $s2, $14
    mfc2    $t3, $19
    lw      $v1, 0x60($s1)
    nop
    andi    $v0, $v1, 0xF00
    beqz    $v0, .L800D719C
    sra     $t3, $t3, 2
    srl     $v0, $v1, 8
    j       .L800D71A0
    andi    $a0, $v0, 0xF
.L800D719C:
    lbu     $a0, 0x43($s1)
.L800D71A0:
    nop
    sltiu   $v0, $a0, 0x5
    beqz    $v0, .L800D71EC
    addu    $s3, $t3, $zero
    lui     $v0, %hi(jtbl_80069B54)
    addiu   $v0, $v0, %lo(jtbl_80069B54)
    sll     $v1, $a0, 2
    addu    $v1, $v1, $v0
    lw      $v0, 0x0($v1)
    nop
    jr      $v0
    nop
.L800D71D0:
    j       .L800D71EC
    addiu   $s3, $s3, -0x8
.L800D71D8:
    j       .L800D71EC
    addiu   $s3, $s3, -0x10
.L800D71E0:
    j       .L800D71EC
    addiu   $s3, $s3, 0x8
.L800D71E8:
    addiu   $s3, $s3, 0x10
.L800D71EC:
    slti    $v0, $s3, 0x800
    beqz    $v0, .L800D77D4
    lui     $v0, %hi(vs_main_nearClip)
    lw      $v0, %lo(vs_main_nearClip)($v0)
    nop
    slt     $v0, $v0, $s3
    beqz    $v0, .L800D77D4
    addiu   $v0, $zero, 0x6
    beq     $a0, $v0, .L800D7250
    slti    $v0, $a0, 0x7
    beqz    $v0, .L800D722C
    addiu   $v0, $zero, 0x5
    beq     $a0, $v0, .L800D7248
    lui     $a1, (0xFFFFFF >> 16)
    j       .L800D726C
    ori     $a1, $a1, (0xFFFFFF & 0xFFFF)
.L800D722C:
    addiu   $v0, $zero, 0x7
    beq     $a0, $v0, .L800D7258
    addiu   $v0, $zero, 0x8
    beq     $a0, $v0, .L800D7260
    lui     $a1, (0xFFFFFF >> 16)
    j       .L800D726C
    ori     $a1, $a1, (0xFFFFFF & 0xFFFF)
.L800D7248:
    j       .L800D7264
    addiu   $s3, $zero, 0x7FE
.L800D7250:
    j       .L800D7264
    addiu   $s3, $zero, -0xF
.L800D7258:
    j       .L800D7264
    addiu   $s3, $zero, -0xD
.L800D7260:
    addiu   $s3, $zero, -0xB
.L800D7264:
    lui     $a1, (0xFFFFFF >> 16)
    ori     $a1, $a1, (0xFFFFFF & 0xFFFF)
.L800D726C:
    sll     $a0, $s3, 2
    lw      $a3, (0x1F800000 & 0xFFFF)($s7)
    lui     $a2, (0xE1000200 >> 16)
    addiu   $v0, $a3, 0xC
    sw      $v0, (0x1F800000 & 0xFFFF)($s7)
    lw      $v0, 0x4($fp)
    ori     $a2, $a2, (0xE1000200 & 0xFFFF)
    addu    $v0, $a0, $v0
    lw      $v1, 0x0($v0)
    lui     $v0, (0x1000000 >> 16)
    and     $v1, $v1, $a1
    or      $v1, $v1, $v0
    sw      $v1, 0x0($a3)
    lw      $v0, 0x4($fp)
    and     $a1, $a3, $a1
    addu    $a0, $a0, $v0
    lw      $v1, 0x0($a0)
    lui     $v0, (0xFF000000 >> 16)
    and     $v1, $v1, $v0
    or      $v1, $v1, $a1
    sw      $v1, 0x0($a0)
    sw      $a2, 0x4($a3)
    sw      $zero, 0x8($a3)
    lw      $v0, 0x5C($s1)
    lui     $v1, (0x10000 >> 16)
    and     $v0, $v0, $v1
    beqz    $v0, .L800D73D0
    nop
    lw      $a0, 0x18($s1)
    lw      $v0, 0x1C($s1)
    lw      $v1, 0x20($s1)
    sra     $a0, $a0, 5
    addu    $a0, $t2, $a0
    andi    $a0, $a0, 0xFFFF
    sra     $v0, $v0, 5
    addu    $v0, $t1, $v0
    sll     $v0, $v0, 16
    addu    $t2, $a0, $v0
    sra     $v1, $v1, 5
    addu    $t0, $t0, $v1
    mtc2    $t2, $0
    mtc2    $t0, $1
    nop
    nop
    rtps
    mfc2    $t2, $14
    sll     $v1, $s2, 16
    sra     $v1, $v1, 16
    sll     $v0, $t2, 16
    sra     $v0, $v0, 16
    subu    $t1, $v1, $v0
    sra     $v1, $s2, 16
    sra     $v0, $t2, 16
    subu    $t0, $v1, $v0
    or      $a0, $t0, $t1
    beqz    $a0, .L800D73CC
    addu    $v1, $zero, $zero
    bgez    $t1, .L800D735C
    addu    $a1, $t1, $zero
    negu    $a1, $t1
.L800D735C:
    bgez    $t0, .L800D7368
    addu    $a2, $t0, $zero
    negu    $a2, $t0
.L800D7368:
    slt     $v0, $a1, $a2
    beqz    $v0, .L800D7398
    addiu   $a0, $zero, 0x200
    sll     $v1, $a1, 9
    div     $zero, $v1, $a2
    mflo    $v1
    lui     $v0, %hi(D_80040A14)
    addiu   $v0, $v0, %lo(D_80040A14)
    addu    $v0, $v1, $v0
    lbu     $v1, 0x0($v0)
    j       .L800D73B4
    subu    $v1, $a0, $v1
.L800D7398:
    sll     $v1, $a2, 9
    div     $zero, $v1, $a1
    mflo    $v1
    lui     $v0, %hi(D_80040A14)
    addiu   $v0, $v0, %lo(D_80040A14)
    addu    $v0, $v1, $v0
    lbu     $v1, 0x0($v0)
.L800D73B4:
    beq     $a1, $t1, .L800D73C0
    addiu   $a0, $zero, 0x400
    subu    $v1, $a0, $v1
.L800D73C0:
    beq     $a2, $t0, .L800D73CC
    sll     $v1, $v1, 1
    negu    $v1, $v1
.L800D73CC:
    sh      $v1, 0x50($s1)
.L800D73D0:
    lw      $t7, 0x14($sp)
    nop
    div     $zero, $t7, $t3
    sll     $v0, $s2, 16
    sra     $v1, $v0, 16
    ctc2    $v1, $13
    sra     $s2, $s2, 16
    ctc2    $s2, $14
    ctc2    $zero, $15
    lui     $s6, %hi(D_800F569C)
    lw      $s5, 0x58($s1)
    lw      $v1, %lo(D_800F569C)($s6)
    lhu     $a0, 0x2($s5)
    lw      $v1, 0xA8($v1)
    sll     $v0, $a0, 1
    addu    $v0, $v0, $a0
    sll     $v0, $v0, 3
    addu    $s4, $v1, $v0
    mflo    $s2
    lh      $a0, 0x50($s1)
    jal     rcos
    nop
    lbu     $v1, 0x60($s1)
    nop
    mult    $v0, $v1
    mflo    $v0
    bgez    $v0, .L800D7448
    sra     $s0, $v0, 2
    addiu   $v0, $v0, 0x3
    sra     $s0, $v0, 2
.L800D7448:
    mult    $s2, $s0
    mflo    $s0
    lh      $a0, 0x50($s1)
    jal     rsin
    nop
    lbu     $v1, 0x60($s1)
    nop
    mult    $v0, $v1
    mflo    $v0
    bgez    $v0, .L800D747C
    sra     $v1, $v0, 2
    addiu   $v0, $v0, 0x3
    sra     $v1, $v0, 2
.L800D747C:
    sra     $s0, $s0, 12
    mult    $s2, $v1
    andi    $s0, $s0, 0xFFFF
    mflo    $v1
    sra     $v1, $v1, 12
    negu    $v0, $v1
    sll     $v0, $v0, 16
    or      $s2, $s0, $v0
    ctc2    $s2, $8
    sll     $v1, $v1, 16
    ctc2    $v1, $9
    ctc2    $s0, $10
    addu    $a2, $zero, $zero
    lbu     $v0, 0x77($s1)
    lbu     $v1, 0x74($s1)
    addiu   $v0, $v0, 0x1
    beqz    $v1, .L800D7514
    andi    $a3, $v0, 0xFF
    addu    $v0, $v1, $zero
    lw      $t7, 0x10($sp)
    addiu   $a1, $v0, -0x1
    addu    $v0, $t7, $a1
    lbu     $v0, 0x0($v0)
    nop
    div     $zero, $a3, $v0
    mfhi    $a0
    lw      $v0, %lo(D_800F569C)($s6)
    sll     $v1, $a1, 2
    addu    $v0, $v0, $v1
    lw      $v0, 0xC($v0)
    nop
    addu    $v0, $v0, $a0
    lbu     $a1, 0x0($v0)
    nop
    beqz    $a1, .L800D7518
    sll     $v0, $a1, 1
    j       .L800D7518
    addiu   $a2, $v0, -0x1
.L800D7514:
    addiu   $a2, $zero, 0x80
.L800D7518:
    lbu     $v0, 0x75($s1)
    nop
    beqz    $v0, .L800D757C
    addiu   $a1, $v0, -0x1
    lw      $t7, 0x10($sp)
    nop
    addu    $v0, $t7, $a1
    lbu     $v0, 0x0($v0)
    nop
    div     $zero, $a3, $v0
    mfhi    $a0
    lui     $v0, %hi(D_800F569C)
    lw      $v0, %lo(D_800F569C)($v0)
    sll     $v1, $a1, 2
    addu    $v0, $v0, $v1
    lw      $v0, 0xC($v0)
    nop
    addu    $v0, $v0, $a0
    lbu     $a1, 0x0($v0)
    nop
    beqz    $a1, .L800D7580
    sll     $v0, $a1, 9
    addiu   $v0, $v0, -0x100
    j       .L800D7580
    or      $a2, $a2, $v0
.L800D757C:
    ori     $a2, $a2, 0x8000
.L800D7580:
    lbu     $v0, 0x76($s1)
    nop
    beqz    $v0, .L800D75E4
    addiu   $a1, $v0, -0x1
    lw      $t7, 0x10($sp)
    nop
    addu    $v0, $t7, $a1
    lbu     $v0, 0x0($v0)
    nop
    div     $zero, $a3, $v0
    mfhi    $a0
    lui     $v0, %hi(D_800F569C)
    lw      $v0, %lo(D_800F569C)($v0)
    sll     $v1, $a1, 2
    addu    $v0, $v0, $v1
    lw      $v0, 0xC($v0)
    nop
    addu    $v0, $v0, $a0
    lbu     $a1, 0x0($v0)
    nop
    beqz    $a1, .L800D75EC
    sll     $v0, $a1, 1
    addiu   $v0, $v0, -0x1
    j       .L800D75E8
    sll     $v0, $v0, 16
.L800D75E4:
    lui     $v0, (0x800000 >> 16)
.L800D75E8:
    or      $a2, $a2, $v0
.L800D75EC:
    lhu     $v0, 0x0($s5)
    nop
    beqz    $v0, .L800D7774
    addu    $a1, $zero, $zero
    lui     $v0, (0x2E000000 >> 16)
    or      $t5, $a2, $v0
    lui     $v0, (0x2C000000 >> 16)
    or      $t4, $a2, $v0
    sll     $t3, $s3, 2
    lui     $t2, (0xFFFFFF >> 16)
    ori     $t2, $t2, (0xFFFFFF & 0xFFFF)
    addiu   $t1, $s4, 0x14
    addiu   $v0, $s4, 0x8
.L800D7620:
    lw      $a2, (0x1F800000 & 0xFFFF)($s7)
    lwc2    $0, 0x0($v0)
    addiu   $v0, $s4, 0xC
    lwc2    $2, 0x0($v0)
    addiu   $v0, $s4, 0x10
    lwc2    $4, 0x0($v0)
    lw      $a3, 0x0($s4)
    lhu     $t0, -0x10($t1)
    lhu     $a0, -0xE($t1)
    llv0bk
    nop
    andi    $v0, $a0, 0xFF00
    addu    $v0, $t0, $v0
    sh      $v0, 0x1C($a2)
    andi    $v1, $a0, 0xFF
    addu    $v1, $t0, $v1
    sra     $v0, $a3, 16
    sll     $v0, $v0, 16
    or      $v1, $v1, $v0
    sw      $v1, 0x14($a2)
    mfc2    $s2, $9
    mfc2    $s0, $10
    andi    $v0, $s2, 0xFFFF
    sll     $v1, $s0, 16
    addu    $v0, $v0, $v1
    sw      $v0, 0x8($a2)
    llv1bk
    andi    $v0, $a3, 0x8000
    beqz    $v0, .L800D76A0
    nop
    j       .L800D76A4
    sw      $t5, 0x4($a2)
.L800D76A0:
    sw      $t4, 0x4($a2)
.L800D76A4:
    addu    $v0, $t0, $a0
    sh      $v0, 0x24($a2)
    mfc2    $s2, $9
    mfc2    $s0, $10
    andi    $v0, $s2, 0xFFFF
    sll     $v1, $s0, 16
    addu    $v0, $v0, $v1
    sw      $v0, 0x10($a2)
    llv2bk
    lw      $v0, (0x1F800000 & 0xFFFF)($s7)
    lw      $v1, 0x4($fp)
    addiu   $v0, $v0, 0x28
    addu    $v1, $t3, $v1
    sw      $v0, (0x1F800000 & 0xFFFF)($s7)
    lw      $v0, 0x0($v1)
    lui     $v1, (0x9000000 >> 16)
    and     $v0, $v0, $t2
    or      $v0, $v0, $v1
    sw      $v0, 0x0($a2)
    mfc2    $s2, $9
    mfc2    $s0, $10
    andi    $v0, $s2, 0xFFFF
    sll     $v1, $s0, 16
    addu    $v0, $v0, $v1
    sw      $v0, 0x18($a2)
    lwc2    $0, 0x0($t1)
    andi    $v0, $t0, 0xFFFF
    sll     $v1, $a3, 16
    or      $v0, $v0, $v1
    sw      $v0, 0xC($a2)
    llv0bk
    addiu   $t1, $t1, 0x18
    lw      $a0, 0x4($fp)
    addiu   $s4, $s4, 0x18
    addu    $a0, $t3, $a0
    lw      $v0, 0x0($a0)
    lui     $v1, (0xFF000000 >> 16)
    and     $v0, $v0, $v1
    and     $v1, $a2, $t2
    or      $v0, $v0, $v1
    sw      $v0, 0x0($a0)
    mfc2    $s2, $9
    mfc2    $s0, $10
    andi    $v0, $s2, 0xFFFF
    sll     $v1, $s0, 16
    addu    $v0, $v0, $v1
    sw      $v0, 0x20($a2)
    lhu     $v0, 0x0($s5)
    addiu   $a1, $a1, 0x1
    slt     $v0, $a1, $v0
    bnez    $v0, .L800D7620
    addiu   $v0, $s4, 0x8
.L800D7774:
    lui     $a1, (0xFFFFFF >> 16)
    lw      $a3, (0x1F800000 & 0xFFFF)($s7)
    sll     $a0, $s3, 2
    addiu   $v0, $a3, 0xC
    sw      $v0, (0x1F800000 & 0xFFFF)($s7)
    lw      $v0, 0x4($fp)
    ori     $a1, $a1, (0xFFFFFF & 0xFFFF)
    addu    $v0, $a0, $v0
    lw      $v1, 0x0($v0)
    lui     $v0, (0x1000000 >> 16)
    and     $v1, $v1, $a1
    or      $v1, $v1, $v0
    sw      $v1, 0x0($a3)
    lw      $v0, 0x4($fp)
    and     $a1, $a3, $a1
    addu    $a0, $a0, $v0
    lw      $v1, 0x0($a0)
    lui     $v0, (0xFF000000 >> 16)
    and     $v1, $v1, $v0
    or      $v1, $v1, $a1
    lui     $v0, (0xE1000000 >> 16)
    sw      $v1, 0x0($a0)
    sw      $v0, 0x4($a3)
    sw      $zero, 0x8($a3)
.L800D77D4:
    lw      $s1, 0x4($s1)
    nop
    bnez    $s1, .L800D6EBC
    nop
.L800D77E4:
    lw      $ra, 0x44($sp)
    lw      $fp, 0x40($sp)
    lw      $s7, 0x3C($sp)
    lw      $s6, 0x38($sp)
    lw      $s5, 0x34($sp)
    lw      $s4, 0x30($sp)
    lw      $s3, 0x2C($sp)
    lw      $s2, 0x28($sp)
    lw      $s1, 0x24($sp)
    lw      $s0, 0x20($sp)
    jr      $ra
    addiu   $sp, $sp, 0x48
endlabel func_800D6E44
