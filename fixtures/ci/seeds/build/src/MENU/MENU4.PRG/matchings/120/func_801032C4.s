nonmatching func_801032C4, 0xE0

glabel func_801032C4
    /* AC4 801032C4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* AC8 801032C8 2400B1AF */  sw         $s1, 0x24($sp)
    /* ACC 801032CC 21888000 */  addu       $s1, $a0, $zero
    /* AD0 801032D0 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* AD4 801032D4 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* AD8 801032D8 2120A000 */  addu       $a0, $a1, $zero
    /* ADC 801032DC 2800BFAF */  sw         $ra, 0x28($sp)
    /* AE0 801032E0 2000B0AF */  sw         $s0, 0x20($sp)
    /* AE4 801032E4 1C684224 */  addiu      $v0, $v0, 0x681C
    /* AE8 801032E8 08002016 */  bnez       $s1, .L8010330C
    /* AEC 801032EC 1400A2AF */   sw        $v0, 0x14($sp)
    /* AF0 801032F0 1000A527 */  addiu      $a1, $sp, 0x10
    /* AF4 801032F4 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* AF8 801032F8 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* AFC 801032FC 3AF3030C */  jal        vs_mainMenu_setUiShield
    /* B00 80103300 1800A627 */   addiu     $a2, $sp, 0x18
    /* B04 80103304 DF0C0408 */  j          .L8010337C
    /* B08 80103308 00000000 */   nop
  .L8010330C:
    /* B0C 8010330C 1B002006 */  bltz       $s1, .L8010337C
    /* B10 80103310 0400222A */   slti      $v0, $s1, 0x4
    /* B14 80103314 19004010 */  beqz       $v0, .L8010337C
    /* B18 80103318 FFFF2226 */   addiu     $v0, $s1, -0x1
    /* B1C 8010331C 40180200 */  sll        $v1, $v0, 1
    /* B20 80103320 21186200 */  addu       $v1, $v1, $v0
    /* B24 80103324 00190300 */  sll        $v1, $v1, 4
    /* B28 80103328 21188300 */  addu       $v1, $a0, $v1
    /* B2C 8010332C 48006294 */  lhu        $v0, 0x48($v1)
    /* B30 80103330 00000000 */  nop
    /* B34 80103334 0D004010 */  beqz       $v0, .L8010336C
    /* B38 80103338 40801100 */   sll       $s0, $s1, 1
    /* B3C 8010333C 21801102 */  addu       $s0, $s0, $s1
    /* B40 80103340 00811000 */  sll        $s0, $s0, 4
    /* B44 80103344 18001026 */  addiu      $s0, $s0, 0x18
    /* B48 80103348 21809000 */  addu       $s0, $a0, $s0
    /* B4C 8010334C 21200002 */  addu       $a0, $s0, $zero
    /* B50 80103350 1000A527 */  addiu      $a1, $sp, 0x10
    /* B54 80103354 460C040C */  jal        func_80103118
    /* B58 80103358 1800A627 */   addiu     $a2, $sp, 0x18
    /* B5C 8010335C B00B040C */  jal        func_80102EC0
    /* B60 80103360 21200002 */   addu      $a0, $s0, $zero
    /* B64 80103364 DF0C0408 */  j          .L8010337C
    /* B68 80103368 00000000 */   nop
  .L8010336C:
    /* B6C 8010336C 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* B70 80103370 08000424 */   addiu     $a0, $zero, 0x8
    /* B74 80103374 88F4030C */  jal        vs_mainMenu_resetStats
    /* B78 80103378 00000000 */   nop
  .L8010337C:
    /* B7C 8010337C 9223030C */  jal        vs_battle_getMenuItem
    /* B80 80103380 14002426 */   addiu     $a0, $s1, 0x14
    /* B84 80103384 01000324 */  addiu      $v1, $zero, 0x1
    /* B88 80103388 060043A0 */  sb         $v1, 0x6($v0)
    /* B8C 8010338C 1400A28F */  lw         $v0, 0x14($sp)
    /* B90 80103390 2800BF8F */  lw         $ra, 0x28($sp)
    /* B94 80103394 2400B18F */  lw         $s1, 0x24($sp)
    /* B98 80103398 2000B08F */  lw         $s0, 0x20($sp)
    /* B9C 8010339C 0800E003 */  jr         $ra
    /* BA0 801033A0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_801032C4
