nonmatching DsControlB, 0x68

glabel DsControlB
    /* 163E4 80025BE4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 163E8 80025BE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 163EC 80025BEC 2188C000 */  addu       $s1, $a2, $zero
    /* 163F0 80025BF0 FF008430 */  andi       $a0, $a0, 0xFF
    /* 163F4 80025BF4 21300000 */  addu       $a2, $zero, $zero
    /* 163F8 80025BF8 21380000 */  addu       $a3, $zero, $zero
    /* 163FC 80025BFC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 16400 80025C00 CD8E000C */  jal        DsCommand
    /* 16404 80025C04 1000B0AF */   sw        $s0, 0x10($sp)
    /* 16408 80025C08 21804000 */  addu       $s0, $v0, $zero
    /* 1640C 80025C0C 03000016 */  bnez       $s0, .L80025C1C
    /* 16410 80025C10 21200002 */   addu      $a0, $s0, $zero
    /* 16414 80025C14 0E970008 */  j          .L80025C38
    /* 16418 80025C18 21100000 */   addu      $v0, $zero, $zero
  .L80025C1C:
    /* 1641C 80025C1C 4790000C */  jal        DsSync
    /* 16420 80025C20 21282002 */   addu      $a1, $s1, $zero
    /* 16424 80025C24 FF004230 */  andi       $v0, $v0, 0xFF
    /* 16428 80025C28 FCFF4010 */  beqz       $v0, .L80025C1C
    /* 1642C 80025C2C 21200002 */   addu      $a0, $s0, $zero
    /* 16430 80025C30 02004238 */  xori       $v0, $v0, 0x2
    /* 16434 80025C34 0100422C */  sltiu      $v0, $v0, 0x1
  .L80025C38:
    /* 16438 80025C38 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1643C 80025C3C 1400B18F */  lw         $s1, 0x14($sp)
    /* 16440 80025C40 1000B08F */  lw         $s0, 0x10($sp)
    /* 16444 80025C44 0800E003 */  jr         $ra
    /* 16448 80025C48 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DsControlB
    /* 1644C 80025C4C 00000000 */  nop
    /* 16450 80025C50 00000000 */  nop
