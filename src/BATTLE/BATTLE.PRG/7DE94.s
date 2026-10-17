.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
glabel func_800E6694
    lui     $t0, %hi(D_800F5878)
    addiu   $t0, $t0, %lo(D_800F5878)
    sll     $a0, $a0, 2
    addu    $t0, $t0, $a0
    lw      $t0, 0x0($t0)
    addu    $t6, $zero, $zero
    beqz    $t0, L800E66F8
    addi    $v0, $zero, -0x1 /* handwritten instruction */
    lw      $t1, 0x1A4($t0)
    lbu     $t2, 0x13($t0)
    lbu     $t5, 0x12D($t0)
    sll     $t6, $t1, 5
    srl     $t6, $t6, 25
    sll     $t6, $t6, 6
    sll     $t3, $t1, 24
    srl     $t3, $t3, 30
    sll     $t4, $t1, 2
    srl     $t4, $t4, 30
    sll     $t3, $t3, 1
    sll     $t4, $t4, 3
    slti    $t5, $t5, 0x1
    sll     $t5, $t5, 5
    or      $v0, $t2, $t3
    or      $v0, $v0, $t4
    or      $v0, $v0, $t5
alabel L800E66F8
    jr      $ra
    or      $v0, $v0, $t6
endlabel func_800E6694

# hasm: cross-function control flow
# hasm: reserved register usage
glabel func_800E6700
    lui     $a1, %hi(vs_battle_actors)
    addiu   $a1, $a1, %lo(vs_battle_actors)
    sll     $v0, $a0, 2
    addu    $a1, $a1, $v0
    lw      $a1, 0x0($a1)
    lui     $a2, %hi(D_800F4538)
    addiu   $a2, $a2, %lo(D_800F4538)
    beqz    $a1, L800E66F8
    addu    $a2, $a2, $v0
    lbu     $a1, 0x9($a1)
    lw      $a2, 0x0($a2)
    addiu   $v1, $zero, 0x1
    sllv    $v1, $v1, $a1
    lui     $at, (0xA41800 >> 16)
    ori     $at, $at, (0xA41800 & 0xFFFF)
    and     $v1, $v1, $at
    beqz    $v1, L800E66F8
    lbu     $v0, 0xA($a2)
    lbu     $v1, 0xB($a2)
    andi    $v0, $v0, 0x1F
    andi    $v1, $v1, 0xB
    or      $v0, $v0, $v1
    beqz    $v0, .L800E6768
    addu    $t0, $zero, $zero
    jr      $ra
endlabel func_800E6700

# hasm: cross-function control flow
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800E6764
    addiu   $t0, $zero, 0x1
.L800E6768:
    lui     $a1, %hi(D_800F5878)
    addiu   $a1, $a1, %lo(D_800F5878)
    sll     $a0, $a0, 2
    addu    $a1, $a1, $a0
    lw      $a0, 0x0($a1)
    lui     $t7, (0x800F0000 >> 16)
    bnez    $a0, .L800E6798
    addu    $t8, $ra, $zero
    jr      $ra
endlabel func_800E6764

# hasm: trapping arithmetic
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800E678C
    addu    $t0, $zero, $zero
    addu    $t8, $ra, $zero
    lui     $t7, (0x800F58BC >> 16)
.L800E6798:
    ori     $t7, $t7, (0x800F58BC & 0xFFFF)
    addu    $t9, $a0, $zero
    lw      $t7, 0x0($t7)
    lw      $a1, 0x170($a0)
    sb      $t0, 0x1A($a0)
    lw      $t2, 0x0($t7)
    andi    $t0, $a1, 0xFF
    srl     $a1, $a1, 16
    andi    $t1, $a1, 0xFF
    sll     $a0, $t2, 8
    srl     $a0, $a0, 24
    andi    $a1, $t2, 0xFF
    srl     $a2, $t2, 24
    sll     $a3, $t2, 16
    srl     $a3, $a3, 24
    slt     $t3, $t0, $a0
    slt     $t4, $a1, $t0
    or      $t4, $t4, $t3
    slt     $t3, $t1, $a2
    or      $t4, $t4, $t3
    slt     $t6, $a3, $t1
    or      $t4, $t4, $t6
    bnez    $t4, .L800E6804
    lbu     $t9, 0x19B($t9)
    addu    $a0, $t0, $zero
    jal     func_800E4C28
    addu    $a1, $t1, $zero
.L800E6804:
    beqz    $t9, .L800E6820
    lbu     $a0, 0xE($t7)
    addiu   $a1, $zero, 0x1
    sllv    $a1, $a1, $a0
    neg     $a1, $a1 /* handwritten instruction */
    and     $a0, $a0, $a1
    sb      $a0, 0xE($t7)
.L800E6820:
    jr      $t8
    addu    $ra, $t8, $zero
endlabel func_800E678C
