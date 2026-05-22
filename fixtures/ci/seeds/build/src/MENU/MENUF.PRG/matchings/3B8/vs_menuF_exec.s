nonmatching vs_menuF_exec, 0x9C

glabel vs_menuF_exec
    /* 3B8 80102BB8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3BC 80102BBC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C0 80102BC0 21888000 */  addu       $s1, $a0, $zero
    /* 3C4 80102BC4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3C8 80102BC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3CC 80102BCC 00002392 */  lbu        $v1, 0x0($s1)
    /* 3D0 80102BD0 01000424 */  addiu      $a0, $zero, 0x1
    /* 3D4 80102BD4 0C006410 */  beq        $v1, $a0, .L80102C08
    /* 3D8 80102BD8 02006228 */   slti      $v0, $v1, 0x2
    /* 3DC 80102BDC 05004010 */  beqz       $v0, .L80102BF4
    /* 3E0 80102BE0 02000224 */   addiu     $v0, $zero, 0x2
    /* 3E4 80102BE4 07006010 */  beqz       $v1, .L80102C04
    /* 3E8 80102BE8 21100000 */   addu      $v0, $zero, $zero
    /* 3EC 80102BEC 100B0408 */  j          .L80102C40
    /* 3F0 80102BF0 00000000 */   nop
  .L80102BF4:
    /* 3F4 80102BF4 0B006210 */  beq        $v1, $v0, .L80102C24
    /* 3F8 80102BF8 21100000 */   addu      $v0, $zero, $zero
    /* 3FC 80102BFC 100B0408 */  j          .L80102C40
    /* 400 80102C00 00000000 */   nop
  .L80102C04:
    /* 404 80102C04 000024A2 */  sb         $a0, 0x0($s1)
  .L80102C08:
    /* 408 80102C08 00003092 */  lbu        $s0, 0x0($s1)
    /* 40C 80102C0C 150B040C */  jal        func_80102C54
    /* 410 80102C10 00000000 */   nop
    /* 414 80102C14 2B100200 */  sltu       $v0, $zero, $v0
    /* 418 80102C18 21800202 */  addu       $s0, $s0, $v0
    /* 41C 80102C1C 0F0B0408 */  j          .L80102C3C
    /* 420 80102C20 000030A2 */   sb        $s0, 0x0($s1)
  .L80102C24:
    /* 424 80102C24 E80D040C */  jal        func_801037A0
    /* 428 80102C28 00000000 */   nop
    /* 42C 80102C2C 03004010 */  beqz       $v0, .L80102C3C
    /* 430 80102C30 01000224 */   addiu     $v0, $zero, 0x1
    /* 434 80102C34 100B0408 */  j          .L80102C40
    /* 438 80102C38 000020A2 */   sb        $zero, 0x0($s1)
  .L80102C3C:
    /* 43C 80102C3C 21100000 */  addu       $v0, $zero, $zero
  .L80102C40:
    /* 440 80102C40 1800BF8F */  lw         $ra, 0x18($sp)
    /* 444 80102C44 1400B18F */  lw         $s1, 0x14($sp)
    /* 448 80102C48 1000B08F */  lw         $s0, 0x10($sp)
    /* 44C 80102C4C 0800E003 */  jr         $ra
    /* 450 80102C50 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_menuF_exec
