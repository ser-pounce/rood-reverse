nonmatching vs_mainMenu_initItem, 0x1EC

glabel vs_mainMenu_initItem
    /* 4BE0 800FE3E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4BE4 800FE3E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4BE8 800FE3E8 2190A000 */  addu       $s2, $a1, $zero
    /* 4BEC 800FE3EC 0700822C */  sltiu      $v0, $a0, 0x7
    /* 4BF0 800FE3F0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4BF4 800FE3F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4BF8 800FE3F8 6E004010 */  beqz       $v0, .L800FE5B4
    /* 4BFC 800FE3FC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4C00 800FE400 1080023C */  lui        $v0, %hi(jtbl_800F999C)
    /* 4C04 800FE404 9C994224 */  addiu      $v0, $v0, %lo(jtbl_800F999C)
    /* 4C08 800FE408 80180400 */  sll        $v1, $a0, 2
    /* 4C0C 800FE40C 21186200 */  addu       $v1, $v1, $v0
    /* 4C10 800FE410 0000628C */  lw         $v0, 0x0($v1)
    /* 4C14 800FE414 00000000 */  nop
    /* 4C18 800FE418 08004000 */  jr         $v0
    /* 4C1C 800FE41C 00000000 */   nop
    /* 4C20 800FE420 01000424 */  addiu      $a0, $zero, 0x1
    /* 4C24 800FE424 40191200 */  sll        $v1, $s2, 5
    /* 4C28 800FE428 0680023C */  lui        $v0, %hi(D_80060148)
    /* 4C2C 800FE42C 48014224 */  addiu      $v0, $v0, %lo(D_80060148)
    /* 4C30 800FE430 21886200 */  addu       $s1, $v1, $v0
    /* 4C34 800FE434 01002592 */  lbu        $a1, 0x1($s1)
    /* 4C38 800FE438 F8F8030C */  jal        vs_mainMenu_initItem
    /* 4C3C 800FE43C 21800000 */   addu      $s0, $zero, $zero
    /* 4C40 800FE440 02002592 */  lbu        $a1, 0x2($s1)
    /* 4C44 800FE444 F8F8030C */  jal        vs_mainMenu_initItem
    /* 4C48 800FE448 02000424 */   addiu     $a0, $zero, 0x2
    /* 4C4C 800FE44C 21103002 */  addu       $v0, $s1, $s0
  .L800FE450:
    /* 4C50 800FE450 04004590 */  lbu        $a1, 0x4($v0)
    /* 4C54 800FE454 00000000 */  nop
    /* 4C58 800FE458 0300A010 */  beqz       $a1, .L800FE468
    /* 4C5C 800FE45C 00000000 */   nop
    /* 4C60 800FE460 F8F8030C */  jal        vs_mainMenu_initItem
    /* 4C64 800FE464 05000424 */   addiu     $a0, $zero, 0x5
  .L800FE468:
    /* 4C68 800FE468 01001026 */  addiu      $s0, $s0, 0x1
    /* 4C6C 800FE46C 0300022A */  slti       $v0, $s0, 0x3
    /* 4C70 800FE470 F7FF4014 */  bnez       $v0, .L800FE450
    /* 4C74 800FE474 21103002 */   addu      $v0, $s1, $s0
    /* 4C78 800FE478 21202002 */  addu       $a0, $s1, $zero
    /* 4C7C 800FE47C 4BF90308 */  j          .L800FE52C
    /* 4C80 800FE480 20000524 */   addiu     $a1, $zero, 0x20
    /* 4C84 800FE484 40801200 */  sll        $s0, $s2, 1
    /* 4C88 800FE488 21801202 */  addu       $s0, $s0, $s2
    /* 4C8C 800FE48C 80801000 */  sll        $s0, $s0, 2
    /* 4C90 800FE490 23801202 */  subu       $s0, $s0, $s2
    /* 4C94 800FE494 80801000 */  sll        $s0, $s0, 2
    /* 4C98 800FE498 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 4C9C 800FE49C BC034224 */  addiu      $v0, $v0, %lo(D_800603BC)
    /* 4CA0 800FE4A0 21800202 */  addu       $s0, $s0, $v0
    /* 4CA4 800FE4A4 21200002 */  addu       $a0, $s0, $zero
    /* 4CA8 800FE4A8 0733030C */  jal        vs_battle_rMemzero
    /* 4CAC 800FE4AC 2C000524 */   addiu     $a1, $zero, 0x2C
    /* 4CB0 800FE4B0 6DF90308 */  j          .L800FE5B4
    /* 4CB4 800FE4B4 2B0012A2 */   sb        $s2, 0x2B($s0)
    /* 4CB8 800FE4B8 00811200 */  sll        $s0, $s2, 4
    /* 4CBC 800FE4BC 0680023C */  lui        $v0, %hi(D_80060698)
    /* 4CC0 800FE4C0 98064224 */  addiu      $v0, $v0, %lo(D_80060698)
    /* 4CC4 800FE4C4 21800202 */  addu       $s0, $s0, $v0
    /* 4CC8 800FE4C8 21200002 */  addu       $a0, $s0, $zero
    /* 4CCC 800FE4CC 0733030C */  jal        vs_battle_rMemzero
    /* 4CD0 800FE4D0 10000524 */   addiu     $a1, $zero, 0x10
    /* 4CD4 800FE4D4 6DF90308 */  j          .L800FE5B4
    /* 4CD8 800FE4D8 0E0012A6 */   sh        $s2, 0xE($s0)
    /* 4CDC 800FE4DC 40181200 */  sll        $v1, $s2, 1
    /* 4CE0 800FE4E0 21187200 */  addu       $v1, $v1, $s2
    /* 4CE4 800FE4E4 00190300 */  sll        $v1, $v1, 4
    /* 4CE8 800FE4E8 0680023C */  lui        $v0, %hi(D_80060238)
    /* 4CEC 800FE4EC 38024224 */  addiu      $v0, $v0, %lo(D_80060238)
    /* 4CF0 800FE4F0 21886200 */  addu       $s1, $v1, $v0
    /* 4CF4 800FE4F4 21800000 */  addu       $s0, $zero, $zero
    /* 4CF8 800FE4F8 21103002 */  addu       $v0, $s1, $s0
  .L800FE4FC:
    /* 4CFC 800FE4FC 2C004590 */  lbu        $a1, 0x2C($v0)
    /* 4D00 800FE500 00000000 */  nop
    /* 4D04 800FE504 0300A010 */  beqz       $a1, .L800FE514
    /* 4D08 800FE508 00000000 */   nop
    /* 4D0C 800FE50C F8F8030C */  jal        vs_mainMenu_initItem
    /* 4D10 800FE510 05000424 */   addiu     $a0, $zero, 0x5
  .L800FE514:
    /* 4D14 800FE514 01001026 */  addiu      $s0, $s0, 0x1
    /* 4D18 800FE518 0300022A */  slti       $v0, $s0, 0x3
    /* 4D1C 800FE51C F7FF4014 */  bnez       $v0, .L800FE4FC
    /* 4D20 800FE520 21103002 */   addu      $v0, $s1, $s0
    /* 4D24 800FE524 21202002 */  addu       $a0, $s1, $zero
    /* 4D28 800FE528 30000524 */  addiu      $a1, $zero, 0x30
  .L800FE52C:
    /* 4D2C 800FE52C 0733030C */  jal        vs_battle_rMemzero
    /* 4D30 800FE530 00000000 */   nop
    /* 4D34 800FE534 6DF90308 */  j          .L800FE5B4
    /* 4D38 800FE538 000032A2 */   sb        $s2, 0x0($s1)
    /* 4D3C 800FE53C 80801200 */  sll        $s0, $s2, 2
    /* 4D40 800FE540 21801202 */  addu       $s0, $s0, $s2
    /* 4D44 800FE544 C0801000 */  sll        $s0, $s0, 3
    /* 4D48 800FE548 0680023C */  lui        $v0, %hi(D_80060780)
    /* 4D4C 800FE54C 80074224 */  addiu      $v0, $v0, %lo(D_80060780)
    /* 4D50 800FE550 21800202 */  addu       $s0, $s0, $v0
    /* 4D54 800FE554 21200002 */  addu       $a0, $s0, $zero
    /* 4D58 800FE558 0733030C */  jal        vs_battle_rMemzero
    /* 4D5C 800FE55C 28000524 */   addiu     $a1, $zero, 0x28
    /* 4D60 800FE560 6DF90308 */  j          .L800FE5B4
    /* 4D64 800FE564 270012A2 */   sb        $s2, 0x27($s0)
    /* 4D68 800FE568 C0801200 */  sll        $s0, $s2, 3
    /* 4D6C 800FE56C 23801202 */  subu       $s0, $s0, $s2
    /* 4D70 800FE570 80801000 */  sll        $s0, $s0, 2
    /* 4D74 800FE574 0680023C */  lui        $v0, %hi(D_80060A0C)
    /* 4D78 800FE578 0C0A4224 */  addiu      $v0, $v0, %lo(D_80060A0C)
    /* 4D7C 800FE57C 21800202 */  addu       $s0, $s0, $v0
    /* 4D80 800FE580 21200002 */  addu       $a0, $s0, $zero
    /* 4D84 800FE584 0733030C */  jal        vs_battle_rMemzero
    /* 4D88 800FE588 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 4D8C 800FE58C 6DF90308 */  j          .L800FE5B4
    /* 4D90 800FE590 1A0012A6 */   sh        $s2, 0x1A($s0)
    /* 4D94 800FE594 80801200 */  sll        $s0, $s2, 2
    /* 4D98 800FE598 0680023C */  lui        $v0, %hi(D_80060F64)
    /* 4D9C 800FE59C 640F4224 */  addiu      $v0, $v0, %lo(D_80060F64)
    /* 4DA0 800FE5A0 21800202 */  addu       $s0, $s0, $v0
    /* 4DA4 800FE5A4 21200002 */  addu       $a0, $s0, $zero
    /* 4DA8 800FE5A8 0733030C */  jal        vs_battle_rMemzero
    /* 4DAC 800FE5AC 04000524 */   addiu     $a1, $zero, 0x4
    /* 4DB0 800FE5B0 030012A2 */  sb         $s2, 0x3($s0)
  .L800FE5B4:
    /* 4DB4 800FE5B4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4DB8 800FE5B8 1800B28F */  lw         $s2, 0x18($sp)
    /* 4DBC 800FE5BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 4DC0 800FE5C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4DC4 800FE5C4 0800E003 */  jr         $ra
    /* 4DC8 800FE5C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainMenu_initItem
