nonmatching vs_mainMenu_setUiBladeStats, 0x100

glabel vs_mainMenu_setUiBladeStats
    /* 3C04 800FD404 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C08 800FD408 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C0C 800FD40C 21888000 */  addu       $s1, $a0, $zero
    /* 3C10 800FD410 21280000 */  addu       $a1, $zero, $zero
    /* 3C14 800FD414 20000724 */  addiu      $a3, $zero, 0x20
    /* 3C18 800FD418 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 3C1C 800FD41C C0244824 */  addiu      $t0, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 3C20 800FD420 21300001 */  addu       $a2, $t0, $zero
    /* 3C24 800FD424 1080033C */  lui        $v1, %hi(vs_mainMenu_blades)
    /* 3C28 800FD428 40101100 */  sll        $v0, $s1, 1
    /* 3C2C 800FD42C 21105100 */  addu       $v0, $v0, $s1
    /* 3C30 800FD430 80100200 */  sll        $v0, $v0, 2
    /* 3C34 800FD434 23105100 */  subu       $v0, $v0, $s1
    /* 3C38 800FD438 80100200 */  sll        $v0, $v0, 2
    /* 3C3C 800FD43C 6424638C */  lw         $v1, %lo(vs_mainMenu_blades)($v1)
    /* 3C40 800FD440 D4FF4224 */  addiu      $v0, $v0, -0x2C
    /* 3C44 800FD444 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3C48 800FD448 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C4C 800FD44C 21806200 */  addu       $s0, $v1, $v0
  .L800FD450:
    /* 3C50 800FD450 2120E800 */  addu       $a0, $a3, $t0
    /* 3C54 800FD454 0200E724 */  addiu      $a3, $a3, 0x2
    /* 3C58 800FD458 0700A330 */  andi       $v1, $a1, 0x7
    /* 3C5C 800FD45C 21180302 */  addu       $v1, $s0, $v1
    /* 3C60 800FD460 18006290 */  lbu        $v0, 0x18($v1)
    /* 3C64 800FD464 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3C68 800FD468 00160200 */  sll        $v0, $v0, 24
    /* 3C6C 800FD46C 03160200 */  sra        $v0, $v0, 24
    /* 3C70 800FD470 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 3C74 800FD474 20006290 */  lbu        $v0, 0x20($v1)
    /* 3C78 800FD478 00000000 */  nop
    /* 3C7C 800FD47C 00160200 */  sll        $v0, $v0, 24
    /* 3C80 800FD480 03160200 */  sra        $v0, $v0, 24
    /* 3C84 800FD484 000082A4 */  sh         $v0, 0x0($a0)
    /* 3C88 800FD488 1000A228 */  slti       $v0, $a1, 0x10
    /* 3C8C 800FD48C F0FF4014 */  bnez       $v0, .L800FD450
    /* 3C90 800FD490 0200C624 */   addiu     $a2, $a2, 0x2
    /* 3C94 800FD494 08000496 */  lhu        $a0, 0x8($s0)
    /* 3C98 800FD498 04000596 */  lhu        $a1, 0x4($s0)
    /* 3C9C 800FD49C 0A000696 */  lhu        $a2, 0xA($s0)
    /* 3CA0 800FD4A0 06000796 */  lhu        $a3, 0x6($s0)
    /* 3CA4 800FD4A4 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 3CA8 800FD4A8 00000000 */   nop
    /* 3CAC 800FD4AC 0C000482 */  lb         $a0, 0xC($s0)
    /* 3CB0 800FD4B0 0D000582 */  lb         $a1, 0xD($s0)
    /* 3CB4 800FD4B4 0E000682 */  lb         $a2, 0xE($s0)
    /* 3CB8 800FD4B8 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 3CBC 800FD4BC 01000724 */   addiu     $a3, $zero, 0x1
    /* 3CC0 800FD4C0 21300000 */  addu       $a2, $zero, $zero
    /* 3CC4 800FD4C4 14000492 */  lbu        $a0, 0x14($s0)
    /* 3CC8 800FD4C8 0F000592 */  lbu        $a1, 0xF($s0)
    /* 3CCC 800FD4CC 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 3CD0 800FD4D0 01000724 */   addiu     $a3, $zero, 0x1
    /* 3CD4 800FD4D4 03000424 */  addiu      $a0, $zero, 0x3
    /* 3CD8 800FD4D8 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 3CDC 800FD4DC 02000324 */  addiu      $v1, $zero, 0x2
    /* 3CE0 800FD4E0 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 3CE4 800FD4E4 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 3CE8 800FD4E8 E3EE030C */  jal        func_800FBB8C
    /* 3CEC 800FD4EC A12451A0 */   sb        $s1, %lo(D_801024A1)($v0)
    /* 3CF0 800FD4F0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3CF4 800FD4F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 3CF8 800FD4F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 3CFC 800FD4FC 0800E003 */  jr         $ra
    /* 3D00 800FD500 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainMenu_setUiBladeStats
