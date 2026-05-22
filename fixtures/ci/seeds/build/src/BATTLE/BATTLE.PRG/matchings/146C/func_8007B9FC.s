nonmatching func_8007B9FC, 0x9C

glabel func_8007B9FC
    /* 131FC 8007B9FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13200 8007BA00 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 13204 8007BA04 F018438C */  lw         $v1, %lo(_cameraMode)($v0)
    /* 13208 8007BA08 04000224 */  addiu      $v0, $zero, 0x4
    /* 1320C 8007BA0C 13006210 */  beq        $v1, $v0, .L8007BA5C
    /* 13210 8007BA10 1000BFAF */   sw        $ra, 0x10($sp)
    /* 13214 8007BA14 0500622C */  sltiu      $v0, $v1, 0x5
    /* 13218 8007BA18 05004010 */  beqz       $v0, .L8007BA30
    /* 1321C 8007BA1C 03000224 */   addiu     $v0, $zero, 0x3
    /* 13220 8007BA20 0A006210 */  beq        $v1, $v0, .L8007BA4C
    /* 13224 8007BA24 21100000 */   addu      $v0, $zero, $zero
    /* 13228 8007BA28 A2EE0108 */  j          .L8007BA88
    /* 1322C 8007BA2C 00000000 */   nop
  .L8007BA30:
    /* 13230 8007BA30 05000224 */  addiu      $v0, $zero, 0x5
    /* 13234 8007BA34 0D006210 */  beq        $v1, $v0, .L8007BA6C
    /* 13238 8007BA38 06000224 */   addiu     $v0, $zero, 0x6
    /* 1323C 8007BA3C 0F006210 */  beq        $v1, $v0, .L8007BA7C
    /* 13240 8007BA40 21100000 */   addu      $v0, $zero, $zero
    /* 13244 8007BA44 A2EE0108 */  j          .L8007BA88
    /* 13248 8007BA48 00000000 */   nop
  .L8007BA4C:
    /* 1324C 8007BA4C 0DEE010C */  jal        func_8007B834
    /* 13250 8007BA50 00000000 */   nop
    /* 13254 8007BA54 A2EE0108 */  j          .L8007BA88
    /* 13258 8007BA58 01000224 */   addiu     $v0, $zero, 0x1
  .L8007BA5C:
    /* 1325C 8007BA5C 21EE010C */  jal        func_8007B884
    /* 13260 8007BA60 00000000 */   nop
    /* 13264 8007BA64 A2EE0108 */  j          .L8007BA88
    /* 13268 8007BA68 01000224 */   addiu     $v0, $zero, 0x1
  .L8007BA6C:
    /* 1326C 8007BA6C 42EE010C */  jal        func_8007B908
    /* 13270 8007BA70 00000000 */   nop
    /* 13274 8007BA74 A2EE0108 */  j          .L8007BA88
    /* 13278 8007BA78 01000224 */   addiu     $v0, $zero, 0x1
  .L8007BA7C:
    /* 1327C 8007BA7C 4EEE010C */  jal        func_8007B938
    /* 13280 8007BA80 00000000 */   nop
    /* 13284 8007BA84 01000224 */  addiu      $v0, $zero, 0x1
  .L8007BA88:
    /* 13288 8007BA88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1328C 8007BA8C 00000000 */  nop
    /* 13290 8007BA90 0800E003 */  jr         $ra
    /* 13294 8007BA94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B9FC
