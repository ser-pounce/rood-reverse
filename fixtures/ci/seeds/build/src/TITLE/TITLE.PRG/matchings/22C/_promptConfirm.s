nonmatching _promptConfirm, 0x218

glabel _promptConfirm
    /* 466C 8006CE6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4670 8006CE70 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4674 8006CE74 08008010 */  beqz       $a0, .L8006CE98
    /* 4678 8006CE78 1000B0AF */   sw        $s0, 0x10($sp)
    /* 467C 8006CE7C 21100000 */  addu       $v0, $zero, $zero
    /* 4680 8006CE80 0E80033C */  lui        $v1, %hi(_promptConfirmNoSelected)
    /* 4684 8006CE84 01000424 */  addiu      $a0, $zero, 0x1
    /* 4688 8006CE88 E9C864A0 */  sb         $a0, %lo(_promptConfirmNoSelected)($v1)
    /* 468C 8006CE8C 0E80033C */  lui        $v1, %hi(_promptConfirmState)
    /* 4690 8006CE90 1DB40108 */  j          .L8006D074
    /* 4694 8006CE94 E8C860A0 */   sb        $zero, %lo(_promptConfirmState)($v1)
  .L8006CE98:
    /* 4698 8006CE98 0E80103C */  lui        $s0, %hi(_promptConfirmState)
    /* 469C 8006CE9C E8C80792 */  lbu        $a3, %lo(_promptConfirmState)($s0)
    /* 46A0 8006CEA0 02000224 */  addiu      $v0, $zero, 0x2
    /* 46A4 8006CEA4 1E00E210 */  beq        $a3, $v0, .L8006CF20
    /* 46A8 8006CEA8 0300E228 */   slti      $v0, $a3, 0x3
    /* 46AC 8006CEAC 05004014 */  bnez       $v0, .L8006CEC4
    /* 46B0 8006CEB0 03000224 */   addiu     $v0, $zero, 0x3
    /* 46B4 8006CEB4 2100E210 */  beq        $a3, $v0, .L8006CF3C
    /* 46B8 8006CEB8 21100000 */   addu      $v0, $zero, $zero
    /* 46BC 8006CEBC 1DB40108 */  j          .L8006D074
    /* 46C0 8006CEC0 00000000 */   nop
  .L8006CEC4:
    /* 46C4 8006CEC4 6A00E004 */  bltz       $a3, .L8006D070
    /* 46C8 8006CEC8 0300E424 */   addiu     $a0, $a3, 0x3
    /* 46CC 8006CECC 00290700 */  sll        $a1, $a3, 4
    /* 46D0 8006CED0 1200A524 */  addiu      $a1, $a1, 0x12
    /* 46D4 8006CED4 002C0500 */  sll        $a1, $a1, 16
    /* 46D8 8006CED8 82FFA534 */  ori        $a1, $a1, 0xFF82
    /* 46DC 8006CEDC 0C00063C */  lui        $a2, (0xC007E >> 16)
    /* 46E0 8006CEE0 0E80023C */  lui        $v0, %hi(_textTable)
    /* 46E4 8006CEE4 C0EA438C */  lw         $v1, %lo(_textTable)($v0)
    /* 46E8 8006CEE8 40100700 */  sll        $v0, $a3, 1
    /* 46EC 8006CEEC 21104300 */  addu       $v0, $v0, $v1
    /* 46F0 8006CEF0 48004794 */  lhu        $a3, 0x48($v0)
    /* 46F4 8006CEF4 7E00C634 */  ori        $a2, $a2, (0xC007E & 0xFFFF)
    /* 46F8 8006CEF8 40380700 */  sll        $a3, $a3, 1
    /* 46FC 8006CEFC 9CAB010C */  jal        _initFileMenuElement
    /* 4700 8006CF00 21386700 */   addu      $a3, $v1, $a3
    /* 4704 8006CF04 04000324 */  addiu      $v1, $zero, 0x4
    /* 4708 8006CF08 000043A0 */  sb         $v1, 0x0($v0)
    /* 470C 8006CF0C E8C80392 */  lbu        $v1, %lo(_promptConfirmState)($s0)
    /* 4710 8006CF10 080040A4 */  sh         $zero, 0x8($v0)
    /* 4714 8006CF14 01006324 */  addiu      $v1, $v1, 0x1
    /* 4718 8006CF18 1CB40108 */  j          .L8006D070
    /* 471C 8006CF1C E8C803A2 */   sb        $v1, %lo(_promptConfirmState)($s0)
  .L8006CF20:
    /* 4720 8006CF20 EFAB010C */  jal        _fileMenuElementsActive
    /* 4724 8006CF24 00000000 */   nop
    /* 4728 8006CF28 E8C80392 */  lbu        $v1, %lo(_promptConfirmState)($s0)
    /* 472C 8006CF2C 00000000 */  nop
    /* 4730 8006CF30 21186200 */  addu       $v1, $v1, $v0
    /* 4734 8006CF34 1CB40108 */  j          .L8006D070
    /* 4738 8006CF38 E8C803A2 */   sb        $v1, %lo(_promptConfirmState)($s0)
  .L8006CF3C:
    /* 473C 8006CF3C 0E80023C */  lui        $v0, %hi(_fileMenuElements)
    /* 4740 8006CF40 0E80103C */  lui        $s0, %hi(_promptConfirmNoSelected)
    /* 4744 8006CF44 E9C80392 */  lbu        $v1, %lo(_promptConfirmNoSelected)($s0)
    /* 4748 8006CF48 18EB4724 */  addiu      $a3, $v0, %lo(_fileMenuElements)
    /* 474C 8006CF4C 03006324 */  addiu      $v1, $v1, 0x3
    /* 4750 8006CF50 40100300 */  sll        $v0, $v1, 1
    /* 4754 8006CF54 21104300 */  addu       $v0, $v0, $v1
    /* 4758 8006CF58 80100200 */  sll        $v0, $v0, 2
    /* 475C 8006CF5C 21104300 */  addu       $v0, $v0, $v1
    /* 4760 8006CF60 80100200 */  sll        $v0, $v0, 2
    /* 4764 8006CF64 21104700 */  addu       $v0, $v0, $a3
    /* 4768 8006CF68 01000324 */  addiu      $v1, $zero, 0x1
    /* 476C 8006CF6C 040043A0 */  sb         $v1, 0x4($v0)
    /* 4770 8006CF70 E9C80292 */  lbu        $v0, %lo(_promptConfirmNoSelected)($s0)
    /* 4774 8006CF74 04000324 */  addiu      $v1, $zero, 0x4
    /* 4778 8006CF78 23186200 */  subu       $v1, $v1, $v0
    /* 477C 8006CF7C 40100300 */  sll        $v0, $v1, 1
    /* 4780 8006CF80 21104300 */  addu       $v0, $v0, $v1
    /* 4784 8006CF84 80100200 */  sll        $v0, $v0, 2
    /* 4788 8006CF88 21104300 */  addu       $v0, $v0, $v1
    /* 478C 8006CF8C 80100200 */  sll        $v0, $v0, 2
    /* 4790 8006CF90 21104700 */  addu       $v0, $v0, $a3
    /* 4794 8006CF94 040040A0 */  sb         $zero, 0x4($v0)
    /* 4798 8006CF98 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 479C 8006CF9C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 47A0 8006CFA0 00000000 */  nop
    /* 47A4 8006CFA4 60004230 */  andi       $v0, $v0, 0x60
    /* 47A8 8006CFA8 1F004010 */  beqz       $v0, .L8006D028
    /* 47AC 8006CFAC 0E80023C */   lui       $v0, %hi(_selectCursorXy)
    /* 47B0 8006CFB0 68ED40AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 47B4 8006CFB4 03000424 */  addiu      $a0, $zero, 0x3
    /* 47B8 8006CFB8 04000624 */  addiu      $a2, $zero, 0x4
    /* 47BC 8006CFBC 82FF0524 */  addiu      $a1, $zero, -0x7E
    /* 47C0 8006CFC0 9C00E324 */  addiu      $v1, $a3, 0x9C
  .L8006CFC4:
    /* 47C4 8006CFC4 000066A0 */  sb         $a2, 0x0($v1)
    /* 47C8 8006CFC8 080065A4 */  sh         $a1, 0x8($v1)
    /* 47CC 8006CFCC 01008424 */  addiu      $a0, $a0, 0x1
    /* 47D0 8006CFD0 05008228 */  slti       $v0, $a0, 0x5
    /* 47D4 8006CFD4 FBFF4014 */  bnez       $v0, .L8006CFC4
    /* 47D8 8006CFD8 34006324 */   addiu     $v1, $v1, 0x34
    /* 47DC 8006CFDC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 47E0 8006CFE0 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 47E4 8006CFE4 00000000 */  nop
    /* 47E8 8006CFE8 20004230 */  andi       $v0, $v0, 0x20
    /* 47EC 8006CFEC 09004010 */  beqz       $v0, .L8006D014
    /* 47F0 8006CFF0 0E80023C */   lui       $v0, %hi(_promptConfirmNoSelected)
    /* 47F4 8006CFF4 E9C84290 */  lbu        $v0, %lo(_promptConfirmNoSelected)($v0)
    /* 47F8 8006CFF8 00000000 */  nop
    /* 47FC 8006CFFC 06004014 */  bnez       $v0, .L8006D018
    /* 4800 8006D000 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4804 8006D004 6216010C */  jal        vs_main_playSfxDefault
    /* 4808 8006D008 05000524 */   addiu     $a1, $zero, 0x5
    /* 480C 8006D00C 1DB40108 */  j          .L8006D074
    /* 4810 8006D010 01000224 */   addiu     $v0, $zero, 0x1
  .L8006D014:
    /* 4814 8006D014 7E000424 */  addiu      $a0, $zero, 0x7E
  .L8006D018:
    /* 4818 8006D018 6216010C */  jal        vs_main_playSfxDefault
    /* 481C 8006D01C 06000524 */   addiu     $a1, $zero, 0x6
    /* 4820 8006D020 1DB40108 */  j          .L8006D074
    /* 4824 8006D024 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006D028:
    /* 4828 8006D028 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 482C 8006D02C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 4830 8006D030 00000000 */  nop
    /* 4834 8006D034 00504230 */  andi       $v0, $v0, 0x5000
    /* 4838 8006D038 07004010 */  beqz       $v0, .L8006D058
    /* 483C 8006D03C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4840 8006D040 6216010C */  jal        vs_main_playSfxDefault
    /* 4844 8006D044 04000524 */   addiu     $a1, $zero, 0x4
    /* 4848 8006D048 E9C80392 */  lbu        $v1, %lo(_promptConfirmNoSelected)($s0)
    /* 484C 8006D04C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4850 8006D050 23104300 */  subu       $v0, $v0, $v1
    /* 4854 8006D054 E9C802A2 */  sb         $v0, %lo(_promptConfirmNoSelected)($s0)
  .L8006D058:
    /* 4858 8006D058 E9C80292 */  lbu        $v0, %lo(_promptConfirmNoSelected)($s0)
    /* 485C 8006D05C 0E80033C */  lui        $v1, %hi(_selectCursorXy)
    /* 4860 8006D060 00110200 */  sll        $v0, $v0, 4
    /* 4864 8006D064 0A004224 */  addiu      $v0, $v0, 0xA
    /* 4868 8006D068 00140200 */  sll        $v0, $v0, 16
    /* 486C 8006D06C 68ED62AC */  sw         $v0, %lo(_selectCursorXy)($v1)
  .L8006D070:
    /* 4870 8006D070 21100000 */  addu       $v0, $zero, $zero
  .L8006D074:
    /* 4874 8006D074 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4878 8006D078 1000B08F */  lw         $s0, 0x10($sp)
    /* 487C 8006D07C 0800E003 */  jr         $ra
    /* 4880 8006D080 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _promptConfirm
