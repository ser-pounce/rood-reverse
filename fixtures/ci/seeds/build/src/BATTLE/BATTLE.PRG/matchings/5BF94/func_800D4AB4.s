nonmatching func_800D4AB4, 0x38

glabel func_800D4AB4
    /* 6C2B4 800D4AB4 0F80033C */  lui        $v1, %hi(D_800F522C)
    /* 6C2B8 800D4AB8 2C526290 */  lbu        $v0, %lo(D_800F522C)($v1)
    /* 6C2BC 800D4ABC 00000000 */  nop
    /* 6C2C0 800D4AC0 0400422C */  sltiu      $v0, $v0, 0x4
    /* 6C2C4 800D4AC4 07004010 */  beqz       $v0, .L800D4AE4
    /* 6C2C8 800D4AC8 0F80023C */   lui       $v0, %hi(D_800EC32C)
    /* 6C2CC 800D4ACC 2C526390 */  lbu        $v1, %lo(D_800F522C)($v1)
    /* 6C2D0 800D4AD0 2CC34224 */  addiu      $v0, $v0, %lo(D_800EC32C)
    /* 6C2D4 800D4AD4 21186200 */  addu       $v1, $v1, $v0
    /* 6C2D8 800D4AD8 00006290 */  lbu        $v0, 0x0($v1)
    /* 6C2DC 800D4ADC 00000000 */  nop
    /* 6C2E0 800D4AE0 130082A0 */  sb         $v0, 0x13($a0)
  .L800D4AE4:
    /* 6C2E4 800D4AE4 0800E003 */  jr         $ra
    /* 6C2E8 800D4AE8 01000224 */   addiu     $v0, $zero, 0x1
endlabel func_800D4AB4
