nonmatching MoveImage2, 0x144

glabel MoveImage2
    /* 1B774 8002AF74 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B778 8002AF78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B77C 8002AF7C 21808000 */  addu       $s0, $a0, $zero
    /* 1B780 8002AF80 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1B784 8002AF84 2190A000 */  addu       $s2, $a1, $zero
    /* 1B788 8002AF88 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B78C 8002AF8C 2188C000 */  addu       $s1, $a2, $zero
    /* 1B790 8002AF90 0180043C */  lui        $a0, %hi(D_800109A8)
    /* 1B794 8002AF94 A8098424 */  addiu      $a0, $a0, %lo(D_800109A8)
    /* 1B798 8002AF98 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1B79C 8002AF9C AEA1000C */  jal        func_800286B8
    /* 1B7A0 8002AFA0 21280002 */   addu      $a1, $s0, $zero
    /* 1B7A4 8002AFA4 B17D000C */  jal        VSync
    /* 1B7A8 8002AFA8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1B7AC 8002AFAC 0380033C */  lui        $v1, %hi(D_80033558)
    /* 1B7B0 8002AFB0 5835638C */  lw         $v1, %lo(D_80033558)($v1)
    /* 1B7B4 8002AFB4 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1B7B8 8002AFB8 0380013C */  lui        $at, %hi(D_80033580)
    /* 1B7BC 8002AFBC 803522AC */  sw         $v0, %lo(D_80033580)($at)
    /* 1B7C0 8002AFC0 0380013C */  lui        $at, %hi(D_80033584)
    /* 1B7C4 8002AFC4 843520AC */  sw         $zero, %lo(D_80033584)($at)
    /* 1B7C8 8002AFC8 0000628C */  lw         $v0, 0x0($v1)
    /* 1B7CC 8002AFCC FEAB0008 */  j          .L8002AFF8
    /* 1B7D0 8002AFD0 0001033C */   lui       $v1, (0x1000000 >> 16)
  .L8002AFD4:
    /* 1B7D4 8002AFD4 EEAA000C */  jal        func_8002ABB8
    /* 1B7D8 8002AFD8 00000000 */   nop
    /* 1B7DC 8002AFDC 30004014 */  bnez       $v0, .L8002B0A0
    /* 1B7E0 8002AFE0 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1B7E4 8002AFE4 0380023C */  lui        $v0, %hi(D_80033558)
    /* 1B7E8 8002AFE8 5835428C */  lw         $v0, %lo(D_80033558)($v0)
    /* 1B7EC 8002AFEC 00000000 */  nop
    /* 1B7F0 8002AFF0 0000428C */  lw         $v0, 0x0($v0)
    /* 1B7F4 8002AFF4 0001033C */  lui        $v1, (0x1000000 >> 16)
  .L8002AFF8:
    /* 1B7F8 8002AFF8 24104300 */  and        $v0, $v0, $v1
    /* 1B7FC 8002AFFC F5FF4014 */  bnez       $v0, .L8002AFD4
    /* 1B800 8002B000 00000000 */   nop
    /* 1B804 8002B004 0380023C */  lui        $v0, %hi(D_8003354C)
    /* 1B808 8002B008 4C35428C */  lw         $v0, %lo(D_8003354C)($v0)
    /* 1B80C 8002B00C 00000000 */  nop
    /* 1B810 8002B010 0000428C */  lw         $v0, 0x0($v0)
    /* 1B814 8002B014 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1B818 8002B018 24104300 */  and        $v0, $v0, $v1
    /* 1B81C 8002B01C EDFF4010 */  beqz       $v0, .L8002AFD4
    /* 1B820 8002B020 00000000 */   nop
    /* 1B824 8002B024 0380053C */  lui        $a1, %hi(_GPU_ResetCallback)
    /* 1B828 8002B028 B4B1A524 */  addiu      $a1, $a1, %lo(_GPU_ResetCallback)
    /* 1B82C 8002B02C 4D7E000C */  jal        DMACallback
    /* 1B830 8002B030 02000424 */   addiu     $a0, $zero, 0x2
    /* 1B834 8002B034 04000286 */  lh         $v0, 0x4($s0)
    /* 1B838 8002B038 00000000 */  nop
    /* 1B83C 8002B03C 18004010 */  beqz       $v0, .L8002B0A0
    /* 1B840 8002B040 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1B844 8002B044 06000286 */  lh         $v0, 0x6($s0)
    /* 1B848 8002B048 00000000 */  nop
    /* 1B84C 8002B04C 03004014 */  bnez       $v0, .L8002B05C
    /* 1B850 8002B050 00141100 */   sll       $v0, $s1, 16
    /* 1B854 8002B054 28AC0008 */  j          .L8002B0A0
    /* 1B858 8002B058 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8002B05C:
    /* 1B85C 8002B05C FFFF4332 */  andi       $v1, $s2, 0xFFFF
    /* 1B860 8002B060 25104300 */  or         $v0, $v0, $v1
    /* 1B864 8002B064 0000058E */  lw         $a1, 0x0($s0)
    /* 1B868 8002B068 0380033C */  lui        $v1, %hi(D_8003343C)
    /* 1B86C 8002B06C 3C34638C */  lw         $v1, %lo(D_8003343C)($v1)
    /* 1B870 8002B070 0380043C */  lui        $a0, %hi(D_800334E4)
    /* 1B874 8002B074 E4348424 */  addiu      $a0, $a0, %lo(D_800334E4)
    /* 1B878 8002B078 040082AC */  sw         $v0, 0x4($a0)
    /* 1B87C 8002B07C 000085AC */  sw         $a1, 0x0($a0)
    /* 1B880 8002B080 0400028E */  lw         $v0, 0x4($s0)
    /* 1B884 8002B084 00000000 */  nop
    /* 1B888 8002B088 080082AC */  sw         $v0, 0x8($a0)
    /* 1B88C 8002B08C 1800628C */  lw         $v0, 0x18($v1)
    /* 1B890 8002B090 00000000 */  nop
    /* 1B894 8002B094 09F84000 */  jalr       $v0
    /* 1B898 8002B098 F8FF8424 */   addiu     $a0, $a0, -0x8
    /* 1B89C 8002B09C 21100000 */  addu       $v0, $zero, $zero
  .L8002B0A0:
    /* 1B8A0 8002B0A0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1B8A4 8002B0A4 1800B28F */  lw         $s2, 0x18($sp)
    /* 1B8A8 8002B0A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B8AC 8002B0AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B8B0 8002B0B0 0800E003 */  jr         $ra
    /* 1B8B4 8002B0B4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel MoveImage2
