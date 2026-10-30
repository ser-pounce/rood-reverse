.include "macro.inc"

.set noat
.set noreorder

.section .rodata

dlabel D_80069C0C
    .byte 0x03, 0x02, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03, 0xB4, 0x5A, 0x0F, 0x00
enddlabel D_80069C0C

.section .text

glabel func_800E65DC
    li         $v0, 0x10
    lui        $a3, (0x1F8003DC >> 16)
    la         $a0, D_800F5878
  0:
    sll        $a2, $v0, 2
    addu       $v1, $a0, $a2
    lw         $a1, 0x0($v1)
    addiu      $v0, -0x1
    addu       $v1, $a3, $a2
    bgez       $v0, 0b
     sw        $a1, (0x1F80037C & 0xFFFF)($v1)
    lui        $v0, %hi(D_800F58BC)
    lw         $v0, %lo(D_800F58BC)($v0)
    lui        $t0, %hi(D_800F58D0)
    lw         $t0, %lo(D_800F58D0)($t0)
    lui        $t1, %hi(D_800F58B8)
    lw         $t1, %lo(D_800F58B8)($t1)
    lui        $t2, %hi(D_800F58CC)
    lw         $t2, %lo(D_800F58CC)($t2)
    lui        $t3, %hi(D_800F58C0)
    lw         $t3, %lo(D_800F58C0)($t3)
    lui        $t4, %hi(D_800F58C4)
    lw         $t4, %lo(D_800F58C4)($t4)
    lui        $t5, %hi(D_800F16E0)
    lw         $t5, %lo(D_800F16E0)($t5)
    lui        $t6, %hi(D_800F16E4)
    lw         $t6, %lo(D_800F16E4)($t6)
    lui        $t7, %hi(D_800F16E8)
    lw         $t7, %lo(D_800F16E8)($t7)
    lui        $t8, %hi(D_800F16EC)
    lw         $t8, %lo(D_800F16EC)($t8)
    lui        $t9, %hi(D_800F16F0)
    lw         $t9, %lo(D_800F16F0)($t9)
    lw         $v0, 0x4($v0)
    sw         $t0, (0x1F8003BC & 0xFFFF)($a3)
    sw         $t1, (0x1F8003C0 & 0xFFFF)($a3)
    sw         $t2, (0x1F8003C4 & 0xFFFF)($a3)
    sw         $t3, (0x1F8003F4 & 0xFFFF)($a3)
    sw         $t4, (0x1F8003F8 & 0xFFFF)($a3)
    sw         $t5, (0x1F8003E0 & 0xFFFF)($a3)
    sw         $t6, (0x1F8003E4 & 0xFFFF)($a3)
    sw         $t7, (0x1F8003E8 & 0xFFFF)($a3)
    sw         $t8, (0x1F8003EC & 0xFFFF)($a3)
    sw         $t9, (0x1F8003F0 & 0xFFFF)($a3)
    jr         $ra
     sw        $v0, (0x1F8003DC & 0xFFFF)($a3)
endlabel func_800E65DC

glabel func_800E6694
    la         $t0, D_800F5878
    sll        $a0, 2
    addu       $t0, $a0
    lw         $t0, 0x0($t0)
    addu       $t6, $zero, $zero
    beqz       $t0, .L800E66F8
     add       $v0, $zero, -0x1
    lw         $t1, 0x1A4($t0)
    lbu        $t2, 0x13($t0)
    lbu        $t5, 0x12D($t0)
    sll        $t6, $t1, 5
    srl        $t6, 25
    sll        $t6, 6
    sll        $t3, $t1, 24
    srl        $t3, 30
    sll        $t4, $t1, 2
    srl        $t4, 30
    sll        $t3, 1
    sll        $t4, 3
    slt        $t5, 0x1
    sll        $t5, 5
    or         $v0, $t2, $t3
    or         $v0, $t4
    or         $v0, $t5
  .L800E66F8:
    jr         $ra
     or        $v0, $t6
endlabel func_800E6694

glabel func_800E6700
    la         $a1, vs_battle_actors
    sll        $v0, $a0, 2
    addu       $a1, $v0
    lw         $a1, 0x0($a1)
    la         $a2, D_800F4538
    beqz       $a1, .L800E66F8
     addu      $a2, $v0
    lbu        $a1, 0x9($a1)
    lw         $a2, 0x0($a2)
    li         $v1, 0x1
    sllv       $v1, $v1, $a1
    li         $at, 0xA41800
    and        $v1, $at
    beqz       $v1, .L800E66F8
     lbu       $v0, 0xA($a2)
    lbu        $v1, 0xB($a2)
    and        $v0, 0x1F
    and        $v1, 0xB
    or         $v0, $v1
    beqz       $v0, .L800E6768
     addu      $t0, $zero, $zero
    jr         $ra
endlabel func_800E6700

glabel func_800E6764
    li         $t0, 0x1
  .L800E6768:
    la         $a1, D_800F5878
    sll        $a0, 2
    addu       $a1, $a0
    lw         $a0, 0x0($a1)
    lui        $t7, (0x800F0000 >> 16)
    bnez       $a0, .L800E6798
     addu      $t8, $ra, $zero
    jr         $ra
endlabel func_800E6764

