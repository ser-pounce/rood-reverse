nonmatching func_8002C438, 0xF0

glabel func_8002C438
    /* 1CC38 8002C438 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1CC3C 8002C43C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CC40 8002C440 21808000 */  addu       $s0, $a0, $zero
    /* 1CC44 8002C444 0380053C */  lui        $a1, %hi(D_800335E0)
    /* 1CC48 8002C448 E035A524 */  addiu      $a1, $a1, %lo(D_800335E0)
    /* 1CC4C 8002C44C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1CC50 8002C450 0000A38C */  lw         $v1, 0x0($a1)
    /* 1CC54 8002C454 00000000 */  nop
    /* 1CC58 8002C458 80100300 */  sll        $v0, $v1, 2
    /* 1CC5C 8002C45C 0380013C */  lui        $at, %hi(D_80033624)
    /* 1CC60 8002C460 21082200 */  addu       $at, $at, $v0
    /* 1CC64 8002C464 2436228C */  lw         $v0, %lo(D_80033624)($at)
    /* 1CC68 8002C468 01006324 */  addiu      $v1, $v1, 0x1
    /* 1CC6C 8002C46C 09F84000 */  jalr       $v0
    /* 1CC70 8002C470 0000A3AC */   sw        $v1, 0x0($a1)
    /* 1CC74 8002C474 21204000 */  addu       $a0, $v0, $zero
    /* 1CC78 8002C478 22008004 */  bltz       $a0, .L8002C504
    /* 1CC7C 8002C47C 00000000 */   nop
    /* 1CC80 8002C480 0380033C */  lui        $v1, %hi(D_800335E0)
    /* 1CC84 8002C484 E035638C */  lw         $v1, %lo(D_800335E0)($v1)
    /* 1CC88 8002C488 00000000 */  nop
    /* 1CC8C 8002C48C 17006010 */  beqz       $v1, .L8002C4EC
    /* 1CC90 8002C490 03000224 */   addiu     $v0, $zero, 0x3
    /* 1CC94 8002C494 07006214 */  bne        $v1, $v0, .L8002C4B4
    /* 1CC98 8002C498 00000000 */   nop
    /* 1CC9C 8002C49C 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1CCA0 8002C4A0 00000000 */  nop
    /* 1CCA4 8002C4A4 00004390 */  lbu        $v1, 0x0($v0)
    /* 1CCA8 8002C4A8 80000224 */  addiu      $v0, $zero, 0x80
    /* 1CCAC 8002C4AC 0C006210 */  beq        $v1, $v0, .L8002C4E0
    /* 1CCB0 8002C4B0 00000000 */   nop
  .L8002C4B4:
    /* 1CCB4 8002C4B4 FDB9000C */  jal        setRC2wait
    /* 1CCB8 8002C4B8 3C000424 */   addiu     $a0, $zero, 0x3C
    /* 1CCBC 8002C4BC 6CB2000C */  jal        _padClrIntSio0
    /* 1CCC0 8002C4C0 00000000 */   nop
    /* 1CCC4 8002C4C4 06004014 */  bnez       $v0, .L8002C4E0
    /* 1CCC8 8002C4C8 00000000 */   nop
    /* 1CCCC 8002C4CC 0380023C */  lui        $v0, %hi(D_8003359C)
    /* 1CCD0 8002C4D0 9C35428C */  lw         $v0, %lo(D_8003359C)($v0)
    /* 1CCD4 8002C4D4 00000000 */  nop
    /* 1CCD8 8002C4D8 09F84000 */  jalr       $v0
    /* 1CCDC 8002C4DC FDFF0424 */   addiu     $a0, $zero, -0x3
  .L8002C4E0:
    /* 1CCE0 8002C4E0 0380033C */  lui        $v1, %hi(D_800335E0)
    /* 1CCE4 8002C4E4 E035638C */  lw         $v1, %lo(D_800335E0)($v1)
    /* 1CCE8 8002C4E8 00000000 */  nop
  .L8002C4EC:
    /* 1CCEC 8002C4EC 05006228 */  slti       $v0, $v1, 0x5
    /* 1CCF0 8002C4F0 09004014 */  bnez       $v0, .L8002C518
    /* 1CCF4 8002C4F4 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 1CCF8 8002C4F8 0380013C */  lui        $at, %hi(D_800335E0)
    /* 1CCFC 8002C4FC 46B10008 */  j          .L8002C518
    /* 1CD00 8002C500 E03522AC */   sw        $v0, %lo(D_800335E0)($at)
  .L8002C504:
    /* 1CD04 8002C504 0380023C */  lui        $v0, %hi(D_8003359C)
    /* 1CD08 8002C508 9C35428C */  lw         $v0, %lo(D_8003359C)($v0)
    /* 1CD0C 8002C50C 00000000 */  nop
    /* 1CD10 8002C510 09F84000 */  jalr       $v0
    /* 1CD14 8002C514 00000000 */   nop
  .L8002C518:
    /* 1CD18 8002C518 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1CD1C 8002C51C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CD20 8002C520 0800E003 */  jr         $ra
    /* 1CD24 8002C524 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002C438
