.include "macro.inc"
.include "src/include/gte_reg_macros.inc"

.set noreorder

.section .text, "ax"

nonmatching func_800B396C, 0xFC

glabel func_800B396C
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x0($a1)
    sll        $t7, $t0, 16
    sra        $t7, 16
    sra        $t8, $t1, 16
    sll        $t9, $t3, 16
    sra        $t9, 16
    ldir0123   $t4, $t7, $t8, $t9
    sra        $t7, $t0, 16
    sra        $t9, $t3, 16
    gpf12
    lw         $t5, 0x4($a1)
    sll        $t8, $t2, 16
    sra        $t8, 16
    addu       $v0, $zero, $a0
    mfc2       $v1, $9
    mfc2       $a2, $10
    mfc2       $a3, $11
    ldir0123   $t5, $t7, $t8, $t9
    sll        $t7, $t1, 16
    sra        $t7, 16
    gpf12
    lh         $t4, 0x10($a0)
    lw         $t6, 0x8($a1)
    sra        $t8, $t2, 16
    and        $v1, 0xFFFF
    and        $a3, 0xFFFF
    mfc2       $t1, $9
    mfc2       $t2, $10
    mfc2       $t3, $11
    ldir0123   $t6, $t7, $t8, $t4
    sll        $a2, 16
    sll        $t1, 16
    gpf12
    and        $t2, 0xFFFF
    sll        $t3, 16
    or         $t1, $v1
    sw         $t1, 0x0($v0)
    or         $t3, $a3
    mfc2       $t4, $9
    mfc2       $t5, $10
    mfc2       $t6, $11
    and        $t4, 0xFFFF
    or         $t4, $a2
    sll        $t5, 16
    or         $t5, $t2
    sw         $t4, 0x4($v0)
    sw         $t5, 0x8($v0)
    sw         $t3, 0xC($v0)
    jr         $ra
     sh        $t6, 0x10($v0)
endlabel func_800B396C

nonmatching func_800B3A68, 0x288

glabel func_800B3A68
    or         $t0, $a3, $zero
    lui        $a3, %hi(0x1F800378)
    sw         $s0, %lo(0x1F800358)($a3)
    sw         $s1, %lo(0x1F80035C)($a3)
    sw         $s2, %lo(0x1F800360)($a3)
    sw         $s3, %lo(0x1F800364)($a3)
    sw         $s4, %lo(0x1F800368)($a3)
    sw         $s5, %lo(0x1F80036C)($a3)
    sw         $s6, %lo(0x1F800370)($a3)
    sw         $s7, %lo(0x1F800374)($a3)
    sw         $gp, %lo(0x1F800378)($a3)
    lbu        $a3, 0x1($a0)
    lw         $t2, 0x34($t0)
    lw         $t5, 0x38($t0)
    or         $t6, $zero, $zero
    or         $s6, $t5, $zero
    or         $s7, $zero, $zero
    lw         $s0, 0x0($s6)
    lw         $s1, 0x4($s6)
    lw         $s2, 0x8($s6)
    lw         $s3, 0xC($s6)
    lw         $s4, 0x10($s6)
    lw         $s5, 0x14($s6)
    lw         $t3, 0x0($t2)
    la         $gp, D_800F2458
  0:
    srl        $t4, $t3, 16
  1:
    add        $t4, -0x1
    and        $t3, 0xFFFF
    sll        $t3, 5
  2:
    add        $t3, $a1
    lw         $v0, 0x0($t3)
    lw         $v1, 0x4($t3)
    lw         $t8, 0x8($t3)
    lw         $t9, 0xC($t3)
    ctc2       $v0, $0
    ctc2       $v1, $1
    ctc2       $t8, $2
    ctc2       $t9, $3
    lw         $v0, 0x10($t3)
    lw         $v1, 0x14($t3)
    lw         $t8, 0x18($t3)
    lw         $t9, 0x1C($t3)
    ctc2       $v0, $4
    ctc2       $v1, $5
    ctc2       $t8, $6
    ctc2       $t9, $7
    sub        $v0, $t4, $t6
  3:
    add        $v0, -0x2
    bltz       $v0, 5f
     mtv3      $s0, $s1, $s2, $s3, $s4, $s5
    sll        $v0, $t6, 2
    add        $v1, $v0, 0xC00
    rtpt
    add        $t1, $v0, $gp
    lw         $s0, 0x18($s6)
    lw         $s1, 0x1C($s6)
    lw         $s2, 0x20($s6)
    lw         $s3, 0x24($s6)
    lw         $s4, 0x28($s6)
    lw         $s5, 0x2C($s6)
    add        $t6, 0x3
    sub        $v0, $t4, $t6
    bgez       $v0, 4f
     add       $v1, $gp
    add        $t2, 0x4
    lw         $t3, 0x0($t2)
  4:
    mfc2       $t7, $17
    mfc2       $t8, $18
    mfc2       $t9, $19
    or         $s7, $t7
    sw         $t7, 0x0($v1)
    or         $s7, $t8
    sw         $t8, 0x4($v1)
    or         $s7, $t9
    sw         $t9, 0x8($v1)
    swc2       $12, 0x0($t1)
    swc2       $13, 0x4($t1)
    swc2       $14, 0x8($t1)
    bgez       $v0, 3b
     add       $s6, 0x18
    add        $a3, -0x1
    beqz       $a3, 7f
     srl       $t4, $t3, 16
    j          1b
  5:
     add       $v0, 0x1
    bltz       $v0, 6f
     mtc2      $s0, $0
    mtc2       $s1, $1
    mtc2       $s2, $2
    mtc2       $s3, $3
    sll        $v0, $t6, 2
    add        $v1, $v0, 0xC00
    rtpt
    add        $v0, $gp
    add        $v1, $gp
    or         $s0, $s4, $zero
    or         $s1, $s5, $zero
    lw         $s2, 0x18($s6)
    lw         $s3, 0x1C($s6)
    lw         $s4, 0x20($s6)
    lw         $s5, 0x24($s6)
    add        $t6, 0x2
    add        $t2, 0x4
    lw         $t3, 0x0($t2)
    add        $s6, 0x10
    srl        $t4, $t3, 16
    add        $t4, -0x1
    and        $t3, 0xFFFF
    mfc2       $t7, $17
    mfc2       $t8, $18
    or         $s7, $t7
    sw         $t7, 0x0($v1)
    or         $s7, $t8
    sw         $t8, 0x4($v1)
    swc2       $12, 0x0($v0)
    swc2       $13, 0x4($v0)
    add        $a3, -0x1
    beqz       $a3, 7f
     sll       $t3, 5
    j          2b
  6:
     mtv0      $s0, $s1
    sll        $v0, $t6, 2
    add        $v1, $v0, 0xC00
    rtps
    add        $v0, $gp
    add        $v1, $gp
    or         $s0, $s2, $zero
    or         $s1, $s3, $zero
    or         $s2, $s4, $zero
    or         $s3, $s5, $zero
    lw         $s4, 0x18($s6)
    lw         $s5, 0x1C($s6)
    add        $t2, 0x4
    lw         $t3, 0x0($t2)
    mfc2       $t7, $19
    swc2       $14, 0x0($v0)
    or         $s7, $t7
    sw         $t7, 0x0($v1)
    add        $a3, -0x1
    beqz       $a3, 7f
     add       $s6, 0x8
    j          0b
     add       $t6, 0x1
  7:
    or         $v0, $s7, $zero
    lui        $a3, %hi(0x1F800378)
    lw         $s0, %lo(0x1F800358)($a3)
    lw         $s1, %lo(0x1F80035C)($a3)
    lw         $s2, %lo(0x1F800360)($a3)
    lw         $s3, %lo(0x1F800364)($a3)
    lw         $s4, %lo(0x1F800368)($a3)
    lw         $s5, %lo(0x1F80036C)($a3)
    lw         $s6, %lo(0x1F800370)($a3)
    lw         $s7, %lo(0x1F800374)($a3)
    jr         $ra
     lw        $gp, %lo(0x1F800378)($a3)
endlabel func_800B3A68

nonmatching func_800B3CF0, 0x8A4

