nonmatching func_80070E64, 0x3E8

glabel func_80070E64
    /* 8664 80070E64 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 8668 80070E68 07000424 */  addiu      $a0, $zero, 0x7
    /* 866C 80070E6C 40000524 */  addiu      $a1, $zero, 0x40
    /* 8670 80070E70 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8674 80070E74 01001124 */  addiu      $s1, $zero, 0x1
    /* 8678 80070E78 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 867C 80070E7C F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 8680 80070E80 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8684 80070E84 21904000 */  addu       $s2, $v0, $zero
    /* 8688 80070E88 21102002 */  addu       $v0, $s1, $zero
    /* 868C 80070E8C 3000BFAF */  sw         $ra, 0x30($sp)
    /* 8690 80070E90 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 8694 80070E94 2800B6AF */  sw         $s6, 0x28($sp)
    /* 8698 80070E98 2400B5AF */  sw         $s5, 0x24($sp)
    /* 869C 80070E9C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 86A0 80070EA0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 86A4 80070EA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 86A8 80070EA8 110042A2 */  sb         $v0, 0x11($s2)
    /* 86AC 80070EAC 02000224 */  addiu      $v0, $zero, 0x2
    /* 86B0 80070EB0 010042A2 */  sb         $v0, 0x1($s2)
    /* 86B4 80070EB4 80000224 */  addiu      $v0, $zero, 0x80
    /* 86B8 80070EB8 050042A2 */  sb         $v0, 0x5($s2)
    /* 86BC 80070EBC 0680023C */  lui        $v0, %hi(D_8006002A)
    /* 86C0 80070EC0 150040A2 */  sb         $zero, 0x15($s2)
    /* 86C4 80070EC4 2A004390 */  lbu        $v1, %lo(D_8006002A)($v0)
    /* 86C8 80070EC8 03001024 */  addiu      $s0, $zero, 0x3
    /* 86CC 80070ECC 190050A2 */  sb         $s0, 0x19($s2)
    /* 86D0 80070ED0 04102302 */  sllv       $v0, $v1, $s1
    /* 86D4 80070ED4 21104300 */  addu       $v0, $v0, $v1
    /* 86D8 80070ED8 21188000 */  addu       $v1, $a0, $zero
    /* 86DC 80070EDC 0DBF010C */  jal        func_8006FC34
    /* 86E0 80070EE0 23986200 */   subu      $s3, $v1, $v0
    /* 86E4 80070EE4 04000424 */  addiu      $a0, $zero, 0x4
    /* 86E8 80070EE8 0DBF010C */  jal        func_8006FC34
    /* 86EC 80070EEC 60000524 */   addiu     $a1, $zero, 0x60
    /* 86F0 80070EF0 04000424 */  addiu      $a0, $zero, 0x4
    /* 86F4 80070EF4 21280000 */  addu       $a1, $zero, $zero
    /* 86F8 80070EF8 2130A000 */  addu       $a2, $a1, $zero
    /* 86FC 80070EFC 2138A000 */  addu       $a3, $a1, $zero
    /* 8700 80070F00 210050A2 */  sb         $s0, 0x21($s2)
    /* 8704 80070F04 ABC0010C */  jal        _setMenuItemClut
    /* 8708 80070F08 390050A2 */   sb        $s0, 0x39($s2)
    /* 870C 80070F0C 07000424 */  addiu      $a0, $zero, 0x7
    /* 8710 80070F10 21280000 */  addu       $a1, $zero, $zero
    /* 8714 80070F14 2130A000 */  addu       $a2, $a1, $zero
    /* 8718 80070F18 ABC0010C */  jal        _setMenuItemClut
    /* 871C 80070F1C 2138A000 */   addu      $a3, $a1, $zero
    /* 8720 80070F20 03000424 */  addiu      $a0, $zero, 0x3
  .L80070F24:
    /* 8724 80070F24 40281100 */  sll        $a1, $s1, 1
    /* 8728 80070F28 01000624 */  addiu      $a2, $zero, 0x1
    /* 872C 80070F2C ABC0010C */  jal        _setMenuItemClut
    /* 8730 80070F30 21388000 */   addu      $a3, $a0, $zero
    /* 8734 80070F34 1C004292 */  lbu        $v0, 0x1C($s2)
    /* 8738 80070F38 01003126 */  addiu      $s1, $s1, 0x1
    /* 873C 80070F3C FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 8740 80070F40 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8744 80070F44 1C0042A2 */   sb        $v0, 0x1C($s2)
    /* 8748 80070F48 0900222A */  slti       $v0, $s1, 0x9
    /* 874C 80070F4C F5FF4014 */  bnez       $v0, .L80070F24
    /* 8750 80070F50 03000424 */   addiu     $a0, $zero, 0x3
    /* 8754 80070F54 01001124 */  addiu      $s1, $zero, 0x1
    /* 8758 80070F58 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 875C 80070F5C F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 8760 80070F60 010040A0 */  sb         $zero, 0x1($v0)
    /* 8764 80070F64 090040A0 */  sb         $zero, 0x9($v0)
    /* 8768 80070F68 110040A0 */  sb         $zero, 0x11($v0)
  .L80070F6C:
    /* 876C 80070F6C 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8770 80070F70 01003126 */   addiu     $s1, $s1, 0x1
    /* 8774 80070F74 0900222A */  slti       $v0, $s1, 0x9
    /* 8778 80070F78 FCFF4014 */  bnez       $v0, .L80070F6C
    /* 877C 80070F7C 0F80023C */   lui       $v0, %hi(_menuItemStates)
    /* 8780 80070F80 21880000 */  addu       $s1, $zero, $zero
    /* 8784 80070F84 F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 8788 80070F88 C0181300 */  sll        $v1, $s3, 3
    /* 878C 80070F8C 21806200 */  addu       $s0, $v1, $v0
    /* 8790 80070F90 21206002 */  addu       $a0, $s3, $zero
  .L80070F94:
    /* 8794 80070F94 40281100 */  sll        $a1, $s1, 1
    /* 8798 80070F98 21300000 */  addu       $a2, $zero, $zero
    /* 879C 80070F9C ABC0010C */  jal        _setMenuItemClut
    /* 87A0 80070FA0 01000724 */   addiu     $a3, $zero, 0x1
    /* 87A4 80070FA4 0400222A */  slti       $v0, $s1, 0x4
    /* 87A8 80070FA8 04004014 */  bnez       $v0, .L80070FBC
    /* 87AC 80070FAC 80111100 */   sll       $v0, $s1, 6
    /* 87B0 80070FB0 03000292 */  lbu        $v0, 0x3($s0)
    /* 87B4 80070FB4 00000000 */  nop
    /* 87B8 80070FB8 F0FF4224 */  addiu      $v0, $v0, -0x10
  .L80070FBC:
    /* 87BC 80070FBC 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 87C0 80070FC0 030002A2 */   sb        $v0, 0x3($s0)
    /* 87C4 80070FC4 01003126 */  addiu      $s1, $s1, 0x1
    /* 87C8 80070FC8 0800222A */  slti       $v0, $s1, 0x8
    /* 87CC 80070FCC F1FF4014 */  bnez       $v0, .L80070F94
    /* 87D0 80070FD0 21206002 */   addu      $a0, $s3, $zero
    /* 87D4 80070FD4 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 87D8 80070FD8 20005724 */  addiu      $s7, $v0, %lo(vs_main_settings)
    /* 87DC 80070FDC 0B001524 */  addiu      $s5, $zero, 0xB
    /* 87E0 80070FE0 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 87E4 80070FE4 F8FD5624 */  addiu      $s6, $v0, %lo(_menuItemStates)
  .L80070FE8:
    /* 87E8 80070FE8 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 87EC 80070FEC 00000000 */   nop
    /* 87F0 80070FF0 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 87F4 80070FF4 38E2438C */  lw         $v1, %lo(vs_main_buttonsState)($v0)
    /* 87F8 80070FF8 00000000 */  nop
    /* 87FC 80070FFC 20086230 */  andi       $v0, $v1, 0x820
    /* 8800 80071000 0C004010 */  beqz       $v0, .L80071034
    /* 8804 80071004 40006230 */   andi      $v0, $v1, 0x40
    /* 8808 80071008 A3A2010C */  jal        _playMenuSelectSfx
    /* 880C 8007100C 00000000 */   nop
    /* 8810 80071010 01006226 */  addiu      $v0, $s3, 0x1
    /* 8814 80071014 01005330 */  andi       $s3, $v0, 0x1
    /* 8818 80071018 0A00F3A2 */  sb         $s3, 0xA($s7)
    /* 881C 8007101C 2F1A010C */  jal        vs_main_setMonoSound
    /* 8820 80071020 21206002 */   addu      $a0, $s3, $zero
    /* 8824 80071024 8C4C000C */  jal        vs_sound_setCdVol
    /* 8828 80071028 7F000424 */   addiu     $a0, $zero, 0x7F
    /* 882C 8007102C 40C40108 */  j          .L80071100
    /* 8830 80071030 02000424 */   addiu     $a0, $zero, 0x2
  .L80071034:
    /* 8834 80071034 05004010 */  beqz       $v0, .L8007104C
    /* 8838 80071038 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 883C 8007103C ACA2010C */  jal        _playMenuLeaveSfx
    /* 8840 80071040 00000000 */   nop
    /* 8844 80071044 40C40108 */  j          .L80071100
    /* 8848 80071048 02000424 */   addiu     $a0, $zero, 0x2
  .L8007104C:
    /* 884C 8007104C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 8850 80071050 00000000 */  nop
    /* 8854 80071054 00514230 */  andi       $v0, $v0, 0x5100
    /* 8858 80071058 E3FF4010 */  beqz       $v0, .L80070FE8
    /* 885C 8007105C 00000000 */   nop
    /* 8860 80071060 9AA2010C */  jal        _playMenuChangeSfx
    /* 8864 80071064 2398B302 */   subu      $s3, $s5, $s3
    /* 8868 80071068 01001124 */  addiu      $s1, $zero, 0x1
    /* 886C 8007106C C0101300 */  sll        $v0, $s3, 3
    /* 8870 80071070 21905600 */  addu       $s2, $v0, $s6
    /* 8874 80071074 2310B302 */  subu       $v0, $s5, $s3
    /* 8878 80071078 C0100200 */  sll        $v0, $v0, 3
    /* 887C 8007107C 21A05600 */  addu       $s4, $v0, $s6
    /* 8880 80071080 21206002 */  addu       $a0, $s3, $zero
  .L80071084:
    /* 8884 80071084 40801100 */  sll        $s0, $s1, 1
    /* 8888 80071088 21280002 */  addu       $a1, $s0, $zero
    /* 888C 8007108C 21300000 */  addu       $a2, $zero, $zero
    /* 8890 80071090 ABC0010C */  jal        _setMenuItemClut
    /* 8894 80071094 01000724 */   addiu     $a3, $zero, 0x1
    /* 8898 80071098 2320B302 */  subu       $a0, $s5, $s3
    /* 889C 8007109C 21280002 */  addu       $a1, $s0, $zero
    /* 88A0 800710A0 01000624 */  addiu      $a2, $zero, 0x1
    /* 88A4 800710A4 ABC0010C */  jal        _setMenuItemClut
    /* 88A8 800710A8 21380000 */   addu      $a3, $zero, $zero
    /* 88AC 800710AC 0400222A */  slti       $v0, $s1, 0x4
    /* 88B0 800710B0 04004014 */  bnez       $v0, .L800710C4
    /* 88B4 800710B4 80111100 */   sll       $v0, $s1, 6
    /* 88B8 800710B8 03004292 */  lbu        $v0, 0x3($s2)
    /* 88BC 800710BC 00000000 */  nop
    /* 88C0 800710C0 F0FF4224 */  addiu      $v0, $v0, -0x10
  .L800710C4:
    /* 88C4 800710C4 030042A2 */  sb         $v0, 0x3($s2)
    /* 88C8 800710C8 03008292 */  lbu        $v0, 0x3($s4)
    /* 88CC 800710CC 00000000 */  nop
    /* 88D0 800710D0 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 88D4 800710D4 030082A2 */  sb         $v0, 0x3($s4)
    /* 88D8 800710D8 07000224 */  addiu      $v0, $zero, 0x7
    /* 88DC 800710DC C2FF2212 */  beq        $s1, $v0, .L80070FE8
    /* 88E0 800710E0 00000000 */   nop
    /* 88E4 800710E4 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 88E8 800710E8 01003126 */   addiu     $s1, $s1, 0x1
    /* 88EC 800710EC 0800222A */  slti       $v0, $s1, 0x8
    /* 88F0 800710F0 E4FF4014 */  bnez       $v0, .L80071084
    /* 88F4 800710F4 21206002 */   addu      $a0, $s3, $zero
    /* 88F8 800710F8 FAC30108 */  j          .L80070FE8
    /* 88FC 800710FC 00000000 */   nop
  .L80071100:
    /* 8900 80071100 0DBF010C */  jal        func_8006FC34
    /* 8904 80071104 21280000 */   addu      $a1, $zero, $zero
    /* 8908 80071108 21200000 */  addu       $a0, $zero, $zero
    /* 890C 8007110C 0DBF010C */  jal        func_8006FC34
    /* 8910 80071110 80000524 */   addiu     $a1, $zero, 0x80
    /* 8914 80071114 01001124 */  addiu      $s1, $zero, 0x1
    /* 8918 80071118 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 891C 8007111C F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 8920 80071120 21804000 */  addu       $s0, $v0, $zero
    /* 8924 80071124 02000224 */  addiu      $v0, $zero, 0x2
    /* 8928 80071128 110002A2 */  sb         $v0, 0x11($s0)
    /* 892C 8007112C 20000224 */  addiu      $v0, $zero, 0x20
    /* 8930 80071130 150002A2 */  sb         $v0, 0x15($s0)
    /* 8934 80071134 21102002 */  addu       $v0, $s1, $zero
    /* 8938 80071138 010002A2 */  sb         $v0, 0x1($s0)
    /* 893C 8007113C 60000224 */  addiu      $v0, $zero, 0x60
    /* 8940 80071140 050002A2 */  sb         $v0, 0x5($s0)
    /* 8944 80071144 03000424 */  addiu      $a0, $zero, 0x3
  .L80071148:
    /* 8948 80071148 40281100 */  sll        $a1, $s1, 1
    /* 894C 8007114C 21308000 */  addu       $a2, $a0, $zero
    /* 8950 80071150 ABC0010C */  jal        _setMenuItemClut
    /* 8954 80071154 01000724 */   addiu     $a3, $zero, 0x1
    /* 8958 80071158 1C000292 */  lbu        $v0, 0x1C($s0)
    /* 895C 8007115C 22000392 */  lbu        $v1, 0x22($s0)
    /* 8960 80071160 04004224 */  addiu      $v0, $v0, 0x4
    /* 8964 80071164 1C0002A2 */  sb         $v0, 0x1C($s0)
    /* 8968 80071168 1800622C */  sltiu      $v0, $v1, 0x18
    /* 896C 8007116C 03004010 */  beqz       $v0, .L8007117C
    /* 8970 80071170 E8FF6224 */   addiu     $v0, $v1, -0x18
    /* 8974 80071174 60C40108 */  j          .L80071180
    /* 8978 80071178 220000A2 */   sb        $zero, 0x22($s0)
  .L8007117C:
    /* 897C 8007117C 220002A2 */  sb         $v0, 0x22($s0)
  .L80071180:
    /* 8980 80071180 3A000392 */  lbu        $v1, 0x3A($s0)
    /* 8984 80071184 00000000 */  nop
    /* 8988 80071188 1800622C */  sltiu      $v0, $v1, 0x18
    /* 898C 8007118C 03004010 */  beqz       $v0, .L8007119C
    /* 8990 80071190 E8FF6224 */   addiu     $v0, $v1, -0x18
    /* 8994 80071194 68C40108 */  j          .L800711A0
    /* 8998 80071198 3A0000A2 */   sb        $zero, 0x3A($s0)
  .L8007119C:
    /* 899C 8007119C 3A0002A2 */  sb         $v0, 0x3A($s0)
  .L800711A0:
    /* 89A0 800711A0 23000292 */  lbu        $v0, 0x23($s0)
    /* 89A4 800711A4 00000000 */  nop
    /* 89A8 800711A8 02004010 */  beqz       $v0, .L800711B4
    /* 89AC 800711AC F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 89B0 800711B0 230002A2 */  sb         $v0, 0x23($s0)
  .L800711B4:
    /* 89B4 800711B4 3B000292 */  lbu        $v0, 0x3B($s0)
    /* 89B8 800711B8 00000000 */  nop
    /* 89BC 800711BC 02004010 */  beqz       $v0, .L800711C8
    /* 89C0 800711C0 F0FF4224 */   addiu     $v0, $v0, -0x10
    /* 89C4 800711C4 3B0002A2 */  sb         $v0, 0x3B($s0)
  .L800711C8:
    /* 89C8 800711C8 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 89CC 800711CC 01003126 */   addiu     $s1, $s1, 0x1
    /* 89D0 800711D0 0900222A */  slti       $v0, $s1, 0x9
    /* 89D4 800711D4 DCFF4014 */  bnez       $v0, .L80071148
    /* 89D8 800711D8 03000424 */   addiu     $a0, $zero, 0x3
    /* 89DC 800711DC 0F80103C */  lui        $s0, %hi(_menuItemStates)
    /* 89E0 800711E0 F8FD1026 */  addiu      $s0, $s0, %lo(_menuItemStates)
    /* 89E4 800711E4 40000224 */  addiu      $v0, $zero, 0x40
    /* 89E8 800711E8 200000A2 */  sb         $zero, 0x20($s0)
    /* 89EC 800711EC 380000A2 */  sb         $zero, 0x38($s0)
    /* 89F0 800711F0 1E0002A2 */  sb         $v0, 0x1E($s0)
    /* 89F4 800711F4 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 89F8 800711F8 1B0002A2 */   sb        $v0, 0x1B($s0)
    /* 89FC 800711FC 80000224 */  addiu      $v0, $zero, 0x80
    /* 8A00 80071200 96C2010C */  jal        _drawAndSyncTitleMenu
    /* 8A04 80071204 1B0002A2 */   sb        $v0, 0x1B($s0)
    /* 8A08 80071208 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 8A0C 8007120C 4FC2010C */  jal        _drawTitleMenu
    /* 8A10 80071210 1B0002A2 */   sb        $v0, 0x1B($s0)
    /* 8A14 80071214 10000224 */  addiu      $v0, $zero, 0x10
    /* 8A18 80071218 1F0002A2 */  sb         $v0, 0x1F($s0)
    /* 8A1C 8007121C 190000A2 */  sb         $zero, 0x19($s0)
    /* 8A20 80071220 3000BF8F */  lw         $ra, 0x30($sp)
    /* 8A24 80071224 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 8A28 80071228 2800B68F */  lw         $s6, 0x28($sp)
    /* 8A2C 8007122C 2400B58F */  lw         $s5, 0x24($sp)
    /* 8A30 80071230 2000B48F */  lw         $s4, 0x20($sp)
    /* 8A34 80071234 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8A38 80071238 1800B28F */  lw         $s2, 0x18($sp)
    /* 8A3C 8007123C 1400B18F */  lw         $s1, 0x14($sp)
    /* 8A40 80071240 1000B08F */  lw         $s0, 0x10($sp)
    /* 8A44 80071244 0800E003 */  jr         $ra
    /* 8A48 80071248 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80070E64
