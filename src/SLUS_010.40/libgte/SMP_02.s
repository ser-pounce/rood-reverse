.include "macro.inc"
.set noreorder

glabel RotTransPers
    lwc2    $0, 0($a0)
    lwc2    $1, 4($a0)
    .nop
    RTPS
    swc2    $14, 0($a1)
    swc2    $8, 0($a2)
    cfc2    $v1, $31
    mfc2    $v0, $19
    sw      $v1, 0($a3)
    j       $ra
    sra     $v0, 2
endlabel RotTransPers
