.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800DB370
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    sw      $s2, 0xC($sp)
    lui     $t0, %hi(D_800F4538)
    addiu   $t0, $t0, %lo(D_800F4538)
    sll     $v0, $a1, 2
    addu    $t0, $t0, $v0
    lw      $t0, 0x0($t0)
    lui     $t1, (0x1F80037C >> 16)
    addu    $t1, $t1, $v0
    lw      $t1, (0x1F80037C & 0xFFFF)($t1)
    addu    $s0, $a0, $zero
    addu    $s1, $a3, $zero
    lbu     $t2, 0xE5($s0)
    beqz    $t1, .L800DB484
    lh      $t3, 0x15E($s0)
    beq     $t2, $a1, .L800DB3C8
    andi    $t3, $t3, 0x38
    sw      $zero, 0xE4($s0)
    sw      $zero, 0xE8($s0)
.L800DB3C8:
    lbu     $v0, 0xA($t0)
    sb      $a1, 0xE5($s0)
    sw      $a2, 0xDC($s0)
    bnez    $t3, .L800DB448
    andi    $v0, $v0, 0x1F
    beqz    $v0, .L800DB448
    nop
    lw      $v0, 0x60($t0)
    nop
    sw      $v0, 0x168($s0)
    andi    $t0, $v0, 0xFF00
    beqz    $t0, .L800DB478
    srl     $t0, $t0, 8
    addi    $a0, $t0, -0x2 /* handwritten instruction */
.L800DB400:
    jal     func_8008E2D4
    addu    $s2, $a0, $zero
    lw      $a1, 0x0($v0)
    lw      $a2, 0x8($v0)
    addiu   $a3, $s0, 0x168
    jal     func_800DFA54
    addu    $a0, $s2, $zero
    lw      $a0, 0x168($s0)
    nop
    sw      $a0, 0xEC($s0)
    sll     $a1, $a0, 8
    srl     $a1, $a1, 24
    sll     $a1, $a1, 1
    andi    $a0, $a0, 0xFF
    sll     $a0, $a0, 1
    or      $a0, $a0, $a1
    bgez    $zero, .L800DB478
    sw      $a0, 0xF4($s0)
.L800DB448:
    lbu     $v0, 0x29($s0)
    lbu     $v1, 0xC($t0)
    or      $v0, $v0, $t3
    beqz    $v0, .L800DB46C
    andi    $v1, $v1, 0xF
    beqz    $v1, .L800DB46C
    addi    $a0, $v1, -0x2 /* handwritten instruction */
    bgez    $zero, .L800DB400
    nop
.L800DB46C:
    lw      $v0, 0x5C($t0)
    nop
    sw      $v0, 0x168($s0)
.L800DB478:
    addu    $a0, $s0, $zero
    jal     func_800E24EC
    addu    $a1, $s1, $zero
.L800DB484:
    lw      $ra, 0x18($sp)
    addu    $a0, $s0, $zero
    lw      $s0, 0x10($sp)
    lw      $s1, 0x14($sp)
    lw      $s2, 0xC($sp)
    addiu   $sp, $sp, 0x20
    bnez    $v0, func_800DB4AC
    addiu   $a1, $zero, 0x1
    jr      $ra
    addiu   $a1, $zero, 0x0
endlabel func_800DB370

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800DB4AC
    lbu     $v0, 0x8A($a0)
    addi    $v1, $zero, -0x1 /* handwritten instruction */
    bne     $v0, $a1, .L800DB4C0
    sb      $a1, 0x89($a0)
.L800DB4BC:
    jr      $ra
.L800DB4C0:
    addiu   $v0, $zero, 0x1
    bne     $v0, $a1, .L800DB4D8
    addiu   $v0, $zero, 0x3
    sw      $zero, 0xE4($a0)
    bgez    $zero, .L800DB59C
    sh      $zero, 0xE8($a0)
.L800DB4D8:
    bne     $v0, $a1, .L800DB4EC
    addiu   $v0, $zero, 0x6
    sh      $zero, 0xC0($a0)
    bgez    $zero, .L800DB59C
    sh      $zero, 0xD2($a0)
