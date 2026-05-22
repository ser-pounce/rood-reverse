nonmatching func_80104534, 0x334

glabel func_80104534
    /* 1D34 80104534 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1D38 80104538 21188000 */  addu       $v1, $a0, $zero
    /* 1D3C 8010453C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D40 80104540 21880000 */  addu       $s1, $zero, $zero
    /* 1D44 80104544 3400BFAF */  sw         $ra, 0x34($sp)
    /* 1D48 80104548 3000BEAF */  sw         $fp, 0x30($sp)
    /* 1D4C 8010454C 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 1D50 80104550 2800B6AF */  sw         $s6, 0x28($sp)
    /* 1D54 80104554 2400B5AF */  sw         $s5, 0x24($sp)
    /* 1D58 80104558 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1D5C 8010455C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1D60 80104560 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1D64 80104564 0C006010 */  beqz       $v1, .L80104598
    /* 1D68 80104568 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1D6C 8010456C 07007330 */  andi       $s3, $v1, 0x7
    /* 1D70 80104570 F8007230 */  andi       $s2, $v1, 0xF8
    /* 1D74 80104574 0A006426 */  addiu      $a0, $s3, 0xA
    /* 1D78 80104578 1180023C */  lui        $v0, %hi(D_8010BC11)
    /* 1D7C 8010457C 07184302 */  srav       $v1, $v1, $s2
    /* 1D80 80104580 630F040C */  jal        func_80103D8C
    /* 1D84 80104584 11BC43A0 */   sb        $v1, %lo(D_8010BC11)($v0)
    /* 1D88 80104588 21102002 */  addu       $v0, $s1, $zero
    /* 1D8C 8010458C 1180033C */  lui        $v1, %hi(D_8010BC10)
    /* 1D90 80104590 0E120408 */  j          .L80104838
    /* 1D94 80104594 10BC60A0 */   sb        $zero, %lo(D_8010BC10)($v1)
  .L80104598:
    /* 1D98 80104598 1180033C */  lui        $v1, %hi(D_8010BC11)
    /* 1D9C 8010459C 11BC6290 */  lbu        $v0, %lo(D_8010BC11)($v1)
    /* 1DA0 801045A0 00000000 */  nop
    /* 1DA4 801045A4 06004010 */  beqz       $v0, .L801045C0
    /* 1DA8 801045A8 C0180200 */   sll       $v1, $v0, 3
    /* 1DAC 801045AC 23186200 */  subu       $v1, $v1, $v0
    /* 1DB0 801045B0 80180300 */  sll        $v1, $v1, 2
    /* 1DB4 801045B4 0680023C */  lui        $v0, %hi(D_80060A0C)
    /* 1DB8 801045B8 0C0A4224 */  addiu      $v0, $v0, %lo(D_80060A0C)
    /* 1DBC 801045BC 21886200 */  addu       $s1, $v1, $v0
  .L801045C0:
    /* 1DC0 801045C0 1180023C */  lui        $v0, %hi(D_8010BC10)
    /* 1DC4 801045C4 10BC4390 */  lbu        $v1, %lo(D_8010BC10)($v0)
    /* 1DC8 801045C8 01001024 */  addiu      $s0, $zero, 0x1
    /* 1DCC 801045CC 5D007010 */  beq        $v1, $s0, .L80104744
    /* 1DD0 801045D0 02006228 */   slti      $v0, $v1, 0x2
    /* 1DD4 801045D4 05004010 */  beqz       $v0, .L801045EC
    /* 1DD8 801045D8 02000224 */   addiu     $v0, $zero, 0x2
    /* 1DDC 801045DC 07006010 */  beqz       $v1, .L801045FC
    /* 1DE0 801045E0 21100000 */   addu      $v0, $zero, $zero
    /* 1DE4 801045E4 0E120408 */  j          .L80104838
    /* 1DE8 801045E8 00000000 */   nop
  .L801045EC:
    /* 1DEC 801045EC 8A006210 */  beq        $v1, $v0, .L80104818
    /* 1DF0 801045F0 21100000 */   addu      $v0, $zero, $zero
    /* 1DF4 801045F4 0E120408 */  j          .L80104838
    /* 1DF8 801045F8 00000000 */   nop
  .L801045FC:
    /* 1DFC 801045FC 74EA030C */  jal        vs_mainmenu_ready
    /* 1E00 80104600 00000000 */   nop
    /* 1E04 80104604 8C004010 */  beqz       $v0, .L80104838
    /* 1E08 80104608 21100000 */   addu      $v0, $zero, $zero
    /* 1E0C 8010460C 8F0F010C */  jal        vs_main_allocHeapR
    /* 1E10 80104610 AC140424 */   addiu     $a0, $zero, 0x14AC
    /* 1E14 80104614 21B04000 */  addu       $s6, $v0, $zero
    /* 1E18 80104618 0C002016 */  bnez       $s1, .L8010464C
    /* 1E1C 8010461C 2413D726 */   addiu     $s7, $s6, 0x1324
    /* 1E20 80104620 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 1E24 80104624 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 1E28 80104628 00000000 */  nop
    /* 1E2C 8010462C 42086224 */  addiu      $v0, $v1, 0x842
    /* 1E30 80104630 2413C2AE */  sw         $v0, 0x1324($s6)
    /* 1E34 80104634 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1E38 80104638 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1E3C 8010463C 48086324 */  addiu      $v1, $v1, 0x848
    /* 1E40 80104640 0400E3AE */  sw         $v1, 0x4($s7)
    /* 1E44 80104644 99110408 */  j          .L80104664
    /* 1E48 80104648 000050AC */   sw        $s0, 0x0($v0)
  .L8010464C:
    /* 1E4C 8010464C 21202002 */  addu       $a0, $s1, $zero
    /* 1E50 80104650 2128E002 */  addu       $a1, $s7, $zero
    /* 1E54 80104654 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1E58 80104658 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1E5C 8010465C 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 1E60 80104660 2138C002 */   addu      $a3, $s6, $zero
  .L80104664:
    /* 1E64 80104664 01001224 */  addiu      $s2, $zero, 0x1
    /* 1E68 80104668 21980000 */  addu       $s3, $zero, $zero
    /* 1E6C 8010466C 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 1E70 80104670 A4BC7E24 */  addiu      $fp, $v1, %lo(D_8010BCA4)
    /* 1E74 80104674 6000D526 */  addiu      $s5, $s6, 0x60
    /* 1E78 80104678 1180023C */  lui        $v0, %hi(D_8010BC11)
    /* 1E7C 8010467C 11BC4290 */  lbu        $v0, %lo(D_8010BC11)($v0)
    /* 1E80 80104680 0800F426 */  addiu      $s4, $s7, 0x8
    /* 1E84 80104684 A4BC62A0 */  sb         $v0, %lo(D_8010BCA4)($v1)
    /* 1E88 80104688 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L8010468C:
    /* 1E8C 8010468C D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 1E90 80104690 21106802 */  addu       $v0, $s3, $t0
    /* 1E94 80104694 40005090 */  lbu        $s0, 0x40($v0)
    /* 1E98 80104698 00000000 */  nop
    /* 1E9C 8010469C 1A000012 */  beqz       $s0, .L80104708
    /* 1EA0 801046A0 1180023C */   lui       $v0, %hi(D_8010BC11)
    /* 1EA4 801046A4 11BC4290 */  lbu        $v0, %lo(D_8010BC11)($v0)
    /* 1EA8 801046A8 00000000 */  nop
    /* 1EAC 801046AC 16000212 */  beq        $s0, $v0, .L80104708
    /* 1EB0 801046B0 C0101000 */   sll       $v0, $s0, 3
    /* 1EB4 801046B4 23105000 */  subu       $v0, $v0, $s0
    /* 1EB8 801046B8 80100200 */  sll        $v0, $v0, 2
    /* 1EBC 801046BC 0680083C */  lui        $t0, %hi(D_80060A0C)
    /* 1EC0 801046C0 0C0A0825 */  addiu      $t0, $t0, %lo(D_80060A0C)
    /* 1EC4 801046C4 21884800 */  addu       $s1, $v0, $t0
    /* 1EC8 801046C8 18002296 */  lhu        $v0, 0x18($s1)
    /* 1ECC 801046CC 00000000 */  nop
    /* 1ED0 801046D0 0D004014 */  bnez       $v0, .L80104708
    /* 1ED4 801046D4 21202002 */   addu      $a0, $s1, $zero
    /* 1ED8 801046D8 21288002 */  addu       $a1, $s4, $zero
    /* 1EDC 801046DC 2138A002 */  addu       $a3, $s5, $zero
    /* 1EE0 801046E0 6000B526 */  addiu      $s5, $s5, 0x60
    /* 1EE4 801046E4 08009426 */  addiu      $s4, $s4, 0x8
    /* 1EE8 801046E8 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1EEC 801046EC 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1EF0 801046F0 80301200 */  sll        $a2, $s2, 2
    /* 1EF4 801046F4 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 1EF8 801046F8 21304600 */   addu      $a2, $v0, $a2
    /* 1EFC 801046FC 21105E02 */  addu       $v0, $s2, $fp
    /* 1F00 80104700 01005226 */  addiu      $s2, $s2, 0x1
    /* 1F04 80104704 000050A0 */  sb         $s0, 0x0($v0)
  .L80104708:
    /* 1F08 80104708 01007326 */  addiu      $s3, $s3, 0x1
    /* 1F0C 8010470C 3000622A */  slti       $v0, $s3, 0x30
    /* 1F10 80104710 DEFF4014 */  bnez       $v0, .L8010468C
    /* 1F14 80104714 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
    /* 1F18 80104718 21204002 */  addu       $a0, $s2, $zero
    /* 1F1C 8010471C 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1F20 80104720 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1F24 80104724 FF0C040C */  jal        _populateItemsList
    /* 1F28 80104728 2128E002 */   addu      $a1, $s7, $zero
    /* 1F2C 8010472C 180F010C */  jal        vs_main_freeHeapR
    /* 1F30 80104730 2120C002 */   addu      $a0, $s6, $zero
    /* 1F34 80104734 1180033C */  lui        $v1, %hi(D_8010BC10)
    /* 1F38 80104738 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F3C 8010473C 0D120408 */  j          .L80104834
    /* 1F40 80104740 10BC62A0 */   sb        $v0, %lo(D_8010BC10)($v1)
  .L80104744:
    /* 1F44 80104744 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 1F48 80104748 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 1F4C 8010474C 1180053C */  lui        $a1, %hi(D_8010BC9C)
    /* 1F50 80104750 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 1F54 80104754 9CBCA58C */  lw         $a1, %lo(D_8010BC9C)($a1)
    /* 1F58 80104758 A4BC6324 */  addiu      $v1, $v1, %lo(D_8010BCA4)
    /* 1F5C 8010475C 21104500 */  addu       $v0, $v0, $a1
    /* 1F60 80104760 21104300 */  addu       $v0, $v0, $v1
    /* 1F64 80104764 00005090 */  lbu        $s0, 0x0($v0)
    /* 1F68 80104768 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 1F6C 8010476C 08000424 */   addiu     $a0, $zero, 0x8
    /* 1F70 80104770 05000012 */  beqz       $s0, .L80104788
    /* 1F74 80104774 00000000 */   nop
    /* 1F78 80104778 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 1F7C 8010477C 21200002 */   addu      $a0, $s0, $zero
    /* 1F80 80104780 E7110408 */  j          .L8010479C
    /* 1F84 80104784 1180043C */   lui       $a0, %hi(D_8010BC9C)
  .L80104788:
    /* 1F88 80104788 E3EE030C */  jal        func_800FBB8C
    /* 1F8C 8010478C 03000424 */   addiu     $a0, $zero, 0x3
    /* 1F90 80104790 88F4030C */  jal        vs_mainMenu_resetStats
    /* 1F94 80104794 00000000 */   nop
    /* 1F98 80104798 1180043C */  lui        $a0, %hi(D_8010BC9C)
  .L8010479C:
    /* 1F9C 8010479C 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 1FA0 801047A0 1180033C */  lui        $v1, %hi(D_8010BCA0)
    /* 1FA4 801047A4 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 1FA8 801047A8 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 1FAC 801047AC A0BC6590 */  lbu        $a1, %lo(D_8010BCA0)($v1)
    /* 1FB0 801047B0 79FE030C */  jal        vs_mainMenu_printInformation
    /* 1FB4 801047B4 21208200 */   addu      $a0, $a0, $v0
    /* 1FB8 801047B8 820D040C */  jal        func_80103608
    /* 1FBC 801047BC 02000424 */   addiu     $a0, $zero, 0x2
    /* 1FC0 801047C0 780D040C */  jal        func_801035E0
    /* 1FC4 801047C4 1180103C */   lui       $s0, %hi(D_8010BC0C)
    /* 1FC8 801047C8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1FCC 801047CC 19004010 */  beqz       $v0, .L80104834
    /* 1FD0 801047D0 0CBC02AE */   sw        $v0, %lo(D_8010BC0C)($s0)
    /* 1FD4 801047D4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1FD8 801047D8 28000424 */   addiu     $a0, $zero, 0x28
    /* 1FDC 801047DC 0CBC038E */  lw         $v1, %lo(D_8010BC0C)($s0)
    /* 1FE0 801047E0 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1FE4 801047E4 14006210 */  beq        $v1, $v0, .L80104838
    /* 1FE8 801047E8 00000000 */   nop
    /* 1FEC 801047EC 06006018 */  blez       $v1, .L80104808
    /* 1FF0 801047F0 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 1FF4 801047F4 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 1FF8 801047F8 21106200 */  addu       $v0, $v1, $v0
    /* 1FFC 801047FC FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 2000 80104800 00000000 */  nop
    /* 2004 80104804 0CBC02AE */  sw         $v0, %lo(D_8010BC0C)($s0)
  .L80104808:
    /* 2008 80104808 1180033C */  lui        $v1, %hi(D_8010BC10)
    /* 200C 8010480C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2010 80104810 0D120408 */  j          .L80104834
    /* 2014 80104814 10BC62A0 */   sb        $v0, %lo(D_8010BC10)($v1)
  .L80104818:
    /* 2018 80104818 74EA030C */  jal        vs_mainmenu_ready
    /* 201C 8010481C 00000000 */   nop
    /* 2020 80104820 04004010 */  beqz       $v0, .L80104834
    /* 2024 80104824 1180023C */   lui       $v0, %hi(D_8010BC0C)
    /* 2028 80104828 0CBC428C */  lw         $v0, %lo(D_8010BC0C)($v0)
    /* 202C 8010482C 0E120408 */  j          .L80104838
    /* 2030 80104830 00000000 */   nop
  .L80104834:
    /* 2034 80104834 21100000 */  addu       $v0, $zero, $zero
  .L80104838:
    /* 2038 80104838 3400BF8F */  lw         $ra, 0x34($sp)
    /* 203C 8010483C 3000BE8F */  lw         $fp, 0x30($sp)
    /* 2040 80104840 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 2044 80104844 2800B68F */  lw         $s6, 0x28($sp)
    /* 2048 80104848 2400B58F */  lw         $s5, 0x24($sp)
    /* 204C 8010484C 2000B48F */  lw         $s4, 0x20($sp)
    /* 2050 80104850 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2054 80104854 1800B28F */  lw         $s2, 0x18($sp)
    /* 2058 80104858 1400B18F */  lw         $s1, 0x14($sp)
    /* 205C 8010485C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2060 80104860 0800E003 */  jr         $ra
    /* 2064 80104864 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80104534
