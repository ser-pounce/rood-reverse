nonmatching _loadZndEnemies, 0xC8

glabel _loadZndEnemies
    /* 20540 80088D40 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 20544 80088D44 1400B1AF */  sw         $s1, 0x14($sp)
    /* 20548 80088D48 21888000 */  addu       $s1, $a0, $zero
    /* 2054C 80088D4C 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 20550 80088D50 1800BFAF */  sw         $ra, 0x18($sp)
    /* 20554 80088D54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 20558 80088D58 0000248E */  lw         $a0, 0x0($s1)
    /* 2055C 80088D5C 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 20560 80088D60 22008010 */  beqz       $a0, .L80088DEC
    /* 20564 80088D64 080004AE */   sw        $a0, 0x8($s0)
    /* 20568 80088D68 B10F010C */  jal        vs_main_allocHeap
    /* 2056C 80088D6C C0200400 */   sll       $a0, $a0, 3
    /* 20570 80088D70 21204000 */  addu       $a0, $v0, $zero
    /* 20574 80088D74 0800068E */  lw         $a2, 0x8($s0)
    /* 20578 80088D78 04002526 */  addiu      $a1, $s1, 0x4
    /* 2057C 80088D7C 100004AE */  sw         $a0, 0x10($s0)
    /* 20580 80088D80 2C24010C */  jal        vs_main_memcpy
    /* 20584 80088D84 C0300600 */   sll       $a2, $a2, 3
    /* 20588 80088D88 0800028E */  lw         $v0, 0x8($s0)
    /* 2058C 80088D8C 00000000 */  nop
    /* 20590 80088D90 C0200200 */  sll        $a0, $v0, 3
    /* 20594 80088D94 21208200 */  addu       $a0, $a0, $v0
    /* 20598 80088D98 80200400 */  sll        $a0, $a0, 2
    /* 2059C 80088D9C 23208200 */  subu       $a0, $a0, $v0
    /* 205A0 80088DA0 C0200400 */  sll        $a0, $a0, 3
    /* 205A4 80088DA4 21208200 */  addu       $a0, $a0, $v0
    /* 205A8 80088DA8 B10F010C */  jal        vs_main_allocHeap
    /* 205AC 80088DAC 80200400 */   sll       $a0, $a0, 2
    /* 205B0 80088DB0 0800038E */  lw         $v1, 0x8($s0)
    /* 205B4 80088DB4 21204000 */  addu       $a0, $v0, $zero
    /* 205B8 80088DB8 0C0004AE */  sw         $a0, 0xC($s0)
    /* 205BC 80088DBC C0300300 */  sll        $a2, $v1, 3
    /* 205C0 80088DC0 0400C524 */  addiu      $a1, $a2, 0x4
    /* 205C4 80088DC4 21282502 */  addu       $a1, $s1, $a1
    /* 205C8 80088DC8 2130C300 */  addu       $a2, $a2, $v1
    /* 205CC 80088DCC 80300600 */  sll        $a2, $a2, 2
    /* 205D0 80088DD0 2330C300 */  subu       $a2, $a2, $v1
    /* 205D4 80088DD4 C0300600 */  sll        $a2, $a2, 3
    /* 205D8 80088DD8 2130C300 */  addu       $a2, $a2, $v1
    /* 205DC 80088DDC 2C24010C */  jal        vs_main_memcpy
    /* 205E0 80088DE0 80300600 */   sll       $a2, $a2, 2
    /* 205E4 80088DE4 7D230208 */  j          .L80088DF4
    /* 205E8 80088DE8 00000000 */   nop
  .L80088DEC:
    /* 205EC 80088DEC 100000AE */  sw         $zero, 0x10($s0)
    /* 205F0 80088DF0 0C0000AE */  sw         $zero, 0xC($s0)
  .L80088DF4:
    /* 205F4 80088DF4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 205F8 80088DF8 1400B18F */  lw         $s1, 0x14($sp)
    /* 205FC 80088DFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 20600 80088E00 0800E003 */  jr         $ra
    /* 20604 80088E04 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadZndEnemies
