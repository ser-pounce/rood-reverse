nonmatching func_8001A1F4, 0x38

glabel func_8001A1F4
    /* A9F4 8001A1F4 80FFA224 */  addiu      $v0, $a1, -0x80
    /* A9F8 8001A1F8 2000422C */  sltiu      $v0, $v0, 0x20
    /* A9FC 8001A1FC 07004010 */  beqz       $v0, .L8001A21C
    /* AA00 8001A200 02008230 */   andi      $v0, $a0, 0x2
    /* AA04 8001A204 03004010 */  beqz       $v0, .L8001A214
    /* AA08 8001A208 04008230 */   andi      $v0, $a0, 0x4
    /* AA0C 8001A20C 0800E003 */  jr         $ra
    /* AA10 8001A210 2000A224 */   addiu     $v0, $a1, 0x20
  .L8001A214:
    /* AA14 8001A214 03004014 */  bnez       $v0, .L8001A224
    /* AA18 8001A218 4000A224 */   addiu     $v0, $a1, 0x40
  .L8001A21C:
    /* AA1C 8001A21C 0800E003 */  jr         $ra
    /* AA20 8001A220 2110A000 */   addu      $v0, $a1, $zero
  .L8001A224:
    /* AA24 8001A224 0800E003 */  jr         $ra
    /* AA28 8001A228 00000000 */   nop
endlabel func_8001A1F4
