nonmatching vs_mainMenu_initInventory, 0x120

glabel vs_mainMenu_initInventory
    /* C48 800FA448 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* C4C 800FA44C FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* C50 800FA450 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* C54 800FA454 2400BFAF */  sw         $ra, 0x24($sp)
    /* C58 800FA458 2000B4AF */  sw         $s4, 0x20($sp)
    /* C5C 800FA45C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* C60 800FA460 1800B2AF */  sw         $s2, 0x18($sp)
    /* C64 800FA464 1400B1AF */  sw         $s1, 0x14($sp)
    /* C68 800FA468 1000B0AF */  sw         $s0, 0x10($sp)
    /* C6C 800FA46C 3C00518C */  lw         $s1, 0x3C($v0)
    /* C70 800FA470 00000000 */  nop
    /* C74 800FA474 49012292 */  lbu        $v0, 0x149($s1)
    /* C78 800FA478 00000000 */  nop
    /* C7C 800FA47C 06004010 */  beqz       $v0, .L800FA498
    /* C80 800FA480 3C002526 */   addiu     $a1, $s1, 0x3C
    /* C84 800FA484 40110200 */  sll        $v0, $v0, 5
    /* C88 800FA488 0680043C */  lui        $a0, %hi(D_80060148)
    /* C8C 800FA48C 48018424 */  addiu      $a0, $a0, %lo(D_80060148)
    /* C90 800FA490 30AE010C */  jal        vs_battle_copyUiWeaponStats
    /* C94 800FA494 21204400 */   addu      $a0, $v0, $a0
  .L800FA498:
    /* C98 800FA498 AE022292 */  lbu        $v0, 0x2AE($s1)
    /* C9C 800FA49C 00000000 */  nop
    /* CA0 800FA4A0 09004010 */  beqz       $v0, .L800FA4C8
    /* CA4 800FA4A4 21184000 */   addu      $v1, $v0, $zero
    /* CA8 800FA4A8 D4012526 */  addiu      $a1, $s1, 0x1D4
    /* CAC 800FA4AC 40100300 */  sll        $v0, $v1, 1
    /* CB0 800FA4B0 21104300 */  addu       $v0, $v0, $v1
    /* CB4 800FA4B4 00110200 */  sll        $v0, $v0, 4
    /* CB8 800FA4B8 0680043C */  lui        $a0, %hi(D_80060238)
    /* CBC 800FA4BC 38028424 */  addiu      $a0, $a0, %lo(D_80060238)
    /* CC0 800FA4C0 78AE010C */  jal        vs_battle_copyUiShieldStats
    /* CC4 800FA4C4 21204400 */   addu      $a0, $v0, $a0
  .L800FA4C8:
    /* CC8 800FA4C8 21980000 */  addu       $s3, $zero, $zero
    /* CCC 800FA4CC 0680023C */  lui        $v0, %hi(D_80060780)
    /* CD0 800FA4D0 80075424 */  addiu      $s4, $v0, %lo(D_80060780)
    /* CD4 800FA4D4 98031224 */  addiu      $s2, $zero, 0x398
    /* CD8 800FA4D8 21802002 */  addu       $s0, $s1, $zero
  .L800FA4DC:
    /* CDC 800FA4DC 52040292 */  lbu        $v0, 0x452($s0)
    /* CE0 800FA4E0 00000000 */  nop
    /* CE4 800FA4E4 07004010 */  beqz       $v0, .L800FA504
    /* CE8 800FA4E8 21283202 */   addu      $a1, $s1, $s2
    /* CEC 800FA4EC 2000A524 */  addiu      $a1, $a1, 0x20
    /* CF0 800FA4F0 80200200 */  sll        $a0, $v0, 2
    /* CF4 800FA4F4 21208200 */  addu       $a0, $a0, $v0
    /* CF8 800FA4F8 C0200400 */  sll        $a0, $a0, 3
    /* CFC 800FA4FC AAAE010C */  jal        vs_battle_copyUiArmorStats
    /* D00 800FA500 21209400 */   addu      $a0, $a0, $s4
  .L800FA504:
    /* D04 800FA504 DC005226 */  addiu      $s2, $s2, 0xDC
    /* D08 800FA508 01007326 */  addiu      $s3, $s3, 0x1
    /* D0C 800FA50C 0600622A */  slti       $v0, $s3, 0x6
    /* D10 800FA510 F2FF4014 */  bnez       $v0, .L800FA4DC
    /* D14 800FA514 DC001026 */   addiu     $s0, $s0, 0xDC
    /* D18 800FA518 6F032292 */  lbu        $v0, 0x36F($s1)
    /* D1C 800FA51C 00000000 */  nop
    /* D20 800FA520 09004010 */  beqz       $v0, .L800FA548
    /* D24 800FA524 21184000 */   addu      $v1, $v0, $zero
    /* D28 800FA528 38032526 */  addiu      $a1, $s1, 0x338
    /* D2C 800FA52C 80100300 */  sll        $v0, $v1, 2
    /* D30 800FA530 21104300 */  addu       $v0, $v0, $v1
    /* D34 800FA534 C0100200 */  sll        $v0, $v0, 3
    /* D38 800FA538 0680043C */  lui        $a0, %hi(D_80060780)
    /* D3C 800FA53C 80078424 */  addiu      $a0, $a0, %lo(D_80060780)
    /* D40 800FA540 B7AE010C */  jal        vs_battle_copyUiAccessoryStats
    /* D44 800FA544 21204400 */   addu      $a0, $v0, $a0
  .L800FA548:
    /* D48 800FA548 2400BF8F */  lw         $ra, 0x24($sp)
    /* D4C 800FA54C 2000B48F */  lw         $s4, 0x20($sp)
    /* D50 800FA550 1C00B38F */  lw         $s3, 0x1C($sp)
    /* D54 800FA554 1800B28F */  lw         $s2, 0x18($sp)
    /* D58 800FA558 1400B18F */  lw         $s1, 0x14($sp)
    /* D5C 800FA55C 1000B08F */  lw         $s0, 0x10($sp)
    /* D60 800FA560 0800E003 */  jr         $ra
    /* D64 800FA564 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_mainMenu_initInventory