glabel func_800E678C
    addu       $t0, $zero, $zero
    addu       $t8, $ra, $zero
    lui        $t7, (0x800F58BC >> 16)
  .L800E6798:
    or         $t7, (0x800F58BC & 0xFFFF)
    addu       $t9, $a0, $zero
    lw         $t7, 0x0($t7)
    lw         $a1, 0x170($a0)
    sb         $t0, 0x1A($a0)
    lw         $t2, 0x0($t7)
    and        $t0, $a1, 0xFF
    srl        $a1, 16
    and        $t1, $a1, 0xFF
    sll        $a0, $t2, 8
    srl        $a0, 24
    and        $a1, $t2, 0xFF
    srl        $a2, $t2, 24
    sll        $a3, $t2, 16
    srl        $a3, 24
    slt        $t3, $t0, $a0
    slt        $t4, $a1, $t0
    or         $t4, $t3
    slt        $t3, $t1, $a2
    or         $t4, $t3
    slt        $t6, $a3, $t1
    or         $t4, $t6
    bnez       $t4, 0f
     lbu       $t9, 0x19B($t9)
    addu       $a0, $t0, $zero
    jal        func_800E4C28
     addu      $a1, $t1, $zero
  0:
    beqz       $t9, 1f
     lbu       $a0, 0xE($t7)
    li         $a1, 0x1
    sllv       $a1, $a1, $a0
    neg        $a1, $a1
    and        $a0, $a1
    sb         $a0, 0xE($t7)
  1:
    jr         $t8
     addu      $ra, $t8, $zero
endlabel func_800E678C

glabel func_800E6828
    lhu        $a1, 0x224($a0)
    li         $a3, 0x1
    srl        $a2, $a1, 8
    or         $a1, $a2
    sh         $a1, 0x15E($a0)
    and        $a2, $a1, 0x30
    bnez       $a2, 0f
     and       $a2, $a1, 0x8
    bnez       $a2, 0f
     li        $a3, 0x2
    li         $a3, 0x0
  0:
    jr         $ra
     sb        $a3, 0x125($a0)
endlabel func_800E6828

glabel func_800E685C
    la         $a3, D_800F5878
    sll        $a0, 2
    addu       $a3, $a0
    lw         $a3, 0x0($a3)
    slt        $v0, $a1, $a2
    bnez       $v0, 0f
     addu      $v1, $a2, $zero
    addu       $v1, $a1, $zero
  0:
    sll        $a2, 8
    beqz       $a3, .L800E6918
     or        $a0, $a2, $a1
    sb         $v1, 0xB3($a3)
    jr         $ra
     sh        $a0, 0x226($a3)
endlabel func_800E685C

glabel func_800E6898
    bgez       $zero, .L800E68A4
     add       $a1, $zero, 0x1
endlabel func_800E6898

glabel func_800E68A0
    add        $a1, $zero, -0x1
  .L800E68A4:
    la         $t2, D_800F58D0
    lw         $a3, 0x5C($a0)
    lui        $a2, %hi(D_800F58B8)
    lw         $a2, %lo(D_800F58B8)($a2)
    and        $t0, $a3, 0xFF
    sll        $t1, $a3, 8
    beqz       $a2, .L800E6918
     srl       $t1, 18
    lw         $t2, 0x0($t2)
    sll        $t0, 1
    addu       $t0, $t1
    addu       $t0, $t2
    lhu        $t3, 0x0($t0)
    sll        $a1, 10
    add        $t3, $a1
    jr         $ra
     sh        $t3, 0x0($t0)
endlabel func_800E68A0

glabel func_800E68EC
    lui        $a2, %hi(D_800F58B8)
    lw         $a2, %lo(D_800F58B8)($a2)
    sll        $a0, 1
    beqz       $a2, .L800E6918
     sll       $a1, 6
    add        $a1, $a0, $a1
    add        $a1, $a2, $a1
    lhu        $a0, 0x0($a1)
    nop
    or         $a0, 0x400
    sh         $a0, 0x0($a1)
  .L800E6918:
    jr         $ra
     addu      $a1, $a2, $zero
    addiu      $sp, -0x18
    sw         $ra, 0x10($sp)
    jal        func_8008B764
     addu      $a2, $zero, $zero
    lw         $a0, 0x0($v0)
    add        $a1, $zero, 0x3
    sll        $a0, 3
    srl        $a0, 30
    lw         $ra, 0x10($sp)
    bne        $a0, $a1, 0f
     add       $v0, $zero, 0x1
    addu       $v0, $zero, $zero
  0:
    jr         $ra
     addiu     $sp, 0x18
endlabel func_800E68EC

glabel func_800E6958
    addiu      $sp, -0x8
    sw         $ra, 0x4($sp)
    jal        func_800E6974
     sw        $s0, 0x0($sp)
    lw         $ra, 0x4($sp)
    bgez       $zero, .L800E6A64
     lw        $s0, 0x0($sp)
endlabel func_800E6958

