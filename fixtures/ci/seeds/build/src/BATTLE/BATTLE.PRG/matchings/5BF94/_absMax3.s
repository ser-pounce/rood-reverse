nonmatching _absMax3, 0x50

glabel _absMax3
    /* 673F8 800CFBF8 02008104 */  bgez       $a0, .L800CFC04
    /* 673FC 800CFBFC 21408000 */   addu      $t0, $a0, $zero
    /* 67400 800CFC00 23400400 */  negu       $t0, $a0
  .L800CFC04:
    /* 67404 800CFC04 0200A104 */  bgez       $a1, .L800CFC10
    /* 67408 800CFC08 2138A000 */   addu      $a3, $a1, $zero
    /* 6740C 800CFC0C 23380500 */  negu       $a3, $a1
  .L800CFC10:
    /* 67410 800CFC10 0200C104 */  bgez       $a2, .L800CFC1C
    /* 67414 800CFC14 2118C000 */   addu      $v1, $a2, $zero
    /* 67418 800CFC18 23180600 */  negu       $v1, $a2
  .L800CFC1C:
    /* 6741C 800CFC1C 2A100701 */  slt        $v0, $t0, $a3
    /* 67420 800CFC20 03004010 */  beqz       $v0, .L800CFC30
    /* 67424 800CFC24 2A10E300 */   slt       $v0, $a3, $v1
    /* 67428 800CFC28 0D3F0308 */  j          .L800CFC34
    /* 6742C 800CFC2C 2120A000 */   addu      $a0, $a1, $zero
  .L800CFC30:
    /* 67430 800CFC30 2A100301 */  slt        $v0, $t0, $v1
  .L800CFC34:
    /* 67434 800CFC34 02004010 */  beqz       $v0, .L800CFC40
    /* 67438 800CFC38 00000000 */   nop
    /* 6743C 800CFC3C 2120C000 */  addu       $a0, $a2, $zero
  .L800CFC40:
    /* 67440 800CFC40 0800E003 */  jr         $ra
    /* 67444 800CFC44 21108000 */   addu      $v0, $a0, $zero
endlabel _absMax3
