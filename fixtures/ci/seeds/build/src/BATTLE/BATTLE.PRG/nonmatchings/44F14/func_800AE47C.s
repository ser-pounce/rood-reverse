nonmatching func_800AE47C, 0x80

glabel func_800AE47C
    /* 45C7C 800AE47C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 45C80 800AE480 1800B0AF */  sw         $s0, 0x18($sp)
    /* 45C84 800AE484 21808000 */  addu       $s0, $a0, $zero
    /* 45C88 800AE488 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 45C8C 800AE48C B8050592 */  lbu        $a1, 0x5B8($s0)
    /* 45C90 800AE490 25B5020C */  jal        func_800AD494
    /* 45C94 800AE494 1000A627 */   addiu     $a2, $sp, 0x10
    /* 45C98 800AE498 1000A38F */  lw         $v1, 0x10($sp)
    /* 45C9C 800AE49C 0000478C */  lw         $a3, 0x0($v0)
    /* 45CA0 800AE4A0 04006294 */  lhu        $v0, 0x4($v1)
    /* 45CA4 800AE4A4 00000000 */  nop
    /* 45CA8 800AE4A8 2138E200 */  addu       $a3, $a3, $v0
    /* 45CAC 800AE4AC 0000E390 */  lbu        $v1, 0x0($a3)
    /* 45CB0 800AE4B0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 45CB4 800AE4B4 05006214 */  bne        $v1, $v0, .L800AE4CC
    /* 45CB8 800AE4B8 00000000 */   nop
    /* 45CBC 800AE4BC 0100E290 */  lbu        $v0, 0x1($a3)
    /* 45CC0 800AE4C0 0200E724 */  addiu      $a3, $a3, 0x2
    /* 45CC4 800AE4C4 34B90208 */  j          .L800AE4D0
    /* 45CC8 800AE4C8 FF004324 */   addiu     $v1, $v0, 0xFF
  .L800AE4CC:
    /* 45CCC 800AE4CC 0100E724 */  addiu      $a3, $a3, 0x1
  .L800AE4D0:
    /* 45CD0 800AE4D0 21200002 */  addu       $a0, $s0, $zero
    /* 45CD4 800AE4D4 04078524 */  addiu      $a1, $a0, 0x704
    /* 45CD8 800AE4D8 02000624 */  addiu      $a2, $zero, 0x2
    /* 45CDC 800AE4DC 460C83A4 */  sh         $v1, 0xC46($a0)
    /* 45CE0 800AE4E0 C5B5020C */  jal        func_800AD714
    /* 45CE4 800AE4E4 480C87AC */   sw        $a3, 0xC48($a0)
    /* 45CE8 800AE4E8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 45CEC 800AE4EC 1800B08F */  lw         $s0, 0x18($sp)
    /* 45CF0 800AE4F0 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 45CF4 800AE4F4 0800E003 */  jr         $ra
    /* 45CF8 800AE4F8 00000000 */   nop
endlabel func_800AE47C