glabel func_800E6974
    addiu      $sp, -0x8
    sw         $ra, 0x4($sp)
    sll        $t1, $a1, 8
    sll        $t2, $s0, 16
    or         $t1, $a2
    or         $t2, $t1, $t2
    sw         $t2, 0x0($sp)
    slt        $t0, $a1, $a2
    beqz       $t0, 3f
     addu      $a3, $a1, $a2
    sra        $a3, 1
    sll        $a3, 2
    sll        $t1, $a1, 2
    addu       $t2, $a0, $t1
    addu       $t3, $a0, $a3
    lw         $t4, 0x0($t2)
    lw         $t5, 0x0($t3)
    sw         $t4, 0x0($t3)
    sw         $t5, 0x0($t2)
    addu       $s0, $a1, $zero
    add        $t0, $a1, 0x1
  0:
    sll        $t1, $t0, 2
    addu       $t1, $a0
    lw         $t3, 0x0($t1)
    lw         $t4, 0x0($t2)
    lw         $t5, 0x0($t3)
    lw         $t6, 0x0($t4)
    nop
    slt        $t7, $t6, $t5
    beqz       $t7, 1f
     nop
    add        $s0, 0x1
    sll        $t7, $s0, 2
    addu       $t7, $a0, $t7
    lw         $t8, 0x0($t7)
    sw         $t3, 0x0($t7)
    sw         $t8, 0x0($t1)
  1:
    add        $t0, 0x1
    slt        $t7, $a2, $t0
    bnez       $t7, 2f
     nop
    bgez       $zero, 0b
  2:
     sll       $v0, $s0, 2
    addu       $v0, $a0
    lw         $t7, 0x0($v0)
    lw         $t8, 0x0($t2)
    sw         $t7, 0x0($t2)
    sw         $t8, 0x0($v0)
    jal        func_800E6974
     add       $a2, $s0, -0x1
    lw         $a2, 0x0($sp)
    nop
    and        $a2, 0xFF
    jal        func_800E6974
     add       $a1, $s0, 0x1
  3:
    lw         $t0, 0x0($sp)
    lw         $ra, 0x4($sp)
    and        $a2, $t0, 0xFF
    srl        $a1, $t0, 8
    srl        $s0, $t0, 16
  .L800E6A64:
    jr         $ra
     addiu     $sp, 0x8
endlabel func_800E6974

glabel func_800E6A6C
    addiu      $sp, -0x38
    sw         $ra, 0x30($sp)
    sw         $s0, 0x10($sp)
    sw         $s7, 0x2C($sp)
    sw         $s6, 0x28($sp)
    sw         $s5, 0x24($sp)
    sw         $s4, 0x20($sp)
    sw         $s3, 0x1C($sp)
    sw         $s2, 0x18($sp)
    sw         $s1, 0x14($sp)
    addu       $s0, $a0, $zero
    addu       $s2, $a1, $zero
    sub        $s3, $a2, $s0
    sub        $s5, $a3, $s2
    sra        $s3, 4
    sra        $s5, 4
    addu       $s1, $zero, $zero
    addu       $s6, $zero, $zero
  0:
    add        $a0, $s0, $s3
    add        $a1, $s2, $s5
    addu       $s0, $a0, $zero
    jal        func_800E4318
     addu      $s2, $a1, $zero
    sll        $v0, 17
    sra        $v0, 17
    slt        $at, $s1, $v0
    bnez       $at, 1f
     nop
    addu       $s1, $v0, $zero
  1:
    add        $s6, 0x1
    slt        $a2, $s6, 0x10
    beqz       $a2, 2f
     addu      $v0, $s1, $zero
    bgez       $zero, 0b
     nop
  2:
    lw         $ra, 0x30($sp)
    lw         $s0, 0x10($sp)
    lw         $s7, 0x2C($sp)
    lw         $s6, 0x28($sp)
    lw         $s5, 0x24($sp)
    lw         $s4, 0x20($sp)
    lw         $s3, 0x1C($sp)
    lw         $s2, 0x18($sp)
    lw         $s1, 0x14($sp)
    jr         $ra
     addiu     $sp, 0x38
endlabel func_800E6A6C

glabel func_800E6B24
    sll        $a0, 2
    la         $a1, D_800F5878
    addu       $a0, $a1
    lw         $a0, 0x0($a0)
    nop
    beqz       $a0, .L800E66F8
     addu      $v0, $a0, $zero
    bgez       $zero, .L800E66F8
     sb        $zero, 0x1A($a0)
endlabel func_800E6B24

glabel func_800E6B4C
    addiu      $sp, -0x30
    sw         $s0, 0x10($sp)
    sw         $ra, 0x18($sp)
    li         $a1, 0x7
    or         $at, $zero, 0x8000
    addu       $a0, $zero, $at
    jal        vs_main_allocHeapR
     addu      $a2, $zero, $zero
    beqz       $v0, func_800DB89C
     addu      $s0, $v0, $zero
    sw         $sp, 0x0($s0)
    or         $at, $zero, 0x8000
    addu       $sp, $v0, $at
    jal        func_800E6098
     nop
    lw         $sp, 0x0($s0)
    la         $ra, func_800DB89C
    addu       $a0, $s0, $zero
    j          vs_main_freeHeapR
     li        $a1, 0x7
