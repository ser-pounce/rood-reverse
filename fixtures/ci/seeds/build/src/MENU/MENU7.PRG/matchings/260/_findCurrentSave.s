nonmatching _findCurrentSave, 0x174

glabel _findCurrentSave
    /* 2880 80105080 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2884 80105084 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2888 80105088 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 288C 8010508C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2890 80105090 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2894 80105094 07008010 */  beqz       $a0, .L801050B4
    /* 2898 80105098 1000B0AF */   sw        $s0, 0x10($sp)
    /* 289C 8010509C 21100000 */  addu       $v0, $zero, $zero
    /* 28A0 801050A0 1180033C */  lui        $v1, %hi(_findCurrentSaveState)
    /* 28A4 801050A4 A4AA60A0 */  sb         $zero, %lo(_findCurrentSaveState)($v1)
    /* 28A8 801050A8 1180033C */  lui        $v1, %hi(_findCurrentSaveSubState)
    /* 28AC 801050AC 76140408 */  j          .L801051D8
    /* 28B0 801050B0 A5AA60A0 */   sb        $zero, %lo(_findCurrentSaveSubState)($v1)
  .L801050B4:
    /* 28B4 801050B4 1180133C */  lui        $s3, %hi(_findCurrentSaveState)
    /* 28B8 801050B8 A4AA6292 */  lbu        $v0, %lo(_findCurrentSaveState)($s3)
    /* 28BC 801050BC 00000000 */  nop
    /* 28C0 801050C0 42800200 */  srl        $s0, $v0, 1
    /* 28C4 801050C4 01004230 */  andi       $v0, $v0, 0x1
    /* 28C8 801050C8 18004014 */  bnez       $v0, .L8010512C
    /* 28CC 801050CC 01001226 */   addiu     $s2, $s0, 0x1
    /* 28D0 801050D0 1180113C */  lui        $s1, %hi(_textTable)
    /* 28D4 801050D4 F8AD238E */  lw         $v1, %lo(_textTable)($s1)
    /* 28D8 801050D8 40801200 */  sll        $s0, $s2, 1
    /* 28DC 801050DC 21100302 */  addu       $v0, $s0, $v1
    /* 28E0 801050E0 2A004494 */  lhu        $a0, 0x2A($v0)
    /* 28E4 801050E4 00000000 */  nop
    /* 28E8 801050E8 40200400 */  sll        $a0, $a0, 1
    /* 28EC 801050EC 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 28F0 801050F0 21206400 */   addu      $a0, $v1, $a0
    /* 28F4 801050F4 F8AD238E */  lw         $v1, %lo(_textTable)($s1)
    /* 28F8 801050F8 21204002 */  addu       $a0, $s2, $zero
    /* 28FC 801050FC 21800302 */  addu       $s0, $s0, $v1
    /* 2900 80105100 2A000296 */  lhu        $v0, 0x2A($s0)
    /* 2904 80105104 1180053C */  lui        $a1, %hi(_memoryCardMessage)
    /* 2908 80105108 40100200 */  sll        $v0, $v0, 1
    /* 290C 8010510C 21186200 */  addu       $v1, $v1, $v0
    /* 2910 80105110 F70C040C */  jal        _memcardEventHandler
    /* 2914 80105114 A4B0A3AC */   sw        $v1, %lo(_memoryCardMessage)($a1)
    /* 2918 80105118 A4AA6292 */  lbu        $v0, %lo(_findCurrentSaveState)($s3)
    /* 291C 8010511C 00000000 */  nop
    /* 2920 80105120 01004224 */  addiu      $v0, $v0, 0x1
    /* 2924 80105124 6F140408 */  j          .L801051BC
    /* 2928 80105128 A4AA62A2 */   sb        $v0, %lo(_findCurrentSaveState)($s3)
  .L8010512C:
    /* 292C 8010512C F70C040C */  jal        _memcardEventHandler
    /* 2930 80105130 21200000 */   addu      $a0, $zero, $zero
    /* 2934 80105134 03004330 */  andi       $v1, $v0, 0x3
    /* 2938 80105138 20006010 */  beqz       $v1, .L801051BC
    /* 293C 8010513C 01000424 */   addiu     $a0, $zero, 0x1
    /* 2940 80105140 0C006414 */  bne        $v1, $a0, .L80105174
    /* 2944 80105144 02000224 */   addiu     $v0, $zero, 0x2
    /* 2948 80105148 4D0C040C */  jal        _initSaveFileInfo
    /* 294C 8010514C 21204002 */   addu      $a0, $s2, $zero
    /* 2950 80105150 16004014 */  bnez       $v0, .L801051AC
    /* 2954 80105154 1180033C */   lui       $v1, %hi(_findCurrentSaveState)
    /* 2958 80105158 450B040C */  jal        _findCurrentSaveOnActiveMemcard
    /* 295C 8010515C 00000000 */   nop
    /* 2960 80105160 21184000 */  addu       $v1, $v0, $zero
    /* 2964 80105164 10006010 */  beqz       $v1, .L801051A8
    /* 2968 80105168 00111000 */   sll       $v0, $s0, 4
    /* 296C 8010516C 76140408 */  j          .L801051D8
    /* 2970 80105170 21106200 */   addu      $v0, $v1, $v0
  .L80105174:
    /* 2974 80105174 0D006214 */  bne        $v1, $v0, .L801051AC
    /* 2978 80105178 1180033C */   lui       $v1, %hi(_findCurrentSaveState)
    /* 297C 8010517C A4AA6392 */  lbu        $v1, %lo(_findCurrentSaveState)($s3)
    /* 2980 80105180 00000000 */  nop
    /* 2984 80105184 07006410 */  beq        $v1, $a0, .L801051A4
    /* 2988 80105188 1180023C */   lui       $v0, %hi(_findCurrentSaveSubState)
    /* 298C 8010518C A5AA4290 */  lbu        $v0, %lo(_findCurrentSaveSubState)($v0)
    /* 2990 80105190 00000000 */  nop
    /* 2994 80105194 04004010 */  beqz       $v0, .L801051A8
    /* 2998 80105198 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 299C 8010519C 76140408 */  j          .L801051D8
    /* 29A0 801051A0 00000000 */   nop
  .L801051A4:
    /* 29A4 801051A4 A5AA43A0 */  sb         $v1, %lo(_findCurrentSaveSubState)($v0)
  .L801051A8:
    /* 29A8 801051A8 1180033C */  lui        $v1, %hi(_findCurrentSaveState)
  .L801051AC:
    /* 29AC 801051AC A4AA6290 */  lbu        $v0, %lo(_findCurrentSaveState)($v1)
    /* 29B0 801051B0 00000000 */  nop
    /* 29B4 801051B4 01004224 */  addiu      $v0, $v0, 0x1
    /* 29B8 801051B8 A4AA62A0 */  sb         $v0, %lo(_findCurrentSaveState)($v1)
  .L801051BC:
    /* 29BC 801051BC 1180023C */  lui        $v0, %hi(_findCurrentSaveState)
    /* 29C0 801051C0 A4AA4390 */  lbu        $v1, %lo(_findCurrentSaveState)($v0)
    /* 29C4 801051C4 04000224 */  addiu      $v0, $zero, 0x4
    /* 29C8 801051C8 02006214 */  bne        $v1, $v0, .L801051D4
    /* 29CC 801051CC 21200000 */   addu      $a0, $zero, $zero
    /* 29D0 801051D0 FFFF0424 */  addiu      $a0, $zero, -0x1
  .L801051D4:
    /* 29D4 801051D4 21108000 */  addu       $v0, $a0, $zero
  .L801051D8:
    /* 29D8 801051D8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 29DC 801051DC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 29E0 801051E0 1800B28F */  lw         $s2, 0x18($sp)
    /* 29E4 801051E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 29E8 801051E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 29EC 801051EC 0800E003 */  jr         $ra
    /* 29F0 801051F0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _findCurrentSave
