.include "macro.inc"

.set noat
.set noreorder

.section .rodata, "a"

dlabel D_80069C0C
    .byte 0x03, 0x02, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03
    .byte 0xB4, 0x5A, 0x0F, 0x00
enddlabel D_80069C0C

.section .text, "ax"

# hasm: cross-function control flow
glabel func_800E685C
    lui     $a3, %hi(D_800F5878)
    addiu   $a3, $a3, %lo(D_800F5878)
    sll     $a0, $a0, 2
    addu    $a3, $a3, $a0
    lw      $a3, 0x0($a3)
    slt     $v0, $a1, $a2
    bnez    $v0, .L800E6880
    addu    $v1, $a2, $zero
    addu    $v1, $a1, $zero
.L800E6880:
    sll     $a2, $a2, 8
    beqz    $a3, .L800E6918
    or      $a0, $a2, $a1
    sb      $v1, 0xB3($a3)
    jr      $ra
    sh      $a0, 0x226($a3)
endlabel func_800E685C

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E6898
    bgez    $zero, .L800E68A4
    addi    $a1, $zero, 0x1 /* handwritten instruction */
endlabel func_800E6898

# hasm: trapping arithmetic
# hasm: cross-function control flow
# hasm: temp register usage
glabel func_800E68A0
    addi    $a1, $zero, -0x1 /* handwritten instruction */
.L800E68A4:
    lui     $t2, %hi(D_800F58D0)
    addiu   $t2, $t2, %lo(D_800F58D0)
    lw      $a3, 0x5C($a0)
    lui     $a2, %hi(D_800F58B8)
    lw      $a2, %lo(D_800F58B8)($a2)
    andi    $t0, $a3, 0xFF
    sll     $t1, $a3, 8
    beqz    $a2, .L800E6918
    srl     $t1, $t1, 18
    lw      $t2, 0x0($t2)
    sll     $t0, $t0, 1
    addu    $t0, $t0, $t1
    addu    $t0, $t0, $t2
    lhu     $t3, 0x0($t0)
    sll     $a1, $a1, 10
    add     $t3, $t3, $a1 /* handwritten instruction */
    jr      $ra
    sh      $t3, 0x0($t0)
endlabel func_800E68A0

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E68EC
    lui     $a2, %hi(D_800F58B8)
    lw      $a2, %lo(D_800F58B8)($a2)
    sll     $a0, $a0, 1
    beqz    $a2, .L800E6918
    sll     $a1, $a1, 6
    add     $a1, $a0, $a1 /* handwritten instruction */
    add     $a1, $a2, $a1 /* handwritten instruction */
    lhu     $a0, 0x0($a1)
    nop
    ori     $a0, $a0, 0x400
    sh      $a0, 0x0($a1)
.L800E6918:
    jr      $ra
    addu    $a1, $a2, $zero
    addiu   $sp, $sp, -0x18
    sw      $ra, 0x10($sp)
    jal     func_8008B764
    addu    $a2, $zero, $zero
    lw      $a0, 0x0($v0)
    addi    $a1, $zero, 0x3 /* handwritten instruction */
    sll     $a0, $a0, 3
    srl     $a0, $a0, 30
    lw      $ra, 0x10($sp)
    bne     $a0, $a1, .L800E6950
    addi    $v0, $zero, 0x1 /* handwritten instruction */
    addu    $v0, $zero, $zero
.L800E6950:
    jr      $ra
    addiu   $sp, $sp, 0x18
alabel L800E6958
    addiu   $sp, $sp, -0x8
    sw      $ra, 0x4($sp)
    jal     func_800E6974
    sw      $s0, 0x0($sp)
    lw      $ra, 0x4($sp)
    bgez    $zero, .L800E6A64
    lw      $s0, 0x0($sp)
endlabel func_800E68EC

# hasm: trapping arithmetic
# hasm: unconditional b branch
glabel func_800E6974
    addiu   $sp, $sp, -0x8
    sw      $ra, 0x4($sp)
    sll     $t1, $a1, 8
    sll     $t2, $s0, 16
    or      $t1, $t1, $a2
    or      $t2, $t1, $t2
    sw      $t2, 0x0($sp)
    slt     $t0, $a1, $a2
    beqz    $t0, .L800E6A50
    addu    $a3, $a1, $a2
    sra     $a3, $a3, 1
    sll     $a3, $a3, 2
    sll     $t1, $a1, 2
    addu    $t2, $a0, $t1
    addu    $t3, $a0, $a3
    lw      $t4, 0x0($t2)
    lw      $t5, 0x0($t3)
    sw      $t4, 0x0($t3)
    sw      $t5, 0x0($t2)
    addu    $s0, $a1, $zero
    addi    $t0, $a1, 0x1 /* handwritten instruction */
.L800E69C8:
    sll     $t1, $t0, 2
    addu    $t1, $t1, $a0
    lw      $t3, 0x0($t1)
    lw      $t4, 0x0($t2)
    lw      $t5, 0x0($t3)
    lw      $t6, 0x0($t4)
    nop
    slt     $t7, $t6, $t5
    beqz    $t7, .L800E6A08
    nop
    addi    $s0, $s0, 0x1 /* handwritten instruction */
    sll     $t7, $s0, 2
    addu    $t7, $a0, $t7
    lw      $t8, 0x0($t7)
    sw      $t3, 0x0($t7)
    sw      $t8, 0x0($t1)
