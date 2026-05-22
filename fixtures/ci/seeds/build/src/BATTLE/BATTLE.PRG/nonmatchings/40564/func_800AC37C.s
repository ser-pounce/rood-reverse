nonmatching func_800AC37C, 0xC4

glabel func_800AC37C
    /* 43B7C 800AC37C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 43B80 800AC380 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 43B84 800AC384 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 43B88 800AC388 80200400 */  sll        $a0, $a0, 2
    /* 43B8C 800AC38C 21208200 */  addu       $a0, $a0, $v0
    /* 43B90 800AC390 01000224 */  addiu      $v0, $zero, 0x1
    /* 43B94 800AC394 1000BFAF */  sw         $ra, 0x10($sp)
    /* 43B98 800AC398 0000848C */  lw         $a0, 0x0($a0)
    /* 43B9C 800AC39C 1200A210 */  beq        $a1, $v0, .L800AC3E8
    /* 43BA0 800AC3A0 FFF00324 */   addiu     $v1, $zero, -0xF01
    /* 43BA4 800AC3A4 0200A228 */  slti       $v0, $a1, 0x2
    /* 43BA8 800AC3A8 05004010 */  beqz       $v0, .L800AC3C0
    /* 43BAC 800AC3AC 00000000 */   nop
    /* 43BB0 800AC3B0 0800A010 */  beqz       $a1, .L800AC3D4
    /* 43BB4 800AC3B4 00000000 */   nop
    /* 43BB8 800AC3B8 04B10208 */  j          .L800AC410
    /* 43BBC 800AC3BC 00000000 */   nop
  .L800AC3C0:
    /* 43BC0 800AC3C0 02000224 */  addiu      $v0, $zero, 0x2
    /* 43BC4 800AC3C4 0D00A210 */  beq        $a1, $v0, .L800AC3FC
    /* 43BC8 800AC3C8 FFF00324 */   addiu     $v1, $zero, -0xF01
    /* 43BCC 800AC3CC 04B10208 */  j          .L800AC410
    /* 43BD0 800AC3D0 00000000 */   nop
  .L800AC3D4:
    /* 43BD4 800AC3D4 0800828C */  lw         $v0, 0x8($a0)
    /* 43BD8 800AC3D8 00000000 */  nop
    /* 43BDC 800AC3DC 24104300 */  and        $v0, $v0, $v1
    /* 43BE0 800AC3E0 03B10208 */  j          .L800AC40C
    /* 43BE4 800AC3E4 000E4234 */   ori       $v0, $v0, 0xE00
  .L800AC3E8:
    /* 43BE8 800AC3E8 0800828C */  lw         $v0, 0x8($a0)
    /* 43BEC 800AC3EC 00000000 */  nop
    /* 43BF0 800AC3F0 24104300 */  and        $v0, $v0, $v1
    /* 43BF4 800AC3F4 03B10208 */  j          .L800AC40C
    /* 43BF8 800AC3F8 00064234 */   ori       $v0, $v0, 0x600
  .L800AC3FC:
    /* 43BFC 800AC3FC 0800828C */  lw         $v0, 0x8($a0)
    /* 43C00 800AC400 00000000 */  nop
    /* 43C04 800AC404 24104300 */  and        $v0, $v0, $v1
    /* 43C08 800AC408 00094234 */  ori        $v0, $v0, 0x900
  .L800AC40C:
    /* 43C0C 800AC40C 080082AC */  sw         $v0, 0x8($a0)
  .L800AC410:
    /* 43C10 800AC410 FD178290 */  lbu        $v0, 0x17FD($a0)
    /* 43C14 800AC414 00000000 */  nop
    /* 43C18 800AC418 0200422C */  sltiu      $v0, $v0, 0x2
    /* 43C1C 800AC41C 04004014 */  bnez       $v0, .L800AC430
    /* 43C20 800AC420 00000000 */   nop
    /* 43C24 800AC424 FD178490 */  lbu        $a0, 0x17FD($a0)
    /* 43C28 800AC428 DFB0020C */  jal        func_800AC37C
    /* 43C2C 800AC42C 00000000 */   nop
  .L800AC430:
    /* 43C30 800AC430 1000BF8F */  lw         $ra, 0x10($sp)
    /* 43C34 800AC434 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 43C38 800AC438 0800E003 */  jr         $ra
    /* 43C3C 800AC43C 00000000 */   nop
endlabel func_800AC37C
