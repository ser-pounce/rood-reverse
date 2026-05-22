nonmatching func_8010439C, 0x194

glabel func_8010439C
    /* 1B9C 8010439C 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 1BA0 801043A0 6800BEAF */  sw         $fp, 0x68($sp)
    /* 1BA4 801043A4 21F0A003 */  addu       $fp, $sp, $zero
    /* 1BA8 801043A8 6400B7AF */  sw         $s7, 0x64($sp)
    /* 1BAC 801043AC 21B88000 */  addu       $s7, $a0, $zero
    /* 1BB0 801043B0 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 1BB4 801043B4 A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 1BB8 801043B8 2110E202 */  addu       $v0, $s7, $v0
    /* 1BBC 801043BC 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 1BC0 801043C0 21A80000 */  addu       $s5, $zero, $zero
    /* 1BC4 801043C4 1080033C */  lui        $v1, %hi(vs_mainMenu_inventoryIndices)
    /* 1BC8 801043C8 6C00BFAF */  sw         $ra, 0x6C($sp)
    /* 1BCC 801043CC 6000B6AF */  sw         $s6, 0x60($sp)
    /* 1BD0 801043D0 5800B4AF */  sw         $s4, 0x58($sp)
    /* 1BD4 801043D4 5400B3AF */  sw         $s3, 0x54($sp)
    /* 1BD8 801043D8 5000B2AF */  sw         $s2, 0x50($sp)
    /* 1BDC 801043DC 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 1BE0 801043E0 4800B0AF */  sw         $s0, 0x48($sp)
    /* 1BE4 801043E4 7400C5AF */  sw         $a1, 0x74($fp)
    /* 1BE8 801043E8 00005490 */  lbu        $s4, 0x0($v0)
    /* 1BEC 801043EC A8226324 */  addiu      $v1, $v1, %lo(vs_mainMenu_inventoryIndices)
    /* 1BF0 801043F0 07008226 */  addiu      $v0, $s4, 0x7
    /* 1BF4 801043F4 F8014230 */  andi       $v0, $v0, 0x1F8
    /* 1BF8 801043F8 23E8A203 */  subu       $sp, $sp, $v0
    /* 1BFC 801043FC 1000A727 */  addiu      $a3, $sp, 0x10
    /* 1C00 80104400 2120E000 */  addu       $a0, $a3, $zero
    /* 1C04 80104404 80101700 */  sll        $v0, $s7, 2
    /* 1C08 80104408 21104300 */  addu       $v0, $v0, $v1
    /* 1C0C 8010440C 0000568C */  lw         $s6, 0x0($v0)
    /* 1C10 80104410 21288002 */  addu       $a1, $s4, $zero
    /* 1C14 80104414 0733030C */  jal        vs_battle_rMemzero
    /* 1C18 80104418 4000C7AF */   sw        $a3, 0x40($fp)
  .L8010441C:
    /* 1C1C 8010441C 0080133C */  lui        $s3, (0x80000000 >> 16)
  .L80104420:
    /* 1C20 80104420 15008012 */  beqz       $s4, .L80104478
    /* 1C24 80104424 21880000 */   addu      $s1, $zero, $zero
    /* 1C28 80104428 2110D102 */  addu       $v0, $s6, $s1
  .L8010442C:
    /* 1C2C 8010442C 00005090 */  lbu        $s0, 0x0($v0)
    /* 1C30 80104430 00000000 */  nop
    /* 1C34 80104434 0C000012 */  beqz       $s0, .L80104468
    /* 1C38 80104438 1000C427 */   addiu     $a0, $fp, 0x10
    /* 1C3C 8010443C 2128E002 */  addu       $a1, $s7, $zero
    /* 1C40 80104440 B110040C */  jal        func_801042C4
    /* 1C44 80104444 FFFF0626 */   addiu     $a2, $s0, -0x1
    /* 1C48 80104448 7400C48F */  lw         $a0, 0x74($fp)
    /* 1C4C 8010444C 7310040C */  jal        func_801041CC
    /* 1C50 80104450 1000C527 */   addiu     $a1, $fp, 0x10
    /* 1C54 80104454 21184000 */  addu       $v1, $v0, $zero
    /* 1C58 80104458 2A106302 */  slt        $v0, $s3, $v1
    /* 1C5C 8010445C 02004010 */  beqz       $v0, .L80104468
    /* 1C60 80104460 00000000 */   nop
    /* 1C64 80104464 21986000 */  addu       $s3, $v1, $zero
  .L80104468:
    /* 1C68 80104468 01003126 */  addiu      $s1, $s1, 0x1
    /* 1C6C 8010446C 2A103402 */  slt        $v0, $s1, $s4
    /* 1C70 80104470 EEFF4014 */  bnez       $v0, .L8010442C
    /* 1C74 80104474 2110D102 */   addu      $v0, $s6, $s1
  .L80104478:
    /* 1C78 80104478 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 1C7C 8010447C 1C006212 */  beq        $s3, $v0, .L801044F0
    /* 1C80 80104480 2120C002 */   addu      $a0, $s6, $zero
    /* 1C84 80104484 E5FF8012 */  beqz       $s4, .L8010441C
    /* 1C88 80104488 21880000 */   addu      $s1, $zero, $zero
    /* 1C8C 8010448C 2190D102 */  addu       $s2, $s6, $s1
  .L80104490:
    /* 1C90 80104490 00005092 */  lbu        $s0, 0x0($s2)
    /* 1C94 80104494 00000000 */  nop
    /* 1C98 80104498 0F000012 */  beqz       $s0, .L801044D8
    /* 1C9C 8010449C 1000C427 */   addiu     $a0, $fp, 0x10
    /* 1CA0 801044A0 2128E002 */  addu       $a1, $s7, $zero
    /* 1CA4 801044A4 B110040C */  jal        func_801042C4
    /* 1CA8 801044A8 FFFF0626 */   addiu     $a2, $s0, -0x1
    /* 1CAC 801044AC 7400C48F */  lw         $a0, 0x74($fp)
    /* 1CB0 801044B0 7310040C */  jal        func_801041CC
    /* 1CB4 801044B4 1000C527 */   addiu     $a1, $fp, 0x10
    /* 1CB8 801044B8 07005314 */  bne        $v0, $s3, .L801044D8
    /* 1CBC 801044BC 00000000 */   nop
    /* 1CC0 801044C0 4000C78F */  lw         $a3, 0x40($fp)
    /* 1CC4 801044C4 00000000 */  nop
    /* 1CC8 801044C8 2110F500 */  addu       $v0, $a3, $s5
    /* 1CCC 801044CC 0100B526 */  addiu      $s5, $s5, 0x1
    /* 1CD0 801044D0 000050A0 */  sb         $s0, 0x0($v0)
    /* 1CD4 801044D4 000040A2 */  sb         $zero, 0x0($s2)
  .L801044D8:
    /* 1CD8 801044D8 01003126 */  addiu      $s1, $s1, 0x1
    /* 1CDC 801044DC 2A103402 */  slt        $v0, $s1, $s4
    /* 1CE0 801044E0 EBFF4014 */  bnez       $v0, .L80104490
    /* 1CE4 801044E4 2190D102 */   addu      $s2, $s6, $s1
    /* 1CE8 801044E8 08110408 */  j          .L80104420
    /* 1CEC 801044EC 0080133C */   lui       $s3, (0x80000000 >> 16)
  .L801044F0:
    /* 1CF0 801044F0 4000C58F */  lw         $a1, 0x40($fp)
    /* 1CF4 801044F4 7800030C */  jal        vs_battle_memcpy
    /* 1CF8 801044F8 21308002 */   addu      $a2, $s4, $zero
    /* 1CFC 801044FC 21E8C003 */  addu       $sp, $fp, $zero
    /* 1D00 80104500 6C00BF8F */  lw         $ra, 0x6C($sp)
    /* 1D04 80104504 6800BE8F */  lw         $fp, 0x68($sp)
    /* 1D08 80104508 6400B78F */  lw         $s7, 0x64($sp)
    /* 1D0C 8010450C 6000B68F */  lw         $s6, 0x60($sp)
    /* 1D10 80104510 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 1D14 80104514 5800B48F */  lw         $s4, 0x58($sp)
    /* 1D18 80104518 5400B38F */  lw         $s3, 0x54($sp)
    /* 1D1C 8010451C 5000B28F */  lw         $s2, 0x50($sp)
    /* 1D20 80104520 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 1D24 80104524 4800B08F */  lw         $s0, 0x48($sp)
    /* 1D28 80104528 0800E003 */  jr         $ra
    /* 1D2C 8010452C 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel func_8010439C