.L800E6A08:
    addi    $t0, $t0, 0x1 /* handwritten instruction */
    slt     $t7, $a2, $t0
    bnez    $t7, .L800E6A1C
    nop
    bgez    $zero, .L800E69C8
.L800E6A1C:
    sll     $v0, $s0, 2
    addu    $v0, $v0, $a0
    lw      $t7, 0x0($v0)
    lw      $t8, 0x0($t2)
    sw      $t7, 0x0($t2)
    sw      $t8, 0x0($v0)
    jal     func_800E6974
    addi    $a2, $s0, -0x1 /* handwritten instruction */
    lw      $a2, 0x0($sp)
    nop
    andi    $a2, $a2, 0xFF
    jal     func_800E6974
    addi    $a1, $s0, 0x1 /* handwritten instruction */
.L800E6A50:
    lw      $t0, 0x0($sp)
    lw      $ra, 0x4($sp)
    andi    $a2, $t0, 0xFF
    srl     $a1, $t0, 8
    srl     $s0, $t0, 16
.L800E6A64:
    jr      $ra
    addiu   $sp, $sp, 0x8
endlabel func_800E6974

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: reserved register usage
glabel func_800E6A6C
    addiu   $sp, $sp, -0x38
    sw      $ra, 0x30($sp)
    sw      $s0, 0x10($sp)
    sw      $s7, 0x2C($sp)
    sw      $s6, 0x28($sp)
    sw      $s5, 0x24($sp)
    sw      $s4, 0x20($sp)
    sw      $s3, 0x1C($sp)
    sw      $s2, 0x18($sp)
    sw      $s1, 0x14($sp)
    addu    $s0, $a0, $zero
    addu    $s2, $a1, $zero
    sub     $s3, $a2, $s0 /* handwritten instruction */
    sub     $s5, $a3, $s2 /* handwritten instruction */
    sra     $s3, $s3, 4
    sra     $s5, $s5, 4
    addu    $s1, $zero, $zero
    addu    $s6, $zero, $zero
.L800E6AB4:
    add     $a0, $s0, $s3 /* handwritten instruction */
    add     $a1, $s2, $s5 /* handwritten instruction */
    addu    $s0, $a0, $zero
    jal     func_800E4318
    addu    $s2, $a1, $zero
    sll     $v0, $v0, 17
    sra     $v0, $v0, 17
    slt     $at, $s1, $v0
    bnez    $at, .L800E6AE0
    nop
    addu    $s1, $v0, $zero
.L800E6AE0:
    addi    $s6, $s6, 0x1 /* handwritten instruction */
    slti    $a2, $s6, 0x10
    beqz    $a2, .L800E6AF8
    addu    $v0, $s1, $zero
    bgez    $zero, .L800E6AB4
    nop
.L800E6AF8:
    lw      $ra, 0x30($sp)
    lw      $s0, 0x10($sp)
    lw      $s7, 0x2C($sp)
    lw      $s6, 0x28($sp)
    lw      $s5, 0x24($sp)
    lw      $s4, 0x20($sp)
    lw      $s3, 0x1C($sp)
    lw      $s2, 0x18($sp)
    lw      $s1, 0x14($sp)
    jr      $ra
    addiu   $sp, $sp, 0x38
endlabel func_800E6A6C

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E6B24
    sll     $a0, $a0, 2
    lui     $a1, %hi(D_800F5878)
    addiu   $a1, $a1, %lo(D_800F5878)
    addu    $a0, $a0, $a1
    lw      $a0, 0x0($a0)
    nop
    beqz    $a0, L800E66F8
    addu    $v0, $a0, $zero
    bgez    $zero, L800E66F8
    sb      $zero, 0x1A($a0)
endlabel func_800E6B24

# hasm: cross-function control flow
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_800E6B4C
    addiu   $sp, $sp, -0x30
    sw      $s0, 0x10($sp)
    sw      $ra, 0x18($sp)
    addiu   $a1, $zero, 0x7
    ori     $at, $zero, 0x8000
    addu    $a0, $zero, $at
    jal     vs_main_allocHeapR
    addu    $a2, $zero, $zero
    beqz    $v0, L800DB89C
    addu    $s0, $v0, $zero
    sw      $sp, 0x0($s0)
    ori     $at, $zero, 0x8000
    addu    $sp, $v0, $at
    jal     func_800E6098
    nop
    lw      $sp, 0x0($s0)
    lui     $ra, %hi(L800DB89C)
    addiu   $ra, $ra, %lo(L800DB89C)
    addu    $a0, $s0, $zero
    j       vs_main_freeHeapR
    addiu   $a1, $zero, 0x7
endlabel func_800E6B4C

# hasm: trapping arithmetic
# hasm: unconditional b branch
glabel func_800E6BA0
    addiu   $sp, $sp, -0x40
    sw      $ra, 0x20($sp)
    jal     func_8008D2C0
    addu    $a0, $sp, $zero
    addu    $t3, $zero, $zero
    addu    $t4, $v0, $zero
    addu    $a3, $sp, $zero
