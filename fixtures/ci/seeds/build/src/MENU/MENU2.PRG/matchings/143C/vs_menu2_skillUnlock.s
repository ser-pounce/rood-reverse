nonmatching vs_menu2_skillUnlock, 0x118

glabel vs_menu2_skillUnlock
    /* 1D78 80104578 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D7C 8010457C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1D80 80104580 21808000 */  addu       $s0, $a0, $zero
    /* 1D84 80104584 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1D88 80104588 00000392 */  lbu        $v1, 0x0($s0)
    /* 1D8C 8010458C 00000000 */  nop
    /* 1D90 80104590 0600622C */  sltiu      $v0, $v1, 0x6
    /* 1D94 80104594 39004010 */  beqz       $v0, .L8010467C
    /* 1D98 80104598 1080023C */   lui       $v0, %hi(jtbl_8010284C)
    /* 1D9C 8010459C 4C284224 */  addiu      $v0, $v0, %lo(jtbl_8010284C)
    /* 1DA0 801045A0 80180300 */  sll        $v1, $v1, 2
    /* 1DA4 801045A4 21186200 */  addu       $v1, $v1, $v0
    /* 1DA8 801045A8 0000628C */  lw         $v0, 0x0($v1)
    /* 1DAC 801045AC 00000000 */  nop
    /* 1DB0 801045B0 08004000 */  jr         $v0
    /* 1DB4 801045B4 00000000 */   nop
    /* 1DB8 801045B8 F2FE030C */  jal        func_800FFBC8
    /* 1DBC 801045BC 00000000 */   nop
    /* 1DC0 801045C0 03000224 */  addiu      $v0, $zero, 0x3
    /* 1DC4 801045C4 000002A2 */  sb         $v0, 0x0($s0)
    /* 1DC8 801045C8 0F80023C */  lui        $v0, %hi(D_800F4E88)
    /* 1DCC 801045CC 884E4290 */  lbu        $v0, %lo(D_800F4E88)($v0)
    /* 1DD0 801045D0 00000000 */  nop
    /* 1DD4 801045D4 2A004010 */  beqz       $v0, .L80104680
    /* 1DD8 801045D8 21100000 */   addu      $v0, $zero, $zero
    /* 1DDC 801045DC 0F0F040C */  jal        _breakArtUnlocked
    /* 1DE0 801045E0 01000424 */   addiu     $a0, $zero, 0x1
    /* 1DE4 801045E4 26004014 */  bnez       $v0, .L80104680
    /* 1DE8 801045E8 21100000 */   addu      $v0, $zero, $zero
    /* 1DEC 801045EC 02000224 */  addiu      $v0, $zero, 0x2
    /* 1DF0 801045F0 9F110408 */  j          .L8010467C
    /* 1DF4 801045F4 000002A2 */   sb        $v0, 0x0($s0)
    /* 1DF8 801045F8 0F0F040C */  jal        _breakArtUnlocked
    /* 1DFC 801045FC 21200000 */   addu      $a0, $zero, $zero
    /* 1E00 80104600 1E004010 */  beqz       $v0, .L8010467C
    /* 1E04 80104604 01000224 */   addiu     $v0, $zero, 0x1
    /* 1E08 80104608 9F110408 */  j          .L8010467C
    /* 1E0C 8010460C 000002A2 */   sb        $v0, 0x0($s0)
    /* 1E10 80104610 05000224 */  addiu      $v0, $zero, 0x5
    /* 1E14 80104614 000002A2 */  sb         $v0, 0x0($s0)
    /* 1E18 80104618 0F80023C */  lui        $v0, %hi(D_800F4FDA)
    /* 1E1C 8010461C DA4F4290 */  lbu        $v0, %lo(D_800F4FDA)($v0)
    /* 1E20 80104620 00000000 */  nop
    /* 1E24 80104624 16004010 */  beqz       $v0, .L80104680
    /* 1E28 80104628 21100000 */   addu      $v0, $zero, $zero
    /* 1E2C 8010462C 880F040C */  jal        _battleAbilityUnlocked
    /* 1E30 80104630 01000424 */   addiu     $a0, $zero, 0x1
    /* 1E34 80104634 12004014 */  bnez       $v0, .L80104680
    /* 1E38 80104638 21100000 */   addu      $v0, $zero, $zero
    /* 1E3C 8010463C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1E40 80104640 9F110408 */  j          .L8010467C
    /* 1E44 80104644 000002A2 */   sb        $v0, 0x0($s0)
    /* 1E48 80104648 880F040C */  jal        _battleAbilityUnlocked
    /* 1E4C 8010464C 21200000 */   addu      $a0, $zero, $zero
    /* 1E50 80104650 0A004010 */  beqz       $v0, .L8010467C
    /* 1E54 80104654 03000224 */   addiu     $v0, $zero, 0x3
    /* 1E58 80104658 9F110408 */  j          .L8010467C
    /* 1E5C 8010465C 000002A2 */   sb        $v0, 0x0($s0)
    /* 1E60 80104660 1934030C */  jal        vs_battle_dismissTextBox
    /* 1E64 80104664 07000424 */   addiu     $a0, $zero, 0x7
    /* 1E68 80104668 05004014 */  bnez       $v0, .L80104680
    /* 1E6C 8010466C 21100000 */   addu      $v0, $zero, $zero
    /* 1E70 80104670 000000A2 */  sb         $zero, 0x0($s0)
    /* 1E74 80104674 A0110408 */  j          .L80104680
    /* 1E78 80104678 01000224 */   addiu     $v0, $zero, 0x1
  .L8010467C:
    /* 1E7C 8010467C 21100000 */  addu       $v0, $zero, $zero
  .L80104680:
    /* 1E80 80104680 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1E84 80104684 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E88 80104688 0800E003 */  jr         $ra
    /* 1E8C 8010468C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_menu2_skillUnlock
