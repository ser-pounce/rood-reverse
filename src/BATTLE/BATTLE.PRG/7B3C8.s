.include "macro.inc"

.set noat
.set noreorder

glabel func_800E3BC8
    lw         $t0, 0x168($a0)
    li         $t8, 0x3FFFFF
    lw         $t2, 0x34($a0)
    sll        $t1, $t0, 8
    srl        $t1, 24
    and        $t0, 0xFF
    sll        $t3, $t2, 8
    srl        $t3, 24
    and        $t2, 0xFF
    lw         $t9, 0x190($a0)
    slt        $v0, $t2, $t0
    slt        $v1, $t3, $t1
    bne        $t0, $t2, 0f
     add       $t0, $v0
    addu       $t0, $zero, $zero
  0:
    sll        $t0, 22
    bne        $t1, $t3, 1f
     add       $t1, $v1
    addu       $t1, $zero, $zero
  1:
    sll        $t1, 27
    and        $t9, $t8
    or         $t9, $t0
    or         $t9, $t1
    jr         $ra
     sw        $t9, 0x190($a0)
endlabel func_800E3BC8

glabel func_800E3C30
    lui        $v1, (0x800E3EAC >> 16)
    bgez       $zero, 0f
     or        $v1, (0x800E3EAC & 0xFFFF)
    lui        $v1, (0x800E3FF4 >> 16)
    bgez       $zero, 0f
     or        $v1, (0x800E3FF4 & 0xFFFF)
    lui        $v1, (0x800E40F0 >> 16)
    bgez       $zero, 0f
     or        $v1, (0x800E40F0 & 0xFFFF)
  0:
    lw         $t0, 0x34($a0)
    lw         $t2, 0x168($a0)
    sll        $t1, $t0, 8
    srl        $t1, 17
    and        $t0, 0xFF
    sll        $t0, 7
    sll        $t3, $t2, 8
    srl        $t3, 17
    and        $t2, 0xFF
    sll        $t2, 7
    sub        $t0, $t2, $t0
    sub        $t1, $t3, $t1
    mtc2       $t0, $9
    mtc2       $t1, $10
    lw         $t5, 0x4($a0)
    lui        $t4, (0x31000 >> 16)
    sqr        0
    mfc2       $t0, $25
    mfc2       $t1, $26
    or         $t4, (0x31000 & 0xFFFF)
    add        $t0, $t1
    slt        $t0, $t4
    and        $v0, $t0, $t5
    beqz       $v0, 1f
     mtc2      $ra, $0
    jalr       $v1
     mtc2      $a0, $2
    mfc2       $a0, $2
    jal        func_800E3BC8
     mtc2      $v0, $1
    mfc2       $ra, $0
    mfc2       $v0, $1
  1:
    jr         $ra
     nop
endlabel func_800E3C30

glabel func_800E3CDC
    lw         $t0, 0x194($a0)
    lui        $a3, (0xFF00FF >> 16)
    lw         $t1, 0x34($a0)
    or         $a3, (0xFF00FF & 0xFFFF)
    and        $t2, $t0, $a3
    lbu        $t4, 0x198($a0)
    and        $t3, $t1, $a3
    beq        $t2, $t3, 0f
     addu      $t4, 0x1
    addu       $t4, $zero, $zero
  0:
    slt        $v0, $t4, 0x5
    bnez       $v0, 1f
     li        $v1, 0x78
    sb         $v1, 0x19A($a0)
    addu       $t4, $zero, $zero
  1:
    sw         $t1, 0x194($a0)
    sb         $t4, 0x198($a0)
    sh         $zero, 0x156($a0)
    lbu        $a3, 0x23($a0)
    li         $a2, 0x7E
    bnez       $a3, 2f
     addu      $v0, $a2, $zero
    jal        func_800E45D4
     li        $a0, 0x4
    bnez       $v0, 2f
     addu      $v0, $a2, $zero
    srl        $v0, $a2, 2
  2:
    sll        $v0, 5
    add        $v1, $zero, -0xFE1
    and        $a1, $v1
    jr         $ra
     or        $v0, $a1, $v0
endlabel func_800E3CDC

glabel func_800E3D5C
    addu       $v1, $a1, $zero
    mtc2       $ra, $25
    mtc2       $a0, $12
    mtc2       $v1, $13
    jalr       $v1
     addu      $a1, $zero, $zero
    mtc2       $v0, $8
    mfc2       $v1, $13
    mfc2       $a0, $12
    jalr       $v1
     li        $a1, 0x2
    mtc2       $v0, $9
    mfc2       $v1, $13
    mfc2       $a0, $12
    jalr       $v1
     li        $a1, 0x4
    mtc2       $v0, $10
    mfc2       $v1, $13
    mfc2       $a0, $12
    jalr       $v1
     li        $a1, 0x6
    mfc2       $a0, $8
    mfc2       $a1, $9
    mfc2       $a2, $10
    sll        $a0, 3
    sll        $a1, 2
    sll        $a2, 1
    mfc2       $ra, $25
    or         $a0, $a1
    or         $a0, $a2
    jr         $ra
     or        $v0, $a0, $v0
endlabel func_800E3D5C

glabel func_800E3DDC
    lbu        $a3, 0x1($a0)
    addu       $sp, -0x10
    sw         $s0, 0x0($sp)
    sw         $s1, 0x4($sp)
    sw         $s2, 0x8($sp)
    sw         $ra, 0xC($sp)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    addu       $s2, $a2, $zero
    sb         $a3, 0x199($s0)
    lbu        $t0, 0x4($s0)
    and        $t1, $a1, 0xFE0
    slt        $t1, 0x1
    srl        $t2, $a1, 16
    and        $t2, 0x1
    or         $t1, $t2
    or         $t1, $t0
    beqz       $t1, 0f
     lui       $v0, (0xFFFEFFFF >> 16)
    or         $v0, (0xFFFEFFFF & 0xFFFF)
    and        $s1, $v0
    jal        func_800E45D4
     li        $a0, 0x2
    lbu        $a3, 0x89($s0)
    add        $v1, $zero, -0x11
    and        $s1, $v1
    sll        $v0, 4
    or         $s1, $v0
    addu       $a0, $s0, $zero
    li         $a1, 0x8
    jal        func_800E4180
     li        $a2, 0x1
  0:
    add        $v0, $zero, -0xFE1
    and        $v0, $s1, $v0
    bnez       $v0, 1f
     lui       $v1, (0xFFFDFFFF >> 16)
    or         $v1, (0xFFFDFFFF & 0xFFFF)
    and        $s1, $v1
  1:
    addu       $a1, $s2, $zero
    lw         $s2, 0x8($sp)
    jal        func_800E3D5C
     addu      $a0, $s0, $zero
    lw         $s0, 0x0($sp)
    li         $v1, 0xFFC30FFF
    and        $s1, $v1
    lw         $ra, 0xC($sp)
    sll        $v0, 18
    or         $v0, $s1, $v0
    lw         $s1, 0x4($sp)
    jr         $ra
     addu      $sp, 0x10
endlabel func_800E3DDC