.L800E6BBC:
    lw      $a0, 0x0($a3)
    beqz    $t4, .L800E6C24
    addiu   $v0, $zero, 0x1
    lh      $a2, 0x4($a3)
    sra     $a1, $a0, 16
    addi    $a1, $a1, 0x20 /* handwritten instruction */
    andi    $a0, $a0, 0xFFFF
    sub     $a0, $a0, $s2 /* handwritten instruction */
    bgez    $a0, .L800E6BE8
    sub     $a1, $a1, $s3 /* handwritten instruction */
    neg     $a0, $a0 /* handwritten instruction */
.L800E6BE8:
    bgez    $a1, .L800E6BF4
    sub     $a2, $a2, $s4 /* handwritten instruction */
    neg     $a1, $a1 /* handwritten instruction */
.L800E6BF4:
    bgez    $a2, .L800E6C00
    slti    $t0, $a0, 0x40
    neg     $a2, $a2 /* handwritten instruction */
.L800E6C00:
    slti    $t1, $a1, 0x20
    slti    $t2, $a2, 0x40
    and     $t0, $t0, $t1
    and     $t0, $t0, $t2
    bnez    $t0, .L800E6C24
    addu    $v0, $zero, $zero
    addiu   $a3, $a3, 0x8
    bgez    $zero, .L800E6BBC
    addiu   $t4, $t4, -0x1
.L800E6C24:
    lw      $ra, 0x20($sp)
    addiu   $sp, $sp, 0x40
    jr      $ra
    nop
endlabel func_800E6BA0

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E6C34
    addiu   $sp, $sp, -0x40
    sw      $s0, 0x18($sp)
    sw      $s1, 0x1C($sp)
    sw      $s2, 0x20($sp)
    sw      $s3, 0x24($sp)
    sw      $s4, 0x28($sp)
    sw      $s5, 0x2C($sp)
    sw      $s6, 0x30($sp)
    sw      $s7, 0x34($sp)
    sw      $ra, 0x38($sp)
    lw      $t0, 0x0($a0)
    addu    $s0, $a2, $zero
    addu    $s1, $a3, $zero
    lh      $t2, 0x4($a0)
    sra     $t1, $t0, 16
    sll     $t0, $t0, 16
    sra     $t0, $t0, 16
    lw      $t3, 0x0($a1)
    addu    $s2, $t0, $zero
    addu    $s3, $t1, $zero
    addu    $s4, $t2, $zero
    lh      $t5, 0x4($a1)
    sra     $t4, $t3, 16
    sll     $t3, $t3, 16
    sra     $t3, $t3, 16
    sub     $s5, $t3, $t0 /* handwritten instruction */
    sub     $s6, $t4, $t1 /* handwritten instruction */
    sub     $s7, $t5, $t2 /* handwritten instruction */
    mtc2    $s2, $8 /* handwritten instruction */
    mtc2    $s4, $10 /* handwritten instruction */
    sra     $s5, $s5, 5
    sra     $s6, $s6, 5
    sra     $s7, $s7, 5
    addu    $t0, $zero, $zero
.L800E6CBC:
    add     $s2, $s2, $s5 /* handwritten instruction */
    add     $s3, $s3, $s6 /* handwritten instruction */
    add     $s4, $s4, $s7 /* handwritten instruction */
    addu    $t1, $zero, $zero
.L800E6CCC:
    lui     $v0, %hi(vs_battle_actors)
    addiu   $v0, $v0, %lo(vs_battle_actors)
    addu    $v0, $v0, $t1
    lw      $v0, 0x0($v0)
    lui     $t2, %hi(D_800F45E0)
    addiu   $t2, $t2, %lo(D_800F45E0)
    beqz    $v0, .L800E6E08
    nop
    lbu     $v0, 0x1C($v0)
    ori     $t4, $zero, 0xFFEA
    and     $v0, $v0, $t4
    bnez    $v0, .L800E6E08
    srl     $v0, $t1, 2
    beq     $v0, $s1, .L800E6E08
    lui     $t3, %hi(D_800F4538)
    addiu   $t3, $t3, %lo(D_800F4538)
    addu    $t4, $t2, $t1
    lw      $t4, 0x0($t4)
    addiu   $v0, $zero, 0x3F
    beqz    $t4, .L800E6D3C
    nop
    lbu     $a0, 0x12($t4)
    lbu     $a1, 0x1A($t4)
    beqz    $a0, .L800E6E08
    addiu   $v1, $zero, 0x80
    bnez    $a1, .L800E6E08
    nop
    bgez    $zero, .L800E6D80
.L800E6D3C:
    addu    $a0, $t3, $t1
    lw      $t4, 0x0($a0)
    nop
    beqz    $t4, .L800E6E08
    nop
    lbu     $a0, 0xB($t4)
    addiu   $a1, $zero, 0x1
    lhu     $v0, 0x63C($t4)
    andi    $a0, $a0, 0xF
    beq     $a0, $a1, .L800E6E08
    addiu   $a2, $zero, 0x2
    beq     $a0, $a2, .L800E6E08
    lbu     $a0, 0x5AF($t4)
    addiu   $a2, $zero, 0x1
    andi    $a0, $a0, 0x1
    beq     $a0, $a2, .L800E6E08
    lhu     $v1, 0x63E($t4)
