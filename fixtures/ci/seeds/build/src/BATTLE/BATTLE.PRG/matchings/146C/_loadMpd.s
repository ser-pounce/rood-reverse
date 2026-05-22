nonmatching _loadMpd, 0x9C

glabel _loadMpd
    /* 21524 80089D24 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21528 80089D28 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 2152C 80089D2C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 21530 80089D30 80185024 */  addiu      $s0, $v0, %lo(_zoneContext)
    /* 21534 80089D34 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 21538 80089D38 0400028E */  lw         $v0, 0x4($s0)
    /* 2153C 80089D3C C0200400 */  sll        $a0, $a0, 3
    /* 21540 80089D40 21208200 */  addu       $a0, $a0, $v0
    /* 21544 80089D44 0000828C */  lw         $v0, 0x0($a0)
    /* 21548 80089D48 00000000 */  nop
    /* 2154C 80089D4C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 21550 80089D50 0400828C */  lw         $v0, 0x4($a0)
    /* 21554 80089D54 5800038E */  lw         $v1, 0x58($s0)
    /* 21558 80089D58 00000000 */  nop
    /* 2155C 80089D5C 04006010 */  beqz       $v1, .L80089D70
    /* 21560 80089D60 1400A2AF */   sw        $v0, 0x14($sp)
    /* 21564 80089D64 89000424 */  addiu      $a0, $zero, 0x89
    /* 21568 80089D68 2624010C */  jal        vs_main_nop9
    /* 2156C 80089D6C 21280000 */   addu      $a1, $zero, $zero
  .L80089D70:
    /* 21570 80089D70 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 21574 80089D74 1000A427 */   addiu     $a0, $sp, 0x10
    /* 21578 80089D78 5C00038E */  lw         $v1, 0x5C($s0)
    /* 2157C 80089D7C 00000000 */  nop
    /* 21580 80089D80 04006010 */  beqz       $v1, .L80089D94
    /* 21584 80089D84 580002AE */   sw        $v0, 0x58($s0)
    /* 21588 80089D88 8A000424 */  addiu      $a0, $zero, 0x8A
    /* 2158C 80089D8C 2624010C */  jal        vs_main_nop9
    /* 21590 80089D90 21280000 */   addu      $a1, $zero, $zero
  .L80089D94:
    /* 21594 80089D94 1400A48F */  lw         $a0, 0x14($sp)
    /* 21598 80089D98 8F0F010C */  jal        vs_main_allocHeapR
    /* 2159C 80089D9C 00000000 */   nop
    /* 215A0 80089DA0 5800048E */  lw         $a0, 0x58($s0)
    /* 215A4 80089DA4 21284000 */  addu       $a1, $v0, $zero
    /* 215A8 80089DA8 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 215AC 80089DAC 5C0005AE */   sw        $a1, 0x5C($s0)
    /* 215B0 80089DB0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 215B4 80089DB4 1800B08F */  lw         $s0, 0x18($sp)
    /* 215B8 80089DB8 0800E003 */  jr         $ra
    /* 215BC 80089DBC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadMpd
