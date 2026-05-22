nonmatching _selectSaveMemoryCard, 0x3F8

glabel _selectSaveMemoryCard
    /* 4670 80106E70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4674 80106E74 0C008010 */  beqz       $a0, .L80106EA8
    /* 4678 80106E78 1000BFAF */   sw        $ra, 0x10($sp)
    /* 467C 80106E7C 21100000 */  addu       $v0, $zero, $zero
    /* 4680 80106E80 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardPort)
    /* 4684 80106E84 EAAA64A0 */  sb         $a0, %lo(_selectSaveMemoryCardPort)($v1)
    /* 4688 80106E88 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
    /* 468C 80106E8C E9AA60A0 */  sb         $zero, %lo(_selectSaveMemoryCardState)($v1)
    /* 4690 80106E90 1180033C */  lui        $v1, %hi(_textTable)
    /* 4694 80106E94 F8AD638C */  lw         $v1, %lo(_textTable)($v1)
    /* 4698 80106E98 1180043C */  lui        $a0, %hi(_memoryCardMessage)
    /* 469C 80106E9C 88016324 */  addiu      $v1, $v1, 0x188
    /* 46A0 80106EA0 961C0408 */  j          .L80107258
    /* 46A4 80106EA4 A4B083AC */   sw        $v1, %lo(_memoryCardMessage)($a0)
  .L80106EA8:
    /* 46A8 80106EA8 1180023C */  lui        $v0, %hi(_selectSaveMemoryCardState)
    /* 46AC 80106EAC E9AA4390 */  lbu        $v1, %lo(_selectSaveMemoryCardState)($v0)
    /* 46B0 80106EB0 00000000 */  nop
    /* 46B4 80106EB4 0800622C */  sltiu      $v0, $v1, 0x8
    /* 46B8 80106EB8 E6004010 */  beqz       $v0, .L80107254
    /* 46BC 80106EBC 1080023C */   lui       $v0, %hi(jtbl_801028F8)
    /* 46C0 80106EC0 F8284224 */  addiu      $v0, $v0, %lo(jtbl_801028F8)
    /* 46C4 80106EC4 80180300 */  sll        $v1, $v1, 2
    /* 46C8 80106EC8 21186200 */  addu       $v1, $v1, $v0
    /* 46CC 80106ECC 0000628C */  lw         $v0, 0x0($v1)
    /* 46D0 80106ED0 00000000 */  nop
    /* 46D4 80106ED4 08004000 */  jr         $v0
    /* 46D8 80106ED8 00000000 */   nop
    /* 46DC 80106EDC 1180053C */  lui        $a1, %hi(_fileMenuElements)
    /* 46E0 80106EE0 1180063C */  lui        $a2, %hi(_selectSaveMemoryCardPort)
    /* 46E4 80106EE4 50AEA524 */  addiu      $a1, $a1, %lo(_fileMenuElements)
    /* 46E8 80106EE8 EAAAC390 */  lbu        $v1, %lo(_selectSaveMemoryCardPort)($a2)
    /* 46EC 80106EEC 02000824 */  addiu      $t0, $zero, 0x2
    /* 46F0 80106EF0 40100300 */  sll        $v0, $v1, 1
    /* 46F4 80106EF4 21104300 */  addu       $v0, $v0, $v1
    /* 46F8 80106EF8 80100200 */  sll        $v0, $v0, 2
    /* 46FC 80106EFC 21104300 */  addu       $v0, $v0, $v1
    /* 4700 80106F00 80100200 */  sll        $v0, $v0, 2
    /* 4704 80106F04 21104500 */  addu       $v0, $v0, $a1
    /* 4708 80106F08 000048A0 */  sb         $t0, 0x0($v0)
    /* 470C 80106F0C EAAAC390 */  lbu        $v1, %lo(_selectSaveMemoryCardPort)($a2)
    /* 4710 80106F10 01000724 */  addiu      $a3, $zero, 0x1
    /* 4714 80106F14 40100300 */  sll        $v0, $v1, 1
    /* 4718 80106F18 21104300 */  addu       $v0, $v0, $v1
    /* 471C 80106F1C 80100200 */  sll        $v0, $v0, 2
    /* 4720 80106F20 21104300 */  addu       $v0, $v0, $v1
    /* 4724 80106F24 80100200 */  sll        $v0, $v0, 2
    /* 4728 80106F28 21104500 */  addu       $v0, $v0, $a1
    /* 472C 80106F2C B4000324 */  addiu      $v1, $zero, 0xB4
    /* 4730 80106F30 080043A4 */  sh         $v1, 0x8($v0)
    /* 4734 80106F34 030047A0 */  sb         $a3, 0x3($v0)
    /* 4738 80106F38 EAAAC390 */  lbu        $v1, %lo(_selectSaveMemoryCardPort)($a2)
    /* 473C 80106F3C 03000424 */  addiu      $a0, $zero, 0x3
    /* 4740 80106F40 23188300 */  subu       $v1, $a0, $v1
    /* 4744 80106F44 40100300 */  sll        $v0, $v1, 1
    /* 4748 80106F48 21104300 */  addu       $v0, $v0, $v1
    /* 474C 80106F4C 80100200 */  sll        $v0, $v0, 2
    /* 4750 80106F50 21104300 */  addu       $v0, $v0, $v1
    /* 4754 80106F54 80100200 */  sll        $v0, $v0, 2
    /* 4758 80106F58 21104500 */  addu       $v0, $v0, $a1
    /* 475C 80106F5C 000048A0 */  sb         $t0, 0x0($v0)
    /* 4760 80106F60 EAAAC390 */  lbu        $v1, %lo(_selectSaveMemoryCardPort)($a2)
    /* 4764 80106F64 1180023C */  lui        $v0, %hi(_selectSaveMemoryCardState)
    /* 4768 80106F68 E9AA47A0 */  sb         $a3, %lo(_selectSaveMemoryCardState)($v0)
    /* 476C 80106F6C 23208300 */  subu       $a0, $a0, $v1
    /* 4770 80106F70 40100400 */  sll        $v0, $a0, 1
    /* 4774 80106F74 21104400 */  addu       $v0, $v0, $a0
    /* 4778 80106F78 80100200 */  sll        $v0, $v0, 2
    /* 477C 80106F7C 21104400 */  addu       $v0, $v0, $a0
    /* 4780 80106F80 80100200 */  sll        $v0, $v0, 2
    /* 4784 80106F84 21104500 */  addu       $v0, $v0, $a1
    /* 4788 80106F88 40010324 */  addiu      $v1, $zero, 0x140
    /* 478C 80106F8C 951C0408 */  j          .L80107254
    /* 4790 80106F90 080043A4 */   sh        $v1, 0x8($v0)
    /* 4794 80106F94 C113040C */  jal        _fileMenuElementsActive
    /* 4798 80106F98 00000000 */   nop
    /* 479C 80106F9C AD004010 */  beqz       $v0, .L80107254
    /* 47A0 80106FA0 1180023C */   lui       $v0, %hi(_selectSaveMemoryCardPort)
    /* 47A4 80106FA4 EAAA4290 */  lbu        $v0, %lo(_selectSaveMemoryCardPort)($v0)
    /* 47A8 80106FA8 02000424 */  addiu      $a0, $zero, 0x2
    /* 47AC 80106FAC 08004414 */  bne        $v0, $a0, .L80106FD0
    /* 47B0 80106FB0 1180023C */   lui       $v0, %hi(_selectSaveMemoryCardState)
    /* 47B4 80106FB4 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 47B8 80106FB8 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 47BC 80106FBC 03000324 */  addiu      $v1, $zero, 0x3
    /* 47C0 80106FC0 680043A0 */  sb         $v1, 0x68($v0)
    /* 47C4 80106FC4 32000324 */  addiu      $v1, $zero, 0x32
    /* 47C8 80106FC8 700043A4 */  sh         $v1, 0x70($v0)
    /* 47CC 80106FCC 1180023C */  lui        $v0, %hi(_selectSaveMemoryCardState)
  .L80106FD0:
    /* 47D0 80106FD0 951C0408 */  j          .L80107254
    /* 47D4 80106FD4 E9AA44A0 */   sb        $a0, %lo(_selectSaveMemoryCardState)($v0)
    /* 47D8 80106FD8 C113040C */  jal        _fileMenuElementsActive
    /* 47DC 80106FDC 00000000 */   nop
    /* 47E0 80106FE0 9C004010 */  beqz       $v0, .L80107254
    /* 47E4 80106FE4 1180023C */   lui       $v0, %hi(_selectSaveMemoryCardPort)
    /* 47E8 80106FE8 EAAA4490 */  lbu        $a0, %lo(_selectSaveMemoryCardPort)($v0)
    /* 47EC 80106FEC F70C040C */  jal        _memcardEventHandler
    /* 47F0 80106FF0 00000000 */   nop
    /* 47F4 80106FF4 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
    /* 47F8 80106FF8 03000224 */  addiu      $v0, $zero, 0x3
    /* 47FC 80106FFC 951C0408 */  j          .L80107254
    /* 4800 80107000 E9AA62A0 */   sb        $v0, %lo(_selectSaveMemoryCardState)($v1)
    /* 4804 80107004 F70C040C */  jal        _memcardEventHandler
    /* 4808 80107008 21200000 */   addu      $a0, $zero, $zero
    /* 480C 8010700C 03004430 */  andi       $a0, $v0, 0x3
    /* 4810 80107010 90008010 */  beqz       $a0, .L80107254
    /* 4814 80107014 02000224 */   addiu     $v0, $zero, 0x2
    /* 4818 80107018 10008210 */  beq        $a0, $v0, .L8010705C
    /* 481C 8010701C 03008228 */   slti      $v0, $a0, 0x3
    /* 4820 80107020 05004010 */  beqz       $v0, .L80107038
    /* 4824 80107024 01000224 */   addiu     $v0, $zero, 0x1
    /* 4828 80107028 08008210 */  beq        $a0, $v0, .L8010704C
    /* 482C 8010702C 21100000 */   addu      $v0, $zero, $zero
    /* 4830 80107030 961C0408 */  j          .L80107258
    /* 4834 80107034 00000000 */   nop
  .L80107038:
    /* 4838 80107038 03000224 */  addiu      $v0, $zero, 0x3
    /* 483C 8010703C 10008210 */  beq        $a0, $v0, .L80107080
    /* 4840 80107040 1180023C */   lui       $v0, %hi(_saveFileInfo)
    /* 4844 80107044 961C0408 */  j          .L80107258
    /* 4848 80107048 21100000 */   addu      $v0, $zero, $zero
  .L8010704C:
    /* 484C 8010704C 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
    /* 4850 80107050 06000224 */  addiu      $v0, $zero, 0x6
    /* 4854 80107054 951C0408 */  j          .L80107254
    /* 4858 80107058 E9AA62A0 */   sb        $v0, %lo(_selectSaveMemoryCardState)($v1)
  .L8010705C:
    /* 485C 8010705C 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
    /* 4860 80107060 04000224 */  addiu      $v0, $zero, 0x4
    /* 4864 80107064 E9AA62A0 */  sb         $v0, %lo(_selectSaveMemoryCardState)($v1)
    /* 4868 80107068 1180023C */  lui        $v0, %hi(_textTable)
    /* 486C 8010706C F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4870 80107070 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4874 80107074 C6014224 */  addiu      $v0, $v0, 0x1C6
    /* 4878 80107078 951C0408 */  j          .L80107254
    /* 487C 8010707C A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L80107080:
    /* 4880 80107080 40AE448C */  lw         $a0, %lo(_saveFileInfo)($v0)
    /* 4884 80107084 21280000 */  addu       $a1, $zero, $zero
    /* 4888 80107088 AD9B000C */  jal        memset
    /* 488C 8010708C 80020624 */   addiu     $a2, $zero, 0x280
    /* 4890 80107090 0E000424 */  addiu      $a0, $zero, 0xE
    /* 4894 80107094 1180023C */  lui        $v0, %hi(_memcardFiles)
    /* 4898 80107098 00AE4224 */  addiu      $v0, $v0, %lo(_memcardFiles)
    /* 489C 8010709C 38004224 */  addiu      $v0, $v0, 0x38
  .L801070A0:
    /* 48A0 801070A0 000040AC */  sw         $zero, 0x0($v0)
    /* 48A4 801070A4 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 48A8 801070A8 FDFF8104 */  bgez       $a0, .L801070A0
    /* 48AC 801070AC FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 48B0 801070B0 01000324 */  addiu      $v1, $zero, 0x1
    /* 48B4 801070B4 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 48B8 801070B8 40AE428C */  lw         $v0, %lo(_saveFileInfo)($v0)
    /* 48BC 801070BC 04000424 */  addiu      $a0, $zero, 0x4
    /* 48C0 801070C0 00024224 */  addiu      $v0, $v0, 0x200
  .L801070C4:
    /* 48C4 801070C4 040043AC */  sw         $v1, 0x4($v0)
    /* 48C8 801070C8 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 48CC 801070CC FDFF8104 */  bgez       $a0, .L801070C4
    /* 48D0 801070D0 80FF4224 */   addiu     $v0, $v0, -0x80
    /* 48D4 801070D4 781C0408 */  j          .L801071E0
    /* 48D8 801070D8 1180023C */   lui       $v0, %hi(_selectSaveMemoryCardPort)
    /* 48DC 801070DC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 48E0 801070E0 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 48E4 801070E4 00000000 */  nop
    /* 48E8 801070E8 5A004010 */  beqz       $v0, .L80107254
    /* 48EC 801070EC 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 48F0 801070F0 6216010C */  jal        vs_main_playSfxDefault
    /* 48F4 801070F4 06000524 */   addiu     $a1, $zero, 0x6
    /* 48F8 801070F8 01000424 */  addiu      $a0, $zero, 0x1
    /* 48FC 801070FC 02000624 */  addiu      $a2, $zero, 0x2
    /* 4900 80107100 40010524 */  addiu      $a1, $zero, 0x140
    /* 4904 80107104 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 4908 80107108 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 490C 8010710C 34004324 */  addiu      $v1, $v0, 0x34
  .L80107110:
    /* 4910 80107110 000066A0 */  sb         $a2, 0x0($v1)
    /* 4914 80107114 080065A4 */  sh         $a1, 0x8($v1)
    /* 4918 80107118 01008424 */  addiu      $a0, $a0, 0x1
    /* 491C 8010711C 03008228 */  slti       $v0, $a0, 0x3
    /* 4920 80107120 FBFF4014 */  bnez       $v0, .L80107110
    /* 4924 80107124 34006324 */   addiu     $v1, $v1, 0x34
    /* 4928 80107128 931C0408 */  j          .L8010724C
    /* 492C 8010712C 1180033C */   lui       $v1, %hi(_selectSaveMemoryCardState)
    /* 4930 80107130 C113040C */  jal        _fileMenuElementsActive
    /* 4934 80107134 00000000 */   nop
    /* 4938 80107138 46004010 */  beqz       $v0, .L80107254
    /* 493C 8010713C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4940 80107140 961C0408 */  j          .L80107258
    /* 4944 80107144 00000000 */   nop
    /* 4948 80107148 1180023C */  lui        $v0, %hi(_selectSaveMemoryCardPort)
    /* 494C 8010714C EAAA4490 */  lbu        $a0, %lo(_selectSaveMemoryCardPort)($v0)
    /* 4950 80107150 4D0C040C */  jal        _initSaveFileInfo
    /* 4954 80107154 00000000 */   nop
    /* 4958 80107158 09004010 */  beqz       $v0, .L80107180
    /* 495C 8010715C 1180033C */   lui       $v1, %hi(_selectSaveMemoryCardState)
    /* 4960 80107160 04000224 */  addiu      $v0, $zero, 0x4
    /* 4964 80107164 E9AA62A0 */  sb         $v0, %lo(_selectSaveMemoryCardState)($v1)
    /* 4968 80107168 1180023C */  lui        $v0, %hi(_textTable)
    /* 496C 8010716C F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4970 80107170 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4974 80107174 3C024224 */  addiu      $v0, $v0, 0x23C
    /* 4978 80107178 951C0408 */  j          .L80107254
    /* 497C 8010717C A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L80107180:
    /* 4980 80107180 21200000 */  addu       $a0, $zero, $zero
    /* 4984 80107184 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 4988 80107188 40AE438C */  lw         $v1, %lo(_saveFileInfo)($v0)
  .L8010718C:
    /* 498C 8010718C 00000000 */  nop
    /* 4990 80107190 0400628C */  lw         $v0, 0x4($v1)
    /* 4994 80107194 00000000 */  nop
    /* 4998 80107198 06004014 */  bnez       $v0, .L801071B4
    /* 499C 8010719C 05000224 */   addiu     $v0, $zero, 0x5
    /* 49A0 801071A0 01008424 */  addiu      $a0, $a0, 0x1
    /* 49A4 801071A4 05008228 */  slti       $v0, $a0, 0x5
    /* 49A8 801071A8 F8FF4014 */  bnez       $v0, .L8010718C
    /* 49AC 801071AC 80006324 */   addiu     $v1, $v1, 0x80
    /* 49B0 801071B0 05000224 */  addiu      $v0, $zero, 0x5
  .L801071B4:
    /* 49B4 801071B4 0A008214 */  bne        $a0, $v0, .L801071E0
    /* 49B8 801071B8 1180023C */   lui       $v0, %hi(_selectSaveMemoryCardPort)
    /* 49BC 801071BC 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
    /* 49C0 801071C0 04000224 */  addiu      $v0, $zero, 0x4
    /* 49C4 801071C4 E9AA62A0 */  sb         $v0, %lo(_selectSaveMemoryCardState)($v1)
    /* 49C8 801071C8 1180023C */  lui        $v0, %hi(_textTable)
    /* 49CC 801071CC F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 49D0 801071D0 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 49D4 801071D4 E2054224 */  addiu      $v0, $v0, 0x5E2
    /* 49D8 801071D8 951C0408 */  j          .L80107254
    /* 49DC 801071DC A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L801071E0:
    /* 49E0 801071E0 EAAA4490 */  lbu        $a0, %lo(_selectSaveMemoryCardPort)($v0)
    /* 49E4 801071E4 5519040C */  jal        _showSaveFilesMenu
    /* 49E8 801071E8 00000000 */   nop
    /* 49EC 801071EC 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
    /* 49F0 801071F0 07000224 */  addiu      $v0, $zero, 0x7
    /* 49F4 801071F4 951C0408 */  j          .L80107254
    /* 49F8 801071F8 E9AA62A0 */   sb        $v0, %lo(_selectSaveMemoryCardState)($v1)
    /* 49FC 801071FC 5519040C */  jal        _showSaveFilesMenu
    /* 4A00 80107200 21200000 */   addu      $a0, $zero, $zero
    /* 4A04 80107204 21204000 */  addu       $a0, $v0, $zero
    /* 4A08 80107208 13008010 */  beqz       $a0, .L80107258
    /* 4A0C 8010720C 21100000 */   addu      $v0, $zero, $zero
    /* 4A10 80107210 11008104 */  bgez       $a0, .L80107258
    /* 4A14 80107214 01000224 */   addiu     $v0, $zero, 0x1
    /* 4A18 80107218 01000424 */  addiu      $a0, $zero, 0x1
    /* 4A1C 8010721C 02000624 */  addiu      $a2, $zero, 0x2
    /* 4A20 80107220 40010524 */  addiu      $a1, $zero, 0x140
    /* 4A24 80107224 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 4A28 80107228 50AE4224 */  addiu      $v0, $v0, %lo(_fileMenuElements)
    /* 4A2C 8010722C 34004324 */  addiu      $v1, $v0, 0x34
  .L80107230:
    /* 4A30 80107230 000066A0 */  sb         $a2, 0x0($v1)
    /* 4A34 80107234 080065A4 */  sh         $a1, 0x8($v1)
    /* 4A38 80107238 01008424 */  addiu      $a0, $a0, 0x1
    /* 4A3C 8010723C 03008228 */  slti       $v0, $a0, 0x3
    /* 4A40 80107240 FBFF4014 */  bnez       $v0, .L80107230
    /* 4A44 80107244 34006324 */   addiu     $v1, $v1, 0x34
    /* 4A48 80107248 1180033C */  lui        $v1, %hi(_selectSaveMemoryCardState)
  .L8010724C:
    /* 4A4C 8010724C 05000224 */  addiu      $v0, $zero, 0x5
    /* 4A50 80107250 E9AA62A0 */  sb         $v0, %lo(_selectSaveMemoryCardState)($v1)
  .L80107254:
    /* 4A54 80107254 21100000 */  addu       $v0, $zero, $zero
  .L80107258:
    /* 4A58 80107258 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4A5C 8010725C 00000000 */  nop
    /* 4A60 80107260 0800E003 */  jr         $ra
    /* 4A64 80107264 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _selectSaveMemoryCard