.L800E6D80:
    lw      $a0, 0x1C($t4)
    sra     $v1, $v1, 1
    lhu     $a2, 0x20($t4)
    sra     $a1, $a0, 16
    sub     $a1, $a1, $v1 /* handwritten instruction */
    sll     $a0, $a0, 16
    mfc2    $t4, $8 /* handwritten instruction */
    sra     $a0, $a0, 16
    sub     $t4, $a0, $t4 /* handwritten instruction */
    mult    $t4, $s5
    sub     $t6, $a0, $s2 /* handwritten instruction */
    bgez    $t6, .L800E6DB8
    sub     $t7, $a1, $s3 /* handwritten instruction */
    neg     $t6, $t6 /* handwritten instruction */
.L800E6DB8:
    bgez    $t7, .L800E6DC4
    sub     $t8, $a2, $s4 /* handwritten instruction */
    neg     $t7, $t7 /* handwritten instruction */
.L800E6DC4:
    bgez    $t8, .L800E6DD0
    mflo    $t4
    neg     $t8, $t8 /* handwritten instruction */
.L800E6DD0:
    mfc2    $t5, $10 /* handwritten instruction */
    slt     $t6, $t6, $v0
    sub     $t5, $a2, $t5 /* handwritten instruction */
    mult    $s7, $t5
    slt     $t7, $t7, $v1
    slt     $t8, $t8, $v0
    and     $t6, $t6, $t7
    mflo    $t5
    and     $t6, $t6, $t8
    add     $t4, $t4, $t5 /* handwritten instruction */
    bltz    $t4, .L800E6E08
    srl     $v0, $t1, 2
    bnez    $t6, .L800E6E18
    addi    $v0, $v0, 0x1 /* handwritten instruction */
.L800E6E08:
    addiu   $t1, $t1, 0x4
    slti    $v1, $t1, 0x40
    bnez    $v1, .L800E6CCC
    addu    $v0, $zero, $zero
.L800E6E18:
    bnez    $v0, .L800E6E60
    sw      $t0, 0x3C($sp)
    jal     func_800E6BA0
    nop
    beqz    $v0, .L800E6E60
    addu    $a0, $s2, $zero
    jal     func_8008DC7C
    addu    $a1, $s4, $zero
    lw      $t0, 0x3C($sp)
    sll     $v0, $v0, 17
    sra     $v0, $v0, 17
    slt     $v0, $s3, $v0
    beqz    $v0, .L800E6E60
    addi    $t0, $t0, 0x1 /* handwritten instruction */
    slti    $v1, $t0, 0x20
    bnez    $v1, .L800E6CBC
    addu    $v0, $zero, $zero
    bgez    $zero, .L800E6E84
.L800E6E60:
    andi    $s2, $s2, 0xFFFF
    sll     $s3, $s3, 16
    or      $s2, $s2, $s3
    sll     $v0, $v0, 16
    andi    $s4, $s4, 0xFFFF
    or      $s4, $s4, $v0
    sw      $s2, 0x0($s0)
    sw      $s4, 0x4($s0)
    addu    $v0, $s0, $zero
.L800E6E84:
    lw      $ra, 0x38($sp)
    lw      $s0, 0x18($sp)
    lw      $s1, 0x1C($sp)
    lw      $s2, 0x20($sp)
    lw      $s3, 0x24($sp)
    lw      $s4, 0x28($sp)
    lw      $s5, 0x2C($sp)
    lw      $s6, 0x30($sp)
    lw      $s7, 0x34($sp)
    addiu   $sp, $sp, 0x40
endlabel func_800E6C34

# hasm: cross-function control flow
glabel func_800E6EAC
    jr      $ra
endlabel func_800E6EAC

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E6EB0
    lui     $t0, %hi(vs_battle_actors)
    addiu   $t0, $t0, %lo(vs_battle_actors)
    sll     $a0, $a0, 2
    addu    $t0, $t0, $a0
    lw      $t0, 0x0($t0)
    lui     $t1, %hi(D_800F5878)
    addiu   $t1, $t1, %lo(D_800F5878)
    addu    $t1, $t1, $a0
    lw      $t1, 0x0($t1)
    sltiu   $v0, $t0, 0x1
    sltiu   $v1, $t1, 0x1
    and     $v0, $v0, $v1
    bnez    $v0, func_800E6EAC
    addiu   $v1, $zero, 0x1
    lbu     $v0, 0x9($t0)
    lw      $a1, 0x58($t1)
    sllv    $v1, $v1, $v0
    lw      $a2, 0x170($t1)
    andi    $v1, $v1, 0x4800
    beqz    $v1, func_800E6EAC
    andi    $a2, $a2, 0xFF00
    lbu     $a1, 0xC($a1)
    beqz    $a2, func_800E6EAC
    andi    $a1, $a1, 0xF
    bnez    $a1, func_800E6EAC
    srl     $a0, $a2, 8
    bgez    $zero, func_800E4BD8
endlabel func_800E6EB0

# hasm: custom register abi
glabel func_800E6F1C
    lui     $t0, (0x800F5878 >> 16)
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x10($sp)
    lui     $s0, %hi(vs_battle_actors)
    lw      $s0, %lo(vs_battle_actors)($s0)
    sw      $ra, 0x18($sp)
