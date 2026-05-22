nonmatching func_8009FB64, 0x74

glabel func_8009FB64
    /* 37364 8009FB64 0F80023C */  lui        $v0, %hi(D_800F4438)
    /* 37368 8009FB68 38444724 */  addiu      $a3, $v0, %lo(D_800F4438)
    /* 3736C 8009FB6C 0000838C */  lw         $v1, 0x0($a0)
    /* 37370 8009FB70 0400858C */  lw         $a1, 0x4($a0)
    /* 37374 8009FB74 0800868C */  lw         $a2, 0x8($a0)
    /* 37378 8009FB78 0000E3AC */  sw         $v1, 0x0($a3)
    /* 3737C 8009FB7C 0400E5AC */  sw         $a1, 0x4($a3)
    /* 37380 8009FB80 0800E6AC */  sw         $a2, 0x8($a3)
    /* 37384 8009FB84 0C00838C */  lw         $v1, 0xC($a0)
    /* 37388 8009FB88 00000000 */  nop
    /* 3738C 8009FB8C 0C00E3AC */  sw         $v1, 0xC($a3)
    /* 37390 8009FB90 21280000 */  addu       $a1, $zero, $zero
    /* 37394 8009FB94 0F80023C */  lui        $v0, %hi(D_800F2458)
    /* 37398 8009FB98 58244624 */  addiu      $a2, $v0, %lo(D_800F2458)
    /* 3739C 8009FB9C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 373A0 8009FBA0 38454424 */  addiu      $a0, $v0, %lo(D_800F4538)
  .L8009FBA4:
    /* 373A4 8009FBA4 0000838C */  lw         $v1, 0x0($a0)
    /* 373A8 8009FBA8 00000000 */  nop
    /* 373AC 8009FBAC 04006010 */  beqz       $v1, .L8009FBC0
    /* 373B0 8009FBB0 00000000 */   nop
    /* 373B4 8009FBB4 E01FC294 */  lhu        $v0, 0x1FE0($a2)
    /* 373B8 8009FBB8 00000000 */  nop
    /* 373BC 8009FBBC 3C1862A4 */  sh         $v0, 0x183C($v1)
  .L8009FBC0:
    /* 373C0 8009FBC0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 373C4 8009FBC4 1100A228 */  slti       $v0, $a1, 0x11
    /* 373C8 8009FBC8 F6FF4014 */  bnez       $v0, .L8009FBA4
    /* 373CC 8009FBCC 04008424 */   addiu     $a0, $a0, 0x4
    /* 373D0 8009FBD0 0800E003 */  jr         $ra
    /* 373D4 8009FBD4 00000000 */   nop
endlabel func_8009FB64
