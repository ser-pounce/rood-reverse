.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: cross-function control flow
glabel rcos
    addiu   $a0, $a0, 0x400
endlabel rcos

glabel rsin
    lui     $v0, %hi(_trig_table)
    addiu   $v0, $v0, %lo(_trig_table)
    andi    $t0, $a0, 0x400
    beqz    $t0, .L80040F50
    andi    $t1, $a0, 0x3FF
    bnez    $t1, .L80040F4C
    addiu   $t2, $zero, 0x800
    j       .L80040F74
    addiu   $v0, $zero, 0x1000
.L80040F4C:
    subu    $a0, $t2, $a0
.L80040F50:
    andi    $t1, $a0, 0x200
    beqz    $t1, .L80040F68
    andi    $t2, $a0, 0x1FF
    addiu   $t0, $zero, 0x200
    subu    $t2, $t0, $t2
    addiu   $v0, $v0, 0x2
.L80040F68:
    sll     $t2, $t2, 2
    addu    $v0, $v0, $t2
    lhu     $v0, 0x0($v0)
.L80040F74:
    andi    $t0, $a0, 0x800
    beqz    $t0, .L80040F84
    .nop
    negu    $v0, $v0
.L80040F84:
    jr      $ra
    .nop
endlabel rsin

# hasm: cross-function control flow
glabel RotMatrixYXZ_gte
    lw      $v0, 0x0($a0)
    lw      $t8, 0x4($a0)
    lui     $a2, %hi(_trig_table)
    addiu   $a2, $a2, %lo(_trig_table)
    lui     $t7, %hi(func_80041104)
    addiu   $t7, $t7, %lo(func_80041104)
    addiu   $a3, $a2, 0x800
alabel D_80040FA8
    srl     $t1, $t8, 4
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    lui     $t9, %hi(D_80040FA8)
    addiu   $t9, $t9, %lo(D_80040FA8)
    sll     $t8, $t8, 2
    jr      $t1
    andi    $t8, $t8, 0x7FC
    sll     $t4, $t0, 1
    sll     $t5, $t1, 1
    srl     $t8, $v0, 14
    srl     $t1, $t8, 6
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    jr      $t1
    andi    $t8, $t8, 0x7FC
    sll     $t2, $t0, 1
    sll     $t3, $t1, 1
    sll     $t8, $v0, 2
    srl     $t1, $t8, 6
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    jr      $t1
    andi    $t8, $t8, 0x7FC
    mtc2    $t4, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    mult    $t1, $t2
    addu    $v0, $zero, $a1
    gpf     1
    negu    $t8, $t0
    sll     $t8, $t8, 16
    mfc2    $a0, $9
    mfc2    $a1, $10
    mfc2    $t4, $11
    mtc2    $t5, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    sra     $t4, $t4, 1
    sll     $t4, $t4, 16
    gpf     1
    mflo    $t7
    sra     $t7, $t7, 13
    andi    $t7, $t7, 0xFFFF
    mult    $t1, $t3
    or      $t4, $t4, $t7
    sw      $t4, 0x4($v0)
    mfc2    $a2, $9
    mfc2    $a3, $10
    mfc2    $t5, $11
    mtc2    $t0, $8
    mtc2    $a0, $9
    mtc2    $a2, $10
    mtc2    $a1, $11
    sra     $t5, $t5, 1
    andi    $t5, $t5, 0xFFFF
    gpf     1
    or      $t5, $t5, $t8
    sw      $t5, 0x8($v0)
    mflo    $t7
    sra     $t7, $t7, 13
    sh      $t7, 0x10($v0)
    mult    $t0, $a3
    mfc2    $t2, $9
    mfc2    $t3, $10
    mfc2    $t4, $11
    addu    $t2, $t2, $a3
    subu    $t3, $t3, $a1
    subu    $t4, $t4, $a2
    sra     $t2, $t2, 2
    andi    $t2, $t2, 0xFFFF
    sra     $t3, $t3, 2
    sll     $t3, $t3, 16
    or      $t2, $t2, $t3
    sw      $t2, 0x0($v0)
    sra     $t4, $t4, 2
    andi    $t4, $t4, 0xFFFF
    mflo    $t5
    sra     $t5, $t5, 12
    addu    $t5, $t5, $a0
    sra     $t5, $t5, 2
    sll     $t5, $t5, 16
    or      $t4, $t4, $t5
    jr      $ra
    sw      $t4, 0xC($v0)
