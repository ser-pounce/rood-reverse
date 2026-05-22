nonmatching _determineCharacterRank, 0xA4

glabel _determineCharacterRank
    /* 4E00 80107600 21180000 */  addu       $v1, $zero, $zero
    /* 4E04 80107604 21306000 */  addu       $a2, $v1, $zero
    /* 4E08 80107608 01000524 */  addiu      $a1, $zero, 0x1
    /* 4E0C 8010760C 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 4E10 80107610 A0FE448C */  lw         $a0, %lo(vs_main_scoredata)($v0)
    /* 4E14 80107614 04106500 */  sllv       $v0, $a1, $v1
  .L80107618:
    /* 4E18 80107618 24108200 */  and        $v0, $a0, $v0
    /* 4E1C 8010761C 02004010 */  beqz       $v0, .L80107628
    /* 4E20 80107620 00000000 */   nop
    /* 4E24 80107624 0100C624 */  addiu      $a2, $a2, 0x1
  .L80107628:
    /* 4E28 80107628 01006324 */  addiu      $v1, $v1, 0x1
    /* 4E2C 8010762C 10006228 */  slti       $v0, $v1, 0x10
    /* 4E30 80107630 F9FF4014 */  bnez       $v0, .L80107618
    /* 4E34 80107634 04106500 */   sllv      $v0, $a1, $v1
    /* 4E38 80107638 21180000 */  addu       $v1, $zero, $zero
    /* 4E3C 8010763C 1180023C */  lui        $v0, %hi(_score)
    /* 4E40 80107640 60A4478C */  lw         $a3, %lo(_score)($v0)
    /* 4E44 80107644 1180083C */  lui        $t0, %hi(_characterRank)
    /* 4E48 80107648 1180023C */  lui        $v0, %hi(_characterRankPointThresholds)
    /* 4E4C 8010764C C4984524 */  addiu      $a1, $v0, %lo(_characterRankPointThresholds)
    /* 4E50 80107650 1180023C */  lui        $v0, %hi(_characterRankTitleThresholds)
    /* 4E54 80107654 A4984424 */  addiu      $a0, $v0, %lo(_characterRankTitleThresholds)
  .L80107658:
    /* 4E58 80107658 00008284 */  lh         $v0, 0x0($a0)
    /* 4E5C 8010765C 00000000 */  nop
    /* 4E60 80107660 2A10C200 */  slt        $v0, $a2, $v0
    /* 4E64 80107664 08004014 */  bnez       $v0, .L80107688
    /* 4E68 80107668 00000000 */   nop
    /* 4E6C 8010766C 0000A28C */  lw         $v0, 0x0($a1)
    /* 4E70 80107670 00000000 */  nop
    /* 4E74 80107674 2B10E200 */  sltu       $v0, $a3, $v0
    /* 4E78 80107678 04004014 */  bnez       $v0, .L8010768C
    /* 4E7C 8010767C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 4E80 80107680 0800E003 */  jr         $ra
    /* 4E84 80107684 64A403A5 */   sh        $v1, %lo(_characterRank)($t0)
  .L80107688:
    /* 4E88 80107688 0400A524 */  addiu      $a1, $a1, 0x4
  .L8010768C:
    /* 4E8C 8010768C 01006324 */  addiu      $v1, $v1, 0x1
    /* 4E90 80107690 10006228 */  slti       $v0, $v1, 0x10
    /* 4E94 80107694 F0FF4014 */  bnez       $v0, .L80107658
    /* 4E98 80107698 02008424 */   addiu     $a0, $a0, 0x2
    /* 4E9C 8010769C 0800E003 */  jr         $ra
    /* 4EA0 801076A0 00000000 */   nop
endlabel _determineCharacterRank
