nonmatching func_8007BD8C, 0x4C

glabel func_8007BD8C
    /* 1358C 8007BD8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13590 8007BD90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13594 8007BD94 21808000 */  addu       $s0, $a0, $zero
    /* 13598 8007BD98 05000012 */  beqz       $s0, .L8007BDB0
    /* 1359C 8007BD9C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 135A0 8007BDA0 952D030C */  jal        func_800CB654
    /* 135A4 8007BDA4 01000424 */   addiu     $a0, $zero, 0x1
    /* 135A8 8007BDA8 6FEF0108 */  j          .L8007BDBC
    /* 135AC 8007BDAC 21200000 */   addu      $a0, $zero, $zero
  .L8007BDB0:
    /* 135B0 8007BDB0 952D030C */  jal        func_800CB654
    /* 135B4 8007BDB4 21200000 */   addu      $a0, $zero, $zero
    /* 135B8 8007BDB8 01000424 */  addiu      $a0, $zero, 0x1
  .L8007BDBC:
    /* 135BC 8007BDBC 322D020C */  jal        func_8008B4C8
    /* 135C0 8007BDC0 00000000 */   nop
    /* 135C4 8007BDC4 21100002 */  addu       $v0, $s0, $zero
    /* 135C8 8007BDC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 135CC 8007BDCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 135D0 8007BDD0 0800E003 */  jr         $ra
    /* 135D4 8007BDD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BD8C