alabel func_800E6BA0
    addiu      $sp, -0x40
    sw         $ra, 0x20($sp)
    jal        func_8008D2C0
     addu      $a0, $sp, $zero
    addu       $t3, $zero, $zero
    addu       $t4, $v0, $zero
    addu       $a3, $sp, $zero
  0:
    lw         $a0, 0x0($a3)
    beqz       $t4, 4f
     li        $v0, 0x1
    lh         $a2, 0x4($a3)
    sra        $a1, $a0, 16
    add        $a1, 0x20
    and        $a0, 0xFFFF
    sub        $a0, $s2
    bgez       $a0, 1f
     sub       $a1, $s3
    neg        $a0, $a0
  1:
    bgez       $a1, 2f
     sub       $a2, $s4
    neg        $a1, $a1
  2:
    bgez       $a2, 3f
     slt       $t0, $a0, 0x40
    neg        $a2, $a2
  3:
    slt        $t1, $a1, 0x20
    slt        $t2, $a2, 0x40
    and        $t0, $t1
    and        $t0, $t2
    bnez       $t0, 4f
     addu      $v0, $zero, $zero
    addiu      $a3, 0x8
    bgez       $zero, 0b
     addiu     $t4, -0x1
  4:
    lw         $ra, 0x20($sp)
    addiu      $sp, 0x40
    jr         $ra
     nop
alabel func_800E6C34
    addiu      $sp, -0x40
    sw         $s0, 0x18($sp)
    sw         $s1, 0x1C($sp)
    sw         $s2, 0x20($sp)
    sw         $s3, 0x24($sp)
    sw         $s4, 0x28($sp)
    sw         $s5, 0x2C($sp)
    sw         $s6, 0x30($sp)
    sw         $s7, 0x34($sp)
    sw         $ra, 0x38($sp)
    lw         $t0, 0x0($a0)
    addu       $s0, $a2, $zero
    addu       $s1, $a3, $zero
    lh         $t2, 0x4($a0)
    sra        $t1, $t0, 16
    sll        $t0, 16
    sra        $t0, 16
    lw         $t3, 0x0($a1)
    addu       $s2, $t0, $zero
    addu       $s3, $t1, $zero
    addu       $s4, $t2, $zero
    lh         $t5, 0x4($a1)
    sra        $t4, $t3, 16
    sll        $t3, 16
    sra        $t3, 16
    sub        $s5, $t3, $t0
    sub        $s6, $t4, $t1
    sub        $s7, $t5, $t2
    mtc2       $s2, $8
    mtc2       $s4, $10
    sra        $s5, 5
    sra        $s6, 5
    sra        $s7, 5
    addu       $t0, $zero, $zero
  5:
    add        $s2, $s5
    add        $s3, $s6
    add        $s4, $s7
    addu       $t1, $zero, $zero
  6:
    la         $v0, vs_battle_actors
    addu       $v0, $t1
    lw         $v0, 0x0($v0)
    la         $t2, D_800F45E0
    beqz       $v0, 12f
     nop
    lbu        $v0, 0x1C($v0)
    or         $t4, $zero, 0xFFEA
    and        $v0, $t4
    bnez       $v0, 12f
     srl       $v0, $t1, 2
    beq        $v0, $s1, 12f
     lui       $t3, %hi(D_800F4538)
    addiu      $t3, %lo(D_800F4538)
    addu       $t4, $t2, $t1
    lw         $t4, 0x0($t4)
    li         $v0, 0x3F
    beqz       $t4, 7f
     nop
    lbu        $a0, 0x12($t4)
    lbu        $a1, 0x1A($t4)
    beqz       $a0, 12f
     li        $v1, 0x80
    bnez       $a1, 12f
     nop
    bgez       $zero, 8f
  7:
     addu      $a0, $t3, $t1
    lw         $t4, 0x0($a0)
    nop
    beqz       $t4, 12f
     nop
    lbu        $a0, 0xB($t4)
    li         $a1, 0x1
    lhu        $v0, 0x63C($t4)
    and        $a0, 0xF
    beq        $a0, $a1, 12f
     li        $a2, 0x2
    beq        $a0, $a2, 12f
     lbu       $a0, 0x5AF($t4)
    li         $a2, 0x1
    and        $a0, 0x1
    beq        $a0, $a2, 12f
     lhu       $v1, 0x63E($t4)
  8:
    lw         $a0, 0x1C($t4)
    sra        $v1, 1
    lhu        $a2, 0x20($t4)
    sra        $a1, $a0, 16
    sub        $a1, $v1
    sll        $a0, 16
    mfc2       $t4, $8
    sra        $a0, 16
    sub        $t4, $a0, $t4
    mult       $t4, $s5
    sub        $t6, $a0, $s2
    bgez       $t6, 9f
     sub       $t7, $a1, $s3
    neg        $t6, $t6
  9:
    bgez       $t7, 10f
     sub       $t8, $a2, $s4
    neg        $t7, $t7
  10:
    bgez       $t8, 11f
     mflo      $t4
    neg        $t8, $t8
  11:
    mfc2       $t5, $10
    slt        $t6, $v0
    sub        $t5, $a2, $t5
    mult       $s7, $t5
    slt        $t7, $v1
    slt        $t8, $v0
    and        $t6, $t7
    mflo       $t5
    and        $t6, $t8
    add        $t4, $t5
    bltz       $t4, 12f
     srl       $v0, $t1, 2
    bnez       $t6, 13f
     add       $v0, 0x1
  12:
    addiu      $t1, 0x4
    slt        $v1, $t1, 0x40
    bnez       $v1, 6b
     addu      $v0, $zero, $zero
  13:
    bnez       $v0, 14f
     sw        $t0, 0x3C($sp)
    jal        func_800E6BA0
     nop
    beqz       $v0, 14f
     addu      $a0, $s2, $zero
    jal        func_8008DC7C
     addu      $a1, $s4, $zero
    lw         $t0, 0x3C($sp)
    sll        $v0, 17
    sra        $v0, 17
    slt        $v0, $s3, $v0
    beqz       $v0, 14f
     add       $t0, 0x1
    slt        $v1, $t0, 0x20
    bnez       $v1, 5b
     addu      $v0, $zero, $zero
    bgez       $zero, 15f
  14:
     and       $s2, 0xFFFF
    sll        $s3, 16
    or         $s2, $s3
    sll        $v0, 16
    and        $s4, 0xFFFF
    or         $s4, $v0
    sw         $s2, 0x0($s0)
    sw         $s4, 0x4($s0)
    addu       $v0, $s0, $zero
  15:
    lw         $ra, 0x38($sp)
    lw         $s0, 0x18($sp)
    lw         $s1, 0x1C($sp)
    lw         $s2, 0x20($sp)
    lw         $s3, 0x24($sp)
    lw         $s4, 0x28($sp)
    lw         $s5, 0x2C($sp)
    lw         $s6, 0x30($sp)
    lw         $s7, 0x34($sp)
    addiu      $sp, 0x40
