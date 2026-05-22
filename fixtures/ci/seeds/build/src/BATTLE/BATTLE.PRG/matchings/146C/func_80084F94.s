nonmatching func_80084F94, 0x5C

glabel func_80084F94
    /* 1C794 80084F94 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C798 80084F98 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C79C 80084F9C 2180C000 */  addu       $s0, $a2, $zero
    /* 1C7A0 80084FA0 3000A28F */  lw         $v0, 0x30($sp)
    /* 1C7A4 80084FA4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C7A8 80084FA8 3B0E020C */  jal        _calculateDamage
    /* 1C7AC 80084FAC 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1C7B0 80084FB0 21204000 */  addu       $a0, $v0, $zero
    /* 1C7B4 80084FB4 00140400 */  sll        $v0, $a0, 16
    /* 1C7B8 80084FB8 09004010 */  beqz       $v0, .L80084FE0
    /* 1C7BC 80084FBC 00000000 */   nop
    /* 1C7C0 80084FC0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1C7C4 80084FC4 CFFF0224 */  addiu      $v0, $zero, -0x31
    /* 1C7C8 80084FC8 24186200 */  and        $v1, $v1, $v0
    /* 1C7CC 80084FCC 08000296 */  lhu        $v0, 0x8($s0)
    /* 1C7D0 80084FD0 20006334 */  ori        $v1, $v1, 0x20
    /* 1C7D4 80084FD4 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 1C7D8 80084FD8 21104400 */  addu       $v0, $v0, $a0
    /* 1C7DC 80084FDC 080002A6 */  sh         $v0, 0x8($s0)
  .L80084FE0:
    /* 1C7E0 80084FE0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C7E4 80084FE4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C7E8 80084FE8 0800E003 */  jr         $ra
    /* 1C7EC 80084FEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80084F94