glabel func_800E3EAC
    addu       $sp, -0x1C
    sw         $s0, 0x0($sp)
    sw         $s1, 0x4($sp)
    sw         $s2, 0x8($sp)
    sw         $s3, 0xC($sp)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    addu       $s2, $a2, $zero
    addu       $s3, $a3, $zero
    sw         $s4, 0x10($sp)
    lw         $a1, 0x190($s0)
    sw         $ra, 0x14($sp)
    sw         $s5, 0x18($sp)
    jal        func_800E3DDC
     addu      $a2, $a3, $zero
    addu       $s4, $v0, $zero
    sll        $t1, $s4, 27
    bltz       $t1, 0f
     add       $t0, $zero, 0x1
    add        $t0, $zero, -0x1
  0:
    sll        $t0, 1
    add        $t1, $s1, $t0
    addu       $s1, $t0, $zero
    and        $t1, 0x7
    bne        $t1, $s2, 1f
     add       $v0, $zero, 0x4
    addu       $v0, $t0, $zero
  1:
    add        $s5, $s2, $v0
    and        $s5, 0x7
    addu       $a1, $s5, $zero
    jalr       $s3
     addu      $a0, $s0, $zero
    bnez       $v0, 2f
     srl       $a1, $s4, 1
    and        $a1, 0x7
    add        $a1, $s1
    addu       $a0, $s0, $zero
    and        $s5, $a1, 0x7
    jalr       $s3
     addu      $a1, $s5, $zero
    beqz       $v0, .L800E3FCC
  2:
     add       $v1, $zero, -0xF
    and        $s4, $v1
    sll        $t0, $s5, 1
    or         $a1, $s4, $t0
    jal        func_800E3CDC
     addu      $a0, $s0, $zero
    lw         $t0, 0x34($s0)
    addu       $s4, $v0, $zero
    sll        $t1, $t0, 8
    srl        $t1, 24
    lw         $t2, 0x168($s0)
    and        $t0, 0xFF
    sll        $t3, $t2, 8
    srl        $t3, 24
    and        $t2, 0xFF
    beq        $t1, $t3, 3f
     addu      $v0, $zero, $zero
    slt        $v0, $t1, $t3
    add        $v0, $t1
  3:
    sll        $v0, 27
    beq        $t0, $t2, 4f
     addu      $v1, $zero, $zero
    slt        $v1, $t0, $t2
    add        $v1, $t0
  4:
    sll        $v1, 22
  .L800E3FB4:
    sll        $s4, 10
    srl        $s4, 10
    or         $s4, $v0
    or         $s4, $v1
    or         $s4, 0x1
    li         $v0, 0x1
  .L800E3FCC:
    sw         $s4, 0x190($s0)
    lw         $s0, 0x0($sp)
    lw         $s1, 0x4($sp)
    lw         $s2, 0x8($sp)
    lw         $s3, 0xC($sp)
    lw         $s4, 0x10($sp)
    lw         $ra, 0x14($sp)
    lw         $s5, 0x18($sp)
    jr         $ra
     addu      $sp, 0x1C
endlabel func_800E3EAC

glabel func_800E3FF4
    addu       $sp, -0x1C
    sw         $s0, 0x0($sp)
    sw         $s1, 0x4($sp)
    sw         $s2, 0x8($sp)
    sw         $s3, 0xC($sp)
    addu       $s1, $a1, $zero
    addu       $s0, $a0, $zero
    sw         $s4, 0x10($sp)
    lw         $a1, 0x190($s0)
    addu       $s2, $a2, $zero
    addu       $s3, $a3, $zero
    sw         $ra, 0x14($sp)
    sw         $s5, 0x18($sp)
    jal        func_800E3DDC
     addu      $a2, $a3, $zero
    addu       $s4, $v0, $zero
    sll        $t1, $s4, 27
    bltz       $t1, 0f
     add       $t0, $zero, 0x1
    add        $t0, $zero, -0x1
  0:
    beq        $t0, $s2, 2f
     addu      $s5, $s1, $zero
    add        $a1, $s1, 0x4
    addu       $s1, $t0, $zero
    and        $s5, $a1, 0x7
    addu       $a1, $s5, $zero
    jalr       $s3
     addu      $a0, $s0, $zero
    bnez       $v0, 2f
     sll       $s1, 1
    sub        $s5, $s1
    and        $s5, 0x7
  1:
    addu       $a1, $s5, $zero
    jalr       $s3
     addu      $a0, $s0, $zero
    beqz       $v0, .L800E3FCC
  2:
     add       $v1, $zero, -0xF
    and        $s4, $v1
    addu       $a0, $s0, $zero
    sll        $a3, $s5, 1
    jal        func_800E3CDC
     or        $a1, $s4, $a3
    lw         $t0, 0x34($s0)
    addu       $s4, $v0, $zero
    lw         $t1, 0x168($s0)
    and        $a0, $t0, 0xFF
    sll        $a1, $t0, 8
    srl        $a1, 24
    and        $t0, $t1, 0xFF
    sll        $t1, 8
    srl        $t1, 24
    and        $v1, $s4, 0x4
    bnez       $v1, 3f
     slt       $a3, $a0, $t0
    add        $a0, $a3
    bgez       $zero, 4f
     addu      $a1, $zero, $zero
  3:
    slt        $a3, $a1, $t1
    add        $a1, $a3
    addu       $a0, $zero, $zero
  4:
    sll        $v0, $a0, 22
    bgez       $zero, .L800E3FB4
     sll       $v1, $a1, 27
    addu       $sp, -0x1C
    sw         $s0, 0x0($sp)
    sw         $s1, 0x4($sp)
    sw         $s2, 0x8($sp)
    sw         $s3, 0xC($sp)
    sw         $s4, 0x10($sp)
    sw         $ra, 0x14($sp)
    sw         $s5, 0x18($sp)
    addu       $s1, $a1, $zero
    lw         $a1, 0x190($a0)
    addu       $s3, $a2, $zero
    jal        func_800E3DDC
     addu      $s0, $a0, $zero
    addu       $s4, $v0, $zero
    sll        $t1, $s4, 27
    bltz       $t1, 5f
     add       $t0, $zero, 0x1
    add        $t0, $zero, -0x1
  5:
    sll        $t0, 1
    sub        $s5, $s1, $t0
    and        $s5, 0x7
    addu       $a1, $s5, $zero
    jalr       $s3
     addu      $a0, $s0, $zero
    bnez       $v0, 2b
     add       $a1, $s5, 0x4
    and        $a1, 0x7
    addu       $s5, $a1, $zero
    jalr       $s3
     addu      $a0, $s0, $zero
    bnez       $v0, 2b
     add       $a1, $s1, 0x4
    and        $a1, 0x7
    addu       $s5, $a1, $zero
    bgez       $zero, 1b
     addu      $a0, $s0, $zero
endlabel func_800E3FF4

glabel func_800E4180
    addu       $sp, -0x20
    sw         $ra, 0x18($sp)
    sll        $a3, 1
    addu       $a3, $a0
    lhu        $v1, 0x474($a3)
    addu       $t3, $a0, $zero
    addu       $t4, $a1, $zero
    addu       $t5, $a2, $zero
    srl        $t7, $v1, 8
    and        $t7, 0xFF
    and        $t6, $v1, 0xFF
    bnez       $t7, 0f
     li        $v0, 0x3
    beq        $v0, $t5, 3f
     li        $v0, 0x1
    jal        func_800E45D4
     li        $a0, 0x80
    slt        $t4, $v0
    bnez       $t4, 3f
     li        $v0, 0x1
    la         $t4, D_800F1758
    addu       $t4, $t5
    lbu        $t7, 0x0($t4)
    addu       $t6, $t5, $zero
  0:
    sw         $t7, 0x14($sp)
    add        $v1, $t7, -0x1
    sll        $v1, 8
    or         $v0, $v1, $t6
    sh         $v0, 0x474($a3)
    li         $v0, 0x40
    sh         $v0, 0x13A($t3)
    li         $v0, 0x2
    bne        $t5, $v0, 2f
     li        $v0, 0x1
    slt        $v1, $t7, 0xB
    beqz       $v1, 1f
     li        $v1, 0x500
    addu       $v1, $zero, $zero
  1:
    sh         $v1, 0x188($t3)
    addu       $a0, $t3, $zero
    la         $ra, D_800E425C
    bgez       $zero, func_800DEEFC
     li        $a1, 0x10
  2:
    bne        $t5, $v0, 3f
     li        $v0, 0x1
    slt        $v0, $t7, 0x35
    beqz       $v0, 1b
     add       $v1, $zero, 0x320
    slt        $v0, $t7, 0x12
    beqz       $v0, 1b
     add       $v1, $zero, -0x320
    bgez       $zero, 1b
     addu      $v1, $zero, $zero
