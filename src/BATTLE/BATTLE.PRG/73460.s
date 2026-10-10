.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800DBC60
    lbu     $v0, 0x13($a0)
    lw      $v1, 0xC($a1)
    bnez    $v0, .L800DBCA4
    lw      $v0, 0x4($a1)
    lui     $t1, %hi(D_800F45E0)
    addiu   $t1, $t1, %lo(D_800F45E0)
    lw      $t0, 0x10($a1)
    andi    $v1, $v1, 0xF
    srl     $t0, $t0, 4
    andi    $t0, $t0, 0x1
    beqz    $t0, .L800DBCAC
    sll     $v1, $v1, 2
    addu    $v1, $v1, $t1
    lw      $v1, 0x0($v1)
    nop
    bnez    $v1, .L800DBCAC
    nop
.L800DBCA4:
    jr      $ra
    addiu   $v0, $zero, 0x1
.L800DBCAC:
    jr      $ra
    addu    $v0, $zero, $zero
endlabel func_800DBC60

# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800DBCB4
    lhu     $t0, 0x90($a0)
    addu    $t9, $ra, $zero
    bnez    $t0, .L800DBCAC
    nop
    jal     func_800DBC60
    nop
    addu    $ra, $t9, $zero
    beqz    $v0, .L800DBCA4
    nop
    lbu     $t0, 0x13F($a0)
    nop
    bnez    $t0, .L800DBCAC
    nop
    bgez    $zero, .L800DBCA4
endlabel func_800DBCB4

# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800DBCEC
    lui     $t8, %hi(vs_battle_actors)
    addiu   $t8, $t8, %lo(vs_battle_actors)
    mtc2    $a0, $2
    mtc2    $a1, $4
.L800DBCFC:
    beqz    $t8, .L800DBCA4
    mfc2    $a0, $2
    mfc2    $a1, $4
    lw      $t1, 0x4($t8)
    addu    $t9, $ra, $zero
    sll     $t1, $t1, 2
    addiu   $v0, $t1, 0x1A4
    addu    $v0, $a0, $v0
    lw      $v0, 0x0($v0)
    nop
    srl     $v0, $v0, 6
    andi    $v0, $v0, 0x3
    slti    $v0, $v0, 0x3
    bnez    $v0, .L800DBD74
    lui     $v0, %hi(D_800F4538)
    addiu   $v0, $v0, %lo(D_800F4538)
    addu    $v0, $v0, $t1
    lw      $v0, 0x0($v0)
    lui     $v1, %hi(D_800F45E0)
    addiu   $v1, $v1, %lo(D_800F45E0)
    sll     $a1, $a1, 2
    addu    $v1, $v1, $a1
    lw      $v1, 0x0($v1)
    lw      $a0, 0x5C($v0)
    jal     func_800E45F4
    lw      $a1, 0x5C($v1)
    addu    $ra, $t9, $zero
    slti    $v0, $v0, 0x3
    bnez    $v0, .L800DBCAC
    mfc2    $a0, $2
.L800DBD74:
    lw      $t8, 0x0($t8)
    bgez    $zero, .L800DBCFC
    nop
endlabel func_800DBCEC
