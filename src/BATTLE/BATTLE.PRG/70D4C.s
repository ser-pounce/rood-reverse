.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
glabel func_800D954C
    lw      $t0, 0x38($a0)
    addu    $t9, $ra, $zero
    addu    $t8, $a0, $zero
    lui     $a0, (0xFFFF00FF >> 16)
    ori     $a0, $a0, (0xFFFF00FF & 0xFFFF)
    and     $t1, $a1, $a0
    lui     $t2, (0x1F8003DC >> 16)
    lbu     $t3, (0x1F8003DD & 0xFFFF)($t2)
    lbu     $t2, (0x1F8003DC & 0xFFFF)($t2)
    sll     $t1, $t1, 8
    sll     $t0, $t0, 8
    beq     $t0, $t1, .L800D96B0
    andi    $t0, $a1, 0xFF
    sll     $t1, $a1, 8
    srl     $t1, $t1, 24
    addu    $a0, $t0, $zero
    jal     func_800E42EC
    addu    $a1, $t1, $zero
    sll     $a0, $t0, 7
    sll     $a1, $t1, 7
    addi    $a0, $a0, 0x40 /* handwritten instruction */
    addi    $a1, $a1, 0x40 /* handwritten instruction */
    lbu     $a2, 0x32($t8)
    slt     $t2, $t0, $t2
    slt     $t3, $t1, $t3
    and     $t2, $t2, $t3
    beqz    $t2, .L800D96B0
    lui     $a3, (0x1F8003C0 >> 16)
    lw      $v1, (0x1F8003C0 & 0xFFFF)($a3)
    sll     $t1, $t1, 6
    sll     $t0, $t0, 1
    addu    $v1, $v1, $t0
    addu    $v1, $v1, $t1
    lhu     $v1, 0x0($v1)
    sll     $a2, $a2, 8
    ori     $a2, $a2, 0x80B0
    and     $a2, $v1, $a2
    bnez    $a2, .L800D96B0
    lui     $t0, %hi(vs_battle_actors)
    lw      $t0, %lo(vs_battle_actors)($t0)
    lbu     $t1, 0x88($t8)
    lhu     $t2, 0x94($t8)
    lui     $t7, %hi(D_800F4538)
    addiu   $t7, $t7, %lo(D_800F4538)
    sll     $t1, $t1, 2
.L800D9600:
    lw      $v1, 0x4($t0)
    lui     $a3, (0x1F80037C >> 16)
    sll     $v1, $v1, 2
    addu    $a2, $a3, $v1
    beq     $v1, $t1, .L800D9698
    addu    $t3, $t7, $v1
    lw      $t3, 0x0($t3)
    lw      $a2, (0x1F80037C & 0xFFFF)($a2)
    lbu     $t6, 0xA($t3)
    lhu     $t5, 0x94($a2)
    andi    $t6, $t6, 0x1F
    beqz    $v1, .L800D9648
    addiu   $a3, $zero, 0x80
    beqz    $t6, .L800D9648
    nop
    lw      $t4, 0x174($a2)
    bgez    $zero, .L800D9650
    lhu     $t6, 0x178($a2)
.L800D9648:
    lw      $t4, 0x1C($t3)
    lhu     $t6, 0x20($t3)
.L800D9650:
    andi    $v1, $t4, 0xFFFF
    sra     $t4, $t4, 16
    sub     $v1, $v1, $a0 /* handwritten instruction */
    bgez    $v1, .L800D9668
    sub     $t4, $t4, $v0 /* handwritten instruction */
    neg     $v1, $v1 /* handwritten instruction */
.L800D9668:
    bgez    $t4, .L800D9674
    sub     $t6, $t6, $a1 /* handwritten instruction */
    neg     $t4, $t4 /* handwritten instruction */
.L800D9674:
    bgez    $t6, .L800D9680
    add     $t5, $t5, $t2 /* handwritten instruction */
    neg     $t6, $t6 /* handwritten instruction */
