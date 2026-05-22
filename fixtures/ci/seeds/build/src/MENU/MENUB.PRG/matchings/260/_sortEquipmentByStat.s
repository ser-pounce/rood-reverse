nonmatching _sortEquipmentByStat, 0x194

glabel _sortEquipmentByStat
    /* 1C74 80104474 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 1C78 80104478 6800BEAF */  sw         $fp, 0x68($sp)
    /* 1C7C 8010447C 21F0A003 */  addu       $fp, $sp, $zero
    /* 1C80 80104480 6400B7AF */  sw         $s7, 0x64($sp)
    /* 1C84 80104484 21B88000 */  addu       $s7, $a0, $zero
    /* 1C88 80104488 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 1C8C 8010448C A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 1C90 80104490 2110E202 */  addu       $v0, $s7, $v0
    /* 1C94 80104494 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 1C98 80104498 21A80000 */  addu       $s5, $zero, $zero
    /* 1C9C 8010449C 1080033C */  lui        $v1, %hi(vs_mainMenu_inventoryIndices)
    /* 1CA0 801044A0 6C00BFAF */  sw         $ra, 0x6C($sp)
    /* 1CA4 801044A4 6000B6AF */  sw         $s6, 0x60($sp)
    /* 1CA8 801044A8 5800B4AF */  sw         $s4, 0x58($sp)
    /* 1CAC 801044AC 5400B3AF */  sw         $s3, 0x54($sp)
    /* 1CB0 801044B0 5000B2AF */  sw         $s2, 0x50($sp)
    /* 1CB4 801044B4 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 1CB8 801044B8 4800B0AF */  sw         $s0, 0x48($sp)
    /* 1CBC 801044BC 7400C5AF */  sw         $a1, 0x74($fp)
    /* 1CC0 801044C0 00005490 */  lbu        $s4, 0x0($v0)
    /* 1CC4 801044C4 A8226324 */  addiu      $v1, $v1, %lo(vs_mainMenu_inventoryIndices)
    /* 1CC8 801044C8 07008226 */  addiu      $v0, $s4, 0x7
    /* 1CCC 801044CC F8014230 */  andi       $v0, $v0, 0x1F8
    /* 1CD0 801044D0 23E8A203 */  subu       $sp, $sp, $v0
    /* 1CD4 801044D4 1000A727 */  addiu      $a3, $sp, 0x10
    /* 1CD8 801044D8 2120E000 */  addu       $a0, $a3, $zero
    /* 1CDC 801044DC 80101700 */  sll        $v0, $s7, 2
    /* 1CE0 801044E0 21104300 */  addu       $v0, $v0, $v1
    /* 1CE4 801044E4 0000568C */  lw         $s6, 0x0($v0)
    /* 1CE8 801044E8 21288002 */  addu       $a1, $s4, $zero
    /* 1CEC 801044EC 0733030C */  jal        vs_battle_rMemzero
    /* 1CF0 801044F0 4000C7AF */   sw        $a3, 0x40($fp)
  .L801044F4:
    /* 1CF4 801044F4 0080133C */  lui        $s3, (0x80000000 >> 16)
  .L801044F8:
    /* 1CF8 801044F8 15008012 */  beqz       $s4, .L80104550
    /* 1CFC 801044FC 21880000 */   addu      $s1, $zero, $zero
    /* 1D00 80104500 2110D102 */  addu       $v0, $s6, $s1
  .L80104504:
    /* 1D04 80104504 00005090 */  lbu        $s0, 0x0($v0)
    /* 1D08 80104508 00000000 */  nop
    /* 1D0C 8010450C 0C000012 */  beqz       $s0, .L80104540
    /* 1D10 80104510 1000C427 */   addiu     $a0, $fp, 0x10
    /* 1D14 80104514 2128E002 */  addu       $a1, $s7, $zero
    /* 1D18 80104518 E710040C */  jal        _copyEquipmentStats
    /* 1D1C 8010451C FFFF0626 */   addiu     $a2, $s0, -0x1
    /* 1D20 80104520 7400C48F */  lw         $a0, 0x74($fp)
    /* 1D24 80104524 A910040C */  jal        _getEquipmentStat
    /* 1D28 80104528 1000C527 */   addiu     $a1, $fp, 0x10
    /* 1D2C 8010452C 21184000 */  addu       $v1, $v0, $zero
    /* 1D30 80104530 2A106302 */  slt        $v0, $s3, $v1
    /* 1D34 80104534 02004010 */  beqz       $v0, .L80104540
    /* 1D38 80104538 00000000 */   nop
    /* 1D3C 8010453C 21986000 */  addu       $s3, $v1, $zero
  .L80104540:
    /* 1D40 80104540 01003126 */  addiu      $s1, $s1, 0x1
    /* 1D44 80104544 2A103402 */  slt        $v0, $s1, $s4
    /* 1D48 80104548 EEFF4014 */  bnez       $v0, .L80104504
    /* 1D4C 8010454C 2110D102 */   addu      $v0, $s6, $s1
  .L80104550:
    /* 1D50 80104550 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 1D54 80104554 1C006212 */  beq        $s3, $v0, .L801045C8
    /* 1D58 80104558 2120C002 */   addu      $a0, $s6, $zero
    /* 1D5C 8010455C E5FF8012 */  beqz       $s4, .L801044F4
    /* 1D60 80104560 21880000 */   addu      $s1, $zero, $zero
    /* 1D64 80104564 2190D102 */  addu       $s2, $s6, $s1
  .L80104568:
    /* 1D68 80104568 00005092 */  lbu        $s0, 0x0($s2)
    /* 1D6C 8010456C 00000000 */  nop
    /* 1D70 80104570 0F000012 */  beqz       $s0, .L801045B0
    /* 1D74 80104574 1000C427 */   addiu     $a0, $fp, 0x10
    /* 1D78 80104578 2128E002 */  addu       $a1, $s7, $zero
    /* 1D7C 8010457C E710040C */  jal        _copyEquipmentStats
    /* 1D80 80104580 FFFF0626 */   addiu     $a2, $s0, -0x1
    /* 1D84 80104584 7400C48F */  lw         $a0, 0x74($fp)
    /* 1D88 80104588 A910040C */  jal        _getEquipmentStat
    /* 1D8C 8010458C 1000C527 */   addiu     $a1, $fp, 0x10
    /* 1D90 80104590 07005314 */  bne        $v0, $s3, .L801045B0
    /* 1D94 80104594 00000000 */   nop
    /* 1D98 80104598 4000C78F */  lw         $a3, 0x40($fp)
    /* 1D9C 8010459C 00000000 */  nop
    /* 1DA0 801045A0 2110F500 */  addu       $v0, $a3, $s5
    /* 1DA4 801045A4 0100B526 */  addiu      $s5, $s5, 0x1
    /* 1DA8 801045A8 000050A0 */  sb         $s0, 0x0($v0)
    /* 1DAC 801045AC 000040A2 */  sb         $zero, 0x0($s2)
  .L801045B0:
    /* 1DB0 801045B0 01003126 */  addiu      $s1, $s1, 0x1
    /* 1DB4 801045B4 2A103402 */  slt        $v0, $s1, $s4
    /* 1DB8 801045B8 EBFF4014 */  bnez       $v0, .L80104568
    /* 1DBC 801045BC 2190D102 */   addu      $s2, $s6, $s1
    /* 1DC0 801045C0 3E110408 */  j          .L801044F8
    /* 1DC4 801045C4 0080133C */   lui       $s3, (0x80000000 >> 16)
  .L801045C8:
    /* 1DC8 801045C8 4000C58F */  lw         $a1, 0x40($fp)
    /* 1DCC 801045CC 7800030C */  jal        vs_battle_memcpy
    /* 1DD0 801045D0 21308002 */   addu      $a2, $s4, $zero
    /* 1DD4 801045D4 21E8C003 */  addu       $sp, $fp, $zero
    /* 1DD8 801045D8 6C00BF8F */  lw         $ra, 0x6C($sp)
    /* 1DDC 801045DC 6800BE8F */  lw         $fp, 0x68($sp)
    /* 1DE0 801045E0 6400B78F */  lw         $s7, 0x64($sp)
    /* 1DE4 801045E4 6000B68F */  lw         $s6, 0x60($sp)
    /* 1DE8 801045E8 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 1DEC 801045EC 5800B48F */  lw         $s4, 0x58($sp)
    /* 1DF0 801045F0 5400B38F */  lw         $s3, 0x54($sp)
    /* 1DF4 801045F4 5000B28F */  lw         $s2, 0x50($sp)
    /* 1DF8 801045F8 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 1DFC 801045FC 4800B08F */  lw         $s0, 0x48($sp)
    /* 1E00 80104600 0800E003 */  jr         $ra
    /* 1E04 80104604 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel _sortEquipmentByStat
