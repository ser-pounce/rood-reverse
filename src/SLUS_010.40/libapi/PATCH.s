.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel EnablePAD
    lui     $t1, %hi(jtbl_8003FEC0)
    lw      $t1, %lo(jtbl_8003FEC0)($t1)
    .nop
    jr      $t1
    .nop
endlabel EnablePAD

glabel DisablePAD
    lui     $t1, %hi(jtbl_8003FEC4)
    lw      $t1, %lo(jtbl_8003FEC4)($t1)
    .nop
    jr      $t1
    .nop
endlabel DisablePAD

glabel _patch_pad
    lui     $at, %hi(D_8003FEB8)
    sw      $ra, %lo(D_8003FEB8)($at)
    jal     EnterCriticalSection
    .nop
    addiu   $t1, $zero, 0x57
    addiu   $t2, $zero, 0xB0
    jalr    $t2
    .nop
    lw      $v0, 0x16C($v0)
    addiu   $t1, $zero, 0xB
    addi    $v1, $v0, 0x884
    lui     $at, %hi(jtbl_8003FEC0)
    sw      $v1, %lo(jtbl_8003FEC0)($at)
    addi    $v1, $v0, 0x894
    lui     $at, %hi(jtbl_8003FEC4)
    sw      $v1, %lo(jtbl_8003FEC4)($at)
.L8002EDDC:
    sw      $zero, 0x594($v0)
    addiu   $v0, $v0, 0x4
    addiu   $t1, $t1, -0x1
    bnez    $t1, .L8002EDDC
    .nop
    jal     FlushCache
    .nop
    lui     $ra, %hi(D_8003FEB8)
    lw      $ra, %lo(D_8003FEB8)($ra)
    .nop
    jr      $ra
    .nop
endlabel _patch_pad
    .nop
    .nop
