nonmatching func_800AC440, 0xC0

glabel func_800AC440
    /* 43C40 800AC440 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 43C44 800AC444 2400B3AF */  sw         $s3, 0x24($sp)
    /* 43C48 800AC448 2198A000 */  addu       $s3, $a1, $zero
    /* 43C4C 800AC44C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 43C50 800AC450 21880000 */  addu       $s1, $zero, $zero
    /* 43C54 800AC454 90180724 */  addiu      $a3, $zero, 0x1890
    /* 43C58 800AC458 1800B0AF */  sw         $s0, 0x18($sp)
    /* 43C5C 800AC45C 21808000 */  addu       $s0, $a0, $zero
    /* 43C60 800AC460 00111300 */  sll        $v0, $s3, 4
    /* 43C64 800AC464 2800BFAF */  sw         $ra, 0x28($sp)
    /* 43C68 800AC468 2000B2AF */  sw         $s2, 0x20($sp)
    /* 43C6C 800AC46C 6800838C */  lw         $v1, 0x68($a0)
    /* 43C70 800AC470 40004224 */  addiu      $v0, $v0, 0x40
    /* 43C74 800AC474 21906200 */  addu       $s2, $v1, $v0
  .L800AC478:
    /* 43C78 800AC478 0800C014 */  bnez       $a2, .L800AC49C
    /* 43C7C 800AC47C 00000000 */   nop
    /* 43C80 800AC480 D0180292 */  lbu        $v0, 0x18D0($s0)
    /* 43C84 800AC484 00000000 */  nop
    /* 43C88 800AC488 11005314 */  bne        $v0, $s3, .L800AC4D0
    /* 43C8C 800AC48C 2000E724 */   addiu     $a3, $a3, 0x20
    /* 43C90 800AC490 D01800A2 */  sb         $zero, 0x18D0($s0)
    /* 43C94 800AC494 38B10208 */  j          .L800AC4E0
    /* 43C98 800AC498 0C0040A2 */   sb        $zero, 0xC($s2)
  .L800AC49C:
    /* 43C9C 800AC49C D0180292 */  lbu        $v0, 0x18D0($s0)
    /* 43CA0 800AC4A0 00000000 */  nop
    /* 43CA4 800AC4A4 09004014 */  bnez       $v0, .L800AC4CC
    /* 43CA8 800AC4A8 21286002 */   addu      $a1, $s3, $zero
    /* 43CAC 800AC4AC 21308700 */  addu       $a2, $a0, $a3
    /* 43CB0 800AC4B0 0F008490 */  lbu        $a0, 0xF($a0)
    /* 43CB4 800AC4B4 C885020C */  jal        func_800A1720
    /* 43CB8 800AC4B8 1000A727 */   addiu     $a3, $sp, 0x10
    /* 43CBC 800AC4BC 01002226 */  addiu      $v0, $s1, 0x1
    /* 43CC0 800AC4C0 0C0042A2 */  sb         $v0, 0xC($s2)
    /* 43CC4 800AC4C4 38B10208 */  j          .L800AC4E0
    /* 43CC8 800AC4C8 D01813A2 */   sb        $s3, 0x18D0($s0)
  .L800AC4CC:
    /* 43CCC 800AC4CC 2000E724 */  addiu      $a3, $a3, 0x20
  .L800AC4D0:
    /* 43CD0 800AC4D0 01003126 */  addiu      $s1, $s1, 0x1
    /* 43CD4 800AC4D4 0200222A */  slti       $v0, $s1, 0x2
    /* 43CD8 800AC4D8 E7FF4014 */  bnez       $v0, .L800AC478
    /* 43CDC 800AC4DC 01001026 */   addiu     $s0, $s0, 0x1
  .L800AC4E0:
    /* 43CE0 800AC4E0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 43CE4 800AC4E4 2400B38F */  lw         $s3, 0x24($sp)
    /* 43CE8 800AC4E8 2000B28F */  lw         $s2, 0x20($sp)
    /* 43CEC 800AC4EC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 43CF0 800AC4F0 1800B08F */  lw         $s0, 0x18($sp)
    /* 43CF4 800AC4F4 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 43CF8 800AC4F8 0800E003 */  jr         $ra
    /* 43CFC 800AC4FC 00000000 */   nop
endlabel func_800AC440
