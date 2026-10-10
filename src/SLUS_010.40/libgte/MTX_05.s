.include "macro.inc"
.set noreorder

# hasm: temp register usage
# hasm: single-nop gte hazard
glabel ApplyMatrix
    lw      $t0, 0($a0)
    lw      $t1, 4($a0)
    lw      $t2, 8($a0)
    lw      $t3, 0xC($a0)
    lw      $t4, 0x10($a0)
    ctc2    $t0, $0
    ctc2    $t1, $1
    ctc2    $t2, $2
    ctc2    $t3, $3
    ctc2    $t4, $4
    lwc2    $0, 0($a1)
    lwc2    $1, 4($a1)
    .nop
    RTV0
    swc2    $25, 0($a2)
    swc2    $26, 4($a2)
    swc2    $27, 8($a2)
    j       $ra
    addu    $v0, $a2, $0
endlabel ApplyMatrix
