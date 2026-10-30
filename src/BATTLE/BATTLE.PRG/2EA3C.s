.include "macro.inc"
.include "src/include/gte_reg_macros.inc"

.set noat

.section .text, "ax"

nonmatching func_8009723C, 0x14C

glabel func_8009723C
    lui        $a3, %hi(0x1F8003FC)
    sw         $fp, %lo(0x1F8003D4)($a3)
    sw         $gp, %lo(0x1F8003D8)($a3)
    sw         $ra, %lo(0x1F8003DC)($a3)
    sw         $s0, %lo(0x1F8003E0)($a3)
    sw         $s1, %lo(0x1F8003E4)($a3)
    sw         $s2, %lo(0x1F8003E8)($a3)
    or         $s0, $zero, $a0
    sw         $s3, %lo(0x1F8003EC)($a3)
    or         $s1, $zero, $a0
    sw         $s4, %lo(0x1F8003F0)($a3)
    lw         $s2, 0x0($s1)
    sw         $s5, %lo(0x1F8003F4)($a3)
    addiu      $s1, 0x4
    sw         $s6, %lo(0x1F8003F8)($a3)
    sw         $s7, %lo(0x1F8003FC)($a3)
    addu       $s6, $a1, $zero
    lw         $a1, %lo(0x1F800000)($a3)
    lw         $a2, %lo(0x1F800004)($a3)
  0:
    lw         $at, %lo(0x1F800000)($a3)
    li         $t0, 0x10000
    lw         $v0, 0x0($s1)
    subu       $at, $a1, $at
    lw         $a0, 0x1C($s1)
    subu       $at, $t0
    lw         $v1, %lo(0x1F800010)($a3)
    addiu     $s3, $s1, 0x20
    bgez       $at, 3f
    and        $at, $v0, 0x1100
.set noreorder
    bnez       $at, 2f
     srl       $at, $v0, 15
.set reorder
    and        $at, 0x1
    and        $at, $s6
    lui       $t0, %hi(0xFFFF6000)
    bnez       $at, 2f
    or         $t0, (0xFFFF6000 & 0xFFFF)
    xor        $gp, $v0, 0x800
    and        $gp, 0x800
    srl        $at, $gp, 11
    srl        $gp, 10
    or         $gp, $at
    and        $t0, $v0
    or         $gp, $t0
    and        $at, $v1, 0xFF
    srl        $v1, 16
    xor       $v0, 0xFF
    bnez       $v1, 1f
    and        $v0, $at
.set noreorder
    bnez       $v0, 2f
.set reorder
  1:
     lw        $t0, 0x0($s3)
    lw         $t1, 0x4($s3)
    lw         $t2, 0x8($s3)
    lw         $t3, 0xC($s3)
    ctc2       $t0, $0
    lw         $t4, 0x10($s3)
    ctc2       $t1, $1
    lw         $t5, 0x14($s3)
    ctc2       $t2, $2
    lw         $t6, 0x18($s3)
    ctc2       $t3, $3
    lw         $t7, 0x1C($s3)
    ctc2       $t4, $4
    ctc2       $t5, $5
    ctc2       $t6, $6
    ctc2       $t7, $7
    addu       $a0, $s0
.set noreorder
    jal        func_80097388
.set reorder
  2:
     addiu     $s2, -0x1
    addiu     $s1, 0x40
    bnez       $s2, 0b
  3:
    sw         $a1, %lo(0x1F800000)($a3)
    lw         $fp, %lo(0x1F8003D4)($a3)
    lw         $gp, %lo(0x1F8003D8)($a3)
    lw         $ra, %lo(0x1F8003DC)($a3)
    lw         $s0, %lo(0x1F8003E0)($a3)
    lw         $s1, %lo(0x1F8003E4)($a3)
    lw         $s2, %lo(0x1F8003E8)($a3)
    lw         $s3, %lo(0x1F8003EC)($a3)
    lw         $s4, %lo(0x1F8003F0)($a3)
    lw         $s5, %lo(0x1F8003F4)($a3)
    lw         $s6, %lo(0x1F8003F8)($a3)
.set noreorder
    jr         $ra
     lw        $s7, %lo(0x1F8003FC)($a3)
.set reorder
endlabel func_8009723C

nonmatching func_80097388, 0x5F4

glabel func_80097388
    sw         $ra, 0x3C4($a3)
    sw         $s0, 0x3C8($a3)
    sw         $s1, 0x3CC($a3)
    sw         $s2, 0x3D0($a3)
    lw         $at, 0x4($a0)
    lw         $v0, 0x0($a0)
    sll        $at, 16
    or         $v0, $at
    addiu     $a0, 0x8
    jal        func_8009797C
    and        $at, $v0, 0xFFFF
    addu      $a3, $a0, $zero
    beqz       $at, 5f
  0:
    lw         $s7, 0xC($a0)
    addiu     $a3, 0x20
    jal        func_80097A10
    li        $t0, 0x1000000
    bgez       $at, 1f
    and        $t0, $s7
    negu      $at, $at
    beqz       $t0, 4f
  1:
    addu       $fp, $at, $zero
    mfc2       $t0, $12
    mfc2       $t1, $13
    mfc2       $t2, $14
.set noreorder
    jal        func_80098014
     addu      $t3, $t2, $zero
    beqz       $at, 4f
     and       $at, $s6, 0x1
    beqz       $at, 2f
.set reorder
     sltiu     $at, $fp, 0x200
    srl       $t4, $gp, 13
    bnez       $at, 2f
    and        $t4, 0x3
    srl        $at, $t9, 9
    subu       $at, $t4, $at
    lui       $fp, %hi(0x1F800390)
    blez       $at, 2f
    or         $fp, (0x1F800390 & 0xFFFF)
    sw         $s0, 0x0($fp)
    sw         $s1, 0x4($fp)
    sw         $s2, 0x8($fp)
    sw         $s3, 0xC($fp)
    sw         $s4, 0x10($fp)
    sw         $s5, 0x14($fp)
    addiu      $fp, -0x4C
    addiu      $s0, $fp, 0x10
    addiu      $s1, $fp, 0x24
    addiu      $s2, $fp, 0x38
    sw         $at, 0x0($fp)
    sw         $s0, 0x4($fp)
    sw         $s1, 0x8($fp)
    sw         $s2, 0xC($fp)
    swc2       $0, 0x0($s0)
    swc2       $2, 0x0($s1)
    swc2       $4, 0x0($s2)
    mfc2       $t4, $1
    mfc2       $t5, $3
    mfc2       $t6, $5
    sh         $t4, 0x4($s0)
    sh         $t5, 0x4($s1)
    sh         $t6, 0x4($s2)
    lw         $t4, 0x10($a0)
    lw         $t5, 0x14($a0)
    lw         $t6, 0x18($a0)
    lw         $t7, 0x1C($a0)
    sw         $t0, 0xC($s0)
    sw         $t1, 0xC($s1)
    sw         $t2, 0xC($s2)
    swc2       $17, 0x10($s0)
    swc2       $18, 0x10($s1)
    swc2       $19, 0x10($s2)
    li         $t8, 0xFFFFFF
    li         $t9, 0x1000000
    and        $at, $s7, $t8
    or         $at, $t9
    sw         $at, 0x8($s0)
    and        $at, $t4, $t8
    or         $at, $t9
    sw         $at, 0x8($s1)
    and        $at, $t5, $t8
    or         $at, $t9
    sw         $at, 0x8($s2)
    li         $t8, 0xFE000000
    lui        $t9, %hi(0x1F8003BC)
    and        $at, $s7, $t8
    sw         $at, %lo(0x1F8003B8)($t9)
    li         $t8, 0xFFFF0000
    and        $at, $t6, $t8
    sw         $at, %lo(0x1F8003C0)($t9)
    and        $at, $t7, $t8
    sw         $at, %lo(0x1F8003BC)($t9)
    and        $t6, 0xFFFF
    sh         $t6, 0x6($s0)
    and        $t7, 0xFFFF
    sh         $t7, 0x6($s1)
    srl        $t4, 24
    srl        $t5, 24
    sll        $t5, 8
    or         $t4, $t5
    sh        $t4, 0x6($s2)
    jal        func_80097AEC
    addiu      $fp, 0x4C
    lw         $s0, 0x0($fp)
    lw         $s1, 0x4($fp)
    lw         $s2, 0x8($fp)
    lw         $s3, 0xC($fp)
    lw         $s4, 0x10($fp)
.set noreorder
    b          4f
     lw        $s5, 0x14($fp)
.set reorder
  2:
    sw         $t0, 0x8($a1)
    li        $v1, 0x9000000
    jal        func_800980F8
    sw         $t1, 0x14($a1)
    sw        $t2, 0x20($a1)
    beqz       $at, 4f
    lw         $t0, 0x10($a0)
    lw         $t1, 0x14($a0)
    lw         $t2, 0x18($a0)
    lw         $t3, 0x1C($a0)
    li         $at, 0xFEFFFFFF
    and        $s7, $at
    sw         $s7, 0x4($a1)
    srl        $t4, $t0, 24
    sw         $t0, 0x10($a1)
    srl        $t5, $t1, 24
    sw         $t1, 0x1C($a1)
    sll        $t5, 8
  alabel D_80097590
    sltiu      $at, $t9, 0x200
    or        $t4, $t5
    bnez       $at, 3f
    li         $t9, 0xFFFF0000
    srl        $t8, $t2, 1
    and        $t8, 0x7F7F
    and        $t2, $t9
    or         $t2, $t8
    srl        $t8, $t3, 1
    and        $t8, 0x7F7F
    srl        $t3, 16
    addiu      $t3, -0x1
    sll        $t3, 16
    or         $t3, $t8
    srl        $t4, 1
    and        $t4, 0x7F7F
  3:
    sw         $t2, 0xC($a1)
    sw         $t3, 0x18($a1)
    sw         $t4, 0x24($a1)
    addiu      $a1, 0x28
  4:
    addiu      $v0, -0x1
    and        $at, $v0, 0xFFFF
    addiu     $a0, 0x20
    bnez       $at, 0b
  5:
    srl        $v0, 16
.set noreorder
    beqz       $v0, 13f
