nonmatching _getAgilityDifference, 0x234

glabel _getAgilityDifference
    /* 16274 8007EA74 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 16278 8007EA78 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1627C 8007EA7C 21988000 */  addu       $s3, $a0, $zero
    /* 16280 8007EA80 2000B4AF */  sw         $s4, 0x20($sp)
    /* 16284 8007EA84 21A0E000 */  addu       $s4, $a3, $zero
    /* 16288 8007EA88 21480000 */  addu       $t1, $zero, $zero
    /* 1628C 8007EA8C 0F80043C */  lui        $a0, %hi(vs_battle_actors)
    /* 16290 8007EA90 3800AB8F */  lw         $t3, 0x38($sp)
    /* 16294 8007EA94 28198424 */  addiu      $a0, $a0, %lo(vs_battle_actors)
    /* 16298 8007EA98 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1629C 8007EA9C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 162A0 8007EAA0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 162A4 8007EAA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 162A8 8007EAA8 0100CA80 */  lb         $t2, 0x1($a2)
    /* 162AC 8007EAAC 0000A390 */  lbu        $v1, 0x0($a1)
    /* 162B0 8007EAB0 0000C290 */  lbu        $v0, 0x0($a2)
    /* 162B4 8007EAB4 80180300 */  sll        $v1, $v1, 2
    /* 162B8 8007EAB8 21186400 */  addu       $v1, $v1, $a0
    /* 162BC 8007EABC 80100200 */  sll        $v0, $v0, 2
    /* 162C0 8007EAC0 21104400 */  addu       $v0, $v0, $a0
    /* 162C4 8007EAC4 0000428C */  lw         $v0, 0x0($v0)
    /* 162C8 8007EAC8 0000638C */  lw         $v1, 0x0($v1)
    /* 162CC 8007EACC 3C00518C */  lw         $s1, 0x3C($v0)
    /* 162D0 8007EAD0 3C00728C */  lw         $s2, 0x3C($v1)
    /* 162D4 8007EAD4 21382002 */  addu       $a3, $s1, $zero
    /* 162D8 8007EAD8 21304002 */  addu       $a2, $s2, $zero
    /* 162DC 8007EADC 2A004596 */  lhu        $a1, 0x2A($s2)
    /* 162E0 8007EAE0 6C034386 */  lh         $v1, 0x36C($s2)
    /* 162E4 8007EAE4 2A002496 */  lhu        $a0, 0x2A($s1)
    /* 162E8 8007EAE8 6C032286 */  lh         $v0, 0x36C($s1)
    /* 162EC 8007EAEC 2128A300 */  addu       $a1, $a1, $v1
    /* 162F0 8007EAF0 21408200 */  addu       $t0, $a0, $v0
  .L8007EAF4:
    /* 162F4 8007EAF4 F403E384 */  lh         $v1, 0x3F4($a3)
    /* 162F8 8007EAF8 DC00E724 */  addiu      $a3, $a3, 0xDC
    /* 162FC 8007EAFC F403C284 */  lh         $v0, 0x3F4($a2)
    /* 16300 8007EB00 DC00C624 */  addiu      $a2, $a2, 0xDC
    /* 16304 8007EB04 01002925 */  addiu      $t1, $t1, 0x1
    /* 16308 8007EB08 2128A200 */  addu       $a1, $a1, $v0
    /* 1630C 8007EB0C 06002229 */  slti       $v0, $t1, 0x6
    /* 16310 8007EB10 F8FF4014 */  bnez       $v0, .L8007EAF4
    /* 16314 8007EB14 21400301 */   addu      $t0, $t0, $v1
    /* 16318 8007EB18 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1631C 8007EB1C 57094292 */  lbu        $v0, 0x957($s2)
    /* 16320 8007EB20 28196424 */  addiu      $a0, $v1, %lo(vs_battle_actors)
    /* 16324 8007EB24 80100200 */  sll        $v0, $v0, 2
    /* 16328 8007EB28 21104400 */  addu       $v0, $v0, $a0
    /* 1632C 8007EB2C 0000428C */  lw         $v0, 0x0($v0)
    /* 16330 8007EB30 00000000 */  nop
    /* 16334 8007EB34 2000428C */  lw         $v0, 0x20($v0)
    /* 16338 8007EB38 00000000 */  nop
    /* 1633C 8007EB3C 01004230 */  andi       $v0, $v0, 0x1
    /* 16340 8007EB40 06004010 */  beqz       $v0, .L8007EB5C
    /* 16344 8007EB44 00000000 */   nop
    /* 16348 8007EB48 5C014286 */  lh         $v0, 0x15C($s2)
    /* 1634C 8007EB4C C0024386 */  lh         $v1, 0x2C0($s2)
    /* 16350 8007EB50 00000000 */  nop
    /* 16354 8007EB54 21104300 */  addu       $v0, $v0, $v1
    /* 16358 8007EB58 2128A200 */  addu       $a1, $a1, $v0
  .L8007EB5C:
    /* 1635C 8007EB5C 57092292 */  lbu        $v0, 0x957($s1)
    /* 16360 8007EB60 00000000 */  nop
    /* 16364 8007EB64 80100200 */  sll        $v0, $v0, 2
    /* 16368 8007EB68 21104400 */  addu       $v0, $v0, $a0
    /* 1636C 8007EB6C 0000428C */  lw         $v0, 0x0($v0)
    /* 16370 8007EB70 00000000 */  nop
    /* 16374 8007EB74 2000428C */  lw         $v0, 0x20($v0)
    /* 16378 8007EB78 00000000 */  nop
    /* 1637C 8007EB7C 01004230 */  andi       $v0, $v0, 0x1
    /* 16380 8007EB80 06004010 */  beqz       $v0, .L8007EB9C
    /* 16384 8007EB84 00000000 */   nop
    /* 16388 8007EB88 5C012286 */  lh         $v0, 0x15C($s1)
    /* 1638C 8007EB8C C0022386 */  lh         $v1, 0x2C0($s1)
    /* 16390 8007EB90 00000000 */  nop
    /* 16394 8007EB94 21104300 */  addu       $v0, $v0, $v1
    /* 16398 8007EB98 21400201 */  addu       $t0, $t0, $v0
  .L8007EB9C:
    /* 1639C 8007EB9C 20004496 */  lhu        $a0, 0x20($s2)
    /* 163A0 8007EBA0 64000324 */  addiu      $v1, $zero, 0x64
    /* 163A4 8007EBA4 23206400 */  subu       $a0, $v1, $a0
    /* 163A8 8007EBA8 1800A400 */  mult       $a1, $a0
    /* 163AC 8007EBAC C0100A00 */  sll        $v0, $t2, 3
    /* 163B0 8007EBB0 23104A00 */  subu       $v0, $v0, $t2
    /* 163B4 8007EBB4 C0100200 */  sll        $v0, $v0, 3
    /* 163B8 8007EBB8 23104A00 */  subu       $v0, $v0, $t2
    /* 163BC 8007EBBC 80100200 */  sll        $v0, $v0, 2
    /* 163C0 8007EBC0 21102202 */  addu       $v0, $s1, $v0
    /* 163C4 8007EBC4 9C034280 */  lb         $v0, 0x39C($v0)
    /* 163C8 8007EBC8 20002596 */  lhu        $a1, 0x20($s1)
    /* 163CC 8007EBCC 12200000 */  mflo       $a0
    /* 163D0 8007EBD0 21400201 */  addu       $t0, $t0, $v0
    /* 163D4 8007EBD4 23186500 */  subu       $v1, $v1, $a1
    /* 163D8 8007EBD8 18000301 */  mult       $t0, $v1
    /* 163DC 8007EBDC 12180000 */  mflo       $v1
    /* 163E0 8007EBE0 EB51023C */  lui        $v0, (0x51EB851F >> 16)
    /* 163E4 8007EBE4 1F854234 */  ori        $v0, $v0, (0x51EB851F & 0xFFFF)
    /* 163E8 8007EBE8 18008200 */  mult       $a0, $v0
    /* 163EC 8007EBEC 10400000 */  mfhi       $t0
    /* 163F0 8007EBF0 00000000 */  nop
    /* 163F4 8007EBF4 00000000 */  nop
    /* 163F8 8007EBF8 18006200 */  mult       $v1, $v0
    /* 163FC 8007EBFC C3270400 */  sra        $a0, $a0, 31
    /* 16400 8007EC00 43110800 */  sra        $v0, $t0, 5
    /* 16404 8007EC04 23284400 */  subu       $a1, $v0, $a0
    /* 16408 8007EC08 C31F0300 */  sra        $v1, $v1, 31
    /* 1640C 8007EC0C 10300000 */  mfhi       $a2
    /* 16410 8007EC10 43110600 */  sra        $v0, $a2, 5
    /* 16414 8007EC14 23404300 */  subu       $t0, $v0, $v1
    /* 16418 8007EC18 2380A800 */  subu       $s0, $a1, $t0
    /* 1641C 8007EC1C 05006011 */  beqz       $t3, .L8007EC34
    /* 16420 8007EC20 64001026 */   addiu     $s0, $s0, 0x64
    /* 16424 8007EC24 180A010C */  jal        vs_main_getRandSmoothed
    /* 16428 8007EC28 0B000424 */   addiu     $a0, $zero, 0xB
    /* 1642C 8007EC2C FBFF0326 */  addiu      $v1, $s0, -0x5
    /* 16430 8007EC30 21806200 */  addu       $s0, $v1, $v0
  .L8007EC34:
    /* 16434 8007EC34 21206002 */  addu       $a0, $s3, $zero
    /* 16438 8007EC38 78F9010C */  jal        _getAttackGemBuff
    /* 1643C 8007EC3C 21284002 */   addu      $a1, $s2, $zero
    /* 16440 8007EC40 00140200 */  sll        $v0, $v0, 16
    /* 16444 8007EC44 03140200 */  sra        $v0, $v0, 16
    /* 16448 8007EC48 21800202 */  addu       $s0, $s0, $v0
    /* 1644C 8007EC4C 21206002 */  addu       $a0, $s3, $zero
    /* 16450 8007EC50 21282002 */  addu       $a1, $s1, $zero
    /* 16454 8007EC54 A8F9010C */  jal        _getDefenseGemBuff
    /* 16458 8007EC58 21308002 */   addu      $a2, $s4, $zero
    /* 1645C 8007EC5C 00140200 */  sll        $v0, $v0, 16
    /* 16460 8007EC60 03140200 */  sra        $v0, $v0, 16
    /* 16464 8007EC64 23800202 */  subu       $s0, $s0, $v0
    /* 16468 8007EC68 03000106 */  bgez       $s0, .L8007EC78
    /* 1646C 8007EC6C FF000224 */   addiu     $v0, $zero, 0xFF
    /* 16470 8007EC70 21FB0108 */  j          .L8007EC84
    /* 16474 8007EC74 21800000 */   addu      $s0, $zero, $zero
  .L8007EC78:
    /* 16478 8007EC78 03000216 */  bne        $s0, $v0, .L8007EC88
    /* 1647C 8007EC7C 21100002 */   addu      $v0, $s0, $zero
    /* 16480 8007EC80 FE001024 */  addiu      $s0, $zero, 0xFE
  .L8007EC84:
    /* 16484 8007EC84 21100002 */  addu       $v0, $s0, $zero
  .L8007EC88:
    /* 16488 8007EC88 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1648C 8007EC8C 2000B48F */  lw         $s4, 0x20($sp)
    /* 16490 8007EC90 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 16494 8007EC94 1800B28F */  lw         $s2, 0x18($sp)
    /* 16498 8007EC98 1400B18F */  lw         $s1, 0x14($sp)
    /* 1649C 8007EC9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 164A0 8007ECA0 0800E003 */  jr         $ra
    /* 164A4 8007ECA4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _getAgilityDifference
