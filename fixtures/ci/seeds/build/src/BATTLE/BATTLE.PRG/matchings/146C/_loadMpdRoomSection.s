nonmatching _loadMpdRoomSection, 0x260

glabel _loadMpdRoomSection
    /* 22108 8008A908 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2210C 8008A90C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 22110 8008A910 21A88000 */  addu       $s5, $a0, $zero
    /* 22114 8008A914 2000B4AF */  sw         $s4, 0x20($sp)
    /* 22118 8008A918 21A0A000 */  addu       $s4, $a1, $zero
    /* 2211C 8008A91C 0F80023C */  lui        $v0, %hi(D_800F1BB6)
    /* 22120 8008A920 21200000 */  addu       $a0, $zero, $zero
    /* 22124 8008A924 1800B2AF */  sw         $s2, 0x18($sp)
    /* 22128 8008A928 21908000 */  addu       $s2, $a0, $zero
    /* 2212C 8008A92C 21188002 */  addu       $v1, $s4, $zero
    /* 22130 8008A930 2800BFAF */  sw         $ra, 0x28($sp)
    /* 22134 8008A934 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 22138 8008A938 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2213C 8008A93C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 22140 8008A940 B61B40A4 */  sh         $zero, %lo(D_800F1BB6)($v0)
  .L8008A944:
    /* 22144 8008A944 0000628C */  lw         $v0, 0x0($v1)
    /* 22148 8008A948 01008424 */  addiu      $a0, $a0, 0x1
    /* 2214C 8008A94C 21904202 */  addu       $s2, $s2, $v0
    /* 22150 8008A950 18008228 */  slti       $v0, $a0, 0x18
    /* 22154 8008A954 FBFF4014 */  bnez       $v0, .L8008A944
    /* 22158 8008A958 04006324 */   addiu     $v1, $v1, 0x4
    /* 2215C 8008A95C 03004016 */  bnez       $s2, .L8008A96C
    /* 22160 8008A960 0F80103C */   lui       $s0, %hi(vs_battle_roomData + 0x4)
    /* 22164 8008A964 D12A0208 */  j          .L8008AB44
    /* 22168 8008A968 21100000 */   addu      $v0, $zero, $zero
  .L8008A96C:
    /* 2216C 8008A96C FC1B1026 */  addiu      $s0, $s0, %lo(vs_battle_roomData + 0x4)
    /* 22170 8008A970 21200002 */  addu       $a0, $s0, $zero
    /* 22174 8008A974 21288002 */  addu       $a1, $s4, $zero
    /* 22178 8008A978 2C24010C */  jal        vs_main_memcpy
    /* 2217C 8008A97C 60000624 */   addiu     $a2, $zero, 0x60
    /* 22180 8008A980 B10F010C */  jal        vs_main_allocHeap
    /* 22184 8008A984 21204002 */   addu      $a0, $s2, $zero
    /* 22188 8008A988 21984000 */  addu       $s3, $v0, $zero
    /* 2218C 8008A98C 21206002 */  addu       $a0, $s3, $zero
    /* 22190 8008A990 60009126 */  addiu      $s1, $s4, 0x60
    /* 22194 8008A994 21282002 */  addu       $a1, $s1, $zero
    /* 22198 8008A998 2C24010C */  jal        vs_main_memcpy
    /* 2219C 8008A99C 21304002 */   addu      $a2, $s2, $zero
    /* 221A0 8008A9A0 21900000 */  addu       $s2, $zero, $zero
    /* 221A4 8008A9A4 21288002 */  addu       $a1, $s4, $zero
    /* 221A8 8008A9A8 FCFF1026 */  addiu      $s0, $s0, -0x4
  .L8008A9AC:
    /* 221AC 8008A9AC 0000A28C */  lw         $v0, 0x0($a1)
    /* 221B0 8008A9B0 00000000 */  nop
    /* 221B4 8008A9B4 03004018 */  blez       $v0, .L8008A9C4
    /* 221B8 8008A9B8 21107202 */   addu      $v0, $s3, $s2
    /* 221BC 8008A9BC 722A0208 */  j          .L8008A9C8
    /* 221C0 8008A9C0 640002AE */   sw        $v0, 0x64($s0)
  .L8008A9C4:
    /* 221C4 8008A9C4 640000AE */  sw         $zero, 0x64($s0)
  .L8008A9C8:
    /* 221C8 8008A9C8 0000A28C */  lw         $v0, 0x0($a1)
    /* 221CC 8008A9CC 0400A524 */  addiu      $a1, $a1, 0x4
    /* 221D0 8008A9D0 21904202 */  addu       $s2, $s2, $v0
    /* 221D4 8008A9D4 2A10B100 */  slt        $v0, $a1, $s1
    /* 221D8 8008A9D8 F4FF4014 */  bnez       $v0, .L8008A9AC
    /* 221DC 8008A9DC 04001026 */   addiu     $s0, $s0, 0x4
    /* 221E0 8008A9E0 0F80033C */  lui        $v1, %hi(vs_battle_roomData)
    /* 221E4 8008A9E4 F81B7024 */  addiu      $s0, $v1, %lo(vs_battle_roomData)
    /* 221E8 8008A9E8 6400058E */  lw         $a1, 0x64($s0)
    /* 221EC 8008A9EC 01000224 */  addiu      $v0, $zero, 0x1
    /* 221F0 8008A9F0 F81B62A0 */  sb         $v0, %lo(vs_battle_roomData)($v1)
    /* 221F4 8008A9F4 010000A2 */  sb         $zero, 0x1($s0)
    /* 221F8 8008A9F8 0300A010 */  beqz       $a1, .L8008AA08
    /* 221FC 8008A9FC 020015A6 */   sh        $s5, 0x2($s0)
    /* 22200 8008AA00 E42C020C */  jal        func_8008B390
    /* 22204 8008AA04 0B000424 */   addiu     $a0, $zero, 0xB
  .L8008AA08:
    /* 22208 8008AA08 9800038E */  lw         $v1, 0x98($s0)
    /* 2220C 8008AA0C 00000000 */  nop
    /* 22210 8008AA10 0D006010 */  beqz       $v1, .L8008AA48
    /* 22214 8008AA14 14006424 */   addiu     $a0, $v1, 0x14
    /* 22218 8008AA18 0800628C */  lw         $v0, 0x8($v1)
    /* 2221C 8008AA1C 00000000 */  nop
    /* 22220 8008AA20 08004018 */  blez       $v0, .L8008AA44
    /* 22224 8008AA24 0C0064AC */   sw        $a0, 0xC($v1)
    /* 22228 8008AA28 0400628C */  lw         $v0, 0x4($v1)
    /* 2222C 8008AA2C 100064AC */  sw         $a0, 0x10($v1)
    /* 22230 8008AA30 83100200 */  sra        $v0, $v0, 2
    /* 22234 8008AA34 80100200 */  sll        $v0, $v0, 2
    /* 22238 8008AA38 21108200 */  addu       $v0, $a0, $v0
    /* 2223C 8008AA3C 922A0208 */  j          .L8008AA48
    /* 22240 8008AA40 100062AC */   sw        $v0, 0x10($v1)
  .L8008AA44:
    /* 22244 8008AA44 100060AC */  sw         $zero, 0x10($v1)
  .L8008AA48:
    /* 22248 8008AA48 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 2224C 8008AA4C F81B5024 */  addiu      $s0, $v0, %lo(vs_battle_roomData)
    /* 22250 8008AA50 6800048E */  lw         $a0, 0x68($s0)
    /* 22254 8008AA54 00000000 */  nop
    /* 22258 8008AA58 07008010 */  beqz       $a0, .L8008AA78
    /* 2225C 8008AA5C 00000000 */   nop
    /* 22260 8008AA60 00008394 */  lhu        $v1, 0x0($a0)
    /* 22264 8008AA64 02008294 */  lhu        $v0, 0x2($a0)
    /* 22268 8008AA68 00000000 */  nop
    /* 2226C 8008AA6C 18006200 */  mult       $v1, $v0
    /* 22270 8008AA70 12380000 */  mflo       $a3
    /* 22274 8008AA74 060087A4 */  sh         $a3, 0x6($a0)
  .L8008AA78:
    /* 22278 8008AA78 9C00048E */  lw         $a0, 0x9C($s0)
    /* 2227C 8008AA7C 00000000 */  nop
    /* 22280 8008AA80 18008010 */  beqz       $a0, .L8008AAE4
    /* 22284 8008AA84 00000000 */   nop
    /* 22288 8008AA88 D363020C */  jal        vs_battle_initSceneAndGetRoomNames
    /* 2228C 8008AA8C 00000000 */   nop
    /* 22290 8008AA90 9C00048E */  lw         $a0, 0x9C($s0)
    /* 22294 8008AA94 362D020C */  jal        vs_battle_setRoomsUnk0
    /* 22298 8008AA98 00000000 */   nop
    /* 2229C 8008AA9C 9C00038E */  lw         $v1, 0x9C($s0)
    /* 222A0 8008AAA0 01000224 */  addiu      $v0, $zero, 0x1
    /* 222A4 8008AAA4 040062AC */  sw         $v0, 0x4($v1)
    /* 222A8 8008AAA8 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 222AC 8008AAAC 98155024 */  addiu      $s0, $v0, %lo(vs_main_stateFlags)
    /* 222B0 8008AAB0 05010292 */  lbu        $v0, 0x105($s0)
    /* 222B4 8008AAB4 00000000 */  nop
    /* 222B8 8008AAB8 06004014 */  bnez       $v0, .L8008AAD4
    /* 222BC 8008AABC 0F80023C */   lui       $v0, %hi(vs_battle_doorEntered)
    /* 222C0 8008AAC0 BE1B4484 */  lh         $a0, %lo(vs_battle_doorEntered)($v0)
    /* 222C4 8008AAC4 5236020C */  jal        vs_battle_setDoorEntered2
    /* 222C8 8008AAC8 00000000 */   nop
    /* 222CC 8008AACC B92A0208 */  j          .L8008AAE4
    /* 222D0 8008AAD0 00000000 */   nop
  .L8008AAD4:
    /* 222D4 8008AAD4 05010492 */  lbu        $a0, 0x105($s0)
    /* 222D8 8008AAD8 5236020C */  jal        vs_battle_setDoorEntered2
    /* 222DC 8008AADC FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 222E0 8008AAE0 050100A2 */  sb         $zero, 0x105($s0)
  .L8008AAE4:
    /* 222E4 8008AAE4 AD2D020C */  jal        func_8008B6B4
    /* 222E8 8008AAE8 00000000 */   nop
    /* 222EC 8008AAEC 5249020C */  jal        func_80092548
    /* 222F0 8008AAF0 00000000 */   nop
    /* 222F4 8008AAF4 C435020C */  jal        func_8008D710
    /* 222F8 8008AAF8 00000000 */   nop
    /* 222FC 8008AAFC 4E31020C */  jal        func_8008C538
    /* 22300 8008AB00 00000000 */   nop
    /* 22304 8008AB04 AD4E020C */  jal        func_80093AB4
    /* 22308 8008AB08 00000000 */   nop
    /* 2230C 8008AB0C 3E3A020C */  jal        func_8008E8F8
    /* 22310 8008AB10 00000000 */   nop
    /* 22314 8008AB14 4E3A020C */  jal        func_8008E938
    /* 22318 8008AB18 00000000 */   nop
    /* 2231C 8008AB1C C82C020C */  jal        func_8008B320
    /* 22320 8008AB20 00000000 */   nop
    /* 22324 8008AB24 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x98)
    /* 22328 8008AB28 901C438C */  lw         $v1, %lo(vs_battle_roomData + 0x98)($v0)
    /* 2232C 8008AB2C 0F80023C */  lui        $v0, %hi(D_800F1BBC)
    /* 22330 8008AB30 03006010 */  beqz       $v1, .L8008AB40
    /* 22334 8008AB34 BC1B40A0 */   sb        $zero, %lo(D_800F1BBC)($v0)
    /* 22338 8008AB38 1D0B010C */  jal        vs_main_wait
    /* 2233C 8008AB3C 00000000 */   nop
  .L8008AB40:
    /* 22340 8008AB40 01000224 */  addiu      $v0, $zero, 0x1
  .L8008AB44:
    /* 22344 8008AB44 2800BF8F */  lw         $ra, 0x28($sp)
    /* 22348 8008AB48 2400B58F */  lw         $s5, 0x24($sp)
    /* 2234C 8008AB4C 2000B48F */  lw         $s4, 0x20($sp)
    /* 22350 8008AB50 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 22354 8008AB54 1800B28F */  lw         $s2, 0x18($sp)
    /* 22358 8008AB58 1400B18F */  lw         $s1, 0x14($sp)
    /* 2235C 8008AB5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 22360 8008AB60 0800E003 */  jr         $ra
    /* 22364 8008AB64 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _loadMpdRoomSection
