.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800C0B50
    addiu   $sp, $sp, -0x48
    sw      $s7, 0x3C($sp)
    addu    $s7, $a0, $zero
    sw      $fp, 0x40($sp)
    addu    $fp, $a1, $zero
    sw      $s0, 0x20($sp)
    lui     $s0, %hi(D_800EB9B8)
    lw      $v0, %lo(D_800EB9B8)($s0)
    addiu   $a0, $s7, 0x4
    sw      $ra, 0x44($sp)
    sw      $s6, 0x38($sp)
    sw      $s5, 0x34($sp)
    sw      $s4, 0x30($sp)
    sw      $s3, 0x2C($sp)
    sw      $s2, 0x28($sp)
    sw      $s1, 0x24($sp)
    lh      $a1, 0x2($s7)
    jal     func_800C085C
    addiu   $s6, $v0, 0x48
    lui     $a1, (0x1F800398 >> 16)
    ori     $a1, $a1, (0x1F800398 & 0xFFFF)
    lw      $a0, %lo(D_800EB9B8)($s0)
    addu    $s1, $v0, $zero
    jal     RotMatrixYXZ_gte
    addiu   $a0, $a0, 0x24
    lw      $v0, %lo(D_800EB9B8)($s0)
    lui     $s3, (0x1F800398 >> 16)
    lh      $a0, 0x2A($v0)
    ori     $s3, $s3, (0x1F800398 & 0xFFFF)
    jal     rcos
    sll     $a0, $a0, 6
    addu    $s2, $v0, $zero
    lui     $a0, (0x1F800398 >> 16)
    ori     $a0, $a0, (0x1F800398 & 0xFFFF)
    addiu   $a1, $sp, 0x10
    sw      $s2, 0x10($sp)
    sw      $s2, 0x14($sp)
    jal     ScaleMatrix
    sw      $s2, 0x18($sp)
    addu    $a0, $s1, $zero
    lui     $a1, (0x1F800398 >> 16)
    jal     func_80041C68
    ori     $a1, $a1, (0x1F800398 & 0xFFFF)
    jal     func_800C02A8
    nop
    lw      $a2, 0x4($s3)
    lw      $s5, 0x8($s3)
    lw      $s1, 0xC($s3)
    lw      $s4, 0x10($s3)
    lw      $t0, 0x0($s3)
    nop
    ctc2    $t0, $8
    ctc2    $a2, $9
    ctc2    $s5, $10
    ctc2    $s1, $11
    ctc2    $s4, $12
    lh      $s2, 0x8($s7)
    lh      $a2, 0xA($s7)
    lh      $s5, 0xC($s7)
    ctc2    $s2, $13
    ctc2    $a2, $14
    ctc2    $s5, $15
    lui     $v0, (0x44000000 >> 16)
    or      $fp, $fp, $v0
    lbu     $a0, 0x4($s7)
    lbu     $v0, 0x6($s7)
    lw      $v1, %lo(D_800EB9B8)($s0)
    sltu    $v0, $v0, $a0
    lhu     $s1, 0x32($v1)
    bnez    $v0, .L800C0C70
    addu    $s4, $a0, $zero
    lbu     $s4, 0x6($s7)
.L800C0C70:
    lui     $v0, %hi(D_800EB9B8)
    lw      $v0, %lo(D_800EB9B8)($v0)
    nop
    lh      $v0, 0x20($v0)
    nop
    sll     $s0, $v0, 1
.L800C0C88:
    lwc2    $0, 0x0($s6)
    lwc2    $1, 0x4($s6)
    beqz    $s1, .L800C0D48
    addiu   $s1, $s1, -0x1
    mvmva   1, 1, 0, 1, 0
    mfc2    $s2, $9
    mfc2    $a2, $10
    mfc2    $s5, $11
    andi    $v0, $s2, 0xFFFF
    sll     $v1, $a2, 16
    or      $s2, $v0, $v1
    mtc2    $s2, $0
    mtc2    $s5, $1
    lh      $a2, 0x6($s6)
    addiu   $s6, $s6, 0x8
    rtps
    swc2    $14, 0x0($s3)
    addiu   $v0, $s3, 0x4
    mfc2    $t4, $19
    nop
    sra     $t4, $t4, 2
    sw      $t4, 0x0($v0)
    beqz    $a2, .L800C0D20
    addu    $a0, $s3, $zero
    lhu     $a3, 0x4($s3)
    lh      $v0, 0xC($s3)
    sll     $a3, $a3, 16
    sra     $a3, $a3, 16
    addu    $a3, $a3, $v0
    subu    $a3, $a3, $s0
    div     $zero, $a3, $s4
    mflo    $a3
    addiu   $a1, $s3, 0x8
    sll     $a2, $a2, 25
    subu    $a2, $fp, $a2
    addiu   $v0, $zero, 0x20
    jal     func_800C0990
    subu    $a3, $v0, $a3
.L800C0D20:
    addu    $a2, $zero, $zero
    addu    $v1, $s3, $zero
.L800C0D28:
    lhu     $v0, 0x0($v1)
    addiu   $a2, $a2, 0x1
    sh      $v0, 0x8($v1)
    slti    $v0, $a2, 0x3
    bnez    $v0, .L800C0D28
    addiu   $v1, $v1, 0x2
    j       .L800C0C88
    nop
.L800C0D48:
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
endlabel func_800C0B50
