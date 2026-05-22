nonmatching func_800CACD0, 0x1DC

glabel func_800CACD0
    /* 624D0 800CACD0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 624D4 800CACD4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 624D8 800CACD8 21908000 */  addu       $s2, $a0, $zero
    /* 624DC 800CACDC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 624E0 800CACE0 2188A000 */  addu       $s1, $a1, $zero
    /* 624E4 800CACE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 624E8 800CACE8 0F80103C */  lui        $s0, %hi(vs_battle_menuState)
    /* 624EC 800CACEC C0510392 */  lbu        $v1, %lo(vs_battle_menuState)($s0)
    /* 624F0 800CACF0 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 624F4 800CACF4 64006214 */  bne        $v1, $v0, .L800CAE88
    /* 624F8 800CACF8 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 624FC 800CACFC 21202002 */  addu       $a0, $s1, $zero
    /* 62500 800CAD00 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 62504 800CAD04 6A4E40A0 */  sb         $zero, %lo(vs_battle_shortcutInvoked)($v0)
    /* 62508 800CAD08 0F80023C */  lui        $v0, %hi(D_800F4FDB)
    /* 6250C 800CAD0C F82A030C */  jal        func_800CABE0
    /* 62510 800CAD10 DB4F40A0 */   sb        $zero, %lo(D_800F4FDB)($v0)
    /* 62514 800CAD14 0F80033C */  lui        $v1, %hi(D_800F4EA0)
    /* 62518 800CAD18 A04E62AC */  sw         $v0, %lo(D_800F4EA0)($v1)
    /* 6251C 800CAD1C 0F80033C */  lui        $v1, %hi(D_800F4E98)
    /* 62520 800CAD20 984E6224 */  addiu      $v0, $v1, %lo(D_800F4E98)
    /* 62524 800CAD24 020040A4 */  sh         $zero, 0x2($v0)
    /* 62528 800CAD28 01000224 */  addiu      $v0, $zero, 0x1
    /* 6252C 800CAD2C C05112A2 */  sb         $s2, %lo(vs_battle_menuState)($s0)
    /* 62530 800CAD30 03002016 */  bnez       $s1, .L800CAD40
    /* 62534 800CAD34 984E62A4 */   sh        $v0, %lo(D_800F4E98)($v1)
    /* 62538 800CAD38 B600030C */  jal        vs_battle_playSfx10
    /* 6253C 800CAD3C 00000000 */   nop
  .L800CAD40:
    /* 62540 800CAD40 0F80103C */  lui        $s0, %hi(vs_battle_menuItems)
    /* 62544 800CAD44 C0B9028E */  lw         $v0, %lo(vs_battle_menuItems)($s0)
    /* 62548 800CAD48 00000000 */  nop
    /* 6254C 800CAD4C 51004014 */  bnez       $v0, .L800CAE94
    /* 62550 800CAD50 01000224 */   addiu     $v0, $zero, 0x1
    /* 62554 800CAD54 06000424 */  addiu      $a0, $zero, 0x6
    /* 62558 800CAD58 0F80033C */  lui        $v1, %hi(_loadedSubMenu)
    /* 6255C 800CAD5C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 62560 800CAD60 60F8010C */  jal        func_8007E180
    /* 62564 800CAD64 ADB962A0 */   sb        $v0, %lo(_loadedSubMenu)($v1)
    /* 62568 800CAD68 8F0F010C */  jal        vs_main_allocHeapR
    /* 6256C 800CAD6C 240B0424 */   addiu     $a0, $zero, 0xB24
    /* 62570 800CAD70 21400000 */  addu       $t0, $zero, $zero
    /* 62574 800CAD74 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* 62578 800CAD78 DCB96D24 */  addiu      $t5, $v1, %lo(vs_main_skills)
    /* 6257C 800CAD7C 01000C24 */  addiu      $t4, $zero, 0x1
    /* 62580 800CAD80 21388001 */  addu       $a3, $t4, $zero
    /* 62584 800CAD84 0F80033C */  lui        $v1, %hi(D_800EBD68)
    /* 62588 800CAD88 68BD6B24 */  addiu      $t3, $v1, %lo(D_800EBD68)
    /* 6258C 800CAD8C 21506001 */  addu       $t2, $t3, $zero
    /* 62590 800CAD90 0680033C */  lui        $v1, %hi(D_80060022)
    /* 62594 800CAD94 0F80043C */  lui        $a0, %hi(vs_battle_stringBuf)
    /* 62598 800CAD98 22006594 */  lhu        $a1, %lo(D_80060022)($v1)
    /* 6259C 800CAD9C 000A4324 */  addiu      $v1, $v0, 0xA00
    /* 625A0 800CADA0 8C4E83AC */  sw         $v1, %lo(vs_battle_stringBuf)($a0)
    /* 625A4 800CADA4 0F80033C */  lui        $v1, %hi(vs_battle_rowTypeBuf)
    /* 625A8 800CADA8 C0B902AE */  sw         $v0, %lo(vs_battle_menuItems)($s0)
    /* 625AC 800CADAC 600A4224 */  addiu      $v0, $v0, 0xA60
    /* 625B0 800CADB0 844E62AC */  sw         $v0, %lo(vs_battle_rowTypeBuf)($v1)
  .L800CADB4:
    /* 625B4 800CADB4 2110EB00 */  addu       $v0, $a3, $t3
    /* 625B8 800CADB8 00004491 */  lbu        $a0, 0x0($t2)
    /* 625BC 800CADBC 00004290 */  lbu        $v0, 0x0($v0)
    /* 625C0 800CADC0 00000000 */  nop
    /* 625C4 800CADC4 2A108200 */  slt        $v0, $a0, $v0
    /* 625C8 800CADC8 17004010 */  beqz       $v0, .L800CAE28
    /* 625CC 800CADCC 0F80023C */   lui       $v0, %hi(D_800EBD68)
    /* 625D0 800CADD0 04480C01 */  sllv       $t1, $t4, $t0
    /* 625D4 800CADD4 68BD4224 */  addiu      $v0, $v0, %lo(D_800EBD68)
    /* 625D8 800CADD8 2110E200 */  addu       $v0, $a3, $v0
    /* 625DC 800CADDC 00004690 */  lbu        $a2, 0x0($v0)
    /* 625E0 800CADE0 40100400 */  sll        $v0, $a0, 1
    /* 625E4 800CADE4 21104400 */  addu       $v0, $v0, $a0
    /* 625E8 800CADE8 80100200 */  sll        $v0, $v0, 2
    /* 625EC 800CADEC 21104400 */  addu       $v0, $v0, $a0
    /* 625F0 800CADF0 80100200 */  sll        $v0, $v0, 2
    /* 625F4 800CADF4 21184D00 */  addu       $v1, $v0, $t5
  .L800CADF8:
    /* 625F8 800CADF8 0C00628C */  lw         $v0, 0xC($v1)
    /* 625FC 800CADFC 00000000 */  nop
    /* 62600 800CAE00 C2130200 */  srl        $v0, $v0, 15
    /* 62604 800CAE04 01004230 */  andi       $v0, $v0, 0x1
    /* 62608 800CAE08 03004010 */  beqz       $v0, .L800CAE18
    /* 6260C 800CAE0C 00000000 */   nop
    /* 62610 800CAE10 8A2B0308 */  j          .L800CAE28
    /* 62614 800CAE14 2528A900 */   or        $a1, $a1, $t1
  .L800CAE18:
    /* 62618 800CAE18 01008424 */  addiu      $a0, $a0, 0x1
    /* 6261C 800CAE1C 2A108600 */  slt        $v0, $a0, $a2
    /* 62620 800CAE20 F5FF4014 */  bnez       $v0, .L800CADF8
    /* 62624 800CAE24 34006324 */   addiu     $v1, $v1, 0x34
  .L800CAE28:
    /* 62628 800CAE28 0200E724 */  addiu      $a3, $a3, 0x2
    /* 6262C 800CAE2C 01000825 */  addiu      $t0, $t0, 0x1
    /* 62630 800CAE30 03000229 */  slti       $v0, $t0, 0x3
    /* 62634 800CAE34 DFFF4014 */  bnez       $v0, .L800CADB4
    /* 62638 800CAE38 02004A25 */   addiu     $t2, $t2, 0x2
    /* 6263C 800CAE3C 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 62640 800CAE40 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 62644 800CAE44 B5006290 */  lbu        $v0, 0xB5($v1)
    /* 62648 800CAE48 00000000 */  nop
    /* 6264C 800CAE4C 02004010 */  beqz       $v0, .L800CAE58
    /* 62650 800CAE50 00000000 */   nop
    /* 62654 800CAE54 0100A534 */  ori        $a1, $a1, 0x1
  .L800CAE58:
    /* 62658 800CAE58 AB006290 */  lbu        $v0, 0xAB($v1)
    /* 6265C 800CAE5C 00000000 */  nop
    /* 62660 800CAE60 0300422C */  sltiu      $v0, $v0, 0x3
    /* 62664 800CAE64 02004014 */  bnez       $v0, .L800CAE70
    /* 62668 800CAE68 00000000 */   nop
    /* 6266C 800CAE6C 2001A534 */  ori        $a1, $a1, 0x120
  .L800CAE70:
    /* 62670 800CAE70 0680023C */  lui        $v0, %hi(D_80060022)
    /* 62674 800CAE74 220045A4 */  sh         $a1, %lo(D_80060022)($v0)
    /* 62678 800CAE78 C324030C */  jal        func_800C930C
    /* 6267C 800CAE7C 02000424 */   addiu     $a0, $zero, 0x2
    /* 62680 800CAE80 A52B0308 */  j          .L800CAE94
    /* 62684 800CAE84 01000224 */   addiu     $v0, $zero, 0x1
  .L800CAE88:
    /* 62688 800CAE88 B800030C */  jal        vs_battle_playInvalidSfx
    /* 6268C 800CAE8C 00000000 */   nop
    /* 62690 800CAE90 21100000 */  addu       $v0, $zero, $zero
  .L800CAE94:
    /* 62694 800CAE94 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 62698 800CAE98 1800B28F */  lw         $s2, 0x18($sp)
    /* 6269C 800CAE9C 1400B18F */  lw         $s1, 0x14($sp)
    /* 626A0 800CAEA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 626A4 800CAEA4 0800E003 */  jr         $ra
    /* 626A8 800CAEA8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CACD0
