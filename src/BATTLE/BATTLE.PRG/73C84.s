.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800DC484
    bgez    $zero, .L800DC490
    addiu   $v0, $zero, 0xF
endlabel func_800DC484

glabel func_800DC48C
    addiu   $v0, $zero, 0xE
.L800DC490:
    addiu   $v1, $zero, 0x34
    mult    $v1, $a0
    lui     $t0, %hi(vs_battle_actors)
    addiu   $t0, $t0, %lo(vs_battle_actors)
    sll     $a1, $a1, 2
    addu    $t0, $t0, $a1
    lw      $t0, 0x0($t0)
    lui     $t2, %hi(vs_main_actions)
    addiu   $t2, $t2, %lo(vs_main_actions)
    lw      $t0, 0x3C($t0)
    mflo    $t1
    lbu     $t0, 0x37($t0)
    addu    $t1, $t1, $t2
    lhu     $t1, 0xE($t1)
    andi    $t0, $t0, 0x7
    srlv    $t1, $t1, $v0
    andi    $v0, $t1, 0x1
    ori     $v1, $zero, 0x60
    bne     $v1, $a0, .L800DC4EC
    addiu   $v1, $zero, 0x2
    bne     $t0, $v1, .L800DC4EC
    nop
    xori    $v0, $t1, 0x1
.L800DC4EC:
    jr      $ra
endlabel func_800DC48C

glabel func_800DC4F0
    addiu   $a2, $zero, 0x1
    lw      $t0, 0x4($a0)
    lui     $t3, %hi(D_800F58F0)
    addiu   $t3, $t3, %lo(D_800F58F0)
    lhu     $t1, 0xE($a1)
    andi    $v0, $t0, 0x7
    sll     $v0, $v0, 2
    srl     $v1, $t0, 3
    andi    $v1, $v1, 0x3
    lui     $t2, %hi(D_800F58F4)
    lw      $t2, %lo(D_800F58F4)($t2)
    add     $v0, $v0, $v1 /* handwritten instruction */
    sll     $t1, $t1, 25
    bgez    $t1, .L800DC4EC
    sllv    $a2, $a2, $v0
    and     $a3, $t2, $a2
    bnez    $a3, .L800DC4EC
    addiu   $v0, $zero, 0x14
    lw      $a3, 0x0($t3)
    or      $t2, $t2, $a2
    mult    $v0, $a3
    lui     $v1, %hi(D_800F58F8)
    lw      $v1, %lo(D_800F58F8)($v1)
    addu    $a1, $a0, $zero
    mflo    $v0
    lui     $at, %hi(D_800F58F4)
    sw      $t2, %lo(D_800F58F4)($at)
    addu    $a0, $v0, $v1
    slti    $v0, $a3, 0x10
    beqz    $v0, .L800DC4EC
    addiu   $a3, $a3, 0x1
    bgez    $zero, func_800DC2E0
    sw      $a3, 0x0($t3)
endlabel func_800DC4F0

glabel func_800DC574
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    sw      $s2, 0x1C($sp)
    sw      $s5, 0x28($sp)
    lbu     $s2, 0x2B($a0)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    addu    $s5, $zero, $zero
.L800DC59C:
    jal     rand
    nop
    sll     $v1, $s5, 2
    addu    $v1, $v1, $s0
    lw      $t0, 0x430($v1)
    andi    $v0, $v0, 0x7F
    lw      $t1, 0x4($t0)
    lw      $t3, 0xC($t0)
    srl     $t2, $t1, 5
    andi    $t2, $t2, 0xFF
    beqz    $t2, .L800DC620
    srl     $t4, $t3, 19
    andi    $t4, $t4, 0xFF
    addiu   $v1, $t4, 0x4C
    bnez    $s2, .L800DC5DC
    srl     $a0, $v1, 1
.L800DC5DC:
    slti    $v1, $t4, 0x4C
    bnez    $v1, .L800DC5EC
    addu    $a0, $t4, $zero
    addiu   $a0, $zero, 0x4C
.L800DC5EC:
    sltu    $v0, $v0, $a0
    beqz    $v0, .L800DC620
    lw      $v0, 0x430($s0)
    lui     $ra, %hi(L800DB890)
    addiu   $ra, $ra, %lo(L800DB890)
    addiu   $a1, $zero, 0x1
    sll     $v1, $s5, 2
    addu    $v1, $s0, $v1
    sw      $t0, 0x430($s0)
    sw      $v0, 0x430($v1)
    addi    $a2, $s1, -0x1 /* handwritten instruction */
    bgez    $zero, L800E6958
    addiu   $a0, $s0, 0x430
.L800DC620:
    addi    $s5, $s5, 0x1 /* handwritten instruction */
    slt     $v0, $s5, $s1
    bnez    $v0, .L800DC59C
    nop
    bgez    $zero, L800DB890
    nop
endlabel func_800DC574

glabel func_800DC638
    addiu   $sp, $sp, -0x80
    sw      $ra, 0x78($sp)
    jal     func_8008D2C0
    addiu   $a0, $sp, 0x10
    addiu   $v1, $sp, 0x10
    addu    $a3, $zero, $zero
.L800DC650:
    beqz    $v0, .L800DC674
    addi    $v0, $v0, -0x1 /* handwritten instruction */
    sll     $a0, $v0, 3
    addu    $a0, $a0, $v1
    lhu     $a0, 0x6($a0)
    addiu   $a1, $zero, 0x1
    sllv    $a1, $a1, $a0
    bgez    $zero, .L800DC650
    or      $a3, $a3, $a1
