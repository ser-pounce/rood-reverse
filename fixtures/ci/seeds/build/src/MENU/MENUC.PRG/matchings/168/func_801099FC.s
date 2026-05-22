nonmatching func_801099FC, 0x3C0

glabel func_801099FC
    /* 71FC 801099FC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 7200 80109A00 21188000 */  addu       $v1, $a0, $zero
    /* 7204 80109A04 2000B2AF */  sw         $s2, 0x20($sp)
    /* 7208 80109A08 21900000 */  addu       $s2, $zero, $zero
    /* 720C 80109A0C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 7210 80109A10 3800BEAF */  sw         $fp, 0x38($sp)
    /* 7214 80109A14 3400B7AF */  sw         $s7, 0x34($sp)
    /* 7218 80109A18 3000B6AF */  sw         $s6, 0x30($sp)
    /* 721C 80109A1C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 7220 80109A20 2800B4AF */  sw         $s4, 0x28($sp)
    /* 7224 80109A24 2400B3AF */  sw         $s3, 0x24($sp)
    /* 7228 80109A28 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 722C 80109A2C 09006010 */  beqz       $v1, .L80109A54
    /* 7230 80109A30 1800B0AF */   sw        $s0, 0x18($sp)
    /* 7234 80109A34 0A006424 */  addiu      $a0, $v1, 0xA
    /* 7238 80109A38 1180023C */  lui        $v0, %hi(D_8010BC79)
    /* 723C 80109A3C 630F040C */  jal        func_80103D8C
    /* 7240 80109A40 79BC43A0 */   sb        $v1, %lo(D_8010BC79)($v0)
    /* 7244 80109A44 21104002 */  addu       $v0, $s2, $zero
    /* 7248 80109A48 1180033C */  lui        $v1, %hi(D_8010BC78)
    /* 724C 80109A4C 63270408 */  j          .L80109D8C
    /* 7250 80109A50 78BC60A0 */   sb        $zero, %lo(D_8010BC78)($v1)
  .L80109A54:
    /* 7254 80109A54 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7258 80109A58 1180033C */  lui        $v1, %hi(D_8010BC79)
    /* 725C 80109A5C 79BC6390 */  lbu        $v1, %lo(D_8010BC79)($v1)
    /* 7260 80109A60 7CBD4224 */  addiu      $v0, $v0, %lo(D_8010BD7C)
    /* 7264 80109A64 21186200 */  addu       $v1, $v1, $v0
    /* 7268 80109A68 FFFF7090 */  lbu        $s0, -0x1($v1)
    /* 726C 80109A6C 00000000 */  nop
    /* 7270 80109A70 06000012 */  beqz       $s0, .L80109A8C
    /* 7274 80109A74 80181000 */   sll       $v1, $s0, 2
    /* 7278 80109A78 21187000 */  addu       $v1, $v1, $s0
    /* 727C 80109A7C C0180300 */  sll        $v1, $v1, 3
    /* 7280 80109A80 0680023C */  lui        $v0, %hi(D_80060780)
    /* 7284 80109A84 80074224 */  addiu      $v0, $v0, %lo(D_80060780)
    /* 7288 80109A88 21906200 */  addu       $s2, $v1, $v0
  .L80109A8C:
    /* 728C 80109A8C 1180023C */  lui        $v0, %hi(D_8010BC78)
    /* 7290 80109A90 78BC4390 */  lbu        $v1, %lo(D_8010BC78)($v0)
    /* 7294 80109A94 01001124 */  addiu      $s1, $zero, 0x1
    /* 7298 80109A98 82007110 */  beq        $v1, $s1, .L80109CA4
    /* 729C 80109A9C 02006228 */   slti      $v0, $v1, 0x2
    /* 72A0 80109AA0 05004010 */  beqz       $v0, .L80109AB8
    /* 72A4 80109AA4 02000224 */   addiu     $v0, $zero, 0x2
    /* 72A8 80109AA8 07006010 */  beqz       $v1, .L80109AC8
    /* 72AC 80109AAC 21100000 */   addu      $v0, $zero, $zero
    /* 72B0 80109AB0 63270408 */  j          .L80109D8C
    /* 72B4 80109AB4 00000000 */   nop
  .L80109AB8:
    /* 72B8 80109AB8 AC006210 */  beq        $v1, $v0, .L80109D6C
    /* 72BC 80109ABC 21100000 */   addu      $v0, $zero, $zero
    /* 72C0 80109AC0 63270408 */  j          .L80109D8C
    /* 72C4 80109AC4 00000000 */   nop
  .L80109AC8:
    /* 72C8 80109AC8 74EA030C */  jal        vs_mainmenu_ready
    /* 72CC 80109ACC 00000000 */   nop
    /* 72D0 80109AD0 AE004010 */  beqz       $v0, .L80109D8C
    /* 72D4 80109AD4 21100000 */   addu      $v0, $zero, $zero
    /* 72D8 80109AD8 8F0F010C */  jal        vs_main_allocHeapR
    /* 72DC 80109ADC 2C070424 */   addiu     $a0, $zero, 0x72C
    /* 72E0 80109AE0 21B84000 */  addu       $s7, $v0, $zero
    /* 72E4 80109AE4 A406E826 */  addiu      $t0, $s7, 0x6A4
    /* 72E8 80109AE8 0C004016 */  bnez       $s2, .L80109B1C
    /* 72EC 80109AEC 1000A8AF */   sw        $t0, 0x10($sp)
    /* 72F0 80109AF0 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 72F4 80109AF4 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 72F8 80109AF8 00000000 */  nop
    /* 72FC 80109AFC 7A086224 */  addiu      $v0, $v1, 0x87A
    /* 7300 80109B00 A406E2AE */  sw         $v0, 0x6A4($s7)
    /* 7304 80109B04 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 7308 80109B08 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 730C 80109B0C D4086324 */  addiu      $v1, $v1, 0x8D4
    /* 7310 80109B10 040003AD */  sw         $v1, 0x4($t0)
    /* 7314 80109B14 CD260408 */  j          .L80109B34
    /* 7318 80109B18 000051AC */   sw        $s1, 0x0($v0)
  .L80109B1C:
    /* 731C 80109B1C 21204002 */  addu       $a0, $s2, $zero
    /* 7320 80109B20 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 7324 80109B24 1000A58F */  lw         $a1, 0x10($sp)
    /* 7328 80109B28 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 732C 80109B2C 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 7330 80109B30 2138E002 */   addu      $a3, $s7, $zero
  .L80109B34:
    /* 7334 80109B34 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 7338 80109B38 01001424 */  addiu      $s4, $zero, 0x1
    /* 733C 80109B3C 21A80000 */  addu       $s5, $zero, $zero
    /* 7340 80109B40 0F801E3C */  lui        $fp, %hi(vs_battle_rowTypeBuf)
    /* 7344 80109B44 1000A88F */  lw         $t0, 0x10($sp)
    /* 7348 80109B48 6000F626 */  addiu      $s6, $s7, 0x60
    /* 734C 80109B4C A4BC50A0 */  sb         $s0, %lo(D_8010BCA4)($v0)
    /* 7350 80109B50 08001325 */  addiu      $s3, $t0, 0x8
    /* 7354 80109B54 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L80109B58:
    /* 7358 80109B58 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 735C 80109B5C 2110A802 */  addu       $v0, $s5, $t0
    /* 7360 80109B60 30005090 */  lbu        $s0, 0x30($v0)
    /* 7364 80109B64 00000000 */  nop
    /* 7368 80109B68 3F000012 */  beqz       $s0, .L80109C68
    /* 736C 80109B6C 1180023C */   lui       $v0, %hi(D_8010BD7C)
    /* 7370 80109B70 7CBD4390 */  lbu        $v1, %lo(D_8010BD7C)($v0)
    /* 7374 80109B74 00000000 */  nop
    /* 7378 80109B78 3B000312 */  beq        $s0, $v1, .L80109C68
    /* 737C 80109B7C 7CBD4224 */   addiu     $v0, $v0, %lo(D_8010BD7C)
    /* 7380 80109B80 01004290 */  lbu        $v0, 0x1($v0)
    /* 7384 80109B84 00000000 */  nop
    /* 7388 80109B88 37000212 */  beq        $s0, $v0, .L80109C68
    /* 738C 80109B8C 80101000 */   sll       $v0, $s0, 2
    /* 7390 80109B90 21105000 */  addu       $v0, $v0, $s0
    /* 7394 80109B94 C0100200 */  sll        $v0, $v0, 3
    /* 7398 80109B98 0680083C */  lui        $t0, %hi(D_80060780)
    /* 739C 80109B9C 80070825 */  addiu      $t0, $t0, %lo(D_80060780)
    /* 73A0 80109BA0 21904800 */  addu       $s2, $v0, $t0
    /* 73A4 80109BA4 03004392 */  lbu        $v1, 0x3($s2)
    /* 73A8 80109BA8 07000224 */  addiu      $v0, $zero, 0x7
    /* 73AC 80109BAC 2E006210 */  beq        $v1, $v0, .L80109C68
    /* 73B0 80109BB0 21204002 */   addu      $a0, $s2, $zero
    /* 73B4 80109BB4 21286002 */  addu       $a1, $s3, $zero
    /* 73B8 80109BB8 2138C002 */  addu       $a3, $s6, $zero
    /* 73BC 80109BBC 844EC68F */  lw         $a2, %lo(vs_battle_rowTypeBuf)($fp)
    /* 73C0 80109BC0 80881400 */  sll        $s1, $s4, 2
    /* 73C4 80109BC4 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 73C8 80109BC8 2130D100 */   addu      $a2, $a2, $s1
    /* 73CC 80109BCC 1180023C */  lui        $v0, %hi(_inWorkshop)
    /* 73D0 80109BD0 1180083C */  lui        $t0, %hi(D_8010BB30)
    /* 73D4 80109BD4 30BB0825 */  addiu      $t0, $t0, %lo(D_8010BB30)
    /* 73D8 80109BD8 80BC4290 */  lbu        $v0, %lo(_inWorkshop)($v0)
    /* 73DC 80109BDC 24004396 */  lhu        $v1, 0x24($s2)
    /* 73E0 80109BE0 21104800 */  addu       $v0, $v0, $t0
    /* 73E4 80109BE4 00004290 */  lbu        $v0, 0x0($v0)
    /* 73E8 80109BE8 00000000 */  nop
    /* 73EC 80109BEC 07106200 */  srav       $v0, $v0, $v1
    /* 73F0 80109BF0 01004230 */  andi       $v0, $v0, 0x1
    /* 73F4 80109BF4 0A004014 */  bnez       $v0, .L80109C20
    /* 73F8 80109BF8 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 73FC 80109BFC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 7400 80109C00 844EC38F */  lw         $v1, %lo(vs_battle_rowTypeBuf)($fp)
    /* 7404 80109C04 54034224 */  addiu      $v0, $v0, 0x354
    /* 7408 80109C08 21182302 */  addu       $v1, $s1, $v1
    /* 740C 80109C0C 040062AE */  sw         $v0, 0x4($s3)
    /* 7410 80109C10 0000628C */  lw         $v0, 0x0($v1)
    /* 7414 80109C14 00000000 */  nop
    /* 7418 80109C18 01004234 */  ori        $v0, $v0, 0x1
    /* 741C 80109C1C 000062AC */  sw         $v0, 0x0($v1)
  .L80109C20:
    /* 7420 80109C20 26004292 */  lbu        $v0, 0x26($s2)
    /* 7424 80109C24 00000000 */  nop
    /* 7428 80109C28 09004010 */  beqz       $v0, .L80109C50
    /* 742C 80109C2C 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 7430 80109C30 844EC38F */  lw         $v1, %lo(vs_battle_rowTypeBuf)($fp)
    /* 7434 80109C34 00000000 */  nop
    /* 7438 80109C38 21182302 */  addu       $v1, $s1, $v1
    /* 743C 80109C3C 0000628C */  lw         $v0, 0x0($v1)
    /* 7440 80109C40 00000000 */  nop
    /* 7444 80109C44 00CA4234 */  ori        $v0, $v0, 0xCA00
    /* 7448 80109C48 000062AC */  sw         $v0, 0x0($v1)
    /* 744C 80109C4C 1180023C */  lui        $v0, %hi(D_8010BCA4)
  .L80109C50:
    /* 7450 80109C50 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 7454 80109C54 21108202 */  addu       $v0, $s4, $v0
    /* 7458 80109C58 000050A0 */  sb         $s0, 0x0($v0)
    /* 745C 80109C5C 6000D626 */  addiu      $s6, $s6, 0x60
    /* 7460 80109C60 08007326 */  addiu      $s3, $s3, 0x8
    /* 7464 80109C64 01009426 */  addiu      $s4, $s4, 0x1
  .L80109C68:
    /* 7468 80109C68 0100B526 */  addiu      $s5, $s5, 0x1
    /* 746C 80109C6C 1000A22A */  slti       $v0, $s5, 0x10
    /* 7470 80109C70 B9FF4014 */  bnez       $v0, .L80109B58
    /* 7474 80109C74 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
    /* 7478 80109C78 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 747C 80109C7C 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 7480 80109C80 1000A58F */  lw         $a1, 0x10($sp)
    /* 7484 80109C84 FF0C040C */  jal        _populateItemsList
    /* 7488 80109C88 21208002 */   addu      $a0, $s4, $zero
    /* 748C 80109C8C 180F010C */  jal        vs_main_freeHeapR
    /* 7490 80109C90 2120E002 */   addu      $a0, $s7, $zero
    /* 7494 80109C94 1180033C */  lui        $v1, %hi(D_8010BC78)
    /* 7498 80109C98 01000224 */  addiu      $v0, $zero, 0x1
    /* 749C 80109C9C 62270408 */  j          .L80109D88
    /* 74A0 80109CA0 78BC62A0 */   sb        $v0, %lo(D_8010BC78)($v1)
  .L80109CA4:
    /* 74A4 80109CA4 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 74A8 80109CA8 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 74AC 80109CAC 1180043C */  lui        $a0, %hi(D_8010BC9C)
    /* 74B0 80109CB0 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 74B4 80109CB4 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 74B8 80109CB8 A4BC6324 */  addiu      $v1, $v1, %lo(D_8010BCA4)
    /* 74BC 80109CBC 21104400 */  addu       $v0, $v0, $a0
    /* 74C0 80109CC0 21104300 */  addu       $v0, $v0, $v1
    /* 74C4 80109CC4 00005090 */  lbu        $s0, 0x0($v0)
    /* 74C8 80109CC8 00000000 */  nop
    /* 74CC 80109CCC 05000012 */  beqz       $s0, .L80109CE4
    /* 74D0 80109CD0 00000000 */   nop
    /* 74D4 80109CD4 C0F5030C */  jal        vs_mainMenu_setArmorStats
    /* 74D8 80109CD8 21200002 */   addu      $a0, $s0, $zero
    /* 74DC 80109CDC 3C270408 */  j          .L80109CF0
    /* 74E0 80109CE0 1180043C */   lui       $a0, %hi(D_8010BC9C)
  .L80109CE4:
    /* 74E4 80109CE4 88F4030C */  jal        vs_mainMenu_resetStats
    /* 74E8 80109CE8 00000000 */   nop
    /* 74EC 80109CEC 1180043C */  lui        $a0, %hi(D_8010BC9C)
  .L80109CF0:
    /* 74F0 80109CF0 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 74F4 80109CF4 1180033C */  lui        $v1, %hi(D_8010BCA0)
    /* 74F8 80109CF8 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 74FC 80109CFC 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 7500 80109D00 A0BC6590 */  lbu        $a1, %lo(D_8010BCA0)($v1)
    /* 7504 80109D04 79FE030C */  jal        vs_mainMenu_printInformation
    /* 7508 80109D08 21208200 */   addu      $a0, $a0, $v0
    /* 750C 80109D0C 820D040C */  jal        func_80103608
    /* 7510 80109D10 02000424 */   addiu     $a0, $zero, 0x2
    /* 7514 80109D14 780D040C */  jal        func_801035E0
    /* 7518 80109D18 1180103C */   lui       $s0, %hi(D_8010BC74)
    /* 751C 80109D1C 01004224 */  addiu      $v0, $v0, 0x1
    /* 7520 80109D20 19004010 */  beqz       $v0, .L80109D88
    /* 7524 80109D24 74BC02AE */   sw        $v0, %lo(D_8010BC74)($s0)
    /* 7528 80109D28 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 752C 80109D2C 28000424 */   addiu     $a0, $zero, 0x28
    /* 7530 80109D30 74BC038E */  lw         $v1, %lo(D_8010BC74)($s0)
    /* 7534 80109D34 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 7538 80109D38 14006210 */  beq        $v1, $v0, .L80109D8C
    /* 753C 80109D3C 00000000 */   nop
    /* 7540 80109D40 06006018 */  blez       $v1, .L80109D5C
    /* 7544 80109D44 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 7548 80109D48 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 754C 80109D4C 21106200 */  addu       $v0, $v1, $v0
    /* 7550 80109D50 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 7554 80109D54 00000000 */  nop
    /* 7558 80109D58 74BC02AE */  sw         $v0, %lo(D_8010BC74)($s0)
  .L80109D5C:
    /* 755C 80109D5C 1180033C */  lui        $v1, %hi(D_8010BC78)
    /* 7560 80109D60 02000224 */  addiu      $v0, $zero, 0x2
    /* 7564 80109D64 62270408 */  j          .L80109D88
    /* 7568 80109D68 78BC62A0 */   sb        $v0, %lo(D_8010BC78)($v1)
  .L80109D6C:
    /* 756C 80109D6C 74EA030C */  jal        vs_mainmenu_ready
    /* 7570 80109D70 00000000 */   nop
    /* 7574 80109D74 04004010 */  beqz       $v0, .L80109D88
    /* 7578 80109D78 1180023C */   lui       $v0, %hi(D_8010BC74)
    /* 757C 80109D7C 74BC428C */  lw         $v0, %lo(D_8010BC74)($v0)
    /* 7580 80109D80 63270408 */  j          .L80109D8C
    /* 7584 80109D84 00000000 */   nop
  .L80109D88:
    /* 7588 80109D88 21100000 */  addu       $v0, $zero, $zero
  .L80109D8C:
    /* 758C 80109D8C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 7590 80109D90 3800BE8F */  lw         $fp, 0x38($sp)
    /* 7594 80109D94 3400B78F */  lw         $s7, 0x34($sp)
    /* 7598 80109D98 3000B68F */  lw         $s6, 0x30($sp)
    /* 759C 80109D9C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 75A0 80109DA0 2800B48F */  lw         $s4, 0x28($sp)
    /* 75A4 80109DA4 2400B38F */  lw         $s3, 0x24($sp)
    /* 75A8 80109DA8 2000B28F */  lw         $s2, 0x20($sp)
    /* 75AC 80109DAC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 75B0 80109DB0 1800B08F */  lw         $s0, 0x18($sp)
    /* 75B4 80109DB4 0800E003 */  jr         $ra
    /* 75B8 80109DB8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_801099FC
