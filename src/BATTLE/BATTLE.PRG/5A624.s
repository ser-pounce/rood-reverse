.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_800C2E24
    addiu   $sp, $sp, -0x38
    sw      $fp, 0x30($sp)
    addu    $fp, $a0, $zero
    sw      $s4, 0x20($sp)
    lui     $s4, (0x1F800088 >> 16)
    ori     $s4, $s4, (0x1F800088 & 0xFFFF)
    lui     $a0, (0x1010101 >> 16)
    ori     $a0, $a0, (0x1010101 & 0xFFFF)
    sw      $s2, 0x18($sp)
    addiu   $s2, $zero, 0x14
    lui     $v1, (0x1F8000D8 >> 16)
    lui     $v0, %hi(D_800EB9B8)
    lw      $v0, %lo(D_800EB9B8)($v0)
    ori     $v1, $v1, (0x1F8000D8 & 0xFFFF)
    sw      $s7, 0x2C($sp)
    sw      $s6, 0x28($sp)
    sw      $s5, 0x24($sp)
    sw      $s3, 0x1C($sp)
    sw      $s1, 0x14($sp)
    sw      $s0, 0x10($sp)
    sw      $a1, 0x3C($sp)
    sw      $a2, 0x40($sp)
    sw      $s4, 0x8($sp)
    addiu   $a1, $v0, 0x4370
.L800C2E84:
    sw      $a0, 0x0($v1)
    addiu   $s2, $s2, -0x1
    bgez    $s2, .L800C2E84
    addiu   $v1, $v1, -0x4
    lw      $s4, 0x8($sp)
    addiu   $s2, $zero, 0x15
    addiu   $v1, $s4, 0x54
    sb      $zero, 0x53($s4)
.L800C2EA4:
    sw      $zero, 0x0($v1)
    addiu   $s2, $s2, 0x1
    slti    $v0, $s2, 0x7A
    bnez    $v0, .L800C2EA4
    addiu   $v1, $v1, 0x4
    lui     $v0, %hi(D_800EB9B8)
    lw      $v0, %lo(D_800EB9B8)($v0)
    nop
    lh      $v0, 0x22($v0)
    lh      $s6, 0x2($fp)
    addiu   $v0, $v0, -0x200
    sra     $v0, $v0, 10
    andi    $v1, $v0, 0x3
    addiu   $v0, $zero, 0x1
    beq     $v1, $v0, .L800C2FB0
    addu    $s2, $zero, $zero
    slti    $v0, $v1, 0x2
    beqz    $v0, .L800C2F00
    addiu   $v0, $zero, 0x2
    beqz    $v1, .L800C2F18
    addu    $t8, $zero, $zero
    j       .L800C3168
    nop
.L800C2F00:
    beq     $v1, $v0, .L800C3048
    addiu   $v0, $zero, 0x3
    beq     $v1, $v0, .L800C30DC
    addiu   $t6, $zero, 0x8
    j       .L800C3168
    nop
.L800C2F18:
    lw      $s4, 0x8($sp)
    addu    $t6, $zero, $zero
    addu    $a0, $s2, $s4
.L800C2F24:
    addu    $v0, $t6, $t8
    sll     $v0, $v0, 2
    addu    $v0, $v0, $a1
    lw      $t0, 0x0($v0)
    nop
    sll     $v0, $t0, 15
    sra     $t2, $v0, 17
    slt     $v0, $s6, $t2
    bnez    $v0, .L800C2F70
    sra     $t3, $t0, 17
    andi    $v0, $t0, 0x1
    beqz    $v0, .L800C2F84
    subu    $v1, $s6, $t2
    slti    $v0, $v1, 0x31
    bnez    $v0, .L800C2F68
    nop
    addiu   $v1, $zero, 0x30
.L800C2F68:
    j       .L800C2F84
    sb      $v1, 0x0($a0)
.L800C2F70:
    beqz    $t3, .L800C2F80
    slt     $v0, $t3, $s6
    beqz    $v0, .L800C2F84
    nop
.L800C2F80:
    sb      $zero, 0x0($a0)
.L800C2F84:
    addiu   $a0, $a0, 0x1
    addiu   $t6, $t6, 0x1
    slti    $v0, $t6, 0x9
    bnez    $v0, .L800C2F24
    addiu   $s2, $s2, 0x1
    addiu   $t8, $t8, 0x9
    slti    $v0, $t8, 0x49
    beqz    $v0, .L800C3168
    nop
    j       .L800C2F18
    nop
.L800C2FB0:
    addu    $t6, $zero, $zero
.L800C2FB4:
    lw      $s4, 0x8($sp)
    addiu   $t8, $zero, 0x48
    addu    $a0, $s2, $s4
.L800C2FC0:
    addu    $v0, $t6, $t8
    sll     $v0, $v0, 2
    addu    $v0, $v0, $a1
    lw      $t0, 0x0($v0)
    nop
    sll     $v0, $t0, 15
    sra     $t2, $v0, 17
    slt     $v0, $s6, $t2
    bnez    $v0, .L800C300C
    sra     $t3, $t0, 17
    andi    $v0, $t0, 0x1
    beqz    $v0, .L800C3020
    subu    $v1, $s6, $t2
    slti    $v0, $v1, 0x31
    bnez    $v0, .L800C3004
    nop
    addiu   $v1, $zero, 0x30
.L800C3004:
    j       .L800C3020
    sb      $v1, 0x0($a0)
.L800C300C:
    beqz    $t3, .L800C301C
    slt     $v0, $t3, $s6
    beqz    $v0, .L800C3020
    nop
.L800C301C:
    sb      $zero, 0x0($a0)
.L800C3020:
    addiu   $a0, $a0, 0x1
    addiu   $t8, $t8, -0x9
    bgez    $t8, .L800C2FC0
    addiu   $s2, $s2, 0x1
    addiu   $t6, $t6, 0x1
    slti    $v0, $t6, 0x9
    beqz    $v0, .L800C3168
    nop
    j       .L800C2FB4
    nop
.L800C3048:
    addiu   $t8, $zero, 0x48
.L800C304C:
    lw      $s4, 0x8($sp)
    addiu   $t6, $zero, 0x8
    addu    $a0, $s2, $s4
.L800C3058:
    addu    $v0, $t6, $t8
    sll     $v0, $v0, 2
    addu    $v0, $v0, $a1
    lw      $t0, 0x0($v0)
    nop
    sll     $v0, $t0, 15
    sra     $t2, $v0, 17
    slt     $v0, $s6, $t2
    bnez    $v0, .L800C30A4
    sra     $t3, $t0, 17
    andi    $v0, $t0, 0x1
    beqz    $v0, .L800C30B8
    subu    $v1, $s6, $t2
    slti    $v0, $v1, 0x31
    bnez    $v0, .L800C309C
    nop
    addiu   $v1, $zero, 0x30
.L800C309C:
    j       .L800C30B8
    sb      $v1, 0x0($a0)
.L800C30A4:
    beqz    $t3, .L800C30B4
    slt     $v0, $t3, $s6
    beqz    $v0, .L800C30B8
    nop
.L800C30B4:
    sb      $zero, 0x0($a0)
.L800C30B8:
    addiu   $a0, $a0, 0x1
    addiu   $t6, $t6, -0x1
    bgez    $t6, .L800C3058
    addiu   $s2, $s2, 0x1
    addiu   $t8, $t8, -0x9
    bltz    $t8, .L800C3168
    nop
    j       .L800C304C
    nop
.L800C30DC:
    lw      $s4, 0x8($sp)
    addu    $t8, $zero, $zero
    addu    $a0, $s2, $s4
