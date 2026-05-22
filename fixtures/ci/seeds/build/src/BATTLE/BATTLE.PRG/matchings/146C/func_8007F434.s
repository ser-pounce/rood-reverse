nonmatching func_8007F434, 0x7C

glabel func_8007F434
    /* 16C34 8007F434 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 16C38 8007F438 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 16C3C 8007F43C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16C40 8007F440 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16C44 8007F444 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16C48 8007F448 3C00428C */  lw         $v0, 0x3C($v0)
    /* 16C4C 8007F44C 00000000 */  nop
    /* 16C50 8007F450 20004394 */  lhu        $v1, 0x20($v0)
    /* 16C54 8007F454 00000000 */  nop
    /* 16C58 8007F458 96006324 */  addiu      $v1, $v1, 0x96
    /* 16C5C 8007F45C 40100300 */  sll        $v0, $v1, 1
    /* 16C60 8007F460 21104300 */  addu       $v0, $v0, $v1
    /* 16C64 8007F464 C0100200 */  sll        $v0, $v0, 3
    /* 16C68 8007F468 21104300 */  addu       $v0, $v0, $v1
    /* 16C6C 8007F46C 80100200 */  sll        $v0, $v0, 2
    /* 16C70 8007F470 03004104 */  bgez       $v0, .L8007F480
    /* 16C74 8007F474 03820200 */   sra       $s0, $v0, 8
    /* 16C78 8007F478 FF004224 */  addiu      $v0, $v0, 0xFF
    /* 16C7C 8007F47C 03820200 */  sra        $s0, $v0, 8
  .L8007F480:
    /* 16C80 8007F480 6500022A */  slti       $v0, $s0, 0x65
    /* 16C84 8007F484 02004014 */  bnez       $v0, .L8007F490
    /* 16C88 8007F488 00000000 */   nop
    /* 16C8C 8007F48C 64001024 */  addiu      $s0, $zero, 0x64
  .L8007F490:
    /* 16C90 8007F490 EA09010C */  jal        vs_main_getRand
    /* 16C94 8007F494 64000424 */   addiu     $a0, $zero, 0x64
    /* 16C98 8007F498 14000326 */  addiu      $v1, $s0, 0x14
    /* 16C9C 8007F49C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 16CA0 8007F4A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 16CA4 8007F4A4 2A104300 */  slt        $v0, $v0, $v1
    /* 16CA8 8007F4A8 0800E003 */  jr         $ra
    /* 16CAC 8007F4AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F434
