nonmatching _displayInventoryCapacities, 0x360

glabel _displayInventoryCapacities
    /* 5B7C 8010837C 1180033C */  lui        $v1, %hi(D_8010A6B7)
    /* 5B80 80108380 B7A66290 */  lbu        $v0, %lo(D_8010A6B7)($v1)
    /* 5B84 80108384 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5B88 80108388 3000B6AF */  sw         $s6, 0x30($sp)
    /* 5B8C 8010838C 21B00000 */  addu       $s6, $zero, $zero
    /* 5B90 80108390 3800BEAF */  sw         $fp, 0x38($sp)
    /* 5B94 80108394 01001E24 */  addiu      $fp, $zero, 0x1
    /* 5B98 80108398 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 5B9C 8010839C 3400B7AF */  sw         $s7, 0x34($sp)
    /* 5BA0 801083A0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 5BA4 801083A4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 5BA8 801083A8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5BAC 801083AC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5BB0 801083B0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5BB4 801083B4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 5BB8 801083B8 1B004010 */  beqz       $v0, .L80108428
    /* 5BBC 801083BC 4000A4AF */   sw        $a0, 0x40($sp)
    /* 5BC0 801083C0 0F004230 */  andi       $v0, $v0, 0xF
    /* 5BC4 801083C4 18004010 */  beqz       $v0, .L80108428
    /* 5BC8 801083C8 21B0C003 */   addu      $s6, $fp, $zero
    /* 5BCC 801083CC 21880000 */  addu       $s1, $zero, $zero
    /* 5BD0 801083D0 21F02002 */  addu       $fp, $s1, $zero
    /* 5BD4 801083D4 1180023C */  lui        $v0, %hi(D_8010A6B5)
    /* 5BD8 801083D8 1180043C */  lui        $a0, %hi(D_8010A6A0)
    /* 5BDC 801083DC B5A64290 */  lbu        $v0, %lo(D_8010A6B5)($v0)
    /* 5BE0 801083E0 B7A66390 */  lbu        $v1, %lo(D_8010A6B7)($v1)
    /* 5BE4 801083E4 A0A6848C */  lw         $a0, %lo(D_8010A6A0)($a0)
    /* 5BE8 801083E8 21104300 */  addu       $v0, $v0, $v1
    /* 5BEC 801083EC 80100200 */  sll        $v0, $v0, 2
    /* 5BF0 801083F0 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 5BF4 801083F4 1180033C */  lui        $v1, %hi(D_8010A6B6)
    /* 5BF8 801083F8 B6A66390 */  lbu        $v1, %lo(D_8010A6B6)($v1)
    /* 5BFC 801083FC 00000000 */  nop
    /* 5C00 80108400 09006010 */  beqz       $v1, .L80108428
    /* 5C04 80108404 21B08200 */   addu      $s6, $a0, $v0
    /* 5C08 80108408 21286000 */  addu       $a1, $v1, $zero
    /* 5C0C 8010840C 21188000 */  addu       $v1, $a0, $zero
  .L80108410:
    /* 5C10 80108410 03006290 */  lbu        $v0, 0x3($v1)
    /* 5C14 80108414 01003126 */  addiu      $s1, $s1, 0x1
    /* 5C18 80108418 21F0C203 */  addu       $fp, $fp, $v0
    /* 5C1C 8010841C 2A102502 */  slt        $v0, $s1, $a1
    /* 5C20 80108420 FBFF4014 */  bnez       $v0, .L80108410
    /* 5C24 80108424 04006324 */   addiu     $v1, $v1, 0x4
  .L80108428:
    /* 5C28 80108428 1080043C */  lui        $a0, %hi(D_801029A4)
    /* 5C2C 8010842C A4298424 */  addiu      $a0, $a0, %lo(D_801029A4)
    /* 5C30 80108430 0C00053C */  lui        $a1, (0xC0000 >> 16)
    /* 5C34 80108434 4000A88F */  lw         $t0, 0x40($sp)
    /* 5C38 80108438 21300000 */  addu       $a2, $zero, $zero
    /* 5C3C 8010843C B0000225 */  addiu      $v0, $t0, 0xB0
    /* 5C40 80108440 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 5C44 80108444 25284500 */   or        $a1, $v0, $a1
    /* 5C48 80108448 21880000 */  addu       $s1, $zero, $zero
    /* 5C4C 8010844C 1180023C */  lui        $v0, %hi(D_8010A5CC)
    /* 5C50 80108450 CCA55724 */  addiu      $s7, $v0, %lo(D_8010A5CC)
    /* 5C54 80108454 4000A88F */  lw         $t0, 0x40($sp)
    /* 5C58 80108458 1800123C */  lui        $s2, (0x180000 >> 16)
    /* 5C5C 8010845C 10010825 */  addiu      $t0, $t0, 0x110
    /* 5C60 80108460 1000A8AF */  sw         $t0, 0x10($sp)
  .L80108464:
    /* 5C64 80108464 8000103C */  lui        $s0, (0x808080 >> 16)
    /* 5C68 80108468 80801036 */  ori        $s0, $s0, (0x808080 & 0xFFFF)
    /* 5C6C 8010846C 21202002 */  addu       $a0, $s1, $zero
    /* 5C70 80108470 1080083C */  lui        $t0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 5C74 80108474 A0220825 */  addiu      $t0, $t0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 5C78 80108478 21102802 */  addu       $v0, $s1, $t0
    /* 5C7C 8010847C 00005390 */  lbu        $s3, 0x0($v0)
    /* 5C80 80108480 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 5C84 80108484 21280000 */   addu      $a1, $zero, $zero
    /* 5C88 80108488 0D00C012 */  beqz       $s6, .L801084C0
    /* 5C8C 8010848C 21A04000 */   addu      $s4, $v0, $zero
    /* 5C90 80108490 01000224 */  addiu      $v0, $zero, 0x1
    /* 5C94 80108494 0600C212 */  beq        $s6, $v0, .L801084B0
    /* 5C98 80108498 21800000 */   addu      $s0, $zero, $zero
    /* 5C9C 8010849C 21202002 */  addu       $a0, $s1, $zero
    /* 5CA0 801084A0 9920040C */  jal        func_80108264
    /* 5CA4 801084A4 2128C002 */   addu      $a1, $s6, $zero
    /* 5CA8 801084A8 03004010 */  beqz       $v0, .L801084B8
    /* 5CAC 801084AC 4000023C */   lui       $v0, (0x404040 >> 16)
  .L801084B0:
    /* 5CB0 801084B0 01001024 */  addiu      $s0, $zero, 0x1
    /* 5CB4 801084B4 4000023C */  lui        $v0, (0x404040 >> 16)
  .L801084B8:
    /* 5CB8 801084B8 40404234 */  ori        $v0, $v0, (0x404040 & 0xFFFF)
    /* 5CBC 801084BC 04800202 */  sllv       $s0, $v0, $s0
  .L801084C0:
    /* 5CC0 801084C0 1080043C */  lui        $a0, %hi(D_801029B0)
    /* 5CC4 801084C4 B0298424 */  addiu      $a0, $a0, %lo(D_801029B0)
    /* 5CC8 801084C8 21300002 */  addu       $a2, $s0, $zero
    /* 5CCC 801084CC 1000A88F */  lw         $t0, 0x10($sp)
    /* 5CD0 801084D0 21380000 */  addu       $a3, $zero, $zero
    /* 5CD4 801084D4 5019030C */  jal        vs_battle_renderTextRawColor
    /* 5CD8 801084D8 25281201 */   or        $a1, $t0, $s2
    /* 5CDC 801084DC 21300002 */  addu       $a2, $s0, $zero
    /* 5CE0 801084E0 21380000 */  addu       $a3, $zero, $zero
    /* 5CE4 801084E4 4000A88F */  lw         $t0, 0x40($sp)
    /* 5CE8 801084E8 0000E48E */  lw         $a0, 0x0($s7)
    /* 5CEC 801084EC C0000525 */  addiu      $a1, $t0, 0xC0
    /* 5CF0 801084F0 5019030C */  jal        vs_battle_renderTextRawColor
    /* 5CF4 801084F4 2528B200 */   or        $a1, $a1, $s2
    /* 5CF8 801084F8 21206002 */  addu       $a0, $s3, $zero
    /* 5CFC 801084FC 21300002 */  addu       $a2, $s0, $zero
    /* 5D00 80108500 4000A88F */  lw         $t0, 0x40($sp)
    /* 5D04 80108504 21380000 */  addu       $a3, $zero, $zero
    /* 5D08 80108508 28010525 */  addiu      $a1, $t0, 0x128
    /* 5D0C 8010850C 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 5D10 80108510 2528B200 */   or        $a1, $a1, $s2
    /* 5D14 80108514 C2151000 */  srl        $v0, $s0, 23
    /* 5D18 80108518 11004010 */  beqz       $v0, .L80108560
    /* 5D1C 8010851C 21A84002 */   addu      $s5, $s2, $zero
    /* 5D20 80108520 40101400 */  sll        $v0, $s4, 1
    /* 5D24 80108524 2A105300 */  slt        $v0, $v0, $s3
    /* 5D28 80108528 03004010 */  beqz       $v0, .L80108538
    /* 5D2C 8010852C 42101600 */   srl       $v0, $s6, 1
    /* 5D30 80108530 8000103C */  lui        $s0, (0x804020 >> 16)
    /* 5D34 80108534 20401036 */  ori        $s0, $s0, (0x804020 & 0xFFFF)
  .L80108538:
    /* 5D38 80108538 09004010 */  beqz       $v0, .L80108560
    /* 5D3C 8010853C 21202002 */   addu      $a0, $s1, $zero
    /* 5D40 80108540 9920040C */  jal        func_80108264
    /* 5D44 80108544 2128C002 */   addu      $a1, $s6, $zero
    /* 5D48 80108548 21105400 */  addu       $v0, $v0, $s4
    /* 5D4C 8010854C 2A106202 */  slt        $v0, $s3, $v0
    /* 5D50 80108550 04004010 */  beqz       $v0, .L80108564
    /* 5D54 80108554 21208002 */   addu      $a0, $s4, $zero
    /* 5D58 80108558 2000103C */  lui        $s0, (0x204080 >> 16)
    /* 5D5C 8010855C 80401036 */  ori        $s0, $s0, (0x204080 & 0xFFFF)
  .L80108560:
    /* 5D60 80108560 21208002 */  addu       $a0, $s4, $zero
  .L80108564:
    /* 5D64 80108564 1000A88F */  lw         $t0, 0x10($sp)
    /* 5D68 80108568 21300002 */  addu       $a2, $s0, $zero
    /* 5D6C 8010856C 21380000 */  addu       $a3, $zero, $zero
    /* 5D70 80108570 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 5D74 80108574 25281501 */   or        $a1, $t0, $s5
    /* 5D78 80108578 0C00023C */  lui        $v0, (0xC0000 >> 16)
    /* 5D7C 8010857C 21904202 */  addu       $s2, $s2, $v0
    /* 5D80 80108580 01003126 */  addiu      $s1, $s1, 0x1
    /* 5D84 80108584 0700222A */  slti       $v0, $s1, 0x7
    /* 5D88 80108588 B6FF4014 */  bnez       $v0, .L80108464
    /* 5D8C 8010858C 0400F726 */   addiu     $s7, $s7, 0x4
    /* 5D90 80108590 70000524 */  addiu      $a1, $zero, 0x70
    /* 5D94 80108594 2130A000 */  addu       $a2, $a1, $zero
    /* 5D98 80108598 4000A88F */  lw         $t0, 0x40($sp)
    /* 5D9C 8010859C 0A000724 */  addiu      $a3, $zero, 0xA
    /* 5DA0 801085A0 B8001025 */  addiu      $s0, $t0, 0xB8
    /* 5DA4 801085A4 D100040C */  jal        vs_mainMenu_drawButtonUiBackground
    /* 5DA8 801085A8 21200002 */   addu      $a0, $s0, $zero
    /* 5DAC 801085AC 21200002 */  addu       $a0, $s0, $zero
    /* 5DB0 801085B0 80000524 */  addiu      $a1, $zero, 0x80
    /* 5DB4 801085B4 40000624 */  addiu      $a2, $zero, 0x40
    /* 5DB8 801085B8 D100040C */  jal        vs_mainMenu_drawButtonUiBackground
    /* 5DBC 801085BC 0A000724 */   addiu     $a3, $zero, 0xA
    /* 5DC0 801085C0 4000113C */  lui        $s1, (0x404040 >> 16)
    /* 5DC4 801085C4 40403136 */  ori        $s1, $s1, (0x404040 & 0xFFFF)
    /* 5DC8 801085C8 1080043C */  lui        $a0, %hi(D_801029B4)
    /* 5DCC 801085CC B4298424 */  addiu      $a0, $a0, %lo(D_801029B4)
    /* 5DD0 801085D0 7000103C */  lui        $s0, (0x700000 >> 16)
    /* 5DD4 801085D4 1180123C */  lui        $s2, %hi(D_8010A505)
    /* 5DD8 801085D8 21380000 */  addu       $a3, $zero, $zero
    /* 5DDC 801085DC 4000A88F */  lw         $t0, 0x40($sp)
    /* 5DE0 801085E0 05A54692 */  lbu        $a2, %lo(D_8010A505)($s2)
    /* 5DE4 801085E4 C4000525 */  addiu      $a1, $t0, 0xC4
    /* 5DE8 801085E8 2528B000 */  or         $a1, $a1, $s0
    /* 5DEC 801085EC 5019030C */  jal        vs_battle_renderTextRawColor
    /* 5DF0 801085F0 0430D100 */   sllv      $a2, $s1, $a2
    /* 5DF4 801085F4 02000424 */  addiu      $a0, $zero, 0x2
    /* 5DF8 801085F8 6E000624 */  addiu      $a2, $zero, 0x6E
    /* 5DFC 801085FC 4000A88F */  lw         $t0, 0x40($sp)
    /* 5E00 80108600 21380000 */  addu       $a3, $zero, $zero
    /* 5E04 80108604 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 5E08 80108608 B0000525 */   addiu     $a1, $t0, 0xB0
    /* 5E0C 8010860C 1080023C */  lui        $v0, %hi(D_801029B8)
    /* 5E10 80108610 4000A88F */  lw         $t0, 0x40($sp)
    /* 5E14 80108614 B8294424 */  addiu      $a0, $v0, %lo(D_801029B8)
    /* 5E18 80108618 FC000225 */  addiu      $v0, $t0, 0xFC
    /* 5E1C 8010861C 0600C013 */  beqz       $fp, .L80108638
    /* 5E20 80108620 25285000 */   or        $a1, $v0, $s0
    /* 5E24 80108624 05A54292 */  lbu        $v0, %lo(D_8010A505)($s2)
    /* 5E28 80108628 00000000 */  nop
    /* 5E2C 8010862C 01004230 */  andi       $v0, $v0, 0x1
    /* 5E30 80108630 90210408 */  j          .L80108640
    /* 5E34 80108634 04305100 */   sllv      $a2, $s1, $v0
  .L80108638:
    /* 5E38 80108638 4000063C */  lui        $a2, (0x404040 >> 16)
    /* 5E3C 8010863C 4040C634 */  ori        $a2, $a2, (0x404040 & 0xFFFF)
  .L80108640:
    /* 5E40 80108640 5019030C */  jal        vs_battle_renderTextRawColor
    /* 5E44 80108644 21380000 */   addu      $a3, $zero, $zero
    /* 5E48 80108648 01000424 */  addiu      $a0, $zero, 0x1
    /* 5E4C 8010864C 6E000624 */  addiu      $a2, $zero, 0x6E
    /* 5E50 80108650 4000A88F */  lw         $t0, 0x40($sp)
    /* 5E54 80108654 21380000 */  addu       $a3, $zero, $zero
    /* 5E58 80108658 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 5E5C 8010865C E8000525 */   addiu     $a1, $t0, 0xE8
    /* 5E60 80108660 4000033C */  lui        $v1, (0x404040 >> 16)
    /* 5E64 80108664 40406334 */  ori        $v1, $v1, (0x404040 & 0xFFFF)
    /* 5E68 80108668 1080043C */  lui        $a0, %hi(D_801029BC)
    /* 5E6C 8010866C BC298424 */  addiu      $a0, $a0, %lo(D_801029BC)
    /* 5E70 80108670 4000A88F */  lw         $t0, 0x40($sp)
    /* 5E74 80108674 8000053C */  lui        $a1, (0x800000 >> 16)
    /* 5E78 80108678 C4000225 */  addiu      $v0, $t0, 0xC4
    /* 5E7C 8010867C 25284500 */  or         $a1, $v0, $a1
    /* 5E80 80108680 1180023C */  lui        $v0, %hi(D_8010A505)
    /* 5E84 80108684 05A54690 */  lbu        $a2, %lo(D_8010A505)($v0)
    /* 5E88 80108688 21380000 */  addu       $a3, $zero, $zero
    /* 5E8C 8010868C 5019030C */  jal        vs_battle_renderTextRawColor
    /* 5E90 80108690 0430C300 */   sllv      $a2, $v1, $a2
    /* 5E94 80108694 03000424 */  addiu      $a0, $zero, 0x3
    /* 5E98 80108698 7E000624 */  addiu      $a2, $zero, 0x7E
    /* 5E9C 8010869C 4000A88F */  lw         $t0, 0x40($sp)
    /* 5EA0 801086A0 21380000 */  addu       $a3, $zero, $zero
    /* 5EA4 801086A4 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 5EA8 801086A8 B0000525 */   addiu     $a1, $t0, 0xB0
    /* 5EAC 801086AC 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 5EB0 801086B0 3800BE8F */  lw         $fp, 0x38($sp)
    /* 5EB4 801086B4 3400B78F */  lw         $s7, 0x34($sp)
    /* 5EB8 801086B8 3000B68F */  lw         $s6, 0x30($sp)
    /* 5EBC 801086BC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 5EC0 801086C0 2800B48F */  lw         $s4, 0x28($sp)
    /* 5EC4 801086C4 2400B38F */  lw         $s3, 0x24($sp)
    /* 5EC8 801086C8 2000B28F */  lw         $s2, 0x20($sp)
    /* 5ECC 801086CC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5ED0 801086D0 1800B08F */  lw         $s0, 0x18($sp)
    /* 5ED4 801086D4 0800E003 */  jr         $ra
    /* 5ED8 801086D8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _displayInventoryCapacities
