nonmatching vs_battle_script_setStringContextInt, 0x140

glabel vs_battle_script_setStringContextInt
    /* 4EA18 800B7218 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4EA1C 800B721C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4EA20 800B7220 21888000 */  addu       $s1, $a0, $zero
    /* 4EA24 800B7224 02002426 */  addiu      $a0, $s1, 0x2
    /* 4EA28 800B7228 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4EA2C 800B722C 80FF020C */  jal        vs_battle_getShort
    /* 4EA30 800B7230 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4EA34 800B7234 FF035030 */  andi       $s0, $v0, 0x3FF
    /* 4EA38 800B7238 03002392 */  lbu        $v1, 0x3($s1)
    /* 4EA3C 800B723C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4EA40 800B7240 82190300 */  srl        $v1, $v1, 6
    /* 4EA44 800B7244 15006210 */  beq        $v1, $v0, .L800B729C
    /* 4EA48 800B7248 02006228 */   slti      $v0, $v1, 0x2
    /* 4EA4C 800B724C 05004010 */  beqz       $v0, .L800B7264
    /* 4EA50 800B7250 00000000 */   nop
    /* 4EA54 800B7254 0A006010 */  beqz       $v1, .L800B7280
    /* 4EA58 800B7258 00000000 */   nop
    /* 4EA5C 800B725C D0DC0208 */  j          .L800B7340
    /* 4EA60 800B7260 00000000 */   nop
  .L800B7264:
    /* 4EA64 800B7264 02000224 */  addiu      $v0, $zero, 0x2
    /* 4EA68 800B7268 17006210 */  beq        $v1, $v0, .L800B72C8
    /* 4EA6C 800B726C 03000224 */   addiu     $v0, $zero, 0x3
    /* 4EA70 800B7270 22006210 */  beq        $v1, $v0, .L800B72FC
    /* 4EA74 800B7274 00000000 */   nop
    /* 4EA78 800B7278 D0DC0208 */  j          .L800B7340
    /* 4EA7C 800B727C 00000000 */   nop
  .L800B7280:
    /* 4EA80 800B7280 FDFA020C */  jal        vs_battle_getStateFlag
    /* 4EA84 800B7284 21200002 */   addu      $a0, $s0, $zero
    /* 4EA88 800B7288 0F80033C */  lui        $v1, %hi(vs_battle_stringContext)
    /* 4EA8C 800B728C 68516324 */  addiu      $v1, $v1, %lo(vs_battle_stringContext)
    /* 4EA90 800B7290 01002492 */  lbu        $a0, 0x1($s1)
    /* 4EA94 800B7294 AEDC0208 */  j          .L800B72B8
    /* 4EA98 800B7298 FF004230 */   andi      $v0, $v0, 0xFF
  .L800B729C:
    /* 4EA9C 800B729C FDFA020C */  jal        vs_battle_getStateFlag
    /* 4EAA0 800B72A0 21200002 */   addu      $a0, $s0, $zero
    /* 4EAA4 800B72A4 0F80033C */  lui        $v1, %hi(vs_battle_stringContext)
    /* 4EAA8 800B72A8 68516324 */  addiu      $v1, $v1, %lo(vs_battle_stringContext)
    /* 4EAAC 800B72AC 00160200 */  sll        $v0, $v0, 24
    /* 4EAB0 800B72B0 01002492 */  lbu        $a0, 0x1($s1)
    /* 4EAB4 800B72B4 03160200 */  sra        $v0, $v0, 24
  .L800B72B8:
    /* 4EAB8 800B72B8 80200400 */  sll        $a0, $a0, 2
    /* 4EABC 800B72BC 21208300 */  addu       $a0, $a0, $v1
    /* 4EAC0 800B72C0 D0DC0208 */  j          .L800B7340
    /* 4EAC4 800B72C4 000082AC */   sw        $v0, 0x0($a0)
  .L800B72C8:
    /* 4EAC8 800B72C8 FDFA020C */  jal        vs_battle_getStateFlag
    /* 4EACC 800B72CC 21200002 */   addu      $a0, $s0, $zero
    /* 4EAD0 800B72D0 01000426 */  addiu      $a0, $s0, 0x1
    /* 4EAD4 800B72D4 FDFA020C */  jal        vs_battle_getStateFlag
    /* 4EAD8 800B72D8 21804000 */   addu      $s0, $v0, $zero
    /* 4EADC 800B72DC 0F80033C */  lui        $v1, %hi(vs_battle_stringContext)
    /* 4EAE0 800B72E0 68516324 */  addiu      $v1, $v1, %lo(vs_battle_stringContext)
    /* 4EAE4 800B72E4 FF001032 */  andi       $s0, $s0, 0xFF
    /* 4EAE8 800B72E8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 4EAEC 800B72EC 00120200 */  sll        $v0, $v0, 8
    /* 4EAF0 800B72F0 01002492 */  lbu        $a0, 0x1($s1)
    /* 4EAF4 800B72F4 CDDC0208 */  j          .L800B7334
    /* 4EAF8 800B72F8 25800202 */   or        $s0, $s0, $v0
  .L800B72FC:
    /* 4EAFC 800B72FC FDFA020C */  jal        vs_battle_getStateFlag
    /* 4EB00 800B7300 21200002 */   addu      $a0, $s0, $zero
    /* 4EB04 800B7304 01000426 */  addiu      $a0, $s0, 0x1
    /* 4EB08 800B7308 FDFA020C */  jal        vs_battle_getStateFlag
    /* 4EB0C 800B730C 21804000 */   addu      $s0, $v0, $zero
    /* 4EB10 800B7310 0F80033C */  lui        $v1, %hi(vs_battle_stringContext)
    /* 4EB14 800B7314 68516324 */  addiu      $v1, $v1, %lo(vs_battle_stringContext)
    /* 4EB18 800B7318 FF001032 */  andi       $s0, $s0, 0xFF
    /* 4EB1C 800B731C FF004230 */  andi       $v0, $v0, 0xFF
    /* 4EB20 800B7320 00120200 */  sll        $v0, $v0, 8
    /* 4EB24 800B7324 25800202 */  or         $s0, $s0, $v0
    /* 4EB28 800B7328 00841000 */  sll        $s0, $s0, 16
    /* 4EB2C 800B732C 01002492 */  lbu        $a0, 0x1($s1)
    /* 4EB30 800B7330 03841000 */  sra        $s0, $s0, 16
  .L800B7334:
    /* 4EB34 800B7334 80200400 */  sll        $a0, $a0, 2
    /* 4EB38 800B7338 21208300 */  addu       $a0, $a0, $v1
    /* 4EB3C 800B733C 000090AC */  sw         $s0, 0x0($a0)
  .L800B7340:
    /* 4EB40 800B7340 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4EB44 800B7344 1400B18F */  lw         $s1, 0x14($sp)
    /* 4EB48 800B7348 1000B08F */  lw         $s0, 0x10($sp)
    /* 4EB4C 800B734C 21100000 */  addu       $v0, $zero, $zero
    /* 4EB50 800B7350 0800E003 */  jr         $ra
    /* 4EB54 800B7354 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_script_setStringContextInt
