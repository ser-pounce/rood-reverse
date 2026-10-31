.include "macro.inc"

.set noat
.set noreorder

glabel func_800DC19C
    lbu        $v0, 0x13($a0)
    addu       $sp, -0x20
    sw         $s0, 0x10($sp)
    sw         $ra, 0x14($sp)
    sb         $zero, 0x126($a0)
    addu       $s0, $a0, $zero
    beqz       $v0, .L800DC274
     lbu       $a0, 0x88($s0)
    li         $a1, 0x40
    jal        func_800D820C
     sb        $zero, 0x13($s0)
    jal        func_800E7370
     addu      $a0, $s0, $zero
    lw         $a0, 0x6C($s0)
    lbu        $v0, 0x30($s0)
    beqz       $a0, 0f
     sw        $zero, 0x6C($s0)
    sw         $a0, 0x68($s0)
  0:
    bnez       $v0, .L800DC274
     li        $a1, 0x6
    li         $a2, 0x28
    jal        func_800D8260
     addu      $a0, $s0, $zero
    li         $a1, 0x2
    li         $a2, 0x80
    la         $ra, .L800DC274
    bgez       $zero, func_800E48A8
     addu      $a0, $s0, $zero
endlabel func_800DC19C

glabel func_800DC210
    addu       $sp, -0x20
    sw         $s0, 0x10($sp)
    sw         $ra, 0x14($sp)
    bnez       $a1, 1f
     addu      $s0, $a0, $zero
    jal        rand
     nop
    lbu        $v1, 0x126($s0)
    and        $v0, 0x7F
    slt        $v0, 0x4C
    beqz       $v0, .L800DC274
     addu      $v1, 0x1
    slt        $v0, $v1, 0x2
    bnez       $v0, .L800DC274
     sb        $v1, 0x126($s0)
  1:
    li         $v0, 0x1
    sb         $v0, 0x13($s0)
    lw         $v1, 0x68($s0)
    la         $v0, D_800DBC0C
    lbu        $a0, 0x88($s0)
    sw         $v0, 0x68($s0)
    sw         $v1, 0x6C($s0)
    jal        func_800D820C
     li        $a1, 0x80
  .L800DC274:
    lw         $ra, 0x14($sp)
    lw         $s0, 0x10($sp)
    jr         $ra
     addu      $sp, 0x20
endlabel func_800DC210

glabel func_800DC284
    li         $v0, 0x6
    mult       $v0, $a0
    sll        $a2, 16
    and        $a1, 0xFFFF
    or         $a1, $a2, $a1
    ctc2       $a1, $0
    ctc2       $a3, $1
    ctc2       $zero, $2
    ctc2       $zero, $3
    ctc2       $zero, $4
    or         $t0, $zero, 0x4
    or         $t1, $zero, 0x1
    or         $t2, $zero, 0x2
    mtc2       $t0, $9
    mtc2       $t1, $10
    mtc2       $t2, $11
    nop
    nop
    mvmva      0, 0, 3, 3, 0
    mflo       $a1
    mfc2       $a0, $25
    jr         $ra
     add       $v0, $a0, $a1
endlabel func_800DC284

glabel func_800DC2E0
    lw         $t0, 0x0($a1)
    lw         $t1, 0x4($a1)
    lw         $t2, 0x8($a1)
    lw         $t3, 0xC($a1)
    lw         $t4, 0x10($a1)
    sw         $t0, 0x0($a0)
    sw         $t1, 0x4($a0)
    sw         $t2, 0x8($a0)
    sw         $t3, 0xC($a0)
    jr         $ra
     sw        $t4, 0x10($a0)
endlabel func_800DC2E0

glabel func_800DC30C
    lh         $t0, 0x0($a0)
    li         $v0, 0x2
    bne        $v0, $a3, 2f
     sub       $v1, $t0, $a2
    add        $v1, $t0, $a2
  2:
    lh         $t1, 0x0($a1)
    bltz       $v1, 3f
     addu      $a3, $zero, $zero
    slt        $t2, $t1, $v1
    bnez       $t2, 3f
     addu      $a3, $t1, $zero
    addu       $a3, $v1, $zero
  3:
    jr         $ra
     sh        $a3, 0x0($a0)
