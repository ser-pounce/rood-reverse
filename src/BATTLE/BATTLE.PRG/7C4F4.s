.include "macro.inc"

.set noat
.set noreorder

glabel func_800E4CF4
    lw         $t0, 0x4($a1)
    la         $v0, D_800F5878
    sll        $v1, $a2, 2
    addu       $v0, $v1
    srl        $t1, $t0, 5
    lw         $at, 0x10($a1)
    and        $t1, 0xFF
    li         $t2, 0x34
    mult       $t1, $t2
    addu       $v1, $a0, $v1
    lw         $v0, 0x0($v0)
    and        $t3, $t0, 0x7
    srl        $t4, $t0, 3
    and        $t4, 0x3
    beqz       $v0, 50f
     lw        $v1, 0x1A4($v1)
    sll        $t3, 5
    sll        $t4, 3
    srl        $v1, 6
    and        $v1, 0x3
    lw         $v0, 0x10($v0)
    la         $t0, vs_main_actions
    mflo       $t5
    slt        $a3, $v1, 0x2
    bnez       $a3, 50f
     addu      $t3, $t4
    addu       $t5, $t0
    lhu        $t5, 0xE($t5)
    srl        $t0, $v0, 7
    and        $t0, 0x2
    srl        $t2, $v0, 14
    and        $t2, 0x4
    or         $t0, $t2
    slt        $a3, $v1, 0x3
    sll        $t4, $at, 26
    bgez       $t4, 49f
     and       $v0, 0x1
    or         $v0, $t0, $v0
    beqz       $a3, 50f
     sll       $a3, $t5, 23
    bltz       $a3, 49f
     srl       $a3, $t5, 9
    and        $a3, $v0
    beqz       $a3, 50f
  49:
     addu      $t3, $a0
    lw         $t3, 0x230($t3)
    srl        $t0, $at, 4
    and        $t0, 0x1
    slt        $t2, $v1, 0x3
    and        $t0, $t2
    bnez       $t0, 50f
     srl       $t3, 1
    lbu        $a3, 0x88($a0)
    and        $t3, 0x1
    sub        $a2, $a3
    sltu       $a2, 0x1
    and        $a2, $t3
    bnez       $a2, 50f
     nop
    jr         $ra
     li        $v0, 0x1
  50:
    jr         $ra
     addu      $v0, $zero, $zero
alabel func_800E4DF8
    lw         $t0, 0x54($a0)
    li         $t1, 0xDC
    li         $t2, 0x4
    li         $t3, 0x34
    mult       $a1, $t1
    lw         $t0, 0x3C($t0)
    sll        $t5, $a1, 2
    addu       $t5, $a2
    la         $t4, vs_main_actions
    sll        $v0, $t5, 2
    addu       $v0, $t0, $v0
    lhu        $v0, 0x8C0($v0)
    lh         $v1, 0x1C($t0)
    mflo       $a3
    lw         $t6, 0x948($t0)
    addu       $a3, $t0, $a3
    mult       $t3, $v0
    lh         $a3, 0x398($a3)
    and        $t8, $t6, 0x2000
    lw         $t7, 0x18($t0)
    slt        $a3, 0x2
    bnez       $a3, 55f
     and       $t2, $t7, 0xFFFF
    mflo       $a2
    srl        $t3, $t7, 16
    addu       $a2, $t4, $a2
    lbu        $a3, 0x2($a2)
    li         $t7, 0x1
    li         $t9, 0x4
    lbu        $a2, 0x3($a2)
    srl        $a3, 1
    and        $a3, 0x7
    beqz       $t8, 51f
     li        $t8, 0x3
    li         $t8, 0x1
    sllv       $t8, $t8, $a3
    and        $t8, 0x6
    beqz       $t8, 55f
     li        $t8, 0x3
  51:
    bne        $a3, $t7, 52f
     slt       $a1, $v1, $a2
    bnez       $a1, 55f
     and       $a1, $t6, 0x1000
    bnez       $a1, 55f
     nop
    bgez       $zero, 54f
  52:
     srl       $t3, 1
    bne        $a3, $t8, 53f
     addu      $t3, $a2, $t3
    slt        $a1, $t2, $t3
    bnez       $a1, 55f
     nop
    bgez       $zero, 54f
  53:
     lh        $a1, 0x14C($t0)
    bne        $a3, $t9, 54f
     slt       $a1, $a2
    bnez       $a1, 55f
     nop
  54:
    bgez       $zero, 56f
     li        $v0, 0x1
  55:
    addu       $v0, $zero, $zero
  56:
    sll        $t5, 3
    addu       $a0, $t5
    lw         $a2, 0x230($a0)
    sll        $v1, $v0, 7
    add        $a3, $zero, -0x81
    and        $a2, $a3
    or         $a2, $v1
    jr         $ra
     sw        $a2, 0x230($a0)
