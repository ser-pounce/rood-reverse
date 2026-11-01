.include "macro.inc"

.set noat
.set noreorder

glabel func_800DB370
    addu       $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    sw         $s2, 0xC($sp)
    la         $t0, D_800F4538
    sll        $v0, $a1, 2
    addu       $t0, $v0
    lw         $t0, 0x0($t0)
    lui        $t1, (0x1F80037C >> 16)
    addu       $t1, $v0
    lw         $t1, (0x1F80037C & 0xFFFF)($t1)
    addu       $s0, $a0, $zero
    addu       $s1, $a3, $zero
    lbu        $t2, 0xE5($s0)
    beqz       $t1, 5f
     lh        $t3, 0x15E($s0)
    beq        $t2, $a1, 0f
     and       $t3, 0x38
    sw         $zero, 0xE4($s0)
    sw         $zero, 0xE8($s0)
  0:
    lbu        $v0, 0xA($t0)
    sb         $a1, 0xE5($s0)
    sw         $a2, 0xDC($s0)
    bnez       $t3, 2f
     and       $v0, 0x1F
    beqz       $v0, 2f
     nop
    lw         $v0, 0x60($t0)
    nop
    sw         $v0, 0x168($s0)
    and        $t0, $v0, 0xFF00
    beqz       $t0, 4f
     srl       $t0, 8
    add        $a0, $t0, -0x2
  1:
    jal        func_8008E2D4
     addu      $s2, $a0, $zero
    lw         $a1, 0x0($v0)
    lw         $a2, 0x8($v0)
    addu       $a3, $s0, 0x168
    jal        func_800DFA54
     addu      $a0, $s2, $zero
    lw         $a0, 0x168($s0)
    nop
    sw         $a0, 0xEC($s0)
    sll        $a1, $a0, 8
    srl        $a1, 24
    sll        $a1, 1
    and        $a0, 0xFF
    sll        $a0, 1
    or         $a0, $a1
    bgez       $zero, 4f
     sw        $a0, 0xF4($s0)
  2:
    lbu        $v0, 0x29($s0)
    lbu        $v1, 0xC($t0)
    or         $v0, $t3
    beqz       $v0, 3f
     and       $v1, 0xF
    beqz       $v1, 3f
     add       $a0, $v1, -0x2
    bgez       $zero, 1b
     nop
  3:
    lw         $v0, 0x5C($t0)
    nop
    sw         $v0, 0x168($s0)
  4:
    addu       $a0, $s0, $zero
    jal        func_800E24EC
     addu      $a1, $s1, $zero
  5:
    lw         $ra, 0x18($sp)
    addu       $a0, $s0, $zero
    lw         $s0, 0x10($sp)
    lw         $s1, 0x14($sp)
    lw         $s2, 0xC($sp)
    addu       $sp, 0x20
    bnez       $v0, func_800DB4AC
     li        $a1, 0x1
    jr         $ra
     li        $a1, 0x0
endlabel func_800DB370

