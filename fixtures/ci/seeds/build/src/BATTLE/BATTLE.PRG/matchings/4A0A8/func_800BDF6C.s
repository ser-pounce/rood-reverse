nonmatching func_800BDF6C, 0xB0

glabel func_800BDF6C
    /* 5576C 800BDF6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 55770 800BDF70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 55774 800BDF74 21808000 */  addu       $s0, $a0, $zero
    /* 55778 800BDF78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5577C 800BDF7C 09000292 */  lbu        $v0, 0x9($s0)
    /* 55780 800BDF80 00000000 */  nop
    /* 55784 800BDF84 21004010 */  beqz       $v0, .L800BE00C
    /* 55788 800BDF88 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 5578C 800BDF8C 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 55790 800BDF90 08000292 */  lbu        $v0, 0x8($s0)
    /* 55794 800BDF94 43180300 */  sra        $v1, $v1, 1
    /* 55798 800BDF98 21104300 */  addu       $v0, $v0, $v1
    /* 5579C 800BDF9C 09000392 */  lbu        $v1, 0x9($s0)
    /* 557A0 800BDFA0 080002A2 */  sb         $v0, 0x8($s0)
    /* 557A4 800BDFA4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 557A8 800BDFA8 2B106200 */  sltu       $v0, $v1, $v0
    /* 557AC 800BDFAC 02004010 */  beqz       $v0, .L800BDFB8
    /* 557B0 800BDFB0 00000000 */   nop
    /* 557B4 800BDFB4 080003A2 */  sb         $v1, 0x8($s0)
  .L800BDFB8:
    /* 557B8 800BDFB8 01000492 */  lbu        $a0, 0x1($s0)
    /* 557BC 800BDFBC 08000592 */  lbu        $a1, 0x8($s0)
    /* 557C0 800BDFC0 09000692 */  lbu        $a2, 0x9($s0)
    /* 557C4 800BDFC4 AFFF020C */  jal        func_800BFEBC
    /* 557C8 800BDFC8 00000000 */   nop
    /* 557CC 800BDFCC 801F013C */  lui        $at, (0x1F800088 >> 16)
    /* 557D0 800BDFD0 880022AC */  sw         $v0, (0x1F800088 & 0xFFFF)($at)
    /* 557D4 800BDFD4 06000386 */  lh         $v1, 0x6($s0)
    /* 557D8 800BDFD8 00000000 */  nop
    /* 557DC 800BDFDC 18006200 */  mult       $v1, $v0
    /* 557E0 800BDFE0 08000592 */  lbu        $a1, 0x8($s0)
    /* 557E4 800BDFE4 04000296 */  lhu        $v0, 0x4($s0)
    /* 557E8 800BDFE8 09000392 */  lbu        $v1, 0x9($s0)
    /* 557EC 800BDFEC 12380000 */  mflo       $a3
    /* 557F0 800BDFF0 03230700 */  sra        $a0, $a3, 12
    /* 557F4 800BDFF4 21104400 */  addu       $v0, $v0, $a0
    /* 557F8 800BDFF8 0200A314 */  bne        $a1, $v1, .L800BE004
    /* 557FC 800BDFFC 020002A6 */   sh        $v0, 0x2($s0)
    /* 55800 800BE000 090000A2 */  sb         $zero, 0x9($s0)
  .L800BE004:
    /* 55804 800BE004 01000224 */  addiu      $v0, $zero, 0x1
    /* 55808 800BE008 000002A2 */  sb         $v0, 0x0($s0)
  .L800BE00C:
    /* 5580C 800BE00C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 55810 800BE010 1000B08F */  lw         $s0, 0x10($sp)
    /* 55814 800BE014 0800E003 */  jr         $ra
    /* 55818 800BE018 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BDF6C