endlabel RotMatrixYXZ_gte

# hasm: custom register abi
# hasm: temp register usage
glabel func_80041104
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    jr      $t9
    andi    $t0, $t0, 0xFFFF
    .nop
    .nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    jr      $t9
    srl     $t0, $t0, 16
    .nop
    .nop
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    negu    $t1, $t1
    jr      $t9
    srl     $t0, $t0, 16
    .nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    negu    $t1, $t1
    jr      $t9
    andi    $t0, $t0, 0xFFFF
    .nop
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    negu    $t1, $t1
    andi    $t0, $t0, 0xFFFF
    jr      $t9
    negu    $t0, $t0
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    negu    $t1, $t1
    srl     $t0, $t0, 16
    jr      $t9
    negu    $t0, $t0
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    srl     $t0, $t0, 16
    jr      $t9
    negu    $t0, $t0
    .nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
    jr      $t9
    negu    $t0, $t0
endlabel func_80041104

# hasm: cross-function control flow
glabel RotMatrix_gte
    lw      $v0, 0x0($a0)
    lw      $t8, 0x4($a0)
    lui     $a2, %hi(_trig_table)
    addiu   $a2, $a2, %lo(_trig_table)
    lui     $t7, %hi(func_80041104)
    addiu   $t7, $t7, %lo(func_80041104)
    addiu   $a3, $a2, 0x800
alabel D_8004121C
    srl     $t1, $t8, 4
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    lui     $t9, %hi(D_8004121C)
    addiu   $t9, $t9, %lo(D_8004121C)
    sll     $t8, $t8, 2
    jr      $t1
    andi    $t8, $t8, 0x7FC
    sll     $t4, $t0, 1
    sll     $t5, $t1, 1
    sll     $t8, $v0, 2
    srl     $t1, $t8, 6
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    jr      $t1
    andi    $t8, $t8, 0x7FC
    sll     $t2, $t0, 1
    sll     $t3, $t1, 1
    srl     $t8, $v0, 14
    srl     $t1, $t8, 6
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    jr      $t1
    andi    $t8, $t8, 0x7FC
    mtc2    $t4, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    mult    $t1, $t3
    addu    $v0, $zero, $a1
    gpf     1
    andi    $t8, $t0, 0xFFFF
    mfc2    $a0, $9
    mfc2    $a1, $10
    mfc2    $t4, $11
    mtc2    $t5, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    sra     $t4, $t4, 1
    negu    $t4, $t4
    gpf     1
    mflo    $t7
    sll     $t4, $t4, 16
    sra     $t7, $t7, 13
    mult    $t1, $t2
    sh      $t7, 0x10($v0)
    mfc2    $a2, $9
    mfc2    $a3, $10
    mfc2    $t5, $11
    mtc2    $t0, $8
    mtc2    $a2, $9
    mtc2    $a0, $10
    mtc2    $a3, $11
    sra     $t5, $t5, 1
    andi    $t5, $t5, 0xFFFF
    gpf     1
    or      $t5, $t5, $t4
    sw      $t5, 0x0($v0)
    mflo    $t7
    sra     $t7, $t7, 13
    negu    $t7, $t7
    mult    $t0, $a1
    sll     $t7, $t7, 16
    mfc2    $t2, $9
    mfc2    $t3, $10
    mfc2    $t4, $11
    addu    $t2, $t2, $a1
    subu    $t3, $a3, $t3
    subu    $t4, $a0, $t4
    sra     $t2, $t2, 2
    sll     $t2, $t2, 16
    or      $t2, $t2, $t8
    sw      $t2, 0x4($v0)
    sra     $t3, $t3, 2
    andi    $t3, $t3, 0xFFFF
    or      $t3, $t3, $t7
    sw      $t3, 0x8($v0)
    sra     $t4, $t4, 2
    andi    $t4, $t4, 0xFFFF
    mflo    $t5
    sra     $t5, $t5, 12
    addu    $t5, $t5, $a2
    sra     $t5, $t5, 2
    sll     $t5, $t5, 16
    or      $t4, $t4, $t5
    jr      $ra
    sw      $t4, 0xC($v0)
endlabel RotMatrix_gte
