.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel _ExitCard
    lui     $at, %hi(D_8003FEE8)
    sw      $ra, %lo(D_8003FEE8)($at)
    jal     EnterCriticalSection
    .nop
    addiu   $t1, $zero, 0x56
    addiu   $t2, $zero, 0xB0
    jalr    $t2
    .nop
    lw      $v0, 0x18($v0)
    lui     $t2, %hi(D_8002F144)
    addiu   $t2, $t2, %lo(D_8002F144)
    lui     $t1, %hi(D_8002F150)
    addiu   $t1, $t1, %lo(D_8002F150)
.L8002F108:
    lw      $v1, 0x0($t2)
    .nop
    sw      $v1, 0x70($v0)
    addiu   $t2, $t2, 0x4
    bne     $t2, $t1, .L8002F108
    addiu   $v0, $v0, 0x4
    jal     FlushCache
    .nop
    jal     ExitCriticalSection
    .nop
    lui     $ra, %hi(D_8003FEE8)
    lw      $ra, %lo(D_8003FEE8)($ra)
    .nop
    jr      $ra
    .nop
endlabel _ExitCard

# Copied into the BIOS table by _ExitCard
dlabel D_8002F144
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
dlabel D_8002F150
    .word 0x00000000
