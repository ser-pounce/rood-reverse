nonmatching func_800B63AC, 0x58

glabel func_800B63AC
    /* 4DBAC 800B63AC 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DBB0 800B63B0 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DBB4 800B63B4 80180400 */  sll        $v1, $a0, 2
    /* 4DBB8 800B63B8 21104300 */  addu       $v0, $v0, $v1
    /* 4DBBC 800B63BC 0000428C */  lw         $v0, 0x0($v0)
    /* 4DBC0 800B63C0 00000000 */  nop
    /* 4DBC4 800B63C4 0A004380 */  lb         $v1, 0xA($v0)
    /* 4DBC8 800B63C8 B0054980 */  lb         $t1, 0x5B0($v0)
    /* 4DBCC 800B63CC 40006830 */  andi       $t0, $v1, 0x40
    /* 4DBD0 800B63D0 14000015 */  bnez       $t0, .L800B6424
    /* 4DBD4 800B63D4 20006830 */   andi      $t0, $v1, 0x20
    /* 4DBD8 800B63D8 1E000015 */  bnez       $t0, .L800B6454
    /* 4DBDC 800B63DC FC002931 */   andi      $t1, $t1, 0xFC
    /* 4DBE0 800B63E0 01002935 */  ori        $t1, $t1, 0x1
    /* 4DBE4 800B63E4 B00549A0 */  sb         $t1, 0x5B0($v0)
  .L800B63E8:
    /* 4DBE8 800B63E8 FCFFBD27 */  addiu      $sp, $sp, -0x4
    /* 4DBEC 800B63EC 0000BFAF */  sw         $ra, 0x0($sp)
    /* 4DBF0 800B63F0 2388020C */  jal        func_800A208C
    /* 4DBF4 800B63F4 21204000 */   addu      $a0, $v0, $zero
    /* 4DBF8 800B63F8 0000BF8F */  lw         $ra, 0x0($sp)
    /* 4DBFC 800B63FC 0400BD27 */  addiu      $sp, $sp, 0x4
    /* 4DC00 800B6400 0800E003 */  jr         $ra
endlabel func_800B63AC