.L800C30E8:
    addu    $v0, $t6, $t8
    sll     $v0, $v0, 2
    addu    $v0, $v0, $a1
    lw      $t0, 0x0($v0)
    nop
    sll     $v0, $t0, 15
    sra     $t2, $v0, 17
    slt     $v0, $s6, $t2
    bnez    $v0, .L800C3134
    sra     $t3, $t0, 17
    andi    $v0, $t0, 0x1
    beqz    $v0, .L800C3148
    subu    $v1, $s6, $t2
    slti    $v0, $v1, 0x31
    bnez    $v0, .L800C312C
    nop
    addiu   $v1, $zero, 0x30
.L800C312C:
    j       .L800C3148
    sb      $v1, 0x0($a0)
.L800C3134:
    beqz    $t3, .L800C3144
    slt     $v0, $t3, $s6
    beqz    $v0, .L800C3148
    nop
.L800C3144:
    sb      $zero, 0x0($a0)
.L800C3148:
    addiu   $a0, $a0, 0x1
    addiu   $t8, $t8, 0x9
    slti    $v0, $t8, 0x49
    bnez    $v0, .L800C30E8
    addiu   $s2, $s2, 0x1
    addiu   $t6, $t6, -0x1
    bgez    $t6, .L800C30DC
    nop
.L800C3168:
    lw      $s4, 0x8($sp)
    addu    $s2, $zero, $zero
    addu    $t8, $s2, $zero
    addiu   $a1, $zero, 0x1
    addiu   $s5, $s4, 0x134
    addu    $t6, $zero, $zero
.L800C3180:
    lw      $s4, 0x8($sp)
    nop
    addu    $v0, $s4, $s2
    lbu     $v0, 0x0($v0)
    nop
    bnez    $v0, .L800C31D4
    addiu   $s2, $s2, 0x1
    addu    $v0, $t6, $t8
    addu    $v0, $s5, $v0
    lbu     $v1, 0x0($v0)
    lbu     $a0, 0x9($v0)
    subu    $v1, $a1, $v1
    sb      $v1, 0x0($v0)
    lbu     $v1, 0xA($v0)
    subu    $a0, $a1, $a0
    sb      $a0, 0x9($v0)
    lbu     $a0, 0x13($v0)
    subu    $v1, $a1, $v1
    subu    $a0, $a1, $a0
    sb      $v1, 0xA($v0)
    sb      $a0, 0x13($v0)
.L800C31D4:
    addiu   $t6, $t6, 0x1
    slti    $v0, $t6, 0x9
    bnez    $v0, .L800C3180
    nop
    addiu   $t8, $t8, 0x13
    slti    $v0, $t8, 0x99
    bnez    $v0, .L800C3180
    addu    $t6, $zero, $zero
    addiu   $s7, $s5, -0xE0
    addu    $s2, $zero, $zero
    sll     $t7, $s6, 16
    lui     $v0, %hi(D_800EA130)
    addiu   $s0, $v0, %lo(D_800EA130)
    addu    $a3, $s5, $zero
    lui     $v0, %hi(D_800EB9B8)
    lw      $a0, %lo(D_800EB9B8)($v0)
    lhu     $v0, 0x0($fp)
    lhu     $v1, 0x4($fp)
    addiu   $s1, $a0, 0xB70
    sll     $v0, $v0, 16
    sra     $v0, $v0, 23
    addiu   $v0, $v0, -0x4
    sll     $t6, $v0, 7
    sll     $v1, $v1, 16
    sra     $v1, $v1, 23
    addiu   $v1, $v1, -0x4
    lh      $v0, 0x22($a0)
    sll     $t8, $v1, 7
    addiu   $v0, $v0, -0x200
    sra     $v0, $v0, 10
    andi    $v0, $v0, 0x3
    sll     $v1, $v0, 1
    addu    $v1, $v1, $v0
    sll     $v0, $v1, 4
    subu    $v0, $v0, $v1
    sll     $v0, $v0, 3
    addiu   $v0, $v0, 0x44B4
    addu    $a0, $a0, $v0
    addu    $t4, $a0, $zero
    sw      $a0, 0x0($sp)
.L800C3274:
    lbu     $v0, 0x0($a3)
    nop
    beqz    $v0, .L800C352C
    nop
    lhu     $t0, 0x0($t4)
    nop
    andi    $v0, $t0, 0xF
    sll     $v0, $v0, 7
    addu    $v0, $t6, $v0
    andi    $v0, $v0, 0xFFFF
    or      $t2, $v0, $t7
    sll     $v0, $t0, 3
    andi    $v0, $v0, 0x780
    addu    $t1, $t8, $v0
    mtc2    $t2, $0
    mtc2    $t1, $1
    srl     $t5, $t0, 5
    andi    $t5, $t5, 0x780
    rtps
    addu    $t5, $t5, $t8
    srl     $v0, $t0, 1
    andi    $v0, $v0, 0x780
    addu    $v0, $t6, $v0
    andi    $v0, $v0, 0xFFFF
    or      $t3, $v0, $t7
    mfc2    $t2, $14
    mtc2    $t3, $0
    mtc2    $t5, $1
    sra     $t1, $t2, 16
    sll     $t2, $t2, 16
    rtps
    sb      $zero, 0x0($a3)
    mfc2    $t3, $14
    ori     $at, $zero, 0x8000
    addu    $t2, $t2, $at
    sra     $t5, $t3, 16
    sll     $v0, $t3, 16
    ori     $t3, $v0, 0x8000
    subu    $v0, $t1, $t5
    addiu   $v0, $v0, 0x2
    sltiu   $v0, $v0, 0x5
    beqz    $v0, .L800C3334
    slt     $v0, $t3, $t2
    bnez    $v0, .L800C332C
    addiu   $v0, $zero, 0xFF
    addiu   $v0, $zero, 0x7F
.L800C332C:
    sb      $v0, 0x0($a3)
    sb      $t1, 0xB4($a3)
.L800C3334:
    slt     $v0, $t1, $t5
    beqz    $v0, .L800C3434
    slt     $v0, $t5, $t1
    blez    $t5, .L800C352C
    slti    $v0, $t1, 0xE0
    beqz    $v0, .L800C352C
    nop
    bgez    $t1, .L800C335C
    addu    $t0, $t1, $zero
    addu    $t0, $zero, $zero
.L800C335C:
    lbu     $v0, 0x0($a3)
    nop
    bnez    $v0, .L800C33B4
    subu    $v1, $t3, $t2
    addu    $v0, $s7, $t0
    lbu     $v1, 0x0($v0)
    subu    $v0, $t3, $t2
    bltz    $v0, .L800C3394
    addiu   $v0, $v1, 0x1
    andi    $v0, $v0, 0x1
    bnez    $v0, .L800C33A0
    addu    $v0, $s7, $t0
    j       .L800C33B4
    subu    $v1, $t3, $t2
.L800C3394:
    andi    $v0, $v1, 0x1
    beqz    $v0, .L800C33B0
    addu    $v0, $s7, $t0
.L800C33A0:
    lbu     $v0, 0x0($v0)
    nop
    addiu   $v0, $v0, 0x1
    sb      $v0, 0x0($a3)
.L800C33B0:
    subu    $v1, $t3, $t2
.L800C33B4:
    subu    $v0, $t5, $t1
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s0
    lhu     $v0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $v0
    slti    $v0, $t5, 0xE1
    mflo    $t3
    bnez    $v0, .L800C33E0
    nop
    addiu   $t5, $zero, 0xE0
.L800C33E0:
    bgez    $t1, .L800C33F4
    sb      $t5, 0xB4($a3)
