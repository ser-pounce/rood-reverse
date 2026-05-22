nonmatching vs_battle_setFarClip, 0x5C

glabel vs_battle_setFarClip
    /* 14514 8007CD14 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14518 8007CD18 801F023C */  lui        $v0, (0x1F800064 >> 16)
    /* 1451C 8007CD1C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14520 8007CD20 0F00A014 */  bnez       $a1, .L8007CD60
    /* 14524 8007CD24 640044AC */   sw        $a0, (0x1F800064 & 0xFFFF)($v0)
    /* 14528 8007CD28 02008104 */  bgez       $a0, .L8007CD34
    /* 1452C 8007CD2C 00000000 */   nop
    /* 14530 8007CD30 07008424 */  addiu      $a0, $a0, 0x7
  .L8007CD34:
    /* 14534 8007CD34 C3200400 */  sra        $a0, $a0, 3
    /* 14538 8007CD38 01088228 */  slti       $v0, $a0, 0x801
    /* 1453C 8007CD3C 03004014 */  bnez       $v0, .L8007CD4C
    /* 14540 8007CD40 00000000 */   nop
    /* 14544 8007CD44 56F30108 */  j          .L8007CD58
    /* 14548 8007CD48 00080424 */   addiu     $a0, $zero, 0x800
  .L8007CD4C:
    /* 1454C 8007CD4C 02008104 */  bgez       $a0, .L8007CD58
    /* 14550 8007CD50 00000000 */   nop
    /* 14554 8007CD54 21200000 */  addu       $a0, $zero, $zero
  .L8007CD58:
    /* 14558 8007CD58 6560020C */  jal        func_80098194
    /* 1455C 8007CD5C 00000000 */   nop
  .L8007CD60:
    /* 14560 8007CD60 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14564 8007CD64 00000000 */  nop
    /* 14568 8007CD68 0800E003 */  jr         $ra
    /* 1456C 8007CD6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_setFarClip
