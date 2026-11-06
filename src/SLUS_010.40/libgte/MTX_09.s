.include "macro.inc"
.set noreorder

# hasm: temp register usage
glabel SetRotMatrix
    lw      $t0, 0($a0)
    lw      $t1, 4($a0)
    lw      $t2, 8($a0)
    lw      $t3, 12($a0)
    lw      $t4, 16($a0)
    ctc2    $t0, $0
    ctc2    $t1, $1
    ctc2    $t2, $2
    ctc2    $t3, $3
    ctc2    $t4, $4
    j       $ra
    nop
endlabel SetRotMatrix
