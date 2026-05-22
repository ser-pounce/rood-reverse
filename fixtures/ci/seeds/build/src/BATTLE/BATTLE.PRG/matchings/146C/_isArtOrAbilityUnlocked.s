nonmatching _isArtOrAbilityUnlocked, 0xE8

glabel _isArtOrAbilityUnlocked
    /* 6F60 8006F760 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 6F64 8006F764 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 6F68 8006F768 00000000 */  nop
    /* 6F6C 8006F76C 25004490 */  lbu        $a0, 0x25($v0)
    /* 6F70 8006F770 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 6F74 8006F774 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 6F78 8006F778 19008200 */  multu      $a0, $v0
    /* 6F7C 8006F77C 21400000 */  addu       $t0, $zero, $zero
    /* 6F80 8006F780 10480000 */  mfhi       $t1
    /* 6F84 8006F784 C2180900 */  srl        $v1, $t1, 3
    /* 6F88 8006F788 80100300 */  sll        $v0, $v1, 2
    /* 6F8C 8006F78C 21104300 */  addu       $v0, $v0, $v1
    /* 6F90 8006F790 40100200 */  sll        $v0, $v0, 1
    /* 6F94 8006F794 23208200 */  subu       $a0, $a0, $v0
    /* 6F98 8006F798 FF008630 */  andi       $a2, $a0, 0xFF
    /* 6F9C 8006F79C 0680023C */  lui        $v0, %hi(vs_main_artsStatus)
    /* 6FA0 8006F7A0 40004724 */  addiu      $a3, $v0, %lo(vs_main_artsStatus)
    /* 6FA4 8006F7A4 2110C700 */  addu       $v0, $a2, $a3
    /* 6FA8 8006F7A8 00004390 */  lbu        $v1, 0x0($v0)
    /* 6FAC 8006F7AC 00000000 */  nop
    /* 6FB0 8006F7B0 0400622C */  sltiu      $v0, $v1, 0x4
    /* 6FB4 8006F7B4 0E004010 */  beqz       $v0, .L8006F7F0
    /* 6FB8 8006F7B8 21200001 */   addu      $a0, $t0, $zero
    /* 6FBC 8006F7BC 40280600 */  sll        $a1, $a2, 1
    /* 6FC0 8006F7C0 2128A700 */  addu       $a1, $a1, $a3
    /* 6FC4 8006F7C4 0580043C */  lui        $a0, %hi(vs_main_artsPointsRequirements)
    /* 6FC8 8006F7C8 E4FD8424 */  addiu      $a0, $a0, %lo(vs_main_artsPointsRequirements)
    /* 6FCC 8006F7CC 40180300 */  sll        $v1, $v1, 1
    /* 6FD0 8006F7D0 C0100600 */  sll        $v0, $a2, 3
    /* 6FD4 8006F7D4 21186200 */  addu       $v1, $v1, $v0
    /* 6FD8 8006F7D8 21186400 */  addu       $v1, $v1, $a0
    /* 6FDC 8006F7DC 0C00A294 */  lhu        $v0, 0xC($a1)
    /* 6FE0 8006F7E0 00006394 */  lhu        $v1, 0x0($v1)
    /* 6FE4 8006F7E4 00000000 */  nop
    /* 6FE8 8006F7E8 2B104300 */  sltu       $v0, $v0, $v1
    /* 6FEC 8006F7EC 01004438 */  xori       $a0, $v0, 0x1
  .L8006F7F0:
    /* 6FF0 8006F7F0 13008014 */  bnez       $a0, .L8006F840
    /* 6FF4 8006F7F4 00140400 */   sll       $v0, $a0, 16
    /* 6FF8 8006F7F8 2000E294 */  lhu        $v0, 0x20($a3)
    /* 6FFC 8006F7FC 00000000 */  nop
    /* 7000 8006F800 1600422C */  sltiu      $v0, $v0, 0x16
    /* 7004 8006F804 0E004010 */  beqz       $v0, .L8006F840
    /* 7008 8006F808 00140400 */   sll       $v0, $a0, 16
    /* 700C 8006F80C 0580023C */  lui        $v0, %hi(vs_main_battleAbilitiesPointsRequirements)
    /* 7010 8006F810 2000E394 */  lhu        $v1, 0x20($a3)
    /* 7014 8006F814 5CFE4224 */  addiu      $v0, $v0, %lo(vs_main_battleAbilitiesPointsRequirements)
    /* 7018 8006F818 40180300 */  sll        $v1, $v1, 1
    /* 701C 8006F81C 21186200 */  addu       $v1, $v1, $v0
    /* 7020 8006F820 2200E294 */  lhu        $v0, 0x22($a3)
    /* 7024 8006F824 00006394 */  lhu        $v1, 0x0($v1)
    /* 7028 8006F828 00000000 */  nop
    /* 702C 8006F82C 2B104300 */  sltu       $v0, $v0, $v1
    /* 7030 8006F830 02004014 */  bnez       $v0, .L8006F83C
    /* 7034 8006F834 00000000 */   nop
    /* 7038 8006F838 01000824 */  addiu      $t0, $zero, 0x1
  .L8006F83C:
    /* 703C 8006F83C 00140400 */  sll        $v0, $a0, 16
  .L8006F840:
    /* 7040 8006F840 0800E003 */  jr         $ra
    /* 7044 8006F844 25104800 */   or        $v0, $v0, $t0
endlabel _isArtOrAbilityUnlocked
