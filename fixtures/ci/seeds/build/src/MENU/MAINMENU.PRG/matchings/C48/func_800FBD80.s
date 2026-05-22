nonmatching func_800FBD80, 0x124

glabel func_800FBD80
    /* 2580 800FBD80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2584 800FBD84 21488000 */  addu       $t1, $a0, $zero
    /* 2588 800FBD88 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 258C 800FBD8C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 2590 800FBD90 0F002431 */  andi       $a0, $t1, 0xF
    /* 2594 800FBD94 80100400 */  sll        $v0, $a0, 2
    /* 2598 800FBD98 21104300 */  addu       $v0, $v0, $v1
    /* 259C 800FBD9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25A0 800FBDA0 0000428C */  lw         $v0, 0x0($v0)
    /* 25A4 800FBDA4 1080053C */  lui        $a1, %hi(D_80102488)
    /* 25A8 800FBDA8 3C00488C */  lw         $t0, 0x3C($v0)
    /* 25AC 800FBDAC 8824A724 */  addiu      $a3, $a1, %lo(D_80102488)
    /* 25B0 800FBDB0 0600E4A4 */  sh         $a0, 0x6($a3)
    /* 25B4 800FBDB4 68030395 */  lhu        $v1, 0x368($t0)
    /* 25B8 800FBDB8 1080023C */  lui        $v0, %hi(D_80102498)
    /* 25BC 800FBDBC 982443A4 */  sh         $v1, %lo(D_80102498)($v0)
    /* 25C0 800FBDC0 6A030395 */  lhu        $v1, 0x36A($t0)
    /* 25C4 800FBDC4 98244224 */  addiu      $v0, $v0, %lo(D_80102498)
    /* 25C8 800FBDC8 020043A4 */  sh         $v1, 0x2($v0)
    /* 25CC 800FBDCC 6C030395 */  lhu        $v1, 0x36C($t0)
    /* 25D0 800FBDD0 00000000 */  nop
    /* 25D4 800FBDD4 040043A4 */  sh         $v1, 0x4($v0)
    /* 25D8 800FBDD8 22000295 */  lhu        $v0, 0x22($t0)
    /* 25DC 800FBDDC 00000000 */  nop
    /* 25E0 800FBDE0 8824A2A4 */  sh         $v0, %lo(D_80102488)($a1)
    /* 25E4 800FBDE4 26000295 */  lhu        $v0, 0x26($t0)
    /* 25E8 800FBDE8 00000000 */  nop
    /* 25EC 800FBDEC 0200E2A4 */  sh         $v0, 0x2($a3)
    /* 25F0 800FBDF0 2A000295 */  lhu        $v0, 0x2A($t0)
    /* 25F4 800FBDF4 00000000 */  nop
    /* 25F8 800FBDF8 0400E2A4 */  sh         $v0, 0x4($a3)
    /* 25FC 800FBDFC 24000295 */  lhu        $v0, 0x24($t0)
    /* 2600 800FBE00 00000000 */  nop
    /* 2604 800FBE04 0800E2A4 */  sh         $v0, 0x8($a3)
    /* 2608 800FBE08 28000295 */  lhu        $v0, 0x28($t0)
    /* 260C 800FBE0C 00000000 */  nop
    /* 2610 800FBE10 0A00E2A4 */  sh         $v0, 0xA($a3)
    /* 2614 800FBE14 2C000395 */  lhu        $v1, 0x2C($t0)
    /* 2618 800FBE18 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 261C 800FBE1C 452540A0 */  sb         $zero, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 2620 800FBE20 10002229 */  slti       $v0, $t1, 0x10
    /* 2624 800FBE24 1B004010 */  beqz       $v0, .L800FBE94
    /* 2628 800FBE28 0C00E3A4 */   sh        $v1, 0xC($a3)
    /* 262C 800FBE2C 21300000 */  addu       $a2, $zero, $zero
    /* 2630 800FBE30 2128E000 */  addu       $a1, $a3, $zero
    /* 2634 800FBE34 08000424 */  addiu      $a0, $zero, 0x8
  .L800FBE38:
    /* 2638 800FBE38 21188700 */  addu       $v1, $a0, $a3
    /* 263C 800FBE3C 02008424 */  addiu      $a0, $a0, 0x2
    /* 2640 800FBE40 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2644 800FBE44 00006394 */  lhu        $v1, 0x0($v1)
    /* 2648 800FBE48 0100C624 */  addiu      $a2, $a2, 0x1
    /* 264C 800FBE4C 23104300 */  subu       $v0, $v0, $v1
    /* 2650 800FBE50 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 2654 800FBE54 0300C228 */  slti       $v0, $a2, 0x3
    /* 2658 800FBE58 F7FF4014 */  bnez       $v0, .L800FBE38
    /* 265C 800FBE5C 0200A524 */   addiu     $a1, $a1, 0x2
    /* 2660 800FBE60 0100222D */  sltiu      $v0, $t1, 0x1
    /* 2664 800FBE64 24000495 */  lhu        $a0, 0x24($t0)
    /* 2668 800FBE68 5409078D */  lw         $a3, 0x954($t0)
    /* 266C 800FBE6C 28000595 */  lhu        $a1, 0x28($t0)
    /* 2670 800FBE70 2C000695 */  lhu        $a2, 0x2C($t0)
    /* 2674 800FBE74 423C0700 */  srl        $a3, $a3, 17
    /* 2678 800FBE78 0100E730 */  andi       $a3, $a3, 0x1
    /* 267C 800FBE7C 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 2680 800FBE80 2538E200 */   or        $a3, $a3, $v0
    /* 2684 800FBE84 1080043C */  lui        $a0, %hi(D_80102490)
    /* 2688 800FBE88 90248424 */  addiu      $a0, $a0, %lo(D_80102490)
    /* 268C 800FBE8C 0733030C */  jal        vs_battle_rMemzero
    /* 2690 800FBE90 08000524 */   addiu     $a1, $zero, 0x8
  .L800FBE94:
    /* 2694 800FBE94 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2698 800FBE98 00000000 */  nop
    /* 269C 800FBE9C 0800E003 */  jr         $ra
    /* 26A0 800FBEA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FBD80
