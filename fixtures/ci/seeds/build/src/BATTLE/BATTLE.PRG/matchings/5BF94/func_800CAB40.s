nonmatching func_800CAB40, 0xA0

glabel func_800CAB40
    /* 62340 800CAB40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62344 800CAB44 0F80033C */  lui        $v1, %hi(D_800F4E98)
    /* 62348 800CAB48 984E6224 */  addiu      $v0, $v1, %lo(D_800F4E98)
    /* 6234C 800CAB4C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 62350 800CAB50 020040A4 */  sh         $zero, 0x2($v0)
    /* 62354 800CAB54 01000224 */  addiu      $v0, $zero, 0x1
    /* 62358 800CAB58 984E62A4 */  sh         $v0, %lo(D_800F4E98)($v1)
    /* 6235C 800CAB5C 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 62360 800CAB60 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 62364 800CAB64 05000224 */  addiu      $v0, $zero, 0x5
    /* 62368 800CAB68 07006214 */  bne        $v1, $v0, .L800CAB88
    /* 6236C 800CAB6C 0F80033C */   lui       $v1, %hi(vs_battle_menuState)
    /* 62370 800CAB70 04000224 */  addiu      $v0, $zero, 0x4
    /* 62374 800CAB74 C05162A0 */  sb         $v0, %lo(vs_battle_menuState)($v1)
    /* 62378 800CAB78 AFEB030C */  jal        func_800FAEBC
    /* 6237C 800CAB7C 02000424 */   addiu     $a0, $zero, 0x2
    /* 62380 800CAB80 ED2A0308 */  j          .L800CABB4
    /* 62384 800CAB84 0F80023C */   lui       $v0, %hi(D_800F4FDB)
  .L800CAB88:
    /* 62388 800CAB88 C0516424 */  addiu      $a0, $v1, %lo(vs_battle_menuState)
    /* 6238C 800CAB8C 01008290 */  lbu        $v0, 0x1($a0)
    /* 62390 800CAB90 00000000 */  nop
    /* 62394 800CAB94 C05162A0 */  sb         $v0, %lo(vs_battle_menuState)($v1)
    /* 62398 800CAB98 0F80033C */  lui        $v1, %hi(vs_battle_submenuStates)
    /* 6239C 800CAB9C 704E6324 */  addiu      $v1, $v1, %lo(vs_battle_submenuStates)
    /* 623A0 800CABA0 0F004230 */  andi       $v0, $v0, 0xF
    /* 623A4 800CABA4 02008490 */  lbu        $a0, 0x2($a0)
    /* 623A8 800CABA8 21104300 */  addu       $v0, $v0, $v1
    /* 623AC 800CABAC 000044A0 */  sb         $a0, 0x0($v0)
    /* 623B0 800CABB0 0F80023C */  lui        $v0, %hi(D_800F4FDB)
  .L800CABB4:
    /* 623B4 800CABB4 DB4F4290 */  lbu        $v0, %lo(D_800F4FDB)($v0)
    /* 623B8 800CABB8 00000000 */  nop
    /* 623BC 800CABBC 04004014 */  bnez       $v0, .L800CABD0
    /* 623C0 800CABC0 1A000424 */   addiu     $a0, $zero, 0x1A
    /* 623C4 800CABC4 03000524 */  addiu      $a1, $zero, 0x3
    /* 623C8 800CABC8 FCF7010C */  jal        func_8007DFF0
    /* 623CC 800CABCC 06000624 */   addiu     $a2, $zero, 0x6
  .L800CABD0:
    /* 623D0 800CABD0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 623D4 800CABD4 00000000 */  nop
    /* 623D8 800CABD8 0800E003 */  jr         $ra
    /* 623DC 800CABDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CAB40