alabel func_800E4F14
    lw         $t0, 0x54($a0)
    lbu        $t1, 0x17($a0)
    lw         $t0, 0x3C($t0)
    li         $v0, 0x2
    lw         $t2, 0x18($t0)
    li         $v1, 0x2
    and        $t3, $t2, 0xFFFF
    mult       $v0, $t3
    lw         $t4, 0x1C($t0)
    srl        $t2, 16
    lui        $t5, (0x90000 >> 16)
    and        $t6, $t4, 0xFFFF
    lw         $t8, 0x948($t0)
    mflo       $v0
    or         $t5, $zero, 0xE2B0
    srl        $t4, 16
    mult       $t6, $v1
    slt        $v0, $t2
    sb         $v0, 0x12($a0)
    beqz       $t1, 57f
     addu      $a3, $zero, $zero
    slt        $a3, $t6, $t1
    mflo       $v1
    bnez       $a3, 57f
     nop
    slt        $a3, $v1, $t4
  57:
    sb         $a3, 0x11($a0)
    and        $v0, $t8, $t5
    sltu       $a3, $v0, 0x1
    beqz       $a3, 58f
     sltu      $t2, $t1, 0x1
    and        $t3, $t8, 0x1000
    sltu       $t3, 0x1
    or         $a3, $t2, $t3
    bnez       $a3, 59f
     addu      $a3, $zero, $zero
  58:
    xor        $a3, 0x1
  59:
    jr         $ra
     sb        $a3, 0x10($a0)
alabel func_800E4FB0
    lw         $t0, 0x54($a0)
    sll        $a1, 2
    lbu        $t0, 0x9($t0)
    li         $v0, 0xA
    bne        $t0, $v0, 60f
     addu      $a1, $a0, $a1
    addiu      $a2, 0x80
  60:
    mult       $v0, $v0
    lw         $t0, 0x1E4($a1)
    mflo       $v0
    jr         $ra
     sltu      $v0, $t0
alabel func_800E4FE0
    lw         $t0, 0x17C($a0)
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    li         $v0, 0x1
    lw         $t1, 0x180($t8)
    lh         $a0, 0x4C($t8)
    sb         $a1, 0x1($t8)
    sb         $v0, 0x9($t8)
    lh         $a1, 0x50($t8)
    sll        $t2, $t1, 16
    or         $t2, $t0, $t2
    sw         $t2, 0x158($t8)
    sub        $a0, $t0, $a0
    jal        ratan2
     sub       $a1, $t1, $a1
    addu       $ra, $t9, $zero
    addu       $a2, $v0, $zero
    addu       $a0, $t8, $zero
    bgez       $zero, func_800E50A0
     li        $a1, 0x1
alabel func_800E5030
    lw         $t6, 0x168($a0)
    mult       $a1, $a1
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    jal        func_800E42E0
     addu      $a0, $t6, $zero
    lh         $t0, 0x4C($t8)
    and        $a0, $t6, 0xFF
    sll        $a2, $t6, 8
    srl        $a2, 24
    sll        $a0, 7
    lh         $t1, 0x4E($t8)
    sll        $a2, 7
    addiu      $a0, 0x40
    addiu      $a2, 0x40
    lh         $t2, 0x50($t8)
    sub        $a0, $t0
    sub        $a1, $v0, $t1
    jal        func_800E4660
     sub       $a2, $t2
    mflo       $v1
    addu       $ra, $t9, $zero
    addu       $a0, $t8, $zero
    sltu       $v0, $v1
    bnez       $v0, func_800DEEFC
     li        $a1, 0x0
    li         $a1, 0x0
    addu       $a2, $zero, $zero