.L800C33E8:
    addiu   $t1, $t1, 0x1
    bltz    $t1, .L800C33E8
    addu    $t2, $t2, $t3
.L800C33F4:
    addu    $a1, $s7, $t1
    sll     $a0, $t1, 5
    addiu   $t1, $t1, 0x1
    sra     $a2, $t2, 16
    lbu     $v1, 0x0($a1)
    addu    $t2, $t2, $t3
    addiu   $v0, $v1, 0x1
    andi    $v1, $v1, 0xFF
    addu    $a0, $a0, $v1
    sll     $a0, $a0, 1
    addu    $a0, $a0, $s1
    sb      $v0, 0x0($a1)
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C33F4
    sh      $a2, 0x0($a0)
    slt     $v0, $t5, $t1
.L800C3434:
    beqz    $v0, .L800C352C
    nop
    blez    $t1, .L800C352C
    slti    $v0, $t5, 0xE0
    beqz    $v0, .L800C352C
    nop
    bgez    $t5, .L800C3458
    addu    $t0, $t5, $zero
    addu    $t0, $zero, $zero
.L800C3458:
    lbu     $v0, 0x0($a3)
    nop
    bnez    $v0, .L800C34B0
    subu    $v1, $t2, $t3
    addu    $v0, $s7, $t0
    lbu     $v1, 0x0($v0)
    subu    $v0, $t2, $t3
    bltz    $v0, .L800C3490
    addiu   $v0, $v1, 0x1
    andi    $v0, $v0, 0x1
    bnez    $v0, .L800C349C
    addu    $v0, $s7, $t0
    j       .L800C34B0
    subu    $v1, $t2, $t3
.L800C3490:
    andi    $v0, $v1, 0x1
    beqz    $v0, .L800C34AC
    addu    $v0, $s7, $t0
.L800C349C:
    lbu     $v0, 0x0($v0)
    nop
    addiu   $v0, $v0, 0x81
    sb      $v0, 0x0($a3)
.L800C34AC:
    subu    $v1, $t2, $t3
.L800C34B0:
    subu    $v0, $t1, $t5
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s0
    lhu     $v0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $v0
    slti    $v0, $t1, 0xE1
    mflo    $t2
    bnez    $v0, .L800C34DC
    nop
    addiu   $t1, $zero, 0xE0
.L800C34DC:
    bgez    $t5, .L800C34F0
    sb      $t1, 0xB4($a3)
.L800C34E4:
    addiu   $t5, $t5, 0x1
    bltz    $t5, .L800C34E4
    addu    $t3, $t3, $t2
.L800C34F0:
    addu    $a1, $s7, $t5
    sll     $a0, $t5, 5
    addiu   $t5, $t5, 0x1
    sra     $a2, $t3, 16
    lbu     $v1, 0x0($a1)
    addu    $t3, $t3, $t2
    addiu   $v0, $v1, 0x1
    andi    $v1, $v1, 0xFF
    addu    $a0, $a0, $v1
    sll     $a0, $a0, 1
    addu    $a0, $a0, $s1
    sb      $v0, 0x0($a1)
    slt     $v0, $t5, $t1
    bnez    $v0, .L800C34F0
    sh      $a2, 0x0($a0)
.L800C352C:
    addiu   $a3, $a3, 0x1
    addiu   $s2, $s2, 0x1
    slti    $v0, $s2, 0xB4
    bnez    $v0, .L800C3274
    addiu   $t4, $t4, 0x2
    addiu   $s2, $zero, 0xA
    addu    $s3, $s5, $s2
.L800C3548:
    lbu     $a2, 0x0($s3)
    nop
    beqz    $a2, .L800C3C74
    lui     $v0, %hi(D_800EA6B0)
    addiu   $v0, $v0, %lo(D_800EA6B0)
    sll     $a0, $s2, 1
    addu    $v0, $a0, $v0
    lhu     $t0, 0x0($v0)
    lw      $s4, 0x8($sp)
    andi    $v1, $t0, 0xFF
    addu    $v1, $s4, $v1
    sra     $v0, $t0, 8
    addu    $v0, $s4, $v0
    lbu     $v1, 0x0($v1)
    lbu     $v0, 0x0($v0)
    nop
    addu    $t9, $v1, $v0
    slti    $v0, $t9, 0x2
    bnez    $v0, .L800C3C74
    nop
    lw      $s4, 0x0($sp)
    nop
    addu    $v0, $a0, $s4
    lhu     $t0, 0x0($v0)
    andi    $v0, $a2, 0x80
    beqz    $v0, .L800C35C0
    sra     $v0, $t0, 8
    sll     $v1, $t0, 8
    or      $v0, $v0, $v1
    andi    $t0, $v0, 0xFFFF
.L800C35C0:
    andi    $v0, $t0, 0xF
    sll     $v0, $v0, 7
    addu    $v0, $t6, $v0
    andi    $v0, $v0, 0xFFFF
    subu    $v1, $s6, $t9
    sll     $v1, $v1, 16
    or      $t2, $v0, $v1
    sll     $v0, $t0, 3
    andi    $v0, $v0, 0x780
    addu    $t1, $t8, $v0
    mtc2    $t2, $0
    mtc2    $t1, $1
    srl     $t5, $t0, 5
    andi    $t5, $t5, 0x780
    rtps
    addu    $t5, $t5, $t8
    sra     $v0, $t0, 1
    andi    $v0, $v0, 0x780
    addu    $v0, $t6, $v0
    andi    $v0, $v0, 0xFFFF
    or      $t3, $v0, $v1
    mfc2    $t2, $14
    mtc2    $t3, $0
    mtc2    $t5, $1
    sra     $t1, $t2, 16
    sll     $t2, $t2, 16
    rtps
    sra     $t9, $t2, 16
    mfc2    $t3, $14
    ori     $at, $zero, 0x8000
    addu    $t2, $t2, $at
    sra     $t5, $t3, 16
    sll     $v0, $t3, 16
    blez    $t5, .L800C3C74
    ori     $t3, $v0, 0x8000
    andi    $v1, $a2, 0x7F
    addiu   $v0, $zero, 0x7F
    bne     $v1, $v0, .L800C3818
    subu    $v0, $t5, $t1
    addu    $t2, $t9, $zero
    lbu     $t5, 0xB4($s3)
    nop
    slti    $v0, $t5, 0xE0
    bnez    $v0, .L800C3678
    sra     $t3, $t3, 16
    addiu   $t5, $zero, 0xE0
.L800C3678:
    bgez    $t1, .L800C3688
    slt     $v0, $t1, $t5
    addu    $t1, $zero, $zero
    slt     $v0, $t1, $t5
.L800C3688:
    beqz    $v0, .L800C3C74
    addu    $t7, $t1, $s7
.L800C3690:
    lbu     $v0, 0x0($t7)
    nop
    beqz    $v0, .L800C37FC
    addu    $t0, $zero, $zero
    sll     $t4, $t1, 5
    addu    $a3, $t7, $zero
    addu    $v0, $t4, $t0
.L800C36AC:
    sll     $v0, $v0, 1
    addu    $a1, $v0, $s1
    lh      $a0, 0x2($a1)
    nop
    slt     $v0, $t2, $a0
    beqz    $v0, .L800C37E8
    nop
    lh      $v1, 0x0($a1)
    nop
    slt     $v0, $v1, $t3
    beqz    $v0, .L800C37FC
    slt     $v0, $t3, $a0
    beqz    $v0, .L800C36E8
    slt     $v1, $v1, $t2
    addiu   $v1, $v1, 0x2
