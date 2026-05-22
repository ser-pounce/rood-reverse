nonmatching vs_battle_equipWeapon, 0x128

glabel vs_battle_equipWeapon
    /* 2B38 8006B338 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B3C 8006B33C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B40 8006B340 0F80113C */  lui        $s1, %hi(vs_battle_characterState)
    /* 2B44 8006B344 FC19228E */  lw         $v0, %lo(vs_battle_characterState)($s1)
    /* 2B48 8006B348 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B4C 8006B34C 21808000 */  addu       $s0, $a0, $zero
    /* 2B50 8006B350 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2B54 8006B354 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2B58 8006B358 21280002 */  addu       $a1, $s0, $zero
    /* 2B5C 8006B35C ABAB010C */  jal        vs_battle_applyWeapon
    /* 2B60 8006B360 3C008424 */   addiu     $a0, $a0, 0x3C
    /* 2B64 8006B364 FC19228E */  lw         $v0, %lo(vs_battle_characterState)($s1)
    /* 2B68 8006B368 00000000 */  nop
    /* 2B6C 8006B36C 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2B70 8006B370 83AC010C */  jal        vs_battle_nop0
    /* 2B74 8006B374 00000000 */   nop
    /* 2B78 8006B378 04000016 */  bnez       $s0, .L8006B38C
    /* 2B7C 8006B37C 0680043C */   lui       $a0, %hi(vs_battle_inventory)
    /* 2B80 8006B380 FC19238E */  lw         $v1, %lo(vs_battle_characterState)($s1)
    /* 2B84 8006B384 EEAC0108 */  j          .L8006B3B8
    /* 2B88 8006B388 0A000224 */   addiu     $v0, $zero, 0xA
  .L8006B38C:
    /* 2B8C 8006B38C 01000392 */  lbu        $v1, 0x1($s0)
    /* 2B90 8006B390 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 2B94 8006B394 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2B98 8006B398 40100300 */  sll        $v0, $v1, 1
    /* 2B9C 8006B39C 21104300 */  addu       $v0, $v0, $v1
    /* 2BA0 8006B3A0 80100200 */  sll        $v0, $v0, 2
    /* 2BA4 8006B3A4 23104300 */  subu       $v0, $v0, $v1
    /* 2BA8 8006B3A8 80100200 */  sll        $v0, $v0, 2
    /* 2BAC 8006B3AC 21104400 */  addu       $v0, $v0, $a0
    /* 2BB0 8006B3B0 FC19238E */  lw         $v1, %lo(vs_battle_characterState)($s1)
    /* 2BB4 8006B3B4 83024290 */  lbu        $v0, 0x283($v0)
  .L8006B3B8:
    /* 2BB8 8006B3B8 00000000 */  nop
    /* 2BBC 8006B3BC 250062A0 */  sb         $v0, 0x25($v1)
    /* 2BC0 8006B3C0 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 2BC4 8006B3C4 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 2BC8 8006B3C8 FF07053C */  lui        $a1, (0x7FFFFFF >> 16)
    /* 2BCC 8006B3CC 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2BD0 8006B3D0 FFFFA534 */  ori        $a1, $a1, (0x7FFFFFF & 0xFFFF)
    /* 2BD4 8006B3D4 3400828C */  lw         $v0, 0x34($a0)
    /* 2BD8 8006B3D8 60018390 */  lbu        $v1, 0x160($a0)
    /* 2BDC 8006B3DC C2160200 */  srl        $v0, $v0, 27
    /* 2BE0 8006B3E0 21186200 */  addu       $v1, $v1, $v0
    /* 2BE4 8006B3E4 3400828C */  lw         $v0, 0x34($a0)
    /* 2BE8 8006B3E8 FFF8063C */  lui        $a2, (0xF8FFFFFF >> 16)
    /* 2BEC 8006B3EC 380083A0 */  sb         $v1, 0x38($a0)
    /* 2BF0 8006B3F0 61018390 */  lbu        $v1, 0x161($a0)
    /* 2BF4 8006B3F4 C2160200 */  srl        $v0, $v0, 27
    /* 2BF8 8006B3F8 21186200 */  addu       $v1, $v1, $v0
    /* 2BFC 8006B3FC 3400828C */  lw         $v0, 0x34($a0)
    /* 2C00 8006B400 FFFFC634 */  ori        $a2, $a2, (0xF8FFFFFF & 0xFFFF)
    /* 2C04 8006B404 390083A0 */  sb         $v1, 0x39($a0)
    /* 2C08 8006B408 62018390 */  lbu        $v1, 0x162($a0)
    /* 2C0C 8006B40C C2160200 */  srl        $v0, $v0, 27
    /* 2C10 8006B410 21186200 */  addu       $v1, $v1, $v0
    /* 2C14 8006B414 3A0083A0 */  sb         $v1, 0x3A($a0)
    /* 2C18 8006B418 3800828C */  lw         $v0, 0x38($a0)
    /* 2C1C 8006B41C 6001838C */  lw         $v1, 0x160($a0)
    /* 2C20 8006B420 24104500 */  and        $v0, $v0, $a1
    /* 2C24 8006B424 C21E0300 */  srl        $v1, $v1, 27
    /* 2C28 8006B428 C01E0300 */  sll        $v1, $v1, 27
    /* 2C2C 8006B42C 25104300 */  or         $v0, $v0, $v1
    /* 2C30 8006B430 24104600 */  and        $v0, $v0, $a2
    /* 2C34 8006B434 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 2C38 8006B438 25104300 */  or         $v0, $v0, $v1
    /* 2C3C 8006B43C 85AC010C */  jal        func_8006B214
    /* 2C40 8006B440 380082AC */   sw        $v0, 0x38($a0)
    /* 2C44 8006B444 9CAC010C */  jal        func_8006B270
    /* 2C48 8006B448 00000000 */   nop
    /* 2C4C 8006B44C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2C50 8006B450 1400B18F */  lw         $s1, 0x14($sp)
    /* 2C54 8006B454 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C58 8006B458 0800E003 */  jr         $ra
    /* 2C5C 8006B45C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_equipWeapon