alabel func_800E50A0
    lbu        $a3, 0x125($a0)
    la         $t0, jtbl_800F1740
    sll        $a3, 1
    addu       $a3, $a1
    sll        $a3, 2
    addu       $t0, $a3
    lw         $t0, 0x0($t0)
    addu       $a1, $a2, $zero
    jr         $t0
     lui       $t1, %hi(D_800F58D4)
    addiu      $t1, %lo(D_800F58D4)
    lw         $a3, 0x0($t1)
    li         $v1, 0x1
    lui        $a2, %hi(D_800F590C)
    lw         $a2, %lo(D_800F590C)($a2)
  61:
    addiu      $a3, 0x1
    and        $a3, 0xF
    sllv       $v1, $v1, $a3
    and        $v0, $a2, $v1
    beqz       $v0, 61b
     li        $v1, 0x1
    jr         $ra
     sw        $a3, 0x0($t1)
    lui        $a3, (0x1F800374 >> 16)
    sw         $sp, (0x1F800378 & 0xFFFF)($a3)
    jr         $ra
     or        $sp, $a3, (0x1F800374 & 0xFFFF)
    lui        $a3, (0x1F800378 >> 16)
    lw         $sp, (0x1F800378 & 0xFFFF)($a3)
    jr         $ra
alabel func_800E511C
     lui       $a3, (0x800F0000 >> 16)
    lw         $a3, 0x58B8($a3)
    addiu      $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    beqz       $a3, func_800DB89C
     lui       $s0, %hi(D_800F16BC)
    addiu      $s0, %lo(D_800F16BC)
    lw         $t0, 0x0($s0)
    lui        $ra, (0x800E513C >> 16)
    beqz       $t0, func_800DB89C
     or        $ra, (0x800E513C & 0xFFFF)
    jr         $t0
     addiu     $s0, 0x4
alabel func_800E5154
    li         $a3, 0x1
alabel func_800E5158
    lui        $a1, %hi(D_800F58B8)
    lw         $a1, %lo(D_800F58B8)($a1)
    la         $a2, D_800F5878
    sll        $v0, $a0, 2
    addu       $a2, $v0
    lw         $a2, 0x0($a2)
    sltu       $v0, $a1, 0x1
    sltu       $v1, $a2, 0x1
    bnez       $a3, 62f
     or        $v0, $v1
    jr         $ra
     xor       $v0, 0x1
  62:
    bnez       $v0, 63f
     li        $v0, 0x2
    lw         $a2, 0x18C($a2)
    lui        $v1, (0xFF00FF >> 16)
    beqz       $a2, 63f
     or        $v1, (0xFF00FF & 0xFFFF)
    lw         $a0, 0x64($a2)
    lw         $a1, 0x168($a2)
    lw         $a0, 0x0($a0)
    and        $a1, $v1
    and        $a0, $v1
    beq        $a0, $a1, 63f
     li        $v0, 0x0
    li         $v0, 0x1
  63:
    jr         $ra
alabel func_800E51C8
     lui       $v1, (0x800F0000 >> 16)
    addiu      $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    addu       $s0, $a0, $zero
    addu       $s1, $a1, $zero
    or         $a2, $v1, 0x5878
    sll        $v0, $s0, 2
    addu       $a2, $v0
    lw         $a1, 0x0($a2)
    addu       $a0, $s1, $zero
    jal        vs_main_memcpy
     li        $a2, 0x484
    sb         $s0, 0x88($s1)
    li         $v0, 0x140
    sh         $v0, 0xB0($s1)
    li         $v0, 0x3
    sb         $v0, 0xB2($s1)
    sw         $zero, 0x190($s1)
    sb         $zero, 0x19A($s1)
    li         $v0, 0x3
    sb         $v0, 0x29($s1)
    li         $v0, 0x1
    sb         $v0, 0x23($s1)
  64:
    lw         $ra, 0x18($sp)
    lw         $s0, 0x10($sp)
    lw         $s1, 0x14($sp)
    jr         $ra
     addiu     $sp, 0x20