glabel func_800DB4AC
    lbu        $v0, 0x8A($a0)
    add        $v1, $zero, -0x1
    bne        $v0, $a1, 6f
     sb        $a1, 0x89($a0)
  .L800DB4BC:
    jr         $ra
  6:
     li        $v0, 0x1
    bne        $v0, $a1, 7f
     li        $v0, 0x3
    sw         $zero, 0xE4($a0)
    bgez       $zero, 15f
     sh        $zero, 0xE8($a0)
  7:
    bne        $v0, $a1, 8f
     li        $v0, 0x6
    sh         $zero, 0xC0($a0)
    bgez       $zero, 15f
     sh        $zero, 0xD2($a0)
  8:
    bne        $v0, $a1, 9f
     li        $v0, 0x5
    sb         $zero, 0x10C($a0)
    add        $v0, $zero, -0x1
    bgez       $zero, 15f
     sw        $v0, 0x108($a0)
  9:
    bne        $v0, $a1, 15f
     add       $v0, $zero, -0x1
    lbu        $t0, 0x101($a0)
    lw         $t1, D_800F58D8
    sll        $t0, 4
    lw         $t3, 0x34($a0)
    addu       $t1, $t0
    li         $t2, 0x8
    sll        $t4, $t3, 8
    srl        $t4, 24
    and        $t3, 0xFF
  10:
    lh         $t0, 0x0($t1)
    nop
    bgez       $t0, 13f
     and       $a2, $t0, 0x1F
    srl        $a3, $t0, 5
    and        $a3, 0x1F
    sub        $a2, $t3
    bgez       $a2, 11f
     sub       $a3, $t4
    neg        $a2, $a2
  11:
    bgez       $a3, 12f
     nop
    neg        $a3, $a3
  12:
    addu       $a2, $a3
    sltu       $a3, $a2, $v0
    beqz       $a3, 13f
     li        $a3, 0x8
    addu       $v0, $a2, $zero
    subu       $v1, $a3, $t2
  13:
    add        $t2, -0x1
    bgtz       $t2, 10b
     addu      $t1, 0x2
    bltz       $v1, 14f
     li        $v0, 0x1
    sb         $v1, 0x100($a0)
  14:
    sb         $zero, 0x104($a0)
  15:
    sb         $a1, 0x8A($a0)
    sll        $a2, $a1, 1
    addu       $a2, $a0, $a2
    bgez       $zero, func_800E4BB8
     sb        $zero, 0x474($a2)
endlabel func_800DB4AC

glabel func_800DB5B0
    lw         $a1, 0xCC($a0)
    lw         $a2, 0xC8($a0)
endlabel func_800DB5B0

glabel func_800DB5B8
    addu       $t9, $ra, $zero
    addu       $t8, $a1, $zero
    addu       $t7, $a2, $zero
    jal        func_800DB4AC
     li        $a1, 0x3
    addu       $ra, $t9, $zero
    addu       $a1, $t8, $zero
    bgez       $zero, func_800E1EAC
     addu      $a2, $t7, $zero
endlabel func_800DB5B8

glabel func_800DB5DC
    sw         $a1, 0x168($a0)
    addu       $t9, $ra, $zero
    addu       $t8, $a2, $zero
    jal        func_800DB4AC
     li        $a1, 0x2
    addu       $ra, $t9, $zero
    bgez       $zero, func_800E5030
     addu      $a1, $t8, $zero
endlabel func_800DB5DC

glabel func_800DB5FC
    lw         $a3, 0x1F8003F4
    beqz       $a2, .L800DB4BC
     addu      $t9, $ra, $zero
    jal        func_800DB4AC
     li        $a1, 0x5
    bgez       $zero, func_800E23AC
     addu      $ra, $t9, $zero
endlabel func_800DB5FC