.L800C36E8:
    addiu   $v0, $zero, 0x1
    beq     $v1, $v0, .L800C3778
    slti    $v0, $v1, 0x2
    beqz    $v0, .L800C370C
    addiu   $v0, $zero, 0x2
    beqz    $v1, .L800C3724
    addu    $a2, $t0, $zero
    j       .L800C3800
    addiu   $t7, $t7, 0x1
.L800C370C:
    beq     $v1, $v0, .L800C3780
    addiu   $v0, $zero, 0x3
    beq     $v1, $v0, .L800C3788
    nop
    j       .L800C3800
    addiu   $t7, $t7, 0x1
.L800C3724:
    lbu     $v0, 0x0($a3)
    nop
    addiu   $v0, $v0, -0x2
    sb      $v0, 0x0($a3)
    andi    $v0, $v0, 0xFF
    slt     $v0, $a2, $v0
    beqz    $v0, .L800C37FC
    addu    $a0, $a3, $zero
    addu    $v0, $t4, $a2
.L800C3748:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x4($v0)
    nop
    sh      $v1, 0x0($v0)
    lbu     $v0, 0x0($a0)
    addiu   $a2, $a2, 0x1
    slt     $v0, $a2, $v0
    bnez    $v0, .L800C3748
    addu    $v0, $t4, $a2
    j       .L800C3800
    addiu   $t7, $t7, 0x1
.L800C3778:
    j       .L800C37FC
    sh      $t2, 0x2($a1)
.L800C3780:
    j       .L800C37FC
    sh      $t3, 0x0($a1)
.L800C3788:
    lbu     $v0, 0x0($a3)
    nop
    addiu   $a2, $v0, -0x1
    slt     $v0, $t0, $a2
    beqz    $v0, .L800C37C0
    addu    $v0, $t4, $a2
.L800C37A0:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x0($v0)
    addiu   $a2, $a2, -0x1
    sh      $v1, 0x4($v0)
    slt     $v0, $t0, $a2
    bnez    $v0, .L800C37A0
    addu    $v0, $t4, $a2
.L800C37C0:
    lbu     $v0, 0x0($a3)
    nop
    addiu   $v0, $v0, 0x2
    sb      $v0, 0x0($a3)
    addu    $v0, $t4, $a2
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    sh      $t2, 0x2($v0)
    j       .L800C37FC
    sh      $t3, 0x4($v0)
.L800C37E8:
    lbu     $v0, 0x0($a3)
    addiu   $t0, $t0, 0x2
    slt     $v0, $t0, $v0
    bnez    $v0, .L800C36AC
    addu    $v0, $t4, $t0
.L800C37FC:
    addiu   $t7, $t7, 0x1
.L800C3800:
    addiu   $t1, $t1, 0x1
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C3690
    nop
    j       .L800C3C78
    addiu   $s3, $s3, 0x1
.L800C3818:
    subu    $v1, $t3, $t2
    sll     $v0, $v0, 1
    lui     $s4, %hi(D_800EA130)
    addiu   $s4, $s4, %lo(D_800EA130)
    addu    $v0, $v0, $s4
    lhu     $v0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $v0
    slti    $v0, $t5, 0xE1
    mflo    $t3
    bnez    $v0, .L800C384C
    nop
    addiu   $t5, $zero, 0xE0
.L800C384C:
    bgez    $t1, .L800C3864
    andi    $v0, $a2, 0x1
.L800C3854:
    addiu   $t1, $t1, 0x1
    bltz    $t1, .L800C3854
    addu    $t2, $t2, $t3
    andi    $v0, $a2, 0x1
.L800C3864:
    beqz    $v0, .L800C3A78
    slt     $v0, $t1, $t5
    beqz    $v0, .L800C396C
    nop
    addu    $a3, $t1, $s7
.L800C3878:
    addu    $a1, $a3, $zero
    lbu     $v0, 0x0($a3)
    nop
    beqz    $v0, .L800C3958
    addu    $t0, $zero, $zero
    sll     $a0, $t1, 5
    sra     $t4, $t2, 16
    addu    $t7, $a3, $zero
    addu    $v0, $a0, $t0
.L800C389C:
    sll     $v0, $v0, 1
    addu    $v1, $v0, $s1
    lh      $v0, 0x2($v1)
    nop
    slt     $v0, $t4, $v0
    beqz    $v0, .L800C3940
    nop
    lh      $v1, 0x0($v1)
    nop
    slt     $v0, $v1, $t4
    beqz    $v0, .L800C3958
    slt     $v0, $v1, $t9
    beqz    $v0, .L800C3930
    addu    $v0, $a0, $t0
    lbu     $v0, 0x0($a1)
    nop
    addiu   $a2, $v0, -0x1
    slt     $v0, $t0, $a2
    beqz    $v0, .L800C390C
    addu    $v0, $a0, $a2
.L800C38EC:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x0($v0)
    addiu   $a2, $a2, -0x1
    sh      $v1, 0x4($v0)
    slt     $v0, $t0, $a2
    bnez    $v0, .L800C38EC
    addu    $v0, $a0, $a2
.L800C390C:
    lbu     $v0, 0x0($t7)
    addiu   $t0, $t0, 0x2
    addiu   $v0, $v0, 0x2
    sb      $v0, 0x0($t7)
    addu    $v0, $a0, $a2
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    sh      $t9, 0x2($v0)
    addu    $v0, $a0, $t0
.L800C3930:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    j       .L800C3958
    sh      $t4, 0x0($v0)
.L800C3940:
    addu    $a1, $s7, $t1
    lbu     $v0, 0x0($a1)
    addiu   $t0, $t0, 0x2
    slt     $v0, $t0, $v0
    bnez    $v0, .L800C389C
    addu    $v0, $a0, $t0
.L800C3958:
    addiu   $a3, $a3, 0x1
    addiu   $t1, $t1, 0x1
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C3878
    addu    $t2, $t2, $t3
.L800C396C:
    lbu     $t1, 0xB4($s3)
    nop
    slt     $v0, $t5, $t1
    beqz    $v0, .L800C3C74
    sra     $t2, $t2, 16
    addu    $a3, $t5, $s7
.L800C3984:
    addu    $a1, $a3, $zero
    lbu     $v0, 0x0($a3)
    nop
    beqz    $v0, .L800C3A60
    addu    $t0, $zero, $zero
    sll     $a0, $t5, 5
    addu    $t3, $a3, $zero
    addu    $v0, $a0, $t0
.L800C39A4:
    sll     $v0, $v0, 1
    addu    $v1, $v0, $s1
    lh      $v0, 0x2($v1)
    nop
    slt     $v0, $t2, $v0
    beqz    $v0, .L800C3A48
    nop
    lh      $v1, 0x0($v1)
    nop
    slt     $v0, $v1, $t2
    beqz    $v0, .L800C3A60
    slt     $v0, $v1, $t9
    beqz    $v0, .L800C3A38
    addu    $v0, $a0, $t0
    lbu     $v0, 0x0($a1)
    nop
    addiu   $a2, $v0, -0x1
    slt     $v0, $t0, $a2
    beqz    $v0, .L800C3A14
    addu    $v0, $a0, $a2
.L800C39F4:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x0($v0)
    addiu   $a2, $a2, -0x1
    sh      $v1, 0x4($v0)
    slt     $v0, $t0, $a2
    bnez    $v0, .L800C39F4
    addu    $v0, $a0, $a2
.L800C3A14:
    lbu     $v0, 0x0($t3)
    addiu   $t0, $t0, 0x2
    addiu   $v0, $v0, 0x2
    sb      $v0, 0x0($t3)
    addu    $v0, $a0, $a2
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    sh      $t9, 0x2($v0)
    addu    $v0, $a0, $t0