.set reorder
  6:
     lw        $s7, 0xC($a0)
    addiu     $a3, 0x28
    jal        func_80097A10
    li        $t0, 0x1000000
    bltz       $at, 7f
    or         $s7, $t0
  7:
    addu       $fp, $at, $zero
    lw         $t8, 0x20($a0)
    mfc2       $t0, $0
    mfc2       $t2, $1
    mthi       $t0
    mtlo       $t2
    sra        $t1, $t0, 16
    sll        $t0, 16
    sra        $t0, 16
    sll        $t3, $t8, 24
    sll        $t4, $t8, 16
    sll        $t5, $t8, 8
    sra        $t3, 24
    sra        $t4, 24
    sra        $t5, 24
    sllv       $t3, $t3, $gp
    sllv       $t4, $t4, $gp
    sllv       $t5, $t5, $gp
    addu       $t0, $t3
    addu       $t1, $t4
    addu       $t2, $t5
    and        $t0, 0xFFFF
    sll        $t1, 16
    or         $t0, $t1
    mtv0       $t0, $t2
    lui        $at, %hi(0x1F8003B4)
    mfc2       $t0, $12
    mfc2       $t1, $13
    mfc2       $t2, $14
    swc2       $17, %lo(0x1F8003AC)($at)
    swc2       $18, %lo(0x1F8003B0)($at)
    swc2       $19, %lo(0x1F8003B4)($at)
    rtps
    mfc2       $t3, $14
    jal        func_80098014
    li        $t4, 0x1000000
    beqz       $at, 12f
    and        $t4, $s7
    bnez       $t4, 8f
    ldsxy3     $t3, $t2, $t1
    nop
    nop
    nclip
    mfc2       $fp, $24
    nop
.set noreorder
    bltz       $fp, 12f
.set reorder
  8:
     and       $at, $s6, 0x1
.set noreorder
    beqz       $at, 9f
.set reorder
     sltiu     $at, $fp, 0x200
    srl       $t4, $gp, 13
    bnez       $at, 9f
    and        $t4, 0x3
    srl        $at, $t9, 9
    subu       $at, $t4, $at
    lui       $fp, %hi(0x1F800390)
    blez       $at, 9f
    or         $fp, (0x1F800390 & 0xFFFF)
    sw         $s0, 0x0($fp)
    sw         $s1, 0x4($fp)
    sw         $s2, 0x8($fp)
    sw         $s3, 0xC($fp)
    sw         $s4, 0x10($fp)
    sw         $s5, 0x14($fp)
    addiu      $fp, -0x64
    addiu      $s0, $fp, 0x14
    addiu      $s1, $fp, 0x28
    addiu      $s2, $fp, 0x3C
    addiu      $s3, $fp, 0x50
    sw         $at, 0x0($fp)
    sw         $s0, 0x4($fp)
    sw         $s1, 0x8($fp)
    sw         $s2, 0xC($fp)
    sw         $s3, 0x10($fp)
    mfhi       $at
    swc2       $2, 0x0($s1)
    swc2       $4, 0x0($s2)
    swc2       $0, 0x0($s3)
    sw         $at, 0x0($s0)
    mflo       $at
    mfc2       $t7, $1
    mfc2       $t5, $3
    mfc2       $t6, $5
    sh         $at, 0x4($s0)
    sh         $t7, 0x4($s3)
    sh         $t6, 0x4($s2)
    sh         $t5, 0x4($s1)
    lw         $t4, 0x10($a0)
    lw         $t5, 0x14($a0)
    lw         $t6, 0x18($a0)
    lw         $t7, 0x1C($a0)
    sw         $t0, 0xC($s0)
    sw         $t1, 0xC($s1)
    sw         $t2, 0xC($s2)
    sw         $t3, 0xC($s3)
    lui        $at, %hi(0x1F8003B4)
    lw         $t3, 0x24($a0)
    lw         $t0, %lo(0x1F8003AC)($at)
    lw         $t1, %lo(0x1F8003B0)($at)
    lw         $t2, %lo(0x1F8003B4)($at)
    sw         $t0, 0x10($s0)
    sw         $t1, 0x10($s1)
    sw         $t2, 0x10($s2)
    swc2       $19, 0x10($s3)
    srl        $t0, $t8, 24
    srl        $t1, $t3, 24
    sll        $t1, 8
    or         $t0, $t1
    sh         $t0, 0x6($s3)
    li         $t9, 0x1000000
    li         $t8, 0xFFFFFF
    and        $at, $s7, $t8
    or         $at, $t9
    sw         $at, 0x8($s0)
    and        $at, $t4, $t8
    or         $at, $t9
    sw         $at, 0x8($s1)
    and        $at, $t5, $t8
    or         $at, $t9
    sw         $at, 0x8($s2)
    and        $at, $t3, $t8
    or         $at, $t9
    sw         $at, 0x8($s3)
    lui        $t9, %hi(0x1F8003BC)
    li         $t8, 0xFE000000
    and        $at, $s7, $t8
    sw         $at, %lo(0x1F8003B8)($t9)
    li         $t8, 0xFFFF0000
    and        $at, $t6, $t8
    sw         $at, %lo(0x1F8003C0)($t9)
    and        $at, $t7, $t8
    sw         $at, %lo(0x1F8003BC)($t9)
    and        $t6, 0xFFFF
    sh         $t6, 0x6($s0)
    and        $t7, 0xFFFF
    sh         $t7, 0x6($s1)
    srl        $t4, 24
    srl        $t5, 24
    sll        $t5, 8
    or         $t4, $t5
    sh        $t4, 0x6($s2)
    jal        func_80097CF0
    addiu      $fp, 0x64
    lw         $s0, 0x0($fp)
    lw         $s1, 0x4($fp)
    lw         $s2, 0x8($fp)
    lw         $s3, 0xC($fp)
    lw         $s4, 0x10($fp)
.set noreorder
    b          12f
     lw        $s5, 0x14($fp)
.set reorder
  9:
    mfc2       $v1, $19
    sw         $t0, 0x8($a1)
    slt        $at, $v1, $t9
    bnez       $at, 10f
    or         $t9, $zero, $v1
  10:
    li        $v1, 0xC000000
    jal        func_800980F8
    sw         $t1, 0x14($a1)
    sw        $t2, 0x20($a1)
    beqz       $at, 12f
    sw         $t3, 0x2C($a1)
    lw         $t0, 0x10($a0)
    lw         $t1, 0x14($a0)
    lw         $t2, 0x18($a0)
    lw         $t3, 0x1C($a0)
    lw         $t7, 0x24($a0)
    li         $at, 0xFEFFFFFF
    sw         $t7, 0x28($a1)
    srl        $t7, 24
    sll        $t7, 8
    srl        $t8, 24
    or         $t7, $t8
    and        $s7, $at
    sw         $s7, 0x4($a1)
    srl        $t4, $t0, 24
    sw         $t0, 0x10($a1)
    srl        $t5, $t1, 24
    sw         $t1, 0x1C($a1)
    sll        $t5, 8
  alabel D_800978F8
    sltiu      $at, $t9, 0x200
    or        $t4, $t5
    bnez       $at, 11f
    li         $t9, 0xFFFF0000
    srl        $t8, $t2, 1
    and        $t8, 0x7F7F
    and        $t2, $t9
    or         $t2, $t8
    srl        $t8, $t3, 1
    and        $t8, 0x7F7F
    srl        $t3, 16
    addiu      $t3, -0x1
    sll        $t3, 16
    or         $t3, $t8
    srl        $t4, 1
    and        $t4, 0x7F7F
    srl        $t7, 1
    and        $t7, 0x7F7F
  11:
    sw         $t2, 0xC($a1)
    sw         $t3, 0x18($a1)
    sw         $t4, 0x24($a1)
    sw         $t7, 0x30($a1)
    addiu      $a1, 0x34
  12:
    addiu      $v0, -0x1
    addiu     $a0, 0x28
    bnez       $v0, 6b
  13:
    lui        $a3, %hi(0x1F8003D0)
    lw         $ra, %lo(0x1F8003C4)($a3)
    lw         $s0, %lo(0x1F8003C8)($a3)
    lw         $s1, %lo(0x1F8003CC)($a3)
    lw         $s2, %lo(0x1F8003D0)($a3)
    jr         $ra
endlabel func_80097388

nonmatching func_8009797C, 0x94

glabel func_8009797C
    lw         $s0, 0x0($a0)
    lw         $s4, 0x4($a0)
    lw         $s5, 0x8($a0)
    sll        $t9, $s0, 16
    sra        $t9, 16
    sra        $t8, $s0, 16
    sll        $s1, $s4, 16
    sra        $s1, 16
    sll        $t7, $s4, 8
    sra        $t7, 24
    sllv       $t7, $t7, $gp
    addu       $t7, $t9
    sra        $at, $s4, 24
    sllv       $at, $at, $gp
    addu       $at, $t8
    and        $t7, 0xFFFF
    sll        $at, 16
    or         $s2, $at, $t7
    sll        $s3, $s5, 24
    sra        $s3, 24
    sllv       $s3, $s3, $gp
    addu       $s3, $s1
    sll        $t7, $s5, 16
    sra        $t7, 24
    sllv       $t7, $t7, $gp
    addu       $t7, $t9
    sll        $at, $s5, 8
    sra        $at, 24
    sllv       $at, $at, $gp
    addu       $at, $t8
    and        $t7, 0xFFFF
    sll        $at, 16
    or         $s4, $at, $t7
    sra        $s5, 24
    sllv       $s5, $s5, $gp
    addu      $s5, $s1
    jr         $ra
endlabel func_8009797C

nonmatching func_80097A10, 0xDC

glabel func_80097A10
    mtv3       $s0, $s1, $s2, $s3, $s4, $s5
    lw         $s0, 0x0($a3)
    lw         $s4, 0x4($a3)
    rtpt
    lw         $s5, 0x8($a3)
    sll        $t9, $s0, 16
    sra        $t9, 16
    sra        $t8, $s0, 16
    sll        $s1, $s4, 16
    sra        $s1, 16
    sll        $t7, $s4, 8
    sra        $t7, 24
    sllv       $t7, $t7, $gp
    addu       $t7, $t9
    sra        $at, $s4, 24
    sllv       $at, $at, $gp
    addu       $at, $t8
    and        $t7, 0xFFFF
    sll        $at, 16
    or         $s2, $at, $t7
    sll        $s3, $s5, 24
    sra        $s3, 24
    sllv       $s3, $s3, $gp
    addu       $s3, $s1
    sll        $t7, $s5, 16
    sra        $t7, 24
    sllv       $t7, $t7, $gp
    nclip
    addu       $t7, $t9
    sll        $at, $s5, 8
    sra        $at, 24
    sllv       $at, $at, $gp
    addu       $at, $t8
    and        $t7, 0xFFFF
    sll        $at, 16
    or         $s4, $at, $t7
    mfc2       $t9, $17
    mfc2       $t8, $18
    mfc2       $t7, $19
    slt        $at, $t8, $t9
    sra       $s5, 24
    bnez       $at, 0f
    or         $t9, $zero, $t8
  0:
    slt        $at, $t7, $t9
    sllv      $s5, $s5, $gp
    bnez       $at, 1f
    or         $t9, $zero, $t7
  1:
    mfc2       $at, $24
    addu      $s5, $s1
    jr         $ra
