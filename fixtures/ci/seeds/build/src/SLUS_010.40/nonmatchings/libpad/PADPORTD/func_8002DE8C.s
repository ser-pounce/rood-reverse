nonmatching func_8002DE8C, 0xF4

glabel func_8002DE8C
    /* 1E68C 8002DE8C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1E690 8002DE90 21288000 */  addu       $a1, $a0, $zero
    /* 1E694 8002DE94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1E698 8002DE98 0480113C */  lui        $s1, %hi(D_8003FCC0)
    /* 1E69C 8002DE9C C0FC3126 */  addiu      $s1, $s1, %lo(D_8003FCC0)
    /* 1E6A0 8002DEA0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1E6A4 8002DEA4 F7FF1324 */  addiu      $s3, $zero, -0x9
    /* 1E6A8 8002DEA8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1E6AC 8002DEAC 0380123C */  lui        $s2, %hi(D_800335F4)
    /* 1E6B0 8002DEB0 F4355226 */  addiu      $s2, $s2, %lo(D_800335F4)
    /* 1E6B4 8002DEB4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1E6B8 8002DEB8 1000B0AF */  sw         $s0, 0x10($sp)
  .L8002DEBC:
    /* 1E6BC 8002DEBC 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1E6C0 8002DEC0 DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1E6C4 8002DEC4 00000000 */  nop
    /* 1E6C8 8002DEC8 00110300 */  sll        $v0, $v1, 4
    /* 1E6CC 8002DECC 23104300 */  subu       $v0, $v0, $v1
    /* 1E6D0 8002DED0 00110200 */  sll        $v0, $v0, 4
    /* 1E6D4 8002DED4 0A00B310 */  beq        $a1, $s3, .L8002DF00
    /* 1E6D8 8002DED8 21805100 */   addu      $s0, $v0, $s1
    /* 1E6DC 8002DEDC 0400A014 */  bnez       $a1, .L8002DEF0
    /* 1E6E0 8002DEE0 80100300 */   sll       $v0, $v1, 2
    /* 1E6E4 8002DEE4 21105200 */  addu       $v0, $v0, $s2
    /* 1E6E8 8002DEE8 C0B70008 */  j          .L8002DF00
    /* 1E6EC 8002DEEC 000040AC */   sw        $zero, 0x0($v0)
  .L8002DEF0:
    /* 1E6F0 8002DEF0 B7B9000C */  jal        func_8002E6DC
    /* 1E6F4 8002DEF4 21200002 */   addu      $a0, $s0, $zero
    /* 1E6F8 8002DEF8 E0B7000C */  jal        func_8002DF80
    /* 1E6FC 8002DEFC 21200002 */   addu      $a0, $s0, $zero
  .L8002DF00:
    /* 1E700 8002DF00 0380023C */  lui        $v0, %hi(D_80033644)
    /* 1E704 8002DF04 4436428C */  lw         $v0, %lo(D_80033644)($v0)
    /* 1E708 8002DF08 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1E70C 8002DF0C DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1E710 8002DF10 0380013C */  lui        $at, %hi(D_800335E0)
    /* 1E714 8002DF14 E03520AC */  sw         $zero, %lo(D_800335E0)($at)
    /* 1E718 8002DF18 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 1E71C 8002DF1C 0380023C */  lui        $v0, %hi(D_800335F0)
    /* 1E720 8002DF20 F035428C */  lw         $v0, %lo(D_800335F0)($v0)
    /* 1E724 8002DF24 01006324 */  addiu      $v1, $v1, 0x1
    /* 1E728 8002DF28 0380013C */  lui        $at, %hi(D_800335DC)
    /* 1E72C 8002DF2C DC3523AC */  sw         $v1, %lo(D_800335DC)($at)
    /* 1E730 8002DF30 2A104300 */  slt        $v0, $v0, $v1
    /* 1E734 8002DF34 08004014 */  bnez       $v0, .L8002DF58
    /* 1E738 8002DF38 01000224 */   addiu     $v0, $zero, 0x1
    /* 1E73C 8002DF3C 00210300 */  sll        $a0, $v1, 4
    /* 1E740 8002DF40 23208300 */  subu       $a0, $a0, $v1
    /* 1E744 8002DF44 00210400 */  sll        $a0, $a0, 4
    /* 1E748 8002DF48 41B0000C */  jal        _padInitSioMode
    /* 1E74C 8002DF4C 21209100 */   addu      $a0, $a0, $s1
    /* 1E750 8002DF50 D7B70008 */  j          .L8002DF5C
    /* 1E754 8002DF54 FFFF0534 */   ori       $a1, $zero, 0xFFFF
  .L8002DF58:
    /* 1E758 8002DF58 FFFF0534 */  ori        $a1, $zero, 0xFFFF
  .L8002DF5C:
    /* 1E75C 8002DF5C D7FF4010 */  beqz       $v0, .L8002DEBC
    /* 1E760 8002DF60 00000000 */   nop
    /* 1E764 8002DF64 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1E768 8002DF68 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1E76C 8002DF6C 1800B28F */  lw         $s2, 0x18($sp)
    /* 1E770 8002DF70 1400B18F */  lw         $s1, 0x14($sp)
    /* 1E774 8002DF74 1000B08F */  lw         $s0, 0x10($sp)
    /* 1E778 8002DF78 0800E003 */  jr         $ra
    /* 1E77C 8002DF7C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002DE8C
