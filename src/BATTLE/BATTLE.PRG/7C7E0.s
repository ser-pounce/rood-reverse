.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800E4FE0
    lw      $t0, 0x17C($a0)
    addu    $t9, $ra, $zero
    addu    $t8, $a0, $zero
    addiu   $v0, $zero, 0x1
    lw      $t1, 0x180($t8)
    lh      $a0, 0x4C($t8)
    sb      $a1, 0x1($t8)
    sb      $v0, 0x9($t8)
    lh      $a1, 0x50($t8)
    sll     $t2, $t1, 16
    or      $t2, $t0, $t2
    sw      $t2, 0x158($t8)
    sub     $a0, $t0, $a0 /* handwritten instruction */
    jal     ratan2
    sub     $a1, $t1, $a1 /* handwritten instruction */
    addu    $ra, $t9, $zero
    addu    $a2, $v0, $zero
    addu    $a0, $t8, $zero
    bgez    $zero, func_800E50A0
    addiu   $a1, $zero, 0x1
alabel L800E5030
    lw      $t6, 0x168($a0)
    mult    $a1, $a1
    addu    $t9, $ra, $zero
    addu    $t8, $a0, $zero
    jal     func_800E42E0
    addu    $a0, $t6, $zero
    lh      $t0, 0x4C($t8)
    andi    $a0, $t6, 0xFF
    sll     $a2, $t6, 8
    srl     $a2, $a2, 24
    sll     $a0, $a0, 7
    lh      $t1, 0x4E($t8)
    sll     $a2, $a2, 7
    addiu   $a0, $a0, 0x40
    addiu   $a2, $a2, 0x40
    lh      $t2, 0x50($t8)
    sub     $a0, $a0, $t0 /* handwritten instruction */
    sub     $a1, $v0, $t1 /* handwritten instruction */
    jal     func_800E4660
    sub     $a2, $a2, $t2 /* handwritten instruction */
    mflo    $v1
    addu    $ra, $t9, $zero
    addu    $a0, $t8, $zero
    sltu    $v0, $v0, $v1
    bnez    $v0, func_800DEEFC
    addiu   $a1, $zero, 0x0
    addiu   $a1, $zero, 0x0
    addu    $a2, $zero, $zero
endlabel func_800E4FE0

# hasm: cross-function control flow
glabel func_800E50A0
    lbu     $a3, 0x125($a0)
    lui     $t0, %hi(jtbl_800F1740)
    addiu   $t0, $t0, %lo(jtbl_800F1740)
    sll     $a3, $a3, 1
    addu    $a3, $a3, $a1
    sll     $a3, $a3, 2
    addu    $t0, $t0, $a3
    lw      $t0, 0x0($t0)
    addu    $a1, $a2, $zero
    jr      $t0
    lui     $t1, %hi(D_800F58D4)
    addiu   $t1, $t1, %lo(D_800F58D4)
    lw      $a3, 0x0($t1)
    addiu   $v1, $zero, 0x1
    lui     $a2, %hi(D_800F590C)
    lw      $a2, %lo(D_800F590C)($a2)
.L800E50E0:
    addiu   $a3, $a3, 0x1
    andi    $a3, $a3, 0xF
    sllv    $v1, $v1, $a3
    and     $v0, $a2, $v1
    beqz    $v0, .L800E50E0
    addiu   $v1, $zero, 0x1
    jr      $ra
    sw      $a3, 0x0($t1)
    lui     $a3, (0x1F800374 >> 16)
    sw      $sp, (0x1F800378 & 0xFFFF)($a3)
    jr      $ra
    ori     $sp, $a3, (0x1F800374 & 0xFFFF)
    lui     $a3, (0x1F800378 >> 16)
    lw      $sp, (0x1F800378 & 0xFFFF)($a3)
    jr      $ra
endlabel func_800E50A0

