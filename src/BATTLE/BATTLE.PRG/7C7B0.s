.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800E4FB0
    lw      $t0, 0x54($a0)
    sll     $a1, $a1, 2
    lbu     $t0, 0x9($t0)
    addiu   $v0, $zero, 0xA
    bne     $t0, $v0, .L800E4FCC
    addu    $a1, $a0, $a1
    addiu   $a2, $a2, 0x80
.L800E4FCC:
    mult    $v0, $v0
    lw      $t0, 0x1E4($a1)
    mflo    $v0
    jr      $ra
    sltu    $v0, $v0, $t0
endlabel func_800E4FB0
