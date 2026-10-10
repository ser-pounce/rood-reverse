.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: split div
glabel SetFogNear
    sll     $v0, $a0, 2
    addu    $v0, $v0, $a0
    sll     $v0, $v0, 6
    negu    $v0, $v0
    div     $zero, $v0, $a1
    lui     $a2, (0x1400000 >> 16)
    ctc2    $a2, $28
    mflo    $a0
    ctc2    $a0, $27
    jr      $ra
    .nop
endlabel SetFogNear

# hasm: single-nop gte hazard
glabel Square0
    lwc2    $9, 0x0($a0)
    lwc2    $10, 0x4($a0)
    lwc2    $11, 0x8($a0)
    .nop
    sqr     0
    swc2    $25, 0x0($a1)
    swc2    $26, 0x4($a1)
    swc2    $27, 0x8($a1)
    jr      $ra
    addu    $v0, $a1, $zero
endlabel Square0

# hasm: temp register usage
# hasm: single-nop gte hazard
glabel OuterProduct0
    cfc2    $t5, $0
    cfc2    $t6, $2
    cfc2    $t7, $4
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    lw      $t2, 0x8($a0)
    ctc2    $t0, $0
    ctc2    $t1, $2
    ctc2    $t2, $4
    lwc2    $11, 0x8($a1)
    lwc2    $9, 0x0($a1)
    lwc2    $10, 0x4($a1)
    .nop
    op      1
    swc2    $25, 0x0($a2)
    swc2    $26, 0x4($a2)
    swc2    $27, 0x8($a2)
    ctc2    $t5, $0
    ctc2    $t6, $2
    ctc2    $t7, $4
    jr      $ra
    .nop
endlabel OuterProduct0

# hasm: single-nop gte hazard
glabel DpqColor
    lwc2    $6, 0x0($a0)
    mtc2    $a1, $8
    .nop
    dpcs
    swc2    $22, 0x0($a2)
.L80041A14:
    jr      $ra
    .nop
endlabel DpqColor

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
glabel InvSquareRoot
    mtc2    $a0, $30
    lui     $v0, %hi(D_80040D98)
    addiu   $v0, $v0, %lo(D_80040D98)
    mfc2    $t2, $31
    addi    $t1, $zero, 0x1F
    srl     $t0, $t2, 5
    bnez    $t0, .L80041A14
    andi    $t2, $t2, 0x1E
    sub     $t1, $t1, $t2
    addi    $t3, $t2, -0x18
    bltz    $t3, .L80041A54
    addiu   $t0, $zero, 0x18
    sllv    $a0, $a0, $t3
    bgez    $zero, .L80041A5C
.L80041A54:
    sub     $t0, $t0, $t2
    srav    $a0, $a0, $t0
.L80041A5C:
    sll     $a0, $a0, 1
    addu    $v0, $v0, $a0
    lh      $t0, -0x80($v0)
    sra     $t1, $t1, 1
    sw      $t1, 0x0($a2)
    jr      $ra
    sw      $t0, 0x0($a1)
endlabel InvSquareRoot

# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel VectorNormalS
    lw      $t0, 0x0($a0)
    addu    $a3, $ra, $zero
    lw      $t1, 0x4($a0)
    jal     func_80041AF4
    lw      $t2, 0x8($a0)
    bgez    $zero, .L80041ADC
    addu    $ra, $a3, $zero
endlabel VectorNormalS

# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel VectorNormal
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    addu    $a3, $ra, $zero
    jal     func_80041AF4
    lw      $t2, 0x8($a0)
    sw      $t0, 0x0($a1)
    addu    $ra, $a3, $zero
    sw      $t1, 0x4($a1)
    jr      $ra
    sw      $t2, 0x8($a1)
endlabel VectorNormal

# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: temp register usage
glabel VectorNormalSS
    lw      $t0, 0x0($a0)
    addu    $a3, $ra, $zero
    sra     $t1, $t0, 16
    sll     $t0, $t0, 16
    sra     $t0, $t0, 16
    jal     func_80041AF4
    lh      $t2, 0x4($a0)
    addu    $ra, $a3, $zero
.L80041ADC:
    sll     $t1, $t1, 16
    andi    $t0, $t0, 0xFFFF
    or      $t0, $t1, $t0
    sw      $t0, 0x0($a1)
    jr      $ra
    sh      $t2, 0x4($a1)
endlabel VectorNormalSS

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: custom register abi
glabel func_80041AF4
    mtc2    $t0, $9
    mtc2    $t1, $10
    mtc2    $t2, $11
    lui     $t7, %hi(D_80040D98)
    addiu   $t7, $t7, %lo(D_80040D98)
    sqr     0
    mfc2    $t3, $25
    mfc2    $t4, $26
    mfc2    $t5, $27
    add     $t3, $t3, $t4
    add     $v0, $t3, $t5
    mtc2    $v0, $30
    addiu   $t3, $zero, -0x2
    addiu   $t6, $zero, 0x1F
    mfc2    $v1, $31
    mtc2    $t0, $9
    and     $v1, $v1, $t3
    addi    $t3, $v1, -0x18
    bltz    $t3, .L80041B4C
    addiu   $t4, $zero, 0x18
    bgez    $zero, .L80041B54
    sllv    $t4, $v0, $t3
.L80041B4C:
    sub     $t3, $t4, $v1
    srav    $t4, $v0, $t3
