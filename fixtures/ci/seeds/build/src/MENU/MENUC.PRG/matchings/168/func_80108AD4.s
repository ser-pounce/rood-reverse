nonmatching func_80108AD4, 0x3C8

glabel func_80108AD4
    /* 62D4 80108AD4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 62D8 80108AD8 21188000 */  addu       $v1, $a0, $zero
    /* 62DC 80108ADC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 62E0 80108AE0 21900000 */  addu       $s2, $zero, $zero
    /* 62E4 80108AE4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 62E8 80108AE8 3800BEAF */  sw         $fp, 0x38($sp)
    /* 62EC 80108AEC 3400B7AF */  sw         $s7, 0x34($sp)
    /* 62F0 80108AF0 3000B6AF */  sw         $s6, 0x30($sp)
    /* 62F4 80108AF4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 62F8 80108AF8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 62FC 80108AFC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6300 80108B00 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6304 80108B04 09006010 */  beqz       $v1, .L80108B2C
    /* 6308 80108B08 1800B0AF */   sw        $s0, 0x18($sp)
    /* 630C 80108B0C 0A006424 */  addiu      $a0, $v1, 0xA
    /* 6310 80108B10 1180023C */  lui        $v0, %hi(D_8010BC6D)
    /* 6314 80108B14 630F040C */  jal        func_80103D8C
    /* 6318 80108B18 6DBC43A0 */   sb        $v1, %lo(D_8010BC6D)($v0)
    /* 631C 80108B1C 21104002 */  addu       $v0, $s2, $zero
    /* 6320 80108B20 1180033C */  lui        $v1, %hi(D_8010BC6C)
    /* 6324 80108B24 9B230408 */  j          .L80108E6C
    /* 6328 80108B28 6CBC60A0 */   sb        $zero, %lo(D_8010BC6C)($v1)
  .L80108B2C:
    /* 632C 80108B2C 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 6330 80108B30 1180033C */  lui        $v1, %hi(D_8010BC6D)
    /* 6334 80108B34 6DBC6390 */  lbu        $v1, %lo(D_8010BC6D)($v1)
    /* 6338 80108B38 44BD4224 */  addiu      $v0, $v0, %lo(D_8010BD44)
    /* 633C 80108B3C 21186200 */  addu       $v1, $v1, $v0
    /* 6340 80108B40 FFFF7090 */  lbu        $s0, -0x1($v1)
    /* 6344 80108B44 00000000 */  nop
    /* 6348 80108B48 06000012 */  beqz       $s0, .L80108B64
    /* 634C 80108B4C 40181000 */   sll       $v1, $s0, 1
    /* 6350 80108B50 21187000 */  addu       $v1, $v1, $s0
    /* 6354 80108B54 00190300 */  sll        $v1, $v1, 4
    /* 6358 80108B58 0680023C */  lui        $v0, %hi(D_80060238)
    /* 635C 80108B5C 38024224 */  addiu      $v0, $v0, %lo(D_80060238)
    /* 6360 80108B60 21906200 */  addu       $s2, $v1, $v0
  .L80108B64:
    /* 6364 80108B64 1180023C */  lui        $v0, %hi(D_8010BC6C)
    /* 6368 80108B68 6CBC4390 */  lbu        $v1, %lo(D_8010BC6C)($v0)
    /* 636C 80108B6C 01001124 */  addiu      $s1, $zero, 0x1
    /* 6370 80108B70 80007110 */  beq        $v1, $s1, .L80108D74
    /* 6374 80108B74 02006228 */   slti      $v0, $v1, 0x2
    /* 6378 80108B78 05004010 */  beqz       $v0, .L80108B90
    /* 637C 80108B7C 02000224 */   addiu     $v0, $zero, 0x2
    /* 6380 80108B80 07006010 */  beqz       $v1, .L80108BA0
    /* 6384 80108B84 21100000 */   addu      $v0, $zero, $zero
    /* 6388 80108B88 9B230408 */  j          .L80108E6C
    /* 638C 80108B8C 00000000 */   nop
  .L80108B90:
    /* 6390 80108B90 AE006210 */  beq        $v1, $v0, .L80108E4C
    /* 6394 80108B94 21100000 */   addu      $v0, $zero, $zero
    /* 6398 80108B98 9B230408 */  j          .L80108E6C
    /* 639C 80108B9C 00000000 */   nop
  .L80108BA0:
    /* 63A0 80108BA0 74EA030C */  jal        vs_mainmenu_ready
    /* 63A4 80108BA4 00000000 */   nop
    /* 63A8 80108BA8 B0004010 */  beqz       $v0, .L80108E6C
    /* 63AC 80108BAC 21100000 */   addu      $v0, $zero, $zero
    /* 63B0 80108BB0 8F0F010C */  jal        vs_main_allocHeapR
    /* 63B4 80108BB4 CC030424 */   addiu     $a0, $zero, 0x3CC
    /* 63B8 80108BB8 21B84000 */  addu       $s7, $v0, $zero
    /* 63BC 80108BBC 8403E826 */  addiu      $t0, $s7, 0x384
    /* 63C0 80108BC0 0C004016 */  bnez       $s2, .L80108BF4
    /* 63C4 80108BC4 1000A8AF */   sw        $t0, 0x10($sp)
    /* 63C8 80108BC8 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 63CC 80108BCC A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 63D0 80108BD0 00000000 */  nop
    /* 63D4 80108BD4 72086224 */  addiu      $v0, $v1, 0x872
    /* 63D8 80108BD8 8403E2AE */  sw         $v0, 0x384($s7)
    /* 63DC 80108BDC 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 63E0 80108BE0 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 63E4 80108BE4 C2086324 */  addiu      $v1, $v1, 0x8C2
    /* 63E8 80108BE8 040003AD */  sw         $v1, 0x4($t0)
    /* 63EC 80108BEC 03230408 */  j          .L80108C0C
    /* 63F0 80108BF0 000051AC */   sw        $s1, 0x0($v0)
  .L80108BF4:
    /* 63F4 80108BF4 21204002 */  addu       $a0, $s2, $zero
    /* 63F8 80108BF8 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 63FC 80108BFC 1000A58F */  lw         $a1, 0x10($sp)
    /* 6400 80108C00 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 6404 80108C04 A722040C */  jal        func_80108A9C
    /* 6408 80108C08 2138E002 */   addu      $a3, $s7, $zero
  .L80108C0C:
    /* 640C 80108C0C 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 6410 80108C10 01001424 */  addiu      $s4, $zero, 0x1
    /* 6414 80108C14 21A80000 */  addu       $s5, $zero, $zero
    /* 6418 80108C18 0F801E3C */  lui        $fp, %hi(vs_battle_rowTypeBuf)
    /* 641C 80108C1C 1000A88F */  lw         $t0, 0x10($sp)
    /* 6420 80108C20 6000F626 */  addiu      $s6, $s7, 0x60
    /* 6424 80108C24 A4BC50A0 */  sb         $s0, %lo(D_8010BCA4)($v0)
    /* 6428 80108C28 08001325 */  addiu      $s3, $t0, 0x8
    /* 642C 80108C2C 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L80108C30:
    /* 6430 80108C30 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 6434 80108C34 2110A802 */  addu       $v0, $s5, $t0
    /* 6438 80108C38 28005090 */  lbu        $s0, 0x28($v0)
    /* 643C 80108C3C 00000000 */  nop
    /* 6440 80108C40 3D000012 */  beqz       $s0, .L80108D38
    /* 6444 80108C44 1180023C */   lui       $v0, %hi(D_8010BD44)
    /* 6448 80108C48 44BD4290 */  lbu        $v0, %lo(D_8010BD44)($v0)
    /* 644C 80108C4C 00000000 */  nop
    /* 6450 80108C50 39000212 */  beq        $s0, $v0, .L80108D38
    /* 6454 80108C54 1180083C */   lui       $t0, %hi(D_8010BD44)
    /* 6458 80108C58 44BD0825 */  addiu      $t0, $t0, %lo(D_8010BD44)
    /* 645C 80108C5C 01000291 */  lbu        $v0, 0x1($t0)
    /* 6460 80108C60 00000000 */  nop
    /* 6464 80108C64 34000212 */  beq        $s0, $v0, .L80108D38
    /* 6468 80108C68 40101000 */   sll       $v0, $s0, 1
    /* 646C 80108C6C 21105000 */  addu       $v0, $v0, $s0
    /* 6470 80108C70 00110200 */  sll        $v0, $v0, 4
    /* 6474 80108C74 0680083C */  lui        $t0, %hi(D_80060238)
    /* 6478 80108C78 38020825 */  addiu      $t0, $t0, %lo(D_80060238)
    /* 647C 80108C7C 21904800 */  addu       $s2, $v0, $t0
    /* 6480 80108C80 21204002 */  addu       $a0, $s2, $zero
    /* 6484 80108C84 21286002 */  addu       $a1, $s3, $zero
    /* 6488 80108C88 2138C002 */  addu       $a3, $s6, $zero
    /* 648C 80108C8C 844EC68F */  lw         $a2, %lo(vs_battle_rowTypeBuf)($fp)
    /* 6490 80108C90 80881400 */  sll        $s1, $s4, 2
    /* 6494 80108C94 A722040C */  jal        func_80108A9C
    /* 6498 80108C98 2130D100 */   addu      $a2, $a2, $s1
    /* 649C 80108C9C 1180023C */  lui        $v0, %hi(_inWorkshop)
    /* 64A0 80108CA0 1180083C */  lui        $t0, %hi(D_8010BB30)
    /* 64A4 80108CA4 30BB0825 */  addiu      $t0, $t0, %lo(D_8010BB30)
    /* 64A8 80108CA8 80BC4290 */  lbu        $v0, %lo(_inWorkshop)($v0)
    /* 64AC 80108CAC 28004396 */  lhu        $v1, 0x28($s2)
    /* 64B0 80108CB0 21104800 */  addu       $v0, $v0, $t0
    /* 64B4 80108CB4 00004290 */  lbu        $v0, 0x0($v0)
    /* 64B8 80108CB8 00000000 */  nop
    /* 64BC 80108CBC 07106200 */  srav       $v0, $v0, $v1
    /* 64C0 80108CC0 01004230 */  andi       $v0, $v0, 0x1
    /* 64C4 80108CC4 0A004014 */  bnez       $v0, .L80108CF0
    /* 64C8 80108CC8 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 64CC 80108CCC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 64D0 80108CD0 844EC38F */  lw         $v1, %lo(vs_battle_rowTypeBuf)($fp)
    /* 64D4 80108CD4 16034224 */  addiu      $v0, $v0, 0x316
    /* 64D8 80108CD8 21182302 */  addu       $v1, $s1, $v1
    /* 64DC 80108CDC 040062AE */  sw         $v0, 0x4($s3)
    /* 64E0 80108CE0 0000628C */  lw         $v0, 0x0($v1)
    /* 64E4 80108CE4 00000000 */  nop
    /* 64E8 80108CE8 01004234 */  ori        $v0, $v0, 0x1
    /* 64EC 80108CEC 000062AC */  sw         $v0, 0x0($v1)
  .L80108CF0:
    /* 64F0 80108CF0 01004292 */  lbu        $v0, 0x1($s2)
    /* 64F4 80108CF4 00000000 */  nop
    /* 64F8 80108CF8 09004010 */  beqz       $v0, .L80108D20
    /* 64FC 80108CFC 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 6500 80108D00 844EC38F */  lw         $v1, %lo(vs_battle_rowTypeBuf)($fp)
    /* 6504 80108D04 00000000 */  nop
    /* 6508 80108D08 21182302 */  addu       $v1, $s1, $v1
    /* 650C 80108D0C 0000628C */  lw         $v0, 0x0($v1)
    /* 6510 80108D10 00000000 */  nop
    /* 6514 80108D14 00CA4234 */  ori        $v0, $v0, 0xCA00
    /* 6518 80108D18 000062AC */  sw         $v0, 0x0($v1)
    /* 651C 80108D1C 1180023C */  lui        $v0, %hi(D_8010BCA4)
  .L80108D20:
    /* 6520 80108D20 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 6524 80108D24 21108202 */  addu       $v0, $s4, $v0
    /* 6528 80108D28 000050A0 */  sb         $s0, 0x0($v0)
    /* 652C 80108D2C 6000D626 */  addiu      $s6, $s6, 0x60
    /* 6530 80108D30 08007326 */  addiu      $s3, $s3, 0x8
    /* 6534 80108D34 01009426 */  addiu      $s4, $s4, 0x1
  .L80108D38:
    /* 6538 80108D38 0100B526 */  addiu      $s5, $s5, 0x1
    /* 653C 80108D3C 0800A22A */  slti       $v0, $s5, 0x8
    /* 6540 80108D40 BBFF4014 */  bnez       $v0, .L80108C30
    /* 6544 80108D44 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
    /* 6548 80108D48 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 654C 80108D4C 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 6550 80108D50 1000A58F */  lw         $a1, 0x10($sp)
    /* 6554 80108D54 FF0C040C */  jal        _populateItemsList
    /* 6558 80108D58 21208002 */   addu      $a0, $s4, $zero
    /* 655C 80108D5C 180F010C */  jal        vs_main_freeHeapR
    /* 6560 80108D60 2120E002 */   addu      $a0, $s7, $zero
    /* 6564 80108D64 1180033C */  lui        $v1, %hi(D_8010BC6C)
    /* 6568 80108D68 01000224 */  addiu      $v0, $zero, 0x1
    /* 656C 80108D6C 9A230408 */  j          .L80108E68
    /* 6570 80108D70 6CBC62A0 */   sb        $v0, %lo(D_8010BC6C)($v1)
  .L80108D74:
    /* 6574 80108D74 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 6578 80108D78 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 657C 80108D7C 1180043C */  lui        $a0, %hi(D_8010BC9C)
    /* 6580 80108D80 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 6584 80108D84 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 6588 80108D88 A4BC6324 */  addiu      $v1, $v1, %lo(D_8010BCA4)
    /* 658C 80108D8C 21104400 */  addu       $v0, $v0, $a0
    /* 6590 80108D90 21104300 */  addu       $v0, $v0, $v1
    /* 6594 80108D94 00005090 */  lbu        $s0, 0x0($v0)
    /* 6598 80108D98 00000000 */  nop
    /* 659C 80108D9C 09000012 */  beqz       $s0, .L80108DC4
    /* 65A0 80108DA0 40101000 */   sll       $v0, $s0, 1
    /* 65A4 80108DA4 21105000 */  addu       $v0, $v0, $s0
    /* 65A8 80108DA8 00110200 */  sll        $v0, $v0, 4
    /* 65AC 80108DAC 0680043C */  lui        $a0, %hi(D_80060238)
    /* 65B0 80108DB0 38028424 */  addiu      $a0, $a0, %lo(D_80060238)
    /* 65B4 80108DB4 F921040C */  jal        func_801087E4
    /* 65B8 80108DB8 21204400 */   addu      $a0, $v0, $a0
    /* 65BC 80108DBC 74230408 */  j          .L80108DD0
    /* 65C0 80108DC0 1180043C */   lui       $a0, %hi(D_8010BC9C)
  .L80108DC4:
    /* 65C4 80108DC4 88F4030C */  jal        vs_mainMenu_resetStats
    /* 65C8 80108DC8 00000000 */   nop
    /* 65CC 80108DCC 1180043C */  lui        $a0, %hi(D_8010BC9C)
  .L80108DD0:
    /* 65D0 80108DD0 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 65D4 80108DD4 1180033C */  lui        $v1, %hi(D_8010BCA0)
    /* 65D8 80108DD8 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 65DC 80108DDC 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 65E0 80108DE0 A0BC6590 */  lbu        $a1, %lo(D_8010BCA0)($v1)
    /* 65E4 80108DE4 79FE030C */  jal        vs_mainMenu_printInformation
    /* 65E8 80108DE8 21208200 */   addu      $a0, $a0, $v0
    /* 65EC 80108DEC 820D040C */  jal        func_80103608
    /* 65F0 80108DF0 02000424 */   addiu     $a0, $zero, 0x2
    /* 65F4 80108DF4 780D040C */  jal        func_801035E0
    /* 65F8 80108DF8 1180103C */   lui       $s0, %hi(D_8010BC68)
    /* 65FC 80108DFC 01004224 */  addiu      $v0, $v0, 0x1
    /* 6600 80108E00 19004010 */  beqz       $v0, .L80108E68
    /* 6604 80108E04 68BC02AE */   sw        $v0, %lo(D_8010BC68)($s0)
    /* 6608 80108E08 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 660C 80108E0C 28000424 */   addiu     $a0, $zero, 0x28
    /* 6610 80108E10 68BC038E */  lw         $v1, %lo(D_8010BC68)($s0)
    /* 6614 80108E14 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 6618 80108E18 14006210 */  beq        $v1, $v0, .L80108E6C
    /* 661C 80108E1C 00000000 */   nop
    /* 6620 80108E20 06006018 */  blez       $v1, .L80108E3C
    /* 6624 80108E24 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 6628 80108E28 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 662C 80108E2C 21106200 */  addu       $v0, $v1, $v0
    /* 6630 80108E30 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 6634 80108E34 00000000 */  nop
    /* 6638 80108E38 68BC02AE */  sw         $v0, %lo(D_8010BC68)($s0)
  .L80108E3C:
    /* 663C 80108E3C 1180033C */  lui        $v1, %hi(D_8010BC6C)
    /* 6640 80108E40 02000224 */  addiu      $v0, $zero, 0x2
    /* 6644 80108E44 9A230408 */  j          .L80108E68
    /* 6648 80108E48 6CBC62A0 */   sb        $v0, %lo(D_8010BC6C)($v1)
  .L80108E4C:
    /* 664C 80108E4C 74EA030C */  jal        vs_mainmenu_ready
    /* 6650 80108E50 00000000 */   nop
    /* 6654 80108E54 04004010 */  beqz       $v0, .L80108E68
    /* 6658 80108E58 1180023C */   lui       $v0, %hi(D_8010BC68)
    /* 665C 80108E5C 68BC428C */  lw         $v0, %lo(D_8010BC68)($v0)
    /* 6660 80108E60 9B230408 */  j          .L80108E6C
    /* 6664 80108E64 00000000 */   nop
  .L80108E68:
    /* 6668 80108E68 21100000 */  addu       $v0, $zero, $zero
  .L80108E6C:
    /* 666C 80108E6C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 6670 80108E70 3800BE8F */  lw         $fp, 0x38($sp)
    /* 6674 80108E74 3400B78F */  lw         $s7, 0x34($sp)
    /* 6678 80108E78 3000B68F */  lw         $s6, 0x30($sp)
    /* 667C 80108E7C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 6680 80108E80 2800B48F */  lw         $s4, 0x28($sp)
    /* 6684 80108E84 2400B38F */  lw         $s3, 0x24($sp)
    /* 6688 80108E88 2000B28F */  lw         $s2, 0x20($sp)
    /* 668C 80108E8C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6690 80108E90 1800B08F */  lw         $s0, 0x18($sp)
    /* 6694 80108E94 0800E003 */  jr         $ra
    /* 6698 80108E98 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80108AD4
