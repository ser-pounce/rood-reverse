.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: unconditional b branch
glabel func_800E3DDC
    lbu     $a3, 0x1($a0)
    addiu   $sp, $sp, -0x10
    sw      $s0, 0x0($sp)
    sw      $s1, 0x4($sp)
    sw      $s2, 0x8($sp)
    sw      $ra, 0xC($sp)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    addu    $s2, $a2, $zero
    sb      $a3, 0x199($s0)
    lbu     $t0, 0x4($s0)
    andi    $t1, $a1, 0xFE0
    slti    $t1, $t1, 0x1
    srl     $t2, $a1, 16
    andi    $t2, $t2, 0x1
    or      $t1, $t1, $t2
    or      $t1, $t1, $t0
    beqz    $t1, .L800E3E5C
    lui     $v0, (0xFFFEFFFF >> 16)
    ori     $v0, $v0, (0xFFFEFFFF & 0xFFFF)
    and     $s1, $s1, $v0
    jal     func_800E45D4
    addiu   $a0, $zero, 0x2
    lbu     $a3, 0x89($s0)
    addi    $v1, $zero, -0x11 /* handwritten instruction */
    and     $s1, $s1, $v1
    sll     $v0, $v0, 4
    or      $s1, $s1, $v0
    addu    $a0, $s0, $zero
    addiu   $a1, $zero, 0x8
    jal     func_800E4180
    addiu   $a2, $zero, 0x1
.L800E3E5C:
    addi    $v0, $zero, -0xFE1 /* handwritten instruction */
    and     $v0, $s1, $v0
    bnez    $v0, .L800E3E74
    lui     $v1, (0xFFFDFFFF >> 16)
    ori     $v1, $v1, (0xFFFDFFFF & 0xFFFF)
    and     $s1, $s1, $v1
.L800E3E74:
    addu    $a1, $s2, $zero
    lw      $s2, 0x8($sp)
    jal     func_800E3D5C
    addu    $a0, $s0, $zero
    lw      $s0, 0x0($sp)
    lui     $v1, (0xFFC30FFF >> 16)
    ori     $v1, $v1, (0xFFC30FFF & 0xFFFF)
    and     $s1, $s1, $v1
    lw      $ra, 0xC($sp)
    sll     $v0, $v0, 18
    or      $v0, $s1, $v0
    lw      $s1, 0x4($sp)
    jr      $ra
    addiu   $sp, $sp, 0x10
alabel func_800E3EAC
    addiu   $sp, $sp, -0x1C
    sw      $s0, 0x0($sp)
    sw      $s1, 0x4($sp)
    sw      $s2, 0x8($sp)
    sw      $s3, 0xC($sp)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    addu    $s2, $a2, $zero
    addu    $s3, $a3, $zero
    sw      $s4, 0x10($sp)
    lw      $a1, 0x190($s0)
    sw      $ra, 0x14($sp)
    sw      $s5, 0x18($sp)
    jal     func_800E3DDC
    addu    $a2, $a3, $zero
    addu    $s4, $v0, $zero
    sll     $t1, $s4, 27
    bltz    $t1, .L800E3EFC
    addi    $t0, $zero, 0x1 /* handwritten instruction */
    addi    $t0, $zero, -0x1 /* handwritten instruction */
.L800E3EFC:
    sll     $t0, $t0, 1
    add     $t1, $s1, $t0 /* handwritten instruction */
    addu    $s1, $t0, $zero
    andi    $t1, $t1, 0x7
    bne     $t1, $s2, .L800E3F18
    addi    $v0, $zero, 0x4 /* handwritten instruction */
    addu    $v0, $t0, $zero
