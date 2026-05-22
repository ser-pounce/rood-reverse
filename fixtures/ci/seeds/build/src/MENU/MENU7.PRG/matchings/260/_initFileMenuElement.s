nonmatching _initFileMenuElement, 0x108

glabel _initFileMenuElement
    /* 25B8 80104DB8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 25BC 80104DBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 25C0 80104DC0 2180A000 */  addu       $s0, $a1, $zero
    /* 25C4 80104DC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 25C8 80104DC8 2188C000 */  addu       $s1, $a2, $zero
    /* 25CC 80104DCC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 25D0 80104DD0 2190E000 */  addu       $s2, $a3, $zero
    /* 25D4 80104DD4 40100400 */  sll        $v0, $a0, 1
    /* 25D8 80104DD8 21104400 */  addu       $v0, $v0, $a0
    /* 25DC 80104DDC 80100200 */  sll        $v0, $v0, 2
    /* 25E0 80104DE0 21104400 */  addu       $v0, $v0, $a0
    /* 25E4 80104DE4 80100200 */  sll        $v0, $v0, 2
    /* 25E8 80104DE8 1180033C */  lui        $v1, %hi(_fileMenuElements)
    /* 25EC 80104DEC 50AE6324 */  addiu      $v1, $v1, %lo(_fileMenuElements)
    /* 25F0 80104DF0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 25F4 80104DF4 21984300 */  addu       $s3, $v0, $v1
    /* 25F8 80104DF8 21206002 */  addu       $a0, $s3, $zero
    /* 25FC 80104DFC 21280000 */  addu       $a1, $zero, $zero
    /* 2600 80104E00 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2604 80104E04 AD9B000C */  jal        memset
    /* 2608 80104E08 34000624 */   addiu     $a2, $zero, 0x34
    /* 260C 80104E0C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2610 80104E10 000062A2 */  sb         $v0, 0x0($s3)
    /* 2614 80104E14 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2618 80104E18 010062A2 */  sb         $v0, 0x1($s3)
    /* 261C 80104E1C 0C0070AE */  sw         $s0, 0xC($s3)
    /* 2620 80104E20 1E004012 */  beqz       $s2, .L80104E9C
    /* 2624 80104E24 100071AE */   sw        $s1, 0x10($s3)
    /* 2628 80104E28 21200000 */  addu       $a0, $zero, $zero
    /* 262C 80104E2C FA000624 */  addiu      $a2, $zero, 0xFA
    /* 2630 80104E30 E7000524 */  addiu      $a1, $zero, 0xE7
  .L80104E34:
    /* 2634 80104E34 00004392 */  lbu        $v1, 0x0($s2)
    /* 2638 80104E38 00000000 */  nop
    /* 263C 80104E3C 07006614 */  bne        $v1, $a2, .L80104E5C
    /* 2640 80104E40 01005226 */   addiu     $s2, $s2, 0x1
    /* 2644 80104E44 21106402 */  addu       $v0, $s3, $a0
    /* 2648 80104E48 01008424 */  addiu      $a0, $a0, 0x1
    /* 264C 80104E4C 140043A0 */  sb         $v1, 0x14($v0)
    /* 2650 80104E50 00004392 */  lbu        $v1, 0x0($s2)
    /* 2654 80104E54 9B130408 */  j          .L80104E6C
    /* 2658 80104E58 01005226 */   addiu     $s2, $s2, 0x1
  .L80104E5C:
    /* 265C 80104E5C 0B006510 */  beq        $v1, $a1, .L80104E8C
    /* 2660 80104E60 E500622C */   sltiu     $v0, $v1, 0xE5
    /* 2664 80104E64 05004010 */  beqz       $v0, .L80104E7C
    /* 2668 80104E68 20008228 */   slti      $v0, $a0, 0x20
  .L80104E6C:
    /* 266C 80104E6C 21106402 */  addu       $v0, $s3, $a0
    /* 2670 80104E70 140043A0 */  sb         $v1, 0x14($v0)
    /* 2674 80104E74 01008424 */  addiu      $a0, $a0, 0x1
    /* 2678 80104E78 20008228 */  slti       $v0, $a0, 0x20
  .L80104E7C:
    /* 267C 80104E7C EDFF4014 */  bnez       $v0, .L80104E34
    /* 2680 80104E80 00000000 */   nop
    /* 2684 80104E84 A9130408 */  j          .L80104EA4
    /* 2688 80104E88 21106002 */   addu      $v0, $s3, $zero
  .L80104E8C:
    /* 268C 80104E8C 21186402 */  addu       $v1, $s3, $a0
    /* 2690 80104E90 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2694 80104E94 A8130408 */  j          .L80104EA0
    /* 2698 80104E98 140062A0 */   sb        $v0, 0x14($v1)
  .L80104E9C:
    /* 269C 80104E9C 140062A2 */  sb         $v0, 0x14($s3)
  .L80104EA0:
    /* 26A0 80104EA0 21106002 */  addu       $v0, $s3, $zero
  .L80104EA4:
    /* 26A4 80104EA4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 26A8 80104EA8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 26AC 80104EAC 1800B28F */  lw         $s2, 0x18($sp)
    /* 26B0 80104EB0 1400B18F */  lw         $s1, 0x14($sp)
    /* 26B4 80104EB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 26B8 80104EB8 0800E003 */  jr         $ra
    /* 26BC 80104EBC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initFileMenuElement
