nonmatching func_80106504, 0x120

glabel func_80106504
    /* 3D04 80106504 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3D08 80106508 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3D0C 8010650C 21800000 */  addu       $s0, $zero, $zero
    /* 3D10 80106510 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3D14 80106514 5800133C */  lui        $s3, (0x580000 >> 16)
    /* 3D18 80106518 1180023C */  lui        $v0, %hi(D_80109A08)
    /* 3D1C 8010651C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3D20 80106520 089A5224 */  addiu      $s2, $v0, %lo(D_80109A08)
    /* 3D24 80106524 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D28 80106528 3A001124 */  addiu      $s1, $zero, 0x3A
    /* 3D2C 8010652C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3D30 80106530 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3D34 80106534 2000B4AF */  sw         $s4, 0x20($sp)
  .L80106538:
    /* 3D38 80106538 0000448E */  lw         $a0, 0x0($s2)
    /* 3D3C 8010653C 25283302 */  or         $a1, $s1, $s3
    /* 3D40 80106540 21300000 */  addu       $a2, $zero, $zero
    /* 3D44 80106544 04005226 */  addiu      $s2, $s2, 0x4
    /* 3D48 80106548 80003126 */  addiu      $s1, $s1, 0x80
    /* 3D4C 8010654C 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 3D50 80106550 01001026 */   addiu     $s0, $s0, 0x1
    /* 3D54 80106554 0200022A */  slti       $v0, $s0, 0x2
    /* 3D58 80106558 F7FF4014 */  bnez       $v0, .L80106538
    /* 3D5C 8010655C 1080143C */   lui       $s4, %hi(vs_menu_inventoryStorage)
    /* 3D60 80106560 21800000 */  addu       $s0, $zero, $zero
    /* 3D64 80106564 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 3D68 80106568 A0225524 */  addiu      $s5, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 3D6C 8010656C 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 3D70 80106570 44995324 */  addiu      $s3, $v0, %lo(_containerItemCapacities)
    /* 3D74 80106574 1180023C */  lui        $v0, %hi(D_80109A10)
    /* 3D78 80106578 109A5224 */  addiu      $s2, $v0, %lo(D_80109A10)
    /* 3D7C 8010657C 6400113C */  lui        $s1, (0x6400F8 >> 16)
  .L80106580:
    /* 3D80 80106580 0100023C */  lui        $v0, (0x105B0 >> 16)
    /* 3D84 80106584 B0054234 */  ori        $v0, $v0, (0x105B0 & 0xFFFF)
    /* 3D88 80106588 5C24858E */  lw         $a1, %lo(vs_menu_inventoryStorage)($s4)
    /* 3D8C 8010658C 21200002 */  addu       $a0, $s0, $zero
    /* 3D90 80106590 1C0C040C */  jal        _countContainerItems
    /* 3D94 80106594 2128A200 */   addu      $a1, $a1, $v0
    /* 3D98 80106598 70002536 */  ori        $a1, $s1, (0x640070 & 0xFFFF)
    /* 3D9C 8010659C 21181502 */  addu       $v1, $s0, $s5
    /* 3DA0 801065A0 00006490 */  lbu        $a0, 0x0($v1)
    /* 3DA4 801065A4 1919040C */  jal        func_80106464
    /* 3DA8 801065A8 21304000 */   addu      $a2, $v0, $zero
    /* 3DAC 801065AC A0002536 */  ori        $a1, $s1, (0x6400A0 & 0xFFFF)
    /* 3DB0 801065B0 21300000 */  addu       $a2, $zero, $zero
    /* 3DB4 801065B4 0000448E */  lw         $a0, 0x0($s2)
    /* 3DB8 801065B8 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 3DBC 801065BC 04005226 */   addiu     $s2, $s2, 0x4
    /* 3DC0 801065C0 21200002 */  addu       $a0, $s0, $zero
    /* 3DC4 801065C4 01001026 */  addiu      $s0, $s0, 0x1
    /* 3DC8 801065C8 5C24828E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s4)
    /* 3DCC 801065CC 30C40534 */  ori        $a1, $zero, 0xC430
    /* 3DD0 801065D0 1C0C040C */  jal        _countContainerItems
    /* 3DD4 801065D4 21284500 */   addu      $a1, $v0, $a1
    /* 3DD8 801065D8 F8002536 */  ori        $a1, $s1, (0x6400F8 & 0xFFFF)
    /* 3DDC 801065DC 21304000 */  addu       $a2, $v0, $zero
    /* 3DE0 801065E0 00006496 */  lhu        $a0, 0x0($s3)
    /* 3DE4 801065E4 1919040C */  jal        func_80106464
    /* 3DE8 801065E8 02007326 */   addiu     $s3, $s3, 0x2
    /* 3DEC 801065EC 0C00023C */  lui        $v0, (0xC0000 >> 16)
    /* 3DF0 801065F0 21882202 */  addu       $s1, $s1, $v0
    /* 3DF4 801065F4 0700022A */  slti       $v0, $s0, 0x7
    /* 3DF8 801065F8 E1FF4014 */  bnez       $v0, .L80106580
    /* 3DFC 801065FC 00000000 */   nop
    /* 3E00 80106600 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3E04 80106604 2400B58F */  lw         $s5, 0x24($sp)
    /* 3E08 80106608 2000B48F */  lw         $s4, 0x20($sp)
    /* 3E0C 8010660C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3E10 80106610 1800B28F */  lw         $s2, 0x18($sp)
    /* 3E14 80106614 1400B18F */  lw         $s1, 0x14($sp)
    /* 3E18 80106618 1000B08F */  lw         $s0, 0x10($sp)
    /* 3E1C 8010661C 0800E003 */  jr         $ra
    /* 3E20 80106620 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80106504