.L800C3A38:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    j       .L800C3A60
    sh      $t2, 0x0($v0)
.L800C3A48:
    addu    $a1, $s7, $t5
    lbu     $v0, 0x0($a1)
    addiu   $t0, $t0, 0x2
    slt     $v0, $t0, $v0
    bnez    $v0, .L800C39A4
    addu    $v0, $a0, $t0
.L800C3A60:
    addiu   $t5, $t5, 0x1
    slt     $v0, $t5, $t1
    bnez    $v0, .L800C3984
    addiu   $a3, $a3, 0x1
    j       .L800C3C78
    addiu   $s3, $s3, 0x1
.L800C3A78:
    beqz    $v0, .L800C3B74
    nop
    addu    $t4, $t1, $s7
.L800C3A84:
    addu    $a2, $t4, $zero
    lbu     $v0, 0x0($t4)
    nop
    beqz    $v0, .L800C3B60
    addu    $t0, $zero, $zero
    sra     $t7, $t2, 16
    addu    $s0, $t4, $zero
    sll     $a3, $t1, 5
    addu    $a1, $a3, $zero
.L800C3AA8:
    sll     $v0, $a1, 1
    addu    $v1, $v0, $s1
    lh      $a0, 0x2($v1)
    nop
    slt     $v0, $t7, $a0
    beqz    $v0, .L800C3B48
    nop
    lh      $v0, 0x0($v1)
    nop
    slt     $v0, $v0, $t7
    beqz    $v0, .L800C3B60
    slt     $v0, $t9, $a0
    beqz    $v0, .L800C3B3C
    sll     $v0, $a1, 1
    lbu     $v0, 0x0($a2)
    nop
    addiu   $a2, $v0, -0x1
    slt     $v0, $t0, $a2
    beqz    $v0, .L800C3B18
    addu    $v0, $a3, $a2
.L800C3AF8:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x0($v0)
    addiu   $a2, $a2, -0x1
    sh      $v1, 0x4($v0)
    slt     $v0, $t0, $a2
    bnez    $v0, .L800C3AF8
    addu    $v0, $a3, $a2
.L800C3B18:
    lbu     $v0, 0x0($s0)
    nop
    addiu   $v0, $v0, 0x2
    sb      $v0, 0x0($s0)
    addu    $v0, $a3, $a2
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    sh      $t9, 0x4($v0)
    sll     $v0, $a1, 1
.L800C3B3C:
    addu    $v0, $v0, $s1
    j       .L800C3B60
    sh      $t7, 0x2($v0)
.L800C3B48:
    addu    $a2, $s7, $t1
    lbu     $v0, 0x0($a2)
    addiu   $t0, $t0, 0x2
    slt     $v0, $t0, $v0
    bnez    $v0, .L800C3AA8
    addiu   $a1, $a1, 0x2
.L800C3B60:
    addiu   $t4, $t4, 0x1
    addiu   $t1, $t1, 0x1
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C3A84
    addu    $t2, $t2, $t3
.L800C3B74:
    lbu     $t1, 0xB4($s3)
    nop
    slt     $v0, $t5, $t1
    beqz    $v0, .L800C3C74
    sra     $t2, $t2, 16
    addu    $t3, $t5, $s7
.L800C3B8C:
    addu    $a2, $t3, $zero
    lbu     $v0, 0x0($t3)
    nop
    beqz    $v0, .L800C3C64
    addu    $t0, $zero, $zero
    addu    $t4, $t3, $zero
    sll     $a3, $t5, 5
    addu    $a1, $a3, $zero
.L800C3BAC:
    sll     $v0, $a1, 1
    addu    $v1, $v0, $s1
    lh      $a0, 0x2($v1)
    nop
    slt     $v0, $t2, $a0
    beqz    $v0, .L800C3C4C
    nop
    lh      $v0, 0x0($v1)
    nop
    slt     $v0, $t2, $v0
    bnez    $v0, .L800C3C64
    slt     $v0, $t9, $a0
    beqz    $v0, .L800C3C40
    sll     $v0, $a1, 1
    lbu     $v0, 0x0($a2)
    nop
    addiu   $a2, $v0, -0x1
    slt     $v0, $t0, $a2
    beqz    $v0, .L800C3C1C
    addu    $v0, $a3, $a2
.L800C3BFC:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x0($v0)
    addiu   $a2, $a2, -0x1
    sh      $v1, 0x4($v0)
    slt     $v0, $t0, $a2
    bnez    $v0, .L800C3BFC
    addu    $v0, $a3, $a2
.L800C3C1C:
    lbu     $v0, 0x0($t4)
    nop
    addiu   $v0, $v0, 0x2
    sb      $v0, 0x0($t4)
    addu    $v0, $a3, $a2
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    sh      $t9, 0x4($v0)
    sll     $v0, $a1, 1
.L800C3C40:
    addu    $v0, $v0, $s1
    j       .L800C3C64
    sh      $t2, 0x2($v0)
.L800C3C4C:
    addu    $a2, $s7, $t5
    lbu     $v0, 0x0($a2)
    addiu   $t0, $t0, 0x2
    slt     $v0, $t0, $v0
    bnez    $v0, .L800C3BAC
    addiu   $a1, $a1, 0x2
.L800C3C64:
    addiu   $t5, $t5, 0x1
    slt     $v0, $t5, $t1
    bnez    $v0, .L800C3B8C
    addiu   $t3, $t3, 0x1
.L800C3C74:
    addiu   $s3, $s3, 0x1
.L800C3C78:
    addiu   $s2, $s2, 0x1
    slti    $v0, $s2, 0xAA
    bnez    $v0, .L800C3548
    lui     $v0, %hi(D_800EA130)
    addu    $s2, $zero, $zero
    sll     $t7, $s6, 16
    ori     $s3, $zero, 0x8000
    addiu   $s0, $v0, %lo(D_800EA130)
    addu    $t0, $zero, $zero
.L800C3C9C:
    lui     $v0, %hi(D_800EB9B8)
.L800C3CA0:
    sll     $v1, $s2, 3
    addu    $v1, $v1, $s2
    lw      $v0, %lo(D_800EB9B8)($v0)
    addu    $v1, $t0, $v1
    addu    $v0, $v0, $v1
    lbu     $a2, 0x4AB8($v0)
    nop
    beqz    $a2, .L800C40E4
    lui     $v0, (0x38847780 >> 16)
    ori     $v0, $v0, (0x38847780 & 0xFFFF)
    srav    $t9, $v0, $a2
    addiu   $a0, $t0, -0x4
    lhu     $v1, 0x0($fp)
    lhu     $v0, 0x4($fp)
    sll     $v1, $v1, 16
    sra     $v1, $v1, 23
    addu    $t6, $v1, $a0
    sll     $v0, $v0, 16
    sra     $v0, $v0, 23
    addiu   $v1, $s2, -0x4
    addu    $t8, $v0, $v1
    andi    $v0, $t9, 0x1
    addu    $v0, $t6, $v0
    sll     $v0, $v0, 7
    andi    $v0, $v0, 0xFFFF
    or      $t2, $v0, $t7
    sra     $v0, $t9, 1
    andi    $v0, $v0, 0x1
    addu    $v0, $t8, $v0
    sll     $t1, $v0, 7
    mtc2    $t2, $0
    mtc2    $t1, $1
    sra     $v0, $t9, 2
    andi    $v0, $v0, 0x1
    addu    $v0, $t6, $v0
    sll     $v0, $v0, 7
    andi    $v0, $v0, 0xFFFF
    or      $t2, $v0, $t7
    sra     $v0, $t9, 3
    andi    $v0, $v0, 0x1
    addu    $v0, $t8, $v0
    sll     $t1, $v0, 7
    mtc2    $t2, $2
    mtc2    $t1, $3
    sra     $v0, $t9, 4
    andi    $v0, $v0, 0x1
    addu    $v0, $t6, $v0
    sll     $v0, $v0, 7
    andi    $v0, $v0, 0xFFFF
    or      $t2, $v0, $t7
    sra     $v0, $t9, 5
    andi    $v0, $v0, 0x1
    addu    $v0, $t8, $v0
    sll     $t1, $v0, 7
    mtc2    $t2, $4
    mtc2    $t1, $5
    nop
    nop
    rtpt
    swc2    $12, 0x0($s5)
    addiu   $v0, $s5, 0x4
    swc2    $13, 0x0($v0)
    addiu   $v0, $s5, 0x8
    swc2    $14, 0x0($v0)
    lhu     $v0, 0x2($s5)
    lh      $v1, 0x6($s5)
    sll     $v0, $v0, 16
    sra     $a2, $v0, 16
    lw      $v0, 0x0($s5)
    nop
    sw      $v0, 0xC($s5)
    slt     $v0, $v1, $a2
    beqz    $v0, .L800C3DCC
    addu    $t9, $a2, $zero
    addu    $a2, $v1, $zero