alabel func_800E6EAC
    jr         $ra
alabel func_800E6EB0
     lui       $t0, (0x800F0000 >> 16)
    addiu      $t0, 0x1928
    sll        $a0, 2
    addu       $t0, $a0
    lw         $t0, 0x0($t0)
    la         $t1, D_800F5878
    addu       $t1, $a0
    lw         $t1, 0x0($t1)
    sltu       $v0, $t0, 0x1
    sltu       $v1, $t1, 0x1
    and        $v0, $v1
    bnez       $v0, func_800E6EAC
     li        $v1, 0x1
    lbu        $v0, 0x9($t0)
    lw         $a1, 0x58($t1)
    sllv       $v1, $v1, $v0
    lw         $a2, 0x170($t1)
    and        $v1, 0x4800
    beqz       $v1, func_800E6EAC
     and       $a2, 0xFF00
    lbu        $a1, 0xC($a1)
    beqz       $a2, func_800E6EAC
     and       $a1, 0xF
    bnez       $a1, func_800E6EAC
     srl       $a0, $a2, 8
    bgez       $zero, func_800E4BD8
alabel func_800E6F1C
     lui       $t0, (0x800F5878 >> 16)
    addiu      $sp, -0x20
    sw         $s0, 0x10($sp)
    lui        $s0, %hi(vs_battle_actors)
    lw         $s0, %lo(vs_battle_actors)($s0)
    sw         $ra, 0x18($sp)
  16:
    lw         $v0, 0x4($s0)
    or         $t0, (0x800F5878 & 0xFFFF)
    sll        $v0, 2
    addu       $t0, $v0
    lw         $t0, 0x0($t0)
    jal        func_800E7454
     addu      $a0, $s0, $zero
    lw         $s0, 0x0($s0)
    lui        $t0, (0x800F5878 >> 16)
    bnez       $s0, 16b
     lui       $at, %hi(D_800F58D0)
    sw         $zero, %lo(D_800F58D0)($at)
    lui        $at, %hi(D_800F58B8)
    sw         $zero, %lo(D_800F58B8)($at)
    lui        $at, %hi(D_800F58C0)
    sw         $zero, %lo(D_800F58C0)($at)
    lui        $a0, %hi(D_800F58BC)
    lw         $a0, %lo(D_800F58BC)($a0)
    jal        vs_main_freeHeap
     li        $a1, 0x7
    lw         $s0, 0x10($sp)
    lw         $ra, 0x18($sp)
    lui        $at, %hi(D_800F58BC)
    sw         $zero, %lo(D_800F58BC)($at)
    jr         $ra
     addiu     $sp, 0x20