alabel D_800E425C
    lw         $v0, 0x14($sp)
    nop
    slt        $v0, 0x2
  3:
    lw         $ra, 0x18($sp)
    xor        $v0, 0x1
    jr         $ra
     addu      $sp, 0x20
    sll        $a1, 1
    addu       $a1, $a0
    jr         $ra
     sh        $zero, 0x474($a1)
alabel func_800E4288
    addu       $t0, $zero, $zero
    srl        $a2, $a1, 4
    beqz       $a2, 5f
     and       $a3, $a1, 0xC
  4:
    sw         $zero, 0x0($a0)
    sw         $zero, 0x4($a0)
    sw         $zero, 0x8($a0)
    sw         $zero, 0xC($a0)
    add        $a2, -0x1
    bnez       $a2, 4b
     addu      $a0, 0x10
    beqz       $a3, 6f
     nop
  5:
    add        $a3, -0x4
    sw         $zero, 0x0($a0)
    bnez       $a3, 5b
     addu      $a0, 0x4
  6:
    jr         $ra
     nop
alabel func_800E42D4
    sra        $a0, 7
    bgez       $zero, func_800E42EC
     sra       $a1, 7
alabel func_800E42E0
    sll        $a1, $a0, 8
    srl        $a1, 24
    and        $a0, 0xFF
alabel func_800E42EC
    addu       $at, $ra, $zero
    jal        func_800E4320
     nop
    addu       $ra, $at, $zero
    sll        $v0, 17
    jr         $ra
     sra       $v0, 17
alabel func_800E4308
    sll        $a1, $a0, 8
    srl        $a1, 24
    bgez       $zero, func_800E4320
     and       $a0, 0xFF
alabel func_800E4318
    sra        $a0, 7
    sra        $a1, 7
alabel func_800E4320
    sll        $v1, $a0, 1
    lw         $a2, 0x1F8003BC
    sll        $v0, $a1, 6
    addu       $v0, $a2
    addu       $v1, $v0
    lhu        $v0, 0x0($v1)
    nop
    sll        $a2, $v0, 22
    sra        $a2, 16
    and        $v0, 0x1C00
    sra        $v0, 3
    jr         $ra
     sub       $v0, $a2, $v0
alabel func_800E4358
    lbu        $t0, 0x155($a0)
    lbu        $t3, 0x13F($a0)
    beqz       $t0, 7f
     add       $t0, -0x1
    sb         $t0, 0x155($a0)
  7:
    beqz       $t3, 18f
     add       $t3, -0x1
    jr         $ra
     sb        $t3, 0x13F($a0)
alabel func_800E437C
    beqz       $a3, 16f
     add       $v0, $zero, 0x1000
    addu       $a3, $ra, $zero
    negu       $a2, $a2
    addu       $a2, 0xC00
    and        $a2, 0xFFF
    li         $t6, 0x1
    addu       $t7, $a2, $zero
  8:
    xor        $t6, 0x1
    la         $v0, _trig_table
    and        $t0, $a2, 0x400
    beqz       $t0, 10f
     and       $t1, $a2, 0x3FF
    bnez       $t1, 9f
     li        $t2, 0x800
    bgez       $zero, 12f
     li        $v0, 0x1000
  9:
    subu       $a2, $t2, $a2
  10:
    and        $t1, $a2, 0x200
    beqz       $t1, 11f
     and       $t2, $a2, 0x1FF
    li         $t0, 0x200
    subu       $t2, $t0, $t2
    addu       $v0, 0x2
  11:
    sll        $t2, 2
    addu       $v0, $t2
    lhu        $v0, 0x0($v0)
  12:
    and        $t0, $a2, 0x800
    beqz       $t0, 13f
     nop
    negu       $v0, $v0
  13:
    beqz       $t6, 14f
     addu      $a2, $t7, 0x400
    bgez       $zero, 15f
     addu      $t8, $v0, $zero
  14:
    bgez       $zero, 8b
     addu      $t9, $v0, $zero
  15:
    lh         $t0, 0x0($a0)
    lh         $t2, 0x4($a0)
    lh         $t3, 0x0($a1)
    lh         $t4, 0x4($a1)
    sub        $t0, $t3, $t0
    sub        $t2, $t4, $t2
    addu       $t1, $zero, $zero
    jal        func_80041AF4
     nop
    mult       $t0, $t8
    mflo       $a0
    nop
    addu       $ra, $a3, $zero
    mult       $t2, $t9
    mflo       $v0
    add        $v0, $a0
    sra        $t0, $v0, 12
    slt        $t1, $t0, -0x1000
    bnez       $t1, 16f
     add       $v0, $zero, -0x1000
    slt        $t1, $t0, 0x1000
    beqz       $t1, 16f
     add       $v0, $zero, 0x1000
    addu       $v0, $t0, $zero
  16:
    jr         $ra
alabel func_800E4478
     addu      $t8, $a1, $zero
    addu       $a1, $a2, $zero
    sra        $a0, 7
    sra        $a1, 7
    sll        $v1, $a0, 1
    lw         $a2, 0x1F8003BC
    sll        $v0, $a1, 6
    addu       $v0, $a2
    addu       $v1, $v0
    lhu        $v0, 0x0($v1)
    nop
    sll        $a2, $v0, 18
    bltz       $a2, 17f
     addu      $t0, $zero, $zero
    sll        $a2, $v0, 22
    sra        $a2, 16
    and        $v0, 0x1C00
    sra        $v0, 3
    sub        $v0, $a2, $v0
    sll        $t0, $v0, 17
    sra        $t0, 17
  17:
    slt        $t8, $t0
    bnez       $t8, 18f
     li        $v0, 0x1
    addu       $v0, $zero, $zero
  18:
    jr         $ra
     nop
alabel func_800E44E8
    addu       $sp, -0x38
    sw         $ra, 0x30($sp)
    sw         $s0, 0x10($sp)
    sw         $s6, 0x28($sp)
    sw         $s5, 0x24($sp)
    sw         $s4, 0x20($sp)
    sw         $s3, 0x1C($sp)
    sw         $s2, 0x18($sp)
    sw         $s1, 0x14($sp)
    lw         $s0, 0x0($a0)
    lh         $s2, 0x4($a0)
    sra        $s1, $s0, 16
    and        $s0, 0xFFFF
    sub        $s1, $a2
    lw         $t0, 0x0($a1)
    lh         $t2, 0x4($a1)
    sra        $t1, $t0, 16
    and        $t0, 0xFFFF
    sub        $t1, $a3
    sub        $s3, $t0, $s0
    sub        $s4, $t1, $s1
    sub        $s5, $t2, $s2
    sra        $s3, 4
    sra        $s4, 4
    sra        $s5, 4
    addu       $s6, $zero, $zero
  19:
    add        $a0, $s0, $s3
    add        $a1, $s1, $s4
    add        $a2, $s2, $s5
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    jal        func_800E4478
     addu      $s2, $a2, $zero
    beqz       $v0, 20f
     add       $s6, 0x1
    and        $at, $s6, 0x10
    bnez       $at, 21f
     addu      $v0, $zero, $zero
    bgez       $zero, 19b
     nop
  20:
    add        $v0, $zero, 0x1
  21:
    lw         $ra, 0x30($sp)
    lw         $s0, 0x10($sp)
    lw         $s6, 0x28($sp)
    lw         $s5, 0x24($sp)
    lw         $s4, 0x20($sp)
    lw         $s3, 0x1C($sp)
    lw         $s2, 0x18($sp)
    lw         $s1, 0x14($sp)
    jr         $ra
     addu      $sp, 0x38