glabel func_800DB61C
    addu       $sp, -0x20
    sw         $s0, 0x10($sp)
    sw         $ra, 0x18($sp)
    lw         $t0, vs_battle_actors
    addu       $s0, $a0, $zero
    addu       $t5, $zero, $zero
    addu       $t7, $zero, $zero
    addu       $t8, $zero, $zero
  16:
    lw         $t1, 0x4($t0)
    la         $t2, D_800F4538
    sll        $t1, 2
    addu       $v0, $t1, $s0
    lw         $v0, 0x1A4($v0)
    addu       $v1, $t1, $t2
    srl        $v0, 5
    and        $v0, 0x7
    slt        $v0, 0x7
    bnez       $v0, 17f
     li        $t6, 0x1
    lw         $v1, 0x0($v1)
    addu       $t8, 0x1
    lh         $t1, 0x1C($v1)
    lh         $t3, 0x20($v1)
    add        $t5, $t1
    add        $t7, $t3
    beq        $t6, $t8, 17f
     nop
    srl        $t5, 1
    srl        $t7, 1
  17:
    lw         $t0, 0x0($t0)
    nop
    bnez       $t0, 16b
     nop
    blez       $t8, 18f
     li        $v0, 0x5A
    sh         $v0, 0x114($s0)
    srl        $t5, 7
    srl        $t7, 7
    sll        $t7, 16
    or         $t5, $t7
    bgez       $zero, 20f
     sw        $t5, 0x110($s0)
  18:
    lhu        $v0, 0x114($s0)
    lbu        $v1, 0x8A($s0)
    beqz       $v0, 19f
     li        $t0, 0x4
    add        $v0, -0x1
  19:
    beqz       $v0, 21f
     sh        $v0, 0x114($s0)
    bne        $t0, $v1, 21f
     addu      $v0, $zero, $zero
  20:
    lw         $v1, 0x110($s0)
    li         $v0, 0x1
    sb         $v0, 0x4($s0)
    sll        $t1, $v1, 8
    srl        $t1, 24
    and        $t0, $v1, 0xFF
    sll        $t0, 7
    sll        $t1, 7
    addu       $t0, 0x40
    addu       $t1, 0x40
    sw         $t0, 0x17C($s0)
    sw         $t1, 0x180($s0)
    jal        func_800E4FE0
     sw        $v1, 0x168($s0)
    li         $v0, 0x1
  21:
    lw         $ra, 0x18($sp)
    addu       $a0, $s0, $zero
    lw         $s0, 0x10($sp)
    addu       $sp, 0x20
    bnez       $v0, func_800DB4AC
     li        $a1, 0x4
    jr         $ra
     nop
endlabel func_800DB61C

glabel func_800DB74C
    addu       $sp, -0x20
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    sw         $ra, 0x18($sp)
    la         $v0, D_800F4538
    sll        $v1, $a1, 2
    addu       $v0, $v1
    lw         $v0, 0x0($v0)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    lh         $t0, 0x1C($v0)
    lh         $t1, 0x20($v0)
    lw         $t2, 0x5C($v0)
    sw         $t0, 0x17C($a0)
    sw         $t1, 0x180($a0)
    jal        func_800E2B2C
     sw        $t2, 0x168($a0)
    addu       $a0, $s0, $zero
    lw         $s0, 0x10($sp)
    lw         $s1, 0x14($sp)
    lw         $ra, 0x18($sp)
    li         $a1, 0x6
    bnez       $v0, func_800DB4AC
     addu      $sp, 0x20
  .L800DB7B0:
    jr         $ra
endlabel func_800DB74C

glabel func_800DB7B4
    li         $t2, 0x1
    lbu        $t0, 0x12D($a0)
    li         $t1, 0x0
    beq        $t0, $t1, .L800DB7B0
     li        $t3, 0x2
    bne        $t0, $t2, 22f
     lw        $v0, 0x54($a0)
    nop
    lbu        $v0, 0x9($v0)
    nop
    slt        $v0, 0x9
    beqz       $v0, 22f
     nop
    bgez       $zero, func_800DEEFC
     li        $a1, 0x1
  22:
    addu       $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    jal        func_800E678C
     addu      $s0, $a0, $zero
    sb         $zero, 0x12D($s0)
    addu       $a0, $s0, $zero
    lw         $s0, 0x10($sp)
    lw         $ra, 0x18($sp)
    li         $a1, 0x2
    bgez       $zero, func_800DEEFC
     addu      $sp, 0x20
endlabel func_800DB7B4