.L800C3DCC:
    slt     $v0, $t9, $v1
    beqz    $v0, .L800C3DDC
    nop
    addu    $t9, $v1, $zero
.L800C3DDC:
    lh      $v1, 0xA($s5)
    nop
    slt     $v0, $v1, $a2
    beqz    $v0, .L800C3DF4
    slt     $v0, $t9, $v1
    addu    $a2, $v1, $zero
.L800C3DF4:
    beqz    $v0, .L800C3E00
    nop
    addu    $t9, $v1, $zero
.L800C3E00:
    bgez    $a2, .L800C3E0C
    slti    $v0, $t9, 0xE1
    addu    $a2, $zero, $zero
.L800C3E0C:
    bnez    $v0, .L800C3E18
    addu    $t8, $zero, $zero
    addiu   $t9, $zero, 0xE0
.L800C3E18:
    addu    $a0, $s5, $zero
.L800C3E1C:
    lw      $t6, 0x0($a0)
    nop
    sra     $t1, $t6, 16
    sll     $v0, $t6, 16
    lw      $t6, 0x4($a0)
    addu    $t2, $v0, $s3
    sll     $v0, $t6, 16
    addu    $t3, $v0, $s3
    sra     $t5, $t6, 16
    slt     $v0, $t1, $t5
    beqz    $v0, .L800C3EC4
    subu    $v1, $t3, $t2
    subu    $v0, $t5, $t1
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s0
    lhu     $v0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $v0
    slti    $v0, $t5, 0xE1
    mflo    $t3
    bnez    $v0, .L800C3E78
    nop
    addiu   $t5, $zero, 0xE0
.L800C3E78:
    bgez    $t1, .L800C3E90
    slt     $v0, $t1, $t5
.L800C3E80:
    addiu   $t1, $t1, 0x1
    bltz    $t1, .L800C3E80
    addu    $t2, $t2, $t3
    slt     $v0, $t1, $t5
.L800C3E90:
    beqz    $v0, .L800C3F34
    nop
.L800C3E98:
    subu    $v0, $t1, $a2
    sll     $v0, $v0, 2
    addu    $v0, $v0, $s5
    sra     $v1, $t2, 16
    sh      $v1, 0x12($v0)
    addiu   $t1, $t1, 0x1
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C3E98
    addu    $t2, $t2, $t3
    j       .L800C3F38
    addiu   $a0, $a0, 0x4
.L800C3EC4:
    subu    $v1, $t2, $t3
    subu    $v0, $t1, $t5
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s0
    lhu     $v0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $v0
    slti    $v0, $t1, 0xE1
    mflo    $t2
    bnez    $v0, .L800C3EF4
    nop
    addiu   $t1, $zero, 0xE0
.L800C3EF4:
    bgez    $t5, .L800C3F2C
    slt     $v0, $t5, $t1
.L800C3EFC:
    addiu   $t5, $t5, 0x1
    bltz    $t5, .L800C3EFC
    addu    $t3, $t3, $t2
    j       .L800C3F2C
    slt     $v0, $t5, $t1
.L800C3F10:
    sll     $v0, $v0, 2
    addu    $v0, $v0, $s5
    sra     $v1, $t3, 16
    sh      $v1, 0x10($v0)
    addiu   $t5, $t5, 0x1
    addu    $t3, $t3, $t2
    slt     $v0, $t5, $t1
.L800C3F2C:
    bnez    $v0, .L800C3F10
    subu    $v0, $t5, $a2
.L800C3F34:
    addiu   $a0, $a0, 0x4
.L800C3F38:
    addiu   $t8, $t8, 0x1
    slti    $v0, $t8, 0x3
    bnez    $v0, .L800C3E1C
    slt     $v0, $a2, $t9
    beqz    $v0, .L800C40E4
    addu    $t8, $a2, $zero
    addu    $t5, $a2, $s7
    subu    $v0, $t8, $a2
.L800C3F58:
    sll     $v0, $v0, 2
    addu    $v0, $v0, $s5
    lh      $t2, 0x10($v0)
    lbu     $v1, 0x0($t5)
    lh      $t3, 0x12($v0)
    beqz    $v1, .L800C40D0
    addu    $t6, $zero, $zero
    sll     $t4, $t8, 5
    addu    $a3, $t5, $zero
    addu    $v0, $t4, $t6
.L800C3F80:
    sll     $v0, $v0, 1
    addu    $a1, $v0, $s1
    lh      $a0, 0x2($a1)
    nop
    slt     $v0, $t2, $a0
    beqz    $v0, .L800C40BC
    nop
    lh      $v1, 0x0($a1)
    nop
    slt     $v0, $v1, $t3
    beqz    $v0, .L800C40D0
    slt     $v0, $t3, $a0
    beqz    $v0, .L800C3FBC
    slt     $v1, $v1, $t2
    addiu   $v1, $v1, 0x2
.L800C3FBC:
    addiu   $v0, $zero, 0x1
    beq     $v1, $v0, .L800C404C
    slti    $v0, $v1, 0x2
    beqz    $v0, .L800C3FE0
    addiu   $v0, $zero, 0x2
    beqz    $v1, .L800C3FF8
    addu    $t1, $t6, $zero
    j       .L800C40D4
    addiu   $t5, $t5, 0x1
.L800C3FE0:
    beq     $v1, $v0, .L800C4054
    addiu   $v0, $zero, 0x3
    beq     $v1, $v0, .L800C405C
    nop
    j       .L800C40D4
    addiu   $t5, $t5, 0x1
.L800C3FF8:
    lbu     $v0, 0x0($a3)
    nop
    addiu   $v0, $v0, -0x2
    sb      $v0, 0x0($a3)
    andi    $v0, $v0, 0xFF
    slt     $v0, $t1, $v0
    beqz    $v0, .L800C40D0
    addu    $a0, $a3, $zero
    addu    $v0, $t4, $t1
.L800C401C:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x4($v0)
    nop
    sh      $v1, 0x0($v0)
    lbu     $v0, 0x0($a0)
    addiu   $t1, $t1, 0x1
    slt     $v0, $t1, $v0
    bnez    $v0, .L800C401C
    addu    $v0, $t4, $t1
    j       .L800C40D4
    addiu   $t5, $t5, 0x1
.L800C404C:
    j       .L800C40D0
    sh      $t2, 0x2($a1)
