nonmatching func_800BB874, 0x13C

glabel func_800BB874
    /* 53074 800BB874 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 53078 800BB878 0F80043C */  lui        $a0, %hi(D_800F4B20)
    /* 5307C 800BB87C 0680033C */  lui        $v1, %hi(D_8005DFDA)
    /* 53080 800BB880 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 53084 800BB884 801F133C */  lui        $s3, (0x1F800000 >> 16)
    /* 53088 800BB888 0000738E */  lw         $s3, (0x1F800000 & 0xFFFF)($s3)
    /* 5308C 800BB88C 204B8294 */  lhu        $v0, %lo(D_800F4B20)($a0)
    /* 53090 800BB890 DADF6394 */  lhu        $v1, %lo(D_8005DFDA)($v1)
    /* 53094 800BB894 1800B2AF */  sw         $s2, 0x18($sp)
    /* 53098 800BB898 21900000 */  addu       $s2, $zero, $zero
    /* 5309C 800BB89C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 530A0 800BB8A0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 530A4 800BB8A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 530A8 800BB8A8 01004224 */  addiu      $v0, $v0, 0x1
    /* 530AC 800BB8AC 29006010 */  beqz       $v1, .L800BB954
    /* 530B0 800BB8B0 204B82A4 */   sh        $v0, %lo(D_800F4B20)($a0)
    /* 530B4 800BB8B4 21886002 */  addu       $s1, $s3, $zero
    /* 530B8 800BB8B8 00141200 */  sll        $v0, $s2, 16
  .L800BB8BC:
    /* 530BC 800BB8BC 0F80033C */  lui        $v1, %hi(D_800F4B20)
    /* 530C0 800BB8C0 204B6394 */  lhu        $v1, %lo(D_800F4B20)($v1)
    /* 530C4 800BB8C4 03140200 */  sra        $v0, $v0, 16
    /* 530C8 800BB8C8 42180300 */  srl        $v1, $v1, 1
    /* 530CC 800BB8CC 21104300 */  addu       $v0, $v0, $v1
    /* 530D0 800BB8D0 01004230 */  andi       $v0, $v0, 0x1
    /* 530D4 800BB8D4 40110200 */  sll        $v0, $v0, 5
    /* 530D8 800BB8D8 15004010 */  beqz       $v0, .L800BB930
    /* 530DC 800BB8DC 21804000 */   addu      $s0, $v0, $zero
    /* 530E0 800BB8E0 99AD000C */  jal        SetLineF2
    /* 530E4 800BB8E4 21206002 */   addu      $a0, $s3, $zero
    /* 530E8 800BB8E8 07002292 */  lbu        $v0, 0x7($s1)
    /* 530EC 800BB8EC 10007326 */  addiu      $s3, $s3, 0x10
    /* 530F0 800BB8F0 060030A2 */  sb         $s0, 0x6($s1)
    /* 530F4 800BB8F4 050030A2 */  sb         $s0, 0x5($s1)
    /* 530F8 800BB8F8 040030A2 */  sb         $s0, 0x4($s1)
    /* 530FC 800BB8FC 02004234 */  ori        $v0, $v0, 0x2
    /* 53100 800BB900 070022A2 */  sb         $v0, 0x7($s1)
    /* 53104 800BB904 0680023C */  lui        $v0, %hi(D_8005DFD6)
    /* 53108 800BB908 D6DF4294 */  lhu        $v0, %lo(D_8005DFD6)($v0)
    /* 5310C 800BB90C 21282002 */  addu       $a1, $s1, $zero
    /* 53110 800BB910 080020A6 */  sh         $zero, 0x8($s1)
    /* 53114 800BB914 0E0032A6 */  sh         $s2, 0xE($s1)
    /* 53118 800BB918 0A0032A6 */  sh         $s2, 0xA($s1)
    /* 5311C 800BB91C 0C0022A6 */  sh         $v0, 0xC($s1)
    /* 53120 800BB920 801F043C */  lui        $a0, (0x1F800008 >> 16)
    /* 53124 800BB924 0800848C */  lw         $a0, (0x1F800008 & 0xFFFF)($a0)
    /* 53128 800BB928 35AD000C */  jal        AddPrim
    /* 5312C 800BB92C 10003126 */   addiu     $s1, $s1, 0x10
  .L800BB930:
    /* 53130 800BB930 01004226 */  addiu      $v0, $s2, 0x1
    /* 53134 800BB934 21904000 */  addu       $s2, $v0, $zero
    /* 53138 800BB938 00140200 */  sll        $v0, $v0, 16
    /* 5313C 800BB93C 0680033C */  lui        $v1, %hi(D_8005DFDA)
    /* 53140 800BB940 DADF6394 */  lhu        $v1, %lo(D_8005DFDA)($v1)
    /* 53144 800BB944 03140200 */  sra        $v0, $v0, 16
    /* 53148 800BB948 2A104300 */  slt        $v0, $v0, $v1
    /* 5314C 800BB94C DBFF4014 */  bnez       $v0, .L800BB8BC
    /* 53150 800BB950 00141200 */   sll       $v0, $s2, 16
  .L800BB954:
    /* 53154 800BB954 21200000 */  addu       $a0, $zero, $zero
    /* 53158 800BB958 02000524 */  addiu      $a1, $zero, 0x2
    /* 5315C 800BB95C 21308000 */  addu       $a2, $a0, $zero
    /* 53160 800BB960 1DAD000C */  jal        GetTPage
    /* 53164 800BB964 21388000 */   addu      $a3, $a0, $zero
    /* 53168 800BB968 21206002 */  addu       $a0, $s3, $zero
    /* 5316C 800BB96C 01000524 */  addiu      $a1, $zero, 0x1
    /* 53170 800BB970 2130A000 */  addu       $a2, $a1, $zero
    /* 53174 800BB974 A1AD000C */  jal        SetDrawTPage
    /* 53178 800BB978 FFFF4730 */   andi      $a3, $v0, 0xFFFF
    /* 5317C 800BB97C 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 53180 800BB980 0800048E */  lw         $a0, (0x1F800008 & 0xFFFF)($s0)
    /* 53184 800BB984 35AD000C */  jal        AddPrim
    /* 53188 800BB988 21286002 */   addu      $a1, $s3, $zero
    /* 5318C 800BB98C 08006226 */  addiu      $v0, $s3, 0x8
    /* 53190 800BB990 000002AE */  sw         $v0, (0x1F800000 & 0xFFFF)($s0)
    /* 53194 800BB994 2000BF8F */  lw         $ra, 0x20($sp)
    /* 53198 800BB998 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5319C 800BB99C 1800B28F */  lw         $s2, 0x18($sp)
    /* 531A0 800BB9A0 1400B18F */  lw         $s1, 0x14($sp)
    /* 531A4 800BB9A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 531A8 800BB9A8 0800E003 */  jr         $ra
    /* 531AC 800BB9AC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800BB874
