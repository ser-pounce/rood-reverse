nonmatching func_8008D5FC, 0x5C

glabel func_8008D5FC
    /* 24DFC 8008D5FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 24E00 8008D600 21288000 */  addu       $a1, $a0, $zero
    /* 24E04 8008D604 1000BFAF */  sw         $ra, 0x10($sp)
    /* 24E08 8008D608 0B00A280 */  lb         $v0, 0xB($a1)
    /* 24E0C 8008D60C 00000000 */  nop
    /* 24E10 8008D610 0D004014 */  bnez       $v0, .L8008D648
    /* 24E14 8008D614 01000224 */   addiu     $v0, $zero, 0x1
    /* 24E18 8008D618 0800A384 */  lh         $v1, 0x8($a1)
    /* 24E1C 8008D61C 00000000 */  nop
    /* 24E20 8008D620 07006014 */  bnez       $v1, .L8008D640
    /* 24E24 8008D624 0B00A2A0 */   sb        $v0, 0xB($a1)
    /* 24E28 8008D628 14000224 */  addiu      $v0, $zero, 0x14
    /* 24E2C 8008D62C 0A00A2A0 */  sb         $v0, 0xA($a1)
    /* 24E30 8008D630 1C30020C */  jal        func_8008C070
    /* 24E34 8008D634 02000424 */   addiu     $a0, $zero, 0x2
    /* 24E38 8008D638 92350208 */  j          .L8008D648
    /* 24E3C 8008D63C 00000000 */   nop
  .L8008D640:
    /* 24E40 8008D640 9635020C */  jal        func_8008D658
    /* 24E44 8008D644 2120A000 */   addu      $a0, $a1, $zero
  .L8008D648:
    /* 24E48 8008D648 1000BF8F */  lw         $ra, 0x10($sp)
    /* 24E4C 8008D64C 00000000 */  nop
    /* 24E50 8008D650 0800E003 */  jr         $ra
    /* 24E54 8008D654 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D5FC