.L800C4054:
    j       .L800C40D0
    sh      $t3, 0x0($a1)
.L800C405C:
    lbu     $v0, 0x0($a3)
    nop
    addiu   $t1, $v0, -0x1
    slt     $v0, $t6, $t1
    beqz    $v0, .L800C4094
    addu    $v0, $t4, $t1
.L800C4074:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lhu     $v1, 0x0($v0)
    addiu   $t1, $t1, -0x1
    sh      $v1, 0x4($v0)
    slt     $v0, $t6, $t1
    bnez    $v0, .L800C4074
    addu    $v0, $t4, $t1
.L800C4094:
    lbu     $v0, 0x0($a3)
    nop
    addiu   $v0, $v0, 0x2
    sb      $v0, 0x0($a3)
    addu    $v0, $t4, $t1
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    sh      $t2, 0x2($v0)
    j       .L800C40D0
    sh      $t3, 0x4($v0)
.L800C40BC:
    lbu     $v0, 0x0($a3)
    addiu   $t6, $t6, 0x2
    slt     $v0, $t6, $v0
    bnez    $v0, .L800C3F80
    addu    $v0, $t4, $t6
.L800C40D0:
    addiu   $t5, $t5, 0x1
.L800C40D4:
    addiu   $t8, $t8, 0x1
    slt     $v0, $t8, $t9
    bnez    $v0, .L800C3F58
    subu    $v0, $t8, $a2
.L800C40E4:
    addiu   $t0, $t0, 0x1
    slti    $v0, $t0, 0x9
    bnez    $v0, .L800C3CA0
    lui     $v0, %hi(D_800EB9B8)
    addiu   $s2, $s2, 0x1
    slti    $v0, $s2, 0x9
    bnez    $v0, .L800C3C9C
    addu    $t0, $zero, $zero
    lw      $s4, 0x3C($sp)
    nop
    lh      $v0, 0x0($s4)
    lw      $s4, 0x40($sp)
    nop
    mult    $v0, $s4
    lw      $s4, 0x3C($sp)
    nop
    lh      $v0, 0xC($s4)
    mflo    $v1
    lw      $s4, 0x40($sp)
    nop
    mult    $v0, $s4
    lw      $s4, 0x3C($sp)
    nop
    lh      $v0, 0x4($s4)
    mflo    $a0
    lw      $s4, 0x40($sp)
    nop
    mult    $v0, $s4
    addiu   $t0, $zero, 0xE0
    lw      $s4, 0x3C($sp)
    sll     $s6, $s6, 16
    lh      $v0, 0x10($s4)
    mflo    $a1
    lw      $s4, 0x40($sp)
    addu    $a3, $s5, $zero
    mult    $v0, $s4
    addiu   $t7, $zero, 0x10
    lui     $v0, %hi(D_800EA818)
    addiu   $s3, $v0, %lo(D_800EA818)
    addu    $s0, $s3, $zero
    addiu   $v0, $v1, 0x800
    sra     $t2, $v0, 12
    addiu   $v0, $a0, 0x800
    sra     $t1, $v0, 12
    addiu   $v0, $a1, 0x800
    sra     $t3, $v0, 12
    sw      $zero, 0x40($sp)
    mflo    $t5
    addiu   $v0, $t5, 0x800
    sra     $t5, $v0, 12
.L800C41AC:
    addu    $v0, $t7, $s3
    lh      $a2, 0x0($v0)
    nop
    mult    $t2, $a2
    mflo    $v0
    lh      $t9, 0x0($s0)
    nop
    mult    $t1, $t9
    mflo    $v1
    nop
    nop
    mult    $t3, $a2
    mflo    $a1
    nop
    nop
    mult    $t5, $t9
    addu    $v0, $v0, $v1
    addiu   $v0, $v0, 0x800
    lh      $v1, 0x0($fp)
    sra     $v0, $v0, 12
    addu    $v1, $v1, $v0
    andi    $v1, $v1, 0xFFFF
    or      $t6, $v1, $s6
    lh      $v1, 0x4($fp)
    mflo    $a0
    addu    $v0, $a1, $a0
    addiu   $v0, $v0, 0x800
    sra     $v0, $v0, 12
    addu    $t8, $v1, $v0
    mtc2    $t6, $0
    mtc2    $t8, $1
    nop
    nop
    rtps
    swc2    $14, 0x0($a3)
    addiu   $v0, $a3, 0x4
    mfc2    $t4, $19
    nop
    sra     $t4, $t4, 2
    sw      $t4, 0x0($v0)
    lh      $v1, 0x2($a3)
    nop
    slt     $v0, $v1, $t0
    beqz    $v0, .L800C4268
    nop
    addu    $t0, $v1, $zero
    lw      $s2, 0x40($sp)
.L800C4268:
    addiu   $a3, $a3, 0x8
    addiu   $s0, $s0, 0x2
    lw      $s4, 0x40($sp)
    addiu   $t7, $t7, 0x2
    addiu   $s4, $s4, 0x1
    slti    $v0, $s4, 0x20
    bnez    $v0, .L800C41AC
    sw      $s4, 0x40($sp)
    sw      $s2, 0x40($sp)
    ori     $a2, $zero, 0x8000
    lui     $v0, %hi(D_800EA130)
    addiu   $a3, $v0, %lo(D_800EA130)
    addiu   $v0, $s2, -0x1
.L800C429C:
    andi    $s2, $v0, 0x1F
.L800C42A0:
    addiu   $v0, $s2, 0x1
    andi    $v0, $v0, 0x1F
    sll     $v0, $v0, 3
    addu    $v0, $v0, $s5
    lw      $t2, 0x0($v0)
    sll     $v0, $s2, 3
    addu    $v0, $v0, $s5
    lw      $t3, 0x0($v0)
    sra     $t1, $t2, 16
    sra     $t5, $t3, 16
    beq     $t1, $t5, .L800C42D8
    nop
    bgez    $t5, .L800C42F0
    slt     $v0, $t5, $t1
.L800C42D8:
    lw      $s4, 0x40($sp)
    nop
    beq     $s2, $s4, .L800C43CC
    addiu   $v0, $s2, -0x1
    j       .L800C42A0
    andi    $s2, $v0, 0x1F
.L800C42F0:
    bnez    $v0, .L800C43CC
    slti    $v0, $t1, 0xE0
    beqz    $v0, .L800C43CC
    sll     $v0, $t2, 16
    addu    $t2, $v0, $a2
    sll     $v0, $t3, 16
    addu    $t3, $v0, $a2
    subu    $v1, $t3, $t2
    subu    $v0, $t5, $t1
    sll     $v0, $v0, 1
    addu    $v0, $v0, $a3
    lhu     $v0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $v0
    slti    $v0, $t5, 0xE1
    mflo    $t3
    bnez    $v0, .L800C433C
    nop
    addiu   $t5, $zero, 0xE0
.L800C433C:
    bgez    $t1, .L800C4350
    addu    $a0, $t1, $s7
    addiu   $t1, $t1, 0x1
    addu    $t2, $t2, $t3
    addu    $a0, $t1, $s7
.L800C4350:
    lbu     $t6, 0x0($a0)
    nop
    blez    $t6, .L800C43AC
    sra     $t8, $t2, 16
    sll     $a1, $t1, 5
    addu    $v0, $a1, $t6
.L800C4368:
    sll     $v0, $v0, 1
    addu    $v1, $v0, $s1
    lh      $v0, -0x4($v1)
    nop
    slt     $v0, $v0, $t8
    beqz    $v0, .L800C43A0
    nop
    lh      $v0, -0x2($v1)
    nop
    slt     $v0, $t8, $v0
    beqz    $v0, .L800C43AC
    nop
    j       .L800C43AC
    sh      $t8, -0x2($v1)
