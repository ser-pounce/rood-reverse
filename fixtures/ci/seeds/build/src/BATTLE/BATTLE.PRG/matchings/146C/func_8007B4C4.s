nonmatching func_8007B4C4, 0x44

glabel func_8007B4C4
    /* 12CC4 8007B4C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12CC8 8007B4C8 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 12CCC 8007B4CC 02000224 */  addiu      $v0, $zero, 0x2
    /* 12CD0 8007B4D0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12CD4 8007B4D4 1CED010C */  jal        func_8007B470
    /* 12CD8 8007B4D8 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 12CDC 8007B4DC 0F80023C */  lui        $v0, %hi(D_800F1864)
    /* 12CE0 8007B4E0 6418428C */  lw         $v0, %lo(D_800F1864)($v0)
    /* 12CE4 8007B4E4 00000000 */  nop
    /* 12CE8 8007B4E8 03004010 */  beqz       $v0, .L8007B4F8
    /* 12CEC 8007B4EC 00000000 */   nop
    /* 12CF0 8007B4F0 7179020C */  jal        func_8009E5C4
    /* 12CF4 8007B4F4 21200000 */   addu      $a0, $zero, $zero
  .L8007B4F8:
    /* 12CF8 8007B4F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12CFC 8007B4FC 00000000 */  nop
    /* 12D00 8007B500 0800E003 */  jr         $ra
    /* 12D04 8007B504 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B4C4
