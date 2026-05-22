nonmatching func_801035E0, 0x28

glabel func_801035E0
    /* DE0 801035E0 1180023C */  lui        $v0, %hi(D_8010BC98)
    /* DE4 801035E4 98BC428C */  lw         $v0, %lo(D_8010BC98)($v0)
    /* DE8 801035E8 00000000 */  nop
    /* DEC 801035EC 04004014 */  bnez       $v0, .L80103600
    /* DF0 801035F0 1180023C */   lui       $v0, %hi(D_8010BC9C)
    /* DF4 801035F4 9CBC428C */  lw         $v0, %lo(D_8010BC9C)($v0)
    /* DF8 801035F8 0800E003 */  jr         $ra
    /* DFC 801035FC 00000000 */   nop
  .L80103600:
    /* E00 80103600 0800E003 */  jr         $ra
    /* E04 80103604 FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel func_801035E0
