nonmatching vs_battle_setMenuItem, 0xE8

glabel vs_battle_setMenuItem
    /* 6065C 800C8E5C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 60660 800C8E60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 60664 800C8E64 2180A000 */  addu       $s0, $a1, $zero
    /* 60668 800C8E68 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6066C 800C8E6C 2188C000 */  addu       $s1, $a2, $zero
    /* 60670 800C8E70 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 60674 800C8E74 80210400 */  sll        $a0, $a0, 6
    /* 60678 800C8E78 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6067C 800C8E7C 3C00B28F */  lw         $s2, 0x3C($sp)
    /* 60680 800C8E80 C0B9428C */  lw         $v0, %lo(vs_battle_menuItems)($v0)
    /* 60684 800C8E84 3800A38F */  lw         $v1, 0x38($sp)
    /* 60688 800C8E88 3C000524 */  addiu      $a1, $zero, 0x3C
    /* 6068C 800C8E8C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 60690 800C8E90 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 60694 800C8E94 21984400 */  addu       $s3, $v0, $a0
    /* 60698 800C8E98 01000224 */  addiu      $v0, $zero, 0x1
    /* 6069C 800C8E9C 04006426 */  addiu      $a0, $s3, 0x4
    /* 606A0 800C8EA0 000062A2 */  sb         $v0, 0x0($s3)
    /* 606A4 800C8EA4 010067A2 */  sb         $a3, 0x1($s3)
    /* 606A8 800C8EA8 0733030C */  jal        vs_battle_rMemzero
    /* 606AC 800C8EAC 020063A2 */   sb        $v1, 0x2($s3)
    /* 606B0 800C8EB0 21280000 */  addu       $a1, $zero, $zero
    /* 606B4 800C8EB4 FA000824 */  addiu      $t0, $zero, 0xFA
    /* 606B8 800C8EB8 E7000624 */  addiu      $a2, $zero, 0xE7
    /* 606BC 800C8EBC FF000724 */  addiu      $a3, $zero, 0xFF
    /* 606C0 800C8EC0 21206002 */  addu       $a0, $s3, $zero
    /* 606C4 800C8EC4 140070A6 */  sh         $s0, 0x14($s3)
    /* 606C8 800C8EC8 160071A6 */  sh         $s1, 0x16($s3)
  .L800C8ECC:
    /* 606CC 800C8ECC 00004392 */  lbu        $v1, 0x0($s2)
    /* 606D0 800C8ED0 00000000 */  nop
    /* 606D4 800C8ED4 07006814 */  bne        $v1, $t0, .L800C8EF4
    /* 606D8 800C8ED8 01005226 */   addiu     $s2, $s2, 0x1
    /* 606DC 800C8EDC 1C0083A0 */  sb         $v1, 0x1C($a0)
    /* 606E0 800C8EE0 01008424 */  addiu      $a0, $a0, 0x1
    /* 606E4 800C8EE4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 606E8 800C8EE8 00004392 */  lbu        $v1, 0x0($s2)
    /* 606EC 800C8EEC C3230308 */  j          .L800C8F0C
    /* 606F0 800C8EF0 01005226 */   addiu     $s2, $s2, 0x1
  .L800C8EF4:
    /* 606F4 800C8EF4 03006614 */  bne        $v1, $a2, .L800C8F04
    /* 606F8 800C8EF8 E500622C */   sltiu     $v0, $v1, 0xE5
    /* 606FC 800C8EFC C9230308 */  j          .L800C8F24
    /* 60700 800C8F00 1C0087A0 */   sb        $a3, 0x1C($a0)
  .L800C8F04:
    /* 60704 800C8F04 05004010 */  beqz       $v0, .L800C8F1C
    /* 60708 800C8F08 1F00A228 */   slti      $v0, $a1, 0x1F
  .L800C8F0C:
    /* 6070C 800C8F0C 1C0083A0 */  sb         $v1, 0x1C($a0)
    /* 60710 800C8F10 01008424 */  addiu      $a0, $a0, 0x1
    /* 60714 800C8F14 0100A524 */  addiu      $a1, $a1, 0x1
    /* 60718 800C8F18 1F00A228 */  slti       $v0, $a1, 0x1F
  .L800C8F1C:
    /* 6071C 800C8F1C EBFF4014 */  bnez       $v0, .L800C8ECC
    /* 60720 800C8F20 00000000 */   nop
  .L800C8F24:
    /* 60724 800C8F24 21106002 */  addu       $v0, $s3, $zero
    /* 60728 800C8F28 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6072C 800C8F2C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 60730 800C8F30 1800B28F */  lw         $s2, 0x18($sp)
    /* 60734 800C8F34 1400B18F */  lw         $s1, 0x14($sp)
    /* 60738 800C8F38 1000B08F */  lw         $s0, 0x10($sp)
    /* 6073C 800C8F3C 0800E003 */  jr         $ra
    /* 60740 800C8F40 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_battle_setMenuItem
