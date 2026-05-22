nonmatching SetDefDrawEnv, 0xB4

glabel SetDefDrawEnv
    /* 1BB74 8002B374 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BB78 8002B378 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1BB7C 8002B37C 3800B28F */  lw         $s2, 0x38($sp)
    /* 1BB80 8002B380 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1BB84 8002B384 21888000 */  addu       $s1, $a0, $zero
    /* 1BB88 8002B388 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1BB8C 8002B38C 2198A000 */  addu       $s3, $a1, $zero
    /* 1BB90 8002B390 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1BB94 8002B394 21A0C000 */  addu       $s4, $a2, $zero
    /* 1BB98 8002B398 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1BB9C 8002B39C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1BBA0 8002B3A0 DA80000C */  jal        GetVideoMode
    /* 1BBA4 8002B3A4 2180E000 */   addu      $s0, $a3, $zero
    /* 1BBA8 8002B3A8 01000324 */  addiu      $v1, $zero, 0x1
    /* 1BBAC 8002B3AC 000033A6 */  sh         $s3, 0x0($s1)
    /* 1BBB0 8002B3B0 020034A6 */  sh         $s4, 0x2($s1)
    /* 1BBB4 8002B3B4 040030A6 */  sh         $s0, 0x4($s1)
    /* 1BBB8 8002B3B8 0C0020A6 */  sh         $zero, 0xC($s1)
    /* 1BBBC 8002B3BC 0E0020A6 */  sh         $zero, 0xE($s1)
    /* 1BBC0 8002B3C0 100020A6 */  sh         $zero, 0x10($s1)
    /* 1BBC4 8002B3C4 120020A6 */  sh         $zero, 0x12($s1)
    /* 1BBC8 8002B3C8 190020A2 */  sb         $zero, 0x19($s1)
    /* 1BBCC 8002B3CC 1A0020A2 */  sb         $zero, 0x1A($s1)
    /* 1BBD0 8002B3D0 1B0020A2 */  sb         $zero, 0x1B($s1)
    /* 1BBD4 8002B3D4 160023A2 */  sb         $v1, 0x16($s1)
    /* 1BBD8 8002B3D8 03004010 */  beqz       $v0, .L8002B3E8
    /* 1BBDC 8002B3DC 060032A6 */   sh        $s2, 0x6($s1)
    /* 1BBE0 8002B3E0 FBAC0008 */  j          .L8002B3EC
    /* 1BBE4 8002B3E4 2101422A */   slti      $v0, $s2, 0x121
  .L8002B3E8:
    /* 1BBE8 8002B3E8 0101422A */  slti       $v0, $s2, 0x101
  .L8002B3EC:
    /* 1BBEC 8002B3EC 170022A2 */  sb         $v0, 0x17($s1)
    /* 1BBF0 8002B3F0 21102002 */  addu       $v0, $s1, $zero
    /* 1BBF4 8002B3F4 0A000324 */  addiu      $v1, $zero, 0xA
    /* 1BBF8 8002B3F8 080053A4 */  sh         $s3, 0x8($v0)
    /* 1BBFC 8002B3FC 0A0054A4 */  sh         $s4, 0xA($v0)
    /* 1BC00 8002B400 140043A4 */  sh         $v1, 0x14($v0)
    /* 1BC04 8002B404 180040A0 */  sb         $zero, 0x18($v0)
    /* 1BC08 8002B408 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1BC0C 8002B40C 2000B48F */  lw         $s4, 0x20($sp)
    /* 1BC10 8002B410 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1BC14 8002B414 1800B28F */  lw         $s2, 0x18($sp)
    /* 1BC18 8002B418 1400B18F */  lw         $s1, 0x14($sp)
    /* 1BC1C 8002B41C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BC20 8002B420 0800E003 */  jr         $ra
    /* 1BC24 8002B424 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel SetDefDrawEnv
    /* 1BC28 8002B428 00000000 */  nop
    /* 1BC2C 8002B42C 00000000 */  nop
    /* 1BC30 8002B430 00000000 */  nop
