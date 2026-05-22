nonmatching func_80106C64, 0x268

glabel func_80106C64
    /* 4464 80106C64 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 4468 80106C68 4400BFAF */  sw         $ra, 0x44($sp)
    /* 446C 80106C6C 4000B6AF */  sw         $s6, 0x40($sp)
    /* 4470 80106C70 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 4474 80106C74 3800B4AF */  sw         $s4, 0x38($sp)
    /* 4478 80106C78 3400B3AF */  sw         $s3, 0x34($sp)
    /* 447C 80106C7C 3000B2AF */  sw         $s2, 0x30($sp)
    /* 4480 80106C80 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 4484 80106C84 0B008010 */  beqz       $a0, .L80106CB4
    /* 4488 80106C88 2800B0AF */   sw        $s0, 0x28($sp)
    /* 448C 80106C8C 02000424 */  addiu      $a0, $zero, 0x2
    /* 4490 80106C90 01000524 */  addiu      $a1, $zero, 0x1
    /* 4494 80106C94 1180023C */  lui        $v0, %hi(D_8010BC41)
    /* 4498 80106C98 2118A000 */  addu       $v1, $a1, $zero
    /* 449C 80106C9C 4BEA030C */  jal        func_800FA92C
    /* 44A0 80106CA0 41BC43A0 */   sb        $v1, %lo(D_8010BC41)($v0)
    /* 44A4 80106CA4 21100000 */  addu       $v0, $zero, $zero
    /* 44A8 80106CA8 1180033C */  lui        $v1, %hi(D_8010BC3F)
    /* 44AC 80106CAC A91B0408 */  j          .L80106EA4
    /* 44B0 80106CB0 3FBC60A0 */   sb        $zero, %lo(D_8010BC3F)($v1)
  .L80106CB4:
    /* 44B4 80106CB4 1180113C */  lui        $s1, %hi(D_8010BC3F)
    /* 44B8 80106CB8 3FBC2392 */  lbu        $v1, %lo(D_8010BC3F)($s1)
    /* 44BC 80106CBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 44C0 80106CC0 4E006210 */  beq        $v1, $v0, .L80106DFC
    /* 44C4 80106CC4 02006228 */   slti      $v0, $v1, 0x2
    /* 44C8 80106CC8 05004010 */  beqz       $v0, .L80106CE0
    /* 44CC 80106CCC 02000224 */   addiu     $v0, $zero, 0x2
    /* 44D0 80106CD0 09006010 */  beqz       $v1, .L80106CF8
    /* 44D4 80106CD4 21100000 */   addu      $v0, $zero, $zero
    /* 44D8 80106CD8 A91B0408 */  j          .L80106EA4
    /* 44DC 80106CDC 00000000 */   nop
  .L80106CE0:
    /* 44E0 80106CE0 58006210 */  beq        $v1, $v0, .L80106E44
    /* 44E4 80106CE4 03000224 */   addiu     $v0, $zero, 0x3
    /* 44E8 80106CE8 60006210 */  beq        $v1, $v0, .L80106E6C
    /* 44EC 80106CEC 21100000 */   addu      $v0, $zero, $zero
    /* 44F0 80106CF0 A91B0408 */  j          .L80106EA4
    /* 44F4 80106CF4 00000000 */   nop
  .L80106CF8:
    /* 44F8 80106CF8 74EA030C */  jal        vs_mainmenu_ready
    /* 44FC 80106CFC 00000000 */   nop
    /* 4500 80106D00 67004010 */  beqz       $v0, .L80106EA0
    /* 4504 80106D04 21800000 */   addu      $s0, $zero, $zero
    /* 4508 80106D08 1080163C */  lui        $s6, %hi(vs_mainMenu_menu12Text)
    /* 450C 80106D0C 04001424 */  addiu      $s4, $zero, 0x4
    /* 4510 80106D10 1000B527 */  addiu      $s5, $sp, 0x10
    /* 4514 80106D14 2198A002 */  addu       $s3, $s5, $zero
  .L80106D18:
    /* 4518 80106D18 A424C38E */  lw         $v1, %lo(vs_mainMenu_menu12Text)($s6)
    /* 451C 80106D1C 80901000 */  sll        $s2, $s0, 2
    /* 4520 80106D20 21104302 */  addu       $v0, $s2, $v1
    /* 4524 80106D24 38004294 */  lhu        $v0, 0x38($v0)
    /* 4528 80106D28 21200000 */  addu       $a0, $zero, $zero
    /* 452C 80106D2C 40100200 */  sll        $v0, $v0, 1
    /* 4530 80106D30 21106200 */  addu       $v0, $v1, $v0
    /* 4534 80106D34 000062AE */  sw         $v0, 0x0($s3)
    /* 4538 80106D38 40101000 */  sll        $v0, $s0, 1
    /* 453C 80106D3C 21104300 */  addu       $v0, $v0, $v1
    /* 4540 80106D40 4A004294 */  lhu        $v0, 0x4A($v0)
    /* 4544 80106D44 2188B402 */  addu       $s1, $s5, $s4
    /* 4548 80106D48 40100200 */  sll        $v0, $v0, 1
    /* 454C 80106D4C 21186200 */  addu       $v1, $v1, $v0
    /* 4550 80106D50 02000012 */  beqz       $s0, .L80106D5C
    /* 4554 80106D54 000023AE */   sw        $v1, 0x0($s1)
    /* 4558 80106D58 03000424 */  addiu      $a0, $zero, 0x3
  .L80106D5C:
    /* 455C 80106D5C 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 4560 80106D60 21280000 */   addu      $a1, $zero, $zero
    /* 4564 80106D64 2000A727 */  addiu      $a3, $sp, 0x20
    /* 4568 80106D68 2128F200 */  addu       $a1, $a3, $s2
    /* 456C 80106D6C 401A0200 */  sll        $v1, $v0, 9
    /* 4570 80106D70 4000043C */  lui        $a0, (0x400000 >> 16)
    /* 4574 80106D74 21186400 */  addu       $v1, $v1, $a0
    /* 4578 80106D78 09004014 */  bnez       $v0, .L80106DA0
    /* 457C 80106D7C 0000A3AC */   sw        $v1, 0x0($a1)
    /* 4580 80106D80 A424C28E */  lw         $v0, %lo(vs_mainMenu_menu12Text)($s6)
    /* 4584 80106D84 00000000 */  nop
    /* 4588 80106D88 E8064224 */  addiu      $v0, $v0, 0x6E8
    /* 458C 80106D8C 000022AE */  sw         $v0, 0x0($s1)
    /* 4590 80106D90 0000A28C */  lw         $v0, 0x0($a1)
    /* 4594 80106D94 00000000 */  nop
    /* 4598 80106D98 01004234 */  ori        $v0, $v0, 0x1
    /* 459C 80106D9C 0000A2AC */  sw         $v0, 0x0($a1)
  .L80106DA0:
    /* 45A0 80106DA0 08009426 */  addiu      $s4, $s4, 0x8
    /* 45A4 80106DA4 01001026 */  addiu      $s0, $s0, 0x1
    /* 45A8 80106DA8 0200022A */  slti       $v0, $s0, 0x2
    /* 45AC 80106DAC DAFF4014 */  bnez       $v0, .L80106D18
    /* 45B0 80106DB0 08007326 */   addiu     $s3, $s3, 0x8
    /* 45B4 80106DB4 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 45B8 80106DB8 20005124 */  addiu      $s1, $v0, %lo(vs_main_settings)
    /* 45BC 80106DBC 1180033C */  lui        $v1, %hi(D_8010BC41)
    /* 45C0 80106DC0 41BC6290 */  lbu        $v0, %lo(D_8010BC41)($v1)
    /* 45C4 80106DC4 01003092 */  lbu        $s0, 0x1($s1)
    /* 45C8 80106DC8 03004014 */  bnez       $v0, .L80106DD8
    /* 45CC 80106DCC 02000424 */   addiu     $a0, $zero, 0x2
    /* 45D0 80106DD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 45D4 80106DD4 010022A2 */  sb         $v0, 0x1($s1)
  .L80106DD8:
    /* 45D8 80106DD8 39020524 */  addiu      $a1, $zero, 0x239
    /* 45DC 80106DDC 1000A627 */  addiu      $a2, $sp, 0x10
    /* 45E0 80106DE0 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 45E4 80106DE4 41BC60A0 */   sb        $zero, %lo(D_8010BC41)($v1)
    /* 45E8 80106DE8 1180033C */  lui        $v1, %hi(D_8010BC3F)
    /* 45EC 80106DEC 01000224 */  addiu      $v0, $zero, 0x1
    /* 45F0 80106DF0 010030A2 */  sb         $s0, 0x1($s1)
    /* 45F4 80106DF4 A81B0408 */  j          .L80106EA0
    /* 45F8 80106DF8 3FBC62A0 */   sb        $v0, %lo(D_8010BC3F)($v1)
  .L80106DFC:
    /* 45FC 80106DFC 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 4600 80106E00 00000000 */   nop
    /* 4604 80106E04 01005024 */  addiu      $s0, $v0, 0x1
    /* 4608 80106E08 26000012 */  beqz       $s0, .L80106EA4
    /* 460C 80106E0C 21100000 */   addu      $v0, $zero, $zero
    /* 4610 80106E10 05000106 */  bgez       $s0, .L80106E28
    /* 4614 80106E14 00000000 */   nop
    /* 4618 80106E18 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 461C 80106E1C 21200000 */   addu      $a0, $zero, $zero
    /* 4620 80106E20 A91B0408 */  j          .L80106EA4
    /* 4624 80106E24 21100002 */   addu      $v0, $s0, $zero
  .L80106E28:
    /* 4628 80106E28 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 462C 80106E2C 28000424 */   addiu     $a0, $zero, 0x28
    /* 4630 80106E30 8419040C */  jal        func_80106610
    /* 4634 80106E34 21200002 */   addu      $a0, $s0, $zero
    /* 4638 80106E38 02000224 */  addiu      $v0, $zero, 0x2
    /* 463C 80106E3C A81B0408 */  j          .L80106EA0
    /* 4640 80106E40 3FBC22A2 */   sb        $v0, %lo(D_8010BC3F)($s1)
  .L80106E44:
    /* 4644 80106E44 8419040C */  jal        func_80106610
    /* 4648 80106E48 21200000 */   addu      $a0, $zero, $zero
    /* 464C 80106E4C 21804000 */  addu       $s0, $v0, $zero
    /* 4650 80106E50 13000012 */  beqz       $s0, .L80106EA0
    /* 4654 80106E54 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4658 80106E58 12000216 */  bne        $s0, $v0, .L80106EA4
    /* 465C 80106E5C 21100002 */   addu      $v0, $s0, $zero
    /* 4660 80106E60 03000224 */  addiu      $v0, $zero, 0x3
    /* 4664 80106E64 A81B0408 */  j          .L80106EA0
    /* 4668 80106E68 3FBC22A2 */   sb        $v0, %lo(D_8010BC3F)($s1)
  .L80106E6C:
    /* 466C 80106E6C 74EA030C */  jal        vs_mainmenu_ready
    /* 4670 80106E70 00000000 */   nop
    /* 4674 80106E74 0B004010 */  beqz       $v0, .L80106EA4
    /* 4678 80106E78 21100000 */   addu      $v0, $zero, $zero
    /* 467C 80106E7C F2FE030C */  jal        func_800FFBC8
    /* 4680 80106E80 00000000 */   nop
    /* 4684 80106E84 21200000 */  addu       $a0, $zero, $zero
    /* 4688 80106E88 740A040C */  jal        func_801029D0
    /* 468C 80106E8C 57000524 */   addiu     $a1, $zero, 0x57
    /* 4690 80106E90 0C000424 */  addiu      $a0, $zero, 0xC
    /* 4694 80106E94 740A040C */  jal        func_801029D0
    /* 4698 80106E98 93000524 */   addiu     $a1, $zero, 0x93
    /* 469C 80106E9C 3FBC20A2 */  sb         $zero, %lo(D_8010BC3F)($s1)
  .L80106EA0:
    /* 46A0 80106EA0 21100000 */  addu       $v0, $zero, $zero
  .L80106EA4:
    /* 46A4 80106EA4 4400BF8F */  lw         $ra, 0x44($sp)
    /* 46A8 80106EA8 4000B68F */  lw         $s6, 0x40($sp)
    /* 46AC 80106EAC 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 46B0 80106EB0 3800B48F */  lw         $s4, 0x38($sp)
    /* 46B4 80106EB4 3400B38F */  lw         $s3, 0x34($sp)
    /* 46B8 80106EB8 3000B28F */  lw         $s2, 0x30($sp)
    /* 46BC 80106EBC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 46C0 80106EC0 2800B08F */  lw         $s0, 0x28($sp)
    /* 46C4 80106EC4 0800E003 */  jr         $ra
    /* 46C8 80106EC8 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_80106C64
