nonmatching PadEnableCom, 0x118

glabel PadEnableCom
    /* 1C4A4 8002BCA4 0380033C */  lui        $v1, %hi(D_800335F0)
    /* 1C4A8 8002BCA8 F035638C */  lw         $v1, %lo(D_800335F0)($v1)
    /* 1C4AC 8002BCAC 0380023C */  lui        $v0, %hi(D_800335EC)
    /* 1C4B0 8002BCB0 EC35428C */  lw         $v0, %lo(D_800335EC)($v0)
    /* 1C4B4 8002BCB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C4B8 8002BCB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C4BC 8002BCBC 21808000 */  addu       $s0, $a0, $zero
    /* 1C4C0 8002BCC0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C4C4 8002BCC4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1C4C8 8002BCC8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C4CC 8002BCCC 40180300 */  sll        $v1, $v1, 1
    /* 1C4D0 8002BCD0 0100422C */  sltiu      $v0, $v0, 0x1
    /* 1C4D4 8002BCD4 25886200 */  or         $s1, $v1, $v0
    /* 1C4D8 8002BCD8 31003012 */  beq        $s1, $s0, .L8002BDA0
    /* 1C4DC 8002BCDC 01000232 */   andi      $v0, $s0, 0x1
    /* 1C4E0 8002BCE0 0380013C */  lui        $at, %hi(D_800335D4)
    /* 1C4E4 8002BCE4 D43520AC */  sw         $zero, %lo(D_800335D4)($at)
    /* 1C4E8 8002BCE8 12004010 */  beqz       $v0, .L8002BD34
    /* 1C4EC 8002BCEC 01000224 */   addiu     $v0, $zero, 0x1
    /* 1C4F0 8002BCF0 0480123C */  lui        $s2, %hi(D_8003FC10)
    /* 1C4F4 8002BCF4 10FC5226 */  addiu      $s2, $s2, %lo(D_8003FC10)
    /* 1C4F8 8002BCF8 0000428E */  lw         $v0, 0x0($s2)
    /* 1C4FC 8002BCFC 0380013C */  lui        $at, %hi(D_800335EC)
    /* 1C500 8002BD00 EC3520AC */  sw         $zero, %lo(D_800335EC)($at)
    /* 1C504 8002BD04 96004228 */  slti       $v0, $v0, 0x96
    /* 1C508 8002BD08 08004014 */  bnez       $v0, .L8002BD2C
    /* 1C50C 8002BD0C 00000000 */   nop
    /* 1C510 8002BD10 0380043C */  lui        $a0, %hi(D_800335D0)
    /* 1C514 8002BD14 D035848C */  lw         $a0, %lo(D_800335D0)($a0)
    /* 1C518 8002BD18 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1C51C 8002BD1C A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1C520 8002BD20 00000000 */  nop
    /* 1C524 8002BD24 09F84000 */  jalr       $v0
    /* 1C528 8002BD28 00000000 */   nop
  .L8002BD2C:
    /* 1C52C 8002BD2C 4FAF0008 */  j          .L8002BD3C
    /* 1C530 8002BD30 000040AE */   sw        $zero, 0x0($s2)
  .L8002BD34:
    /* 1C534 8002BD34 0380013C */  lui        $at, %hi(D_800335EC)
    /* 1C538 8002BD38 EC3522AC */  sw         $v0, %lo(D_800335EC)($at)
  .L8002BD3C:
    /* 1C53C 8002BD3C 02000232 */  andi       $v0, $s0, 0x2
    /* 1C540 8002BD40 12004010 */  beqz       $v0, .L8002BD8C
    /* 1C544 8002BD44 01000324 */   addiu     $v1, $zero, 0x1
    /* 1C548 8002BD48 0480103C */  lui        $s0, %hi(D_8003FC14)
    /* 1C54C 8002BD4C 14FC1026 */  addiu      $s0, $s0, %lo(D_8003FC14)
    /* 1C550 8002BD50 0000028E */  lw         $v0, 0x0($s0)
    /* 1C554 8002BD54 0380013C */  lui        $at, %hi(D_800335F0)
    /* 1C558 8002BD58 F03523AC */  sw         $v1, %lo(D_800335F0)($at)
    /* 1C55C 8002BD5C 96004228 */  slti       $v0, $v0, 0x96
    /* 1C560 8002BD60 08004014 */  bnez       $v0, .L8002BD84
    /* 1C564 8002BD64 00000000 */   nop
    /* 1C568 8002BD68 0380043C */  lui        $a0, %hi(D_800335D0)
    /* 1C56C 8002BD6C D035848C */  lw         $a0, %lo(D_800335D0)($a0)
    /* 1C570 8002BD70 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1C574 8002BD74 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1C578 8002BD78 00000000 */  nop
    /* 1C57C 8002BD7C 09F84000 */  jalr       $v0
    /* 1C580 8002BD80 F0008424 */   addiu     $a0, $a0, 0xF0
  .L8002BD84:
    /* 1C584 8002BD84 65AF0008 */  j          .L8002BD94
    /* 1C588 8002BD88 000000AE */   sw        $zero, 0x0($s0)
  .L8002BD8C:
    /* 1C58C 8002BD8C 0380013C */  lui        $at, %hi(D_800335F0)
    /* 1C590 8002BD90 F03520AC */  sw         $zero, %lo(D_800335F0)($at)
  .L8002BD94:
    /* 1C594 8002BD94 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C598 8002BD98 0380013C */  lui        $at, %hi(D_800335D4)
    /* 1C59C 8002BD9C D43522AC */  sw         $v0, %lo(D_800335D4)($at)
  .L8002BDA0:
    /* 1C5A0 8002BDA0 21102002 */  addu       $v0, $s1, $zero
    /* 1C5A4 8002BDA4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C5A8 8002BDA8 1800B28F */  lw         $s2, 0x18($sp)
    /* 1C5AC 8002BDAC 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C5B0 8002BDB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C5B4 8002BDB4 0800E003 */  jr         $ra
    /* 1C5B8 8002BDB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadEnableCom
