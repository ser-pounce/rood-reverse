nonmatching func_800463BC, 0x90

glabel func_800463BC
    /* 36BBC 800463BC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 36BC0 800463C0 3000B2AF */  sw         $s2, 0x30($sp)
    /* 36BC4 800463C4 21908000 */  addu       $s2, $a0, $zero
    /* 36BC8 800463C8 3400B3AF */  sw         $s3, 0x34($sp)
    /* 36BCC 800463CC 2198A000 */  addu       $s3, $a1, $zero
    /* 36BD0 800463D0 3800B4AF */  sw         $s4, 0x38($sp)
    /* 36BD4 800463D4 21A0C000 */  addu       $s4, $a2, $zero
    /* 36BD8 800463D8 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 36BDC 800463DC 2188E000 */  addu       $s1, $a3, $zero
    /* 36BE0 800463E0 2800B0AF */  sw         $s0, 0x28($sp)
    /* 36BE4 800463E4 801F103C */  lui        $s0, %hi(D_1F800014_mat)
    /* 36BE8 800463E8 14001026 */  addiu      $s0, $s0, %lo(D_1F800014_mat)
    /* 36BEC 800463EC 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 36BF0 800463F0 6605010C */  jal        SetRotMatrix
    /* 36BF4 800463F4 21200002 */   addu      $a0, $s0, $zero
    /* 36BF8 800463F8 5E05010C */  jal        SetTransMatrix
    /* 36BFC 800463FC 21200002 */   addu      $a0, $s0, $zero
    /* 36C00 80046400 21202002 */  addu       $a0, $s1, $zero
    /* 36C04 80046404 1800A527 */  addiu      $a1, $sp, 0x18
    /* 36C08 80046408 1C00A627 */  addiu      $a2, $sp, 0x1C
    /* 36C0C 8004640C 0506010C */  jal        RotTransPers
    /* 36C10 80046410 2000A727 */   addiu     $a3, $sp, 0x20
    /* 36C14 80046414 21204002 */  addu       $a0, $s2, $zero
    /* 36C18 80046418 21286002 */  addu       $a1, $s3, $zero
    /* 36C1C 8004641C 1800A78F */  lw         $a3, 0x18($sp)
    /* 36C20 80046420 21308002 */  addu       $a2, $s4, $zero
    /* 36C24 80046424 C418010C */  jal        func_80046310
    /* 36C28 80046428 1000A2AF */   sw        $v0, 0x10($sp)
    /* 36C2C 8004642C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 36C30 80046430 3800B48F */  lw         $s4, 0x38($sp)
    /* 36C34 80046434 3400B38F */  lw         $s3, 0x34($sp)
    /* 36C38 80046438 3000B28F */  lw         $s2, 0x30($sp)
    /* 36C3C 8004643C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 36C40 80046440 2800B08F */  lw         $s0, 0x28($sp)
    /* 36C44 80046444 0800E003 */  jr         $ra
    /* 36C48 80046448 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800463BC
