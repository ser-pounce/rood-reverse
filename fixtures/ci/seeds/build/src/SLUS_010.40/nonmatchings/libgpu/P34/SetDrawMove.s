nonmatching SetDrawMove, 0x60

glabel SetDrawMove
    /* 1BEB4 8002B6B4 21408000 */  addu       $t0, $a0, $zero
    /* 1BEB8 8002B6B8 0400A284 */  lh         $v0, 0x4($a1)
    /* 1BEBC 8002B6BC 00000000 */  nop
    /* 1BEC0 8002B6C0 05004010 */  beqz       $v0, .L8002B6D8
    /* 1BEC4 8002B6C4 05000424 */   addiu     $a0, $zero, 0x5
    /* 1BEC8 8002B6C8 0600A284 */  lh         $v0, 0x6($a1)
    /* 1BECC 8002B6CC 00000000 */  nop
    /* 1BED0 8002B6D0 03004014 */  bnez       $v0, .L8002B6E0
    /* 1BED4 8002B6D4 0001023C */   lui       $v0, (0x1000000 >> 16)
  .L8002B6D8:
    /* 1BED8 8002B6D8 21200000 */  addu       $a0, $zero, $zero
    /* 1BEDC 8002B6DC 0001023C */  lui        $v0, (0x1000000 >> 16)
  .L8002B6E0:
    /* 1BEE0 8002B6E0 040002AD */  sw         $v0, 0x4($t0)
    /* 1BEE4 8002B6E4 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 1BEE8 8002B6E8 080002AD */  sw         $v0, 0x8($t0)
    /* 1BEEC 8002B6EC 00140700 */  sll        $v0, $a3, 16
    /* 1BEF0 8002B6F0 FFFFC330 */  andi       $v1, $a2, 0xFFFF
    /* 1BEF4 8002B6F4 030004A1 */  sb         $a0, 0x3($t0)
    /* 1BEF8 8002B6F8 0000A48C */  lw         $a0, 0x0($a1)
    /* 1BEFC 8002B6FC 25104300 */  or         $v0, $v0, $v1
    /* 1BF00 8002B700 100002AD */  sw         $v0, 0x10($t0)
    /* 1BF04 8002B704 0C0004AD */  sw         $a0, 0xC($t0)
    /* 1BF08 8002B708 0400A28C */  lw         $v0, 0x4($a1)
    /* 1BF0C 8002B70C 0800E003 */  jr         $ra
    /* 1BF10 8002B710 140002AD */   sw        $v0, 0x14($t0)
endlabel SetDrawMove