endlabel func_80097A10

nonmatching func_80097AEC, 0x204

glabel func_80097AEC
    addiu      $fp, -0x2C
    sw         $ra, 0x0($fp)
    sw         $t0, 0x4($fp)
    sw         $t1, 0x8($fp)
    sw         $t2, 0xC($fp)
    sw         $t3, 0x10($fp)
    sw         $t4, 0x14($fp)
    sw         $t5, 0x18($fp)
    sw         $t6, 0x1C($fp)
    sw         $t7, 0x20($fp)
    sw         $t9, 0x28($fp)
    lw         $t9, 0x2C($fp)
    lw         $t0, 0x30($fp)
    lw         $t1, 0x34($fp)
    lw         $t2, 0x38($fp)
    addu       $s0, $t0, $zero
    addu      $s1, $t1, $zero
    bnez       $t9, 2f
    addu       $s2, $t2, $zero
    lw         $t0, 0xC($s0)
    lw         $t1, 0xC($s1)
    lw         $t2, 0xC($s2)
.set noreorder
    jal        func_80098014
     addu      $t3, $t2, $zero
    beqz       $at, 3f
     lh        $t9, 0x10($s0)
.set reorder
    lh         $t4, 0x10($s1)
    lh         $t5, 0x10($s2)
    sw         $t0, 0x8($a1)
    slt        $at, $t4, $t9
    sw        $t1, 0x14($a1)
    bnez       $at, 0f
    or         $t9, $zero, $t4
  0:
    slt        $at, $t5, $t9
    sw        $t2, 0x20($a1)
    bnez       $at, 1f
    or         $t9, $zero, $t5
  1:
    li        $v1, 0x9000000
    jal        func_800980F8
    lui       $v1, %hi(0x1F8003B8)
    beqz       $at, 3f
    lhu        $t0, 0x6($s0)
    lw         $t3, %lo(0x1F8003C0)($v1)
    lhu        $t1, 0x6($s1)
    lw         $t4, %lo(0x1F8003BC)($v1)
    lhu        $t2, 0x6($s2)
    or         $t0, $t3
    or         $t1, $t4
    sw         $t0, 0xC($a1)
    sw         $t1, 0x18($a1)
    sw         $t2, 0x24($a1)
    lw         $t3, %lo(0x1F8003B8)($v1)
    li         $t4, 0xF7000000
    li         $t5, 0xFFFFFF
    lw         $t0, 0x8($s0)
    lw         $t1, 0x8($s1)
    lw         $t2, 0x8($s2)
    and        $t3, $t4
    and        $t0, $t5
    or         $t0, $t3
    sw         $t0, 0x4($a1)
    sw         $t1, 0x10($a1)
    sw         $t2, 0x1C($a1)
    addiu     $a1, 0x28
    b          3f
  2:
    addiu      $fp, -0x4C
    addiu      $t4, $fp, 0x10
    addiu      $t5, $fp, 0x24
    addiu      $t6, $fp, 0x38
    addu      $s2, $t4, $zero
    jal        func_80097F70
    lwc2       $0, 0x0($t4)
    lwc2       $1, 0x4($t4)
    addu       $s0, $t2, $zero
    addu      $s2, $t5, $zero
    jal        func_80097F70
    lwc2       $2, 0x0($t5)
    lwc2       $3, 0x4($t5)
    addu       $s1, $t0, $zero
    addu      $s2, $t6, $zero
    jal        func_80097F70
    lwc2       $4, 0x0($t6)
    lwc2       $5, 0x4($t6)
    addiu      $t9, -0x1
    sw         $t9, 0x0($fp)
    rtpt
    sw         $t0, 0x4($fp)
    sw         $t4, 0x8($fp)
    swc2       $12, 0xC($t4)
    swc2       $13, 0xC($t5)
    swc2       $14, 0xC($t6)
    swc2       $17, 0x10($t4)
    swc2       $18, 0x10($t5)
    swc2       $19, 0x10($t6)
    sw        $t6, 0xC($fp)
    jal        func_80097AEC
    sw         $t5, 0x4($fp)
    sw        $t1, 0xC($fp)
    jal        func_80097AEC
    sw         $t2, 0x8($fp)
    sw        $t6, 0xC($fp)
    jal        func_80097AEC
    sw         $t4, 0x4($fp)
    sw        $t5, 0x8($fp)
    jal        func_80097AEC
    sw         $zero, 0x0($fp)
    sw         $t2, 0x4($fp)
    sw        $t0, 0x8($fp)
    jal        func_80097AEC
    sw         $t5, 0x8($fp)
    sw        $t1, 0xC($fp)
    jal        func_80097AEC
    sw         $t4, 0x4($fp)
    sw        $t0, 0x8($fp)
    jal        func_80097AEC
    addiu      $fp, 0x4C
  3:
    lw         $ra, 0x0($fp)
    lw         $t0, 0x4($fp)
    lw         $t1, 0x8($fp)
    lw         $t2, 0xC($fp)
    lw         $t3, 0x10($fp)
    lw         $t4, 0x14($fp)
    lw         $t5, 0x18($fp)
    lw         $t6, 0x1C($fp)
    lw         $t7, 0x20($fp)
    lw         $t9, 0x28($fp)
    addiu     $fp, 0x2C
    jr         $ra
endlabel func_80097AEC

nonmatching func_80097CF0, 0x280

glabel func_80097CF0
    addiu      $fp, -0x2C
    sw         $ra, 0x0($fp)
    sw         $t0, 0x4($fp)
    sw         $t1, 0x8($fp)
    sw         $t2, 0xC($fp)
    sw         $t3, 0x10($fp)
    sw         $t4, 0x14($fp)
    sw         $t5, 0x18($fp)
    sw         $t6, 0x1C($fp)
    sw         $t7, 0x20($fp)
    sw         $t8, 0x24($fp)
    sw         $t9, 0x28($fp)
    lw         $t9, 0x2C($fp)
    lw         $t0, 0x30($fp)
    lw         $t1, 0x34($fp)
    lw         $t2, 0x38($fp)
    lw         $t3, 0x3C($fp)
    addu       $s0, $t0, $zero
    addu      $s1, $t1, $zero
    bnez       $t9, 3f
    addu       $s2, $t2, $zero
    addu       $s3, $t3, $zero
    lw         $t0, 0xC($s0)
    lw         $t1, 0xC($s1)
    lw         $t2, 0xC($s2)
.set noreorder
    jal        func_80098014
     lw        $t3, 0xC($s3)
    beqz       $at, 4f
     lh        $t9, 0x10($s0)
.set reorder
    lh         $t4, 0x10($s1)
    lh         $t5, 0x10($s2)
    lh         $t6, 0x10($s3)
    sw         $t0, 0x8($a1)
    slt        $at, $t4, $t9
    sw        $t1, 0x14($a1)
    bnez       $at, 0f
    or         $t9, $zero, $t4
  0:
    slt        $at, $t5, $t9
    sw        $t2, 0x20($a1)
    bnez       $at, 1f
    or         $t9, $zero, $t5
  1:
    slt        $at, $t6, $t9
    sw        $t3, 0x2C($a1)
    bnez       $at, 2f
    or         $t9, $zero, $t6
  2:
    li        $v1, 0xC000000
    jal        func_800980F8
    lui       $v1, %hi(0x1F8003B8)
    beqz       $at, 4f
    lw         $t4, %lo(0x1F8003C0)($v1)
    lw         $t5, %lo(0x1F8003BC)($v1)
    lhu        $t0, 0x6($s0)
    lhu        $t1, 0x6($s1)
    lhu        $t2, 0x6($s2)
    lhu        $t3, 0x6($s3)
    or         $t0, $t4
    or         $t1, $t5
    sw         $t0, 0xC($a1)
    sw         $t1, 0x18($a1)
    sw         $t2, 0x24($a1)
    sw         $t3, 0x30($a1)
    lw         $t4, %lo(0x1F8003B8)($v1)
    li         $t5, 0xFFFFFF
    lw         $t0, 0x8($s0)
    lw         $t1, 0x8($s1)
    lw         $t2, 0x8($s2)
    lw         $t3, 0x8($s3)
    and        $t0, $t5
    or         $t0, $t4
    sw         $t0, 0x4($a1)
    sw         $t1, 0x10($a1)
    sw         $t2, 0x1C($a1)
    sw         $t3, 0x28($a1)
    addiu     $a1, 0x34
    b          4f
  3:
    addiu      $fp, -0x78
    addiu      $t4, $fp, 0x14
    addiu      $t5, $fp, 0x28
    addiu      $t6, $fp, 0x3C
    addiu      $t7, $fp, 0x50
    addiu      $t8, $fp, 0x64
    addu      $s2, $t4, $zero
    jal        func_80097F70
    lwc2       $0, 0x0($t4)
    lwc2       $1, 0x4($t4)
    addu       $s0, $t2, $zero
    addu      $s2, $t8, $zero
    jal        func_80097F70
    lwc2       $2, 0x0($t8)
    lwc2       $3, 0x4($t8)
    addu       $s0, $t3, $zero
    addu      $s2, $t5, $zero
    jal        func_80097F70
    lwc2       $4, 0x0($t5)
    lwc2       $5, 0x4($t5)
    addiu      $t9, -0x1
    addu       $s1, $t2, $zero
    rtpt
    addu      $s2, $t6, $zero
    jal        func_80097F70
    lwc2       $0, 0x0($t6)
    lwc2       $1, 0x4($t6)
    swc2       $12, 0xC($t4)
    swc2       $13, 0xC($t8)
    swc2       $14, 0xC($t5)
    swc2       $17, 0x10($t4)
    swc2       $18, 0x10($t8)
    swc2       $19, 0x10($t5)
    addu       $s0, $t0, $zero
    addu      $s2, $t7, $zero
    jal        func_80097F70
    lwc2       $2, 0x0($t7)
    lwc2       $3, 0x4($t7)
    sw         $t9, 0x0($fp)
    sw         $t0, 0x4($fp)
    rtpt
    sw         $t4, 0x8($fp)
    sw         $t7, 0xC($fp)
    swc2       $12, 0xC($t6)
    swc2       $13, 0xC($t7)
    swc2       $17, 0x10($t6)
    swc2       $18, 0x10($t7)
    sw        $t8, 0x10($fp)
    jal        func_80097CF0
    sw         $t1, 0x4($fp)
    sw        $t5, 0xC($fp)
    jal        func_80097CF0
    sw         $t3, 0x4($fp)
    sw        $t6, 0x8($fp)
    jal        func_80097CF0
    sw         $t2, 0x4($fp)
    sw        $t7, 0xC($fp)
    jal        func_80097CF0
    sw         $zero, 0x0($fp)
    sw        $t3, 0xC($fp)
    jal        func_80097AEC
    sw         $t0, 0x8($fp)
    sw        $t7, 0xC($fp)
    jal        func_80097AEC
    sw         $t4, 0x4($fp)
    sw        $t1, 0xC($fp)
    jal        func_80097AEC
    sw         $t3, 0x4($fp)
    sw        $t5, 0x8($fp)
    jal        func_80097AEC
    addiu      $fp, 0x78
  4:
    lw         $ra, 0x0($fp)
    lw         $t0, 0x4($fp)
    lw         $t1, 0x8($fp)
    lw         $t2, 0xC($fp)
    lw         $t3, 0x10($fp)
    lw         $t4, 0x14($fp)
    lw         $t5, 0x18($fp)
    lw         $t6, 0x1C($fp)
    lw         $t7, 0x20($fp)
    lw         $t8, 0x24($fp)
    lw         $t9, 0x28($fp)
    addiu     $fp, 0x2C
    jr         $ra
