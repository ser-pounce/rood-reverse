nonmatching _SpuInit, 0xE8

glabel _SpuInit
    /* E0F4 8001D8F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E0F8 8001D8F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* E0FC 8001D8FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* E100 8001D900 357E000C */  jal        ResetCallback
    /* E104 8001D904 21808000 */   addu      $s0, $a0, $zero
    /* E108 8001D908 9576000C */  jal        _spu_init
    /* E10C 8001D90C 21200002 */   addu      $a0, $s0, $zero
    /* E110 8001D910 08000016 */  bnez       $s0, .L8001D934
    /* E114 8001D914 00C00434 */   ori       $a0, $zero, 0xC000
    /* E118 8001D918 17000324 */  addiu      $v1, $zero, 0x17
    /* E11C 8001D91C 0380023C */  lui        $v0, %hi(D_8003084A)
    /* E120 8001D920 4A084224 */  addiu      $v0, $v0, %lo(D_8003084A)
  .L8001D924:
    /* E124 8001D924 000044A4 */  sh         $a0, 0x0($v0)
    /* E128 8001D928 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* E12C 8001D92C FDFF6104 */  bgez       $v1, .L8001D924
    /* E130 8001D930 FEFF4224 */   addiu     $v0, $v0, -0x2
  .L8001D934:
    /* E134 8001D934 7776000C */  jal        SpuStart
    /* E138 8001D938 00000000 */   nop
    /* E13C 8001D93C D1000424 */  addiu      $a0, $zero, 0xD1
    /* E140 8001D940 0380023C */  lui        $v0, %hi(D_80030804)
    /* E144 8001D944 04084224 */  addiu      $v0, $v0, %lo(D_80030804)
    /* E148 8001D948 0380053C */  lui        $a1, %hi(D_80030CD0)
    /* E14C 8001D94C D00CA58C */  lw         $a1, %lo(D_80030CD0)($a1)
    /* E150 8001D950 0380013C */  lui        $at, %hi(D_800307F4)
    /* E154 8001D954 F40720AC */  sw         $zero, %lo(D_800307F4)($at)
    /* E158 8001D958 0380013C */  lui        $at, %hi(D_800307F8)
    /* E15C 8001D95C F80720AC */  sw         $zero, %lo(D_800307F8)($at)
    /* E160 8001D960 000040AC */  sw         $zero, 0x0($v0)
    /* E164 8001D964 040040A4 */  sh         $zero, 0x4($v0)
    /* E168 8001D968 060040A4 */  sh         $zero, 0x6($v0)
    /* E16C 8001D96C 080040AC */  sw         $zero, 0x8($v0)
    /* E170 8001D970 0C0040AC */  sw         $zero, 0xC($v0)
    /* E174 8001D974 0380013C */  lui        $at, %hi(D_800307FC)
    /* E178 8001D978 FC0725AC */  sw         $a1, %lo(D_800307FC)($at)
    /* E17C 8001D97C D878000C */  jal        _spu_FsetRXX
    /* E180 8001D980 21300000 */   addu      $a2, $zero, $zero
    /* E184 8001D984 0380013C */  lui        $at, %hi(D_800308C0)
    /* E188 8001D988 C00820AC */  sw         $zero, %lo(D_800308C0)($at)
    /* E18C 8001D98C 0380013C */  lui        $at, %hi(D_800308C4)
    /* E190 8001D990 C40820AC */  sw         $zero, %lo(D_800308C4)($at)
    /* E194 8001D994 0380013C */  lui        $at, %hi(D_800308C8)
    /* E198 8001D998 C80820AC */  sw         $zero, %lo(D_800308C8)($at)
    /* E19C 8001D99C 0380013C */  lui        $at, %hi(D_800307F0)
    /* E1A0 8001D9A0 F00720AC */  sw         $zero, %lo(D_800307F0)($at)
    /* E1A4 8001D9A4 0380013C */  lui        $at, %hi(D_8003087C)
    /* E1A8 8001D9A8 7C0820AC */  sw         $zero, %lo(D_8003087C)($at)
    /* E1AC 8001D9AC 0380013C */  lui        $at, %hi(D_800307EC)
    /* E1B0 8001D9B0 EC0720AC */  sw         $zero, %lo(D_800307EC)($at)
    /* E1B4 8001D9B4 0380013C */  lui        $at, %hi(D_80030818)
    /* E1B8 8001D9B8 180820AC */  sw         $zero, %lo(D_80030818)($at)
    /* E1BC 8001D9BC 0380013C */  lui        $at, %hi(D_80030814)
    /* E1C0 8001D9C0 140820AC */  sw         $zero, %lo(D_80030814)($at)
    /* E1C4 8001D9C4 0380013C */  lui        $at, %hi(D_8003084C)
    /* E1C8 8001D9C8 4C0820AC */  sw         $zero, %lo(D_8003084C)($at)
    /* E1CC 8001D9CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* E1D0 8001D9D0 1000B08F */  lw         $s0, 0x10($sp)
    /* E1D4 8001D9D4 0800E003 */  jr         $ra
    /* E1D8 8001D9D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _SpuInit
