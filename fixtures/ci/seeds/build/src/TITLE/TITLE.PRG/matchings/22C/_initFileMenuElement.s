nonmatching _initFileMenuElement, 0x108

glabel _initFileMenuElement
    /* 2670 8006AE70 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2674 8006AE74 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2678 8006AE78 2180A000 */  addu       $s0, $a1, $zero
    /* 267C 8006AE7C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2680 8006AE80 2188C000 */  addu       $s1, $a2, $zero
    /* 2684 8006AE84 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2688 8006AE88 2190E000 */  addu       $s2, $a3, $zero
    /* 268C 8006AE8C 40100400 */  sll        $v0, $a0, 1
    /* 2690 8006AE90 21104400 */  addu       $v0, $v0, $a0
    /* 2694 8006AE94 80100200 */  sll        $v0, $v0, 2
    /* 2698 8006AE98 21104400 */  addu       $v0, $v0, $a0
    /* 269C 8006AE9C 80100200 */  sll        $v0, $v0, 2
    /* 26A0 8006AEA0 0E80033C */  lui        $v1, %hi(_fileMenuElements)
    /* 26A4 8006AEA4 18EB6324 */  addiu      $v1, $v1, %lo(_fileMenuElements)
    /* 26A8 8006AEA8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 26AC 8006AEAC 21984300 */  addu       $s3, $v0, $v1
    /* 26B0 8006AEB0 21206002 */  addu       $a0, $s3, $zero
    /* 26B4 8006AEB4 21280000 */  addu       $a1, $zero, $zero
    /* 26B8 8006AEB8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 26BC 8006AEBC AD9B000C */  jal        memset
    /* 26C0 8006AEC0 34000624 */   addiu     $a2, $zero, 0x34
    /* 26C4 8006AEC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 26C8 8006AEC8 000062A2 */  sb         $v0, 0x0($s3)
    /* 26CC 8006AECC FF000224 */  addiu      $v0, $zero, 0xFF
    /* 26D0 8006AED0 010062A2 */  sb         $v0, 0x1($s3)
    /* 26D4 8006AED4 0C0070AE */  sw         $s0, 0xC($s3)
    /* 26D8 8006AED8 1E004012 */  beqz       $s2, .L8006AF54
    /* 26DC 8006AEDC 100071AE */   sw        $s1, 0x10($s3)
    /* 26E0 8006AEE0 21200000 */  addu       $a0, $zero, $zero
    /* 26E4 8006AEE4 FA000624 */  addiu      $a2, $zero, 0xFA
    /* 26E8 8006AEE8 E7000524 */  addiu      $a1, $zero, 0xE7
  .L8006AEEC:
    /* 26EC 8006AEEC 00004392 */  lbu        $v1, 0x0($s2)
    /* 26F0 8006AEF0 00000000 */  nop
    /* 26F4 8006AEF4 07006614 */  bne        $v1, $a2, .L8006AF14
    /* 26F8 8006AEF8 01005226 */   addiu     $s2, $s2, 0x1
    /* 26FC 8006AEFC 21106402 */  addu       $v0, $s3, $a0
    /* 2700 8006AF00 01008424 */  addiu      $a0, $a0, 0x1
    /* 2704 8006AF04 140043A0 */  sb         $v1, 0x14($v0)
    /* 2708 8006AF08 00004392 */  lbu        $v1, 0x0($s2)
    /* 270C 8006AF0C C9AB0108 */  j          .L8006AF24
    /* 2710 8006AF10 01005226 */   addiu     $s2, $s2, 0x1
  .L8006AF14:
    /* 2714 8006AF14 0B006510 */  beq        $v1, $a1, .L8006AF44
    /* 2718 8006AF18 E500622C */   sltiu     $v0, $v1, 0xE5
    /* 271C 8006AF1C 05004010 */  beqz       $v0, .L8006AF34
    /* 2720 8006AF20 20008228 */   slti      $v0, $a0, 0x20
  .L8006AF24:
    /* 2724 8006AF24 21106402 */  addu       $v0, $s3, $a0
    /* 2728 8006AF28 140043A0 */  sb         $v1, 0x14($v0)
    /* 272C 8006AF2C 01008424 */  addiu      $a0, $a0, 0x1
    /* 2730 8006AF30 20008228 */  slti       $v0, $a0, 0x20
  .L8006AF34:
    /* 2734 8006AF34 EDFF4014 */  bnez       $v0, .L8006AEEC
    /* 2738 8006AF38 00000000 */   nop
    /* 273C 8006AF3C D7AB0108 */  j          .L8006AF5C
    /* 2740 8006AF40 21106002 */   addu      $v0, $s3, $zero
  .L8006AF44:
    /* 2744 8006AF44 21186402 */  addu       $v1, $s3, $a0
    /* 2748 8006AF48 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 274C 8006AF4C D6AB0108 */  j          .L8006AF58
    /* 2750 8006AF50 140062A0 */   sb        $v0, 0x14($v1)
  .L8006AF54:
    /* 2754 8006AF54 140062A2 */  sb         $v0, 0x14($s3)
  .L8006AF58:
    /* 2758 8006AF58 21106002 */  addu       $v0, $s3, $zero
  .L8006AF5C:
    /* 275C 8006AF5C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2760 8006AF60 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2764 8006AF64 1800B28F */  lw         $s2, 0x18($sp)
    /* 2768 8006AF68 1400B18F */  lw         $s1, 0x14($sp)
    /* 276C 8006AF6C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2770 8006AF70 0800E003 */  jr         $ra
    /* 2774 8006AF74 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initFileMenuElement
