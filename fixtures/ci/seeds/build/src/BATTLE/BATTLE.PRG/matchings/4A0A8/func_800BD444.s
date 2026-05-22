nonmatching func_800BD444, 0x138

glabel func_800BD444
    /* 54C44 800BD444 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 54C48 800BD448 1400B1AF */  sw         $s1, 0x14($sp)
    /* 54C4C 800BD44C 21888000 */  addu       $s1, $a0, $zero
    /* 54C50 800BD450 1800BFAF */  sw         $ra, 0x18($sp)
    /* 54C54 800BD454 1000B0AF */  sw         $s0, 0x10($sp)
    /* 54C58 800BD458 00002392 */  lbu        $v1, 0x0($s1)
    /* 54C5C 800BD45C E2000224 */  addiu      $v0, $zero, 0xE2
    /* 54C60 800BD460 05006210 */  beq        $v1, $v0, .L800BD478
    /* 54C64 800BD464 E3000224 */   addiu     $v0, $zero, 0xE3
    /* 54C68 800BD468 07006210 */  beq        $v1, $v0, .L800BD488
    /* 54C6C 800BD46C 0F80023C */   lui       $v0, %hi(D_800F4BA4)
    /* 54C70 800BD470 25F50208 */  j          .L800BD494
    /* 54C74 800BD474 00000000 */   nop
  .L800BD478:
    /* 54C78 800BD478 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 54C7C 800BD47C A44B428C */  lw         $v0, %lo(D_800F4BA4)($v0)
    /* 54C80 800BD480 25F50208 */  j          .L800BD494
    /* 54C84 800BD484 68015024 */   addiu     $s0, $v0, 0x168
  .L800BD488:
    /* 54C88 800BD488 A44B428C */  lw         $v0, %lo(D_800F4BA4)($v0)
    /* 54C8C 800BD48C 00000000 */  nop
    /* 54C90 800BD490 74015024 */  addiu      $s0, $v0, 0x174
  .L800BD494:
    /* 54C94 800BD494 04002292 */  lbu        $v0, 0x4($s1)
    /* 54C98 800BD498 00000000 */  nop
    /* 54C9C 800BD49C 07004014 */  bnez       $v0, .L800BD4BC
    /* 54CA0 800BD4A0 0A0002A6 */   sh        $v0, 0xA($s0)
    /* 54CA4 800BD4A4 80FF020C */  jal        vs_battle_getShort
    /* 54CA8 800BD4A8 01002426 */   addiu     $a0, $s1, 0x1
    /* 54CAC 800BD4AC 020002A6 */  sh         $v0, 0x2($s0)
    /* 54CB0 800BD4B0 01000224 */  addiu      $v0, $zero, 0x1
    /* 54CB4 800BD4B4 59F50208 */  j          .L800BD564
    /* 54CB8 800BD4B8 000002A2 */   sb        $v0, 0x0($s0)
  .L800BD4BC:
    /* 54CBC 800BD4BC 02000296 */  lhu        $v0, 0x2($s0)
    /* 54CC0 800BD4C0 01002426 */  addiu      $a0, $s1, 0x1
    /* 54CC4 800BD4C4 80FF020C */  jal        vs_battle_getShort
    /* 54CC8 800BD4C8 040002A6 */   sh        $v0, 0x4($s0)
    /* 54CCC 800BD4CC 02000396 */  lhu        $v1, 0x2($s0)
    /* 54CD0 800BD4D0 00000000 */  nop
    /* 54CD4 800BD4D4 23184300 */  subu       $v1, $v0, $v1
    /* 54CD8 800BD4D8 00140300 */  sll        $v0, $v1, 16
    /* 54CDC 800BD4DC 03240200 */  sra        $a0, $v0, 16
    /* 54CE0 800BD4E0 00F88228 */  slti       $v0, $a0, -0x800
    /* 54CE4 800BD4E4 03004010 */  beqz       $v0, .L800BD4F4
    /* 54CE8 800BD4E8 060003A6 */   sh        $v1, 0x6($s0)
    /* 54CEC 800BD4EC 40F50208 */  j          .L800BD500
    /* 54CF0 800BD4F0 00106224 */   addiu     $v0, $v1, 0x1000
  .L800BD4F4:
    /* 54CF4 800BD4F4 01088228 */  slti       $v0, $a0, 0x801
    /* 54CF8 800BD4F8 02004014 */  bnez       $v0, .L800BD504
    /* 54CFC 800BD4FC 00F06224 */   addiu     $v0, $v1, -0x1000
  .L800BD500:
    /* 54D00 800BD500 060002A6 */  sh         $v0, 0x6($s0)
  .L800BD504:
    /* 54D04 800BD504 03002292 */  lbu        $v0, 0x3($s1)
    /* 54D08 800BD508 00000000 */  nop
    /* 54D0C 800BD50C 02190200 */  srl        $v1, $v0, 4
    /* 54D10 800BD510 05006010 */  beqz       $v1, .L800BD528
    /* 54D14 800BD514 02000224 */   addiu     $v0, $zero, 0x2
    /* 54D18 800BD518 09006210 */  beq        $v1, $v0, .L800BD540
    /* 54D1C 800BD51C 00000000 */   nop
    /* 54D20 800BD520 55F50208 */  j          .L800BD554
    /* 54D24 800BD524 00000000 */   nop
  .L800BD528:
    /* 54D28 800BD528 06000286 */  lh         $v0, 0x6($s0)
    /* 54D2C 800BD52C 06000396 */  lhu        $v1, 0x6($s0)
    /* 54D30 800BD530 08004018 */  blez       $v0, .L800BD554
    /* 54D34 800BD534 00F06224 */   addiu     $v0, $v1, -0x1000
    /* 54D38 800BD538 55F50208 */  j          .L800BD554
    /* 54D3C 800BD53C 060002A6 */   sh        $v0, 0x6($s0)
  .L800BD540:
    /* 54D40 800BD540 06000286 */  lh         $v0, 0x6($s0)
    /* 54D44 800BD544 06000396 */  lhu        $v1, 0x6($s0)
    /* 54D48 800BD548 02004104 */  bgez       $v0, .L800BD554
    /* 54D4C 800BD54C 00106224 */   addiu     $v0, $v1, 0x1000
    /* 54D50 800BD550 060002A6 */  sh         $v0, 0x6($s0)
  .L800BD554:
    /* 54D54 800BD554 03002292 */  lbu        $v0, 0x3($s1)
    /* 54D58 800BD558 080000A6 */  sh         $zero, 0x8($s0)
    /* 54D5C 800BD55C 0F004230 */  andi       $v0, $v0, 0xF
    /* 54D60 800BD560 010002A2 */  sb         $v0, 0x1($s0)
  .L800BD564:
    /* 54D64 800BD564 1800BF8F */  lw         $ra, 0x18($sp)
    /* 54D68 800BD568 1400B18F */  lw         $s1, 0x14($sp)
    /* 54D6C 800BD56C 1000B08F */  lw         $s0, 0x10($sp)
    /* 54D70 800BD570 21100000 */  addu       $v0, $zero, $zero
    /* 54D74 800BD574 0800E003 */  jr         $ra
    /* 54D78 800BD578 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BD444
