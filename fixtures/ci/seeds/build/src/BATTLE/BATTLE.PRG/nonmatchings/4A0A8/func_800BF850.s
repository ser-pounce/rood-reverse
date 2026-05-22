nonmatching func_800BF850, 0x368

glabel func_800BF850
    /* 57050 800BF850 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 57054 800BF854 2400B3AF */  sw         $s3, 0x24($sp)
    /* 57058 800BF858 0F80133C */  lui        $s3, %hi(D_800F4C34)
    /* 5705C 800BF85C 344C6492 */  lbu        $a0, %lo(D_800F4C34)($s3)
    /* 57060 800BF860 2800BFAF */  sw         $ra, 0x28($sp)
    /* 57064 800BF864 2000B2AF */  sw         $s2, 0x20($sp)
    /* 57068 800BF868 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5706C 800BF86C 03008014 */  bnez       $a0, .L800BF87C
    /* 57070 800BF870 1800B0AF */   sw        $s0, 0x18($sp)
  .L800BF874:
    /* 57074 800BF874 E7FE0208 */  j          .L800BFB9C
    /* 57078 800BF878 21100000 */   addu      $v0, $zero, $zero
  .L800BF87C:
    /* 5707C 800BF87C 01000524 */  addiu      $a1, $zero, 0x1
    /* 57080 800BF880 1A008514 */  bne        $a0, $a1, .L800BF8EC
    /* 57084 800BF884 02000224 */   addiu     $v0, $zero, 0x2
    /* 57088 800BF888 0F80033C */  lui        $v1, %hi(D_800F4BB8)
    /* 5708C 800BF88C B84B6290 */  lbu        $v0, %lo(D_800F4BB8)($v1)
    /* 57090 800BF890 00000000 */  nop
    /* 57094 800BF894 F7FF4010 */  beqz       $v0, .L800BF874
    /* 57098 800BF898 02000224 */   addiu     $v0, $zero, 0x2
    /* 5709C 800BF89C 344C62A2 */  sb         $v0, %lo(D_800F4C34)($s3)
    /* 570A0 800BF8A0 FAEE020C */  jal        func_800BBBE8
    /* 570A4 800BF8A4 B84B60A0 */   sb        $zero, %lo(D_800F4BB8)($v1)
    /* 570A8 800BF8A8 B0F3010C */  jal        func_8007CEC0
    /* 570AC 800BF8AC 21800000 */   addu      $s0, $zero, $zero
    /* 570B0 800BF8B0 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 570B4 800BF8B4 704B4324 */  addiu      $v1, $v0, %lo(D_800F4B70)
    /* 570B8 800BF8B8 00141000 */  sll        $v0, $s0, 16
  .L800BF8BC:
    /* 570BC 800BF8BC 03140200 */  sra        $v0, $v0, 16
    /* 570C0 800BF8C0 21104300 */  addu       $v0, $v0, $v1
    /* 570C4 800BF8C4 000040A0 */  sb         $zero, 0x0($v0)
    /* 570C8 800BF8C8 01000226 */  addiu      $v0, $s0, 0x1
    /* 570CC 800BF8CC 21804000 */  addu       $s0, $v0, $zero
    /* 570D0 800BF8D0 00140200 */  sll        $v0, $v0, 16
    /* 570D4 800BF8D4 03140200 */  sra        $v0, $v0, 16
    /* 570D8 800BF8D8 11004228 */  slti       $v0, $v0, 0x11
    /* 570DC 800BF8DC F7FF4014 */  bnez       $v0, .L800BF8BC
    /* 570E0 800BF8E0 00141000 */   sll       $v0, $s0, 16
    /* 570E4 800BF8E4 E7FE0208 */  j          .L800BFB9C
    /* 570E8 800BF8E8 02000224 */   addiu     $v0, $zero, 0x2
  .L800BF8EC:
    /* 570EC 800BF8EC 2C008214 */  bne        $a0, $v0, .L800BF9A0
    /* 570F0 800BF8F0 03000224 */   addiu     $v0, $zero, 0x3
    /* 570F4 800BF8F4 0F80023C */  lui        $v0, %hi(D_800F4C6A)
    /* 570F8 800BF8F8 6A4C40A0 */  sb         $zero, %lo(D_800F4C6A)($v0)
    /* 570FC 800BF8FC 0F80023C */  lui        $v0, %hi(D_800F4BE0)
    /* 57100 800BF900 E04B4384 */  lh         $v1, %lo(D_800F4BE0)($v0)
    /* 57104 800BF904 0F80023C */  lui        $v0, %hi(D_800F4C54)
    /* 57108 800BF908 0C006510 */  beq        $v1, $a1, .L800BF93C
    /* 5710C 800BF90C 544C40A4 */   sh        $zero, %lo(D_800F4C54)($v0)
    /* 57110 800BF910 02006228 */  slti       $v0, $v1, 0x2
    /* 57114 800BF914 05004010 */  beqz       $v0, .L800BF92C
    /* 57118 800BF918 00000000 */   nop
    /* 5711C 800BF91C 17006010 */  beqz       $v1, .L800BF97C
    /* 57120 800BF920 02000224 */   addiu     $v0, $zero, 0x2
    /* 57124 800BF924 E7FE0208 */  j          .L800BFB9C
    /* 57128 800BF928 00000000 */   nop
  .L800BF92C:
    /* 5712C 800BF92C 09006410 */  beq        $v1, $a0, .L800BF954
    /* 57130 800BF930 0F80033C */   lui       $v1, %hi(_mpdRoomDoorSection)
    /* 57134 800BF934 E7FE0208 */  j          .L800BFB9C
    /* 57138 800BF938 02000224 */   addiu     $v0, $zero, 0x2
  .L800BF93C:
    /* 5713C 800BF93C 0F80023C */  lui        $v0, %hi(D_800F4C30)
    /* 57140 800BF940 304C448C */  lw         $a0, %lo(D_800F4C30)($v0)
    /* 57144 800BF944 7CFD020C */  jal        func_800BF5F0
    /* 57148 800BF948 00000000 */   nop
    /* 5714C 800BF94C 66FE0208 */  j          .L800BF998
    /* 57150 800BF950 04000224 */   addiu     $v0, $zero, 0x4
  .L800BF954:
    /* 57154 800BF954 0F80023C */  lui        $v0, %hi(_evtFile)
    /* 57158 800BF958 524C4284 */  lh         $v0, %lo(_evtFile)($v0)
    /* 5715C 800BF95C E84B638C */  lw         $v1, %lo(_mpdRoomDoorSection)($v1)
    /* 57160 800BF960 40100200 */  sll        $v0, $v0, 1
    /* 57164 800BF964 21104300 */  addu       $v0, $v0, $v1
    /* 57168 800BF968 00004484 */  lh         $a0, 0x0($v0)
    /* 5716C 800BF96C 7CFD020C */  jal        func_800BF5F0
    /* 57170 800BF970 21206400 */   addu      $a0, $v1, $a0
    /* 57174 800BF974 66FE0208 */  j          .L800BF998
    /* 57178 800BF978 04000224 */   addiu     $v0, $zero, 0x4
  .L800BF97C:
    /* 5717C 800BF97C 0F80023C */  lui        $v0, %hi(_evtFile)
    /* 57180 800BF980 524C4484 */  lh         $a0, %lo(_evtFile)($v0)
    /* 57184 800BF984 0F80023C */  lui        $v0, %hi(D_800F4C30)
    /* 57188 800BF988 304C458C */  lw         $a1, %lo(D_800F4C30)($v0)
    /* 5718C 800BF98C 3A00030C */  jal        func_800C00E8
    /* 57190 800BF990 00000000 */   nop
    /* 57194 800BF994 03000224 */  addiu      $v0, $zero, 0x3
  .L800BF998:
    /* 57198 800BF998 E6FE0208 */  j          .L800BFB98
    /* 5719C 800BF99C 344C62A2 */   sb        $v0, %lo(D_800F4C34)($s3)
  .L800BF9A0:
    /* 571A0 800BF9A0 1C008214 */  bne        $a0, $v0, .L800BFA14
    /* 571A4 800BF9A4 0F80023C */   lui       $v0, %hi(D_800F4BBC)
    /* 571A8 800BF9A8 BC4B448C */  lw         $a0, %lo(D_800F4BBC)($v0)
    /* 571AC 800BF9AC 00000000 */  nop
    /* 571B0 800BF9B0 00009184 */  lh         $s1, 0x0($a0)
    /* 571B4 800BF9B4 04000224 */  addiu      $v0, $zero, 0x4
    /* 571B8 800BF9B8 78002216 */  bne        $s1, $v0, .L800BFB9C
    /* 571BC 800BF9BC 02000224 */   addiu     $v0, $zero, 0x2
    /* 571C0 800BF9C0 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 571C4 800BF9C4 0F80123C */   lui       $s2, %hi(D_800F4C54)
    /* 571C8 800BF9C8 544C4286 */  lh         $v0, %lo(D_800F4C54)($s2)
    /* 571CC 800BF9CC 00000000 */  nop
    /* 571D0 800BF9D0 0A004010 */  beqz       $v0, .L800BF9FC
    /* 571D4 800BF9D4 0F80023C */   lui       $v0, %hi(D_800F4C30)
    /* 571D8 800BF9D8 0F80103C */  lui        $s0, %hi(D_800F4C24)
    /* 571DC 800BF9DC 304C448C */  lw         $a0, %lo(D_800F4C30)($v0)
    /* 571E0 800BF9E0 244C058E */  lw         $a1, %lo(D_800F4C24)($s0)
    /* 571E4 800BF9E4 2C24010C */  jal        vs_main_memcpy
    /* 571E8 800BF9E8 00180624 */   addiu     $a2, $zero, 0x1800
    /* 571EC 800BF9EC 244C048E */  lw         $a0, %lo(D_800F4C24)($s0)
    /* 571F0 800BF9F0 180F010C */  jal        vs_main_freeHeapR
    /* 571F4 800BF9F4 00000000 */   nop
    /* 571F8 800BF9F8 544C40A6 */  sh         $zero, %lo(D_800F4C54)($s2)
  .L800BF9FC:
    /* 571FC 800BF9FC 0F80023C */  lui        $v0, %hi(D_800F4C30)
    /* 57200 800BFA00 304C448C */  lw         $a0, %lo(D_800F4C30)($v0)
    /* 57204 800BFA04 7CFD020C */  jal        func_800BF5F0
    /* 57208 800BFA08 00000000 */   nop
    /* 5720C 800BFA0C E6FE0208 */  j          .L800BFB98
    /* 57210 800BFA10 344C71A2 */   sb        $s1, %lo(D_800F4C34)($s3)
  .L800BFA14:
    /* 57214 800BFA14 A5EF020C */  jal        func_800BBE94
    /* 57218 800BFA18 00000000 */   nop
    /* 5721C 800BFA1C 0F80023C */  lui        $v0, %hi(D_800F4C22)
    /* 57220 800BFA20 224C4284 */  lh         $v0, %lo(D_800F4C22)($v0)
    /* 57224 800BFA24 00000000 */  nop
    /* 57228 800BFA28 2F004014 */  bnez       $v0, .L800BFAE8
    /* 5722C 800BFA2C 0F80043C */   lui       $a0, %hi(D_800F4C38)
    /* 57230 800BFA30 384C8424 */  addiu      $a0, $a0, %lo(D_800F4C38)
    /* 57234 800BFA34 EEFE020C */  jal        func_800BFBB8
    /* 57238 800BFA38 21280000 */   addu      $a1, $zero, $zero
    /* 5723C 800BFA3C 00140200 */  sll        $v0, $v0, 16
    /* 57240 800BFA40 15004010 */  beqz       $v0, .L800BFA98
    /* 57244 800BFA44 0F80023C */   lui       $v0, %hi(D_800F4BB6)
    /* 57248 800BFA48 B64B4284 */  lh         $v0, %lo(D_800F4BB6)($v0)
    /* 5724C 800BFA4C 00000000 */  nop
    /* 57250 800BFA50 0F004014 */  bnez       $v0, .L800BFA90
    /* 57254 800BFA54 0F80033C */   lui       $v1, %hi(D_800F4C22)
    /* 57258 800BFA58 0F80023C */  lui        $v0, %hi(D_800F4C54)
    /* 5725C 800BFA5C 544C4284 */  lh         $v0, %lo(D_800F4C54)($v0)
    /* 57260 800BFA60 00000000 */  nop
    /* 57264 800BFA64 0B004014 */  bnez       $v0, .L800BFA94
    /* 57268 800BFA68 01000224 */   addiu     $v0, $zero, 0x1
    /* 5726C 800BFA6C 0F80023C */  lui        $v0, %hi(D_800F4BE2)
    /* 57270 800BFA70 E24B4284 */  lh         $v0, %lo(D_800F4BE2)($v0)
    /* 57274 800BFA74 00000000 */  nop
    /* 57278 800BFA78 06004014 */  bnez       $v0, .L800BFA94
    /* 5727C 800BFA7C 01000224 */   addiu     $v0, $zero, 0x1
    /* 57280 800BFA80 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 57284 800BFA84 73F0020C */  jal        func_800BC1CC
    /* 57288 800BFA88 21288000 */   addu      $a1, $a0, $zero
    /* 5728C 800BFA8C 0F80033C */  lui        $v1, %hi(D_800F4C22)
  .L800BFA90:
    /* 57290 800BFA90 01000224 */  addiu      $v0, $zero, 0x1
  .L800BFA94:
    /* 57294 800BFA94 224C62A4 */  sh         $v0, %lo(D_800F4C22)($v1)
  .L800BFA98:
    /* 57298 800BFA98 01001024 */  addiu      $s0, $zero, 0x1
    /* 5729C 800BFA9C 0F80023C */  lui        $v0, %hi(D_800F4C38)
    /* 572A0 800BFAA0 384C5124 */  addiu      $s1, $v0, %lo(D_800F4C38)
    /* 572A4 800BFAA4 00141000 */  sll        $v0, $s0, 16
  .L800BFAA8:
    /* 572A8 800BFAA8 032C0200 */  sra        $a1, $v0, 16
    /* 572AC 800BFAAC 80100500 */  sll        $v0, $a1, 2
    /* 572B0 800BFAB0 21205100 */  addu       $a0, $v0, $s1
    /* 572B4 800BFAB4 0000828C */  lw         $v0, 0x0($a0)
    /* 572B8 800BFAB8 00000000 */  nop
    /* 572BC 800BFABC 04004010 */  beqz       $v0, .L800BFAD0
    /* 572C0 800BFAC0 01000226 */   addiu     $v0, $s0, 0x1
    /* 572C4 800BFAC4 EEFE020C */  jal        func_800BFBB8
    /* 572C8 800BFAC8 00000000 */   nop
    /* 572CC 800BFACC 01000226 */  addiu      $v0, $s0, 0x1
  .L800BFAD0:
    /* 572D0 800BFAD0 21804000 */  addu       $s0, $v0, $zero
    /* 572D4 800BFAD4 00140200 */  sll        $v0, $v0, 16
    /* 572D8 800BFAD8 03140200 */  sra        $v0, $v0, 16
    /* 572DC 800BFADC 04004228 */  slti       $v0, $v0, 0x4
    /* 572E0 800BFAE0 F1FF4014 */  bnez       $v0, .L800BFAA8
    /* 572E4 800BFAE4 00141000 */   sll       $v0, $s0, 16
  .L800BFAE8:
    /* 572E8 800BFAE8 78F2020C */  jal        func_800BC9E0
    /* 572EC 800BFAEC 00000000 */   nop
    /* 572F0 800BFAF0 ADF6020C */  jal        func_800BDAB4
    /* 572F4 800BFAF4 00000000 */   nop
    /* 572F8 800BFAF8 C5EF020C */  jal        vs_battle_applyCameraState
    /* 572FC 800BFAFC 00000000 */   nop
    /* 57300 800BFB00 6CEE020C */  jal        func_800BB9B0
    /* 57304 800BFB04 00000000 */   nop
    /* 57308 800BFB08 BFEE020C */  jal        func_800BBAFC
    /* 5730C 800BFB0C 00000000 */   nop
    /* 57310 800BFB10 0F80023C */  lui        $v0, %hi(D_800F4BE4)
    /* 57314 800BFB14 E44B4290 */  lbu        $v0, %lo(D_800F4BE4)($v0)
    /* 57318 800BFB18 00000000 */  nop
    /* 5731C 800BFB1C 04004010 */  beqz       $v0, .L800BFB30
    /* 57320 800BFB20 0F80023C */   lui       $v0, %hi(D_800F4C22)
    /* 57324 800BFB24 1DEE020C */  jal        func_800BB874
    /* 57328 800BFB28 00000000 */   nop
    /* 5732C 800BFB2C 0F80023C */  lui        $v0, %hi(D_800F4C22)
  .L800BFB30:
    /* 57330 800BFB30 224C4284 */  lh         $v0, %lo(D_800F4C22)($v0)
    /* 57334 800BFB34 00000000 */  nop
    /* 57338 800BFB38 18004010 */  beqz       $v0, .L800BFB9C
    /* 5733C 800BFB3C 02000224 */   addiu     $v0, $zero, 0x2
    /* 57340 800BFB40 84F5020C */  jal        func_800BD610
    /* 57344 800BFB44 00000000 */   nop
    /* 57348 800BFB48 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5734C 800BFB4C FF000324 */  addiu      $v1, $zero, 0xFF
    /* 57350 800BFB50 12004314 */  bne        $v0, $v1, .L800BFB9C
    /* 57354 800BFB54 02000224 */   addiu     $v0, $zero, 0x2
    /* 57358 800BFB58 0F80023C */  lui        $v0, %hi(D_800F4C54)
    /* 5735C 800BFB5C 544C4284 */  lh         $v0, %lo(D_800F4C54)($v0)
    /* 57360 800BFB60 00000000 */  nop
    /* 57364 800BFB64 06004010 */  beqz       $v0, .L800BFB80
    /* 57368 800BFB68 0F80023C */   lui       $v0, %hi(D_800F4C34)
    /* 5736C 800BFB6C 03000324 */  addiu      $v1, $zero, 0x3
    /* 57370 800BFB70 344C43A0 */  sb         $v1, %lo(D_800F4C34)($v0)
    /* 57374 800BFB74 0F80023C */  lui        $v0, %hi(D_800F4BE0)
    /* 57378 800BFB78 E4FE0208 */  j          .L800BFB90
    /* 5737C 800BFB7C E04B40A4 */   sh        $zero, %lo(D_800F4BE0)($v0)
  .L800BFB80:
    /* 57380 800BFB80 67FF020C */  jal        func_800BFD9C
    /* 57384 800BFB84 00000000 */   nop
    /* 57388 800BFB88 0F80023C */  lui        $v0, %hi(D_800F4C34)
    /* 5738C 800BFB8C 344C40A0 */  sb         $zero, %lo(D_800F4C34)($v0)
  .L800BFB90:
    /* 57390 800BFB90 0F80023C */  lui        $v0, %hi(D_800F4C22)
    /* 57394 800BFB94 224C40A4 */  sh         $zero, %lo(D_800F4C22)($v0)
  .L800BFB98:
    /* 57398 800BFB98 02000224 */  addiu      $v0, $zero, 0x2
  .L800BFB9C:
    /* 5739C 800BFB9C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 573A0 800BFBA0 2400B38F */  lw         $s3, 0x24($sp)
    /* 573A4 800BFBA4 2000B28F */  lw         $s2, 0x20($sp)
    /* 573A8 800BFBA8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 573AC 800BFBAC 1800B08F */  lw         $s0, 0x18($sp)
    /* 573B0 800BFBB0 0800E003 */  jr         $ra
    /* 573B4 800BFBB4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800BF850
