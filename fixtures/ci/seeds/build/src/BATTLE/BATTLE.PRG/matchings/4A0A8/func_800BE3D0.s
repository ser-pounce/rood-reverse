nonmatching func_800BE3D0, 0x16C

glabel func_800BE3D0
    /* 55BD0 800BE3D0 98FFBD27 */  addiu      $sp, $sp, -0x68
    /* 55BD4 800BE3D4 5000B0AF */  sw         $s0, 0x50($sp)
    /* 55BD8 800BE3D8 21808000 */  addu       $s0, $a0, $zero
    /* 55BDC 800BE3DC AF000424 */  addiu      $a0, $zero, 0xAF
    /* 55BE0 800BE3E0 6400BFAF */  sw         $ra, 0x64($sp)
    /* 55BE4 800BE3E4 6000B4AF */  sw         $s4, 0x60($sp)
    /* 55BE8 800BE3E8 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 55BEC 800BE3EC 5800B2AF */  sw         $s2, 0x58($sp)
    /* 55BF0 800BE3F0 FDFA020C */  jal        vs_battle_getStateFlag
    /* 55BF4 800BE3F4 5400B1AF */   sw        $s1, 0x54($sp)
    /* 55BF8 800BE3F8 B0000424 */  addiu      $a0, $zero, 0xB0
    /* 55BFC 800BE3FC FDFA020C */  jal        vs_battle_getStateFlag
    /* 55C00 800BE400 21984000 */   addu      $s3, $v0, $zero
    /* 55C04 800BE404 3000B227 */  addiu      $s2, $sp, 0x30
    /* 55C08 800BE408 21204002 */  addu       $a0, $s2, $zero
    /* 55C0C 800BE40C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 55C10 800BE410 FF007332 */  andi       $s3, $s3, 0xFF
    /* 55C14 800BE414 FFFF6626 */  addiu      $a2, $s3, -0x1
    /* 55C18 800BE418 FF001032 */  andi       $s0, $s0, 0xFF
    /* 55C1C 800BE41C 40801000 */  sll        $s0, $s0, 1
    /* 55C20 800BE420 2130D000 */  addu       $a2, $a2, $s0
    /* 55C24 800BE424 0700C630 */  andi       $a2, $a2, 0x7
    /* 55C28 800BE428 FF005030 */  andi       $s0, $v0, 0xFF
    /* 55C2C 800BE42C 01001426 */  addiu      $s4, $s0, 0x1
    /* 55C30 800BE430 5CF3010C */  jal        vs_battle_initialiseCameraFromSpherical
    /* 55C34 800BE434 21388002 */   addu      $a3, $s4, $zero
    /* 55C38 800BE438 0F80113C */  lui        $s1, %hi(D_800F4BA4)
    /* 55C3C 800BE43C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 55C40 800BE440 0F80023C */  lui        $v0, %hi(D_800E9C24)
    /* 55C44 800BE444 249C4224 */  addiu      $v0, $v0, %lo(D_800E9C24)
    /* 55C48 800BE448 40801000 */  sll        $s0, $s0, 1
    /* 55C4C 800BE44C 21800202 */  addu       $s0, $s0, $v0
    /* 55C50 800BE450 A44B248E */  lw         $a0, %lo(D_800F4BA4)($s1)
    /* 55C54 800BE454 00000286 */  lh         $v0, 0x0($s0)
    /* 55C58 800BE458 3400A38F */  lw         $v1, 0x34($sp)
    /* 55C5C 800BE45C 94008424 */  addiu      $a0, $a0, 0x94
    /* 55C60 800BE460 00130200 */  sll        $v0, $v0, 12
    /* 55C64 800BE464 21186200 */  addu       $v1, $v1, $v0
    /* 55C68 800BE468 3400A3AF */  sw         $v1, 0x34($sp)
    /* 55C6C 800BE46C 00000286 */  lh         $v0, 0x0($s0)
    /* 55C70 800BE470 1400A38F */  lw         $v1, 0x14($sp)
    /* 55C74 800BE474 00130200 */  sll        $v0, $v0, 12
    /* 55C78 800BE478 21186200 */  addu       $v1, $v1, $v0
    /* 55C7C 800BE47C C7F9020C */  jal        _copyVector
    /* 55C80 800BE480 1400A3AF */   sw        $v1, 0x14($sp)
    /* 55C84 800BE484 A44B248E */  lw         $a0, %lo(D_800F4BA4)($s1)
    /* 55C88 800BE488 21284002 */  addu       $a1, $s2, $zero
    /* 55C8C 800BE48C C7F9020C */  jal        _copyVector
    /* 55C90 800BE490 A4008424 */   addiu     $a0, $a0, 0xA4
    /* 55C94 800BE494 A44B248E */  lw         $a0, %lo(D_800F4BA4)($s1)
    /* 55C98 800BE498 1000A527 */  addiu      $a1, $sp, 0x10
    /* 55C9C 800BE49C C7F9020C */  jal        _copyVector
    /* 55CA0 800BE4A0 58018424 */   addiu     $a0, $a0, 0x158
    /* 55CA4 800BE4A4 A44B248E */  lw         $a0, %lo(D_800F4BA4)($s1)
    /* 55CA8 800BE4A8 21284002 */  addu       $a1, $s2, $zero
    /* 55CAC 800BE4AC C7F9020C */  jal        _copyVector
    /* 55CB0 800BE4B0 48018424 */   addiu     $a0, $a0, 0x148
    /* 55CB4 800BE4B4 4000B027 */  addiu      $s0, $sp, 0x40
    /* 55CB8 800BE4B8 21200002 */  addu       $a0, $s0, $zero
    /* 55CBC 800BE4BC 2000B227 */  addiu      $s2, $sp, 0x20
    /* 55CC0 800BE4C0 21284002 */  addu       $a1, $s2, $zero
    /* 55CC4 800BE4C4 21306002 */  addu       $a2, $s3, $zero
    /* 55CC8 800BE4C8 21388002 */  addu       $a3, $s4, $zero
    /* 55CCC 800BE4CC A44B238E */  lw         $v1, %lo(D_800F4BA4)($s1)
    /* 55CD0 800BE4D0 0F000224 */  addiu      $v0, $zero, 0xF
    /* 55CD4 800BE4D4 5CF3010C */  jal        vs_battle_initialiseCameraFromSpherical
    /* 55CD8 800BE4D8 000062A0 */   sb        $v0, 0x0($v1)
    /* 55CDC 800BE4DC A44B248E */  lw         $a0, %lo(D_800F4BA4)($s1)
    /* 55CE0 800BE4E0 21280002 */  addu       $a1, $s0, $zero
    /* 55CE4 800BE4E4 C7F9020C */  jal        _copyVector
    /* 55CE8 800BE4E8 D8008424 */   addiu     $a0, $a0, 0xD8
    /* 55CEC 800BE4EC A44B248E */  lw         $a0, %lo(D_800F4BA4)($s1)
    /* 55CF0 800BE4F0 21284002 */  addu       $a1, $s2, $zero
    /* 55CF4 800BE4F4 C7F9020C */  jal        _copyVector
    /* 55CF8 800BE4F8 24008424 */   addiu     $a0, $a0, 0x24
    /* 55CFC 800BE4FC 0F80043C */  lui        $a0, %hi(D_800E9C28)
    /* 55D00 800BE500 289C8424 */  addiu      $a0, $a0, %lo(D_800E9C28)
    /* 55D04 800BE504 BAF0020C */  jal        func_800BC2E8
    /* 55D08 800BE508 21280000 */   addu      $a1, $zero, $zero
    /* 55D0C 800BE50C 0F80043C */  lui        $a0, %hi(D_800E9C2C)
    /* 55D10 800BE510 2C9C8424 */  addiu      $a0, $a0, %lo(D_800E9C2C)
    /* 55D14 800BE514 BAF0020C */  jal        func_800BC2E8
    /* 55D18 800BE518 21280000 */   addu      $a1, $zero, $zero
    /* 55D1C 800BE51C 6400BF8F */  lw         $ra, 0x64($sp)
    /* 55D20 800BE520 6000B48F */  lw         $s4, 0x60($sp)
    /* 55D24 800BE524 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 55D28 800BE528 5800B28F */  lw         $s2, 0x58($sp)
    /* 55D2C 800BE52C 5400B18F */  lw         $s1, 0x54($sp)
    /* 55D30 800BE530 5000B08F */  lw         $s0, 0x50($sp)
    /* 55D34 800BE534 0800E003 */  jr         $ra
    /* 55D38 800BE538 6800BD27 */   addiu     $sp, $sp, 0x68
endlabel func_800BE3D0
