nonmatching func_8006CAF4, 0x244

glabel func_8006CAF4
    /* 42F4 8006CAF4 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 42F8 8006CAF8 2800B2AF */  sw         $s2, 0x28($sp)
    /* 42FC 8006CAFC 21908000 */  addu       $s2, $a0, $zero
    /* 4300 8006CB00 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* 4304 8006CB04 21B8A000 */  addu       $s7, $a1, $zero
    /* 4308 8006CB08 2000B0AF */  sw         $s0, 0x20($sp)
    /* 430C 8006CB0C 2180C000 */  addu       $s0, $a2, $zero
    /* 4310 8006CB10 4000BFAF */  sw         $ra, 0x40($sp)
    /* 4314 8006CB14 3800B6AF */  sw         $s6, 0x38($sp)
    /* 4318 8006CB18 3400B5AF */  sw         $s5, 0x34($sp)
    /* 431C 8006CB1C 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4320 8006CB20 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4324 8006CB24 02000106 */  bgez       $s0, .L8006CB30
    /* 4328 8006CB28 2400B1AF */   sw        $s1, 0x24($sp)
    /* 432C 8006CB2C 21800000 */  addu       $s0, $zero, $zero
  .L8006CB30:
    /* 4330 8006CB30 4100022A */  slti       $v0, $s0, 0x41
    /* 4334 8006CB34 02004014 */  bnez       $v0, .L8006CB40
    /* 4338 8006CB38 00000000 */   nop
    /* 433C 8006CB3C 40001024 */  addiu      $s0, $zero, 0x40
  .L8006CB40:
    /* 4340 8006CB40 7200001A */  blez       $s0, .L8006CD0C
    /* 4344 8006CB44 C0181000 */   sll       $v1, $s0, 3
    /* 4348 8006CB48 0E80133C */  lui        $s3, %hi(D_800DC1FC)
    /* 434C 8006CB4C FCC1628E */  lw         $v0, %lo(D_800DC1FC)($s3)
    /* 4350 8006CB50 00000000 */  nop
    /* 4354 8006CB54 1E004010 */  beqz       $v0, .L8006CBD0
    /* 4358 8006CB58 21A04302 */   addu      $s4, $s2, $v1
    /* 435C 8006CB5C 2000022A */  slti       $v0, $s0, 0x20
    /* 4360 8006CB60 32004014 */  bnez       $v0, .L8006CC2C
    /* 4364 8006CB64 1800A427 */   addiu     $a0, $sp, 0x18
    /* 4368 8006CB68 0E80113C */  lui        $s1, %hi(D_800DC200)
    /* 436C 8006CB6C 00C2228E */  lw         $v0, %lo(D_800DC200)($s1)
    /* 4370 8006CB70 00000000 */  nop
    /* 4374 8006CB74 06004014 */  bnez       $v0, .L8006CB90
    /* 4378 8006CB78 0E80033C */   lui       $v1, %hi(D_800DC218)
    /* 437C 8006CB7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4380 8006CB80 18C262AC */  sw         $v0, %lo(D_800DC218)($v1)
    /* 4384 8006CB84 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 4388 8006CB88 6216010C */  jal        vs_main_playSfxDefault
    /* 438C 8006CB8C 72000524 */   addiu     $a1, $zero, 0x72
  .L8006CB90:
    /* 4390 8006CB90 00C2238E */  lw         $v1, %lo(D_800DC200)($s1)
    /* 4394 8006CB94 FCC1628E */  lw         $v0, %lo(D_800DC1FC)($s3)
    /* 4398 8006CB98 00000000 */  nop
    /* 439C 8006CB9C 0D006214 */  bne        $v1, $v0, .L8006CBD4
    /* 43A0 8006CBA0 2000022A */   slti      $v0, $s0, 0x20
    /* 43A4 8006CBA4 0E80033C */  lui        $v1, %hi(D_800DC218)
    /* 43A8 8006CBA8 18C2628C */  lw         $v0, %lo(D_800DC218)($v1)
    /* 43AC 8006CBAC 00000000 */  nop
    /* 43B0 8006CBB0 07004010 */  beqz       $v0, .L8006CBD0
    /* 43B4 8006CBB4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 43B8 8006CBB8 18C260AC */  sw         $zero, %lo(D_800DC218)($v1)
    /* 43BC 8006CBBC 5917010C */  jal        func_80045D64
    /* 43C0 8006CBC0 72000524 */   addiu     $a1, $zero, 0x72
    /* 43C4 8006CBC4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 43C8 8006CBC8 6216010C */  jal        vs_main_playSfxDefault
    /* 43CC 8006CBCC 73000524 */   addiu     $a1, $zero, 0x73
  .L8006CBD0:
    /* 43D0 8006CBD0 2000022A */  slti       $v0, $s0, 0x20
  .L8006CBD4:
    /* 43D4 8006CBD4 15004014 */  bnez       $v0, .L8006CC2C
    /* 43D8 8006CBD8 1800A427 */   addiu     $a0, $sp, 0x18
    /* 43DC 8006CBDC 0E80023C */  lui        $v0, %hi(D_800DC1FC)
    /* 43E0 8006CBE0 FCC1438C */  lw         $v1, %lo(D_800DC1FC)($v0)
    /* 43E4 8006CBE4 00000000 */  nop
    /* 43E8 8006CBE8 2000622C */  sltiu      $v0, $v1, 0x20
    /* 43EC 8006CBEC 08004014 */  bnez       $v0, .L8006CC10
    /* 43F0 8006CBF0 0E80053C */   lui       $a1, %hi(D_800DC200)
    /* 43F4 8006CBF4 E0FF0226 */  addiu      $v0, $s0, -0x20
    /* 43F8 8006CBF8 18006200 */  mult       $v1, $v0
    /* 43FC 8006CBFC 0E80033C */  lui        $v1, %hi(D_800DC200)
    /* 4400 8006CC00 12400000 */  mflo       $t0
    /* 4404 8006CC04 42110800 */  srl        $v0, $t0, 5
    /* 4408 8006CC08 0BB30108 */  j          .L8006CC2C
    /* 440C 8006CC0C 00C262AC */   sw        $v0, %lo(D_800DC200)($v1)
  .L8006CC10:
    /* 4410 8006CC10 00C2A48C */  lw         $a0, %lo(D_800DC200)($a1)
    /* 4414 8006CC14 00000000 */  nop
    /* 4418 8006CC18 2B108300 */  sltu       $v0, $a0, $v1
    /* 441C 8006CC1C 02004010 */  beqz       $v0, .L8006CC28
    /* 4420 8006CC20 01008224 */   addiu     $v0, $a0, 0x1
    /* 4424 8006CC24 00C2A2AC */  sw         $v0, %lo(D_800DC200)($a1)
  .L8006CC28:
    /* 4428 8006CC28 1800A427 */  addiu      $a0, $sp, 0x18
  .L8006CC2C:
    /* 442C 8006CC2C 0780053C */  lui        $a1, %hi(D_800688AC)
    /* 4430 8006CC30 AC88A524 */  addiu      $a1, $a1, %lo(D_800688AC)
    /* 4434 8006CC34 21980000 */  addu       $s3, $zero, $zero
    /* 4438 8006CC38 21B08000 */  addu       $s6, $a0, $zero
    /* 443C 8006CC3C 0E80023C */  lui        $v0, %hi(D_800DC200)
    /* 4440 8006CC40 00C2468C */  lw         $a2, %lo(D_800DC200)($v0)
    /* 4444 8006CC44 0E80023C */  lui        $v0, %hi(D_800DBAA0)
    /* 4448 8006CC48 BD9B000C */  jal        sprintf
    /* 444C 8006CC4C 21A84000 */   addu      $s5, $v0, $zero
    /* 4450 8006CC50 2128E002 */  addu       $a1, $s7, $zero
    /* 4454 8006CC54 15000624 */  addiu      $a2, $zero, 0x15
    /* 4458 8006CC58 A0BAB126 */  addiu      $s1, $s5, %lo(D_800DBAA0)
    /* 445C 8006CC5C 21382002 */  addu       $a3, $s1, $zero
    /* 4460 8006CC60 0E80103C */  lui        $s0, %hi(D_800DB814)
    /* 4464 8006CC64 14B81026 */  addiu      $s0, $s0, %lo(D_800DB814)
    /* 4468 8006CC68 1000B4AF */  sw         $s4, 0x10($sp)
    /* 446C 8006CC6C AA000292 */  lbu        $v0, 0xAA($s0)
    /* 4470 8006CC70 D2000392 */  lbu        $v1, 0xD2($s0)
    /* 4474 8006CC74 9A000492 */  lbu        $a0, 0x9A($s0)
    /* 4478 8006CC78 21104300 */  addu       $v0, $v0, $v1
    /* 447C 8006CC7C 21104400 */  addu       $v0, $v0, $a0
    /* 4480 8006CC80 26004224 */  addiu      $v0, $v0, 0x26
    /* 4484 8006CC84 43100200 */  sra        $v0, $v0, 1
    /* 4488 8006CC88 23904202 */  subu       $s2, $s2, $v0
    /* 448C 8006CC8C 86B6010C */  jal        func_8006DA18
    /* 4490 8006CC90 21204002 */   addu      $a0, $s2, $zero
    /* 4494 8006CC94 0700E526 */  addiu      $a1, $s7, 0x7
    /* 4498 8006CC98 1A000624 */  addiu      $a2, $zero, 0x1A
    /* 449C 8006CC9C AA000292 */  lbu        $v0, 0xAA($s0)
    /* 44A0 8006CCA0 21382002 */  addu       $a3, $s1, $zero
    /* 44A4 8006CCA4 1000B4AF */  sw         $s4, 0x10($sp)
    /* 44A8 8006CCA8 21904202 */  addu       $s2, $s2, $v0
    /* 44AC 8006CCAC 86B6010C */  jal        func_8006DA18
    /* 44B0 8006CCB0 21204002 */   addu      $a0, $s2, $zero
    /* 44B4 8006CCB4 D2000392 */  lbu        $v1, 0xD2($s0)
    /* 44B8 8006CCB8 02004226 */  addiu      $v0, $s2, 0x2
    /* 44BC 8006CCBC 21904300 */  addu       $s2, $v0, $v1
  .L8006CCC0:
    /* 44C0 8006CCC0 21204002 */  addu       $a0, $s2, $zero
    /* 44C4 8006CCC4 0300E526 */  addiu      $a1, $s7, 0x3
    /* 44C8 8006CCC8 A0BAA726 */  addiu      $a3, $s5, %lo(D_800DBAA0)
    /* 44CC 8006CCCC 2110D302 */  addu       $v0, $s6, $s3
    /* 44D0 8006CCD0 00004690 */  lbu        $a2, 0x0($v0)
    /* 44D4 8006CCD4 01007326 */  addiu      $s3, $s3, 0x1
    /* 44D8 8006CCD8 1000B4AF */  sw         $s4, 0x10($sp)
    /* 44DC 8006CCDC 86B6010C */  jal        func_8006DA18
    /* 44E0 8006CCE0 D0FFC624 */   addiu     $a2, $a2, -0x30
    /* 44E4 8006CCE4 0300622A */  slti       $v0, $s3, 0x3
    /* 44E8 8006CCE8 F5FF4014 */  bnez       $v0, .L8006CCC0
    /* 44EC 8006CCEC 0C005226 */   addiu     $s2, $s2, 0xC
    /* 44F0 8006CCF0 1000B4AF */  sw         $s4, 0x10($sp)
    /* 44F4 8006CCF4 21204002 */  addu       $a0, $s2, $zero
    /* 44F8 8006CCF8 0800E526 */  addiu      $a1, $s7, 0x8
    /* 44FC 8006CCFC 13000624 */  addiu      $a2, $zero, 0x13
    /* 4500 8006CD00 0E80073C */  lui        $a3, %hi(D_800DBAA0)
    /* 4504 8006CD04 86B6010C */  jal        func_8006DA18
    /* 4508 8006CD08 A0BAE724 */   addiu     $a3, $a3, %lo(D_800DBAA0)
  .L8006CD0C:
    /* 450C 8006CD0C 4000BF8F */  lw         $ra, 0x40($sp)
    /* 4510 8006CD10 3C00B78F */  lw         $s7, 0x3C($sp)
    /* 4514 8006CD14 3800B68F */  lw         $s6, 0x38($sp)
    /* 4518 8006CD18 3400B58F */  lw         $s5, 0x34($sp)
    /* 451C 8006CD1C 3000B48F */  lw         $s4, 0x30($sp)
    /* 4520 8006CD20 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4524 8006CD24 2800B28F */  lw         $s2, 0x28($sp)
    /* 4528 8006CD28 2400B18F */  lw         $s1, 0x24($sp)
    /* 452C 8006CD2C 2000B08F */  lw         $s0, 0x20($sp)
    /* 4530 8006CD30 0800E003 */  jr         $ra
    /* 4534 8006CD34 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8006CAF4
