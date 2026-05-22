nonmatching _spu_Fr_, 0xA8

glabel _spu_Fr_
    /* E750 8001DF50 0380023C */  lui        $v0, %hi(D_80030860)
    /* E754 8001DF54 6008428C */  lw         $v0, %lo(D_80030860)($v0)
    /* E758 8001DF58 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* E75C 8001DF5C 1400B1AF */  sw         $s1, 0x14($sp)
    /* E760 8001DF60 21888000 */  addu       $s1, $a0, $zero
    /* E764 8001DF64 1000B0AF */  sw         $s0, 0x10($sp)
    /* E768 8001DF68 1800BFAF */  sw         $ra, 0x18($sp)
    /* E76C 8001DF6C A60145A4 */  sh         $a1, 0x1A6($v0)
    /* E770 8001DF70 4B79000C */  jal        _spu_Fw1ts
    /* E774 8001DF74 2180C000 */   addu      $s0, $a2, $zero
    /* E778 8001DF78 0380033C */  lui        $v1, %hi(D_80030860)
    /* E77C 8001DF7C 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* E780 8001DF80 00000000 */  nop
    /* E784 8001DF84 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* E788 8001DF88 00000000 */  nop
    /* E78C 8001DF8C 30004234 */  ori        $v0, $v0, 0x30
    /* E790 8001DF90 AA0162A4 */  sh         $v0, 0x1AA($v1)
    /* E794 8001DF94 4B79000C */  jal        _spu_Fw1ts
    /* E798 8001DF98 00841000 */   sll       $s0, $s0, 16
    /* E79C 8001DF9C 4179000C */  jal        func_8001E504
    /* E7A0 8001DFA0 00000000 */   nop
    /* E7A4 8001DFA4 0001043C */  lui        $a0, (0x1000200 >> 16)
    /* E7A8 8001DFA8 00028434 */  ori        $a0, $a0, (0x1000200 & 0xFFFF)
    /* E7AC 8001DFAC 0380023C */  lui        $v0, %hi(D_80030864)
    /* E7B0 8001DFB0 6408428C */  lw         $v0, %lo(D_80030864)($v0)
    /* E7B4 8001DFB4 00000000 */  nop
    /* E7B8 8001DFB8 000051AC */  sw         $s1, 0x0($v0)
    /* E7BC 8001DFBC 0380023C */  lui        $v0, %hi(D_80030868)
    /* E7C0 8001DFC0 6808428C */  lw         $v0, %lo(D_80030868)($v0)
    /* E7C4 8001DFC4 10001036 */  ori        $s0, $s0, 0x10
    /* E7C8 8001DFC8 000050AC */  sw         $s0, 0x0($v0)
    /* E7CC 8001DFCC 0380033C */  lui        $v1, %hi(D_8003086C)
    /* E7D0 8001DFD0 6C08638C */  lw         $v1, %lo(D_8003086C)($v1)
    /* E7D4 8001DFD4 01000224 */  addiu      $v0, $zero, 0x1
    /* E7D8 8001DFD8 0380013C */  lui        $at, %hi(D_800308B0)
    /* E7DC 8001DFDC B00822AC */  sw         $v0, %lo(D_800308B0)($at)
    /* E7E0 8001DFE0 000064AC */  sw         $a0, 0x0($v1)
    /* E7E4 8001DFE4 1800BF8F */  lw         $ra, 0x18($sp)
    /* E7E8 8001DFE8 1400B18F */  lw         $s1, 0x14($sp)
    /* E7EC 8001DFEC 1000B08F */  lw         $s0, 0x10($sp)
    /* E7F0 8001DFF0 0800E003 */  jr         $ra
    /* E7F4 8001DFF4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _spu_Fr_
