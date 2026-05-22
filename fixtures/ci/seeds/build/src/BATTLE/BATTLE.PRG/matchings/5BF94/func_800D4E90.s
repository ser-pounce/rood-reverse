nonmatching func_800D4E90, 0x30

glabel func_800D4E90
    /* 6C690 800D4E90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C694 800D4E94 21288000 */  addu       $a1, $a0, $zero
    /* 6C698 800D4E98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C69C 800D4E9C 4C0DA28C */  lw         $v0, 0xD4C($a1)
    /* 6C6A0 800D4EA0 00000000 */  nop
    /* 6C6A4 800D4EA4 0400448C */  lw         $a0, 0x4($v0)
    /* 6C6A8 800D4EA8 B751030C */  jal        func_800D46DC
    /* 6C6AC 800D4EAC 0100842C */   sltiu     $a0, $a0, 0x1
    /* 6C6B0 800D4EB0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C6B4 800D4EB4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C6B8 800D4EB8 0800E003 */  jr         $ra
    /* 6C6BC 800D4EBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4E90
