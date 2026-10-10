.include "macro.inc"
.set noreorder

# hasm: temp register usage
glabel TransMatrix
    lw      $t0, 0($a1)
    lw      $t1, 4($a1)
    lw      $t2, 8($a1)
    sw      $t0, 0x14($a0)
    sw      $t1, 0x18($a0)
    sw      $t2, 0x1C($a0)
    j       $ra
    addu    $v0, $a0, $0
endlabel TransMatrix
