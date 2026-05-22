nonmatching _createSaveFile, 0x60

glabel _createSaveFile
    /* B7C 8010337C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B80 80103380 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* B84 80103384 00210400 */  sll        $a0, $a0, 4
    /* B88 80103388 1400BFAF */  sw         $ra, 0x14($sp)
    /* B8C 8010338C EF0A040C */  jal        _memcardMakeFilename
    /* B90 80103390 1000B0AF */   sw        $s0, 0x10($sp)
    /* B94 80103394 21804000 */  addu       $s0, $v0, $zero
    /* B98 80103398 7D9A000C */  jal        erase
    /* B9C 8010339C 21200002 */   addu      $a0, $s0, $zero
    /* BA0 801033A0 21200002 */  addu       $a0, $s0, $zero
    /* BA4 801033A4 0300053C */  lui        $a1, (0x30200 >> 16)
    /* BA8 801033A8 659A000C */  jal        open
    /* BAC 801033AC 0002A534 */   ori       $a1, $a1, (0x30200 & 0xFFFF)
    /* BB0 801033B0 21204000 */  addu       $a0, $v0, $zero
    /* BB4 801033B4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* BB8 801033B8 04008210 */  beq        $a0, $v0, .L801033CC
    /* BBC 801033BC 00000000 */   nop
    /* BC0 801033C0 719A000C */  jal        close
    /* BC4 801033C4 00000000 */   nop
    /* BC8 801033C8 21100000 */  addu       $v0, $zero, $zero
  .L801033CC:
    /* BCC 801033CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* BD0 801033D0 1000B08F */  lw         $s0, 0x10($sp)
    /* BD4 801033D4 0800E003 */  jr         $ra
    /* BD8 801033D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _createSaveFile
