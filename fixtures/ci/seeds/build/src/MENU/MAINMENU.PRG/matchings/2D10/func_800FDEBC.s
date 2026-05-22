nonmatching func_800FDEBC, 0x4A4

glabel func_800FDEBC
    /* 46BC 800FDEBC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 46C0 800FDEC0 1080023C */  lui        $v0, %hi(D_801024B8)
    /* 46C4 800FDEC4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 46C8 800FDEC8 B8245290 */  lbu        $s2, %lo(D_801024B8)($v0)
    /* 46CC 800FDECC 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 46D0 800FDED0 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 46D4 800FDED4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 46D8 800FDED8 21980000 */  addu       $s3, $zero, $zero
    /* 46DC 800FDEDC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 46E0 800FDEE0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 46E4 800FDEE4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 46E8 800FDEE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 46EC 800FDEEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 46F0 800FDEF0 00106230 */  andi       $v0, $v1, 0x1000
    /* 46F4 800FDEF4 03004010 */  beqz       $v0, .L800FDF04
    /* 46F8 800FDEF8 21884002 */   addu      $s1, $s2, $zero
    /* 46FC 800FDEFC CDF70308 */  j          .L800FDF34
    /* 4700 800FDF00 01001324 */   addiu     $s3, $zero, 0x1
  .L800FDF04:
    /* 4704 800FDF04 00406230 */  andi       $v0, $v1, 0x4000
    /* 4708 800FDF08 03004010 */  beqz       $v0, .L800FDF18
    /* 470C 800FDF0C 00806230 */   andi      $v0, $v1, 0x8000
    /* 4710 800FDF10 CDF70308 */  j          .L800FDF34
    /* 4714 800FDF14 02001324 */   addiu     $s3, $zero, 0x2
  .L800FDF18:
    /* 4718 800FDF18 03004010 */  beqz       $v0, .L800FDF28
    /* 471C 800FDF1C 00206230 */   andi      $v0, $v1, 0x2000
    /* 4720 800FDF20 CDF70308 */  j          .L800FDF34
    /* 4724 800FDF24 03001324 */   addiu     $s3, $zero, 0x3
  .L800FDF28:
    /* 4728 800FDF28 02004010 */  beqz       $v0, .L800FDF34
    /* 472C 800FDF2C 00000000 */   nop
    /* 4730 800FDF30 04001324 */  addiu      $s3, $zero, 0x4
  .L800FDF34:
    /* 4734 800FDF34 09006012 */  beqz       $s3, .L800FDF5C
    /* 4738 800FDF38 1080033C */   lui       $v1, %hi(vs_mainMenu_equipmentDetailNavigationMap)
    /* 473C 800FDF3C 4C216324 */  addiu      $v1, $v1, %lo(vs_mainMenu_equipmentDetailNavigationMap)
    /* 4740 800FDF40 80101200 */  sll        $v0, $s2, 2
    /* 4744 800FDF44 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 4748 800FDF48 21106202 */  addu       $v0, $s3, $v0
    /* 474C 800FDF4C 21104300 */  addu       $v0, $v0, $v1
    /* 4750 800FDF50 00004390 */  lbu        $v1, 0x0($v0)
    /* 4754 800FDF54 1080023C */  lui        $v0, %hi(D_801024B8)
    /* 4758 800FDF58 B82443A0 */  sb         $v1, %lo(D_801024B8)($v0)
  .L800FDF5C:
    /* 475C 800FDF5C 1080103C */  lui        $s0, %hi(D_801024B8)
    /* 4760 800FDF60 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentDetailNavigationMap)
    /* 4764 800FDF64 4C215524 */  addiu      $s5, $v0, %lo(vs_mainMenu_equipmentDetailNavigationMap)
  .L800FDF68:
    /* 4768 800FDF68 B8240492 */  lbu        $a0, %lo(D_801024B8)($s0)
    /* 476C 800FDF6C 62F7030C */  jal        func_800FDD88
    /* 4770 800FDF70 00000000 */   nop
    /* 4774 800FDF74 25004014 */  bnez       $v0, .L800FE00C
    /* 4778 800FDF78 1080043C */   lui       $a0, %hi(D_80102211)
    /* 477C 800FDF7C B8240292 */  lbu        $v0, %lo(D_801024B8)($s0)
    /* 4780 800FDF80 00000000 */  nop
    /* 4784 800FDF84 19004216 */  bne        $s2, $v0, .L800FDFEC
    /* 4788 800FDF88 00000000 */   nop
    /* 478C 800FDF8C FEFF4226 */  addiu      $v0, $s2, -0x2
    /* 4790 800FDF90 0E00422C */  sltiu      $v0, $v0, 0xE
    /* 4794 800FDF94 0B004010 */  beqz       $v0, .L800FDFC4
    /* 4798 800FDF98 00000000 */   nop
  .L800FDF9C:
    /* 479C 800FDF9C B8240292 */  lbu        $v0, %lo(D_801024B8)($s0)
    /* 47A0 800FDFA0 00000000 */  nop
    /* 47A4 800FDFA4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 47A8 800FDFA8 B82402A2 */  sb         $v0, %lo(D_801024B8)($s0)
    /* 47AC 800FDFAC 62F7030C */  jal        func_800FDD88
    /* 47B0 800FDFB0 FF004430 */   andi      $a0, $v0, 0xFF
    /* 47B4 800FDFB4 F9FF4010 */  beqz       $v0, .L800FDF9C
    /* 47B8 800FDFB8 1080043C */   lui       $a0, %hi(D_80102211)
    /* 47BC 800FDFBC 04F80308 */  j          .L800FE010
    /* 47C0 800FDFC0 1080023C */   lui       $v0, %hi(D_801024A1)
  .L800FDFC4:
    /* 47C4 800FDFC4 B8240292 */  lbu        $v0, %lo(D_801024B8)($s0)
    /* 47C8 800FDFC8 00000000 */  nop
    /* 47CC 800FDFCC 01004224 */  addiu      $v0, $v0, 0x1
    /* 47D0 800FDFD0 B82402A2 */  sb         $v0, %lo(D_801024B8)($s0)
    /* 47D4 800FDFD4 62F7030C */  jal        func_800FDD88
    /* 47D8 800FDFD8 FF004430 */   andi      $a0, $v0, 0xFF
    /* 47DC 800FDFDC F9FF4010 */  beqz       $v0, .L800FDFC4
    /* 47E0 800FDFE0 1080043C */   lui       $a0, %hi(D_80102211)
    /* 47E4 800FDFE4 04F80308 */  j          .L800FE010
    /* 47E8 800FDFE8 1080023C */   lui       $v0, %hi(D_801024A1)
  .L800FDFEC:
    /* 47EC 800FDFEC 21904000 */  addu       $s2, $v0, $zero
    /* 47F0 800FDFF0 80101200 */  sll        $v0, $s2, 2
    /* 47F4 800FDFF4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 47F8 800FDFF8 21106202 */  addu       $v0, $s3, $v0
    /* 47FC 800FDFFC 21105500 */  addu       $v0, $v0, $s5
    /* 4800 800FE000 00004290 */  lbu        $v0, 0x0($v0)
    /* 4804 800FE004 DAF70308 */  j          .L800FDF68
    /* 4808 800FE008 B82402A2 */   sb        $v0, %lo(D_801024B8)($s0)
  .L800FE00C:
    /* 480C 800FE00C 1080023C */  lui        $v0, %hi(D_801024A1)
  .L800FE010:
    /* 4810 800FE010 A1244390 */  lbu        $v1, %lo(D_801024A1)($v0)
    /* 4814 800FE014 11228290 */  lbu        $v0, %lo(D_80102211)($a0)
    /* 4818 800FE018 00000000 */  nop
    /* 481C 800FE01C 09004314 */  bne        $v0, $v1, .L800FE044
    /* 4820 800FE020 1080023C */   lui       $v0, %hi(D_801024B8)
    /* 4824 800FE024 B8244290 */  lbu        $v0, %lo(D_801024B8)($v0)
    /* 4828 800FE028 00000000 */  nop
    /* 482C 800FE02C 07002212 */  beq        $s1, $v0, .L800FE04C
    /* 4830 800FE030 0B001124 */   addiu     $s1, $zero, 0xB
    /* 4834 800FE034 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 4838 800FE038 00000000 */   nop
    /* 483C 800FE03C 13F80308 */  j          .L800FE04C
    /* 4840 800FE040 00000000 */   nop
  .L800FE044:
    /* 4844 800FE044 112283A0 */  sb         $v1, %lo(D_80102211)($a0)
    /* 4848 800FE048 0B001124 */  addiu      $s1, $zero, 0xB
  .L800FE04C:
    /* 484C 800FE04C 9223030C */  jal        vs_battle_getMenuItem
    /* 4850 800FE050 21202002 */   addu      $a0, $s1, $zero
    /* 4854 800FE054 060040A0 */  sb         $zero, 0x6($v0)
    /* 4858 800FE058 01003126 */  addiu      $s1, $s1, 0x1
    /* 485C 800FE05C 1000222A */  slti       $v0, $s1, 0x10
    /* 4860 800FE060 FAFF4014 */  bnez       $v0, .L800FE04C
    /* 4864 800FE064 1080103C */   lui       $s0, %hi(vs_mainMenu_equipmentSubtype)
    /* 4868 800FE068 45250292 */  lbu        $v0, %lo(vs_mainMenu_equipmentSubtype)($s0)
    /* 486C 800FE06C 00000000 */  nop
    /* 4870 800FE070 01004230 */  andi       $v0, $v0, 0x1
    /* 4874 800FE074 07004010 */  beqz       $v0, .L800FE094
    /* 4878 800FE078 00000000 */   nop
    /* 487C 800FE07C 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 4880 800FE080 0B000424 */   addiu     $a0, $zero, 0xB
    /* 4884 800FE084 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 4888 800FE088 A1244490 */  lbu        $a0, %lo(D_801024A1)($v0)
    /* 488C 800FE08C 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 4890 800FE090 00000000 */   nop
  .L800FE094:
    /* 4894 800FE094 45250292 */  lbu        $v0, %lo(vs_mainMenu_equipmentSubtype)($s0)
    /* 4898 800FE098 00000000 */  nop
    /* 489C 800FE09C 08004230 */  andi       $v0, $v0, 0x8
    /* 48A0 800FE0A0 07004010 */  beqz       $v0, .L800FE0C0
    /* 48A4 800FE0A4 00000000 */   nop
    /* 48A8 800FE0A8 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 48AC 800FE0AC 0B000424 */   addiu     $a0, $zero, 0xB
    /* 48B0 800FE0B0 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 48B4 800FE0B4 A1244490 */  lbu        $a0, %lo(D_801024A1)($v0)
    /* 48B8 800FE0B8 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* 48BC 800FE0BC 00000000 */   nop
  .L800FE0C0:
    /* 48C0 800FE0C0 45250292 */  lbu        $v0, %lo(vs_mainMenu_equipmentSubtype)($s0)
    /* 48C4 800FE0C4 00000000 */  nop
    /* 48C8 800FE0C8 10004230 */  andi       $v0, $v0, 0x10
    /* 48CC 800FE0CC 03004010 */  beqz       $v0, .L800FE0DC
    /* 48D0 800FE0D0 00000000 */   nop
    /* 48D4 800FE0D4 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 48D8 800FE0D8 09000424 */   addiu     $a0, $zero, 0x9
  .L800FE0DC:
    /* 48DC 800FE0DC 45250292 */  lbu        $v0, %lo(vs_mainMenu_equipmentSubtype)($s0)
    /* 48E0 800FE0E0 00000000 */  nop
    /* 48E4 800FE0E4 20004230 */  andi       $v0, $v0, 0x20
    /* 48E8 800FE0E8 04004010 */  beqz       $v0, .L800FE0FC
    /* 48EC 800FE0EC 1080053C */   lui       $a1, %hi(D_801024B8)
    /* 48F0 800FE0F0 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 48F4 800FE0F4 08000424 */   addiu     $a0, $zero, 0x8
    /* 48F8 800FE0F8 1080053C */  lui        $a1, %hi(D_801024B8)
  .L800FE0FC:
    /* 48FC 800FE0FC B824A390 */  lbu        $v1, %lo(D_801024B8)($a1)
    /* 4900 800FE100 00000000 */  nop
    /* 4904 800FE104 0200622C */  sltiu      $v0, $v1, 0x2
    /* 4908 800FE108 09004010 */  beqz       $v0, .L800FE130
    /* 490C 800FE10C 1080043C */   lui       $a0, %hi(vs_mainMenu_itemHelp)
    /* 4910 800FE110 9F010224 */  addiu      $v0, $zero, 0x19F
    /* 4914 800FE114 23104300 */  subu       $v0, $v0, $v1
    /* 4918 800FE118 4025838C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($a0)
    /* 491C 800FE11C 40100200 */  sll        $v0, $v0, 1
    /* 4920 800FE120 21104300 */  addu       $v0, $v0, $v1
    /* 4924 800FE124 00004294 */  lhu        $v0, 0x0($v0)
    /* 4928 800FE128 73F80308 */  j          .L800FE1CC
    /* 492C 800FE12C 40100200 */   sll       $v0, $v0, 1
  .L800FE130:
    /* 4930 800FE130 0900622C */  sltiu      $v0, $v1, 0x9
    /* 4934 800FE134 27004010 */  beqz       $v0, .L800FE1D4
    /* 4938 800FE138 1080023C */   lui       $v0, %hi(D_801024B9)
    /* 493C 800FE13C B9244390 */  lbu        $v1, %lo(D_801024B9)($v0)
    /* 4940 800FE140 01000224 */  addiu      $v0, $zero, 0x1
    /* 4944 800FE144 12006210 */  beq        $v1, $v0, .L800FE190
    /* 4948 800FE148 02006228 */   slti      $v0, $v1, 0x2
    /* 494C 800FE14C 05004010 */  beqz       $v0, .L800FE164
    /* 4950 800FE150 02000224 */   addiu     $v0, $zero, 0x2
    /* 4954 800FE154 07006010 */  beqz       $v1, .L800FE174
    /* 4958 800FE158 1080033C */   lui       $v1, %hi(vs_mainMenu_itemHelp)
    /* 495C 800FE15C ADF80308 */  j          .L800FE2B4
    /* 4960 800FE160 00000000 */   nop
  .L800FE164:
    /* 4964 800FE164 12006210 */  beq        $v1, $v0, .L800FE1B0
    /* 4968 800FE168 1080033C */   lui       $v1, %hi(vs_mainMenu_itemHelp)
    /* 496C 800FE16C ADF80308 */  j          .L800FE2B4
    /* 4970 800FE170 00000000 */   nop
  .L800FE174:
    /* 4974 800FE174 B824A290 */  lbu        $v0, %lo(D_801024B8)($a1)
    /* 4978 800FE178 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 497C 800FE17C 40100200 */  sll        $v0, $v0, 1
    /* 4980 800FE180 21104300 */  addu       $v0, $v0, $v1
    /* 4984 800FE184 3C034294 */  lhu        $v0, 0x33C($v0)
    /* 4988 800FE188 73F80308 */  j          .L800FE1CC
    /* 498C 800FE18C 40100200 */   sll       $v0, $v0, 1
  .L800FE190:
    /* 4990 800FE190 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 4994 800FE194 B824A290 */  lbu        $v0, %lo(D_801024B8)($a1)
    /* 4998 800FE198 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 499C 800FE19C 40100200 */  sll        $v0, $v0, 1
    /* 49A0 800FE1A0 21104300 */  addu       $v0, $v0, $v1
    /* 49A4 800FE1A4 48034294 */  lhu        $v0, 0x348($v0)
    /* 49A8 800FE1A8 73F80308 */  j          .L800FE1CC
    /* 49AC 800FE1AC 40100200 */   sll       $v0, $v0, 1
  .L800FE1B0:
    /* 49B0 800FE1B0 B824A290 */  lbu        $v0, %lo(D_801024B8)($a1)
    /* 49B4 800FE1B4 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 49B8 800FE1B8 40100200 */  sll        $v0, $v0, 1
    /* 49BC 800FE1BC 21104300 */  addu       $v0, $v0, $v1
    /* 49C0 800FE1C0 56034294 */  lhu        $v0, 0x356($v0)
    /* 49C4 800FE1C4 00000000 */  nop
    /* 49C8 800FE1C8 40100200 */  sll        $v0, $v0, 1
  .L800FE1CC:
    /* 49CC 800FE1CC ADF80308 */  j          .L800FE2B4
    /* 49D0 800FE1D0 21A06200 */   addu      $s4, $v1, $v0
  .L800FE1D4:
    /* 49D4 800FE1D4 0F00622C */  sltiu      $v0, $v1, 0xF
    /* 49D8 800FE1D8 17004010 */  beqz       $v0, .L800FE238
    /* 49DC 800FE1DC 21880000 */   addu      $s1, $zero, $zero
    /* 49E0 800FE1E0 21980002 */  addu       $s3, $s0, $zero
    /* 49E4 800FE1E4 2190A000 */  addu       $s2, $a1, $zero
    /* 49E8 800FE1E8 1080023C */  lui        $v0, %hi(D_801021F4)
    /* 49EC 800FE1EC F4215024 */  addiu      $s0, $v0, %lo(D_801021F4)
  .L800FE1F0:
    /* 49F0 800FE1F0 45256292 */  lbu        $v0, %lo(vs_mainMenu_equipmentSubtype)($s3)
    /* 49F4 800FE1F4 00000000 */  nop
    /* 49F8 800FE1F8 07102202 */  srav       $v0, $v0, $s1
    /* 49FC 800FE1FC 01004230 */  andi       $v0, $v0, 0x1
    /* 4A00 800FE200 07004010 */  beqz       $v0, .L800FE220
    /* 4A04 800FE204 00000000 */   nop
    /* 4A08 800FE208 B8244492 */  lbu        $a0, %lo(D_801024B8)($s2)
    /* 4A0C 800FE20C 0000028E */  lw         $v0, 0x0($s0)
    /* 4A10 800FE210 00000000 */  nop
    /* 4A14 800FE214 09F84000 */  jalr       $v0
    /* 4A18 800FE218 F7FF8424 */   addiu     $a0, $a0, -0x9
    /* 4A1C 800FE21C 21A04000 */  addu       $s4, $v0, $zero
  .L800FE220:
    /* 4A20 800FE220 01003126 */  addiu      $s1, $s1, 0x1
    /* 4A24 800FE224 0700222A */  slti       $v0, $s1, 0x7
    /* 4A28 800FE228 F1FF4014 */  bnez       $v0, .L800FE1F0
    /* 4A2C 800FE22C 04001026 */   addiu     $s0, $s0, 0x4
    /* 4A30 800FE230 ADF80308 */  j          .L800FE2B4
    /* 4A34 800FE234 00000000 */   nop
  .L800FE238:
    /* 4A38 800FE238 0F000224 */  addiu      $v0, $zero, 0xF
    /* 4A3C 800FE23C 04006214 */  bne        $v1, $v0, .L800FE250
    /* 4A40 800FE240 1080023C */   lui       $v0, %hi(vs_mainMenu_itemHelp)
    /* 4A44 800FE244 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 4A48 800FE248 ADF80308 */  j          .L800FE2B4
    /* 4A4C 800FE24C 2E685424 */   addiu     $s4, $v0, 0x682E
  .L800FE250:
    /* 4A50 800FE250 B824A390 */  lbu        $v1, %lo(D_801024B8)($a1)
    /* 4A54 800FE254 4025458C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v0)
    /* 4A58 800FE258 40100300 */  sll        $v0, $v1, 1
    /* 4A5C 800FE25C 21204500 */  addu       $a0, $v0, $a1
    /* 4A60 800FE260 40038294 */  lhu        $v0, 0x340($a0)
    /* 4A64 800FE264 1200632C */  sltiu      $v1, $v1, 0x12
    /* 4A68 800FE268 40100200 */  sll        $v0, $v0, 1
    /* 4A6C 800FE26C 11006014 */  bnez       $v1, .L800FE2B4
    /* 4A70 800FE270 21A0A200 */   addu      $s4, $a1, $v0
    /* 4A74 800FE274 45250392 */  lbu        $v1, %lo(vs_mainMenu_equipmentSubtype)($s0)
    /* 4A78 800FE278 00000000 */  nop
    /* 4A7C 800FE27C 07006230 */  andi       $v0, $v1, 0x7
    /* 4A80 800FE280 06004010 */  beqz       $v0, .L800FE29C
    /* 4A84 800FE284 18006230 */   andi      $v0, $v1, 0x18
    /* 4A88 800FE288 00058294 */  lhu        $v0, 0x500($a0)
    /* 4A8C 800FE28C 00000000 */  nop
    /* 4A90 800FE290 40100200 */  sll        $v0, $v0, 1
    /* 4A94 800FE294 21A0A200 */  addu       $s4, $a1, $v0
    /* 4A98 800FE298 18006230 */  andi       $v0, $v1, 0x18
  .L800FE29C:
    /* 4A9C 800FE29C 05004010 */  beqz       $v0, .L800FE2B4
    /* 4AA0 800FE2A0 00000000 */   nop
    /* 4AA4 800FE2A4 06058294 */  lhu        $v0, 0x506($a0)
    /* 4AA8 800FE2A8 00000000 */  nop
    /* 4AAC 800FE2AC 40100200 */  sll        $v0, $v0, 1
    /* 4AB0 800FE2B0 21A0A200 */  addu       $s4, $a1, $v0
  .L800FE2B4:
    /* 4AB4 800FE2B4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4AB8 800FE2B8 21208002 */   addu      $a0, $s4, $zero
    /* 4ABC 800FE2BC 1080033C */  lui        $v1, %hi(D_801021A0)
    /* 4AC0 800FE2C0 1080023C */  lui        $v0, %hi(D_801024B8)
    /* 4AC4 800FE2C4 B8244490 */  lbu        $a0, %lo(D_801024B8)($v0)
    /* 4AC8 800FE2C8 A0216324 */  addiu      $v1, $v1, %lo(D_801021A0)
    /* 4ACC 800FE2CC 80100400 */  sll        $v0, $a0, 2
    /* 4AD0 800FE2D0 21104300 */  addu       $v0, $v0, $v1
    /* 4AD4 800FE2D4 0000518C */  lw         $s1, 0x0($v0)
    /* 4AD8 800FE2D8 0F000224 */  addiu      $v0, $zero, 0xF
    /* 4ADC 800FE2DC 07008214 */  bne        $a0, $v0, .L800FE2FC
    /* 4AE0 800FE2E0 1080023C */   lui       $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 4AE4 800FE2E4 1080023C */  lui        $v0, %hi(D_8010214A)
    /* 4AE8 800FE2E8 4A214290 */  lbu        $v0, %lo(D_8010214A)($v0)
    /* 4AEC 800FE2EC 00000000 */  nop
    /* 4AF0 800FE2F0 00150200 */  sll        $v0, $v0, 20
    /* 4AF4 800FE2F4 21882202 */  addu       $s1, $s1, $v0
    /* 4AF8 800FE2F8 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
  .L800FE2FC:
    /* 4AFC 800FE2FC 45254290 */  lbu        $v0, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 4B00 800FE300 00000000 */  nop
    /* 4B04 800FE304 08004230 */  andi       $v0, $v0, 0x8
    /* 4B08 800FE308 05004010 */  beqz       $v0, .L800FE320
    /* 4B0C 800FE30C F6FF8224 */   addiu     $v0, $a0, -0xA
    /* 4B10 800FE310 0200422C */  sltiu      $v0, $v0, 0x2
    /* 4B14 800FE314 03004010 */  beqz       $v0, .L800FE324
    /* 4B18 800FE318 1080103C */   lui       $s0, %hi(D_80102210)
    /* 4B1C 800FE31C 07003126 */  addiu      $s1, $s1, 0x7
  .L800FE320:
    /* 4B20 800FE320 1080103C */  lui        $s0, %hi(D_80102210)
  .L800FE324:
    /* 4B24 800FE324 10220492 */  lbu        $a0, %lo(D_80102210)($s0)
    /* 4B28 800FE328 37FF030C */  jal        func_800FFCDC
    /* 4B2C 800FE32C 21282002 */   addu      $a1, $s1, $zero
    /* 4B30 800FE330 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4B34 800FE334 2400B58F */  lw         $s5, 0x24($sp)
    /* 4B38 800FE338 2000B48F */  lw         $s4, 0x20($sp)
    /* 4B3C 800FE33C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4B40 800FE340 1800B28F */  lw         $s2, 0x18($sp)
    /* 4B44 800FE344 1400B18F */  lw         $s1, 0x14($sp)
    /* 4B48 800FE348 102202A2 */  sb         $v0, %lo(D_80102210)($s0)
    /* 4B4C 800FE34C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4B50 800FE350 1080023C */  lui        $v0, %hi(D_8010214A)
    /* 4B54 800FE354 4A2140A0 */  sb         $zero, %lo(D_8010214A)($v0)
    /* 4B58 800FE358 0800E003 */  jr         $ra
    /* 4B5C 800FE35C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800FDEBC
