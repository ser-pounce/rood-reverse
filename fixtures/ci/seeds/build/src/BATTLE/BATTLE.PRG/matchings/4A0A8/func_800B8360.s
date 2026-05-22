nonmatching func_800B8360, 0x74

glabel func_800B8360
    /* 4FB60 800B8360 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4FB64 800B8364 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4FB68 800B8368 21808000 */  addu       $s0, $a0, $zero
    /* 4FB6C 800B836C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4FB70 800B8370 80FF020C */  jal        vs_battle_getShort
    /* 4FB74 800B8374 03000426 */   addiu     $a0, $s0, 0x3
    /* 4FB78 800B8378 05000426 */  addiu      $a0, $s0, 0x5
    /* 4FB7C 800B837C 80FF020C */  jal        vs_battle_getShort
    /* 4FB80 800B8380 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 4FB84 800B8384 01000426 */  addiu      $a0, $s0, 0x1
    /* 4FB88 800B8388 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 4FB8C 800B838C 80FF020C */  jal        vs_battle_getShort
    /* 4FB90 800B8390 1400A0A7 */   sh        $zero, 0x14($sp)
    /* 4FB94 800B8394 94FF020C */  jal        func_800BFE50
    /* 4FB98 800B8398 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FB9C 800B839C 07000392 */  lbu        $v1, 0x7($s0)
    /* 4FBA0 800B83A0 00000000 */  nop
    /* 4FBA4 800B83A4 02006010 */  beqz       $v1, .L800B83B0
    /* 4FBA8 800B83A8 00100724 */   addiu     $a3, $zero, 0x1000
    /* 4FBAC 800B83AC 21386000 */  addu       $a3, $v1, $zero
  .L800B83B0:
    /* 4FBB0 800B83B0 21204000 */  addu       $a0, $v0, $zero
    /* 4FBB4 800B83B4 FCFF0524 */  addiu      $a1, $zero, -0x4
    /* 4FBB8 800B83B8 187F020C */  jal        func_8009FC60
    /* 4FBBC 800B83BC 1000A627 */   addiu     $a2, $sp, 0x10
    /* 4FBC0 800B83C0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4FBC4 800B83C4 1800B08F */  lw         $s0, 0x18($sp)
    /* 4FBC8 800B83C8 21100000 */  addu       $v0, $zero, $zero
    /* 4FBCC 800B83CC 0800E003 */  jr         $ra
    /* 4FBD0 800B83D0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B8360
