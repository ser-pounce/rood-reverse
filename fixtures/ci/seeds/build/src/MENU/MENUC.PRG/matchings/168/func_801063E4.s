nonmatching func_801063E4, 0x22C

glabel func_801063E4
    /* 3BE4 801063E4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 3BE8 801063E8 3800BFAF */  sw         $ra, 0x38($sp)
    /* 3BEC 801063EC 3400B1AF */  sw         $s1, 0x34($sp)
    /* 3BF0 801063F0 0B008010 */  beqz       $a0, .L80106420
    /* 3BF4 801063F4 3000B0AF */   sw        $s0, 0x30($sp)
    /* 3BF8 801063F8 01000424 */  addiu      $a0, $zero, 0x1
    /* 3BFC 801063FC 21288000 */  addu       $a1, $a0, $zero
    /* 3C00 80106400 1180023C */  lui        $v0, %hi(D_8010BC35)
    /* 3C04 80106404 21188000 */  addu       $v1, $a0, $zero
    /* 3C08 80106408 4BEA030C */  jal        func_800FA92C
    /* 3C0C 8010640C 35BC43A0 */   sb        $v1, %lo(D_8010BC35)($v0)
    /* 3C10 80106410 21100000 */  addu       $v0, $zero, $zero
    /* 3C14 80106414 1180033C */  lui        $v1, %hi(D_8010BC34)
    /* 3C18 80106418 7F190408 */  j          .L801065FC
    /* 3C1C 8010641C 34BC60A0 */   sb        $zero, %lo(D_8010BC34)($v1)
  .L80106420:
    /* 3C20 80106420 1180113C */  lui        $s1, %hi(D_8010BC34)
    /* 3C24 80106424 34BC2392 */  lbu        $v1, %lo(D_8010BC34)($s1)
    /* 3C28 80106428 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C2C 8010642C 49006210 */  beq        $v1, $v0, .L80106554
    /* 3C30 80106430 02006228 */   slti      $v0, $v1, 0x2
    /* 3C34 80106434 05004010 */  beqz       $v0, .L8010644C
    /* 3C38 80106438 02000224 */   addiu     $v0, $zero, 0x2
    /* 3C3C 8010643C 09006010 */  beqz       $v1, .L80106464
    /* 3C40 80106440 21100000 */   addu      $v0, $zero, $zero
    /* 3C44 80106444 7F190408 */  j          .L801065FC
    /* 3C48 80106448 00000000 */   nop
  .L8010644C:
    /* 3C4C 8010644C 53006210 */  beq        $v1, $v0, .L8010659C
    /* 3C50 80106450 03000224 */   addiu     $v0, $zero, 0x3
    /* 3C54 80106454 5B006210 */  beq        $v1, $v0, .L801065C4
    /* 3C58 80106458 21100000 */   addu      $v0, $zero, $zero
    /* 3C5C 8010645C 7F190408 */  j          .L801065FC
    /* 3C60 80106460 00000000 */   nop
  .L80106464:
    /* 3C64 80106464 74EA030C */  jal        vs_mainmenu_ready
    /* 3C68 80106468 00000000 */   nop
    /* 3C6C 8010646C 62004010 */  beqz       $v0, .L801065F8
    /* 3C70 80106470 21800000 */   addu      $s0, $zero, $zero
    /* 3C74 80106474 2000A527 */  addiu      $a1, $sp, 0x20
    /* 3C78 80106478 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 3C7C 8010647C A424468C */  lw         $a2, %lo(vs_mainMenu_menu12Text)($v0)
    /* 3C80 80106480 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3C84 80106484 2118C000 */  addu       $v1, $a2, $zero
  .L80106488:
    /* 3C88 80106488 38006294 */  lhu        $v0, 0x38($v1)
    /* 3C8C 8010648C 02006324 */  addiu      $v1, $v1, 0x2
    /* 3C90 80106490 01001026 */  addiu      $s0, $s0, 0x1
    /* 3C94 80106494 40100200 */  sll        $v0, $v0, 1
    /* 3C98 80106498 2110C200 */  addu       $v0, $a2, $v0
    /* 3C9C 8010649C 000082AC */  sw         $v0, 0x0($a0)
    /* 3CA0 801064A0 0000A0AC */  sw         $zero, 0x0($a1)
    /* 3CA4 801064A4 0400A524 */  addiu      $a1, $a1, 0x4
    /* 3CA8 801064A8 0400022A */  slti       $v0, $s0, 0x4
    /* 3CAC 801064AC F6FF4014 */  bnez       $v0, .L80106488
    /* 3CB0 801064B0 04008424 */   addiu     $a0, $a0, 0x4
    /* 3CB4 801064B4 21200000 */  addu       $a0, $zero, $zero
    /* 3CB8 801064B8 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 3CBC 801064BC 21288000 */   addu      $a1, $a0, $zero
    /* 3CC0 801064C0 07004014 */  bnez       $v0, .L801064E0
    /* 3CC4 801064C4 03000424 */   addiu     $a0, $zero, 0x3
    /* 3CC8 801064C8 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 3CCC 801064CC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 3CD0 801064D0 01000324 */  addiu      $v1, $zero, 0x1
    /* 3CD4 801064D4 2000A3AF */  sw         $v1, 0x20($sp)
    /* 3CD8 801064D8 E8064224 */  addiu      $v0, $v0, 0x6E8
    /* 3CDC 801064DC 1400A2AF */  sw         $v0, 0x14($sp)
  .L801064E0:
    /* 3CE0 801064E0 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 3CE4 801064E4 21280000 */   addu      $a1, $zero, $zero
    /* 3CE8 801064E8 08004014 */  bnez       $v0, .L8010650C
    /* 3CEC 801064EC 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 3CF0 801064F0 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 3CF4 801064F4 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 3CF8 801064F8 01000324 */  addiu      $v1, $zero, 0x1
    /* 3CFC 801064FC 2400A3AF */  sw         $v1, 0x24($sp)
    /* 3D00 80106500 E8064224 */  addiu      $v0, $v0, 0x6E8
    /* 3D04 80106504 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 3D08 80106508 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L8010650C:
    /* 3D0C 8010650C 20005124 */  addiu      $s1, $v0, %lo(vs_main_settings)
    /* 3D10 80106510 1180033C */  lui        $v1, %hi(D_8010BC35)
    /* 3D14 80106514 35BC6290 */  lbu        $v0, %lo(D_8010BC35)($v1)
    /* 3D18 80106518 01003092 */  lbu        $s0, 0x1($s1)
    /* 3D1C 8010651C 03004014 */  bnez       $v0, .L8010652C
    /* 3D20 80106520 02000424 */   addiu     $a0, $zero, 0x2
    /* 3D24 80106524 01000224 */  addiu      $v0, $zero, 0x1
    /* 3D28 80106528 010022A2 */  sb         $v0, 0x1($s1)
  .L8010652C:
    /* 3D2C 8010652C 36020524 */  addiu      $a1, $zero, 0x236
    /* 3D30 80106530 1000A627 */  addiu      $a2, $sp, 0x10
    /* 3D34 80106534 2000A727 */  addiu      $a3, $sp, 0x20
    /* 3D38 80106538 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 3D3C 8010653C 35BC60A0 */   sb        $zero, %lo(D_8010BC35)($v1)
    /* 3D40 80106540 1180033C */  lui        $v1, %hi(D_8010BC34)
    /* 3D44 80106544 01000224 */  addiu      $v0, $zero, 0x1
    /* 3D48 80106548 010030A2 */  sb         $s0, 0x1($s1)
    /* 3D4C 8010654C 7E190408 */  j          .L801065F8
    /* 3D50 80106550 34BC62A0 */   sb        $v0, %lo(D_8010BC34)($v1)
  .L80106554:
    /* 3D54 80106554 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 3D58 80106558 00000000 */   nop
    /* 3D5C 8010655C 01005024 */  addiu      $s0, $v0, 0x1
    /* 3D60 80106560 26000012 */  beqz       $s0, .L801065FC
    /* 3D64 80106564 21100000 */   addu      $v0, $zero, $zero
    /* 3D68 80106568 05000106 */  bgez       $s0, .L80106580
    /* 3D6C 8010656C 00000000 */   nop
    /* 3D70 80106570 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 3D74 80106574 21200000 */   addu      $a0, $zero, $zero
    /* 3D78 80106578 7F190408 */  j          .L801065FC
    /* 3D7C 8010657C 21100002 */   addu      $v0, $s0, $zero
  .L80106580:
    /* 3D80 80106580 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 3D84 80106584 28000424 */   addiu     $a0, $zero, 0x28
    /* 3D88 80106588 EF15040C */  jal        func_801057BC
    /* 3D8C 8010658C 21200002 */   addu      $a0, $s0, $zero
    /* 3D90 80106590 02000224 */  addiu      $v0, $zero, 0x2
    /* 3D94 80106594 7E190408 */  j          .L801065F8
    /* 3D98 80106598 34BC22A2 */   sb        $v0, %lo(D_8010BC34)($s1)
  .L8010659C:
    /* 3D9C 8010659C EF15040C */  jal        func_801057BC
    /* 3DA0 801065A0 21200000 */   addu      $a0, $zero, $zero
    /* 3DA4 801065A4 21804000 */  addu       $s0, $v0, $zero
    /* 3DA8 801065A8 13000012 */  beqz       $s0, .L801065F8
    /* 3DAC 801065AC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3DB0 801065B0 12000216 */  bne        $s0, $v0, .L801065FC
    /* 3DB4 801065B4 21100002 */   addu      $v0, $s0, $zero
    /* 3DB8 801065B8 03000224 */  addiu      $v0, $zero, 0x3
    /* 3DBC 801065BC 7E190408 */  j          .L801065F8
    /* 3DC0 801065C0 34BC22A2 */   sb        $v0, %lo(D_8010BC34)($s1)
  .L801065C4:
    /* 3DC4 801065C4 74EA030C */  jal        vs_mainmenu_ready
    /* 3DC8 801065C8 00000000 */   nop
    /* 3DCC 801065CC 0B004010 */  beqz       $v0, .L801065FC
    /* 3DD0 801065D0 21100000 */   addu      $v0, $zero, $zero
    /* 3DD4 801065D4 F2FE030C */  jal        func_800FFBC8
    /* 3DD8 801065D8 00000000 */   nop
    /* 3DDC 801065DC 21200000 */  addu       $a0, $zero, $zero
    /* 3DE0 801065E0 740A040C */  jal        func_801029D0
    /* 3DE4 801065E4 57000524 */   addiu     $a1, $zero, 0x57
    /* 3DE8 801065E8 0B000424 */  addiu      $a0, $zero, 0xB
    /* 3DEC 801065EC 740A040C */  jal        func_801029D0
    /* 3DF0 801065F0 7B000524 */   addiu     $a1, $zero, 0x7B
    /* 3DF4 801065F4 34BC20A2 */  sb         $zero, %lo(D_8010BC34)($s1)
  .L801065F8:
    /* 3DF8 801065F8 21100000 */  addu       $v0, $zero, $zero
  .L801065FC:
    /* 3DFC 801065FC 3800BF8F */  lw         $ra, 0x38($sp)
    /* 3E00 80106600 3400B18F */  lw         $s1, 0x34($sp)
    /* 3E04 80106604 3000B08F */  lw         $s0, 0x30($sp)
    /* 3E08 80106608 0800E003 */  jr         $ra
    /* 3E0C 8010660C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_801063E4
