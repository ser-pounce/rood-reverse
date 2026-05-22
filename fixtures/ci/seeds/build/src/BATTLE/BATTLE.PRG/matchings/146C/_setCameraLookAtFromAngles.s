nonmatching _setCameraLookAtFromAngles, 0xF4

glabel _setCameraLookAtFromAngles
    /* 122F8 8007AAF8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 122FC 8007AAFC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 12300 8007AB00 21908000 */  addu       $s2, $a0, $zero
    /* 12304 8007AB04 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 12308 8007AB08 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1230C 8007AB0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12310 8007AB10 0000448E */  lw         $a0, 0x0($s2)
    /* 12314 8007AB14 CA03010C */  jal        rsin
    /* 12318 8007AB18 801F113C */   lui       $s1, %hi(D_1F800000)
    /* 1231C 8007AB1C 00003126 */  addiu      $s1, $s1, %lo(D_1F800000)
    /* 12320 8007AB20 23100200 */  negu       $v0, $v0
    /* 12324 8007AB24 440022AE */  sw         $v0, 0x44($s1)
    /* 12328 8007AB28 0000448E */  lw         $a0, 0x0($s2)
    /* 1232C 8007AB2C C903010C */  jal        rcos
    /* 12330 8007AB30 00000000 */   nop
    /* 12334 8007AB34 23100200 */  negu       $v0, $v0
    /* 12338 8007AB38 4C0022AE */  sw         $v0, 0x4C($s1)
    /* 1233C 8007AB3C 0400448E */  lw         $a0, 0x4($s2)
    /* 12340 8007AB40 CA03010C */  jal        rsin
    /* 12344 8007AB44 00000000 */   nop
    /* 12348 8007AB48 0400448E */  lw         $a0, 0x4($s2)
    /* 1234C 8007AB4C C903010C */  jal        rcos
    /* 12350 8007AB50 21804000 */   addu      $s0, $v0, $zero
    /* 12354 8007AB54 23801000 */  negu       $s0, $s0
    /* 12358 8007AB58 00831000 */  sll        $s0, $s0, 12
    /* 1235C 8007AB5C 1A000202 */  div        $zero, $s0, $v0
    /* 12360 8007AB60 12800000 */  mflo       $s0
    /* 12364 8007AB64 44002426 */  addiu      $a0, $s1, 0x44
    /* 12368 8007AB68 21288000 */  addu       $a1, $a0, $zero
    /* 1236C 8007AB6C A506010C */  jal        VectorNormal
    /* 12370 8007AB70 480030AE */   sw        $s0, 0x48($s1)
    /* 12374 8007AB74 4400238E */  lw         $v1, 0x44($s1)
    /* 12378 8007AB78 0800428E */  lw         $v0, 0x8($s2)
    /* 1237C 8007AB7C 00000000 */  nop
    /* 12380 8007AB80 18006200 */  mult       $v1, $v0
    /* 12384 8007AB84 3400228E */  lw         $v0, 0x34($s1)
    /* 12388 8007AB88 12180000 */  mflo       $v1
    /* 1238C 8007AB8C 21106200 */  addu       $v0, $v1, $v0
    /* 12390 8007AB90 4C00238E */  lw         $v1, 0x4C($s1)
    /* 12394 8007AB94 440022AE */  sw         $v0, 0x44($s1)
    /* 12398 8007AB98 0800428E */  lw         $v0, 0x8($s2)
    /* 1239C 8007AB9C 00000000 */  nop
    /* 123A0 8007ABA0 18006200 */  mult       $v1, $v0
    /* 123A4 8007ABA4 3C00228E */  lw         $v0, 0x3C($s1)
    /* 123A8 8007ABA8 12180000 */  mflo       $v1
    /* 123AC 8007ABAC 21106200 */  addu       $v0, $v1, $v0
    /* 123B0 8007ABB0 4800238E */  lw         $v1, 0x48($s1)
    /* 123B4 8007ABB4 4C0022AE */  sw         $v0, 0x4C($s1)
    /* 123B8 8007ABB8 0800428E */  lw         $v0, 0x8($s2)
    /* 123BC 8007ABBC 00000000 */  nop
    /* 123C0 8007ABC0 18006200 */  mult       $v1, $v0
    /* 123C4 8007ABC4 3800228E */  lw         $v0, 0x38($s1)
    /* 123C8 8007ABC8 12180000 */  mflo       $v1
    /* 123CC 8007ABCC 21106200 */  addu       $v0, $v1, $v0
    /* 123D0 8007ABD0 480022AE */  sw         $v0, 0x48($s1)
    /* 123D4 8007ABD4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 123D8 8007ABD8 1800B28F */  lw         $s2, 0x18($sp)
    /* 123DC 8007ABDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 123E0 8007ABE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 123E4 8007ABE4 0800E003 */  jr         $ra
    /* 123E8 8007ABE8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setCameraLookAtFromAngles
