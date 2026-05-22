nonmatching func_80104DFC, 0x130

glabel func_80104DFC
    /* 25FC 80104DFC A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 2600 80104E00 5000B2AF */  sw         $s2, 0x50($sp)
    /* 2604 80104E04 21908000 */  addu       $s2, $a0, $zero
    /* 2608 80104E08 2138A000 */  addu       $a3, $a1, $zero
    /* 260C 80104E0C 5800B4AF */  sw         $s4, 0x58($sp)
    /* 2610 80104E10 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* 2614 80104E14 5400B3AF */  sw         $s3, 0x54($sp)
    /* 2618 80104E18 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 261C 80104E1C 4800B0AF */  sw         $s0, 0x48($sp)
    /* 2620 80104E20 2D00E290 */  lbu        $v0, 0x2D($a3)
    /* 2624 80104E24 FFFF5026 */  addiu      $s0, $s2, -0x1
    /* 2628 80104E28 2A100202 */  slt        $v0, $s0, $v0
    /* 262C 80104E2C 1B004010 */  beqz       $v0, .L80104E9C
    /* 2630 80104E30 21A0C000 */   addu      $s4, $a2, $zero
    /* 2634 80104E34 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 2638 80104E38 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 263C 80104E3C 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 2640 80104E40 16684224 */  addiu      $v0, $v0, 0x6816
    /* 2644 80104E44 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2648 80104E48 40101000 */  sll        $v0, $s0, 1
    /* 264C 80104E4C 21105000 */  addu       $v0, $v0, $s0
    /* 2650 80104E50 00290200 */  sll        $a1, $v0, 4
    /* 2654 80104E54 2110E500 */  addu       $v0, $a3, $a1
    /* 2658 80104E58 48004394 */  lhu        $v1, 0x48($v0)
    /* 265C 80104E5C 0058023C */  lui        $v0, (0x58000000 >> 16)
    /* 2660 80104E60 0C006010 */  beqz       $v1, .L80104E94
    /* 2664 80104E64 4000A2AF */   sw        $v0, 0x40($sp)
    /* 2668 80104E68 2000B027 */  addiu      $s0, $sp, 0x20
    /* 266C 80104E6C 21200002 */  addu       $a0, $s0, $zero
    /* 2670 80104E70 4800A524 */  addiu      $a1, $a1, 0x48
    /* 2674 80104E74 CAAD010C */  jal        vs_battle_copyUiGemStats
    /* 2678 80104E78 2128E500 */   addu      $a1, $a3, $a1
    /* 267C 80104E7C 21200002 */  addu       $a0, $s0, $zero
    /* 2680 80104E80 1800A527 */  addiu      $a1, $sp, 0x18
    /* 2684 80104E84 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2688 80104E88 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 268C 80104E8C 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 2690 80104E90 4000A627 */   addiu     $a2, $sp, 0x40
  .L80104E94:
    /* 2694 80104E94 A8130408 */  j          .L80104EA0
    /* 2698 80104E98 97001024 */   addiu     $s0, $zero, 0x97
  .L80104E9C:
    /* 269C 80104E9C 21800000 */  addu       $s0, $zero, $zero
  .L80104EA0:
    /* 26A0 80104EA0 14005126 */  addiu      $s1, $s2, 0x14
    /* 26A4 80104EA4 E4FE030C */  jal        vs_mainMenu_deactivateMenuItem
    /* 26A8 80104EA8 21202002 */   addu      $a0, $s1, $zero
    /* 26AC 80104EAC 17000012 */  beqz       $s0, .L80104F0C
    /* 26B0 80104EB0 21202002 */   addu      $a0, $s1, $zero
    /* 26B4 80104EB4 40011324 */  addiu      $s3, $zero, 0x140
    /* 26B8 80104EB8 23887002 */  subu       $s1, $s3, $s0
    /* 26BC 80104EBC 21282002 */  addu       $a1, $s1, $zero
    /* 26C0 80104EC0 00311200 */  sll        $a2, $s2, 4
    /* 26C4 80104EC4 1200C624 */  addiu      $a2, $a2, 0x12
    /* 26C8 80104EC8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 26CC 80104ECC 1800A28F */  lw         $v0, 0x18($sp)
    /* 26D0 80104ED0 21380002 */  addu       $a3, $s0, $zero
    /* 26D4 80104ED4 9723030C */  jal        vs_battle_setMenuItem
    /* 26D8 80104ED8 1400A2AF */   sw        $v0, 0x14($sp)
    /* 26DC 80104EDC 21204000 */  addu       $a0, $v0, $zero
    /* 26E0 80104EE0 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 26E4 80104EE4 01008232 */  andi       $v0, $s4, 0x1
    /* 26E8 80104EE8 0100632C */  sltiu      $v1, $v1, 0x1
    /* 26EC 80104EEC 05004010 */  beqz       $v0, .L80104F04
    /* 26F0 80104EF0 070083A0 */   sb        $v1, 0x7($a0)
    /* 26F4 80104EF4 02000224 */  addiu      $v0, $zero, 0x2
    /* 26F8 80104EF8 140093A4 */  sh         $s3, 0x14($a0)
    /* 26FC 80104EFC 000082A0 */  sb         $v0, 0x0($a0)
    /* 2700 80104F00 180091A4 */  sh         $s1, 0x18($a0)
  .L80104F04:
    /* 2704 80104F04 16000224 */  addiu      $v0, $zero, 0x16
    /* 2708 80104F08 090082A0 */  sb         $v0, 0x9($a0)
  .L80104F0C:
    /* 270C 80104F0C 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* 2710 80104F10 5800B48F */  lw         $s4, 0x58($sp)
    /* 2714 80104F14 5400B38F */  lw         $s3, 0x54($sp)
    /* 2718 80104F18 5000B28F */  lw         $s2, 0x50($sp)
    /* 271C 80104F1C 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 2720 80104F20 4800B08F */  lw         $s0, 0x48($sp)
    /* 2724 80104F24 0800E003 */  jr         $ra
    /* 2728 80104F28 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel func_80104DFC
