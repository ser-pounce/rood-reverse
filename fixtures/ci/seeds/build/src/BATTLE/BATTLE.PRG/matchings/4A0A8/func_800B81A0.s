nonmatching func_800B81A0, 0x8C

glabel func_800B81A0
    /* 4F9A0 800B81A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4F9A4 800B81A4 21288000 */  addu       $a1, $a0, $zero
    /* 4F9A8 800B81A8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4F9AC 800B81AC 0300A290 */  lbu        $v0, 0x3($a1)
    /* 4F9B0 800B81B0 00000000 */  nop
    /* 4F9B4 800B81B4 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 4F9B8 800B81B8 0400A490 */  lbu        $a0, 0x4($a1)
    /* 4F9BC 800B81BC 00000000 */  nop
    /* 4F9C0 800B81C0 1100A4A3 */  sb         $a0, 0x11($sp)
    /* 4F9C4 800B81C4 0500A390 */  lbu        $v1, 0x5($a1)
    /* 4F9C8 800B81C8 25104400 */  or         $v0, $v0, $a0
    /* 4F9CC 800B81CC 1200A3A3 */  sb         $v1, 0x12($sp)
    /* 4F9D0 800B81D0 25186200 */  or         $v1, $v1, $v0
    /* 4F9D4 800B81D4 FF006330 */  andi       $v1, $v1, 0xFF
    /* 4F9D8 800B81D8 08006010 */  beqz       $v1, .L800B81FC
    /* 4F9DC 800B81DC 00000000 */   nop
    /* 4F9E0 800B81E0 80FF020C */  jal        vs_battle_getShort
    /* 4F9E4 800B81E4 0100A424 */   addiu     $a0, $a1, 0x1
    /* 4F9E8 800B81E8 94FF020C */  jal        func_800BFE50
    /* 4F9EC 800B81EC FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F9F0 800B81F0 21204000 */  addu       $a0, $v0, $zero
    /* 4F9F4 800B81F4 85E00208 */  j          .L800B8214
    /* 4F9F8 800B81F8 1000A527 */   addiu     $a1, $sp, 0x10
  .L800B81FC:
    /* 4F9FC 800B81FC 80FF020C */  jal        vs_battle_getShort
    /* 4FA00 800B8200 0100A424 */   addiu     $a0, $a1, 0x1
    /* 4FA04 800B8204 94FF020C */  jal        func_800BFE50
    /* 4FA08 800B8208 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FA0C 800B820C 21204000 */  addu       $a0, $v0, $zero
    /* 4FA10 800B8210 21280000 */  addu       $a1, $zero, $zero
  .L800B8214:
    /* 4FA14 800B8214 FF81020C */  jal        func_800A07FC
    /* 4FA18 800B8218 00000000 */   nop
    /* 4FA1C 800B821C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4FA20 800B8220 21100000 */  addu       $v0, $zero, $zero
    /* 4FA24 800B8224 0800E003 */  jr         $ra
    /* 4FA28 800B8228 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B81A0
