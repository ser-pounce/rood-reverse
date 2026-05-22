nonmatching _createSaveFile, 0x60

glabel _createSaveFile
    /* C1C 8006941C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C20 80069420 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* C24 80069424 00210400 */  sll        $a0, $a0, 4
    /* C28 80069428 1400BFAF */  sw         $ra, 0x14($sp)
    /* C2C 8006942C 17A3010C */  jal        _memcardMakeFilename
    /* C30 80069430 1000B0AF */   sw        $s0, 0x10($sp)
    /* C34 80069434 21804000 */  addu       $s0, $v0, $zero
    /* C38 80069438 7D9A000C */  jal        erase
    /* C3C 8006943C 21200002 */   addu      $a0, $s0, $zero
    /* C40 80069440 21200002 */  addu       $a0, $s0, $zero
    /* C44 80069444 0300053C */  lui        $a1, (0x30200 >> 16)
    /* C48 80069448 659A000C */  jal        open
    /* C4C 8006944C 0002A534 */   ori       $a1, $a1, (0x30200 & 0xFFFF)
    /* C50 80069450 21204000 */  addu       $a0, $v0, $zero
    /* C54 80069454 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C58 80069458 04008210 */  beq        $a0, $v0, .L8006946C
    /* C5C 8006945C 00000000 */   nop
    /* C60 80069460 719A000C */  jal        close
    /* C64 80069464 00000000 */   nop
    /* C68 80069468 21100000 */  addu       $v0, $zero, $zero
  .L8006946C:
    /* C6C 8006946C 1400BF8F */  lw         $ra, 0x14($sp)
    /* C70 80069470 1000B08F */  lw         $s0, 0x10($sp)
    /* C74 80069474 0800E003 */  jr         $ra
    /* C78 80069478 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _createSaveFile
