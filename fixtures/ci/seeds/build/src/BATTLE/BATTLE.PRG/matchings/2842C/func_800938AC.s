nonmatching func_800938AC, 0x68

glabel func_800938AC
    /* 2B0AC 800938AC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B0B0 800938B0 0F80023C */  lui        $v0, %hi(D_800F2258)
    /* 2B0B4 800938B4 58224684 */  lh         $a2, %lo(D_800F2258)($v0)
    /* 2B0B8 800938B8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B0BC 800938BC 1100C210 */  beq        $a2, $v0, .L80093904
    /* 2B0C0 800938C0 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2B0C4 800938C4 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 2B0C8 800938C8 F81B4324 */  addiu      $v1, $v0, %lo(vs_battle_roomData)
    /* 2B0CC 800938CC B000628C */  lw         $v0, 0xB0($v1)
    /* 2B0D0 800938D0 00000000 */  nop
    /* 2B0D4 800938D4 0B004010 */  beqz       $v0, .L80093904
    /* 2B0D8 800938D8 00000000 */   nop
    /* 2B0DC 800938DC 04008010 */  beqz       $a0, .L800938F0
    /* 2B0E0 800938E0 00020424 */   addiu     $a0, $zero, 0x200
    /* 2B0E4 800938E4 20000724 */  addiu      $a3, $zero, 0x20
    /* 2B0E8 800938E8 3E4E0208 */  j          .L800938F8
    /* 2B0EC 800938EC 21284000 */   addu      $a1, $v0, $zero
  .L800938F0:
    /* 2B0F0 800938F0 7F000724 */  addiu      $a3, $zero, 0x7F
    /* 2B0F4 800938F4 B000658C */  lw         $a1, 0xB0($v1)
  .L800938F8:
    /* 2B0F8 800938F8 08000224 */  addiu      $v0, $zero, 0x8
    /* 2B0FC 800938FC 2519010C */  jal        func_80046494
    /* 2B100 80093900 1000A2AF */   sw        $v0, 0x10($sp)
  .L80093904:
    /* 2B104 80093904 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2B108 80093908 00000000 */  nop
    /* 2B10C 8009390C 0800E003 */  jr         $ra
    /* 2B110 80093910 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800938AC