alabel func_800E5240
    addiu      $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    jal        func_800E5158
     addu      $a3, $zero, $zero
    beqz       $v0, 64b
     lui       $ra, (0x800E522C >> 16)
    lw         $a0, 0x18C($a2)
    addu       $s0, $a2, $zero
    beqz       $a0, 64b
     or        $ra, (0x800E522C & 0xFFFF)
    sw         $zero, 0x18C($s0)
    j          vs_main_freeHeapR
     li        $a1, 0x7
alabel func_800E527C
    addiu      $sp, -0x20
    sw         $ra, 0x18($sp)
    sw         $s1, 0x14($sp)
    sll        $a2, 16
    or         $s1, $a2, $a1
    jal        func_800E5158
     addu      $a3, $zero, $zero
    beqz       $v0, 64b
     sw        $s0, 0x10($sp)
    addu       $s0, $a2, $zero
    jal        func_800D82CC
     addu      $a0, $s0, $zero
    jal        func_800D821C
     addu      $a0, $s0, $zero
    jal        func_800DBF00
     addu      $a0, $s0, $zero
    lw         $a1, 0x18C($s0)
    lbu        $a0, 0x88($s0)
    bnez       $a1, 65f
     addu      $a2, $zero, $zero
    li         $a1, 0x7
    jal        vs_main_allocHeapR
     li        $a0, 0x484
    beqz       $v0, 64b
     li        $a1, 0x484
    sw         $v0, 0x18C($s0)
    jal        func_800E4288
     addu      $a0, $v0, $zero
    lbu        $a0, 0x88($s0)
    addu       $s0, $v0, $zero
  65:
    jal        func_800E51C8
     addu      $a1, $s0, $zero
    sw         $s1, 0x160($s0)
    bgez       $zero, 64b
     li        $v0, 0x1
