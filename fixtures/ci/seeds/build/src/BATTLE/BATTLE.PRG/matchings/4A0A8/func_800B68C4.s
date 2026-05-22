nonmatching func_800B68C4, 0x44

glabel func_800B68C4
    /* 4E0C4 800B68C4 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4E0C8 800B68C8 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4E0CC 800B68CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E0D0 800B68D0 2C4C40A0 */  sb         $zero, %lo(D_800F4C2C)($v0)
    /* 4E0D4 800B68D4 02000224 */  addiu      $v0, $zero, 0x2
    /* 4E0D8 800B68D8 FF006330 */  andi       $v1, $v1, 0xFF
    /* 4E0DC 800B68DC 03006210 */  beq        $v1, $v0, .L800B68EC
    /* 4E0E0 800B68E0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 4E0E4 800B68E4 3EDA0208 */  j          .L800B68F8
    /* 4E0E8 800B68E8 21100000 */   addu      $v0, $zero, $zero
  .L800B68EC:
    /* 4E0EC 800B68EC DED9020C */  jal        func_800B6778
    /* 4E0F0 800B68F0 00000000 */   nop
    /* 4E0F4 800B68F4 04000224 */  addiu      $v0, $zero, 0x4
  .L800B68F8:
    /* 4E0F8 800B68F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E0FC 800B68FC 00000000 */  nop
    /* 4E100 800B6900 0800E003 */  jr         $ra
    /* 4E104 800B6904 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B68C4