.L800DC674:
    lui     $a1, %hi(D_800F58C0)
    lw      $a1, %lo(D_800F58C0)($a1)
    lui     $t0, %hi(D_800F5910)
    lw      $t0, %lo(D_800F5910)($t0)
    addu    $a0, $zero, $zero
    beqz    $a1, .L800DC778
.L800DC68C:
    addu    $a2, $a1, $a0
    lw      $v0, 0x0($a2)
    addu    $t1, $zero, $zero
    lui     $at, (0x4000400 >> 16)
    ori     $at, $at, (0x4000400 & 0xFFFF)
    and     $at, $v0, $at
    beqz    $at, .L800DC768
    lui     $at, (0x80008000 >> 16)
    ori     $at, $at, (0x80008000 & 0xFFFF)
    or      $v0, $v0, $at
    sll     $t3, $v0, 22
    srl     $t3, $t3, 27
    andi    $t4, $v0, 0x1F
    sll     $t5, $v0, 6
    srl     $t5, $t5, 27
    srl     $t6, $v0, 16
    andi    $t6, $t6, 0x1F
    srl     $t2, $v0, 13
    andi    $t2, $t2, 0x3
    srl     $t9, $v0, 29
    andi    $t9, $t9, 0x3
.L800DC6E0:
    sll     $at, $t1, 2
    addu    $at, $at, $t0
    lw      $at, 0x0($at)
    nop
    andi    $t7, $at, 0x1F
    sll     $t8, $at, 22
    srl     $t8, $t8, 27
    sll     $at, $v0, 21
    bgez    $at, .L800DC72C
    nop
    bne     $t3, $t7, .L800DC72C
    addiu   $v1, $zero, 0x1
    bne     $t4, $t8, .L800DC72C
    sllv    $t2, $v1, $t2
    and     $t2, $t2, $a3
    beqz    $t2, .L800DC72C
    lui     $at, (0xFFFF7FFF >> 16)
    ori     $at, $at, (0xFFFF7FFF & 0xFFFF)
    and     $v0, $v0, $at
.L800DC72C:
    sll     $at, $v0, 5
    bgez    $at, .L800DC754
    sllv    $t9, $v1, $t9
    bne     $t5, $t7, .L800DC754
    and     $t9, $t9, $a3
    bne     $t6, $t8, .L800DC754
    nop
    beqz    $t9, .L800DC754
    sll     $at, $v0, 1
    srl     $v0, $at, 1
.L800DC754:
    addiu   $t1, $t1, 0x1
    slti    $v1, $t1, 0x8
    bnez    $v1, .L800DC6E0
    nop
    sw      $v0, 0x0($a2)
.L800DC768:
    addiu   $a0, $a0, 0x4
    slti    $v1, $a0, 0x400
    bnez    $v1, .L800DC68C
    nop
.L800DC778:
    lw      $ra, 0x78($sp)
    addiu   $sp, $sp, 0x80
    jr      $ra
endlabel func_800DC638

glabel func_800DC784
    sll     $a1, $a1, 2
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s1, 0x14($sp)
    sw      $s2, 0x1C($sp)
    addu    $v0, $a0, $a1
    lw      $s2, 0x1A4($v0)
    addu    $s1, $v0, $zero
    sw      $s0, 0x10($sp)
    addu    $s0, $a0, $zero
    srl     $v0, $s2, 6
    andi    $v0, $v0, 0x3
    slti    $v0, $v0, 0x3
    beqz    $v0, .L800DC7FC
    nop
    jal     rand
    nop
    andi    $v0, $v0, 0x7F
    slti    $v0, $v0, 0x80
    beqz    $v0, .L800DC7DC
    addiu   $v1, $zero, 0x1
    sb      $v1, 0x18($s0)
.L800DC7DC:
    addiu   $a1, $zero, 0x6
    addiu   $a2, $zero, 0x28
    jal     func_800D8260
    addu    $a0, $s0, $zero
    addiu   $a1, $zero, 0x2
    addiu   $a2, $zero, 0x80
    jal     func_800E48A8
    addu    $a0, $s0, $zero
.L800DC7FC:
    addi    $v0, $zero, -0x7FC1 /* handwritten instruction */
    and     $s2, $s2, $v0
    ori     $s2, $s2, 0xC0
    bgez    $zero, L800DB894
    sw      $s2, 0x1A4($s1)
endlabel func_800DC784

glabel func_800DC810
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s1, 0x14($sp)
    sw      $s5, 0x28($sp)
    sw      $s2, 0x1C($sp)
    addu    $s1, $a0, $zero
    sw      $s0, 0x10($sp)
    lui     $s5, %hi(func_800DD000)
    addiu   $s5, $s5, %lo(func_800DD000)
    addiu   $s2, $zero, 0x2
.L800DC838:
    lui     $s0, %hi(vs_battle_actors)
    lw      $s0, %lo(vs_battle_actors)($s0)
    lui     $t1, (0x800F5878 >> 16)
.L800DC844:
    lw      $t0, 0x4($s0)
    ori     $t1, $t1, (0x800F5878 & 0xFFFF)
    sll     $t0, $t0, 2
    addu    $t1, $t1, $t0
    lw      $a0, 0x0($t1)
    jalr    $s5
    addu    $a1, $s1, $zero
    lw      $s0, 0x0($s0)
    lui     $t1, (0x800F5878 >> 16)
    bnez    $s0, .L800DC844
    nop
    addi    $s2, $s2, -0x1 /* handwritten instruction */
    lui     $s5, (0x800DD344 >> 16)
    bgtz    $s2, .L800DC838
    ori     $s5, $s5, (0x800DD344 & 0xFFFF)
    bgez    $zero, L800DB890
    nop
endlabel func_800DC810
