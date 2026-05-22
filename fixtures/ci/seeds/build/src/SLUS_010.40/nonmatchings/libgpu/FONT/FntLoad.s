nonmatching FntLoad, 0xA0

glabel FntLoad
    /* 18094 80027894 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 18098 80027898 2800B2AF */  sw         $s2, 0x28($sp)
    /* 1809C 8002789C 21908000 */  addu       $s2, $a0, $zero
    /* 180A0 800278A0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 180A4 800278A4 2188A000 */  addu       $s1, $a1, $zero
    /* 180A8 800278A8 2000B0AF */  sw         $s0, 0x20($sp)
    /* 180AC 800278AC 0380103C */  lui        $s0, %hi(D_800329EC)
    /* 180B0 800278B0 EC291026 */  addiu      $s0, $s0, %lo(D_800329EC)
    /* 180B4 800278B4 21200002 */  addu       $a0, $s0, $zero
    /* 180B8 800278B8 21284002 */  addu       $a1, $s2, $zero
    /* 180BC 800278BC 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 180C0 800278C0 C1AC000C */  jal        LoadClut2
    /* 180C4 800278C4 80002626 */   addiu     $a2, $s1, 0x80
    /* 180C8 800278C8 00020426 */  addiu      $a0, $s0, 0x200
    /* 180CC 800278CC 21280000 */  addu       $a1, $zero, $zero
    /* 180D0 800278D0 21300000 */  addu       $a2, $zero, $zero
    /* 180D4 800278D4 0480013C */  lui        $at, %hi(D_8003E2A2)
    /* 180D8 800278D8 A2E222A4 */  sh         $v0, %lo(D_8003E2A2)($at)
    /* 180DC 800278DC 80000224 */  addiu      $v0, $zero, 0x80
    /* 180E0 800278E0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 180E4 800278E4 20000224 */  addiu      $v0, $zero, 0x20
    /* 180E8 800278E8 21384002 */  addu       $a3, $s2, $zero
    /* 180EC 800278EC 1000B1AF */  sw         $s1, 0x10($sp)
    /* 180F0 800278F0 85AC000C */  jal        LoadTPage
    /* 180F4 800278F4 1800A2AF */   sw        $v0, 0x18($sp)
    /* 180F8 800278F8 0380043C */  lui        $a0, %hi(D_80032864)
    /* 180FC 800278FC 64288424 */  addiu      $a0, $a0, %lo(D_80032864)
    /* 18100 80027900 21280000 */  addu       $a1, $zero, $zero
    /* 18104 80027904 0480013C */  lui        $at, %hi(D_8003E2A0)
    /* 18108 80027908 A0E222A4 */  sh         $v0, %lo(D_8003E2A0)($at)
    /* 1810C 8002790C 0380013C */  lui        $at, %hi(D_800329E4)
    /* 18110 80027910 E42920AC */  sw         $zero, %lo(D_800329E4)($at)
    /* 18114 80027914 AD9B000C */  jal        memset
    /* 18118 80027918 80010624 */   addiu     $a2, $zero, 0x180
    /* 1811C 8002791C 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 18120 80027920 2800B28F */  lw         $s2, 0x28($sp)
    /* 18124 80027924 2400B18F */  lw         $s1, 0x24($sp)
    /* 18128 80027928 2000B08F */  lw         $s0, 0x20($sp)
    /* 1812C 8002792C 0800E003 */  jr         $ra
    /* 18130 80027930 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel FntLoad
