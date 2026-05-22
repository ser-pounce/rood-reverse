nonmatching func_801080C8, 0x64

glabel func_801080C8
    /* 58C8 801080C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 58CC 801080CC 7FFF063C */  lui        $a2, (0xFF7FFFFF >> 16)
    /* 58D0 801080D0 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* 58D4 801080D4 FFFFC634 */  ori        $a2, $a2, (0xFF7FFFFF & 0xFFFF)
    /* 58D8 801080D8 3C45448C */  lw         $a0, %lo(D_800F453C)($v0)
    /* 58DC 801080DC 21000324 */  addiu      $v1, $zero, 0x21
    /* 58E0 801080E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 58E4 801080E4 0800828C */  lw         $v0, 0x8($a0)
    /* 58E8 801080E8 04078524 */  addiu      $a1, $a0, 0x704
    /* 58EC 801080EC B80583A0 */  sb         $v1, 0x5B8($a0)
    /* 58F0 801080F0 24104600 */  and        $v0, $v0, $a2
    /* 58F4 801080F4 02B4020C */  jal        func_800AD008
    /* 58F8 801080F8 080082AC */   sw        $v0, 0x8($a0)
    /* 58FC 801080FC 01000424 */  addiu      $a0, $zero, 0x1
    /* 5900 80108100 1F82020C */  jal        func_800A087C
    /* 5904 80108104 03000524 */   addiu     $a1, $zero, 0x3
    /* 5908 80108108 01000424 */  addiu      $a0, $zero, 0x1
    /* 590C 8010810C 21280000 */  addu       $a1, $zero, $zero
    /* 5910 80108110 2130A000 */  addu       $a2, $a1, $zero
    /* 5914 80108114 507E020C */  jal        func_8009F940
    /* 5918 80108118 2138A000 */   addu      $a3, $a1, $zero
    /* 591C 8010811C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5920 80108120 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 5924 80108124 0800E003 */  jr         $ra
    /* 5928 80108128 00000000 */   nop
endlabel func_801080C8
