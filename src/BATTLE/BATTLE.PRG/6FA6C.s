.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800D826C
    lhu     $v0, 0x8E($a0)
    nop
    slti    $v0, $v0, 0x20
alabel L800D8278
    jr      $ra
    xori    $v0, $v0, 0x1
endlabel func_800D826C

glabel func_800D8280
    lbu     $v0, 0x12A($a0)
    addu    $t0, $a0, $zero
    beqz    $v0, .L800D82A4
    addi    $v0, $v0, -0x1 /* handwritten instruction */
    beqz    $v0, L800D8254
    sb      $v0, 0x12A($t0)
    lbu     $a0, 0x88($t0)
    bgez    $zero, func_800D820C
    lhu     $a1, 0x138($t0)
.L800D82A4:
    jr      $ra
endlabel func_800D8280

glabel func_800D82A8
    lui     $a1, (0x800F5878 >> 16)
    beqz    $a0, .L800D82A4
    ori     $a1, $a1, (0x800F5878 & 0xFFFF)
    sll     $a0, $a0, 2
    addu    $a0, $a0, $a1
    lw      $a0, 0x0($a0)
    nop
    beqz    $a0, .L800D82A4
    nop
endlabel func_800D82A8

glabel func_800D82CC
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s2, 0x1C($sp)
    sw      $s1, 0x14($sp)
    sw      $s0, 0x10($sp)
    lui     $s2, %hi(D_800F58BC)
    lw      $s2, %lo(D_800F58BC)($s2)
    addu    $s0, $a0, $zero
    lbu     $s1, 0x88($s0)
    addiu   $v0, $zero, 0x1
    lhu     $v1, 0x10($s2)
    sllv    $v0, $v0, $s1
    and     $v0, $v1, $v0
    beqz    $v0, L800DB894
    subu    $v1, $v1, $v0
    lui     $v0, %hi(vs_battle_actors)
    lw      $v0, %lo(vs_battle_actors)($v0)
    sh      $v1, 0x10($s2)
    lw      $v0, 0x0($v0)
    sh      $zero, 0x8E($s0)
    beqz    $v0, .L800D8334
    nop
    lw      $v1, 0x0($v0)
    nop
    beqz    $v1, .L800D8338
    addu    $v0, $zero, $zero
.L800D8334:
    addiu   $v0, $zero, 0x30
.L800D8338:
    sh      $v0, 0x98($s0)
    addiu   $v0, $zero, 0x5A
    sh      $v0, 0x9A($s0)
    jal     func_800DBF00
    addu    $a0, $s0, $zero
    lbu     $v0, 0x12($s2)
    lui     $ra, %hi(L800DB894)
    addiu   $ra, $ra, %lo(L800DB894)
    addu    $a0, $s1, $zero
    addi    $v0, $v0, -0x1 /* handwritten instruction */
    addiu   $a1, $zero, 0x0
    bgez    $zero, func_800D820C
    sb      $v0, 0x12($s2)
endlabel func_800D82CC

glabel func_800D836C
    lhu     $t0, 0x8E($a0)
    lui     $v1, %hi(D_800F58BC)
    lw      $v1, %lo(D_800F58BC)($v1)
    bnez    $t0, .L800D82A4
    addiu   $v0, $zero, 0x1
    lbu     $t1, 0x12($v1)
    lbu     $a2, 0xD($v1)
    lui     $a1, %hi(D_800F58E0)
    lw      $a1, %lo(D_800F58E0)($a1)
    sltu    $v0, $a2, $t1
    lhu     $a3, 0x98($a0)
    bnez    $v0, L800D8278
    or      $a3, $a3, $a1
    bnez    $a3, .L800D82A4
    addu    $v0, $zero, $zero
    lhu     $a3, 0x9A($a0)
    bnez    $t0, L800D8278
    addiu   $t0, $t0, 0x1
    beqz    $a3, .L800D83C0
    sb      $zero, 0x12C($a0)
    addiu   $t0, $zero, 0x20
.L800D83C0:
    lhu     $a1, 0x10($v1)
    addiu   $t1, $t1, 0x1
    lbu     $a2, 0x88($a0)
    addiu   $v0, $zero, 0x1
    sh      $t0, 0x8E($a0)
    lw      $t2, 0x1C($v1)
    sllv    $v0, $v0, $a2
    or      $a1, $a1, $v0
    sh      $a1, 0x10($v1)
    bnez    $t2, .L800D83F0
    sb      $t1, 0x12($v1)
    sw      $a0, 0x20($v1)
.L800D83F0:
    sw      $t2, 0x1A0($a0)
    sw      $a0, 0x1C($v1)
    jr      $ra
    addiu   $v0, $zero, 0x1
endlabel func_800D836C