alabel func_800E6F9C
    addiu      $sp, -0x30
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    sw         $s2, 0x1C($sp)
    sw         $s5, 0x28($sp)
    sw         $s3, 0x20($sp)
    sw         $ra, 0x18($sp)
    jal        func_8008B6FC
     sw        $s4, 0x24($sp)
    lui        $at, %hi(D_800F58C0)
    sw         $v0, %lo(D_800F58C0)($at)
    addiu      $v0, 0x400
    lui        $at, %hi(D_800F58D8)
    sw         $v0, %lo(D_800F58D8)($at)
    addiu      $v0, 0x40
    lui        $at, %hi(D_800F58C8)
    sw         $v0, %lo(D_800F58C8)($at)
    addiu      $v0, 0x10
    lui        $at, %hi(D_800F5908)
    sw         $v0, %lo(D_800F5908)($at)
    addiu      $v0, 0x4
    lui        $at, %hi(D_800F5910)
    sw         $v0, %lo(D_800F5910)($at)
    addiu      $v0, 0x44
    lui        $at, %hi(D_800F58CC)
    sw         $v0, %lo(D_800F58CC)($at)
    addu       $a2, $zero, $zero
    li         $a0, 0x1038
    jal        vs_main_allocHeap
     li        $a1, 0x7
    lui        $at, %hi(D_800F58BC)
    sw         $v0, %lo(D_800F58BC)($at)
    addu       $s0, $v0, $zero
    addu       $a0, $v0, $zero
    jal        func_800E4288
     li        $a1, 0x1038
    addiu      $v0, $s0, 0x38
    lui        $at, %hi(D_800F58B8)
    sw         $v0, %lo(D_800F58B8)($at)
    addu       $s3, $v0, $zero
    addiu      $v0, $s0, 0x838
    lui        $at, %hi(D_800F58D0)
    sw         $v0, %lo(D_800F58D0)($at)
    addu       $s4, $v0, $zero
    jal        _getCollisionMapDimensions
     addu      $a0, $zero, $zero
    and        $a0, $v0, 0xFFFF
    srl        $a0, 4
    srl        $v1, $v0, 12
    or         $a0, $v1
    jal        func_8008E4AC
     sh        $a0, 0x4($s0)
    sh         $a0, 0x0($s0)
    sll        $v0, 6
    neg        $v0, $v0
    sw         $v0, 0x14($s0)
    addu       $s1, $zero, $zero
  17:
    addu       $a2, $zero, $zero
    and        $a0, $s1, 0x1F
    jal        func_8008B764
     srl       $a1, $s1, 5
    beqz       $v0, 18f
     and       $a0, $s1, 0x1F
    lw         $t0, 0x0($v0)
    srl        $a1, $s1, 5
    srl        $t1, $t0, 23
    and        $t1, 0xF
    srl        $t2, $t0, 27
    and        $t2, 0x1
    srl        $t3, $t0, 28
    and        $t3, 0x1
    srl        $t4, $t0, 17
    and        $t4, 0x1
    srl        $t5, $t0, 31
    and        $t5, 0x1
    srl        $t6, $t0, 30
    and        $t6, 0x1
    srl        $t7, $t0, 29
    and        $t7, 0x1
    sll        $t2, 4
    sll        $t4, 5
    sll        $t3, 6
    sll        $t5, 11
    sll        $t6, 12
    sll        $t7, 13
    or         $v1, $t1, $t2
    or         $v1, $t3
    or         $v1, $t5
    or         $v1, $t6
    or         $v1, $t7
    jal        func_800E71DC
     or        $s2, $v1, $t4
    addu       $t0, $s4, $zero
    sra        $v0, 6
    and        $v0, 0x3FF
    sll        $a0, $s1, 1
    addu       $t0, $a0
    sh         $v0, 0x0($t0)
    addu       $a2, $zero, $zero
    and        $a0, $s1, 0x1F
    jal        func_8008D438
     srl       $a1, $s1, 5
    beqz       $v0, 19f
     li        $a3, 0x1
    lhu        $a0, 0x6($v0)
    lhu        $a1, 0x8($v0)
    slt        $v0, $a0, 0x10
    beqz       $v0, 19f
     slt       $a0, $a1, 0x2
    beqz       $a0, 19f
     sllv      $a3, $a3, $a1
    sll        $a3, 8
    bgez       $zero, 19f
     or        $s2, $a3
  18:
    or         $s2, 0x8000
  19:
    sh         $s2, 0x0($s3)
    add        $s1, 0x1
    slt        $v1, $s1, 0x400
    bnez       $v1, 17b
     addiu     $s3, 0x2
    jal        func_800E6B4C
     nop
    lui        $a1, %hi(D_800F58C0)
    lw         $a1, %lo(D_800F58C0)($a1)
    lui        $v1, %hi(D_800F5908)
    lw         $v1, %lo(D_800F5908)($v1)
    bnez       $a1, 20f
     li        $v0, 0x96
    sh         $v0, 0x8($s0)
    bgez       $zero, 21f
  20:
     lw        $v1, 0x0($v1)
    lw         $a1, 0x494($a1)
    srl        $v0, $v1, 29
    sw         $a1, 0x0($s0)
    sb         $v0, 0xD($s0)
    sll        $v0, $v1, 3
    srl        $v0, 24
    sh         $v0, 0x8($s0)
    sll        $v0, $v1, 11
    srl        $v0, 31
    sb         $v0, 0xA($s0)
  21:
    lui        $ra, (0x800DB888 >> 16)
    bgez       $zero, func_800DC638
     or        $ra, (0x800DB888 & 0xFFFF)
alabel func_800E71DC
    addiu      $sp, -0x30
    sw         $s3, 0x20($sp)
    sw         $s5, 0x28($sp)
    sw         $s4, 0x24($sp)
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    sw         $s2, 0x1C($sp)
    sll        $s0, $a0, 7
    sll        $s1, $a1, 7
    addiu      $a0, $s0, 0x40
    jal        func_8008DC7C
     addiu     $a1, $s1, 0x40
    addu       $s5, $v0, $zero
    addu       $s2, $zero, $zero
    addu       $s4, $zero, $zero
    addu       $s3, $zero, $zero
  22:
    srl        $a0, $s2, 2
    sll        $a0, 5
    and        $a1, $s2, 0x3
    sll        $a1, 5
    add        $a0, $s0, $a0
    jal        func_8008DC7C
     add       $a1, $s1, $a1
    li         $v1, 0xA
    bne        $s2, $v1, 23f
     li        $t0, 0x1
    addu       $s4, $v0, $zero
  23:
    bgez       $v0, 24f
     sllv      $t0, $t0, $s2
    or         $s3, $t0
  24:
    sll        $t0, $v0, 17
    sra        $t0, 17
    sll        $v1, $s5, 17
    sra        $v1, 17
    slt        $v1, $t0
    beqz       $v1, 25f
     addiu     $s2, 0x1
    addu       $s5, $v0, $zero
  25:
    slt        $v0, $s2, 0x10
    bnez       $v0, 22b
     sltu      $v0, $s3, 0x1
    bnez       $v0, 28f
     neg       $v0, $s3
    add        $v0, -0x1
    addu       $v1, $zero, $zero
    li         $t0, 0x3
    li         $t1, 0x7
  26:
    beq        $v1, $t0, 27f
     or        $t2, $zero, 0x33
    beq        $v1, $t1, 27f
     sllv      $t2, $t2, $v1
    and        $t3, $v0, $t2
    beq        $t3, $t2, 28f
  27:
     addiu     $v1, 0x1
    slt        $t2, $v1, 0xA
    bnez       $t2, 26b
     nop
    addu       $s5, $s4, $zero
  28:
    bgez       $zero, func_800DB888
     addu      $v0, $s5, $zero
