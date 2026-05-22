nonmatching func_800760CC, 0x1D0

glabel func_800760CC
    /* D8CC 800760CC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* D8D0 800760D0 2000B2AF */  sw         $s2, 0x20($sp)
    /* D8D4 800760D4 21908000 */  addu       $s2, $a0, $zero
    /* D8D8 800760D8 C2271200 */  srl        $a0, $s2, 31
    /* D8DC 800760DC 21204402 */  addu       $a0, $s2, $a0
    /* D8E0 800760E0 43200400 */  sra        $a0, $a0, 1
    /* D8E4 800760E4 2400B3AF */  sw         $s3, 0x24($sp)
    /* D8E8 800760E8 F0FFB324 */  addiu      $s3, $a1, -0x10
    /* D8EC 800760EC C22F1300 */  srl        $a1, $s3, 31
    /* D8F0 800760F0 21286502 */  addu       $a1, $s3, $a1
    /* D8F4 800760F4 3000B6AF */  sw         $s6, 0x30($sp)
    /* D8F8 800760F8 5000B68F */  lw         $s6, 0x50($sp)
    /* D8FC 800760FC 43280500 */  sra        $a1, $a1, 1
    /* D900 80076100 3400B7AF */  sw         $s7, 0x34($sp)
    /* D904 80076104 5400B78F */  lw         $s7, 0x54($sp)
    /* D908 80076108 1000A524 */  addiu      $a1, $a1, 0x10
    /* D90C 8007610C 1800B0AF */  sw         $s0, 0x18($sp)
    /* D910 80076110 2180C000 */  addu       $s0, $a2, $zero
    /* D914 80076114 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* D918 80076118 21A8E000 */  addu       $s5, $a3, $zero
    /* D91C 8007611C 3800BFAF */  sw         $ra, 0x38($sp)
    /* D920 80076120 2800B4AF */  sw         $s4, 0x28($sp)
    /* D924 80076124 5005010C */  jal        SetGeomOffset
    /* D928 80076128 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* D92C 8007612C 4D05010C */  jal        SetGeomScreen
    /* D930 80076130 21200002 */   addu      $a0, $s0, $zero
    /* D934 80076134 0680103C */  lui        $s0, %hi(vs_main_drawEnv)
    /* D938 80076138 D0E01026 */  addiu      $s0, $s0, %lo(vs_main_drawEnv)
    /* D93C 8007613C 21200002 */  addu       $a0, $s0, $zero
    /* D940 80076140 21280000 */  addu       $a1, $zero, $zero
    /* D944 80076144 2130A000 */  addu       $a2, $a1, $zero
    /* D948 80076148 21384002 */  addu       $a3, $s2, $zero
    /* D94C 8007614C DDAC000C */  jal        SetDefDrawEnv
    /* D950 80076150 1000B3AF */   sw        $s3, 0x10($sp)
    /* D954 80076154 0680113C */  lui        $s1, %hi(vs_main_dispEnv)
    /* D958 80076158 88E13126 */  addiu      $s1, $s1, %lo(vs_main_dispEnv)
    /* D95C 8007615C 21202002 */  addu       $a0, $s1, $zero
    /* D960 80076160 21284002 */  addu       $a1, $s2, $zero
    /* D964 80076164 21300000 */  addu       $a2, $zero, $zero
    /* D968 80076168 21384002 */  addu       $a3, $s2, $zero
    /* D96C 8007616C 0DAD000C */  jal        SetDefDispEnv
    /* D970 80076170 1000B3AF */   sw        $s3, 0x10($sp)
    /* D974 80076174 5C001426 */  addiu      $s4, $s0, 0x5C
    /* D978 80076178 21208002 */  addu       $a0, $s4, $zero
    /* D97C 8007617C 21284002 */  addu       $a1, $s2, $zero
    /* D980 80076180 21300000 */  addu       $a2, $zero, $zero
    /* D984 80076184 21384002 */  addu       $a3, $s2, $zero
    /* D988 80076188 DDAC000C */  jal        SetDefDrawEnv
    /* D98C 8007618C 1000B3AF */   sw        $s3, 0x10($sp)
    /* D990 80076190 14002426 */  addiu      $a0, $s1, 0x14
    /* D994 80076194 21280000 */  addu       $a1, $zero, $zero
    /* D998 80076198 2130A000 */  addu       $a2, $a1, $zero
    /* D99C 8007619C 21384002 */  addu       $a3, $s2, $zero
    /* D9A0 800761A0 0DAD000C */  jal        SetDefDispEnv
    /* D9A4 800761A4 1000B3AF */   sw        $s3, 0x10($sp)
    /* D9A8 800761A8 08002226 */  addiu      $v0, $s1, 0x8
    /* D9AC 800761AC 08000524 */  addiu      $a1, $zero, 0x8
    /* D9B0 800761B0 00010424 */  addiu      $a0, $zero, 0x100
    /* D9B4 800761B4 E0000324 */  addiu      $v1, $zero, 0xE0
    /* D9B8 800761B8 080020A6 */  sh         $zero, 0x8($s1)
    /* D9BC 800761BC 020045A4 */  sh         $a1, 0x2($v0)
    /* D9C0 800761C0 040044A4 */  sh         $a0, 0x4($v0)
    /* D9C4 800761C4 060043A4 */  sh         $v1, 0x6($v0)
    /* D9C8 800761C8 1C002226 */  addiu      $v0, $s1, 0x1C
    /* D9CC 800761CC 1C0020A6 */  sh         $zero, 0x1C($s1)
    /* D9D0 800761D0 020045A4 */  sh         $a1, 0x2($v0)
    /* D9D4 800761D4 040044A4 */  sh         $a0, 0x4($v0)
    /* D9D8 800761D8 060043A4 */  sh         $v1, 0x6($v0)
    /* D9DC 800761DC 0680023C */  lui        $v0, %hi(D_8005DFD4)
    /* D9E0 800761E0 D4DF40A4 */  sh         $zero, %lo(D_8005DFD4)($v0)
    /* D9E4 800761E4 0680023C */  lui        $v0, %hi(D_8005DFD8)
    /* D9E8 800761E8 D8DF40A4 */  sh         $zero, %lo(D_8005DFD8)($v0)
    /* D9EC 800761EC 0680023C */  lui        $v0, %hi(D_8005DFD6)
    /* D9F0 800761F0 D6DF52A4 */  sh         $s2, %lo(D_8005DFD6)($v0)
    /* D9F4 800761F4 0680123C */  lui        $s2, %hi(vs_main_frameBuf)
    /* D9F8 800761F8 10E2438E */  lw         $v1, %lo(vs_main_frameBuf)($s2)
    /* D9FC 800761FC 0680023C */  lui        $v0, %hi(D_8005DFDA)
    /* DA00 80076200 DADF53A4 */  sh         $s3, %lo(D_8005DFDA)($v0)
    /* DA04 80076204 01000224 */  addiu      $v0, $zero, 0x1
    /* DA08 80076208 720002A2 */  sb         $v0, 0x72($s0)
    /* DA0C 8007620C 160002A2 */  sb         $v0, 0x16($s0)
    /* DA10 80076210 730000A2 */  sb         $zero, 0x73($s0)
    /* DA14 80076214 170000A2 */  sb         $zero, 0x17($s0)
    /* DA18 80076218 740000A2 */  sb         $zero, 0x74($s0)
    /* DA1C 8007621C 180000A2 */  sb         $zero, 0x18($s0)
    /* DA20 80076220 190015A2 */  sb         $s5, 0x19($s0)
    /* DA24 80076224 190095A2 */  sb         $s5, 0x19($s4)
    /* DA28 80076228 80200300 */  sll        $a0, $v1, 2
    /* DA2C 8007622C 21208300 */  addu       $a0, $a0, $v1
    /* DA30 80076230 80200400 */  sll        $a0, $a0, 2
    /* DA34 80076234 21209100 */  addu       $a0, $a0, $s1
    /* DA38 80076238 1A0016A2 */  sb         $s6, 0x1A($s0)
    /* DA3C 8007623C 1B0017A2 */  sb         $s7, 0x1B($s0)
    /* DA40 80076240 1A0096A2 */  sb         $s6, 0x1A($s4)
    /* DA44 80076244 A0A3000C */  jal        PutDispEnv
    /* DA48 80076248 1B0097A2 */   sb        $s7, 0x1B($s4)
    /* DA4C 8007624C 10E2428E */  lw         $v0, %lo(vs_main_frameBuf)($s2)
    /* DA50 80076250 00000000 */  nop
    /* DA54 80076254 40200200 */  sll        $a0, $v0, 1
    /* DA58 80076258 21208200 */  addu       $a0, $a0, $v0
    /* DA5C 8007625C C0200400 */  sll        $a0, $a0, 3
    /* DA60 80076260 23208200 */  subu       $a0, $a0, $v0
    /* DA64 80076264 80200400 */  sll        $a0, $a0, 2
    /* DA68 80076268 2DA3000C */  jal        PutDrawEnv
    /* DA6C 8007626C 21209000 */   addu      $a0, $a0, $s0
    /* DA70 80076270 3800BF8F */  lw         $ra, 0x38($sp)
    /* DA74 80076274 3400B78F */  lw         $s7, 0x34($sp)
    /* DA78 80076278 3000B68F */  lw         $s6, 0x30($sp)
    /* DA7C 8007627C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* DA80 80076280 2800B48F */  lw         $s4, 0x28($sp)
    /* DA84 80076284 2400B38F */  lw         $s3, 0x24($sp)
    /* DA88 80076288 2000B28F */  lw         $s2, 0x20($sp)
    /* DA8C 8007628C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* DA90 80076290 1800B08F */  lw         $s0, 0x18($sp)
    /* DA94 80076294 0800E003 */  jr         $ra
    /* DA98 80076298 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800760CC
