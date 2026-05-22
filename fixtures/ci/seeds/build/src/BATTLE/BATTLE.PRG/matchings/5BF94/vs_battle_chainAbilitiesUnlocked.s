nonmatching vs_battle_chainAbilitiesUnlocked, 0x7C

glabel vs_battle_chainAbilitiesUnlocked
    /* 627B4 800CAFB4 21280000 */  addu       $a1, $zero, $zero
    /* 627B8 800CAFB8 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 627BC 800CAFBC DCB94624 */  addiu      $a2, $v0, %lo(vs_main_skills)
    /* 627C0 800CAFC0 0F80023C */  lui        $v0, %hi(vs_battle_chainAbilityOffsets)
    /* 627C4 800CAFC4 BCBD4824 */  addiu      $t0, $v0, %lo(vs_battle_chainAbilityOffsets)
    /* 627C8 800CAFC8 0F80023C */  lui        $v0, %hi(vs_battle_defenseAbilityOffsets)
    /* 627CC 800CAFCC CCBD4724 */  addiu      $a3, $v0, %lo(vs_battle_defenseAbilityOffsets)
  .L800CAFD0:
    /* 627D0 800CAFD0 02008014 */  bnez       $a0, .L800CAFDC
    /* 627D4 800CAFD4 2110A700 */   addu      $v0, $a1, $a3
    /* 627D8 800CAFD8 2110A800 */  addu       $v0, $a1, $t0
  .L800CAFDC:
    /* 627DC 800CAFDC 00004390 */  lbu        $v1, 0x0($v0)
    /* 627E0 800CAFE0 00000000 */  nop
    /* 627E4 800CAFE4 40100300 */  sll        $v0, $v1, 1
    /* 627E8 800CAFE8 21104300 */  addu       $v0, $v0, $v1
    /* 627EC 800CAFEC 80100200 */  sll        $v0, $v0, 2
    /* 627F0 800CAFF0 21104300 */  addu       $v0, $v0, $v1
    /* 627F4 800CAFF4 80100200 */  sll        $v0, $v0, 2
    /* 627F8 800CAFF8 21104600 */  addu       $v0, $v0, $a2
    /* 627FC 800CAFFC 0C00428C */  lw         $v0, 0xC($v0)
    /* 62800 800CB000 00000000 */  nop
    /* 62804 800CB004 C2130200 */  srl        $v0, $v0, 15
    /* 62808 800CB008 01004230 */  andi       $v0, $v0, 0x1
    /* 6280C 800CB00C 03004010 */  beqz       $v0, .L800CB01C
    /* 62810 800CB010 0100A524 */   addiu     $a1, $a1, 0x1
    /* 62814 800CB014 0800E003 */  jr         $ra
    /* 62818 800CB018 01000224 */   addiu     $v0, $zero, 0x1
  .L800CB01C:
    /* 6281C 800CB01C 0E00A228 */  slti       $v0, $a1, 0xE
    /* 62820 800CB020 EBFF4014 */  bnez       $v0, .L800CAFD0
    /* 62824 800CB024 21100000 */   addu      $v0, $zero, $zero
    /* 62828 800CB028 0800E003 */  jr         $ra
    /* 6282C 800CB02C 00000000 */   nop
endlabel vs_battle_chainAbilitiesUnlocked