.L800E6F34:
    lw      $v0, 0x4($s0)
    ori     $t0, $t0, (0x800F5878 & 0xFFFF)
    sll     $v0, $v0, 2
    addu    $t0, $t0, $v0
    lw      $t0, 0x0($t0)
    jal     func_800E7454
    addu    $a0, $s0, $zero
    lw      $s0, 0x0($s0)
    lui     $t0, (0x800F5878 >> 16)
    bnez    $s0, .L800E6F34
    lui     $at, %hi(D_800F58D0)
    sw      $zero, %lo(D_800F58D0)($at)
    lui     $at, %hi(D_800F58B8)
    sw      $zero, %lo(D_800F58B8)($at)
    lui     $at, %hi(D_800F58C0)
    sw      $zero, %lo(D_800F58C0)($at)
    lui     $a0, %hi(D_800F58BC)
    lw      $a0, %lo(D_800F58BC)($a0)
    jal     vs_main_freeHeap
    addiu   $a1, $zero, 0x7
    lw      $s0, 0x10($sp)
    lw      $ra, 0x18($sp)
    lui     $at, %hi(D_800F58BC)
    sw      $zero, %lo(D_800F58BC)($at)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800E6F1C

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800E6F9C
    addiu   $sp, $sp, -0x30
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    sw      $s2, 0x1C($sp)
    sw      $s5, 0x28($sp)
    sw      $s3, 0x20($sp)
    sw      $ra, 0x18($sp)
    jal     func_8008B6FC
    sw      $s4, 0x24($sp)
    lui     $at, %hi(D_800F58C0)
    sw      $v0, %lo(D_800F58C0)($at)
    addiu   $v0, $v0, 0x400
    lui     $at, %hi(D_800F58D8)
    sw      $v0, %lo(D_800F58D8)($at)
    addiu   $v0, $v0, 0x40
    lui     $at, %hi(D_800F58C8)
    sw      $v0, %lo(D_800F58C8)($at)
    addiu   $v0, $v0, 0x10
    lui     $at, %hi(D_800F5908)
    sw      $v0, %lo(D_800F5908)($at)
    addiu   $v0, $v0, 0x4
    lui     $at, %hi(D_800F5910)
    sw      $v0, %lo(D_800F5910)($at)
    addiu   $v0, $v0, 0x44
    lui     $at, %hi(D_800F58CC)
    sw      $v0, %lo(D_800F58CC)($at)
    addu    $a2, $zero, $zero
    addiu   $a0, $zero, 0x1038
    jal     vs_main_allocHeap
    addiu   $a1, $zero, 0x7
    lui     $at, %hi(D_800F58BC)
    sw      $v0, %lo(D_800F58BC)($at)
    addu    $s0, $v0, $zero
    addu    $a0, $v0, $zero
    jal     func_800E4288
    addiu   $a1, $zero, 0x1038
    addiu   $v0, $s0, 0x38
    lui     $at, %hi(D_800F58B8)
    sw      $v0, %lo(D_800F58B8)($at)
    addu    $s3, $v0, $zero
    addiu   $v0, $s0, 0x838
    lui     $at, %hi(D_800F58D0)
    sw      $v0, %lo(D_800F58D0)($at)
    addu    $s4, $v0, $zero
    jal     _getCollisionMapDimensions
    addu    $a0, $zero, $zero
    andi    $a0, $v0, 0xFFFF
    srl     $a0, $a0, 4
    srl     $v1, $v0, 12
    or      $a0, $a0, $v1
    jal     func_8008E4AC
    sh      $a0, 0x4($s0)
    sh      $a0, 0x0($s0)
    sll     $v0, $v0, 6
    neg     $v0, $v0 /* handwritten instruction */
    sw      $v0, 0x14($s0)
    addu    $s1, $zero, $zero
.L800E7080:
    addu    $a2, $zero, $zero
    andi    $a0, $s1, 0x1F
    jal     func_8008B764
    srl     $a1, $s1, 5
    beqz    $v0, .L800E7164
    andi    $a0, $s1, 0x1F
    lw      $t0, 0x0($v0)
    srl     $a1, $s1, 5
    srl     $t1, $t0, 23
    andi    $t1, $t1, 0xF
    srl     $t2, $t0, 27
    andi    $t2, $t2, 0x1
    srl     $t3, $t0, 28
    andi    $t3, $t3, 0x1
    srl     $t4, $t0, 17
    andi    $t4, $t4, 0x1
    srl     $t5, $t0, 31
    andi    $t5, $t5, 0x1
    srl     $t6, $t0, 30
    andi    $t6, $t6, 0x1
    srl     $t7, $t0, 29
    andi    $t7, $t7, 0x1
    sll     $t2, $t2, 4
    sll     $t4, $t4, 5
    sll     $t3, $t3, 6
    sll     $t5, $t5, 11
    sll     $t6, $t6, 12
    sll     $t7, $t7, 13
    or      $v1, $t1, $t2
    or      $v1, $v1, $t3
    or      $v1, $v1, $t5
    or      $v1, $v1, $t6
    or      $v1, $v1, $t7
    jal     func_800E71DC
    or      $s2, $v1, $t4
    addu    $t0, $s4, $zero
    sra     $v0, $v0, 6
    andi    $v0, $v0, 0x3FF
    sll     $a0, $s1, 1
    addu    $t0, $t0, $a0
    sh      $v0, 0x0($t0)
    addu    $a2, $zero, $zero
    andi    $a0, $s1, 0x1F
    jal     func_8008D438
    srl     $a1, $s1, 5
    beqz    $v0, .L800E7168
    addiu   $a3, $zero, 0x1
    lhu     $a0, 0x6($v0)
    lhu     $a1, 0x8($v0)
    slti    $v0, $a0, 0x10
    beqz    $v0, .L800E7168
    slti    $a0, $a1, 0x2
    beqz    $a0, .L800E7168
    sllv    $a3, $a3, $a1
    sll     $a3, $a3, 8
    bgez    $zero, .L800E7168
    or      $s2, $s2, $a3