.L800E3F18:
    add     $s5, $s2, $v0 /* handwritten instruction */
    andi    $s5, $s5, 0x7
    addu    $a1, $s5, $zero
    jalr    $s3
    addu    $a0, $s0, $zero
    bnez    $v0, .L800E3F50
    srl     $a1, $s4, 1
    andi    $a1, $a1, 0x7
    add     $a1, $a1, $s1 /* handwritten instruction */
    addu    $a0, $s0, $zero
    andi    $s5, $a1, 0x7
    jalr    $s3
    addu    $a1, $s5, $zero
    beqz    $v0, .L800E3FCC
.L800E3F50:
    addi    $v1, $zero, -0xF /* handwritten instruction */
    and     $s4, $s4, $v1
    sll     $t0, $s5, 1
    or      $a1, $s4, $t0
    jal     func_800E3CDC
    addu    $a0, $s0, $zero
    lw      $t0, 0x34($s0)
    addu    $s4, $v0, $zero
    sll     $t1, $t0, 8
    srl     $t1, $t1, 24
    lw      $t2, 0x168($s0)
    andi    $t0, $t0, 0xFF
    sll     $t3, $t2, 8
    srl     $t3, $t3, 24
    andi    $t2, $t2, 0xFF
    beq     $t1, $t3, .L800E3F9C
    addu    $v0, $zero, $zero
    slt     $v0, $t1, $t3
    add     $v0, $v0, $t1 /* handwritten instruction */
.L800E3F9C:
    sll     $v0, $v0, 27
    beq     $t0, $t2, .L800E3FB0
    addu    $v1, $zero, $zero
    slt     $v1, $t0, $t2
    add     $v1, $v1, $t0 /* handwritten instruction */
.L800E3FB0:
    sll     $v1, $v1, 22
.L800E3FB4:
    sll     $s4, $s4, 10
    srl     $s4, $s4, 10
    or      $s4, $s4, $v0
    or      $s4, $s4, $v1
    ori     $s4, $s4, 0x1
    addiu   $v0, $zero, 0x1
.L800E3FCC:
    sw      $s4, 0x190($s0)
    lw      $s0, 0x0($sp)
    lw      $s1, 0x4($sp)
    lw      $s2, 0x8($sp)
    lw      $s3, 0xC($sp)
    lw      $s4, 0x10($sp)
    lw      $ra, 0x14($sp)
    lw      $s5, 0x18($sp)
    jr      $ra
    addiu   $sp, $sp, 0x1C
alabel func_800E3FF4
    addiu   $sp, $sp, -0x1C
    sw      $s0, 0x0($sp)
    sw      $s1, 0x4($sp)
    sw      $s2, 0x8($sp)
    sw      $s3, 0xC($sp)
    addu    $s1, $a1, $zero
    addu    $s0, $a0, $zero
    sw      $s4, 0x10($sp)
    lw      $a1, 0x190($s0)
    addu    $s2, $a2, $zero
    addu    $s3, $a3, $zero
    sw      $ra, 0x14($sp)
    sw      $s5, 0x18($sp)
    jal     func_800E3DDC
    addu    $a2, $a3, $zero
    addu    $s4, $v0, $zero
    sll     $t1, $s4, 27
    bltz    $t1, .L800E4044
    addi    $t0, $zero, 0x1 /* handwritten instruction */
    addi    $t0, $zero, -0x1 /* handwritten instruction */
.L800E4044:
    beq     $t0, $s2, .L800E4084
    addu    $s5, $s1, $zero
    addi    $a1, $s1, 0x4 /* handwritten instruction */
    addu    $s1, $t0, $zero
    andi    $s5, $a1, 0x7
    addu    $a1, $s5, $zero
    jalr    $s3
    addu    $a0, $s0, $zero
    bnez    $v0, .L800E4084
    sll     $s1, $s1, 1
    sub     $s5, $s5, $s1 /* handwritten instruction */
    andi    $s5, $s5, 0x7
.L800E4074:
    addu    $a1, $s5, $zero
    jalr    $s3
    addu    $a0, $s0, $zero
    beqz    $v0, .L800E3FCC
