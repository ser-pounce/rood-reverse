nonmatching _copyEquipmentStats, 0xD8

glabel _copyEquipmentStats
    /* 1B9C 8010439C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BA0 801043A0 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BA4 801043A4 1900A210 */  beq        $a1, $v0, .L8010440C
    /* 1BA8 801043A8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1BAC 801043AC 0300A228 */  slti       $v0, $a1, 0x3
    /* 1BB0 801043B0 05004010 */  beqz       $v0, .L801043C8
    /* 1BB4 801043B4 01000224 */   addiu     $v0, $zero, 0x1
    /* 1BB8 801043B8 0A00A210 */  beq        $a1, $v0, .L801043E4
    /* 1BBC 801043BC 40280600 */   sll       $a1, $a2, 1
    /* 1BC0 801043C0 19110408 */  j          .L80104464
    /* 1BC4 801043C4 00000000 */   nop
  .L801043C8:
    /* 1BC8 801043C8 04000224 */  addiu      $v0, $zero, 0x4
    /* 1BCC 801043CC 1600A210 */  beq        $a1, $v0, .L80104428
    /* 1BD0 801043D0 05000224 */   addiu     $v0, $zero, 0x5
    /* 1BD4 801043D4 1D00A210 */  beq        $a1, $v0, .L8010444C
    /* 1BD8 801043D8 C0100600 */   sll       $v0, $a2, 3
    /* 1BDC 801043DC 19110408 */  j          .L80104464
    /* 1BE0 801043E0 00000000 */   nop
  .L801043E4:
    /* 1BE4 801043E4 2128A600 */  addu       $a1, $a1, $a2
    /* 1BE8 801043E8 80280500 */  sll        $a1, $a1, 2
    /* 1BEC 801043EC 2328A600 */  subu       $a1, $a1, $a2
    /* 1BF0 801043F0 80280500 */  sll        $a1, $a1, 2
    /* 1BF4 801043F4 0680023C */  lui        $v0, %hi(D_800603E8)
    /* 1BF8 801043F8 E8034224 */  addiu      $v0, $v0, %lo(D_800603E8)
    /* 1BFC 801043FC D1AA010C */  jal        vs_battle_copyInventoryBladeStats
    /* 1C00 80104400 2128A200 */   addu      $a1, $a1, $v0
    /* 1C04 80104404 19110408 */  j          .L80104464
    /* 1C08 80104408 00000000 */   nop
  .L8010440C:
    /* 1C0C 8010440C 00110600 */  sll        $v0, $a2, 4
    /* 1C10 80104410 0680053C */  lui        $a1, %hi(D_800606A8)
    /* 1C14 80104414 A806A524 */  addiu      $a1, $a1, %lo(D_800606A8)
    /* 1C18 80104418 1DAB010C */  jal        vs_battle_copyInventoryGripStats
    /* 1C1C 8010441C 21284500 */   addu      $a1, $v0, $a1
    /* 1C20 80104420 19110408 */  j          .L80104464
    /* 1C24 80104424 00000000 */   nop
  .L80104428:
    /* 1C28 80104428 80100600 */  sll        $v0, $a2, 2
    /* 1C2C 8010442C 21104600 */  addu       $v0, $v0, $a2
    /* 1C30 80104430 C0100200 */  sll        $v0, $v0, 3
    /* 1C34 80104434 0680053C */  lui        $a1, %hi(D_800607A8)
    /* 1C38 80104438 A807A524 */  addiu      $a1, $a1, %lo(D_800607A8)
    /* 1C3C 8010443C 3FAB010C */  jal        vs_battle_copyInventoryArmorStats
    /* 1C40 80104440 21284500 */   addu      $a1, $v0, $a1
    /* 1C44 80104444 19110408 */  j          .L80104464
    /* 1C48 80104448 00000000 */   nop
  .L8010444C:
    /* 1C4C 8010444C 23104600 */  subu       $v0, $v0, $a2
    /* 1C50 80104450 80100200 */  sll        $v0, $v0, 2
    /* 1C54 80104454 0680053C */  lui        $a1, %hi(D_80060A28)
    /* 1C58 80104458 280AA524 */  addiu      $a1, $a1, %lo(D_80060A28)
    /* 1C5C 8010445C 83AB010C */  jal        vs_battle_copyInventoryGemStats
    /* 1C60 80104460 21284500 */   addu      $a1, $v0, $a1
  .L80104464:
    /* 1C64 80104464 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C68 80104468 00000000 */  nop
    /* 1C6C 8010446C 0800E003 */  jr         $ra
    /* 1C70 80104470 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _copyEquipmentStats
