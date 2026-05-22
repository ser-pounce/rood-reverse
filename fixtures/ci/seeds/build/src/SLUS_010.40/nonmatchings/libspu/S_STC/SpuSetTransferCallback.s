nonmatching SpuSetTransferCallback, 0x24

glabel SpuSetTransferCallback
    /* F454 8001EC54 0380023C */  lui        $v0, %hi(D_80030898)
    /* F458 8001EC58 9808428C */  lw         $v0, %lo(D_80030898)($v0)
    /* F45C 8001EC5C 00000000 */  nop
    /* F460 8001EC60 03008210 */  beq        $a0, $v0, .L8001EC70
    /* F464 8001EC64 00000000 */   nop
    /* F468 8001EC68 0380013C */  lui        $at, %hi(D_80030898)
    /* F46C 8001EC6C 980824AC */  sw         $a0, %lo(D_80030898)($at)
  .L8001EC70:
    /* F470 8001EC70 0800E003 */  jr         $ra
    /* F474 8001EC74 00000000 */   nop
endlabel SpuSetTransferCallback
    /* F478 8001EC78 00000000 */  nop
    /* F47C 8001EC7C 00000000 */  nop
    /* F480 8001EC80 00000000 */  nop