# hasm: cross-function control flow
# hasm: saved registers outside frame
# hasm: temp register usage
glabel func_800E511C
    lui     $a3, %hi(D_800F58B8)
    lw      $a3, %lo(D_800F58B8)($a3)
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    beqz    $a3, L800DB89C
    lui     $s0, %hi(D_800F16BC)
    addiu   $s0, $s0, %lo(D_800F16BC)
    lw      $t0, 0x0($s0)
    lui     $ra, (0x800E513C >> 16)
    beqz    $t0, L800DB89C
    ori     $ra, $ra, (0x800E513C & 0xFFFF)
    jr      $t0
    addiu   $s0, $s0, 0x4
endlabel func_800E511C

# hasm: cross-function control flow
glabel func_800E5154
    addiu   $a3, $zero, 0x1
endlabel func_800E5154

# hasm: cross-function control flow
glabel func_800E5158
    lui     $a1, %hi(D_800F58B8)
    lw      $a1, %lo(D_800F58B8)($a1)
    lui     $a2, %hi(D_800F5878)
    addiu   $a2, $a2, %lo(D_800F5878)
    sll     $v0, $a0, 2
    addu    $a2, $a2, $v0
    lw      $a2, 0x0($a2)
    sltiu   $v0, $a1, 0x1
    sltiu   $v1, $a2, 0x1
    bnez    $a3, .L800E518C
    or      $v0, $v0, $v1
    jr      $ra
    xori    $v0, $v0, 0x1
.L800E518C:
    bnez    $v0, .L800E51C4
    addiu   $v0, $zero, 0x2
    lw      $a2, 0x18C($a2)
    lui     $v1, (0xFF00FF >> 16)
    beqz    $a2, .L800E51C4
    ori     $v1, $v1, (0xFF00FF & 0xFFFF)
    lw      $a0, 0x64($a2)
    lw      $a1, 0x168($a2)
    lw      $a0, 0x0($a0)
    and     $a1, $a1, $v1
    and     $a0, $a0, $v1
    beq     $a0, $a1, .L800E51C4
    addiu   $v0, $zero, 0x0
    addiu   $v0, $zero, 0x1
.L800E51C4:
    jr      $ra
endlabel func_800E5158

glabel func_800E51C8
    lui     $v1, (0x800F5878 >> 16)
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    addu    $s0, $a0, $zero
    addu    $s1, $a1, $zero
    ori     $a2, $v1, (0x800F5878 & 0xFFFF)
    sll     $v0, $s0, 2
    addu    $a2, $a2, $v0
    lw      $a1, 0x0($a2)
    addu    $a0, $s1, $zero
    jal     vs_main_memcpy
    addiu   $a2, $zero, 0x484
    sb      $s0, 0x88($s1)
    addiu   $v0, $zero, 0x140
    sh      $v0, 0xB0($s1)
    addiu   $v0, $zero, 0x3
    sb      $v0, 0xB2($s1)
    sw      $zero, 0x190($s1)
    sb      $zero, 0x19A($s1)
    addiu   $v0, $zero, 0x3
    sb      $v0, 0x29($s1)
    addiu   $v0, $zero, 0x1
    sb      $v0, 0x23($s1)
