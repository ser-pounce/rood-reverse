nonmatching DS_reset_members, 0x18

glabel DS_reset_members
    /* 14F2C 8002472C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14F30 80024730 03000324 */  addiu      $v1, $zero, 0x3
    /* 14F34 80024734 0380023C */  lui        $v0, %hi(D_8003267C)
    /* 14F38 80024738 7C264224 */  addiu      $v0, $v0, %lo(D_8003267C)
    /* 14F3C 8002473C 08004424 */  addiu      $a0, $v0, 0x8
    /* 14F40 80024740 1400BFAF */  sw         $ra, 0x14($sp)
endlabel DS_reset_members
