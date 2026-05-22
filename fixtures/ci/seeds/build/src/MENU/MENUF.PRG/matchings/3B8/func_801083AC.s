nonmatching func_801083AC, 0x148

glabel func_801083AC
    /* 5BAC 801083AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5BB0 801083B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5BB4 801083B4 1180103C */  lui        $s0, %hi(D_8010988C)
    /* 5BB8 801083B8 8C98048E */  lw         $a0, %lo(D_8010988C)($s0)
    /* 5BBC 801083BC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5BC0 801083C0 CA03010C */  jal        rsin
    /* 5BC4 801083C4 00000000 */   nop
    /* 5BC8 801083C8 02004104 */  bgez       $v0, .L801083D4
    /* 5BCC 801083CC 00000000 */   nop
    /* 5BD0 801083D0 FF014224 */  addiu      $v0, $v0, 0x1FF
  .L801083D4:
    /* 5BD4 801083D4 43220200 */  sra        $a0, $v0, 9
    /* 5BD8 801083D8 9412040C */  jal        func_80104A50
    /* 5BDC 801083DC 08008424 */   addiu     $a0, $a0, 0x8
    /* 5BE0 801083E0 1180033C */  lui        $v1, %hi(D_801098A0)
    /* 5BE4 801083E4 8C98028E */  lw         $v0, %lo(D_8010988C)($s0)
    /* 5BE8 801083E8 A098638C */  lw         $v1, %lo(D_801098A0)($v1)
    /* 5BEC 801083EC 40004224 */  addiu      $v0, $v0, 0x40
    /* 5BF0 801083F0 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 5BF4 801083F4 3A006014 */  bnez       $v1, .L801084E0
    /* 5BF8 801083F8 8C9802AE */   sw        $v0, %lo(D_8010988C)($s0)
    /* 5BFC 801083FC 1180103C */  lui        $s0, %hi(D_8010989C)
    /* 5C00 80108400 9C98028E */  lw         $v0, %lo(D_8010989C)($s0)
    /* 5C04 80108404 00000000 */  nop
    /* 5C08 80108408 03004014 */  bnez       $v0, .L80108418
    /* 5C0C 8010840C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 5C10 80108410 6216010C */  jal        vs_main_playSfxDefault
    /* 5C14 80108414 7A000524 */   addiu     $a1, $zero, 0x7A
  .L80108418:
    /* 5C18 80108418 9C98038E */  lw         $v1, %lo(D_8010989C)($s0)
    /* 5C1C 8010841C 0F000224 */  addiu      $v0, $zero, 0xF
    /* 5C20 80108420 03006214 */  bne        $v1, $v0, .L80108430
    /* 5C24 80108424 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 5C28 80108428 6216010C */  jal        vs_main_playSfxDefault
    /* 5C2C 8010842C 7A000524 */   addiu     $a1, $zero, 0x7A
  .L80108430:
    /* 5C30 80108430 9C98058E */  lw         $a1, %lo(D_8010989C)($s0)
    /* 5C34 80108434 3D21040C */  jal        func_801084F4
    /* 5C38 80108438 40000424 */   addiu     $a0, $zero, 0x40
    /* 5C3C 8010843C 9C98058E */  lw         $a1, %lo(D_8010989C)($s0)
    /* 5C40 80108440 64000424 */  addiu      $a0, $zero, 0x64
    /* 5C44 80108444 5921040C */  jal        func_80108564
    /* 5C48 80108448 F1FFA524 */   addiu     $a1, $a1, -0xF
    /* 5C4C 8010844C D6000424 */  addiu      $a0, $zero, 0xD6
    /* 5C50 80108450 9C98078E */  lw         $a3, %lo(D_8010989C)($s0)
    /* 5C54 80108454 BB000524 */  addiu      $a1, $zero, 0xBB
    /* 5C58 80108458 3519040C */  jal        func_801064D4
    /* 5C5C 8010845C F1FFE624 */   addiu     $a2, $a3, -0xF
    /* 5C60 80108460 9C98038E */  lw         $v1, %lo(D_8010989C)($s0)
    /* 5C64 80108464 00000000 */  nop
    /* 5C68 80108468 FF7F6228 */  slti       $v0, $v1, 0x7FFF
    /* 5C6C 8010846C 02004010 */  beqz       $v0, .L80108478
    /* 5C70 80108470 01006224 */   addiu     $v0, $v1, 0x1
    /* 5C74 80108474 9C9802AE */  sw         $v0, %lo(D_8010989C)($s0)
  .L80108478:
    /* 5C78 80108478 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5C7C 8010847C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5C80 80108480 00000000 */  nop
    /* 5C84 80108484 20004230 */  andi       $v0, $v0, 0x20
    /* 5C88 80108488 16004010 */  beqz       $v0, .L801084E4
    /* 5C8C 8010848C 21100000 */   addu      $v0, $zero, $zero
    /* 5C90 80108490 9C98028E */  lw         $v0, %lo(D_8010989C)($s0)
    /* 5C94 80108494 00000000 */  nop
    /* 5C98 80108498 3F004228 */  slti       $v0, $v0, 0x3F
    /* 5C9C 8010849C 0C004014 */  bnez       $v0, .L801084D0
    /* 5CA0 801084A0 3F000224 */   addiu     $v0, $zero, 0x3F
    /* 5CA4 801084A4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 5CA8 801084A8 5917010C */  jal        func_80045D64
    /* 5CAC 801084AC 21280000 */   addu      $a1, $zero, $zero
    /* 5CB0 801084B0 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 5CB4 801084B4 01000524 */  addiu      $a1, $zero, 0x1
    /* 5CB8 801084B8 2AF8010C */  jal        func_8007E0A8
    /* 5CBC 801084BC 05000624 */   addiu     $a2, $zero, 0x5
    /* 5CC0 801084C0 9023040C */  jal        func_80108E40
    /* 5CC4 801084C4 00000000 */   nop
    /* 5CC8 801084C8 39210408 */  j          .L801084E4
    /* 5CCC 801084CC 01000224 */   addiu     $v0, $zero, 0x1
  .L801084D0:
    /* 5CD0 801084D0 9C9802AE */  sw         $v0, %lo(D_8010989C)($s0)
    /* 5CD4 801084D4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 5CD8 801084D8 5917010C */  jal        func_80045D64
    /* 5CDC 801084DC 21280000 */   addu      $a1, $zero, $zero
  .L801084E0:
    /* 5CE0 801084E0 21100000 */  addu       $v0, $zero, $zero
  .L801084E4:
    /* 5CE4 801084E4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5CE8 801084E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 5CEC 801084EC 0800E003 */  jr         $ra
    /* 5CF0 801084F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801083AC