endlabel func_80097CF0

nonmatching func_80097F70, 0xA4

glabel func_80097F70
    lbu        $s3, 0x8($s0)
    lbu        $s4, 0x8($s1)
    lbu        $s5, 0x9($s0)
    lbu        $at, 0x9($s1)
    addu       $s3, $s4
    srl        $s3, 1
    sb         $s3, 0x8($s2)
    lbu        $s3, 0xA($s0)
    lbu        $s4, 0xA($s1)
    addu       $s5, $at
    srl        $s5, 1
    sb         $s5, 0x9($s2)
    addu       $s3, $s4
    srl        $s3, 1
    sb         $s3, 0xA($s2)
    lh         $s3, 0x0($s0)
    lh         $s4, 0x0($s1)
    lh         $s5, 0x2($s0)
    lh         $at, 0x2($s1)
    addu       $s3, $s4
    sra        $s3, 1
    addu       $s5, $at
    sra        $s5, 1
    sh         $s3, 0x0($s2)
    sh         $s5, 0x2($s2)
    lh         $s3, 0x4($s0)
    lh         $s4, 0x4($s1)
    lbu        $s5, 0x6($s0)
    lbu        $at, 0x6($s1)
    addu       $s3, $s4
    sra        $s3, 1
    lbu        $s4, 0x7($s0)
    addu       $s5, $at
    lbu        $at, 0x7($s1)
    sra        $s5, 1
    sh         $s3, 0x4($s2)
    sb         $s5, 0x6($s2)
    addu       $s4, $at
    sra        $s4, 1
    sb        $s4, 0x7($s2)
    jr         $ra
endlabel func_80097F70

nonmatching func_80098014, 0xE4

glabel func_80098014
    sra        $t4, $t0, 16
    sra        $t5, $t1, 16
    sra        $t6, $t2, 16
    sra        $t7, $t3, 16
    slt        $at, $t4, 0xE0
.set noreorder
    bnez       $at, 0f
     slt       $at, $t5, 0xE0
    bnez       $at, 0f
     slt       $at, $t6, 0xE0
    bnez       $at, 0f
     slt       $at, $t7, 0xE0
.set reorder
    bnez       $at, 0f
.set noreorder
    b          4f
.set reorder
  0:
     slt       $at, $t4, 0x0
.set noreorder
    beqz       $at, 1f
     slt       $at, $t5, 0x0
    beqz       $at, 1f
     slt       $at, $t6, 0x0
    beqz       $at, 1f
     slt       $at, $t7, 0x0
.set reorder
    beqz       $at, 1f
.set noreorder
    b          4f
.set reorder
  1:
     sll       $t4, $t0, 16
    sll        $t5, $t1, 16
    sll        $t6, $t2, 16
    sll        $t7, $t3, 16
    sra        $t4, 16
    sra        $t5, 16
    sra        $t6, 16
    sra        $t7, 16
    slt        $at, $t4, 0x0
.set noreorder
    beqz       $at, 2f
     slt       $at, $t5, 0x0
    beqz       $at, 2f
     slt       $at, $t6, 0x0
    beqz       $at, 2f
     slt       $at, $t7, 0x0
.set reorder
    beqz       $at, 2f
.set noreorder
    b          4f
.set reorder
  2:
     slt       $at, $t4, 0x140
.set noreorder
    bnez       $at, 3f
     slt       $at, $t5, 0x140
    bnez       $at, 3f
     slt       $at, $t6, 0x140
    bnez       $at, 3f
     slt       $at, $t7, 0x140
.set reorder
    bnez       $at, 3f
    b          4f
  3:
    or        $at, $zero, 0x1
    jr         $ra
  4:
    or        $at, $zero, $zero
    jr         $ra
endlabel func_80098014

nonmatching func_800980F8, 0x68

glabel func_800980F8
    srl        $t9, 2
    slt        $at, $t9, 0x8
.set noreorder
    bnez       $at, 0f
     sra       $at, $gp, 16
.set reorder
    addu       $t9, $at
    slt        $at, $t9, 0x7FF
.set noreorder
    beqz       $at, 0f
.set reorder
     slt       $at, $t9, 0x8
    sll       $t6, $t9, 2
    bnez       $at, 0f
    lui        $t4, (0xFFFFFF >> 16)
    addu       $t6, $a2
    lw         $t7, 0x0($t6)
    or         $t4, (0xFFFFFF & 0xFFFF)
    li         $t5, 0xFF000000
    and        $at, $t7, $t4
    or         $at, $v1
    sw         $at, 0x0($a1)
    and        $at, $a1, $t4
    and        $t7, $t5
    or         $t7, $at
    sw         $t7, 0x0($t6)
    or        $at, $zero, 0x1
    jr         $ra
  0:
    or        $at, $zero, $zero
    jr         $ra
endlabel func_800980F8

nonmatching func_80098160, 0x1C

glabel func_80098160
    la         $v0, func_800980F8
    nop
    sh         $a0, 0x4($v0)
.set noreorder
    sh         $a0, 0x1C($v0)
.set reorder
    jr         $ra
endlabel func_80098160

nonmatching func_8009817C, 0x18

glabel func_8009817C
    la         $v0, func_800980F8
    nop
.set noreorder
    sh         $a0, 0x14($v0)
.set reorder
    jr         $ra
endlabel func_8009817C

nonmatching func_80098194, 0x24

glabel func_80098194
    la         $v0, D_80097590
    la         $v1, D_800978F8
    nop
    sh         $a0, 0x0($v0)
.set noreorder
    sh         $a0, 0x0($v1)
.set reorder
    jr         $ra
endlabel func_80098194

nonmatching func_800981B8, 0x54

glabel func_800981B8
    la         $v0, func_80098014
    nop
    sh         $a3, 0x10($v0)
    sh         $a3, 0x18($v0)
    sh         $a3, 0x20($v0)
    sh         $a3, 0x28($v0)
    sh         $a1, 0x38($v0)
    sh         $a1, 0x40($v0)
    sh         $a1, 0x48($v0)
    sh         $a1, 0x50($v0)
    sh         $a0, 0x80($v0)
    sh         $a0, 0x88($v0)
    sh         $a0, 0x90($v0)
    sh         $a0, 0x98($v0)
    sh         $a2, 0xA8($v0)
    sh         $a2, 0xB0($v0)
    sh         $a2, 0xB8($v0)
.set noreorder
    sh         $a2, 0xC0($v0)
.set reorder
    jr         $ra
endlabel func_800981B8

nonmatching func_8009820C, 0x1EC

glabel func_8009820C
    lui        $a3, %hi(0x1F800100)
    or         $t1, $a3, (0x1F800100 & 0xFFFF)
    lw         $a1, %lo(0x1F800004)($a3)
    lw         $a2, %lo(0x1F800000)($a3)
    addiu      $a1, 0x1FFC
    or         $t0, $zero, 0x22
  0:
    lwc2       $0, 0x0($a0)
    lwc2       $1, 0x4($a0)
    lw         $t9, 0x8($a0)
    addiu      $t0, -0x1
    rtv0tr
    sw         $t9, 0xC($t1)
    swc2       $25, 0x0($t1)
    swc2       $26, 0x4($t1)
    swc2       $27, 0x8($t1)
    addiu      $a0, 0xC
    addiu     $t1, 0x10
    bgtz       $t0, 0b
    or         $t1, $a3, (0x1F800100 & 0xFFFF)
    or         $t0, $zero, 0x40
    lw         $a3, 0x0($a1)
  1:
    lw         $t2, 0x0($a0)
    srl        $t4, $t2, 8
    srl        $t5, $t2, 16
    and        $t3, $t2, 0xFF
    and        $t4, 0xFF
    and        $t5, 0xFF
    sll        $t3, 4
    sll        $t4, 4
    sll        $t5, 4
    addu       $t3, $t1
    addu       $t4, $t1
    addu       $t5, $t1
    lw         $t6, 0x8($t3)
    lw         $t7, 0x8($t4)
.set noreorder
    bgtz       $t6, 2f
     lw        $t8, 0x8($t5)
.set reorder
    bgtz       $t7, 2f
    blez       $t8, 7f
  2:
    lw         $t6, 0x0($t3)
    lw         $t7, 0x0($t4)
    lw         $t8, 0x0($t5)
    lw         $t9, 0x4($t3)
    lw         $v0, 0x4($t4)
    lw         $v1, 0x4($t5)
    addiu      $t6, 0xA0
    addiu      $t7, 0xA0
    addiu      $t8, 0xA0
    addiu      $t9, 0x78
    addiu      $v0, 0x78
    addiu      $v1, 0x78
    slt        $at, $t6, 0x0
