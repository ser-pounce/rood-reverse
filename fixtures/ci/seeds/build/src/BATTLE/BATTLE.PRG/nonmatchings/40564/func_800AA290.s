nonmatching func_800AA290, 0x1C4

glabel func_800AA290
    /* 41A90 800AA290 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 41A94 800AA294 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 41A98 800AA298 2188C000 */  addu       $s1, $a2, $zero
    /* 41A9C 800AA29C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41AA0 800AA2A0 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41AA4 800AA2A4 80200400 */  sll        $a0, $a0, 2
    /* 41AA8 800AA2A8 21208200 */  addu       $a0, $a0, $v0
    /* 41AAC 800AA2AC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 41AB0 800AA2B0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 41AB4 800AA2B4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 41AB8 800AA2B8 0000908C */  lw         $s0, 0x0($a0)
    /* 41ABC 800AA2BC 00000000 */  nop
    /* 41AC0 800AA2C0 5D000012 */  beqz       $s0, .L800AA438
    /* 41AC4 800AA2C4 2190E000 */   addu      $s2, $a3, $zero
    /* 41AC8 800AA2C8 0000A390 */  lbu        $v1, 0x0($a1)
    /* 41ACC 800AA2CC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 41AD0 800AA2D0 C0190300 */  sll        $v1, $v1, 7
    /* 41AD4 800AA2D4 40006324 */  addiu      $v1, $v1, 0x40
    /* 41AD8 800AA2D8 1000A3A7 */  sh         $v1, 0x10($sp)
    /* 41ADC 800AA2DC 0200A290 */  lbu        $v0, 0x2($a1)
    /* 41AE0 800AA2E0 04000724 */  addiu      $a3, $zero, 0x4
    /* 41AE4 800AA2E4 C0110200 */  sll        $v0, $v0, 7
    /* 41AE8 800AA2E8 40004224 */  addiu      $v0, $v0, 0x40
    /* 41AEC 800AA2EC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 41AF0 800AA2F0 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 41AF4 800AA2F4 21280000 */  addu       $a1, $zero, $zero
    /* 41AF8 800AA2F8 23186200 */  subu       $v1, $v1, $v0
    /* 41AFC 800AA2FC 340003A6 */  sh         $v1, 0x34($s0)
    /* 41B00 800AA300 1400A297 */  lhu        $v0, 0x14($sp)
    /* 41B04 800AA304 20000396 */  lhu        $v1, 0x20($s0)
    /* 41B08 800AA308 2130A000 */  addu       $a2, $a1, $zero
    /* 41B0C 800AA30C 23104300 */  subu       $v0, $v0, $v1
    /* 41B10 800AA310 BA9B020C */  jal        func_800A6EE8
    /* 41B14 800AA314 380002A6 */   sh        $v0, 0x38($s0)
    /* 41B18 800AA318 1E000396 */  lhu        $v1, 0x1E($s0)
    /* 41B1C 800AA31C 34000486 */  lh         $a0, 0x34($s0)
    /* 41B20 800AA320 23184300 */  subu       $v1, $v0, $v1
    /* 41B24 800AA324 07008014 */  bnez       $a0, .L800AA344
    /* 41B28 800AA328 360003A6 */   sh        $v1, 0x36($s0)
    /* 41B2C 800AA32C 38000286 */  lh         $v0, 0x38($s0)
    /* 41B30 800AA330 00000000 */  nop
    /* 41B34 800AA334 03004014 */  bnez       $v0, .L800AA344
    /* 41B38 800AA338 00140300 */   sll       $v0, $v1, 16
    /* 41B3C 800AA33C 3E004010 */  beqz       $v0, .L800AA438
    /* 41B40 800AA340 00000000 */   nop
  .L800AA344:
    /* 41B44 800AA344 0F002016 */  bnez       $s1, .L800AA384
    /* 41B48 800AA348 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 41B4C 800AA34C 1A0000A6 */  sh         $zero, 0x1A($s0)
  .L800AA350:
    /* 41B50 800AA350 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 41B54 800AA354 34000396 */  lhu        $v1, 0x34($s0)
    /* 41B58 800AA358 36000496 */  lhu        $a0, 0x36($s0)
    /* 41B5C 800AA35C 38000596 */  lhu        $a1, 0x38($s0)
    /* 41B60 800AA360 21104300 */  addu       $v0, $v0, $v1
    /* 41B64 800AA364 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 41B68 800AA368 1E000296 */  lhu        $v0, 0x1E($s0)
    /* 41B6C 800AA36C 20000396 */  lhu        $v1, 0x20($s0)
    /* 41B70 800AA370 21104400 */  addu       $v0, $v0, $a0
    /* 41B74 800AA374 21186500 */  addu       $v1, $v1, $a1
    /* 41B78 800AA378 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 41B7C 800AA37C 0EA90208 */  j          .L800AA438
    /* 41B80 800AA380 200003A6 */   sh        $v1, 0x20($s0)
  .L800AA384:
    /* 41B84 800AA384 2B002216 */  bne        $s1, $v0, .L800AA434
    /* 41B88 800AA388 00000000 */   nop
    /* 41B8C 800AA38C 34000386 */  lh         $v1, 0x34($s0)
    /* 41B90 800AA390 00000000 */  nop
    /* 41B94 800AA394 18006300 */  mult       $v1, $v1
    /* 41B98 800AA398 12180000 */  mflo       $v1
    /* 41B9C 800AA39C 03006104 */  bgez       $v1, .L800AA3AC
    /* 41BA0 800AA3A0 21106000 */   addu      $v0, $v1, $zero
    /* 41BA4 800AA3A4 23180300 */  negu       $v1, $v1
    /* 41BA8 800AA3A8 21106000 */  addu       $v0, $v1, $zero
  .L800AA3AC:
    /* 41BAC 800AA3AC 38000386 */  lh         $v1, 0x38($s0)
    /* 41BB0 800AA3B0 00000000 */  nop
    /* 41BB4 800AA3B4 18006300 */  mult       $v1, $v1
    /* 41BB8 800AA3B8 12180000 */  mflo       $v1
    /* 41BBC 800AA3BC 02006104 */  bgez       $v1, .L800AA3C8
    /* 41BC0 800AA3C0 00000000 */   nop
    /* 41BC4 800AA3C4 23180300 */  negu       $v1, $v1
  .L800AA3C8:
    /* 41BC8 800AA3C8 21104300 */  addu       $v0, $v0, $v1
    /* 41BCC 800AA3CC 36000386 */  lh         $v1, 0x36($s0)
    /* 41BD0 800AA3D0 00000000 */  nop
    /* 41BD4 800AA3D4 18006300 */  mult       $v1, $v1
    /* 41BD8 800AA3D8 12180000 */  mflo       $v1
    /* 41BDC 800AA3DC 02006104 */  bgez       $v1, .L800AA3E8
    /* 41BE0 800AA3E0 00000000 */   nop
    /* 41BE4 800AA3E4 23180300 */  negu       $v1, $v1
  .L800AA3E8:
    /* 41BE8 800AA3E8 E506010C */  jal        vs_gte_rsqrt
    /* 41BEC 800AA3EC 21204300 */   addu      $a0, $v0, $v1
    /* 41BF0 800AA3F0 18005200 */  mult       $v0, $s2
    /* 41BF4 800AA3F4 12100000 */  mflo       $v0
    /* 41BF8 800AA3F8 02004104 */  bgez       $v0, .L800AA404
    /* 41BFC 800AA3FC 21184000 */   addu      $v1, $v0, $zero
    /* 41C00 800AA400 7F004324 */  addiu      $v1, $v0, 0x7F
  .L800AA404:
    /* 41C04 800AA404 C3190300 */  sra        $v1, $v1, 7
    /* 41C08 800AA408 7F004230 */  andi       $v0, $v0, 0x7F
    /* 41C0C 800AA40C 03004010 */  beqz       $v0, .L800AA41C
    /* 41C10 800AA410 1A0003A6 */   sh        $v1, 0x1A($s0)
    /* 41C14 800AA414 01006224 */  addiu      $v0, $v1, 0x1
    /* 41C18 800AA418 1A0002A6 */  sh         $v0, 0x1A($s0)
  .L800AA41C:
    /* 41C1C 800AA41C 1A000296 */  lhu        $v0, 0x1A($s0)
    /* 41C20 800AA420 00000000 */  nop
    /* 41C24 800AA424 CAFF4010 */  beqz       $v0, .L800AA350
    /* 41C28 800AA428 00000000 */   nop
    /* 41C2C 800AA42C 0EA90208 */  j          .L800AA438
    /* 41C30 800AA430 00000000 */   nop
  .L800AA434:
    /* 41C34 800AA434 1A0011A6 */  sh         $s1, 0x1A($s0)
  .L800AA438:
    /* 41C38 800AA438 2400BF8F */  lw         $ra, 0x24($sp)
    /* 41C3C 800AA43C 2000B28F */  lw         $s2, 0x20($sp)
    /* 41C40 800AA440 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 41C44 800AA444 1800B08F */  lw         $s0, 0x18($sp)
    /* 41C48 800AA448 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 41C4C 800AA44C 0800E003 */  jr         $ra
    /* 41C50 800AA450 00000000 */   nop
endlabel func_800AA290
