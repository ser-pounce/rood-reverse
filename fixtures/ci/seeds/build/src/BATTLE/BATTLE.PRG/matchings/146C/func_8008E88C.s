nonmatching func_8008E88C, 0x6C

glabel func_8008E88C
    /* 2608C 8008E88C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26090 8008E890 0F80023C */  lui        $v0, %hi(D_800F1DAC)
    /* 26094 8008E894 AC1D40AC */  sw         $zero, %lo(D_800F1DAC)($v0)
    /* 26098 8008E898 0F80023C */  lui        $v0, %hi(D_800F1DB0)
    /* 2609C 8008E89C B01D40AC */  sw         $zero, %lo(D_800F1DB0)($v0)
    /* 260A0 8008E8A0 0F80023C */  lui        $v0, %hi(D_800F1DCC)
    /* 260A4 8008E8A4 CC1D40AC */  sw         $zero, %lo(D_800F1DCC)($v0)
    /* 260A8 8008E8A8 0F80023C */  lui        $v0, %hi(D_800F1DD0)
    /* 260AC 8008E8AC D01D40AC */  sw         $zero, %lo(D_800F1DD0)($v0)
    /* 260B0 8008E8B0 0F80023C */  lui        $v0, %hi(D_800F1DD4)
    /* 260B4 8008E8B4 D41D40AC */  sw         $zero, %lo(D_800F1DD4)($v0)
    /* 260B8 8008E8B8 0F80023C */  lui        $v0, %hi(D_800F1DC9)
    /* 260BC 8008E8BC 0F80033C */  lui        $v1, %hi(D_800F1DBC)
    /* 260C0 8008E8C0 C91D40A0 */  sb         $zero, %lo(D_800F1DC9)($v0)
    /* 260C4 8008E8C4 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 260C8 8008E8C8 BC1D62A4 */  sh         $v0, %lo(D_800F1DBC)($v1)
    /* 260CC 8008E8CC 0F80023C */  lui        $v0, %hi(D_800F1DCA)
    /* 260D0 8008E8D0 0F80033C */  lui        $v1, %hi(D_800F1DCB)
    /* 260D4 8008E8D4 CA1D40A0 */  sb         $zero, %lo(D_800F1DCA)($v0)
    /* 260D8 8008E8D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 260DC 8008E8DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 260E0 8008E8E0 4E3A020C */  jal        func_8008E938
    /* 260E4 8008E8E4 CB1D62A0 */   sb        $v0, %lo(D_800F1DCB)($v1)
    /* 260E8 8008E8E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 260EC 8008E8EC 00000000 */  nop
    /* 260F0 8008E8F0 0800E003 */  jr         $ra
    /* 260F4 8008E8F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008E88C
