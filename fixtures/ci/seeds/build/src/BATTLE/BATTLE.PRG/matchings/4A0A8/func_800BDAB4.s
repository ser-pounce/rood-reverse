nonmatching func_800BDAB4, 0x100

glabel func_800BDAB4
    /* 552B4 800BDAB4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 552B8 800BDAB8 2800B0AF */  sw         $s0, 0x28($sp)
    /* 552BC 800BDABC 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 552C0 800BDAC0 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 552C4 800BDAC4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 552C8 800BDAC8 EDF6020C */  jal        func_800BDBB4
    /* 552CC 800BDACC FC018424 */   addiu     $a0, $a0, 0x1FC
    /* 552D0 800BDAD0 0A004010 */  beqz       $v0, .L800BDAFC
    /* 552D4 800BDAD4 00000000 */   nop
    /* 552D8 800BDAD8 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 552DC 800BDADC 00000000 */  nop
    /* 552E0 800BDAE0 FE014384 */  lh         $v1, 0x1FE($v0)
    /* 552E4 800BDAE4 00000000 */  nop
    /* 552E8 800BDAE8 1000A3AF */  sw         $v1, 0x10($sp)
    /* 552EC 800BDAEC 00024284 */  lh         $v0, 0x200($v0)
    /* 552F0 800BDAF0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 552F4 800BDAF4 6EF7010C */  jal        func_8007DDB8
    /* 552F8 800BDAF8 1400A2AF */   sw        $v0, 0x14($sp)
  .L800BDAFC:
    /* 552FC 800BDAFC A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 55300 800BDB00 EDF6020C */  jal        func_800BDBB4
    /* 55304 800BDB04 1C028424 */   addiu     $a0, $a0, 0x21C
    /* 55308 800BDB08 0D004010 */  beqz       $v0, .L800BDB40
    /* 5530C 800BDB0C 00000000 */   nop
    /* 55310 800BDB10 A44B038E */  lw         $v1, %lo(D_800F4BA4)($s0)
    /* 55314 800BDB14 00000000 */  nop
    /* 55318 800BDB18 1E026290 */  lbu        $v0, 0x21E($v1)
    /* 5531C 800BDB1C 00000000 */  nop
    /* 55320 800BDB20 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 55324 800BDB24 20026290 */  lbu        $v0, 0x220($v1)
    /* 55328 800BDB28 00000000 */  nop
    /* 5532C 800BDB2C 2100A2A3 */  sb         $v0, 0x21($sp)
    /* 55330 800BDB30 22026290 */  lbu        $v0, 0x222($v1)
    /* 55334 800BDB34 2000A427 */  addiu      $a0, $sp, 0x20
    /* 55338 800BDB38 75F7010C */  jal        func_8007DDD4
    /* 5533C 800BDB3C 2200A2A3 */   sb        $v0, 0x22($sp)
  .L800BDB40:
    /* 55340 800BDB40 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 55344 800BDB44 EDF6020C */  jal        func_800BDBB4
    /* 55348 800BDB48 3C028424 */   addiu     $a0, $a0, 0x23C
    /* 5534C 800BDB4C 0A004010 */  beqz       $v0, .L800BDB78
    /* 55350 800BDB50 00000000 */   nop
    /* 55354 800BDB54 A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 55358 800BDB58 00000000 */  nop
    /* 5535C 800BDB5C 3E024384 */  lh         $v1, 0x23E($v0)
    /* 55360 800BDB60 00000000 */  nop
    /* 55364 800BDB64 1000A3AF */  sw         $v1, 0x10($sp)
    /* 55368 800BDB68 40024284 */  lh         $v0, 0x240($v0)
    /* 5536C 800BDB6C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 55370 800BDB70 7EF7010C */  jal        func_8007DDF8
    /* 55374 800BDB74 1400A2AF */   sw        $v0, 0x14($sp)
  .L800BDB78:
    /* 55378 800BDB78 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 5537C 800BDB7C EDF6020C */  jal        func_800BDBB4
    /* 55380 800BDB80 5C028424 */   addiu     $a0, $a0, 0x25C
    /* 55384 800BDB84 07004010 */  beqz       $v0, .L800BDBA4
    /* 55388 800BDB88 00000000 */   nop
    /* 5538C 800BDB8C A44B028E */  lw         $v0, %lo(D_800F4BA4)($s0)
    /* 55390 800BDB90 00000000 */  nop
    /* 55394 800BDB94 5E024484 */  lh         $a0, 0x25E($v0)
    /* 55398 800BDB98 60024584 */  lh         $a1, 0x260($v0)
    /* 5539C 800BDB9C F0E6030C */  jal        func_800F9BC0
    /* 553A0 800BDBA0 00000000 */   nop
  .L800BDBA4:
    /* 553A4 800BDBA4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 553A8 800BDBA8 2800B08F */  lw         $s0, 0x28($sp)
    /* 553AC 800BDBAC 0800E003 */  jr         $ra
    /* 553B0 800BDBB0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800BDAB4
