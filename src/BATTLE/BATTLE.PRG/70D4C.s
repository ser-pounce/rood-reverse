.include "macro.inc"

.set noat
.set noreorder

glabel func_800D954C
    lw         $t0, 0x38($a0)
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    li         $a0, 0xFFFF00FF
    and        $t1, $a1, $a0
    lui        $t2, (0x1F8003DC >> 16)
    lbu        $t3, (0x1F8003DD & 0xFFFF)($t2)
    lbu        $t2, (0x1F8003DC & 0xFFFF)($t2)
    sll        $t1, 8
    sll        $t0, 8
    beq        $t0, $t1, 7f
     and       $t0, $a1, 0xFF
    sll        $t1, $a1, 8
    srl        $t1, 24
    addu       $a0, $t0, $zero
    jal        func_800E42EC
     addu      $a1, $t1, $zero
    sll        $a0, $t0, 7
    sll        $a1, $t1, 7
    add        $a0, 0x40
    add        $a1, 0x40
    lbu        $a2, 0x32($t8)
    slt        $t2, $t0, $t2
    slt        $t3, $t1, $t3
    and        $t2, $t3
    beqz       $t2, 7f
     lui       $a3, (0x1F8003C0 >> 16)
    lw         $v1, (0x1F8003C0 & 0xFFFF)($a3)
    sll        $t1, 6
    sll        $t0, 1
    addu       $v1, $t0
    addu       $v1, $t1
    lhu        $v1, 0x0($v1)
    sll        $a2, 8
    or         $a2, 0x80B0
    and        $a2, $v1, $a2
    bnez       $a2, 7f
     lui       $t0, %hi(vs_battle_actors)
    lw         $t0, %lo(vs_battle_actors)($t0)
    lbu        $t1, 0x88($t8)
    lhu        $t2, 0x94($t8)
    la         $t7, D_800F4538
    sll        $t1, 2
  0:
    lw         $v1, 0x4($t0)
    lui        $a3, (0x1F80037C >> 16)
    sll        $v1, 2
    addu       $a2, $a3, $v1
    beq        $v1, $t1, 6f
     addu      $t3, $t7, $v1
    lw         $t3, 0x0($t3)
    lw         $a2, (0x1F80037C & 0xFFFF)($a2)
    lbu        $t6, 0xA($t3)
    lhu        $t5, 0x94($a2)
    and        $t6, 0x1F
    beqz       $v1, 1f
     li        $a3, 0x80
    beqz       $t6, 1f
     nop
    lw         $t4, 0x174($a2)
    bgez       $zero, 2f
     lhu       $t6, 0x178($a2)
  1:
    lw         $t4, 0x1C($t3)
    lhu        $t6, 0x20($t3)
  2:
    and        $v1, $t4, 0xFFFF
    sra        $t4, 16
    sub        $v1, $a0
    bgez       $v1, 3f
     sub       $t4, $v0
    neg        $v1, $v1
  3:
    bgez       $t4, 4f
     sub       $t6, $a1
    neg        $t4, $t4
  4:
    bgez       $t6, 5f
     add       $t5, $t2
    neg        $t6, $t6
  5:
    slt        $v1, $t5, $v1
    slt        $t4, $a3, $t4
    slt        $t6, $t5, $t6
    or         $t4, $t6
    or         $v1, $t4
    beqz       $v1, 8f
  6:
     lw        $t0, 0x0($t0)
    nop
    bnez       $t0, 0b
     nop
    bgez       $zero, 9f
     li        $v0, 0x1
  7:
    bgez       $zero, 9f
     addu      $v0, $zero, $zero
  8:
    add        $v0, $zero, -0x1
  9:
    addu       $ra, $t9, $zero
    jr         $ra
     nop
endlabel func_800D954C