.L80041B54:
    sll     $t4, $t4, 1
    addu    $t5, $t4, $t7
    lh      $t5, -0x80($t5)
    mtc2    $t1, $10
    mtc2    $t5, $8
    mtc2    $t2, $11
    sub     $t6, $t6, $v1
    sra     $t6, $t6, 1
    gpf     0
    mfc2    $t0, $25
    mfc2    $t1, $26
    mfc2    $t2, $27
    srav    $t0, $t0, $t6
    srav    $t1, $t1, $t6
    jr      $ra
    srav    $t2, $t2, $t6
endlabel func_80041AF4

# hasm: trapping arithmetic
# hasm: unconditional b branch
glabel vs_gte_rsqrt
    mtc2    $a0, $30
    lui     $v0, %hi(D_80040C18)
    addiu   $v0, $v0, %lo(D_80040C18)
    mfc2    $t2, $31
    addi    $t1, $zero, 0x1F
    srl     $t0, $t2, 5
    bnez    $t0, .L80041BE8
    andi    $t2, $t2, 0x1E
    sub     $t1, $t1, $t2
    addi    $a1, $t2, -0x18
    bltz    $a1, .L80041BCC
    addiu   $t0, $zero, 0x18
    sllv    $a0, $a0, $a1
    bgez    $zero, .L80041BD4
.L80041BCC:
    sub     $t0, $t0, $t2
    srav    $a0, $a0, $t0
.L80041BD4:
    sll     $a0, $a0, 1
    addu    $v0, $v0, $a0
    lh      $t0, -0x80($v0)
    sra     $t1, $t1, 1
    sllv    $t0, $t0, $t1
.L80041BE8:
    jr      $ra
    srl     $v0, $t0, 12
endlabel vs_gte_rsqrt

# hasm: trapping arithmetic
# hasm: unconditional b branch
glabel SquareRoot12
    mtc2    $a0, $30
    lui     $v0, %hi(D_80040C18)
    addiu   $v0, $v0, %lo(D_80040C18)
    mfc2    $t2, $31
    addiu   $t1, $zero, 0x13
    srl     $t0, $t2, 5
    bnez    $t0, .L80041C58
    addu    $t3, $zero, $zero
    andi    $t2, $t2, 0x1E
    sub     $t1, $t1, $t2
    addi    $a1, $t2, -0x18
    bltz    $a1, .L80041C2C
    addiu   $t0, $zero, 0x18
    sllv    $a0, $a0, $a1
    bgez    $zero, .L80041C34
.L80041C2C:
    sub     $t0, $t0, $t2
    srav    $a0, $a0, $t0
.L80041C34:
    sll     $a0, $a0, 1
    addu    $v0, $v0, $a0
    lh      $t0, -0x80($v0)
    sra     $t1, $t1, 1
    bgtz    $t1, .L80041C58
    sllv    $t3, $t0, $t1
    neg     $t1, $t1
    bgez    $zero, .L80041C58
    srlv    $t3, $t0, $t1
.L80041C58:
    jr      $ra
    addu    $v0, $t3, $zero
endlabel SquareRoot12

# hasm: cross-function control flow
glabel CompMatrixLV
    j       .L80041C6C
    addu    $a2, $zero, $a0
endlabel CompMatrixLV

glabel func_80041C68
    addu    $a2, $zero, $a1
.L80041C6C:
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    lw      $t2, 0x8($a0)
    lw      $t3, 0xC($a0)
    lw      $t4, 0x10($a0)
    ctc2    $t0, $0
    ctc2    $t1, $1
    ctc2    $t2, $2
    ctc2    $t3, $3
    ctc2    $t4, $4
    lw      $t1, 0x4($a1)
    lw      $t2, 0x8($a1)
    lw      $t4, 0x10($a1)
    lui     $t9, (0xFFFF0000 >> 16)
    and     $t5, $t2, $t9
    andi    $t6, $t1, 0xFFFF
    or      $t5, $t5, $t6
    mtc2    $t5, $0
    mtc2    $t4, $1
    addu    $v0, $zero, $a2
    rtv0
    lw      $t0, 0x0($a1)
    lw      $t3, 0xC($a1)
    sll     $t6, $t2, 16
    srl     $t5, $t0, 16
    or      $t5, $t5, $t6
    srl     $t6, $t3, 16
    mfc2    $a1, $9
    mfc2    $a2, $10
    mfc2    $a3, $11
    mtc2    $t5, $0
    mtc2    $t6, $1
    sll     $a2, $a2, 16
    rtv0
    and     $t7, $t1, $t9
    andi    $t8, $t0, 0xFFFF
    or      $t7, $t7, $t8
    andi    $a1, $a1, 0xFFFF
    sh      $a3, 0x10($v0)
    mfc2    $t0, $9
    mfc2    $t1, $10
    mfc2    $t2, $11
    mtc2    $t7, $0
    mtc2    $t3, $1
    andi    $t1, $t1, 0xFFFF
    rtv0
    or      $t1, $t1, $a2
    sw      $t1, 0x8($v0)
    sll     $t0, $t0, 16
    sll     $t2, $t2, 16
    mfc2    $t3, $9
    mfc2    $t4, $10
    mfc2    $t5, $11
    andi    $t3, $t3, 0xFFFF
    or      $t3, $t3, $t0
    sw      $t3, 0x0($v0)
    sll     $t4, $t4, 16
    or      $t4, $t4, $a1
    sw      $t4, 0x4($v0)
    andi    $t5, $t5, 0xFFFF
    or      $t5, $t5, $t2
    jr      $ra
    sw      $t5, 0xC($v0)
endlabel func_80041C68
