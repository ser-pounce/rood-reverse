.include "macro.inc"

.set noat
.set noreorder

glabel func_800D820C
    beqz       $a0, .L800D8278
     addu      $v0, $zero, $zero
    j          func_80095B7C
     nop
endlabel func_800D820C

glabel func_800D821C
    li         $a1, 0x0
    addu       $sp, -0x20
    sw         $s0, 0x14($sp)
    sw         $ra, 0x18($sp)
    lbu        $a0, 0x88($a0)
    jal        func_800D820C
     addu      $s0, $a0, $zero
    addu       $a0, $s0, $zero
    jal        func_800D820C
     li        $a1, 0x40
    lw         $ra, 0x18($sp)
    lw         $s0, 0x14($sp)
    jr         $ra
     addu      $sp, 0x20
  .L800D8254:
    lbu        $a0, 0x88($a0)
    bgez       $zero, func_800D820C
     li        $a1, 0x0
endlabel func_800D821C

glabel func_800D8260
    sh         $a1, 0x138($a0)
    jr         $ra
     sb        $a2, 0x12A($a0)
endlabel func_800D8260

glabel func_800D826C
    lhu        $v0, 0x8E($a0)
    nop
    slt        $v0, 0x20
  .L800D8278:
    jr         $ra
     xor       $v0, 0x1
  alabel func_800D8280
    lbu        $v0, 0x12A($a0)
    addu       $t0, $a0, $zero
    beqz       $v0, .L800D82A4
     add       $v0, -0x1
    beqz       $v0, .L800D8254
     sb        $v0, 0x12A($t0)
    lbu        $a0, 0x88($t0)
    bgez       $zero, func_800D820C
     lhu       $a1, 0x138($t0)
  .L800D82A4:
    jr         $ra
endlabel func_800D826C

glabel func_800D82A8
    lui        $a1, (0x800F5878 >> 16)
    beqz       $a0, .L800D82A4
     or        $a1, (0x800F5878 & 0xFFFF)
    sll        $a0, 2
    addu       $a0, $a1
    lw         $a0, 0x0($a0)
    nop
    beqz       $a0, .L800D82A4
     nop
  alabel func_800D82CC
    addu       $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s2, 0x1C($sp)
    sw         $s1, 0x14($sp)
    sw         $s0, 0x10($sp)
    lw         $s2, D_800F58BC
    addu       $s0, $a0, $zero
    lbu        $s1, 0x88($s0)
    li         $v0, 0x1
    lhu        $v1, 0x10($s2)
    sllv       $v0, $v0, $s1
    and        $v0, $v1, $v0
    beqz       $v0, func_800DB894
     subu      $v1, $v0
    lw         $v0, vs_battle_actors
    sh         $v1, 0x10($s2)
    lw         $v0, 0x0($v0)
    sh         $zero, 0x8E($s0)
    beqz       $v0, 0f
     nop
    lw         $v1, 0x0($v0)
    nop
    beqz       $v1, 1f
     addu      $v0, $zero, $zero
  0:
    li         $v0, 0x30
  1:
    sh         $v0, 0x98($s0)
    li         $v0, 0x5A
    sh         $v0, 0x9A($s0)
    jal        func_800DBF00
     addu      $a0, $s0, $zero
    lbu        $v0, 0x12($s2)
    la         $ra, func_800DB894
    addu       $a0, $s1, $zero
    add        $v0, -0x1
    li         $a1, 0x0
    bgez       $zero, func_800D820C
     sb        $v0, 0x12($s2)
  alabel func_800D836C
    lhu        $t0, 0x8E($a0)
    lw         $v1, D_800F58BC
    bnez       $t0, .L800D82A4
     li        $v0, 0x1
    lbu        $t1, 0x12($v1)
    lbu        $a2, 0xD($v1)
    lw         $a1, D_800F58E0
    sltu       $v0, $a2, $t1
    lhu        $a3, 0x98($a0)
    bnez       $v0, .L800D8278
     or        $a3, $a1
    bnez       $a3, .L800D82A4
     addu      $v0, $zero, $zero
    lhu        $a3, 0x9A($a0)
    bnez       $t0, .L800D8278
     addu      $t0, 0x1
    beqz       $a3, 2f
     sb        $zero, 0x12C($a0)
    li         $t0, 0x20
  2:
    lhu        $a1, 0x10($v1)
    addu       $t1, 0x1
    lbu        $a2, 0x88($a0)
    li         $v0, 0x1
    sh         $t0, 0x8E($a0)
    lw         $t2, 0x1C($v1)
    sllv       $v0, $v0, $a2
    or         $a1, $v0
    sh         $a1, 0x10($v1)
    bnez       $t2, 3f
     sb        $t1, 0x12($v1)
    sw         $a0, 0x20($v1)
  3:
    sw         $t2, 0x1A0($a0)
    sw         $a0, 0x1C($v1)
    jr         $ra
     li        $v0, 0x1
endlabel func_800D82A8

