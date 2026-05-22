nonmatching func_800CFC48, 0x44

glabel func_800CFC48
    /* 67448 800CFC48 02008104 */  bgez       $a0, .L800CFC54
    /* 6744C 800CFC4C 21188000 */   addu      $v1, $a0, $zero
    /* 67450 800CFC50 23180300 */  negu       $v1, $v1
  .L800CFC54:
    /* 67454 800CFC54 0500A004 */  bltz       $a1, .L800CFC6C
    /* 67458 800CFC58 2A106500 */   slt       $v0, $v1, $a1
    /* 6745C 800CFC5C 07004014 */  bnez       $v0, .L800CFC7C
    /* 67460 800CFC60 21108000 */   addu      $v0, $a0, $zero
    /* 67464 800CFC64 213F0308 */  j          .L800CFC84
    /* 67468 800CFC68 00000000 */   nop
  .L800CFC6C:
    /* 6746C 800CFC6C 23100500 */  negu       $v0, $a1
    /* 67470 800CFC70 2A106200 */  slt        $v0, $v1, $v0
    /* 67474 800CFC74 03004010 */  beqz       $v0, .L800CFC84
    /* 67478 800CFC78 21108000 */   addu      $v0, $a0, $zero
  .L800CFC7C:
    /* 6747C 800CFC7C 0800E003 */  jr         $ra
    /* 67480 800CFC80 2110A000 */   addu      $v0, $a1, $zero
  .L800CFC84:
    /* 67484 800CFC84 0800E003 */  jr         $ra
    /* 67488 800CFC88 00000000 */   nop
endlabel func_800CFC48