alabel func_800E45B4
    lui        $t0, (0x1F801110 >> 16)
    lw         $t1, (0x1F801110 & 0xFFFF)($t0)
    lw         $t2, D_80030FE4
    nop
    subu       $v0, $t1, $t2
    jr         $ra
     and       $v0, 0xFFFF
alabel func_800E45D4
    lui        $a1, (0x1F8003F8 >> 16)
    lh         $t0, (0x1F8003F8 & 0xFFFF)($a1)
    lw         $t1, (0x1F8003FC & 0xFFFF)($a1)
    addu       $a0, -0x1
    add        $t0, $t1
    sw         $t0, (0x1F8003F8 & 0xFFFF)($a1)
    jr         $ra
     and       $v0, $t0, $a0
alabel func_800E45F4
    sll        $t0, $a0, 24
    srl        $t0, 24
    sll        $t1, $a0, 8
    srl        $t1, 24
alabel func_800E4604
    sll        $t2, $a1, 24
    srl        $t2, 24
    sll        $t3, $a1, 8
    srl        $t3, 24
    sub        $a0, $t0, $t2
    sub        $a2, $t1, $t3
    bgez       $zero, func_800E4660
     addu      $a1, $zero, $zero
alabel func_800E4624
    lw         $t6, 0x0($a0)
    lh         $t2, 0x4($a0)
    sll        $t0, $t6, 16
    sra        $t0, 16
    sra        $t1, $t6, 16
    lw         $t6, 0x0($a1)
    lh         $t5, 0x4($a1)
    sll        $t3, $t6, 16
    sra        $t3, 16
    sra        $t4, $t6, 16
    add        $t1, $a2
    add        $t4, $a3
    sub        $a0, $t0, $t3
    sub        $a1, $t1, $t4
    sub        $a2, $t2, $t5
alabel func_800E4660
    mtc2       $a0, $9
    mtc2       $a1, $10
    mtc2       $a2, $11
    nop
    nop
    sqr        0
    mfc2       $a0, $25
    mfc2       $a1, $26
    mfc2       $a2, $27
    addu       $v0, $a0, $a1
    jr         $ra
     add       $v0, $a2
alabel func_800E4690
    addu       $sp, -0x20
    sw         $t0, 0x0($sp)
    sw         $t1, 0x4($sp)
    sw         $t2, 0x8($sp)
    sw         $t3, 0xC($sp)
    sw         $t4, 0x10($sp)
    sw         $t5, 0x14($sp)
    sw         $v1, 0x18($sp)
    addu       $a3, $ra, $zero
    addu       $t1, $a0, $zero
    addu       $t2, $a1, $zero
    and        $a0, 0xFF
    srl        $a1, $t1, 16
    and        $a1, 0xFF
    addu       $t3, $a0, $zero
    jal        func_800E4320
     addu      $t4, $a1, $zero
    lui        $a0, (0x1F8003EC >> 16)
    addu       $a0, $t2
    lb         $t2, (0x1F8003EC & 0xFFFF)($a0)
    sll        $t5, $v0, 17
    sra        $t5, 17
    sll        $a0, $t2, 30
    sra        $a0, 30
    sll        $a1, $t2, 26
    sra        $a1, 30
    add        $a0, $t3, $a0
    jal        func_800E4320
     add       $a1, $t4, $a1
    sll        $t2, $v0, 17
    sra        $t2, 17
    srl        $t0, $v0, 31
    bnez       $t0, 23f
     add       $v0, $zero, 0x1
    sub        $t5, $t2
    srl        $a0, $t5, 31
    beqz       $a0, 22f
     nop
    neg        $t5, $t5
  22:
    srl        $a1, $t5, 6
    bnez       $a1, 23f
     add       $v0, $zero, 0x1
    addu       $v0, $zero, $zero
  23:
    lw         $t0, 0x0($sp)
    lw         $t1, 0x4($sp)
    lw         $t2, 0x8($sp)
    lw         $t3, 0xC($sp)
    lw         $t4, 0x10($sp)
    lw         $t5, 0x14($sp)
    lw         $v1, 0x18($sp)
    addu       $sp, 0x20
    jr         $a3
     addu      $ra, $a3, $zero
alabel func_800E4764
    lw         $t1, 0x224($a0)
    li         $v0, 0xA
    lbu        $t0, 0x1($a0)
    sll        $t2, $t1, 16
    srl        $t2, 24
    sll        $t3, $t1, 8
    srl        $t3, 24
    srl        $t4, $t1, 24
    and        $t1, 0xFF
    beqz       $t0, 25f
  24:
     and       $v1, $t1, 0x20
    bnez       $v1, 26f
     addu      $v1, $t3, $zero
    and        $v1, $t2, 0x20
    bnez       $v1, 26f
     addu      $v1, $t4, $zero
    beqz       $t0, 27f
     addu      $v0, $zero, $zero
  25:
    li         $v0, 0x9
    and        $v1, $t1, 0x10
    bnez       $v1, 26f
     addu      $v1, $t3, $zero
    and        $v1, $t2, 0x10
    bnez       $v1, 26f
     addu      $v1, $t4, $zero
    bgez       $zero, 24b
     li        $v0, 0xA
  26:
    sw         $v1, 0x0($a1)
    sw         $v0, 0x0($a2)
    li         $v0, 0x1
  27:
    jr         $ra
     nop
alabel func_800E47E4
    lbu        $a2, 0xC($a0)
    addu       $t6, $ra, $zero
    bnez       $a2, 41f
     addu      $v0, $zero, $zero
    lw         $v0, 0x34($a0)
    and        $a2, $a1, 0xFF
    sll        $a1, 8
    srl        $a1, 24
    and        $t0, $v0, 0xFF
    sll        $t1, $v0, 8
    srl        $t1, 24
    lbu        $t2, 0x15C($a0)
    la         $a3, D_800F4538
    slt        $v0, $t2, 0x10
    bnez       $v0, 28f
     sub       $t9, $a1, $t1
    lbu        $v1, 0x88($a0)
    sub        $t8, $a2, $t0
    sll        $v1, 2
    addu       $a3, $v1
    lw         $a3, 0x0($a3)
    bgez       $zero, 29f
     lhu       $v0, 0x26($a3)
  28:
    sll        $t2, 2
    addu       $a3, $t2
    lw         $a3, 0x0($a3)
    sub        $t8, $a2, $t0
    lhu        $t0, 0x1C($a3)
    lhu        $t1, 0x20($a3)
    lhu        $t2, 0x4C($a0)
    lhu        $t3, 0x50($a0)
    subu       $a0, $t2, $t0
    jal        ratan2
     subu      $a1, $t3, $t1
  29:
    li         $a0, 0xC00
    sub        $a0, $v0
    jal        rcos
     addu      $t7, $a0, $zero
    mult       $v0, $t8
    mflo       $t8
    jal        rsin
     addu      $a0, $t7, $zero
    mult       $v0, $t9
    addu       $ra, $t6, $zero
    mflo       $t9
    add        $v0, $t9, $t8
    jr         $ra
     slt       $v0, $zero
