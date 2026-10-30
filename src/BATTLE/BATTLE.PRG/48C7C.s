.include "macro.inc"
.include "src/include/gte_reg_macros.inc"

.set noreorder

glabel func_800B147C
    lw         $t0, 0x10($sp)
    sll        $v0, $a3, 12
    beq        $a3, $t0, 14f
     srl       $v1, $t0, 1
    beq        $a3, $v1, 13f
     div       $zero, $v0, $t0
    lw         $t1, 0x148($a0)
    lh         $t3, 0x14C($a0)
    lw         $t4, 0x148($a1)
    lh         $t6, 0x14C($a1)
    sra        $t2, $t1, 16
    sra        $t5, $t4, 16
    sub        $t8, $t5, $t2
    sll        $t1, 16
    sra        $t1, 16
    sll        $t4, 16
    sra        $t4, 16
    sub        $t7, $t4, $t1
    mflo       $v0
    sub        $t9, $t6, $t3
    ldir0123   $v0, $t7, $t8, $t9
    or         $v0, $t7, $t8
    or         $v0, $t9
    gpf12
    lw         $v1, 0x0($a0)
    beqz       $v0, 1f
     mfc2      $t7, $25
    mfc2       $t8, $26
    mfc2       $t9, $27
    or         $v0, $t7, $t8
    beqz       $v0, 0f
     add       $t1, $t7
    add        $t2, $t8
    and        $t1, 0xFFFF
    sll        $t2, 16
    or         $t1, $t2
    sw         $t1, 0x148($a0)
  0:
    beqz       $t9, 1f
     add       $t3, $t9
    sw         $t3, 0x14C($a0)
  1:
    lh         $t3, 0x4($a0)
    lw         $t4, 0x0($a1)
    lh         $t6, 0x4($a1)
    sra        $t2, $v1, 16
    sra        $t5, $t4, 16
    subu       $t8, $t5, $t2
    sll        $t1, $v1, 16
    sra        $t1, 16
    sll        $t4, 16
    sra        $t4, 16
    subu       $t7, $t4, $t1
    subu       $t9, $t6, $t3
    beqz       $t7, 3f
     slt       $v0, $t7, 0x1000
    bnez       $v0, 2f
     slt       $v0, $t7, -0x1000
    j          3f
     add       $t7, -0x2000
  2:
    beqz       $v0, 3f
     nop
    add        $t7, 0x2000
  3:
    mtc2       $t7, $9
    beqz       $t8, 5f
     slt       $v0, $t8, 0x1000
    bnez       $v0, 4f
     slt       $v0, $t8, -0x1000
    j          5f
     add       $t8, -0x2000
  4:
    beqz       $v0, 5f
     nop
    add        $t8, 0x2000
  5:
    mtc2       $t8, $10
    beqz       $t9, 8f
     slt       $v0, $t9, 0x1000
    bnez       $v0, 6f
     slt       $v0, $t9, -0x1000
    j          7f
     add       $t9, -0x2000
  6:
    beqz       $v0, 7f
     nop
    add        $t9, 0x2000
  7:
    mtc2       $t9, $11
  8:
    or         $v0, $t7, $t8
    or         $v0, $t9
    gpf12
    lw         $v1, 0x150($a0)
    beqz       $v0, 10f
     mfc2      $t7, $25
    mfc2       $t8, $26
    mfc2       $t9, $27
    or         $v0, $t7, $t8
    beqz       $v0, 9f
     add       $t1, $t7
    add        $t2, $t8
    sll        $t2, 16
    and        $t1, 0xFFFF
    or         $t1, $t2
    sw         $t1, 0x0($a0)
  9:
    beqz       $t9, 10f
     add       $t3, $t9
    sw         $t3, 0x4($a0)
  10:
    lh         $t3, 0x154($a0)
    lw         $t4, 0x150($a1)
    lh         $t6, 0x154($a1)
    sra        $t2, $v1, 16
    sra        $t5, $t4, 16
    subu       $t8, $t5, $t2
    and        $t1, $v1, 0xFFFF
    and        $t4, 0xFFFF
    subu       $t7, $t4, $t1
    subu       $t9, $t6, $t3
    mtc2       $t7, $9
    mtc2       $t8, $10
    mtc2       $t9, $11
    or         $v0, $t7, $t8
    or         $v0, $t9
    gpf12
    lw         $v1, 0x8($a0)
    beqz       $v0, 12f
     mfc2      $t7, $25
    mfc2       $t8, $26
    mfc2       $t9, $27
    or         $v0, $t7, $t8
    beqz       $v0, 11f
     add       $t1, $t7
    add        $t2, $t8
    and        $t1, 0xFFFF
    sll        $t2, 16
    or         $t1, $t2
    sw         $t1, 0x150($a0)
  11:
    beqz       $t9, 12f
     add       $t3, $t9
    sw         $t3, 0x154($a0)
  12:
    add        $a0, 0x8
    add        $a1, 0x8
    add        $a2, -0x1
    bnez       $a2, 1b
     nop
    jr         $ra
     nop
  13:
    sw         $ra, 0x0($sp)
    jal        func_800AE980
     nop
    lw         $ra, 0x0($sp)
    nop
    jr         $ra
     nop
  14:
    sw         $ra, 0x0($sp)
    jal        vs_main_memcpy
     or        $a2, $zero, 0x60C
    nop
    lw         $ra, 0x0($sp)
    nop
    jr         $ra
     nop
endlabel func_800B147C

