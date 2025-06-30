.include "macro.inc"

.data 
decodeSize:
.word 0xFFFFFF
D_80075C98:
.zero 36
D_80075CBC:
.zero 4

.set noat
.set noreorder

.text

glabel DecDCTvlcSize2
    size = $a0
    previous = $v0
    la        $t0, decodeSize
    add       $at, size, -1
    blez      $at, 0f
    lw        previous, 0($t0)
    sll       $at, size, 1
    j         $ra
    sw        $at, 0($t0)
  0:
    li        $at, 0xFFFFFF
    j         $ra
    sw        $at, 0($t0)


glabel DecDCTvlc2
    bs = $a0
    buf = $a1
    table = $a2
    la         $t0, decodeSize
    add        table, 0x800
    li         $at, 0x10000
    add        $a3, table, $at
    bnez       bs, 0f
    lw         $t1, 0x0($t0)
    la         $t0, D_80075C98
    lw         $a0, 0x0($t0)
    lw         $a1, 0x4($t0)
    lw         $v0, 0x8($t0)
    lw         $v1, 0xC($t0)
    lw         $t4, 0x10($t0)
    lw         $t5, 0x14($t0)
    lw         $t7, 0x18($t0)
    lw         $t8, 0x1C($t0)
    lw         $t9, 0x20($t0)
    add        $t1, $t1
    b          13f
    add        $t6, $a1, $t1
  0:
    add        $t5, $zero, $zero
    add        $t7, $zero, $zero
    add        $t8, $zero, $zero
    add        $t9, $zero, $zero
    add        $t1, $t1
    add        $t6, buf, $t1
    lw         $t1, 0x0(bs)
    lhu        $t4, 0x4(bs)
    lhu        $t2, 0x6(bs)
    lhu        $v0, 0x8(bs)
    lhu        $v1, 0xA(bs)
    add        $t2, -0x3
    bltz       $t2, 1f
    sll        $t4, 10
    add        $t5, $zero, 0x1
  1:
    add        $a0, 0xC
    sll        $v0, 16
    or         $v0, $v1
    or         $v1, $zero, $zero
    sw         $t1, 0x0($a1)
    and        $t1, 0xFFFF
    sll        $t1, 2
    addu       $t1, 0x4
    add        $t1, $a1
    la         $t0, D_80075CBC
    sw         $t1, 0x0($t0)
    add        $a1, 0x2
  2:
    beqz       $t5, 10f
    srl        $t0, $v0, 22
    xor        $at, $t0, 0x3FF
    beqz       $at, 19f
    add        $a1, 0x2
    add        $at, $t5, -0x3
    bltz       $at, 3f
    add        $at, $a2, -0x400
    add        $at, -0x400
  3:
    srl        $t0, $v0, 24
    sll        $t0, 2
    add        $t0, $at
    lhu        $t1, 0x0($t0)
    lhu        $t2, 0x2($t0)
    and        $t0, $zero, $zero
    beqz       $t2, 5f
    sll        $v0, $t1
    add        $at, $zero, 0x20
    sub        $at, $t2
    srl        $t0, $v0, $at
    bltz       $v0, 4f
    sll        $v0, $t2
    add        $t3, $zero, -0x1
    srl        $t3, $at
    sub        $t0, $t3
  4:
    add        $v1, $t2
  5:
    add        $v1, $t1
    and        $at, $v1, 0x10
    beqz       $at, 6f
    and        $v1, 0xF
    lhu        $t1, 0x0($a0)
    add        $a0, 0x2
    sll        $t1, $v1
    or         $v0, $t1
  6:
    add        $at, $t5, -0x2
    bgtz       $at, 8f
    add        $t1, $t9, $t0
    beqz       $at, 7f
    add        $t1, $t8, $t0
    add        $t1, $t7, $t0
    b          9f
    add        $t7, $t0
  7:
    b          9f
    add        $t8, $t0
  8:
    add        $t9, $t0
  9:
    sll        $t1, 2
    and        $t1, 0x3FF
    or         $t1, $t4, $t1
    add        $t5, 0x1
    add        $at, $t5, -0x7
    bnez       $at, 12f
    sh         $t1, 0x0($a1)
    b          12f
    add        $t5, -0x6
