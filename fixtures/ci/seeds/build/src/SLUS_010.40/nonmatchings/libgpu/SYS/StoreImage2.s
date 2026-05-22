nonmatching StoreImage2, 0xEC

glabel StoreImage2
    /* 1B688 8002AE88 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B68C 8002AE8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B690 8002AE90 21808000 */  addu       $s0, $a0, $zero
    /* 1B694 8002AE94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B698 8002AE98 2188A000 */  addu       $s1, $a1, $zero
    /* 1B69C 8002AE9C 0180043C */  lui        $a0, %hi(D_8001099C)
    /* 1B6A0 8002AEA0 9C098424 */  addiu      $a0, $a0, %lo(D_8001099C)
    /* 1B6A4 8002AEA4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1B6A8 8002AEA8 AEA1000C */  jal        func_800286B8
    /* 1B6AC 8002AEAC 21280002 */   addu      $a1, $s0, $zero
    /* 1B6B0 8002AEB0 B17D000C */  jal        VSync
    /* 1B6B4 8002AEB4 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1B6B8 8002AEB8 0380033C */  lui        $v1, %hi(D_80033558)
    /* 1B6BC 8002AEBC 5835638C */  lw         $v1, %lo(D_80033558)($v1)
    /* 1B6C0 8002AEC0 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1B6C4 8002AEC4 0380013C */  lui        $at, %hi(D_80033580)
    /* 1B6C8 8002AEC8 803522AC */  sw         $v0, %lo(D_80033580)($at)
    /* 1B6CC 8002AECC 0380013C */  lui        $at, %hi(D_80033584)
    /* 1B6D0 8002AED0 843520AC */  sw         $zero, %lo(D_80033584)($at)
    /* 1B6D4 8002AED4 0000628C */  lw         $v0, 0x0($v1)
    /* 1B6D8 8002AED8 C1AB0008 */  j          .L8002AF04
    /* 1B6DC 8002AEDC 0001033C */   lui       $v1, (0x1000000 >> 16)
  .L8002AEE0:
    /* 1B6E0 8002AEE0 EEAA000C */  jal        func_8002ABB8
    /* 1B6E4 8002AEE4 00000000 */   nop
    /* 1B6E8 8002AEE8 1D004014 */  bnez       $v0, .L8002AF60
    /* 1B6EC 8002AEEC FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 1B6F0 8002AEF0 0380023C */  lui        $v0, %hi(D_80033558)
    /* 1B6F4 8002AEF4 5835428C */  lw         $v0, %lo(D_80033558)($v0)
    /* 1B6F8 8002AEF8 00000000 */  nop
    /* 1B6FC 8002AEFC 0000428C */  lw         $v0, 0x0($v0)
    /* 1B700 8002AF00 0001033C */  lui        $v1, (0x1000000 >> 16)
  .L8002AF04:
    /* 1B704 8002AF04 24104300 */  and        $v0, $v0, $v1
    /* 1B708 8002AF08 F5FF4014 */  bnez       $v0, .L8002AEE0
    /* 1B70C 8002AF0C 00000000 */   nop
    /* 1B710 8002AF10 0380023C */  lui        $v0, %hi(D_8003354C)
    /* 1B714 8002AF14 4C35428C */  lw         $v0, %lo(D_8003354C)($v0)
    /* 1B718 8002AF18 00000000 */  nop
    /* 1B71C 8002AF1C 0000428C */  lw         $v0, 0x0($v0)
    /* 1B720 8002AF20 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1B724 8002AF24 24104300 */  and        $v0, $v0, $v1
    /* 1B728 8002AF28 EDFF4010 */  beqz       $v0, .L8002AEE0
    /* 1B72C 8002AF2C 00000000 */   nop
    /* 1B730 8002AF30 0380053C */  lui        $a1, %hi(_GPU_ResetCallback)
    /* 1B734 8002AF34 B4B1A524 */  addiu      $a1, $a1, %lo(_GPU_ResetCallback)
    /* 1B738 8002AF38 4D7E000C */  jal        DMACallback
    /* 1B73C 8002AF3C 02000424 */   addiu     $a0, $zero, 0x2
    /* 1B740 8002AF40 0380023C */  lui        $v0, %hi(D_8003343C)
    /* 1B744 8002AF44 3C34428C */  lw         $v0, %lo(D_8003343C)($v0)
    /* 1B748 8002AF48 21200002 */  addu       $a0, $s0, $zero
    /* 1B74C 8002AF4C 1C00428C */  lw         $v0, 0x1C($v0)
    /* 1B750 8002AF50 00000000 */  nop
    /* 1B754 8002AF54 09F84000 */  jalr       $v0
    /* 1B758 8002AF58 21282002 */   addu      $a1, $s1, $zero
    /* 1B75C 8002AF5C 21100000 */  addu       $v0, $zero, $zero
  .L8002AF60:
    /* 1B760 8002AF60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1B764 8002AF64 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B768 8002AF68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B76C 8002AF6C 0800E003 */  jr         $ra
    /* 1B770 8002AF70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel StoreImage2
