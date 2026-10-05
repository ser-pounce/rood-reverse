.include "macro.inc"
.set noreorder

glabel ApplyMatrixLV
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
    lw      $t0, 0($a1)
    lw      $t2, 8($a1)
    bgez    $t0, 0f
    lw      $t1, 4($a1)
    negu    $t0, $t0
    sra     $t3, $t0, 15
    negu    $t3, $t3
    andi    $t0, 0x7FFF
    b       1f
    negu    $t0, $t0
0:
    sra     $t3, $t0, 15
    andi    $t0, 0x7FFF
1:
    bgez    $t1, 0f
    .nop
    negu    $t1, $t1
    sra     $t4, $t1, 15
    negu    $t4, $t4
    andi    $t1, 0x7FFF
    b       1f
    negu    $t1, $t1
0:
    sra     $t4, $t1, 15
    andi    $t1, 0x7FFF
1:
    bgez    $t2, 0f
    .nop
    negu    $t2, $t2
    sra     $t5, $t2, 15
    negu    $t5, $t5
    andi    $t2, 0x7FFF
    b       1f
    negu    $t2, $t2
0:
    sra     $t5, $t2, 15
    andi    $t2, 0x7FFF
1:
    mtc2    $t3, $9
    mtc2    $t4, $10
    mtc2    $t5, $11
    .nop
    MVMVA   0, 0, 3, 3, 0
    mfc2    $t3, $25
    mfc2    $t4, $26
    mfc2    $t5, $27
    mtc2    $t0, $9
    mtc2    $t1, $10
    mtc2    $t2, $11
    .nop
    MVMVA   1, 0, 3, 3, 0
    bgez    $t3, 0f
    .nop
    negu    $t3, $t3
    sll     $t3, 3
    b       1f
    negu    $t3, $t3
0:
    sll     $t3, 3
1:
    bgez    $t4, 0f
    .nop
    negu    $t4, $t4
    sll     $t4, 3
    b       1f
    negu    $t4, $t4
0:
    sll     $t4, 3
1:
    bgez    $t5, 0f
    .nop
    negu    $t5, $t5
    sll     $t5, 3
    b       1f
    negu    $t5, $t5
0:
    sll     $t5, 3
1:
    mfc2    $t0, $25
    mfc2    $t1, $26
    mfc2    $t2, $27
    addu    $t0, $t3
    addu    $t1, $t4
    addu    $t2, $t5
    sw      $t0, 0($a2)
    sw      $t1, 4($a2)
    sw      $t2, 8($a2)
    j       $ra
    addu    $v0, $a2, $0
endlabel ApplyMatrixLV
