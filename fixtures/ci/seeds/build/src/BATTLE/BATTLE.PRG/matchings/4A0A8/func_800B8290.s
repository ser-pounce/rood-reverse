nonmatching func_800B8290, 0xD0

glabel func_800B8290
    /* 4FA90 800B8290 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4FA94 800B8294 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4FA98 800B8298 21808000 */  addu       $s0, $a0, $zero
    /* 4FA9C 800B829C 01000426 */  addiu      $a0, $s0, 0x1
    /* 4FAA0 800B82A0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4FAA4 800B82A4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 4FAA8 800B82A8 80FF020C */  jal        vs_battle_getShort
    /* 4FAAC 800B82AC 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 4FAB0 800B82B0 94FF020C */  jal        func_800BFE50
    /* 4FAB4 800B82B4 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FAB8 800B82B8 21904000 */  addu       $s2, $v0, $zero
    /* 4FABC 800B82BC 0A000392 */  lbu        $v1, 0xA($s0)
    /* 4FAC0 800B82C0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4FAC4 800B82C4 02006210 */  beq        $v1, $v0, .L800B82D0
    /* 4FAC8 800B82C8 FFFF1124 */   addiu     $s1, $zero, -0x1
    /* 4FACC 800B82CC 0A001192 */  lbu        $s1, 0xA($s0)
  .L800B82D0:
    /* 4FAD0 800B82D0 80FF020C */  jal        vs_battle_getShort
    /* 4FAD4 800B82D4 04000426 */   addiu     $a0, $s0, 0x4
    /* 4FAD8 800B82D8 06000426 */  addiu      $a0, $s0, 0x6
    /* 4FADC 800B82DC 80FF020C */  jal        vs_battle_getShort
    /* 4FAE0 800B82E0 1000A2A7 */   sh        $v0, 0x10($sp)
    /* 4FAE4 800B82E4 08000426 */  addiu      $a0, $s0, 0x8
    /* 4FAE8 800B82E8 80FF020C */  jal        vs_battle_getShort
    /* 4FAEC 800B82EC 1200A2A7 */   sh        $v0, 0x12($sp)
    /* 4FAF0 800B82F0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 4FAF4 800B82F4 03000292 */  lbu        $v0, 0x3($s0)
    /* 4FAF8 800B82F8 00000000 */  nop
    /* 4FAFC 800B82FC 07004010 */  beqz       $v0, .L800B831C
    /* 4FB00 800B8300 FFFF4432 */   andi      $a0, $s2, 0xFFFF
    /* 4FB04 800B8304 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4FB08 800B8308 00341100 */  sll        $a2, $s1, 16
    /* 4FB0C 800B830C D9A7020C */  jal        func_800A9F64
    /* 4FB10 800B8310 03340600 */   sra       $a2, $a2, 16
    /* 4FB14 800B8314 CCE00208 */  j          .L800B8330
    /* 4FB18 800B8318 0F80023C */   lui       $v0, %hi(D_800F4B70)
  .L800B831C:
    /* 4FB1C 800B831C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4FB20 800B8320 00341100 */  sll        $a2, $s1, 16
    /* 4FB24 800B8324 F4A7020C */  jal        func_800A9FD0
    /* 4FB28 800B8328 03340600 */   sra       $a2, $a2, 16
    /* 4FB2C 800B832C 0F80023C */  lui        $v0, %hi(D_800F4B70)
  .L800B8330:
    /* 4FB30 800B8330 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4FB34 800B8334 FFFF4332 */  andi       $v1, $s2, 0xFFFF
    /* 4FB38 800B8338 21186200 */  addu       $v1, $v1, $v0
    /* 4FB3C 800B833C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FB40 800B8340 000062A0 */  sb         $v0, 0x0($v1)
    /* 4FB44 800B8344 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4FB48 800B8348 2000B28F */  lw         $s2, 0x20($sp)
    /* 4FB4C 800B834C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4FB50 800B8350 1800B08F */  lw         $s0, 0x18($sp)
    /* 4FB54 800B8354 21100000 */  addu       $v0, $zero, $zero
    /* 4FB58 800B8358 0800E003 */  jr         $ra
    /* 4FB5C 800B835C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800B8290