.L800DB4EC:
    bne     $v0, $a1, .L800DB504
    addiu   $v0, $zero, 0x5
    sb      $zero, 0x10C($a0)
    addi    $v0, $zero, -0x1 /* handwritten instruction */
    bgez    $zero, .L800DB59C
    sw      $v0, 0x108($a0)
.L800DB504:
    bne     $v0, $a1, .L800DB59C
    addi    $v0, $zero, -0x1 /* handwritten instruction */
    lbu     $t0, 0x101($a0)
    lui     $t1, %hi(D_800F58D8)
    lw      $t1, %lo(D_800F58D8)($t1)
    sll     $t0, $t0, 4
    lw      $t3, 0x34($a0)
    addu    $t1, $t1, $t0
    addiu   $t2, $zero, 0x8
    sll     $t4, $t3, 8
    srl     $t4, $t4, 24
    andi    $t3, $t3, 0xFF
.L800DB534:
    lh      $t0, 0x0($t1)
    nop
    bgez    $t0, .L800DB580
    andi    $a2, $t0, 0x1F
    srl     $a3, $t0, 5
    andi    $a3, $a3, 0x1F
    sub     $a2, $a2, $t3 /* handwritten instruction */
    bgez    $a2, .L800DB55C
    sub     $a3, $a3, $t4 /* handwritten instruction */
    neg     $a2, $a2 /* handwritten instruction */
.L800DB55C:
    bgez    $a3, .L800DB568
    nop
    neg     $a3, $a3 /* handwritten instruction */
.L800DB568:
    addu    $a2, $a2, $a3
    sltu    $a3, $a2, $v0
    beqz    $a3, .L800DB580
    addiu   $a3, $zero, 0x8
    addu    $v0, $a2, $zero
    subu    $v1, $a3, $t2
.L800DB580:
    addi    $t2, $t2, -0x1 /* handwritten instruction */
    bgtz    $t2, .L800DB534
    addiu   $t1, $t1, 0x2
    bltz    $v1, .L800DB598
    addiu   $v0, $zero, 0x1
    sb      $v1, 0x100($a0)
.L800DB598:
    sb      $zero, 0x104($a0)
.L800DB59C:
    sb      $a1, 0x8A($a0)
    sll     $a2, $a1, 1
    addu    $a2, $a0, $a2
    bgez    $zero, func_800E4BB8
    sb      $zero, 0x474($a2)
endlabel func_800DB4AC

# hasm: cross-function control flow
glabel func_800DB5B0
    lw      $a1, 0xCC($a0)
    lw      $a2, 0xC8($a0)
endlabel func_800DB5B0

# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800DB5B8
    addu    $t9, $ra, $zero
    addu    $t8, $a1, $zero
    addu    $t7, $a2, $zero
    jal     func_800DB4AC
    addiu   $a1, $zero, 0x3
    addu    $ra, $t9, $zero
    addu    $a1, $t8, $zero
    bgez    $zero, func_800E1EAC
    addu    $a2, $t7, $zero
endlabel func_800DB5B8

# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800DB5DC
    sw      $a1, 0x168($a0)
    addu    $t9, $ra, $zero
    addu    $t8, $a2, $zero
    jal     func_800DB4AC
    addiu   $a1, $zero, 0x2
    addu    $ra, $t9, $zero
    bgez    $zero, L800E5030
    addu    $a1, $t8, $zero
endlabel func_800DB5DC

# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800DB5FC
    lui     $a3, (0x1F8003F4 >> 16)
    lw      $a3, (0x1F8003F4 & 0xFFFF)($a3)
    beqz    $a2, .L800DB4BC
    addu    $t9, $ra, $zero
    jal     func_800DB4AC
    addiu   $a1, $zero, 0x5
    bgez    $zero, func_800E23AC
    addu    $ra, $t9, $zero
endlabel func_800DB5FC

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800DB61C
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    sw      $ra, 0x18($sp)
    lui     $t0, %hi(vs_battle_actors)
    lw      $t0, %lo(vs_battle_actors)($t0)
    addu    $s0, $a0, $zero
    addu    $t5, $zero, $zero
    addu    $t7, $zero, $zero
    addu    $t8, $zero, $zero
