nonmatching func_80109344, 0x74

glabel func_80109344
    /* 6B44 80109344 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6B48 80109348 17008010 */  beqz       $a0, .L801093A8
    /* 6B4C 8010934C 2800BFAF */   sw        $ra, 0x28($sp)
    /* 6B50 80109350 60008228 */  slti       $v0, $a0, 0x60
    /* 6B54 80109354 03004010 */  beqz       $v0, .L80109364
    /* 6B58 80109358 21300000 */   addu      $a2, $zero, $zero
    /* 6B5C 8010935C DB240408 */  j          .L8010936C
    /* 6B60 80109360 F0000724 */   addiu     $a3, $zero, 0xF0
  .L80109364:
    /* 6B64 80109364 01000624 */  addiu      $a2, $zero, 0x1
    /* 6B68 80109368 F1000724 */  addiu      $a3, $zero, 0xF1
  .L8010936C:
    /* 6B6C 8010936C 03000224 */  addiu      $v0, $zero, 0x3
    /* 6B70 80109370 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 6B74 80109374 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 6B78 80109378 FC19438C */  lw         $v1, %lo(vs_battle_characterState)($v0)
    /* 6B7C 8010937C 80100600 */  sll        $v0, $a2, 2
    /* 6B80 80109380 1100A6A3 */  sb         $a2, 0x11($sp)
    /* 6B84 80109384 1200A4A7 */  sh         $a0, 0x12($sp)
    /* 6B88 80109388 21104300 */  addu       $v0, $v0, $v1
    /* 6B8C 8010938C 4800428C */  lw         $v0, 0x48($v0)
    /* 6B90 80109390 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6B94 80109394 2000A0A3 */  sb         $zero, 0x20($sp)
    /* 6B98 80109398 2100A7A3 */  sb         $a3, 0x21($sp)
    /* 6B9C 8010939C 2200A5A3 */  sb         $a1, 0x22($sp)
    /* 6BA0 801093A0 7A65020C */  jal        vs_battle_populateDataSlot
    /* 6BA4 801093A4 1400A2AF */   sw        $v0, 0x14($sp)
  .L801093A8:
    /* 6BA8 801093A8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 6BAC 801093AC 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 6BB0 801093B0 0800E003 */  jr         $ra
    /* 6BB4 801093B4 00000000 */   nop
endlabel func_80109344