.L800C43A0:
    addiu   $t6, $t6, -0x2
    bgtz    $t6, .L800C4368
    addu    $v0, $a1, $t6
.L800C43AC:
    sb      $t6, 0x0($a0)
    addiu   $a0, $a0, 0x1
    addiu   $t1, $t1, 0x1
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C4350
    addu    $t2, $t2, $t3
    j       .L800C429C
    addiu   $v0, $s2, -0x1
.L800C43CC:
    lui     $v1, (0x1F800000 >> 16)
    lui     $fp, (0xFFFFFF >> 16)
    ori     $fp, $fp, (0xFFFFFF & 0xFFFF)
    lw      $s2, 0x40($sp)
    lw      $t7, (0x1F800000 & 0xFFFF)($v1)
    addiu   $v0, $s2, 0x1
.L800C43E4:
    andi    $s2, $v0, 0x1F
.L800C43E8:
    addiu   $v0, $s2, -0x1
    andi    $v0, $v0, 0x1F
    sll     $v0, $v0, 3
    addu    $a0, $v0, $s5
    sll     $v0, $s2, 3
    addu    $v1, $v0, $s5
    lw      $t2, 0x0($a0)
    lw      $t3, 0x0($v1)
    sra     $t1, $t2, 16
    sra     $t5, $t3, 16
    beq     $t1, $t5, .L800C4420
    nop
    bgez    $t5, .L800C4438
    slt     $v0, $t5, $t1
.L800C4420:
    lw      $s4, 0x40($sp)
    nop
    beq     $s2, $s4, .L800C461C
    addiu   $v0, $s2, 0x1
    j       .L800C43E8
    andi    $s2, $v0, 0x1F
.L800C4438:
    bnez    $v0, .L800C461C
    slti    $v0, $t1, 0xE0
    beqz    $v0, .L800C461C
    ori     $s4, $zero, 0x8000
    lh      $v0, 0x4($a0)
    lh      $v1, 0x4($v1)
    sll     $v0, $v0, 16
    addu    $a2, $v0, $s4
    sll     $v1, $v1, 16
    addu    $t9, $v1, $s4
    subu    $v1, $t9, $a2
    subu    $v0, $t5, $t1
    sll     $v0, $v0, 1
    lui     $s4, %hi(D_800EA130)
    addiu   $s4, $s4, %lo(D_800EA130)
    addu    $v0, $v0, $s4
    lhu     $a0, 0x0($v0)
    sra     $v1, $v1, 15
    mult    $v1, $a0
    sll     $v0, $t2, 16
    ori     $s4, $zero, 0x8000
    addu    $t2, $v0, $s4
    sll     $v0, $t3, 16
    addu    $t3, $v0, $s4
    mflo    $t9
    subu    $v0, $t3, $t2
    sra     $v0, $v0, 15
    mult    $v0, $a0
    slti    $v0, $t5, 0xE1
    mflo    $t3
    bnez    $v0, .L800C44BC
    nop
    addiu   $t5, $zero, 0xE0
.L800C44BC:
    bgez    $t1, .L800C44D8
    lui     $s0, (0xE1000220 >> 16)
.L800C44C4:
    addiu   $t1, $t1, 0x1
    addu    $t2, $t2, $t3
    bltz    $t1, .L800C44C4
    addu    $a2, $a2, $t9
    lui     $s0, (0xE1000220 >> 16)
.L800C44D8:
    ori     $s0, $s0, (0xE1000220 & 0xFFFF)
.L800C44DC:
    sra     $t8, $a2, 16
    sltiu   $v0, $t8, 0x800
    beqz    $v0, .L800C4600
    sra     $v0, $t1, 1
    sll     $v0, $v0, 8
    lui     $v1, (0x42000000 >> 16)
    or      $s6, $v0, $v1
    sll     $a0, $t8, 2
    sra     $t8, $t2, 16
    addu    $v0, $s7, $t1
    lui     $s4, %hi(vs_scratch)
    addiu   $s4, $s4, %lo(vs_scratch)
    lw      $v1, 0x4($s4)
    lbu     $t6, 0x0($v0)
    nop
    blez    $t6, .L800C4600
    addu    $t4, $v1, $a0
    sll     $s3, $t1, 5
    andi    $v0, $t8, 0xFFFF
    sll     $a3, $t1, 16
    or      $v0, $v0, $a3
    sw      $v0, 0x8($sp)
    addiu   $a1, $t7, 0x10
    addu    $v0, $s3, $t6
.L800C453C:
    sll     $v0, $v0, 1
    addu    $v0, $v0, $s1
    lw      $t0, -0x4($v0)
    lh      $v1, -0x4($v0)
    sra     $a0, $t0, 16
    slt     $v0, $v1, $a0
    beqz    $v0, .L800C45F4
    slt     $v0, $v1, $t8
    beqz    $v0, .L800C45AC
    slt     $v0, $t8, $a0
    beqz    $v0, .L800C4600
    sll     $v1, $t7, 8
    lui     $s4, (0x4000000 >> 16)
    lw      $v0, 0x0($t4)
    srl     $v1, $v1, 8
    and     $v0, $v0, $fp
    or      $v0, $v0, $s4
    sw      $v0, 0x0($t7)
    addiu   $t7, $t7, 0x14
    srl     $v0, $t0, 16
    sw      $s0, -0xC($a1)
    sw      $s6, -0x8($a1)
    lw      $s4, 0x8($sp)
    or      $v0, $v0, $a3
    sw      $s4, -0x4($a1)
    sw      $v0, 0x0($a1)
    j       .L800C4600
    sw      $v1, 0x0($t4)
.L800C45AC:
    lw      $v0, 0x0($t4)
    lui     $s4, (0x4000000 >> 16)
    and     $v0, $v0, $fp
    or      $v0, $v0, $s4
    sw      $v0, 0x0($t7)
    andi    $v0, $t0, 0xFFFF
    or      $v0, $v0, $a3
    sw      $v0, -0x4($a1)
    srl     $v0, $t0, 16
    or      $v0, $v0, $a3
    sw      $s0, -0xC($a1)
    sw      $s6, -0x8($a1)
    sw      $v0, 0x0($a1)
    addiu   $a1, $a1, 0x14
    sll     $v0, $t7, 8
    addiu   $t7, $t7, 0x14
    srl     $v0, $v0, 8
    sw      $v0, 0x0($t4)
.L800C45F4:
    addiu   $t6, $t6, -0x2
    bgtz    $t6, .L800C453C
    addu    $v0, $s3, $t6
.L800C4600:
    addiu   $t1, $t1, 0x1
    addu    $t2, $t2, $t3
    slt     $v0, $t1, $t5
    bnez    $v0, .L800C44DC
    addu    $a2, $a2, $t9
    j       .L800C43E4
    addiu   $v0, $s2, 0x1
.L800C461C:
    lw      $fp, 0x30($sp)
    lw      $s7, 0x2C($sp)
    lw      $s6, 0x28($sp)
    lw      $s5, 0x24($sp)
    lw      $s4, 0x20($sp)
    lw      $s3, 0x1C($sp)
    lw      $s2, 0x18($sp)
    lw      $s1, 0x14($sp)
    lw      $s0, 0x10($sp)
    lui     $v0, (0x1F800000 >> 16)
    sw      $t7, (0x1F800000 & 0xFFFF)($v0)
    jr      $ra
    addiu   $sp, $sp, 0x38
endlabel func_800C2E24
