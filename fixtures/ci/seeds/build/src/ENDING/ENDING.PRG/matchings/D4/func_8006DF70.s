nonmatching func_8006DF70, 0x60

glabel func_8006DF70
    /* 5770 8006DF70 04008424 */  addiu      $a0, $a0, 0x4
    /* 5774 8006DF74 0000828C */  lw         $v0, 0x0($a0)
    /* 5778 8006DF78 00000000 */  nop
    /* 577C 8006DF7C 0000A2AC */  sw         $v0, 0x0($a1)
    /* 5780 8006DF80 08004230 */  andi       $v0, $v0, 0x8
    /* 5784 8006DF84 0B004010 */  beqz       $v0, .L8006DFB4
    /* 5788 8006DF88 04008424 */   addiu     $a0, $a0, 0x4
    /* 578C 8006DF8C 04008224 */  addiu      $v0, $a0, 0x4
    /* 5790 8006DF90 0400A2AC */  sw         $v0, 0x4($a1)
    /* 5794 8006DF94 0C008224 */  addiu      $v0, $a0, 0xC
    /* 5798 8006DF98 0800A2AC */  sw         $v0, 0x8($a1)
    /* 579C 8006DF9C 0000828C */  lw         $v0, 0x0($a0)
    /* 57A0 8006DFA0 00000000 */  nop
    /* 57A4 8006DFA4 82100200 */  srl        $v0, $v0, 2
    /* 57A8 8006DFA8 80100200 */  sll        $v0, $v0, 2
    /* 57AC 8006DFAC EFB70108 */  j          .L8006DFBC
    /* 57B0 8006DFB0 21208200 */   addu      $a0, $a0, $v0
  .L8006DFB4:
    /* 57B4 8006DFB4 0400A0AC */  sw         $zero, 0x4($a1)
    /* 57B8 8006DFB8 0800A0AC */  sw         $zero, 0x8($a1)
  .L8006DFBC:
    /* 57BC 8006DFBC 04008224 */  addiu      $v0, $a0, 0x4
    /* 57C0 8006DFC0 0C00A2AC */  sw         $v0, 0xC($a1)
    /* 57C4 8006DFC4 0C008224 */  addiu      $v0, $a0, 0xC
    /* 57C8 8006DFC8 0800E003 */  jr         $ra
    /* 57CC 8006DFCC 1000A2AC */   sw        $v0, 0x10($a1)
endlabel func_8006DF70
