nonmatching func_8006ABBC, 0x34

glabel func_8006ABBC
    /* 23BC 8006ABBC 0E80053C */  lui        $a1, %hi(D_800DBB88)
    /* 23C0 8006ABC0 88BBA324 */  addiu      $v1, $a1, %lo(D_800DBB88)
    /* 23C4 8006ABC4 08006284 */  lh         $v0, 0x8($v1)
    /* 23C8 8006ABC8 00000000 */  nop
    /* 23CC 8006ABCC 03004010 */  beqz       $v0, .L8006ABDC
    /* 23D0 8006ABD0 21106000 */   addu      $v0, $v1, $zero
    /* 23D4 8006ABD4 0800E003 */  jr         $ra
    /* 23D8 8006ABD8 21100000 */   addu      $v0, $zero, $zero
  .L8006ABDC:
    /* 23DC 8006ABDC 01000324 */  addiu      $v1, $zero, 0x1
    /* 23E0 8006ABE0 88BBA4AC */  sw         $a0, %lo(D_800DBB88)($a1)
    /* 23E4 8006ABE4 080043A4 */  sh         $v1, 0x8($v0)
    /* 23E8 8006ABE8 0800E003 */  jr         $ra
    /* 23EC 8006ABEC 0A0040A4 */   sh        $zero, 0xA($v0)
endlabel func_8006ABBC
