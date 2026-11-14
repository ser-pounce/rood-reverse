.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel ScaleMatrix
    lw      $t0, 0x0($a0)
    lw      $t1, 0x4($a0)
    lw      $t2, 0x8($a0)
    lw      $t3, 0xC($a0)
    lw      $t4, 0x0($a1)
    sll     $t7, $t0, 16
    sra     $t7, $t7, 16
    sra     $t8, $t1, 16
    sll     $t9, $t3, 16
    sra     $t9, $t9, 16
    mtc2    $t4, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t9, $11
    sra     $t7, $t0, 16
    sra     $t9, $t3, 16
    gpf     1
    lw      $t5, 0x4($a1)
    sll     $t8, $t2, 16
    sra     $t8, $t8, 16
    addu    $v0, $zero, $a0
    mfc2    $v1, $9
    mfc2    $a2, $10
    mfc2    $a3, $11
    mtc2    $t5, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t9, $11
    sll     $t7, $t1, 16
    sra     $t7, $t7, 16
    gpf     1
    lh      $t4, 0x10($a0)
    lw      $t6, 0x8($a1)
    sra     $t8, $t2, 16
    andi    $v1, $v1, 0xFFFF
    andi    $a3, $a3, 0xFFFF
    mfc2    $t1, $9
    mfc2    $t2, $10
    mfc2    $t3, $11
    mtc2    $t6, $8
    mtc2    $t7, $9
    mtc2    $t8, $10
    mtc2    $t4, $11
    sll     $a2, $a2, 16
    sll     $t1, $t1, 16
    gpf     1
    andi    $t2, $t2, 0xFFFF
    sll     $t3, $t3, 16
    or      $t1, $t1, $v1
    sw      $t1, 0x0($v0)
    or      $t3, $t3, $a3
    mfc2    $t4, $9
    mfc2    $t5, $10
    mfc2    $t6, $11
    andi    $t4, $t4, 0xFFFF
    or      $t4, $t4, $a2
    sll     $t5, $t5, 16
    or      $t5, $t5, $t2
    sw      $t4, 0x4($v0)
    sw      $t5, 0x8($v0)
    sw      $t3, 0xC($v0)
    jr      $ra
    sh      $t6, 0x10($v0)
endlabel ScaleMatrix
