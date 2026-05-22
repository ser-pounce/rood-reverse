nonmatching func_800BD57C, 0x94

glabel func_800BD57C
    /* 54D7C 800BD57C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 54D80 800BD580 1000B0AF */  sw         $s0, 0x10($sp)
    /* 54D84 800BD584 21808000 */  addu       $s0, $a0, $zero
    /* 54D88 800BD588 1400BFAF */  sw         $ra, 0x14($sp)
    /* 54D8C 800BD58C 0A000286 */  lh         $v0, 0xA($s0)
    /* 54D90 800BD590 00000000 */  nop
    /* 54D94 800BD594 1A004018 */  blez       $v0, .L800BD600
    /* 54D98 800BD598 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 54D9C 800BD59C 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 54DA0 800BD5A0 08000596 */  lhu        $a1, 0x8($s0)
    /* 54DA4 800BD5A4 01000492 */  lbu        $a0, 0x1($s0)
    /* 54DA8 800BD5A8 0A000686 */  lh         $a2, 0xA($s0)
    /* 54DAC 800BD5AC 43100200 */  sra        $v0, $v0, 1
    /* 54DB0 800BD5B0 2128A200 */  addu       $a1, $a1, $v0
    /* 54DB4 800BD5B4 080005A6 */  sh         $a1, 0x8($s0)
    /* 54DB8 800BD5B8 002C0500 */  sll        $a1, $a1, 16
    /* 54DBC 800BD5BC AFFF020C */  jal        func_800BFEBC
    /* 54DC0 800BD5C0 032C0500 */   sra       $a1, $a1, 16
    /* 54DC4 800BD5C4 06000386 */  lh         $v1, 0x6($s0)
    /* 54DC8 800BD5C8 00000000 */  nop
    /* 54DCC 800BD5CC 18006200 */  mult       $v1, $v0
    /* 54DD0 800BD5D0 0A000486 */  lh         $a0, 0xA($s0)
    /* 54DD4 800BD5D4 08000386 */  lh         $v1, 0x8($s0)
    /* 54DD8 800BD5D8 04000296 */  lhu        $v0, 0x4($s0)
    /* 54DDC 800BD5DC 2A186400 */  slt        $v1, $v1, $a0
    /* 54DE0 800BD5E0 12380000 */  mflo       $a3
    /* 54DE4 800BD5E4 032B0700 */  sra        $a1, $a3, 12
    /* 54DE8 800BD5E8 21104500 */  addu       $v0, $v0, $a1
    /* 54DEC 800BD5EC 02006014 */  bnez       $v1, .L800BD5F8
    /* 54DF0 800BD5F0 020002A6 */   sh        $v0, 0x2($s0)
    /* 54DF4 800BD5F4 0A0000A6 */  sh         $zero, 0xA($s0)
  .L800BD5F8:
    /* 54DF8 800BD5F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 54DFC 800BD5FC 000002A2 */  sb         $v0, 0x0($s0)
  .L800BD600:
    /* 54E00 800BD600 1400BF8F */  lw         $ra, 0x14($sp)
    /* 54E04 800BD604 1000B08F */  lw         $s0, 0x10($sp)
    /* 54E08 800BD608 0800E003 */  jr         $ra
    /* 54E0C 800BD60C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BD57C
