nonmatching _copySprites, 0xB4

glabel _copySprites
    /* 1224 80103A24 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1228 80103A28 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 122C 80103A2C 21888000 */  addu       $s1, $a0, $zero
    /* 1230 80103A30 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1234 80103A34 2190A000 */  addu       $s2, $a1, $zero
    /* 1238 80103A38 1800B0AF */  sw         $s0, 0x18($sp)
    /* 123C 80103A3C 21800000 */  addu       $s0, $zero, $zero
    /* 1240 80103A40 04000224 */  addiu      $v0, $zero, 0x4
    /* 1244 80103A44 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 1248 80103A48 10000224 */  addiu      $v0, $zero, 0x10
    /* 124C 80103A4C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1250 80103A50 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1254 80103A54 1900401A */  blez       $s2, .L80103ABC
    /* 1258 80103A58 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 125C 80103A5C AA2A133C */  lui        $s3, (0x2AAAAAAB >> 16)
    /* 1260 80103A60 ABAA7336 */  ori        $s3, $s3, (0x2AAAAAAB & 0xFFFF)
  .L80103A64:
    /* 1264 80103A64 18001302 */  mult       $s0, $s3
    /* 1268 80103A68 C3171000 */  sra        $v0, $s0, 31
    /* 126C 80103A6C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1270 80103A70 21282002 */  addu       $a1, $s1, $zero
    /* 1274 80103A74 10300000 */  mfhi       $a2
    /* 1278 80103A78 C3180600 */  sra        $v1, $a2, 3
    /* 127C 80103A7C 23186200 */  subu       $v1, $v1, $v0
    /* 1280 80103A80 40100300 */  sll        $v0, $v1, 1
    /* 1284 80103A84 21104300 */  addu       $v0, $v0, $v1
    /* 1288 80103A88 00110200 */  sll        $v0, $v0, 4
    /* 128C 80103A8C 23100202 */  subu       $v0, $s0, $v0
    /* 1290 80103A90 80100200 */  sll        $v0, $v0, 2
    /* 1294 80103A94 40034224 */  addiu      $v0, $v0, 0x340
    /* 1298 80103A98 00190300 */  sll        $v1, $v1, 4
    /* 129C 80103A9C 00016324 */  addiu      $v1, $v1, 0x100
    /* 12A0 80103AA0 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 12A4 80103AA4 67AB000C */  jal        LoadImage2
    /* 12A8 80103AA8 1200A3A7 */   sh        $v1, 0x12($sp)
    /* 12AC 80103AAC 01001026 */  addiu      $s0, $s0, 0x1
    /* 12B0 80103AB0 2A101202 */  slt        $v0, $s0, $s2
    /* 12B4 80103AB4 EBFF4014 */  bnez       $v0, .L80103A64
    /* 12B8 80103AB8 80003126 */   addiu     $s1, $s1, 0x80
  .L80103ABC:
    /* 12BC 80103ABC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 12C0 80103AC0 2400B38F */  lw         $s3, 0x24($sp)
    /* 12C4 80103AC4 2000B28F */  lw         $s2, 0x20($sp)
    /* 12C8 80103AC8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 12CC 80103ACC 1800B08F */  lw         $s0, 0x18($sp)
    /* 12D0 80103AD0 0800E003 */  jr         $ra
    /* 12D4 80103AD4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _copySprites