.L800E7164:
    ori     $s2, $s2, 0x8000
.L800E7168:
    sh      $s2, 0x0($s3)
    addi    $s1, $s1, 0x1 /* handwritten instruction */
    slti    $v1, $s1, 0x400
    bnez    $v1, .L800E7080
    addiu   $s3, $s3, 0x2
    jal     func_800E6B4C
    nop
    lui     $a1, %hi(D_800F58C0)
    lw      $a1, %lo(D_800F58C0)($a1)
    lui     $v1, %hi(D_800F5908)
    lw      $v1, %lo(D_800F5908)($v1)
    bnez    $a1, .L800E71A4
    addiu   $v0, $zero, 0x96
    sh      $v0, 0x8($s0)
    bgez    $zero, .L800E71D0
.L800E71A4:
    lw      $v1, 0x0($v1)
    lw      $a1, 0x494($a1)
    srl     $v0, $v1, 29
    sw      $a1, 0x0($s0)
    sb      $v0, 0xD($s0)
    sll     $v0, $v1, 3
    srl     $v0, $v0, 24
    sh      $v0, 0x8($s0)
    sll     $v0, $v1, 11
    srl     $v0, $v0, 31
    sb      $v0, 0xA($s0)
.L800E71D0:
    lui     $ra, (0x800DB888 >> 16)
    bgez    $zero, func_800DC638
    ori     $ra, $ra, (0x800DB888 & 0xFFFF)
endlabel func_800E6F9C

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E71DC
    addiu   $sp, $sp, -0x30
    sw      $s3, 0x20($sp)
    sw      $s5, 0x28($sp)
    sw      $s4, 0x24($sp)
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    sw      $s2, 0x1C($sp)
    sll     $s0, $a0, 7
    sll     $s1, $a1, 7
    addiu   $a0, $s0, 0x40
    jal     func_8008DC7C
    addiu   $a1, $s1, 0x40
    addu    $s5, $v0, $zero
    addu    $s2, $zero, $zero
    addu    $s4, $zero, $zero
    addu    $s3, $zero, $zero
.L800E7220:
    srl     $a0, $s2, 2
    sll     $a0, $a0, 5
    andi    $a1, $s2, 0x3
    sll     $a1, $a1, 5
    add     $a0, $s0, $a0 /* handwritten instruction */
    jal     func_8008DC7C
    add     $a1, $s1, $a1 /* handwritten instruction */
    addiu   $v1, $zero, 0xA
    bne     $s2, $v1, .L800E724C
    addiu   $t0, $zero, 0x1
    addu    $s4, $v0, $zero
.L800E724C:
    bgez    $v0, .L800E7258
    sllv    $t0, $t0, $s2
    or      $s3, $s3, $t0
.L800E7258:
    sll     $t0, $v0, 17
    sra     $t0, $t0, 17
    sll     $v1, $s5, 17
    sra     $v1, $v1, 17
    slt     $v1, $v1, $t0
    beqz    $v1, .L800E7278
    addiu   $s2, $s2, 0x1
    addu    $s5, $v0, $zero
.L800E7278:
    slti    $v0, $s2, 0x10
    bnez    $v0, .L800E7220
    sltiu   $v0, $s3, 0x1
    bnez    $v0, .L800E72C8
    neg     $v0, $s3 /* handwritten instruction */
    addi    $v0, $v0, -0x1 /* handwritten instruction */
    addu    $v1, $zero, $zero
    addiu   $t0, $zero, 0x3
    addiu   $t1, $zero, 0x7
.L800E729C:
    beq     $v1, $t0, .L800E72B4
    ori     $t2, $zero, 0x33
    beq     $v1, $t1, .L800E72B4
    sllv    $t2, $t2, $v1
    and     $t3, $v0, $t2
    beq     $t3, $t2, .L800E72C8
.L800E72B4:
    addiu   $v1, $v1, 0x1
    slti    $t2, $v1, 0xA
    bnez    $t2, .L800E729C
    nop
    addu    $s5, $s4, $zero
.L800E72C8:
    bgez    $zero, L800DB888
    addu    $v0, $s5, $zero
endlabel func_800E71DC

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E72D0
    addiu   $sp, $sp, -0x30
    sw      $s0, 0x10($sp)
    sw      $ra, 0x18($sp)
    lui     $s0, %hi(vs_battle_actors)
    lw      $s0, %lo(vs_battle_actors)($s0)
    lui     $t1, (0x800F5878 >> 16)
    ori     $t1, $t1, (0x800F5878 & 0xFFFF)
