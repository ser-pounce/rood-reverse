nonmatching func_8009FBD8, 0x48

glabel func_8009FBD8
    /* 373D8 8009FBD8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 373DC 8009FBDC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 373E0 8009FBE0 80200400 */  sll        $a0, $a0, 2
    /* 373E4 8009FBE4 21208200 */  addu       $a0, $a0, $v0
    /* 373E8 8009FBE8 0000848C */  lw         $a0, 0x0($a0)
    /* 373EC 8009FBEC F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 373F0 8009FBF0 08008010 */  beqz       $a0, .L8009FC14
    /* 373F4 8009FBF4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 373F8 8009FBF8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 373FC 8009FBFC 0300A214 */  bne        $a1, $v0, .L8009FC0C
    /* 37400 8009FC00 0D000224 */   addiu     $v0, $zero, 0xD
    /* 37404 8009FC04 047F0208 */  j          .L8009FC10
    /* 37408 8009FC08 E50682A0 */   sb        $v0, 0x6E5($a0)
  .L8009FC0C:
    /* 3740C 8009FC0C E50685A0 */  sb         $a1, 0x6E5($a0)
  .L8009FC10:
    /* 37410 8009FC10 21100000 */  addu       $v0, $zero, $zero
  .L8009FC14:
    /* 37414 8009FC14 0800BD27 */  addiu      $sp, $sp, 0x8
    /* 37418 8009FC18 0800E003 */  jr         $ra
    /* 3741C 8009FC1C 00000000 */   nop
endlabel func_8009FBD8
