nonmatching _selectLoadMemoryCard, 0x344

glabel _selectLoadMemoryCard
    /* 5698 80107E98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 569C 80107E9C 0C008010 */  beqz       $a0, .L80107ED0
    /* 56A0 80107EA0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 56A4 80107EA4 21100000 */  addu       $v0, $zero, $zero
    /* 56A8 80107EA8 1180033C */  lui        $v1, %hi(_selectLoadMemoryCardPort)
    /* 56AC 80107EAC FFAA64A0 */  sb         $a0, %lo(_selectLoadMemoryCardPort)($v1)
    /* 56B0 80107EB0 1180033C */  lui        $v1, %hi(_selectLoadMemoryCardState)
    /* 56B4 80107EB4 FEAA60A0 */  sb         $zero, %lo(_selectLoadMemoryCardState)($v1)
    /* 56B8 80107EB8 1180033C */  lui        $v1, %hi(_textTable)
    /* 56BC 80107EBC F8AD638C */  lw         $v1, %lo(_textTable)($v1)
    /* 56C0 80107EC0 1180043C */  lui        $a0, %hi(_memoryCardMessage)
    /* 56C4 80107EC4 88016324 */  addiu      $v1, $v1, 0x188
    /* 56C8 80107EC8 73200408 */  j          .L801081CC
    /* 56CC 80107ECC A4B083AC */   sw        $v1, %lo(_memoryCardMessage)($a0)
  .L80107ED0:
    /* 56D0 80107ED0 1180023C */  lui        $v0, %hi(_selectLoadMemoryCardState)
    /* 56D4 80107ED4 FEAA4390 */  lbu        $v1, %lo(_selectLoadMemoryCardState)($v0)
    /* 56D8 80107ED8 00000000 */  nop
    /* 56DC 80107EDC 0800622C */  sltiu      $v0, $v1, 0x8
    /* 56E0 80107EE0 B9004010 */  beqz       $v0, .L801081C8
    /* 56E4 80107EE4 1080023C */   lui       $v0, %hi(jtbl_80102960)
    /* 56E8 80107EE8 60294224 */  addiu      $v0, $v0, %lo(jtbl_80102960)
    /* 56EC 80107EEC 80180300 */  sll        $v1, $v1, 2
    /* 56F0 80107EF0 21186200 */  addu       $v1, $v1, $v0
    /* 56F4 80107EF4 0000628C */  lw         $v0, 0x0($v1)
    /* 56F8 80107EF8 00000000 */  nop
    /* 56FC 80107EFC 08004000 */  jr         $v0
    /* 5700 80107F00 00000000 */   nop
    /* 5704 80107F04 1180053C */  lui        $a1, %hi(_fileMenuElements)
    /* 5708 80107F08 1180063C */  lui        $a2, %hi(_selectLoadMemoryCardPort)
    /* 570C 80107F0C 50AEA524 */  addiu      $a1, $a1, %lo(_fileMenuElements)
    /* 5710 80107F10 FFAAC390 */  lbu        $v1, %lo(_selectLoadMemoryCardPort)($a2)
    /* 5714 80107F14 02000824 */  addiu      $t0, $zero, 0x2
    /* 5718 80107F18 40100300 */  sll        $v0, $v1, 1
    /* 571C 80107F1C 21104300 */  addu       $v0, $v0, $v1
    /* 5720 80107F20 80100200 */  sll        $v0, $v0, 2
    /* 5724 80107F24 21104300 */  addu       $v0, $v0, $v1
    /* 5728 80107F28 80100200 */  sll        $v0, $v0, 2
    /* 572C 80107F2C 21104500 */  addu       $v0, $v0, $a1
    /* 5730 80107F30 000048A0 */  sb         $t0, 0x0($v0)
    /* 5734 80107F34 FFAAC390 */  lbu        $v1, %lo(_selectLoadMemoryCardPort)($a2)
    /* 5738 80107F38 01000724 */  addiu      $a3, $zero, 0x1
    /* 573C 80107F3C 40100300 */  sll        $v0, $v1, 1
    /* 5740 80107F40 21104300 */  addu       $v0, $v0, $v1
    /* 5744 80107F44 80100200 */  sll        $v0, $v0, 2
    /* 5748 80107F48 21104300 */  addu       $v0, $v0, $v1
    /* 574C 80107F4C 80100200 */  sll        $v0, $v0, 2
    /* 5750 80107F50 21104500 */  addu       $v0, $v0, $a1
    /* 5754 80107F54 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 5758 80107F58 080043A4 */  sh         $v1, 0x8($v0)
    /* 575C 80107F5C 030047A0 */  sb         $a3, 0x3($v0)
    /* 5760 80107F60 FFAAC390 */  lbu        $v1, %lo(_selectLoadMemoryCardPort)($a2)
    /* 5764 80107F64 03000424 */  addiu      $a0, $zero, 0x3
    /* 5768 80107F68 23188300 */  subu       $v1, $a0, $v1
    /* 576C 80107F6C 40100300 */  sll        $v0, $v1, 1
    /* 5770 80107F70 21104300 */  addu       $v0, $v0, $v1
    /* 5774 80107F74 80100200 */  sll        $v0, $v0, 2
    /* 5778 80107F78 21104300 */  addu       $v0, $v0, $v1
    /* 577C 80107F7C 80100200 */  sll        $v0, $v0, 2
    /* 5780 80107F80 21104500 */  addu       $v0, $v0, $a1
    /* 5784 80107F84 000048A0 */  sb         $t0, 0x0($v0)
    /* 5788 80107F88 FFAAC390 */  lbu        $v1, %lo(_selectLoadMemoryCardPort)($a2)
    /* 578C 80107F8C 1180023C */  lui        $v0, %hi(_selectLoadMemoryCardState)
    /* 5790 80107F90 FEAA47A0 */  sb         $a3, %lo(_selectLoadMemoryCardState)($v0)
    /* 5794 80107F94 23208300 */  subu       $a0, $a0, $v1
    /* 5798 80107F98 40100400 */  sll        $v0, $a0, 1
    /* 579C 80107F9C 21104400 */  addu       $v0, $v0, $a0
    /* 57A0 80107FA0 80100200 */  sll        $v0, $v0, 2
    /* 57A4 80107FA4 21104400 */  addu       $v0, $v0, $a0
    /* 57A8 80107FA8 80100200 */  sll        $v0, $v0, 2
    /* 57AC 80107FAC 21104500 */  addu       $v0, $v0, $a1
    /* 57B0 80107FB0 40010324 */  addiu      $v1, $zero, 0x140
    /* 57B4 80107FB4 72200408 */  j          .L801081C8
    /* 57B8 80107FB8 080043A4 */   sh        $v1, 0x8($v0)
    /* 57BC 80107FBC C113040C */  jal        _fileMenuElementsActive
    /* 57C0 80107FC0 00000000 */   nop
    /* 57C4 80107FC4 80004010 */  beqz       $v0, .L801081C8
    /* 57C8 80107FC8 1180023C */   lui       $v0, %hi(_selectLoadMemoryCardPort)
    /* 57CC 80107FCC FFAA4290 */  lbu        $v0, %lo(_selectLoadMemoryCardPort)($v0)
    /* 57D0 80107FD0 02000424 */  addiu      $a0, $zero, 0x2
    /* 57D4 80107FD4 08004414 */  bne        $v0, $a0, .L80107FF8
    /* 57D8 80107FD8 1180023C */   lui       $v0, %hi(_selectLoadMemoryCardState)
    /* 57DC 80107FDC 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 57E0 80107FE0 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 57E4 80107FE4 03000324 */  addiu      $v1, $zero, 0x3
    /* 57E8 80107FE8 680043A0 */  sb         $v1, 0x68($v0)
    /* 57EC 80107FEC 32000324 */  addiu      $v1, $zero, 0x32
    /* 57F0 80107FF0 700043A4 */  sh         $v1, 0x70($v0)
    /* 57F4 80107FF4 1180023C */  lui        $v0, %hi(_selectLoadMemoryCardState)
  .L80107FF8:
    /* 57F8 80107FF8 72200408 */  j          .L801081C8
    /* 57FC 80107FFC FEAA44A0 */   sb        $a0, %lo(_selectLoadMemoryCardState)($v0)
    /* 5800 80108000 C113040C */  jal        _fileMenuElementsActive
    /* 5804 80108004 00000000 */   nop
    /* 5808 80108008 6F004010 */  beqz       $v0, .L801081C8
    /* 580C 8010800C 1180023C */   lui       $v0, %hi(_selectLoadMemoryCardPort)
    /* 5810 80108010 FFAA4490 */  lbu        $a0, %lo(_selectLoadMemoryCardPort)($v0)
    /* 5814 80108014 7D14040C */  jal        _memcardMaskedHandler
    /* 5818 80108018 30008424 */   addiu     $a0, $a0, 0x30
    /* 581C 8010801C 1180033C */  lui        $v1, %hi(_selectLoadMemoryCardState)
    /* 5820 80108020 03000224 */  addiu      $v0, $zero, 0x3
    /* 5824 80108024 72200408 */  j          .L801081C8
    /* 5828 80108028 FEAA62A0 */   sb        $v0, %lo(_selectLoadMemoryCardState)($v1)
    /* 582C 8010802C 7D14040C */  jal        _memcardMaskedHandler
    /* 5830 80108030 21200000 */   addu      $a0, $zero, $zero
    /* 5834 80108034 21204000 */  addu       $a0, $v0, $zero
    /* 5838 80108038 63008010 */  beqz       $a0, .L801081C8
    /* 583C 8010803C 1180033C */   lui       $v1, %hi(_selectLoadMemoryCardState)
    /* 5840 80108040 05008224 */  addiu      $v0, $a0, 0x5
    /* 5844 80108044 72200408 */  j          .L801081C8
    /* 5848 80108048 FEAA62A0 */   sb        $v0, %lo(_selectLoadMemoryCardState)($v1)
    /* 584C 8010804C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5850 80108050 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5854 80108054 00000000 */  nop
    /* 5858 80108058 5B004010 */  beqz       $v0, .L801081C8
    /* 585C 8010805C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 5860 80108060 6216010C */  jal        vs_main_playSfxDefault
    /* 5864 80108064 06000524 */   addiu     $a1, $zero, 0x6
    /* 5868 80108068 01000424 */  addiu      $a0, $zero, 0x1
    /* 586C 8010806C 02000624 */  addiu      $a2, $zero, 0x2
    /* 5870 80108070 40010524 */  addiu      $a1, $zero, 0x140
    /* 5874 80108074 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 5878 80108078 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 587C 8010807C 34004324 */  addiu      $v1, $v0, 0x34
  .L80108080:
    /* 5880 80108080 000066A0 */  sb         $a2, 0x0($v1)
    /* 5884 80108084 080065A4 */  sh         $a1, 0x8($v1)
    /* 5888 80108088 01008424 */  addiu      $a0, $a0, 0x1
    /* 588C 8010808C 03008228 */  slti       $v0, $a0, 0x3
    /* 5890 80108090 FBFF4014 */  bnez       $v0, .L80108080
    /* 5894 80108094 34006324 */   addiu     $v1, $v1, 0x34
    /* 5898 80108098 70200408 */  j          .L801081C0
    /* 589C 8010809C 1180033C */   lui       $v1, %hi(_selectLoadMemoryCardState)
    /* 58A0 801080A0 C113040C */  jal        _fileMenuElementsActive
    /* 58A4 801080A4 00000000 */   nop
    /* 58A8 801080A8 47004010 */  beqz       $v0, .L801081C8
    /* 58AC 801080AC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 58B0 801080B0 73200408 */  j          .L801081CC
    /* 58B4 801080B4 00000000 */   nop
    /* 58B8 801080B8 1180023C */  lui        $v0, %hi(_selectLoadMemoryCardPort)
    /* 58BC 801080BC FFAA4490 */  lbu        $a0, %lo(_selectLoadMemoryCardPort)($v0)
    /* 58C0 801080C0 4D0C040C */  jal        _initSaveFileInfo
    /* 58C4 801080C4 00000000 */   nop
    /* 58C8 801080C8 09004010 */  beqz       $v0, .L801080F0
    /* 58CC 801080CC 1180033C */   lui       $v1, %hi(_selectLoadMemoryCardState)
    /* 58D0 801080D0 04000224 */  addiu      $v0, $zero, 0x4
    /* 58D4 801080D4 FEAA62A0 */  sb         $v0, %lo(_selectLoadMemoryCardState)($v1)
    /* 58D8 801080D8 1180023C */  lui        $v0, %hi(_textTable)
    /* 58DC 801080DC F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 58E0 801080E0 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 58E4 801080E4 3C024224 */  addiu      $v0, $v0, 0x23C
    /* 58E8 801080E8 72200408 */  j          .L801081C8
    /* 58EC 801080EC A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L801080F0:
    /* 58F0 801080F0 21200000 */  addu       $a0, $zero, $zero
    /* 58F4 801080F4 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 58F8 801080F8 40AE438C */  lw         $v1, %lo(_saveFileInfo)($v0)
  .L801080FC:
    /* 58FC 801080FC 00000000 */  nop
    /* 5900 80108100 0400628C */  lw         $v0, 0x4($v1)
    /* 5904 80108104 00000000 */  nop
    /* 5908 80108108 0200422C */  sltiu      $v0, $v0, 0x2
    /* 590C 8010810C 06004010 */  beqz       $v0, .L80108128
    /* 5910 80108110 05000224 */   addiu     $v0, $zero, 0x5
    /* 5914 80108114 01008424 */  addiu      $a0, $a0, 0x1
    /* 5918 80108118 05008228 */  slti       $v0, $a0, 0x5
    /* 591C 8010811C F7FF4014 */  bnez       $v0, .L801080FC
    /* 5920 80108120 80006324 */   addiu     $v1, $v1, 0x80
    /* 5924 80108124 05000224 */  addiu      $v0, $zero, 0x5
  .L80108128:
    /* 5928 80108128 0A008214 */  bne        $a0, $v0, .L80108154
    /* 592C 8010812C 1180023C */   lui       $v0, %hi(_selectLoadMemoryCardPort)
    /* 5930 80108130 1180033C */  lui        $v1, %hi(_selectLoadMemoryCardState)
    /* 5934 80108134 04000224 */  addiu      $v0, $zero, 0x4
    /* 5938 80108138 FEAA62A0 */  sb         $v0, %lo(_selectLoadMemoryCardState)($v1)
    /* 593C 8010813C 1180023C */  lui        $v0, %hi(_textTable)
    /* 5940 80108140 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 5944 80108144 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 5948 80108148 C4054224 */  addiu      $v0, $v0, 0x5C4
    /* 594C 8010814C 72200408 */  j          .L801081C8
    /* 5950 80108150 A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L80108154:
    /* 5954 80108154 FFAA4490 */  lbu        $a0, %lo(_selectLoadMemoryCardPort)($v0)
    /* 5958 80108158 1F1E040C */  jal        _showLoadFilesMenu
    /* 595C 8010815C 00000000 */   nop
    /* 5960 80108160 1180033C */  lui        $v1, %hi(_selectLoadMemoryCardState)
    /* 5964 80108164 07000224 */  addiu      $v0, $zero, 0x7
    /* 5968 80108168 72200408 */  j          .L801081C8
    /* 596C 8010816C FEAA62A0 */   sb        $v0, %lo(_selectLoadMemoryCardState)($v1)
    /* 5970 80108170 1F1E040C */  jal        _showLoadFilesMenu
    /* 5974 80108174 21200000 */   addu      $a0, $zero, $zero
    /* 5978 80108178 21204000 */  addu       $a0, $v0, $zero
    /* 597C 8010817C 13008010 */  beqz       $a0, .L801081CC
    /* 5980 80108180 21100000 */   addu      $v0, $zero, $zero
    /* 5984 80108184 11008104 */  bgez       $a0, .L801081CC
    /* 5988 80108188 01000224 */   addiu     $v0, $zero, 0x1
    /* 598C 8010818C 01000424 */  addiu      $a0, $zero, 0x1
    /* 5990 80108190 02000624 */  addiu      $a2, $zero, 0x2
    /* 5994 80108194 40010524 */  addiu      $a1, $zero, 0x140
    /* 5998 80108198 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 599C 8010819C 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 59A0 801081A0 34004324 */  addiu      $v1, $v0, 0x34
  .L801081A4:
    /* 59A4 801081A4 000066A0 */  sb         $a2, 0x0($v1)
    /* 59A8 801081A8 080065A4 */  sh         $a1, 0x8($v1)
    /* 59AC 801081AC 01008424 */  addiu      $a0, $a0, 0x1
    /* 59B0 801081B0 03008228 */  slti       $v0, $a0, 0x3
    /* 59B4 801081B4 FBFF4014 */  bnez       $v0, .L801081A4
    /* 59B8 801081B8 34006324 */   addiu     $v1, $v1, 0x34
    /* 59BC 801081BC 1180033C */  lui        $v1, %hi(_selectLoadMemoryCardState)
  .L801081C0:
    /* 59C0 801081C0 05000224 */  addiu      $v0, $zero, 0x5
    /* 59C4 801081C4 FEAA62A0 */  sb         $v0, %lo(_selectLoadMemoryCardState)($v1)
  .L801081C8:
    /* 59C8 801081C8 21100000 */  addu       $v0, $zero, $zero
  .L801081CC:
    /* 59CC 801081CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 59D0 801081D0 00000000 */  nop
    /* 59D4 801081D4 0800E003 */  jr         $ra
    /* 59D8 801081D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _selectLoadMemoryCard
