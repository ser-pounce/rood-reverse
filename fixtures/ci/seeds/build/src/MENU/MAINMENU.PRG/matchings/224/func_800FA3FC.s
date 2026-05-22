nonmatching func_800FA3FC, 0x4C

glabel func_800FA3FC
    /* BFC 800FA3FC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* C00 800FA400 2800B0AF */  sw         $s0, 0x28($sp)
    /* C04 800FA404 21808000 */  addu       $s0, $a0, $zero
    /* C08 800FA408 21200000 */  addu       $a0, $zero, $zero
    /* C0C 800FA40C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* C10 800FA410 0873020C */  jal        func_8009CC20
    /* C14 800FA414 21288000 */   addu      $a1, $a0, $zero
    /* C18 800FA418 1000A427 */  addiu      $a0, $sp, 0x10
    /* C1C 800FA41C 07000224 */  addiu      $v0, $zero, 0x7
    /* C20 800FA420 1000A2A3 */  sb         $v0, 0x10($sp)
    /* C24 800FA424 1100A0A3 */  sb         $zero, 0x11($sp)
    /* C28 800FA428 1200B0A7 */  sh         $s0, 0x12($sp)
    /* C2C 800FA42C 7A65020C */  jal        vs_battle_populateDataSlot
    /* C30 800FA430 2000A0A3 */   sb        $zero, 0x20($sp)
    /* C34 800FA434 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* C38 800FA438 2800B08F */  lw         $s0, 0x28($sp)
    /* C3C 800FA43C 3000BD27 */  addiu      $sp, $sp, 0x30
    /* C40 800FA440 0800E003 */  jr         $ra
    /* C44 800FA444 00000000 */   nop
endlabel func_800FA3FC