endlabel func_800DC30C

glabel func_800DC344
    lw         $v0, 0x470($a0)
    li         $t3, 0x14
    la         $t0, D_800F5904
    lw         $v1, 0xC($a1)
    mult       $v0, $t3
    slt        $a3, $v0, 0x10
    xor        $a3, 0x1
    srl        $a2, $v1, 19
    and        $a2, 0xFF
    sltu       $a2, 0x1
    or         $a3, $a2, $a3
    beqz       $a3, 4f
     lw        $t0, 0x0($t0)
    jr         $ra
  4:
     li        $t2, 0x1
    lw         $t1, 0x4($a1)
    and        $v1, 0xF
    srl        $t1, 5
    and        $t1, 0xFF
    sll        $v1, 8
    addu       $t1, $v1
    mflo       $t3
    addu       $t1, $t0
    sb         $t2, 0x0($t1)
    addu       $v1, $t3, $a0
    addu       $v1, 0x2F0
    sll        $t2, $v0, 2
    addu       $t2, $a0
    sw         $v1, 0x430($t2)
    addu       $v0, 0x1
    sw         $v0, 0x470($a0)
    bgez       $zero, func_800DC2E0
     addu      $a0, $v1, $zero
endlabel func_800DC344

glabel func_800DC3CC
    lw         $a2, 0x470($a0)
    addu       $a1, $zero, $zero
    addu       $a0, 0x430
    bnez       $a2, func_800E6958
     add       $a2, -0x1
    jr         $ra
     nop
endlabel func_800DC3CC

glabel func_800DC3E8
    lw         $t0, 0x18($a0)
    li         $a2, 0x528
    lw         $t1, 0x1C($a0)
    addu       $v0, $a1, $zero
    lui        $t4, (0x800490B0 >> 16)
    lw         $t2, 0x948($a0)
    or         $t4, (0x800490B0 & 0xFFFF)
    lw         $t3, 0x30($a0)
    sw         $t0, 0x18($a1)
    sw         $t1, 0x1C($a1)
    sw         $t2, 0x948($a1)
    sw         $t3, 0x30($a1)
    addu       $a1, $a0, 0x398
    jr         $t4
     addu      $a0, $v0, 0x398
endlabel func_800DC3E8

glabel func_800DC424
    lw         $t0, vs_battle_actors
    li         $a1, 0x18
  5:
    lw         $t1, 0x4($t0)
    lw         $t2, 0x3C($t0)
    mult       $a1, $t1
    lw         $t3, 0x18($t2)
    lw         $t4, 0x1C($t2)
    lw         $t5, 0x150($t2)
    lw         $t6, 0x2B4($t2)
    lw         $t0, 0x0($t0)
    mflo       $v0
    lw         $t7, 0x948($t2)
    addu       $v0, $a0
    sw         $t1, 0x0($v0)
    sw         $t3, 0x4($v0)
    sw         $t4, 0x8($v0)
    sw         $t5, 0x10($v0)
    sw         $t6, 0x14($v0)
    sw         $t7, 0xC($v0)
    bnez       $t0, 5b
     li        $a1, 0x18
    jr         $ra
     nop
endlabel func_800DC424

glabel func_800DC484
    bgez       $zero, .L800DC490
     li        $v0, 0xF
endlabel func_800DC484

glabel func_800DC48C
    li         $v0, 0xE
  .L800DC490:
    li         $v1, 0x34
    mult       $v1, $a0
    la         $t0, vs_battle_actors
    sll        $a1, 2
    addu       $t0, $a1
    lw         $t0, 0x0($t0)
    la         $t2, vs_main_actions
    lw         $t0, 0x3C($t0)
    mflo       $t1
    lbu        $t0, 0x37($t0)
    addu       $t1, $t2
    lhu        $t1, 0xE($t1)
    and        $t0, 0x7
    srlv       $t1, $t1, $v0
    and        $v0, $t1, 0x1
    or         $v1, $zero, 0x60
    bne        $v1, $a0, .L800DC4EC
     li        $v1, 0x2
    bne        $t0, $v1, .L800DC4EC
     nop
    xor        $v0, $t1, 0x1
  .L800DC4EC:
    jr         $ra