alabel func_800E48A8
    addu       $t3, $a0, $zero
    addu       $t4, $a1, $zero
    addu       $t5, $ra, $zero
    lw         $a3, 0x18C($a0)
    lbu        $t2, 0x155($a0)
    jal        func_800E45D4
     addu      $a0, $a2, $zero
    or         $a3, $t2, $a3
    bnez       $a3, 41f
     addu      $ra, $t5, $zero
    slt        $a0, $v0, $a2
    beqz       $a0, 41f
     lw        $a1, 0x54($t3)
    li         $t0, 0x1E
    lbu        $t1, 0xB($a1)
    sb         $t0, 0x155($t3)
    and        $t1, 0xFC
    or         $t1, $t4
    jr         $ra
     sb        $t4, 0xB($a1)
alabel func_800E48F8
    lbu        $v0, 0x89($a0)
    li         $v1, 0x1
    bne        $v1, $v0, 41f
alabel func_800E4904
     lui       $a1, (0x1F80037C >> 16)
    lbu        $a3, 0xE5($a0)
    addu       $sp, -0x20
    sw         $ra, 0x10($sp)
    sw         $s0, 0x14($sp)
    sw         $s1, 0x18($sp)
    addu       $s0, $a0, $zero
    sll        $a3, 2
    addu       $a0, $a1, $a3
    lw         $a0, (0x1F80037C & 0xFFFF)($a0)
    la         $a2, D_800F4538
    addu       $a1, $a3, $a2
    lw         $a1, 0x0($a1)
    beqz       $a0, 33f
     lbu       $a2, 0xA($a1)
    lbu        $a0, 0x5D($a1)
    and        $a2, 0x1F
    bnez       $a2, 31f
     slt       $a3, $a0, 0x2
    beqz       $a3, 30f
     add       $a0, -0x2
    lh         $a0, 0x1C($a1)
    lh         $a2, 0x20($a1)
    sra        $a0, 6
    bgez       $zero, 32f
     sra       $a2, 6
  30:
    jal        func_8008E2D4
     addu      $s1, $a0, $zero
    lw         $a1, 0x0($v0)
    lw         $a2, 0x8($v0)
    addu       $a3, $s0, 0xF4
    jal        func_800DFA54
     addu      $a0, $s1, $zero
    lb         $a0, 0xF4($s0)
    lb         $a2, 0xF6($s0)
    sll        $a0, 1
    bgez       $zero, 32f
     sll       $a2, 1
  31:
    lw         $a2, 0x60($a1)
    nop
    and        $a2, 0xFF00
    srl        $a2, 8
    bnez       $a2, 30b
     add       $a0, $a2, -0x2
    lh         $a0, 0x4C($a1)
    lh         $a2, 0x50($a1)
    sra        $a0, 6
    bgez       $zero, 32f
     sra       $a2, 6
  32:
    sb         $a0, 0xF4($s0)
    sb         $a2, 0xF6($s0)
  33:
    bgez       $zero, 38f
alabel func_800E49D8
     lui       $t0, (0x1F8003F4 >> 16)
    addu       $sp, -0x20
    sw         $ra, 0x10($sp)
    sw         $s0, 0x14($sp)
    sw         $s1, 0x18($sp)
    lw         $t0, (0x1F8003F4 & 0xFFFF)($t0)
    addu       $s0, $a0, $zero
    lw         $a0, 0x34($s0)
    beqz       $t0, 37f
     addu      $t9, $a0, $zero
    addu       $t1, $a2, $zero
    jal        func_800E42E0
     addu      $s1, $a1, $zero
    addu       $t2, $v0, $zero
    jal        func_800E4308
     addu      $a0, $s1, $zero
    bltz       $v0, 37f
     sll       $a0, $v0, 17
    sra        $a0, 17
    slt        $a1, $t2, $a0
    beqz       $a1, 37f
     addu      $t2, $a0, $zero
    addu       $a0, $a3, $zero
    add        $t4, $zero, 0x2
    beqz       $a0, 37f
     addu      $t3, $zero, $zero
    add        $a0, -0x1
    slt        $a1, $a0, $t4
    beqz       $t4, 34f
     lui       $t0, (0x1F8003EC >> 16)
    addu       $t4, $a0, $zero
  34:
    addu       $t0, $t1
    lbu        $a0, (0x1F8003EC & 0xFFFF)($t0)
    and        $t7, $s1, 0xFF
    sll        $t8, $s1, 8
    srl        $t8, 24
    sll        $t5, $a0, 30
    sra        $t5, 30
    sll        $t6, $a0, 26
    sra        $t6, 30
  35:
    addu       $a0, $t7, $t5
    jal        func_800E42EC
     addu      $a1, $t8, $t6
    slt        $a2, $v0, $t2
    bnez       $a2, 36f
     addu      $t7, $a0, $zero
    add        $t3, 0x1
    slt        $a2, $t3, $t4
    bnez       $a2, 35b
     addu      $t8, $a1, $zero
    addu       $t2, $v0, $zero
    bgez       $zero, 37f
  36:
     addu      $t8, $a1, $zero
    li         $a0, 0xFF00FF00
    sll        $t8, 16
    or         $t8, $t7, $t8
    and        $s1, $a0
    or         $s1, $t8
    addu       $a0, $s0, $zero
    addu       $a1, $t9, $zero
    addu       $a2, $s1, $zero
    jal        func_800D96C8
     addu      $a3, $t1, $zero
    blez       $v0, 37f
     addu      $a0, $s0, $zero
    jal        func_800D954C
     addu      $a1, $s1, $zero
    blez       $v0, 37f
     nop
    bgez       $zero, 38f
     addu      $v0, $s1, $zero
  37:
    addu       $v0, $zero, $zero
  38:
    lw         $ra, 0x10($sp)
    lw         $s0, 0x14($sp)
    lw         $s1, 0x18($sp)
    jr         $ra
     addu      $sp, 0x20
alabel func_800E4B10
    bgez       $zero, 39f
     add       $a1, $zero, 0xB
alabel func_800E4B18
    add        $a1, $zero, 0xC
  39:
    sw         $zero, 0x228($a0)
    lw         $a2, 0x34($a0)
    j          func_800DEEFC
     sw        $a2, 0x170($a0)
alabel func_800E4B2C
    lbu        $t0, 0x19B($a0)
    lw         $t1, 0x168($a0)
    bnez       $t0, func_800DF8A4
     lui       $v0, (0xFF00FF >> 16)
    lw         $t2, 0x34($a0)
    or         $v0, (0xFF00FF & 0xFFFF)
    and        $t1, $v0
    and        $t2, $v0
    beq        $t1, $t2, func_800E2CCC
     srl       $v1, $t1, 9
    and        $v0, $t1, 0xFF
    sll        $v0, 7
    addu       $v0, 0x40
    addu       $v1, 0x40
    sw         $v0, 0x17C($a0)
    bgez       $zero, func_800E19FC
     sw        $v1, 0x180($a0)
