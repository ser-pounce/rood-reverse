nonmatching func_800FDD88, 0x134

glabel func_800FDD88
    /* 4588 800FDD88 21308000 */  addu       $a2, $a0, $zero
    /* 458C 800FDD8C 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 4590 800FDD90 45254590 */  lbu        $a1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 4594 800FDD94 1500C22C */  sltiu      $v0, $a2, 0x15
    /* 4598 800FDD98 45004010 */  beqz       $v0, .L800FDEB0
    /* 459C 800FDD9C 21200000 */   addu      $a0, $zero, $zero
    /* 45A0 800FDDA0 1080023C */  lui        $v0, %hi(jtbl_800F9944)
    /* 45A4 800FDDA4 44994224 */  addiu      $v0, $v0, %lo(jtbl_800F9944)
    /* 45A8 800FDDA8 80180600 */  sll        $v1, $a2, 2
    /* 45AC 800FDDAC 21186200 */  addu       $v1, $v1, $v0
    /* 45B0 800FDDB0 0000628C */  lw         $v0, 0x0($v1)
    /* 45B4 800FDDB4 00000000 */  nop
    /* 45B8 800FDDB8 08004000 */  jr         $v0
    /* 45BC 800FDDBC 00000000 */   nop
    /* 45C0 800FDDC0 ACF70308 */  j          .L800FDEB0
    /* 45C4 800FDDC4 0B00A430 */   andi      $a0, $a1, 0xB
    /* 45C8 800FDDC8 ACF70308 */  j          .L800FDEB0
    /* 45CC 800FDDCC 1B00A430 */   andi      $a0, $a1, 0x1B
    /* 45D0 800FDDD0 1080023C */  lui        $v0, %hi(D_801024B9)
    /* 45D4 800FDDD4 B9244290 */  lbu        $v0, %lo(D_801024B9)($v0)
    /* 45D8 800FDDD8 00000000 */  nop
    /* 45DC 800FDDDC 02004238 */  xori       $v0, $v0, 0x2
    /* 45E0 800FDDE0 ACF70308 */  j          .L800FDEB0
    /* 45E4 800FDDE4 2B200200 */   sltu      $a0, $zero, $v0
    /* 45E8 800FDDE8 1080023C */  lui        $v0, %hi(D_801024B9)
    /* 45EC 800FDDEC B9244290 */  lbu        $v0, %lo(D_801024B9)($v0)
    /* 45F0 800FDDF0 00000000 */  nop
    /* 45F4 800FDDF4 01004238 */  xori       $v0, $v0, 0x1
    /* 45F8 800FDDF8 ACF70308 */  j          .L800FDEB0
    /* 45FC 800FDDFC 0100442C */   sltiu     $a0, $v0, 0x1
    /* 4600 800FDE00 01000424 */  addiu      $a0, $zero, 0x1
    /* 4604 800FDE04 0800A230 */  andi       $v0, $a1, 0x8
    /* 4608 800FDE08 0F004010 */  beqz       $v0, .L800FDE48
    /* 460C 800FDE0C 1080033C */   lui       $v1, %hi(D_801024A1)
    /* 4610 800FDE10 A1246290 */  lbu        $v0, %lo(D_801024A1)($v1)
    /* 4614 800FDE14 00000000 */  nop
    /* 4618 800FDE18 0B004010 */  beqz       $v0, .L800FDE48
    /* 461C 800FDE1C 21184000 */   addu      $v1, $v0, $zero
    /* 4620 800FDE20 1080043C */  lui        $a0, %hi(vs_mainMenu_shields)
    /* 4624 800FDE24 40100300 */  sll        $v0, $v1, 1
    /* 4628 800FDE28 21104300 */  addu       $v0, $v0, $v1
    /* 462C 800FDE2C 6C24838C */  lw         $v1, %lo(vs_mainMenu_shields)($a0)
    /* 4630 800FDE30 00110200 */  sll        $v0, $v0, 4
    /* 4634 800FDE34 21104300 */  addu       $v0, $v0, $v1
    /* 4638 800FDE38 E0FF4290 */  lbu        $v0, -0x20($v0)
    /* 463C 800FDE3C F6FFC424 */  addiu      $a0, $a2, -0xA
    /* 4640 800FDE40 ACF70308 */  j          .L800FDEB0
    /* 4644 800FDE44 2A208200 */   slt       $a0, $a0, $v0
  .L800FDE48:
    /* 4648 800FDE48 0100A230 */  andi       $v0, $a1, 0x1
    /* 464C 800FDE4C 18004010 */  beqz       $v0, .L800FDEB0
    /* 4650 800FDE50 1080053C */   lui       $a1, %hi(D_801024A1)
    /* 4654 800FDE54 A124A290 */  lbu        $v0, %lo(D_801024A1)($a1)
    /* 4658 800FDE58 00000000 */  nop
    /* 465C 800FDE5C 14004010 */  beqz       $v0, .L800FDEB0
    /* 4660 800FDE60 1080033C */   lui       $v1, %hi(vs_mainMenu_weapons)
    /* 4664 800FDE64 7024638C */  lw         $v1, %lo(vs_mainMenu_weapons)($v1)
    /* 4668 800FDE68 40110200 */  sll        $v0, $v0, 5
    /* 466C 800FDE6C 21104300 */  addu       $v0, $v0, $v1
    /* 4670 800FDE70 1080033C */  lui        $v1, %hi(vs_mainMenu_grips)
    /* 4674 800FDE74 E2FF4290 */  lbu        $v0, -0x1E($v0)
    /* 4678 800FDE78 6024638C */  lw         $v1, %lo(vs_mainMenu_grips)($v1)
    /* 467C 800FDE7C 00110200 */  sll        $v0, $v0, 4
    /* 4680 800FDE80 21104300 */  addu       $v0, $v0, $v1
    /* 4684 800FDE84 F4FF4290 */  lbu        $v0, -0xC($v0)
    /* 4688 800FDE88 F4FFC424 */  addiu      $a0, $a2, -0xC
    /* 468C 800FDE8C ACF70308 */  j          .L800FDEB0
    /* 4690 800FDE90 2A208200 */   slt       $a0, $a0, $v0
    /* 4694 800FDE94 1080023C */  lui        $v0, %hi(D_8010214A)
    /* 4698 800FDE98 4A214490 */  lbu        $a0, %lo(D_8010214A)($v0)
    /* 469C 800FDE9C 0800E003 */  jr         $ra
    /* 46A0 800FDEA0 21108000 */   addu      $v0, $a0, $zero
    /* 46A4 800FDEA4 ACF70308 */  j          .L800FDEB0
    /* 46A8 800FDEA8 0300A430 */   andi      $a0, $a1, 0x3
    /* 46AC 800FDEAC 01000424 */  addiu      $a0, $zero, 0x1
  .L800FDEB0:
    /* 46B0 800FDEB0 21108000 */  addu       $v0, $a0, $zero
    /* 46B4 800FDEB4 0800E003 */  jr         $ra
    /* 46B8 800FDEB8 00000000 */   nop
endlabel func_800FDD88
