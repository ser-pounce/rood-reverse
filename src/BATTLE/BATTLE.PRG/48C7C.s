.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: split div
glabel func_800B147C
    lw      $t0, 0x10($sp)
    sll     $v0, $a3, 12
    beq     $a3, $t0, .L800B16D4
    srl     $v1, $t0, 1
    beq     $a3, $v1, .L800B16B8
    div     $zero, $v0, $t0
    lw      $t1, 0x148($a0)
    lh      $t3, 0x14C($a0)
    lw      $t4, 0x148($a1)
    lh      $t6, 0x14C($a1)
    sra     $t2, $t1, 16
    sra     $t5, $t4, 16
    sub     $t8, $t5, $t2
    sll     $t1, $t1, 16
    sra     $t1, $t1, 16
    sll     $t4, $t4, 16
    sra     $t4, $t4, 16
    sub     $t7, $t4, $t1
    mflo    $v0
    sub     $t9, $t6, $t3
    mtc2    $v0, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t9, $11
    or      $v0, $t7, $t8
    or      $v0, $v0, $t9
    gpf     1
    lw      $v1, 0x0($a0)
    beqz    $v0, .L800B1528
    mfc2    $t7, $25
    mfc2    $t8, $26
    mfc2    $t9, $27
    or      $v0, $t7, $t8
    beqz    $v0, .L800B151C
    add     $t1, $t1, $t7
    add     $t2, $t2, $t8
    andi    $t1, $t1, 0xFFFF
    sll     $t2, $t2, 16
    or      $t1, $t1, $t2
    sw      $t1, 0x148($a0)
.L800B151C:
    beqz    $t9, .L800B1528
    add     $t3, $t3, $t9
    sw      $t3, 0x14C($a0)
.L800B1528:
    lh      $t3, 0x4($a0)
    lw      $t4, 0x0($a1)
    lh      $t6, 0x4($a1)
    sra     $t2, $v1, 16
    sra     $t5, $t4, 16
    subu    $t8, $t5, $t2
    sll     $t1, $v1, 16
    sra     $t1, $t1, 16
    sll     $t4, $t4, 16
    sra     $t4, $t4, 16
    subu    $t7, $t4, $t1
    subu    $t9, $t6, $t3
    beqz    $t7, .L800B157C
    slti    $v0, $t7, 0x1000
    bnez    $v0, .L800B1570
    slti    $v0, $t7, -0x1000
    j       .L800B157C
    addi    $t7, $t7, -0x2000
.L800B1570:
    beqz    $v0, .L800B157C
    nop
    addi    $t7, $t7, 0x2000
.L800B157C:
    mtc2    $t7, $9
    beqz    $t8, .L800B15A4
    slti    $v0, $t8, 0x1000
    bnez    $v0, .L800B1598
    slti    $v0, $t8, -0x1000
    j       .L800B15A4
    addi    $t8, $t8, -0x2000
.L800B1598:
    beqz    $v0, .L800B15A4
    nop
    addi    $t8, $t8, 0x2000
.L800B15A4:
    mtc2    $t8, $10
    beqz    $t9, .L800B15D0
    slti    $v0, $t9, 0x1000
    bnez    $v0, .L800B15C0
    slti    $v0, $t9, -0x1000
    j       .L800B15CC
    addi    $t9, $t9, -0x2000
.L800B15C0:
    beqz    $v0, .L800B15CC
    nop
    addi    $t9, $t9, 0x2000
.L800B15CC:
    mtc2    $t9, $11
.L800B15D0:
    or      $v0, $t7, $t8
    or      $v0, $v0, $t9
    gpf     1
    lw      $v1, 0x150($a0)
    beqz    $v0, .L800B161C
    mfc2    $t7, $25
    mfc2    $t8, $26
    mfc2    $t9, $27
    or      $v0, $t7, $t8
    beqz    $v0, .L800B1610
    add     $t1, $t1, $t7
    add     $t2, $t2, $t8
    sll     $t2, $t2, 16
    andi    $t1, $t1, 0xFFFF
    or      $t1, $t1, $t2
    sw      $t1, 0x0($a0)
.L800B1610:
    beqz    $t9, .L800B161C
    add     $t3, $t3, $t9
    sw      $t3, 0x4($a0)
.L800B161C:
    lh      $t3, 0x154($a0)
    lw      $t4, 0x150($a1)
    lh      $t6, 0x154($a1)
    sra     $t2, $v1, 16
    sra     $t5, $t4, 16
    subu    $t8, $t5, $t2
    andi    $t1, $v1, 0xFFFF
    andi    $t4, $t4, 0xFFFF
    subu    $t7, $t4, $t1
    subu    $t9, $t6, $t3
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t9, $11
    or      $v0, $t7, $t8
    or      $v0, $v0, $t9
    gpf     1
    lw      $v1, 0x8($a0)
    beqz    $v0, .L800B169C
    mfc2    $t7, $25
    mfc2    $t8, $26
    mfc2    $t9, $27
    or      $v0, $t7, $t8
    beqz    $v0, .L800B1690
    add     $t1, $t1, $t7
    add     $t2, $t2, $t8
    andi    $t1, $t1, 0xFFFF
    sll     $t2, $t2, 16
    or      $t1, $t1, $t2
    sw      $t1, 0x150($a0)
.L800B1690:
    beqz    $t9, .L800B169C
    add     $t3, $t3, $t9
    sw      $t3, 0x154($a0)
.L800B169C:
    addi    $a0, $a0, 0x8
    addi    $a1, $a1, 0x8
    addi    $a2, $a2, -0x1
    bnez    $a2, .L800B1528
    nop
    jr      $ra
    nop