alabel func_800E4B70
    lbu        $v0, 0x1A($a0)
    addu       $sp, -0x20
    sw         $ra, 0x10($sp)
    lui        $ra, (0x800E4BAC >> 16)
    bnez       $v0, func_800E1908
     or        $ra, (0x800E4BAC & 0xFFFF)
    lbu        $v0, 0x19B($a0)
    and        $a1, 0xFFF
    beqz       $v0, 40f
     lui       $v1, (0x1F8003D0 >> 16)
    bgez       $zero, func_800DF8A4
  40:
     add       $a2, $zero, 0x1
    sb         $a2, 0x2($a0)
    bgez       $zero, func_800E3600
     sb        $zero, (0x1F8003D0 & 0xFFFF)($v1)
    lw         $ra, 0x10($sp)
    addu       $sp, 0x20
  41:
    jr         $ra
alabel func_800E4BB8
     add       $a3, $zero, -0xFE2
    lb         $a2, 0x23($a0)
    lw         $a1, 0x190($a0)
    beqz       $a2, 42f
     and       $a1, $a3
    or         $a1, 0x3C0
  42:
    jr         $ra
     sw        $a1, 0x190($a0)
alabel func_800E4BD8
    bgez       $zero, 43f
     li        $a3, 0x1
alabel func_800E4BE0
    addu       $a3, $zero, $zero
  43:
    lw         $a1, D_800F58BC
    add        $v1, $zero, -0x1
    beqz       $a1, 41b
     li        $v0, 0x1
    beqz       $a3, 44f
     sllv      $v0, $v0, $a0
    sub        $v0, $v1, $v0
  44:
    lbu        $a2, 0xE($a1)
    bltz       $v0, 45f
     and       $v1, $a2, $v0
    or         $v1, $a2, $v0
  45:
    jr         $ra
     sb        $v1, 0xE($a1)
alabel func_800E4C1C
    add        $a3, $zero, 0x1
    bgez       $zero, 46f
     or        $a2, $zero, 0x80
alabel func_800E4C28
    addu       $a3, $zero, $zero
    or         $a2, $zero, 0xFF7F
  46:
    lw         $t0, D_800F58B8
    sll        $a1, 6
    beqz       $t0, 41b
     sll       $a0, 1
    addu       $a0, $a1
    addu       $t0, $a0
    lhu        $t1, 0x0($t0)
    bnez       $a3, 47f
     or        $t2, $t1, $a2
    and        $t2, $t1, $a2
  47:
    jr         $ra
     sh        $t2, 0x0($t0)
alabel func_800E4C64
    beqz       $a0, 41b
     lui       $a1, %hi(D_800F5878)
    addiu      $a1, %lo(D_800F5878)
    sll        $a0, 2
    addu       $a0, $a1
    lw         $a0, 0x0($a0)
    nop
    beqz       $a0, 41b
     li        $a1, 0x1E
    sb         $a1, 0x13F($a0)
alabel func_800E4C8C
    la         $a1, D_800F4538
    lw         $v0, 0x470($a0)
    lbu        $t0, 0x19($a0)
    blez       $v0, 48f
     lw        $a2, 0x430($a0)
    li         $v1, 0x384
    lw         $a2, 0xC($a2)
    lw         $a3, 0x34($a0)
    and        $a2, 0xF
    sll        $v0, $a2, 24
    bnez       $t0, 48f
     sll       $a2, 2
    sll        $a3, 8
    addu       $a2, $a1, $a2
    lw         $a2, 0x0($a2)
    srl        $a3, 8
    or         $v0, $a3
    sw         $v0, 0x38($a0)
    lw         $a2, 0x5C($a2)
    sh         $v1, 0x40($a0)
    sw         $a2, 0x3C($a0)
  48:
    jr         $ra
alabel func_800E4CE8
     li        $v0, -0x1
    jr         $ra
     sw        $v0, 0x38($a0)
alabel func_800E4CF4
    lw         $t0, 0x4($a1)
    la         $v0, D_800F5878
    sll        $v1, $a2, 2
    addu       $v0, $v1
    srl        $t1, $t0, 5
    lw         $at, 0x10($a1)
    and        $t1, 0xFF
    li         $t2, 0x34
    mult       $t1, $t2
    addu       $v1, $a0, $v1
    lw         $v0, 0x0($v0)
    and        $t3, $t0, 0x7
    srl        $t4, $t0, 3
    and        $t4, 0x3
    beqz       $v0, 50f
     lw        $v1, 0x1A4($v1)
    sll        $t3, 5
    sll        $t4, 3
    srl        $v1, 6
    and        $v1, 0x3
    lw         $v0, 0x10($v0)
    la         $t0, vs_main_actions
    mflo       $t5
    slt        $a3, $v1, 0x2
    bnez       $a3, 50f
     addu      $t3, $t4
    addu       $t5, $t0
    lhu        $t5, 0xE($t5)
    srl        $t0, $v0, 7
    and        $t0, 0x2
    srl        $t2, $v0, 14
    and        $t2, 0x4
    or         $t0, $t2
    slt        $a3, $v1, 0x3
    sll        $t4, $at, 26
    bgez       $t4, 49f
     and       $v0, 0x1
    or         $v0, $t0, $v0
    beqz       $a3, 50f
     sll       $a3, $t5, 23
    bltz       $a3, 49f
     srl       $a3, $t5, 9
    and        $a3, $v0
    beqz       $a3, 50f
  49:
     addu      $t3, $a0
    lw         $t3, 0x230($t3)
    srl        $t0, $at, 4
    and        $t0, 0x1
    slt        $t2, $v1, 0x3
    and        $t0, $t2
    bnez       $t0, 50f
     srl       $t3, 1
    lbu        $a3, 0x88($a0)
    and        $t3, 0x1
    sub        $a2, $a3
    sltu       $a2, 0x1
    and        $a2, $t3
    bnez       $a2, 50f
     nop
    jr         $ra
     li        $v0, 0x1
  50:
    jr         $ra
     addu      $v0, $zero, $zero
alabel func_800E4DF8
    lw         $t0, 0x54($a0)
    li         $t1, 0xDC
    li         $t2, 0x4
    li         $t3, 0x34
    mult       $a1, $t1
    lw         $t0, 0x3C($t0)
    sll        $t5, $a1, 2
    addu       $t5, $a2
    la         $t4, vs_main_actions
    sll        $v0, $t5, 2
    addu       $v0, $t0, $v0
    lhu        $v0, 0x8C0($v0)
    lh         $v1, 0x1C($t0)
    mflo       $a3
    lw         $t6, 0x948($t0)
    addu       $a3, $t0, $a3
    mult       $t3, $v0
    lh         $a3, 0x398($a3)
    and        $t8, $t6, 0x2000
    lw         $t7, 0x18($t0)
    slt        $a3, 0x2
    bnez       $a3, 55f
     and       $t2, $t7, 0xFFFF
    mflo       $a2
    srl        $t3, $t7, 16
    addu       $a2, $t4, $a2
    lbu        $a3, 0x2($a2)
    li         $t7, 0x1
    li         $t9, 0x4
    lbu        $a2, 0x3($a2)
    srl        $a3, 1
    and        $a3, 0x7
    beqz       $t8, 51f
     li        $t8, 0x3
    li         $t8, 0x1
    sllv       $t8, $t8, $a3
    and        $t8, 0x6
    beqz       $t8, 55f
     li        $t8, 0x3
  51:
    bne        $a3, $t7, 52f
     slt       $a1, $v1, $a2
    bnez       $a1, 55f
     and       $a1, $t6, 0x1000
    bnez       $a1, 55f
     nop
    bgez       $zero, 54f
  52:
     srl       $t3, 1
    bne        $a3, $t8, 53f
     addu      $t3, $a2, $t3
    slt        $a1, $t2, $t3
    bnez       $a1, 55f
     nop
    bgez       $zero, 54f
  53:
     lh        $a1, 0x14C($t0)
    bne        $a3, $t9, 54f
     slt       $a1, $a2
    bnez       $a1, 55f
     nop
  54:
    bgez       $zero, 56f
     li        $v0, 0x1
  55:
    addu       $v0, $zero, $zero
  56:
    sll        $t5, 3
    addu       $a0, $t5
    lw         $a2, 0x230($a0)
    sll        $v1, $v0, 7
    add        $a3, $zero, -0x81
    and        $a2, $a3
    or         $a2, $v1
    jr         $ra
     sw        $a2, 0x230($a0)
