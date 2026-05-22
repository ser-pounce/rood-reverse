nonmatching SetDrawMode, 0x94

glabel SetDrawMode
    /* 1BF44 8002B744 21408000 */  addu       $t0, $a0, $zero
    /* 1BF48 8002B748 00E1033C */  lui        $v1, (0xE1000200 >> 16)
    /* 1BF4C 8002B74C 1000A98F */  lw         $t1, 0x10($sp)
    /* 1BF50 8002B750 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BF54 8002B754 0200C010 */  beqz       $a2, .L8002B760
    /* 1BF58 8002B758 030002A1 */   sb        $v0, 0x3($t0)
    /* 1BF5C 8002B75C 00026334 */  ori        $v1, $v1, (0xE1000200 & 0xFFFF)
  .L8002B760:
    /* 1BF60 8002B760 0200A010 */  beqz       $a1, .L8002B76C
    /* 1BF64 8002B764 FF09E230 */   andi      $v0, $a3, 0x9FF
    /* 1BF68 8002B768 00044234 */  ori        $v0, $v0, 0x400
  .L8002B76C:
    /* 1BF6C 8002B76C 25106200 */  or         $v0, $v1, $v0
    /* 1BF70 8002B770 16002011 */  beqz       $t1, .L8002B7CC
    /* 1BF74 8002B774 040002AD */   sw        $v0, 0x4($t0)
    /* 1BF78 8002B778 00E2033C */  lui        $v1, (0xE2000000 >> 16)
    /* 1BF7C 8002B77C 02002491 */  lbu        $a0, 0x2($t1)
    /* 1BF80 8002B780 00002291 */  lbu        $v0, 0x0($t1)
    /* 1BF84 8002B784 C2200400 */  srl        $a0, $a0, 3
    /* 1BF88 8002B788 C0230400 */  sll        $a0, $a0, 15
    /* 1BF8C 8002B78C C2100200 */  srl        $v0, $v0, 3
    /* 1BF90 8002B790 80120200 */  sll        $v0, $v0, 10
    /* 1BF94 8002B794 25104300 */  or         $v0, $v0, $v1
    /* 1BF98 8002B798 25208200 */  or         $a0, $a0, $v0
    /* 1BF9C 8002B79C 06002385 */  lh         $v1, 0x6($t1)
    /* 1BFA0 8002B7A0 04002285 */  lh         $v0, 0x4($t1)
    /* 1BFA4 8002B7A4 23180300 */  negu       $v1, $v1
    /* 1BFA8 8002B7A8 80180300 */  sll        $v1, $v1, 2
    /* 1BFAC 8002B7AC E0036330 */  andi       $v1, $v1, 0x3E0
    /* 1BFB0 8002B7B0 25208300 */  or         $a0, $a0, $v1
    /* 1BFB4 8002B7B4 23100200 */  negu       $v0, $v0
    /* 1BFB8 8002B7B8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1BFBC 8002B7BC C3100200 */  sra        $v0, $v0, 3
    /* 1BFC0 8002B7C0 25208200 */  or         $a0, $a0, $v0
    /* 1BFC4 8002B7C4 F4AD0008 */  j          .L8002B7D0
    /* 1BFC8 8002B7C8 080004AD */   sw        $a0, 0x8($t0)
  .L8002B7CC:
    /* 1BFCC 8002B7CC 080000AD */  sw         $zero, 0x8($t0)
  .L8002B7D0:
    /* 1BFD0 8002B7D0 0800E003 */  jr         $ra
    /* 1BFD4 8002B7D4 00000000 */   nop
endlabel SetDrawMode
    /* 1BFD8 8002B7D8 00000000 */  nop
    /* 1BFDC 8002B7DC 00000000 */  nop
    /* 1BFE0 8002B7E0 00000000 */  nop
