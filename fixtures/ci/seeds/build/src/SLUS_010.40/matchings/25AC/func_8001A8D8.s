nonmatching func_8001A8D8, 0x788

glabel func_8001A8D8
    /* B0D8 8001A8D8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* B0DC 8001A8DC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* B0E0 8001A8E0 21888000 */  addu       $s1, $a0, $zero
    /* B0E4 8001A8E4 2000B2AF */  sw         $s2, 0x20($sp)
    /* B0E8 8001A8E8 2190A000 */  addu       $s2, $a1, $zero
    /* B0EC 8001A8EC 0380023C */  lui        $v0, %hi(D_80030760)
    /* B0F0 8001A8F0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* B0F4 8001A8F4 60075524 */  addiu      $s5, $v0, %lo(D_80030760)
    /* B0F8 8001A8F8 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* B0FC 8001A8FC 2400B3AF */  sw         $s3, 0x24($sp)
    /* B100 8001A900 90785324 */  addiu      $s3, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* B104 8001A904 0380023C */  lui        $v0, %hi(D_800305E0)
    /* B108 8001A908 2800B4AF */  sw         $s4, 0x28($sp)
    /* B10C 8001A90C E0055424 */  addiu      $s4, $v0, %lo(D_800305E0)
    /* B110 8001A910 3000BFAF */  sw         $ra, 0x30($sp)
    /* B114 8001A914 1800B0AF */  sw         $s0, 0x18($sp)
  .L8001A918:
    /* B118 8001A918 0000258E */  lw         $a1, 0x0($s1)
    /* B11C 8001A91C 00000000 */  nop
    /* B120 8001A920 0000B090 */  lbu        $s0, 0x0($a1)
    /* B124 8001A924 0100A524 */  addiu      $a1, $a1, 0x1
    /* B128 8001A928 A000022E */  sltiu      $v0, $s0, 0xA0
    /* B12C 8001A92C 2E004014 */  bnez       $v0, .L8001A9E8
    /* B130 8001A930 000025AE */   sw        $a1, 0x0($s1)
    /* B134 8001A934 FE000224 */  addiu      $v0, $zero, 0xFE
    /* B138 8001A938 08000216 */  bne        $s0, $v0, .L8001A95C
    /* B13C 8001A93C 10FF0326 */   addiu     $v1, $s0, -0xF0
    /* B140 8001A940 21202002 */  addu       $a0, $s1, $zero
    /* B144 8001A944 0000A690 */  lbu        $a2, 0x0($a1)
    /* B148 8001A948 0100A224 */  addiu      $v0, $a1, 0x1
    /* B14C 8001A94C 000022AE */  sw         $v0, 0x0($s1)
    /* B150 8001A950 80100600 */  sll        $v0, $a2, 2
    /* B154 8001A954 766A0008 */  j          .L8001A9D8
    /* B158 8001A958 21105500 */   addu      $v0, $v0, $s5
  .L8001A95C:
    /* B15C 8001A95C 0E00622C */  sltiu      $v0, $v1, 0xE
    /* B160 8001A960 09004010 */  beqz       $v0, .L8001A988
    /* B164 8001A964 40100300 */   sll       $v0, $v1, 1
    /* B168 8001A968 21104300 */  addu       $v0, $v0, $v1
    /* B16C 8001A96C 80100200 */  sll        $v0, $v0, 2
    /* B170 8001A970 23804300 */  subu       $s0, $v0, $v1
    /* B174 8001A974 0000A390 */  lbu        $v1, 0x0($a1)
    /* B178 8001A978 0100A224 */  addiu      $v0, $a1, 0x1
    /* B17C 8001A97C 000022AE */  sw         $v0, 0x0($s1)
    /* B180 8001A980 7A6A0008 */  j          .L8001A9E8
    /* B184 8001A984 660023A6 */   sh        $v1, 0x66($s1)
  .L8001A988:
    /* B188 8001A988 FF000224 */  addiu      $v0, $zero, 0xFF
    /* B18C 8001A98C 03000216 */  bne        $s0, $v0, .L8001A99C
    /* B190 8001A990 CA000224 */   addiu     $v0, $zero, 0xCA
    /* B194 8001A994 726A0008 */  j          .L8001A9C8
    /* B198 8001A998 A0001024 */   addiu     $s0, $zero, 0xA0
  .L8001A99C:
    /* B19C 8001A99C 0B000216 */  bne        $s0, $v0, .L8001A9CC
    /* B1A0 8001A9A0 21202002 */   addu      $a0, $s1, $zero
    /* B1A4 8001A9A4 3400228E */  lw         $v0, 0x34($s1)
    /* B1A8 8001A9A8 2000033C */  lui        $v1, (0x200000 >> 16)
    /* B1AC 8001A9AC 24104300 */  and        $v0, $v0, $v1
    /* B1B0 8001A9B0 07004010 */  beqz       $v0, .L8001A9D0
    /* B1B4 8001A9B4 60FF0226 */   addiu     $v0, $s0, -0xA0
    /* B1B8 8001A9B8 0C00628E */  lw         $v0, 0xC($s3)
    /* B1BC 8001A9BC A0001024 */  addiu      $s0, $zero, 0xA0
    /* B1C0 8001A9C0 25105200 */  or         $v0, $v0, $s2
    /* B1C4 8001A9C4 0C0062AE */  sw         $v0, 0xC($s3)
  .L8001A9C8:
    /* B1C8 8001A9C8 21202002 */  addu       $a0, $s1, $zero
  .L8001A9CC:
    /* B1CC 8001A9CC 60FF0226 */  addiu      $v0, $s0, -0xA0
  .L8001A9D0:
    /* B1D0 8001A9D0 80100200 */  sll        $v0, $v0, 2
    /* B1D4 8001A9D4 21105400 */  addu       $v0, $v0, $s4
  .L8001A9D8:
    /* B1D8 8001A9D8 0000428C */  lw         $v0, 0x0($v0)
    /* B1DC 8001A9DC 00000000 */  nop
    /* B1E0 8001A9E0 09F84000 */  jalr       $v0
    /* B1E4 8001A9E4 21284002 */   addu      $a1, $s2, $zero
  .L8001A9E8:
    /* B1E8 8001A9E8 70002296 */  lhu        $v0, 0x70($s1)
    /* B1EC 8001A9EC 00000000 */  nop
    /* B1F0 8001A9F0 01004224 */  addiu      $v0, $v0, 0x1
    /* B1F4 8001A9F4 700022A6 */  sh         $v0, 0x70($s1)
    /* B1F8 8001A9F8 A100022E */  sltiu      $v0, $s0, 0xA1
    /* B1FC 8001A9FC C6FF4010 */  beqz       $v0, .L8001A918
    /* B200 8001AA00 A0000224 */   addiu     $v0, $zero, 0xA0
    /* B204 8001AA04 0C000216 */  bne        $s0, $v0, .L8001AA38
    /* B208 8001AA08 00000000 */   nop
    /* B20C 8001AA0C 64002296 */  lhu        $v0, 0x64($s1)
    /* B210 8001AA10 00000000 */  nop
    /* B214 8001AA14 89014014 */  bnez       $v0, .L8001B03C
    /* B218 8001AA18 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* B21C 8001AA1C 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* B220 8001AA20 00000000 */  nop
    /* B224 8001AA24 1800628C */  lw         $v0, 0x18($v1)
    /* B228 8001AA28 00000000 */  nop
    /* B22C 8001AA2C 25105200 */  or         $v0, $v0, $s2
    /* B230 8001AA30 0F6C0008 */  j          .L8001B03C
    /* B234 8001AA34 180062AC */   sw        $v0, 0x18($v1)
  .L8001AA38:
    /* B238 8001AA38 F167000C */  jal        func_80019FC4
    /* B23C 8001AA3C 21202002 */   addu      $a0, $s1, $zero
    /* B240 8001AA40 FF004630 */  andi       $a2, $v0, 0xFF
    /* B244 8001AA44 D6002286 */  lh         $v0, 0xD6($s1)
    /* B248 8001AA48 D6002396 */  lhu        $v1, 0xD6($s1)
    /* B24C 8001AA4C 03004010 */  beqz       $v0, .L8001AA5C
    /* B250 8001AA50 00000000 */   nop
    /* B254 8001AA54 680023A6 */  sh         $v1, 0x68($s1)
    /* B258 8001AA58 660023A6 */  sh         $v1, 0x66($s1)
  .L8001AA5C:
    /* B25C 8001AA5C 66002296 */  lhu        $v0, 0x66($s1)
    /* B260 8001AA60 00000000 */  nop
    /* B264 8001AA64 0F004010 */  beqz       $v0, .L8001AAA4
    /* B268 8001AA68 8F00C22C */   sltiu     $v0, $a2, 0x8F
    /* B26C 8001AA6C 08004010 */  beqz       $v0, .L8001AA90
    /* B270 8001AA70 8400C22C */   sltiu     $v0, $a2, 0x84
    /* B274 8001AA74 27004010 */  beqz       $v0, .L8001AB14
    /* B278 8001AA78 00000000 */   nop
    /* B27C 8001AA7C 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B280 8001AA80 00000000 */  nop
    /* B284 8001AA84 05004230 */  andi       $v0, $v0, 0x5
    /* B288 8001AA88 22004014 */  bnez       $v0, .L8001AB14
    /* B28C 8001AA8C 00000000 */   nop
  .L8001AA90:
    /* B290 8001AA90 68002296 */  lhu        $v0, 0x68($s1)
    /* B294 8001AA94 00000000 */  nop
    /* B298 8001AA98 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* B29C 8001AA9C C56A0008 */  j          .L8001AB14
    /* B2A0 8001AAA0 680022A6 */   sh        $v0, 0x68($s1)
  .L8001AAA4:
    /* B2A4 8001AAA4 2EBA023C */  lui        $v0, (0xBA2E8BA3 >> 16)
    /* B2A8 8001AAA8 A38B4234 */  ori        $v0, $v0, (0xBA2E8BA3 & 0xFFFF)
    /* B2AC 8001AAAC 19000202 */  multu      $s0, $v0
    /* B2B0 8001AAB0 0380043C */  lui        $a0, %hi(D_8002F620)
    /* B2B4 8001AAB4 20F68424 */  addiu      $a0, $a0, %lo(D_8002F620)
    /* B2B8 8001AAB8 10400000 */  mfhi       $t0
    /* B2BC 8001AABC C2180800 */  srl        $v1, $t0, 3
    /* B2C0 8001AAC0 40100300 */  sll        $v0, $v1, 1
    /* B2C4 8001AAC4 21104300 */  addu       $v0, $v0, $v1
    /* B2C8 8001AAC8 80100200 */  sll        $v0, $v0, 2
    /* B2CC 8001AACC 23104300 */  subu       $v0, $v0, $v1
    /* B2D0 8001AAD0 23100202 */  subu       $v0, $s0, $v0
    /* B2D4 8001AAD4 40100200 */  sll        $v0, $v0, 1
    /* B2D8 8001AAD8 21104400 */  addu       $v0, $v0, $a0
    /* B2DC 8001AADC 00004294 */  lhu        $v0, 0x0($v0)
    /* B2E0 8001AAE0 00000000 */  nop
    /* B2E4 8001AAE4 21184000 */  addu       $v1, $v0, $zero
    /* B2E8 8001AAE8 7CFFC224 */  addiu      $v0, $a2, -0x84
    /* B2EC 8001AAEC 0B00422C */  sltiu      $v0, $v0, 0xB
    /* B2F0 8001AAF0 07004014 */  bnez       $v0, .L8001AB10
    /* B2F4 8001AAF4 660023A6 */   sh        $v1, 0x66($s1)
    /* B2F8 8001AAF8 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B2FC 8001AAFC 00000000 */  nop
    /* B300 8001AB00 05004230 */  andi       $v0, $v0, 0x5
    /* B304 8001AB04 02004014 */  bnez       $v0, .L8001AB10
    /* B308 8001AB08 00000000 */   nop
    /* B30C 8001AB0C FEFF6324 */  addiu      $v1, $v1, -0x2
  .L8001AB10:
    /* B310 8001AB10 680023A6 */  sh         $v1, 0x68($s1)
  .L8001AB14:
    /* B314 8001AB14 64002296 */  lhu        $v0, 0x64($s1)
    /* B318 8001AB18 00000000 */  nop
    /* B31C 8001AB1C 09004014 */  bnez       $v0, .L8001AB44
    /* B320 8001AB20 00000000 */   nop
    /* B324 8001AB24 3400228E */  lw         $v0, 0x34($s1)
    /* B328 8001AB28 00000000 */  nop
    /* B32C 8001AB2C 40004230 */  andi       $v0, $v0, 0x40
    /* B330 8001AB30 04004010 */  beqz       $v0, .L8001AB44
    /* B334 8001AB34 00000000 */   nop
    /* B338 8001AB38 66002296 */  lhu        $v0, 0x66($s1)
    /* B33C 8001AB3C 00000000 */  nop
    /* B340 8001AB40 680022A6 */  sh         $v0, 0x68($s1)
  .L8001AB44:
    /* B344 8001AB44 F800238E */  lw         $v1, 0xF8($s1)
    /* B348 8001AB48 66002296 */  lhu        $v0, 0x66($s1)
    /* B34C 8001AB4C 00406334 */  ori        $v1, $v1, 0x4000
    /* B350 8001AB50 D40022A6 */  sh         $v0, 0xD4($s1)
    /* B354 8001AB54 8F00022E */  sltiu      $v0, $s0, 0x8F
    /* B358 8001AB58 1B004014 */  bnez       $v0, .L8001ABC8
    /* B35C 8001AB5C F80023AE */   sw        $v1, 0xF8($s1)
    /* B360 8001AB60 64002296 */  lhu        $v0, 0x64($s1)
    /* B364 8001AB64 00000000 */  nop
    /* B368 8001AB68 10004014 */  bnez       $v0, .L8001ABAC
    /* B36C 8001AB6C 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* B370 8001AB70 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* B374 8001AB74 00000000 */  nop
    /* B378 8001AB78 1400828C */  lw         $v0, 0x14($a0)
    /* B37C 8001AB7C 27181200 */  nor        $v1, $zero, $s2
    /* B380 8001AB80 24104300 */  and        $v0, $v0, $v1
    /* B384 8001AB84 140082AC */  sw         $v0, 0x14($a0)
    /* B388 8001AB88 F400228E */  lw         $v0, 0xF4($s1)
    /* B38C 8001AB8C 00000000 */  nop
    /* B390 8001AB90 1800422C */  sltiu      $v0, $v0, 0x18
    /* B394 8001AB94 05004010 */  beqz       $v0, .L8001ABAC
    /* B398 8001AB98 00000000 */   nop
    /* B39C 8001AB9C 1800828C */  lw         $v0, 0x18($a0)
    /* B3A0 8001ABA0 00000000 */  nop
    /* B3A4 8001ABA4 25105200 */  or         $v0, $v0, $s2
    /* B3A8 8001ABA8 180082AC */  sw         $v0, 0x18($a0)
  .L8001ABAC:
    /* B3AC 8001ABAC 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B3B0 8001ABB0 9A0020A6 */  sh         $zero, 0x9A($s1)
    /* B3B4 8001ABB4 EC0020A6 */  sh         $zero, 0xEC($s1)
    /* B3B8 8001ABB8 EE0020A6 */  sh         $zero, 0xEE($s1)
    /* B3BC 8001ABBC FDFF4230 */  andi       $v0, $v0, 0xFFFD
    /* B3C0 8001ABC0 0F6C0008 */  j          .L8001B03C
    /* B3C4 8001ABC4 9C0022A6 */   sh        $v0, 0x9C($s1)
  .L8001ABC8:
    /* B3C8 8001ABC8 8400022E */  sltiu      $v0, $s0, 0x84
    /* B3CC 8001ABCC E8004010 */  beqz       $v0, .L8001AF70
    /* B3D0 8001ABD0 00000000 */   nop
    /* B3D4 8001ABD4 2EBA023C */  lui        $v0, (0xBA2E8BA3 >> 16)
    /* B3D8 8001ABD8 A38B4234 */  ori        $v0, $v0, (0xBA2E8BA3 & 0xFFFF)
    /* B3DC 8001ABDC 19000202 */  multu      $s0, $v0
    /* B3E0 8001ABE0 94002396 */  lhu        $v1, 0x94($s1)
    /* B3E4 8001ABE4 3400258E */  lw         $a1, 0x34($s1)
    /* B3E8 8001ABE8 40100300 */  sll        $v0, $v1, 1
    /* B3EC 8001ABEC 21104300 */  addu       $v0, $v0, $v1
    /* B3F0 8001ABF0 80100200 */  sll        $v0, $v0, 2
    /* B3F4 8001ABF4 10400000 */  mfhi       $t0
    /* B3F8 8001ABF8 C2800800 */  srl        $s0, $t0, 3
    /* B3FC 8001ABFC 21800202 */  addu       $s0, $s0, $v0
    /* B400 8001AC00 0800A230 */  andi       $v0, $a1, 0x8
    /* B404 8001AC04 06004010 */  beqz       $v0, .L8001AC20
    /* B408 8001AC08 21202002 */   addu      $a0, $s1, $zero
    /* B40C 8001AC0C 21284002 */  addu       $a1, $s2, $zero
    /* B410 8001AC10 9369000C */  jal        func_8001A64C
    /* B414 8001AC14 21300002 */   addu      $a2, $s0, $zero
    /* B418 8001AC18 906B0008 */  j          .L8001AE40
    /* B41C 8001AC1C 21304000 */   addu      $a2, $v0, $zero
  .L8001AC20:
    /* B420 8001AC20 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B424 8001AC24 00000000 */  nop
    /* B428 8001AC28 02004230 */  andi       $v0, $v0, 0x2
    /* B42C 8001AC2C 41004014 */  bnez       $v0, .L8001AD34
    /* B430 8001AC30 00000000 */   nop
    /* B434 8001AC34 64002296 */  lhu        $v0, 0x64($s1)
    /* B438 8001AC38 00000000 */  nop
    /* B43C 8001AC3C 37004014 */  bnez       $v0, .L8001AD1C
    /* B440 8001AC40 0380033C */   lui       $v1, %hi(g_Sound_VoiceSchedulerState)
    /* B444 8001AC44 0480023C */  lui        $v0, %hi(D_80039AFC)
    /* B448 8001AC48 FC9A428C */  lw         $v0, %lo(D_80039AFC)($v0)
    /* B44C 8001AC4C 00000000 */  nop
    /* B450 8001AC50 10004230 */  andi       $v0, $v0, 0x10
    /* B454 8001AC54 10004010 */  beqz       $v0, .L8001AC98
    /* B458 8001AC58 0380043C */   lui       $a0, %hi(g_pActiveMusicConfig)
    /* B45C 8001AC5C AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* B460 8001AC60 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* B464 8001AC64 19000202 */  multu      $s0, $v0
    /* B468 8001AC68 10400000 */  mfhi       $t0
    /* B46C 8001AC6C C2180800 */  srl        $v1, $t0, 3
    /* B470 8001AC70 40100300 */  sll        $v0, $v1, 1
    /* B474 8001AC74 21104300 */  addu       $v0, $v0, $v1
    /* B478 8001AC78 2078838C */  lw         $v1, %lo(g_pActiveMusicConfig)($a0)
    /* B47C 8001AC7C 80100200 */  sll        $v0, $v0, 2
    /* B480 8001AC80 4400638C */  lw         $v1, 0x44($v1)
    /* B484 8001AC84 23100202 */  subu       $v0, $s0, $v0
    /* B488 8001AC88 21186200 */  addu       $v1, $v1, $v0
    /* B48C 8001AC8C 00006280 */  lb         $v0, 0x0($v1)
    /* B490 8001AC90 00000000 */  nop
    /* B494 8001AC94 21800202 */  addu       $s0, $s0, $v0
  .L8001AC98:
    /* B498 8001AC98 0010A230 */  andi       $v0, $a1, 0x1000
    /* B49C 8001AC9C 03004010 */  beqz       $v0, .L8001ACAC
    /* B4A0 8001ACA0 21202002 */   addu      $a0, $s1, $zero
    /* B4A4 8001ACA4 9668000C */  jal        func_8001A258
    /* B4A8 8001ACA8 21280002 */   addu      $a1, $s0, $zero
  .L8001ACAC:
    /* B4AC 8001ACAC 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* B4B0 8001ACB0 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* B4B4 8001ACB4 00000000 */  nop
    /* B4B8 8001ACB8 1000828C */  lw         $v0, 0x10($a0)
    /* B4BC 8001ACBC 1400838C */  lw         $v1, 0x14($a0)
    /* B4C0 8001ACC0 25105200 */  or         $v0, $v0, $s2
    /* B4C4 8001ACC4 24187200 */  and        $v1, $v1, $s2
    /* B4C8 8001ACC8 0A006010 */  beqz       $v1, .L8001ACF4
    /* B4CC 8001ACCC 100082AC */   sw        $v0, 0x10($a0)
    /* B4D0 8001ACD0 F400228E */  lw         $v0, 0xF4($s1)
    /* B4D4 8001ACD4 00000000 */  nop
    /* B4D8 8001ACD8 1800422C */  sltiu      $v0, $v0, 0x18
    /* B4DC 8001ACDC 05004010 */  beqz       $v0, .L8001ACF4
    /* B4E0 8001ACE0 00000000 */   nop
    /* B4E4 8001ACE4 1800828C */  lw         $v0, 0x18($a0)
    /* B4E8 8001ACE8 00000000 */  nop
    /* B4EC 8001ACEC 25105200 */  or         $v0, $v0, $s2
    /* B4F0 8001ACF0 180082AC */  sw         $v0, 0x18($a0)
  .L8001ACF4:
    /* B4F4 8001ACF4 8A002496 */  lhu        $a0, 0x8A($s1)
    /* B4F8 8001ACF8 00000000 */  nop
    /* B4FC 8001ACFC 0C008010 */  beqz       $a0, .L8001AD30
    /* B500 8001AD00 00000000 */   nop
    /* B504 8001AD04 5C00228E */  lw         $v0, 0x5C($s1)
    /* B508 8001AD08 6000238E */  lw         $v1, 0x60($s1)
    /* B50C 8001AD0C 880024A6 */  sh         $a0, 0x88($s1)
    /* B510 8001AD10 480022AE */  sw         $v0, 0x48($s1)
    /* B514 8001AD14 4C6B0008 */  j          .L8001AD30
    /* B518 8001AD18 4C0023AE */   sw        $v1, 0x4C($s1)
  .L8001AD1C:
    /* B51C 8001AD1C 90786324 */  addiu      $v1, $v1, %lo(g_Sound_VoiceSchedulerState)
    /* B520 8001AD20 0400628C */  lw         $v0, 0x4($v1)
    /* B524 8001AD24 00000000 */  nop
    /* B528 8001AD28 25105200 */  or         $v0, $v0, $s2
    /* B52C 8001AD2C 040062AC */  sw         $v0, 0x4($v1)
  .L8001AD30:
    /* B530 8001AD30 920020A6 */  sh         $zero, 0x92($s1)
  .L8001AD34:
    /* B534 8001AD34 9A002396 */  lhu        $v1, 0x9A($s1)
    /* B538 8001AD38 00000000 */  nop
    /* B53C 8001AD3C 16006010 */  beqz       $v1, .L8001AD98
    /* B540 8001AD40 00000000 */   nop
    /* B544 8001AD44 98002296 */  lhu        $v0, 0x98($s1)
    /* B548 8001AD48 00000000 */  nop
    /* B54C 8001AD4C 12004010 */  beqz       $v0, .L8001AD98
    /* B550 8001AD50 00000000 */   nop
    /* B554 8001AD54 E2002296 */  lhu        $v0, 0xE2($s1)
    /* B558 8001AD58 98002496 */  lhu        $a0, 0x98($s1)
    /* B55C 8001AD5C 960023A6 */  sh         $v1, 0x96($s1)
    /* B560 8001AD60 EA002386 */  lh         $v1, 0xEA($s1)
    /* B564 8001AD64 21105000 */  addu       $v0, $v0, $s0
    /* B568 8001AD68 21808300 */  addu       $s0, $a0, $v1
    /* B56C 8001AD6C 98002396 */  lhu        $v1, 0x98($s1)
    /* B570 8001AD70 EA002496 */  lhu        $a0, 0xEA($s1)
    /* B574 8001AD74 23104300 */  subu       $v0, $v0, $v1
    /* B578 8001AD78 E2002396 */  lhu        $v1, 0xE2($s1)
    /* B57C 8001AD7C 23104400 */  subu       $v0, $v0, $a0
    /* B580 8001AD80 E80022A6 */  sh         $v0, 0xE8($s1)
    /* B584 8001AD84 98002296 */  lhu        $v0, 0x98($s1)
    /* B588 8001AD88 23186400 */  subu       $v1, $v1, $a0
    /* B58C 8001AD8C 23104300 */  subu       $v0, $v0, $v1
    /* B590 8001AD90 696B0008 */  j          .L8001ADA4
    /* B594 8001AD94 E60022A6 */   sh        $v0, 0xE6($s1)
  .L8001AD98:
    /* B598 8001AD98 E2002286 */  lh         $v0, 0xE2($s1)
    /* B59C 8001AD9C E60030A6 */  sh         $s0, 0xE6($s1)
    /* B5A0 8001ADA0 21800202 */  addu       $s0, $s0, $v0
  .L8001ADA4:
    /* B5A4 8001ADA4 21280002 */  addu       $a1, $s0, $zero
    /* B5A8 8001ADA8 54002726 */  addiu      $a3, $s1, 0x54
    /* B5AC 8001ADAC 0380043C */  lui        $a0, %hi(g_InstrumentInfo)
    /* B5B0 8001ADB0 88678424 */  addiu      $a0, $a0, %lo(g_InstrumentInfo)
    /* B5B4 8001ADB4 6A002296 */  lhu        $v0, 0x6A($s1)
    /* B5B8 8001ADB8 E4002686 */  lh         $a2, 0xE4($s1)
    /* B5BC 8001ADBC 00110200 */  sll        $v0, $v0, 4
    /* B5C0 8001ADC0 2F69000C */  jal        func_8001A4BC
    /* B5C4 8001ADC4 21204400 */   addu      $a0, $v0, $a0
    /* B5C8 8001ADC8 D2002396 */  lhu        $v1, 0xD2($s1)
    /* B5CC 8001ADCC 00000000 */  nop
    /* B5D0 8001ADD0 1B006010 */  beqz       $v1, .L8001AE40
    /* B5D4 8001ADD4 21304000 */   addu      $a2, $v0, $zero
    /* B5D8 8001ADD8 21106000 */  addu       $v0, $v1, $zero
    /* B5DC 8001ADDC 1800C200 */  mult       $a2, $v0
    /* B5E0 8001ADE0 0380023C */  lui        $v0, %hi(D_8002F69C)
    /* B5E4 8001ADE4 12180000 */  mflo       $v1
    /* B5E8 8001ADE8 02220300 */  srl        $a0, $v1, 8
    /* B5EC 8001ADEC 0480033C */  lui        $v1, %hi(g_Sound_LfoPhase)
    /* B5F0 8001ADF0 E89A638C */  lw         $v1, %lo(g_Sound_LfoPhase)($v1)
    /* B5F4 8001ADF4 9CF64224 */  addiu      $v0, $v0, %lo(D_8002F69C)
    /* B5F8 8001ADF8 1000A4AF */  sw         $a0, 0x10($sp)
    /* B5FC 8001ADFC 21186200 */  addu       $v1, $v1, $v0
    /* B600 8001AE00 00006290 */  lbu        $v0, 0x0($v1)
    /* B604 8001AE04 00000000 */  nop
    /* B608 8001AE08 18008200 */  mult       $a0, $v0
    /* B60C 8001AE0C 12200000 */  mflo       $a0
    /* B610 8001AE10 1000A4AF */  sw         $a0, 0x10($sp)
    /* B614 8001AE14 00006290 */  lbu        $v0, 0x0($v1)
    /* B618 8001AE18 00000000 */  nop
    /* B61C 8001AE1C 80004230 */  andi       $v0, $v0, 0x80
    /* B620 8001AE20 04004010 */  beqz       $v0, .L8001AE34
    /* B624 8001AE24 42120400 */   srl       $v0, $a0, 9
    /* B628 8001AE28 1000A2AF */  sw         $v0, 0x10($sp)
    /* B62C 8001AE2C 906B0008 */  j          .L8001AE40
    /* B630 8001AE30 2330C200 */   subu      $a2, $a2, $v0
  .L8001AE34:
    /* B634 8001AE34 C2110400 */  srl        $v0, $a0, 7
    /* B638 8001AE38 1000A2AF */  sw         $v0, 0x10($sp)
    /* B63C 8001AE3C 2130C200 */  addu       $a2, $a2, $v0
  .L8001AE40:
    /* B640 8001AE40 64002296 */  lhu        $v0, 0x64($s1)
    /* B644 8001AE44 00000000 */  nop
    /* B648 8001AE48 09004014 */  bnez       $v0, .L8001AE70
    /* B64C 8001AE4C 2C0026AE */   sw        $a2, 0x2C($s1)
    /* B650 8001AE50 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* B654 8001AE54 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* B658 8001AE58 00000000 */  nop
    /* B65C 8001AE5C 1400628C */  lw         $v0, 0x14($v1)
    /* B660 8001AE60 00000000 */  nop
    /* B664 8001AE64 25105200 */  or         $v0, $v0, $s2
    /* B668 8001AE68 A26B0008 */  j          .L8001AE88
    /* B66C 8001AE6C 140062AC */   sw        $v0, 0x14($v1)
  .L8001AE70:
    /* B670 8001AE70 0380033C */  lui        $v1, %hi(g_Sound_VoiceSchedulerState)
    /* B674 8001AE74 90786324 */  addiu      $v1, $v1, %lo(g_Sound_VoiceSchedulerState)
    /* B678 8001AE78 0800628C */  lw         $v0, 0x8($v1)
    /* B67C 8001AE7C 00000000 */  nop
    /* B680 8001AE80 25105200 */  or         $v0, $v0, $s2
    /* B684 8001AE84 080062AC */  sw         $v0, 0x8($v1)
  .L8001AE88:
    /* B688 8001AE88 F800228E */  lw         $v0, 0xF8($s1)
    /* B68C 8001AE8C 3400308E */  lw         $s0, 0x34($s1)
    /* B690 8001AE90 13004234 */  ori        $v0, $v0, 0x13
    /* B694 8001AE94 F80022AE */  sw         $v0, 0xF8($s1)
    /* B698 8001AE98 01000232 */  andi       $v0, $s0, 0x1
    /* B69C 8001AE9C 20004010 */  beqz       $v0, .L8001AF20
    /* B6A0 8001AEA0 02000232 */   andi      $v0, $s0, 0x2
    /* B6A4 8001AEA4 AA002296 */  lhu        $v0, 0xAA($s1)
    /* B6A8 8001AEA8 00000000 */  nop
    /* B6AC 8001AEAC 007F4330 */  andi       $v1, $v0, 0x7F00
    /* B6B0 8001AEB0 00804230 */  andi       $v0, $v0, 0x8000
    /* B6B4 8001AEB4 06004014 */  bnez       $v0, .L8001AED0
    /* B6B8 8001AEB8 021A0300 */   srl       $v1, $v1, 8
    /* B6BC 8001AEBC 00110600 */  sll        $v0, $a2, 4
    /* B6C0 8001AEC0 23104600 */  subu       $v0, $v0, $a2
    /* B6C4 8001AEC4 02120200 */  srl        $v0, $v0, 8
    /* B6C8 8001AEC8 B56B0008 */  j          .L8001AED4
    /* B6CC 8001AECC 18006200 */   mult      $v1, $v0
  .L8001AED0:
    /* B6D0 8001AED0 18006600 */  mult       $v1, $a2
  .L8001AED4:
    /* B6D4 8001AED4 12400000 */  mflo       $t0
    /* B6D8 8001AED8 C2190800 */  srl        $v1, $t0, 7
    /* B6DC 8001AEDC 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B6E0 8001AEE0 00000000 */  nop
    /* B6E4 8001AEE4 02004230 */  andi       $v0, $v0, 0x2
    /* B6E8 8001AEE8 0C004014 */  bnez       $v0, .L8001AF1C
    /* B6EC 8001AEEC A80023A6 */   sh        $v1, 0xA8($s1)
    /* B6F0 8001AEF0 0380033C */  lui        $v1, %hi(g_Sound_LfoTable)
    /* B6F4 8001AEF4 A6002296 */  lhu        $v0, 0xA6($s1)
    /* B6F8 8001AEF8 A0016324 */  addiu      $v1, $v1, %lo(g_Sound_LfoTable)
    /* B6FC 8001AEFC 80100200 */  sll        $v0, $v0, 2
    /* B700 8001AF00 21104300 */  addu       $v0, $v0, $v1
    /* B704 8001AF04 9E002396 */  lhu        $v1, 0x9E($s1)
    /* B708 8001AF08 0000448C */  lw         $a0, 0x0($v0)
    /* B70C 8001AF0C 01000224 */  addiu      $v0, $zero, 0x1
    /* B710 8001AF10 A40022A6 */  sh         $v0, 0xA4($s1)
    /* B714 8001AF14 A00023A6 */  sh         $v1, 0xA0($s1)
    /* B718 8001AF18 1C0024AE */  sw         $a0, 0x1C($s1)
  .L8001AF1C:
    /* B71C 8001AF1C 02000232 */  andi       $v0, $s0, 0x2
  .L8001AF20:
    /* B720 8001AF20 10004010 */  beqz       $v0, .L8001AF64
    /* B724 8001AF24 00000000 */   nop
    /* B728 8001AF28 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B72C 8001AF2C 00000000 */  nop
    /* B730 8001AF30 02004230 */  andi       $v0, $v0, 0x2
    /* B734 8001AF34 0B004014 */  bnez       $v0, .L8001AF64
    /* B738 8001AF38 0380033C */   lui       $v1, %hi(g_Sound_LfoTable)
    /* B73C 8001AF3C B8002296 */  lhu        $v0, 0xB8($s1)
    /* B740 8001AF40 A0016324 */  addiu      $v1, $v1, %lo(g_Sound_LfoTable)
    /* B744 8001AF44 80100200 */  sll        $v0, $v0, 2
    /* B748 8001AF48 21104300 */  addu       $v0, $v0, $v1
    /* B74C 8001AF4C B0002396 */  lhu        $v1, 0xB0($s1)
    /* B750 8001AF50 0000448C */  lw         $a0, 0x0($v0)
    /* B754 8001AF54 01000224 */  addiu      $v0, $zero, 0x1
    /* B758 8001AF58 B60022A6 */  sh         $v0, 0xB6($s1)
    /* B75C 8001AF5C B20023A6 */  sh         $v1, 0xB2($s1)
    /* B760 8001AF60 200024AE */  sw         $a0, 0x20($s1)
  .L8001AF64:
    /* B764 8001AF64 EC0020A6 */  sh         $zero, 0xEC($s1)
    /* B768 8001AF68 EE0020A6 */  sh         $zero, 0xEE($s1)
    /* B76C 8001AF6C 300020AE */  sw         $zero, 0x30($s1)
  .L8001AF70:
    /* B770 8001AF70 9C002296 */  lhu        $v0, 0x9C($s1)
    /* B774 8001AF74 E8002596 */  lhu        $a1, 0xE8($s1)
    /* B778 8001AF78 FDFF4330 */  andi       $v1, $v0, 0xFFFD
    /* B77C 8001AF7C 01004230 */  andi       $v0, $v0, 0x1
    /* B780 8001AF80 40100200 */  sll        $v0, $v0, 1
    /* B784 8001AF84 25186200 */  or         $v1, $v1, $v0
    /* B788 8001AF88 E8002286 */  lh         $v0, 0xE8($s1)
    /* B78C 8001AF8C 00000000 */  nop
    /* B790 8001AF90 26004010 */  beqz       $v0, .L8001B02C
    /* B794 8001AF94 9C0023A6 */   sh        $v1, 0x9C($s1)
    /* B798 8001AF98 1000A727 */  addiu      $a3, $sp, 0x10
    /* B79C 8001AF9C 0380043C */  lui        $a0, %hi(g_InstrumentInfo)
    /* B7A0 8001AFA0 88678424 */  addiu      $a0, $a0, %lo(g_InstrumentInfo)
    /* B7A4 8001AFA4 6A002396 */  lhu        $v1, 0x6A($s1)
    /* B7A8 8001AFA8 E4002686 */  lh         $a2, 0xE4($s1)
    /* B7AC 8001AFAC E6002296 */  lhu        $v0, 0xE6($s1)
    /* B7B0 8001AFB0 00190300 */  sll        $v1, $v1, 4
    /* B7B4 8001AFB4 21206400 */  addu       $a0, $v1, $a0
    /* B7B8 8001AFB8 21104500 */  addu       $v0, $v0, $a1
    /* B7BC 8001AFBC 002C0200 */  sll        $a1, $v0, 16
    /* B7C0 8001AFC0 E2002386 */  lh         $v1, 0xE2($s1)
    /* B7C4 8001AFC4 032C0500 */  sra        $a1, $a1, 16
    /* B7C8 8001AFC8 E60022A6 */  sh         $v0, 0xE6($s1)
    /* B7CC 8001AFCC 2F69000C */  jal        func_8001A4BC
    /* B7D0 8001AFD0 2128A300 */   addu      $a1, $a1, $v1
    /* B7D4 8001AFD4 00340200 */  sll        $a2, $v0, 16
    /* B7D8 8001AFD8 96002396 */  lhu        $v1, 0x96($s1)
    /* B7DC 8001AFDC 2C00228E */  lw         $v0, 0x2C($s1)
    /* B7E0 8001AFE0 920023A6 */  sh         $v1, 0x92($s1)
    /* B7E4 8001AFE4 3000238E */  lw         $v1, 0x30($s1)
    /* B7E8 8001AFE8 00140200 */  sll        $v0, $v0, 16
    /* B7EC 8001AFEC 21104300 */  addu       $v0, $v0, $v1
    /* B7F0 8001AFF0 92002396 */  lhu        $v1, 0x92($s1)
    /* B7F4 8001AFF4 2310C200 */  subu       $v0, $a2, $v0
    /* B7F8 8001AFF8 1A004300 */  div        $zero, $v0, $v1
    /* B7FC 8001AFFC 02006014 */  bnez       $v1, .L8001B008
    /* B800 8001B000 00000000 */   nop
    /* B804 8001B004 0D000700 */  break      7
  .L8001B008:
    /* B808 8001B008 FFFF0124 */  addiu      $at, $zero, -0x1
    /* B80C 8001B00C 04006114 */  bne        $v1, $at, .L8001B020
    /* B810 8001B010 0080013C */   lui       $at, (0x80000000 >> 16)
    /* B814 8001B014 02004114 */  bne        $v0, $at, .L8001B020
    /* B818 8001B018 00000000 */   nop
    /* B81C 8001B01C 0D000600 */  break      6
  .L8001B020:
    /* B820 8001B020 12100000 */  mflo       $v0
    /* B824 8001B024 E80020A6 */  sh         $zero, 0xE8($s1)
    /* B828 8001B028 500022AE */  sw         $v0, 0x50($s1)
  .L8001B02C:
    /* B82C 8001B02C E6002296 */  lhu        $v0, 0xE6($s1)
    /* B830 8001B030 E2002396 */  lhu        $v1, 0xE2($s1)
    /* B834 8001B034 980022A6 */  sh         $v0, 0x98($s1)
    /* B838 8001B038 EA0023A6 */  sh         $v1, 0xEA($s1)
  .L8001B03C:
    /* B83C 8001B03C 3000BF8F */  lw         $ra, 0x30($sp)
    /* B840 8001B040 2C00B58F */  lw         $s5, 0x2C($sp)
    /* B844 8001B044 2800B48F */  lw         $s4, 0x28($sp)
    /* B848 8001B048 2400B38F */  lw         $s3, 0x24($sp)
    /* B84C 8001B04C 2000B28F */  lw         $s2, 0x20($sp)
    /* B850 8001B050 1C00B18F */  lw         $s1, 0x1C($sp)
    /* B854 8001B054 1800B08F */  lw         $s0, 0x18($sp)
    /* B858 8001B058 0800E003 */  jr         $ra
    /* B85C 8001B05C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8001A8D8
