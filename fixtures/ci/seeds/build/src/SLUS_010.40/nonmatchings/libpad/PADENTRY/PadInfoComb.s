nonmatching PadInfoComb, 0xA8

glabel PadInfoComb
    /* 1C328 8002BB28 0380023C */  lui        $v0, %hi(D_800335B0)
    /* 1C32C 8002BB2C B035428C */  lw         $v0, %lo(D_800335B0)($v0)
    /* 1C330 8002BB30 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C334 8002BB34 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C338 8002BB38 2180A000 */  addu       $s0, $a1, $zero
    /* 1C33C 8002BB3C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C340 8002BB40 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1C344 8002BB44 09F84000 */  jalr       $v0
    /* 1C348 8002BB48 2188C000 */   addu      $s1, $a2, $zero
    /* 1C34C 8002BB4C 04000106 */  bgez       $s0, .L8002BB60
    /* 1C350 8002BB50 21184000 */   addu      $v1, $v0, $zero
    /* 1C354 8002BB54 EA006290 */  lbu        $v0, 0xEA($v1)
    /* 1C358 8002BB58 EFAE0008 */  j          .L8002BBBC
    /* 1C35C 8002BB5C 00000000 */   nop
  .L8002BB60:
    /* 1C360 8002BB60 EA006290 */  lbu        $v0, 0xEA($v1)
    /* 1C364 8002BB64 00000000 */  nop
    /* 1C368 8002BB68 2A100202 */  slt        $v0, $s0, $v0
    /* 1C36C 8002BB6C 12004010 */  beqz       $v0, .L8002BBB8
    /* 1C370 8002BB70 C0101000 */   sll       $v0, $s0, 3
    /* 1C374 8002BB74 0800638C */  lw         $v1, 0x8($v1)
    /* 1C378 8002BB78 04002106 */  bgez       $s1, .L8002BB8C
    /* 1C37C 8002BB7C 21186200 */   addu      $v1, $v1, $v0
    /* 1C380 8002BB80 00006290 */  lbu        $v0, 0x0($v1)
    /* 1C384 8002BB84 EFAE0008 */  j          .L8002BBBC
    /* 1C388 8002BB88 00000000 */   nop
  .L8002BB8C:
    /* 1C38C 8002BB8C 00006290 */  lbu        $v0, 0x0($v1)
    /* 1C390 8002BB90 00000000 */  nop
    /* 1C394 8002BB94 2A102202 */  slt        $v0, $s1, $v0
    /* 1C398 8002BB98 08004010 */  beqz       $v0, .L8002BBBC
    /* 1C39C 8002BB9C 21100000 */   addu      $v0, $zero, $zero
    /* 1C3A0 8002BBA0 0400628C */  lw         $v0, 0x4($v1)
    /* 1C3A4 8002BBA4 00000000 */  nop
    /* 1C3A8 8002BBA8 21105100 */  addu       $v0, $v0, $s1
    /* 1C3AC 8002BBAC 00004290 */  lbu        $v0, 0x0($v0)
    /* 1C3B0 8002BBB0 EFAE0008 */  j          .L8002BBBC
    /* 1C3B4 8002BBB4 00000000 */   nop
  .L8002BBB8:
    /* 1C3B8 8002BBB8 21100000 */  addu       $v0, $zero, $zero
  .L8002BBBC:
    /* 1C3BC 8002BBBC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1C3C0 8002BBC0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C3C4 8002BBC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C3C8 8002BBC8 0800E003 */  jr         $ra
    /* 1C3CC 8002BBCC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadInfoComb
