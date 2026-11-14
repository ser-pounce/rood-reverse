.include "macro.inc"
.set noreorder

# hasm: temp register usage
glabel SetTransMatrix
    lw      $t0, 20($a0)
    lw      $t1, 24($a0)
    lw      $t2, 28($a0)
    ctc2    $t0, $5
    ctc2    $t1, $6
    ctc2    $t2, $7
    j       $ra
    nop
endlabel SetTransMatrix
