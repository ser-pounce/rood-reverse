.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel __SN_ENTRY_POINT
    lui     $v0, %hi(__ra_temp)
    addiu   $v0, $v0, %lo(__ra_temp)
    lui     $v1, %hi(D_800401A8)
    addiu   $v1, $v1, %lo(D_800401A8)
.L8001F554:
    sw      $zero, 0x0($v0)
    addiu   $v0, $v0, 0x4
    sltu    $at, $v0, $v1
    bnez    $at, .L8001F554
    .nop
    lui     $v0, %hi(_ramsize)
    lw      $v0, %lo(_ramsize)($v0)
    .nop
    addi    $v0, $v0, -0x8
    lui     $t0, %hi(D_80000004)
    or      $sp, $v0, $t0
    lui     $a0, %hi(D_800401A8)
    addiu   $a0, $a0, %lo(D_800401A8)
    sll     $a0, $a0, 3
    srl     $a0, $a0, 3
    lui     $v1, %hi(_stacksize)
    lw      $v1, %lo(_stacksize)($v1)
    .nop
    subu    $a1, $v0, $v1
    subu    $a1, $a1, $a0
    lui     $at, %hi(__heapsize)
    sw      $a1, %lo(__heapsize)($at)
    or      $a0, $a0, $t0
    lui     $at, %hi(__heapbase)
    sw      $a0, %lo(__heapbase)($at)
    lui     $at, %hi(__ra_temp)
    sw      $ra, %lo(__ra_temp)($at)
    lui     $gp, %hi(_gp)
    addiu   $gp, $gp, %lo(_gp)
    addu    $fp, $sp, $zero
    jal     InitHeap
    addi    $a0, $a0, %lo(D_80000004)
    lui     $ra, %hi(__ra_temp)
    lw      $ra, %lo(__ra_temp)($ra)
    .nop
    jal     vs_main_exec
    .nop
    break   0, 1
endlabel __SN_ENTRY_POINT
