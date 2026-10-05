.include "macro.inc"
.set noreorder

glabel ApplyMatrixSV
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
    MVMVA   1, 0, 0, 3, 0
    mfc2    $t0, $9
    mfc2    $t1, $10
    mfc2    $t2, $11
    sh      $t0, 0($a2)
    sh      $t1, 2($a2)
    sh      $t2, 4($a2)
    j       $ra
    addu    $v0, $a2, $0
endlabel ApplyMatrixSV
