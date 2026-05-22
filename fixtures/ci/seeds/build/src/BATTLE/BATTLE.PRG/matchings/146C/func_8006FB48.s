nonmatching func_8006FB48, 0x84

glabel func_8006FB48
    /* 7348 8006FB48 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 734C 8006FB4C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7350 8006FB50 FDFA020C */  jal        vs_battle_getStateFlag
    /* 7354 8006FB54 AB000424 */   addiu     $a0, $zero, 0xAB
    /* 7358 8006FB58 FF004230 */  andi       $v0, $v0, 0xFF
    /* 735C 8006FB5C 0300422C */  sltiu      $v0, $v0, 0x3
    /* 7360 8006FB60 14004014 */  bnez       $v0, .L8006FBB4
    /* 7364 8006FB64 0F80023C */   lui       $v0, %hi(_lootListHead)
    /* 7368 8006FB68 0019448C */  lw         $a0, %lo(_lootListHead)($v0)
    /* 736C 8006FB6C 00000000 */  nop
    /* 7370 8006FB70 0C008010 */  beqz       $a0, .L8006FBA4
    /* 7374 8006FB74 00000000 */   nop
    /* 7378 8006FB78 562C030C */  jal        func_800CB158
    /* 737C 8006FB7C 00000000 */   nop
    /* 7380 8006FB80 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* 7384 8006FB84 02000224 */  addiu      $v0, $zero, 0x2
    /* 7388 8006FB88 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* 738C 8006FB8C 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 7390 8006FB90 0C000224 */  addiu      $v0, $zero, 0xC
    /* 7394 8006FB94 E7B0010C */  jal        func_8006C39C
    /* 7398 8006FB98 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 739C 8006FB9C EFBE0108 */  j          .L8006FBBC
    /* 73A0 8006FBA0 00000000 */   nop
  .L8006FBA4:
    /* 73A4 8006FBA4 27BE010C */  jal        func_8006F89C
    /* 73A8 8006FBA8 00000000 */   nop
    /* 73AC 8006FBAC EFBE0108 */  j          .L8006FBBC
    /* 73B0 8006FBB0 00000000 */   nop
  .L8006FBB4:
    /* 73B4 8006FBB4 7FBD010C */  jal        func_8006F5FC
    /* 73B8 8006FBB8 00000000 */   nop
  .L8006FBBC:
    /* 73BC 8006FBBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 73C0 8006FBC0 00000000 */  nop
    /* 73C4 8006FBC4 0800E003 */  jr         $ra
    /* 73C8 8006FBC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006FB48