.L800DB640:
    lw      $t1, 0x4($t0)
    lui     $t2, %hi(D_800F4538)
    addiu   $t2, $t2, %lo(D_800F4538)
    sll     $t1, $t1, 2
    addu    $v0, $t1, $s0
    lw      $v0, 0x1A4($v0)
    addu    $v1, $t1, $t2
    srl     $v0, $v0, 5
    andi    $v0, $v0, 0x7
    slti    $v0, $v0, 0x7
    bnez    $v0, .L800DB698
    addiu   $t6, $zero, 0x1
    lw      $v1, 0x0($v1)
    addiu   $t8, $t8, 0x1
    lh      $t1, 0x1C($v1)
    lh      $t3, 0x20($v1)
    add     $t5, $t5, $t1 /* handwritten instruction */
    add     $t7, $t7, $t3 /* handwritten instruction */
    beq     $t6, $t8, .L800DB698
    nop
    srl     $t5, $t5, 1
    srl     $t7, $t7, 1
.L800DB698:
    lw      $t0, 0x0($t0)
    nop
    bnez    $t0, .L800DB640
    nop
    blez    $t8, .L800DB6CC
    addiu   $v0, $zero, 0x5A
    sh      $v0, 0x114($s0)
    srl     $t5, $t5, 7
    srl     $t7, $t7, 7
    sll     $t7, $t7, 16
    or      $t5, $t5, $t7
    bgez    $zero, .L800DB6F0
    sw      $t5, 0x110($s0)
.L800DB6CC:
    lhu     $v0, 0x114($s0)
    lbu     $v1, 0x8A($s0)
    beqz    $v0, .L800DB6E0
    addiu   $t0, $zero, 0x4
    addi    $v0, $v0, -0x1 /* handwritten instruction */
.L800DB6E0:
    beqz    $v0, .L800DB72C
    sh      $v0, 0x114($s0)
    bne     $t0, $v1, .L800DB72C
    addu    $v0, $zero, $zero
.L800DB6F0:
    lw      $v1, 0x110($s0)
    addiu   $v0, $zero, 0x1
    sb      $v0, 0x4($s0)
    sll     $t1, $v1, 8
    srl     $t1, $t1, 24
    andi    $t0, $v1, 0xFF
    sll     $t0, $t0, 7
    sll     $t1, $t1, 7
    addiu   $t0, $t0, 0x40
    addiu   $t1, $t1, 0x40
    sw      $t0, 0x17C($s0)
    sw      $t1, 0x180($s0)
    jal     func_800E4FE0
    sw      $v1, 0x168($s0)
    addiu   $v0, $zero, 0x1
.L800DB72C:
    lw      $ra, 0x18($sp)
    addu    $a0, $s0, $zero
    lw      $s0, 0x10($sp)
    addiu   $sp, $sp, 0x20
    bnez    $v0, func_800DB4AC
    addiu   $a1, $zero, 0x4
    jr      $ra
    nop
endlabel func_800DB61C

# hasm: cross-function control flow
glabel func_800DB74C
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    sw      $ra, 0x18($sp)
    lui     $v0, %hi(D_800F4538)
    addiu   $v0, $v0, %lo(D_800F4538)
    sll     $v1, $a1, 2
    addu    $v0, $v0, $v1
    lw      $v0, 0x0($v0)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    lh      $t0, 0x1C($v0)
    lh      $t1, 0x20($v0)
    lw      $t2, 0x5C($v0)
    sw      $t0, 0x17C($a0)
    sw      $t1, 0x180($a0)
    jal     func_800E2B2C
    sw      $t2, 0x168($a0)
    addu    $a0, $s0, $zero
    lw      $s0, 0x10($sp)
    lw      $s1, 0x14($sp)
    lw      $ra, 0x18($sp)
    addiu   $a1, $zero, 0x6
    bnez    $v0, func_800DB4AC
    addiu   $sp, $sp, 0x20
.L800DB7B0:
    jr      $ra
