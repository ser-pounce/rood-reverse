nonmatching _showSaveFilesMenu, 0x91C

glabel _showSaveFilesMenu
    /* 3D54 80106554 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3D58 80106558 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3D5C 8010655C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3D60 80106560 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3D64 80106564 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D68 80106568 22008010 */  beqz       $a0, .L801065F4
    /* 3D6C 8010656C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3D70 80106570 1180023C */  lui        $v0, %hi(_showSaveFilesMenuPort)
    /* 3D74 80106574 450B040C */  jal        _findCurrentSaveOnActiveMemcard
    /* 3D78 80106578 E5AA44A0 */   sb        $a0, %lo(_showSaveFilesMenuPort)($v0)
    /* 3D7C 8010657C 1180103C */  lui        $s0, %hi(_showSaveFilesMenuFileSlot)
    /* 3D80 80106580 21184000 */  addu       $v1, $v0, $zero
    /* 3D84 80106584 FF006230 */  andi       $v0, $v1, 0xFF
    /* 3D88 80106588 03004010 */  beqz       $v0, .L80106598
    /* 3D8C 8010658C E7AA03A2 */   sb        $v1, %lo(_showSaveFilesMenuFileSlot)($s0)
    /* 3D90 80106590 FFFF6224 */  addiu      $v0, $v1, -0x1
    /* 3D94 80106594 E7AA02A2 */  sb         $v0, %lo(_showSaveFilesMenuFileSlot)($s0)
  .L80106598:
    /* 3D98 80106598 1180043C */  lui        $a0, %hi(_showSaveFilesMenuPage)
    /* 3D9C 8010659C E7AA0592 */  lbu        $a1, %lo(_showSaveFilesMenuFileSlot)($s0)
    /* 3DA0 801065A0 04000224 */  addiu      $v0, $zero, 0x4
    /* 3DA4 801065A4 FF00A330 */  andi       $v1, $a1, 0xFF
    /* 3DA8 801065A8 04006214 */  bne        $v1, $v0, .L801065BC
    /* 3DAC 801065AC E6AA80A0 */   sb        $zero, %lo(_showSaveFilesMenuPage)($a0)
    /* 3DB0 801065B0 02000224 */  addiu      $v0, $zero, 0x2
    /* 3DB4 801065B4 73190408 */  j          .L801065CC
    /* 3DB8 801065B8 E6AA82A0 */   sb        $v0, %lo(_showSaveFilesMenuPage)($a0)
  .L801065BC:
    /* 3DBC 801065BC 04006010 */  beqz       $v1, .L801065D0
    /* 3DC0 801065C0 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 3DC4 801065C4 E6AA82A0 */  sb         $v0, %lo(_showSaveFilesMenuPage)($a0)
    /* 3DC8 801065C8 01000224 */  addiu      $v0, $zero, 0x1
  .L801065CC:
    /* 3DCC 801065CC E7AA02A2 */  sb         $v0, %lo(_showSaveFilesMenuFileSlot)($s0)
  .L801065D0:
    /* 3DD0 801065D0 21100000 */  addu       $v0, $zero, $zero
    /* 3DD4 801065D4 1180043C */  lui        $a0, %hi(_showSaveFilesMenuSaveSuccessful)
    /* 3DD8 801065D8 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 3DDC 801065DC E0AA83AC */  sw         $v1, %lo(_showSaveFilesMenuSaveSuccessful)($a0)
    /* 3DE0 801065E0 1180033C */  lui        $v1, %hi(_showSaveFilesMenuLeaveTimer)
    /* 3DE4 801065E4 E8AA60A0 */  sb         $zero, %lo(_showSaveFilesMenuLeaveTimer)($v1)
    /* 3DE8 801065E8 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 3DEC 801065EC 951B0408 */  j          .L80106E54
    /* 3DF0 801065F0 E4AA60A0 */   sb        $zero, %lo(_showSaveFilesMenuState)($v1)
  .L801065F4:
    /* 3DF4 801065F4 1180023C */  lui        $v0, %hi(_showSaveFilesMenuState)
    /* 3DF8 801065F8 E4AA4390 */  lbu        $v1, %lo(_showSaveFilesMenuState)($v0)
    /* 3DFC 801065FC 00000000 */  nop
    /* 3E00 80106600 0B00622C */  sltiu      $v0, $v1, 0xB
    /* 3E04 80106604 12024010 */  beqz       $v0, .L80106E50
    /* 3E08 80106608 1080023C */   lui       $v0, %hi(jtbl_801028C8)
    /* 3E0C 8010660C C8284224 */  addiu      $v0, $v0, %lo(jtbl_801028C8)
    /* 3E10 80106610 80180300 */  sll        $v1, $v1, 2
    /* 3E14 80106614 21186200 */  addu       $v1, $v1, $v0
    /* 3E18 80106618 0000628C */  lw         $v0, 0x0($v1)
    /* 3E1C 8010661C 00000000 */  nop
    /* 3E20 80106620 08004000 */  jr         $v0
    /* 3E24 80106624 00000000 */   nop
    /* 3E28 80106628 21800000 */  addu       $s0, $zero, $zero
    /* 3E2C 8010662C 1180123C */  lui        $s2, %hi(_saveFileInfo)
    /* 3E30 80106630 4800113C */  lui        $s1, (0x480040 >> 16)
    /* 3E34 80106634 05000426 */  addiu      $a0, $s0, 0x5
  .L80106638:
    /* 3E38 80106638 40002536 */  ori        $a1, $s1, (0x480040 & 0xFFFF)
    /* 3E3C 8010663C 2000063C */  lui        $a2, (0x200100 >> 16)
    /* 3E40 80106640 0001C634 */  ori        $a2, $a2, (0x200100 & 0xFFFF)
    /* 3E44 80106644 6E13040C */  jal        _initFileMenuElement
    /* 3E48 80106648 21380000 */   addu      $a3, $zero, $zero
    /* 3E4C 8010664C 010050A0 */  sb         $s0, 0x1($v0)
    /* 3E50 80106650 40AE438E */  lw         $v1, %lo(_saveFileInfo)($s2)
    /* 3E54 80106654 C0291000 */  sll        $a1, $s0, 7
    /* 3E58 80106658 2118A300 */  addu       $v1, $a1, $v1
    /* 3E5C 8010665C 0400638C */  lw         $v1, 0x4($v1)
    /* 3E60 80106660 00000000 */  nop
    /* 3E64 80106664 0100632C */  sltiu      $v1, $v1, 0x1
    /* 3E68 80106668 050043A0 */  sb         $v1, 0x5($v0)
    /* 3E6C 8010666C 2800033C */  lui        $v1, (0x280000 >> 16)
    /* 3E70 80106670 40AE448E */  lw         $a0, %lo(_saveFileInfo)($s2)
    /* 3E74 80106674 21882302 */  addu       $s1, $s1, $v1
    /* 3E78 80106678 2128A400 */  addu       $a1, $a1, $a0
    /* 3E7C 8010667C 1C00A390 */  lbu        $v1, 0x1C($a1)
    /* 3E80 80106680 01001026 */  addiu      $s0, $s0, 0x1
    /* 3E84 80106684 060043A0 */  sb         $v1, 0x6($v0)
    /* 3E88 80106688 0500022A */  slti       $v0, $s0, 0x5
    /* 3E8C 8010668C EAFF4014 */  bnez       $v0, .L80106638
    /* 3E90 80106690 05000426 */   addiu     $a0, $s0, 0x5
    /* 3E94 80106694 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 3E98 80106698 01000224 */  addiu      $v0, $zero, 0x1
    /* 3E9C 8010669C E4AA62A0 */  sb         $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 3EA0 801066A0 1180043C */  lui        $a0, %hi(_memoryCardMessage)
    /* 3EA4 801066A4 1180023C */  lui        $v0, %hi(_textTable)
    /* 3EA8 801066A8 0680033C */  lui        $v1, %hi(vs_main_buttonsPressed)
    /* 3EAC 801066AC F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 3EB0 801066B0 D0E1638C */  lw         $v1, %lo(vs_main_buttonsPressed)($v1)
    /* 3EB4 801066B4 76024224 */  addiu      $v0, $v0, 0x276
    /* 3EB8 801066B8 40006330 */  andi       $v1, $v1, 0x40
    /* 3EBC 801066BC 08006010 */  beqz       $v1, .L801066E0
    /* 3EC0 801066C0 A4B082AC */   sw        $v0, %lo(_memoryCardMessage)($a0)
    /* 3EC4 801066C4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 3EC8 801066C8 6216010C */  jal        vs_main_playSfxDefault
    /* 3ECC 801066CC 06000524 */   addiu     $a1, $zero, 0x6
    /* 3ED0 801066D0 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 3ED4 801066D4 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 3ED8 801066D8 511B0408 */  j          .L80106D44
    /* 3EDC 801066DC A0B040AC */   sw        $zero, %lo(_selectCursorXy)($v0)
  .L801066E0:
    /* 3EE0 801066E0 21800000 */  addu       $s0, $zero, $zero
    /* 3EE4 801066E4 1180023C */  lui        $v0, %hi(_fileMenuElements)
    /* 3EE8 801066E8 50AE4724 */  addiu      $a3, $v0, %lo(_fileMenuElements)
    /* 3EEC 801066EC 1180063C */  lui        $a2, %hi(_showSaveFilesMenuPage)
    /* 3EF0 801066F0 04010524 */  addiu      $a1, $zero, 0x104
  .L801066F4:
    /* 3EF4 801066F4 2120A700 */  addu       $a0, $a1, $a3
    /* 3EF8 801066F8 E6AAC390 */  lbu        $v1, %lo(_showSaveFilesMenuPage)($a2)
    /* 3EFC 801066FC 040080A0 */  sb         $zero, 0x4($a0)
    /* 3F00 80106700 23180302 */  subu       $v1, $s0, $v1
    /* 3F04 80106704 01001026 */  addiu      $s0, $s0, 0x1
    /* 3F08 80106708 80100300 */  sll        $v0, $v1, 2
    /* 3F0C 8010670C 21104300 */  addu       $v0, $v0, $v1
    /* 3F10 80106710 C0100200 */  sll        $v0, $v0, 3
    /* 3F14 80106714 48004224 */  addiu      $v0, $v0, 0x48
    /* 3F18 80106718 0E0082A4 */  sh         $v0, 0xE($a0)
    /* 3F1C 8010671C 0500022A */  slti       $v0, $s0, 0x5
    /* 3F20 80106720 F4FF4014 */  bnez       $v0, .L801066F4
    /* 3F24 80106724 3400A524 */   addiu     $a1, $a1, 0x34
    /* 3F28 80106728 1180023C */  lui        $v0, %hi(_showSaveFilesMenuFileSlot)
    /* 3F2C 8010672C 1180033C */  lui        $v1, %hi(_showSaveFilesMenuPage)
    /* 3F30 80106730 0680043C */  lui        $a0, %hi(vs_main_buttonsPressed)
    /* 3F34 80106734 E7AA4590 */  lbu        $a1, %lo(_showSaveFilesMenuFileSlot)($v0)
    /* 3F38 80106738 E6AA6390 */  lbu        $v1, %lo(_showSaveFilesMenuPage)($v1)
    /* 3F3C 8010673C D0E1828C */  lw         $v0, %lo(vs_main_buttonsPressed)($a0)
    /* 3F40 80106740 00000000 */  nop
    /* 3F44 80106744 20004230 */  andi       $v0, $v0, 0x20
    /* 3F48 80106748 22004010 */  beqz       $v0, .L801067D4
    /* 3F4C 8010674C 2180A300 */   addu      $s0, $a1, $v1
    /* 3F50 80106750 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 3F54 80106754 40AE438C */  lw         $v1, %lo(_saveFileInfo)($v0)
    /* 3F58 80106758 C0111000 */  sll        $v0, $s0, 7
    /* 3F5C 8010675C 21104300 */  addu       $v0, $v0, $v1
    /* 3F60 80106760 0400428C */  lw         $v0, 0x4($v0)
    /* 3F64 80106764 00000000 */  nop
    /* 3F68 80106768 18004010 */  beqz       $v0, .L801067CC
    /* 3F6C 8010676C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3F70 80106770 6216010C */  jal        vs_main_playSfxDefault
    /* 3F74 80106774 05000524 */   addiu     $a1, $zero, 0x5
    /* 3F78 80106778 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 3F7C 8010677C 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 3F80 80106780 05000326 */  addiu      $v1, $s0, 0x5
    /* 3F84 80106784 40100300 */  sll        $v0, $v1, 1
    /* 3F88 80106788 21104300 */  addu       $v0, $v0, $v1
    /* 3F8C 8010678C 80100200 */  sll        $v0, $v0, 2
    /* 3F90 80106790 21104300 */  addu       $v0, $v0, $v1
    /* 3F94 80106794 80100200 */  sll        $v0, $v0, 2
    /* 3F98 80106798 21104400 */  addu       $v0, $v0, $a0
    /* 3F9C 8010679C 01000324 */  addiu      $v1, $zero, 0x1
    /* 3FA0 801067A0 040043A0 */  sb         $v1, 0x4($v0)
    /* 3FA4 801067A4 1180023C */  lui        $v0, %hi(_showSaveFilesMenuPort)
    /* 3FA8 801067A8 E5AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuPort)($v0)
    /* 3FAC 801067AC 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 3FB0 801067B0 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 3FB4 801067B4 7D14040C */  jal        _memcardMaskedHandler
    /* 3FB8 801067B8 70008424 */   addiu     $a0, $a0, 0x70
    /* 3FBC 801067BC 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 3FC0 801067C0 02000224 */  addiu      $v0, $zero, 0x2
    /* 3FC4 801067C4 941B0408 */  j          .L80106E50
    /* 3FC8 801067C8 E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
  .L801067CC:
    /* 3FCC 801067CC B800030C */  jal        vs_battle_playInvalidSfx
    /* 3FD0 801067D0 00000000 */   nop
  .L801067D4:
    /* 3FD4 801067D4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 3FD8 801067D8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 3FDC 801067DC 00000000 */  nop
    /* 3FE0 801067E0 00104230 */  andi       $v0, $v0, 0x1000
    /* 3FE4 801067E4 0D004010 */  beqz       $v0, .L8010681C
    /* 3FE8 801067E8 1180033C */   lui       $v1, %hi(_showSaveFilesMenuFileSlot)
    /* 3FEC 801067EC E7AA6290 */  lbu        $v0, %lo(_showSaveFilesMenuFileSlot)($v1)
    /* 3FF0 801067F0 00000000 */  nop
    /* 3FF4 801067F4 08004014 */  bnez       $v0, .L80106818
    /* 3FF8 801067F8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 3FFC 801067FC 1180033C */  lui        $v1, %hi(_showSaveFilesMenuPage)
    /* 4000 80106800 E6AA6290 */  lbu        $v0, %lo(_showSaveFilesMenuPage)($v1)
    /* 4004 80106804 00000000 */  nop
    /* 4008 80106808 04004010 */  beqz       $v0, .L8010681C
    /* 400C 8010680C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 4010 80106810 071A0408 */  j          .L8010681C
    /* 4014 80106814 E6AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuPage)($v1)
  .L80106818:
    /* 4018 80106818 E7AA62A0 */  sb         $v0, %lo(_showSaveFilesMenuFileSlot)($v1)
  .L8010681C:
    /* 401C 8010681C 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 4020 80106820 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 4024 80106824 00000000 */  nop
    /* 4028 80106828 00404230 */  andi       $v0, $v0, 0x4000
    /* 402C 8010682C 0E004010 */  beqz       $v0, .L80106868
    /* 4030 80106830 1180043C */   lui       $a0, %hi(_showSaveFilesMenuFileSlot)
    /* 4034 80106834 E7AA8390 */  lbu        $v1, %lo(_showSaveFilesMenuFileSlot)($a0)
    /* 4038 80106838 02000224 */  addiu      $v0, $zero, 0x2
    /* 403C 8010683C 09006214 */  bne        $v1, $v0, .L80106864
    /* 4040 80106840 01006224 */   addiu     $v0, $v1, 0x1
    /* 4044 80106844 1180043C */  lui        $a0, %hi(_showSaveFilesMenuPage)
    /* 4048 80106848 E6AA8390 */  lbu        $v1, %lo(_showSaveFilesMenuPage)($a0)
    /* 404C 8010684C 00000000 */  nop
    /* 4050 80106850 0200622C */  sltiu      $v0, $v1, 0x2
    /* 4054 80106854 04004010 */  beqz       $v0, .L80106868
    /* 4058 80106858 01006224 */   addiu     $v0, $v1, 0x1
    /* 405C 8010685C 1A1A0408 */  j          .L80106868
    /* 4060 80106860 E6AA82A0 */   sb        $v0, %lo(_showSaveFilesMenuPage)($a0)
  .L80106864:
    /* 4064 80106864 E7AA82A0 */  sb         $v0, %lo(_showSaveFilesMenuFileSlot)($a0)
  .L80106868:
    /* 4068 80106868 1180113C */  lui        $s1, %hi(_showSaveFilesMenuFileSlot)
    /* 406C 8010686C 1180023C */  lui        $v0, %hi(_showSaveFilesMenuPage)
    /* 4070 80106870 E7AA2392 */  lbu        $v1, %lo(_showSaveFilesMenuFileSlot)($s1)
    /* 4074 80106874 E6AA4290 */  lbu        $v0, %lo(_showSaveFilesMenuPage)($v0)
    /* 4078 80106878 00000000 */  nop
    /* 407C 8010687C 21186200 */  addu       $v1, $v1, $v0
    /* 4080 80106880 03000312 */  beq        $s0, $v1, .L80106890
    /* 4084 80106884 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4088 80106888 6216010C */  jal        vs_main_playSfxDefault
    /* 408C 8010688C 04000524 */   addiu     $a1, $zero, 0x4
  .L80106890:
    /* 4090 80106890 E7AA2392 */  lbu        $v1, %lo(_showSaveFilesMenuFileSlot)($s1)
    /* 4094 80106894 1180043C */  lui        $a0, %hi(_selectCursorXy)
    /* 4098 80106898 80100300 */  sll        $v0, $v1, 2
    /* 409C 8010689C 21104300 */  addu       $v0, $v0, $v1
    /* 40A0 801068A0 C0100200 */  sll        $v0, $v0, 3
    /* 40A4 801068A4 3E004224 */  addiu      $v0, $v0, 0x3E
    /* 40A8 801068A8 00140200 */  sll        $v0, $v0, 16
    /* 40AC 801068AC 18004234 */  ori        $v0, $v0, 0x18
    /* 40B0 801068B0 A0B082AC */  sw         $v0, %lo(_selectCursorXy)($a0)
    /* 40B4 801068B4 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 40B8 801068B8 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 40BC 801068BC 05000326 */  addiu      $v1, $s0, 0x5
    /* 40C0 801068C0 40100300 */  sll        $v0, $v1, 1
    /* 40C4 801068C4 21104300 */  addu       $v0, $v0, $v1
    /* 40C8 801068C8 80100200 */  sll        $v0, $v0, 2
    /* 40CC 801068CC 21104300 */  addu       $v0, $v0, $v1
    /* 40D0 801068D0 80100200 */  sll        $v0, $v0, 2
    /* 40D4 801068D4 21104400 */  addu       $v0, $v0, $a0
    /* 40D8 801068D8 01000324 */  addiu      $v1, $zero, 0x1
    /* 40DC 801068DC 941B0408 */  j          .L80106E50
    /* 40E0 801068E0 040043A0 */   sb        $v1, 0x4($v0)
    /* 40E4 801068E4 7D14040C */  jal        _memcardMaskedHandler
    /* 40E8 801068E8 21200000 */   addu      $a0, $zero, $zero
    /* 40EC 801068EC 21804000 */  addu       $s0, $v0, $zero
    /* 40F0 801068F0 57010012 */  beqz       $s0, .L80106E50
    /* 40F4 801068F4 1180123C */   lui       $s2, %hi(_memoryCardMessage)
    /* 40F8 801068F8 1180113C */  lui        $s1, %hi(_textTable)
    /* 40FC 801068FC F8AD228E */  lw         $v0, %lo(_textTable)($s1)
    /* 4100 80106900 A4B0438E */  lw         $v1, %lo(_memoryCardMessage)($s2)
    /* 4104 80106904 C4054224 */  addiu      $v0, $v0, 0x5C4
    /* 4108 80106908 08006214 */  bne        $v1, $v0, .L8010692C
    /* 410C 8010690C 1180023C */   lui       $v0, %hi(_showSaveFilesMenuPort)
    /* 4110 80106910 E5AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuPort)($v0)
    /* 4114 80106914 E718040C */  jal        _promptFormat
    /* 4118 80106918 00000000 */   nop
    /* 411C 8010691C 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 4120 80106920 09000224 */  addiu      $v0, $zero, 0x9
    /* 4124 80106924 941B0408 */  j          .L80106E50
    /* 4128 80106928 E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
  .L8010692C:
    /* 412C 8010692C E9000006 */  bltz       $s0, .L80106CD4
    /* 4130 80106930 1180023C */   lui       $v0, %hi(_showSaveFilesMenuFileSlot)
    /* 4134 80106934 1180033C */  lui        $v1, %hi(_showSaveFilesMenuPage)
    /* 4138 80106938 E7AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuFileSlot)($v0)
    /* 413C 8010693C E6AA6290 */  lbu        $v0, %lo(_showSaveFilesMenuPage)($v1)
    /* 4140 80106940 00000000 */  nop
    /* 4144 80106944 21808200 */  addu       $s0, $a0, $v0
    /* 4148 80106948 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 414C 8010694C 40AE438C */  lw         $v1, %lo(_saveFileInfo)($v0)
    /* 4150 80106950 C0111000 */  sll        $v0, $s0, 7
    /* 4154 80106954 21104300 */  addu       $v0, $v0, $v1
    /* 4158 80106958 0400438C */  lw         $v1, 0x4($v0)
    /* 415C 8010695C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4160 80106960 0C006214 */  bne        $v1, $v0, .L80106994
    /* 4164 80106964 1180023C */   lui       $v0, %hi(_showSaveFilesMenuPort)
    /* 4168 80106968 E5AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuPort)($v0)
    /* 416C 8010696C DF0C040C */  jal        _createSaveFile
    /* 4170 80106970 01000526 */   addiu     $a1, $s0, 0x1
    /* 4174 80106974 22014010 */  beqz       $v0, .L80106E00
    /* 4178 80106978 1180023C */   lui       $v0, %hi(_showSaveFilesMenuState)
    /* 417C 8010697C F8AD238E */  lw         $v1, %lo(_textTable)($s1)
    /* 4180 80106980 07000424 */  addiu      $a0, $zero, 0x7
    /* 4184 80106984 E4AA44A0 */  sb         $a0, %lo(_showSaveFilesMenuState)($v0)
    /* 4188 80106988 04026324 */  addiu      $v1, $v1, 0x204
    /* 418C 8010698C 941B0408 */  j          .L80106E50
    /* 4190 80106990 A4B043AE */   sw        $v1, %lo(_memoryCardMessage)($s2)
  .L80106994:
    /* 4194 80106994 B818040C */  jal        _promptOverwrite
    /* 4198 80106998 01000424 */   addiu     $a0, $zero, 0x1
    /* 419C 8010699C 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 41A0 801069A0 03000224 */  addiu      $v0, $zero, 0x3
    /* 41A4 801069A4 941B0408 */  j          .L80106E50
    /* 41A8 801069A8 E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 41AC 801069AC B818040C */  jal        _promptOverwrite
    /* 41B0 801069B0 21200000 */   addu      $a0, $zero, $zero
    /* 41B4 801069B4 21804000 */  addu       $s0, $v0, $zero
    /* 41B8 801069B8 25010012 */  beqz       $s0, .L80106E50
    /* 41BC 801069BC 01000324 */   addiu     $v1, $zero, 0x1
    /* 41C0 801069C0 09000316 */  bne        $s0, $v1, .L801069E8
    /* 41C4 801069C4 1180023C */   lui       $v0, %hi(_showSaveFilesMenuState)
    /* 41C8 801069C8 1180023C */  lui        $v0, %hi(_showSaveFilesMenuPort)
    /* 41CC 801069CC E5AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuPort)($v0)
    /* 41D0 801069D0 7D14040C */  jal        _memcardMaskedHandler
    /* 41D4 801069D4 70008424 */   addiu     $a0, $a0, 0x70
    /* 41D8 801069D8 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 41DC 801069DC 04000224 */  addiu      $v0, $zero, 0x4
    /* 41E0 801069E0 941B0408 */  j          .L80106E50
    /* 41E4 801069E4 E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
  .L801069E8:
    /* 41E8 801069E8 941B0408 */  j          .L80106E50
    /* 41EC 801069EC E4AA43A0 */   sb        $v1, %lo(_showSaveFilesMenuState)($v0)
    /* 41F0 801069F0 7D14040C */  jal        _memcardMaskedHandler
    /* 41F4 801069F4 21200000 */   addu      $a0, $zero, $zero
    /* 41F8 801069F8 21804000 */  addu       $s0, $v0, $zero
    /* 41FC 801069FC 15010012 */  beqz       $s0, .L80106E54
    /* 4200 80106A00 21100000 */   addu      $v0, $zero, $zero
    /* 4204 80106A04 B3000006 */  bltz       $s0, .L80106CD4
    /* 4208 80106A08 1180113C */   lui       $s1, %hi(_dataNotSaved)
    /* 420C 80106A0C ABB03092 */  lbu        $s0, %lo(_dataNotSaved)($s1)
    /* 4210 80106A10 450B040C */  jal        _findCurrentSaveOnActiveMemcard
    /* 4214 80106A14 00000000 */   nop
    /* 4218 80106A18 1180033C */  lui        $v1, %hi(_showSaveFilesMenuFileSlot)
    /* 421C 80106A1C 1180043C */  lui        $a0, %hi(_showSaveFilesMenuPage)
    /* 4220 80106A20 1180063C */  lui        $a2, %hi(_showSaveFilesMenuState)
    /* 4224 80106A24 E7AA6390 */  lbu        $v1, %lo(_showSaveFilesMenuFileSlot)($v1)
    /* 4228 80106A28 E6AA8590 */  lbu        $a1, %lo(_showSaveFilesMenuPage)($a0)
    /* 422C 80106A2C 05000424 */  addiu      $a0, $zero, 0x5
    /* 4230 80106A30 E4AAC4A0 */  sb         $a0, %lo(_showSaveFilesMenuState)($a2)
    /* 4234 80106A34 21186500 */  addu       $v1, $v1, $a1
    /* 4238 80106A38 01006324 */  addiu      $v1, $v1, 0x1
    /* 423C 80106A3C 26104300 */  xor        $v0, $v0, $v1
    /* 4240 80106A40 0100422C */  sltiu      $v0, $v0, 0x1
    /* 4244 80106A44 25800202 */  or         $s0, $s0, $v0
    /* 4248 80106A48 941B0408 */  j          .L80106E50
    /* 424C 80106A4C ABB030A2 */   sb        $s0, %lo(_dataNotSaved)($s1)
    /* 4250 80106A50 1180043C */  lui        $a0, %hi(_showSaveFilesMenuSettingsBackup)
    /* 4254 80106A54 C0AA8424 */  addiu      $a0, $a0, %lo(_showSaveFilesMenuSettingsBackup)
    /* 4258 80106A58 0680113C */  lui        $s1, %hi(vs_main_settings)
    /* 425C 80106A5C 20002526 */  addiu      $a1, $s1, %lo(vs_main_settings)
    /* 4260 80106A60 1180023C */  lui        $v0, %hi(_showSaveFilesMenuFileSlot)
    /* 4264 80106A64 1180033C */  lui        $v1, %hi(_showSaveFilesMenuPage)
    /* 4268 80106A68 E7AA4790 */  lbu        $a3, %lo(_showSaveFilesMenuFileSlot)($v0)
    /* 426C 80106A6C E6AA6290 */  lbu        $v0, %lo(_showSaveFilesMenuPage)($v1)
    /* 4270 80106A70 20000624 */  addiu      $a2, $zero, 0x20
    /* 4274 80106A74 2180E200 */  addu       $s0, $a3, $v0
    /* 4278 80106A78 1180023C */  lui        $v0, %hi(_textTable)
    /* 427C 80106A7C F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 4280 80106A80 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4284 80106A84 F6024224 */  addiu      $v0, $v0, 0x2F6
    /* 4288 80106A88 E70A040C */  jal        _rMemcpy
    /* 428C 80106A8C A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
    /* 4290 80106A90 005C0624 */  addiu      $a2, $zero, 0x5C00
    /* 4294 80106A94 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 4298 80106A98 F0AD458C */  lw         $a1, %lo(_spmcimg)($v0)
    /* 429C 80106A9C 00B80434 */  ori        $a0, $zero, 0xB800
    /* 42A0 80106AA0 2120A400 */  addu       $a0, $a1, $a0
    /* 42A4 80106AA4 E70A040C */  jal        _rMemcpy
    /* 42A8 80106AA8 2128A600 */   addu      $a1, $a1, $a2
    /* 42AC 80106AAC 1180023C */  lui        $v0, %hi(_containerDataEmpty)
    /* 42B0 80106AB0 ACB04290 */  lbu        $v0, %lo(_containerDataEmpty)($v0)
    /* 42B4 80106AB4 00000000 */  nop
    /* 42B8 80106AB8 08004010 */  beqz       $v0, .L80106ADC
    /* 42BC 80106ABC 1180043C */   lui       $a0, %hi(_backupMainSetting)
    /* 42C0 80106AC0 2000228E */  lw         $v0, %lo(vs_main_settings)($s1)
    /* 42C4 80106AC4 00000000 */  nop
    /* 42C8 80106AC8 02190200 */  srl        $v1, $v0, 4
    /* 42CC 80106ACC 01006330 */  andi       $v1, $v1, 0x1
    /* 42D0 80106AD0 10004234 */  ori        $v0, $v0, 0x10
    /* 42D4 80106AD4 ADB083A0 */  sb         $v1, %lo(_backupMainSetting)($a0)
    /* 42D8 80106AD8 200022AE */  sw         $v0, %lo(vs_main_settings)($s1)
  .L80106ADC:
    /* 42DC 80106ADC FA0D040C */  jal        _packageGameSaveData
    /* 42E0 80106AE0 21200002 */   addu      $a0, $s0, $zero
    /* 42E4 80106AE4 1180023C */  lui        $v0, %hi(_showSaveFilesMenuPort)
    /* 42E8 80106AE8 E5AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuPort)($v0)
    /* 42EC 80106AEC 01000226 */  addiu      $v0, $s0, 0x1
    /* 42F0 80106AF0 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 42F4 80106AF4 00240400 */  sll        $a0, $a0, 16
    /* 42F8 80106AF8 1110040C */  jal        _saveFile
    /* 42FC 80106AFC 25204400 */   or        $a0, $v0, $a0
    /* 4300 80106B00 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 4304 80106B04 06000224 */  addiu      $v0, $zero, 0x6
    /* 4308 80106B08 941B0408 */  j          .L80106E50
    /* 430C 80106B0C E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 4310 80106B10 1110040C */  jal        _saveFile
    /* 4314 80106B14 21200000 */   addu      $a0, $zero, $zero
    /* 4318 80106B18 1180133C */  lui        $s3, %hi(_fileProgressCounter)
    /* 431C 80106B1C 4CAE638E */  lw         $v1, %lo(_fileProgressCounter)($s3)
    /* 4320 80106B20 21804000 */  addu       $s0, $v0, $zero
    /* 4324 80106B24 01006324 */  addiu      $v1, $v1, 0x1
    /* 4328 80106B28 C9000012 */  beqz       $s0, .L80106E50
    /* 432C 80106B2C 4CAE63AE */   sw        $v1, %lo(_fileProgressCounter)($s3)
    /* 4330 80106B30 1180023C */  lui        $v0, %hi(_showSaveFilesMenuFileSlot)
    /* 4334 80106B34 1180033C */  lui        $v1, %hi(_showSaveFilesMenuPage)
    /* 4338 80106B38 E7AA4490 */  lbu        $a0, %lo(_showSaveFilesMenuFileSlot)($v0)
    /* 433C 80106B3C E6AA6390 */  lbu        $v1, %lo(_showSaveFilesMenuPage)($v1)
    /* 4340 80106B40 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0x105)
    /* 4344 80106B44 9D1640A0 */  sb         $zero, %lo(vs_main_stateFlags + 0x105)($v0)
    /* 4348 80106B48 37000106 */  bgez       $s0, .L80106C28
    /* 434C 80106B4C 21908300 */   addu      $s2, $a0, $v1
    /* 4350 80106B50 1180023C */  lui        $v0, %hi(_containerDataEmpty)
    /* 4354 80106B54 ACB04290 */  lbu        $v0, %lo(_containerDataEmpty)($v0)
    /* 4358 80106B58 00000000 */  nop
    /* 435C 80106B5C 0A004010 */  beqz       $v0, .L80106B88
    /* 4360 80106B60 0680053C */   lui       $a1, %hi(vs_main_settings)
    /* 4364 80106B64 1180023C */  lui        $v0, %hi(_backupMainSetting)
    /* 4368 80106B68 EFFF0424 */  addiu      $a0, $zero, -0x11
    /* 436C 80106B6C 2000A38C */  lw         $v1, %lo(vs_main_settings)($a1)
    /* 4370 80106B70 ADB04290 */  lbu        $v0, %lo(_backupMainSetting)($v0)
    /* 4374 80106B74 24186400 */  and        $v1, $v1, $a0
    /* 4378 80106B78 01004230 */  andi       $v0, $v0, 0x1
    /* 437C 80106B7C 00110200 */  sll        $v0, $v0, 4
    /* 4380 80106B80 25186200 */  or         $v1, $v1, $v0
    /* 4384 80106B84 2000A3AC */  sw         $v1, %lo(vs_main_settings)($a1)
  .L80106B88:
    /* 4388 80106B88 21280000 */  addu       $a1, $zero, $zero
    /* 438C 80106B8C 80000624 */  addiu      $a2, $zero, 0x80
    /* 4390 80106B90 1180113C */  lui        $s1, %hi(_saveFileInfo)
    /* 4394 80106B94 40AE248E */  lw         $a0, %lo(_saveFileInfo)($s1)
    /* 4398 80106B98 C0811200 */  sll        $s0, $s2, 7
    /* 439C 80106B9C AD9B000C */  jal        memset
    /* 43A0 80106BA0 21209000 */   addu      $a0, $a0, $s0
    /* 43A4 80106BA4 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 43A8 80106BA8 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 43AC 80106BAC 05004326 */  addiu      $v1, $s2, 0x5
    /* 43B0 80106BB0 40AE228E */  lw         $v0, %lo(_saveFileInfo)($s1)
    /* 43B4 80106BB4 005C0624 */  addiu      $a2, $zero, 0x5C00
    /* 43B8 80106BB8 21800202 */  addu       $s0, $s0, $v0
    /* 43BC 80106BBC 02000224 */  addiu      $v0, $zero, 0x2
    /* 43C0 80106BC0 040002AE */  sw         $v0, 0x4($s0)
    /* 43C4 80106BC4 40100300 */  sll        $v0, $v1, 1
    /* 43C8 80106BC8 21104300 */  addu       $v0, $v0, $v1
    /* 43CC 80106BCC 80100200 */  sll        $v0, $v0, 2
    /* 43D0 80106BD0 21104300 */  addu       $v0, $v0, $v1
    /* 43D4 80106BD4 80100200 */  sll        $v0, $v0, 2
    /* 43D8 80106BD8 21104400 */  addu       $v0, $v0, $a0
    /* 43DC 80106BDC 060040A0 */  sb         $zero, 0x6($v0)
    /* 43E0 80106BE0 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 43E4 80106BE4 F0AD428C */  lw         $v0, %lo(_spmcimg)($v0)
    /* 43E8 80106BE8 00B80534 */  ori        $a1, $zero, 0xB800
    /* 43EC 80106BEC 21204600 */  addu       $a0, $v0, $a2
    /* 43F0 80106BF0 E70A040C */  jal        _rMemcpy
    /* 43F4 80106BF4 21284500 */   addu      $a1, $v0, $a1
    /* 43F8 80106BF8 0680043C */  lui        $a0, %hi(vs_main_settings)
    /* 43FC 80106BFC 20008424 */  addiu      $a0, $a0, %lo(vs_main_settings)
    /* 4400 80106C00 1180053C */  lui        $a1, %hi(_showSaveFilesMenuSettingsBackup)
    /* 4404 80106C04 C0AAA524 */  addiu      $a1, $a1, %lo(_showSaveFilesMenuSettingsBackup)
    /* 4408 80106C08 20000624 */  addiu      $a2, $zero, 0x20
    /* 440C 80106C0C E70A040C */  jal        _rMemcpy
    /* 4410 80106C10 4CAE60AE */   sw        $zero, %lo(_fileProgressCounter)($s3)
    /* 4414 80106C14 1180023C */  lui        $v0, %hi(_textTable)
    /* 4418 80106C18 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 441C 80106C1C 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 4420 80106C20 341B0408 */  j          .L80106CD0
    /* 4424 80106C24 04024224 */   addiu     $v0, $v0, 0x204
  .L80106C28:
    /* 4428 80106C28 80000624 */  addiu      $a2, $zero, 0x80
    /* 442C 80106C2C 1180023C */  lui        $v0, %hi(_dataNotSaved)
    /* 4430 80106C30 ABB040A0 */  sb         $zero, %lo(_dataNotSaved)($v0)
    /* 4434 80106C34 F0FF0224 */  addiu      $v0, $zero, -0x10
    /* 4438 80106C38 1180113C */  lui        $s1, %hi(_saveFileInfo)
    /* 443C 80106C3C C0811200 */  sll        $s0, $s2, 7
    /* 4440 80106C40 4CAE62AE */  sw         $v0, %lo(_fileProgressCounter)($s3)
    /* 4444 80106C44 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 4448 80106C48 40AE248E */  lw         $a0, %lo(_saveFileInfo)($s1)
    /* 444C 80106C4C F0AD458C */  lw         $a1, %lo(_spmcimg)($v0)
    /* 4450 80106C50 21209000 */  addu       $a0, $a0, $s0
    /* 4454 80106C54 E70A040C */  jal        _rMemcpy
    /* 4458 80106C58 8001A524 */   addiu     $a1, $a1, 0x180
    /* 445C 80106C5C 40AE258E */  lw         $a1, %lo(_saveFileInfo)($s1)
    /* 4460 80106C60 7C000624 */  addiu      $a2, $zero, 0x7C
    /* 4464 80106C64 21280502 */  addu       $a1, $s0, $a1
    /* 4468 80106C68 0000A48C */  lw         $a0, 0x0($a1)
    /* 446C 80106C6C AF0B040C */  jal        _decode
    /* 4470 80106C70 0400A524 */   addiu     $a1, $a1, 0x4
    /* 4474 80106C74 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 4478 80106C78 08000524 */  addiu      $a1, $zero, 0x8
    /* 447C 80106C7C 1180063C */  lui        $a2, %hi(_fileMenuElements)
    /* 4480 80106C80 50AEC624 */  addiu      $a2, $a2, %lo(_fileMenuElements)
    /* 4484 80106C84 05004326 */  addiu      $v1, $s2, 0x5
    /* 4488 80106C88 40100300 */  sll        $v0, $v1, 1
    /* 448C 80106C8C 21104300 */  addu       $v0, $v0, $v1
    /* 4490 80106C90 80100200 */  sll        $v0, $v0, 2
    /* 4494 80106C94 21104300 */  addu       $v0, $v0, $v1
    /* 4498 80106C98 40AE238E */  lw         $v1, %lo(_saveFileInfo)($s1)
    /* 449C 80106C9C 80100200 */  sll        $v0, $v0, 2
    /* 44A0 80106CA0 21800302 */  addu       $s0, $s0, $v1
    /* 44A4 80106CA4 1C000392 */  lbu        $v1, 0x1C($s0)
    /* 44A8 80106CA8 21104600 */  addu       $v0, $v0, $a2
    /* 44AC 80106CAC 6216010C */  jal        vs_main_playSfxDefault
    /* 44B0 80106CB0 060043A0 */   sb        $v1, 0x6($v0)
    /* 44B4 80106CB4 1180033C */  lui        $v1, %hi(_showSaveFilesMenuSaveSuccessful)
    /* 44B8 80106CB8 01000224 */  addiu      $v0, $zero, 0x1
    /* 44BC 80106CBC E0AA62AC */  sw         $v0, %lo(_showSaveFilesMenuSaveSuccessful)($v1)
    /* 44C0 80106CC0 1180023C */  lui        $v0, %hi(_textTable)
    /* 44C4 80106CC4 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 44C8 80106CC8 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 44CC 80106CCC 58034224 */  addiu      $v0, $v0, 0x358
  .L80106CD0:
    /* 44D0 80106CD0 A4B062AC */  sw         $v0, %lo(_memoryCardMessage)($v1)
  .L80106CD4:
    /* 44D4 80106CD4 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 44D8 80106CD8 07000224 */  addiu      $v0, $zero, 0x7
    /* 44DC 80106CDC 941B0408 */  j          .L80106E50
    /* 44E0 80106CE0 E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 44E4 80106CE4 1180023C */  lui        $v0, %hi(_showSaveFilesMenuSaveSuccessful)
    /* 44E8 80106CE8 E0AA438C */  lw         $v1, %lo(_showSaveFilesMenuSaveSuccessful)($v0)
    /* 44EC 80106CEC 01000224 */  addiu      $v0, $zero, 0x1
    /* 44F0 80106CF0 07006214 */  bne        $v1, $v0, .L80106D10
    /* 44F4 80106CF4 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 44F8 80106CF8 1180033C */  lui        $v1, %hi(_showSaveFilesMenuLeaveTimer)
    /* 44FC 80106CFC E8AA6290 */  lbu        $v0, %lo(_showSaveFilesMenuLeaveTimer)($v1)
    /* 4500 80106D00 00000000 */  nop
    /* 4504 80106D04 01004224 */  addiu      $v0, $v0, 0x1
    /* 4508 80106D08 E8AA62A0 */  sb         $v0, %lo(_showSaveFilesMenuLeaveTimer)($v1)
    /* 450C 80106D0C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L80106D10:
    /* 4510 80106D10 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 4514 80106D14 00000000 */  nop
    /* 4518 80106D18 07004014 */  bnez       $v0, .L80106D38
    /* 451C 80106D1C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4520 80106D20 1180023C */  lui        $v0, %hi(_showSaveFilesMenuLeaveTimer)
    /* 4524 80106D24 E8AA4390 */  lbu        $v1, %lo(_showSaveFilesMenuLeaveTimer)($v0)
    /* 4528 80106D28 96000224 */  addiu      $v0, $zero, 0x96
    /* 452C 80106D2C 49006214 */  bne        $v1, $v0, .L80106E54
    /* 4530 80106D30 21100000 */   addu      $v0, $zero, $zero
    /* 4534 80106D34 7E000424 */  addiu      $a0, $zero, 0x7E
  .L80106D38:
    /* 4538 80106D38 6216010C */  jal        vs_main_playSfxDefault
    /* 453C 80106D3C 06000524 */   addiu     $a1, $zero, 0x6
    /* 4540 80106D40 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
  .L80106D44:
    /* 4544 80106D44 08000224 */  addiu      $v0, $zero, 0x8
    /* 4548 80106D48 941B0408 */  j          .L80106E50
    /* 454C 80106D4C E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 4550 80106D50 1180023C */  lui        $v0, %hi(_fileProgressCounter)
    /* 4554 80106D54 4CAE428C */  lw         $v0, %lo(_fileProgressCounter)($v0)
    /* 4558 80106D58 00000000 */  nop
    /* 455C 80106D5C 3D004014 */  bnez       $v0, .L80106E54
    /* 4560 80106D60 21100000 */   addu      $v0, $zero, $zero
    /* 4564 80106D64 05001024 */  addiu      $s0, $zero, 0x5
  .L80106D68:
    /* 4568 80106D68 B013040C */  jal        _clearFileMenuElement
    /* 456C 80106D6C 21200002 */   addu      $a0, $s0, $zero
    /* 4570 80106D70 01001026 */  addiu      $s0, $s0, 0x1
    /* 4574 80106D74 0A00022A */  slti       $v0, $s0, 0xA
    /* 4578 80106D78 FBFF4014 */  bnez       $v0, .L80106D68
    /* 457C 80106D7C 1180023C */   lui       $v0, %hi(_showSaveFilesMenuSaveSuccessful)
    /* 4580 80106D80 E0AA428C */  lw         $v0, %lo(_showSaveFilesMenuSaveSuccessful)($v0)
    /* 4584 80106D84 951B0408 */  j          .L80106E54
    /* 4588 80106D88 00000000 */   nop
    /* 458C 80106D8C E718040C */  jal        _promptFormat
    /* 4590 80106D90 21200000 */   addu      $a0, $zero, $zero
    /* 4594 80106D94 21804000 */  addu       $s0, $v0, $zero
    /* 4598 80106D98 2E000012 */  beqz       $s0, .L80106E54
    /* 459C 80106D9C 21100000 */   addu      $v0, $zero, $zero
    /* 45A0 80106DA0 05000106 */  bgez       $s0, .L80106DB8
    /* 45A4 80106DA4 1180043C */   lui       $a0, %hi(_showSaveFilesMenuPort)
    /* 45A8 80106DA8 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 45AC 80106DAC 0A000224 */  addiu      $v0, $zero, 0xA
    /* 45B0 80106DB0 941B0408 */  j          .L80106E50
    /* 45B4 80106DB4 E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
  .L80106DB8:
    /* 45B8 80106DB8 1180023C */  lui        $v0, %hi(_showSaveFilesMenuPage)
    /* 45BC 80106DBC 1180033C */  lui        $v1, %hi(_showSaveFilesMenuFileSlot)
    /* 45C0 80106DC0 E6AA4590 */  lbu        $a1, %lo(_showSaveFilesMenuPage)($v0)
    /* 45C4 80106DC4 E7AA6290 */  lbu        $v0, %lo(_showSaveFilesMenuFileSlot)($v1)
    /* 45C8 80106DC8 E5AA8490 */  lbu        $a0, %lo(_showSaveFilesMenuPort)($a0)
    /* 45CC 80106DCC 2128A200 */  addu       $a1, $a1, $v0
    /* 45D0 80106DD0 DF0C040C */  jal        _createSaveFile
    /* 45D4 80106DD4 0100A524 */   addiu     $a1, $a1, 0x1
    /* 45D8 80106DD8 09004010 */  beqz       $v0, .L80106E00
    /* 45DC 80106DDC 1180033C */   lui       $v1, %hi(_showSaveFilesMenuState)
    /* 45E0 80106DE0 07000224 */  addiu      $v0, $zero, 0x7
    /* 45E4 80106DE4 E4AA62A0 */  sb         $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 45E8 80106DE8 1180023C */  lui        $v0, %hi(_textTable)
    /* 45EC 80106DEC F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 45F0 80106DF0 1180033C */  lui        $v1, %hi(_memoryCardMessage)
    /* 45F4 80106DF4 04024224 */  addiu      $v0, $v0, 0x204
    /* 45F8 80106DF8 941B0408 */  j          .L80106E50
    /* 45FC 80106DFC A4B062AC */   sw        $v0, %lo(_memoryCardMessage)($v1)
  .L80106E00:
    /* 4600 80106E00 1180033C */  lui        $v1, %hi(_showSaveFilesMenuState)
    /* 4604 80106E04 05000224 */  addiu      $v0, $zero, 0x5
    /* 4608 80106E08 941B0408 */  j          .L80106E50
    /* 460C 80106E0C E4AA62A0 */   sb        $v0, %lo(_showSaveFilesMenuState)($v1)
    /* 4610 80106E10 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 4614 80106E14 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 4618 80106E18 00000000 */  nop
    /* 461C 80106E1C 0C004010 */  beqz       $v0, .L80106E50
    /* 4620 80106E20 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 4624 80106E24 6216010C */  jal        vs_main_playSfxDefault
    /* 4628 80106E28 06000524 */   addiu     $a1, $zero, 0x6
    /* 462C 80106E2C 05001024 */  addiu      $s0, $zero, 0x5
  .L80106E30:
    /* 4630 80106E30 B013040C */  jal        _clearFileMenuElement
    /* 4634 80106E34 21200002 */   addu      $a0, $s0, $zero
    /* 4638 80106E38 01001026 */  addiu      $s0, $s0, 0x1
    /* 463C 80106E3C 0A00022A */  slti       $v0, $s0, 0xA
    /* 4640 80106E40 FBFF4014 */  bnez       $v0, .L80106E30
    /* 4644 80106E44 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4648 80106E48 951B0408 */  j          .L80106E54
    /* 464C 80106E4C 00000000 */   nop
  .L80106E50:
    /* 4650 80106E50 21100000 */  addu       $v0, $zero, $zero
  .L80106E54:
    /* 4654 80106E54 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4658 80106E58 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 465C 80106E5C 1800B28F */  lw         $s2, 0x18($sp)
    /* 4660 80106E60 1400B18F */  lw         $s1, 0x14($sp)
    /* 4664 80106E64 1000B08F */  lw         $s0, 0x10($sp)
    /* 4668 80106E68 0800E003 */  jr         $ra
    /* 466C 80106E6C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _showSaveFilesMenu
