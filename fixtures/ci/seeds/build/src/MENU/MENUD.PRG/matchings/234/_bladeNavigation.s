nonmatching _bladeNavigation, 0x1F4

glabel _bladeNavigation
    /* 1D34 80104534 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1D38 80104538 21288000 */  addu       $a1, $a0, $zero
    /* 1D3C 8010453C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1D40 80104540 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1D44 80104544 1000A010 */  beqz       $a1, .L80104588
    /* 1D48 80104548 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1D4C 8010454C 1180033C */  lui        $v1, %hi(D_80109A37)
    /* 1D50 80104550 03120500 */  sra        $v0, $a1, 8
    /* 1D54 80104554 379A62A0 */  sb         $v0, %lo(D_80109A37)($v1)
    /* 1D58 80104558 FF004430 */  andi       $a0, $v0, 0xFF
    /* 1D5C 8010455C 1180033C */  lui        $v1, %hi(D_80109A38)
    /* 1D60 80104560 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 1D64 80104564 D90F040C */  jal        func_80103F64
    /* 1D68 80104568 389A62A0 */   sb        $v0, %lo(D_80109A38)($v1)
    /* 1D6C 8010456C 21100000 */  addu       $v0, $zero, $zero
    /* 1D70 80104570 1180043C */  lui        $a0, %hi(D_80109A36)
    /* 1D74 80104574 0A000324 */  addiu      $v1, $zero, 0xA
    /* 1D78 80104578 369A83A0 */  sb         $v1, %lo(D_80109A36)($a0)
    /* 1D7C 8010457C 1180033C */  lui        $v1, %hi(D_80109A35)
    /* 1D80 80104580 C5110408 */  j          .L80104714
    /* 1D84 80104584 359A60A0 */   sb        $zero, %lo(D_80109A35)($v1)
  .L80104588:
    /* 1D88 80104588 1180103C */  lui        $s0, %hi(D_80109A35)
    /* 1D8C 8010458C 359A0392 */  lbu        $v1, %lo(D_80109A35)($s0)
    /* 1D90 80104590 01001124 */  addiu      $s1, $zero, 0x1
    /* 1D94 80104594 21007110 */  beq        $v1, $s1, .L8010461C
    /* 1D98 80104598 02006228 */   slti      $v0, $v1, 0x2
    /* 1D9C 8010459C 05004010 */  beqz       $v0, .L801045B4
    /* 1DA0 801045A0 02000224 */   addiu     $v0, $zero, 0x2
    /* 1DA4 801045A4 09006010 */  beqz       $v1, .L801045CC
    /* 1DA8 801045A8 21100000 */   addu      $v0, $zero, $zero
    /* 1DAC 801045AC C5110408 */  j          .L80104714
    /* 1DB0 801045B0 00000000 */   nop
  .L801045B4:
    /* 1DB4 801045B4 23006210 */  beq        $v1, $v0, .L80104644
    /* 1DB8 801045B8 03000224 */   addiu     $v0, $zero, 0x3
    /* 1DBC 801045BC 50006210 */  beq        $v1, $v0, .L80104700
    /* 1DC0 801045C0 21100000 */   addu      $v0, $zero, $zero
    /* 1DC4 801045C4 C5110408 */  j          .L80104714
    /* 1DC8 801045C8 00000000 */   nop
  .L801045CC:
    /* 1DCC 801045CC 74EA030C */  jal        vs_mainmenu_ready
    /* 1DD0 801045D0 00000000 */   nop
    /* 1DD4 801045D4 4E004010 */  beqz       $v0, .L80104710
    /* 1DD8 801045D8 1180023C */   lui       $v0, %hi(D_80109A37)
    /* 1DDC 801045DC 379A4490 */  lbu        $a0, %lo(D_80109A37)($v0)
    /* 1DE0 801045E0 0D10040C */  jal        func_80104034
    /* 1DE4 801045E4 03000524 */   addiu     $a1, $zero, 0x3
    /* 1DE8 801045E8 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 1DEC 801045EC 1180023C */  lui        $v0, %hi(D_80109A38)
    /* 1DF0 801045F0 389A4290 */  lbu        $v0, %lo(D_80109A38)($v0)
    /* 1DF4 801045F4 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 1DF8 801045F8 40100200 */  sll        $v0, $v0, 1
    /* 1DFC 801045FC 21186200 */  addu       $v1, $v1, $v0
    /* 1E00 80104600 403C6494 */  lhu        $a0, 0x3C40($v1)
    /* 1E04 80104604 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 1E08 80104608 00000000 */   nop
    /* 1E0C 8010460C 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 1E10 80104610 03000424 */   addiu     $a0, $zero, 0x3
    /* 1E14 80104614 C4110408 */  j          .L80104710
    /* 1E18 80104618 359A11A2 */   sb        $s1, %lo(D_80109A35)($s0)
  .L8010461C:
    /* 1E1C 8010461C 1180033C */  lui        $v1, %hi(D_80109A36)
    /* 1E20 80104620 369A6290 */  lbu        $v0, %lo(D_80109A36)($v1)
    /* 1E24 80104624 00000000 */  nop
    /* 1E28 80104628 03004010 */  beqz       $v0, .L80104638
    /* 1E2C 8010462C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1E30 80104630 C4110408 */  j          .L80104710
    /* 1E34 80104634 369A62A0 */   sb        $v0, %lo(D_80109A36)($v1)
  .L80104638:
    /* 1E38 80104638 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E3C 8010463C C4110408 */  j          .L80104710
    /* 1E40 80104640 359A02A2 */   sb        $v0, %lo(D_80109A35)($s0)
  .L80104644:
    /* 1E44 80104644 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 1E48 80104648 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 1E4C 8010464C 00000000 */  nop
    /* 1E50 80104650 50004230 */  andi       $v0, $v0, 0x50
    /* 1E54 80104654 06004010 */  beqz       $v0, .L80104670
    /* 1E58 80104658 00000000 */   nop
    /* 1E5C 8010465C 5C10040C */  jal        func_80104170
    /* 1E60 80104660 01000424 */   addiu     $a0, $zero, 0x1
    /* 1E64 80104664 03000224 */  addiu      $v0, $zero, 0x3
    /* 1E68 80104668 C4110408 */  j          .L80104710
    /* 1E6C 8010466C 359A02A2 */   sb        $v0, %lo(D_80109A35)($s0)
  .L80104670:
    /* 1E70 80104670 1180103C */  lui        $s0, %hi(D_80109A38)
    /* 1E74 80104674 389A0592 */  lbu        $a1, %lo(D_80109A38)($s0)
    /* 1E78 80104678 5B0F040C */  jal        _pollItemNavigation
    /* 1E7C 8010467C 01000424 */   addiu     $a0, $zero, 0x1
    /* 1E80 80104680 389A0392 */  lbu        $v1, %lo(D_80109A38)($s0)
    /* 1E84 80104684 21884000 */  addu       $s1, $v0, $zero
    /* 1E88 80104688 21002312 */  beq        $s1, $v1, .L80104710
    /* 1E8C 8010468C 01000424 */   addiu     $a0, $zero, 0x1
    /* 1E90 80104690 21282002 */  addu       $a1, $s1, $zero
    /* 1E94 80104694 4510040C */  jal        func_80104114
    /* 1E98 80104698 389A11A2 */   sb        $s1, %lo(D_80109A38)($s0)
    /* 1E9C 8010469C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1EA0 801046A0 1800A627 */  addiu      $a2, $sp, 0x18
    /* 1EA4 801046A4 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 1EA8 801046A8 21804000 */  addu       $s0, $v0, $zero
    /* 1EAC 801046AC 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 1EB0 801046B0 40201000 */  sll        $a0, $s0, 1
    /* 1EB4 801046B4 21209000 */  addu       $a0, $a0, $s0
    /* 1EB8 801046B8 80200400 */  sll        $a0, $a0, 2
    /* 1EBC 801046BC 23209000 */  subu       $a0, $a0, $s0
    /* 1EC0 801046C0 80200400 */  sll        $a0, $a0, 2
    /* 1EC4 801046C4 D4098424 */  addiu      $a0, $a0, 0x9D4
    /* 1EC8 801046C8 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 1ECC 801046CC 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 1ED0 801046D0 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 1ED4 801046D4 21204400 */   addu      $a0, $v0, $a0
    /* 1ED8 801046D8 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 1EDC 801046DC 21200002 */   addu      $a0, $s0, $zero
    /* 1EE0 801046E0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1EE4 801046E4 1180023C */  lui        $v0, %hi(D_80109A37)
    /* 1EE8 801046E8 379A4490 */  lbu        $a0, %lo(D_80109A37)($v0)
    /* 1EEC 801046EC 1800A68F */  lw         $a2, 0x18($sp)
    /* 1EF0 801046F0 1E10040C */  jal        func_80104078
    /* 1EF4 801046F4 21382002 */   addu      $a3, $s1, $zero
    /* 1EF8 801046F8 C5110408 */  j          .L80104714
    /* 1EFC 801046FC 21100000 */   addu      $v0, $zero, $zero
  .L80104700:
    /* 1F00 80104700 74EA030C */  jal        vs_mainmenu_ready
    /* 1F04 80104704 00000000 */   nop
    /* 1F08 80104708 C5110408 */  j          .L80104714
    /* 1F0C 8010470C 00000000 */   nop
  .L80104710:
    /* 1F10 80104710 21100000 */  addu       $v0, $zero, $zero
  .L80104714:
    /* 1F14 80104714 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1F18 80104718 2400B18F */  lw         $s1, 0x24($sp)
    /* 1F1C 8010471C 2000B08F */  lw         $s0, 0x20($sp)
    /* 1F20 80104720 0800E003 */  jr         $ra
    /* 1F24 80104724 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _bladeNavigation
