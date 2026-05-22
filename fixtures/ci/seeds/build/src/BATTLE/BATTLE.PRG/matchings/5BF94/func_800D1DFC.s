nonmatching func_800D1DFC, 0x24

glabel func_800D1DFC
    /* 695FC 800D1DFC 06008010 */  beqz       $a0, .L800D1E18
    /* 69600 800D1E00 0F80023C */   lui       $v0, %hi(D_800F5518)
    /* 69604 800D1E04 18554390 */  lbu        $v1, %lo(D_800F5518)($v0)
    /* 69608 800D1E08 27200400 */  nor        $a0, $zero, $a0
    /* 6960C 800D1E0C 24186400 */  and        $v1, $v1, $a0
    /* 69610 800D1E10 0800E003 */  jr         $ra
    /* 69614 800D1E14 185543A0 */   sb        $v1, %lo(D_800F5518)($v0)
  .L800D1E18:
    /* 69618 800D1E18 0800E003 */  jr         $ra
    /* 6961C 800D1E1C 185540A0 */   sb        $zero, %lo(D_800F5518)($v0)
endlabel func_800D1DFC
