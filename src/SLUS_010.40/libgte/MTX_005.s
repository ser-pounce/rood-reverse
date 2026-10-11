.include "macro.inc"
.set noreorder

# hasm: temp register usage
# hasm: single-nop gte hazard
glabel ApplyRotMatrix
    lw      $t0, 0($a0)
    lw      $t1, 4($a0)
    mtc2    $t0, $0
    mtc2    $t1, $1
    .nop
    RTV0
    swc2    $9, 0($a1)
    swc2    $10, 4($a1)
    swc2    $11, 8($a1)
    j       $ra
    addu    $v0, $a1, $0
endlabel ApplyRotMatrix
