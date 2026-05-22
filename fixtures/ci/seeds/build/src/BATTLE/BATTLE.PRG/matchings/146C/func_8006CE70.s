nonmatching func_8006CE70, 0x1B8

glabel func_8006CE70
    /* 4670 8006CE70 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4674 8006CE74 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4678 8006CE78 21808000 */  addu       $s0, $a0, $zero
    /* 467C 8006CE7C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4680 8006CE80 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4684 8006CE84 06000296 */  lhu        $v0, 0x6($s0)
    /* 4688 8006CE88 00000000 */  nop
    /* 468C 8006CE8C F0014330 */  andi       $v1, $v0, 0x1F0
    /* 4690 8006CE90 20000224 */  addiu      $v0, $zero, 0x20
    /* 4694 8006CE94 29006210 */  beq        $v1, $v0, .L8006CF3C
    /* 4698 8006CE98 21006228 */   slti      $v0, $v1, 0x21
    /* 469C 8006CE9C 05004010 */  beqz       $v0, .L8006CEB4
    /* 46A0 8006CEA0 10000224 */   addiu     $v0, $zero, 0x10
    /* 46A4 8006CEA4 08006210 */  beq        $v1, $v0, .L8006CEC8
    /* 46A8 8006CEA8 00000000 */   nop
    /* 46AC 8006CEAC 05B40108 */  j          .L8006D014
    /* 46B0 8006CEB0 00000000 */   nop
  .L8006CEB4:
    /* 46B4 8006CEB4 00010224 */  addiu      $v0, $zero, 0x100
    /* 46B8 8006CEB8 20006210 */  beq        $v1, $v0, .L8006CF3C
    /* 46BC 8006CEBC 00000000 */   nop
    /* 46C0 8006CEC0 05B40108 */  j          .L8006D014
    /* 46C4 8006CEC4 00000000 */   nop
  .L8006CEC8:
    /* 46C8 8006CEC8 EE38020C */  jal        func_8008E3B8
    /* 46CC 8006CECC 1000A427 */   addiu     $a0, $sp, 0x10
    /* 46D0 8006CED0 06000396 */  lhu        $v1, 0x6($s0)
    /* 46D4 8006CED4 21884000 */  addu       $s1, $v0, $zero
    /* 46D8 8006CED8 0F006330 */  andi       $v1, $v1, 0xF
    /* 46DC 8006CEDC 80100300 */  sll        $v0, $v1, 2
    /* 46E0 8006CEE0 21104300 */  addu       $v0, $v0, $v1
    /* 46E4 8006CEE4 80100200 */  sll        $v0, $v0, 2
    /* 46E8 8006CEE8 21105100 */  addu       $v0, $v0, $s1
    /* 46EC 8006CEEC 08004390 */  lbu        $v1, 0x8($v0)
    /* 46F0 8006CEF0 00000000 */  nop
    /* 46F4 8006CEF4 04006228 */  slti       $v0, $v1, 0x4
    /* 46F8 8006CEF8 44004010 */  beqz       $v0, .L8006D00C
    /* 46FC 8006CEFC 02006228 */   slti      $v0, $v1, 0x2
    /* 4700 8006CF00 42004014 */  bnez       $v0, .L8006D00C
    /* 4704 8006CF04 00000000 */   nop
    /* 4708 8006CF08 0DFD010C */  jal        func_8007F434
    /* 470C 8006CF0C 00000000 */   nop
    /* 4710 8006CF10 3E004010 */  beqz       $v0, .L8006D00C
    /* 4714 8006CF14 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4718 8006CF18 06000396 */  lhu        $v1, 0x6($s0)
    /* 471C 8006CF1C 3F000524 */  addiu      $a1, $zero, 0x3F
    /* 4720 8006CF20 0F006330 */  andi       $v1, $v1, 0xF
    /* 4724 8006CF24 80100300 */  sll        $v0, $v1, 2
    /* 4728 8006CF28 21104300 */  addu       $v0, $v0, $v1
    /* 472C 8006CF2C 80100200 */  sll        $v0, $v0, 2
    /* 4730 8006CF30 21105100 */  addu       $v0, $v0, $s1
    /* 4734 8006CF34 FCB30108 */  j          .L8006CFF0
    /* 4738 8006CF38 080040A0 */   sb        $zero, 0x8($v0)
  .L8006CF3C:
    /* 473C 8006CF3C DC38020C */  jal        func_8008E370
    /* 4740 8006CF40 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4744 8006CF44 06000396 */  lhu        $v1, 0x6($s0)
    /* 4748 8006CF48 21884000 */  addu       $s1, $v0, $zero
    /* 474C 8006CF4C 0F006330 */  andi       $v1, $v1, 0xF
    /* 4750 8006CF50 C0100300 */  sll        $v0, $v1, 3
    /* 4754 8006CF54 21104300 */  addu       $v0, $v0, $v1
    /* 4758 8006CF58 80100200 */  sll        $v0, $v0, 2
    /* 475C 8006CF5C 23104300 */  subu       $v0, $v0, $v1
    /* 4760 8006CF60 80100200 */  sll        $v0, $v0, 2
    /* 4764 8006CF64 21104300 */  addu       $v0, $v0, $v1
    /* 4768 8006CF68 80100200 */  sll        $v0, $v0, 2
    /* 476C 8006CF6C 21205100 */  addu       $a0, $v0, $s1
    /* 4770 8006CF70 0C008384 */  lh         $v1, 0xC($a0)
    /* 4774 8006CF74 00000000 */  nop
    /* 4778 8006CF78 04006228 */  slti       $v0, $v1, 0x4
    /* 477C 8006CF7C 23004010 */  beqz       $v0, .L8006D00C
    /* 4780 8006CF80 02006228 */   slti      $v0, $v1, 0x2
    /* 4784 8006CF84 21004014 */  bnez       $v0, .L8006D00C
    /* 4788 8006CF88 00000000 */   nop
    /* 478C 8006CF8C 10008494 */  lhu        $a0, 0x10($a0)
    /* 4790 8006CF90 00000000 */  nop
    /* 4794 8006CF94 C0038424 */  addiu      $a0, $a0, 0x3C0
    /* 4798 8006CF98 00240400 */  sll        $a0, $a0, 16
    /* 479C 8006CF9C FDFA020C */  jal        vs_battle_getStateFlag
    /* 47A0 8006CFA0 03240400 */   sra       $a0, $a0, 16
    /* 47A4 8006CFA4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 47A8 8006CFA8 18004014 */  bnez       $v0, .L8006D00C
    /* 47AC 8006CFAC 00000000 */   nop
    /* 47B0 8006CFB0 0DFD010C */  jal        func_8007F434
    /* 47B4 8006CFB4 00000000 */   nop
    /* 47B8 8006CFB8 14004010 */  beqz       $v0, .L8006D00C
    /* 47BC 8006CFBC 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 47C0 8006CFC0 06000396 */  lhu        $v1, 0x6($s0)
    /* 47C4 8006CFC4 3F000524 */  addiu      $a1, $zero, 0x3F
    /* 47C8 8006CFC8 0F006330 */  andi       $v1, $v1, 0xF
    /* 47CC 8006CFCC C0100300 */  sll        $v0, $v1, 3
    /* 47D0 8006CFD0 21104300 */  addu       $v0, $v0, $v1
    /* 47D4 8006CFD4 80100200 */  sll        $v0, $v0, 2
    /* 47D8 8006CFD8 23104300 */  subu       $v0, $v0, $v1
    /* 47DC 8006CFDC 80100200 */  sll        $v0, $v0, 2
    /* 47E0 8006CFE0 21104300 */  addu       $v0, $v0, $v1
    /* 47E4 8006CFE4 80100200 */  sll        $v0, $v0, 2
    /* 47E8 8006CFE8 21105100 */  addu       $v0, $v0, $s1
    /* 47EC 8006CFEC 0C0040A4 */  sh         $zero, 0xC($v0)
  .L8006CFF0:
    /* 47F0 8006CFF0 6216010C */  jal        vs_main_playSfxDefault
    /* 47F4 8006CFF4 00000000 */   nop
    /* 47F8 8006CFF8 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 47FC 8006CFFC 6216010C */  jal        vs_main_playSfxDefault
    /* 4800 8006D000 40000524 */   addiu     $a1, $zero, 0x40
    /* 4804 8006D004 05B40108 */  j          .L8006D014
    /* 4808 8006D008 00000000 */   nop
  .L8006D00C:
    /* 480C 8006D00C C14E020C */  jal        func_80093B04
    /* 4810 8006D010 21200002 */   addu      $a0, $s0, $zero
  .L8006D014:
    /* 4814 8006D014 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4818 8006D018 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 481C 8006D01C 1800B08F */  lw         $s0, 0x18($sp)
    /* 4820 8006D020 0800E003 */  jr         $ra
    /* 4824 8006D024 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006CE70
