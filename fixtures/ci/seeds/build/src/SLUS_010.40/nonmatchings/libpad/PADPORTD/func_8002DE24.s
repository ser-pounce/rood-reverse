nonmatching func_8002DE24, 0x68

glabel func_8002DE24
    /* 1E624 8002DE24 49008290 */  lbu        $v0, 0x49($a0)
    /* 1E628 8002DE28 00000000 */  nop
    /* 1E62C 8002DE2C 15004010 */  beqz       $v0, .L8002DE84
    /* 1E630 8002DE30 00000000 */   nop
    /* 1E634 8002DE34 5D008324 */  addiu      $v1, $a0, 0x5D
    /* 1E638 8002DE38 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 1E63C 8002DE3C 05000224 */  addiu      $v0, $zero, 0x5
    /* 1E640 8002DE40 490080A0 */  sb         $zero, 0x49($a0)
    /* 1E644 8002DE44 460080A0 */  sb         $zero, 0x46($a0)
    /* 1E648 8002DE48 E60080A4 */  sh         $zero, 0xE6($a0)
    /* 1E64C 8002DE4C 140080AC */  sw         $zero, 0x14($a0)
    /* 1E650 8002DE50 180080AC */  sw         $zero, 0x18($a0)
    /* 1E654 8002DE54 E30080A0 */  sb         $zero, 0xE3($a0)
    /* 1E658 8002DE58 E40080A0 */  sb         $zero, 0xE4($a0)
    /* 1E65C 8002DE5C E60080A4 */  sh         $zero, 0xE6($a0)
    /* 1E660 8002DE60 E90080A0 */  sb         $zero, 0xE9($a0)
    /* 1E664 8002DE64 EA0080A0 */  sb         $zero, 0xEA($a0)
    /* 1E668 8002DE68 000080AC */  sw         $zero, 0x0($a0)
    /* 1E66C 8002DE6C 040080AC */  sw         $zero, 0x4($a0)
    /* 1E670 8002DE70 080080AC */  sw         $zero, 0x8($a0)
  .L8002DE74:
    /* 1E674 8002DE74 000065A0 */  sb         $a1, 0x0($v1)
    /* 1E678 8002DE78 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1E67C 8002DE7C FDFF4104 */  bgez       $v0, .L8002DE74
    /* 1E680 8002DE80 01006324 */   addiu     $v1, $v1, 0x1
  .L8002DE84:
    /* 1E684 8002DE84 0800E003 */  jr         $ra
    /* 1E688 8002DE88 00000000 */   nop
endlabel func_8002DE24
