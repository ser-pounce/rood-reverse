nonmatching func_8007629C, 0x1E0

glabel func_8007629C
    /* DA9C 8007629C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* DAA0 800762A0 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* DAA4 800762A4 21B88000 */  addu       $s7, $a0, $zero
    /* DAA8 800762A8 0680033C */  lui        $v1, %hi(vs_main_frameBuf)
    /* DAAC 800762AC 10E2628C */  lw         $v0, %lo(vs_main_frameBuf)($v1)
    /* DAB0 800762B0 21200000 */  addu       $a0, $zero, $zero
    /* DAB4 800762B4 3000BFAF */  sw         $ra, 0x30($sp)
    /* DAB8 800762B8 2800B6AF */  sw         $s6, 0x28($sp)
    /* DABC 800762BC 2400B5AF */  sw         $s5, 0x24($sp)
    /* DAC0 800762C0 2000B4AF */  sw         $s4, 0x20($sp)
    /* DAC4 800762C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* DAC8 800762C8 1800B2AF */  sw         $s2, 0x18($sp)
    /* DACC 800762CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* DAD0 800762D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* DAD4 800762D4 0100422C */  sltiu      $v0, $v0, 0x1
    /* DAD8 800762D8 EA09010C */  jal        vs_main_getRand
    /* DADC 800762DC 10E262AC */   sw        $v0, %lo(vs_main_frameBuf)($v1)
    /* DAE0 800762E0 A0000424 */  addiu      $a0, $zero, 0xA0
    /* DAE4 800762E4 5005010C */  jal        SetGeomOffset
    /* DAE8 800762E8 70000524 */   addiu     $a1, $zero, 0x70
    /* DAEC 800762EC 94A1000C */  jal        DrawSync
    /* DAF0 800762F0 21200000 */   addu      $a0, $zero, $zero
    /* DAF4 800762F4 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* DAF8 800762F8 4CE2448C */  lw         $a0, %lo(vs_gametime_tickspeed)($v0)
    /* DAFC 800762FC 8709010C */  jal        vs_main_gametimeUpdate
    /* DB00 80076300 00000000 */   nop
    /* DB04 80076304 0580043C */  lui        $a0, %hi(D_8004A52C)
    /* DB08 80076308 2CA5838C */  lw         $v1, %lo(D_8004A52C)($a0)
    /* DB0C 8007630C 00000000 */  nop
    /* DB10 80076310 34006010 */  beqz       $v1, .L800763E4
    /* DB14 80076314 21B04000 */   addu      $s6, $v0, $zero
    /* DB18 80076318 0680103C */  lui        $s0, %hi(vs_main_buttonsState)
    /* DB1C 8007631C 0680023C */  lui        $v0, %hi(vs_main_padBuffer)
    /* DB20 80076320 F0DF5224 */  addiu      $s2, $v0, %lo(vs_main_padBuffer)
    /* DB24 80076324 22005426 */  addiu      $s4, $s2, 0x22
    /* DB28 80076328 0680153C */  lui        $s5, %hi(vs_main_buttonsPressed)
    /* DB2C 8007632C 0680133C */  lui        $s3, %hi(vs_main_buttonsPreviousState)
    /* DB30 80076330 21888000 */  addu       $s1, $a0, $zero
  .L80076334:
    /* DB34 80076334 8709010C */  jal        vs_main_gametimeUpdate
    /* DB38 80076338 02000424 */   addiu     $a0, $zero, 0x2
    /* DB3C 8007633C 21200000 */  addu       $a0, $zero, $zero
    /* DB40 80076340 3D0C010C */  jal        vs_main_updatePadState
    /* DB44 80076344 21284002 */   addu      $a1, $s2, $zero
    /* DB48 80076348 10000424 */  addiu      $a0, $zero, 0x10
    /* DB4C 8007634C 21288002 */  addu       $a1, $s4, $zero
    /* DB50 80076350 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* DB54 80076354 3D0C010C */  jal        vs_main_updatePadState
    /* DB58 80076358 38E202AE */   sw        $v0, %lo(vs_main_buttonsState)($s0)
    /* DB5C 8007635C 21200000 */  addu       $a0, $zero, $zero
    /* DB60 80076360 21284002 */  addu       $a1, $s2, $zero
    /* DB64 80076364 38E2038E */  lw         $v1, %lo(vs_main_buttonsState)($s0)
    /* DB68 80076368 00140200 */  sll        $v0, $v0, 16
    /* DB6C 8007636C 25186200 */  or         $v1, $v1, $v0
    /* DB70 80076370 940C010C */  jal        vs_main_padConnect
    /* DB74 80076374 38E203AE */   sw        $v1, %lo(vs_main_buttonsState)($s0)
    /* DB78 80076378 10000424 */  addiu      $a0, $zero, 0x10
    /* DB7C 8007637C 940C010C */  jal        vs_main_padConnect
    /* DB80 80076380 21288002 */   addu      $a1, $s4, $zero
    /* DB84 80076384 0580063C */  lui        $a2, %hi(vs_main_buttonsReleased)
    /* DB88 80076388 C0E1638E */  lw         $v1, %lo(vs_main_buttonsPreviousState)($s3)
    /* DB8C 8007638C 38E2058E */  lw         $a1, %lo(vs_main_buttonsState)($s0)
    /* DB90 80076390 27200300 */  nor        $a0, $zero, $v1
    /* DB94 80076394 24208500 */  and        $a0, $a0, $a1
    /* DB98 80076398 27100500 */  nor        $v0, $zero, $a1
    /* DB9C 8007639C 24186200 */  and        $v1, $v1, $v0
    /* DBA0 800763A0 D0E1A4AE */  sw         $a0, %lo(vs_main_buttonsPressed)($s5)
    /* DBA4 800763A4 02240400 */  srl        $a0, $a0, 16
    /* DBA8 800763A8 00088230 */  andi       $v0, $a0, 0x800
    /* DBAC 800763AC 785CC3AC */  sw         $v1, %lo(vs_main_buttonsReleased)($a2)
    /* DBB0 800763B0 05004010 */  beqz       $v0, .L800763C8
    /* DBB4 800763B4 C0E165AE */   sw        $a1, %lo(vs_main_buttonsPreviousState)($s3)
    /* DBB8 800763B8 2CA5228E */  lw         $v0, %lo(D_8004A52C)($s1)
    /* DBBC 800763BC 00000000 */  nop
    /* DBC0 800763C0 01004238 */  xori       $v0, $v0, 0x1
    /* DBC4 800763C4 2CA522AE */  sw         $v0, %lo(D_8004A52C)($s1)
  .L800763C8:
    /* DBC8 800763C8 00018230 */  andi       $v0, $a0, 0x100
    /* DBCC 800763CC 05004014 */  bnez       $v0, .L800763E4
    /* DBD0 800763D0 00000000 */   nop
    /* DBD4 800763D4 2CA5228E */  lw         $v0, %lo(D_8004A52C)($s1)
    /* DBD8 800763D8 00000000 */  nop
    /* DBDC 800763DC D5FF4014 */  bnez       $v0, .L80076334
    /* DBE0 800763E0 00000000 */   nop
  .L800763E4:
    /* DBE4 800763E4 0680103C */  lui        $s0, %hi(vs_main_frameBuf)
    /* DBE8 800763E8 0680043C */  lui        $a0, %hi(vs_main_dispEnv)
    /* DBEC 800763EC 10E2038E */  lw         $v1, %lo(vs_main_frameBuf)($s0)
    /* DBF0 800763F0 88E18424 */  addiu      $a0, $a0, %lo(vs_main_dispEnv)
    /* DBF4 800763F4 80100300 */  sll        $v0, $v1, 2
    /* DBF8 800763F8 21104300 */  addu       $v0, $v0, $v1
    /* DBFC 800763FC 80100200 */  sll        $v0, $v0, 2
    /* DC00 80076400 A0A3000C */  jal        PutDispEnv
    /* DC04 80076404 21204400 */   addu      $a0, $v0, $a0
    /* DC08 80076408 10E2028E */  lw         $v0, %lo(vs_main_frameBuf)($s0)
    /* DC0C 8007640C 00000000 */  nop
    /* DC10 80076410 40200200 */  sll        $a0, $v0, 1
    /* DC14 80076414 21208200 */  addu       $a0, $a0, $v0
    /* DC18 80076418 C0200400 */  sll        $a0, $a0, 3
    /* DC1C 8007641C 23208200 */  subu       $a0, $a0, $v0
    /* DC20 80076420 80200400 */  sll        $a0, $a0, 2
    /* DC24 80076424 0680023C */  lui        $v0, %hi(vs_main_drawEnv)
    /* DC28 80076428 D0E04224 */  addiu      $v0, $v0, %lo(vs_main_drawEnv)
    /* DC2C 8007642C 2DA3000C */  jal        PutDrawEnv
    /* DC30 80076430 21208200 */   addu      $a0, $a0, $v0
    /* DC34 80076434 E323010C */  jal        vs_main_commitClut
    /* DC38 80076438 00000000 */   nop
    /* DC3C 8007643C 11A3000C */  jal        DrawOTag
    /* DC40 80076440 2120E002 */   addu      $a0, $s7, $zero
    /* DC44 80076444 FB9E000C */  jal        FntFlush
    /* DC48 80076448 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* DC4C 8007644C 2110C002 */  addu       $v0, $s6, $zero
    /* DC50 80076450 3000BF8F */  lw         $ra, 0x30($sp)
    /* DC54 80076454 2C00B78F */  lw         $s7, 0x2C($sp)
    /* DC58 80076458 2800B68F */  lw         $s6, 0x28($sp)
    /* DC5C 8007645C 2400B58F */  lw         $s5, 0x24($sp)
    /* DC60 80076460 2000B48F */  lw         $s4, 0x20($sp)
    /* DC64 80076464 1C00B38F */  lw         $s3, 0x1C($sp)
    /* DC68 80076468 1800B28F */  lw         $s2, 0x18($sp)
    /* DC6C 8007646C 1400B18F */  lw         $s1, 0x14($sp)
    /* DC70 80076470 1000B08F */  lw         $s0, 0x10($sp)
    /* DC74 80076474 0800E003 */  jr         $ra
    /* DC78 80076478 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8007629C
