nonmatching func_80077078, 0x84

glabel func_80077078
    /* E878 80077078 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* E87C 8007707C 4000A38F */  lw         $v1, 0x40($sp)
    /* E880 80077080 01000224 */  addiu      $v0, $zero, 0x1
    /* E884 80077084 2800BFAF */  sw         $ra, 0x28($sp)
    /* E888 80077088 1000A2A3 */  sb         $v0, 0x10($sp)
    /* E88C 8007708C 1100A5A3 */  sb         $a1, 0x11($sp)
    /* E890 80077090 1200A6A7 */  sh         $a2, 0x12($sp)
    /* E894 80077094 0000E28C */  lw         $v0, 0x0($a3)
    /* E898 80077098 00000000 */  nop
    /* E89C 8007709C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* E8A0 800770A0 4400828C */  lw         $v0, 0x44($a0)
    /* E8A4 800770A4 00000000 */  nop
    /* E8A8 800770A8 1400A2AF */  sw         $v0, 0x14($sp)
    /* E8AC 800770AC 80006230 */  andi       $v0, $v1, 0x80
    /* E8B0 800770B0 07004010 */  beqz       $v0, .L800770D0
    /* E8B4 800770B4 000F6230 */   andi      $v0, $v1, 0xF00
    /* E8B8 800770B8 03120200 */  sra        $v0, $v0, 8
    /* E8BC 800770BC 2000A2A3 */  sb         $v0, 0x20($sp)
    /* E8C0 800770C0 00F06230 */  andi       $v0, $v1, 0xF000
    /* E8C4 800770C4 03130200 */  sra        $v0, $v0, 12
    /* E8C8 800770C8 36DC0108 */  j          .L800770D8
    /* E8CC 800770CC 2100A2A3 */   sb        $v0, 0x21($sp)
  .L800770D0:
    /* E8D0 800770D0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* E8D4 800770D4 2000A2A3 */  sb         $v0, 0x20($sp)
  .L800770D8:
    /* E8D8 800770D8 02000224 */  addiu      $v0, $zero, 0x2
    /* E8DC 800770DC 1000A427 */  addiu      $a0, $sp, 0x10
    /* E8E0 800770E0 2300A0A3 */  sb         $zero, 0x23($sp)
    /* E8E4 800770E4 7A65020C */  jal        vs_battle_populateDataSlot
    /* E8E8 800770E8 2200A2A3 */   sb        $v0, 0x22($sp)
    /* E8EC 800770EC 2800BF8F */  lw         $ra, 0x28($sp)
    /* E8F0 800770F0 00000000 */  nop
    /* E8F4 800770F4 0800E003 */  jr         $ra
    /* E8F8 800770F8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80077078
