nonmatching func_8008A3A0, 0x13C

glabel func_8008A3A0
    /* 21BA0 8008A3A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21BA4 8008A3A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21BA8 8008A3A8 21800000 */  addu       $s0, $zero, $zero
    /* 21BAC 8008A3AC 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 21BB0 8008A3B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 21BB4 8008A3B4 00005124 */  addiu      $s1, $v0, %lo(D_1F800000)
    /* 21BB8 8008A3B8 0580023C */  lui        $v0, %hi(D_80055C80)
    /* 21BBC 8008A3BC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 21BC0 8008A3C0 805C5224 */  addiu      $s2, $v0, %lo(D_80055C80)
    /* 21BC4 8008A3C4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 21BC8 8008A3C8 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
  .L8008A3CC:
    /* 21BCC 8008A3CC 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 21BD0 8008A3D0 00000000 */  nop
    /* 21BD4 8008A3D4 80100200 */  sll        $v0, $v0, 2
    /* 21BD8 8008A3D8 21105200 */  addu       $v0, $v0, $s2
    /* 21BDC 8008A3DC 0000448C */  lw         $a0, 0x0($v0)
    /* 21BE0 8008A3E0 00080524 */  addiu      $a1, $zero, 0x800
    /* 21BE4 8008A3E4 10008424 */  addiu      $a0, $a0, 0x10
    /* 21BE8 8008A3E8 CFA2000C */  jal        ClearOTagR
    /* 21BEC 8008A3EC 040024AE */   sw        $a0, 0x4($s1)
    /* 21BF0 8008A3F0 D0F7010C */  jal        func_8007DF40
    /* 21BF4 8008A3F4 01001026 */   addiu     $s0, $s0, 0x1
    /* 21BF8 8008A3F8 0400248E */  lw         $a0, 0x4($s1)
    /* 21BFC 8008A3FC 29B4010C */  jal        _drawScreenTransition
    /* 21C00 8008A400 00000000 */   nop
    /* 21C04 8008A404 0400248E */  lw         $a0, 0x4($s1)
    /* 21C08 8008A408 A7D8010C */  jal        func_8007629C
    /* 21C0C 8008A40C FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 21C10 8008A410 0200022A */  slti       $v0, $s0, 0x2
    /* 21C14 8008A414 EDFF4014 */  bnez       $v0, .L8008A3CC
    /* 21C18 8008A418 0680023C */   lui       $v0, %hi(vs_main_frameBuf)
    /* 21C1C 8008A41C 94A1000C */  jal        DrawSync
    /* 21C20 8008A420 21200000 */   addu      $a0, $zero, $zero
    /* 21C24 8008A424 8709010C */  jal        vs_main_gametimeUpdate
    /* 21C28 8008A428 21200000 */   addu      $a0, $zero, $zero
    /* 21C2C 8008A42C CDFA020C */  jal        func_800BEB34
    /* 21C30 8008A430 00000000 */   nop
    /* 21C34 8008A434 4FBD010C */  jal        _setRoomSeen
    /* 21C38 8008A438 00000000 */   nop
    /* 21C3C 8008A43C FC2A020C */  jal        func_8008ABF0
    /* 21C40 8008A440 21200000 */   addu      $a0, $zero, $zero
    /* 21C44 8008A444 0F80023C */  lui        $v0, %hi(D_800F18E4)
    /* 21C48 8008A448 E418448C */  lw         $a0, %lo(D_800F18E4)($v0)
    /* 21C4C 8008A44C 00000000 */  nop
    /* 21C50 8008A450 04008010 */  beqz       $a0, .L8008A464
    /* 21C54 8008A454 0F80023C */   lui       $v0, %hi(D_800F192C)
    /* 21C58 8008A458 540F010C */  jal        vs_main_freeHeap
    /* 21C5C 8008A45C 00000000 */   nop
    /* 21C60 8008A460 0F80023C */  lui        $v0, %hi(D_800F192C)
  .L8008A464:
    /* 21C64 8008A464 2C19448C */  lw         $a0, %lo(D_800F192C)($v0)
    /* 21C68 8008A468 00000000 */  nop
    /* 21C6C 8008A46C 03008010 */  beqz       $a0, .L8008A47C
    /* 21C70 8008A470 00000000 */   nop
    /* 21C74 8008A474 159D030C */  jal        func_800E7454
    /* 21C78 8008A478 00000000 */   nop
  .L8008A47C:
    /* 21C7C 8008A47C D928020C */  jal        func_8008A364
    /* 21C80 8008A480 0680103C */   lui       $s0, %hi(D_8005E0C0)
    /* 21C84 8008A484 C79B030C */  jal        func_800E6F1C
    /* 21C88 8008A488 00000000 */   nop
    /* 21C8C 8008A48C 21200000 */  addu       $a0, $zero, $zero
    /* 21C90 8008A490 DF56020C */  jal        func_80095B7C
    /* 21C94 8008A494 21288000 */   addu      $a1, $a0, $zero
    /* 21C98 8008A498 BD75020C */  jal        func_8009D6F4
    /* 21C9C 8008A49C 00000000 */   nop
    /* 21CA0 8008A4A0 BF29020C */  jal        func_8008A6FC
    /* 21CA4 8008A4A4 00000000 */   nop
    /* 21CA8 8008A4A8 C0E00226 */  addiu      $v0, $s0, %lo(D_8005E0C0)
    /* 21CAC 8008A4AC 0400448C */  lw         $a0, 0x4($v0)
    /* 21CB0 8008A4B0 540F010C */  jal        vs_main_freeHeap
    /* 21CB4 8008A4B4 00000000 */   nop
    /* 21CB8 8008A4B8 C0E0048E */  lw         $a0, %lo(D_8005E0C0)($s0)
    /* 21CBC 8008A4BC 540F010C */  jal        vs_main_freeHeap
    /* 21CC0 8008A4C0 00000000 */   nop
    /* 21CC4 8008A4C4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 21CC8 8008A4C8 1800B28F */  lw         $s2, 0x18($sp)
    /* 21CCC 8008A4CC 1400B18F */  lw         $s1, 0x14($sp)
    /* 21CD0 8008A4D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 21CD4 8008A4D4 0800E003 */  jr         $ra
    /* 21CD8 8008A4D8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008A3A0
