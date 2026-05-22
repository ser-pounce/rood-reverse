nonmatching func_800FDBAC, 0x124

glabel func_800FDBAC
    /* 43AC 800FDBAC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 43B0 800FDBB0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 43B4 800FDBB4 21888000 */  addu       $s1, $a0, $zero
    /* 43B8 800FDBB8 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 43BC 800FDBBC 1080043C */  lui        $a0, %hi(vs_mainMenu_shields)
    /* 43C0 800FDBC0 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 43C4 800FDBC4 6C24848C */  lw         $a0, %lo(vs_mainMenu_shields)($a0)
    /* 43C8 800FDBC8 1C684224 */  addiu      $v0, $v0, 0x681C
    /* 43CC 800FDBCC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 43D0 800FDBD0 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 43D4 800FDBD4 A1244390 */  lbu        $v1, %lo(D_801024A1)($v0)
    /* 43D8 800FDBD8 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 43DC 800FDBDC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 43E0 800FDBE0 2000B0AF */  sw         $s0, 0x20($sp)
    /* 43E4 800FDBE4 40100300 */  sll        $v0, $v1, 1
    /* 43E8 800FDBE8 21104300 */  addu       $v0, $v0, $v1
    /* 43EC 800FDBEC 00110200 */  sll        $v0, $v0, 4
    /* 43F0 800FDBF0 D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 43F4 800FDBF4 21808200 */  addu       $s0, $a0, $v0
    /* 43F8 800FDBF8 09002016 */  bnez       $s1, .L800FDC20
    /* 43FC 800FDBFC 21906000 */   addu      $s2, $v1, $zero
    /* 4400 800FDC00 21200002 */  addu       $a0, $s0, $zero
    /* 4404 800FDC04 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4408 800FDC08 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 440C 800FDC0C 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 4410 800FDC10 90F3030C */  jal        vs_mainMenu_initUiShield
    /* 4414 800FDC14 1800A627 */   addiu     $a2, $sp, 0x18
    /* 4418 800FDC18 25F70308 */  j          .L800FDC94
    /* 441C 800FDC1C 0A002426 */   addiu     $a0, $s1, 0xA
  .L800FDC20:
    /* 4420 800FDC20 1B002006 */  bltz       $s1, .L800FDC90
    /* 4424 800FDC24 0400222A */   slti      $v0, $s1, 0x4
    /* 4428 800FDC28 1A004010 */  beqz       $v0, .L800FDC94
    /* 442C 800FDC2C 0A002426 */   addiu     $a0, $s1, 0xA
    /* 4430 800FDC30 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 4434 800FDC34 08000424 */   addiu     $a0, $zero, 0x8
    /* 4438 800FDC38 21103002 */  addu       $v0, $s1, $s0
    /* 443C 800FDC3C 2B005090 */  lbu        $s0, 0x2B($v0)
    /* 4440 800FDC40 00000000 */  nop
    /* 4444 800FDC44 10000012 */  beqz       $s0, .L800FDC88
    /* 4448 800FDC48 1000A527 */   addiu     $a1, $sp, 0x10
    /* 444C 800FDC4C 1800A627 */  addiu      $a2, $sp, 0x18
    /* 4450 800FDC50 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 4454 800FDC54 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 4458 800FDC58 1080023C */  lui        $v0, %hi(vs_mainMenu_gems)
    /* 445C 800FDC5C C0201000 */  sll        $a0, $s0, 3
    /* 4460 800FDC60 23209000 */  subu       $a0, $a0, $s0
    /* 4464 800FDC64 80200400 */  sll        $a0, $a0, 2
    /* 4468 800FDC68 5824428C */  lw         $v0, %lo(vs_mainMenu_gems)($v0)
    /* 446C 800FDC6C E4FF8424 */  addiu      $a0, $a0, -0x1C
    /* 4470 800FDC70 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 4474 800FDC74 21204400 */   addu      $a0, $v0, $a0
    /* 4478 800FDC78 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 447C 800FDC7C 21200002 */   addu      $a0, $s0, $zero
    /* 4480 800FDC80 25F70308 */  j          .L800FDC94
    /* 4484 800FDC84 0A002426 */   addiu     $a0, $s1, 0xA
  .L800FDC88:
    /* 4488 800FDC88 88F4030C */  jal        vs_mainMenu_resetStats
    /* 448C 800FDC8C 00000000 */   nop
  .L800FDC90:
    /* 4490 800FDC90 0A002426 */  addiu      $a0, $s1, 0xA
  .L800FDC94:
    /* 4494 800FDC94 1080033C */  lui        $v1, %hi(vs_mainMenu_equipmentSubtype)
    /* 4498 800FDC98 08000224 */  addiu      $v0, $zero, 0x8
    /* 449C 800FDC9C 452562A0 */  sb         $v0, %lo(vs_mainMenu_equipmentSubtype)($v1)
    /* 44A0 800FDCA0 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 44A4 800FDCA4 9223030C */  jal        vs_battle_getMenuItem
    /* 44A8 800FDCA8 A12452A0 */   sb        $s2, %lo(D_801024A1)($v0)
    /* 44AC 800FDCAC 01000324 */  addiu      $v1, $zero, 0x1
    /* 44B0 800FDCB0 060043A0 */  sb         $v1, 0x6($v0)
    /* 44B4 800FDCB4 1400A28F */  lw         $v0, 0x14($sp)
    /* 44B8 800FDCB8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 44BC 800FDCBC 2800B28F */  lw         $s2, 0x28($sp)
    /* 44C0 800FDCC0 2400B18F */  lw         $s1, 0x24($sp)
    /* 44C4 800FDCC4 2000B08F */  lw         $s0, 0x20($sp)
    /* 44C8 800FDCC8 0800E003 */  jr         $ra
    /* 44CC 800FDCCC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800FDBAC