.set noreorder
    beqz       $at, 3f
     slt       $at, $t7, 0x0
    beqz       $at, 3f
     slt       $at, $t8, 0x0
.set reorder
    beqz       $at, 3f
.set noreorder
    b          7f
.set reorder
  3:
     slt       $at, $t6, 0x140
.set noreorder
    bnez       $at, 4f
     slt       $at, $t7, 0x140
    bnez       $at, 4f
     slt       $at, $t8, 0x140
.set reorder
    bnez       $at, 4f
    b          7f
  4:
    slt        $at, $t9, 0x0
.set noreorder
    beqz       $at, 5f
     slt       $at, $v0, 0x0
    beqz       $at, 5f
     slt       $at, $v1, 0x0
.set reorder
    beqz       $at, 5f
.set noreorder
    b          7f
.set reorder
  5:
     slt       $at, $t9, 0xE0
.set noreorder
    bnez       $at, 6f
     slt       $at, $v0, 0xE0
    bnez       $at, 6f
     slt       $at, $v1, 0xE0
.set reorder
    bnez       $at, 6f
.set noreorder
    b          7f
.set reorder
  6:
     and       $t6, 0xFFFF
    and        $t7, 0xFFFF
    and        $t8, 0xFFFF
    sll        $t9, 16
    sll        $v0, 16
    sll        $v1, 16
    or         $t6, $t9
    or         $t7, $v0
    or         $t8, $v1
    sw         $t6, 0x8($a2)
    sw         $t7, 0x10($a2)
    sw         $t8, 0x18($a2)
    lw         $t6, 0xC($t3)
    lw         $t7, 0xC($t4)
    li         $t9, 0x6000000
    lw         $t8, 0xC($t5)
    lui        $v0, (0xFFFFFF >> 16)
    sw         $t6, 0x4($a2)
    or         $v0, (0xFFFFFF & 0xFFFF)
    sw         $t7, 0xC($a2)
    li         $v1, 0xFF000000
    sw         $t8, 0x14($a2)
    and        $t3, $a3, $v0
    or         $t3, $t9
    sw         $t3, 0x0($a2)
    and        $t4, $a2, $v0
    and        $t3, $a3, $v1
    or         $a3, $t3, $t4
    addiu      $a2, 0x1C
  7:
    addiu      $t0, -0x1
    addiu     $a0, 0x4
    bgtz       $t0, 1b
    sw         $a3, 0x0($a1)
    li         $a3, 0x1F800000
    sw        $a2, %lo(0x1F800000)($a3)
    jr         $ra
endlabel func_8009820C

nonmatching func_800983F8, 0x1B4

glabel func_800983F8
    lui        $at, %hi(0x1F800030)
    sw         $ra, %lo(0x1F8003E0)($at)
    sw         $s0, %lo(0x1F8003E4)($at)
    sw         $s1, %lo(0x1F8003E8)($at)
    sw         $s2, %lo(0x1F8003EC)($at)
    sw         $s3, %lo(0x1F800390)($at)
    sw         $s4, %lo(0x1F800394)($at)
    addu       $v1, $a0, $zero
    lw         $s0, %lo(0x1F80005C)($at)
    lw         $s1, %lo(0x1F800064)($at)
    addu       $s2, $at, $zero
    addu      $a0, $s0, $zero
    jal        func_80098AB8
    mult       $v0, $s1
    addu      $a0, $s0, $zero
    jal        func_80098AB4
    addu       $a0, $v1, $zero
    mflo       $s3
    sw         $zero, 0x3D0($at)
    sw         $zero, 0x3D4($at)
    mult       $v0, $s1
    sw         $zero, 0x3D8($at)
    sw         $zero, 0x3DC($at)
    lw         $s1, 0x0($a0)
    addiu      $s0, $a0, 0x4
    mflo       $s4
    sra        $s3, 12
    sra        $s4, 12
  0:
    lw         $t0, 0x0($s0)
    and        $at, $t0, 0x100
.set noreorder
    bnez       $at, 2f
     and       $at, $t0, 0x400
.set reorder
    bnez       $at, 1f
    addiu      $a0, $s0, 0x4
    addiu      $a1, $s0, 0x10
    addiu     $a2, $s0, 0x20
    jal        func_800985AC
    b          2f
  1:
    addiu      $a0, $s2, %lo(D_1F8003D0)
    addiu      $a1, $s2, %lo(D_1F8003D0)
.set noreorder
    jal        func_800985AC
     addiu     $a2, $s2, %lo(D_1F8003AC)
.set reorder
    nop
    lw         $t0, %lo(0x1F8003AC)($s2)
    lw         $t1, %lo(0x1F8003B0)($s2)
    lw         $t2, %lo(0x1F8003B4)($s2)
    lw         $t3, %lo(0x1F8003B8)($s2)
    ctc2       $t0, $0
    lw         $t4, %lo(0x1F8003BC)($s2)
    ctc2       $t1, $1
    lw         $t5, %lo(0x1F8003C0)($s2)
    ctc2       $t2, $2
    lw         $t6, %lo(0x1F8003C4)($s2)
    ctc2       $t3, $3
    lw         $t7, %lo(0x1F8003C8)($s2)
    ctc2       $t4, $4
    ctc2       $t5, $5
    ctc2       $t6, $6
    ctc2       $t7, $7
    lw         $t0, 0x4($s0)
    lw         $t1, 0x8($s0)
    lw         $t2, 0xC($s0)
    and        $t0, 0xFFFF
    sll        $t1, 16
    or         $t0, $t1
    mtv0       $t0, $t2
    lw         $t0, %lo(0x1F800064)($s2)
    rtv0tr
    nop
    negu       $t1, $s3
    sh         $s4, 0x20($s0)
    sh         $t1, 0x22($s0)
    sh         $s3, 0x26($s0)
    sh         $s4, 0x28($s0)
    sh         $t0, 0x30($s0)
    swc2       $25, 0x34($s0)
    swc2       $26, 0x38($s0)
    swc2       $27, 0x3C($s0)
    lw         $t0, %lo(0x1F800014)($s2)
    lw         $t1, %lo(0x1F800018)($s2)
    lw         $t2, %lo(0x1F80001C)($s2)
    lw         $t3, %lo(0x1F800020)($s2)
    ctc2       $t0, $0
    lw         $t4, %lo(0x1F800024)($s2)
    ctc2       $t1, $1
    lw         $t5, %lo(0x1F800028)($s2)
    ctc2       $t2, $2
    lw         $t6, %lo(0x1F80002C)($s2)
    ctc2       $t3, $3
    lw         $t7, %lo(0x1F800030)($s2)
    ctc2       $t4, $4
    ctc2       $t5, $5
    ctc2       $t6, $6
    ctc2       $t7, $7
  2:
    addiu      $s1, -0x1
    addiu     $s0, 0x40
    bnez       $s1, 0b
    lui        $at, %hi(0x1F8003EC)
    lw         $ra, %lo(0x1F8003E0)($at)
    lw         $s0, %lo(0x1F8003E4)($at)
    lw         $s1, %lo(0x1F8003E8)($at)
    lw         $s3, %lo(0x1F800398)($at)
    lw         $s4, %lo(0x1F80039C)($at)
.set noreorder
    jr         $ra
     lw        $s2, %lo(0x1F8003EC)($at)
.set reorder
endlabel func_800983F8

nonmatching func_800985AC, 0x9C

glabel func_800985AC
    lui        $a3, %hi(0x1F8003FC)
    sw         $ra, %lo(0x1F8003F0)($a3)
    sw         $s0, %lo(0x1F8003F4)($a3)
    sw         $s1, %lo(0x1F8003F8)($a3)
    sw         $s2, %lo(0x1F8003FC)($a3)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    addu       $s2, $a2, $zero
    lw         $t0, 0x0($s1)
    lw         $t1, 0x4($s1)
    lw         $t8, 0x8($s1)
    and        $t0, 0xFFFF
    sll        $t1, 16
    or         $v0, $t0, $t1
    addu      $a1, $s2, $zero
    jal        func_8009874C
    li         $a0, 0x1F800014
    addu      $a1, $s2, $zero
    jal        func_800989B8
    lw         $t0, 0x0($s0)
    lw         $t1, 0x4($s0)
    lw         $t2, 0x8($s0)
    and        $t0, 0xFFFF
    sll        $t1, 16
    or         $t0, $t1
    mtv0       $t0, $t2
    addiu      $t1, $s2, 0x14
    rtv0tr
    lui        $a3, %hi(0x1F8003FC)
    lw         $ra, %lo(0x1F8003F0)($a3)
    lw         $s0, %lo(0x1F8003F4)($a3)
    lw         $s1, %lo(0x1F8003F8)($a3)
    swc2       $25, 0x0($t1)
    swc2       $26, 0x4($t1)
    swc2       $27, 0x8($t1)
.set noreorder
    jr         $ra
     lw        $s2, %lo(0x1F8003FC)($a3)
.set reorder
endlabel func_800985AC

nonmatching func_80098648, 0x104

glabel func_80098648
    lui        $a3, %hi(0x1F8003C0)
    li         $t0, 0x1000000
    lw         $t1, %lo(0x1F800064)($a3)
    sw         $ra, %lo(0x1F8003F0)($a3)
    div        $zero, $t0, $t1
    sw         $s0, %lo(0x1F8003F4)($a3)
    sw         $s1, %lo(0x1F8003F8)($a3)
    sw         $s2, %lo(0x1F8003FC)($a3)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    addu       $s2, $a2, $zero
    lw         $t0, %lo(0x1F800014)($a3)
    lw         $t1, %lo(0x1F800018)($a3)
    lw         $t2, %lo(0x1F80001C)($a3)
    lw         $t3, %lo(0x1F800020)($a3)
    lw         $t4, %lo(0x1F800024)($a3)
    sw         $t0, %lo(0x1F8003D0)($a3)
    sw         $t1, %lo(0x1F8003D4)($a3)
    sw         $t2, %lo(0x1F8003D8)($a3)
    sw         $t3, %lo(0x1F8003DC)($a3)
    sw         $t4, %lo(0x1F8003E0)($a3)
    sw         $zero, %lo(0x1F8003B0)($a3)
    sw         $zero, %lo(0x1F8003B4)($a3)
    sw         $zero, %lo(0x1F8003B8)($a3)
    sw         $zero, %lo(0x1F8003BC)($a3)
    sw         $zero, %lo(0x1F8003C0)($a3)
    mflo       $t0
    sh         $t0, %lo(0x1F8003B0)($a3)
    sh         $t0, %lo(0x1F8003B8)($a3)
    sh         $t0, %lo(0x1F8003C0)($a3)
    lw         $t0, 0x0($s1)
    lw         $t1, 0x4($s1)
    lw         $t8, 0x8($s1)
    and        $t0, 0xFFFF
    sll        $t1, 16
    or         $v0, $t0, $t1
    addu      $a1, $s2, $zero
    jal        func_8009874C
    lui        $a3, %hi(D_1F8003B0)
    addiu      $a0, $a3, %lo(D_1F8003B0)
