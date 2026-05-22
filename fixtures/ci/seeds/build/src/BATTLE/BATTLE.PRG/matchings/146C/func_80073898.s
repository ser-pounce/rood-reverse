nonmatching func_80073898, 0x4C

glabel func_80073898
    /* B098 80073898 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B09C 8007389C 1000BFAF */  sw         $ra, 0x10($sp)
    /* B0A0 800738A0 C4FA020C */  jal        func_800BEB10
    /* B0A4 800738A4 00000000 */   nop
    /* B0A8 800738A8 00140200 */  sll        $v0, $v0, 16
    /* B0AC 800738AC 07004010 */  beqz       $v0, .L800738CC
    /* B0B0 800738B0 0F80033C */   lui       $v1, %hi(D_800F196C)
    /* B0B4 800738B4 03000224 */  addiu      $v0, $zero, 0x3
    /* B0B8 800738B8 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* B0BC 800738BC 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* B0C0 800738C0 01000224 */  addiu      $v0, $zero, 0x1
    /* B0C4 800738C4 35CE0108 */  j          .L800738D4
    /* B0C8 800738C8 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
  .L800738CC:
    /* B0CC 800738CC 1CCE010C */  jal        func_80073870
    /* B0D0 800738D0 00000000 */   nop
  .L800738D4:
    /* B0D4 800738D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* B0D8 800738D8 00000000 */  nop
    /* B0DC 800738DC 0800E003 */  jr         $ra
    /* B0E0 800738E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073898