alabel func_800E4F14
    lw         $t0, 0x54($a0)
    lbu        $t1, 0x17($a0)
    lw         $t0, 0x3C($t0)
    li         $v0, 0x2
    lw         $t2, 0x18($t0)
    li         $v1, 0x2
    and        $t3, $t2, 0xFFFF
    mult       $v0, $t3
    lw         $t4, 0x1C($t0)
    srl        $t2, 16
    lui        $t5, (0x90000 >> 16)
    and        $t6, $t4, 0xFFFF
    lw         $t8, 0x948($t0)
    mflo       $v0
    or         $t5, $zero, 0xE2B0
    srl        $t4, 16
    mult       $t6, $v1
    slt        $v0, $t2
    sb         $v0, 0x12($a0)
    beqz       $t1, 57f
     addu      $a3, $zero, $zero
    slt        $a3, $t6, $t1
    mflo       $v1
    bnez       $a3, 57f
     nop
    slt        $a3, $v1, $t4
  57:
    sb         $a3, 0x11($a0)
    and        $v0, $t8, $t5
    sltu       $a3, $v0, 0x1
    beqz       $a3, 58f
     sltu      $t2, $t1, 0x1
    and        $t3, $t8, 0x1000
    sltu       $t3, 0x1
    or         $a3, $t2, $t3
    bnez       $a3, 59f
     addu      $a3, $zero, $zero
  58:
    xor        $a3, 0x1
  59:
    jr         $ra
     sb        $a3, 0x10($a0)
alabel func_800E4FB0
    lw         $t0, 0x54($a0)
    sll        $a1, 2
    lbu        $t0, 0x9($t0)
    li         $v0, 0xA
    bne        $t0, $v0, 60f
     addu      $a1, $a0, $a1
    addu       $a2, 0x80
  60:
    mult       $v0, $v0
    lw         $t0, 0x1E4($a1)
    mflo       $v0
    jr         $ra
     sltu      $v0, $t0
alabel func_800E4FE0
    lw         $t0, 0x17C($a0)
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    li         $v0, 0x1
    lw         $t1, 0x180($t8)
    lh         $a0, 0x4C($t8)
    sb         $a1, 0x1($t8)
    sb         $v0, 0x9($t8)
    lh         $a1, 0x50($t8)
    sll        $t2, $t1, 16
    or         $t2, $t0, $t2
    sw         $t2, 0x158($t8)
    sub        $a0, $t0, $a0
    jal        ratan2
     sub       $a1, $t1, $a1
    addu       $ra, $t9, $zero
    addu       $a2, $v0, $zero
    addu       $a0, $t8, $zero
    bgez       $zero, func_800E50A0
     li        $a1, 0x1
alabel func_800E5030
    lw         $t6, 0x168($a0)
    mult       $a1, $a1
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    jal        func_800E42E0
     addu      $a0, $t6, $zero
    lh         $t0, 0x4C($t8)
    and        $a0, $t6, 0xFF
    sll        $a2, $t6, 8
    srl        $a2, 24
    sll        $a0, 7
    lh         $t1, 0x4E($t8)
    sll        $a2, 7
    addu       $a0, 0x40
    addu       $a2, 0x40
    lh         $t2, 0x50($t8)
    sub        $a0, $t0
    sub        $a1, $v0, $t1
    jal        func_800E4660
     sub       $a2, $t2
    mflo       $v1
    addu       $ra, $t9, $zero
    addu       $a0, $t8, $zero
    sltu       $v0, $v1
    bnez       $v0, func_800DEEFC
     li        $a1, 0x0
    li         $a1, 0x0
    addu       $a2, $zero, $zero
alabel func_800E50A0
    lbu        $a3, 0x125($a0)
    la         $t0, jtbl_800F1740
    sll        $a3, 1
    addu       $a3, $a1
    sll        $a3, 2
    addu       $t0, $a3
    lw         $t0, 0x0($t0)
    addu       $a1, $a2, $zero
    jr         $t0
     lui       $t1, %hi(D_800F58D4)
    addiu      $t1, %lo(D_800F58D4)
    lw         $a3, 0x0($t1)
    li         $v1, 0x1
    lw         $a2, D_800F590C
  61:
    addu       $a3, 0x1
    and        $a3, 0xF
    sllv       $v1, $v1, $a3
    and        $v0, $a2, $v1
    beqz       $v0, 61b
     li        $v1, 0x1
    jr         $ra
     sw        $a3, 0x0($t1)
    lui        $a3, (0x1F800374 >> 16)
    sw         $sp, (0x1F800378 & 0xFFFF)($a3)
    jr         $ra
     or        $sp, $a3, (0x1F800374 & 0xFFFF)
    lui        $a3, (0x1F800378 >> 16)
    lw         $sp, (0x1F800378 & 0xFFFF)($a3)
    jr         $ra
alabel func_800E511C
     lui       $a3, (0x800F0000 >> 16)
    lw         $a3, 0x58B8($a3)
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    beqz       $a3, func_800DB89C
     lui       $s0, %hi(D_800F16BC)
    addiu      $s0, %lo(D_800F16BC)
    lw         $t0, 0x0($s0)
    lui        $ra, (0x800E513C >> 16)
    beqz       $t0, func_800DB89C
     or        $ra, (0x800E513C & 0xFFFF)
    jr         $t0
     addu      $s0, 0x4
alabel func_800E5154
    li         $a3, 0x1
alabel func_800E5158
    lw         $a1, D_800F58B8
    la         $a2, D_800F5878
    sll        $v0, $a0, 2
    addu       $a2, $v0
    lw         $a2, 0x0($a2)
    sltu       $v0, $a1, 0x1
    sltu       $v1, $a2, 0x1
    bnez       $a3, 62f
     or        $v0, $v1
    jr         $ra
     xor       $v0, 0x1
  62:
    bnez       $v0, 63f
     li        $v0, 0x2
    lw         $a2, 0x18C($a2)
    lui        $v1, (0xFF00FF >> 16)
    beqz       $a2, 63f
     or        $v1, (0xFF00FF & 0xFFFF)
    lw         $a0, 0x64($a2)
    lw         $a1, 0x168($a2)
    lw         $a0, 0x0($a0)
    and        $a1, $v1
    and        $a0, $v1
    beq        $a0, $a1, 63f
     li        $v0, 0x0
    li         $v0, 0x1
  63:
    jr         $ra
alabel func_800E51C8
     lui       $v1, (0x800F0000 >> 16)
    addu       $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    or         $a2, $v1, 0x5878
    sll        $v0, $s0, 2
    addu       $a2, $v0
    lw         $a1, 0x0($a2)
    addu       $a0, $s1, $zero
    jal        vs_main_memcpy
     li        $a2, 0x484
    sb         $s0, 0x88($s1)
    li         $v0, 0x140
    sh         $v0, 0xB0($s1)
    li         $v0, 0x3
    sb         $v0, 0xB2($s1)
    sw         $zero, 0x190($s1)
    sb         $zero, 0x19A($s1)
    li         $v0, 0x3
    sb         $v0, 0x29($s1)
    li         $v0, 0x1
    sb         $v0, 0x23($s1)
  64:
    lw         $ra, 0x18($sp)
    lw         $s0, 0x10($sp)
    lw         $s1, 0x14($sp)
    jr         $ra
     addu      $sp, 0x20
