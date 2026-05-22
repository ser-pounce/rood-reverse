nonmatching func_800D6310, 0x78

glabel func_800D6310
    /* 6DB10 800D6310 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6DB14 800D6314 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6DB18 800D6318 2180A000 */  addu       $s0, $a1, $zero
    /* 6DB1C 800D631C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6DB20 800D6320 06000286 */  lh         $v0, 0x6($s0)
    /* 6DB24 800D6324 0000038E */  lw         $v1, 0x0($s0)
    /* 6DB28 800D6328 C0100200 */  sll        $v0, $v0, 3
    /* 6DB2C 800D632C 21386200 */  addu       $a3, $v1, $v0
    /* 6DB30 800D6330 4C0D828C */  lw         $v0, 0xD4C($a0)
    /* 6DB34 800D6334 0000E384 */  lh         $v1, 0x0($a3)
    /* 6DB38 800D6338 02004284 */  lh         $v0, 0x2($v0)
    /* 6DB3C 800D633C 00000000 */  nop
    /* 6DB40 800D6340 0D006214 */  bne        $v1, $v0, .L800D6378
    /* 6DB44 800D6344 01000224 */   addiu     $v0, $zero, 0x1
    /* 6DB48 800D6348 0700E490 */  lbu        $a0, 0x7($a3)
    /* 6DB4C 800D634C 0200E584 */  lh         $a1, 0x2($a3)
    /* 6DB50 800D6350 0400E690 */  lbu        $a2, 0x4($a3)
    /* 6DB54 800D6354 0600E290 */  lbu        $v0, 0x6($a3)
    /* 6DB58 800D6358 0500E790 */  lbu        $a3, 0x5($a3)
    /* 6DB5C 800D635C 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 6DB60 800D6360 80FFC624 */  addiu      $a2, $a2, -0x80
    /* 6DB64 800D6364 80FFE724 */  addiu      $a3, $a3, -0x80
    /* 6DB68 800D6368 D1EC010C */  jal        func_8007B344
    /* 6DB6C 800D636C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 6DB70 800D6370 E055030C */  jal        func_800D5780
    /* 6DB74 800D6374 21200002 */   addu      $a0, $s0, $zero
  .L800D6378:
    /* 6DB78 800D6378 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6DB7C 800D637C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6DB80 800D6380 0800E003 */  jr         $ra
    /* 6DB84 800D6384 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D6310
