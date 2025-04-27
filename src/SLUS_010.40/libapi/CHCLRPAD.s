.include "macro.inc"
.set noreorder

.lcomm ra, 4

.text
glabel _remove_ChgclrPAD
    sw      $ra, ra
    jal     EnterCriticalSection
    .nop
    li      $t1, 0x57
    li      $t2, 0xB0
    jalr    $t2
    .nop
    li      $t2, 0x9
    lw      $v0, 0x16C($v0)
    .nop
    add     $v1, $v0, 0x62C
0:
    sw      $zero, 0x0($v1)
    addu    $v1, $v1, 0x4
    addu    $t2, $t2, -0x1
    bnez    $t2, 0b
    .nop
    jal     FlushCache
    .nop
    jal     ExitCriticalSection
    .nop
    lw      $ra, ra
    .nop
    j       $ra
