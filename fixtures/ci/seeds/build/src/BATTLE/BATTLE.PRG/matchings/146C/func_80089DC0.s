nonmatching func_80089DC0, 0x5A4

glabel func_80089DC0
    /* 215C0 80089DC0 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 215C4 80089DC4 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 215C8 80089DC8 5000B0AF */  sw         $s0, 0x50($sp)
    /* 215CC 80089DCC 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 215D0 80089DD0 6400BFAF */  sw         $ra, 0x64($sp)
    /* 215D4 80089DD4 6000B4AF */  sw         $s4, 0x60($sp)
    /* 215D8 80089DD8 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 215DC 80089DDC 5800B2AF */  sw         $s2, 0x58($sp)
    /* 215E0 80089DE0 5400B1AF */  sw         $s1, 0x54($sp)
    /* 215E4 80089DE4 5800028E */  lw         $v0, 0x58($s0)
    /* 215E8 80089DE8 00000000 */  nop
    /* 215EC 80089DEC 04004014 */  bnez       $v0, .L80089E00
    /* 215F0 80089DF0 00000000 */   nop
    /* 215F4 80089DF4 4927020C */  jal        _loadMpd
    /* 215F8 80089DF8 00000000 */   nop
    /* 215FC 80089DFC 5800028E */  lw         $v0, 0x58($s0)
  .L80089E00:
    /* 21600 80089E00 00000000 */  nop
    /* 21604 80089E04 00004384 */  lh         $v1, 0x0($v0)
    /* 21608 80089E08 04000224 */  addiu      $v0, $zero, 0x4
    /* 2160C 80089E0C 0A006210 */  beq        $v1, $v0, .L80089E38
    /* 21610 80089E10 21880002 */   addu      $s1, $s0, $zero
    /* 21614 80089E14 21804000 */  addu       $s0, $v0, $zero
  .L80089E18:
    /* 21618 80089E18 8709010C */  jal        vs_main_gametimeUpdate
    /* 2161C 80089E1C 21200000 */   addu      $a0, $zero, $zero
    /* 21620 80089E20 5800228E */  lw         $v0, 0x58($s1)
    /* 21624 80089E24 00000000 */  nop
    /* 21628 80089E28 00004284 */  lh         $v0, 0x0($v0)
    /* 2162C 80089E2C 00000000 */  nop
    /* 21630 80089E30 F9FF5014 */  bne        $v0, $s0, .L80089E18
    /* 21634 80089E34 00000000 */   nop
  .L80089E38:
    /* 21638 80089E38 0F80113C */  lui        $s1, %hi(_zoneContext)
    /* 2163C 80089E3C 80183226 */  addiu      $s2, $s1, %lo(_zoneContext)
    /* 21640 80089E40 5800448E */  lw         $a0, 0x58($s2)
    /* 21644 80089E44 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 21648 80089E48 0680103C */   lui       $s0, %hi(D_8005E0C0)
    /* 2164C 80089E4C 0200043C */  lui        $a0, (0x20000 >> 16)
    /* 21650 80089E50 B10F010C */  jal        vs_main_allocHeap
    /* 21654 80089E54 580040AE */   sw        $zero, 0x58($s2)
    /* 21658 80089E58 0200043C */  lui        $a0, (0x20000 >> 16)
    /* 2165C 80089E5C C0E002AE */  sw         $v0, %lo(D_8005E0C0)($s0)
    /* 21660 80089E60 B10F010C */  jal        vs_main_allocHeap
    /* 21664 80089E64 C0E01026 */   addiu     $s0, $s0, %lo(D_8005E0C0)
    /* 21668 80089E68 FE23010C */  jal        vs_main_clutInit
    /* 2166C 80089E6C 040002AE */   sw        $v0, 0x4($s0)
    /* 21670 80089E70 5C00508E */  lw         $s0, 0x5C($s2)
    /* 21674 80089E74 00000000 */  nop
    /* 21678 80089E78 0000028E */  lw         $v0, 0x0($s0)
    /* 2167C 80089E7C 21200000 */  addu       $a0, $zero, $zero
    /* 21680 80089E80 422A020C */  jal        _loadMpdRoomSection
    /* 21684 80089E84 21285000 */   addu      $a1, $v0, $s0
    /* 21688 80089E88 0F80023C */  lui        $v0, %hi(D_800F1AB0)
    /* 2168C 80089E8C B01A4324 */  addiu      $v1, $v0, %lo(D_800F1AB0)
    /* 21690 80089E90 B01A4290 */  lbu        $v0, %lo(D_800F1AB0)($v0)
    /* 21694 80089E94 01006390 */  lbu        $v1, 0x1($v1)
    /* 21698 80089E98 801822AE */  sw         $v0, %lo(_zoneContext)($s1)
    /* 2169C 80089E9C 0035020C */  jal        vs_battle_getCurrentSceneId
    /* 216A0 80089EA0 340043AE */   sw        $v1, 0x34($s2)
    /* 216A4 80089EA4 6800438E */  lw         $v1, 0x68($s2)
    /* 216A8 80089EA8 21204000 */  addu       $a0, $v0, $zero
    /* 216AC 80089EAC 04008310 */  beq        $a0, $v1, .L80089EC0
    /* 216B0 80089EB0 0580023C */   lui       $v0, %hi(D_8005046A)
    /* 216B4 80089EB4 2B23020C */  jal        func_80088CAC
    /* 216B8 80089EB8 680044AE */   sw        $a0, 0x68($s2)
    /* 216BC 80089EBC 0580023C */  lui        $v0, %hi(D_8005046A)
  .L80089EC0:
    /* 216C0 80089EC0 6A044294 */  lhu        $v0, %lo(D_8005046A)($v0)
    /* 216C4 80089EC4 00000000 */  nop
    /* 216C8 80089EC8 04004014 */  bnez       $v0, .L80089EDC
    /* 216CC 80089ECC 0F80033C */   lui       $v1, %hi(D_800F19A0)
    /* 216D0 80089ED0 33EF010C */  jal        func_8007BCCC
    /* 216D4 80089ED4 00000000 */   nop
    /* 216D8 80089ED8 0F80033C */  lui        $v1, %hi(D_800F19A0)
  .L80089EDC:
    /* 216DC 80089EDC 01000224 */  addiu      $v0, $zero, 0x1
    /* 216E0 80089EE0 A01962AC */  sw         $v0, %lo(D_800F19A0)($v1)
    /* 216E4 80089EE4 C32D020C */  jal        _getCollisionMapDimensions
    /* 216E8 80089EE8 21200000 */   addu      $a0, $zero, $zero
    /* 216EC 80089EEC 21204000 */  addu       $a0, $v0, $zero
    /* 216F0 80089EF0 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 216F4 80089EF4 02004104 */  bgez       $v0, .L80089F00
    /* 216F8 80089EF8 00000000 */   nop
    /* 216FC 80089EFC 0F004224 */  addiu      $v0, $v0, 0xF
  .L80089F00:
    /* 21700 80089F00 03110200 */  sra        $v0, $v0, 4
    /* 21704 80089F04 04008104 */  bgez       $a0, .L80089F18
    /* 21708 80089F08 3C0042A6 */   sh        $v0, 0x3C($s2)
    /* 2170C 80089F0C 0F00023C */  lui        $v0, (0xFFFFF >> 16)
    /* 21710 80089F10 FFFF4234 */  ori        $v0, $v0, (0xFFFFF & 0xFFFF)
    /* 21714 80089F14 21208200 */  addu       $a0, $a0, $v0
  .L80089F18:
    /* 21718 80089F18 03150400 */  sra        $v0, $a0, 20
    /* 2171C 80089F1C 3E0042A6 */  sh         $v0, 0x3E($s2)
    /* 21720 80089F20 D12D020C */  jal        _getMapBounds
    /* 21724 80089F24 21200000 */   addu      $a0, $zero, $zero
    /* 21728 80089F28 0D004010 */  beqz       $v0, .L80089F60
    /* 2172C 80089F2C 00000000 */   nop
    /* 21730 80089F30 D12D020C */  jal        _getMapBounds
    /* 21734 80089F34 21200000 */   addu      $a0, $zero, $zero
    /* 21738 80089F38 03004888 */  lwl        $t0, 0x3($v0)
    /* 2173C 80089F3C 00004898 */  lwr        $t0, 0x0($v0)
    /* 21740 80089F40 07004988 */  lwl        $t1, 0x7($v0)
    /* 21744 80089F44 04004998 */  lwr        $t1, 0x4($v0)
    /* 21748 80089F48 430048AA */  swl        $t0, 0x43($s2)
    /* 2174C 80089F4C 400048BA */  swr        $t0, 0x40($s2)
    /* 21750 80089F50 470049AA */  swl        $t1, 0x47($s2)
    /* 21754 80089F54 440049BA */  swr        $t1, 0x44($s2)
    /* 21758 80089F58 DF270208 */  j          .L80089F7C
    /* 2175C 80089F5C 0F80023C */   lui       $v0, %hi(D_800F18C8)
  .L80089F60:
    /* 21760 80089F60 3C004296 */  lhu        $v0, 0x3C($s2)
    /* 21764 80089F64 3E004396 */  lhu        $v1, 0x3E($s2)
    /* 21768 80089F68 420040A6 */  sh         $zero, 0x42($s2)
    /* 2176C 80089F6C 400040A6 */  sh         $zero, 0x40($s2)
    /* 21770 80089F70 440042A6 */  sh         $v0, 0x44($s2)
    /* 21774 80089F74 460043A6 */  sh         $v1, 0x46($s2)
    /* 21778 80089F78 0F80023C */  lui        $v0, %hi(D_800F18C8)
  .L80089F7C:
    /* 2177C 80089F7C C8185224 */  addiu      $s2, $v0, %lo(D_800F18C8)
    /* 21780 80089F80 C81840A4 */  sh         $zero, %lo(D_800F18C8)($v0)
    /* 21784 80089F84 08004226 */  addiu      $v0, $s2, 0x8
    /* 21788 80089F88 020040A6 */  sh         $zero, 0x2($s2)
    /* 2178C 80089F8C 040040A6 */  sh         $zero, 0x4($s2)
    /* 21790 80089F90 080040A6 */  sh         $zero, 0x8($s2)
    /* 21794 80089F94 020040A4 */  sh         $zero, 0x2($v0)
    /* 21798 80089F98 B123010C */  jal        func_80048EC4
    /* 2179C 80089F9C 040040A4 */   sh        $zero, 0x4($v0)
    /* 217A0 80089FA0 2C00028E */  lw         $v0, 0x2C($s0)
    /* 217A4 80089FA4 00000000 */  nop
    /* 217A8 80089FA8 05004010 */  beqz       $v0, .L80089FC0
    /* 217AC 80089FAC 0580113C */   lui       $s1, %hi(vs_main_startState)
    /* 217B0 80089FB0 2800028E */  lw         $v0, 0x28($s0)
    /* 217B4 80089FB4 AA39020C */  jal        _loadMpdLootSection
    /* 217B8 80089FB8 21205000 */   addu      $a0, $v0, $s0
    /* 217BC 80089FBC 0580113C */  lui        $s1, %hi(vs_main_startState)
  .L80089FC0:
    /* 217C0 80089FC0 0800048E */  lw         $a0, 0x8($s0)
    /* 217C4 80089FC4 1800028E */  lw         $v0, 0x18($s0)
    /* 217C8 80089FC8 1000068E */  lw         $a2, 0x10($s0)
    /* 217CC 80089FCC 0C000596 */  lhu        $a1, 0xC($s0)
    /* 217D0 80089FD0 14000796 */  lhu        $a3, 0x14($s0)
    /* 217D4 80089FD4 1C000396 */  lhu        $v1, 0x1C($s0)
    /* 217D8 80089FD8 21105000 */  addu       $v0, $v0, $s0
    /* 217DC 80089FDC 21209000 */  addu       $a0, $a0, $s0
    /* 217E0 80089FE0 2130D000 */  addu       $a2, $a2, $s0
    /* 217E4 80089FE4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 217E8 80089FE8 7004228E */  lw         $v0, %lo(vs_main_startState)($s1)
    /* 217EC 80089FEC FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 217F0 80089FF0 1400A3AF */  sw         $v1, 0x14($sp)
    /* 217F4 80089FF4 01004238 */  xori       $v0, $v0, 0x1
    /* 217F8 80089FF8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 217FC 80089FFC 63FA020C */  jal        _loadMpdClearedScriptDoorSections
    /* 21800 8008A000 1800A2AF */   sw        $v0, 0x18($sp)
    /* 21804 8008A004 01001324 */  addiu      $s3, $zero, 0x1
    /* 21808 8008A008 7004238E */  lw         $v1, %lo(vs_main_startState)($s1)
    /* 2180C 8008A00C 00000000 */  nop
    /* 21810 8008A010 03007314 */  bne        $v1, $s3, .L8008A020
    /* 21814 8008A014 21A04000 */   addu      $s4, $v0, $zero
    /* 21818 8008A018 05000224 */  addiu      $v0, $zero, 0x5
    /* 2181C 8008A01C 700422AE */  sw         $v0, %lo(vs_main_startState)($s1)
  .L8008A020:
    /* 21820 8008A020 2000028E */  lw         $v0, 0x20($s0)
    /* 21824 8008A024 2400058E */  lw         $a1, 0x24($s0)
    /* 21828 8008A028 1727020C */  jal        _loadMpdEnemySection
    /* 2182C 8008A02C 21205000 */   addu      $a0, $v0, $s0
    /* 21830 8008A030 180F010C */  jal        vs_main_freeHeapR
    /* 21834 8008A034 21200002 */   addu      $a0, $s0, $zero
    /* 21838 8008A038 8026020C */  jal        func_80089A00
    /* 2183C 8008A03C 140040AE */   sw        $zero, 0x14($s2)
    /* 21840 8008A040 2226020C */  jal        func_80089888
    /* 21844 8008A044 0F80103C */   lui       $s0, %hi(vs_battle_characterState)
    /* 21848 8008A048 4524020C */  jal        func_80089114
    /* 2184C 8008A04C 00000000 */   nop
    /* 21850 8008A050 6A8D020C */  jal        func_800A35A8
    /* 21854 8008A054 00000000 */   nop
    /* 21858 8008A058 0200033C */  lui        $v1, (0x21000 >> 16)
    /* 2185C 8008A05C 00106334 */  ori        $v1, $v1, (0x21000 & 0xFFFF)
    /* 21860 8008A060 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 21864 8008A064 21200000 */  addu       $a0, $zero, $zero
    /* 21868 8008A068 3C00428C */  lw         $v0, 0x3C($v0)
    /* 2186C 8008A06C 21288000 */  addu       $a1, $a0, $zero
    /* 21870 8008A070 4809468C */  lw         $a2, 0x948($v0)
    /* 21874 8008A074 01000724 */  addiu      $a3, $zero, 0x1
    /* 21878 8008A078 FB4F020C */  jal        func_80093FEC
    /* 2187C 8008A07C 2430C300 */   and       $a2, $a2, $v1
    /* 21880 8008A080 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 21884 8008A084 0200043C */  lui        $a0, (0x21000 >> 16)
    /* 21888 8008A088 3C00458C */  lw         $a1, 0x3C($v0)
    /* 2188C 8008A08C D519020C */  jal        func_80086754
    /* 21890 8008A090 00108434 */   ori       $a0, $a0, (0x21000 & 0xFFFF)
    /* 21894 8008A094 01000424 */  addiu      $a0, $zero, 0x1
    /* 21898 8008A098 0F80023C */  lui        $v0, %hi(D_800F19C8)
    /* 2189C 8008A09C C81940AC */  sw         $zero, %lo(D_800F19C8)($v0)
    /* 218A0 8008A0A0 0F80023C */  lui        $v0, %hi(_firstPersonViewEnabled)
    /* 218A4 8008A0A4 6C1840AC */  sw         $zero, %lo(_firstPersonViewEnabled)($v0)
    /* 218A8 8008A0A8 0F80023C */  lui        $v0, %hi(D_800F1A50)
    /* 218AC 8008A0AC 501A53AC */  sw         $s3, %lo(D_800F1A50)($v0)
    /* 218B0 8008A0B0 0F80023C */  lui        $v0, %hi(D_800F1868)
    /* 218B4 8008A0B4 57F4010C */  jal        func_8007D15C
    /* 218B8 8008A0B8 681840AC */   sw        $zero, %lo(D_800F1868)($v0)
    /* 218BC 8008A0BC 0680023C */  lui        $v0, %hi(D_8005E1D4)
    /* 218C0 8008A0C0 D4E140AC */  sw         $zero, %lo(D_8005E1D4)($v0)
    /* 218C4 8008A0C4 0680023C */  lui        $v0, %hi(D_8005E244)
    /* 218C8 8008A0C8 44E240AC */  sw         $zero, %lo(D_8005E244)($v0)
    /* 218CC 8008A0CC 0680023C */  lui        $v0, %hi(D_8005E1C4)
    /* 218D0 8008A0D0 C4E140AC */  sw         $zero, %lo(D_8005E1C4)($v0)
    /* 218D4 8008A0D4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 218D8 8008A0D8 DCDF40AC */  sw         $zero, %lo(vs_main_buttonRepeat)($v0)
    /* 218DC 8008A0DC 0580023C */  lui        $v0, %hi(vs_main_buttonsReleased)
    /* 218E0 8008A0E0 785C40AC */  sw         $zero, %lo(vs_main_buttonsReleased)($v0)
    /* 218E4 8008A0E4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 218E8 8008A0E8 D0E140AC */  sw         $zero, %lo(vs_main_buttonsPressed)($v0)
    /* 218EC 8008A0EC 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 218F0 8008A0F0 C0E140AC */  sw         $zero, %lo(vs_main_buttonsPreviousState)($v0)
    /* 218F4 8008A0F4 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 218F8 8008A0F8 801F033C */  lui        $v1, (0x1F800064 >> 16)
    /* 218FC 8008A0FC 38E240AC */  sw         $zero, %lo(vs_main_buttonsState)($v0)
    /* 21900 8008A100 00100224 */  addiu      $v0, $zero, 0x1000
    /* 21904 8008A104 640062AC */  sw         $v0, (0x1F800064 & 0xFFFF)($v1)
    /* 21908 8008A108 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionEffect)
    /* 2190C 8008A10C 981A428C */  lw         $v0, %lo(vs_battle_screenTransitionEffect)($v0)
    /* 21910 8008A110 03000324 */  addiu      $v1, $zero, 0x3
    /* 21914 8008A114 05004314 */  bne        $v0, $v1, .L8008A12C
    /* 21918 8008A118 0F80023C */   lui       $v0, %hi(vs_battle_screenTransitionStep)
    /* 2191C 8008A11C 481A40AC */  sw         $zero, %lo(vs_battle_screenTransitionStep)($v0)
    /* 21920 8008A120 0F80023C */  lui        $v0, %hi(vs_battle_screenTransitionAlpha)
    /* 21924 8008A124 4C280208 */  j          .L8008A130
    /* 21928 8008A128 A01A40AC */   sw        $zero, %lo(vs_battle_screenTransitionAlpha)($v0)
  .L8008A12C:
    /* 2192C 8008A12C 481A43AC */  sw         $v1, %lo(vs_battle_screenTransitionStep)($v0)
  .L8008A130:
    /* 21930 8008A130 33F3010C */  jal        vs_battle_setNearClip
    /* 21934 8008A134 40000424 */   addiu     $a0, $zero, 0x40
    /* 21938 8008A138 3CF3010C */  jal        vs_battle_setProjectionDistance
    /* 2193C 8008A13C 00020424 */   addiu     $a0, $zero, 0x200
    /* 21940 8008A140 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 21944 8008A144 D0194524 */  addiu      $a1, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 21948 8008A148 1400A38C */  lw         $v1, 0x14($a1)
    /* 2194C 8008A14C 2000A48C */  lw         $a0, 0x20($a1)
    /* 21950 8008A150 1000A0AC */  sw         $zero, 0x10($a1)
    /* 21954 8008A154 1800A0AC */  sw         $zero, 0x18($a1)
    /* 21958 8008A158 D01943AC */  sw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v0)
    /* 2195C 8008A15C 00060224 */  addiu      $v0, $zero, 0x600
    /* 21960 8008A160 03008214 */  bne        $a0, $v0, .L8008A170
    /* 21964 8008A164 0800A4AC */   sw        $a0, 0x8($a1)
    /* 21968 8008A168 5D280208 */  j          .L8008A174
    /* 2196C 8008A16C 01000224 */   addiu     $v0, $zero, 0x1
  .L8008A170:
    /* 21970 8008A170 03000224 */  addiu      $v0, $zero, 0x3
  .L8008A174:
    /* 21974 8008A174 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 21978 8008A178 0F80023C */  lui        $v0, %hi(vs_battle_cameraCurrentSpherical)
    /* 2197C 8008A17C D0194424 */  addiu      $a0, $v0, %lo(vs_battle_cameraCurrentSpherical)
    /* 21980 8008A180 80FE0224 */  addiu      $v0, $zero, -0x180
    /* 21984 8008A184 040082AC */  sw         $v0, 0x4($a0)
    /* 21988 8008A188 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 2198C 8008A18C 80184524 */  addiu      $a1, $v0, %lo(_zoneContext)
    /* 21990 8008A190 240080AC */  sw         $zero, 0x24($a0)
    /* 21994 8008A194 8018438C */  lw         $v1, %lo(_zoneContext)($v0)
    /* 21998 8008A198 1B000224 */  addiu      $v0, $zero, 0x1B
    /* 2199C 8008A19C 06006214 */  bne        $v1, $v0, .L8008A1B8
    /* 219A0 8008A1A0 01000224 */   addiu     $v0, $zero, 0x1
    /* 219A4 8008A1A4 3400A38C */  lw         $v1, 0x34($a1)
    /* 219A8 8008A1A8 00000000 */  nop
    /* 219AC 8008A1AC 02006214 */  bne        $v1, $v0, .L8008A1B8
    /* 219B0 8008A1B0 80FF0224 */   addiu     $v0, $zero, -0x80
    /* 219B4 8008A1B4 040082AC */  sw         $v0, 0x4($a0)
  .L8008A1B8:
    /* 219B8 8008A1B8 21200000 */  addu       $a0, $zero, $zero
    /* 219BC 8008A1BC 4000B027 */  addiu      $s0, $sp, 0x40
    /* 219C0 8008A1C0 21280002 */  addu       $a1, $s0, $zero
    /* 219C4 8008A1C4 0F80023C */  lui        $v0, %hi(D_800F1908)
    /* 219C8 8008A1C8 4284020C */  jal        func_800A1108
    /* 219CC 8008A1CC 081940AC */   sw        $zero, %lo(D_800F1908)($v0)
    /* 219D0 8008A1D0 FAFF063C */  lui        $a2, (0xFFFA6000 >> 16)
    /* 219D4 8008A1D4 0060C634 */  ori        $a2, $a2, (0xFFFA6000 & 0xFFFF)
    /* 219D8 8008A1D8 2000A427 */  addiu      $a0, $sp, 0x20
    /* 219DC 8008A1DC 3000A527 */  addiu      $a1, $sp, 0x30
    /* 219E0 8008A1E0 4400A287 */  lh         $v0, 0x44($sp)
    /* 219E4 8008A1E4 4600A387 */  lh         $v1, 0x46($sp)
    /* 219E8 8008A1E8 00130200 */  sll        $v0, $v0, 12
    /* 219EC 8008A1EC 001B0300 */  sll        $v1, $v1, 12
    /* 219F0 8008A1F0 2000A2AF */  sw         $v0, 0x20($sp)
    /* 219F4 8008A1F4 4800A287 */  lh         $v0, 0x48($sp)
    /* 219F8 8008A1F8 21186600 */  addu       $v1, $v1, $a2
    /* 219FC 8008A1FC 2400A3AF */  sw         $v1, 0x24($sp)
    /* 21A00 8008A200 00130200 */  sll        $v0, $v0, 12
    /* 21A04 8008A204 7FB6010C */  jal        _clampPositionToZoneBounds
    /* 21A08 8008A208 2800A2AF */   sw        $v0, 0x28($sp)
    /* 21A0C 8008A20C 0F80033C */  lui        $v1, %hi(vs_battle_cameraCurrentSpherical)
    /* 21A10 8008A210 D0196424 */  addiu      $a0, $v1, %lo(vs_battle_cameraCurrentSpherical)
    /* 21A14 8008A214 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 21A18 8008A218 D019638C */  lw         $v1, %lo(vs_battle_cameraCurrentSpherical)($v1)
    /* 21A1C 8008A21C 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* 21A20 8008A220 3000A88F */  lw         $t0, 0x30($sp)
    /* 21A24 8008A224 3400A98F */  lw         $t1, 0x34($sp)
    /* 21A28 8008A228 3800AA8F */  lw         $t2, 0x38($sp)
    /* 21A2C 8008A22C 3C00AB8F */  lw         $t3, 0x3C($sp)
    /* 21A30 8008A230 440048AC */  sw         $t0, 0x44($v0)
    /* 21A34 8008A234 480049AC */  sw         $t1, 0x48($v0)
    /* 21A38 8008A238 4C004AAC */  sw         $t2, 0x4C($v0)
    /* 21A3C 8008A23C 50004BAC */  sw         $t3, 0x50($v0)
    /* 21A40 8008A240 B3EA010C */  jal        _setCameraPositionFromAngles
    /* 21A44 8008A244 580043AC */   sw        $v1, 0x58($v0)
    /* 21A48 8008A248 21200000 */  addu       $a0, $zero, $zero
    /* 21A4C 8008A24C 4284020C */  jal        func_800A1108
    /* 21A50 8008A250 21280002 */   addu      $a1, $s0, $zero
    /* 21A54 8008A254 21200000 */  addu       $a0, $zero, $zero
    /* 21A58 8008A258 C5D2010C */  jal        func_80074B14
    /* 21A5C 8008A25C 21280002 */   addu      $a1, $s0, $zero
    /* 21A60 8008A260 D8F4010C */  jal        func_8007D360
    /* 21A64 8008A264 00000000 */   nop
    /* 21A68 8008A268 E323010C */  jal        vs_main_commitClut
    /* 21A6C 8008A26C 00000000 */   nop
    /* 21A70 8008A270 40010424 */  addiu      $a0, $zero, 0x140
    /* 21A74 8008A274 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 21A78 8008A278 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* 21A7C 8008A27C 48E2468C */  lw         $a2, %lo(vs_main_projectionDistance)($v0)
    /* 21A80 8008A280 21380000 */  addu       $a3, $zero, $zero
    /* 21A84 8008A284 1000A0AF */  sw         $zero, 0x10($sp)
    /* 21A88 8008A288 33D8010C */  jal        func_800760CC
    /* 21A8C 8008A28C 1400A0AF */   sw        $zero, 0x14($sp)
    /* 21A90 8008A290 00141400 */  sll        $v0, $s4, 16
    /* 21A94 8008A294 0C004014 */  bnez       $v0, .L8008A2C8
    /* 21A98 8008A298 01000424 */   addiu     $a0, $zero, 0x1
    /* 21A9C 8008A29C 21280000 */  addu       $a1, $zero, $zero
    /* 21AA0 8008A2A0 2130A000 */  addu       $a2, $a1, $zero
    /* 21AA4 8008A2A4 16FB020C */  jal        func_800BEC58
    /* 21AA8 8008A2A8 2138A000 */   addu      $a3, $a1, $zero
    /* 21AAC 8008A2AC 00140200 */  sll        $v0, $v0, 16
    /* 21AB0 8008A2B0 03140200 */  sra        $v0, $v0, 16
    /* 21AB4 8008A2B4 01000324 */  addiu      $v1, $zero, 0x1
    /* 21AB8 8008A2B8 09004314 */  bne        $v0, $v1, .L8008A2E0
    /* 21ABC 8008A2BC 00000000 */   nop
    /* 21AC0 8008A2C0 0CFB020C */  jal        func_800BEC30
    /* 21AC4 8008A2C4 00000000 */   nop
  .L8008A2C8:
    /* 21AC8 8008A2C8 A43A020C */  jal        func_8008EA90
    /* 21ACC 8008A2CC 01000424 */   addiu     $a0, $zero, 0x1
    /* 21AD0 8008A2D0 C6CD010C */  jal        func_80073718
    /* 21AD4 8008A2D4 00000000 */   nop
    /* 21AD8 8008A2D8 CF280208 */  j          .L8008A33C
    /* 21ADC 8008A2DC 00000000 */   nop
  .L8008A2E0:
    /* 21AE0 8008A2E0 CBEF010C */  jal        func_8007BF2C
    /* 21AE4 8008A2E4 00000000 */   nop
    /* 21AE8 8008A2E8 F0EF010C */  jal        func_8007BFC0
    /* 21AEC 8008A2EC 00000000 */   nop
    /* 21AF0 8008A2F0 A43A020C */  jal        func_8008EA90
    /* 21AF4 8008A2F4 21200000 */   addu      $a0, $zero, $zero
    /* 21AF8 8008A2F8 854E020C */  jal        func_80093A14
    /* 21AFC 8008A2FC 00000000 */   nop
    /* 21B00 8008A300 73BD010C */  jal        func_8006F5CC
    /* 21B04 8008A304 00000000 */   nop
    /* 21B08 8008A308 952D030C */  jal        func_800CB654
    /* 21B0C 8008A30C 21200000 */   addu      $a0, $zero, $zero
    /* 21B10 8008A310 0F80023C */  lui        $v0, %hi(D_800F18AC)
    /* 21B14 8008A314 AC18448C */  lw         $a0, %lo(D_800F18AC)($v0)
    /* 21B18 8008A318 00000000 */  nop
    /* 21B1C 8008A31C 03008010 */  beqz       $a0, .L8008A32C
    /* 21B20 8008A320 7F000524 */   addiu     $a1, $zero, 0x7F
    /* 21B24 8008A324 0014010C */  jal        func_80045000
    /* 21B28 8008A328 21300000 */   addu      $a2, $zero, $zero
  .L8008A32C:
    /* 21B2C 8008A32C 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionStep)
    /* 21B30 8008A330 04000224 */  addiu      $v0, $zero, 0x4
    /* 21B34 8008A334 3927020C */  jal        func_80089CE4
    /* 21B38 8008A338 481A62AC */   sw        $v0, %lo(vs_battle_screenTransitionStep)($v1)
  .L8008A33C:
    /* 21B3C 8008A33C F70B010C */  jal        vs_main_padDisconnectAll
    /* 21B40 8008A340 00000000 */   nop
    /* 21B44 8008A344 6400BF8F */  lw         $ra, 0x64($sp)
    /* 21B48 8008A348 6000B48F */  lw         $s4, 0x60($sp)
    /* 21B4C 8008A34C 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 21B50 8008A350 5800B28F */  lw         $s2, 0x58($sp)
    /* 21B54 8008A354 5400B18F */  lw         $s1, 0x54($sp)
    /* 21B58 8008A358 5000B08F */  lw         $s0, 0x50($sp)
    /* 21B5C 8008A35C 0800E003 */  jr         $ra
    /* 21B60 8008A360 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_80089DC0
