nonmatching func_800D6388, 0x48

glabel func_800D6388
    /* 6DB88 800D6388 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DB8C 800D638C 21288000 */  addu       $a1, $a0, $zero
    /* 6DB90 800D6390 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DB94 800D6394 340DA394 */  lhu        $v1, 0xD34($a1)
    /* 6DB98 800D6398 04000224 */  addiu      $v0, $zero, 0x4
    /* 6DB9C 800D639C 04006214 */  bne        $v1, $v0, .L800D63B0
    /* 6DBA0 800D63A0 00000000 */   nop
    /* 6DBA4 800D63A4 380DA490 */  lbu        $a0, 0xD38($a1)
    /* 6DBA8 800D63A8 EE580308 */  j          .L800D63B8
    /* 6DBAC 800D63AC 21280000 */   addu      $a1, $zero, $zero
  .L800D63B0:
    /* 6DBB0 800D63B0 3E0DA484 */  lh         $a0, 0xD3E($a1)
    /* 6DBB4 800D63B4 380DA524 */  addiu      $a1, $a1, 0xD38
  .L800D63B8:
    /* 6DBB8 800D63B8 C1B2010C */  jal        func_8006CB04
    /* 6DBBC 800D63BC 00000000 */   nop
    /* 6DBC0 800D63C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DBC4 800D63C4 00000000 */  nop
    /* 6DBC8 800D63C8 0800E003 */  jr         $ra
    /* 6DBCC 800D63CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D6388
