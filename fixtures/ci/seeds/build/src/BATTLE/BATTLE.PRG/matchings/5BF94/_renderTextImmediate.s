nonmatching _renderTextImmediate, 0x394

glabel _renderTextImmediate
    /* 5F89C 800C809C B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 5F8A0 800C80A0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 5F8A4 800C80A4 21A08000 */  addu       $s4, $a0, $zero
    /* 5F8A8 800C80A8 4400B7AF */  sw         $s7, 0x44($sp)
    /* 5F8AC 800C80AC 21B80000 */  addu       $s7, $zero, $zero
    /* 5F8B0 800C80B0 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 5F8B4 800C80B4 4800BEAF */  sw         $fp, 0x48($sp)
    /* 5F8B8 800C80B8 4000B6AF */  sw         $s6, 0x40($sp)
    /* 5F8BC 800C80BC 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 5F8C0 800C80C0 3400B3AF */  sw         $s3, 0x34($sp)
    /* 5F8C4 800C80C4 3000B2AF */  sw         $s2, 0x30($sp)
    /* 5F8C8 800C80C8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 5F8CC 800C80CC 2800B0AF */  sw         $s0, 0x28($sp)
    /* 5F8D0 800C80D0 5400A5AF */  sw         $a1, 0x54($sp)
    /* 5F8D4 800C80D4 2000A0AF */  sw         $zero, 0x20($sp)
    /* 5F8D8 800C80D8 14009686 */  lh         $s6, 0x14($s4)
    /* 5F8DC 800C80DC 10008286 */  lh         $v0, 0x10($s4)
    /* 5F8E0 800C80E0 0800928E */  lw         $s2, 0x8($s4)
    /* 5F8E4 800C80E4 16008886 */  lh         $t0, 0x16($s4)
    /* 5F8E8 800C80E8 23885600 */  subu       $s1, $v0, $s6
    /* 5F8EC 800C80EC 1C00A8AF */  sw         $t0, 0x1C($sp)
    /* 5F8F0 800C80F0 12008286 */  lh         $v0, 0x12($s4)
    /* 5F8F4 800C80F4 20008392 */  lbu        $v1, 0x20($s4)
    /* 5F8F8 800C80F8 23984800 */  subu       $s3, $v0, $t0
    /* 5F8FC 800C80FC 40100300 */  sll        $v0, $v1, 1
    /* 5F900 800C8100 21104300 */  addu       $v0, $v0, $v1
    /* 5F904 800C8104 80100200 */  sll        $v0, $v0, 2
    /* 5F908 800C8108 21008392 */  lbu        $v1, 0x21($s4)
    /* 5F90C 800C810C 0A005524 */  addiu      $s5, $v0, 0xA
    /* 5F910 800C8110 40100300 */  sll        $v0, $v1, 1
    /* 5F914 800C8114 21104300 */  addu       $v0, $v0, $v1
    /* 5F918 800C8118 80100200 */  sll        $v0, $v0, 2
    /* 5F91C 800C811C 21104300 */  addu       $v0, $v0, $v1
    /* 5F920 800C8120 04004224 */  addiu      $v0, $v0, 0x4
    /* 5F924 800C8124 B600C006 */  bltz       $s6, .L800C8400
    /* 5F928 800C8128 1800A2AF */   sw        $v0, 0x18($sp)
    /* 5F92C 800C812C B4000005 */  bltz       $t0, .L800C8400
    /* 5F930 800C8130 2110D502 */   addu      $v0, $s6, $s5
    /* 5F934 800C8134 40014228 */  slti       $v0, $v0, 0x140
    /* 5F938 800C8138 B1004010 */  beqz       $v0, .L800C8400
    /* 5F93C 800C813C 00000000 */   nop
    /* 5F940 800C8140 1800A98F */  lw         $t1, 0x18($sp)
    /* 5F944 800C8144 00000000 */  nop
    /* 5F948 800C8148 21100901 */  addu       $v0, $t0, $t1
    /* 5F94C 800C814C E0004228 */  slti       $v0, $v0, 0xE0
    /* 5F950 800C8150 AB004010 */  beqz       $v0, .L800C8400
    /* 5F954 800C8154 1800A902 */   mult      $s5, $t1
    /* 5F958 800C8158 12400000 */  mflo       $t0
    /* 5F95C 800C815C 8F0F010C */  jal        vs_main_allocHeapR
    /* 5F960 800C8160 40200800 */   sll       $a0, $t0, 1
    /* 5F964 800C8164 5400A98F */  lw         $t1, 0x54($sp)
    /* 5F968 800C8168 2400A2AF */  sw         $v0, 0x24($sp)
    /* 5F96C 800C816C 03140900 */  sra        $v0, $t1, 16
    /* 5F970 800C8170 02004010 */  beqz       $v0, .L800C817C
    /* 5F974 800C8174 0100083C */   lui       $t0, (0x10000 >> 16)
    /* 5F978 800C8178 5400A8AF */  sw         $t0, 0x54($sp)
  .L800C817C:
    /* 5F97C 800C817C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5F980 800C8180 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 5F984 800C8184 10E2438C */  lw         $v1, %lo(vs_main_frameBuf)($v0)
    /* 5F988 800C8188 2400A58F */  lw         $a1, 0x24($sp)
    /* 5F98C 800C818C 1C00A997 */  lhu        $t1, 0x1C($sp)
    /* 5F990 800C8190 1800A897 */  lhu        $t0, 0x18($sp)
    /* 5F994 800C8194 1400B5A7 */  sh         $s5, 0x14($sp)
    /* 5F998 800C8198 80100300 */  sll        $v0, $v1, 2
    /* 5F99C 800C819C 21104300 */  addu       $v0, $v0, $v1
    /* 5F9A0 800C81A0 80110200 */  sll        $v0, $v0, 6
    /* 5F9A4 800C81A4 2110C202 */  addu       $v0, $s6, $v0
    /* 5F9A8 800C81A8 1200A9A7 */  sh         $t1, 0x12($sp)
    /* 5F9AC 800C81AC 1600A8A7 */  sh         $t0, 0x16($sp)
    /* 5F9B0 800C81B0 57A2000C */  jal        StoreImage
    /* 5F9B4 800C81B4 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 5F9B8 800C81B8 0F80023C */  lui        $v0, %hi(_fontTable)
    /* 5F9BC 800C81BC 21F04000 */  addu       $fp, $v0, $zero
  .L800C81C0:
    /* 5F9C0 800C81C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 5F9C4 800C81C4 B94CC2A3 */  sb         $v0, %lo(_fontTable)($fp)
  .L800C81C8:
    /* 5F9C8 800C81C8 00005092 */  lbu        $s0, 0x0($s2)
    /* 5F9CC 800C81CC 00000000 */  nop
    /* 5F9D0 800C81D0 EC00022E */  sltiu      $v0, $s0, 0xEC
    /* 5F9D4 800C81D4 4C004010 */  beqz       $v0, .L800C8308
    /* 5F9D8 800C81D8 01005226 */   addiu     $s2, $s2, 0x1
    /* 5F9DC 800C81DC E500022E */  sltiu      $v0, $s0, 0xE5
    /* 5F9E0 800C81E0 24004010 */  beqz       $v0, .L800C8274
    /* 5F9E4 800C81E4 8F000224 */   addiu     $v0, $zero, 0x8F
    /* 5F9E8 800C81E8 1D000212 */  beq        $s0, $v0, .L800C8260
    /* 5F9EC 800C81EC 0F80023C */   lui       $v0, %hi(vs_battle_characterWidths)
    /* 5F9F0 800C81F0 B94CC293 */  lbu        $v0, %lo(_fontTable)($fp)
    /* 5F9F4 800C81F4 00000000 */  nop
    /* 5F9F8 800C81F8 40180200 */  sll        $v1, $v0, 1
    /* 5F9FC 800C81FC 21186200 */  addu       $v1, $v1, $v0
    /* 5FA00 800C8200 80110300 */  sll        $v0, $v1, 6
    /* 5FA04 800C8204 23104300 */  subu       $v0, $v0, $v1
    /* 5FA08 800C8208 21800202 */  addu       $s0, $s0, $v0
    /* 5FA0C 800C820C F4FFA226 */  addiu      $v0, $s5, -0xC
    /* 5FA10 800C8210 2B105100 */  sltu       $v0, $v0, $s1
    /* 5FA14 800C8214 12004014 */  bnez       $v0, .L800C8260
    /* 5FA18 800C8218 0F80023C */   lui       $v0, %hi(vs_battle_characterWidths)
    /* 5FA1C 800C821C 1800A98F */  lw         $t1, 0x18($sp)
    /* 5FA20 800C8220 00000000 */  nop
    /* 5FA24 800C8224 F4FF2225 */  addiu      $v0, $t1, -0xC
    /* 5FA28 800C8228 2B105300 */  sltu       $v0, $v0, $s3
    /* 5FA2C 800C822C 0C004014 */  bnez       $v0, .L800C8260
    /* 5FA30 800C8230 0F80023C */   lui       $v0, %hi(vs_battle_characterWidths)
    /* 5FA34 800C8234 18007502 */  mult       $s3, $s5
    /* 5FA38 800C8238 21280002 */  addu       $a1, $s0, $zero
    /* 5FA3C 800C823C 2130A002 */  addu       $a2, $s5, $zero
    /* 5FA40 800C8240 2400A98F */  lw         $t1, 0x24($sp)
    /* 5FA44 800C8244 5400A78F */  lw         $a3, 0x54($sp)
    /* 5FA48 800C8248 12400000 */  mflo       $t0
    /* 5FA4C 800C824C 21202802 */  addu       $a0, $s1, $t0
    /* 5FA50 800C8250 40200400 */  sll        $a0, $a0, 1
    /* 5FA54 800C8254 AF1F030C */  jal        func_800C7EBC
    /* 5FA58 800C8258 21202401 */   addu      $a0, $t1, $a0
    /* 5FA5C 800C825C 0F80023C */  lui        $v0, %hi(vs_battle_characterWidths)
  .L800C8260:
    /* 5FA60 800C8260 10B84224 */  addiu      $v0, $v0, %lo(vs_battle_characterWidths)
    /* 5FA64 800C8264 21100202 */  addu       $v0, $s0, $v0
    /* 5FA68 800C8268 00004290 */  lbu        $v0, 0x0($v0)
    /* 5FA6C 800C826C 72200308 */  j          .L800C81C8
    /* 5FA70 800C8270 21882202 */   addu      $s1, $s1, $v0
  .L800C8274:
    /* 5FA74 800C8274 1BFF0526 */  addiu      $a1, $s0, -0xE5
    /* 5FA78 800C8278 02000224 */  addiu      $v0, $zero, 0x2
    /* 5FA7C 800C827C 0500A210 */  beq        $a1, $v0, .L800C8294
    /* 5FA80 800C8280 03000224 */   addiu     $v0, $zero, 0x3
    /* 5FA84 800C8284 0D00A210 */  beq        $a1, $v0, .L800C82BC
    /* 5FA88 800C8288 00000000 */   nop
    /* 5FA8C 800C828C BC200308 */  j          .L800C82F0
    /* 5FA90 800C8290 00000000 */   nop
  .L800C8294:
    /* 5FA94 800C8294 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5FA98 800C8298 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5FA9C 800C829C 00000000 */  nop
    /* 5FAA0 800C82A0 20004230 */  andi       $v0, $v0, 0x20
    /* 5FAA4 800C82A4 02004010 */  beqz       $v0, .L800C82B0
    /* 5FAA8 800C82A8 FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* 5FAAC 800C82AC 0C0082A6 */  sh         $v0, 0xC($s4)
  .L800C82B0:
    /* 5FAB0 800C82B0 01000824 */  addiu      $t0, $zero, 0x1
    /* 5FAB4 800C82B4 BC200308 */  j          .L800C82F0
    /* 5FAB8 800C82B8 2000A8AF */   sw        $t0, 0x20($sp)
  .L800C82BC:
    /* 5FABC 800C82BC 10008286 */  lh         $v0, 0x10($s4)
    /* 5FAC0 800C82C0 0A00E012 */  beqz       $s7, .L800C82EC
    /* 5FAC4 800C82C4 23885600 */   subu      $s1, $v0, $s6
    /* 5FAC8 800C82C8 041C030C */  jal        vs_battle_getTextLineLength
    /* 5FACC 800C82CC 21204002 */   addu      $a0, $s2, $zero
    /* 5FAD0 800C82D0 20008392 */  lbu        $v1, 0x20($s4)
    /* 5FAD4 800C82D4 00000000 */  nop
    /* 5FAD8 800C82D8 40180300 */  sll        $v1, $v1, 1
    /* 5FADC 800C82DC 23186200 */  subu       $v1, $v1, $v0
    /* 5FAE0 800C82E0 40100300 */  sll        $v0, $v1, 1
    /* 5FAE4 800C82E4 21104300 */  addu       $v0, $v0, $v1
    /* 5FAE8 800C82E8 21882202 */  addu       $s1, $s1, $v0
  .L800C82EC:
    /* 5FAEC 800C82EC 0D007326 */  addiu      $s3, $s3, 0xD
  .L800C82F0:
    /* 5FAF0 800C82F0 2000A98F */  lw         $t1, 0x20($sp)
    /* 5FAF4 800C82F4 00000000 */  nop
    /* 5FAF8 800C82F8 2F002015 */  bnez       $t1, .L800C83B8
    /* 5FAFC 800C82FC 0680023C */   lui       $v0, %hi(vs_main_frameBuf)
    /* 5FB00 800C8300 72200308 */  j          .L800C81C8
    /* 5FB04 800C8304 00000000 */   nop
  .L800C8308:
    /* 5FB08 800C8308 00004392 */  lbu        $v1, 0x0($s2)
    /* 5FB0C 800C830C 08FF0526 */  addiu      $a1, $s0, -0xF8
    /* 5FB10 800C8310 02000224 */  addiu      $v0, $zero, 0x2
    /* 5FB14 800C8314 0600A210 */  beq        $a1, $v0, .L800C8330
    /* 5FB18 800C8318 01005226 */   addiu     $s2, $s2, 0x1
    /* 5FB1C 800C831C 03000224 */  addiu      $v0, $zero, 0x3
    /* 5FB20 800C8320 0A00A210 */  beq        $a1, $v0, .L800C834C
    /* 5FB24 800C8324 F8006230 */   andi      $v0, $v1, 0xF8
    /* 5FB28 800C8328 72200308 */  j          .L800C81C8
    /* 5FB2C 800C832C 00000000 */   nop
  .L800C8330:
    /* 5FB30 800C8330 F000622C */  sltiu      $v0, $v1, 0xF0
    /* 5FB34 800C8334 03004014 */  bnez       $v0, .L800C8344
    /* 5FB38 800C8338 00FF2226 */   addiu     $v0, $s1, -0x100
    /* 5FB3C 800C833C 72200308 */  j          .L800C81C8
    /* 5FB40 800C8340 21884300 */   addu      $s1, $v0, $v1
  .L800C8344:
    /* 5FB44 800C8344 72200308 */  j          .L800C81C8
    /* 5FB48 800C8348 21882302 */   addu      $s1, $s1, $v1
  .L800C834C:
    /* 5FB4C 800C834C 03004010 */  beqz       $v0, .L800C835C
    /* 5FB50 800C8350 C2100300 */   srl       $v0, $v1, 3
    /* 5FB54 800C8354 72200308 */  j          .L800C81C8
    /* 5FB58 800C8358 21986202 */   addu      $s3, $s3, $v0
  .L800C835C:
    /* 5FB5C 800C835C 06000224 */  addiu      $v0, $zero, 0x6
    /* 5FB60 800C8360 03006214 */  bne        $v1, $v0, .L800C8370
    /* 5FB64 800C8364 05000224 */   addiu     $v0, $zero, 0x5
    /* 5FB68 800C8368 72200308 */  j          .L800C81C8
    /* 5FB6C 800C836C B94CC0A3 */   sb        $zero, %lo(_fontTable)($fp)
  .L800C8370:
    /* 5FB70 800C8370 93FF6210 */  beq        $v1, $v0, .L800C81C0
    /* 5FB74 800C8374 04000224 */   addiu     $v0, $zero, 0x4
    /* 5FB78 800C8378 93FF6214 */  bne        $v1, $v0, .L800C81C8
    /* 5FB7C 800C837C 00000000 */   nop
    /* 5FB80 800C8380 0100F73A */  xori       $s7, $s7, 0x1
    /* 5FB84 800C8384 90FFE012 */  beqz       $s7, .L800C81C8
    /* 5FB88 800C8388 00000000 */   nop
    /* 5FB8C 800C838C 041C030C */  jal        vs_battle_getTextLineLength
    /* 5FB90 800C8390 21204002 */   addu      $a0, $s2, $zero
    /* 5FB94 800C8394 20008392 */  lbu        $v1, 0x20($s4)
    /* 5FB98 800C8398 10008486 */  lh         $a0, 0x10($s4)
    /* 5FB9C 800C839C 40180300 */  sll        $v1, $v1, 1
    /* 5FBA0 800C83A0 23186200 */  subu       $v1, $v1, $v0
    /* 5FBA4 800C83A4 40100300 */  sll        $v0, $v1, 1
    /* 5FBA8 800C83A8 21104300 */  addu       $v0, $v0, $v1
    /* 5FBAC 800C83AC 21104400 */  addu       $v0, $v0, $a0
    /* 5FBB0 800C83B0 72200308 */  j          .L800C81C8
    /* 5FBB4 800C83B4 23885600 */   subu      $s1, $v0, $s6
  .L800C83B8:
    /* 5FBB8 800C83B8 2400A58F */  lw         $a1, 0x24($sp)
    /* 5FBBC 800C83BC 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 5FBC0 800C83C0 1800A88F */  lw         $t0, 0x18($sp)
    /* 5FBC4 800C83C4 1C00A98F */  lw         $t1, 0x1C($sp)
    /* 5FBC8 800C83C8 00340800 */  sll        $a2, $t0, 16
    /* 5FBCC 800C83CC 2530A602 */  or         $a2, $s5, $a2
    /* 5FBD0 800C83D0 80200200 */  sll        $a0, $v0, 2
    /* 5FBD4 800C83D4 21208200 */  addu       $a0, $a0, $v0
    /* 5FBD8 800C83D8 80210400 */  sll        $a0, $a0, 6
    /* 5FBDC 800C83DC 2120C402 */  addu       $a0, $s6, $a0
    /* 5FBE0 800C83E0 00140900 */  sll        $v0, $t1, 16
    /* 5FBE4 800C83E4 6A33030C */  jal        vs_battle_drawImage
    /* 5FBE8 800C83E8 25208200 */   or        $a0, $a0, $v0
    /* 5FBEC 800C83EC 94A1000C */  jal        DrawSync
    /* 5FBF0 800C83F0 21200000 */   addu      $a0, $zero, $zero
    /* 5FBF4 800C83F4 2400A48F */  lw         $a0, 0x24($sp)
    /* 5FBF8 800C83F8 180F010C */  jal        vs_main_freeHeapR
    /* 5FBFC 800C83FC 00000000 */   nop
  .L800C8400:
    /* 5FC00 800C8400 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 5FC04 800C8404 4800BE8F */  lw         $fp, 0x48($sp)
    /* 5FC08 800C8408 4400B78F */  lw         $s7, 0x44($sp)
    /* 5FC0C 800C840C 4000B68F */  lw         $s6, 0x40($sp)
    /* 5FC10 800C8410 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 5FC14 800C8414 3800B48F */  lw         $s4, 0x38($sp)
    /* 5FC18 800C8418 3400B38F */  lw         $s3, 0x34($sp)
    /* 5FC1C 800C841C 3000B28F */  lw         $s2, 0x30($sp)
    /* 5FC20 800C8420 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 5FC24 800C8424 2800B08F */  lw         $s0, 0x28($sp)
    /* 5FC28 800C8428 0800E003 */  jr         $ra
    /* 5FC2C 800C842C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel _renderTextImmediate