.L800E4084:
    addi    $v1, $zero, -0xF /* handwritten instruction */
    and     $s4, $s4, $v1
    addu    $a0, $s0, $zero
    sll     $a3, $s5, 1
    jal     func_800E3CDC
    or      $a1, $s4, $a3
    lw      $t0, 0x34($s0)
    addu    $s4, $v0, $zero
    lw      $t1, 0x168($s0)
    andi    $a0, $t0, 0xFF
    sll     $a1, $t0, 8
    srl     $a1, $a1, 24
    andi    $t0, $t1, 0xFF
    sll     $t1, $t1, 8
    srl     $t1, $t1, 24
    andi    $v1, $s4, 0x4
    bnez    $v1, .L800E40D8
    slt     $a3, $a0, $t0
    add     $a0, $a0, $a3 /* handwritten instruction */
    bgez    $zero, .L800E40E4
    addu    $a1, $zero, $zero
.L800E40D8:
    slt     $a3, $a1, $t1
    add     $a1, $a1, $a3 /* handwritten instruction */
    addu    $a0, $zero, $zero
.L800E40E4:
    sll     $v0, $a0, 22
    bgez    $zero, .L800E3FB4
    sll     $v1, $a1, 27
    addiu   $sp, $sp, -0x1C
    sw      $s0, 0x0($sp)
    sw      $s1, 0x4($sp)
    sw      $s2, 0x8($sp)
    sw      $s3, 0xC($sp)
    sw      $s4, 0x10($sp)
    sw      $ra, 0x14($sp)
    sw      $s5, 0x18($sp)
    addu    $s1, $a1, $zero
    lw      $a1, 0x190($a0)
    addu    $s3, $a2, $zero
    jal     func_800E3DDC
    addu    $s0, $a0, $zero
    addu    $s4, $v0, $zero
    sll     $t1, $s4, 27
    bltz    $t1, .L800E4138
    addi    $t0, $zero, 0x1 /* handwritten instruction */
    addi    $t0, $zero, -0x1 /* handwritten instruction */
.L800E4138:
    sll     $t0, $t0, 1
    sub     $s5, $s1, $t0 /* handwritten instruction */
    andi    $s5, $s5, 0x7
    addu    $a1, $s5, $zero
    jalr    $s3
    addu    $a0, $s0, $zero
    bnez    $v0, .L800E4084
    addi    $a1, $s5, 0x4 /* handwritten instruction */
    andi    $a1, $a1, 0x7
    addu    $s5, $a1, $zero
    jalr    $s3
    addu    $a0, $s0, $zero
    bnez    $v0, .L800E4084
    addi    $a1, $s1, 0x4 /* handwritten instruction */
    andi    $a1, $a1, 0x7
    addu    $s5, $a1, $zero
    bgez    $zero, .L800E4074
    addu    $a0, $s0, $zero
endlabel func_800E3DDC

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800E4180
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x18($sp)
    sll     $a3, $a3, 1
    addu    $a3, $a3, $a0
    lhu     $v1, 0x474($a3)
    addu    $t3, $a0, $zero
    addu    $t4, $a1, $zero
    addu    $t5, $a2, $zero
    srl     $t7, $v1, 8
    andi    $t7, $t7, 0xFF
    andi    $t6, $v1, 0xFF
    bnez    $t7, .L800E41E4
    addiu   $v0, $zero, 0x3
    beq     $v0, $t5, .L800E4268
    addiu   $v0, $zero, 0x1
    jal     func_800E45D4
    addiu   $a0, $zero, 0x80
    slt     $t4, $t4, $v0
    bnez    $t4, .L800E4268
    addiu   $v0, $zero, 0x1
    lui     $t4, %hi(D_800F1758)
    addiu   $t4, $t4, %lo(D_800F1758)
    addu    $t4, $t4, $t5
    lbu     $t7, 0x0($t4)
    addu    $t6, $t5, $zero
