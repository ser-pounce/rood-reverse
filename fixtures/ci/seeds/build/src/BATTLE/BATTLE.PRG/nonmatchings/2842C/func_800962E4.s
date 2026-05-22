nonmatching func_800962E4, 0xB8

glabel func_800962E4
    /* 2DAE4 800962E4 0F80023C */  lui        $v0, %hi(D_800F227E)
    /* 2DAE8 800962E8 7E224484 */  lh         $a0, %lo(D_800F227E)($v0)
    /* 2DAEC 800962EC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2DAF0 800962F0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2DAF4 800962F4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2DAF8 800962F8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DAFC 800962FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DB00 80096300 20008228 */  slti       $v0, $a0, 0x20
    /* 2DB04 80096304 08004010 */  beqz       $v0, .L80096328
    /* 2DB08 80096308 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2DB0C 8009630C 0F80023C */  lui        $v0, %hi(D_800F1BAC)
    /* 2DB10 80096310 40180400 */  sll        $v1, $a0, 1
    /* 2DB14 80096314 21186400 */  addu       $v1, $v1, $a0
    /* 2DB18 80096318 AC1B428C */  lw         $v0, %lo(D_800F1BAC)($v0)
    /* 2DB1C 8009631C C0180300 */  sll        $v1, $v1, 3
    /* 2DB20 80096320 E0580208 */  j          .L80096380
    /* 2DB24 80096324 21104300 */   addu      $v0, $v0, $v1
  .L80096328:
    /* 2DB28 80096328 21900000 */  addu       $s2, $zero, $zero
    /* 2DB2C 8009632C 0F80133C */  lui        $s3, %hi(D_800F1BAC)
    /* 2DB30 80096330 18001124 */  addiu      $s1, $zero, 0x18
    /* 2DB34 80096334 21804002 */  addu       $s0, $s2, $zero
  .L80096338:
    /* 2DB38 80096338 AC1B658E */  lw         $a1, %lo(D_800F1BAC)($s3)
    /* 2DB3C 8009633C 01005226 */  addiu      $s2, $s2, 0x1
    /* 2DB40 80096340 18000624 */  addiu      $a2, $zero, 0x18
    /* 2DB44 80096344 2120B000 */  addu       $a0, $a1, $s0
    /* 2DB48 80096348 2C24010C */  jal        vs_main_memcpy
    /* 2DB4C 8009634C 2128B100 */   addu      $a1, $a1, $s1
    /* 2DB50 80096350 18003126 */  addiu      $s1, $s1, 0x18
    /* 2DB54 80096354 1F00422A */  slti       $v0, $s2, 0x1F
    /* 2DB58 80096358 F7FF4014 */  bnez       $v0, .L80096338
    /* 2DB5C 8009635C 18001026 */   addiu     $s0, $s0, 0x18
    /* 2DB60 80096360 0F80103C */  lui        $s0, %hi(D_800F1BAC)
    /* 2DB64 80096364 AC1B048E */  lw         $a0, %lo(D_800F1BAC)($s0)
    /* 2DB68 80096368 18000524 */  addiu      $a1, $zero, 0x18
    /* 2DB6C 8009636C 4424010C */  jal        vs_main_bzero
    /* 2DB70 80096370 E8028424 */   addiu     $a0, $a0, 0x2E8
    /* 2DB74 80096374 AC1B028E */  lw         $v0, %lo(D_800F1BAC)($s0)
    /* 2DB78 80096378 00000000 */  nop
    /* 2DB7C 8009637C E8024224 */  addiu      $v0, $v0, 0x2E8
  .L80096380:
    /* 2DB80 80096380 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2DB84 80096384 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2DB88 80096388 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DB8C 8009638C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DB90 80096390 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DB94 80096394 0800E003 */  jr         $ra
    /* 2DB98 80096398 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800962E4