.L800E72EC:
    lw      $t2, 0x4($s0)
    lui     $v0, (0xC80FFF30 >> 16)
    sll     $t2, $t2, 2
    addu    $t1, $t1, $t2
    lw      $t1, 0x0($t1)
    ori     $v0, $v0, (0xC80FFF30 & 0xFFFF)
    lw      $t2, 0x1A4($t1)
    lh      $t4, 0x42($t1)
    and     $t2, $t2, $v0
    bltz    $t4, .L800E735C
    srl     $t3, $t4, 3
    andi    $t3, $t3, 0x3
    sll     $t3, $t3, 28
    or      $t2, $t2, $t3
    srl     $t3, $t4, 1
    andi    $t3, $t3, 0x3
    sll     $t3, $t3, 6
    or      $t2, $t2, $t3
    srl     $t3, $t4, 6
    andi    $t3, $t3, 0x7F
    sll     $t3, $t3, 20
    or      $t2, $t2, $t3
    sw      $t2, 0x1A4($t1)
    andi    $t3, $t4, 0x1
    beqz    $t3, .L800E735C
    addu    $a0, $t1, $zero
    jal     func_800DC210
    addiu   $a1, $zero, 0x1
.L800E735C:
    lw      $s0, 0x0($s0)
    lui     $t1, (0x800F5878 >> 16)
    bnez    $s0, .L800E72EC
    ori     $t1, $t1, (0x800F5878 & 0xFFFF)
    bgez    $zero, L800DB89C
endlabel func_800E72D0

# hasm: trapping arithmetic
# hasm: saved registers outside frame
glabel func_800E7370
    lui     $a3, (0x800F5878 >> 16)
    addiu   $sp, $sp, -0xC
    sw      $s0, 0x0($sp)
    sw      $s1, 0x4($sp)
    addu    $s0, $a0, $zero
    lui     $s1, %hi(vs_battle_actors)
    lw      $s1, %lo(vs_battle_actors)($s1)
    sw      $ra, 0x8($sp)
    beqz    $s1, .L800E7440
    ori     $a3, $a3, (0x800F5878 & 0xFFFF)
.L800E7398:
    lw      $t0, 0x4($s1)
    addiu   $v0, $zero, 0x2
    sll     $v1, $t0, 2
    addu    $a3, $a3, $v1
    lbu     $t3, 0x88($s0)
    lw      $a3, 0x0($a3)
    beq     $t3, $t0, .L800E73E8
    lbu     $v1, 0x2C($s0)
    lbu     $a2, 0x2C($a3)
    slti    $t2, $t0, 0x1
    slti    $a2, $a2, 0x3
    xori    $a2, $a2, 0x1
    or      $t2, $t2, $a2
    xori    $t2, $t2, 0x1
    lui     $t1, %hi(D_80069C0C)
    addiu   $t1, $t1, %lo(D_80069C0C)
    sll     $v1, $v1, 1
    addu    $v1, $v1, $t2
    addu    $v1, $v1, $t1
    lbu     $v0, 0x0($v1)
.L800E73E8:
    sll     $v1, $t0, 2
    addu    $v1, $v1, $s0
    lw      $a2, 0x1A4($v1)
    addi    $a1, $zero, -0xC1 /* handwritten instruction */
    sll     $v0, $v0, 6
    and     $a2, $a2, $a1
    or      $a2, $a2, $v0
    sll     $v0, $t3, 2
    addu    $v0, $v0, $a3
    lw      $t0, 0x1A4($v0)
    lui     $ra, %hi(D_800E7430)
    addiu   $ra, $ra, %lo(D_800E7430)
    sw      $a2, 0x1A4($v1)
    srl     $t0, $t0, 6
    andi    $t0, $t0, 0x3
    slti    $t0, $t0, 0x1
    bnez    $t0, func_800E7370
    addu    $a0, $a3, $zero
alabel D_800E7430
    lw      $s1, 0x0($s1)
    lui     $a3, (0x800F5878 >> 16)
    bnez    $s1, .L800E7398
    ori     $a3, $a3, (0x800F5878 & 0xFFFF)
.L800E7440:
    lw      $ra, 0x8($sp)
    lw      $s0, 0x0($sp)
    lw      $s1, 0x4($sp)
    jr      $ra
    addiu   $sp, $sp, 0xC
endlabel func_800E7370

# hasm: trapping arithmetic
# hasm: cross-function control flow
# hasm: saved registers outside frame
glabel func_800E7454
    addiu   $sp, $sp, -0x30
    sw      $s5, 0x28($sp)
    sw      $s0, 0x10($sp)
    sw      $s2, 0x1C($sp)
    sw      $s1, 0x14($sp)
    sw      $ra, 0x18($sp)
    lui     $a1, %hi(D_800F58B8)
    lw      $a1, %lo(D_800F58B8)($a1)
    addu    $a0, $s0, $zero
    beqz    $a1, L800DB890
    lbu     $a3, 0x1C($s0)
    lw      $s1, 0x4($s0)
    andi    $a3, $a3, 0x14
    beqz    $a3, .L800E74A8
    lui     $a1, %hi(D_800F590C)
    lw      $a1, %lo(D_800F590C)($a1)
    addiu   $v0, $zero, 0x1
    sllv    $v0, $v0, $s1
    subu    $a1, $a1, $v0
    lui     $at, %hi(D_800F590C)
    sw      $a1, %lo(D_800F590C)($at)
.L800E74A8:
    lui     $t0, %hi(vs_battle_actors)
    lw      $t0, %lo(vs_battle_actors)($t0)
    lui     $t6, (0x800F5878 >> 16)
    beqz    $t0, .L800E74F0
.L800E74B8:
    lw      $a3, 0x4($t0)
    ori     $t1, $t6, (0x800F5878 & 0xFFFF)
    sll     $a3, $a3, 2
    addu    $t1, $t1, $a3
    lw      $t1, 0x0($t1)
    nop
    lbu     $t2, 0x16($t1)
    nop
    bne     $t2, $s1, .L800E74E4
    addiu   $v0, $zero, 0x10
    sb      $v0, 0x16($t1)