.L800D9680:
    slt     $v1, $t5, $v1
    slt     $t4, $a3, $t4
    slt     $t6, $t5, $t6
    or      $t4, $t4, $t6
    or      $v1, $v1, $t4
    beqz    $v1, .L800D96B8
.L800D9698:
    lw      $t0, 0x0($t0)
    nop
    bnez    $t0, .L800D9600
    nop
    bgez    $zero, .L800D96BC
    addiu   $v0, $zero, 0x1
.L800D96B0:
    bgez    $zero, .L800D96BC
    addu    $v0, $zero, $zero
.L800D96B8:
    addi    $v0, $zero, -0x1 /* handwritten instruction */
.L800D96BC:
    addu    $ra, $t9, $zero
    jr      $ra
    nop
endlabel func_800D954C

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: custom register abi
glabel func_800D96C8
    addiu   $sp, $sp, -0x20
    sw      $s0, 0x0($sp)
    sw      $s1, 0x4($sp)
    sw      $s2, 0x8($sp)
    sw      $ra, 0xC($sp)
    sw      $s3, 0x10($sp)
    sw      $s4, 0x14($sp)
    sw      $s5, 0x18($sp)
    sw      $s6, 0x1C($sp)
    lbu     $t0, 0x7($a0)
    addu    $s0, $a0, $zero
    bnez    $t0, .L800D98B4
    lui     $a0, (0x1F8003C0 >> 16)
    lw      $t1, (0x1F8003DC & 0xFFFF)($a0)
    andi    $s1, $a2, 0xFF
    sll     $s2, $a2, 8
    srl     $s2, $s2, 24
    andi    $t0, $t1, 0xFF
    srl     $t1, $t1, 8
    andi    $t1, $t1, 0xFF
    slt     $v0, $s1, $t0
    slt     $v1, $s2, $t1
    and     $v0, $v0, $v1
    beqz    $v0, .L800D98B4
    lw      $t0, (0x1F8003C0 & 0xFFFF)($a0)
    sll     $t1, $s2, 6
    sll     $t2, $s1, 1
    add     $t1, $t1, $t2 /* handwritten instruction */
    add     $t1, $t1, $t0 /* handwritten instruction */
    lhu     $t1, 0x0($t1)
    lbu     $t2, 0x2($s0)
    andi    $t4, $t1, 0x30
    bnez    $t4, .L800D98B4
    lbu     $t3, 0x154($s0)
    bnez    $t2, .L800D9768
    andi    $t1, $t1, 0xF
    bne     $t1, $t3, .L800D975C
.L800D975C:
    lbu     $t3, 0x132($s0)
    nop
    bne     $t1, $t3, .L800D98B4
.L800D9768:
    andi    $a0, $a1, 0xFF
    sll     $a1, $a1, 8
    srl     $a1, $a1, 24
    sub     $s3, $s1, $a0 /* handwritten instruction */
    jal     func_800E42EC
    sub     $s5, $s2, $a1 /* handwritten instruction */
    addu    $t6, $v0, $zero
    addu    $a0, $s1, $zero
    jal     func_800E42EC
    addu    $a1, $s2, $zero
    addu    $s6, $v0, $zero
    bgez    $s3, .L800D97A0
    sub     $s4, $v0, $t6 /* handwritten instruction */
    neg     $s5, $s5 /* handwritten instruction */
.L800D97A0:
    bgez    $s5, .L800D97AC
    slti    $t0, $s3, 0x2
    neg     $s5, $s5 /* handwritten instruction */
.L800D97AC:
    slti    $t1, $s5, 0x2
    and     $t0, $t0, $t1
    lbu     $t3, 0x3($s0)
    beqz    $t0, .L800D97D8
    addu    $a0, $s0, $zero
    jal     func_800D98E8
    addu    $a1, $a3, $zero
    bnez    $v0, .L800D98B4
    slti    $t1, $s4, 0x1
    or      $t1, $t3, $t1
    beqz    $t1, .L800D9818
