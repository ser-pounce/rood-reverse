nonmatching func_800B7B58, 0x138

glabel func_800B7B58
    /* 4F358 800B7B58 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4F35C 800B7B5C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4F360 800B7B60 21808000 */  addu       $s0, $a0, $zero
    /* 4F364 800B7B64 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F368 800B7B68 3400BFAF */  sw         $ra, 0x34($sp)
    /* 4F36C 800B7B6C 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4F370 800B7B70 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4F374 800B7B74 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4F378 800B7B78 80FF020C */  jal        vs_battle_getShort
    /* 4F37C 800B7B7C 2400B1AF */   sw        $s1, 0x24($sp)
    /* 4F380 800B7B80 94FF020C */  jal        func_800BFE50
    /* 4F384 800B7B84 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F388 800B7B88 03000426 */  addiu      $a0, $s0, 0x3
    /* 4F38C 800B7B8C 80FF020C */  jal        vs_battle_getShort
    /* 4F390 800B7B90 21904000 */   addu      $s2, $v0, $zero
    /* 4F394 800B7B94 05000426 */  addiu      $a0, $s0, 0x5
    /* 4F398 800B7B98 00140200 */  sll        $v0, $v0, 16
    /* 4F39C 800B7B9C 80FF020C */  jal        vs_battle_getShort
    /* 4F3A0 800B7BA0 438C0200 */   sra       $s1, $v0, 17
    /* 4F3A4 800B7BA4 07000426 */  addiu      $a0, $s0, 0x7
    /* 4F3A8 800B7BA8 80FF020C */  jal        vs_battle_getShort
    /* 4F3AC 800B7BAC 21984000 */   addu      $s3, $v0, $zero
    /* 4F3B0 800B7BB0 03000392 */  lbu        $v1, 0x3($s0)
    /* 4F3B4 800B7BB4 00000000 */  nop
    /* 4F3B8 800B7BB8 01006330 */  andi       $v1, $v1, 0x1
    /* 4F3BC 800B7BBC 0E006010 */  beqz       $v1, .L800B7BF8
    /* 4F3C0 800B7BC0 21A04000 */   addu      $s4, $v0, $zero
    /* 4F3C4 800B7BC4 FFFF4432 */  andi       $a0, $s2, 0xFFFF
    /* 4F3C8 800B7BC8 4284020C */  jal        func_800A1108
    /* 4F3CC 800B7BCC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F3D0 800B7BD0 1400A297 */  lhu        $v0, 0x14($sp)
    /* 4F3D4 800B7BD4 1800A397 */  lhu        $v1, 0x18($sp)
    /* 4F3D8 800B7BD8 21105100 */  addu       $v0, $v0, $s1
    /* 4F3DC 800B7BDC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 4F3E0 800B7BE0 1600A297 */  lhu        $v0, 0x16($sp)
    /* 4F3E4 800B7BE4 21187400 */  addu       $v1, $v1, $s4
    /* 4F3E8 800B7BE8 1800A3A7 */  sh         $v1, 0x18($sp)
    /* 4F3EC 800B7BEC 21105300 */  addu       $v0, $v0, $s3
    /* 4F3F0 800B7BF0 01DF0208 */  j          .L800B7C04
    /* 4F3F4 800B7BF4 1600A2A7 */   sh        $v0, 0x16($sp)
  .L800B7BF8:
    /* 4F3F8 800B7BF8 1400B1A7 */  sh         $s1, 0x14($sp)
    /* 4F3FC 800B7BFC 1600B3A7 */  sh         $s3, 0x16($sp)
    /* 4F400 800B7C00 1800B4A7 */  sh         $s4, 0x18($sp)
  .L800B7C04:
    /* 4F404 800B7C04 00800224 */  addiu      $v0, $zero, -0x8000
    /* 4F408 800B7C08 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4F40C 800B7C0C 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4F410 800B7C10 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4F414 800B7C14 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F418 800B7C18 05006214 */  bne        $v1, $v0, .L800B7C30
    /* 4F41C 800B7C1C FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 4F420 800B7C20 FFFF4432 */  andi       $a0, $s2, 0xFFFF
    /* 4F424 800B7C24 1400A527 */  addiu      $a1, $sp, 0x14
    /* 4F428 800B7C28 12DF0208 */  j          .L800B7C48
    /* 4F42C 800B7C2C 21300000 */   addu      $a2, $zero, $zero
  .L800B7C30:
    /* 4F430 800B7C30 FFFF4432 */  andi       $a0, $s2, 0xFFFF
    /* 4F434 800B7C34 09000392 */  lbu        $v1, 0x9($s0)
    /* 4F438 800B7C38 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4F43C 800B7C3C 02006210 */  beq        $v1, $v0, .L800B7C48
    /* 4F440 800B7C40 1400A527 */   addiu     $a1, $sp, 0x14
    /* 4F444 800B7C44 21306000 */  addu       $a2, $v1, $zero
  .L800B7C48:
    /* 4F448 800B7C48 64A7020C */  jal        func_800A9D90
    /* 4F44C 800B7C4C FFFF5032 */   andi      $s0, $s2, 0xFFFF
    /* 4F450 800B7C50 2377020C */  jal        func_8009DC8C
    /* 4F454 800B7C54 21200002 */   addu      $a0, $s0, $zero
    /* 4F458 800B7C58 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F45C 800B7C5C 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F460 800B7C60 21800202 */  addu       $s0, $s0, $v0
    /* 4F464 800B7C64 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F468 800B7C68 000002A2 */  sb         $v0, 0x0($s0)
    /* 4F46C 800B7C6C 3400BF8F */  lw         $ra, 0x34($sp)
    /* 4F470 800B7C70 3000B48F */  lw         $s4, 0x30($sp)
    /* 4F474 800B7C74 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4F478 800B7C78 2800B28F */  lw         $s2, 0x28($sp)
    /* 4F47C 800B7C7C 2400B18F */  lw         $s1, 0x24($sp)
    /* 4F480 800B7C80 2000B08F */  lw         $s0, 0x20($sp)
    /* 4F484 800B7C84 21100000 */  addu       $v0, $zero, $zero
    /* 4F488 800B7C88 0800E003 */  jr         $ra
    /* 4F48C 800B7C8C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800B7B58
