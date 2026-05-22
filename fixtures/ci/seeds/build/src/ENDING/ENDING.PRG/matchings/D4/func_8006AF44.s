nonmatching func_8006AF44, 0x20

glabel func_8006AF44
    /* 2744 8006AF44 0E80033C */  lui        $v1, %hi(D_800DB72C)
    /* 2748 8006AF48 01000224 */  addiu      $v0, $zero, 0x1
    /* 274C 8006AF4C 2CB762A0 */  sb         $v0, %lo(D_800DB72C)($v1)
    /* 2750 8006AF50 0E80023C */  lui        $v0, %hi(D_800DC1A0)
    /* 2754 8006AF54 A0C145AC */  sw         $a1, %lo(D_800DC1A0)($v0)
    /* 2758 8006AF58 0E80023C */  lui        $v0, %hi(D_800DC1A4)
    /* 275C 8006AF5C 0800E003 */  jr         $ra
    /* 2760 8006AF60 A4C144AC */   sw        $a0, %lo(D_800DC1A4)($v0)
endlabel func_8006AF44
