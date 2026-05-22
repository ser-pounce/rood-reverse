nonmatching func_800B979C, 0x48

glabel func_800B979C
    /* 50F9C 800B979C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50FA0 800B97A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 50FA4 800B97A4 80FF020C */  jal        vs_battle_getShort
    /* 50FA8 800B97A8 01008424 */   addiu     $a0, $a0, 0x1
    /* 50FAC 800B97AC 21204000 */  addu       $a0, $v0, $zero
    /* 50FB0 800B97B0 0F80033C */  lui        $v1, %hi(D_800F4C6A)
    /* 50FB4 800B97B4 00140400 */  sll        $v0, $a0, 16
    /* 50FB8 800B97B8 C3170200 */  sra        $v0, $v0, 31
    /* 50FBC 800B97BC 6A4C62A0 */  sb         $v0, %lo(D_800F4C6A)($v1)
    /* 50FC0 800B97C0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 50FC4 800B97C4 03004010 */  beqz       $v0, .L800B97D4
    /* 50FC8 800B97C8 00000000 */   nop
    /* 50FCC 800B97CC 6560020C */  jal        func_80098194
    /* 50FD0 800B97D0 FF078430 */   andi      $a0, $a0, 0x7FF
  .L800B97D4:
    /* 50FD4 800B97D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 50FD8 800B97D8 21100000 */  addu       $v0, $zero, $zero
    /* 50FDC 800B97DC 0800E003 */  jr         $ra
    /* 50FE0 800B97E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B979C