alabel func_800E72D0
    addiu      $sp, -0x30
    sw         $s0, 0x10($sp)
    sw         $ra, 0x18($sp)
    lui        $s0, %hi(vs_battle_actors)
    lw         $s0, %lo(vs_battle_actors)($s0)
    li         $t1, 0x800F5878
  29:
    lw         $t2, 0x4($s0)
    lui        $v0, (0xC80FFF30 >> 16)
    sll        $t2, 2
    addu       $t1, $t2
    lw         $t1, 0x0($t1)
    or         $v0, (0xC80FFF30 & 0xFFFF)
    lw         $t2, 0x1A4($t1)
    lh         $t4, 0x42($t1)
    and        $t2, $v0
    bltz       $t4, 30f
     srl       $t3, $t4, 3
    and        $t3, 0x3
    sll        $t3, 28
    or         $t2, $t3
    srl        $t3, $t4, 1
    and        $t3, 0x3
    sll        $t3, 6
    or         $t2, $t3
    srl        $t3, $t4, 6
    and        $t3, 0x7F
    sll        $t3, 20
    or         $t2, $t3
    sw         $t2, 0x1A4($t1)
    and        $t3, $t4, 0x1
    beqz       $t3, 30f
     addu      $a0, $t1, $zero
    jal        func_800DC210
     li        $a1, 0x1
  30:
    lw         $s0, 0x0($s0)
    lui        $t1, (0x800F5878 >> 16)
    bnez       $s0, 29b
     or        $t1, (0x800F5878 & 0xFFFF)
    bgez       $zero, func_800DB89C
alabel func_800E7370
     lui       $a3, (0x800F5878 >> 16)
    addiu      $sp, -0xC
    sw         $s0, 0x0($sp)
    sw         $s1, 0x4($sp)
    addu       $s0, $a0, $zero
    lui        $s1, %hi(vs_battle_actors)
    lw         $s1, %lo(vs_battle_actors)($s1)
    sw         $ra, 0x8($sp)
    beqz       $s1, 33f
     or        $a3, (0x800F5878 & 0xFFFF)
  31:
    lw         $t0, 0x4($s1)
    li         $v0, 0x2
    sll        $v1, $t0, 2
    addu       $a3, $v1
    lbu        $t3, 0x88($s0)
    lw         $a3, 0x0($a3)
    beq        $t3, $t0, 32f
     lbu       $v1, 0x2C($s0)
    lbu        $a2, 0x2C($a3)
    slt        $t2, $t0, 0x1
    slt        $a2, 0x3
    xor        $a2, 0x1
    or         $t2, $a2
    xor        $t2, 0x1
    la         $t1, D_80069C0C
    sll        $v1, 1
    addu       $v1, $t2
    addu       $v1, $t1
    lbu        $v0, 0x0($v1)
  32:
    sll        $v1, $t0, 2
    addu       $v1, $s0
    lw         $a2, 0x1A4($v1)
    add        $a1, $zero, -0xC1
    sll        $v0, 6
    and        $a2, $a1
    or         $a2, $v0
    sll        $v0, $t3, 2
    addu       $v0, $a3
    lw         $t0, 0x1A4($v0)
    la         $ra, D_800E7430
    sw         $a2, 0x1A4($v1)
    srl        $t0, 6
    and        $t0, 0x3
    slt        $t0, 0x1
    bnez       $t0, func_800E7370
     addu      $a0, $a3, $zero
alabel D_800E7430
    lw         $s1, 0x0($s1)
    lui        $a3, (0x800F5878 >> 16)
    bnez       $s1, 31b
     or        $a3, (0x800F5878 & 0xFFFF)
  33:
    lw         $ra, 0x8($sp)
    lw         $s0, 0x0($sp)
    lw         $s1, 0x4($sp)
    jr         $ra
     addiu     $sp, 0xC