glabel func_800DB820
    addu       $sp, -0x20
    sw         $s0, 0x10($sp)
    sw         $ra, 0x18($sp)
    jal        func_800DAD9C
     addu      $s0, $a0, $zero
    bnez       $v0, 24f
     addu      $a0, $s0, $zero
    jal        func_800DB0BC
     nop
    bnez       $v0, 24f
     lw        $v1, 0x68($s0)
    nop
    beqz       $v1, 23f
     nop
    jalr       $v1
     addu      $a0, $s0, $zero
    bnez       $v0, 24f
     addu      $a0, $s0, $zero
  23:
    lw         $ra, 0x18($sp)
    lw         $s0, 0x10($sp)
    bgez       $zero, func_800DB5B0
     addu      $sp, 0x20
  24:
    lw         $ra, 0x18($sp)
    lw         $s0, 0x10($sp)
    jr         $ra
     addu      $sp, 0x20
endlabel func_800DB820

glabel func_800DB888
    lw         $s3, 0x20($sp)
    lw         $s4, 0x24($sp)
endlabel func_800DB888

glabel func_800DB890
    lw         $s5, 0x28($sp)
endlabel func_800DB890

glabel func_800DB894
    lw         $s1, 0x14($sp)
endlabel func_800DB894

glabel func_800DB898
    lw         $s2, 0x1C($sp)
endlabel func_800DB898

glabel func_800DB89C
    lw         $ra, 0x18($sp)
    lw         $s0, 0x10($sp)
    jr         $ra
     addu      $sp, 0x30
endlabel func_800DB89C

glabel func_800DB8AC
    addu       $t6, $ra, $zero
    lhu        $t7, 0x8E($a0)
    jal        func_800DBCB4
     lhu       $t5, 0x98($a0)
    bnez       $t7, 25f
     li        $v0, 0x1
    bnez       $t5, 25f
     addu      $v0, $zero, $zero
    lw         $t0, 0xC($a1)
    lw         $t1, D_800F58BC
    and        $t0, 0xF
    sll        $t0, 2
    addu       $t0, $a0
    lw         $t0, 0x1A4($t0)
    lw         $t2, 0x24($t1)
    lbu        $t4, 0xD($t1)
    and        $t0, 0x1
    beqz       $t0, 25f
     sltu      $t2, $t4, $t2
    lbu        $t3, 0x88($a0)
    bnez       $t2, 25f
     li        $t2, 0x1
    lhu        $t0, 0x10($t1)
    sllv       $t2, $t2, $t3
    and        $t0, $t2
    bnez       $t0, 25f
     li        $v0, 0x1
    lbu        $t2, 0x12($t1)
    addu       $v0, $zero, $zero
    sltu       $t4, $t2
    bnez       $t4, 25f
     nop
    li         $v0, 0x1
  25:
    addu       $ra, $t6, $zero
    jr         $ra
endlabel func_800DB8AC