.set noreorder
    jal        func_800989B8
     addiu     $a1, $a3, %lo(D_1F8003D0)
.set reorder
    la         $a0, D_1F8003D0
    addu      $a1, $s2, $zero
    jal        func_800989B8
    lw         $t0, 0x0($s0)
    lw         $t1, 0x4($s0)
    lw         $t2, 0x8($s0)
    and        $t0, 0xFFFF
    sll        $t1, 16
    or         $t0, $t1
    mtv0       $t0, $t2
    addiu      $t1, $s2, 0x14
    rtv0tr
    lui        $a3, %hi(0x1F8003FC)
    lw         $ra, %lo(0x1F8003F0)($a3)
    lw         $s0, %lo(0x1F8003F4)($a3)
    lw         $s1, %lo(0x1F8003F8)($a3)
    swc2       $25, 0x0($t1)
    swc2       $26, 0x4($t1)
    swc2       $27, 0x8($t1)
.set noreorder
    jr         $ra
     lw        $s2, %lo(0x1F8003FC)($a3)
.set reorder
endlabel func_80098648

nonmatching func_8009874C, 0x170

glabel func_8009874C
    la         $a2, _trig_table
    la         $t7, func_800988BC
    addiu      $a3, $a2, 0x800
  alabel D_80098760
    srl        $t1, $t8, 4
    and        $t1, 0xE0
    addu       $t1, $t7
    la         $t9, D_80098760
    sll        $t8, 2
    and       $t8, 0x7FC
    jr         $t1
    sll        $t4, $t0, 1
    sll        $t5, $t1, 1
    srl        $t8, $v0, 14
    srl        $t1, $t8, 6
    and        $t1, 0xE0
    addu       $t1, $t7
    and       $t8, 0x7FC
    jr         $t1
    sll        $t2, $t0, 1
    sll        $t3, $t1, 1
    sll        $t8, $v0, 2
    srl        $t1, $t8, 6
    and        $t1, 0xE0
    addu       $t1, $t7
    and       $t8, 0x7FC
    jr         $t1
    ldir0123   $t4, $t2, $t3, $t1
    mult       $t1, $t2
    addu       $v0, $zero, $a1
    gpf12
    negu       $t8, $t0
    sll        $t8, 16
    mfc2       $a0, $9
    mfc2       $a1, $10
    mfc2       $t4, $11
    ldir0123   $t5, $t2, $t3, $t1
    sra        $t4, 1
    sll        $t4, 16
    gpf12
    mflo       $t7
    sra        $t7, 13
    and        $t7, 0xFFFF
    mult       $t1, $t3
    or         $t4, $t7
    sw         $t4, 0x4($v0)
    mfc2       $a2, $9
    mfc2       $a3, $10
    mfc2       $t5, $11
    ldir0123   $t0, $a0, $a2, $a1
    sra        $t5, 1
    and        $t5, 0xFFFF
    gpf12
    or         $t5, $t8
    sw         $t5, 0x8($v0)
    mflo       $t7
    sra        $t7, 13
    sh         $t7, 0x10($v0)
    mult       $t0, $a3
    mfc2       $t2, $9
    mfc2       $t3, $10
    mfc2       $t4, $11
    addu       $t2, $a3
    subu       $t3, $a1
    subu       $t4, $a2
    sra        $t2, 2
    and        $t2, 0xFFFF
    sra        $t3, 2
    sll        $t3, 16
    or         $t2, $t3
    sw         $t2, 0x0($v0)
    sra        $t4, 2
    and        $t4, 0xFFFF
    mflo       $t5
    sra        $t5, 12
    addu       $t5, $a0
    sra        $t5, 2
    sll        $t5, 16
    or         $t4, $t5
    sw        $t4, 0xC($v0)
    jr         $ra
endlabel func_8009874C

nonmatching func_800988BC, 0xFC

glabel func_800988BC
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    and       $t0, 0xFFFF
    jr         $t9
    nop
    nop
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    srl       $t0, 16
    jr         $t9
    nop
    nop
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    negu       $t1, $t1
    srl       $t0, 16
    jr         $t9
    nop
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    negu       $t1, $t1
    and       $t0, 0xFFFF
    jr         $t9
    nop
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    negu       $t1, $t1
    and        $t0, 0xFFFF
    negu      $t0, $t0
    jr         $t9
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    negu       $t1, $t1
    srl        $t0, 16
    negu      $t0, $t0
    jr         $t9
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    srl        $t0, 16
    negu      $t0, $t0
    jr         $t9
    nop
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
    negu      $t0, $t0
    jr         $t9
endlabel func_800988BC

nonmatching func_800989B8, 0xFC

glabel func_800989B8
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lw         $t1, 0x4($a1)
    lw         $t2, 0x8($a1)
    lw         $t4, 0x10($a1)
    li         $t9, 0xFFFF0000
    and        $t5, $t2, $t9
    and        $t6, $t1, 0xFFFF
    or         $t5, $t6
    mtv0       $t5, $t4
    sll        $t6, $t2, 16
    rtv0
    lw         $t0, 0x0($a1)
    lw         $t3, 0xC($a1)
    srl        $t5, $t0, 16
    or         $t5, $t6
    srl        $t6, $t3, 16
    mfc2       $a0, $9
    mfc2       $a2, $10
    mfc2       $a3, $11
    mtv0       $t5, $t6
    sll        $a2, 16
    rtv0
    and        $t7, $t1, $t9
    and        $t8, $t0, 0xFFFF
    or         $t7, $t8
    and        $a0, 0xFFFF
    sh         $a3, 0x10($a1)
    mfc2       $t0, $9
    mfc2       $t1, $10
    mfc2       $t2, $11
    mtv0       $t7, $t3
    and        $t1, 0xFFFF
    rtv0
    addu       $v0, $zero, $a1
    or         $t1, $a2
    sw         $t1, 0x8($a1)
    sll        $t0, 16
    sll        $t2, 16
    mfc2       $t3, $9
    mfc2       $t4, $10
    mfc2       $t5, $11
    and        $t3, 0xFFFF
    or         $t3, $t0
    sw         $t3, 0x0($a1)
    sll        $t4, 16
    or         $t4, $a0
    sw         $t4, 0x4($a1)
    and        $t5, 0xFFFF
    or         $t5, $t2
    sw        $t5, 0xC($a1)
    jr         $ra
endlabel func_800989B8

nonmatching func_80098AB4, 0x4

glabel func_80098AB4
    addiu      $a0, 0x400
endlabel func_80098AB4

nonmatching func_80098AB8, 0x64

glabel func_80098AB8
    la         $v0, _trig_table
    and        $t0, $a0, 0x400
    and       $t1, $a0, 0x3FF
    beqz       $t0, 1f
    addiu     $t2, $zero, 0x800
    bnez       $t1, 0f
    addiu     $v0, $zero, 0x1000
    j          3f
  0:
    subu       $a0, $t2, $a0
  1:
    and        $t1, $a0, 0x200
    and       $t2, $a0, 0x1FF
    beqz       $t1, 2f
    addiu      $t0, $zero, 0x200
    subu       $t2, $t0, $t2
    addiu      $v0, 0x2
  2:
    sll        $t2, 2
    addu       $v0, $t2
    lhu        $v0, 0x0($v0)
  3:
    and        $t0, $a0, 0x800
    beqz       $t0, 4f
    negu       $v0, $v0
  4:
    jr         $ra
endlabel func_80098AB8

nonmatching func_80098B1C, 0x1C

glabel func_80098B1C
    la         $t0, vs_battle_roomData
    lw         $t1, 0x98($t0)
    addiu      $t1, 0x14
    jr         $t1
endlabel func_80098B1C

nonmatching func_80098B38, 0x104

glabel func_80098B38
    lui        $at, %hi(0x1F800218)
    sw         $ra, %lo(0x1F800200)($at)
    sw         $s0, %lo(0x1F800204)($at)
    sw         $s1, %lo(0x1F800208)($at)
    sw         $s2, %lo(0x1F80020C)($at)
    sw         $s3, %lo(0x1F800210)($at)
    sw         $s4, %lo(0x1F800214)($at)
    sw         $s5, %lo(0x1F800218)($at)
    la         $s0, vs_battle_roomData
    addu       $s4, $a2, $zero
    lb         $t0, 0x0($s0)
    lui        $s5, (0x808080 >> 16)
    or        $s5, (0x808080 & 0xFFFF)
    beqz       $t0, 3f
    lw         $s1, 0x74($s0)
    sra        $s3, $a0, 16
    sll       $s2, $a0, 16
    beqz       $s1, 3f
    lw         $s5, 0x0($s1)
    lw         $s0, 0x4($s1)
    sra       $s2, 16
    beq        $zero, $a1, 0f
    lw         $t1, 0x8($s1)
    sll        $t0, $s0, 5
    addu       $s1, $t0
    addu       $s0, $t1, $zero
  0:
    addiu     $s1, 0xC
    beqz       $s0, 3f
  1:
    lw         $t0, 0x0($s1)
    lw         $t1, 0x4($s1)
    sll        $t2, $t0, 16
    sra        $t2, 16
    subu       $at, $s2, $t2
    sll       $t4, $t1, 16
    bltz       $at, 2f
    sra        $t4, 16
    subu       $at, $s2, $t4
    sra       $t3, $t0, 16
    bgtz       $at, 2f
    subu       $at, $s3, $t3
    sra       $t5, $t1, 16
    bltz       $at, 2f
    subu       $at, $s3, $t5
    bgtz       $at, 2f
    addu       $a2, $s1, $zero
    addu      $a1, $s4, $zero
    jal        func_80098C3C
