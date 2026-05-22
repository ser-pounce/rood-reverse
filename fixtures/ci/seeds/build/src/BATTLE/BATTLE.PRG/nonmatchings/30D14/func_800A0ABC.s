nonmatching func_800A0ABC, 0x40

glabel func_800A0ABC
    /* 382BC 800A0ABC 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 382C0 800A0AC0 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 382C4 800A0AC4 80200400 */  sll        $a0, $a0, 2
    /* 382C8 800A0AC8 21208200 */  addu       $a0, $a0, $v0
    /* 382CC 800A0ACC 0000848C */  lw         $a0, 0x0($a0)
    /* 382D0 800A0AD0 00000000 */  nop
    /* 382D4 800A0AD4 07008010 */  beqz       $a0, .L800A0AF4
    /* 382D8 800A0AD8 FFFF033C */   lui       $v1, (0xFFFF7FFF >> 16)
    /* 382DC 800A0ADC AC05828C */  lw         $v0, 0x5AC($a0)
    /* 382E0 800A0AE0 FF7F6334 */  ori        $v1, $v1, (0xFFFF7FFF & 0xFFFF)
    /* 382E4 800A0AE4 401880A4 */  sh         $zero, 0x1840($a0)
    /* 382E8 800A0AE8 461880A0 */  sb         $zero, 0x1846($a0)
    /* 382EC 800A0AEC 24104300 */  and        $v0, $v0, $v1
    /* 382F0 800A0AF0 AC0582AC */  sw         $v0, 0x5AC($a0)
  .L800A0AF4:
    /* 382F4 800A0AF4 0800E003 */  jr         $ra
    /* 382F8 800A0AF8 00000000 */   nop
endlabel func_800A0ABC
