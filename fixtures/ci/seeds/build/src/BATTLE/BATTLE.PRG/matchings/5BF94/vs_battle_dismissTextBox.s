nonmatching vs_battle_dismissTextBox, 0x98

glabel vs_battle_dismissTextBox
    /* 64864 800CD064 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64868 800CD068 40100400 */  sll        $v0, $a0, 1
    /* 6486C 800CD06C 21104400 */  addu       $v0, $v0, $a0
    /* 64870 800CD070 00110200 */  sll        $v0, $v0, 4
    /* 64874 800CD074 0F80033C */  lui        $v1, %hi(vs_battle_textBoxes)
    /* 64878 800CD078 E04F6324 */  addiu      $v1, $v1, %lo(vs_battle_textBoxes)
    /* 6487C 800CD07C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 64880 800CD080 21804300 */  addu       $s0, $v0, $v1
    /* 64884 800CD084 1400BFAF */  sw         $ra, 0x14($sp)
    /* 64888 800CD088 03000292 */  lbu        $v0, 0x3($s0)
    /* 6488C 800CD08C 00000000 */  nop
    /* 64890 800CD090 3F004430 */  andi       $a0, $v0, 0x3F
    /* 64894 800CD094 20004230 */  andi       $v0, $v0, 0x20
    /* 64898 800CD098 04004014 */  bnez       $v0, .L800CD0AC
    /* 6489C 800CD09C 21280000 */   addu      $a1, $zero, $zero
    /* 648A0 800CD0A0 2130A000 */  addu       $a2, $a1, $zero
    /* 648A4 800CD0A4 53AB020C */  jal        func_800AAD4C
    /* 648A8 800CD0A8 2138A000 */   addu      $a3, $a1, $zero
  .L800CD0AC:
    /* 648AC 800CD0AC 1C000286 */  lh         $v0, 0x1C($s0)
    /* 648B0 800CD0B0 00000000 */  nop
    /* 648B4 800CD0B4 0C004010 */  beqz       $v0, .L800CD0E8
    /* 648B8 800CD0B8 00000000 */   nop
    /* 648BC 800CD0BC 08004018 */  blez       $v0, .L800CD0E0
    /* 648C0 800CD0C0 08000224 */   addiu     $v0, $zero, 0x8
    /* 648C4 800CD0C4 220002A2 */  sb         $v0, 0x22($s0)
    /* 648C8 800CD0C8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 648CC 800CD0CC 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 648D0 800CD0D0 0000028E */  lw         $v0, 0x0($s0)
    /* 648D4 800CD0D4 CFFF0324 */  addiu      $v1, $zero, -0x31
    /* 648D8 800CD0D8 24104300 */  and        $v0, $v0, $v1
    /* 648DC 800CD0DC 000002AE */  sw         $v0, 0x0($s0)
  .L800CD0E0:
    /* 648E0 800CD0E0 3B340308 */  j          .L800CD0EC
    /* 648E4 800CD0E4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800CD0E8:
    /* 648E8 800CD0E8 21100000 */  addu       $v0, $zero, $zero
  .L800CD0EC:
    /* 648EC 800CD0EC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 648F0 800CD0F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 648F4 800CD0F4 0800E003 */  jr         $ra
    /* 648F8 800CD0F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_dismissTextBox
