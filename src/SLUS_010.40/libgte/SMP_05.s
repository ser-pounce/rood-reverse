.include "macro.inc"
.set noreorder

glabel NormalClip
    mtc2    $a0, $12
    mtc2    $a2, $14
    mtc2    $a1, $13
    .nop
    .nop
    NCLIP
    mfc2    $v0, $24
    j       $ra
    nop
endlabel NormalClip