.L800B16B8:
    sw      $ra, 0x0($sp)
    jal     func_800AE980
    nop
    lw      $ra, 0x0($sp)
    nop
    jr      $ra
    nop
.L800B16D4:
    sw      $ra, 0x0($sp)
    jal     vs_main_memcpy
    ori     $a2, $zero, 0x60C
    nop
    lw      $ra, 0x0($sp)
    nop
    jr      $ra
    nop
endlabel func_800B147C

# hasm: custom register abi
# hasm: temp register usage
glabel func_800B16F4
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    jr      $t9
    andi    $t0, $t0, 0xFFFF
    nop
    nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    jr      $t9
    srl     $t0, $t0, 16
    nop
    nop
    addu    $t1, $a2, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    andi    $t1, $t0, 0xFFFF
    negu    $t1, $t1
    jr      $t9
    srl     $t0, $t0, 16
    nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    negu    $t1, $t1
    jr      $t9
    andi    $t0, $t0, 0xFFFF
    nop
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
    nop
    subu    $t1, $a3, $t8
    lw      $t0, 0x0($t1)
    addiu   $t9, $t9, 0x20
    srl     $t1, $t0, 16
    andi    $t0, $t0, 0xFFFF
    jr      $t9
    negu    $t0, $t0
endlabel func_800B16F4

# hasm: cross-function control flow
glabel func_800B17F0
    lw      $v0, 0x0($a0)
    lw      $t8, 0x4($a0)
    lui     $a2, %hi(_trig_table)
    addiu   $a2, $a2, %lo(_trig_table)
    lui     $t7, %hi(func_800B16F4)
    addiu   $t7, $t7, %lo(func_800B16F4)
    addiu   $a3, $a2, 0x800
alabel D_800B180C
    srl     $t1, $t8, 4
    andi    $t1, $t1, 0xE0
    addu    $t1, $t1, $t7
    lui     $t9, %hi(D_800B180C)
    addiu   $t9, $t9, %lo(D_800B180C)
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
    mult    $t1, $t3
    addu    $v0, $zero, $a1
    mtc2    $t4, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    andi    $t8, $t0, 0xFFFF
    negu    $t8, $t8
    gpf     1
    andi    $t8, $t8, 0xFFFF
    mfc2    $a0, $9
    mfc2    $a1, $10
    mfc2    $t4, $11
    mtc2    $t5, $8
    mtc2    $t2, $9
    mtc2    $t3, $10
    mtc2    $t1, $11
    mflo    $t7
    sra     $t7, $t7, 13
    gpf     1
    mult    $t1, $t2
    sh      $t7, 0x10($v0)
    sra     $t4, $t4, 1
    sll     $t4, $t4, 16
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
    mflo    $t7
    sra     $t7, $t7, 13
    sll     $t7, $t7, 16
    mult    $t0, $a1
    or      $t8, $t8, $t7
    sw      $t8, 0xC($v0)
    mfc2    $t2, $9
    mfc2    $t3, $10
    mfc2    $t6, $11
    subu    $t2, $t2, $a1
    addu    $t3, $t3, $a3
    addu    $t6, $t6, $a0
    sra     $t2, $t2, 2
    sll     $t2, $t2, 16
    or      $t2, $t2, $t5
    sw      $t2, 0x0($v0)
    sra     $t6, $t6, 2
    andi    $t6, $t6, 0xFFFF
    or      $t6, $t6, $t4
    sw      $t6, 0x4($v0)
    sra     $t3, $t3, 2
    andi    $t3, $t3, 0xFFFF
    mflo    $t7
    sra     $t7, $t7, 12
    subu    $t7, $t7, $a2
    sra     $t7, $t7, 2
    sll     $t7, $t7, 16
    or      $t7, $t7, $t3
    jr      $ra
    sw      $t7, 0x8($v0)
endlabel func_800B17F0

# hasm: temp register usage
glabel func_800B196C
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
    sll     $t6, $t2, 16
    rtv0
    lw      $t0, 0x0($a1)
    lw      $t3, 0xC($a1)
    srl     $t5, $t0, 16
    or      $t5, $t5, $t6
    srl     $t6, $t3, 16
    mfc2    $a0, $9
    mfc2    $a2, $10
    mfc2    $a3, $11
    mtc2    $t5, $0
    mtc2    $t6, $1
    sll     $a2, $a2, 16
    rtv0
    and     $t7, $t1, $t9
    andi    $t8, $t0, 0xFFFF
    or      $t7, $t7, $t8
    andi    $a0, $a0, 0xFFFF
    sh      $a3, 0x10($a1)
    mfc2    $t0, $9
    mfc2    $t1, $10
    mfc2    $t2, $11
    mtc2    $t7, $0
    mtc2    $t3, $1
    andi    $t1, $t1, 0xFFFF
    rtv0
    addu    $v0, $zero, $a1
    or      $t1, $t1, $a2
    sw      $t1, 0x8($a1)
    sll     $t0, $t0, 16
    sll     $t2, $t2, 16
    mfc2    $t3, $9
    mfc2    $t4, $10
    mfc2    $t5, $11
    andi    $t3, $t3, 0xFFFF
    or      $t3, $t3, $t0
    sw      $t3, 0x0($a1)
    sll     $t4, $t4, 16
    or      $t4, $t4, $a0
    sw      $t4, 0x4($a1)
    andi    $t5, $t5, 0xFFFF
    or      $t5, $t5, $t2
    jr      $ra
    sw      $t5, 0xC($a1)
endlabel func_800B196C