.L800D97D8:
    lbu     $t1, 0xB2($s0)
    addu    $t0, $s3, $s5
    slt     $t0, $t1, $t0
    bnez    $t0, .L800D98B4
    lbu     $a0, 0x15E($s0)
    lhu     $t4, 0xB0($s0)
    andi    $a0, $a0, 0xF8
    beqz    $a0, .L800D9800
    nop
    addiu   $t4, $zero, 0x2000
.L800D9800:
    neg     $t2, $t4 /* handwritten instruction */
    slt     $t0, $t4, $s4
    and     $t0, $t0, $t3
    bnez    $t0, .L800D98B4
    slt     $t2, $s4, $t2
    bnez    $t2, .L800D98B4
.L800D9818:
    lbu     $t0, 0xE5($s0)
    lbu     $t1, 0x5($s0)
    sll     $t0, $t0, 2
    lbu     $t2, 0x89($s0)
    beqz    $t1, .L800D98AC
    addiu   $v0, $zero, 0x1
    bne     $v0, $t2, .L800D987C
    lw      $s3, 0xDC($s0)
    lui     $v0, %hi(D_800F4538)
    addiu   $v0, $v0, %lo(D_800F4538)
    addu    $v0, $v0, $t0
    lhu     $t0, 0x1C($v0)
    sll     $a0, $s1, 7
    addi    $a0, $a0, 0x40 /* handwritten instruction */
    addi    $s3, $s3, -0x60 /* handwritten instruction */
    mult    $s3, $s3
    lhu     $t1, 0x20($v0)
    sll     $a1, $s2, 7
    addi    $a1, $a1, 0x40 /* handwritten instruction */
    sub     $a0, $a0, $t0 /* handwritten instruction */
    jal     func_800E4660
    sub     $a1, $a1, $t1 /* handwritten instruction */
    mflo    $v1
    slt     $v0, $v0, $v1
    bnez    $v0, .L800D98BC
.L800D987C:
    lw      $s4, 0x168($s0)
    lw      $a0, 0x34($s0)
    jal     func_800E45F4
    addu    $a1, $s4, $zero
    addu    $a1, $s4, $zero
    addu    $s5, $v0, $zero
    addu    $t0, $s1, $zero
    jal     func_800E4604
    addu    $t1, $s2, $zero
    slt     $t0, $v0, $s5
    beqz    $t0, .L800D98C0
    addu    $v0, $zero, $zero
.L800D98AC:
    bgez    $zero, .L800D98C0
    addiu   $v0, $zero, 0x1
.L800D98B4:
    bgez    $zero, .L800D98C0
    addu    $v0, $zero, $zero
.L800D98BC:
    addi    $v0, $zero, -0x1 /* handwritten instruction */
