.include "macro.inc"

.set noat
.set noreorder

glabel func_800DEEFC
    sll        $a3, $a1, 2
    lui        $a2, (0x1F8003C8 >> 16)
    sw         $a1, (0x1F8003C8 & 0xFFFF)($a2)
    lw         $a1, 0x54($a0)
    la         $a2, jtbl_800F16F8
    addu       $a2, $a3
    lw         $a2, 0x0($a2)
    lb         $a3, 0x15C($a0)
    li         $v0, 0x80
    sb         $v0, 0x8($a1)
    jr         $a2
     sb        $a3, 0xA($a1)
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    addu       $t7, $a1, $zero
    lw         $t0, 0x34($a0)
    lw         $t1, 0x168($a0)
    and        $a0, $t0, 0xFF
    srl        $a1, $t0, 8
    sll        $a1, 24
    and        $a2, $t1, 0xFF
    srl        $a3, $t1, 8
    sll        $a3, 24
    sub        $a0, $a2
    jal        ratan2
     sub       $a1, $a3
    addu       $ra, $t9, $zero
    addu       $a0, $t8, $zero
    addu       $a1, $t7, $zero
    bgez       $zero, 0f
     addu      $a2, $v0, $zero
    bgez       $zero, 0f
     lh        $a2, 0x188($a0)
    bgez       $zero, 0f
     sll       $a2, 9
  0:
    addu       $sp, -0x44
    sw         $s7, 0x38($sp)
    sw         $s0, 0x34($sp)
    sw         $s1, 0x30($sp)
    sw         $s2, 0x2C($sp)
    sw         $s3, 0x28($sp)
    sw         $s4, 0x24($sp)
    sw         $s5, 0x20($sp)
    sw         $s6, 0x1C($sp)
    sw         $ra, 0x18($sp)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    lw         $a3, 0x34($s0)
    lhu        $s2, 0x92($s0)
    and        $s4, $a3, 0xFF
    sll        $s5, $a3, 8
    srl        $s5, 24
    and        $a2, 0xFFF
    sh         $a2, 0xC($s1)
    add        $a0, $zero, 0xC00
    sub        $a2, $a0, $a2
    lbu        $a0, 0x1($s0)
    and        $a2, 0xFFF
    lw         $v0, 0x224($s0)
    beqz       $a0, 1f
     lhu       $s6, 0x4C($s0)
    and        $a0, $v0, 0x84
    bnez       $a0, 2f
     srl       $t9, $v0, 16
    and        $a0, $v0, 0x8400
    bnez       $a0, 2f
     srl       $t9, $v0, 24
  1:
    and        $a0, $v0, 0x42
    bnez       $a0, 3f
     srl       $t9, $v0, 16
    lui        $at, (0x420000 >> 16)
    and        $a0, $v0, $at
    bnez       $a0, 3f
     srl       $t9, $v0, 24
    add        $v1, $zero, 0x2
    bgez       $zero, 17f
     sb        $v1, 0x9($s1)
  2:
    add        $v1, $zero, 0xA
    bgez       $zero, 4f
     sb        $v1, 0x9($s1)
  3:
    add        $v1, $zero, 0x9
    sb         $v1, 0x9($s1)
  4:
    and        $t9, 0xFF
    addu       $t8, $a2, $zero
    jal        rcos
     addu      $a0, $t8, $zero
    mult       $v0, $t9
    jal        rsin
     addu      $a0, $t8, $zero
    mflo       $a0
    lw         $a3, 0x1F8003F4
    mult       $v0, $t9
    sra        $t0, $a0, 12
    add        $t0, $s6, $t0
    mflo       $a1
    lhu        $s7, 0x50($s0)
    sra        $t1, $a1, 12
    add        $t1, $s7, $t1
    sll        $a1, $t1, 16
    or         $s3, $t0, $a1
    sub        $a0, $t0, $s2
    sra        $a0, 7
    sub        $a0, $s4
    add        $t6, $a0, 0x1
    sub        $a0, $t1, $s2
    sra        $a0, 7
    sub        $a0, $s5
    add        $t7, $a0, 0x1
    add        $a0, $t0, $s2
    sra        $a0, 7
    sub        $a0, $s4
    add        $t8, $a0, 0x1
    add        $a0, $t1, $s2
    sra        $a0, 7
    sub        $a0, $s5
    add        $t9, $a0, 0x1
    beqz       $a3, 8f
     lui       $a0, (0x1F8003E0 >> 16)
    lbu        $a2, (0x1F8003DC & 0xFFFF)($a0)
    lw         $a3, (0x1F8003BC & 0xFFFF)($a0)
    mult       $a2, $s5
    sll        $t0, $t7, 2
    addu       $t0, $a0, $t0
    mflo       $a2
    lw         $a1, (0x1F8003C4 & 0xFFFF)($a0)
    addu       $t0, $t6
    addu       $a1, $a2
    addu       $a1, $s4
    lbu        $a1, 0x0($a1)
    lb         $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll        $t1, $s5, 6
    bltz       $t0, 5f
     sll       $t2, $s4, 1
    add        $t1, $t2
    add        $t1, $a3
    lhu        $t1, 0x0($t1)
    add        $t2, $s5, $t7
    add        $t2, -0x1
    sll        $t2, 6
    add        $t3, $s4, $t6
    add        $t3, -0x1
    sll        $t3, 1
    add        $t2, $t3
    add        $t2, $a3
    lhu        $t2, 0x0($t2)
    srl        $t1, 10
    and        $t1, 0x7
    srl        $t2, 10
    and        $t2, 0x7
    slt        $t4, $t1, $t2
    srlv       $t3, $a1, $t0
    and        $t3, 0x1
    or         $t3, $t4
    bnez       $t3, 12f
  5:
     sll       $t0, $t9, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t6
    lb         $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll        $t1, $s5, 6
    bltz       $t0, 6f
     sll       $t2, $s4, 1
    add        $t1, $t2
    add        $t1, $a3
    lhu        $t1, 0x0($t1)
    add        $t2, $s5, $t9
    add        $t2, -0x1
    sll        $t2, 6
    add        $t3, $s4, $t6
    add        $t3, -0x1
    sll        $t3, 1
    add        $t2, $t3
    add        $t2, $a3
    lhu        $t2, 0x0($t2)
    srl        $t1, 10
    and        $t1, 0x7
    srl        $t2, 10
    and        $t2, 0x7
    slt        $t4, $t1, $t2
    srlv       $t3, $a1, $t0
    and        $t3, 0x1
    or         $t3, $t4
    bnez       $t3, 12f
  6:
     sll       $t0, $t7, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t8
    lb         $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll        $t1, $s5, 6
    bltz       $t0, 7f
     sll       $t2, $s4, 1
    add        $t1, $t2
    add        $t1, $a3
    lhu        $t1, 0x0($t1)
    add        $t2, $s5, $t7
    add        $t2, -0x1
    sll        $t2, 6
    add        $t3, $s4, $t8
    add        $t3, -0x1
    sll        $t3, 1
    add        $t2, $t3
    add        $t2, $a3
    lhu        $t2, 0x0($t2)
    srl        $t1, 10
    and        $t1, 0x7
    srl        $t2, 10
    and        $t2, 0x7
    slt        $t4, $t1, $t2
    srlv       $t3, $a1, $t0
    and        $t3, 0x1
    or         $t3, $t4
    bnez       $t3, 12f
  7:
     sll       $t0, $t9, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t8
    lb         $t0, (0x1F8003E0 & 0xFFFF)($t0)
    sll        $t1, $s5, 6
    bltz       $t0, 17f
     sll       $t2, $s4, 1
    add        $t1, $t2
    add        $t1, $a3
    lhu        $t1, 0x0($t1)
    add        $t2, $s5, $t9
    add        $t2, -0x1
    sll        $t2, 6
    add        $t3, $s4, $t8
    add        $t3, -0x1
    sll        $t3, 1
    add        $t2, $t3
    add        $t2, $a3
    lhu        $t2, 0x0($t2)
    srl        $t1, 10
    and        $t1, 0x7
    srl        $t2, 10
    and        $t2, 0x7
    slt        $t4, $t1, $t2
    srlv       $t3, $a1, $t0
    and        $t3, 0x1
    or         $t3, $t4
    bnez       $t3, 12f
     nop
    bgez       $zero, 17f
  8:
     sll       $t0, $t7, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t6
    lb         $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw         $a0, 0x34($s0)
    bltz       $a1, 9f
     nop
    jal        func_800E4690
     nop
    bnez       $v0, 12f
  9:
     lui       $a0, (0x1F8003E0 >> 16)
    sll        $t0, $t9, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t6
    lb         $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw         $a0, 0x34($s0)
    bltz       $a1, 10f
     nop
    jal        func_800E4690
     nop
    bnez       $v0, 12f
  10:
     lui       $a0, (0x1F8003E0 >> 16)
    sll        $t0, $t7, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t8
    lb         $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw         $a0, 0x34($s0)
    bltz       $a1, 11f
     nop
    jal        func_800E4690
     nop
    bnez       $v0, 12f
  11:
     lui       $a0, (0x1F8003E0 >> 16)
    sll        $t0, $t9, 2
    addu       $t0, $a0, $t0
    addu       $t0, $t8
    lb         $a1, (0x1F8003E0 & 0xFFFF)($t0)
    lw         $a0, 0x34($s0)
    bltz       $a1, 17f
     nop
    jal        func_800E4690
     nop
    beqz       $v0, 17f
  12:
     sll       $t0, $s4, 7
    sll        $t1, $s5, 7
    addu       $t0, 0x40
    addu       $t1, 0x40
    and        $t2, $s3, 0xFFFF
    srl        $t3, $s3, 16
    slt        $a0, $t2, $t0
    bnez       $a0, 13f
     add       $t8, $t0, 0x3F
    bgez       $zero, 14f
     sub       $t8, $s2
  13:
    add        $t8, $t0, -0x40
    add        $t8, $s2
  14:
    sub        $t8, $s6
    slt        $a0, $t3, $t1
    bnez       $a0, 15f
     add       $t9, $t1, 0x3F
    bgez       $zero, 16f
     sub       $t9, $s2
  15:
    add        $t9, $t1, -0x40
    add        $t9, $s2
  16:
    sub        $t9, $s7
    or         $a0, $t8, $t9
    lw         $a1, 0x9C($s0)
    beqz       $a0, 17f
     lui       $a3, (0xFF00FF >> 16)
    or         $a3, (0xFF00FF & 0xFFFF)
    and        $a2, $a1, $a3
    sll        $t0, $s5, 16
    or         $t0, $s4
    beq        $t0, $a2, 17f
     li        $a0, 0xD
    sw         $t0, 0x9C($s0)
    sb         $a0, 0x9($s1)
    sll        $t9, 12
    sll        $t8, 12
    sw         $t8, 0xC($s1)
    sw         $t9, 0x10($s1)
  17:
    lw         $ra, 0x18($sp)
    lw         $s7, 0x38($sp)
    lw         $s0, 0x34($sp)
    lw         $s1, 0x30($sp)
    lw         $s2, 0x2C($sp)
    lw         $s3, 0x28($sp)
    lw         $s4, 0x24($sp)
    lw         $s5, 0x20($sp)
    lw         $s6, 0x1C($sp)
    jr         $ra
     addu      $sp, 0x44
  alabel func_800DF434
    li         $a2, 0x14
    jr         $ra
     sb        $a2, 0x9($a1)
  alabel func_800DF440
    li         $a2, 0x1
    jr         $ra
     sb        $a2, 0x9($a1)
  18:
  alabel func_800DF44C
    li         $a2, 0x2
    jr         $ra
     sb        $a2, 0x9($a1)
  alabel func_800DF458
    lw         $a3, 0x170($a0)
    li         $a2, 0x15
    sw         $a3, 0xC($a1)
    sb         $a2, 0x9($a1)
    and        $a0, $a3, 0xFF
    sll        $a1, $a3, 8
    bgez       $zero, func_800E4C1C
     srl       $a1, 24
    lw         $a3, 0x170($a0)
    li         $a2, 0x16
    addu       $t9, $ra, $zero
    addu       $t7, $a1, $zero
    lh         $t8, 0xBE($a0)
    sb         $a2, 0x9($a1)
    and        $a0, $a3, 0xFF
    sll        $a0, 7
    sll        $a1, $a3, 8
    srl        $a1, 17
    addu       $t6, $a0, 0x40
    addu       $a1, 0x40
    jal        func_800E42D4
     sh        $a1, 0x10($t7)
    addu       $ra, $t9, $zero
    add        $v0, $t8
    sll        $v0, 16
    or         $v0, $t6
    jr         $ra
     sw        $v0, 0xC($t7)
    lhu        $a3, 0xBA($a0)
    lhu        $a0, 0x188($a0)
    sll        $a3, 16
    li         $a2, 0x3
    and        $a0, 0xFFF
    sb         $a2, 0x9($a1)
    or         $a3, $a0
    jr         $ra
     sw        $a3, 0xC($a1)
  19:
    li         $a2, 0x17
    sb         $a2, 0x9($a1)
    addu       $t5, $ra, $zero
    addu       $t6, $a0, $zero
    lw         $a2, 0x170($t6)
    addu       $t7, $a1, $zero
    mtc2       $a2, $12
    sw         $a2, 0xC($t7)
    and        $a0, $a2, 0xFF
    sll        $a0, 7
    sll        $a1, $a2, 8
    srl        $a1, 17
    addu       $a0, 0x40
    addu       $t8, $a0, $zero
    addu       $a1, 0x40
    addu       $t9, $a1, $zero
    jal        func_800E42D4
     sh        $a1, 0x178($t6)
    sll        $v0, 16
    or         $v0, $t8
    sw         $v0, 0x174($t6)
    lhu        $a0, 0x4C($t6)
    lhu        $a1, 0x50($t6)
    sub        $a0, $t8
    jal        ratan2
     sub       $a1, $t9
    addu       $ra, $t5, $zero
    sw         $v0, 0x10($t7)
    mfc2       $a2, $12
    sw         $v0, 0x10($t7)
    and        $a0, $a2, 0xFF
    sll        $a1, $a2, 8
    bgez       $zero, func_800E4C1C
     srl       $a1, 24
    lw         $t7, 0x17C($a0)
    lw         $t8, 0x184($a0)
    lw         $t9, 0x180($a0)
    li         $a2, 0x13
    sb         $a2, 0x9($a1)
    sw         $t7, 0xC($a1)
    sw         $t8, 0x14($a1)
    jr         $ra
     sw        $t9, 0x10($a1)
    bgez       $zero, 20f
     li        $a2, 0x10
    li         $a2, 0x11
  20:
    lw         $t7, 0x17C($a0)
    lw         $t8, 0x184($a0)
    lw         $t9, 0x180($a0)
    sb         $a2, 0x9($a1)
    sll        $t8, 16
    and        $t7, 0xFFFF
    or         $t8, $t7
    sw         $t8, 0xC($a1)
    jr         $ra
     sh        $t9, 0x10($a1)
    lhu        $a3, 0x188($a0)
    li         $a2, 0x6
    lhu        $t9, 0x13A($a0)
    and        $a3, 0xFFFF
    sll        $t9, 16
    or         $a3, $t9
    sb         $a2, 0x9($a1)
    jr         $ra
     sw        $a3, 0xC($a1)
    addu       $t5, $ra, $zero
    addu       $t7, $a0, $zero
    addu       $t8, $a1, $zero
    jal        func_800E42E0
     lw        $a0, 0x34($t7)
    addu       $t6, $v0, $zero
    lw         $t9, 0x170($t7)
    jal        func_800E42E0
     addu      $a0, $t9, $zero
    lhu        $a0, 0xB0($t7)
    sub        $v0, $t6
    bgez       $v0, 21f
     lhu       $a3, 0x15E($t7)
    neg        $v0, $v0
  21:
    slt        $v0, $a0
    addu       $a0, $t7, $zero
    addu       $a1, $t8, $zero
    addu       $ra, $t5, $zero
    bnez       $v0, 22f
     and       $t0, $a3, 0x8
    bnez       $t0, 19b
     and       $v0, $a3, 0x30
    bnez       $v0, 23f
     li        $a2, 0x12
    and        $t0, $a3, 0xC0
    bnez       $t0, 23f
     li        $a2, 0xE
  22:
    li         $a2, 0xB
  23:
    addu       $a3, $t5, $zero
    sb         $a2, 0x9($t8)
    sw         $t9, 0xC($t8)
    and        $t3, $t9, 0xFF
    sll        $a0, $t3, 7
    sll        $t4, $t9, 8
    srl        $t4, 24
    sll        $a1, $t4, 7
    addu       $a0, 0x40
    addu       $t6, $a0, $zero
    addu       $a1, 0x40
    jal        func_800E42D4
     sh        $a1, 0x178($t7)
    sll        $v0, 16
    or         $v0, $t6
    sw         $v0, 0x174($t7)
    lbu        $t6, 0x1($t7)
    addu       $ra, $a3, $zero
    lw         $v0, 0x224($t7)
    beqz       $t6, 24f
     and       $v1, $v0, 0x84
    bnez       $v1, 25f
     srl       $t6, $v0, 16
    and        $v1, $v0, 0x8400
    bnez       $v1, 25f
     srl       $t6, $v0, 24
  24:
    and        $v1, $v0, 0x42
    bnez       $v1, 25f
     srl       $t6, $v0, 16
    and        $v1, $v0, 0x4200
    bnez       $v1, 25f
     srl       $t6, $v0, 24
    addu       $a0, $t7, $zero
    bgez       $zero, 18b
     addu      $a1, $t8, $zero
  25:
    and        $t6, 0xFF
    sw         $t6, 0x10($t8)
    lw         $v0, 0x4($t8)
    and        $v1, $t9, 0xFF00
    beqz       $v0, 26f
     addu      $a0, $t3, $zero
    beqz       $v1, func_800E4C1C
     addu      $a1, $t4, $zero
  26:
    jr         $ra
     nop
    li         $a2, 0x8
    jr         $ra
     sb        $a2, 0x9($a1)
    lw         $t9, 0x58($a0)
    lhu        $a3, 0x18A($a0)
    lh         $v0, 0x26($t9)
    lh         $v1, 0x14($t9)
    and        $a3, 0xFFF
    addu       $t1, $v1, $v0
    sub        $t2, $a3, $t1
    and        $t2, 0xFFF
    slt        $t3, $t2, 0x800
    bnez       $t3, 27f
     lbu       $t4, 0x2A($a0)
    add        $t3, $zero, -0x1
    add        $t5, $zero, -0x320
    slt        $t6, $t5, $v1
    bgez       $zero, 28f
  27:
     add       $t5, $zero, 0x320
    slt        $t6, $v1, $t5
    add        $t3, $zero, 0x1
  28:
    and        $t4, $t6
    bnez       $t4, 29f
     li        $a2, 0x7
    li         $a2, 0x3
  29:
    lhu        $t4, 0x13A($a0)
    add        $t7, $zero, 0x1000
    sb         $a2, 0x9($a1)
    sub        $t7, $t2
    slt        $t0, $t2, 0x1
    slt        $t6, $t2, $t4
    slt        $t5, $t7, $t4
    or         $t7, $t5, $t6
    or         $t7, $t0
    beqz       $t7, 30f
     nop
    li         $t7, 0x4
    sb         $t7, 0x9($a1)
    bgez       $zero, 31f
     addu      $a0, $a3, $zero
    add        $t0, $zero, 0x3
    beq        $a2, $t0, 31f
     sub       $a0, $a3, $v1
    bgez       $zero, 31f
     sub       $a0, $a3, $v0
  30:
    mult       $t3, $t4
    add        $t0, $zero, 0x3
    mflo       $t2
    beq        $a2, $t0, 31f
     add       $a0, $t2, $v0
    add        $a0, $t2, $v1
  31:
    and        $a0, 0xFFFF
    sll        $t4, 16
    or         $a0, $t4
    jr         $ra
     sw        $a0, 0xC($a1)
    lw         $t0, 0x22C($a0)
    la         $v1, D_800F4538
    lw         $t1, 0x4($t0)
    li         $t9, 0x18
    srl        $a2, $t1, 3
    and        $a2, 0x3
    and        $a3, $t1, 0x7
    sll        $t1, $a2, 16
    or         $t1, $a3
    sll        $a3, 5
    sll        $a2, 3
    add        $a3, $a2
    add        $a3, $a0
    lw         $a2, 0x230($a3)
    sw         $t1, 0xC($a1)
    srl        $a2, 3
    and        $a2, 0x3
    add        $a3, $zero, 0x1
    sllv       $a3, $a3, $a2
    and        $a3, 0x6
    lw         $t1, 0xC($t0)
    bnez       $a3, 32f
     and       $t2, $t1, 0xF
    srl        $a3, $t1, 7
    and        $a3, 0xFFF
    sll        $t2, 2
    addu       $v1, $t2
    lw         $v1, 0x0($v1)
    sll        $a3, 16
    lw         $v0, 0x1C($v1)
    lhu        $v1, 0x20($v1)
    sub        $v0, $a3
    sw         $v0, 0x10($a1)
    bgez       $zero, 33f
     sh        $v1, 0x14($a1)
  32:
    srl        $v0, $t1, 4
    and        $v0, 0x7
    sll        $v0, 16
    and        $t1, 0xF
    or         $v0, $t1
    sw         $v0, 0x10($a1)
  33:
    jr         $ra
     sb        $t9, 0x9($a1)
endlabel func_800DEEFC