alabel func_800E7454
    addiu      $sp, -0x30
    sw         $s5, 0x28($sp)
    sw         $s0, 0x10($sp)
    sw         $s2, 0x1C($sp)
    sw         $s1, 0x14($sp)
    sw         $ra, 0x18($sp)
    lui        $a1, %hi(D_800F58B8)
    lw         $a1, %lo(D_800F58B8)($a1)
    addu       $a0, $s0, $zero
    beqz       $a1, func_800DB890
     lbu       $a3, 0x1C($s0)
    lw         $s1, 0x4($s0)
    and        $a3, 0x14
    beqz       $a3, 34f
     lui       $a1, %hi(D_800F590C)
    lw         $a1, %lo(D_800F590C)($a1)
    li         $v0, 0x1
    sllv       $v0, $v0, $s1
    subu       $a1, $v0
    lui        $at, %hi(D_800F590C)
    sw         $a1, %lo(D_800F590C)($at)
  34:
    lui        $t0, %hi(vs_battle_actors)
    lw         $t0, %lo(vs_battle_actors)($t0)
    lui        $t6, (0x800F5878 >> 16)
    beqz       $t0, 37f
  35:
     lw        $a3, 0x4($t0)
    or         $t1, $t6, (0x800F5878 & 0xFFFF)
    sll        $a3, 2
    addu       $t1, $a3
    lw         $t1, 0x0($t1)
    nop
    lbu        $t2, 0x16($t1)
    nop
    bne        $t2, $s1, 36f
     li        $v0, 0x10
    sb         $v0, 0x16($t1)
  36:
    lw         $t0, 0x0($t0)
    lui        $t6, (0x800F5878 >> 16)
    bnez       $t0, 35b
  37:
     lui       $s5, %hi(D_800F58BC)
    lw         $s5, %lo(D_800F58BC)($s5)
    li         $v0, 0xC
  38:
    addu       $t4, $s5, $v0
    lw         $t5, 0x28($t4)
    or         $t6, (0x800F5878 & 0xFFFF)
    bne        $t5, $s0, 39f
     lbu       $a3, 0x1C($s0)
    sw         $zero, 0x28($t4)
  39:
    add        $v0, -0x4
    bgez       $v0, 38b
     and       $a3, 0x5
    beqz       $a3, func_800DB890
     sll       $v0, $s1, 2
    addu       $v0, $t6
    lw         $s2, 0x0($v0)
    jal        func_800E5240
     addu      $a0, $s1, $zero
    jal        func_800E678C
     addu      $a0, $s2, $zero
    beqz       $s1, func_800DB890
     lhu       $t1, 0x10($s5)
    li         $v0, 0x1
    sllv       $v0, $v0, $s1
    and        $v0, $t1
    beqz       $v0, 40f
     lbu       $t0, 0xB($s0)
    subu       $t1, $v0
    lbu        $t2, 0x12($s5)
    sh         $t1, 0x10($s5)
    add        $t2, -0x1
    sb         $t2, 0x12($s5)
  40:
    and        $t0, 0xFC
    beqz       $s2, 41f
     sb        $t0, 0xB($s0)
    jal        func_800D821C
     addu      $a0, $s2, $zero
    jal        func_800DBF00
     addu      $a0, $s2, $zero
    li         $a1, 0x7
    jal        vs_main_freeHeap
     addu      $a0, $s2, $zero
    la         $a0, D_800F5878
    sll        $a1, $s1, 2
    addu       $a0, $a1
    sw         $zero, 0x0($a0)
  41:
    lhu        $a0, 0x1A($s0)
    li         $ra, 0x800DB890
    li         $a1, 0xAC
    beq        $a0, $a1, 43f
     li        $a1, 0xAD
    beq        $a0, $a1, 43f
     nop
  42:
    jr         $ra
     li        $a1, 0xAC
  43:
    la         $a3, D_800F5920
    lw         $a0, 0x0($a3)
    li         $a1, 0x7
    j          vs_main_freeHeap
     sw        $zero, 0x0($a3)
alabel func_800E75EC
    lui        $a3, %hi(D_800F58BC)
    lw         $a3, %lo(D_800F58BC)($a3)
    nop
    beqz       $a3, 42b
     addu      $v0, $zero, $zero
    bgez       $zero, 42b
     lw        $v0, 0x14($a3)
alabel func_800E7608
    lui        $a3, %hi(vs_battle_actors)
    lw         $a3, %lo(vs_battle_actors)($a3)
    lui        $a1, (0x800F5878 >> 16)
  44:
    lw         $v0, 0x4($a3)
    or         $a1, (0x800F5878 & 0xFFFF)
    sll        $v0, 2
    addu       $v0, $a1
    lw         $v0, 0x0($v0)
    nop
    lbu        $v1, 0x16($v0)
    nop
    bne        $v1, $a0, 45f
     li        $v1, 0x10
    sb         $v1, 0x16($v0)
  45:
    lw         $a3, 0x0($a3)
    lui        $a1, (0x800F5878 >> 16)
    bnez       $a3, 44b
     or        $a1, (0x800F5878 & 0xFFFF)
    sll        $v0, $a0, 2
    addu       $a0, $v0, $a1
    j          func_800D82CC
     lw        $a0, 0x0($a0)
alabel func_800E7660
    addiu      $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    li         $a0, 0x20
    jal        vs_main_allocHeap
     li        $a1, 0x7
    addu       $a0, $v0, $zero
    lui        $at, %hi(D_800F5920)
    sw         $v0, %lo(D_800F5920)($at)
    jal        func_800E4288
     li        $a1, 0x20
    li         $v1, 0x384
    j          func_800DB89C
     sh        $v1, 0xC($v0)
endlabel func_800E6B4C
