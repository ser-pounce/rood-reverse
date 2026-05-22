nonmatching func_800C8E04, 0x44

glabel func_800C8E04
    /* 60604 800C8E04 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 60608 800C8E08 04000224 */  addiu      $v0, $zero, 0x4
    /* 6060C 800C8E0C 002A0400 */  sll        $a1, $a0, 8
    /* 60610 800C8E10 07000424 */  addiu      $a0, $zero, 0x7
    /* 60614 800C8E14 2528A200 */  or         $a1, $a1, $v0
    /* 60618 800C8E18 21300000 */  addu       $a2, $zero, $zero
    /* 6061C 800C8E1C 01000724 */  addiu      $a3, $zero, 0x1
    /* 60620 800C8E20 2000BFAF */  sw         $ra, 0x20($sp)
    /* 60624 800C8E24 1000A0AF */  sw         $zero, 0x10($sp)
    /* 60628 800C8E28 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6062C 800C8E2C 1800A0AF */  sw         $zero, 0x18($sp)
    /* 60630 800C8E30 C233030C */  jal        vs_battle_initTextBox
    /* 60634 800C8E34 1C00A0AF */   sw        $zero, 0x1C($sp)
    /* 60638 800C8E38 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6063C 800C8E3C 00000000 */  nop
    /* 60640 800C8E40 0800E003 */  jr         $ra
    /* 60644 800C8E44 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800C8E04
