nonmatching vs_battle_initTextBox, 0x15C

glabel vs_battle_initTextBox
    /* 64708 800CCF08 40180400 */  sll        $v1, $a0, 1
    /* 6470C 800CCF0C 21186400 */  addu       $v1, $v1, $a0
    /* 64710 800CCF10 00190300 */  sll        $v1, $v1, 4
    /* 64714 800CCF14 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 64718 800CCF18 E04F4224 */  addiu      $v0, $v0, %lo(vs_battle_textBoxes)
    /* 6471C 800CCF1C 21406200 */  addu       $t0, $v1, $v0
    /* 64720 800CCF20 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 64724 800CCF24 0020023C */  lui        $v0, (0x20000000 >> 16)
    /* 64728 800CCF28 2528A200 */  or         $a1, $a1, $v0
    /* 6472C 800CCF2C 140006A5 */  sh         $a2, 0x14($t0)
    /* 64730 800CCF30 0500C624 */  addiu      $a2, $a2, 0x5
    /* 64734 800CCF34 160007A5 */  sh         $a3, 0x16($t0)
    /* 64738 800CCF38 0300E724 */  addiu      $a3, $a3, 0x3
    /* 6473C 800CCF3C 000005AD */  sw         $a1, 0x0($t0)
    /* 64740 800CCF40 040000A5 */  sh         $zero, 0x4($t0)
    /* 64744 800CCF44 060000A5 */  sh         $zero, 0x6($t0)
    /* 64748 800CCF48 0C0000A5 */  sh         $zero, 0xC($t0)
    /* 6474C 800CCF4C 100006A5 */  sh         $a2, 0x10($t0)
    /* 64750 800CCF50 120007A5 */  sh         $a3, 0x12($t0)
    /* 64754 800CCF54 2E0000A5 */  sh         $zero, 0x2E($t0)
    /* 64758 800CCF58 1000A48F */  lw         $a0, 0x10($sp)
    /* 6475C 800CCF5C 1400A78F */  lw         $a3, 0x14($sp)
    /* 64760 800CCF60 1800A58F */  lw         $a1, 0x18($sp)
    /* 64764 800CCF64 1C00A68F */  lw         $a2, 0x1C($sp)
    /* 64768 800CCF68 0000038D */  lw         $v1, 0x0($t0)
    /* 6476C 800CCF6C 80000224 */  addiu      $v0, $zero, 0x80
    /* 64770 800CCF70 1E0002A1 */  sb         $v0, 0x1E($t0)
    /* 64774 800CCF74 A5450224 */  addiu      $v0, $zero, 0x45A5
    /* 64778 800CCF78 82180300 */  srl        $v1, $v1, 2
    /* 6477C 800CCF7C 0C006330 */  andi       $v1, $v1, 0xC
    /* 64780 800CCF80 07106200 */  srav       $v0, $v0, $v1
    /* 64784 800CCF84 0F004230 */  andi       $v0, $v0, 0xF
    /* 64788 800CCF88 1C000385 */  lh         $v1, 0x1C($t0)
    /* 6478C 800CCF8C 40100200 */  sll        $v0, $v0, 1
    /* 64790 800CCF90 200004A1 */  sb         $a0, 0x20($t0)
    /* 64794 800CCF94 210007A1 */  sb         $a3, 0x21($t0)
    /* 64798 800CCF98 180005A5 */  sh         $a1, 0x18($t0)
    /* 6479C 800CCF9C 1A0006A5 */  sh         $a2, 0x1A($t0)
    /* 647A0 800CCFA0 0300601C */  bgtz       $v1, .L800CCFB0
    /* 647A4 800CCFA4 220002A1 */   sb        $v0, 0x22($t0)
    /* 647A8 800CCFA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 647AC 800CCFAC 1C0002A5 */  sh         $v0, 0x1C($t0)
  .L800CCFB0:
    /* 647B0 800CCFB0 0000048D */  lw         $a0, 0x0($t0)
    /* 647B4 800CCFB4 04000224 */  addiu      $v0, $zero, 0x4
    /* 647B8 800CCFB8 0F008330 */  andi       $v1, $a0, 0xF
    /* 647BC 800CCFBC 12006210 */  beq        $v1, $v0, .L800CD008
    /* 647C0 800CCFC0 05006228 */   slti      $v0, $v1, 0x5
    /* 647C4 800CCFC4 05004010 */  beqz       $v0, .L800CCFDC
    /* 647C8 800CCFC8 01000224 */   addiu     $v0, $zero, 0x1
    /* 647CC 800CCFCC 08006210 */  beq        $v1, $v0, .L800CCFF0
    /* 647D0 800CCFD0 F0FF0224 */   addiu     $v0, $zero, -0x10
    /* 647D4 800CCFD4 0800E003 */  jr         $ra
    /* 647D8 800CCFD8 00000000 */   nop
  .L800CCFDC:
    /* 647DC 800CCFDC 05000224 */  addiu      $v0, $zero, 0x5
    /* 647E0 800CCFE0 19006210 */  beq        $v1, $v0, .L800CD048
    /* 647E4 800CCFE4 F0FF0224 */   addiu     $v0, $zero, -0x10
    /* 647E8 800CCFE8 0800E003 */  jr         $ra
    /* 647EC 800CCFEC 00000000 */   nop
  .L800CCFF0:
    /* 647F0 800CCFF0 24108200 */  and        $v0, $a0, $v0
    /* 647F4 800CCFF4 07004234 */  ori        $v0, $v0, 0x7
    /* 647F8 800CCFF8 FFF00324 */  addiu      $v1, $zero, -0xF01
    /* 647FC 800CCFFC 24104300 */  and        $v0, $v0, $v1
    /* 64800 800CD000 0800E003 */  jr         $ra
    /* 64804 800CD004 000002AD */   sw        $v0, 0x0($t0)
  .L800CD008:
    /* 64808 800CD008 18000224 */  addiu      $v0, $zero, 0x18
    /* 6480C 800CD00C 200002A1 */  sb         $v0, 0x20($t0)
    /* 64810 800CD010 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 64814 800CD014 180002A5 */  sh         $v0, 0x18($t0)
    /* 64818 800CD018 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 6481C 800CD01C 1A0002A5 */  sh         $v0, 0x1A($t0)
    /* 64820 800CD020 10000224 */  addiu      $v0, $zero, 0x10
    /* 64824 800CD024 100002A5 */  sh         $v0, 0x10($t0)
    /* 64828 800CD028 40100700 */  sll        $v0, $a3, 1
    /* 6482C 800CD02C 21104700 */  addu       $v0, $v0, $a3
    /* 64830 800CD030 80100200 */  sll        $v0, $v0, 2
    /* 64834 800CD034 21104700 */  addu       $v0, $v0, $a3
    /* 64838 800CD038 F2000324 */  addiu      $v1, $zero, 0xF2
    /* 6483C 800CD03C 23186200 */  subu       $v1, $v1, $v0
    /* 64840 800CD040 0800E003 */  jr         $ra
    /* 64844 800CD044 120003A5 */   sh        $v1, 0x12($t0)
  .L800CD048:
    /* 64848 800CD048 24108200 */  and        $v0, $a0, $v0
    /* 6484C 800CD04C 07004234 */  ori        $v0, $v0, 0x7
    /* 64850 800CD050 FFF00324 */  addiu      $v1, $zero, -0xF01
    /* 64854 800CD054 24104300 */  and        $v0, $v0, $v1
    /* 64858 800CD058 00024234 */  ori        $v0, $v0, 0x200
    /* 6485C 800CD05C 0800E003 */  jr         $ra
    /* 64860 800CD060 000002AD */   sw        $v0, 0x0($t0)
endlabel vs_battle_initTextBox