glabel func_800DB93C
    lui        $t0, (0x1F8003C0 >> 16)
    addu       $sp, -0x30
    sw         $s2, 0x1C($sp)
    sw         $s0, 0x10($sp)
    sw         $ra, 0x18($sp)
    lw         $t0, (0x1F8003C0 & 0xFFFF)($t0)
    sll        $a1, 8
    srl        $a1, 8
    and        $t1, $a1, 0xFF
    srl        $t2, $a1, 16
    sll        $t4, $t2, 6
    sll        $t3, $t1, 1
    addu       $v0, $t3, $t4
    addu       $v0, $t0
    lhu        $v0, 0x0($v0)
    addu       $s0, $a0, $zero
    addu       $s2, $a1, $zero
    lbu        $v1, 0xB2($a0)
    sll        $v0, 26
    bgez       $v0, func_800DB898
     addu      $v0, $a1, $zero
    slt        $v0, $v1, 0x3
    lui        $t0, (0x1F8003EC >> 16)
    addu       $t0, $a2
    lbu        $t0, (0x1F8003EC & 0xFFFF)($t0)
    bnez       $v0, 26f
     addu      $t4, $v1, $zero
    li         $t4, 0x3
  26:
    sll        $t5, $t0, 30
    sra        $t5, 30
    sll        $t6, $t0, 26
    sra        $t6, 30
    lw         $t7, 0x1F8003C0
    addu       $t3, $zero, $zero
  27:
    add        $t1, $t5
    add        $t2, $t6
    and        $t1, 0xFF
    and        $t2, 0xFF
    sll        $a0, $t2, 6
    sll        $a1, $t1, 1
    add        $a0, $a1
    addu       $t0, $a0, $t7
    lhu        $t0, 0x0($t0)
    sll        $a0, $t2, 16
    or         $s2, $a0, $t1
    addu       $t3, 0x1
    sll        $t0, 26
    bltz       $t0, 28f
     slt       $v0, $t3, $t4
    beqz       $v0, 29f
     addu      $a0, $s0, $zero
    addu       $a1, $a3, $zero
    addu       $a3, $a2, $zero
    jal        func_800D96C8
     addu      $a2, $s2, $zero
    li         $v1, 0x1
    bne        $v0, $v1, 29f
     addu      $a0, $s0, $zero
    la         $ra, 29f
    bgez       $zero, func_800D954C
     addu      $a1, $s2, $zero
  28:
    bnez       $v1, 27b
     addu      $v0, $zero, $zero
  29:
    sll        $v0, 24
    bgez       $zero, func_800DB898
     or        $v0, $s2, $v0
    lbu        $v0, 0xE($a0)
    addu       $a1, $sp, -0x30
    beqz       $v0, func_800DA1D4
     sw        $s0, 0x10($a1)
    addu       $s0, $a0, $zero
    sw         $ra, 0x18($a1)
    addu       $sp, $a1, $zero
    jal        func_800DB61C
     li        $a1, 0x1
    bnez       $v0, func_800DB89C
     li        $v0, 0x1
    jal        func_800DB5B0
     addu      $a0, $s0, $zero
    bgez       $zero, func_800DB89C
     li        $v0, 0x1
    lbu        $v0, 0xE($a0)
    lbu        $v1, 0x131($a0)
    bnez       $v0, func_800DB61C
     li        $a1, 0x1
    sllv       $a1, $a1, $v1
    and        $a1, 0x3
    beqz       $a1, func_800DA1D4
     and       $a1, 0x1
    lw         $a2, 0x58($a0)
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s2, 0x1C($sp)
    sw         $s1, 0x14($sp)
    lbu        $a2, 0xA($a2)
    addu       $s0, $a0, $zero
    and        $a2, 0x20
    lw         $a3, 0x430($s0)
    bnez       $a2, 30f
     li        $s2, 0x140
    li         $s2, 0x100
  30:
    lw         $s1, 0xC($a3)
    beqz       $a1, 31f
     lw        $a0, 0x8($a3)
    jal        vs_gte_rsqrt
     nop
    slt        $v1, $s2, $v0
    bnez       $v1, 31f
     nop
    addu       $s2, $v0, $zero
  31:
    addu       $a2, $s2, $zero
    and        $a1, $s1, 0xF
    addu       $a0, $s0, $zero
    jal        func_800DB370
     li        $a3, 0x0
    bnez       $v0, func_800DB894
     addu      $a0, $s0, $zero
    la         $ra, func_800DB894
    bgez       $zero, func_800DB74C
     and       $a1, $s1, 0xF
endlabel func_800DB93C