endlabel func_800DC48C

glabel func_800DC4F0
    li         $a2, 0x1
    lw         $t0, 0x4($a0)
    la         $t3, D_800F58F0
    lhu        $t1, 0xE($a1)
    and        $v0, $t0, 0x7
    sll        $v0, 2
    srl        $v1, $t0, 3
    and        $v1, 0x3
    lw         $t2, D_800F58F4
    add        $v0, $v1
    sll        $t1, 25
    bgez       $t1, .L800DC4EC
     sllv      $a2, $a2, $v0
    and        $a3, $t2, $a2
    bnez       $a3, .L800DC4EC
     li        $v0, 0x14
    lw         $a3, 0x0($t3)
    or         $t2, $a2
    mult       $v0, $a3
    lw         $v1, D_800F58F8
    addu       $a1, $a0, $zero
    mflo       $v0
    lui        $at, %hi(D_800F58F4)
    sw         $t2, %lo(D_800F58F4)($at)
    addu       $a0, $v0, $v1
    slt        $v0, $a3, 0x10
    beqz       $v0, .L800DC4EC
     addu      $a3, 0x1
    bgez       $zero, func_800DC2E0
     sw        $a3, 0x0($t3)
endlabel func_800DC4F0

glabel func_800DC574
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    sw         $s2, 0x1C($sp)
    sw         $s5, 0x28($sp)
    lbu        $s2, 0x2B($a0)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    addu       $s5, $zero, $zero
  6:
    jal        rand
     nop
    sll        $v1, $s5, 2
    addu       $v1, $s0
    lw         $t0, 0x430($v1)
    and        $v0, 0x7F
    lw         $t1, 0x4($t0)
    lw         $t3, 0xC($t0)
    srl        $t2, $t1, 5
    and        $t2, 0xFF
    beqz       $t2, 9f
     srl       $t4, $t3, 19
    and        $t4, 0xFF
    addu       $v1, $t4, 0x4C
    bnez       $s2, 7f
     srl       $a0, $v1, 1
  7:
    slt        $v1, $t4, 0x4C
    bnez       $v1, 8f
     addu      $a0, $t4, $zero
    li         $a0, 0x4C
  8:
    sltu       $v0, $a0
    beqz       $v0, 9f
     lw        $v0, 0x430($s0)
    la         $ra, func_800DB890
    li         $a1, 0x1
    sll        $v1, $s5, 2
    addu       $v1, $s0, $v1
    sw         $t0, 0x430($s0)
    sw         $v0, 0x430($v1)
    add        $a2, $s1, -0x1
    bgez       $zero, func_800E6958
     addu      $a0, $s0, 0x430
  9:
    add        $s5, 0x1
    slt        $v0, $s5, $s1
    bnez       $v0, 6b
     nop
    bgez       $zero, func_800DB890
     nop
endlabel func_800DC574

