nonmatching func_800BAA04, 0x30

glabel func_800BAA04
    /* 52204 800BAA04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52208 800BAA08 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5220C 800BAA0C C1EF010C */  jal        func_8007BF04
    /* 52210 800BAA10 00000000 */   nop
    /* 52214 800BAA14 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 52218 800BAA18 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 5221C 800BAA1C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52220 800BAA20 02004238 */  xori       $v0, $v0, 0x2
    /* 52224 800BAA24 0100422C */  sltiu      $v0, $v0, 0x1
    /* 52228 800BAA28 80100200 */  sll        $v0, $v0, 2
    /* 5222C 800BAA2C 0800E003 */  jr         $ra
    /* 52230 800BAA30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAA04
