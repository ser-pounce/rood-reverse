.include "macro.inc"

.set noreorder

glabel _asmNop
    nop
endlabel _asmNop

glabel nop8
    jr         $ra
     nop
endlabel nop8

glabel vs_main_nop9
    jr         $ra
     nop
endlabel vs_main_nop9

glabel vs_main_nop10
    jr         $ra
     nop
endlabel vs_main_nop10

glabel nop11
    jr         $ra
     nop
endlabel nop11

glabel vs_main_memcpy
    srl        $t0, $a2, 4
    beqz       $t0, 1f
     and       $t5, $a2, 0xC
  0:
    lw         $t1, 0x0($a1)
    lw         $t2, 0x4($a1)
    lw         $t3, 0x8($a1)
    lw         $t4, 0xC($a1)
    addu       $t0, -0x1
    sw         $t1, 0x0($a0)
    sw         $t2, 0x4($a0)
    sw         $t3, 0x8($a0)
    sw         $t4, 0xC($a0)
    addu       $a1, 0x10
    bnez       $t0, 0b
     addu      $a0, 0x10
    beqz       $t5, 2f
  1:
     lw        $t1, 0x0($a1)
    addu       $t5, -0x4
    sw         $t1, 0x0($a0)
    addu       $a1, 0x4
    bnez       $t5, 1b
     addu      $a0, 0x4
  2:
    jr         $ra
     nop
endlabel vs_main_memcpy

glabel vs_main_bzero
    and        $t0, $a1, 0xFFFC
    beqz       $t0, 1f
  0:
     sw        $zero, 0x0($a0)
    addu       $t0, -0x4
    bnez       $t0, 0b
     addu      $a0, 0x4
  1:
    jr         $ra
     nop
endlabel vs_main_bzero

glabel nop12
    jr         $ra
     nop
endlabel nop12
