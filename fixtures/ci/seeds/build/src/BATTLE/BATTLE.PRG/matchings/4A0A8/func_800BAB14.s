nonmatching func_800BAB14, 0xB8

glabel func_800BAB14
    /* 52314 800BAB14 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52318 800BAB18 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5231C 800BAB1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52320 800BAB20 01008590 */  lbu        $a1, 0x1($a0)
    /* 52324 800BAB24 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 52328 800BAB28 2120A000 */  addu       $a0, $a1, $zero
    /* 5232C 800BAB2C 06008214 */  bne        $a0, $v0, .L800BAB48
    /* 52330 800BAB30 0800A230 */   andi      $v0, $a1, 0x8
    /* 52334 800BAB34 21200000 */  addu       $a0, $zero, $zero
    /* 52338 800BAB38 290D010C */  jal        func_800434A4
    /* 5233C 800BAB3C 02000524 */   addiu     $a1, $zero, 0x2
    /* 52340 800BAB40 EEEA0208 */  j          .L800BABB8
    /* 52344 800BAB44 00000000 */   nop
  .L800BAB48:
    /* 52348 800BAB48 0F004010 */  beqz       $v0, .L800BAB88
    /* 5234C 800BAB4C 0F80103C */   lui       $s0, %hi(D_800F4C48)
    /* 52350 800BAB50 0F80033C */  lui        $v1, %hi(D_800F4BC0)
    /* 52354 800BAB54 C04B6324 */  addiu      $v1, $v1, %lo(D_800F4BC0)
    /* 52358 800BAB58 0700A230 */  andi       $v0, $a1, 0x7
    /* 5235C 800BAB5C 80100200 */  sll        $v0, $v0, 2
    /* 52360 800BAB60 21104300 */  addu       $v0, $v0, $v1
    /* 52364 800BAB64 484C048E */  lw         $a0, %lo(D_800F4C48)($s0)
    /* 52368 800BAB68 0000458C */  lw         $a1, 0x0($v0)
    /* 5236C 800BAB6C 2C24010C */  jal        vs_main_memcpy
    /* 52370 800BAB70 80000624 */   addiu     $a2, $zero, 0x80
    /* 52374 800BAB74 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 52378 800BAB78 484C048E */  lw         $a0, %lo(D_800F4C48)($s0)
    /* 5237C 800BAB7C 02000624 */  addiu      $a2, $zero, 0x2
    /* 52380 800BAB80 ECEA0208 */  j          .L800BABB0
    /* 52384 800BAB84 08008424 */   addiu     $a0, $a0, 0x8
  .L800BAB88:
    /* 52388 800BAB88 0F80033C */  lui        $v1, %hi(D_800F4BC0)
    /* 5238C 800BAB8C C04B6324 */  addiu      $v1, $v1, %lo(D_800F4BC0)
    /* 52390 800BAB90 80100400 */  sll        $v0, $a0, 2
    /* 52394 800BAB94 21104300 */  addu       $v0, $v0, $v1
    /* 52398 800BAB98 0000428C */  lw         $v0, 0x0($v0)
    /* 5239C 800BAB9C 00000000 */  nop
    /* 523A0 800BABA0 05004010 */  beqz       $v0, .L800BABB8
    /* 523A4 800BABA4 08004424 */   addiu     $a0, $v0, 0x8
    /* 523A8 800BABA8 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 523AC 800BABAC 02000624 */  addiu      $a2, $zero, 0x2
  .L800BABB0:
    /* 523B0 800BABB0 ED0C010C */  jal        func_800433B4
    /* 523B4 800BABB4 00000000 */   nop
  .L800BABB8:
    /* 523B8 800BABB8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 523BC 800BABBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 523C0 800BABC0 21100000 */  addu       $v0, $zero, $zero
    /* 523C4 800BABC4 0800E003 */  jr         $ra
    /* 523C8 800BABC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAB14
