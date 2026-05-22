nonmatching SpuClearReverbWorkArea, 0x194

glabel SpuClearReverbWorkArea
    /* FB64 8001F364 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* FB68 8001F368 1800B0AF */  sw         $s0, 0x18($sp)
    /* FB6C 8001F36C 21808000 */  addu       $s0, $a0, $zero
    /* FB70 8001F370 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* FB74 8001F374 0A00022E */  sltiu      $v0, $s0, 0xA
    /* FB78 8001F378 3000BFAF */  sw         $ra, 0x30($sp)
    /* FB7C 8001F37C 2800B4AF */  sw         $s4, 0x28($sp)
    /* FB80 8001F380 2400B3AF */  sw         $s3, 0x24($sp)
    /* FB84 8001F384 2000B2AF */  sw         $s2, 0x20($sp)
    /* FB88 8001F388 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* FB8C 8001F38C 1000A0AF */  sw         $zero, 0x10($sp)
    /* FB90 8001F390 0A004010 */  beqz       $v0, .L8001F3BC
    /* FB94 8001F394 21A80000 */   addu      $s5, $zero, $zero
    /* FB98 8001F398 0380033C */  lui        $v1, %hi(D_80030CD0)
    /* FB9C 8001F39C D00C6324 */  addiu      $v1, $v1, %lo(D_80030CD0)
    /* FBA0 8001F3A0 80101000 */  sll        $v0, $s0, 2
    /* FBA4 8001F3A4 21884300 */  addu       $s1, $v0, $v1
    /* FBA8 8001F3A8 0000248E */  lw         $a0, 0x0($s1)
    /* FBAC 8001F3AC 217A000C */  jal        _SpuIsInAllocateArea_
    /* FBB0 8001F3B0 00000000 */   nop
    /* FBB4 8001F3B4 03004010 */  beqz       $v0, .L8001F3C4
    /* FBB8 8001F3B8 00000000 */   nop
  .L8001F3BC:
    /* FBBC 8001F3BC 357D0008 */  j          .L8001F4D4
    /* FBC0 8001F3C0 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8001F3C4:
    /* FBC4 8001F3C4 08000016 */  bnez       $s0, .L8001F3E8
    /* FBC8 8001F3C8 0100023C */   lui       $v0, (0x10000 >> 16)
    /* FBCC 8001F3CC 0380023C */  lui        $v0, %hi(D_80030888)
    /* FBD0 8001F3D0 8808428C */  lw         $v0, %lo(D_80030888)($v0)
    /* FBD4 8001F3D4 10000324 */  addiu      $v1, $zero, 0x10
    /* FBD8 8001F3D8 04884300 */  sllv       $s1, $v1, $v0
    /* FBDC 8001F3DC F0FF0334 */  ori        $v1, $zero, 0xFFF0
    /* FBE0 8001F3E0 007D0008 */  j          .L8001F400
    /* FBE4 8001F3E4 04904300 */   sllv      $s2, $v1, $v0
  .L8001F3E8:
    /* FBE8 8001F3E8 0000248E */  lw         $a0, 0x0($s1)
    /* FBEC 8001F3EC 0380033C */  lui        $v1, %hi(D_80030888)
    /* FBF0 8001F3F0 8808638C */  lw         $v1, %lo(D_80030888)($v1)
    /* FBF4 8001F3F4 23104400 */  subu       $v0, $v0, $a0
    /* FBF8 8001F3F8 04886200 */  sllv       $s1, $v0, $v1
    /* FBFC 8001F3FC 04906400 */  sllv       $s2, $a0, $v1
  .L8001F400:
    /* FC00 8001F400 0380143C */  lui        $s4, %hi(D_8003087C)
    /* FC04 8001F404 7C08948E */  lw         $s4, %lo(D_8003087C)($s4)
    /* FC08 8001F408 01000224 */  addiu      $v0, $zero, 0x1
    /* FC0C 8001F40C 04008216 */  bne        $s4, $v0, .L8001F420
    /* FC10 8001F410 00000000 */   nop
    /* FC14 8001F414 0380013C */  lui        $at, %hi(D_8003087C)
    /* FC18 8001F418 7C0820AC */  sw         $zero, %lo(D_8003087C)($at)
    /* FC1C 8001F41C 01001524 */  addiu      $s5, $zero, 0x1
  .L8001F420:
    /* FC20 8001F420 0380023C */  lui        $v0, %hi(D_80030898)
    /* FC24 8001F424 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* FC28 8001F428 00000000 */  nop
    /* FC2C 8001F42C 07004010 */  beqz       $v0, .L8001F44C
    /* FC30 8001F430 01001324 */   addiu     $s3, $zero, 0x1
    /* FC34 8001F434 0380023C */  lui        $v0, %hi(D_80030898)
    /* FC38 8001F438 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* FC3C 8001F43C 00000000 */  nop
    /* FC40 8001F440 1000A2AF */  sw         $v0, 0x10($sp)
    /* FC44 8001F444 0380013C */  lui        $at, %hi(D_80030898)
    /* FC48 8001F448 980820AC */  sw         $zero, %lo(D_80030898)($at)
  .L8001F44C:
    /* FC4C 8001F44C 0104222E */  sltiu      $v0, $s1, 0x401
  .L8001F450:
    /* FC50 8001F450 03004010 */  beqz       $v0, .L8001F460
    /* FC54 8001F454 00041024 */   addiu     $s0, $zero, 0x400
    /* FC58 8001F458 21802002 */  addu       $s0, $s1, $zero
    /* FC5C 8001F45C 21980000 */  addu       $s3, $zero, $zero
  .L8001F460:
    /* FC60 8001F460 02000424 */  addiu      $a0, $zero, 0x2
    /* FC64 8001F464 FE77000C */  jal        _spu_t
    /* FC68 8001F468 21284002 */   addu      $a1, $s2, $zero
    /* FC6C 8001F46C FE77000C */  jal        _spu_t
    /* FC70 8001F470 01000424 */   addiu     $a0, $zero, 0x1
    /* FC74 8001F474 03000424 */  addiu      $a0, $zero, 0x3
    /* FC78 8001F478 0380053C */  lui        $a1, %hi(D_800308D0)
    /* FC7C 8001F47C D008A524 */  addiu      $a1, $a1, %lo(D_800308D0)
    /* FC80 8001F480 FE77000C */  jal        _spu_t
    /* FC84 8001F484 21300002 */   addu      $a2, $s0, $zero
    /* FC88 8001F488 0380043C */  lui        $a0, %hi(D_800307E8)
    /* FC8C 8001F48C E807848C */  lw         $a0, %lo(D_800307E8)($a0)
    /* FC90 8001F490 00FC3126 */  addiu      $s1, $s1, -0x400
    /* FC94 8001F494 3D9A000C */  jal        WaitEvent
    /* FC98 8001F498 00045226 */   addiu     $s2, $s2, 0x400
    /* FC9C 8001F49C ECFF6016 */  bnez       $s3, .L8001F450
    /* FCA0 8001F4A0 0104222E */   sltiu     $v0, $s1, 0x401
    /* FCA4 8001F4A4 0300A012 */  beqz       $s5, .L8001F4B4
    /* FCA8 8001F4A8 00000000 */   nop
    /* FCAC 8001F4AC 0380013C */  lui        $at, %hi(D_8003087C)
    /* FCB0 8001F4B0 7C0834AC */  sw         $s4, %lo(D_8003087C)($at)
  .L8001F4B4:
    /* FCB4 8001F4B4 1000A28F */  lw         $v0, 0x10($sp)
    /* FCB8 8001F4B8 00000000 */  nop
    /* FCBC 8001F4BC 05004010 */  beqz       $v0, .L8001F4D4
    /* FCC0 8001F4C0 21100000 */   addu      $v0, $zero, $zero
    /* FCC4 8001F4C4 1000A28F */  lw         $v0, 0x10($sp)
    /* FCC8 8001F4C8 0380013C */  lui        $at, %hi(D_80030898)
    /* FCCC 8001F4CC 980822AC */  sw         $v0, %lo(D_80030898)($at)
    /* FCD0 8001F4D0 21100000 */  addu       $v0, $zero, $zero
  .L8001F4D4:
    /* FCD4 8001F4D4 3000BF8F */  lw         $ra, 0x30($sp)
    /* FCD8 8001F4D8 2C00B58F */  lw         $s5, 0x2C($sp)
    /* FCDC 8001F4DC 2800B48F */  lw         $s4, 0x28($sp)
    /* FCE0 8001F4E0 2400B38F */  lw         $s3, 0x24($sp)
    /* FCE4 8001F4E4 2000B28F */  lw         $s2, 0x20($sp)
    /* FCE8 8001F4E8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* FCEC 8001F4EC 1800B08F */  lw         $s0, 0x18($sp)
    /* FCF0 8001F4F0 0800E003 */  jr         $ra
    /* FCF4 8001F4F4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel SpuClearReverbWorkArea
    /* FCF8 8001F4F8 00000000 */  nop
    /* FCFC 8001F4FC 00000000 */  nop
    /* FD00 8001F500 00000000 */  nop
