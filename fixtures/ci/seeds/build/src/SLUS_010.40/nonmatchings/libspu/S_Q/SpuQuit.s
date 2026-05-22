nonmatching SpuQuit, 0x74

glabel SpuQuit
    /* EE04 8001E604 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EE08 8001E608 0380033C */  lui        $v1, %hi(D_80030850)
    /* EE0C 8001E60C 5008638C */  lw         $v1, %lo(D_80030850)($v1)
    /* EE10 8001E610 01000224 */  addiu      $v0, $zero, 0x1
    /* EE14 8001E614 14006214 */  bne        $v1, $v0, .L8001E668
    /* EE18 8001E618 1000BFAF */   sw        $ra, 0x10($sp)
    /* EE1C 8001E61C 0380013C */  lui        $at, %hi(D_80030850)
    /* EE20 8001E620 5D9A000C */  jal        EnterCriticalSection
    /* EE24 8001E624 500820AC */   sw        $zero, %lo(D_80030850)($at)
    /* EE28 8001E628 21200000 */  addu       $a0, $zero, $zero
    /* EE2C 8001E62C 0380013C */  lui        $at, %hi(D_80030898)
    /* EE30 8001E630 980820AC */  sw         $zero, %lo(D_80030898)($at)
    /* EE34 8001E634 0380013C */  lui        $at, %hi(D_8003089C)
    /* EE38 8001E638 6579000C */  jal        _SpuDataCallback
    /* EE3C 8001E63C 9C0820AC */   sw        $zero, %lo(D_8003089C)($at)
    /* EE40 8001E640 0380043C */  lui        $a0, %hi(D_800307E8)
    /* EE44 8001E644 E807848C */  lw         $a0, %lo(D_800307E8)($a0)
    /* EE48 8001E648 399A000C */  jal        CloseEvent
    /* EE4C 8001E64C 00000000 */   nop
    /* EE50 8001E650 0380043C */  lui        $a0, %hi(D_800307E8)
    /* EE54 8001E654 E807848C */  lw         $a0, %lo(D_800307E8)($a0)
    /* EE58 8001E658 499A000C */  jal        DisableEvent
    /* EE5C 8001E65C 00000000 */   nop
    /* EE60 8001E660 619A000C */  jal        ExitCriticalSection
    /* EE64 8001E664 00000000 */   nop
  .L8001E668:
    /* EE68 8001E668 1000BF8F */  lw         $ra, 0x10($sp)
    /* EE6C 8001E66C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* EE70 8001E670 0800E003 */  jr         $ra
    /* EE74 8001E674 00000000 */   nop
endlabel SpuQuit
    /* EE78 8001E678 00000000 */  nop
    /* EE7C 8001E67C 00000000 */  nop
    /* EE80 8001E680 00000000 */  nop