.L800E41E4:
    sw      $t7, 0x14($sp)
    addi    $v1, $t7, -0x1 /* handwritten instruction */
    sll     $v1, $v1, 8
    or      $v0, $v1, $t6
    sh      $v0, 0x474($a3)
    addiu   $v0, $zero, 0x40
    sh      $v0, 0x13A($t3)
    addiu   $v0, $zero, 0x2
    bne     $t5, $v0, .L800E4234
    addiu   $v0, $zero, 0x1
    slti    $v1, $t7, 0xB
    beqz    $v1, .L800E421C
    addiu   $v1, $zero, 0x500
    addu    $v1, $zero, $zero
.L800E421C:
    sh      $v1, 0x188($t3)
    addu    $a0, $t3, $zero
    lui     $ra, %hi(D_800E425C)
    addiu   $ra, $ra, %lo(D_800E425C)
    bgez    $zero, func_800DEEFC
    addiu   $a1, $zero, 0x10
.L800E4234:
    bne     $t5, $v0, .L800E4268
    addiu   $v0, $zero, 0x1
    slti    $v0, $t7, 0x35
    beqz    $v0, .L800E421C
    addi    $v1, $zero, 0x320 /* handwritten instruction */
    slti    $v0, $t7, 0x12
    beqz    $v0, .L800E421C
    addi    $v1, $zero, -0x320 /* handwritten instruction */
    bgez    $zero, .L800E421C
    addu    $v1, $zero, $zero
alabel D_800E425C
    lw      $v0, 0x14($sp)
    nop
    slti    $v0, $v0, 0x2
.L800E4268:
    lw      $ra, 0x18($sp)
    xori    $v0, $v0, 0x1
    jr      $ra
    addiu   $sp, $sp, 0x20
    sll     $a1, $a1, 1
    addu    $a1, $a1, $a0
    jr      $ra
    sh      $zero, 0x474($a1)
endlabel func_800E4180

# hasm: trapping arithmetic
# hasm: temp register usage
glabel func_800E4288
    addu    $t0, $zero, $zero
    srl     $a2, $a1, 4
    beqz    $a2, .L800E42BC
    andi    $a3, $a1, 0xC
.L800E4298:
    sw      $zero, 0x0($a0)
    sw      $zero, 0x4($a0)
    sw      $zero, 0x8($a0)
    sw      $zero, 0xC($a0)
    addi    $a2, $a2, -0x1 /* handwritten instruction */
    bnez    $a2, .L800E4298
    addiu   $a0, $a0, 0x10
    beqz    $a3, .L800E42CC
    nop
.L800E42BC:
    addi    $a3, $a3, -0x4 /* handwritten instruction */
    sw      $zero, 0x0($a0)
    bnez    $a3, .L800E42BC
    addiu   $a0, $a0, 0x4
.L800E42CC:
    jr      $ra
    nop
endlabel func_800E4288

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E42D4
    sra     $a0, $a0, 7
    bgez    $zero, func_800E42EC
    sra     $a1, $a1, 7
endlabel func_800E42D4

# hasm: cross-function control flow
glabel func_800E42E0
    sll     $a1, $a0, 8
    srl     $a1, $a1, 24
    andi    $a0, $a0, 0xFF
endlabel func_800E42E0

# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_800E42EC
    addu    $at, $ra, $zero
    jal     func_800E4320
    nop
    addu    $ra, $at, $zero
    sll     $v0, $v0, 17
    jr      $ra
    sra     $v0, $v0, 17
endlabel func_800E42EC

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E4308
    sll     $a1, $a0, 8
    srl     $a1, $a1, 24
    bgez    $zero, func_800E4320
    andi    $a0, $a0, 0xFF
endlabel func_800E4308

# hasm: cross-function control flow
glabel func_800E4318
    sra     $a0, $a0, 7
    sra     $a1, $a1, 7
endlabel func_800E4318