.L800D98C0:
    lw      $s0, 0x0($sp)
    lw      $s1, 0x4($sp)
    lw      $s2, 0x8($sp)
    lw      $ra, 0xC($sp)
    lw      $s3, 0x10($sp)
    lw      $s4, 0x14($sp)
    lw      $s5, 0x18($sp)
    lw      $s6, 0x1C($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800D96C8

# hasm: trapping arithmetic
# hasm: unconditional b branch
# hasm: custom register abi
# hasm: saved registers outside frame
# hasm: reserved register usage
glabel func_800D98E8
    lui     $a3, (0x1F8003D4 >> 16)
    lbu     $v1, (0x1F8003D2 & 0xFFFF)($a3)
    addu    $t7, $ra, $zero
    srlv    $v1, $v1, $a1
    andi    $v1, $v1, 0x1
    beqz    $v1, .L800D990C
    addu    $t0, $a3, $a1
    lbu     $v0, (0x1F8003D4 & 0xFFFF)($t0)
    jr      $ra
.L800D990C:
    addu    $t1, $a3, $a1
    lbu     $t1, 0x3EC($t1)
    lbu     $t0, 0xB3($a0)
    sll     $t2, $t1, 26
    sra     $t2, $t2, 30
    sll     $t1, $t1, 30
    sra     $t1, $t1, 30
    mult    $t0, $t1
    lhu     $t3, 0x4C($a0)
    mflo    $t1
    lhu     $t4, 0x50($a0)
    add     $t3, $t3, $t1 /* handwritten instruction */
    mult    $t0, $t2
    lw      $v0, 0x34($a0)
    lbu     $v1, 0x3DC($a3)
    mflo    $t2
    andi    $t5, $v0, 0xFF
    sll     $t6, $v0, 8
    srl     $t6, $t6, 24
    add     $t4, $t4, $t2 /* handwritten instruction */
    srl     $t1, $t3, 7
    srl     $t2, $t4, 7
    sub     $t1, $t1, $t5 /* handwritten instruction */
    sub     $t2, $t2, $t6 /* handwritten instruction */
    addi    $t1, $t1, 0x1 /* handwritten instruction */
    addi    $t2, $t2, 0x1 /* handwritten instruction */
    addiu   $v0, $zero, 0x1
    sll     $t2, $t2, 2
    add     $t2, $t2, $t1 /* handwritten instruction */
    lb      $t0, 0x3E0($a3)
    lw      $a2, 0x3F4($a3)
    addu    $t8, $a0, $zero
    bltz    $t0, .L800D99D0
    addu    $t9, $a1, $zero
    beqz    $a2, .L800D99C0
    mult    $v1, $t6
    lw      $v0, 0x3C4($a3)
    mflo    $v1
    addu    $v0, $v1, $v0
    addu    $v0, $v0, $t5
    lbu     $v0, 0x0($v0)
    nop
    srlv    $v0, $v0, $t0
    bgez    $zero, .L800D99D0
    andi    $v0, $v0, 0x1
.L800D99C0:
    addu    $a1, $t0, $zero
    jal     func_800E4690
    lw      $a0, 0x34($a0)
    addu    $a0, $t8, $zero
.L800D99D0:
    bnez    $v0, .L800D99E8
    addu    $a1, $t4, $zero
    jal     func_800E42D4
    addu    $a0, $t3, $zero
    bgez    $zero, .L800D99EC
    addu    $a0, $t8, $zero
.L800D99E8:
    lh      $v0, 0x4E($a0)
.L800D99EC:
    lui     $a3, (0x1F8003EC >> 16)
    lui     $t0, %hi(vs_battle_actors)
    addiu   $t0, $t0, %lo(vs_battle_actors)
    lw      $t0, 0x0($t0)
    lbu     $a1, 0x88($a0)
    lui     $a2, %hi(D_800F4538)
    addiu   $a2, $a2, %lo(D_800F4538)
    addu    $t5, $a3, $t9
    lbu     $t5, (0x1F8003EC & 0xFFFF)($t5)
    addu    $ra, $t7, $zero
    sll     $t6, $t5, 26
    sra     $t6, $t6, 30
    sll     $t5, $t5, 30
    sra     $t5, $t5, 30
    lhu     $a3, 0xB8($a0)
    lhu     $t7, 0x94($a0)
    sll     $a3, $a3, 16
    or      $t7, $t7, $a3
.L800D9A34:
    lw      $t1, 0x4($t0)
    lui     $v1, (0x1F800000 >> 16)
    beq     $a1, $t1, .L800D9B34
    sll     $t2, $t1, 2
    add     $t8, $t2, $a2 /* handwritten instruction */
    lw      $t8, 0x0($t8)
    add     $t2, $t2, $v1 /* handwritten instruction */
    lbu     $v1, 0xA($t8)
    lw      $t2, 0x37C($t2)
    andi    $v1, $v1, 0x1F
    beqz    $t1, .L800D9A78
    nop
    beqz    $v1, .L800D9A78
    nop
    lw      $v1, 0x174($t2)
    bgez    $zero, .L800D9A80
    lhu     $at, 0x178($t2)
.L800D9A78:
    lw      $v1, 0x1C($t8)
    lhu     $at, 0x20($t8)
.L800D9A80:
    andi    $a0, $v1, 0xFFFF
    sra     $a3, $v1, 16
    sub     $a0, $a0, $t3 /* handwritten instruction */
    sub     $a3, $a3, $v0 /* handwritten instruction */
    sub     $at, $at, $t4 /* handwritten instruction */
    blez    $t5, .L800D9AA4
    nop
    bltz    $a0, .L800D9B34
    nop
.L800D9AA4:
    bgez    $t5, .L800D9AB4
    nop
    bgtz    $a0, .L800D9B34
    nop
.L800D9AB4:
    blez    $t6, .L800D9AC4
    nop
    bltz    $at, .L800D9B34
    nop
.L800D9AC4:
    bgez    $t6, .L800D9AD4
    nop
    bgtz    $at, .L800D9B34
    nop
.L800D9AD4:
    bgtz    $a0, .L800D9AE0
    lhu     $v1, 0x94($t2)
    neg     $a0, $a0 /* handwritten instruction */
.L800D9AE0:
    bgtz    $a3, .L800D9AEC
    lbu     $t8, 0xB3($t2)
    neg     $a3, $a3 /* handwritten instruction */
.L800D9AEC:
    bgtz    $at, .L800D9AF8
    addu    $v1, $v1, $t8
    neg     $at, $at /* handwritten instruction */
.L800D9AF8:
    andi    $t8, $t7, 0xFFFF
    addu    $v1, $v1, $t8
    lhu     $t8, 0xB8($t2)
    sub     $a0, $a0, $v1 /* handwritten instruction */
    bgtz    $a0, .L800D9B34
    sub     $at, $at, $v1 /* handwritten instruction */
    bgtz    $at, .L800D9B34
    srl     $v1, $t7, 16
    addu    $v1, $v1, $t8
    srl     $v1, $v1, 1
    sub     $a3, $a3, $v1 /* handwritten instruction */
    bgtz    $a3, .L800D9B34
    nop
    bgez    $zero, .L800D9B44
    addiu   $v1, $t1, 0x1
.L800D9B34:
    lw      $t0, 0x0($t0)
    nop
    bnez    $t0, .L800D9A34
    addu    $v1, $zero, $zero
.L800D9B44:
    lui     $a0, (0x1F8003D2 >> 16)
    lbu     $a1, (0x1F8003D2 & 0xFFFF)($a0)
    addu    $t0, $a0, $t9
    sb      $v1, (0x1F8003D4 & 0xFFFF)($t0)
    addiu   $a2, $zero, 0x1
    sllv    $a2, $a2, $t9
    or      $a1, $a1, $a2
    sb      $a1, (0x1F8003D2 & 0xFFFF)($a0)
    jr      $ra
    addu    $v0, $v1, $zero
alabel D_800D9B6C
    lui     $a2, (0x1F8003D1 >> 16)
    lbu     $t0, (0x1F8003D0 & 0xFFFF)($a2)
    mtc2    $a1, $4 /* handwritten instruction */
    lbu     $t1, (0x1F8003D1 & 0xFFFF)($a2)
    srlv    $a3, $t0, $a1
    andi    $a3, $a3, 0x1
    beqz    $a3, .L800D9B94
    srlv    $t1, $t1, $a1
    jr      $ra
    andi    $v0, $t1, 0x1
.L800D9B94:
    addiu   $sp, $sp, -0x20
    sw      $ra, 0x10($sp)
    sw      $s0, 0x14($sp)
    sw      $s1, 0x18($sp)
    addu    $s0, $a0, $zero
    jal     func_800D98E8
    addu    $s1, $a1, $zero
    bnez    $v0, .L800D9D80
    andi    $a3, $s1, 0x1
    lw      $t0, 0x34($s0)
    lui     $a2, (0x1F8003EC >> 16)
    addu    $a2, $a2, $s1
    lbu     $a2, (0x1F8003EC & 0xFFFF)($a2)
    lw      $t1, 0x120($s0)
    andi    $a0, $t0, 0xFF
    sll     $a1, $t0, 8
    srl     $a1, $a1, 24
    andi    $t0, $t1, 0xFF
    sll     $t1, $t1, 8
    srl     $t1, $t1, 24
    sll     $t2, $a2, 30
    sra     $t2, $t2, 30
    sll     $t3, $a2, 26
    sra     $t3, $t3, 30
    add     $t0, $t0, $t2 /* handwritten instruction */
    add     $t1, $t1, $t3 /* handwritten instruction */
    sra     $t0, $t0, 1
    sra     $t1, $t1, 1
    bne     $t0, $a0, .L800D9C14
    lui     $a2, (0x1F8003C0 >> 16)
    beq     $t1, $a1, .L800D9D80
    addu    $v0, $zero, $zero
.L800D9C14:
    beqz    $a3, .L800D9C38
    sub     $t4, $t0, $a0 /* handwritten instruction */
    sub     $t5, $t1, $a1 /* handwritten instruction */
    addi    $t4, $t4, 0x1 /* handwritten instruction */
    addi    $t5, $t5, 0x1 /* handwritten instruction */
    sll     $t5, $t5, 2
    add     $t5, $t4, $t5 /* handwritten instruction */
    add     $a3, $a2, $t5 /* handwritten instruction */
    lb      $s1, 0x3E0($a3)
.L800D9C38:
    lw      $t4, (0x1F8003F4 & 0xFFFF)($a2)
    lw      $t5, (0x1F8003C0 & 0xFFFF)($a2)
    bnez    $t4, .L800D9C74
    sll     $t1, $t1, 6
    addu    $t8, $a0, $zero
    addu    $t9, $a1, $zero
    lw      $a0, 0x34($s0)
    sll     $t0, $t0, 1
    addu    $t6, $t0, $t5
    addu    $t6, $t6, $t1
    jal     func_800E4690
    addu    $a1, $s1, $zero
    addu    $a0, $t8, $zero
    addu    $a1, $t9, $zero
    bgez    $zero, .L800D9CCC
.L800D9C74:
    lbu     $v1, (0x1F8003DC & 0xFFFF)($a2)
    lw      $t7, (0x1F8003C4 & 0xFFFF)($a2)
    mult    $a1, $v1
    lw      $v1, 0x38($s0)
    sll     $t0, $t0, 1
    addu    $t6, $t0, $t5
    addu    $t6, $t6, $t1
    srl     $v0, $v1, 10
    andi    $v0, $v0, 0x3FC0
    andi    $v1, $v1, 0xFF
    sll     $v1, $v1, 1
    or      $v1, $v0, $v1
    addu    $v1, $v1, $t5
    beq     $v1, $t6, .L800D9D80
    addiu   $v0, $zero, 0x1
    mflo    $v1
    addu    $v1, $v1, $t7
    addu    $v1, $v1, $a0
    lbu     $v1, 0x0($v1)
    nop
    srlv    $v0, $v1, $s1
    andi    $v0, $v0, 0x1
.L800D9CCC:
    bnez    $v0, .L800D9D80
    lbu     $v1, 0x6($s0)
    lhu     $t6, 0x0($t6)
    xori    $v1, $v1, 0x1
    srl     $v0, $t6, 4
    and     $v0, $v0, $v1
    bnez    $v0, .L800D9D80
    srl     $v1, $t6, 5
    andi    $v0, $v1, 0x1
    srl     $v1, $t6, 7
    andi    $v1, $v1, 0x1
    or      $v0, $v0, $v1
    bnez    $v0, .L800D9D80
    lbu     $v1, 0x32($s0)
    srl     $v0, $t6, 8
    and     $v0, $v1, $v0
    bnez    $v0, .L800D9D80
    lbu     $t7, 0x29($s0)
    sll     $a0, $a0, 1
    sll     $a1, $a1, 6
    lbu     $t8, 0x2($s0)
    addu    $t9, $t5, $a0
    addu    $t9, $t9, $a1
    lhu     $t9, 0x0($t9)
    xori    $t8, $t8, 0x1
    and     $t7, $t7, $t8
    beqz    $t7, .L800D9D54
    sll     $t8, $t6, 28
    sll     $t7, $t9, 28
    beq     $t7, $t8, .L800D9D54
    lbu     $v1, 0x154($s0)
    addiu   $v0, $zero, 0x1
    sll     $v1, $v1, 28
    bne     $v1, $t8, .L800D9D80
.L800D9D54:
    lui     $a3, (0x1F8003BC >> 16)
    lw      $a2, (0x1F8003BC & 0xFFFF)($a3)
    add     $t7, $t0, $t1 /* handwritten instruction */
    add     $t7, $t7, $a2 /* handwritten instruction */
    lhu     $t7, 0x0($t7)
    add     $t8, $a0, $a1 /* handwritten instruction */
    add     $t8, $t8, $a2 /* handwritten instruction */
    lhu     $t8, 0x0($t8)
    andi    $t7, $t7, 0x1C00
    andi    $t8, $t8, 0x1C00
    slt     $v0, $t8, $t7
.L800D9D80:
    lui     $a3, (0x1F8003D1 >> 16)
    mfc2    $s1, $4 /* handwritten instruction */
    lbu     $a0, (0x1F8003D0 & 0xFFFF)($a3)
    addiu   $v1, $zero, 0x1
    lbu     $a1, (0x1F8003D1 & 0xFFFF)($a3)
    sllv    $v1, $v1, $s1
    or      $a0, $a0, $v1
    beqz    $v0, .L800D9DB4
    sb      $a0, (0x1F8003D0 & 0xFFFF)($a3)
    neg     $v1, $v1 /* handwritten instruction */
    addi    $v1, $v1, -0x1 /* handwritten instruction */
    bgez    $zero, .L800D9DB8
    and     $a1, $a1, $v1
.L800D9DB4:
    or      $a1, $a1, $v1
.L800D9DB8:
    sb      $a1, (0x1F8003D1 & 0xFFFF)($a3)
    srlv    $a1, $a1, $s1
    andi    $v0, $a1, 0x1
    lw      $ra, 0x10($sp)
    lw      $s0, 0x14($sp)
    lw      $s1, 0x18($sp)
    jr      $ra
    addiu   $sp, $sp, 0x20
endlabel func_800D98E8

# hasm: unconditional b branch
# hasm: cross-function control flow
glabel func_800D9DD8
    lw      $a1, 0x68($a0)
    lui     $v0, %hi(func_800DAA6C)
    addiu   $v0, $v0, %lo(func_800DAA6C)
    beq     $a1, $v0, .L800D9E00
    lw      $v0, 0x430($a0)
    lbu     $v1, 0x2D($a0)
    lw      $v0, 0x10($v0)
    addiu   $a1, $zero, 0x2
    and     $v0, $v0, $v1
    bnez    $v0, .L800D9E0C
.L800D9E00:
    addiu   $a2, $zero, 0x1
    jr      $ra
    sb      $a2, 0x12E($a0)
.L800D9E0C:
    sb      $a1, 0x12E($a0)
    bgez    $zero, func_800DD7CC
    addiu   $a1, $a0, 0x134
endlabel func_800D9DD8
