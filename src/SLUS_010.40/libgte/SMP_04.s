.include "macro.inc"
.set noreorder

glabel RotTrans
    lwc2    $0, 0($a0)
    lwc2    $1, 4($a0)
    .nop
    MVMVA   1, 0, 0, 0, 0
    swc2    $25, 0($a1)
    swc2    $26, 4($a1)
    swc2    $27, 8($a1)
    cfc2    $v0, $31
    j       $ra
    sw      $v0, 0($a2)
endlabel RotTrans
