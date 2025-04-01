.include "macro.inc"
.set noreorder

glabel CompMatrix
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
    lhu     $t0, 0($a1)
    lw      $t1, 4($a1)
    lw      $t2, 0xC($a1)
    and     $t1, 0xFFFF0000
    or      $t0, $t1
    mtc2    $t0, $0
    mtc2    $t2, $1
    .nop
    MVMVA   1, 0, 0, 3, 0
    lhu     $t0, 2($a1)
    lw      $t1, 8($a1)
    lh      $t2, 0xE($a1)
    sll     $t1, 16
    or      $t0, $t1
    mfc2    $t3, $9
    mfc2    $t4, $10
    mfc2    $t5, $11
    mtc2    $t0, $0
    mtc2    $t2, $1
    .nop
    MVMVA   1, 0, 0, 3, 0
    lhu     $t0, 4($a1)
    lw      $t1, 8($a1)
    lw      $t2, 0x10($a1)
    and     $t1, 0xFFFF0000
    or      $t0, $t1
    mfc2    $t6, $9
    mfc2    $t7, $10
    mfc2    $t8, $11
    mtc2    $t0, $0
    mtc2    $t2, $1
    .nop
    MVMVA   1, 0, 0, 3, 0
    and     $t3, 0xFFFF
    sll     $t6, 16
    or      $t6, $t3
    sw      $t6, 0($a2)
    and     $t5, 0xFFFF
    sll     $t8, 16
    or      $t8, $t5
    sw      $t8, 0xC($a2)
    mfc2    $t0, $9
    mfc2    $t1, $10
    swc2    $11, 0x10($a2)
    lhu     $t5, 0x14($a1)
    lw      $t6, 0x18($a1)
    lw      $t2, 0x1C($a1)
    sll     $t6, 16
    or      $t5, $t6
    mtc2    $t5, $0
    mtc2    $t2, $1
    .nop
    MVMVA   1, 0, 0, 3, 0
    sll     $t4, 16
    and     $t0, 0xFFFF
    or      $t0, $t4
    sw      $t0, 4($a2)
    and     $t7, 0xFFFF
    sll     $t1, 16
    or      $t1, $t7
    sw      $t1, 8($a2)
    mfc2    $t0, $25
    mfc2    $t1, $26
    mfc2    $t2, $27
    lw      $t3, 0x14($a0)
    lw      $t4, 0x18($a0)
    lw      $t5, 0x1C($a0)
    add     $t0, $t3
    add     $t1, $t4
    add     $t2, $t5
    sw      $t0, 0x14($a2)
    sw      $t1, 0x18($a2)
    sw      $t2, 0x1C($a2)
    addu    $v0, $a2, $0
    j $ra
