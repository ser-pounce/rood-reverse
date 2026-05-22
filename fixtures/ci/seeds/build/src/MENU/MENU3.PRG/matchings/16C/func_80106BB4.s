nonmatching func_80106BB4, 0xE0

glabel func_80106BB4
    /* 43B4 80106BB4 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 43B8 80106BB8 7000B0AF */  sw         $s0, 0x70($sp)
    /* 43BC 80106BBC 7400BFAF */  sw         $ra, 0x74($sp)
    /* 43C0 80106BC0 88F4030C */  jal        vs_mainMenu_resetStats
    /* 43C4 80106BC4 21808000 */   addu      $s0, $a0, $zero
    /* 43C8 80106BC8 27000012 */  beqz       $s0, .L80106C68
    /* 43CC 80106BCC 1000A427 */   addiu     $a0, $sp, 0x10
    /* 43D0 80106BD0 1080023C */  lui        $v0, %hi(vs_mainMenu_armor)
    /* 43D4 80106BD4 80281000 */  sll        $a1, $s0, 2
    /* 43D8 80106BD8 2128B000 */  addu       $a1, $a1, $s0
    /* 43DC 80106BDC C0280500 */  sll        $a1, $a1, 3
    /* 43E0 80106BE0 6824428C */  lw         $v0, %lo(vs_mainMenu_armor)($v0)
    /* 43E4 80106BE4 D8FFA524 */  addiu      $a1, $a1, -0x28
    /* 43E8 80106BE8 65AC010C */  jal        vs_battle_applyAccessory
    /* 43EC 80106BEC 21284500 */   addu      $a1, $v0, $a1
    /* 43F0 80106BF0 21300000 */  addu       $a2, $zero, $zero
    /* 43F4 80106BF4 1000AB27 */  addiu      $t3, $sp, 0x10
    /* 43F8 80106BF8 40000924 */  addiu      $t1, $zero, 0x40
    /* 43FC 80106BFC 20000824 */  addiu      $t0, $zero, 0x20
    /* 4400 80106C00 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 4404 80106C04 C0244A24 */  addiu      $t2, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 4408 80106C08 21384001 */  addu       $a3, $t2, $zero
  .L80106C0C:
    /* 440C 80106C0C 21282A01 */  addu       $a1, $t1, $t2
    /* 4410 80106C10 02002925 */  addiu      $t1, $t1, 0x2
    /* 4414 80106C14 0700C230 */  andi       $v0, $a2, 0x7
    /* 4418 80106C18 40100200 */  sll        $v0, $v0, 1
    /* 441C 80106C1C 21106201 */  addu       $v0, $t3, $v0
    /* 4420 80106C20 21200A01 */  addu       $a0, $t0, $t2
    /* 4424 80106C24 40004394 */  lhu        $v1, 0x40($v0)
    /* 4428 80106C28 02000825 */  addiu      $t0, $t0, 0x2
    /* 442C 80106C2C 0000E3A4 */  sh         $v1, 0x0($a3)
    /* 4430 80106C30 50004394 */  lhu        $v1, 0x50($v0)
    /* 4434 80106C34 0100C624 */  addiu      $a2, $a2, 0x1
    /* 4438 80106C38 000083A4 */  sh         $v1, 0x0($a0)
    /* 443C 80106C3C 38004294 */  lhu        $v0, 0x38($v0)
    /* 4440 80106C40 00000000 */  nop
    /* 4444 80106C44 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 4448 80106C48 1000C228 */  slti       $v0, $a2, 0x10
    /* 444C 80106C4C EFFF4014 */  bnez       $v0, .L80106C0C
    /* 4450 80106C50 0200E724 */   addiu     $a3, $a3, 0x2
    /* 4454 80106C54 4000A487 */  lh         $a0, 0x40($sp)
    /* 4458 80106C58 4200A587 */  lh         $a1, 0x42($sp)
    /* 445C 80106C5C 4400A687 */  lh         $a2, 0x44($sp)
    /* 4460 80106C60 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 4464 80106C64 02000724 */   addiu     $a3, $zero, 0x2
  .L80106C68:
    /* 4468 80106C68 07000424 */  addiu      $a0, $zero, 0x7
    /* 446C 80106C6C 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 4470 80106C70 20000324 */  addiu      $v1, $zero, 0x20
    /* 4474 80106C74 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 4478 80106C78 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 447C 80106C7C E3EE030C */  jal        func_800FBB8C
    /* 4480 80106C80 A12450A0 */   sb        $s0, %lo(D_801024A1)($v0)
    /* 4484 80106C84 7400BF8F */  lw         $ra, 0x74($sp)
    /* 4488 80106C88 7000B08F */  lw         $s0, 0x70($sp)
    /* 448C 80106C8C 0800E003 */  jr         $ra
    /* 4490 80106C90 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_80106BB4