glabel func_800B16F4
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    jr         $t9
     and       $t0, 0xFFFF
    nop
    nop
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    jr         $t9
     srl       $t0, 16
    nop
    nop
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    negu       $t1, $t1
    jr         $t9
     srl       $t0, 16
    nop
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    negu       $t1, $t1
    jr         $t9
     and       $t0, 0xFFFF
    nop
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    negu       $t1, $t1
    and        $t0, 0xFFFF
    jr         $t9
     negu      $t0, $t0
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    negu       $t1, $t1
    srl        $t0, 16
    jr         $t9
     negu      $t0, $t0
    addu       $t1, $a2, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    and        $t1, $t0, 0xFFFF
    srl        $t0, 16
    jr         $t9
     negu      $t0, $t0
    nop
    subu       $t1, $a3, $t8
    lw         $t0, 0x0($t1)
    addiu      $t9, 0x20
    srl        $t1, $t0, 16
    and        $t0, 0xFFFF
    jr         $t9
     negu      $t0, $t0
endlabel func_800B16F4

glabel func_800B17F0
    lw         $v0, 0x0($a0)
    lw         $t8, 0x4($a0)
    la         $a2, _trig_table
    la         $t7, func_800B16F4
    addiu      $a3, $a2, 0x800
  alabel D_800B180C
    srl        $t1, $t8, 4
    and        $t1, 0xE0
    addu       $t1, $t7
    la         $t9, D_800B180C
    sll        $t8, 2
    jr         $t1
     and       $t8, 0x7FC
    sll        $t4, $t0, 1
    sll        $t5, $t1, 1
    sll        $t8, $v0, 2
    srl        $t1, $t8, 6
    and        $t1, 0xE0
    addu       $t1, $t7
    jr         $t1
     and       $t8, 0x7FC
    sll        $t2, $t0, 1
    sll        $t3, $t1, 1
    srl        $t8, $v0, 14
    srl        $t1, $t8, 6
    and        $t1, 0xE0
    addu       $t1, $t7
    jr         $t1
     and       $t8, 0x7FC
    mult       $t1, $t3
    addu       $v0, $zero, $a1
    ldir0123   $t4, $t2, $t3, $t1
    and        $t8, $t0, 0xFFFF
    negu       $t8, $t8
    gpf12
    and        $t8, 0xFFFF
    mfc2       $a0, $9
    mfc2       $a1, $10
    mfc2       $t4, $11
    ldir0123   $t5, $t2, $t3, $t1
    mflo       $t7
    sra        $t7, 13
    gpf12
    mult       $t1, $t2
    sh         $t7, 0x10($v0)
    sra        $t4, 1
    sll        $t4, 16
    mfc2       $a2, $9
    mfc2       $a3, $10
    mfc2       $t5, $11
    ldir0123   $t0, $a2, $a0, $a3
    sra        $t5, 1
    and        $t5, 0xFFFF
    gpf12
    mflo       $t7
    sra        $t7, 13
    sll        $t7, 16
    mult       $t0, $a1
    or         $t8, $t7
    sw         $t8, 0xC($v0)
    mfc2       $t2, $9
    mfc2       $t3, $10
    mfc2       $t6, $11
    subu       $t2, $a1
    addu       $t3, $a3
    addu       $t6, $a0
    sra        $t2, 2
    sll        $t2, 16
    or         $t2, $t5
    sw         $t2, 0x0($v0)
    sra        $t6, 2
    and        $t6, 0xFFFF
    or         $t6, $t4
    sw         $t6, 0x4($v0)
    sra        $t3, 2
    and        $t3, 0xFFFF
    mflo       $t7
    sra        $t7, 12
    subu       $t7, $a2
    sra        $t7, 2
    sll        $t7, 16
    or         $t7, $t3
    jr         $ra
     sw        $t7, 0x8($v0)
endlabel func_800B17F0

glabel func_800B196C
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lw         $t1, 0x4($a1)
    lw         $t2, 0x8($a1)
    lw         $t4, 0x10($a1)
    li         $t9, 0xFFFF0000
    and        $t5, $t2, $t9
    and        $t6, $t1, 0xFFFF
    or         $t5, $t6
    mtv0       $t5, $t4
    sll        $t6, $t2, 16
    rtv0
    lw         $t0, 0x0($a1)
    lw         $t3, 0xC($a1)
    srl        $t5, $t0, 16
    or         $t5, $t6
    srl        $t6, $t3, 16
    mfc2       $a0, $9
    mfc2       $a2, $10
    mfc2       $a3, $11
    mtv0       $t5, $t6
    sll        $a2, 16
    rtv0
    and        $t7, $t1, $t9
    and        $t8, $t0, 0xFFFF
    or         $t7, $t8
    and        $a0, 0xFFFF
    sh         $a3, 0x10($a1)
    mfc2       $t0, $9
    mfc2       $t1, $10
    mfc2       $t2, $11
    mtv0       $t7, $t3
    and        $t1, 0xFFFF
    rtv0
    addu       $v0, $zero, $a1
    or         $t1, $a2
    sw         $t1, 0x8($a1)
    sll        $t0, 16
    sll        $t2, 16
    mfc2       $t3, $9
    mfc2       $t4, $10
    mfc2       $t5, $11
    and        $t3, 0xFFFF
    or         $t3, $t0
    sw         $t3, 0x0($a1)
    sll        $t4, 16
    or         $t4, $a0
    sw         $t4, 0x4($a1)
    and        $t5, 0xFFFF
    or         $t5, $t2
    jr         $ra
     sw        $t5, 0xC($a1)
endlabel func_800B196C