# hasm: trapping arithmetic
glabel func_800E4320
    sll     $v1, $a0, 1
    lui     $a2, (0x1F8003BC >> 16)
    lw      $a2, (0x1F8003BC & 0xFFFF)($a2)
    sll     $v0, $a1, 6
    addu    $v0, $v0, $a2
    addu    $v1, $v1, $v0
    lhu     $v0, 0x0($v1)
    nop
    sll     $a2, $v0, 22
    sra     $a2, $a2, 16
    andi    $v0, $v0, 0x1C00
    sra     $v0, $v0, 3
    jr      $ra
    sub     $v0, $a2, $v0 /* handwritten instruction */
endlabel func_800E4320

# hasm: trapping arithmetic
# hasm: cross-function control flow
# hasm: temp register usage
glabel func_800E4358
    lbu     $t0, 0x155($a0)
    lbu     $t3, 0x13F($a0)
    beqz    $t0, .L800E436C
    addi    $t0, $t0, -0x1 /* handwritten instruction */
    sb      $t0, 0x155($a0)
.L800E436C:
    beqz    $t3, .L800E44E0
    addi    $t3, $t3, -0x1 /* handwritten instruction */
    jr      $ra
    sb      $t3, 0x13F($a0)
endlabel func_800E4358

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800E437C
    beqz    $a3, .L800E4474
    addi    $v0, $zero, 0x1000 /* handwritten instruction */
    addu    $a3, $ra, $zero
    negu    $a2, $a2
    addiu   $a2, $a2, 0xC00
    andi    $a2, $a2, 0xFFF
    addiu   $t6, $zero, 0x1
    addu    $t7, $a2, $zero
.L800E439C:
    xori    $t6, $t6, 0x1
    lui     $v0, %hi(_trig_table)
    addiu   $v0, $v0, %lo(_trig_table)
    andi    $t0, $a2, 0x400
    beqz    $t0, .L800E43C8
    andi    $t1, $a2, 0x3FF
    bnez    $t1, .L800E43C4
    addiu   $t2, $zero, 0x800
    bgez    $zero, .L800E43EC
    addiu   $v0, $zero, 0x1000
.L800E43C4:
    subu    $a2, $t2, $a2
.L800E43C8:
    andi    $t1, $a2, 0x200
    beqz    $t1, .L800E43E0
    andi    $t2, $a2, 0x1FF
    addiu   $t0, $zero, 0x200
    subu    $t2, $t0, $t2
    addiu   $v0, $v0, 0x2
.L800E43E0:
    sll     $t2, $t2, 2
    addu    $v0, $v0, $t2
    lhu     $v0, 0x0($v0)
.L800E43EC:
    andi    $t0, $a2, 0x800
    beqz    $t0, .L800E43FC
    nop
    negu    $v0, $v0
.L800E43FC:
    beqz    $t6, .L800E440C
    addiu   $a2, $t7, 0x400
    bgez    $zero, .L800E4414
    addu    $t8, $v0, $zero
.L800E440C:
    bgez    $zero, .L800E439C
    addu    $t9, $v0, $zero
.L800E4414:
    lh      $t0, 0x0($a0)
    lh      $t2, 0x4($a0)
    lh      $t3, 0x0($a1)
    lh      $t4, 0x4($a1)
    sub     $t0, $t3, $t0 /* handwritten instruction */
    sub     $t2, $t4, $t2 /* handwritten instruction */
    addu    $t1, $zero, $zero
    jal     func_80041AF4
    nop
    mult    $t0, $t8
    mflo    $a0
    nop
    addu    $ra, $a3, $zero
    mult    $t2, $t9
    mflo    $v0
    add     $v0, $v0, $a0 /* handwritten instruction */
    sra     $t0, $v0, 12
    slti    $t1, $t0, -0x1000
    bnez    $t1, .L800E4474
    addi    $v0, $zero, -0x1000 /* handwritten instruction */
    slti    $t1, $t0, 0x1000
    beqz    $t1, .L800E4474
    addi    $v0, $zero, 0x1000 /* handwritten instruction */
    addu    $v0, $t0, $zero
