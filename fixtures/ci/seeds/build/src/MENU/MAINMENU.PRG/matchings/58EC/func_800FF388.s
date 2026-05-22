nonmatching func_800FF388, 0xB4

glabel func_800FF388
    /* 5B88 800FF388 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 5B8C 800FF38C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 5B90 800FF390 21808000 */  addu       $s0, $a0, $zero
    /* 5B94 800FF394 1080043C */  lui        $a0, %hi(D_801024A0)
    /* 5B98 800FF398 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5B9C 800FF39C 1080123C */  lui        $s2, %hi(D_801022D2)
    /* 5BA0 800FF3A0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5BA4 800FF3A4 1080113C */  lui        $s1, %hi(D_801022C8)
    /* 5BA8 800FF3A8 A0248690 */  lbu        $a2, %lo(D_801024A0)($a0)
    /* 5BAC 800FF3AC 20000426 */  addiu      $a0, $s0, 0x20
    /* 5BB0 800FF3B0 D2224392 */  lbu        $v1, %lo(D_801022D2)($s2)
    /* 5BB4 800FF3B4 C822228E */  lw         $v0, %lo(D_801022C8)($s1)
    /* 5BB8 800FF3B8 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 5BBC 800FF3BC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 5BC0 800FF3C0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 5BC4 800FF3C4 21187000 */  addu       $v1, $v1, $s0
    /* 5BC8 800FF3C8 C0190300 */  sll        $v1, $v1, 7
    /* 5BCC 800FF3CC 21104300 */  addu       $v0, $v0, $v1
    /* 5BD0 800FF3D0 21300602 */  addu       $a2, $s0, $a2
    /* 5BD4 800FF3D4 00310600 */  sll        $a2, $a2, 4
    /* 5BD8 800FF3D8 1200C624 */  addiu      $a2, $a2, 0x12
    /* 5BDC 800FF3DC 9723030C */  jal        vs_battle_setMenuItem
    /* 5BE0 800FF3E0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 5BE4 800FF3E4 D2224392 */  lbu        $v1, %lo(D_801022D2)($s2)
    /* 5BE8 800FF3E8 C822248E */  lw         $a0, %lo(D_801022C8)($s1)
    /* 5BEC 800FF3EC 21187000 */  addu       $v1, $v1, $s0
    /* 5BF0 800FF3F0 C0190300 */  sll        $v1, $v1, 7
    /* 5BF4 800FF3F4 21186400 */  addu       $v1, $v1, $a0
    /* 5BF8 800FF3F8 1C00638C */  lw         $v1, 0x1C($v1)
    /* 5BFC 800FF3FC 21204000 */  addu       $a0, $v0, $zero
    /* 5C00 800FF400 01006330 */  andi       $v1, $v1, 0x1
    /* 5C04 800FF404 06000016 */  bnez       $s0, .L800FF420
    /* 5C08 800FF408 070083A0 */   sb        $v1, 0x7($a0)
    /* 5C0C 800FF40C D2224292 */  lbu        $v0, %lo(D_801022D2)($s2)
    /* 5C10 800FF410 00000000 */  nop
    /* 5C14 800FF414 02004010 */  beqz       $v0, .L800FF420
    /* 5C18 800FF418 01000224 */   addiu     $v0, $zero, 0x1
    /* 5C1C 800FF41C 050082A0 */  sb         $v0, 0x5($a0)
  .L800FF420:
    /* 5C20 800FF420 2400BF8F */  lw         $ra, 0x24($sp)
    /* 5C24 800FF424 2000B28F */  lw         $s2, 0x20($sp)
    /* 5C28 800FF428 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5C2C 800FF42C 1800B08F */  lw         $s0, 0x18($sp)
    /* 5C30 800FF430 21108000 */  addu       $v0, $a0, $zero
    /* 5C34 800FF434 0800E003 */  jr         $ra
    /* 5C38 800FF438 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800FF388