glabel func_800DC638
    addu       $sp, -0x80
    sw         $ra, 0x78($sp)
    jal        func_8008D2C0
     addu      $a0, $sp, 0x10
    addu       $v1, $sp, 0x10
    addu       $a3, $zero, $zero
  10:
    beqz       $v0, 11f
     add       $v0, -0x1
    sll        $a0, $v0, 3
    addu       $a0, $v1
    lhu        $a0, 0x6($a0)
    li         $a1, 0x1
    sllv       $a1, $a1, $a0
    bgez       $zero, 10b
     or        $a3, $a1
  11:
    lw         $a1, D_800F58C0
    lw         $t0, D_800F5910
    addu       $a0, $zero, $zero
    beqz       $a1, 17f
  12:
     addu      $a2, $a1, $a0
    lw         $v0, 0x0($a2)
    addu       $t1, $zero, $zero
    li         $at, 0x4000400
    and        $at, $v0, $at
    beqz       $at, 16f
     lui       $at, (0x80008000 >> 16)
    or         $at, (0x80008000 & 0xFFFF)
    or         $v0, $at
    sll        $t3, $v0, 22
    srl        $t3, 27
    and        $t4, $v0, 0x1F
    sll        $t5, $v0, 6
    srl        $t5, 27
    srl        $t6, $v0, 16
    and        $t6, 0x1F
    srl        $t2, $v0, 13
    and        $t2, 0x3
    srl        $t9, $v0, 29
    and        $t9, 0x3
  13:
    sll        $at, $t1, 2
    addu       $at, $t0
    lw         $at, 0x0($at)
    nop
    and        $t7, $at, 0x1F
    sll        $t8, $at, 22
    srl        $t8, 27
    sll        $at, $v0, 21
    bgez       $at, 14f
     nop
    bne        $t3, $t7, 14f
     li        $v1, 0x1
    bne        $t4, $t8, 14f
     sllv      $t2, $v1, $t2
    and        $t2, $a3
    beqz       $t2, 14f
     lui       $at, (0xFFFF7FFF >> 16)
    or         $at, (0xFFFF7FFF & 0xFFFF)
    and        $v0, $at
  14:
    sll        $at, $v0, 5
    bgez       $at, 15f
     sllv      $t9, $v1, $t9
    bne        $t5, $t7, 15f
     and       $t9, $a3
    bne        $t6, $t8, 15f
     nop
    beqz       $t9, 15f
     sll       $at, $v0, 1
    srl        $v0, $at, 1
  15:
    addu       $t1, 0x1
    slt        $v1, $t1, 0x8
    bnez       $v1, 13b
     nop
    sw         $v0, 0x0($a2)
  16:
    addu       $a0, 0x4
    slt        $v1, $a0, 0x400
    bnez       $v1, 12b
     nop
  17:
    lw         $ra, 0x78($sp)
    addu       $sp, 0x80
    jr         $ra
endlabel func_800DC638

glabel func_800DC784
    sll        $a1, 2
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s1, 0x14($sp)
    sw         $s2, 0x1C($sp)
    addu       $v0, $a0, $a1
    lw         $s2, 0x1A4($v0)
    addu       $s1, $v0, $zero
    sw         $s0, 0x10($sp)
    addu       $s0, $a0, $zero
    srl        $v0, $s2, 6
    and        $v0, 0x3
    slt        $v0, 0x3
    beqz       $v0, 19f
     nop
    jal        rand
     nop
    and        $v0, 0x7F
    slt        $v0, 0x80
    beqz       $v0, 18f
     li        $v1, 0x1
    sb         $v1, 0x18($s0)
  18:
    li         $a1, 0x6
    li         $a2, 0x28
    jal        func_800D8260
     addu      $a0, $s0, $zero
    li         $a1, 0x2
    li         $a2, 0x80
    jal        func_800E48A8
     addu      $a0, $s0, $zero
  19:
    add        $v0, $zero, -0x7FC1
    and        $s2, $v0
    or         $s2, 0xC0
    bgez       $zero, func_800DB894
     sw        $s2, 0x1A4($s1)
endlabel func_800DC784

glabel func_800DC810
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s1, 0x14($sp)
    sw         $s5, 0x28($sp)
    sw         $s2, 0x1C($sp)
    addu       $s1, $a0, $zero
    sw         $s0, 0x10($sp)
    la         $s5, func_800DD000
    li         $s2, 0x2
  20:
    lw         $s0, vs_battle_actors
    lui        $t1, (0x800F5878 >> 16)
  21:
    lw         $t0, 0x4($s0)
    or         $t1, (0x800F5878 & 0xFFFF)
    sll        $t0, 2
    addu       $t1, $t0
    lw         $a0, 0x0($t1)
    jalr       $s5
     addu      $a1, $s1, $zero
    lw         $s0, 0x0($s0)
    lui        $t1, (0x800F5878 >> 16)
    bnez       $s0, 21b
     nop
    add        $s2, -0x1
    lui        $s5, (0x800DD344 >> 16)
    bgtz       $s2, 20b
     or        $s5, (0x800DD344 & 0xFFFF)
    bgez       $zero, func_800DB890
     nop
endlabel func_800DC810