endlabel func_800DB74C

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800DB7B4
    addiu   $t2, $zero, 0x1
    lbu     $t0, 0x12D($a0)
    addiu   $t1, $zero, 0x0
    beq     $t0, $t1, .L800DB7B0
    addiu   $t3, $zero, 0x2
    bne     $t0, $t2, .L800DB7F0
    lw      $v0, 0x54($a0)
    nop
    lbu     $v0, 0x9($v0)
    nop
    slti    $v0, $v0, 0x9
    beqz    $v0, .L800DB7F0
    nop
    bgez    $zero, func_800DEEFC
    addiu   $a1, $zero, 0x1
.L800DB7F0:
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    jal     func_800E678C
    addu    $s0, $a0, $zero
    sb      $zero, 0x12D($s0)
    addu    $a0, $s0, $zero
    lw      $s0, 0x10($sp)
    lw      $ra, 0x18($sp)
    addiu   $a1, $zero, 0x2
    bgez    $zero, func_800DEEFC
    addiu   $sp, $sp, 0x20
endlabel func_800DB7B4

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800DB820
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    sw      $ra, 0x18($sp)
    jal     func_800DAD9C
    addu    $s0, $a0, $zero
    bnez    $v0, .L800DB878
    addu    $a0, $s0, $zero
    jal     func_800DB0BC
    nop
    bnez    $v0, .L800DB878
    lw      $v1, 0x68($s0)
    nop
    beqz    $v1, .L800DB868
    nop
    jalr    $v1
    addu    $a0, $s0, $zero
    bnez    $v0, .L800DB878
    addu    $a0, $s0, $zero
.L800DB868:
    lw      $ra, 0x18($sp)
    lw      $s0, 0x10($sp)
    bgez    $zero, func_800DB5B0
    addiu   $sp, $sp, 0x20
