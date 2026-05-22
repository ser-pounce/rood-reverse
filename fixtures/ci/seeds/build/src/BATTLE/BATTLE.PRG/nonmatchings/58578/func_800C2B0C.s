nonmatching func_800C2B0C, 0x318

glabel func_800C2B0C
    /* 5A30C 800C2B0C B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 5A310 800C2B10 5400A5AF */  sw         $a1, 0x54($sp)
    /* 5A314 800C2B14 0900A22C */  sltiu      $v0, $a1, 0x9
    /* 5A318 800C2B18 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 5A31C 800C2B1C 4800BEAF */  sw         $fp, 0x48($sp)
    /* 5A320 800C2B20 4400B7AF */  sw         $s7, 0x44($sp)
    /* 5A324 800C2B24 4000B6AF */  sw         $s6, 0x40($sp)
    /* 5A328 800C2B28 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 5A32C 800C2B2C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 5A330 800C2B30 3400B3AF */  sw         $s3, 0x34($sp)
    /* 5A334 800C2B34 3000B2AF */  sw         $s2, 0x30($sp)
    /* 5A338 800C2B38 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 5A33C 800C2B3C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 5A340 800C2B40 AC004010 */  beqz       $v0, .L800C2DF4
    /* 5A344 800C2B44 5000A4AF */   sw        $a0, 0x50($sp)
    /* 5A348 800C2B48 5400A78F */  lw         $a3, 0x54($sp)
    /* 5A34C 800C2B4C 21280000 */  addu       $a1, $zero, $zero
    /* 5A350 800C2B50 C0100700 */  sll        $v0, $a3, 3
    /* 5A354 800C2B54 21104700 */  addu       $v0, $v0, $a3
    /* 5A358 800C2B58 0F80073C */  lui        $a3, %hi(D_800EB9B8)
    /* 5A35C 800C2B5C 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5A360 800C2B60 B8B9E28C */  lw         $v0, %lo(D_800EB9B8)($a3)
    /* 5A364 800C2B64 2000A78F */  lw         $a3, 0x20($sp)
    /* 5A368 800C2B68 09000624 */  addiu      $a2, $zero, 0x9
    /* 5A36C 800C2B6C B84AE424 */  addiu      $a0, $a3, 0x4AB8
    /* 5A370 800C2B70 AD9B000C */  jal        memset
    /* 5A374 800C2B74 21204400 */   addu      $a0, $v0, $a0
    /* 5A378 800C2B78 C32D020C */  jal        _getCollisionMapDimensions
    /* 5A37C 800C2B7C 21200000 */   addu      $a0, $zero, $zero
    /* 5A380 800C2B80 21F04000 */  addu       $fp, $v0, $zero
    /* 5A384 800C2B84 FFFFC233 */  andi       $v0, $fp, 0xFFFF
    /* 5A388 800C2B88 03110200 */  sra        $v0, $v0, 4
    /* 5A38C 800C2B8C 033D1E00 */  sra        $a3, $fp, 20
    /* 5A390 800C2B90 21F00000 */  addu       $fp, $zero, $zero
    /* 5A394 800C2B94 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5A398 800C2B98 1800A7AF */  sw         $a3, 0x18($sp)
  .L800C2B9C:
    /* 5A39C 800C2B9C 5000A78F */  lw         $a3, 0x50($sp)
    /* 5A3A0 800C2BA0 FCFFC427 */  addiu      $a0, $fp, -0x4
    /* 5A3A4 800C2BA4 0000E294 */  lhu        $v0, 0x0($a3)
    /* 5A3A8 800C2BA8 0400E394 */  lhu        $v1, 0x4($a3)
    /* 5A3AC 800C2BAC 5400A78F */  lw         $a3, 0x54($sp)
    /* 5A3B0 800C2BB0 00140200 */  sll        $v0, $v0, 16
    /* 5A3B4 800C2BB4 C3150200 */  sra        $v0, $v0, 23
    /* 5A3B8 800C2BB8 21A84400 */  addu       $s5, $v0, $a0
    /* 5A3BC 800C2BBC 001C0300 */  sll        $v1, $v1, 16
    /* 5A3C0 800C2BC0 C31D0300 */  sra        $v1, $v1, 23
    /* 5A3C4 800C2BC4 FCFFE224 */  addiu      $v0, $a3, -0x4
    /* 5A3C8 800C2BC8 1400A78F */  lw         $a3, 0x14($sp)
    /* 5A3CC 800C2BCC 21A06200 */  addu       $s4, $v1, $v0
    /* 5A3D0 800C2BD0 2B10A702 */  sltu       $v0, $s5, $a3
    /* 5A3D4 800C2BD4 1800A78F */  lw         $a3, 0x18($sp)
    /* 5A3D8 800C2BD8 00000000 */  nop
    /* 5A3DC 800C2BDC 2B188702 */  sltu       $v1, $s4, $a3
    /* 5A3E0 800C2BE0 24104300 */  and        $v0, $v0, $v1
    /* 5A3E4 800C2BE4 77004010 */  beqz       $v0, .L800C2DC4
    /* 5A3E8 800C2BE8 0100173C */   lui       $s7, (0x10000 >> 16)
    /* 5A3EC 800C2BEC 2120A002 */  addu       $a0, $s5, $zero
    /* 5A3F0 800C2BF0 21288002 */  addu       $a1, $s4, $zero
    /* 5A3F4 800C2BF4 D92D020C */  jal        func_8008B764
    /* 5A3F8 800C2BF8 21300000 */   addu      $a2, $zero, $zero
    /* 5A3FC 800C2BFC 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5A400 800C2C00 0000438C */  lw         $v1, 0x0($v0)
    /* 5A404 800C2C04 00000000 */  nop
    /* 5A408 800C2C08 82110300 */  srl        $v0, $v1, 6
    /* 5A40C 800C2C0C 01004230 */  andi       $v0, $v0, 0x1
    /* 5A410 800C2C10 07004010 */  beqz       $v0, .L800C2C30
    /* 5A414 800C2C14 0F80073C */   lui       $a3, %hi(D_800EB9B8)
    /* 5A418 800C2C18 B8B9E28C */  lw         $v0, %lo(D_800EB9B8)($a3)
    /* 5A41C 800C2C1C 2000A78F */  lw         $a3, 0x20($sp)
    /* 5A420 800C2C20 80F0173C */  lui        $s7, (0xF0800000 >> 16)
    /* 5A424 800C2C24 21104700 */  addu       $v0, $v0, $a3
    /* 5A428 800C2C28 710B0308 */  j          .L800C2DC4
    /* 5A42C 800C2C2C B84A40A0 */   sb        $zero, 0x4AB8($v0)
  .L800C2C30:
    /* 5A430 800C2C30 82120300 */  srl        $v0, $v1, 10
    /* 5A434 800C2C34 07004230 */  andi       $v0, $v0, 0x7
    /* 5A438 800C2C38 05004228 */  slti       $v0, $v0, 0x5
    /* 5A43C 800C2C3C 05004014 */  bnez       $v0, .L800C2C54
    /* 5A440 800C2C40 2120A002 */   addu      $a0, $s5, $zero
    /* 5A444 800C2C44 C2140300 */  srl        $v0, $v1, 19
    /* 5A448 800C2C48 01004230 */  andi       $v0, $v0, 0x1
    /* 5A44C 800C2C4C 5D004010 */  beqz       $v0, .L800C2DC4
    /* 5A450 800C2C50 00000000 */   nop
  .L800C2C54:
    /* 5A454 800C2C54 21288002 */  addu       $a1, $s4, $zero
    /* 5A458 800C2C58 62E8030C */  jal        func_800FA188
    /* 5A45C 800C2C5C 1000A627 */   addiu     $a2, $sp, 0x10
    /* 5A460 800C2C60 1000A28F */  lw         $v0, 0x10($sp)
    /* 5A464 800C2C64 00000000 */  nop
    /* 5A468 800C2C68 18004010 */  beqz       $v0, .L800C2CCC
    /* 5A46C 800C2C6C 2120A002 */   addu      $a0, $s5, $zero
    /* 5A470 800C2C70 21288002 */  addu       $a1, $s4, $zero
    /* 5A474 800C2C74 77A4020C */  jal        func_800A91DC
    /* 5A478 800C2C78 21300000 */   addu      $a2, $zero, $zero
    /* 5A47C 800C2C7C 80100200 */  sll        $v0, $v0, 2
    /* 5A480 800C2C80 0F80073C */  lui        $a3, %hi(D_800F45E0)
    /* 5A484 800C2C84 E045E724 */  addiu      $a3, $a3, %lo(D_800F45E0)
    /* 5A488 800C2C88 21104700 */  addu       $v0, $v0, $a3
    /* 5A48C 800C2C8C 0000428C */  lw         $v0, 0x0($v0)
    /* 5A490 800C2C90 00000000 */  nop
    /* 5A494 800C2C94 6C014290 */  lbu        $v0, 0x16C($v0)
    /* 5A498 800C2C98 00000000 */  nop
    /* 5A49C 800C2C9C 07004230 */  andi       $v0, $v0, 0x7
    /* 5A4A0 800C2CA0 0200422C */  sltiu      $v0, $v0, 0x2
    /* 5A4A4 800C2CA4 05004010 */  beqz       $v0, .L800C2CBC
    /* 5A4A8 800C2CA8 00000000 */   nop
    /* 5A4AC 800C2CAC 1000A28F */  lw         $v0, 0x10($sp)
    /* 5A4B0 800C2CB0 21B80000 */  addu       $s7, $zero, $zero
    /* 5A4B4 800C2CB4 320B0308 */  j          .L800C2CC8
    /* 5A4B8 800C2CB8 20004224 */   addiu     $v0, $v0, 0x20
  .L800C2CBC:
    /* 5A4BC 800C2CBC 1000A28F */  lw         $v0, 0x10($sp)
    /* 5A4C0 800C2CC0 00000000 */  nop
    /* 5A4C4 800C2CC4 10004224 */  addiu      $v0, $v0, 0x10
  .L800C2CC8:
    /* 5A4C8 800C2CC8 1000A2AF */  sw         $v0, 0x10($sp)
  .L800C2CCC:
    /* 5A4CC 800C2CCC C0A91500 */  sll        $s5, $s5, 7
    /* 5A4D0 800C2CD0 C0A11400 */  sll        $s4, $s4, 7
    /* 5A4D4 800C2CD4 00401224 */  addiu      $s2, $zero, 0x4000
    /* 5A4D8 800C2CD8 00C01324 */  addiu      $s3, $zero, -0x4000
    /* 5A4DC 800C2CDC 21B06002 */  addu       $s6, $s3, $zero
    /* 5A4E0 800C2CE0 21880000 */  addu       $s1, $zero, $zero
  .L800C2CE4:
    /* 5A4E4 800C2CE4 21800000 */  addu       $s0, $zero, $zero
    /* 5A4E8 800C2CE8 2120B002 */  addu       $a0, $s5, $s0
  .L800C2CEC:
    /* 5A4EC 800C2CEC 6A37020C */  jal        func_8008DDA8
    /* 5A4F0 800C2CF0 21289102 */   addu      $a1, $s4, $s1
    /* 5A4F4 800C2CF4 21284000 */  addu       $a1, $v0, $zero
    /* 5A4F8 800C2CF8 40140500 */  sll        $v0, $a1, 17
    /* 5A4FC 800C2CFC 1000A38F */  lw         $v1, 0x10($sp)
    /* 5A500 800C2D00 43240200 */  sra        $a0, $v0, 17
    /* 5A504 800C2D04 21208300 */  addu       $a0, $a0, $v1
    /* 5A508 800C2D08 2A109200 */  slt        $v0, $a0, $s2
    /* 5A50C 800C2D0C 02004010 */  beqz       $v0, .L800C2D18
    /* 5A510 800C2D10 2A106402 */   slt       $v0, $s3, $a0
    /* 5A514 800C2D14 21908000 */  addu       $s2, $a0, $zero
  .L800C2D18:
    /* 5A518 800C2D18 02004010 */  beqz       $v0, .L800C2D24
    /* 5A51C 800C2D1C 40100500 */   sll       $v0, $a1, 1
    /* 5A520 800C2D20 21988000 */  addu       $s3, $a0, $zero
  .L800C2D24:
    /* 5A524 800C2D24 43240200 */  sra        $a0, $v0, 17
    /* 5A528 800C2D28 2A10C402 */  slt        $v0, $s6, $a0
    /* 5A52C 800C2D2C 02004010 */  beqz       $v0, .L800C2D38
    /* 5A530 800C2D30 00000000 */   nop
    /* 5A534 800C2D34 21B08000 */  addu       $s6, $a0, $zero
  .L800C2D38:
    /* 5A538 800C2D38 20001026 */  addiu      $s0, $s0, 0x20
    /* 5A53C 800C2D3C 8000022A */  slti       $v0, $s0, 0x80
    /* 5A540 800C2D40 EAFF4014 */  bnez       $v0, .L800C2CEC
    /* 5A544 800C2D44 2120B002 */   addu      $a0, $s5, $s0
    /* 5A548 800C2D48 20003126 */  addiu      $s1, $s1, 0x20
    /* 5A54C 800C2D4C 8000222A */  slti       $v0, $s1, 0x80
    /* 5A550 800C2D50 E4FF4014 */  bnez       $v0, .L800C2CE4
    /* 5A554 800C2D54 00000000 */   nop
    /* 5A558 800C2D58 0200E012 */  beqz       $s7, .L800C2D64
    /* 5A55C 800C2D5C 26105302 */   xor       $v0, $s2, $s3
    /* 5A560 800C2D60 0100572C */  sltiu      $s7, $v0, 0x1
  .L800C2D64:
    /* 5A564 800C2D64 1C00A78F */  lw         $a3, 0x1C($sp)
    /* 5A568 800C2D68 00000000 */  nop
    /* 5A56C 800C2D6C 0000E28C */  lw         $v0, 0x0($a3)
    /* 5A570 800C2D70 00000000 */  nop
    /* 5A574 800C2D74 82120200 */  srl        $v0, $v0, 10
    /* 5A578 800C2D78 07004430 */  andi       $a0, $v0, 0x7
    /* 5A57C 800C2D7C FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 5A580 800C2D80 0400422C */  sltiu      $v0, $v0, 0x4
    /* 5A584 800C2D84 09004010 */  beqz       $v0, .L800C2DAC
    /* 5A588 800C2D88 0F80073C */   lui       $a3, %hi(D_800EB9B8)
    /* 5A58C 800C2D8C 21906002 */  addu       $s2, $s3, $zero
    /* 5A590 800C2D90 40100400 */  sll        $v0, $a0, 1
    /* 5A594 800C2D94 21104400 */  addu       $v0, $v0, $a0
    /* 5A598 800C2D98 B8B9E38C */  lw         $v1, %lo(D_800EB9B8)($a3)
    /* 5A59C 800C2D9C 2000A78F */  lw         $a3, 0x20($sp)
    /* 5A5A0 800C2DA0 40100200 */  sll        $v0, $v0, 1
    /* 5A5A4 800C2DA4 21186700 */  addu       $v1, $v1, $a3
    /* 5A5A8 800C2DA8 B84A62A0 */  sb         $v0, 0x4AB8($v1)
  .L800C2DAC:
    /* 5A5AC 800C2DAC 3000C326 */  addiu      $v1, $s6, 0x30
    /* 5A5B0 800C2DB0 401C0300 */  sll        $v1, $v1, 17
    /* 5A5B4 800C2DB4 FF7F4232 */  andi       $v0, $s2, 0x7FFF
    /* 5A5B8 800C2DB8 80100200 */  sll        $v0, $v0, 2
    /* 5A5BC 800C2DBC 25186200 */  or         $v1, $v1, $v0
    /* 5A5C0 800C2DC0 25B8E302 */  or         $s7, $s7, $v1
  .L800C2DC4:
    /* 5A5C4 800C2DC4 2000A78F */  lw         $a3, 0x20($sp)
    /* 5A5C8 800C2DC8 00000000 */  nop
    /* 5A5CC 800C2DCC 80100700 */  sll        $v0, $a3, 2
    /* 5A5D0 800C2DD0 0100E724 */  addiu      $a3, $a3, 0x1
    /* 5A5D4 800C2DD4 2000A7AF */  sw         $a3, 0x20($sp)
    /* 5A5D8 800C2DD8 0F80073C */  lui        $a3, %hi(D_800EB9B8)
    /* 5A5DC 800C2DDC B8B9E38C */  lw         $v1, %lo(D_800EB9B8)($a3)
    /* 5A5E0 800C2DE0 0100DE27 */  addiu      $fp, $fp, 0x1
    /* 5A5E4 800C2DE4 21186200 */  addu       $v1, $v1, $v0
    /* 5A5E8 800C2DE8 0900C22B */  slti       $v0, $fp, 0x9
    /* 5A5EC 800C2DEC 6BFF4014 */  bnez       $v0, .L800C2B9C
    /* 5A5F0 800C2DF0 704377AC */   sw        $s7, 0x4370($v1)
  .L800C2DF4:
    /* 5A5F4 800C2DF4 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 5A5F8 800C2DF8 4800BE8F */  lw         $fp, 0x48($sp)
    /* 5A5FC 800C2DFC 4400B78F */  lw         $s7, 0x44($sp)
    /* 5A600 800C2E00 4000B68F */  lw         $s6, 0x40($sp)
    /* 5A604 800C2E04 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 5A608 800C2E08 3800B48F */  lw         $s4, 0x38($sp)
    /* 5A60C 800C2E0C 3400B38F */  lw         $s3, 0x34($sp)
    /* 5A610 800C2E10 3000B28F */  lw         $s2, 0x30($sp)
    /* 5A614 800C2E14 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 5A618 800C2E18 2800B08F */  lw         $s0, 0x28($sp)
    /* 5A61C 800C2E1C 0800E003 */  jr         $ra
    /* 5A620 800C2E20 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_800C2B0C