.L800E74E4:
    lw      $t0, 0x0($t0)
    lui     $t6, (0x800F5878 >> 16)
    bnez    $t0, .L800E74B8
.L800E74F0:
    lui     $s5, %hi(D_800F58BC)
    lw      $s5, %lo(D_800F58BC)($s5)
    addiu   $v0, $zero, 0xC
.L800E74FC:
    addu    $t4, $s5, $v0
    lw      $t5, 0x28($t4)
    ori     $t6, $t6, (0x800F5878 & 0xFFFF)
    bne     $t5, $s0, .L800E7514
    lbu     $a3, 0x1C($s0)
    sw      $zero, 0x28($t4)
.L800E7514:
    addi    $v0, $v0, -0x4 /* handwritten instruction */
    bgez    $v0, .L800E74FC
    andi    $a3, $a3, 0x5
    beqz    $a3, L800DB890
    sll     $v0, $s1, 2
    addu    $v0, $v0, $t6
    lw      $s2, 0x0($v0)
    jal     func_800E5240
    addu    $a0, $s1, $zero
    jal     func_800E678C
    addu    $a0, $s2, $zero
    beqz    $s1, L800DB890
    lhu     $t1, 0x10($s5)
    addiu   $v0, $zero, 0x1
    sllv    $v0, $v0, $s1
    and     $v0, $v0, $t1
    beqz    $v0, .L800E7570
    lbu     $t0, 0xB($s0)
    subu    $t1, $t1, $v0
    lbu     $t2, 0x12($s5)
    sh      $t1, 0x10($s5)
    addi    $t2, $t2, -0x1 /* handwritten instruction */
    sb      $t2, 0x12($s5)
.L800E7570:
    andi    $t0, $t0, 0xFC
    beqz    $s2, .L800E75AC
    sb      $t0, 0xB($s0)
    jal     func_800D821C
    addu    $a0, $s2, $zero
    jal     func_800DBF00
    addu    $a0, $s2, $zero
    addiu   $a1, $zero, 0x7
    jal     vs_main_freeHeap
    addu    $a0, $s2, $zero
    lui     $a0, %hi(D_800F5878)
    addiu   $a0, $a0, %lo(D_800F5878)
    sll     $a1, $s1, 2
    addu    $a0, $a0, $a1
    sw      $zero, 0x0($a0)
.L800E75AC:
    lhu     $a0, 0x1A($s0)
    lui     $ra, (0x800DB890 >> 16)
    ori     $ra, $ra, (0x800DB890 & 0xFFFF)
    addiu   $a1, $zero, 0xAC
    beq     $a0, $a1, .L800E75D4
    addiu   $a1, $zero, 0xAD
    beq     $a0, $a1, .L800E75D4
    nop
.L800E75CC:
    jr      $ra
    addiu   $a1, $zero, 0xAC
.L800E75D4:
    lui     $a3, %hi(D_800F5920)
    addiu   $a3, $a3, %lo(D_800F5920)
    lw      $a0, 0x0($a3)
    addiu   $a1, $zero, 0x7
    j       vs_main_freeHeap
    sw      $zero, 0x0($a3)
endlabel func_800E7454

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E75EC
    lui     $a3, %hi(D_800F58BC)
    lw      $a3, %lo(D_800F58BC)($a3)
    nop
    beqz    $a3, .L800E75CC
    addu    $v0, $zero, $zero
    bgez    $zero, .L800E75CC
    lw      $v0, 0x14($a3)
endlabel func_800E75EC

# hasm: cross-function control flow
glabel func_800E7608
    lui     $a3, %hi(vs_battle_actors)
    lw      $a3, %lo(vs_battle_actors)($a3)
    lui     $a1, (0x800F5878 >> 16)
.L800E7614:
    lw      $v0, 0x4($a3)
    ori     $a1, $a1, (0x800F5878 & 0xFFFF)
    sll     $v0, $v0, 2
    addu    $v0, $v0, $a1
    lw      $v0, 0x0($v0)
    nop
    lbu     $v1, 0x16($v0)
    nop
    bne     $v1, $a0, .L800E7640
    addiu   $v1, $zero, 0x10
    sb      $v1, 0x16($v0)
.L800E7640:
    lw      $a3, 0x0($a3)
    lui     $a1, (0x800F5878 >> 16)
    bnez    $a3, .L800E7614
    ori     $a1, $a1, (0x800F5878 & 0xFFFF)
    sll     $v0, $a0, 2
    addu    $a0, $v0, $a1
    j       func_800D82CC
    lw      $a0, 0x0($a0)
endlabel func_800E7608

# hasm: cross-function control flow
glabel func_800E7660
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    addiu   $a0, $zero, 0x20
    jal     vs_main_allocHeap
    addiu   $a1, $zero, 0x7
    addu    $a0, $v0, $zero
    lui     $at, %hi(D_800F5920)
    sw      $v0, %lo(D_800F5920)($at)
    jal     func_800E4288
    addiu   $a1, $zero, 0x20
    addiu   $v1, $zero, 0x384
    j       L800DB89C
    sh      $v1, 0xC($v0)
endlabel func_800E7660
