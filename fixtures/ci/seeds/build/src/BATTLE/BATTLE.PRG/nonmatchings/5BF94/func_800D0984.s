nonmatching func_800D0984, 0x184

glabel func_800D0984
    /* 68184 800D0984 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 68188 800D0988 5400B1AF */  sw         $s1, 0x54($sp)
    /* 6818C 800D098C 2188A000 */  addu       $s1, $a1, $zero
    /* 68190 800D0990 5000B0AF */  sw         $s0, 0x50($sp)
    /* 68194 800D0994 2180C000 */  addu       $s0, $a2, $zero
    /* 68198 800D0998 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 6819C 800D099C 2000B327 */  addiu      $s3, $sp, 0x20
    /* 681A0 800D09A0 21206002 */  addu       $a0, $s3, $zero
    /* 681A4 800D09A4 3000A527 */  addiu      $a1, $sp, 0x30
    /* 681A8 800D09A8 5800B2AF */  sw         $s2, 0x58($sp)
    /* 681AC 800D09AC 78003226 */  addiu      $s2, $s1, 0x78
    /* 681B0 800D09B0 21304002 */  addu       $a2, $s2, $zero
    /* 681B4 800D09B4 801F073C */  lui        $a3, %hi(D_1F800000)
    /* 681B8 800D09B8 0000E724 */  addiu      $a3, $a3, %lo(D_1F800000)
    /* 681BC 800D09BC 6000BFAF */  sw         $ra, 0x60($sp)
    /* 681C0 800D09C0 4400E28C */  lw         $v0, 0x44($a3)
    /* 681C4 800D09C4 4800E38C */  lw         $v1, 0x48($a3)
    /* 681C8 800D09C8 03130200 */  sra        $v0, $v0, 12
    /* 681CC 800D09CC 031B0300 */  sra        $v1, $v1, 12
    /* 681D0 800D09D0 2000A2AF */  sw         $v0, 0x20($sp)
    /* 681D4 800D09D4 2400A3AF */  sw         $v1, 0x24($sp)
    /* 681D8 800D09D8 4C00E28C */  lw         $v0, 0x4C($a3)
    /* 681DC 800D09DC 3400E38C */  lw         $v1, 0x34($a3)
    /* 681E0 800D09E0 03130200 */  sra        $v0, $v0, 12
    /* 681E4 800D09E4 031B0300 */  sra        $v1, $v1, 12
    /* 681E8 800D09E8 2800A2AF */  sw         $v0, 0x28($sp)
    /* 681EC 800D09EC 3000A3AF */  sw         $v1, 0x30($sp)
    /* 681F0 800D09F0 3800E28C */  lw         $v0, 0x38($a3)
    /* 681F4 800D09F4 3C00E38C */  lw         $v1, 0x3C($a3)
    /* 681F8 800D09F8 03130200 */  sra        $v0, $v0, 12
    /* 681FC 800D09FC 031B0300 */  sra        $v1, $v1, 12
    /* 68200 800D0A00 3400A2AF */  sw         $v0, 0x34($sp)
    /* 68204 800D0A04 EAEB010C */  jal        _lookAt
    /* 68208 800D0A08 3800A3AF */   sw        $v1, 0x38($sp)
    /* 6820C 800D0A0C 2000A28F */  lw         $v0, 0x20($sp)
    /* 68210 800D0A10 00000000 */  nop
    /* 68214 800D0A14 8C0022AE */  sw         $v0, 0x8C($s1)
    /* 68218 800D0A18 2400A28F */  lw         $v0, 0x24($sp)
    /* 6821C 800D0A1C 00000000 */  nop
    /* 68220 800D0A20 900022AE */  sw         $v0, 0x90($s1)
    /* 68224 800D0A24 2800A28F */  lw         $v0, 0x28($sp)
    /* 68228 800D0A28 30000012 */  beqz       $s0, .L800D0AEC
    /* 6822C 800D0A2C 940022AE */   sw        $v0, 0x94($s1)
    /* 68230 800D0A30 3000A58F */  lw         $a1, 0x30($sp)
    /* 68234 800D0A34 2000A28F */  lw         $v0, 0x20($sp)
    /* 68238 800D0A38 00000000 */  nop
    /* 6823C 800D0A3C 2328A200 */  subu       $a1, $a1, $v0
    /* 68240 800D0A40 1800A500 */  mult       $a1, $a1
    /* 68244 800D0A44 3400A48F */  lw         $a0, 0x34($sp)
    /* 68248 800D0A48 2400A28F */  lw         $v0, 0x24($sp)
    /* 6824C 800D0A4C 12380000 */  mflo       $a3
    /* 68250 800D0A50 23208200 */  subu       $a0, $a0, $v0
    /* 68254 800D0A54 00000000 */  nop
    /* 68258 800D0A58 18008400 */  mult       $a0, $a0
    /* 6825C 800D0A5C 2800A38F */  lw         $v1, 0x28($sp)
    /* 68260 800D0A60 3800A28F */  lw         $v0, 0x38($sp)
    /* 68264 800D0A64 12300000 */  mflo       $a2
    /* 68268 800D0A68 23104300 */  subu       $v0, $v0, $v1
    /* 6826C 800D0A6C 00000000 */  nop
    /* 68270 800D0A70 18004200 */  mult       $v0, $v0
    /* 68274 800D0A74 1000A5AF */  sw         $a1, 0x10($sp)
    /* 68278 800D0A78 1400A4AF */  sw         $a0, 0x14($sp)
    /* 6827C 800D0A7C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 68280 800D0A80 2120E600 */  addu       $a0, $a3, $a2
    /* 68284 800D0A84 12180000 */  mflo       $v1
    /* 68288 800D0A88 E506010C */  jal        vs_gte_rsqrt
    /* 6828C 800D0A8C 21208300 */   addu      $a0, $a0, $v1
    /* 68290 800D0A90 4800A2AF */  sw         $v0, 0x48($sp)
    /* 68294 800D0A94 4800A297 */  lhu        $v0, 0x48($sp)
    /* 68298 800D0A98 21204002 */  addu       $a0, $s2, $zero
    /* 6829C 800D0A9C 4200A0A7 */  sh         $zero, 0x42($sp)
    /* 682A0 800D0AA0 4000A0A7 */  sh         $zero, 0x40($sp)
    /* 682A4 800D0AA4 00FA4224 */  addiu      $v0, $v0, -0x600
    /* 682A8 800D0AA8 6605010C */  jal        SetRotMatrix
    /* 682AC 800D0AAC 4400A2A7 */   sh        $v0, 0x44($sp)
    /* 682B0 800D0AB0 5E05010C */  jal        SetTransMatrix
    /* 682B4 800D0AB4 21204002 */   addu      $a0, $s2, $zero
    /* 682B8 800D0AB8 4000A427 */  addiu      $a0, $sp, 0x40
    /* 682BC 800D0ABC 21286002 */  addu       $a1, $s3, $zero
    /* 682C0 800D0AC0 FB05010C */  jal        RotTrans
    /* 682C4 800D0AC4 4800A627 */   addiu     $a2, $sp, 0x48
    /* 682C8 800D0AC8 2000A28F */  lw         $v0, 0x20($sp)
    /* 682CC 800D0ACC 00000000 */  nop
    /* 682D0 800D0AD0 8C0022AE */  sw         $v0, 0x8C($s1)
    /* 682D4 800D0AD4 2400A28F */  lw         $v0, 0x24($sp)
    /* 682D8 800D0AD8 00000000 */  nop
    /* 682DC 800D0ADC 900022AE */  sw         $v0, 0x90($s1)
    /* 682E0 800D0AE0 2800A28F */  lw         $v0, 0x28($sp)
    /* 682E4 800D0AE4 00000000 */  nop
    /* 682E8 800D0AE8 940022AE */  sw         $v0, 0x94($s1)
  .L800D0AEC:
    /* 682EC 800D0AEC 6000BF8F */  lw         $ra, 0x60($sp)
    /* 682F0 800D0AF0 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 682F4 800D0AF4 5800B28F */  lw         $s2, 0x58($sp)
    /* 682F8 800D0AF8 5400B18F */  lw         $s1, 0x54($sp)
    /* 682FC 800D0AFC 5000B08F */  lw         $s0, 0x50($sp)
    /* 68300 800D0B00 0800E003 */  jr         $ra
    /* 68304 800D0B04 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_800D0984
