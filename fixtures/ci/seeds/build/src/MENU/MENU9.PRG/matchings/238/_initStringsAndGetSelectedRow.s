nonmatching _initStringsAndGetSelectedRow, 0xEC

glabel _initStringsAndGetSelectedRow
    /* 23D0 80104BD0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 23D4 80104BD4 05008010 */  beqz       $a0, .L80104BEC
    /* 23D8 80104BD8 3000BFAF */   sw        $ra, 0x30($sp)
    /* 23DC 80104BDC 1180023C */  lui        $v0, %hi(D_8010A224)
    /* 23E0 80104BE0 24A240AC */  sw         $zero, %lo(D_8010A224)($v0)
    /* 23E4 80104BE4 1180023C */  lui        $v0, %hi(_selectedRow)
    /* 23E8 80104BE8 28A240AC */  sw         $zero, %lo(_selectedRow)($v0)
  .L80104BEC:
    /* 23EC 80104BEC 1180023C */  lui        $v0, %hi(D_8010A224)
    /* 23F0 80104BF0 24A2438C */  lw         $v1, %lo(D_8010A224)($v0)
    /* 23F4 80104BF4 00000000 */  nop
    /* 23F8 80104BF8 05006010 */  beqz       $v1, .L80104C10
    /* 23FC 80104BFC 01000224 */   addiu     $v0, $zero, 0x1
    /* 2400 80104C00 21006210 */  beq        $v1, $v0, .L80104C88
    /* 2404 80104C04 00000000 */   nop
    /* 2408 80104C08 2B130408 */  j          .L80104CAC
    /* 240C 80104C0C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80104C10:
    /* 2410 80104C10 21380000 */  addu       $a3, $zero, $zero
    /* 2414 80104C14 04000624 */  addiu      $a2, $zero, 0x4
    /* 2418 80104C18 1000A827 */  addiu      $t0, $sp, 0x10
    /* 241C 80104C1C 21280001 */  addu       $a1, $t0, $zero
    /* 2420 80104C20 1180023C */  lui        $v0, %hi(_menuText)
    /* 2424 80104C24 20854924 */  addiu      $t1, $v0, %lo(_menuText)
    /* 2428 80104C28 21202001 */  addu       $a0, $t1, $zero
  .L80104C2C:
    /* 242C 80104C2C 21180601 */  addu       $v1, $t0, $a2
    /* 2430 80104C30 0800C624 */  addiu      $a2, $a2, 0x8
    /* 2434 80104C34 00008294 */  lhu        $v0, 0x0($a0)
    /* 2438 80104C38 02008424 */  addiu      $a0, $a0, 0x2
    /* 243C 80104C3C 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2440 80104C40 40100200 */  sll        $v0, $v0, 1
    /* 2444 80104C44 21104900 */  addu       $v0, $v0, $t1
    /* 2448 80104C48 0000A2AC */  sw         $v0, 0x0($a1)
    /* 244C 80104C4C 0800A524 */  addiu      $a1, $a1, 0x8
    /* 2450 80104C50 0400E228 */  slti       $v0, $a3, 0x4
    /* 2454 80104C54 F5FF4014 */  bnez       $v0, .L80104C2C
    /* 2458 80104C58 000060AC */   sw        $zero, 0x0($v1)
    /* 245C 80104C5C 0F80023C */  lui        $v0, %hi(D_800F1BF7)
    /* 2460 80104C60 04000424 */  addiu      $a0, $zero, 0x4
    /* 2464 80104C64 F71B4590 */  lbu        $a1, %lo(D_800F1BF7)($v0)
    /* 2468 80104C68 840B040C */  jal        func_80102E10
    /* 246C 80104C6C 1000A627 */   addiu     $a2, $sp, 0x10
    /* 2470 80104C70 1180033C */  lui        $v1, %hi(D_8010A224)
    /* 2474 80104C74 24A2628C */  lw         $v0, %lo(D_8010A224)($v1)
    /* 2478 80104C78 00000000 */  nop
    /* 247C 80104C7C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2480 80104C80 2A130408 */  j          .L80104CA8
    /* 2484 80104C84 24A262AC */   sw        $v0, %lo(D_8010A224)($v1)
  .L80104C88:
    /* 2488 80104C88 C30B040C */  jal        _getSelectedRow
    /* 248C 80104C8C 00000000 */   nop
    /* 2490 80104C90 21184000 */  addu       $v1, $v0, $zero
    /* 2494 80104C94 1180023C */  lui        $v0, %hi(_selectedRow)
    /* 2498 80104C98 28A243AC */  sw         $v1, %lo(_selectedRow)($v0)
    /* 249C 80104C9C FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 24A0 80104CA0 02006414 */  bne        $v1, $a0, .L80104CAC
    /* 24A4 80104CA4 21106000 */   addu      $v0, $v1, $zero
  .L80104CA8:
    /* 24A8 80104CA8 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80104CAC:
    /* 24AC 80104CAC 3000BF8F */  lw         $ra, 0x30($sp)
    /* 24B0 80104CB0 00000000 */  nop
    /* 24B4 80104CB4 0800E003 */  jr         $ra
    /* 24B8 80104CB8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _initStringsAndGetSelectedRow
