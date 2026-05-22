nonmatching func_8010399C, 0xD0

glabel func_8010399C
    /* 119C 8010399C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 11A0 801039A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 11A4 801039A4 21808000 */  addu       $s0, $a0, $zero
    /* 11A8 801039A8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 11AC 801039AC 2198C000 */  addu       $s3, $a2, $zero
    /* 11B0 801039B0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 11B4 801039B4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 11B8 801039B8 1500A010 */  beqz       $a1, .L80103A10
    /* 11BC 801039BC 1400B1AF */   sw        $s1, 0x14($sp)
    /* 11C0 801039C0 21880000 */  addu       $s1, $zero, $zero
    /* 11C4 801039C4 F437123C */  lui        $s2, (0x37F400E4 >> 16)
    /* 11C8 801039C8 E4005236 */  ori        $s2, $s2, (0x37F400E4 & 0xFFFF)
  .L801039CC:
    /* 11CC 801039CC 80000424 */  addiu      $a0, $zero, 0x80
    /* 11D0 801039D0 21280002 */  addu       $a1, $s0, $zero
    /* 11D4 801039D4 0900063C */  lui        $a2, (0x90006 >> 16)
    /* 11D8 801039D8 0600C634 */  ori        $a2, $a2, (0x90006 & 0xFFFF)
    /* 11DC 801039DC 8C00030C */  jal        vs_battle_setSprite
    /* 11E0 801039E0 21386002 */   addu      $a3, $s3, $zero
    /* 11E4 801039E4 100052AC */  sw         $s2, 0x10($v0)
    /* 11E8 801039E8 01003126 */  addiu      $s1, $s1, 0x1
    /* 11EC 801039EC 0300222A */  slti       $v0, $s1, 0x3
    /* 11F0 801039F0 F6FF4014 */  bnez       $v0, .L801039CC
    /* 11F4 801039F4 FBFF1026 */   addiu     $s0, $s0, -0x5
    /* 11F8 801039F8 02000424 */  addiu      $a0, $zero, 0x2
    /* 11FC 801039FC 21280002 */  addu       $a1, $s0, $zero
    /* 1200 80103A00 21300000 */  addu       $a2, $zero, $zero
    /* 1204 80103A04 5426030C */  jal        vs_battle_renderValue
    /* 1208 80103A08 21386002 */   addu      $a3, $s3, $zero
    /* 120C 80103A0C F9FF1026 */  addiu      $s0, $s0, -0x7
  .L80103A10:
    /* 1210 80103A10 FFFF023C */  lui        $v0, %hi(D_FFFEFFFA)
    /* 1214 80103A14 21800202 */  addu       $s0, $s0, $v0
    /* 1218 80103A18 21880000 */  addu       $s1, $zero, $zero
    /* 121C 80103A1C F437123C */  lui        $s2, (0x37F400EA >> 16)
    /* 1220 80103A20 EA005236 */  ori        $s2, $s2, (0x37F400EA & 0xFFFF)
  .L80103A24:
    /* 1224 80103A24 80000424 */  addiu      $a0, $zero, 0x80
    /* 1228 80103A28 21280002 */  addu       $a1, $s0, $zero
    /* 122C 80103A2C 0A00063C */  lui        $a2, (0xA0007 >> 16)
    /* 1230 80103A30 0700C634 */  ori        $a2, $a2, (0xA0007 & 0xFFFF)
    /* 1234 80103A34 8C00030C */  jal        vs_battle_setSprite
    /* 1238 80103A38 21386002 */   addu      $a3, $s3, $zero
    /* 123C 80103A3C 100052AC */  sw         $s2, 0x10($v0)
    /* 1240 80103A40 01003126 */  addiu      $s1, $s1, 0x1
    /* 1244 80103A44 0300222A */  slti       $v0, $s1, 0x3
    /* 1248 80103A48 F6FF4014 */  bnez       $v0, .L80103A24
    /* 124C 80103A4C FAFF1026 */   addiu     $s0, $s0, %lo(D_FFFEFFFA)
    /* 1250 80103A50 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1254 80103A54 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1258 80103A58 1800B28F */  lw         $s2, 0x18($sp)
    /* 125C 80103A5C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1260 80103A60 1000B08F */  lw         $s0, 0x10($sp)
    /* 1264 80103A64 0800E003 */  jr         $ra
    /* 1268 80103A68 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8010399C
