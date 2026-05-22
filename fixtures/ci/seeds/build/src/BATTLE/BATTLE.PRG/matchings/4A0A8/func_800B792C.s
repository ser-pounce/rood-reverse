nonmatching func_800B792C, 0x16C

glabel func_800B792C
    /* 4F12C 800B792C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4F130 800B7930 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4F134 800B7934 21808000 */  addu       $s0, $a0, $zero
    /* 4F138 800B7938 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F13C 800B793C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 4F140 800B7940 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4F144 800B7944 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4F148 800B7948 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4F14C 800B794C 80FF020C */  jal        vs_battle_getShort
    /* 4F150 800B7950 2400B1AF */   sw        $s1, 0x24($sp)
    /* 4F154 800B7954 94FF020C */  jal        func_800BFE50
    /* 4F158 800B7958 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F15C 800B795C 03000426 */  addiu      $a0, $s0, 0x3
    /* 4F160 800B7960 80FF020C */  jal        vs_battle_getShort
    /* 4F164 800B7964 21A04000 */   addu      $s4, $v0, $zero
    /* 4F168 800B7968 05000426 */  addiu      $a0, $s0, 0x5
    /* 4F16C 800B796C 00140200 */  sll        $v0, $v0, 16
    /* 4F170 800B7970 80FF020C */  jal        vs_battle_getShort
    /* 4F174 800B7974 438C0200 */   sra       $s1, $v0, 17
    /* 4F178 800B7978 07000426 */  addiu      $a0, $s0, 0x7
    /* 4F17C 800B797C 80FF020C */  jal        vs_battle_getShort
    /* 4F180 800B7980 21904000 */   addu      $s2, $v0, $zero
    /* 4F184 800B7984 03000392 */  lbu        $v1, 0x3($s0)
    /* 4F188 800B7988 00000000 */  nop
    /* 4F18C 800B798C 01006330 */  andi       $v1, $v1, 0x1
    /* 4F190 800B7990 0E006010 */  beqz       $v1, .L800B79CC
    /* 4F194 800B7994 21984000 */   addu      $s3, $v0, $zero
    /* 4F198 800B7998 FFFF8432 */  andi       $a0, $s4, 0xFFFF
    /* 4F19C 800B799C 4284020C */  jal        func_800A1108
    /* 4F1A0 800B79A0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F1A4 800B79A4 1400A297 */  lhu        $v0, 0x14($sp)
    /* 4F1A8 800B79A8 1800A397 */  lhu        $v1, 0x18($sp)
    /* 4F1AC 800B79AC 21105100 */  addu       $v0, $v0, $s1
    /* 4F1B0 800B79B0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 4F1B4 800B79B4 1600A297 */  lhu        $v0, 0x16($sp)
    /* 4F1B8 800B79B8 21187300 */  addu       $v1, $v1, $s3
    /* 4F1BC 800B79BC 1800A3A7 */  sh         $v1, 0x18($sp)
    /* 4F1C0 800B79C0 21105200 */  addu       $v0, $v0, $s2
    /* 4F1C4 800B79C4 76DE0208 */  j          .L800B79D8
    /* 4F1C8 800B79C8 1600A2A7 */   sh        $v0, 0x16($sp)
  .L800B79CC:
    /* 4F1CC 800B79CC 1400B1A7 */  sh         $s1, 0x14($sp)
    /* 4F1D0 800B79D0 1600B2A7 */  sh         $s2, 0x16($sp)
    /* 4F1D4 800B79D4 1800B3A7 */  sh         $s3, 0x18($sp)
  .L800B79D8:
    /* 4F1D8 800B79D8 09000392 */  lbu        $v1, 0x9($s0)
    /* 4F1DC 800B79DC FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4F1E0 800B79E0 04006210 */  beq        $v1, $v0, .L800B79F4
    /* 4F1E4 800B79E4 00000000 */   nop
    /* 4F1E8 800B79E8 09000292 */  lbu        $v0, 0x9($s0)
    /* 4F1EC 800B79EC 7EDE0208 */  j          .L800B79F8
    /* 4F1F0 800B79F0 00110200 */   sll       $v0, $v0, 4
  .L800B79F4:
    /* 4F1F4 800B79F4 00800224 */  addiu      $v0, $zero, -0x8000
  .L800B79F8:
    /* 4F1F8 800B79F8 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4F1FC 800B79FC 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4F200 800B7A00 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4F204 800B7A04 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F208 800B7A08 06006214 */  bne        $v1, $v0, .L800B7A24
    /* 4F20C 800B7A0C FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 4F210 800B7A10 FFFF8432 */  andi       $a0, $s4, 0xFFFF
    /* 4F214 800B7A14 1400A527 */  addiu      $a1, $sp, 0x14
    /* 4F218 800B7A18 21300000 */  addu       $a2, $zero, $zero
    /* 4F21C 800B7A1C 94DE0208 */  j          .L800B7A50
    /* 4F220 800B7A20 2138C000 */   addu      $a3, $a2, $zero
  .L800B7A24:
    /* 4F224 800B7A24 FFFF8432 */  andi       $a0, $s4, 0xFFFF
    /* 4F228 800B7A28 0A000292 */  lbu        $v0, 0xA($s0)
    /* 4F22C 800B7A2C FF000324 */  addiu      $v1, $zero, 0xFF
    /* 4F230 800B7A30 02004310 */  beq        $v0, $v1, .L800B7A3C
    /* 4F234 800B7A34 1400A527 */   addiu     $a1, $sp, 0x14
    /* 4F238 800B7A38 21304000 */  addu       $a2, $v0, $zero
  .L800B7A3C:
    /* 4F23C 800B7A3C 0B000292 */  lbu        $v0, 0xB($s0)
    /* 4F240 800B7A40 00000000 */  nop
    /* 4F244 800B7A44 02004310 */  beq        $v0, $v1, .L800B7A50
    /* 4F248 800B7A48 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 4F24C 800B7A4C 21384000 */  addu       $a3, $v0, $zero
  .L800B7A50:
    /* 4F250 800B7A50 62A6020C */  jal        func_800A9988
    /* 4F254 800B7A54 FFFF9032 */   andi      $s0, $s4, 0xFFFF
    /* 4F258 800B7A58 2377020C */  jal        func_8009DC8C
    /* 4F25C 800B7A5C 21200002 */   addu      $a0, $s0, $zero
    /* 4F260 800B7A60 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F264 800B7A64 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F268 800B7A68 21800202 */  addu       $s0, $s0, $v0
    /* 4F26C 800B7A6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F270 800B7A70 000002A2 */  sb         $v0, 0x0($s0)
    /* 4F274 800B7A74 3400BF8F */  lw         $ra, 0x34($sp)
    /* 4F278 800B7A78 3000B48F */  lw         $s4, 0x30($sp)
    /* 4F27C 800B7A7C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4F280 800B7A80 2800B28F */  lw         $s2, 0x28($sp)
    /* 4F284 800B7A84 2400B18F */  lw         $s1, 0x24($sp)
    /* 4F288 800B7A88 2000B08F */  lw         $s0, 0x20($sp)
    /* 4F28C 800B7A8C 21100000 */  addu       $v0, $zero, $zero
    /* 4F290 800B7A90 0800E003 */  jr         $ra
    /* 4F294 800B7A94 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800B792C