.L800E522C:
    lw      $ra, 0x18($sp)
    lw      $s0, 0x10($sp)
    lw      $s1, 0x14($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800E51C8

# hasm: cross-function control flow
# hasm: saved registers outside frame
glabel func_800E5240
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    jal     func_800E5158
    addu    $a3, $zero, $zero
    beqz    $v0, .L800E522C
    lui     $ra, (0x800E522C >> 16)
    lw      $a0, 0x18C($a2)
    addu    $s0, $a2, $zero
    beqz    $a0, .L800E522C
    ori     $ra, $ra, (0x800E522C & 0xFFFF)
    sw      $zero, 0x18C($s0)
    j       vs_main_freeHeapR
    addiu   $a1, $zero, 0x7
endlabel func_800E5240

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800E527C
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x18($sp)
    sw      $s1, 0x14($sp)
    sll     $a2, $a2, 16
    or      $s1, $a2, $a1
    jal     func_800E5158
    addu    $a3, $zero, $zero
    beqz    $v0, .L800E522C
    sw      $s0, 0x10($sp)
    addu    $s0, $a2, $zero
    jal     func_800D82CC
    addu    $a0, $s0, $zero
    jal     func_800D821C
    addu    $a0, $s0, $zero
    jal     func_800DBF00
    addu    $a0, $s0, $zero
    lw      $a1, 0x18C($s0)
    lbu     $a0, 0x88($s0)
    bnez    $a1, .L800E52F4
    addu    $a2, $zero, $zero
    addiu   $a1, $zero, 0x7
    jal     vs_main_allocHeapR
    addiu   $a0, $zero, 0x484
    beqz    $v0, .L800E522C
    addiu   $a1, $zero, 0x484
    sw      $v0, 0x18C($s0)
    jal     func_800E4288
    addu    $a0, $v0, $zero
    lbu     $a0, 0x88($s0)
    addu    $s0, $v0, $zero
.L800E52F4:
    jal     func_800E51C8
    addu    $a1, $s0, $zero
    sw      $s1, 0x160($s0)
    bgez    $zero, .L800E522C
    addiu   $v0, $zero, 0x1
endlabel func_800E527C

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: cross-function control flow
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800E5308
    addiu   $sp, $sp, -0x30
    sw      $ra, 0x18($sp)
    sw      $s0, 0x10($sp)
    sw      $s1, 0x14($sp)
    jal     func_800E65DC
    sw      $s2, 0x1C($sp)
    lui     $a3, (0x1F800378 >> 16)
    sw      $sp, (0x1F800378 & 0xFFFF)($a3)
    addiu   $sp, $a3, %lo(D_1F800374)
    lui     $s0, %hi(vs_battle_actors)
    lw      $s0, %lo(vs_battle_actors)($s0)
    lui     $a3, (0x1F80037C >> 16)
.L800E5338:
    lbu     $t0, 0x8($s0)
    lw      $t1, 0x4($s0)
    andi    $t0, $t0, 0xC0
    bnez    $t0, .L800E54F0
    sll     $t1, $t1, 2
    addu    $s2, $a3, $t1
    lw      $s2, (0x1F80037C & 0xFFFF)($s2)
    jal     func_800E45B4
    lw      $s2, 0x18C($s2)
    sw      $v0, 0x3FC($a3)
    beqz    $s2, .L800E54F0
    lbu     $t3, 0x3($s0)
    sb      $zero, 0x19A($s2)
    lhu     $t5, 0x156($s2)
    lw      $t4, 0x190($s2)
    beqz    $t5, .L800E5380
    srl     $t2, $t4, 5
    addi    $t5, $t5, -0x1 /* handwritten instruction */
.L800E5380:
    sh      $t5, 0x156($s2)
    andi    $t2, $t2, 0x7F
    beqz    $t2, .L800E5394
    andi    $t3, $t3, 0xFC
    addi    $t2, $t2, -0x1 /* handwritten instruction */
.L800E5394:
    addiu   $v0, $zero, 0x1
    sb      $v0, 0x6($s2)
    sb      $zero, 0x1($s2)
    addiu   $v0, $zero, 0x10
    sb      $v0, 0x15C($s2)
    sb      $zero, 0x2($s2)
    sb      $zero, 0x3($s2)
    lw      $t1, 0x4($s0)
    lui     $t0, %hi(D_800F4538)
    addiu   $t0, $t0, %lo(D_800F4538)
    sll     $t1, $t1, 2
    addu    $t0, $t0, $t1
    lw      $t0, 0x0($t0)
    sb      $t3, 0x3($s0)
    addi    $v0, $zero, -0xFE1 /* handwritten instruction */
    and     $t4, $t4, $v0
    sll     $t2, $t2, 5
    or      $t4, $t4, $t2
    sw      $t4, 0x190($s2)
    lw      $t2, 0x5C($t0)
    lw      $t3, 0x1C($t0)
    lw      $t4, 0x20($t0)
    sw      $t2, 0x34($s2)
    sw      $t3, 0x4C($s2)
    sw      $t4, 0x50($s2)
    lui     $t6, %hi(D_800F58B8)
    lw      $t6, %lo(D_800F58B8)($t6)
    sll     $t5, $t2, 8
    srl     $t5, $t5, 24
    andi    $t2, $t2, 0xFF
    sll     $t5, $t5, 6
    sll     $t2, $t2, 1
    addu    $t2, $t2, $t5
    addu    $t6, $t2, $t6
    lhu     $t6, 0x0($t6)
    andi    $t2, $t3, 0xFFFF
    andi    $t4, $t4, 0xFFFF
    srl     $t3, $t2, 6
    srl     $t5, $t4, 6
    sll     $t5, $t5, 16
    or      $t3, $t3, $t5
    sw      $t3, 0x120($s2)
    andi    $t6, $t6, 0xF
    lbu     $v1, 0x125($s2)
    sb      $t6, 0x132($s2)
    sb      $t6, 0x154($s2)
    addiu   $v0, $zero, 0x0
    sw      $zero, 0x3D0($a3)
    bne     $v1, $v0, .L800E5490
    lw      $t3, 0x160($s2)
    addu    $a1, $zero, $zero
    andi    $a0, $t3, 0xFFFF
    srl     $a2, $t3, 16
    sub     $a0, $a0, $t2 /* handwritten instruction */
    jal     func_800E4660
    sub     $a2, $a2, $t4 /* handwritten instruction */
    slti    $v0, $v0, 0x400
    bnez    $v0, .L800E54AC
    addu    $a0, $s2, $zero
    lui     $ra, %hi(.L800E54F0)
    addiu   $ra, $ra, %lo(.L800E54F0)
    bgez    $zero, .L800E550C
    addu    $a1, $zero, $zero
.L800E5490:
    lw      $a0, 0x168($s2)
    lw      $a1, 0x34($s2)
    lui     $v0, (0xFF00FF >> 16)
    ori     $v0, $v0, (0xFF00FF & 0xFFFF)
    and     $a0, $a0, $v0
    and     $a1, $a1, $v0
    bne     $a0, $a1, .L800E54C8
.L800E54AC:
    addiu   $a1, $zero, 0x0
    jal     func_800DEEFC
    addu    $a0, $s2, $zero
    lbu     $a0, 0x88($s2)
    lui     $ra, %hi(.L800E54F0)
    addiu   $ra, $ra, %lo(.L800E54F0)
    bgez    $zero, func_800E5240
.L800E54C8:
    srl     $a1, $t3, 23
    andi    $a0, $t3, 0xFFFF
    srl     $a0, $a0, 7
    sll     $a1, $a1, 16
    or      $a0, $a0, $a1
    sw      $a0, 0x168($s2)
    addu    $a0, $s2, $zero
    addiu   $a1, $zero, 0x0
    jal     func_800E50A0
    addu    $a2, $zero, $zero
.L800E54F0:
    lw      $s0, 0x0($s0)
    lui     $ra, (0x800DB898 >> 16)
    bnez    $s0, .L800E5338
    lui     $a3, (0x1F800378 >> 16)
    lw      $sp, (0x1F800378 & 0xFFFF)($a3)
    bgez    $zero, func_800D9538
    ori     $ra, $ra, (0x800DB898 & 0xFFFF)
.L800E550C:
    lbu     $t0, 0x19B($a0)
    addu    $t9, $ra, $zero
    addu    $t8, $a0, $zero
    lw      $t1, 0x160($a0)
    bnez    $t0, L800DF8A4
    srl     $t2, $t1, 16
    andi    $t1, $t1, 0xFFFF
    sw      $t1, 0x17C($a0)
    sw      $t2, 0x180($a0)
    srl     $t3, $t1, 7
    srl     $t4, $t2, 7
    sll     $t4, $t4, 16
    or      $t3, $t3, $t4
    sw      $t3, 0x168($a0)
    lh      $a0, 0x4C($t8)
    lh      $a1, 0x50($t8)
    sub     $a0, $t1, $a0 /* handwritten instruction */
    jal     ratan2
    sub     $a1, $t2, $a1 /* handwritten instruction */
    addu    $ra, $t9, $zero
    addu    $a1, $v0, $zero
    bgez    $zero, func_800E19FC
    addu    $a0, $t8, $zero
endlabel func_800E5308