alabel func_800E5240
    addu       $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    jal        func_800E5158
     addu      $a3, $zero, $zero
    beqz       $v0, 64b
     lui       $ra, (0x800E522C >> 16)
    lw         $a0, 0x18C($a2)
    addu       $s0, $a2, $zero
    beqz       $a0, 64b
     or        $ra, (0x800E522C & 0xFFFF)
    sw         $zero, 0x18C($s0)
    j          vs_main_freeHeapR
     li        $a1, 0x7
alabel func_800E527C
    addu       $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s1, 0x14($sp)
    sll        $a2, 16
    or         $s1, $a2, $a1
    jal        func_800E5158
     addu      $a3, $zero, $zero
    beqz       $v0, 64b
     sw        $s0, 0x10($sp)
    addu       $s0, $a2, $zero
    jal        func_800D82CC
     addu      $a0, $s0, $zero
    jal        func_800D821C
     addu      $a0, $s0, $zero
    jal        func_800DBF00
     addu      $a0, $s0, $zero
    lw         $a1, 0x18C($s0)
    lbu        $a0, 0x88($s0)
    bnez       $a1, 65f
     addu      $a2, $zero, $zero
    li         $a1, 0x7
    jal        vs_main_allocHeapR
     li        $a0, 0x484
    beqz       $v0, 64b
     li        $a1, 0x484
    sw         $v0, 0x18C($s0)
    jal        func_800E4288
     addu      $a0, $v0, $zero
    lbu        $a0, 0x88($s0)
    addu       $s0, $v0, $zero
  65:
    jal        func_800E51C8
     addu      $a1, $s0, $zero
    sw         $s1, 0x160($s0)
    bgez       $zero, 64b
     li        $v0, 0x1
alabel func_800E5308
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    jal        func_800E65DC
     sw        $s2, 0x1C($sp)
    lui        $a3, (0x1F800378 >> 16)
    sw         $sp, (0x1F800378 & 0xFFFF)($a3)
    addiu      $sp, $a3, %lo(D_1F800374)
    lw         $s0, vs_battle_actors
    lui        $a3, (0x1F80037C >> 16)
  66:
    lbu        $t0, 0x8($s0)
    lw         $t1, 0x4($s0)
    and        $t0, 0xC0
    bnez       $t0, .L800E54F0
     sll       $t1, 2
    addu       $s2, $a3, $t1
    lw         $s2, (0x1F80037C & 0xFFFF)($s2)
    jal        func_800E45B4
     lw        $s2, 0x18C($s2)
    sw         $v0, 0x3FC($a3)
    beqz       $s2, .L800E54F0
     lbu       $t3, 0x3($s0)
    sb         $zero, 0x19A($s2)
    lhu        $t5, 0x156($s2)
    lw         $t4, 0x190($s2)
    beqz       $t5, 67f
     srl       $t2, $t4, 5
    add        $t5, -0x1
  67:
    sh         $t5, 0x156($s2)
    and        $t2, 0x7F
    beqz       $t2, 68f
     and       $t3, 0xFC
    add        $t2, -0x1
  68:
    li         $v0, 0x1
    sb         $v0, 0x6($s2)
    sb         $zero, 0x1($s2)
    li         $v0, 0x10
    sb         $v0, 0x15C($s2)
    sb         $zero, 0x2($s2)
    sb         $zero, 0x3($s2)
    lw         $t1, 0x4($s0)
    la         $t0, D_800F4538
    sll        $t1, 2
    addu       $t0, $t1
    lw         $t0, 0x0($t0)
    sb         $t3, 0x3($s0)
    add        $v0, $zero, -0xFE1
    and        $t4, $v0
    sll        $t2, 5
    or         $t4, $t2
    sw         $t4, 0x190($s2)
    lw         $t2, 0x5C($t0)
    lw         $t3, 0x1C($t0)
    lw         $t4, 0x20($t0)
    sw         $t2, 0x34($s2)
    sw         $t3, 0x4C($s2)
    sw         $t4, 0x50($s2)
    lw         $t6, D_800F58B8
    sll        $t5, $t2, 8
    srl        $t5, 24
    and        $t2, 0xFF
    sll        $t5, 6
    sll        $t2, 1
    addu       $t2, $t5
    addu       $t6, $t2, $t6
    lhu        $t6, 0x0($t6)
    and        $t2, $t3, 0xFFFF
    and        $t4, 0xFFFF
    srl        $t3, $t2, 6
    srl        $t5, $t4, 6
    sll        $t5, 16
    or         $t3, $t5
    sw         $t3, 0x120($s2)
    and        $t6, 0xF
    lbu        $v1, 0x125($s2)
    sb         $t6, 0x132($s2)
    sb         $t6, 0x154($s2)
    li         $v0, 0x0
    sw         $zero, 0x3D0($a3)
    bne        $v1, $v0, 69f
     lw        $t3, 0x160($s2)
    addu       $a1, $zero, $zero
    and        $a0, $t3, 0xFFFF
    srl        $a2, $t3, 16
    sub        $a0, $t2
    jal        func_800E4660
     sub       $a2, $t4
    slt        $v0, 0x400
    bnez       $v0, 70f
     addu      $a0, $s2, $zero
    la         $ra, .L800E54F0
    bgez       $zero, 72f
     addu      $a1, $zero, $zero
  69:
    lw         $a0, 0x168($s2)
    lw         $a1, 0x34($s2)
    li         $v0, 0xFF00FF
    and        $a0, $v0
    and        $a1, $v0
    bne        $a0, $a1, 71f
  70:
     li        $a1, 0x0
    jal        func_800DEEFC
     addu      $a0, $s2, $zero
    lbu        $a0, 0x88($s2)
    la         $ra, .L800E54F0
    bgez       $zero, func_800E5240
  71:
     srl       $a1, $t3, 23
    and        $a0, $t3, 0xFFFF
    srl        $a0, 7
    sll        $a1, 16
    or         $a0, $a1
    sw         $a0, 0x168($s2)
    addu       $a0, $s2, $zero
    li         $a1, 0x0
    jal        func_800E50A0
     addu      $a2, $zero, $zero
  .L800E54F0:
    lw         $s0, 0x0($s0)
    lui        $ra, (0x800DB898 >> 16)
    bnez       $s0, 66b
     lui       $a3, (0x1F800378 >> 16)
    lw         $sp, (0x1F800378 & 0xFFFF)($a3)
    bgez       $zero, func_800D9538
     or        $ra, (0x800DB898 & 0xFFFF)
  72:
    lbu        $t0, 0x19B($a0)
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    lw         $t1, 0x160($a0)
    bnez       $t0, func_800DF8A4
     srl       $t2, $t1, 16
    and        $t1, 0xFFFF
    sw         $t1, 0x17C($a0)
    sw         $t2, 0x180($a0)
    srl        $t3, $t1, 7
    srl        $t4, $t2, 7
    sll        $t4, 16
    or         $t3, $t4
    sw         $t3, 0x168($a0)
    lh         $a0, 0x4C($t8)
    lh         $a1, 0x50($t8)
    sub        $a0, $t1, $a0
    jal        ratan2
     sub       $a1, $t2, $a1
    addu       $ra, $t9, $zero
    addu       $a1, $v0, $zero
    bgez       $zero, func_800E19FC
     addu      $a0, $t8, $zero
endlabel func_800E4180
