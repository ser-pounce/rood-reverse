nonmatching Sound_Cmd_21_unk, 0x2C

glabel Sound_Cmd_21_unk
    /* 7C6C 8001746C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C70 80017470 21108000 */  addu       $v0, $a0, $zero
    /* 7C74 80017474 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C78 80017478 0000448C */  lw         $a0, 0x0($v0)
    /* 7C7C 8001747C 0400458C */  lw         $a1, 0x4($v0)
    /* 7C80 80017480 7158000C */  jal        func_800161C4
    /* 7C84 80017484 00000000 */   nop
    /* 7C88 80017488 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C8C 8001748C 00000000 */  nop
    /* 7C90 80017490 0800E003 */  jr         $ra
    /* 7C94 80017494 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_21_unk
