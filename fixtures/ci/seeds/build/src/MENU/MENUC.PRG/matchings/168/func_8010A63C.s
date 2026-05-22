nonmatching func_8010A63C, 0x80

glabel func_8010A63C
    /* 7E3C 8010A63C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7E40 8010A640 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7E44 8010A644 0680023C */  lui        $v0, %hi(D_800607A8)
    /* 7E48 8010A648 A8074524 */  addiu      $a1, $v0, %lo(D_800607A8)
    /* 7E4C 8010A64C 02000224 */  addiu      $v0, $zero, 0x2
    /* 7E50 8010A650 11008214 */  bne        $a0, $v0, .L8010A698
    /* 7E54 8010A654 21300000 */   addu      $a2, $zero, $zero
    /* 7E58 8010A658 2120C000 */  addu       $a0, $a2, $zero
  .L8010A65C:
    /* 7E5C 8010A65C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 7E60 8010A660 00000000 */  nop
    /* 7E64 8010A664 05004010 */  beqz       $v0, .L8010A67C
    /* 7E68 8010A668 21180000 */   addu      $v1, $zero, $zero
    /* 7E6C 8010A66C 0300A290 */  lbu        $v0, 0x3($a1)
    /* 7E70 8010A670 00000000 */  nop
    /* 7E74 8010A674 07004238 */  xori       $v0, $v0, 0x7
    /* 7E78 8010A678 2B186200 */  sltu       $v1, $v1, $v0
  .L8010A67C:
    /* 7E7C 8010A67C 2130C300 */  addu       $a2, $a2, $v1
    /* 7E80 8010A680 01008424 */  addiu      $a0, $a0, 0x1
    /* 7E84 8010A684 10008228 */  slti       $v0, $a0, 0x10
    /* 7E88 8010A688 F4FF4014 */  bnez       $v0, .L8010A65C
    /* 7E8C 8010A68C 2800A524 */   addiu     $a1, $a1, 0x28
    /* 7E90 8010A690 AB290408 */  j          .L8010A6AC
    /* 7E94 8010A694 00000000 */   nop
  .L8010A698:
    /* 7E98 8010A698 40200400 */  sll        $a0, $a0, 1
    /* 7E9C 8010A69C 01008434 */  ori        $a0, $a0, 0x1
    /* 7EA0 8010A6A0 9BFA030C */  jal        vs_mainMenu_getItemCount
    /* 7EA4 8010A6A4 21280000 */   addu      $a1, $zero, $zero
    /* 7EA8 8010A6A8 21304000 */  addu       $a2, $v0, $zero
  .L8010A6AC:
    /* 7EAC 8010A6AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7EB0 8010A6B0 2110C000 */  addu       $v0, $a2, $zero
    /* 7EB4 8010A6B4 0800E003 */  jr         $ra
    /* 7EB8 8010A6B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8010A63C