glabel func_800DBB2C
    lw         $v0, vs_battle_actors
    lbu        $t0, 0x88($a0)
  32:
    lw         $t1, 0x4($v0)
    nop
    beq        $t1, $t0, 34f
     sll       $t3, $t1, 2
    addu       $t3, $a0
    lw         $t3, 0x1A4($t3)
    sll        $t2, $a2, 6
    and        $t3, 0xC0
    bne        $t3, $t2, 34f
     nop
    beqz       $a1, 33f
     lw        $t3, 0x44($v0)
    nop
    lw         $t3, 0x5C($t3)
    nop
    sw         $t3, 0x0($a1)
  33:
    jr         $ra
     addu      $v0, $t1, $zero
  34:
    lw         $v0, 0x0($v0)
    nop
    bnez       $v0, 32b
     nop
    jr         $ra
     add       $v0, $zero, -0x1
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    jal        func_800DA1D4
     addu      $s0, $a0, $zero
    bnez       $v0, func_800DB89C
     addu      $a0, $s0, $zero
    addu       $a1, $sp, 0x28
    jal        func_800DBB2C
     li        $a2, 0x2
    addu       $v1, $v0, $zero
    bltz       $v1, func_800DB89C
     addu      $v0, $zero, $zero
    sll        $v1, 2
    addu       $v0, $a0, $v1
    lw         $v0, 0x1E4($v0)
    li         $t0, 0x64000
    sltu       $v0, $t0, $v0
    lw         $a1, 0x28($sp)
    addu       $a2, $zero, $zero
    la         $ra, D_800DBC04
    bnez       $v0, func_800DB5DC
     addu      $a0, $s0, $zero
    bgez       $zero, func_800DB5B8
     li        $a2, 0x5
  alabel D_800DBC04
    bgez       $zero, func_800DB89C
     li        $v0, 0x1
  alabel D_800DBC0C
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    jal        func_800D826C
     addu      $s0, $a0, $zero
    beqz       $v0, 35f
     addu      $a1, $zero, $zero
    jal        func_800DA1D4
     addu      $a0, $s0, $zero
    bnez       $v0, func_800DB89C
     addu      $a1, $zero, $zero
  35:
    li         $a2, 0x100
    li         $a3, 0x0
    jal        func_800DB370
     addu      $a0, $s0, $zero
    bnez       $v0, func_800DB89C
     addu      $a0, $s0, $zero
    la         $ra, func_800DB89C
    bgez       $zero, func_800DB74C
     addu      $a1, $zero, $zero
endlabel func_800DBB2C

glabel func_800DBC60
    lbu        $v0, 0x13($a0)
    lw         $v1, 0xC($a1)
    bnez       $v0, .L800DBCA4
     lw        $v0, 0x4($a1)
    la         $t1, D_800F45E0
    lw         $t0, 0x10($a1)
    and        $v1, 0xF
    srl        $t0, 4
    and        $t0, 0x1
    beqz       $t0, .L800DBCAC
     sll       $v1, 2
    addu       $v1, $t1
    lw         $v1, 0x0($v1)
    nop
    bnez       $v1, .L800DBCAC
     nop
  .L800DBCA4:
    jr         $ra
     li        $v0, 0x1
  .L800DBCAC:
    jr         $ra
     addu      $v0, $zero, $zero
endlabel func_800DBC60

glabel func_800DBCB4
    lhu        $t0, 0x90($a0)
    addu       $t9, $ra, $zero
    bnez       $t0, .L800DBCAC
     nop
    jal        func_800DBC60
     nop
    addu       $ra, $t9, $zero
    beqz       $v0, .L800DBCA4
     nop
    lbu        $t0, 0x13F($a0)
    nop
    bnez       $t0, .L800DBCAC
     nop
    bgez       $zero, .L800DBCA4
endlabel func_800DBCB4

glabel func_800DBCEC
    la         $t8, vs_battle_actors
    mtc2       $a0, $2
    mtc2       $a1, $4
  36:
    beqz       $t8, .L800DBCA4
     mfc2      $a0, $2
    mfc2       $a1, $4
    lw         $t1, 0x4($t8)
    addu       $t9, $ra, $zero
    sll        $t1, 2
    addu       $v0, $t1, 0x1A4
    addu       $v0, $a0, $v0
    lw         $v0, 0x0($v0)
    nop
    srl        $v0, 6
    and        $v0, 0x3
    slt        $v0, 0x3
    bnez       $v0, 37f
     lui       $v0, %hi(D_800F4538)
    addiu      $v0, $v0, %lo(D_800F4538)
    addu       $v0, $t1
    lw         $v0, 0x0($v0)
    la         $v1, D_800F45E0
    sll        $a1, 2
    addu       $v1, $a1
    lw         $v1, 0x0($v1)
    lw         $a0, 0x5C($v0)
    jal        func_800E45F4
     lw        $a1, 0x5C($v1)
    addu       $ra, $t9, $zero
    slt        $v0, 0x3
    bnez       $v0, .L800DBCAC
     mfc2      $a0, $2
  37:
    lw         $t8, 0x0($t8)
    bgez       $zero, 36b
     nop
