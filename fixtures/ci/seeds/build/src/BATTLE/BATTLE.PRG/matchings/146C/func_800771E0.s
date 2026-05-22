nonmatching func_800771E0, 0x60

glabel func_800771E0
    /* E9E0 800771E0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* E9E4 800771E4 0400C014 */  bnez       $a2, .L800771F8
    /* E9E8 800771E8 2800BFAF */   sw        $ra, 0x28($sp)
    /* E9EC 800771EC 0200A228 */  slti       $v0, $a1, 0x2
    /* E9F0 800771F0 0F004014 */  bnez       $v0, .L80077230
    /* E9F4 800771F4 00000000 */   nop
  .L800771F8:
    /* E9F8 800771F8 0200A228 */  slti       $v0, $a1, 0x2
    /* E9FC 800771FC 05004014 */  bnez       $v0, .L80077214
    /* EA00 80077200 07000224 */   addiu     $v0, $zero, 0x7
    /* EA04 80077204 0300E330 */  andi       $v1, $a3, 0x3
    /* EA08 80077208 01000224 */  addiu      $v0, $zero, 0x1
    /* EA0C 8007720C 08006214 */  bne        $v1, $v0, .L80077230
    /* EA10 80077210 07000224 */   addiu     $v0, $zero, 0x7
  .L80077214:
    /* EA14 80077214 1000A2A3 */  sb         $v0, 0x10($sp)
    /* EA18 80077218 1100A5A3 */  sb         $a1, 0x11($sp)
    /* EA1C 8007721C 25008290 */  lbu        $v0, 0x25($a0)
    /* EA20 80077220 1000A427 */  addiu      $a0, $sp, 0x10
    /* EA24 80077224 2000A0A3 */  sb         $zero, 0x20($sp)
    /* EA28 80077228 7A65020C */  jal        vs_battle_populateDataSlot
    /* EA2C 8007722C 1200A2A7 */   sh        $v0, 0x12($sp)
  .L80077230:
    /* EA30 80077230 2800BF8F */  lw         $ra, 0x28($sp)
    /* EA34 80077234 00000000 */  nop
    /* EA38 80077238 0800E003 */  jr         $ra
    /* EA3C 8007723C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800771E0