alabel func_800E5308
    addiu      $sp, -0x30
    sw         $ra, 0x18($sp)
    sw         $s0, 0x10($sp)
    sw         $s1, 0x14($sp)
    jal        func_800E65DC
     sw        $s2, 0x1C($sp)
    lui        $a3, (0x1F800378 >> 16)
    sw         $sp, (0x1F800378 & 0xFFFF)($a3)
    addiu      $sp, $a3, %lo(D_1F800374)
    lui        $s0, %hi(vs_battle_actors)
    lw         $s0, %lo(vs_battle_actors)($s0)
    lui        $a3, (0x1F80037C >> 16)
  66:
    lbu        $t0, 0x8($s0)
    lw         $t1, 0x4($s0)
    and        $t0, 0xC0
    bnez       $t0, .L800E54F0
     sll       $t1, 2
    addu       $s2, $a3, $t1
    lw         $s2, (0x1F80037C & 0xFFFF)($s2)
    jal        func_800E45B4
     lw        $s2, 0x18C($s2)
    sw         $v0, 0x3FC($a3)
    beqz       $s2, .L800E54F0
     lbu       $t3, 0x3($s0)
    sb         $zero, 0x19A($s2)
    lhu        $t5, 0x156($s2)
    lw         $t4, 0x190($s2)
    beqz       $t5, 67f
     srl       $t2, $t4, 5
    add        $t5, -0x1
  67:
    sh         $t5, 0x156($s2)
    and        $t2, 0x7F
    beqz       $t2, 68f
     and       $t3, 0xFC
    add        $t2, -0x1
  68:
    li         $v0, 0x1
    sb         $v0, 0x6($s2)
    sb         $zero, 0x1($s2)
    li         $v0, 0x10
    sb         $v0, 0x15C($s2)
    sb         $zero, 0x2($s2)
    sb         $zero, 0x3($s2)
    lw         $t1, 0x4($s0)
    la         $t0, D_800F4538
    sll        $t1, 2
    addu       $t0, $t1
    lw         $t0, 0x0($t0)
    sb         $t3, 0x3($s0)
    add        $v0, $zero, -0xFE1
    and        $t4, $v0
    sll        $t2, 5
    or         $t4, $t2
    sw         $t4, 0x190($s2)
    lw         $t2, 0x5C($t0)
    lw         $t3, 0x1C($t0)
    lw         $t4, 0x20($t0)
    sw         $t2, 0x34($s2)
    sw         $t3, 0x4C($s2)
    sw         $t4, 0x50($s2)
    lui        $t6, %hi(D_800F58B8)
    lw         $t6, %lo(D_800F58B8)($t6)
    sll        $t5, $t2, 8
    srl        $t5, 24
    and        $t2, 0xFF
    sll        $t5, 6
    sll        $t2, 1
    addu       $t2, $t5
    addu       $t6, $t2, $t6
    lhu        $t6, 0x0($t6)
    and        $t2, $t3, 0xFFFF
    and        $t4, 0xFFFF
    srl        $t3, $t2, 6
    srl        $t5, $t4, 6
    sll        $t5, 16
    or         $t3, $t5
    sw         $t3, 0x120($s2)
    and        $t6, 0xF
    lbu        $v1, 0x125($s2)
    sb         $t6, 0x132($s2)
    sb         $t6, 0x154($s2)
    li         $v0, 0x0
    sw         $zero, 0x3D0($a3)
    bne        $v1, $v0, 69f
     lw        $t3, 0x160($s2)
    addu       $a1, $zero, $zero
    and        $a0, $t3, 0xFFFF
    srl        $a2, $t3, 16
    sub        $a0, $t2
    jal        func_800E4660
     sub       $a2, $t4
    slt        $v0, 0x400
    bnez       $v0, 70f
     addu      $a0, $s2, $zero
    la         $ra, .L800E54F0
    bgez       $zero, 72f
     addu      $a1, $zero, $zero
  69:
    lw         $a0, 0x168($s2)
    lw         $a1, 0x34($s2)
    li         $v0, 0xFF00FF
    and        $a0, $v0
    and        $a1, $v0
    bne        $a0, $a1, 71f
  70:
     li        $a1, 0x0
    jal        func_800DEEFC
     addu      $a0, $s2, $zero
    lbu        $a0, 0x88($s2)
    la         $ra, .L800E54F0
    bgez       $zero, func_800E5240
  71:
     srl       $a1, $t3, 23
    and        $a0, $t3, 0xFFFF
    srl        $a0, 7
    sll        $a1, 16
    or         $a0, $a1
    sw         $a0, 0x168($s2)
    addu       $a0, $s2, $zero
    li         $a1, 0x0
    jal        func_800E50A0
     addu      $a2, $zero, $zero
  .L800E54F0:
    lw         $s0, 0x0($s0)
    lui        $ra, (0x800DB898 >> 16)
    bnez       $s0, 66b
     lui       $a3, (0x1F800378 >> 16)
    lw         $sp, (0x1F800378 & 0xFFFF)($a3)
    bgez       $zero, func_800D9538
     or        $ra, (0x800DB898 & 0xFFFF)
  72:
    lbu        $t0, 0x19B($a0)
    addu       $t9, $ra, $zero
    addu       $t8, $a0, $zero
    lw         $t1, 0x160($a0)
    bnez       $t0, func_800DF8A4
     srl       $t2, $t1, 16
    and        $t1, 0xFFFF
    sw         $t1, 0x17C($a0)
    sw         $t2, 0x180($a0)
    srl        $t3, $t1, 7
    srl        $t4, $t2, 7
    sll        $t4, 16
    or         $t3, $t4
    sw         $t3, 0x168($a0)
    lh         $a0, 0x4C($t8)
    lh         $a1, 0x50($t8)
    sub        $a0, $t1, $a0
    jal        ratan2
     sub       $a1, $t2, $a1
    addu       $ra, $t9, $zero
    addu       $a1, $v0, $zero
    bgez       $zero, func_800E19FC
     addu      $a0, $t8, $zero
endlabel func_800E4CF4
