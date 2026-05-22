nonmatching func_800B64A8, 0x24

glabel func_800B64A8
    /* 4DCA8 800B64A8 FCFFBD27 */  addiu      $sp, $sp, -0x4
    /* 4DCAC 800B64AC 0000BFAF */  sw         $ra, 0x0($sp)
    /* 4DCB0 800B64B0 33D9020C */  jal        func_800B64CC
    /* 4DCB4 800B64B4 2138A000 */   addu      $a3, $a1, $zero
    /* 4DCB8 800B64B8 00000334 */  ori        $v1, $zero, 0x0
    /* 4DCBC 800B64BC 481843A0 */  sb         $v1, 0x1848($v0)
    /* 4DCC0 800B64C0 0000BF8F */  lw         $ra, 0x0($sp)
    /* 4DCC4 800B64C4 0400BD27 */  addiu      $sp, $sp, 0x4
    /* 4DCC8 800B64C8 0800E003 */  jr         $ra
endlabel func_800B64A8