.set noreorder
    bnez       $v0, 4f
.set reorder
  2:
     addiu     $s0, -0x1
    addiu     $s1, 0x20
    bnez       $s0, 1b
  3:
    sw         $s5, 0x0($s4)
    or         $v0, $zero, $zero
  4:
    lui        $at, %hi(0x1F800218)
    lw         $ra, %lo(0x1F800200)($at)
    lw         $s0, %lo(0x1F800204)($at)
    lw         $s1, %lo(0x1F800208)($at)
    lw         $s2, %lo(0x1F80020C)($at)
    lw         $s3, %lo(0x1F800210)($at)
    lw         $s4, %lo(0x1F800214)($at)
    lw         $s5, %lo(0x1F800218)($at)
    jr         $ra
endlabel func_80098B38

nonmatching func_80098C3C, 0x130

glabel func_80098C3C
    lw         $t4, 0x8($a2)
    lw         $t5, 0x10($a2)
    lw         $t6, 0xC($a2)
    ldsxy3     $t4, $t5, $t6
    nop
    nop
    nclip
    mfc2       $t0, $24
    blez       $t0, 3f
    ldsxy3     $a0, $t5, $t6
    nop
    nop
    nclip
    mfc2       $t1, $24
    bltz       $t1, 3f
    ldsxy3     $a0, $t6, $t4
    nop
    nop
    nclip
    mfc2       $t2, $24
    bltz       $t2, 3f
    subu       $t3, $t0, $t1
    subu       $t3, $t2
    bltz       $t3, 3f
    lw         $t4, 0x14($a2)
    lw         $t6, 0x18($a2)
    lw         $t5, 0x1C($a2)
    or         $v0, $zero, 0x2
  0:
    and        $t7, $t4, 0xFF
    multu      $t7, $t1
    srl        $t4, 8
    mflo       $t7
    nop
    and        $t8, $t5, 0xFF
    multu      $t8, $t2
    srl        $t5, 8
    mflo       $t8
    nop
    and        $t9, $t6, 0xFF
    multu      $t9, $t3
    srl        $t6, 8
    mflo       $t9
    addu       $at, $t7, $t8
    addu       $at, $t9
    divu       $zero, $at, $t0
    nop
    mflo       $at
.set noreorder
    nop
.set reorder
    bgez       $at, 1f
    or         $at, $zero, $zero
  1:
    sltiu      $t9, $at, 0x100
    bnez       $t9, 2f
    or         $at, $zero, 0xFF
  2:
    sb         $at, 0x0($a1)
    addiu      $a1, 0x1
.set noreorder
    bnez       $v0, 0b
.set reorder
     addiu     $v0, -0x1
    or        $v0, $zero, 0x1
    jr         $ra
  3:
    or        $v0, $zero, $zero
    jr         $ra
endlabel func_80098C3C

nonmatching func_80098D6C, 0xE4

glabel func_80098D6C
    addu      $v0, $ra, $zero
    beq        $a0, $a1, 1f
    addu       $v1, $a3, $zero
    lb         $t0, 0x0($a2)
    lb         $t1, 0x1($a2)
    lb         $t2, 0x2($a2)
    lh         $t8, 0x4($a2)
    and        $v1, 0x2
    sll        $v1, 2
    or         $t7, $zero, 0x100
    sll        $t0, 2
    sll        $t1, 2
    sll        $t2, 2
  0:
    lw         $t3, 0x0($a0)
    srl        $t3, 24
    addiu      $at, $t3, -0x9
.set noreorder
    beqz       $at, 2f
     addiu     $at, $t3, -0xC
.set reorder
    beqz       $at, 3f
  1:
    addu       $ra, $v0, $zero
    jr         $ra
  2:
    addiu     $t3, $a0, 0x4
    jal        func_80098E50
    sw         $t6, 0x4($a0)
    addiu     $t3, $a0, 0x10
    jal        func_80098E50
    sw         $t6, 0x10($a0)
    addiu     $t3, $a0, 0x1C
    jal        func_80098E50
    sw         $t6, 0x1C($a0)
    addiu      $a0, 0x28
    addu       $a0, $v1
    bne        $a0, $a1, 0b
    b          1b
  3:
    addiu     $t3, $a0, 0x4
    jal        func_80098E50
    sw         $t6, 0x4($a0)
    addiu     $t3, $a0, 0x10
    jal        func_80098E50
    sw         $t6, 0x10($a0)
    addiu     $t3, $a0, 0x1C
    jal        func_80098E50
    sw         $t6, 0x1C($a0)
    addiu     $t3, $a0, 0x28
    jal        func_80098E50
    sw         $t6, 0x28($a0)
    addiu      $a0, 0x34
    addu       $a0, $v1
    bne        $a0, $a1, 0b
    b          1b
endlabel func_80098D6C

nonmatching func_80098E50, 0xFC

glabel func_80098E50
    nop
    lw         $t6, 0x0($t3)
    srl        $t4, $t6, 8
    srl        $t5, $t6, 16
    and        $t3, $t6, 0xFF
    and        $t4, 0xFF
    and       $t5, 0xFF
    beqz       $t8, 0f
    sll        $at, $t3, 2
    addu       $t3, $at
    sll        $at, $t4, 3
    addu       $t4, $at
    sll        $t5, 1
    addu       $t3, $t4
    addu       $t3, $t5
    ctc2       $t3, $21
    ctc2       $t3, $22
.set noreorder
    ctc2       $t3, $23
    mtc2       $t6, $6
    mtc2       $t8, $8
.set reorder
    nop
    nop
    dpcs
    mfc2       $t6, $22
    srl        $t4, $t6, 8
    srl        $t5, $t6, 16
    and        $t3, $t6, 0xFF
    and        $t4, 0xFF
    and        $t5, 0xFF
  0:
    addu       $t3, $t0
    addu       $t4, $t1
    addu       $t5, $t2
.set noreorder
    srl        $t6, 24
.set reorder
    bgez       $t3, 1f
    or         $t3, $zero, $zero
  1:
    slt        $at, $t3, $t7
    bnez       $at, 2f
    addiu      $t3, $t7, -0x1
  2:
    bgez       $t4, 3f
    or         $t4, $zero, $zero
  3:
    slt        $at, $t4, $t7
    bnez       $at, 4f
    addiu      $t4, $t7, -0x1
  4:
    bgez       $t5, 5f
    or         $t5, $zero, $zero
  5:
    slt        $at, $t5, $t7
    bnez       $at, 6f
    addiu      $t5, $t7, -0x1
  6:
    sll        $t4, 8
    sll        $t5, 16
    sll        $t6, 24
    or         $t6, $t3
    or         $t6, $t4
    or        $t6, $t5
    jr         $ra
endlabel func_80098E50

nonmatching vs_battle_initSceneAndGetRoomNames, 0x40

glabel vs_battle_initSceneAndGetRoomNames
    lw         $v0, 0x0($a0)
    addiu      $a1, $a0, 0x4
    or         $v1, $zero, $v0
  0:
    addiu      $v0, -0x1
    addiu     $a1, 0xC
    bne        $zero, $v0, 0b
    addiu      $a2, $a0, 0x4
    or         $v0, $zero, $v1
  1:
    lw         $at, 0x4($a2)
    addiu      $v0, -0x1
    sw         $a1, 0x4($a2)
    addu       $a1, $at
    addiu     $a2, 0xC
    bne        $zero, $v0, 1b
    addu      $v0, $a1, $zero
    jr         $ra
endlabel vs_battle_initSceneAndGetRoomNames

nonmatching func_80098F8C, 0x548

