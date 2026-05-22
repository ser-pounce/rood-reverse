nonmatching func_800A70DC, 0x448

glabel func_800A70DC
    /* 3E8DC 800A70DC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3E8E0 800A70E0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3E8E4 800A70E4 21A88000 */  addu       $s5, $a0, $zero
    /* 3E8E8 800A70E8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 3E8EC 800A70EC 21B0A000 */  addu       $s6, $a1, $zero
    /* 3E8F0 800A70F0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3E8F4 800A70F4 801F143C */  lui        $s4, (0x1F8003BC >> 16)
    /* 3E8F8 800A70F8 BC039436 */  ori        $s4, $s4, (0x1F8003BC & 0xFFFF)
    /* 3E8FC 800A70FC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3E900 800A7100 07001324 */  addiu      $s3, $zero, 0x7
    /* 3E904 800A7104 801F043C */  lui        $a0, (0x1F8003C3 >> 16)
    /* 3E908 800A7108 C3038434 */  ori        $a0, $a0, (0x1F8003C3 & 0xFFFF)
    /* 3E90C 800A710C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 3E910 800A7110 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3E914 800A7114 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3E918 800A7118 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3E91C 800A711C AC05A28E */  lw         $v0, 0x5AC($s5)
    /* 3E920 800A7120 FFEF0324 */  addiu      $v1, $zero, -0x1001
    /* 3E924 800A7124 24104300 */  and        $v0, $v0, $v1
    /* 3E928 800A7128 AC05A2AE */  sw         $v0, 0x5AC($s5)
  .L800A712C:
    /* 3E92C 800A712C 2C0080A0 */  sb         $zero, 0x2C($a0)
    /* 3E930 800A7130 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 3E934 800A7134 FDFF6106 */  bgez       $s3, .L800A712C
    /* 3E938 800A7138 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 3E93C 800A713C AC05A28E */  lw         $v0, 0x5AC($s5)
    /* 3E940 800A7140 00000000 */  nop
    /* 3E944 800A7144 00064230 */  andi       $v0, $v0, 0x600
    /* 3E948 800A7148 08004010 */  beqz       $v0, .L800A716C
    /* 3E94C 800A714C 07001324 */   addiu     $s3, $zero, 0x7
    /* 3E950 800A7150 0E008226 */  addiu      $v0, $s4, 0xE
  .L800A7154:
    /* 3E954 800A7154 1C0040A4 */  sh         $zero, 0x1C($v0)
    /* 3E958 800A7158 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 3E95C 800A715C FDFF6106 */  bgez       $s3, .L800A7154
    /* 3E960 800A7160 FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 3E964 800A7164 3E9D0208 */  j          .L800A74F8
    /* 3E968 800A7168 00000000 */   nop
  .L800A716C:
    /* 3E96C 800A716C 0800A28E */  lw         $v0, 0x8($s5)
    /* 3E970 800A7170 1800033C */  lui        $v1, (0x180000 >> 16)
    /* 3E974 800A7174 24104300 */  and        $v0, $v0, $v1
    /* 3E978 800A7178 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 3E97C 800A717C 0B004314 */  bne        $v0, $v1, .L800A71AC
    /* 3E980 800A7180 1C00B126 */   addiu     $s1, $s5, 0x1C
    /* 3E984 800A7184 21980000 */  addu       $s3, $zero, $zero
    /* 3E988 800A7188 21188002 */  addu       $v1, $s4, $zero
  .L800A718C:
    /* 3E98C 800A718C 1E00A296 */  lhu        $v0, 0x1E($s5)
    /* 3E990 800A7190 01007326 */  addiu      $s3, $s3, 0x1
    /* 3E994 800A7194 1C0062A4 */  sh         $v0, 0x1C($v1)
    /* 3E998 800A7198 0800622A */  slti       $v0, $s3, 0x8
    /* 3E99C 800A719C FBFF4014 */  bnez       $v0, .L800A718C
    /* 3E9A0 800A71A0 02006324 */   addiu     $v1, $v1, 0x2
    /* 3E9A4 800A71A4 3E9D0208 */  j          .L800A74F8
    /* 3E9A8 800A71A8 00000000 */   nop
  .L800A71AC:
    /* 3E9AC 800A71AC 21202002 */  addu       $a0, $s1, $zero
    /* 3E9B0 800A71B0 3C06B396 */  lhu        $s3, 0x63C($s5)
    /* 3E9B4 800A71B4 59A3020C */  jal        func_800A8D64
    /* 3E9B8 800A71B8 21280000 */   addu      $a1, $zero, $zero
    /* 3E9BC 800A71BC 21202002 */  addu       $a0, $s1, $zero
    /* 3E9C0 800A71C0 21280000 */  addu       $a1, $zero, $zero
    /* 3E9C4 800A71C4 2138A000 */  addu       $a3, $a1, $zero
    /* 3E9C8 800A71C8 0000428C */  lw         $v0, 0x0($v0)
    /* 3E9CC 800A71CC 23801300 */  negu       $s0, $s3
    /* 3E9D0 800A71D0 21300002 */  addu       $a2, $s0, $zero
    /* 3E9D4 800A71D4 42110200 */  srl        $v0, $v0, 5
    /* 3E9D8 800A71D8 01004230 */  andi       $v0, $v0, 0x1
    /* 3E9DC 800A71DC BA9B020C */  jal        func_800A6EE8
    /* 3E9E0 800A71E0 3C0082A2 */   sb        $v0, 0x3C($s4)
    /* 3E9E4 800A71E4 21202002 */  addu       $a0, $s1, $zero
    /* 3E9E8 800A71E8 21286002 */  addu       $a1, $s3, $zero
    /* 3E9EC 800A71EC 0F80123C */  lui        $s2, %hi(D_800F49F0)
    /* 3E9F0 800A71F0 F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3E9F4 800A71F4 21300000 */  addu       $a2, $zero, $zero
    /* 3E9F8 800A71F8 1C0082A6 */  sh         $v0, 0x1C($s4)
    /* 3E9FC 800A71FC 0000628C */  lw         $v0, 0x0($v1)
    /* 3EA00 800A7200 2138C000 */  addu       $a3, $a2, $zero
    /* 3EA04 800A7204 42110200 */  srl        $v0, $v0, 5
    /* 3EA08 800A7208 01004230 */  andi       $v0, $v0, 0x1
    /* 3EA0C 800A720C BA9B020C */  jal        func_800A6EE8
    /* 3EA10 800A7210 340082A2 */   sb        $v0, 0x34($s4)
    /* 3EA14 800A7214 21202002 */  addu       $a0, $s1, $zero
    /* 3EA18 800A7218 21280002 */  addu       $a1, $s0, $zero
    /* 3EA1C 800A721C F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EA20 800A7220 21300000 */  addu       $a2, $zero, $zero
    /* 3EA24 800A7224 280082A6 */  sh         $v0, 0x28($s4)
    /* 3EA28 800A7228 0000628C */  lw         $v0, 0x0($v1)
    /* 3EA2C 800A722C 2138C000 */  addu       $a3, $a2, $zero
    /* 3EA30 800A7230 42110200 */  srl        $v0, $v0, 5
    /* 3EA34 800A7234 01004230 */  andi       $v0, $v0, 0x1
    /* 3EA38 800A7238 BA9B020C */  jal        func_800A6EE8
    /* 3EA3C 800A723C 3A0082A2 */   sb        $v0, 0x3A($s4)
    /* 3EA40 800A7240 21202002 */  addu       $a0, $s1, $zero
    /* 3EA44 800A7244 2128C002 */  addu       $a1, $s6, $zero
    /* 3EA48 800A7248 23801600 */  negu       $s0, $s6
    /* 3EA4C 800A724C F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EA50 800A7250 21300002 */  addu       $a2, $s0, $zero
    /* 3EA54 800A7254 200082A6 */  sh         $v0, 0x20($s4)
    /* 3EA58 800A7258 0000628C */  lw         $v0, 0x0($v1)
    /* 3EA5C 800A725C 21380000 */  addu       $a3, $zero, $zero
    /* 3EA60 800A7260 42110200 */  srl        $v0, $v0, 5
    /* 3EA64 800A7264 01004230 */  andi       $v0, $v0, 0x1
    /* 3EA68 800A7268 BA9B020C */  jal        func_800A6EE8
    /* 3EA6C 800A726C 360082A2 */   sb        $v0, 0x36($s4)
    /* 3EA70 800A7270 21202002 */  addu       $a0, $s1, $zero
    /* 3EA74 800A7274 21280002 */  addu       $a1, $s0, $zero
    /* 3EA78 800A7278 F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EA7C 800A727C 21300002 */  addu       $a2, $s0, $zero
    /* 3EA80 800A7280 2A0082A6 */  sh         $v0, 0x2A($s4)
    /* 3EA84 800A7284 0000628C */  lw         $v0, 0x0($v1)
    /* 3EA88 800A7288 21380000 */  addu       $a3, $zero, $zero
    /* 3EA8C 800A728C 42110200 */  srl        $v0, $v0, 5
    /* 3EA90 800A7290 01004230 */  andi       $v0, $v0, 0x1
    /* 3EA94 800A7294 BA9B020C */  jal        func_800A6EE8
    /* 3EA98 800A7298 3B0082A2 */   sb        $v0, 0x3B($s4)
    /* 3EA9C 800A729C 21202002 */  addu       $a0, $s1, $zero
    /* 3EAA0 800A72A0 21280002 */  addu       $a1, $s0, $zero
    /* 3EAA4 800A72A4 F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EAA8 800A72A8 2130C002 */  addu       $a2, $s6, $zero
    /* 3EAAC 800A72AC 1E0082A6 */  sh         $v0, 0x1E($s4)
    /* 3EAB0 800A72B0 0000628C */  lw         $v0, 0x0($v1)
    /* 3EAB4 800A72B4 21380000 */  addu       $a3, $zero, $zero
    /* 3EAB8 800A72B8 42110200 */  srl        $v0, $v0, 5
    /* 3EABC 800A72BC 01004230 */  andi       $v0, $v0, 0x1
    /* 3EAC0 800A72C0 BA9B020C */  jal        func_800A6EE8
    /* 3EAC4 800A72C4 350082A2 */   sb        $v0, 0x35($s4)
    /* 3EAC8 800A72C8 21202002 */  addu       $a0, $s1, $zero
    /* 3EACC 800A72CC 2128C002 */  addu       $a1, $s6, $zero
    /* 3EAD0 800A72D0 F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EAD4 800A72D4 2130A000 */  addu       $a2, $a1, $zero
    /* 3EAD8 800A72D8 220082A6 */  sh         $v0, 0x22($s4)
    /* 3EADC 800A72DC 0000628C */  lw         $v0, 0x0($v1)
    /* 3EAE0 800A72E0 21380000 */  addu       $a3, $zero, $zero
    /* 3EAE4 800A72E4 42110200 */  srl        $v0, $v0, 5
    /* 3EAE8 800A72E8 01004230 */  andi       $v0, $v0, 0x1
    /* 3EAEC 800A72EC BA9B020C */  jal        func_800A6EE8
    /* 3EAF0 800A72F0 370082A2 */   sb        $v0, 0x37($s4)
    /* 3EAF4 800A72F4 21202002 */  addu       $a0, $s1, $zero
    /* 3EAF8 800A72F8 21280000 */  addu       $a1, $zero, $zero
    /* 3EAFC 800A72FC F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EB00 800A7300 21306002 */  addu       $a2, $s3, $zero
    /* 3EB04 800A7304 260082A6 */  sh         $v0, 0x26($s4)
    /* 3EB08 800A7308 0000628C */  lw         $v0, 0x0($v1)
    /* 3EB0C 800A730C 2138A000 */  addu       $a3, $a1, $zero
    /* 3EB10 800A7310 42110200 */  srl        $v0, $v0, 5
    /* 3EB14 800A7314 01004230 */  andi       $v0, $v0, 0x1
    /* 3EB18 800A7318 BA9B020C */  jal        func_800A6EE8
    /* 3EB1C 800A731C 390082A2 */   sb        $v0, 0x39($s4)
    /* 3EB20 800A7320 F049438E */  lw         $v1, %lo(D_800F49F0)($s2)
    /* 3EB24 800A7324 240082A6 */  sh         $v0, 0x24($s4)
    /* 3EB28 800A7328 0000628C */  lw         $v0, 0x0($v1)
    /* 3EB2C 800A732C 00000000 */  nop
    /* 3EB30 800A7330 42110200 */  srl        $v0, $v0, 5
    /* 3EB34 800A7334 01004230 */  andi       $v0, $v0, 0x1
    /* 3EB38 800A7338 380082A2 */  sb         $v0, 0x38($s4)
    /* 3EB3C 800A733C 0800A28E */  lw         $v0, 0x8($s5)
    /* 3EB40 800A7340 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3EB44 800A7344 24104300 */  and        $v0, $v0, $v1
    /* 3EB48 800A7348 0300033C */  lui        $v1, (0x30000 >> 16)
    /* 3EB4C 800A734C 08004314 */  bne        $v0, $v1, .L800A7370
    /* 3EB50 800A7350 00000000 */   nop
    /* 3EB54 800A7354 3600A286 */  lh         $v0, 0x36($s5)
    /* 3EB58 800A7358 00000000 */  nop
    /* 3EB5C 800A735C 04004018 */  blez       $v0, .L800A7370
    /* 3EB60 800A7360 00000000 */   nop
    /* 3EB64 800A7364 1E00A286 */  lh         $v0, 0x1E($s5)
    /* 3EB68 800A7368 E69C0208 */  j          .L800A7398
    /* 3EB6C 800A736C E0FF4424 */   addiu     $a0, $v0, -0x20
  .L800A7370:
    /* 3EB70 800A7370 5018A28E */  lw         $v0, 0x1850($s5)
    /* 3EB74 800A7374 00000000 */  nop
    /* 3EB78 800A7378 04004014 */  bnez       $v0, .L800A738C
    /* 3EB7C 800A737C 00000000 */   nop
    /* 3EB80 800A7380 1E00A286 */  lh         $v0, 0x1E($s5)
    /* 3EB84 800A7384 E69C0208 */  j          .L800A7398
    /* 3EB88 800A7388 C0FF4424 */   addiu     $a0, $v0, -0x40
  .L800A738C:
    /* 3EB8C 800A738C 1E00A286 */  lh         $v0, 0x1E($s5)
    /* 3EB90 800A7390 00000000 */  nop
    /* 3EB94 800A7394 A0FF4424 */  addiu      $a0, $v0, -0x60
  .L800A7398:
    /* 3EB98 800A7398 21980000 */  addu       $s3, $zero, $zero
    /* 3EB9C 800A739C 01000624 */  addiu      $a2, $zero, 0x1
    /* 3EBA0 800A73A0 21288002 */  addu       $a1, $s4, $zero
  .L800A73A4:
    /* 3EBA4 800A73A4 1C00A384 */  lh         $v1, 0x1C($a1)
    /* 3EBA8 800A73A8 1E00A286 */  lh         $v0, 0x1E($s5)
    /* 3EBAC 800A73AC 00000000 */  nop
    /* 3EBB0 800A73B0 2A104300 */  slt        $v0, $v0, $v1
    /* 3EBB4 800A73B4 1E00A396 */  lhu        $v1, 0x1E($s5)
    /* 3EBB8 800A73B8 02004010 */  beqz       $v0, .L800A73C4
    /* 3EBBC 800A73BC 00000000 */   nop
    /* 3EBC0 800A73C0 1C00A3A4 */  sh         $v1, 0x1C($a1)
  .L800A73C4:
    /* 3EBC4 800A73C4 21189302 */  addu       $v1, $s4, $s3
    /* 3EBC8 800A73C8 34006290 */  lbu        $v0, 0x34($v1)
    /* 3EBCC 800A73CC 00000000 */  nop
    /* 3EBD0 800A73D0 05004010 */  beqz       $v0, .L800A73E8
    /* 3EBD4 800A73D4 00000000 */   nop
    /* 3EBD8 800A73D8 3C008292 */  lbu        $v0, 0x3C($s4)
    /* 3EBDC 800A73DC 00000000 */  nop
    /* 3EBE0 800A73E0 0B004014 */  bnez       $v0, .L800A7410
    /* 3EBE4 800A73E4 00000000 */   nop
  .L800A73E8:
    /* 3EBE8 800A73E8 1C00A284 */  lh         $v0, 0x1C($a1)
    /* 3EBEC 800A73EC 00000000 */  nop
    /* 3EBF0 800A73F0 2A108200 */  slt        $v0, $a0, $v0
    /* 3EBF4 800A73F4 06004014 */  bnez       $v0, .L800A7410
    /* 3EBF8 800A73F8 00000000 */   nop
    /* 3EBFC 800A73FC 2C0066A0 */  sb         $a2, 0x2C($v1)
    /* 3EC00 800A7400 AC05A28E */  lw         $v0, 0x5AC($s5)
    /* 3EC04 800A7404 00000000 */  nop
    /* 3EC08 800A7408 00104234 */  ori        $v0, $v0, 0x1000
    /* 3EC0C 800A740C AC05A2AE */  sw         $v0, 0x5AC($s5)
  .L800A7410:
    /* 3EC10 800A7410 01007326 */  addiu      $s3, $s3, 0x1
    /* 3EC14 800A7414 0800622A */  slti       $v0, $s3, 0x8
    /* 3EC18 800A7418 E2FF4014 */  bnez       $v0, .L800A73A4
    /* 3EC1C 800A741C 0200A524 */   addiu     $a1, $a1, 0x2
    /* 3EC20 800A7420 0800A28E */  lw         $v0, 0x8($s5)
    /* 3EC24 800A7424 0700033C */  lui        $v1, (0x70000 >> 16)
    /* 3EC28 800A7428 24104300 */  and        $v0, $v0, $v1
    /* 3EC2C 800A742C 32004010 */  beqz       $v0, .L800A74F8
    /* 3EC30 800A7430 00000000 */   nop
    /* 3EC34 800A7434 4C18A386 */  lh         $v1, 0x184C($s5)
    /* 3EC38 800A7438 00000000 */  nop
    /* 3EC3C 800A743C 00017324 */  addiu      $s3, $v1, 0x100
    /* 3EC40 800A7440 02006106 */  bgez       $s3, .L800A744C
    /* 3EC44 800A7444 21106002 */   addu      $v0, $s3, $zero
    /* 3EC48 800A7448 FF026224 */  addiu      $v0, $v1, 0x2FF
  .L800A744C:
    /* 3EC4C 800A744C 439A0200 */  sra        $s3, $v0, 9
    /* 3EC50 800A7450 21200000 */  addu       $a0, $zero, $zero
    /* 3EC54 800A7454 1E00A586 */  lh         $a1, 0x1E($s5)
    /* 3EC58 800A7458 FFFF8224 */  addiu      $v0, $a0, -0x1
  .L800A745C:
    /* 3EC5C 800A745C 21106202 */  addu       $v0, $s3, $v0
    /* 3EC60 800A7460 07004230 */  andi       $v0, $v0, 0x7
    /* 3EC64 800A7464 40100200 */  sll        $v0, $v0, 1
    /* 3EC68 800A7468 21105400 */  addu       $v0, $v0, $s4
    /* 3EC6C 800A746C 1C004284 */  lh         $v0, 0x1C($v0)
    /* 3EC70 800A7470 00000000 */  nop
    /* 3EC74 800A7474 23184500 */  subu       $v1, $v0, $a1
    /* 3EC78 800A7478 01FF6228 */  slti       $v0, $v1, -0xFF
    /* 3EC7C 800A747C 1E004014 */  bnez       $v0, .L800A74F8
    /* 3EC80 800A7480 40FF6228 */   slti      $v0, $v1, -0xC0
    /* 3EC84 800A7484 1C004010 */  beqz       $v0, .L800A74F8
    /* 3EC88 800A7488 01008424 */   addiu     $a0, $a0, 0x1
    /* 3EC8C 800A748C 03008228 */  slti       $v0, $a0, 0x3
    /* 3EC90 800A7490 F2FF4014 */  bnez       $v0, .L800A745C
    /* 3EC94 800A7494 FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 3EC98 800A7498 21200000 */  addu       $a0, $zero, $zero
    /* 3EC9C 800A749C 1E00A586 */  lh         $a1, 0x1E($s5)
    /* 3ECA0 800A74A0 02008224 */  addiu      $v0, $a0, 0x2
  .L800A74A4:
    /* 3ECA4 800A74A4 21106202 */  addu       $v0, $s3, $v0
    /* 3ECA8 800A74A8 07004230 */  andi       $v0, $v0, 0x7
    /* 3ECAC 800A74AC 40100200 */  sll        $v0, $v0, 1
    /* 3ECB0 800A74B0 21105400 */  addu       $v0, $v0, $s4
    /* 3ECB4 800A74B4 1C004284 */  lh         $v0, 0x1C($v0)
    /* 3ECB8 800A74B8 00000000 */  nop
    /* 3ECBC 800A74BC 23184500 */  subu       $v1, $v0, $a1
    /* 3ECC0 800A74C0 40FF6228 */  slti       $v0, $v1, -0xC0
    /* 3ECC4 800A74C4 0C004014 */  bnez       $v0, .L800A74F8
    /* 3ECC8 800A74C8 01008424 */   addiu     $a0, $a0, 0x1
    /* 3ECCC 800A74CC 05008228 */  slti       $v0, $a0, 0x5
    /* 3ECD0 800A74D0 F4FF4014 */  bnez       $v0, .L800A74A4
    /* 3ECD4 800A74D4 02008224 */   addiu     $v0, $a0, 0x2
    /* 3ECD8 800A74D8 40101300 */  sll        $v0, $s3, 1
    /* 3ECDC 800A74DC 1E00A396 */  lhu        $v1, 0x1E($s5)
    /* 3ECE0 800A74E0 21105400 */  addu       $v0, $v0, $s4
    /* 3ECE4 800A74E4 1C0043A4 */  sh         $v1, 0x1C($v0)
    /* 3ECE8 800A74E8 AC05A28E */  lw         $v0, 0x5AC($s5)
    /* 3ECEC 800A74EC FFEF0324 */  addiu      $v1, $zero, -0x1001
    /* 3ECF0 800A74F0 24104300 */  and        $v0, $v0, $v1
    /* 3ECF4 800A74F4 AC05A2AE */  sw         $v0, 0x5AC($s5)
  .L800A74F8:
    /* 3ECF8 800A74F8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 3ECFC 800A74FC 2800B68F */  lw         $s6, 0x28($sp)
    /* 3ED00 800A7500 2400B58F */  lw         $s5, 0x24($sp)
    /* 3ED04 800A7504 2000B48F */  lw         $s4, 0x20($sp)
    /* 3ED08 800A7508 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3ED0C 800A750C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3ED10 800A7510 1400B18F */  lw         $s1, 0x14($sp)
    /* 3ED14 800A7514 1000B08F */  lw         $s0, 0x10($sp)
    /* 3ED18 800A7518 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 3ED1C 800A751C 0800E003 */  jr         $ra
    /* 3ED20 800A7520 00000000 */   nop
endlabel func_800A70DC
