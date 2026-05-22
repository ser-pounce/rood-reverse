nonmatching _initGameData, 0x1CC

glabel _initGameData
    /* 9314 80071B14 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 9318 80071B18 80020424 */  addiu      $a0, $zero, 0x280
    /* 931C 80071B1C F0000524 */  addiu      $a1, $zero, 0xF0
    /* 9320 80071B20 00020624 */  addiu      $a2, $zero, 0x200
    /* 9324 80071B24 21380000 */  addu       $a3, $zero, $zero
    /* 9328 80071B28 2000BFAF */  sw         $ra, 0x20($sp)
    /* 932C 80071B2C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 9330 80071B30 1800B0AF */  sw         $s0, 0x18($sp)
    /* 9334 80071B34 1000A0AF */  sw         $zero, 0x10($sp)
    /* 9338 80071B38 0FC6010C */  jal        func_8007183C
    /* 933C 80071B3C 1400A0AF */   sw        $zero, 0x14($sp)
    /* 9340 80071B40 3F041124 */  addiu      $s1, $zero, 0x43F
    /* 9344 80071B44 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 9348 80071B48 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 934C 80071B4C 21105100 */  addu       $v0, $v0, $s1
  .L80071B50:
    /* 9350 80071B50 000040A0 */  sb         $zero, 0x0($v0)
    /* 9354 80071B54 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 9358 80071B58 FDFF2106 */  bgez       $s1, .L80071B50
    /* 935C 80071B5C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 9360 80071B60 0680043C */  lui        $a0, %hi(vs_main_skillsLearned)
    /* 9364 80071B64 B8FF8424 */  addiu      $a0, $a0, %lo(vs_main_skillsLearned)
    /* 9368 80071B68 0780053C */  lui        $a1, %hi(_skillsLearned)
    /* 936C 80071B6C 245BA524 */  addiu      $a1, $a1, %lo(_skillsLearned)
    /* 9370 80071B70 2C24010C */  jal        vs_main_memcpy
    /* 9374 80071B74 20000624 */   addiu     $a2, $zero, 0x20
    /* 9378 80071B78 0680043C */  lui        $a0, %hi(vs_main_mapStatus)
    /* 937C 80071B7C D8FF8424 */  addiu      $a0, $a0, %lo(vs_main_mapStatus)
    /* 9380 80071B80 4424010C */  jal        vs_main_bzero
    /* 9384 80071B84 48000524 */   addiu     $a1, $zero, 0x48
    /* 9388 80071B88 0680043C */  lui        $a0, %hi(vs_main_gametime)
    /* 938C 80071B8C 74108424 */  addiu      $a0, $a0, %lo(vs_main_gametime)
    /* 9390 80071B90 4424010C */  jal        vs_main_bzero
    /* 9394 80071B94 04000524 */   addiu     $a1, $zero, 0x4
    /* 9398 80071B98 0680103C */  lui        $s0, %hi(vs_main_scoredata)
    /* 939C 80071B9C A0FE1026 */  addiu      $s0, $s0, %lo(vs_main_scoredata)
    /* 93A0 80071BA0 21200002 */  addu       $a0, $s0, $zero
    /* 93A4 80071BA4 4424010C */  jal        vs_main_bzero
    /* 93A8 80071BA8 14010524 */   addiu     $a1, $zero, 0x114
    /* 93AC 80071BAC 0680023C */  lui        $v0, %hi(D_80060064)
    /* 93B0 80071BB0 640040AC */  sw         $zero, %lo(D_80060064)($v0)
    /* 93B4 80071BB4 0680043C */  lui        $a0, %hi(D_80061078)
    /* 93B8 80071BB8 78108424 */  addiu      $a0, $a0, %lo(D_80061078)
    /* 93BC 80071BBC 4424010C */  jal        vs_main_bzero
    /* 93C0 80071BC0 20050524 */   addiu     $a1, $zero, 0x520
    /* 93C4 80071BC4 0680043C */  lui        $a0, %hi(vs_main_artsStatus)
    /* 93C8 80071BC8 40008424 */  addiu      $a0, $a0, %lo(vs_main_artsStatus)
    /* 93CC 80071BCC 4424010C */  jal        vs_main_bzero
    /* 93D0 80071BD0 24000524 */   addiu     $a1, $zero, 0x24
    /* 93D4 80071BD4 21880000 */  addu       $s1, $zero, $zero
    /* 93D8 80071BD8 00FF0A3C */  lui        $t2, (0xFF000000 >> 16)
    /* 93DC 80071BDC 8000093C */  lui        $t1, (0x800000 >> 16)
    /* 93E0 80071BE0 FF80083C */  lui        $t0, (0x80FFFFFF >> 16)
    /* 93E4 80071BE4 FFFF0835 */  ori        $t0, $t0, (0x80FFFFFF & 0xFFFF)
    /* 93E8 80071BE8 21382002 */  addu       $a3, $s1, $zero
  .L80071BEC:
    /* 93EC 80071BEC 21280000 */  addu       $a1, $zero, $zero
    /* 93F0 80071BF0 FF7F063C */  lui        $a2, (0x7FFFFFFF >> 16)
    /* 93F4 80071BF4 FFFFC634 */  ori        $a2, $a2, (0x7FFFFFFF & 0xFFFF)
    /* 93F8 80071BF8 2120E000 */  addu       $a0, $a3, $zero
  .L80071BFC:
    /* 93FC 80071BFC 21109000 */  addu       $v0, $a0, $s0
    /* 9400 80071C00 2800438C */  lw         $v1, 0x28($v0)
    /* 9404 80071C04 0100A524 */  addiu      $a1, $a1, 0x1
    /* 9408 80071C08 24186A00 */  and        $v1, $v1, $t2
    /* 940C 80071C0C 25186900 */  or         $v1, $v1, $t1
    /* 9410 80071C10 24186800 */  and        $v1, $v1, $t0
    /* 9414 80071C14 24186600 */  and        $v1, $v1, $a2
    /* 9418 80071C18 280043AC */  sw         $v1, 0x28($v0)
    /* 941C 80071C1C 0300A228 */  slti       $v0, $a1, 0x3
    /* 9420 80071C20 F6FF4014 */  bnez       $v0, .L80071BFC
    /* 9424 80071C24 04008424 */   addiu     $a0, $a0, 0x4
    /* 9428 80071C28 01003126 */  addiu      $s1, $s1, 0x1
    /* 942C 80071C2C 0800222A */  slti       $v0, $s1, 0x8
    /* 9430 80071C30 EEFF4014 */  bnez       $v0, .L80071BEC
    /* 9434 80071C34 0C00E724 */   addiu     $a3, $a3, 0xC
    /* 9438 80071C38 21880000 */  addu       $s1, $zero, $zero
    /* 943C 80071C3C 0680023C */  lui        $v0, %hi(D_80060068)
    /* 9440 80071C40 68005024 */  addiu      $s0, $v0, %lo(D_80060068)
  .L80071C44:
    /* 9444 80071C44 21200002 */  addu       $a0, $s0, $zero
    /* 9448 80071C48 4424010C */  jal        vs_main_bzero
    /* 944C 80071C4C 50000524 */   addiu     $a1, $zero, 0x50
    /* 9450 80071C50 01003126 */  addiu      $s1, $s1, 0x1
    /* 9454 80071C54 FBFF201A */  blez       $s1, .L80071C44
    /* 9458 80071C58 00011026 */   addiu     $s0, $s0, 0x100
    /* 945C 80071C5C 0680103C */  lui        $s0, %hi(D_80061068)
    /* 9460 80071C60 68101026 */  addiu      $s0, $s0, %lo(D_80061068)
    /* 9464 80071C64 21200002 */  addu       $a0, $s0, $zero
    /* 9468 80071C68 4424010C */  jal        vs_main_bzero
    /* 946C 80071C6C 0C000524 */   addiu     $a1, $zero, 0xC
    /* 9470 80071C70 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* 9474 80071C74 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 9478 80071C78 0780053C */  lui        $a1, %hi(D_80074C24)
    /* 947C 80071C7C 244CA524 */  addiu      $a1, $a1, %lo(D_80074C24)
    /* 9480 80071C80 2C24010C */  jal        vs_main_memcpy
    /* 9484 80071C84 000F0624 */   addiu     $a2, $zero, 0xF00
    /* 9488 80071C88 0680043C */  lui        $a0, %hi(vs_gametime_tickspeed)
    /* 948C 80071C8C 04000296 */  lhu        $v0, 0x4($s0)
    /* 9490 80071C90 02000324 */  addiu      $v1, $zero, 0x2
    /* 9494 80071C94 4CE283AC */  sw         $v1, %lo(vs_gametime_tickspeed)($a0)
    /* 9498 80071C98 06000396 */  lhu        $v1, 0x6($s0)
    /* 949C 80071C9C 02000496 */  lhu        $a0, 0x2($s0)
    /* 94A0 80071CA0 FFE04230 */  andi       $v0, $v0, 0xE0FF
    /* 94A4 80071CA4 00044234 */  ori        $v0, $v0, 0x400
    /* 94A8 80071CA8 FF836330 */  andi       $v1, $v1, 0x83FF
    /* 94AC 80071CAC 00086334 */  ori        $v1, $v1, 0x800
    /* 94B0 80071CB0 FF1F8430 */  andi       $a0, $a0, 0x1FFF
    /* 94B4 80071CB4 040002A6 */  sh         $v0, 0x4($s0)
    /* 94B8 80071CB8 FF9F4230 */  andi       $v0, $v0, 0x9FFF
    /* 94BC 80071CBC 00404234 */  ori        $v0, $v0, 0x4000
    /* 94C0 80071CC0 060003A6 */  sh         $v1, 0x6($s0)
    /* 94C4 80071CC4 020004A6 */  sh         $a0, 0x2($s0)
    /* 94C8 80071CC8 040002A6 */  sh         $v0, 0x4($s0)
    /* 94CC 80071CCC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 94D0 80071CD0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 94D4 80071CD4 1800B08F */  lw         $s0, 0x18($sp)
    /* 94D8 80071CD8 0800E003 */  jr         $ra
    /* 94DC 80071CDC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initGameData