endlabel func_800DBCEC

glabel func_800DBD80
    lw         $t4, 0xC($a1)
    addu       $t7, $ra, $zero
    srl        $v0, $t4, 19
    and        $v0, 0xFF
    beqz       $v0, 40f
     lui       $v1, %hi(D_800F58BC)
    lw         $v1, %lo(D_800F58BC)($v1)
    lw         $v0, 0x4($a1)
    lhu        $v1, 0x18($v1)
    srl        $v0, 13
    and        $v0, 0xFFFF
    sltu       $v0, $v1, $v0
    bnez       $v0, 40f
     nop
    jal        func_800DBCB4
     nop
    beqz       $v0, 40f
     and       $v0, $t4, 0xF
    sll        $v0, 2
    addu       $t0, $v0, $a0
    lw         $t5, 0x1E4($t0)
    la         $v1, D_800F45E0
    addu       $v1, $v0
    lw         $v1, 0x0($v1)
    nop
    beqz       $v1, 38f
     addu      $v1, $v0, $zero
    li         $v0, 0x19000
    slt        $v0, $t5
    bnez       $v0, 40f
     nop
    lbu        $t1, 0x13($a0)
    nop
    bnez       $t1, 40f
     addu      $t6, $a1, $zero
    jal        func_800DBCEC
     srl       $a1, $v1, 2
    addu       $a1, $t6, $zero
    bnez       $v0, 40f
     nop
  38:
    lw         $t0, 0x8($a1)
    and        $v0, $t4, 0xF
    sll        $v0, 2
    addu       $t6, $a0, $v0
    lw         $t6, 0x1A4($t6)
    slt        $v0, $t0, $t5
    bnez       $v0, 40f
     addu      $t9, $a1, $zero
    jal        vs_gte_rsqrt
     addu      $a0, $t0, $zero
    addu       $a1, $t9, $zero
    lw         $t9, 0x10($t9)
    nop
    sll        $v1, $t9, 10
    srl        $v1, 16
    addu       $v0, $v1, $zero
    mult       $v0, $v0
    blez       $v0, 39f
     sll       $v1, $t9, 30
    mflo       $v0
    bgez       $v1, 39f
     slt       $v1, $t5, $v0
    bnez       $v1, 40f
     nop
  39:
    bgez       $t6, 40f
     lui       $v1, %hi(D_800F4538)
    addiu      $v1, $v1, %lo(D_800F4538)
    lw         $v1, 0x0($v1)
    sll        $a0, $t9, 29
    srl        $a0, 31
    lbu        $v1, 0xA($v1)
    srl        $a1, $t6, 2
    and        $a1, 0x1
    and        $t0, $v1, 0x7
    bnez       $t0, 40f
     and       $t0, $v1, 0x18
    li         $v1, 0x8
    beq        $t0, $v1, 40f
     or        $a0, $a1
    beqz       $a0, 40f
     srl       $a0, $t9, 3
    and        $a0, 0x1
    srl        $a1, $t6, 27
    and        $a1, 0x1
    xor        $a1, 0x1
    or         $a0, $a1
    beqz       $a0, 40f
     nop
    bgez       $zero, 41f
     li        $v0, 0x1
  40:
    addu       $v0, $zero, $zero
  41:
    addu       $ra, $t7, $zero
    jr         $ra
     nop
endlabel func_800DBD80