.L800DB878:
    lw      $ra, 0x18($sp)
    lw      $s0, 0x10($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
alabel L800DB888
    lw      $s3, 0x20($sp)
    lw      $s4, 0x24($sp)
alabel L800DB890
    lw      $s5, 0x28($sp)
alabel L800DB894
    lw      $s1, 0x14($sp)
.L800DB898:
    lw      $s2, 0x1C($sp)
alabel L800DB89C
    lw      $ra, 0x18($sp)
    lw      $s0, 0x10($sp)
    jr      $ra
    addiu   $sp, $sp, 0x30
endlabel func_800DB820

# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800DB8AC
    addu    $t6, $ra, $zero
    lhu     $t7, 0x8E($a0)
    jal     func_800DBCB4
    lhu     $t5, 0x98($a0)
    bnez    $t7, .L800DB934
    addiu   $v0, $zero, 0x1
    bnez    $t5, .L800DB934
    addu    $v0, $zero, $zero
    lw      $t0, 0xC($a1)
    lui     $t1, %hi(D_800F58BC)
    lw      $t1, %lo(D_800F58BC)($t1)
    andi    $t0, $t0, 0xF
    sll     $t0, $t0, 2
    addu    $t0, $t0, $a0
    lw      $t0, 0x1A4($t0)
    lw      $t2, 0x24($t1)
    lbu     $t4, 0xD($t1)
    andi    $t0, $t0, 0x1
    beqz    $t0, .L800DB934
    sltu    $t2, $t4, $t2
    lbu     $t3, 0x88($a0)
    bnez    $t2, .L800DB934
    addiu   $t2, $zero, 0x1
    lhu     $t0, 0x10($t1)
    sllv    $t2, $t2, $t3
    and     $t0, $t0, $t2
    bnez    $t0, .L800DB934
    addiu   $v0, $zero, 0x1
    lbu     $t2, 0x12($t1)
    addu    $v0, $zero, $zero
    sltu    $t4, $t4, $t2
    bnez    $t4, .L800DB934
    nop
    addiu   $v0, $zero, 0x1
.L800DB934:
    addu    $ra, $t6, $zero
    jr      $ra
endlabel func_800DB8AC

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: saved registers outside frame
glabel func_800DB93C
    lui     $t0, (0x1F8003C0 >> 16)
    addiu   $sp, $sp, -0x30
    sw      $s2, 0x1C($sp)
    sw      $s0, 0x10($sp)
    sw      $ra, 0x18($sp)
    lw      $t0, (0x1F8003C0 & 0xFFFF)($t0)
    sll     $a1, $a1, 8
    srl     $a1, $a1, 8
    andi    $t1, $a1, 0xFF
    srl     $t2, $a1, 16
    sll     $t4, $t2, 6
    sll     $t3, $t1, 1
    addu    $v0, $t3, $t4
    addu    $v0, $v0, $t0
    lhu     $v0, 0x0($v0)
    addu    $s0, $a0, $zero
    addu    $s2, $a1, $zero
    lbu     $v1, 0xB2($a0)
    sll     $v0, $v0, 26
    bgez    $v0, .L800DB898
    addu    $v0, $a1, $zero
    slti    $v0, $v1, 0x3
    lui     $t0, (0x1F8003EC >> 16)
    addu    $t0, $t0, $a2
    lbu     $t0, (0x1F8003EC & 0xFFFF)($t0)
    bnez    $v0, .L800DB9AC
    addu    $t4, $v1, $zero
    addiu   $t4, $zero, 0x3
.L800DB9AC:
    sll     $t5, $t0, 30
    sra     $t5, $t5, 30
    sll     $t6, $t0, 26
    sra     $t6, $t6, 30
    lui     $t7, (0x1F8003C0 >> 16)
    lw      $t7, (0x1F8003C0 & 0xFFFF)($t7)
    addu    $t3, $zero, $zero
.L800DB9C8:
    add     $t1, $t1, $t5 /* handwritten instruction */
    add     $t2, $t2, $t6 /* handwritten instruction */
    andi    $t1, $t1, 0xFF
    andi    $t2, $t2, 0xFF
    sll     $a0, $t2, 6
    sll     $a1, $t1, 1
    add     $a0, $a0, $a1 /* handwritten instruction */
    addu    $t0, $a0, $t7
    lhu     $t0, 0x0($t0)
    sll     $a0, $t2, 16
    or      $s2, $a0, $t1
    addiu   $t3, $t3, 0x1
    sll     $t0, $t0, 26
    bltz    $t0, .L800DBA38
    slt     $v0, $t3, $t4
    beqz    $v0, .L800DBA40
    addu    $a0, $s0, $zero
    addu    $a1, $a3, $zero
    addu    $a3, $a2, $zero
    jal     func_800D96C8
    addu    $a2, $s2, $zero
    addiu   $v1, $zero, 0x1
    bne     $v0, $v1, .L800DBA40
    addu    $a0, $s0, $zero
    lui     $ra, %hi(.L800DBA40)
    addiu   $ra, $ra, %lo(.L800DBA40)
    bgez    $zero, func_800D954C
    addu    $a1, $s2, $zero
.L800DBA38:
    bnez    $v1, .L800DB9C8
    addu    $v0, $zero, $zero
.L800DBA40:
    sll     $v0, $v0, 24
    bgez    $zero, .L800DB898
    or      $v0, $s2, $v0
    lbu     $v0, 0xE($a0)
    addiu   $a1, $sp, -0x30
    beqz    $v0, func_800DA1D4
    sw      $s0, 0x10($a1)
    addu    $s0, $a0, $zero
    sw      $ra, 0x18($a1)
    addu    $sp, $a1, $zero
    jal     func_800DB61C
    addiu   $a1, $zero, 0x1
    bnez    $v0, L800DB89C
    addiu   $v0, $zero, 0x1
    jal     func_800DB5B0
    addu    $a0, $s0, $zero
    bgez    $zero, L800DB89C
    addiu   $v0, $zero, 0x1
    lbu     $v0, 0xE($a0)
    lbu     $v1, 0x131($a0)
    bnez    $v0, func_800DB61C
    addiu   $a1, $zero, 0x1
    sllv    $a1, $a1, $v1
    andi    $a1, $a1, 0x3
    beqz    $a1, func_800DA1D4
    andi    $a1, $a1, 0x1
    lw      $a2, 0x58($a0)
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s2, 0x1C($sp)
    sw      $s1, 0x14($sp)
    lbu     $a2, 0xA($a2)
    addu    $s0, $a0, $zero
    andi    $a2, $a2, 0x20
    lw      $a3, 0x430($s0)
    bnez    $a2, .L800DBADC
    addiu   $s2, $zero, 0x140
    addiu   $s2, $zero, 0x100
.L800DBADC:
    lw      $s1, 0xC($a3)
    beqz    $a1, .L800DBB00
    lw      $a0, 0x8($a3)
    jal     vs_gte_rsqrt
    nop
    slt     $v1, $s2, $v0
    bnez    $v1, .L800DBB00
    nop
    addu    $s2, $v0, $zero
.L800DBB00:
    addu    $a2, $s2, $zero
    andi    $a1, $s1, 0xF
    addu    $a0, $s0, $zero
    jal     func_800DB370
    addiu   $a3, $zero, 0x0
    bnez    $v0, L800DB894
    addu    $a0, $s0, $zero
    lui     $ra, %hi(L800DB894)
    addiu   $ra, $ra, %lo(L800DB894)
    bgez    $zero, func_800DB74C
    andi    $a1, $s1, 0xF
endlabel func_800DB93C

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: saved registers outside frame
glabel func_800DBB2C
    lui     $v0, %hi(vs_battle_actors)
    lw      $v0, %lo(vs_battle_actors)($v0)
    lbu     $t0, 0x88($a0)
.L800DBB38:
    lw      $t1, 0x4($v0)
    nop
    beq     $t1, $t0, .L800DBB80
    sll     $t3, $t1, 2
    addu    $t3, $t3, $a0
    lw      $t3, 0x1A4($t3)
    sll     $t2, $a2, 6
    andi    $t3, $t3, 0xC0
    bne     $t3, $t2, .L800DBB80
    nop
    beqz    $a1, .L800DBB78
    lw      $t3, 0x44($v0)
    nop
    lw      $t3, 0x5C($t3)
    nop
    sw      $t3, 0x0($a1)
.L800DBB78:
    jr      $ra
    addu    $v0, $t1, $zero
.L800DBB80:
    lw      $v0, 0x0($v0)
    nop
    bnez    $v0, .L800DBB38
    nop
    jr      $ra
    addi    $v0, $zero, -0x1 /* handwritten instruction */
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    jal     func_800DA1D4
    addu    $s0, $a0, $zero
    bnez    $v0, L800DB89C
    addu    $a0, $s0, $zero
    addiu   $a1, $sp, 0x28
    jal     func_800DBB2C
    addiu   $a2, $zero, 0x2
    addu    $v1, $v0, $zero
    bltz    $v1, L800DB89C
    addu    $v0, $zero, $zero
    sll     $v1, $v1, 2
    addu    $v0, $a0, $v1
    lw      $v0, 0x1E4($v0)
    lui     $t0, (0x64000 >> 16)
    ori     $t0, $t0, (0x64000 & 0xFFFF)
    sltu    $v0, $t0, $v0
    lw      $a1, 0x28($sp)
    addu    $a2, $zero, $zero
    lui     $ra, %hi(D_800DBC04)
    addiu   $ra, $ra, %lo(D_800DBC04)
    bnez    $v0, func_800DB5DC
    addu    $a0, $s0, $zero
    bgez    $zero, func_800DB5B8
    addiu   $a2, $zero, 0x5
alabel D_800DBC04
    bgez    $zero, L800DB89C
    addiu   $v0, $zero, 0x1
alabel D_800DBC0C
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    jal     func_800D826C
    addu    $s0, $a0, $zero
    beqz    $v0, .L800DBC38
    addu    $a1, $zero, $zero
    jal     func_800DA1D4
    addu    $a0, $s0, $zero
    bnez    $v0, L800DB89C
    addu    $a1, $zero, $zero
.L800DBC38:
    addiu   $a2, $zero, 0x100
    addiu   $a3, $zero, 0x0
    jal     func_800DB370
    addu    $a0, $s0, $zero
    bnez    $v0, L800DB89C
    addu    $a0, $s0, $zero
    lui     $ra, %hi(L800DB89C)
    addiu   $ra, $ra, %lo(L800DB89C)
    bgez    $zero, func_800DB74C
    addu    $a1, $zero, $zero
endlabel func_800DBB2C