glabel func_800B3CF0
    lui        $t0, %hi(0x1F800390)
    sw         $s0, %lo(0x1F800358)($t0)
    sw         $s1, %lo(0x1F80035C)($t0)
    sw         $s2, %lo(0x1F800360)($t0)
    sw         $s3, %lo(0x1F800364)($t0)
    sw         $s4, %lo(0x1F800368)($t0)
    sw         $s5, %lo(0x1F80036C)($t0)
    sw         $s6, %lo(0x1F800370)($t0)
    sw         $s7, %lo(0x1F800374)($t0)
    sw         $ra, %lo(0x1F800378)($t0)
    sw         $gp, %lo(0x1F80037C)($t0)
    sw         $fp, %lo(0x1F800380)($t0)
    lw         $gp, %lo(0x1F800390)($t0)
    li         $s4, 0xFFFFFF
    sll        $ra, $gp, 16
    srl        $gp, 16
    sll        $gp, 16
    li         $s5, 0xFF000000
    lui        $s0, %hi(0x1F800004)
    lhu        $s3, 0x2($a1)
    lw         $s2, 0x3C($a3)
    addiu      $fp, $a0, 0xC00
    lw         $s1, %lo(0x1F800000)($s0)
    lw         $s7, %lo(0x1F800004)($s0)
    lw         $a2, 0x0($a2)
    add        $s7, -0x4
    and        $a2, $s4
    beqz       $s3, 3f
     li        $t8, 0x7000000
    li         $v1, 0x24000000
    or         $v1, $a2
    lw         $t3, 0x4($s2)
  0:
    lw         $t7, 0x8($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t7, 16
    add        $t0, $fp
    nclip
    lw         $t0, 0x0($t0)
    add        $t1, $fp
    mfc2       $v0, $24
    add        $t2, $fp
    bgtz       $v0, 1f
     addiu     $s3, -0x1
    beqz       $s3, 3f
     addiu     $s2, 0x10
    j          0b
     lw        $t3, 0x4($s2)
  1:
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    ldsz3      $t0, $t1, $t2
    lw         $t3, 0xC($s2)
    sw         $v1, 0x4($s1)
    avsz3
    sw         $t4, 0x8($s1)
    srl        $t1, $t3, 16
    or         $t1, $ra
    and        $t0, $t3, 0xFFFF
    or         $t0, $gp
    sw         $t0, 0xC($s1)
    sw         $t5, 0x10($s1)
    mfc2       $v0, $7
    sw         $t1, 0x14($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 2f
     sll       $v0, 2
    sw         $t6, 0x18($s1)
    add        $v0, $s7, $v0
    sw         $t7, 0x1C($s1)
    lw         $t2, 0x0($v0)
    and        $t1, $s1, $s4
    and        $t0, $t2, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  2:
    beqz       $s3, 3f
     addiu     $s2, 0x10
    j          0b
     lw        $t3, 0x4($s2)
  3:
    lhu        $s3, 0x4($a1)
    li         $t8, 0x9000000
    li         $v1, 0x2C000000
    beqz       $s3, 7f
     or        $v1, $a2
    lw         $t3, 0x4($s2)
  4:
    lw         $t7, 0x8($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    nclip
    add        $t0, $fp
    add        $t1, $fp
    add        $t2, $fp
    lw         $t0, 0x0($t0)
    mfc2       $v0, $24
    add        $t3, $fp
    bgtz       $v0, 5f
     addiu     $s3, -0x1
    beqz       $s3, 7f
     addiu     $s2, 0x14
    j          4b
     lw        $t3, 0x4($s2)
  5:
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    lw         $t7, 0x0($t7)
    add        $v0, $t2
    lw         $t0, 0xC($s2)
    lw         $t2, 0x10($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $t5, 0x10($s1)
    add        $v0, $t3
    sw         $t1, 0x14($s1)
    srl        $t3, $t2, 16
    sw         $t6, 0x18($s1)
    srl        $v0, 4
    sw         $t2, 0x1C($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 6f
     sll       $v0, 2
    sw         $t7, 0x20($s1)
    add        $v0, $s7, $v0
    sw         $t3, 0x24($s1)
    lw         $t2, 0x0($v0)
    and        $t1, $s1, $s4
    and        $t0, $t2, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  6:
    beqz       $s3, 7f
     addiu     $s2, 0x14
    j          4b
     lw        $t3, 0x4($s2)
  7:
    lhu        $s3, 0x6($a1)
    add        $s7, -0x10
    beqz       $s3, 21f
     or        $a1, $fp, $zero
    lw         $fp, 0x0($s2)
  8:
    lw         $t3, 0x4($s2)
    srl        $v1, $fp, 16
    and        $v0, $v1, 0x1
    lw         $t7, 0x8($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    bnez       $v0, 9f
     lw        $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    or         $s0, $t3, $zero
    nclip
    add        $t7, $a0, $t3
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    and        $t8, $fp, 0xFF
    srl        $v1, $fp, 8
    mfc2       $v0, $24
    and        $v1, 0xFF
    bgtz       $v0, 10f
     addiu     $s3, -0x1
    beqz       $s3, 21f
     add       $s2, $v1
    j          8b
     lw        $fp, 0x0($s2)
  9:
    addiu      $s3, -0x1
    srl        $t3, $t7, 16
    or         $s0, $t3, $zero
    add        $t7, $a0, $t3
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    srl        $t9, $fp, 8
    and        $v1, 0x2
    bnez       $v1, 14f
     and       $t8, $fp, 0xFF
  10:
    lw         $t0, 0x0($t0)
    or         $v0, $zero, 0x2C
    lw         $t1, 0x0($t1)
    beq        $t8, $v0, 12f
     lw        $t2, 0x0($t2)
    ldsz3      $t0, $t1, $t2
    srl        $t2, $fp, 20
    and        $t2, 0x1
    sll        $t2, 25
    li         $v1, 0x24000000
    or         $v1, $t2
    or         $v1, $a2
    avsz3
    srl        $t2, $fp, 16
    and        $t2, 0x60
    sll        $t2, 16
    lw         $t0, 0xC($s2)
    sw         $v1, 0x4($s1)
    srl        $t1, $t0, 16
    or         $t1, $ra
    or         $t1, $t2
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    mfc2       $v0, $7
    sw         $t5, 0x10($s1)
    srl        $v1, $fp, 18
    sw         $t1, 0x14($s1)
    and        $v1, 0x3
    sw         $t6, 0x18($s1)
    sll        $v1, 2
    sw         $s0, 0x1C($s1)
    add        $v0, $v1
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 11f
     sll       $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  11:
    beqz       $s3, 21f
     addiu     $s2, 0x10
    j          8b
     lw        $fp, 0x0($s2)
  12:
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    lw         $t7, 0x0($t7)
    add        $v0, $t2
    lw         $t0, 0xC($s2)
    lw         $t2, 0x10($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    and        $t0, 0xFFFF
    or         $t0, $gp
    srl        $t8, $fp, 20
    and        $t8, 0x1
    sll        $t8, 25
    li         $v1, 0x2C000000
    or         $v1, $t8
    or         $v1, $a2
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    srl        $t8, $fp, 16
    and        $t8, 0x60
    sll        $t8, 16
    sw         $t5, 0x10($s1)
    add        $v0, $t3
    or         $t1, $t8
    sw         $t1, 0x14($s1)
    srl        $t3, $t2, 16
    sw         $t6, 0x18($s1)
    srl        $v0, 4
    sw         $t2, 0x1C($s1)
    srl        $v1, $fp, 18
    sw         $t7, 0x20($s1)
    and        $v1, 0x3
    sw         $t3, 0x24($s1)
    sll        $v1, 2
    add        $v0, $v1
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 13f
     sll       $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x9000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  13:
    beqz       $s3, 21f
     addiu     $s2, 0x14
    j          8b
     lw        $fp, 0x0($s2)
  14:
    lw         $t0, 0x0($t0)
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    sll        $v0, $t4, 16
    sll        $v1, $t6, 16
    sra        $v0, 16
    sra        $v1, 16
    subu       $t8, $v1, $v0
    ctc2       $t8, $0
    sra        $s0, $t4, 16
    sra        $v1, $t6, 16
    subu       $t8, $v1, $s0
    ctc2       $t8, $2
    subu       $s0, $t2, $t0
    ctc2       $s0, $4
    subu       $s0, $t1, $t0
    mtc2       $s0, $11
    sll        $v1, $t5, 16
    sra        $v1, 16
    subu       $t8, $v1, $v0
    mtc2       $t8, $9
    sra        $s0, $t4, 16
    sra        $v1, $t5, 16
    subu       $t8, $v1, $s0
    mtc2       $t8, $10
    nop
    op0
    lw         $t7, 0x0($t7)
    mfc2       $s6, $25
    sll        $v1, $t7, 16
    sra        $v1, 16
    subu       $t8, $v1, $v0
    multu      $t8, $s6
    sra        $v1, $t7, 16
    mflo       $t8
    mfc2       $v0, $26
    subu       $s6, $v1, $s0
    multu      $s6, $v0
    lw         $t3, 0x0($t3)
    mflo       $s6
    mfc2       $v0, $27
    subu       $v1, $t3, $t0
    multu      $v0, $v1
    add        $t8, $s6
    mtc2       $t4, $12
    mtc2       $t5, $13
    mflo       $v0
    add        $v0, $t8, $v0
    negu       $v0, $v0
    bgtz       $v0, 18f
     nop
    mtc2       $t7, $14
    mtc2       $t0, $17
    mtc2       $t1, $18
    nclip
    mtc2       $t3, $19
    lw         $t0, 0xC($s2)
    lw         $s6, 0x10($s2)
    srl        $t1, $t0, 16
    mfc2       $v0, $24
    and        $t0, 0xFFFF
    blez       $v0, 15f
     or        $t0, $gp
    avsz3
    li         $v1, 0x24000000
    or         $v1, $a2
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $t5, 0x10($s1)
    or         $t1, $ra
    sw         $t1, 0x14($s1)
    srl        $t3, $s6, 16
    sw         $t7, 0x18($s1)
    mfc2       $v0, $7
    sw         $t3, 0x1C($s1)
    addiu      $v0, 0x4
    sltiu      $s0, $v0, 0x7C0
    beqz       $s0, 15f
     sll       $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $s0, $v1, $s4
    or         $s0, $t8
    sw         $s0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $s0, $v1, $s5
    or         $s0, $t1
    sw         $s0, 0x0($v0)
    addiu      $s1, 0x20
  15:
    mtc2       $t7, $13
    mtc2       $t6, $14
    mtc2       $t2, $18
    li         $v1, 0x24000000
    nclip
    or         $v1, $a2
    srl        $t3, $s6, 16
    or         $t3, $ra
    sw         $v1, 0x4($s1)
    mfc2       $v0, $24
    sw         $t4, 0x8($s1)
    blez       $v0, 16f
     sw        $t0, 0xC($s1)
    avsz3
    sw         $t7, 0x10($s1)
    sw         $t3, 0x14($s1)
    sw         $t6, 0x18($s1)
    mfc2       $v0, $7
    sw         $s6, 0x1C($s1)
    addiu      $v0, 0x4
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 17f
     sll       $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
  16:
    addiu      $s1, 0x20
  17:
    beqz       $s3, 21f
     addiu     $s2, 0x14
    j          8b
     lw        $fp, 0x0($s2)
  18:
    mtc2       $t6, $14
    mtc2       $t0, $17
    mtc2       $t1, $18
    nclip
    mtc2       $t2, $19
    lw         $t0, 0xC($s2)
    lw         $s6, 0x10($s2)
    srl        $t1, $t0, 16
    mfc2       $v0, $24
    li         $v1, 0x24000000
    blez       $v0, 19f
     or        $v1, $a2
    avsz3
    mfc2       $v0, $7
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $t0, 0xC($s1)
    sw         $t5, 0x10($s1)
    or         $t1, $ra
    sw         $t1, 0x14($s1)
    addiu      $v0, 0x4
    sw         $t6, 0x18($s1)
    sltiu      $s0, $v0, 0x7C0
    beqz       $s0, 19f
     sll       $v0, 2
    sw         $s6, 0x1C($s1)
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $s0, $v1, $s4
    or         $s0, $t8
    sw         $s0, 0x0($s1)
    and        $t0, $s1, $s4
    and        $s0, $v1, $s5
    or         $s0, $t0
    sw         $s0, 0x0($v0)
    addiu      $s1, 0x20
  19:
    ldsxy3     $t5, $t7, $t6
    mtc2       $t3, $17
    li         $v1, 0x24000000
    nclip
    or         $v1, $a2
    sw         $v1, 0x4($s1)
    and        $t1, 0xFFFF
    or         $t1, $gp
    mfc2       $v0, $24
    srl        $t3, $s6, 16
    blez       $v0, 20f
     or        $t3, $ra
    avsz3
    sw         $t5, 0x8($s1)
    sw         $t1, 0xC($s1)
    sw         $t7, 0x10($s1)
    sw         $t3, 0x14($s1)
    mfc2       $v0, $7
    sw         $t6, 0x18($s1)
    addiu      $v0, 0x4
    sw         $s6, 0x1C($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 20f
     sll       $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  20:
    beqz       $s3, 21f
     addiu     $s2, 0x14
    j          8b
     lw        $fp, 0x0($s2)
  21:
    lui        $t0, %hi(0x1F800380)
    sw         $s1, %lo(0x1F800000)($t0)
    lw         $s0, %lo(0x1F800358)($t0)
    lw         $s1, %lo(0x1F80035C)($t0)
    lw         $s2, %lo(0x1F800360)($t0)
    lw         $s3, %lo(0x1F800364)($t0)
    lw         $s4, %lo(0x1F800368)($t0)
    lw         $s5, %lo(0x1F80036C)($t0)
    lw         $s6, %lo(0x1F800370)($t0)
    lw         $s7, %lo(0x1F800374)($t0)
    lw         $ra, %lo(0x1F800378)($t0)
    lw         $gp, %lo(0x1F80037C)($t0)
    jr         $ra
     lw        $fp, %lo(0x1F800380)($t0)
endlabel func_800B3CF0

nonmatching func_800B4594, 0x580

glabel func_800B4594
    lui        $t0, %hi(0x1F800390)
    sw         $s0, %lo(0x1F800358)($t0)
    sw         $s1, %lo(0x1F80035C)($t0)
    sw         $s2, %lo(0x1F800360)($t0)
    sw         $s3, %lo(0x1F800364)($t0)
    sw         $s4, %lo(0x1F800368)($t0)
    sw         $s5, %lo(0x1F80036C)($t0)
    sw         $s6, %lo(0x1F800370)($t0)
    sw         $s7, %lo(0x1F800374)($t0)
    sw         $ra, %lo(0x1F800378)($t0)
    sw         $gp, %lo(0x1F80037C)($t0)
    sw         $fp, %lo(0x1F800380)($t0)
    lw         $gp, %lo(0x1F800390)($t0)
    li         $s4, 0xFFFFFF
    sll        $ra, $gp, 16
    srl        $gp, 16
    sll        $gp, 16
    li         $s5, 0xFF000000
    lui        $s0, %hi(0x1F800004)
    lhu        $s3, 0x2($a1)
    lw         $s2, 0x3C($a3)
    addiu      $fp, $a0, 0xC00
    lw         $s1, %lo(0x1F800000)($s0)
    lw         $s7, %lo(0x1F800004)($s0)
    lw         $a2, 0x0($a2)
    add        $s7, -0x4
    beqz       $s3, 3f
     li        $t8, 0x9000000
    lw         $t3, 0x0($s2)
  0:
    lw         $t7, 0x4($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t7, 16
    add        $t0, $fp
    nclip
    lw         $v1, 0x8($s2)
    add        $t1, $fp
    mfc2       $v0, $24
    add        $t2, $fp
    bgtz       $v0, 1f
     addiu     $s3, -0x1
    beqz       $s3, 3f
     addiu     $s2, 0x18
    j          0b
     lw        $t3, 0x0($s2)
  1:
    lw         $t0, 0x0($t0)
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    ldsz3      $t0, $t1, $t2
    lw         $t0, 0xC($s2)
    lw         $t1, 0x10($s2)
    lw         $t3, 0x14($s2)
    sw         $v1, 0x4($s1)
    avsz3
    sw         $t4, 0x8($s1)
    srl        $v1, $t3, 16
    or         $v1, $ra
    and        $v0, $t3, 0xFFFF
    or         $v0, $gp
    sw         $v0, 0xC($s1)
    sw         $t0, 0x10($s1)
    mfc2       $v0, $7
    sw         $t5, 0x14($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 2f
     sll       $v0, 2
    sw         $v1, 0x18($s1)
    add        $v0, $s7, $v0
    sw         $t1, 0x1C($s1)
    lw         $t2, 0x0($v0)
    sw         $t6, 0x20($s1)
    and        $t1, $s1, $s4
    sw         $t7, 0x24($s1)
    and        $t0, $t2, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  2:
    beqz       $s3, 3f
     addiu     $s2, 0x18
    j          0b
     lw        $t3, 0x0($s2)
  3:
    lhu        $s3, 0x4($a1)
    li         $t8, 0xC000000
    beqz       $s3, 7f
     lw        $t3, 0x0($s2)
  4:
    lw         $t7, 0x4($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    nclip
    add        $t0, $fp
    add        $t1, $fp
    add        $t2, $fp
    lw         $v1, 0x8($s2)
    mfc2       $v0, $24
    add        $t3, $fp
    bgtz       $v0, 5f
     addiu     $s3, -0x1
    beqz       $s3, 7f
     addiu     $s2, 0x20
    j          4b
     lw        $t3, 0x0($s2)
  5:
    lw         $t0, 0x0($t0)
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    lw         $t7, 0x0($t7)
    add        $v0, $t2
    lw         $s0, 0xC($s2)
    lw         $s6, 0x10($s2)
    lw         $t9, 0x14($s2)
    lw         $t0, 0x18($s2)
    lw         $t2, 0x1C($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $s0, 0x10($s1)
    add        $v0, $t3
    sw         $t5, 0x14($s1)
    srl        $t3, $t2, 16
    sw         $t1, 0x18($s1)
    srl        $v0, 4
    sw         $s6, 0x1C($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 6f
     sll       $v0, 2
    sw         $t6, 0x20($s1)
    add        $v0, $s7, $v0
    sw         $t2, 0x24($s1)
    lw         $s0, 0x0($v0)
    sw         $t9, 0x28($s1)
    and        $t1, $s1, $s4
    sw         $t7, 0x2C($s1)
    and        $t0, $s0, $s4
    sw         $t3, 0x30($s1)
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $s0, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x34
  6:
    beqz       $s3, 7f
     addiu     $s2, 0x20
    j          4b
     lw        $t3, 0x0($s2)
  7:
    lhu        $s3, 0x6($a1)
    add        $s7, -0x10
    beqz       $s3, 14f
     or        $a1, $fp, $zero
    lw         $fp, 0x10($s2)
  8:
    lw         $t3, 0x0($s2)
    srl        $v1, $fp, 24
    and        $v0, $v1, 0x1
    lw         $t7, 0x4($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    bnez       $v0, 9f
     lw        $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    nclip
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    lw         $t8, 0x8($s2)
    lw         $s0, 0xC($s2)
    mfc2       $v0, $24
    srl        $s0, 24
    bgtz       $v0, 10f
     addiu     $s3, -0x1
    beqz       $s3, 14f
     add       $s2, $s0
    j          8b
     lw        $fp, 0x0($s2)
  9:
    addiu      $s3, -0x1
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    lw         $t8, 0x8($s2)
    nop
  10:
    srl        $s0, $t8, 24
    lw         $t0, 0x0($t0)
    or         $v0, $zero, 0x3C
    lw         $t1, 0x0($t1)
    beq        $s0, $v0, 12f
     lw        $t2, 0x0($t2)
    and        $s0, $v1, 0x10
    sll        $s0, 21
    or         $t8, $s0
    sw         $t8, 0x4($s1)
    ldsz3      $t0, $t1, $t2
    and        $v1, 0x60
    sll        $v1, 16
    avsz3
    lw         $t0, 0xC($s2)
    lw         $t1, 0x10($s2)
    lw         $t3, 0x14($s2)
    lw         $t8, 0x4($s2)
    srl        $t2, $t3, 16
    srl        $t8, 16
    or         $t2, $ra
    or         $t2, $v1
    and        $t7, $t3, 0xFFFF
    sw         $t4, 0x8($s1)
    or         $t7, $gp
    sw         $t7, 0xC($s1)
    mfc2       $v0, $7
    sw         $t0, 0x10($s1)
    srl        $v1, $t1, 26
    sw         $t5, 0x14($s1)
    and        $v1, 0x3
    sw         $t2, 0x18($s1)
    sll        $v1, 2
    sw         $t1, 0x1C($s1)
    add        $v0, $v1
    sw         $t6, 0x20($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 11f
     sll       $v0, 2
    sw         $t8, 0x24($s1)
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x9000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  11:
    beqz       $s3, 14f
     addiu     $s2, 0x18
    j          8b
     lw        $fp, 0x10($s2)
  12:
    and        $s0, $v1, 0x10
    sll        $s0, 21
    or         $t8, $s0
    sw         $t8, 0x4($s1)
    and        $t8, $v1, 0x60
    sll        $t8, 16
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    lw         $t7, 0x0($t7)
    lw         $v1, 0xC($s2)
    lw         $s0, 0x10($s2)
    lw         $s6, 0x14($s2)
    add        $v0, $t2
    lw         $t0, 0x18($s2)
    add        $v0, $t3
    lw         $t2, 0x1C($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    or         $t1, $t8
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $v1, 0x10($s1)
    srl        $t3, $t2, 16
    sw         $t5, 0x14($s1)
    srl        $v0, 4
    sw         $t1, 0x18($s1)
    srl        $v1, $s0, 26
    sw         $s0, 0x1C($s1)
    and        $v1, 0x3
    sw         $t6, 0x20($s1)
    sll        $v1, 2
    sw         $t2, 0x24($s1)
    add        $v0, $v1
    sw         $s6, 0x28($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 13f
     sw        $t7, 0x2C($s1)
    sll        $v0, 2
    sw         $t3, 0x30($s1)
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0xC000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x34
  13:
    beqz       $s3, 14f
     addiu     $s2, 0x20
    j          8b
     lw        $fp, 0x10($s2)
  14:
    lui        $t0, %hi(0x1F800380)
    sw         $s1, %lo(0x1F800000)($t0)
    lw         $s0, %lo(0x1F800358)($t0)
    lw         $s1, %lo(0x1F80035C)($t0)
    lw         $s2, %lo(0x1F800360)($t0)
    lw         $s3, %lo(0x1F800364)($t0)
    lw         $s4, %lo(0x1F800368)($t0)
    lw         $s5, %lo(0x1F80036C)($t0)
    lw         $s6, %lo(0x1F800370)($t0)
    lw         $s7, %lo(0x1F800374)($t0)
    lw         $ra, %lo(0x1F800378)($t0)
    lw         $gp, %lo(0x1F80037C)($t0)
    jr         $ra
     lw        $fp, %lo(0x1F800380)($t0)
endlabel func_800B4594

nonmatching func_800B4B14, 0x658

glabel func_800B4B14
    lui        $t0, %hi(0x1F800348)
    sw         $s0, %lo(0x1F800320)($t0)
    sw         $s1, %lo(0x1F800324)($t0)
    sw         $s2, %lo(0x1F800328)($t0)
    sw         $s3, %lo(0x1F80032C)($t0)
    sw         $s4, %lo(0x1F800330)($t0)
    sw         $s5, %lo(0x1F800334)($t0)
    sw         $s6, %lo(0x1F800338)($t0)
    sw         $s7, %lo(0x1F80033C)($t0)
    sw         $ra, %lo(0x1F800340)($t0)
    sw         $gp, %lo(0x1F800344)($t0)
    sw         $fp, %lo(0x1F800348)($t0)
    lui        $s7, %hi(0x1F8003E4)
    or         $s0, $zero, $a0
    lw         $s1, 0x1C($a0)
    lh         $s4, 0x20($a0)
    and        $s3, $s1, 0xFFFF
    add        $a0, 0x1C
    or         $a1, $zero, $zero
    or         $a2, $zero, $zero
    jal        func_800A6EE8
     or        $a3, $zero, 0x3
    or         $fp, $v0, $zero
    sra        $v1, $s1, 16
    sub        $v0, $v1, $v0
    blez       $v0, 0f
     nop
    sra        $fp, $s1, 16
  0:
    lh         $v0, %lo(0x1F8003B2)($s7)
    lhu        $s2, 0x64C($s0)
    sub        $v0, $fp
    sra        $v0, 3
    add        $v0, $s2
    slt        $v1, $v0, 0x14
    beqz       $v1, 1f
     nop
    or         $v0, $zero, 0x14
  1:
    la         $s5, D_800F49F4
    nop
    lb         $t0, 0x0($s5)
    sll        $s6, $v0, 7
    bgtz       $t0, 12f
     srl       $a0, $s3, 7
    srl        $a1, $s4, 7
    sw         $zero, %lo(0x1F8003E4)($s7)
    add        $a0, $s0, 0x1C
    or         $a1, $s2, $zero
    or         $a2, $zero, $zero
    jal        func_800A6EE8
     or        $a3, $zero, 0x3
    lb         $t0, 0x0($s5)
    or         $s1, $v0, $zero
    bgtz       $t0, 12f
     addiu     $a0, $s0, 0x1C
    neg        $a1, $s2
    or         $a2, $zero, $zero
    jal        func_800A6EE8
     or        $a3, $zero, 0x3
    lb         $t0, 0x0($s5)
    or         $v1, $v0, $zero
    bgtz       $t0, 12f
     sub       $a0, $v1, $s1
    beqz       $a0, 6f
     sub       $a0, $fp, $v1
    sub        $a1, $s1, $fp
    bgez       $a0, 2f
     or        $v0, $zero, $a0
    neg        $v0, $a0
  2:
    bgez       $a1, 3f
     or        $v1, $zero, $a1
    neg        $v1, $a1
  3:
    sub        $v0, $v1
    blez       $v0, 4f
     nop
    or         $a0, $zero, $a1
  4:
    jal        ratan2
     or        $a1, $zero, $s2
    slt        $v1, $v0, -0x280
    bgtz       $v1, 5f
     slt       $t0, $v0, 0x280
    beqz       $t0, 5f
     nop
    j          6f
     sh        $v0, %lo(0x1F8003E4)($s7)
  5:
    or         $v0, $zero, $zero
    sh         $v0, %lo(0x1F8003E4)($s7)
  6:
    sh         $zero, %lo(0x1F8003E0)($s7)
    addiu      $a0, $s0, 0x1C
    or         $a1, $zero, $zero
    neg        $a2, $s2
    jal        func_800A6EE8
     or        $a3, $zero, 0x3
    lb         $t0, 0x0($s5)
    or         $s1, $v0, $zero
    bgtz       $t0, 12f
     addiu     $a0, $s0, 0x1C
    or         $a1, $zero, $zero
    or         $a2, $zero, $s2
    jal        func_800A6EE8
     or        $a3, $zero, 0x3
    lb         $t0, 0x0($s5)
    or         $v1, $v0, $zero
    bgtz       $t0, 12f
     sub       $a0, $v1, $s1
    beqz       $a0, 11f
     sub       $a0, $fp, $v1
    sub        $a1, $s1, $fp
    bgez       $a0, 7f
     or        $v0, $zero, $a0
    neg        $v0, $a0
  7:
    bgez       $a1, 8f
     or        $v1, $zero, $a1
    neg        $v1, $a1
  8:
    sub        $v0, $v1
    blez       $v0, 9f
     nop
    or         $a0, $zero, $a1
  9:
    jal        ratan2
     or        $a1, $zero, $s2
    slt        $v1, $v0, -0x280
    bgtz       $v1, 10f
     slt       $t0, $v0, 0x280
    beqz       $t0, 10f
     nop
    j          11f
     sh        $v0, %lo(0x1F8003E0)($s7)
  10:
    or         $v0, $zero, $zero
    sh         $v0, %lo(0x1F8003E0)($s7)
  11:
    j          13f
     sh        $zero, %lo(0x1F8003E2)($s7)
  12:
    or         $v0, $zero, 0x1000
    sw         $v0, %lo(0x1F8003C0)($s7)
    sw         $zero, %lo(0x1F8003C4)($s7)
    sw         $v0, %lo(0x1F8003C8)($s7)
    sw         $zero, %lo(0x1F8003CC)($s7)
    sw         $zero, %lo(0x1F8003E0)($s7)
    sw         $zero, %lo(0x1F8003E4)($s7)
    j          14f
     sw        $v0, %lo(0x1F8003D0)($s7)
  13:
    addiu      $a0, $s7, %lo(D_1F8003E0)
    jal        RotMatrixYXZ_gte
     addiu     $a1, $s7, %lo(D_1F8003C0)
  14:
    addiu      $a0, $s7, %lo(vs_scratch + 0x14)
    jal        func_800B196C
     addiu     $a1, $s7, %lo(D_1F8003C0)
    lw         $v0, 0x24($s0)
    lw         $a0, 0x28($s0)
    lh         $a2, 0x186C($s0)
    sw         $v0, %lo(0x1F8003E0)($s7)
    sw         $a0, %lo(0x1F8003E4)($s7)
    sra        $a1, $v0, 16
    add        $a1, $a2
    sh         $a1, %lo(0x1F8003E2)($s7)
    addiu      $a0, $s7, %lo(D_1F8003E0)
    jal        RotMatrixYXZ_gte
     addiu     $a1, $s7, %lo(D_1F800350)
    addiu      $a0, $s7, %lo(D_1F8003C0)
    jal        func_800B196C
     addiu     $a1, $s7, %lo(D_1F800350)
    addiu      $a0, $s7, %lo(D_1F8003C0)
    addiu      $a1, $s7, %lo(D_1F800350)
    jal        vs_main_memcpy
     or        $a2, $zero, 0x20
    lw         $t0, 0x2C($s0)
    lw         $t1, 0x30($s0)
    srl        $v0, $t0, 16
    multu      $s6, $v0
    lh         $t2, 0x1870($s0)
    lh         $t3, 0x1872($s0)
    srl        $t2, 1
    srl        $t3, 1
    sw         $t1, %lo(0x1F8003EC)($s7)
    mflo       $v1
    and        $v0, $t0, 0xFFFF
    srl        $v1, 12
    multu      $v1, $t3
    mflo       $v1
    nop
    srl        $v1, 12
    multu      $s6, $v0
    sw         $v1, %lo(0x1F8003E8)($s7)
    mflo       $v1
    nop
    srl        $v1, 12
    multu      $v1, $t2
    nop
    mflo       $v1
    nop
    srl        $v1, 12
    sw         $v1, %lo(0x1F8003F0)($s7)
    addiu      $a0, $s7, %lo(D_1F8003C0)
    jal        func_800B396C
     addiu     $a1, $s7, %lo(D_1F8003E8)
    lw         $t0, %lo(0x1F800014)($s7)
    lw         $t1, %lo(0x1F800018)($s7)
    lw         $t2, %lo(0x1F80001C)($s7)
    lw         $t3, %lo(0x1F800020)($s7)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    lw         $t0, %lo(0x1F800024)($s7)
    lw         $t1, %lo(0x1F800028)($s7)
    lw         $t2, %lo(0x1F80002C)($s7)
    lw         $t3, %lo(0x1F800030)($s7)
    ctc2       $t0, $4
    ctc2       $t1, $5
    ctc2       $t2, $6
    ctc2       $t3, $7
    lw         $v0, %lo(0x1F8003B0)($s7)
    lw         $t0, %lo(0x1F8003B4)($s7)
    sll        $v1, $fp, 16
    and        $v0, 0xFFFF
    or         $v0, $v1
    mtv0       $v0, $t0
    lw         $t2, %lo(0x1F8003C0)($s7)
    lw         $t3, %lo(0x1F8003C4)($s7)
    rtv0tr
    lw         $t4, %lo(0x1F8003C8)($s7)
    lw         $t5, %lo(0x1F8003CC)($s7)
    lw         $t6, %lo(0x1F8003D0)($s7)
    addiu      $s3, $s7, %lo(D_1F800370)
    addiu      $s4, $s7, %lo(D_1F8003B8)
    or         $s5, $zero, 0x5
    la         $s6, D_800E9A68
    mfc2       $t7, $25
    mfc2       $t8, $26
    mfc2       $t9, $27
    ctc2       $t2, $0
    ctc2       $t3, $1
    ctc2       $t4, $2
    ctc2       $t5, $3
    ctc2       $t6, $4
    ctc2       $t7, $5
    ctc2       $t8, $6
    ctc2       $t9, $7
    lw         $t1, 0x0($s6)
    lw         $t3, 0x4($s6)
    lw         $t5, 0x8($s6)
    and        $t0, $t1, 0xFFFF
    srl        $t1, 16
    and        $t2, $t3, 0xFFFF
    srl        $t3, 16
    and        $t4, $t5, 0xFFFF
    srl        $t5, 16
  15:
    mtv3       $t0, $t1, $t2, $t3, $t4, $t5
    addiu      $s6, 0xC
    add        $s5, -0x1
    rtpt
    lw         $t1, 0x0($s6)
    lw         $t3, 0x4($s6)
    lw         $t5, 0x8($s6)
    lw         $t6, 0x1864($s0)
    and        $t0, $t1, 0xFFFF
    srl        $t1, 16
    and        $t2, $t3, 0xFFFF
    srl        $t3, 16
    and        $t4, $t5, 0xFFFF
    srl        $t5, 16
    srl        $t7, $t6, 8
    and        $t7, 0xFF
    sll        $t7, 1
    srl        $t8, $t6, 16
    and        $t6, 0xFF
    swc2       $12, 0x0($s3)
    swc2       $13, 0x4($s3)
    swc2       $14, 0x8($s3)
    swc2       $17, 0x0($s4)
    swc2       $18, 0x4($s4)
    swc2       $19, 0x8($s4)
    addiu      $s3, 0xC
    bgez       $s5, 15b
     addiu     $s4, 0xC
    lb         $t0, 0x6F2($s0)
    add        $t6, $t7
    add        $t6, $t8
    srl        $t6, 2
    add        $t6, 0x40
    sll        $t0, 2
    sub        $t6, $t0
    bgtz       $t6, 16f
     li        $t5, 0xFF000000
    or         $t6, $zero, $zero
    j          17f
  16:
     slt       $v0, $t6, 0xFF
    bgtz       $v0, 17f
     li        $t5, 0xFF000000
    or         $t6, $zero, 0xFF
  17:
    or         $t7, $t6, 0x3200
    sll        $t7, 8
    or         $t7, $t6
    sll        $t7, 8
    or         $t7, $t6
    and        $t8, $t7, 0xFF
    srl        $t8, 1
    sll        $t6, $t8, 8
    or         $t8, $t6
    sll        $t6, 8
    or         $t8, $t6
    li         $s2, 0xE1000640
    li         $t6, 0xFFFFFF
    li         $s4, 0xFF000000
    lw         $t9, %lo(0x1F800370)($s7)
    lw         $ra, %lo(0x1F8003B8)($s7)
    sw         $t9, 0x6FC($s0)
    sw         $ra, 0x700($s0)
    or         $s5, $zero, 0x17
    la         $s6, D_800E9AD4
    lw         $s1, %lo(0x1F800000)($s7)
    lw         $fp, %lo(0x1F800004)($s7)
    li         $gp, 0x7000000
  18:
    lw         $t9, 0x0($s6)
    addiu      $s6, 0x4
    and        $t0, $t9, 0xFF
    srl        $t1, $t9, 8
    and        $t1, 0xFF
    srl        $t2, $t9, 16
    and        $t2, 0xFF
    add        $t0, $s7
    add        $t1, $s7
    add        $t2, $s7
    lw         $t3, 0x370($t0)
    lw         $t4, 0x370($t1)
    lw         $t5, 0x370($t2)
    ldsxy3     $t3, $t4, $t5
    lw         $v0, 0x3B8($t0)
    lw         $t1, 0x3B8($t1)
    nclip
    lw         $t2, 0x3B8($t2)
    slt        $v1, $v0, $t1
    bgtz       $v1, 19f
     nop
    or         $v0, $t1, $zero
  19:
    slt        $v1, $v0, $t2
    bgtz       $v1, 20f
     nop
    or         $v0, $t2, $zero
  20:
    mfc2       $v1, $24
    nop
    bgtz       $v1, 21f
     sw        $s2, 0x4($s1)
    sw         $t7, 0x8($s1)
    sw         $t3, 0xC($s1)
    sw         $t8, 0x10($s1)
    sw         $t4, 0x14($s1)
    sw         $t8, 0x18($s1)
    srl        $v0, 2
    sw         $t5, 0x1C($s1)
    add        $v0, -0x2
    sltiu      $v1, $v0, 0x7C0
    beqz       $v1, 21f
     sll       $v0, 2
    add        $v0, $fp, $v0
    lw         $t2, 0x0($v0)
    and        $t1, $s1, $t6
    and        $t0, $t2, $t6
    or         $t0, $gp
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s4
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  21:
    add        $s5, -0x1
    bltz       $s5, 24f
     add       $v0, $s5, -0xF
    beqz       $v0, 22f
     add       $v0, $s5, -0x7
    beqz       $v0, 23f
     nop
    j          18b
     nop
  22:
    or         $t7, $t8, $zero
    li         $t8, 0x32000000
    or         $t7, $t8
    j          18b
     or        $t8, $zero, $zero
  23:
    or         $t8, $t7, $zero
    j          18b
     li        $t7, 0x32000000
  24:
    sw         $s1, %lo(0x1F800000)($s7)
    lui        $t0, %hi(0x1F800348)
    lw         $s0, %lo(0x1F800320)($t0)
    lw         $s1, %lo(0x1F800324)($t0)
    lw         $s2, %lo(0x1F800328)($t0)
    lw         $s3, %lo(0x1F80032C)($t0)
    lw         $s4, %lo(0x1F800330)($t0)
    lw         $s5, %lo(0x1F800334)($t0)
    lw         $s6, %lo(0x1F800338)($t0)
    lw         $s7, %lo(0x1F80033C)($t0)
    lw         $ra, %lo(0x1F800340)($t0)
    lw         $gp, %lo(0x1F800344)($t0)
    jr         $ra
     lw        $fp, %lo(0x1F800348)($t0)
endlabel func_800B4B14

nonmatching func_800B516C, 0xAC4

glabel func_800B516C
    lui        $t0, %hi(0x1F800390)
    sw         $s0, %lo(0x1F800358)($t0)
    sw         $s1, %lo(0x1F80035C)($t0)
    sw         $s2, %lo(0x1F800360)($t0)
    sw         $s3, %lo(0x1F800364)($t0)
    sw         $s4, %lo(0x1F800368)($t0)
    sw         $s5, %lo(0x1F80036C)($t0)
    sw         $s6, %lo(0x1F800370)($t0)
    sw         $s7, %lo(0x1F800374)($t0)
    sw         $ra, %lo(0x1F800378)($t0)
    sw         $gp, %lo(0x1F80037C)($t0)
    sw         $fp, %lo(0x1F800380)($t0)
    lw         $gp, %lo(0x1F800390)($t0)
    li         $s4, 0xFFFFFF
    sll        $ra, $gp, 16
    srl        $gp, 16
    sll        $gp, 16
    li         $s5, 0xFF000000
    lui        $s0, %hi(0x1F800392)
    lhu        $s3, 0x2($a1)
    lw         $s2, 0x3C($a3)
    addiu      $fp, $a0, 0xC00
    lw         $s1, %lo(0x1F800000)($s0)
    lw         $s7, %lo(0x1F800004)($s0)
    lw         $a2, 0x0($a2)
    add        $s7, -0x4
    lbu        $s6, 0x64($a1)
    lbu        $v1, 0x9($a1)
    and        $a2, $s4
    and        $v1, 0xF
    beqz       $v1, 0f
     or        $t9, $zero, $zero
    slt        $v1, 0x7
    bnez       $v1, 0f
     li        $t9, 0x400000
    li         $t9, 0x200000
  0:
    or         $t0, $zero, 0x9
    sw         $t0, %lo(0x1F80039C)($s0)
    beqz       $s3, 10f
     addiu     $a3, 0x10
    addiu      $a3, -0x10
    li         $t8, 0x7000000
  1:
    lw         $t0, %lo(0x1F80039C)($s0)
    nop
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
  2:
    add        $t0, -0x1
    bltz       $t0, 10f
     sh        $t0, %lo(0x1F80039C)($s0)
    beqz       $t0, 3f
     add       $t3, $t0, -0x1
    lh         $s3, 0x0($a3)
    addiu      $a3, 0x2
    add        $t1, $s3
    beqz       $s3, 2b
     sh        $t1, %lo(0x1F80039E)($s0)
    srlv       $t2, $s6, $t3
    and        $t2, 0x1
    lh         $gp, %lo(0x1F800392)($s0)
    beqz       $t2, 4f
     nop
    addiu      $gp, 0x480
    j          5f
     sll       $gp, 16
  3:
    lhu        $s3, 0x2($a1)
    lh         $gp, %lo(0x1F800392)($s0)
    sub        $s3, $t1
    beqz       $s3, 10f
  4:
     sll       $gp, 16
  5:
    lw         $t3, 0x4($s2)
  6:
    lw         $t7, 0x8($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t7, 16
    add        $t0, $fp
    nclip
    lw         $t0, 0x0($t0)
    add        $t1, $fp
    mfc2       $v0, $24
    add        $t2, $fp
    bgtz       $v0, 7f
     addiu     $s3, -0x1
    beqz       $s3, 1b
     addiu     $s2, 0x10
    j          6b
     lw        $t3, 0x4($s2)
  7:
    beqz       $t9, 8f
     li        $v1, 0x24000000
    li         $v1, 0x26000000
  8:
    or         $v1, $a2
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    ldsz3      $t0, $t1, $t2
    lw         $t3, 0xC($s2)
    sw         $v1, 0x4($s1)
    avsz3
    sw         $t4, 0x8($s1)
    srl        $t1, $t3, 16
    or         $t1, $ra
    or         $t1, $t9
    and        $t0, $t3, 0xFFFF
    or         $t0, $gp
    mfc2       $v0, $7
    sw         $t0, 0xC($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 9f
     sw        $t5, 0x10($s1)
    sw         $t1, 0x14($s1)
    sll        $v0, 2
    sw         $t6, 0x18($s1)
    add        $v0, $s7, $v0
    sw         $t7, 0x1C($s1)
    lw         $t2, 0x0($v0)
    and        $t1, $s1, $s4
    and        $t0, $t2, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  9:
    beqz       $s3, 1b
     addiu     $s2, 0x10
    j          6b
     lw        $t3, 0x4($s2)
  10:
    or         $t0, $zero, 0x9
    sw         $t0, %lo(0x1F80039C)($s0)
    lhu        $s3, 0x4($a1)
    li         $t8, 0x9000000
    beqz       $s3, 20f
     addiu     $a3, 0x10
    addiu      $a3, -0x10
  11:
    lw         $t0, %lo(0x1F80039C)($s0)
    nop
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
  12:
    add        $t0, -0x1
    bltz       $t0, 20f
     sh        $t0, %lo(0x1F80039C)($s0)
    beqz       $t0, 13f
     add       $t3, $t0, -0x1
    lh         $s3, 0x0($a3)
    addiu      $a3, 0x2
    add        $t1, $s3
    beqz       $s3, 12b
     sh        $t1, %lo(0x1F80039E)($s0)
    srlv       $t2, $s6, $t3
    and        $t2, 0x1
    lh         $gp, %lo(0x1F800392)($s0)
    beqz       $t2, 14f
     nop
    addiu      $gp, 0x480
    j          15f
     sll       $gp, 16
  13:
    lhu        $s3, 0x4($a1)
    lh         $gp, %lo(0x1F800392)($s0)
    sub        $s3, $t1
    beqz       $s3, 20f
  14:
     sll       $gp, 16
  15:
    lw         $t3, 0x4($s2)
  16:
    lw         $t7, 0x8($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    nclip
    add        $t0, $fp
    add        $t1, $fp
    add        $t2, $fp
    lw         $t0, 0x0($t0)
    mfc2       $v0, $24
    add        $t3, $fp
    bgtz       $v0, 17f
     addiu     $s3, -0x1
    beqz       $s3, 11b
     addiu     $s2, 0x14
    j          16b
     lw        $t3, 0x4($s2)
  17:
    beqz       $t9, 18f
     li        $v1, 0x2C000000
    li         $v1, 0x2E000000
  18:
    or         $v1, $a2
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    add        $v0, $t0, $t1
    lw         $t3, 0x0($t3)
    add        $v0, $t2
    add        $v0, $t3
    srl        $v0, 4
    sltiu      $t1, $v0, 0x7C0
    beqz       $t1, 19f
     lw        $t7, 0x0($t7)
    lw         $t0, 0xC($s2)
    lw         $t2, 0x10($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    or         $t1, $t9
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $t5, 0x10($s1)
    sw         $t1, 0x14($s1)
    srl        $t3, $t2, 16
    sw         $t6, 0x18($s1)
    sw         $t2, 0x1C($s1)
    sll        $v0, 2
    sw         $t7, 0x20($s1)
    add        $v0, $s7, $v0
    sw         $t3, 0x24($s1)
    lw         $t2, 0x0($v0)
    and        $t1, $s1, $s4
    and        $t0, $t2, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  19:
    beqz       $s3, 11b
     addiu     $s2, 0x14
    j          16b
     lw        $t3, 0x4($s2)
  20:
    or         $t0, $zero, 0x9
    sw         $t0, %lo(0x1F80039C)($s0)
    sw         $a1, %lo(0x1F8003A0)($s0)
    lhu        $s3, 0x6($a1)
    add        $s7, -0x10
    beqz       $s3, 45f
     or        $a1, $fp, $zero
  21:
    lui        $s0, %hi(0x1F800392)
    lw         $t0, %lo(0x1F80039C)($s0)
    lw         $t4, %lo(0x1F8003A0)($s0)
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
  22:
    add        $t0, -0x1
    bltz       $t0, 45f
     sh        $t0, %lo(0x1F80039C)($s0)
    beqz       $t0, 23f
     add       $t3, $t0, -0x1
    lhu        $s3, 0x0($a3)
    addiu      $a3, 0x2
    add        $t1, $s3
    beqz       $s3, 22b
     sh        $t1, %lo(0x1F80039E)($s0)
    lbu        $s6, 0x64($t4)
    nop
    srlv       $t2, $s6, $t3
    and        $t2, 0x1
    lhu        $gp, %lo(0x1F800392)($s0)
    beqz       $t2, 24f
     nop
    addiu      $gp, 0x480
    j          25f
     sll       $gp, 16
  23:
    lhu        $s3, 0x6($t4)
    lhu        $gp, %lo(0x1F800392)($s0)
    sub        $s3, $t1
    beqz       $s3, 45f
  24:
     sll       $gp, 16
  25:
    lw         $fp, 0x0($s2)
  26:
    lw         $t3, 0x4($s2)
    srl        $v1, $fp, 16
    and        $v0, $v1, 0x1
    lw         $t7, 0x8($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    bnez       $v0, 27f
     lw        $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    or         $s0, $t3, $zero
    nclip
    add        $t7, $a0, $t3
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    and        $t8, $fp, 0xFF
    srl        $v1, $fp, 8
    mfc2       $v0, $24
    and        $v1, 0xFF
    bgtz       $v0, 28f
     addiu     $s3, -0x1
    beqz       $s3, 21b
     add       $s2, $v1
    j          26b
     lw        $fp, 0x0($s2)
  27:
    addiu      $s3, -0x1
    srl        $t3, $t7, 16
    or         $s0, $t3, $zero
    add        $t7, $a0, $t3
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    and        $v1, 0x2
    bnez       $v1, 34f
     and       $t8, $fp, 0xFF
  28:
    lw         $t0, 0x0($t0)
    or         $v0, $zero, 0x2C
    lw         $t1, 0x0($t1)
    beq        $t8, $v0, 31f
     lw        $t2, 0x0($t2)
    beqz       $t9, 29f
     lui       $v1, (0xFF0FFFFF >> 16)
    or         $v1, (0xFF0FFFFF & 0xFFFF)
    and        $fp, $v1
    li         $v1, 0x100000
    or         $fp, $v1
    or         $fp, $t9
  29:
    ldsz3      $t0, $t1, $t2
    srl        $t2, $fp, 20
    and        $t2, 0x1
    sll        $t2, 25
    li         $v1, 0x24000000
    or         $v1, $t2
    or         $v1, $a2
    avsz3
    srl        $t2, $fp, 16
    and        $t2, 0x60
    sll        $t2, 16
    lw         $t0, 0xC($s2)
    sw         $v1, 0x4($s1)
    srl        $t1, $t0, 16
    or         $t1, $ra
    or         $t1, $t2
    and        $t0, 0xFFFF
    mfc2       $v0, $7
    or         $t0, $gp
    sltiu      $t8, $v0, 0x7C0
    beqz       $t8, 30f
     sw        $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $t5, 0x10($s1)
    srl        $v1, $fp, 18
    sw         $t1, 0x14($s1)
    and        $v1, 0x3
    sw         $t6, 0x18($s1)
    sll        $v1, 2
    sw         $s0, 0x1C($s1)
    add        $v0, $v1
    sll        $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  30:
    beqz       $s3, 21b
     addiu     $s2, 0x10
    j          26b
     lw        $fp, 0x0($s2)
  31:
    beqz       $t9, 32f
     lui       $v1, (0xFF0FFFFF >> 16)
    or         $v1, (0xFF0FFFFF & 0xFFFF)
    and        $fp, $v1
    li         $v1, 0x100000
    or         $fp, $v1
    or         $fp, $t9
  32:
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    lw         $t7, 0x0($t7)
    add        $v0, $t2
    add        $v0, $t3
    srl        $v0, 4
    sltiu      $t8, $v0, 0x7C0
    beqz       $t8, 33f
     lw        $t0, 0xC($s2)
    lw         $t2, 0x10($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    srl        $t8, $fp, 20
    and        $t8, 0x1
    sll        $t8, 25
    li         $v1, 0x2C000000
    or         $v1, $t8
    or         $v1, $a2
    sw         $v1, 0x4($s1)
    and        $t0, 0xFFFF
    sw         $t4, 0x8($s1)
    or         $t0, $gp
    sw         $t0, 0xC($s1)
    srl        $t8, $fp, 16
    and        $t8, 0x60
    sll        $t8, 16
    sw         $t5, 0x10($s1)
    or         $t1, $t8
    sw         $t1, 0x14($s1)
    srl        $t3, $t2, 16
    sw         $t6, 0x18($s1)
    sw         $t2, 0x1C($s1)
    srl        $v1, $fp, 18
    sw         $t7, 0x20($s1)
    and        $v1, 0x3
    sw         $t3, 0x24($s1)
    sll        $v1, 2
    add        $v0, $v1
    sll        $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x9000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  33:
    beqz       $s3, 21b
     addiu     $s2, 0x14
    j          26b
     lw        $fp, 0x0($s2)
  34:
    lw         $t0, 0x0($t0)
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    sll        $v0, $t4, 16
    sll        $v1, $t6, 16
    sra        $v0, 16
    sra        $v1, 16
    subu       $t8, $v1, $v0
    ctc2       $t8, $0
    sra        $s0, $t4, 16
    sra        $v1, $t6, 16
    subu       $t8, $v1, $s0
    ctc2       $t8, $2
    subu       $s0, $t2, $t0
    ctc2       $s0, $4
    subu       $s0, $t1, $t0
    mtc2       $s0, $11
    sll        $v1, $t5, 16
    sra        $v1, 16
    subu       $t8, $v1, $v0
    mtc2       $t8, $9
    sra        $s0, $t4, 16
    sra        $v1, $t5, 16
    subu       $t8, $v1, $s0
    mtc2       $t8, $10
    nop
    op0
    lw         $t7, 0x0($t7)
    mfc2       $s6, $25
    sll        $v1, $t7, 16
    sra        $v1, 16
    subu       $t8, $v1, $v0
    multu      $t8, $s6
    sra        $v1, $t7, 16
    mflo       $t8
    mfc2       $v0, $26
    subu       $s6, $v1, $s0
    multu      $s6, $v0
    lw         $t3, 0x0($t3)
    mflo       $s6
    mfc2       $v0, $27
    subu       $v1, $t3, $t0
    multu      $v0, $v1
    add        $t8, $s6
    mtc2       $t4, $12
    mtc2       $t5, $13
    mflo       $v0
    add        $v0, $t8, $v0
    negu       $v0, $v0
    bgtz       $v0, 40f
     nop
    mtc2       $t7, $14
    mtc2       $t0, $17
    mtc2       $t1, $18
    nclip
    mtc2       $t3, $19
    lw         $t0, 0xC($s2)
    lw         $s6, 0x10($s2)
    srl        $t1, $t0, 16
    mfc2       $v0, $24
    and        $t0, 0xFFFF
    blez       $v0, 36f
     or        $t0, $gp
    avsz3
    beqz       $t9, 35f
     li        $v1, 0x24000000
    li         $v1, 0x26000000
  35:
    or         $v1, $a2
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    mfc2       $v0, $7
    sw         $t5, 0x10($s1)
    sltiu      $t8, $v0, 0x7C0
    beqz       $t8, 36f
     or        $t1, $ra
    or         $t1, $t9
    sw         $t1, 0x14($s1)
    srl        $t3, $s6, 16
    sw         $t7, 0x18($s1)
    sw         $t3, 0x1C($s1)
    addiu      $v0, 0x4
    sll        $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $s0, $v1, $s4
    or         $s0, $t8
    sw         $s0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $s0, $v1, $s5
    or         $s0, $t1
    sw         $s0, 0x0($v0)
    addiu      $s1, 0x20
  36:
    mtc2       $t7, $13
    mtc2       $t6, $14
    mtc2       $t2, $18
    li         $v1, 0x24000000
    nclip
    beqz       $t9, 37f
     li        $v1, 0x24000000
    li         $v1, 0x26000000
  37:
    or         $v1, $a2
    srl        $t3, $s6, 16
    or         $t3, $ra
    or         $t3, $t9
    sw         $v1, 0x4($s1)
    mfc2       $v0, $24
    sw         $t4, 0x8($s1)
    blez       $v0, 38f
     sw        $t0, 0xC($s1)
    avsz3
    sw         $t7, 0x10($s1)
    sw         $t3, 0x14($s1)
    sw         $t6, 0x18($s1)
    mfc2       $v0, $7
    sw         $s6, 0x1C($s1)
    sltiu      $t8, $v0, 0x7C0
    beqz       $t8, 39f
     addiu     $v0, 0x4
    sll        $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
  38:
    addiu      $s1, 0x20
  39:
    beqz       $s3, 21b
     addiu     $s2, 0x14
    j          26b
     lw        $fp, 0x0($s2)
  40:
    mtc2       $t6, $14
    mtc2       $t0, $17
    mtc2       $t1, $18
    nclip
    mtc2       $t2, $19
    lw         $t0, 0xC($s2)
    lw         $s6, 0x10($s2)
    srl        $t1, $t0, 16
    mfc2       $v0, $24
    beqz       $t9, 41f
     li        $v1, 0x24000000
    li         $v1, 0x26000000
  41:
    blez       $v0, 42f
     or        $v1, $a2
    avsz3
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $t0, 0xC($s1)
    mfc2       $v0, $7
    sw         $t5, 0x10($s1)
    sltiu      $t8, $v0, 0x7C0
    beqz       $t8, 42f
     or        $t1, $ra
    or         $t1, $t9
    sw         $t1, 0x14($s1)
    addiu      $v0, 0x4
    sw         $t6, 0x18($s1)
    sll        $v0, 2
    sw         $s6, 0x1C($s1)
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $s0, $v1, $s4
    or         $s0, $t8
    sw         $s0, 0x0($s1)
    and        $t0, $s1, $s4
    and        $s0, $v1, $s5
    or         $s0, $t0
    sw         $s0, 0x0($v0)
    addiu      $s1, 0x20
  42:
    ldsxy3     $t5, $t7, $t6
    mtc2       $t3, $17
    beqz       $t9, 43f
     li        $v1, 0x24000000
    li         $v1, 0x26000000
  43:
    nclip
    or         $v1, $a2
    sw         $v1, 0x4($s1)
    and        $t1, 0xFFFF
    or         $t1, $gp
    mfc2       $v0, $24
    srl        $t3, $s6, 16
    blez       $v0, 44f
     or        $t3, $ra
    or         $t3, $t9
    avsz3
    sw         $t5, 0x8($s1)
    sw         $t1, 0xC($s1)
    sw         $t7, 0x10($s1)
    sw         $t3, 0x14($s1)
    mfc2       $v0, $7
    sw         $t6, 0x18($s1)
    sltiu      $t8, $v0, 0x7C0
    beqz       $t8, 44f
     addiu     $v0, 0x4
    sw         $s6, 0x1C($s1)
    sll        $v0, 2
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x7000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x20
  44:
    beqz       $s3, 21b
     addiu     $s2, 0x14
    j          26b
     lw        $fp, 0x0($s2)
  45:
    lui        $t0, %hi(0x1F800380)
    sw         $s1, %lo(0x1F800000)($t0)
    lw         $s0, %lo(0x1F800358)($t0)
    lw         $s1, %lo(0x1F80035C)($t0)
    lw         $s2, %lo(0x1F800360)($t0)
    lw         $s3, %lo(0x1F800364)($t0)
    lw         $s4, %lo(0x1F800368)($t0)
    lw         $s5, %lo(0x1F80036C)($t0)
    lw         $s6, %lo(0x1F800370)($t0)
    lw         $s7, %lo(0x1F800374)($t0)
    lw         $ra, %lo(0x1F800378)($t0)
    lw         $gp, %lo(0x1F80037C)($t0)
    jr         $ra
     lw        $fp, %lo(0x1F800380)($t0)
endlabel func_800B516C

nonmatching func_800B5C30, 0x77C

glabel func_800B5C30
    lui        $t0, %hi(0x1F800390)
    sw         $s0, %lo(0x1F800358)($t0)
    sw         $s1, %lo(0x1F80035C)($t0)
    sw         $s2, %lo(0x1F800360)($t0)
    sw         $s3, %lo(0x1F800364)($t0)
    sw         $s4, %lo(0x1F800368)($t0)
    sw         $s5, %lo(0x1F80036C)($t0)
    sw         $s6, %lo(0x1F800370)($t0)
    sw         $s7, %lo(0x1F800374)($t0)
    sw         $ra, %lo(0x1F800378)($t0)
    sw         $gp, %lo(0x1F80037C)($t0)
    sw         $fp, %lo(0x1F800380)($t0)
    lw         $gp, %lo(0x1F800390)($t0)
    li         $s4, 0xFFFFFF
    sll        $ra, $gp, 16
    srl        $gp, 16
    sll        $gp, 16
    li         $s5, 0xFF000000
    lui        $s0, %hi(0x1F800392)
    lhu        $s3, 0x2($a1)
    lw         $s2, 0x3C($a3)
    addiu      $fp, $a0, 0xC00
    lw         $s1, %lo(0x1F800000)($s0)
    lw         $s7, %lo(0x1F800004)($s0)
    lw         $a2, 0x0($a2)
    add        $s7, -0x4
    lbu        $s6, 0x64($a1)
    lbu        $v1, 0x9($a1)
    and        $a2, $s4
    and        $v1, 0xF
    beqz       $v1, 0f
     or        $t9, $zero, $zero
    slt        $v1, 0x7
    bnez       $v1, 0f
     li        $t9, 0x400000
    li         $t9, 0x200000
  0:
    or         $t0, $zero, 0x9
    sw         $t0, %lo(0x1F80039C)($s0)
    beqz       $s3, 11f
     li        $t8, 0x9000000
  1:
    lw         $t0, %lo(0x1F80039C)($s0)
    nop
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
  2:
    add        $t0, -0x1
    bltz       $t0, 11f
     sh        $t0, %lo(0x1F80039C)($s0)
    beqz       $t0, 3f
     add       $t3, $t0, -0x1
    lh         $s3, 0x0($a3)
    addiu      $a3, 0x2
    add        $t1, $s3
    beqz       $s3, 2b
     sh        $t1, %lo(0x1F80039E)($s0)
    srlv       $t2, $s6, $t3
    and        $t2, 0x1
    lh         $gp, %lo(0x1F800392)($s0)
    beqz       $t2, 4f
     nop
    addiu      $gp, 0x480
    j          5f
     sll       $gp, 16
  3:
    lhu        $s3, 0x2($a1)
    lh         $gp, %lo(0x1F800392)($s0)
    sub        $s3, $t1
    beqz       $s3, 11f
  4:
     sll       $gp, 16
  5:
    beqz       $s3, 11f
     li        $t8, 0x9000000
    lw         $t3, 0x0($s2)
  6:
    lw         $t7, 0x4($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t7, 16
    add        $t0, $fp
    nclip
    lw         $v1, 0x8($s2)
    add        $t1, $fp
    mfc2       $v0, $24
    add        $t2, $fp
    bgtz       $v0, 7f
     addiu     $s3, -0x1
    beqz       $s3, 1b
     addiu     $s2, 0x18
    j          6b
     lw        $t3, 0x0($s2)
  7:
    lw         $t0, 0x0($t0)
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    ldsz3      $t0, $t1, $t2
    beqz       $t9, 8f
     li        $t3, 0x36000000
    or         $v1, $a2, $t3
    or         $t0, $zero, $a2
    j          9f
     or        $t1, $zero, $a2
  8:
    lw         $t0, 0xC($s2)
    lw         $t1, 0x10($s2)
  9:
    avsz3
    lw         $t3, 0x14($s2)
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    srl        $v1, $t3, 16
    or         $v1, $ra
    or         $v1, $t9
    and        $v0, $t3, 0xFFFF
    or         $v0, $gp
    sw         $v0, 0xC($s1)
    mfc2       $v0, $7
    sw         $t0, 0x10($s1)
    sltiu      $t0, $v0, 0x7C0
    beqz       $t0, 10f
     sw        $t5, 0x14($s1)
    sll        $v0, 2
    sw         $v1, 0x18($s1)
    add        $v0, $s7, $v0
    sw         $t1, 0x1C($s1)
    lw         $t2, 0x0($v0)
    sw         $t6, 0x20($s1)
    and        $t1, $s1, $s4
    sw         $t7, 0x24($s1)
    and        $t0, $t2, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $t2, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  10:
    beqz       $s3, 1b
     addiu     $s2, 0x18
    j          6b
     lw        $t3, 0x0($s2)
  11:
    or         $t0, $zero, 0x9
    sw         $t0, %lo(0x1F80039C)($s0)
    lhu        $s3, 0x4($a1)
    li         $t8, 0xC000000
    beqz       $s3, 22f
  12:
     lui       $s0, %hi(0x1F800392)
    lw         $t0, %lo(0x1F80039C)($s0)
    nop
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
  13:
    add        $t0, -0x1
    bltz       $t0, 22f
     sh        $t0, %lo(0x1F80039C)($s0)
    beqz       $t0, 14f
     add       $t3, $t0, -0x1
    lh         $s3, 0x0($a3)
    lbu        $s6, 0x64($a1)
    addiu      $a3, 0x2
    add        $t1, $s3
    beqz       $s3, 13b
     sh        $t1, %lo(0x1F80039E)($s0)
    srlv       $t2, $s6, $t3
    and        $t2, 0x1
    lh         $gp, %lo(0x1F800392)($s0)
    beqz       $t2, 15f
     nop
    addiu      $gp, 0x480
    j          16f
     sll       $gp, 16
  14:
    lhu        $s3, 0x4($a1)
    lh         $gp, %lo(0x1F800392)($s0)
    sub        $s3, $t1
    beqz       $s3, 22f
  15:
     sll       $gp, 16
  16:
    lw         $t3, 0x0($s2)
  17:
    lw         $t7, 0x4($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    lw         $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    nclip
    add        $t0, $fp
    add        $t1, $fp
    add        $t2, $fp
    lw         $v1, 0x8($s2)
    mfc2       $v0, $24
    add        $t3, $fp
    bgtz       $v0, 18f
     addiu     $s3, -0x1
    beqz       $s3, 12b
     addiu     $s2, 0x20
    j          17b
     lw        $t3, 0x0($s2)
  18:
    lw         $t0, 0x0($t0)
    lw         $t1, 0x0($t1)
    lw         $t2, 0x0($t2)
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    add        $v0, $t2
    add        $v0, $t3
    srl        $v0, 4
    sltiu      $s0, $v0, 0x7C0
    beqz       $s0, 21f
     lw        $t7, 0x0($t7)
    beqz       $t9, 19f
     li        $t3, 0x3E000000
    or         $v1, $a2, $t3
    or         $s0, $zero, $a2
    or         $s6, $zero, $a2
    j          20f
     or        $t3, $zero, $a2
  19:
    lw         $s0, 0xC($s2)
    lw         $s6, 0x10($s2)
    lw         $t3, 0x14($s2)
  20:
    lw         $t0, 0x18($s2)
    lw         $t2, 0x1C($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    or         $t1, $t9
    and        $t0, 0xFFFF
    or         $t0, $gp
    sw         $v1, 0x4($s1)
    sw         $t4, 0x8($s1)
    sw         $t0, 0xC($s1)
    sw         $s0, 0x10($s1)
    sw         $t5, 0x14($s1)
    srl        $v1, $t2, 16
    sw         $t1, 0x18($s1)
    sw         $s6, 0x1C($s1)
    sll        $v0, 2
    sw         $t6, 0x20($s1)
    add        $v0, $s7, $v0
    sw         $t2, 0x24($s1)
    lw         $s0, 0x0($v0)
    sw         $t3, 0x28($s1)
    and        $t1, $s1, $s4
    sw         $t7, 0x2C($s1)
    and        $t0, $s0, $s4
    sw         $v1, 0x30($s1)
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t0, $s0, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x34
  21:
    beqz       $s3, 12b
     addiu     $s2, 0x20
    j          17b
     lw        $t3, 0x0($s2)
  22:
    or         $t0, $zero, 0x9
    sw         $t0, %lo(0x1F80039C)($s0)
    sw         $a1, %lo(0x1F8003A0)($s0)
    lhu        $s3, 0x6($a1)
    add        $s7, -0x10
    beqz       $s3, 38f
     or        $a1, $fp, $zero
  23:
    lui        $s0, %hi(0x1F800392)
    lw         $t0, %lo(0x1F80039C)($s0)
    lw         $t4, %lo(0x1F8003A0)($s0)
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
  24:
    add        $t0, -0x1
    bltz       $t0, 38f
     sh        $t0, %lo(0x1F80039C)($s0)
    beqz       $t0, 25f
     add       $t3, $t0, -0x1
    lhu        $s3, 0x0($a3)
    addiu      $a3, 0x2
    add        $t1, $s3
    beqz       $s3, 24b
     sh        $t1, %lo(0x1F80039E)($s0)
    lbu        $s6, 0x64($t4)
    nop
    srlv       $t2, $s6, $t3
    and        $t2, 0x1
    lhu        $gp, %lo(0x1F800392)($s0)
    beqz       $t2, 26f
     nop
    addiu      $gp, 0x480
    j          27f
     sll       $gp, 16
  25:
    lhu        $s3, 0x6($t4)
    lhu        $gp, %lo(0x1F800392)($s0)
    sub        $s3, $t1
    beqz       $s3, 38f
  26:
     sll       $gp, 16
  27:
    lw         $fp, 0x10($s2)
  28:
    lw         $t3, 0x0($s2)
    srl        $v1, $fp, 24
    and        $v0, $v1, 0x1
    lw         $t7, 0x4($s2)
    and        $t0, $t3, 0xFFFF
    srl        $t1, $t3, 16
    and        $t2, $t7, 0xFFFF
    add        $t4, $t0, $a0
    lw         $t4, 0x0($t4)
    add        $t5, $t1, $a0
    lw         $t5, 0x0($t5)
    add        $t6, $t2, $a0
    bnez       $v0, 29f
     lw        $t6, 0x0($t6)
    ldsxy3     $t4, $t5, $t6
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    nclip
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    lw         $t8, 0x8($s2)
    lw         $s0, 0xC($s2)
    mfc2       $v0, $24
    srl        $s0, 24
    bgtz       $v0, 30f
     addiu     $s3, -0x1
    beqz       $s3, 23b
     add       $s2, $s0
    j          28b
     lw        $fp, 0x0($s2)
  29:
    addiu      $s3, -0x1
    srl        $t3, $t7, 16
    add        $t7, $a0, $t3
    add        $t0, $a1
    add        $t1, $a1
    add        $t2, $a1
    add        $t3, $a1
    lw         $t8, 0x8($s2)
    nop
  30:
    srl        $s0, $t8, 24
    lw         $t0, 0x0($t0)
    or         $v0, $zero, 0x3C
    lw         $t1, 0x0($t1)
    beq        $s0, $v0, 34f
     lw        $t2, 0x0($t2)
    ldsz3      $t0, $t1, $t2
    beqz       $t9, 31f
     li        $v1, 0x36000000
    lw         $t1, 0x10($s2)
    or         $t8, $a2, $v1
    or         $t0, $zero, $a2
    and        $t1, $s5
    j          32f
     or        $t1, $a2
  31:
    lw         $t0, 0xC($s2)
    lw         $t1, 0x10($s2)
  32:
    avsz3
    sw         $t8, 0x4($s1)
    lw         $t3, 0x14($s2)
    lw         $t8, 0x4($s2)
    srl        $t2, $t3, 16
    srl        $t8, 16
    or         $t2, $ra
    or         $t2, $t9
    and        $t7, $t3, 0xFFFF
    mfc2       $v0, $7
    sw         $t4, 0x8($s1)
    sltiu      $t4, $v0, 0x7C0
    beqz       $t4, 33f
     or        $t7, $gp
    sw         $t7, 0xC($s1)
    sw         $t0, 0x10($s1)
    srl        $v1, $t1, 26
    sw         $t5, 0x14($s1)
    and        $v1, 0x3
    sw         $t2, 0x18($s1)
    sll        $v1, 2
    sw         $t1, 0x1C($s1)
    add        $v0, $v1
    sw         $t6, 0x20($s1)
    sll        $v0, 2
    sw         $t8, 0x24($s1)
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0x9000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x28
  33:
    beqz       $s3, 23b
     addiu     $s2, 0x18
    j          28b
     lw        $fp, 0x10($s2)
  34:
    lw         $t3, 0x0($t3)
    add        $v0, $t0, $t1
    lw         $t7, 0x0($t7)
    add        $v0, $t2
    add        $v0, $t3
    srl        $v0, 4
    sltiu      $s0, $v0, 0x7C0
    beqz       $s0, 37f
     li        $v1, 0x3E000000
    beqz       $t9, 35f
     or        $s6, $zero, $a2
    lw         $s0, 0x10($s2)
    or         $t8, $a2, $v1
    or         $v1, $zero, $a2
    and        $s0, $s5
    j          36f
     or        $s0, $a2
  35:
    lw         $v1, 0xC($s2)
    lw         $s0, 0x10($s2)
    lw         $s6, 0x14($s2)
  36:
    lw         $t0, 0x18($s2)
    lw         $t2, 0x1C($s2)
    srl        $t1, $t0, 16
    or         $t1, $ra
    or         $t1, $t9
    sw         $t8, 0x4($s1)
    and        $t0, 0xFFFF
    sw         $t4, 0x8($s1)
    or         $t0, $gp
    sw         $t0, 0xC($s1)
    sw         $v1, 0x10($s1)
    srl        $t3, $t2, 16
    sw         $t5, 0x14($s1)
    sw         $t1, 0x18($s1)
    srl        $v1, $s0, 26
    sw         $s0, 0x1C($s1)
    and        $v1, 0x3
    sw         $t6, 0x20($s1)
    sll        $v1, 2
    sw         $t2, 0x24($s1)
    add        $v0, $v1
    sw         $s6, 0x28($s1)
    sw         $t7, 0x2C($s1)
    sll        $v0, 2
    sw         $t3, 0x30($s1)
    add        $v0, $s7, $v0
    lw         $v1, 0x0($v0)
    li         $t8, 0xC000000
    and        $t0, $v1, $s4
    or         $t0, $t8
    sw         $t0, 0x0($s1)
    and        $t1, $s1, $s4
    and        $t0, $v1, $s5
    or         $t0, $t1
    sw         $t0, 0x0($v0)
    addiu      $s1, 0x34
  37:
    beqz       $s3, 23b
     addiu     $s2, 0x20
    j          28b
     lw        $fp, 0x10($s2)
  38:
    lui        $t0, %hi(0x1F800380)
    sw         $s1, %lo(0x1F800000)($t0)
    lw         $s0, %lo(0x1F800358)($t0)
    lw         $s1, %lo(0x1F80035C)($t0)
    lw         $s2, %lo(0x1F800360)($t0)
    lw         $s3, %lo(0x1F800364)($t0)
    lw         $s4, %lo(0x1F800368)($t0)
    lw         $s5, %lo(0x1F80036C)($t0)
    lw         $s6, %lo(0x1F800370)($t0)
    lw         $s7, %lo(0x1F800374)($t0)
    lw         $ra, %lo(0x1F800378)($t0)
    lw         $gp, %lo(0x1F80037C)($t0)
    jr         $ra
     lw        $fp, %lo(0x1F800380)($t0)
endlabel func_800B5C30

nonmatching func_800B63AC, 0x58

glabel func_800B63AC
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    nop
    lb         $v1, 0xA($v0)
    lb         $t1, 0x5B0($v0)
    and        $t0, $v1, 0x40
    bnez       $t0, .L800B6424
     and       $t0, $v1, 0x20
    bnez       $t0, .L800B6454
     and       $t1, 0xFC
    or         $t1, 0x1
    sb         $t1, 0x5B0($v0)
  .L800B63E8:
    addiu      $sp, -0x4
    sw         $ra, 0x0($sp)
    jal        func_800A208C
     addu      $a0, $v0, $zero
    lw         $ra, 0x0($sp)
    addiu      $sp, 0x4
    jr         $ra
endlabel func_800B63AC

nonmatching func_800B6404, 0x34

glabel func_800B6404
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    nop
    lb         $v1, 0xA($v0)
    nop
  .L800B6424:
    and        $v1, 0x9F
    or         $v1, 0x40
    sb         $v1, 0xA($v0)
    j          .L800B63E8
     nop
endlabel func_800B6404

nonmatching func_800B6438, 0x70

glabel func_800B6438
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    nop
    lb         $v1, 0xA($v0)
  .L800B6454:
    addiu      $sp, -0x14
    sw         $v0, 0x0($sp)
    sw         $a1, 0x4($sp)
    sw         $a2, 0x8($sp)
    sw         $a3, 0xC($sp)
    sw         $ra, 0x10($sp)
    or         $v1, 0x60
    sb         $v1, 0xA($v0)
    or         $a1, $zero, 0x1F
    addu       $a2, $zero, $zero
    jal        func_800A0204
     or        $a3, $zero, 0x8
    lw         $a0, 0x0($sp)
    lw         $a1, 0x4($sp)
    lw         $a2, 0x8($sp)
    jal        func_800A208C
     lw        $a3, 0xC($sp)
    lw         $ra, 0x10($sp)
    addiu      $sp, 0x14
    jr         $ra
     nop
endlabel func_800B6438

nonmatching func_800B64A8, 0x24

glabel func_800B64A8
    addiu      $sp, -0x4
    sw         $ra, 0x0($sp)
    jal        func_800B64CC
     addu      $a3, $a1, $zero
    or         $v1, $zero, 0x0
    sb         $v1, 0x1848($v0)
    lw         $ra, 0x0($sp)
    addiu      $sp, 0x4
    jr         $ra
endlabel func_800B64A8

nonmatching func_800B64CC, 0x34

glabel func_800B64CC
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    or         $v1, $zero, 0x1
    sll        $t0, $a3, 16
    or         $t0, $a1
    sw         $t0, 0x184C($v0)
    sw         $a2, 0x1850($v0)
  .L800B64F4:
    sw         $v1, 0x1848($v0)
    jr         $ra
     nop
endlabel func_800B64CC

nonmatching func_800B6500, 0x30

glabel func_800B6500
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    lw         $t2, 0x0($a1)
    lw         $t3, 0x4($a1)
    sw         $t2, 0x1858($v0)
    sw         $t3, 0x185C($v0)
    lb         $t1, 0xA($v0)
    j          .L800B64F4
     or        $v1, $zero, 0x2
endlabel func_800B6500

nonmatching func_800B6530, 0xC

glabel func_800B6530
    or         $t4, $zero, 0x4
    j          .L800B6540
     addu      $a3, $a2, $zero
endlabel func_800B6530

nonmatching func_800B653C, 0x44

glabel func_800B653C
    or         $t4, $zero, 0x3
  .L800B6540:
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    lw         $t2, 0x0($a1)
    lw         $t3, 0x4($a1)
    sw         $a2, 0x1850($v0)
    lb         $t1, 0xA($v0)
    sh         $a3, 0x184E($v0)
    sw         $t2, 0x1858($v0)
    sw         $t3, 0x185C($v0)
    or         $t1, 0x20
    sb         $t1, 0xA($v0)
    sw         $t4, 0x1848($v0)
    jr         $ra
endlabel func_800B653C

nonmatching func_800B6580, 0x68

glabel func_800B6580
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    lw         $t2, 0x0($a1)
    lb         $t1, 0xB($v0)
    sll        $t0, $a2, 16
    and        $t1, 0xF
    bnez       $t1, 0f
     or        $t1, 0x1
    lbu        $a0, 0x17FD($v0)
    sh         $zero, 0x1A($v0)
    sw         $t2, 0x5EC($v0)
    sw         $t0, 0x5F0($v0)
    sb         $t1, 0xB($v0)
    slt        $t3, $a0, 0x2
    bnez       $t3, 0f
     nop
    addiu      $sp, -0x4
    sw         $ra, 0x0($sp)
    jal        func_800B6580
     nop
    lw         $ra, 0x0($sp)
    addiu      $sp, 0x4
  0:
    jr         $ra
endlabel func_800B6580

nonmatching func_800B65E8, 0xC

glabel func_800B65E8
    or         $t1, $zero, 0x10
    j          .L800B65F8
     nop
endlabel func_800B65E8

nonmatching func_800B65F4, 0x40

glabel func_800B65F4
    or         $t1, $zero, 0x40
  .L800B65F8:
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    lw         $t2, 0x0($a1)
    lw         $t3, 0x4($a1)
    lb         $t4, 0xB($v0)
    sw         $t2, 0x5EC($v0)
    sw         $t3, 0x5F0($v0)
    sh         $a2, 0x5F2($v0)
    and        $t4, 0x8F
    or         $t1, $t4, $t1
    sb         $t1, 0xB($v0)
    jr         $ra
endlabel func_800B65F4

nonmatching func_800B6634, 0x58

glabel func_800B6634
    la         $v0, D_800F4538
    sll        $v1, $a0, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    addiu      $sp, -0xC
    lhu        $t0, 0x63C($v0)
    sw         $ra, 0x0($sp)
    or         $a2, $zero, 0x80
    sltiu      $t0, 0x80
    beqz       $t0, 0f
     sw        $a0, 0x4($sp)
    or         $a2, $zero, 0x20
  0:
    jal        func_800A9EB4
     sw        $a1, 0x8($sp)
  .L800B6670:
    lw         $a0, 0x4($sp)
    jal        func_800A249C
     lw        $a1, 0x8($sp)
    lw         $ra, 0x0($sp)
    addiu      $sp, 0xC
    jr         $ra
     nop
endlabel func_800B6634

nonmatching func_800B668C, 0x1C

glabel func_800B668C
    addiu      $sp, -0xC
    sw         $ra, 0x0($sp)
    sw         $a0, 0x4($sp)
    jal        func_800AA8D0
     sw        $a1, 0x8($sp)
    j          .L800B6670
     nop
endlabel func_800B668C
