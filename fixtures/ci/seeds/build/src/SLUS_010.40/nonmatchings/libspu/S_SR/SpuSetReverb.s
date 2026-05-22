nonmatching SpuSetReverb, 0xCC

glabel SpuSetReverb
    /* EF34 8001E734 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EF38 8001E738 1000B0AF */  sw         $s0, 0x10($sp)
    /* EF3C 8001E73C 21808000 */  addu       $s0, $a0, $zero
    /* EF40 8001E740 06000012 */  beqz       $s0, .L8001E75C
    /* EF44 8001E744 1400BFAF */   sw        $ra, 0x14($sp)
    /* EF48 8001E748 01000224 */  addiu      $v0, $zero, 0x1
    /* EF4C 8001E74C 0B000212 */  beq        $s0, $v0, .L8001E77C
    /* EF50 8001E750 00000000 */   nop
    /* EF54 8001E754 FA790008 */  j          .L8001E7E8
    /* EF58 8001E758 00000000 */   nop
  .L8001E75C:
    /* EF5C 8001E75C 0380033C */  lui        $v1, %hi(D_80030860)
    /* EF60 8001E760 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* EF64 8001E764 00000000 */  nop
    /* EF68 8001E768 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* EF6C 8001E76C 0380013C */  lui        $at, %hi(D_800307F4)
    /* EF70 8001E770 F40720AC */  sw         $zero, %lo(D_800307F4)($at)
    /* EF74 8001E774 F9790008 */  j          .L8001E7E4
    /* EF78 8001E778 7FFF4230 */   andi      $v0, $v0, 0xFF7F
  .L8001E77C:
    /* EF7C 8001E77C 0380023C */  lui        $v0, %hi(D_800307F8)
    /* EF80 8001E780 F807428C */  lw         $v0, %lo(D_800307F8)($v0)
    /* EF84 8001E784 00000000 */  nop
    /* EF88 8001E788 0F005010 */  beq        $v0, $s0, .L8001E7C8
    /* EF8C 8001E78C 00000000 */   nop
    /* EF90 8001E790 0380043C */  lui        $a0, %hi(D_800307FC)
    /* EF94 8001E794 FC07848C */  lw         $a0, %lo(D_800307FC)($a0)
    /* EF98 8001E798 217A000C */  jal        _SpuIsInAllocateArea_
    /* EF9C 8001E79C 00000000 */   nop
    /* EFA0 8001E7A0 09004010 */  beqz       $v0, .L8001E7C8
    /* EFA4 8001E7A4 00000000 */   nop
    /* EFA8 8001E7A8 0380033C */  lui        $v1, %hi(D_80030860)
    /* EFAC 8001E7AC 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* EFB0 8001E7B0 00000000 */  nop
    /* EFB4 8001E7B4 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* EFB8 8001E7B8 0380013C */  lui        $at, %hi(D_800307F4)
    /* EFBC 8001E7BC F40720AC */  sw         $zero, %lo(D_800307F4)($at)
    /* EFC0 8001E7C0 F9790008 */  j          .L8001E7E4
    /* EFC4 8001E7C4 7FFF4230 */   andi      $v0, $v0, 0xFF7F
  .L8001E7C8:
    /* EFC8 8001E7C8 0380033C */  lui        $v1, %hi(D_80030860)
    /* EFCC 8001E7CC 6008638C */  lw         $v1, %lo(D_80030860)($v1)
    /* EFD0 8001E7D0 00000000 */  nop
    /* EFD4 8001E7D4 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* EFD8 8001E7D8 0380013C */  lui        $at, %hi(D_800307F4)
    /* EFDC 8001E7DC F40730AC */  sw         $s0, %lo(D_800307F4)($at)
    /* EFE0 8001E7E0 80004234 */  ori        $v0, $v0, 0x80
  .L8001E7E4:
    /* EFE4 8001E7E4 AA0162A4 */  sh         $v0, 0x1AA($v1)
  .L8001E7E8:
    /* EFE8 8001E7E8 0380023C */  lui        $v0, %hi(D_800307F4)
    /* EFEC 8001E7EC F407428C */  lw         $v0, %lo(D_800307F4)($v0)
    /* EFF0 8001E7F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* EFF4 8001E7F4 1000B08F */  lw         $s0, 0x10($sp)
    /* EFF8 8001E7F8 0800E003 */  jr         $ra
    /* EFFC 8001E7FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SpuSetReverb
    /* F000 8001E800 00000000 */  nop
