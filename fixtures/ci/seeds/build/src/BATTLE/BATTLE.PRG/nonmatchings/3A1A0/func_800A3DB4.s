nonmatching func_800A3DB4, 0xB8

glabel func_800A3DB4
    /* 3B5B4 800A3DB4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3B5B8 800A3DB8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 3B5BC 800A3DBC 21888000 */  addu       $s1, $a0, $zero
    /* 3B5C0 800A3DC0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 3B5C4 800A3DC4 2190A000 */  addu       $s2, $a1, $zero
    /* 3B5C8 800A3DC8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3B5CC 800A3DCC 2180C000 */  addu       $s0, $a2, $zero
    /* 3B5D0 800A3DD0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3B5D4 800A3DD4 21282002 */  addu       $a1, $s1, $zero
    /* 3B5D8 800A3DD8 21304002 */  addu       $a2, $s2, $zero
    /* 3B5DC 800A3DDC 01000724 */  addiu      $a3, $zero, 0x1
    /* 3B5E0 800A3DE0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3B5E4 800A3DE4 1000A0AF */  sw         $zero, 0x10($sp)
    /* 3B5E8 800A3DE8 BA9B020C */  jal        func_800A6EE8
    /* 3B5EC 800A3DEC 1400A0AF */   sw        $zero, 0x14($sp)
    /* 3B5F0 800A3DF0 21304000 */  addu       $a2, $v0, $zero
    /* 3B5F4 800A3DF4 2A80D000 */  slt        $s0, $a2, $s0
    /* 3B5F8 800A3DF8 15000016 */  bnez       $s0, .L800A3E50
    /* 3B5FC 800A3DFC 21100000 */   addu      $v0, $zero, $zero
    /* 3B600 800A3E00 0F80023C */  lui        $v0, %hi(D_800F49F0)
    /* 3B604 800A3E04 F049428C */  lw         $v0, %lo(D_800F49F0)($v0)
    /* 3B608 800A3E08 00000000 */  nop
    /* 3B60C 800A3E0C 0000428C */  lw         $v0, 0x0($v0)
    /* 3B610 800A3E10 00000000 */  nop
    /* 3B614 800A3E14 02150200 */  srl        $v0, $v0, 20
    /* 3B618 800A3E18 01004230 */  andi       $v0, $v0, 0x1
    /* 3B61C 800A3E1C 0C004014 */  bnez       $v0, .L800A3E50
    /* 3B620 800A3E20 21100000 */   addu      $v0, $zero, $zero
    /* 3B624 800A3E24 21202002 */  addu       $a0, $s1, $zero
    /* 3B628 800A3E28 02008104 */  bgez       $a0, .L800A3E34
    /* 3B62C 800A3E2C 21284002 */   addu      $a1, $s2, $zero
    /* 3B630 800A3E30 7F008424 */  addiu      $a0, $a0, 0x7F
  .L800A3E34:
    /* 3B634 800A3E34 0200A104 */  bgez       $a1, .L800A3E40
    /* 3B638 800A3E38 C3210400 */   sra       $a0, $a0, 7
    /* 3B63C 800A3E3C 7F00A524 */  addiu      $a1, $a1, 0x7F
  .L800A3E40:
    /* 3B640 800A3E40 C3290500 */  sra        $a1, $a1, 7
    /* 3B644 800A3E44 0D8F020C */  jal        func_800A3C34
    /* 3B648 800A3E48 01000724 */   addiu     $a3, $zero, 0x1
    /* 3B64C 800A3E4C 0100422C */  sltiu      $v0, $v0, 0x1
  .L800A3E50:
    /* 3B650 800A3E50 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3B654 800A3E54 2000B28F */  lw         $s2, 0x20($sp)
    /* 3B658 800A3E58 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3B65C 800A3E5C 1800B08F */  lw         $s0, 0x18($sp)
    /* 3B660 800A3E60 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3B664 800A3E64 0800E003 */  jr         $ra
    /* 3B668 800A3E68 00000000 */   nop
endlabel func_800A3DB4
