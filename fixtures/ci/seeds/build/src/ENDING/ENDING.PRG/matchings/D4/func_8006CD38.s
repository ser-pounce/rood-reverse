nonmatching func_8006CD38, 0x5C

glabel func_8006CD38
    /* 4538 8006CD38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 453C 8006CD3C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4540 8006CD40 0200C104 */  bgez       $a2, .L8006CD4C
    /* 4544 8006CD44 21188000 */   addu      $v1, $a0, $zero
    /* 4548 8006CD48 21300000 */  addu       $a2, $zero, $zero
  .L8006CD4C:
    /* 454C 8006CD4C 4100C228 */  slti       $v0, $a2, 0x41
    /* 4550 8006CD50 02004014 */  bnez       $v0, .L8006CD5C
    /* 4554 8006CD54 00000000 */   nop
    /* 4558 8006CD58 40000624 */  addiu      $a2, $zero, 0x40
  .L8006CD5C:
    /* 455C 8006CD5C 0900C018 */  blez       $a2, .L8006CD84
    /* 4560 8006CD60 0E80073C */   lui       $a3, %hi(D_800DBAA8)
    /* 4564 8006CD64 0E80023C */  lui        $v0, %hi(D_800DB876)
    /* 4568 8006CD68 76B84490 */  lbu        $a0, %lo(D_800DB876)($v0)
    /* 456C 8006CD6C A8BAE724 */  addiu      $a3, $a3, %lo(D_800DBAA8)
    /* 4570 8006CD70 0300E6A0 */  sb         $a2, 0x3($a3)
    /* 4574 8006CD74 0C000624 */  addiu      $a2, $zero, 0xC
    /* 4578 8006CD78 42200400 */  srl        $a0, $a0, 1
    /* 457C 8006CD7C C9B3010C */  jal        func_8006CF24
    /* 4580 8006CD80 23206400 */   subu      $a0, $v1, $a0
  .L8006CD84:
    /* 4584 8006CD84 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4588 8006CD88 00000000 */  nop
    /* 458C 8006CD8C 0800E003 */  jr         $ra
    /* 4590 8006CD90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006CD38