glabel func_800D96C8
    addu       $sp, -0x20
    sw         $s0, 0x0($sp)
    sw         $s1, 0x4($sp)
    sw         $s2, 0x8($sp)
    sw         $ra, 0xC($sp)
    sw         $s3, 0x10($sp)
    sw         $s4, 0x14($sp)
    sw         $s5, 0x18($sp)
    sw         $s6, 0x1C($sp)
    lbu        $t0, 0x7($a0)
    addu       $s0, $a0, $zero
    bnez       $t0, 19f
     lui       $a0, (0x1F8003C0 >> 16)
    lw         $t1, (0x1F8003DC & 0xFFFF)($a0)
    and        $s1, $a2, 0xFF
    sll        $s2, $a2, 8
    srl        $s2, 24
    and        $t0, $t1, 0xFF
    srl        $t1, 8
    and        $t1, 0xFF
    slt        $v0, $s1, $t0
    slt        $v1, $s2, $t1
    and        $v0, $v1
    beqz       $v0, 19f
     lw        $t0, (0x1F8003C0 & 0xFFFF)($a0)
    sll        $t1, $s2, 6
    sll        $t2, $s1, 1
    add        $t1, $t2
    add        $t1, $t0
    lhu        $t1, 0x0($t1)
    lbu        $t2, 0x2($s0)
    and        $t4, $t1, 0x30
    bnez       $t4, 19f
     lbu       $t3, 0x154($s0)
    bnez       $t2, 11f
     and       $t1, 0xF
    bne        $t1, $t3, 10f
  10:
     lbu       $t3, 0x132($s0)
    nop
    bne        $t1, $t3, 19f
  11:
     and       $a0, $a1, 0xFF
    sll        $a1, 8
    srl        $a1, 24
    sub        $s3, $s1, $a0
    jal        func_800E42EC
     sub       $s5, $s2, $a1
    addu       $t6, $v0, $zero
    addu       $a0, $s1, $zero
    jal        func_800E42EC
     addu      $a1, $s2, $zero
    addu       $s6, $v0, $zero
    bgez       $s3, 12f
     sub       $s4, $v0, $t6
    neg        $s5, $s5
  12:
    bgez       $s5, 13f
     slt       $t0, $s3, 0x2
    neg        $s5, $s5
  13:
    slt        $t1, $s5, 0x2
    and        $t0, $t1
    lbu        $t3, 0x3($s0)
    beqz       $t0, 14f
     addu      $a0, $s0, $zero
    jal        func_800D98E8
     addu      $a1, $a3, $zero
    bnez       $v0, 19f
     slt       $t1, $s4, 0x1
    or         $t1, $t3, $t1
    beqz       $t1, 16f
  14:
     lbu       $t1, 0xB2($s0)
    addu       $t0, $s3, $s5
    slt        $t0, $t1, $t0
    bnez       $t0, 19f
     lbu       $a0, 0x15E($s0)
    lhu        $t4, 0xB0($s0)
    and        $a0, 0xF8
    beqz       $a0, 15f
     nop
    li         $t4, 0x2000
  15:
    neg        $t2, $t4
    slt        $t0, $t4, $s4
    and        $t0, $t3
    bnez       $t0, 19f
     slt       $t2, $s4, $t2
    bnez       $t2, 19f
  16:
     lbu       $t0, 0xE5($s0)
    lbu        $t1, 0x5($s0)
    sll        $t0, 2
    lbu        $t2, 0x89($s0)
    beqz       $t1, 18f
     li        $v0, 0x1
    bne        $v0, $t2, 17f
     lw        $s3, 0xDC($s0)
    la         $v0, D_800F4538
    addu       $v0, $t0
    lhu        $t0, 0x1C($v0)
    sll        $a0, $s1, 7
    add        $a0, 0x40
    add        $s3, -0x60
    mult       $s3, $s3
    lhu        $t1, 0x20($v0)
    sll        $a1, $s2, 7
    add        $a1, 0x40
    sub        $a0, $t0
    jal        func_800E4660
     sub       $a1, $t1
    mflo       $v1
    slt        $v0, $v1
    bnez       $v0, 20f
  17:
     lw        $s4, 0x168($s0)
    lw         $a0, 0x34($s0)
    jal        func_800E45F4
     addu      $a1, $s4, $zero
    addu       $a1, $s4, $zero
    addu       $s5, $v0, $zero
    addu       $t0, $s1, $zero
    jal        func_800E4604
     addu      $t1, $s2, $zero
    slt        $t0, $v0, $s5
    beqz       $t0, 21f
     addu      $v0, $zero, $zero
  18:
    bgez       $zero, 21f
     li        $v0, 0x1
  19:
    bgez       $zero, 21f
     addu      $v0, $zero, $zero
  20:
    add        $v0, $zero, -0x1
  21:
    lw         $s0, 0x0($sp)
    lw         $s1, 0x4($sp)
    lw         $s2, 0x8($sp)
    lw         $ra, 0xC($sp)
    lw         $s3, 0x10($sp)
    lw         $s4, 0x14($sp)
    lw         $s5, 0x18($sp)
    lw         $s6, 0x1C($sp)
    jr         $ra
     addu      $sp, 0x20
