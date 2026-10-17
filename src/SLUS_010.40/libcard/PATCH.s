.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: custom register abi
# hasm: saved registers outside frame
glabel _patch_card_info
    lui     $at, %hi(D_8003FED8)
    sw      $ra, %lo(D_8003FED8)($at)
    addiu   $t1, $zero, 0x57
    addiu   $t2, $zero, 0xB0
    jalr    $t2
    .nop
    addiu   $t2, $zero, 0x9
    lw      $v0, 0x16C($v0)
    .nop
    addi    $v1, $v0, 0x1988
    jal     FlushCache
    sw      $zero, 0x0($v1)
    lui     $ra, %hi(D_8003FED8)
    lw      $ra, %lo(D_8003FED8)($ra)
    .nop
    jr      $ra
    .nop
endlabel _patch_card_info

# hasm: custom register abi
glabel func_8002EEF8
    lhu     $t7, 0xA($v1)
    lui     $t0, (0x0 >> 16)
    or      $t8, $t7, $v0
    ori     $t9, $t8, 0x12
    sh      $t9, 0xA($v1)
    addiu   $t0, $zero, 0x28
.L8002EF10:
    addiu   $t0, $t0, -0x1
    bnez    $t0, .L8002EF10
    .nop
    jr      $ra
    .nop
endlabel func_8002EEF8

# hasm: cross-function control flow
# hasm: custom register abi
glabel func_8002EF24
    lw      $v0, 0x1074($v1)
    .nop
    andi    $v0, $v0, 0x80
    beqz    $v0, .L8002EF60
    .nop
.L8002EF38:
    lw      $v0, 0x1044($v1)
    .nop
    andi    $v0, $v0, 0x80
    bnez    $v0, .L8002EF38
    .nop
    lui     $v0, (0x10000 >> 16)
    lw      $v0, -0x2004($v0)
    .nop
    jr      $v0
    .nop
.L8002EF60:
    jr      $ra
    .nop
endlabel func_8002EF24

# hasm: cross-function control flow
glabel func_8002EF68
    lui     $v0, %hi(D_A000DFAC)
    addiu   $v0, $v0, %lo(D_A000DFAC)
    jr      $v0
    .nop
    .nop
    lui     $t0, %hi(D_A000DF80)
    addiu   $t0, $t0, %lo(D_A000DF80)
    jalr    $t0
    .nop
endlabel func_8002EF68
    .nop

# hasm: code patching
# hasm: custom register abi
# hasm: saved registers outside frame
glabel _patch_card
    lui     $at, %hi(D_8003FED8)
    sw      $ra, %lo(D_8003FED8)($at)
    jal     EnterCriticalSection
    .nop
    addiu   $t1, $zero, 0x56
    addiu   $t2, $zero, 0xB0
    jalr    $t2
    .nop
    lw      $v0, 0x18($v0)
    .nop
    lw      $v1, 0x70($v0)
    .nop
    andi    $t1, $v1, 0xFFFF
    sll     $t1, $t1, 16
    lw      $v1, 0x74($v0)
    .nop
    andi    $t2, $v1, 0xFFFF
    addu    $v1, $t1, $t2
    addiu   $v0, $v1, 0x28
    lui     $t2, %hi(func_8002EF68)
    addiu   $t2, $t2, %lo(func_8002EF68)
    lui     $t1, %hi(func_8002EF68 + 0x14)
    addiu   $t1, $t1, %lo(func_8002EF68 + 0x14)
.L8002EFEC:
    lw      $v1, 0x0($t2)
    .nop
    sw      $v1, 0x0($v0)
    addiu   $t2, $t2, 0x4
    bne     $t2, $t1, .L8002EFEC
    addiu   $v0, $v0, 0x4
    lui     $at, (0x10000 >> 16)
    jal     FlushCache
    sw      $v0, -0x2004($at)
    lui     $ra, %hi(D_8003FED8)
    lw      $ra, %lo(D_8003FED8)($ra)
    .nop
    jr      $ra
    .nop
endlabel _patch_card

# hasm: code patching
# hasm: custom register abi
# hasm: saved registers outside frame
glabel _patch_card2
    lui     $at, %hi(D_8003FED8)
    sw      $ra, %lo(D_8003FED8)($at)
    jal     EnterCriticalSection
    .nop
    addiu   $t1, $zero, 0x57
    addiu   $t2, $zero, 0xB0
    jalr    $t2
    .nop
    lw      $v0, 0x16C($v0)
    .nop
    lw      $v1, 0x9C8($v0)
    lui     $t2, %hi(func_8002EF68 + 0x14)
    addiu   $t2, $t2, %lo(func_8002EF68 + 0x14)
    lui     $t1, %hi(_patch_card)
    addiu   $t1, $t1, %lo(_patch_card)
.L8002F060:
    lw      $t0, 0x0($t2)
    .nop
    sw      $t0, 0x9C8($v0)
    addiu   $t2, $t2, 0x4
    bne     $t2, $t1, .L8002F060
    addiu   $v0, $v0, 0x4
    jal     FlushCache
    .nop
    lui     $ra, %hi(D_8003FED8)
    lw      $ra, %lo(D_8003FED8)($ra)
    .nop
    jr      $ra
    .nop
endlabel _patch_card2

# hasm: code patching
glabel _copy_memcard_patch
    ori     $v0, $zero, 0xDF80
    lui     $t2, %hi(func_8002EEF8)
    addiu   $t2, $t2, %lo(func_8002EEF8)
    lui     $t1, %hi(func_8002EF68)
    addiu   $t1, $t1, %lo(func_8002EF68)
.L8002F0A8:
    lw      $v1, 0x0($t2)
    .nop
    sw      $v1, 0x0($v0)
    addiu   $t2, $t2, 0x4
    bne     $t2, $t1, .L8002F0A8
    addiu   $v0, $v0, 0x4
    jr      $ra
    .nop
endlabel _copy_memcard_patch
    .nop
    .nop
    .nop