glabel func_80098F8C
    lw         $v0, 0x0($a0)
    lui        $a3, %hi(0x1F8003E8)
    sw         $s0, %lo(0x1F8003F0)($a3)
    sw         $s1, %lo(0x1F8003F4)($a3)
    sw         $s2, %lo(0x1F8003F8)($a3)
    sw         $s3, %lo(0x1F8003FC)($a3)
    sw         $s4, %lo(0x1F8003EC)($a3)
    sw         $s5, %lo(0x1F8003E8)($a3)
    addiu      $a0, 0x4
    li         $a3, 0x1F800000
    li         $t6, 0xFFFFFF
    li         $t7, 0xFF000000
    lw         $t9, %lo(0x1F800004)($a3)
    lw         $t8, %lo(0x1F800000)($a3)
    or         $a1, $zero, $zero
    lw         $s4, 0x10($t9)
    lw         $v1, 0x14($t9)
    la         $t9, D_800F1CDC
    la         $s5, vs_main_stateFlags
    or         $s0, $zero, 0xFFFF
    or         $s1, $zero, $zero
    or         $s2, $zero, 0xFFFF
    or         $s3, $zero, $zero
    or         $at, $zero, 0x100
    ctc2       $zero, $5
    ctc2       $zero, $6
    ctc2       $at, $7
    lw         $t9, 0x0($t9)
  0:
    lw         $at, 0x0($a0)
    lw         $a2, 0x4($a0)
    addiu     $v0, -0x1
    beqz       $at, 18f
    lw         $t0, 0x0($a2)
    addiu      $a2, 0x4
    lui       $a3, %hi(0x1F800100)
    beqz       $t0, 18f
    or         $a3, (0x1F800100 & 0xFFFF)
    li         $t4, 0xFFFEFFFE
  1:
    lwc2       $0, 0x0($a2)
    lwc2       $1, 0x4($a2)
    lwc2       $2, 0x8($a2)
    lwc2       $3, 0xC($a2)
    lwc2       $4, 0x10($a2)
    lwc2       $5, 0x14($a2)
    addiu      $t0, -0x3
    addiu      $a2, 0x18
    rtpt
    swc2       $12, 0x0($a3)
    swc2       $13, 0x4($a3)
    swc2       $14, 0x8($a3)
    addiu     $a3, 0xC
    bgtz       $t0, 1b
    sll        $t0, 3
    addu       $a2, $t0
    li         $a3, 0x1F800100
    lw         $t0, 0x0($a2)
    addiu      $a2, 0x4
    li        $t1, 0x4000000
    beqz       $t0, 3f
    sll        $at, $t0, 2
    addu      $a2, $at
    bnez       $a1, 3f
    lui        $t2, %hi(0x223F7F00)
    subu       $a2, $at
    or         $t2, (0x223F7F00 & 0xFFFF)
  2:
    lw         $at, 0x0($a2)
    sw         $t2, 0x4($t8)
    sll        $t3, $at, 2
    srl        $t4, $at, 6
    srl        $t5, $at, 14
    and        $t3, 0x3FC
    and        $t4, 0x3FC
    and        $t5, 0x3FC
    addu       $t3, $a3
    addu       $t4, $a3
    addu       $t5, $a3
    lw         $t3, 0x0($t3)
    lw         $t4, 0x0($t4)
    lw         $t5, 0x0($t5)
    sw         $t3, 0x8($t8)
    sw         $t4, 0xC($t8)
    sw         $t5, 0x10($t8)
    and        $at, $v1, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $v1, $t7
    or         $v1, $at
    addiu      $t8, 0x14
    addiu      $t0, -0x1
    addiu     $a2, 0x4
    bnez       $t0, 2b
  3:
    lw         $t0, 0x0($a2)
    addiu      $a2, 0x4
    li        $t1, 0x5000000
    beqz       $t0, 5f
    sll        $at, $t0, 2
    addu      $a2, $at
    bnez       $a1, 5f
    lui        $t2, %hi(0x2A3F7F00)
    subu       $a2, $at
    or         $t2, (0x2A3F7F00 & 0xFFFF)
  4:
    lw         $at, 0x0($a2)
    sw         $t2, 0x4($t8)
    sll        $t3, $at, 2
    srl        $t4, $at, 6
    srl        $t5, $at, 14
    srl        $at, 22
    and        $t3, 0x3FC
    and        $t4, 0x3FC
    and        $t5, 0x3FC
    and        $at, 0x3FC
    addu       $t3, $a3
    addu       $t4, $a3
    addu       $t5, $a3
    addu       $at, $a3
    lw         $t3, 0x0($t3)
    lw         $t4, 0x0($t4)
    lw         $t5, 0x0($t5)
    lw         $at, 0x0($at)
    sw         $t3, 0x8($t8)
    sw         $t4, 0xC($t8)
    sw         $at, 0x10($t8)
    sw         $t5, 0x14($t8)
    and        $at, $v1, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $v1, $t7
    or         $v1, $at
    addiu      $t8, 0x18
    addiu      $t0, -0x1
    addiu     $a2, 0x4
    bnez       $t0, 4b
  5:
    lw         $t0, 0x0($a2)
    addiu      $a2, 0x4
    li        $t1, 0x3000000
    beqz       $t0, 7f
    li         $t2, 0x42FF7F00
  6:
    lw         $at, 0x0($a2)
    sw         $t2, 0x4($t8)
    sll        $t3, $at, 2
    srl        $t4, $at, 6
    and        $t3, 0x3FC
    and        $t4, 0x3FC
    addu       $t3, $a3
    addu       $t4, $a3
    lw         $t3, 0x0($t3)
    lw         $t4, 0x0($t4)
    sw         $t3, 0x8($t8)
    sw         $t4, 0xC($t8)
    and        $at, $v1, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $v1, $t7
    or         $v1, $at
    addiu      $t8, 0x10
    addiu      $t0, -0x1
    addiu     $a2, 0x4
    bnez       $t0, 6b
  7:
.set noreorder
    bnez       $a1, 18f
     lw        $t0, 0x0($a2)
.set reorder
    addiu      $a2, 0x4
    li        $t1, 0x3000000
    beqz       $t0, 9f
    li         $t2, 0x422F5F00
  8:
    lw         $at, 0x0($a2)
    sw         $t2, 0x4($t8)
    sll        $t3, $at, 2
    srl        $t4, $at, 6
    and        $t3, 0x3FC
    and        $t4, 0x3FC
    addu       $t3, $a3
    addu       $t4, $a3
    lw         $t3, 0x0($t3)
    lw         $t4, 0x0($t4)
    sw         $t3, 0x8($t8)
    sw         $t4, 0xC($t8)
    and        $at, $v1, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $v1, $t7
    or         $v1, $at
    addiu      $t8, 0x10
    addiu      $t0, -0x1
    addiu     $a2, 0x4
    bnez       $t0, 8b
  9:
    lw         $t0, 0x0($a2)
    addiu      $a2, 0x4
    li        $t1, 0x3000000
    beqz       $t0, 18f
  10:
    lw         $at, 0x0($a2)
    sll        $t3, $at, 2
    and        $t3, 0x3FC
    srl        $t2, $at, 16
    srl        $t5, $at, 24
    and        $t5, 0xFF
    beqz       $t5, 11f
    addiu      $t5, 0x33F
    addu       $t5, $s5
    lb         $at, 0x0($t5)
    nop
.set noreorder
    beqz       $at, 16f
.set reorder
  11:
     and       $t4, $t2, 0x10
    bnez       $t4, 13f
    and        $t4, $t2, 0x4
    bnez       $t4, 12f
    and        $t4, $t2, 0x1F
    beqz       $t4, 14f
    b          17f
  12:
    lui        $t2, %hi(0x60FF7F00)
    or        $t2, (0x60FF7F00 & 0xFFFF)
    b          15f
  13:
    and        $at, $t9, 0x20
    lui       $t2, %hi(0x607F00FF)
    beqz       $at, 17f
    or        $t2, (0x607F00FF & 0xFFFF)
    b          15f
  14:
    li         $t2, 0x607F7F7F
  15:
    addu       $t3, $a3
    lw         $t3, 0x0($t3)
    sw         $t2, 0x4($t8)
    and        $at, $s4, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $s4, $t7
    or         $s4, $at
    sra        $at, $t3, 16
    addiu      $at, -0x1
    sll        $at, 16
    and        $t4, $t3, 0xFFFF
    or         $at, $t4
    li         $t4, 0x30001
    sw         $at, 0x8($t8)
    sw         $t4, 0xC($t8)
    addiu      $t8, 0x10
    sw         $t2, 0x4($t8)
    and        $at, $s4, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $s4, $t7
    or         $s4, $at
    addiu      $at, $t3, -0x1
    and        $at, 0xFFFF
    sra        $t4, $t3, 16
    sll        $t4, 16
    or         $at, $t4
    li         $t4, 0x10003
    sw         $at, 0x8($t8)
    sw         $t4, 0xC($t8)
    addiu     $t8, 0x10
    b          17f
  16:
    addu       $t3, $a3
    lw         $t3, 0x0($t3)
    li         $t2, 0x74808080
    sw         $t2, 0x4($t8)
    and        $at, $s4, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $s4, $t7
    or         $s4, $at
    sra        $at, $t3, 16
    addiu      $at, -0x4
    sll        $at, 16
    and        $t4, $t3, 0xFFFF
    addiu      $t4, -0x3
    and        $t4, 0xFFFF
    or         $at, $t4
    li         $t4, 0x37F898D8
    sw         $at, 0x8($t8)
    sw         $t4, 0xC($t8)
    addiu      $t8, 0x10
  17:
    addiu      $t0, -0x1
    addiu     $a2, 0x4
    bnez       $t0, 10b
  18:
    addiu      $a1, 0x1
    addiu     $a0, 0xC
    bne        $zero, $v0, 0b
    li         $t1, 0x2000000
    li         $t2, 0xE100020C
    and        $at, $v1, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $v1, $t7
    or         $v1, $at
    sw         $t2, 0x4($t8)
    sw         $zero, 0x8($t8)
    addiu      $t8, 0x10
    li         $t1, 0x2000000
    li         $t2, 0xE100020C
    and        $at, $s4, $t6
    or         $at, $t1
    sw         $at, 0x0($t8)
    and        $at, $t8, $t6
    and        $s4, $t7
    or         $s4, $at
    sw         $t2, 0x4($t8)
    sw         $zero, 0x8($t8)
    addiu      $t8, 0x10
    li         $a3, 0x1F800000
    lw         $t9, %lo(0x1F800004)($a3)
    lw         $s0, %lo(0x1F8003F0)($a3)
    lw         $s1, %lo(0x1F8003F4)($a3)
    lw         $s2, %lo(0x1F8003F8)($a3)
    lw         $s3, %lo(0x1F8003FC)($a3)
    sw         $s4, 0x10($t9)
    sw         $v1, 0x14($t9)
    lw         $s4, %lo(0x1F8003EC)($a3)
    lw         $s5, %lo(0x1F8003E8)($a3)
.set noreorder
    sw         $t8, %lo(0x1F800000)($a3)
.set reorder
    jr         $ra
endlabel func_80098F8C

nonmatching vs_battle_getGeomOffset, 0x20

glabel vs_battle_getGeomOffset
    cfc2       $t0, $24
    cfc2       $t1, $25
    srl        $t0, 16
    srl        $t1, 16
    sw         $t0, 0x0($a0)
.set noreorder
    sw         $t1, 0x4($a0)
.set reorder
    jr         $ra
endlabel vs_battle_getGeomOffset

nonmatching vs_battle_setGeomOffset, 0x20

glabel vs_battle_setGeomOffset
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    sll        $t0, 16
    sll        $t1, 16
    ctc2       $t0, $24
    ctc2       $t1, $25
    jr         $ra
endlabel vs_battle_setGeomOffset

nonmatching func_80099514, 0x9C

glabel func_80099514
    la         $a3, vs_battle_roomData
    lw         $a3, 0x68($a3)
    srl        $t1, $a1, 2
    lh         $t0, 0x0($a3)
    lh         $v0, 0x6($a3)
    mult       $t0, $t1
    addiu      $t0, $a3, 0x8
    sll       $v0, 1
    beqz       $a2, 1f
  0:
    addiu      $a2, -0x1
    addu      $t0, $v0
    bnez       $a2, 0b
  1:
    addiu      $t1, $a3, 0x8
    sll        $at, $v0, 1
    addu       $t1, $at
    mflo       $v0
    srl        $at, $a0, 2
    addu       $at, $v0
    sll        $at, 1
    addu       $t0, $at
    lh         $t0, 0x0($t0)
    and        $at, $t0, 0x7FF
    sll        $at, 4
    addu       $t1, $at
    and        $at, $a0, 0x3
    addu       $t1, $at
    and        $at, $a1, 0x3
    sll        $at, 2
    addu       $t1, $at
    lb         $t1, 0x0($t1)
    and        $t0, 0xF800
    srl        $t0, 9
    addu       $v0, $t1, $t0
    and        $v0, 0x7F
    and        $t1, 0x80
    or        $v0, $t1
    jr         $ra
endlabel func_80099514