endlabel func_800D96C8

glabel func_800D98E8
    lui        $a3, (0x1F8003D4 >> 16)
    lbu        $v1, (0x1F8003D2 & 0xFFFF)($a3)
    addu       $t7, $ra, $zero
    srlv       $v1, $v1, $a1
    and        $v1, 0x1
    beqz       $v1, 22f
     addu      $t0, $a3, $a1
    lbu        $v0, (0x1F8003D4 & 0xFFFF)($t0)
    jr         $ra
  22:
     addu      $t1, $a3, $a1
    lbu        $t1, 0x3EC($t1)
    lbu        $t0, 0xB3($a0)
    sll        $t2, $t1, 26
    sra        $t2, 30
    sll        $t1, 30
    sra        $t1, 30
    mult       $t0, $t1
    lhu        $t3, 0x4C($a0)
    mflo       $t1
    lhu        $t4, 0x50($a0)
    add        $t3, $t1
    mult       $t0, $t2
    lw         $v0, 0x34($a0)
    lbu        $v1, 0x3DC($a3)
    mflo       $t2
    and        $t5, $v0, 0xFF
    sll        $t6, $v0, 8
    srl        $t6, 24
    add        $t4, $t2
    srl        $t1, $t3, 7
    srl        $t2, $t4, 7
    sub        $t1, $t5
    sub        $t2, $t6
    add        $t1, 0x1
    add        $t2, 0x1
    li         $v0, 0x1
    sll        $t2, 2
    add        $t2, $t1
    lb         $t0, 0x3E0($a3)
    lw         $a2, 0x3F4($a3)
    addu       $t8, $a0, $zero
    bltz       $t0, 24f
     addu      $t9, $a1, $zero
    beqz       $a2, 23f
     mult      $v1, $t6
    lw         $v0, 0x3C4($a3)
    mflo       $v1
    addu       $v0, $v1, $v0
    addu       $v0, $t5
    lbu        $v0, 0x0($v0)
    nop
    srlv       $v0, $v0, $t0
    bgez       $zero, 24f
     and       $v0, 0x1
  23:
    addu       $a1, $t0, $zero
    jal        func_800E4690
     lw        $a0, 0x34($a0)
    addu       $a0, $t8, $zero
  24:
    bnez       $v0, 25f
     addu      $a1, $t4, $zero
    jal        func_800E42D4
     addu      $a0, $t3, $zero
    bgez       $zero, 26f
     addu      $a0, $t8, $zero
  25:
    lh         $v0, 0x4E($a0)
  26:
    lui        $a3, (0x1F8003EC >> 16)
    la         $t0, vs_battle_actors
    lw         $t0, 0x0($t0)
    lbu        $a1, 0x88($a0)
    la         $a2, D_800F4538
    addu       $t5, $a3, $t9
    lbu        $t5, (0x1F8003EC & 0xFFFF)($t5)
    addu       $ra, $t7, $zero
    sll        $t6, $t5, 26
    sra        $t6, 30
    sll        $t5, 30
    sra        $t5, 30
    lhu        $a3, 0xB8($a0)
    lhu        $t7, 0x94($a0)
    sll        $a3, 16
    or         $t7, $a3
  27:
    lw         $t1, 0x4($t0)
    lui        $v1, (0x1F800000 >> 16)
    beq        $a1, $t1, 37f
     sll       $t2, $t1, 2
    add        $t8, $t2, $a2
    lw         $t8, 0x0($t8)
    add        $t2, $v1
    lbu        $v1, 0xA($t8)
    lw         $t2, 0x37C($t2)
    and        $v1, 0x1F
    beqz       $t1, 28f
     nop
    beqz       $v1, 28f
     nop
    lw         $v1, 0x174($t2)
    bgez       $zero, 29f
     lhu       $at, 0x178($t2)
  28:
    lw         $v1, 0x1C($t8)
    lhu        $at, 0x20($t8)
  29:
    and        $a0, $v1, 0xFFFF
    sra        $a3, $v1, 16
    sub        $a0, $t3
    sub        $a3, $v0
    sub        $at, $t4
    blez       $t5, 30f
     nop
    bltz       $a0, 37f
     nop
  30:
    bgez       $t5, 31f
     nop
    bgtz       $a0, 37f
     nop
  31:
    blez       $t6, 32f
     nop
    bltz       $at, 37f
     nop
  32:
    bgez       $t6, 33f
     nop
    bgtz       $at, 37f
     nop
  33:
    bgtz       $a0, 34f
     lhu       $v1, 0x94($t2)
    neg        $a0, $a0
  34:
    bgtz       $a3, 35f
     lbu       $t8, 0xB3($t2)
    neg        $a3, $a3
  35:
    bgtz       $at, 36f
     addu      $v1, $t8
    neg        $at, $at
  36:
    and        $t8, $t7, 0xFFFF
    addu       $v1, $t8
    lhu        $t8, 0xB8($t2)
    sub        $a0, $v1
    bgtz       $a0, 37f
     sub       $at, $v1
    bgtz       $at, 37f
     srl       $v1, $t7, 16
    addu       $v1, $t8
    srl        $v1, 1
    sub        $a3, $v1
    bgtz       $a3, 37f
     nop
    bgez       $zero, 38f
     addu      $v1, $t1, 0x1
  37:
    lw         $t0, 0x0($t0)
    nop
    bnez       $t0, 27b
     addu      $v1, $zero, $zero
  38:
    lui        $a0, (0x1F8003D2 >> 16)
    lbu        $a1, (0x1F8003D2 & 0xFFFF)($a0)
    addu       $t0, $a0, $t9
    sb         $v1, (0x1F8003D4 & 0xFFFF)($t0)
    li         $a2, 0x1
    sllv       $a2, $a2, $t9
    or         $a1, $a2
    sb         $a1, (0x1F8003D2 & 0xFFFF)($a0)
    jr         $ra
     addu      $v0, $v1, $zero
