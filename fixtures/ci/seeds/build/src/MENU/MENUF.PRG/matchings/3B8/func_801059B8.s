nonmatching func_801059B8, 0x44

glabel func_801059B8
    /* 31B8 801059B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 31BC 801059BC 2138C000 */  addu       $a3, $a2, $zero
    /* 31C0 801059C0 0200E104 */  bgez       $a3, .L801059CC
    /* 31C4 801059C4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 31C8 801059C8 21380000 */  addu       $a3, $zero, $zero
  .L801059CC:
    /* 31CC 801059CC 4100E228 */  slti       $v0, $a3, 0x41
    /* 31D0 801059D0 02004014 */  bnez       $v0, .L801059DC
    /* 31D4 801059D4 00000000 */   nop
    /* 31D8 801059D8 40000724 */  addiu      $a3, $zero, 0x40
  .L801059DC:
    /* 31DC 801059DC 0300E018 */  blez       $a3, .L801059EC
    /* 31E0 801059E0 00000000 */   nop
    /* 31E4 801059E4 0D17040C */  jal        func_80105C34
    /* 31E8 801059E8 45000624 */   addiu     $a2, $zero, 0x45
  .L801059EC:
    /* 31EC 801059EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 31F0 801059F0 00000000 */  nop
    /* 31F4 801059F4 0800E003 */  jr         $ra
    /* 31F8 801059F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801059B8
