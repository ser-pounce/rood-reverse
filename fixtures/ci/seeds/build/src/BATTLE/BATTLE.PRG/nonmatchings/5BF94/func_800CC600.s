nonmatching func_800CC600, 0x490

glabel func_800CC600
    /* 63E00 800CC600 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 63E04 800CC604 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 63E08 800CC608 21A8C000 */  addu       $s5, $a2, $zero
    /* 63E0C 800CC60C 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 63E10 800CC610 6C00BFAF */  sw         $ra, 0x6C($sp)
    /* 63E14 800CC614 6800BEAF */  sw         $fp, 0x68($sp)
    /* 63E18 800CC618 6400B7AF */  sw         $s7, 0x64($sp)
    /* 63E1C 800CC61C 6000B6AF */  sw         $s6, 0x60($sp)
    /* 63E20 800CC620 5800B4AF */  sw         $s4, 0x58($sp)
    /* 63E24 800CC624 5400B3AF */  sw         $s3, 0x54($sp)
    /* 63E28 800CC628 5000B2AF */  sw         $s2, 0x50($sp)
    /* 63E2C 800CC62C 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 63E30 800CC630 4800B0AF */  sw         $s0, 0x48($sp)
    /* 63E34 800CC634 7000A4AF */  sw         $a0, 0x70($sp)
    /* 63E38 800CC638 7400A5AF */  sw         $a1, 0x74($sp)
    /* 63E3C 800CC63C 0000838C */  lw         $v1, 0x0($a0)
    /* 63E40 800CC640 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 63E44 800CC644 00028924 */  addiu      $t1, $a0, 0x200
    /* 63E48 800CC648 2C00A0AF */  sw         $zero, 0x2C($sp)
    /* 63E4C 800CC64C 1800A9AF */  sw         $t1, 0x18($sp)
    /* 63E50 800CC650 82400300 */  srl        $t0, $v1, 2
    /* 63E54 800CC654 01000831 */  andi       $t0, $t0, 0x1
    /* 63E58 800CC658 03004014 */  bnez       $v0, .L800CC668
    /* 63E5C 800CC65C 1C00A8AF */   sw        $t0, 0x1C($sp)
    /* 63E60 800CC660 40010824 */  addiu      $t0, $zero, 0x140
    /* 63E64 800CC664 2C00A8AF */  sw         $t0, 0x2C($sp)
  .L800CC668:
    /* 63E68 800CC668 421A0300 */  srl        $v1, $v1, 9
    /* 63E6C 800CC66C 7000A98F */  lw         $t1, 0x70($sp)
    /* 63E70 800CC670 7000A88F */  lw         $t0, 0x70($sp)
    /* 63E74 800CC674 03002991 */  lbu        $t1, 0x3($t1)
    /* 63E78 800CC678 07006330 */  andi       $v1, $v1, 0x7
    /* 63E7C 800CC67C 1000A9AF */  sw         $t1, 0x10($sp)
    /* 63E80 800CC680 02000291 */  lbu        $v0, 0x2($t0)
    /* 63E84 800CC684 80000424 */  addiu      $a0, $zero, 0x80
    /* 63E88 800CC688 21104300 */  addu       $v0, $v0, $v1
    /* 63E8C 800CC68C F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 63E90 800CC690 80110200 */  sll        $v0, $v0, 6
    /* 63E94 800CC694 07002415 */  bne        $t1, $a0, .L800CC6B4
    /* 63E98 800CC698 3000A2AF */   sw        $v0, 0x30($sp)
    /* 63E9C 800CC69C 21200001 */  addu       $a0, $t0, $zero
    /* 63EA0 800CC6A0 7400A58F */  lw         $a1, 0x74($sp)
    /* 63EA4 800CC6A4 F32E030C */  jal        func_800CBBCC
    /* 63EA8 800CC6A8 2130A002 */   addu      $a2, $s5, $zero
    /* 63EAC 800CC6AC 98320308 */  j          .L800CCA60
    /* 63EB0 800CC6B0 00000000 */   nop
  .L800CC6B4:
    /* 63EB4 800CC6B4 1000A98F */  lw         $t1, 0x10($sp)
    /* 63EB8 800CC6B8 00000000 */  nop
    /* 63EBC 800CC6BC 23208900 */  subu       $a0, $a0, $t1
    /* 63EC0 800CC6C0 00012935 */  ori        $t1, $t1, 0x100
    /* 63EC4 800CC6C4 21408000 */  addu       $t0, $a0, $zero
    /* 63EC8 800CC6C8 07002925 */  addiu      $t1, $t1, 0x7
    /* 63ECC 800CC6CC 1000A9AF */  sw         $t1, 0x10($sp)
    /* 63ED0 800CC6D0 7000A98F */  lw         $t1, 0x70($sp)
    /* 63ED4 800CC6D4 07000825 */  addiu      $t0, $t0, 0x7
    /* 63ED8 800CC6D8 1400A4AF */  sw         $a0, 0x14($sp)
    /* 63EDC 800CC6DC 1400A8AF */  sw         $t0, 0x14($sp)
    /* 63EE0 800CC6E0 05002391 */  lbu        $v1, 0x5($t1)
    /* 63EE4 800CC6E4 2400A0AF */  sw         $zero, 0x24($sp)
    /* 63EE8 800CC6E8 04002891 */  lbu        $t0, 0x4($t1)
    /* 63EEC 800CC6EC 00110300 */  sll        $v0, $v1, 4
    /* 63EF0 800CC6F0 23B84300 */  subu       $s7, $v0, $v1
    /* 63EF4 800CC6F4 43101700 */  sra        $v0, $s7, 1
    /* 63EF8 800CC6F8 0A002385 */  lh         $v1, 0xA($t1)
    /* 63EFC 800CC6FC 88FF4224 */  addiu      $v0, $v0, -0x78
    /* 63F00 800CC700 2000A8AF */  sw         $t0, 0x20($sp)
    /* 63F04 800CC704 23186200 */  subu       $v1, $v1, $v0
    /* 63F08 800CC708 D5000011 */  beqz       $t0, .L800CCA60
    /* 63F0C 800CC70C 2800A3AF */   sw        $v1, 0x28($sp)
    /* 63F10 800CC710 3000A98F */  lw         $t1, 0x30($sp)
    /* 63F14 800CC714 00E1083C */  lui        $t0, (0xE1000000 >> 16)
    /* 63F18 800CC718 4400A0AF */  sw         $zero, 0x44($sp)
    /* 63F1C 800CC71C FF032231 */  andi       $v0, $t1, 0x3FF
    /* 63F20 800CC720 83110200 */  sra        $v0, $v0, 6
    /* 63F24 800CC724 30014334 */  ori        $v1, $v0, 0x130
    /* 63F28 800CC728 25406800 */  or         $t0, $v1, $t0
    /* 63F2C 800CC72C 2C00A98F */  lw         $t1, 0x2C($sp)
    /* 63F30 800CC730 50014234 */  ori        $v0, $v0, 0x150
    /* 63F34 800CC734 3400A8AF */  sw         $t0, 0x34($sp)
    /* 63F38 800CC738 3800A2AF */  sw         $v0, 0x38($sp)
    /* 63F3C 800CC73C 4000A9AF */  sw         $t1, 0x40($sp)
  .L800CC740:
    /* 63F40 800CC740 80010424 */  addiu      $a0, $zero, 0x180
    /* 63F44 800CC744 00341700 */  sll        $a2, $s7, 16
    /* 63F48 800CC748 4000C634 */  ori        $a2, $a2, 0x40
    /* 63F4C 800CC74C 2138A002 */  addu       $a3, $s5, $zero
    /* 63F50 800CC750 2800A88F */  lw         $t0, 0x28($sp)
    /* 63F54 800CC754 4400A98F */  lw         $t1, 0x44($sp)
    /* 63F58 800CC758 002C0800 */  sll        $a1, $t0, 16
    /* 63F5C 800CC75C 8C00030C */  jal        vs_battle_setSprite
    /* 63F60 800CC760 25282501 */   or        $a1, $t1, $a1
    /* 63F64 800CC764 3400A88F */  lw         $t0, 0x34($sp)
    /* 63F68 800CC768 00000000 */  nop
    /* 63F6C 800CC76C 040048AC */  sw         $t0, 0x4($v0)
    /* 63F70 800CC770 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 63F74 800CC774 7031030C */  jal        func_800CC5C0
    /* 63F78 800CC778 2120A002 */   addu      $a0, $s5, $zero
    /* 63F7C 800CC77C F1FFF226 */  addiu      $s2, $s7, -0xF
    /* 63F80 800CC780 2D004006 */  bltz       $s2, .L800CC838
    /* 63F84 800CC784 20001124 */   addiu     $s1, $zero, 0x20
    /* 63F88 800CC788 3800A98F */  lw         $t1, 0x38($sp)
    /* 63F8C 800CC78C 00000000 */  nop
    /* 63F90 800CC790 FF093631 */  andi       $s6, $t1, 0x9FF
  .L800CC794:
    /* 63F94 800CC794 00E1083C */  lui        $t0, (0xE1000000 >> 16)
    /* 63F98 800CC798 2800A98F */  lw         $t1, 0x28($sp)
    /* 63F9C 800CC79C 25A0C802 */  or         $s4, $s6, $t0
    /* 63FA0 800CC7A0 21103201 */  addu       $v0, $t1, $s2
    /* 63FA4 800CC7A4 009C0200 */  sll        $s3, $v0, 16
    /* 63FA8 800CC7A8 80010424 */  addiu      $a0, $zero, 0x180
  .L800CC7AC:
    /* 63FAC 800CC7AC 002C1200 */  sll        $a1, $s2, 16
    /* 63FB0 800CC7B0 25282502 */  or         $a1, $s1, $a1
    /* 63FB4 800CC7B4 0F00063C */  lui        $a2, (0xF0020 >> 16)
    /* 63FB8 800CC7B8 2000C634 */  ori        $a2, $a2, (0xF0020 & 0xFFFF)
    /* 63FBC 800CC7BC 8C00030C */  jal        vs_battle_setSprite
    /* 63FC0 800CC7C0 2138A002 */   addu      $a3, $s5, $zero
    /* 63FC4 800CC7C4 21304000 */  addu       $a2, $v0, $zero
    /* 63FC8 800CC7C8 2120A002 */  addu       $a0, $s5, $zero
    /* 63FCC 800CC7CC 00821200 */  sll        $s0, $s2, 8
    /* 63FD0 800CC7D0 3000A58F */  lw         $a1, 0x30($sp)
    /* 63FD4 800CC7D4 25803002 */  or         $s0, $s1, $s0
    /* 63FD8 800CC7D8 0400D4AC */  sw         $s4, 0x4($a2)
    /* 63FDC 800CC7DC 6031030C */  jal        func_800CC580
    /* 63FE0 800CC7E0 1000D0AC */   sw        $s0, 0x10($a2)
    /* 63FE4 800CC7E4 0F00063C */  lui        $a2, (0xF0020 >> 16)
    /* 63FE8 800CC7E8 2000C634 */  ori        $a2, $a2, (0xF0020 & 0xFFFF)
    /* 63FEC 800CC7EC 2138A002 */  addu       $a3, $s5, $zero
    /* 63FF0 800CC7F0 4400A88F */  lw         $t0, 0x44($sp)
    /* 63FF4 800CC7F4 1000A48F */  lw         $a0, 0x10($sp)
    /* 63FF8 800CC7F8 21282802 */  addu       $a1, $s1, $t0
    /* 63FFC 800CC7FC 8C00030C */  jal        vs_battle_setSprite
    /* 64000 800CC800 2528B300 */   or        $a1, $a1, $s3
    /* 64004 800CC804 21304000 */  addu       $a2, $v0, $zero
    /* 64008 800CC808 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 6400C 800CC80C 3400A98F */  lw         $t1, 0x34($sp)
    /* 64010 800CC810 2120A002 */  addu       $a0, $s5, $zero
    /* 64014 800CC814 1000D0AC */  sw         $s0, 0x10($a2)
    /* 64018 800CC818 7031030C */  jal        func_800CC5C0
    /* 6401C 800CC81C 0400C9AC */   sw        $t1, 0x4($a2)
    /* 64020 800CC820 E0FF3126 */  addiu      $s1, $s1, -0x20
    /* 64024 800CC824 E1FF2106 */  bgez       $s1, .L800CC7AC
    /* 64028 800CC828 80010424 */   addiu     $a0, $zero, 0x180
    /* 6402C 800CC82C F1FF5226 */  addiu      $s2, $s2, -0xF
    /* 64030 800CC830 D8FF4106 */  bgez       $s2, .L800CC794
    /* 64034 800CC834 20001124 */   addiu     $s1, $zero, 0x20
  .L800CC838:
    /* 64038 800CC838 7000A88F */  lw         $t0, 0x70($sp)
    /* 6403C 800CC83C 21900000 */  addu       $s2, $zero, $zero
    /* 64040 800CC840 0A000285 */  lh         $v0, 0xA($t0)
    /* 64044 800CC844 05000391 */  lbu        $v1, 0x5($t0)
    /* 64048 800CC848 00000000 */  nop
    /* 6404C 800CC84C 39006010 */  beqz       $v1, .L800CC934
    /* 64050 800CC850 78005124 */   addiu     $s1, $v0, 0x78
    /* 64054 800CC854 21A04002 */  addu       $s4, $s2, $zero
    /* 64058 800CC858 1C00A98F */  lw         $t1, 0x1C($sp)
    /* 6405C 800CC85C 2400B38F */  lw         $s3, 0x24($sp)
    /* 64060 800CC860 03002231 */  andi       $v0, $t1, 0x3
    /* 64064 800CC864 C0B10200 */  sll        $s6, $v0, 7
  .L800CC868:
    /* 64068 800CC868 1800A88F */  lw         $t0, 0x18($sp)
    /* 6406C 800CC86C 40101300 */  sll        $v0, $s3, 1
    /* 64070 800CC870 21104800 */  addu       $v0, $v0, $t0
    /* 64074 800CC874 00005094 */  lhu        $s0, 0x0($v0)
    /* 64078 800CC878 00000000 */  nop
    /* 6407C 800CC87C 24000012 */  beqz       $s0, .L800CC910
    /* 64080 800CC880 80000424 */   addiu     $a0, $zero, 0x80
    /* 64084 800CC884 23289702 */  subu       $a1, $s4, $s7
    /* 64088 800CC888 43280500 */  sra        $a1, $a1, 1
    /* 6408C 800CC88C 2128B100 */  addu       $a1, $a1, $s1
    /* 64090 800CC890 0F00063C */  lui        $a2, (0xF0040 >> 16)
    /* 64094 800CC894 4000C634 */  ori        $a2, $a2, (0xF0040 & 0xFFFF)
    /* 64098 800CC898 2800A98F */  lw         $t1, 0x28($sp)
    /* 6409C 800CC89C 2138A002 */  addu       $a3, $s5, $zero
    /* 640A0 800CC8A0 2328A900 */  subu       $a1, $a1, $t1
    /* 640A4 800CC8A4 8C00030C */  jal        vs_battle_setSprite
    /* 640A8 800CC8A8 002C0500 */   sll       $a1, $a1, 16
    /* 640AC 800CC8AC 21304000 */  addu       $a2, $v0, $zero
    /* 640B0 800CC8B0 83281000 */  sra        $a1, $s0, 2
    /* 640B4 800CC8B4 80211000 */  sll        $a0, $s0, 6
    /* 640B8 800CC8B8 C0008430 */  andi       $a0, $a0, 0xC0
    /* 640BC 800CC8BC 1F00A330 */  andi       $v1, $a1, 0x1F
    /* 640C0 800CC8C0 00110300 */  sll        $v0, $v1, 4
    /* 640C4 800CC8C4 23104300 */  subu       $v0, $v0, $v1
    /* 640C8 800CC8C8 00120200 */  sll        $v0, $v0, 8
    /* 640CC 800CC8CC 25208200 */  or         $a0, $a0, $v0
    /* 640D0 800CC8D0 C001A530 */  andi       $a1, $a1, 0x1C0
    /* 640D4 800CC8D4 7400A98F */  lw         $t1, 0x74($sp)
    /* 640D8 800CC8D8 7000A88F */  lw         $t0, 0x70($sp)
    /* 640DC 800CC8DC 25208900 */  or         $a0, $a0, $t1
    /* 640E0 800CC8E0 02000291 */  lbu        $v0, 0x2($t0)
    /* 640E4 800CC8E4 00E1083C */  lui        $t0, (0xE1000000 >> 16)
    /* 640E8 800CC8E8 1000C4AC */  sw         $a0, 0x10($a2)
    /* 640EC 800CC8EC EEFF4224 */  addiu      $v0, $v0, -0x12
    /* 640F0 800CC8F0 80110200 */  sll        $v0, $v0, 6
    /* 640F4 800CC8F4 21104500 */  addu       $v0, $v0, $a1
    /* 640F8 800CC8F8 FF034230 */  andi       $v0, $v0, 0x3FF
    /* 640FC 800CC8FC 83110200 */  sra        $v0, $v0, 6
    /* 64100 800CC900 10004234 */  ori        $v0, $v0, 0x10
    /* 64104 800CC904 2510C202 */  or         $v0, $s6, $v0
    /* 64108 800CC908 25104800 */  or         $v0, $v0, $t0
    /* 6410C 800CC90C 0400C2AC */  sw         $v0, 0x4($a2)
  .L800CC910:
    /* 64110 800CC910 1E009426 */  addiu      $s4, $s4, 0x1E
    /* 64114 800CC914 01005226 */  addiu      $s2, $s2, 0x1
    /* 64118 800CC918 7000A88F */  lw         $t0, 0x70($sp)
    /* 6411C 800CC91C 2000A98F */  lw         $t1, 0x20($sp)
    /* 64120 800CC920 05000291 */  lbu        $v0, 0x5($t0)
    /* 64124 800CC924 00000000 */  nop
    /* 64128 800CC928 2A104202 */  slt        $v0, $s2, $v0
    /* 6412C 800CC92C CEFF4014 */  bnez       $v0, .L800CC868
    /* 64130 800CC930 21986902 */   addu      $s3, $s3, $t1
  .L800CC934:
    /* 64134 800CC934 3000A58F */  lw         $a1, 0x30($sp)
    /* 64138 800CC938 6031030C */  jal        func_800CC580
    /* 6413C 800CC93C 2120A002 */   addu      $a0, $s5, $zero
    /* 64140 800CC940 3200E01A */  blez       $s7, .L800CCA0C
    /* 64144 800CC944 21900000 */   addu      $s2, $zero, $zero
    /* 64148 800CC948 4000A98F */  lw         $t1, 0x40($sp)
    /* 6414C 800CC94C 4400BE8F */  lw         $fp, 0x44($sp)
    /* 64150 800CC950 FF032231 */  andi       $v0, $t1, 0x3FF
    /* 64154 800CC954 83110200 */  sra        $v0, $v0, 6
    /* 64158 800CC958 3C00A2AF */  sw         $v0, 0x3C($sp)
  .L800CC95C:
    /* 6415C 800CC95C 21880000 */  addu       $s1, $zero, $zero
    /* 64160 800CC960 3C00A88F */  lw         $t0, 0x3C($sp)
    /* 64164 800CC964 00E1093C */  lui        $t1, (0xE1000000 >> 16)
    /* 64168 800CC968 00010235 */  ori        $v0, $t0, 0x100
    /* 6416C 800CC96C 2800A88F */  lw         $t0, 0x28($sp)
    /* 64170 800CC970 25984900 */  or         $s3, $v0, $t1
    /* 64174 800CC974 21A01201 */  addu       $s4, $t0, $s2
    /* 64178 800CC978 00B21400 */  sll        $s6, $s4, 8
    /* 6417C 800CC97C 21103E02 */  addu       $v0, $s1, $fp
  .L800CC980:
    /* 64180 800CC980 002C1400 */  sll        $a1, $s4, 16
    /* 64184 800CC984 25284500 */  or         $a1, $v0, $a1
    /* 64188 800CC988 0F00063C */  lui        $a2, (0xF0020 >> 16)
    /* 6418C 800CC98C 2000C634 */  ori        $a2, $a2, (0xF0020 & 0xFFFF)
    /* 64190 800CC990 1400A48F */  lw         $a0, 0x14($sp)
    /* 64194 800CC994 8C00030C */  jal        vs_battle_setSprite
    /* 64198 800CC998 2138A002 */   addu      $a3, $s5, $zero
    /* 6419C 800CC99C 21304000 */  addu       $a2, $v0, $zero
    /* 641A0 800CC9A0 2120A002 */  addu       $a0, $s5, $zero
    /* 641A4 800CC9A4 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 641A8 800CC9A8 25803602 */  or         $s0, $s1, $s6
    /* 641AC 800CC9AC 0400D3AC */  sw         $s3, 0x4($a2)
    /* 641B0 800CC9B0 7031030C */  jal        func_800CC5C0
    /* 641B4 800CC9B4 1000D0AC */   sw        $s0, 0x10($a2)
    /* 641B8 800CC9B8 80000424 */  addiu      $a0, $zero, 0x80
    /* 641BC 800CC9BC 002C1200 */  sll        $a1, $s2, 16
    /* 641C0 800CC9C0 25282502 */  or         $a1, $s1, $a1
    /* 641C4 800CC9C4 0F00063C */  lui        $a2, (0xF0020 >> 16)
    /* 641C8 800CC9C8 2000C634 */  ori        $a2, $a2, (0xF0020 & 0xFFFF)
    /* 641CC 800CC9CC 8C00030C */  jal        vs_battle_setSprite
    /* 641D0 800CC9D0 2138A002 */   addu      $a3, $s5, $zero
    /* 641D4 800CC9D4 21304000 */  addu       $a2, $v0, $zero
    /* 641D8 800CC9D8 3000A58F */  lw         $a1, 0x30($sp)
    /* 641DC 800CC9DC 2120A002 */  addu       $a0, $s5, $zero
    /* 641E0 800CC9E0 0400D3AC */  sw         $s3, 0x4($a2)
    /* 641E4 800CC9E4 6031030C */  jal        func_800CC580
    /* 641E8 800CC9E8 1000D0AC */   sw        $s0, 0x10($a2)
    /* 641EC 800CC9EC 20003126 */  addiu      $s1, $s1, 0x20
    /* 641F0 800CC9F0 4000222A */  slti       $v0, $s1, 0x40
    /* 641F4 800CC9F4 E2FF4014 */  bnez       $v0, .L800CC980
    /* 641F8 800CC9F8 21103E02 */   addu      $v0, $s1, $fp
    /* 641FC 800CC9FC 0F005226 */  addiu      $s2, $s2, 0xF
    /* 64200 800CCA00 2A105702 */  slt        $v0, $s2, $s7
    /* 64204 800CCA04 D5FF4014 */  bnez       $v0, .L800CC95C
    /* 64208 800CCA08 00000000 */   nop
  .L800CCA0C:
    /* 6420C 800CCA0C 2120A002 */  addu       $a0, $s5, $zero
    /* 64210 800CCA10 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 64214 800CCA14 21300000 */  addu       $a2, $zero, $zero
    /* 64218 800CCA18 003C1700 */  sll        $a3, $s7, 16
    /* 6421C 800CCA1C 2E33030C */  jal        func_800CCCB8
    /* 64220 800CCA20 4000E734 */   ori       $a3, $a3, 0x40
    /* 64224 800CCA24 3000A58F */  lw         $a1, 0x30($sp)
    /* 64228 800CCA28 6031030C */  jal        func_800CC580
    /* 6422C 800CCA2C 2120A002 */   addu      $a0, $s5, $zero
    /* 64230 800CCA30 4000A98F */  lw         $t1, 0x40($sp)
    /* 64234 800CCA34 4400A88F */  lw         $t0, 0x44($sp)
    /* 64238 800CCA38 40002925 */  addiu      $t1, $t1, 0x40
    /* 6423C 800CCA3C 4000A9AF */  sw         $t1, 0x40($sp)
    /* 64240 800CCA40 2400A98F */  lw         $t1, 0x24($sp)
    /* 64244 800CCA44 40000825 */  addiu      $t0, $t0, 0x40
    /* 64248 800CCA48 4400A8AF */  sw         $t0, 0x44($sp)
    /* 6424C 800CCA4C 2000A88F */  lw         $t0, 0x20($sp)
    /* 64250 800CCA50 01002925 */  addiu      $t1, $t1, 0x1
    /* 64254 800CCA54 2A102801 */  slt        $v0, $t1, $t0
    /* 64258 800CCA58 39FF4014 */  bnez       $v0, .L800CC740
    /* 6425C 800CCA5C 2400A9AF */   sw        $t1, 0x24($sp)
  .L800CCA60:
    /* 64260 800CCA60 6C00BF8F */  lw         $ra, 0x6C($sp)
    /* 64264 800CCA64 6800BE8F */  lw         $fp, 0x68($sp)
    /* 64268 800CCA68 6400B78F */  lw         $s7, 0x64($sp)
    /* 6426C 800CCA6C 6000B68F */  lw         $s6, 0x60($sp)
    /* 64270 800CCA70 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 64274 800CCA74 5800B48F */  lw         $s4, 0x58($sp)
    /* 64278 800CCA78 5400B38F */  lw         $s3, 0x54($sp)
    /* 6427C 800CCA7C 5000B28F */  lw         $s2, 0x50($sp)
    /* 64280 800CCA80 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 64284 800CCA84 4800B08F */  lw         $s0, 0x48($sp)
    /* 64288 800CCA88 0800E003 */  jr         $ra
    /* 6428C 800CCA8C 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel func_800CC600
