.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: saved registers outside frame
glabel func_800E3BC8
    lw      $t0, 0x168($a0)
    lui     $t8, (0x3FFFFF >> 16)
    ori     $t8, $t8, (0x3FFFFF & 0xFFFF)
    lw      $t2, 0x34($a0)
    sll     $t1, $t0, 8
    srl     $t1, $t1, 24
    andi    $t0, $t0, 0xFF
    sll     $t3, $t2, 8
    srl     $t3, $t3, 24
    andi    $t2, $t2, 0xFF
    lw      $t9, 0x190($a0)
    slt     $v0, $t2, $t0
    slt     $v1, $t3, $t1
    bne     $t0, $t2, .L800E3C08
    add     $t0, $t0, $v0 /* handwritten instruction */
    addu    $t0, $zero, $zero
.L800E3C08:
    sll     $t0, $t0, 22
    bne     $t1, $t3, .L800E3C18
    add     $t1, $t1, $v1 /* handwritten instruction */
    addu    $t1, $zero, $zero
.L800E3C18:
    sll     $t1, $t1, 27
    and     $t9, $t9, $t8
    or      $t9, $t9, $t0
    or      $t9, $t9, $t1
    jr      $ra
    sw      $t9, 0x190($a0)
alabel func_800E3C30
    lui     $v1, (0x800E3EAC >> 16)
    bgez    $zero, .L800E3C54
    ori     $v1, $v1, (0x800E3EAC & 0xFFFF)
    lui     $v1, (0x800E3FF4 >> 16)
    bgez    $zero, .L800E3C54
    ori     $v1, $v1, (0x800E3FF4 & 0xFFFF)
    lui     $v1, (0x800E40F0 >> 16)
    bgez    $zero, .L800E3C54
    ori     $v1, $v1, (0x800E40F0 & 0xFFFF)
.L800E3C54:
    lw      $t0, 0x34($a0)
    lw      $t2, 0x168($a0)
    sll     $t1, $t0, 8
    srl     $t1, $t1, 17
    andi    $t0, $t0, 0xFF
    sll     $t0, $t0, 7
    sll     $t3, $t2, 8
    srl     $t3, $t3, 17
    andi    $t2, $t2, 0xFF
    sll     $t2, $t2, 7
    sub     $t0, $t2, $t0 /* handwritten instruction */
    sub     $t1, $t3, $t1 /* handwritten instruction */
    mtc2    $t0, $9 /* handwritten instruction */
    mtc2    $t1, $10 /* handwritten instruction */
    lw      $t5, 0x4($a0)
    lui     $t4, (0x31000 >> 16)
    sqr     0
    mfc2    $t0, $25 /* handwritten instruction */
    mfc2    $t1, $26 /* handwritten instruction */
    ori     $t4, $t4, (0x31000 & 0xFFFF)
    add     $t0, $t0, $t1 /* handwritten instruction */
    slt     $t0, $t0, $t4
    and     $v0, $t0, $t5
    beqz    $v0, .L800E3CD4
    mtc2    $ra, $0 /* handwritten instruction */
    jalr    $v1
    mtc2    $a0, $2 /* handwritten instruction */
    mfc2    $a0, $2 /* handwritten instruction */
    jal     func_800E3BC8
    mtc2    $v0, $1 /* handwritten instruction */
    mfc2    $ra, $0 /* handwritten instruction */
    mfc2    $v0, $1 /* handwritten instruction */
.L800E3CD4:
    jr      $ra
    nop
endlabel func_800E3BC8

# hasm: trapping arithmetic
# hasm: custom register abi
glabel func_800E3CDC
    lw      $t0, 0x194($a0)
    lui     $a3, (0xFF00FF >> 16)
    lw      $t1, 0x34($a0)
    ori     $a3, $a3, (0xFF00FF & 0xFFFF)
    and     $t2, $t0, $a3
    lbu     $t4, 0x198($a0)
    and     $t3, $t1, $a3
    beq     $t2, $t3, .L800E3D04
    addiu   $t4, $t4, 0x1
    addu    $t4, $zero, $zero
.L800E3D04:
    slti    $v0, $t4, 0x5
    bnez    $v0, .L800E3D18
    addiu   $v1, $zero, 0x78
    sb      $v1, 0x19A($a0)
    addu    $t4, $zero, $zero
.L800E3D18:
    sw      $t1, 0x194($a0)
    sb      $t4, 0x198($a0)
    sh      $zero, 0x156($a0)
    lbu     $a3, 0x23($a0)
    addiu   $a2, $zero, 0x7E
    bnez    $a3, .L800E3D48
    addu    $v0, $a2, $zero
    jal     func_800E45D4
    addiu   $a0, $zero, 0x4
    bnez    $v0, .L800E3D48
    addu    $v0, $a2, $zero
    srl     $v0, $a2, 2
.L800E3D48:
    sll     $v0, $v0, 5
    addi    $v1, $zero, -0xFE1 /* handwritten instruction */
    and     $a1, $a1, $v1
    jr      $ra
    or      $v0, $a1, $v0
endlabel func_800E3CDC