.L800E4474:
    jr      $ra
endlabel func_800E437C

# hasm: trapping arithmetic
glabel func_800E4478
    addu    $t8, $a1, $zero
    addu    $a1, $a2, $zero
    sra     $a0, $a0, 7
    sra     $a1, $a1, 7
    sll     $v1, $a0, 1
    lui     $a2, (0x1F8003BC >> 16)
    lw      $a2, (0x1F8003BC & 0xFFFF)($a2)
    sll     $v0, $a1, 6
    addu    $v0, $v0, $a2
    addu    $v1, $v1, $v0
    lhu     $v0, 0x0($v1)
    nop
    sll     $a2, $v0, 18
    bltz    $a2, .L800E44D0
    addu    $t0, $zero, $zero
    sll     $a2, $v0, 22
    sra     $a2, $a2, 16
    andi    $v0, $v0, 0x1C00
    sra     $v0, $v0, 3
    sub     $v0, $a2, $v0 /* handwritten instruction */
    sll     $t0, $v0, 17
    sra     $t0, $t0, 17
.L800E44D0:
    slt     $t8, $t8, $t0
    bnez    $t8, .L800E44E0
    addiu   $v0, $zero, 0x1
    addu    $v0, $zero, $zero
.L800E44E0:
    jr      $ra
    nop
endlabel func_800E4478

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: reserved register usage
glabel func_800E44E8
    addiu   $sp, $sp, -0x38
    sw      $ra, 0x30($sp)
    sw      $s0, 0x10($sp)
    sw      $s6, 0x28($sp)
    sw      $s5, 0x24($sp)
    sw      $s4, 0x20($sp)
    sw      $s3, 0x1C($sp)
    sw      $s2, 0x18($sp)
    sw      $s1, 0x14($sp)
    lw      $s0, 0x0($a0)
    lh      $s2, 0x4($a0)
    sra     $s1, $s0, 16
    andi    $s0, $s0, 0xFFFF
    sub     $s1, $s1, $a2 /* handwritten instruction */
    lw      $t0, 0x0($a1)
    lh      $t2, 0x4($a1)
    sra     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
    sub     $t1, $t1, $a3 /* handwritten instruction */
    sub     $s3, $t0, $s0 /* handwritten instruction */
    sub     $s4, $t1, $s1 /* handwritten instruction */
    sub     $s5, $t2, $s2 /* handwritten instruction */
    sra     $s3, $s3, 4
    sra     $s4, $s4, 4
    sra     $s5, $s5, 4
    addu    $s6, $zero, $zero
.L800E4550:
    add     $a0, $s0, $s3 /* handwritten instruction */
    add     $a1, $s1, $s4 /* handwritten instruction */
    add     $a2, $s2, $s5 /* handwritten instruction */
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    jal     func_800E4478
    addu    $s2, $a2, $zero
    beqz    $v0, .L800E4588
    addi    $s6, $s6, 0x1 /* handwritten instruction */
    andi    $at, $s6, 0x10
    bnez    $at, .L800E458C
    addu    $v0, $zero, $zero
    bgez    $zero, .L800E4550
    nop
.L800E4588:
    addi    $v0, $zero, 0x1 /* handwritten instruction */
.L800E458C:
    lw      $ra, 0x30($sp)
    lw      $s0, 0x10($sp)
    lw      $s6, 0x28($sp)
    lw      $s5, 0x24($sp)
    lw      $s4, 0x20($sp)
    lw      $s3, 0x1C($sp)
    lw      $s2, 0x18($sp)
    lw      $s1, 0x14($sp)
    jr      $ra
    addiu   $sp, $sp, 0x38
endlabel func_800E44E8
