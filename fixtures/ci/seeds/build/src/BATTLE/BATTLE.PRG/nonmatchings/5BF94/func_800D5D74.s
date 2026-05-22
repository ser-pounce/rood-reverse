nonmatching func_800D5D74, 0x8C

glabel func_800D5D74
    /* 6D574 800D5D74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D578 800D5D78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6D57C 800D5D7C 2180A000 */  addu       $s0, $a1, $zero
    /* 6D580 800D5D80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6D584 800D5D84 06000286 */  lh         $v0, 0x6($s0)
    /* 6D588 800D5D88 0000038E */  lw         $v1, 0x0($s0)
    /* 6D58C 800D5D8C C0100200 */  sll        $v0, $v0, 3
    /* 6D590 800D5D90 21384300 */  addu       $a3, $v0, $v1
    /* 6D594 800D5D94 4C0D828C */  lw         $v0, 0xD4C($a0)
    /* 6D598 800D5D98 0000E68C */  lw         $a2, 0x0($a3)
    /* 6D59C 800D5D9C 02004384 */  lh         $v1, 0x2($v0)
    /* 6D5A0 800D5DA0 FF01C230 */  andi       $v0, $a2, 0x1FF
    /* 6D5A4 800D5DA4 12004314 */  bne        $v0, $v1, .L800D5DF0
    /* 6D5A8 800D5DA8 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D5AC 800D5DAC 0F80023C */  lui        $v0, %hi(D_800F56A8)
    /* 6D5B0 800D5DB0 A8564224 */  addiu      $v0, $v0, %lo(D_800F56A8)
    /* 6D5B4 800D5DB4 022C0600 */  srl        $a1, $a2, 16
    /* 6D5B8 800D5DB8 1C00A530 */  andi       $a1, $a1, 0x1C
    /* 6D5BC 800D5DBC 2128A200 */  addu       $a1, $a1, $v0
    /* 6D5C0 800D5DC0 421A0600 */  srl        $v1, $a2, 9
    /* 6D5C4 800D5DC4 FF016330 */  andi       $v1, $v1, 0x1FF
    /* 6D5C8 800D5DC8 42130600 */  srl        $v0, $a2, 13
    /* 6D5CC 800D5DCC 003F4230 */  andi       $v0, $v0, 0x3F00
    /* 6D5D0 800D5DD0 21186200 */  addu       $v1, $v1, $v0
    /* 6D5D4 800D5DD4 0400E694 */  lhu        $a2, 0x4($a3)
    /* 6D5D8 800D5DD8 0000A58C */  lw         $a1, 0x0($a1)
    /* 6D5DC 800D5DDC 00340600 */  sll        $a2, $a2, 16
    /* 6D5E0 800D5DE0 A53D030C */  jal        func_800CF694
    /* 6D5E4 800D5DE4 25306600 */   or        $a2, $v1, $a2
    /* 6D5E8 800D5DE8 E055030C */  jal        func_800D5780
    /* 6D5EC 800D5DEC 21200002 */   addu      $a0, $s0, $zero
  .L800D5DF0:
    /* 6D5F0 800D5DF0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6D5F4 800D5DF4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D5F8 800D5DF8 0800E003 */  jr         $ra
    /* 6D5FC 800D5DFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D5D74
