.include "macro.inc"
.set noreorder

glabel SetGeomOffset
    sll     $a0, $a0, 16
    sll     $a1, $a1, 16
    ctc2    $a0, $24
    ctc2    $a1, $25
    j       $ra
    nop
endlabel SetGeomOffset