endlabel func_800D98E8

glabel func_800D9B6C
    lui        $a2, (0x1F8003D1 >> 16)
    lbu        $t0, (0x1F8003D0 & 0xFFFF)($a2)
    mtc2       $a1, $4
    lbu        $t1, (0x1F8003D1 & 0xFFFF)($a2)
    srlv       $a3, $t0, $a1
    and        $a3, 0x1
    beqz       $a3, 39f
     srlv      $t1, $t1, $a1
    jr         $ra
     and       $v0, $t1, 0x1
  39:
    addu       $sp, -0x20
    sw         $ra, 0x10($sp)
    sw         $s0, 0x14($sp)
    sw         $s1, 0x18($sp)
    addu       $s0, $a0, $zero
    jal        func_800D98E8
     addu      $s1, $a1, $zero
    bnez       $v0, 45f
     and       $a3, $s1, 0x1
    lw         $t0, 0x34($s0)
    lui        $a2, (0x1F8003EC >> 16)
    addu       $a2, $s1
    lbu        $a2, (0x1F8003EC & 0xFFFF)($a2)
    lw         $t1, 0x120($s0)
    and        $a0, $t0, 0xFF
    sll        $a1, $t0, 8
    srl        $a1, 24
    and        $t0, $t1, 0xFF
    sll        $t1, 8
    srl        $t1, 24
    sll        $t2, $a2, 30
    sra        $t2, 30
    sll        $t3, $a2, 26
    sra        $t3, 30
    add        $t0, $t2
    add        $t1, $t3
    sra        $t0, 1
    sra        $t1, 1
    bne        $t0, $a0, 40f
     lui       $a2, (0x1F8003C0 >> 16)
    beq        $t1, $a1, 45f
     addu      $v0, $zero, $zero
  40:
    beqz       $a3, 41f
     sub       $t4, $t0, $a0
    sub        $t5, $t1, $a1
    add        $t4, 0x1
    add        $t5, 0x1
    sll        $t5, 2
    add        $t5, $t4, $t5
    add        $a3, $a2, $t5
    lb         $s1, 0x3E0($a3)
  41:
    lw         $t4, (0x1F8003F4 & 0xFFFF)($a2)
    lw         $t5, (0x1F8003C0 & 0xFFFF)($a2)
    bnez       $t4, 42f
     sll       $t1, 6
    addu       $t8, $a0, $zero
    addu       $t9, $a1, $zero
    lw         $a0, 0x34($s0)
    sll        $t0, 1
    addu       $t6, $t0, $t5
    addu       $t6, $t1
    jal        func_800E4690
     addu      $a1, $s1, $zero
    addu       $a0, $t8, $zero
    addu       $a1, $t9, $zero
    bgez       $zero, 43f
  42:
     lbu       $v1, (0x1F8003DC & 0xFFFF)($a2)
    lw         $t7, (0x1F8003C4 & 0xFFFF)($a2)
    mult       $a1, $v1
    lw         $v1, 0x38($s0)
    sll        $t0, 1
    addu       $t6, $t0, $t5
    addu       $t6, $t1
    srl        $v0, $v1, 10
    and        $v0, 0x3FC0
    and        $v1, 0xFF
    sll        $v1, 1
    or         $v1, $v0, $v1
    addu       $v1, $t5
    beq        $v1, $t6, 45f
     li        $v0, 0x1
    mflo       $v1
    addu       $v1, $t7
    addu       $v1, $a0
    lbu        $v1, 0x0($v1)
    nop
    srlv       $v0, $v1, $s1
    and        $v0, 0x1
  43:
    bnez       $v0, 45f
     lbu       $v1, 0x6($s0)
    lhu        $t6, 0x0($t6)
    xor        $v1, 0x1
    srl        $v0, $t6, 4
    and        $v0, $v1
    bnez       $v0, 45f
     srl       $v1, $t6, 5
    and        $v0, $v1, 0x1
    srl        $v1, $t6, 7
    and        $v1, 0x1
    or         $v0, $v1
    bnez       $v0, 45f
     lbu       $v1, 0x32($s0)
    srl        $v0, $t6, 8
    and        $v0, $v1, $v0
    bnez       $v0, 45f
     lbu       $t7, 0x29($s0)
    sll        $a0, 1
    sll        $a1, 6
    lbu        $t8, 0x2($s0)
    addu       $t9, $t5, $a0
    addu       $t9, $a1
    lhu        $t9, 0x0($t9)
    xor        $t8, 0x1
    and        $t7, $t8
    beqz       $t7, 44f
     sll       $t8, $t6, 28
    sll        $t7, $t9, 28
    beq        $t7, $t8, 44f
     lbu       $v1, 0x154($s0)
    li         $v0, 0x1
    sll        $v1, 28
    bne        $v1, $t8, 45f
  44:
     lui       $a3, (0x1F8003BC >> 16)
    lw         $a2, (0x1F8003BC & 0xFFFF)($a3)
    add        $t7, $t0, $t1
    add        $t7, $a2
    lhu        $t7, 0x0($t7)
    add        $t8, $a0, $a1
    add        $t8, $a2
    lhu        $t8, 0x0($t8)
    and        $t7, 0x1C00
    and        $t8, 0x1C00
    slt        $v0, $t8, $t7
  45:
    lui        $a3, (0x1F8003D1 >> 16)
    mfc2       $s1, $4
    lbu        $a0, (0x1F8003D0 & 0xFFFF)($a3)
    li         $v1, 0x1
    lbu        $a1, (0x1F8003D1 & 0xFFFF)($a3)
    sllv       $v1, $v1, $s1
    or         $a0, $v1
    beqz       $v0, 46f
     sb        $a0, (0x1F8003D0 & 0xFFFF)($a3)
    neg        $v1, $v1
    add        $v1, -0x1
    bgez       $zero, 47f
     and       $a1, $v1
  46:
    or         $a1, $v1
  47:
    sb         $a1, (0x1F8003D1 & 0xFFFF)($a3)
    srlv       $a1, $a1, $s1
    and        $v0, $a1, 0x1
    lw         $ra, 0x10($sp)
    lw         $s0, 0x14($sp)
    lw         $s1, 0x18($sp)
    jr         $ra
     addu      $sp, 0x20
endlabel func_800D9B6C

glabel func_800D9DD8
    lw         $a1, 0x68($a0)
    la         $v0, func_800DAA6C
    beq        $a1, $v0, 48f
     lw        $v0, 0x430($a0)
    lbu        $v1, 0x2D($a0)
    lw         $v0, 0x10($v0)
    li         $a1, 0x2
    and        $v0, $v1
    bnez       $v0, 49f
  48:
     li        $a2, 0x1
    jr         $ra
     sb        $a2, 0x12E($a0)
  49:
    sb         $a1, 0x12E($a0)
    bgez       $zero, func_800DD7CC
     addu      $a1, $a0, 0x134
endlabel func_800D9DD8

