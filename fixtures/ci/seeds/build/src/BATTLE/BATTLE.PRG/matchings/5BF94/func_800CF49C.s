nonmatching func_800CF49C, 0x78

glabel func_800CF49C
    /* 66C9C 800CF49C 21500000 */  addu       $t2, $zero, $zero
    /* 66CA0 800CF4A0 21384001 */  addu       $a3, $t2, $zero
    /* 66CA4 800CF4A4 FEFF0C24 */  addiu      $t4, $zero, -0x2
    /* 66CA8 800CF4A8 01000B24 */  addiu      $t3, $zero, 0x1
    /* 66CAC 800CF4AC 0F80023C */  lui        $v0, %hi(D_800F5320)
    /* 66CB0 800CF4B0 20534624 */  addiu      $a2, $v0, %lo(D_800F5320)
  .L800CF4B4:
    /* 66CB4 800CF4B4 0000C58C */  lw         $a1, 0x0($a2)
    /* 66CB8 800CF4B8 00000000 */  nop
    /* 66CBC 800CF4BC 0F00AC10 */  beq        $a1, $t4, .L800CF4FC
    /* 66CC0 800CF4C0 00000000 */   nop
    /* 66CC4 800CF4C4 01000424 */  addiu      $a0, $zero, 0x1
    /* 66CC8 800CF4C8 2140C000 */  addu       $t0, $a2, $zero
    /* 66CCC 800CF4CC 40490700 */  sll        $t1, $a3, 5
    /* 66CD0 800CF4D0 04188B00 */  sllv       $v1, $t3, $a0
  .L800CF4D4:
    /* 66CD4 800CF4D4 2410A300 */  and        $v0, $a1, $v1
    /* 66CD8 800CF4D8 04004014 */  bnez       $v0, .L800CF4EC
    /* 66CDC 800CF4DC 2510A300 */   or        $v0, $a1, $v1
    /* 66CE0 800CF4E0 000002AD */  sw         $v0, 0x0($t0)
    /* 66CE4 800CF4E4 433D0308 */  j          .L800CF50C
    /* 66CE8 800CF4E8 21502401 */   addu      $t2, $t1, $a0
  .L800CF4EC:
    /* 66CEC 800CF4EC 01008424 */  addiu      $a0, $a0, 0x1
    /* 66CF0 800CF4F0 20008228 */  slti       $v0, $a0, 0x20
    /* 66CF4 800CF4F4 F7FF4014 */  bnez       $v0, .L800CF4D4
    /* 66CF8 800CF4F8 04188B00 */   sllv      $v1, $t3, $a0
  .L800CF4FC:
    /* 66CFC 800CF4FC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 66D00 800CF500 0400E228 */  slti       $v0, $a3, 0x4
    /* 66D04 800CF504 EBFF4014 */  bnez       $v0, .L800CF4B4
    /* 66D08 800CF508 0400C624 */   addiu     $a2, $a2, 0x4
  .L800CF50C:
    /* 66D0C 800CF50C 0800E003 */  jr         $ra
    /* 66D10 800CF510 21104001 */   addu      $v0, $t2, $zero
endlabel func_800CF49C
