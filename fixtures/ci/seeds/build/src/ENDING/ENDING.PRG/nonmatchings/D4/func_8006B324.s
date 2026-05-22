nonmatching func_8006B324, 0x12C

glabel func_8006B324
    /* 2B24 8006B324 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B28 8006B328 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2B2C 8006B32C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B30 8006B330 0000E390 */  lbu        $v1, 0x0($a3)
    /* 2B34 8006B334 801F083C */  lui        $t0, (0x1F800000 >> 16)
    /* 2B38 8006B338 0000088D */  lw         $t0, (0x1F800000 & 0xFFFF)($t0)
    /* 2B3C 8006B33C 3A006010 */  beqz       $v1, .L8006B428
    /* 2B40 8006B340 21508000 */   addu      $t2, $a0, $zero
    /* 2B44 8006B344 3C000E24 */  addiu      $t6, $zero, 0x3C
    /* 2B48 8006B348 2000C224 */  addiu      $v0, $a2, 0x20
    /* 2B4C 8006B34C 80110200 */  sll        $v0, $v0, 6
    /* 2B50 8006B350 25684E00 */  or         $t5, $v0, $t6
    /* 2B54 8006B354 801F0C3C */  lui        $t4, (0x1F800004 >> 16)
    /* 2B58 8006B358 FF00093C */  lui        $t1, (0xFFFFFF >> 16)
    /* 2B5C 8006B35C FFFF2935 */  ori        $t1, $t1, (0xFFFFFF & 0xFFFF)
    /* 2B60 8006B360 00FF0B3C */  lui        $t3, (0xFF000000 >> 16)
    /* 2B64 8006B364 0E000625 */  addiu      $a2, $t0, 0xE
  .L8006B368:
    /* 2B68 8006B368 E0FF6224 */  addiu      $v0, $v1, -0x20
    /* 2B6C 8006B36C 21184000 */  addu       $v1, $v0, $zero
    /* 2B70 8006B370 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2B74 8006B374 6000422C */  sltiu      $v0, $v0, 0x60
    /* 2B78 8006B378 26004010 */  beqz       $v0, .L8006B414
    /* 2B7C 8006B37C FF006230 */   andi      $v0, $v1, 0xFF
    /* 2B80 8006B380 24004010 */  beqz       $v0, .L8006B414
    /* 2B84 8006B384 00000000 */   nop
    /* 2B88 8006B388 04004E14 */  bne        $v0, $t6, .L8006B39C
    /* 2B8C 8006B38C 4100422C */   sltiu     $v0, $v0, 0x41
    /* 2B90 8006B390 0F000324 */  addiu      $v1, $zero, 0xF
    /* 2B94 8006B394 FF006230 */  andi       $v0, $v1, 0xFF
    /* 2B98 8006B398 4100422C */  sltiu      $v0, $v0, 0x41
  .L8006B39C:
    /* 2B9C 8006B39C 02004014 */  bnez       $v0, .L8006B3A8
    /* 2BA0 8006B3A0 03000224 */   addiu     $v0, $zero, 0x3
    /* 2BA4 8006B3A4 E0FF6324 */  addiu      $v1, $v1, -0x20
  .L8006B3A8:
    /* 2BA8 8006B3A8 F5FFC2A0 */  sb         $v0, -0xB($a2)
    /* 2BAC 8006B3AC 75000224 */  addiu      $v0, $zero, 0x75
    /* 2BB0 8006B3B0 F9FFC2A0 */  sb         $v0, -0x7($a2)
    /* 2BB4 8006B3B4 0F006230 */  andi       $v0, $v1, 0xF
    /* 2BB8 8006B3B8 C0100200 */  sll        $v0, $v0, 3
    /* 2BBC 8006B3BC FEFFC2A0 */  sb         $v0, -0x2($a2)
    /* 2BC0 8006B3C0 F0006230 */  andi       $v0, $v1, 0xF0
    /* 2BC4 8006B3C4 42100200 */  srl        $v0, $v0, 1
    /* 2BC8 8006B3C8 FAFFCAA4 */  sh         $t2, -0x6($a2)
    /* 2BCC 8006B3CC FCFFC5A4 */  sh         $a1, -0x4($a2)
    /* 2BD0 8006B3D0 FFFFC2A0 */  sb         $v0, -0x1($a2)
    /* 2BD4 8006B3D4 0000CDA4 */  sh         $t5, 0x0($a2)
    /* 2BD8 8006B3D8 1000C624 */  addiu      $a2, $a2, 0x10
    /* 2BDC 8006B3DC 0400828D */  lw         $v0, (0x1F800004 & 0xFFFF)($t4)
    /* 2BE0 8006B3E0 0000038D */  lw         $v1, 0x0($t0)
    /* 2BE4 8006B3E4 0000428C */  lw         $v0, 0x0($v0)
    /* 2BE8 8006B3E8 24186B00 */  and        $v1, $v1, $t3
    /* 2BEC 8006B3EC 24104900 */  and        $v0, $v0, $t1
    /* 2BF0 8006B3F0 25186200 */  or         $v1, $v1, $v0
    /* 2BF4 8006B3F4 000003AD */  sw         $v1, 0x0($t0)
    /* 2BF8 8006B3F8 0400838D */  lw         $v1, (0x1F800004 & 0xFFFF)($t4)
    /* 2BFC 8006B3FC 24200901 */  and        $a0, $t0, $t1
    /* 2C00 8006B400 0000628C */  lw         $v0, 0x0($v1)
    /* 2C04 8006B404 10000825 */  addiu      $t0, $t0, 0x10
    /* 2C08 8006B408 24104B00 */  and        $v0, $v0, $t3
    /* 2C0C 8006B40C 25104400 */  or         $v0, $v0, $a0
    /* 2C10 8006B410 000062AC */  sw         $v0, 0x0($v1)
  .L8006B414:
    /* 2C14 8006B414 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2C18 8006B418 0000E390 */  lbu        $v1, 0x0($a3)
    /* 2C1C 8006B41C 00000000 */  nop
    /* 2C20 8006B420 D1FF6014 */  bnez       $v1, .L8006B368
    /* 2C24 8006B424 07004A25 */   addiu     $t2, $t2, 0x7
  .L8006B428:
    /* 2C28 8006B428 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 2C2C 8006B42C 0F000424 */  addiu      $a0, $zero, 0xF
    /* 2C30 8006B430 21280000 */  addu       $a1, $zero, $zero
    /* 2C34 8006B434 56AA010C */  jal        _insertTpage
    /* 2C38 8006B438 000008AE */   sw        $t0, (0x1F800000 & 0xFFFF)($s0)
    /* 2C3C 8006B43C 000002AE */  sw         $v0, (0x1F800000 & 0xFFFF)($s0)
    /* 2C40 8006B440 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2C44 8006B444 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C48 8006B448 0800E003 */  jr         $ra
    /* 2C4C 8006B44C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B324
