nonmatching _drawTitleMenu, 0x11C

glabel _drawTitleMenu
    /* 813C 8007093C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 8140 80070940 2800BFAF */  sw         $ra, 0x28($sp)
    /* 8144 80070944 2400B5AF */  sw         $s5, 0x24($sp)
    /* 8148 80070948 2000B4AF */  sw         $s4, 0x20($sp)
    /* 814C 8007094C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8150 80070950 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8154 80070954 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8158 80070958 F3C0010C */  jal        _setTitleMenuState
    /* 815C 8007095C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 8160 80070960 21880000 */  addu       $s1, $zero, $zero
    /* 8164 80070964 0E80153C */  lui        $s5, %hi(_titleMenuItemBg)
    /* 8168 80070968 FF05143C */  lui        $s4, (0x5FFFFFF >> 16)
    /* 816C 8007096C FFFF9436 */  ori        $s4, $s4, (0x5FFFFFF & 0xFFFF)
    /* 8170 80070970 8064133C */  lui        $s3, (0x64808080 >> 16)
    /* 8174 80070974 80807336 */  ori        $s3, $s3, (0x64808080 & 0xFFFF)
    /* 8178 80070978 4000123C */  lui        $s2, (0x4000A0 >> 16)
    /* 817C 8007097C A0005236 */  ori        $s2, $s2, (0x4000A0 & 0xFFFF)
    /* 8180 80070980 48E9B026 */  addiu      $s0, $s5, %lo(_titleMenuItemBg)
  .L80070984:
    /* 8184 80070984 00E1023C */  lui        $v0, (0xE1000113 >> 16)
    /* 8188 80070988 13014234 */  ori        $v0, $v0, (0xE1000113 & 0xFFFF)
    /* 818C 8007098C 0001033C */  lui        $v1, (0x10000B0 >> 16)
    /* 8190 80070990 B0006334 */  ori        $v1, $v1, (0x10000B0 & 0xFFFF)
    /* 8194 80070994 21200002 */  addu       $a0, $s0, $zero
    /* 8198 80070998 040002AE */  sw         $v0, 0x4($s0)
    /* 819C 8007099C 00C00234 */  ori        $v0, $zero, 0xC000
    /* 81A0 800709A0 48E9B4AE */  sw         $s4, %lo(_titleMenuItemBg)($s5)
    /* 81A4 800709A4 080013AE */  sw         $s3, 0x8($s0)
    /* 81A8 800709A8 0C0003AE */  sw         $v1, 0xC($s0)
    /* 81AC 800709AC 100002AE */  sw         $v0, 0x10($s0)
    /* 81B0 800709B0 FAA2000C */  jal        DrawPrim
    /* 81B4 800709B4 140012AE */   sw        $s2, 0x14($s0)
    /* 81B8 800709B8 18001026 */  addiu      $s0, $s0, 0x18
    /* 81BC 800709BC 00E1023C */  lui        $v0, (0xE1000115 >> 16)
    /* 81C0 800709C0 15014234 */  ori        $v0, $v0, (0xE1000115 & 0xFFFF)
    /* 81C4 800709C4 4001033C */  lui        $v1, (0x14000B0 >> 16)
    /* 81C8 800709C8 B0006334 */  ori        $v1, $v1, (0x14000B0 & 0xFFFF)
    /* 81CC 800709CC 21200002 */  addu       $a0, $s0, $zero
    /* 81D0 800709D0 040082AC */  sw         $v0, 0x4($a0)
    /* 81D4 800709D4 20C00234 */  ori        $v0, $zero, 0xC020
    /* 81D8 800709D8 000094AC */  sw         $s4, 0x0($a0)
    /* 81DC 800709DC 080093AC */  sw         $s3, 0x8($a0)
    /* 81E0 800709E0 0C0083AC */  sw         $v1, 0xC($a0)
    /* 81E4 800709E4 100082AC */  sw         $v0, 0x10($a0)
    /* 81E8 800709E8 FAA2000C */  jal        DrawPrim
    /* 81EC 800709EC 140092AC */   sw        $s2, 0x14($a0)
    /* 81F0 800709F0 6BC1010C */  jal        _drawTitleMenuItems
    /* 81F4 800709F4 00000000 */   nop
    /* 81F8 800709F8 09002016 */  bnez       $s1, .L80070A20
    /* 81FC 800709FC 00000000 */   nop
    /* 8200 80070A00 94A1000C */  jal        DrawSync
    /* 8204 80070A04 21200000 */   addu      $a0, $zero, $zero
    /* 8208 80070A08 B17D000C */  jal        VSync
    /* 820C 80070A0C 21200000 */   addu      $a0, $zero, $zero
    /* 8210 80070A10 AD0D010C */  jal        vs_main_setVibrateParams
    /* 8214 80070A14 01003126 */   addiu     $s1, $s1, 0x1
    /* 8218 80070A18 8BC20108 */  j          .L80070A2C
    /* 821C 80070A1C 0200222A */   slti      $v0, $s1, 0x2
  .L80070A20:
    /* 8220 80070A20 81BE010C */  jal        _stopMovieIfComplete
    /* 8224 80070A24 01003126 */   addiu     $s1, $s1, 0x1
    /* 8228 80070A28 0200222A */  slti       $v0, $s1, 0x2
  .L80070A2C:
    /* 822C 80070A2C D5FF4014 */  bnez       $v0, .L80070984
    /* 8230 80070A30 48E9B026 */   addiu     $s0, $s5, %lo(_titleMenuItemBg)
    /* 8234 80070A34 2800BF8F */  lw         $ra, 0x28($sp)
    /* 8238 80070A38 2400B58F */  lw         $s5, 0x24($sp)
    /* 823C 80070A3C 2000B48F */  lw         $s4, 0x20($sp)
    /* 8240 80070A40 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8244 80070A44 1800B28F */  lw         $s2, 0x18($sp)
    /* 8248 80070A48 1400B18F */  lw         $s1, 0x14($sp)
    /* 824C 80070A4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 8250 80070A50 0800E003 */  jr         $ra
    /* 8254 80070A54 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _drawTitleMenu
