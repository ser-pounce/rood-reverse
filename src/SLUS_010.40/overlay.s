.include "macro.inc"

.set noreorder

.section .rodata

dlabel vs_overlay_slots
    .word 0x80068800
    .word 0x800F9800
    .word 0x80102800
    .word 0x800F9800
    .word 0x800F9800
enddlabel vs_overlay_slots

.text

glabel vs_overlay_getSp
    addu       $t0, $a0, $zero
    sw         $sp, 0x0($t0)
    jr         $ra
     nop
endlabel vs_overlay_getSp

# Restore the stack pointer saved by vs_overlay_getSp and enter another module
.macro jumpFunc name, target
glabel \name
    addu       $t0, $a0, $zero
    lw         $sp, 0x0($t0)
    j          \target
     nop
endlabel \name
.endm

jumpFunc vs_overlay_jumpToTitle, vs_main_execTitle
jumpFunc vs_overlay_jumpToBattle, vs_battle_exec

glabel vs_overlay_wait
    .nop 4096
    jr         $ra
     nop
endlabel vs_overlay_wait
