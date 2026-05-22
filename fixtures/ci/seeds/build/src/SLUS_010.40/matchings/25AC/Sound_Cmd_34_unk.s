nonmatching Sound_Cmd_34_unk, 0x4C

glabel Sound_Cmd_34_unk
    /* 7A08 80017208 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7A0C 8001720C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7A10 80017210 0000858C */  lw         $a1, 0x0($a0)
    /* 7A14 80017214 0400868C */  lw         $a2, 0x4($a0)
    /* 7A18 80017218 00040224 */  addiu      $v0, $zero, 0x400
    /* 7A1C 8001721C 000082AC */  sw         $v0, 0x0($a0)
    /* 7A20 80017220 0001023C */  lui        $v0, (0x1000000 >> 16)
    /* 7A24 80017224 040082AC */  sw         $v0, 0x4($a0)
    /* 7A28 80017228 80000224 */  addiu      $v0, $zero, 0x80
    /* 7A2C 8001722C 080082AC */  sw         $v0, 0x8($a0)
    /* 7A30 80017230 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 7A34 80017234 21380000 */  addu       $a3, $zero, $zero
    /* 7A38 80017238 0C0082AC */  sw         $v0, 0xC($a0)
    /* 7A3C 8001723C D159000C */  jal        Sound_PlaySfxProgram
    /* 7A40 80017240 100080AC */   sw        $zero, 0x10($a0)
    /* 7A44 80017244 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7A48 80017248 00000000 */  nop
    /* 7A4C 8001724C 0800E003 */  jr         $ra
    /* 7A50 80017250 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_34_unk
