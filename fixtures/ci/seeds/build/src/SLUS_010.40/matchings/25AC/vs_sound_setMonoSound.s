nonmatching vs_sound_setMonoSound, 0x34

glabel vs_sound_setMonoSound
    /* 2C0C 8001240C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C10 80012410 01000224 */  addiu      $v0, $zero, 0x1
    /* 2C14 80012414 03008214 */  bne        $a0, $v0, .L80012424
    /* 2C18 80012418 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2C1C 8001241C 0A490008 */  j          .L80012428
    /* 2C20 80012420 81000424 */   addiu     $a0, $zero, 0x81
  .L80012424:
    /* 2C24 80012424 80000424 */  addiu      $a0, $zero, 0x80
  .L80012428:
    /* 2C28 80012428 0C63000C */  jal        func_80018C30
    /* 2C2C 8001242C 00000000 */   nop
    /* 2C30 80012430 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2C34 80012434 00000000 */  nop
    /* 2C38 80012438 0800E003 */  jr         $ra
    /* 2C3C 8001243C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_sound_setMonoSound