10:
    xor        $at, $t0, 0x1FF
    beqz       $at, 19f
    add        $a1, 0x2
    sll        $v0, 10
    add        $v1, 0xA
    and        $at, $v1, 0x10
    beqz       $at, 11f
    and        $v1, 0xF
    lhu        $t1, 0x0($a0)
    add        $a0, 0x2
    sll        $t1, $v1
    or         $v0, $t1
  11:
    or         $t0, $t4, $t0
    sh         $t0, 0x0($a1)
  12:
    subu       $at, $a1, $t6
    bgez       $at, 22f
    add        $a1, 0x2
  13:
    srl        $t0, $v0, 19
    sll        $t0, 3
    add        $t0, $a2
    lw         $t1, 0x0($t0)
    .nop
    bnez       $t1, 15f
    and        $at, $t1, 0xFF
    sll        $v0, 8
    add        $v1, 0x8
    and        $at, $v1, 0x10
    beqz       $at, 14f
    and        $v1, 0xF
    lhu        $t0, 0x0($a0)
    add        $a0, 0x2
    sll        $t0, $v1
    or         $v0, $t0
  14:
    srl        $t0, $v0, 23
    sll        $t0, 2
    add        $t0, $a3
    lw         $t1, 0x0($t0)
    add        $t3, $zero, $zero
    b          16f
    and        $at, $t1, 0xFF
  15:
    lw         $t3, 0x4($t0)
  16:
    sll        $v0, $at
    add        $v1, $at
    and        $at, $v1, 0x10
    beqz       $at, 17f
    and        $v1, 0xF
    lhu        $t0, 0x0($a0)
    add        $a0, 0x2
    sll        $t0, $v1
    or         $v0, $t0
  17:
    srl        $t1, 16
    xor        $at, $t1, 0x7C1F
    beqz       $at, 18f
    xor        $at, $t1, 0xFE00
    beqz       $at, 2b
    sh         $t1, 0x0($a1)
    beqz       $t3, 13b
    add        $a1, 0x2
    and        $t2, $t3, 0xFFFF
    xor        $at, $t2, 0x7C1F
    beqz       $at, 18f
    xor        $at, $t2, 0xFE00
    beqz       $at, 2b
    sh         $t2, 0x0($a1)
    srl        $t2, $t3, 16
    beqz       $t2, 13b
    add        $a1, 0x2
    xor        $at, $t2, 0x7C1F
    beqz       $at, 18f
    xor        $at, $t2, 0xFE00
    beqz       $at, 2b
    sh         $t2, 0x0($a1)
    b          13b
    add        $a1, 0x2
  18:
    srl        $t0, $v0, 16
    sh         $t0, 0x0($a1)
    add        $a1, 0x2
    lhu        $t0, 0x0($a0)
    add        $a0, 0x2
    sll        $v0, 16
    sll        $t0, $v1
    b          13b
    or         $v0, $t0
  19:
    la         $t0, D_80075CBC
    lw         $t1, 0x0($t0)
    or         $t0, $zero, 0xFE00
  20:
    subu       $at, $a1, $t1
    bgez       $at, 21f
    .nop
    sh         $t0, 0x0($a1)
    b          20b
    add        $a1, 0x2
  21:
    j          $ra
    add        $v0, $zero, $zero
  22:
    la         $t0, D_80075C98
    sw         $a0, 0x0($t0)
    sw         $a1, 0x4($t0)
    sw         $v0, 0x8($t0)
    sw         $v1, 0xC($t0)
    sw         $t4, 0x10($t0)
    sw         $t5, 0x14($t0)
    sw         $t7, 0x18($t0)
    sw         $t8, 0x1C($t0)
    sw         $t9, 0x20($t0)
    j          $ra
    add        $v0, $zero, 0x1
