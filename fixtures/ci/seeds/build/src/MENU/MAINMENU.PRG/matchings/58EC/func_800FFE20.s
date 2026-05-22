nonmatching func_800FFE20, 0x50

glabel func_800FFE20
    /* 6620 800FFE20 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6624 800FFE24 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6628 800FFE28 2118C000 */  addu       $v1, $a2, $zero
    /* 662C 800FFE2C 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 6630 800FFE30 2A106400 */  slt        $v0, $v1, $a0
    /* 6634 800FFE34 03004010 */  beqz       $v0, .L800FFE44
    /* 6638 800FFE38 8080C634 */   ori       $a2, $a2, (0x808080 & 0xFFFF)
    /* 663C 800FFE3C 8000063C */  lui        $a2, (0x804020 >> 16)
    /* 6640 800FFE40 2040C634 */  ori        $a2, $a2, (0x804020 & 0xFFFF)
  .L800FFE44:
    /* 6644 800FFE44 2A108300 */  slt        $v0, $a0, $v1
    /* 6648 800FFE48 03004010 */  beqz       $v0, .L800FFE58
    /* 664C 800FFE4C 00000000 */   nop
    /* 6650 800FFE50 2000063C */  lui        $a2, (0x204080 >> 16)
    /* 6654 800FFE54 8040C634 */  ori        $a2, $a2, (0x204080 & 0xFFFF)
  .L800FFE58:
    /* 6658 800FFE58 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 665C 800FFE5C 00000000 */   nop
    /* 6660 800FFE60 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6664 800FFE64 00000000 */  nop
    /* 6668 800FFE68 0800E003 */  jr         $ra
    /* 666C 800FFE6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFE20
