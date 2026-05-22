nonmatching DsStartReadySystem, 0x84

glabel DsStartReadySystem
    /* 16A64 80026264 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 16A68 80026268 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16A6C 8002626C 0380103C */  lui        $s0, %hi(D_80032824)
    /* 16A70 80026270 24281026 */  addiu      $s0, $s0, %lo(D_80032824)
    /* 16A74 80026274 1800BFAF */  sw         $ra, 0x18($sp)
    /* 16A78 80026278 1400B1AF */  sw         $s1, 0x14($sp)
    /* 16A7C 8002627C 0000028E */  lw         $v0, 0x0($s0)
    /* 16A80 80026280 01001124 */  addiu      $s1, $zero, 0x1
    /* 16A84 80026284 12005110 */  beq        $v0, $s1, .L800262D0
    /* 16A88 80026288 21188000 */   addu      $v1, $a0, $zero
    /* 16A8C 8002628C 0280043C */  lui        $a0, %hi(func_80026360)
    /* 16A90 80026290 60638424 */  addiu      $a0, $a0, %lo(func_80026360)
    /* 16A94 80026294 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 16A98 80026298 E0FF02AE */  sw         $v0, -0x20($s0)
    /* 16A9C 8002629C E4FF00AE */  sw         $zero, -0x1C($s0)
    /* 16AA0 800262A0 ECFF00AE */  sw         $zero, -0x14($s0)
    /* 16AA4 800262A4 E8FF03AE */  sw         $v1, -0x18($s0)
    /* 16AA8 800262A8 069A000C */  jal        DsReadyCallback
    /* 16AAC 800262AC F0FF05AE */   sw        $a1, -0x10($s0)
    /* 16AB0 800262B0 0280043C */  lui        $a0, %hi(func_8002663C)
    /* 16AB4 800262B4 3C668424 */  addiu      $a0, $a0, %lo(func_8002663C)
    /* 16AB8 800262B8 0B9A000C */  jal        DsStartCallback
    /* 16ABC 800262BC F4FF02AE */   sw        $v0, -0xC($s0)
    /* 16AC0 800262C0 F8FF02AE */  sw         $v0, -0x8($s0)
    /* 16AC4 800262C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 16AC8 800262C8 B5980008 */  j          .L800262D4
    /* 16ACC 800262CC 000011AE */   sw        $s1, 0x0($s0)
  .L800262D0:
    /* 16AD0 800262D0 21100000 */  addu       $v0, $zero, $zero
  .L800262D4:
    /* 16AD4 800262D4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 16AD8 800262D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 16ADC 800262DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 16AE0 800262E0 0800E003 */  jr         $ra
    /* 16AE4 800262E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DsStartReadySystem
