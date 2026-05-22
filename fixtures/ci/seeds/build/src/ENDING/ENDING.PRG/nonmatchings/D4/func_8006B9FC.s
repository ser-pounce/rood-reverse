nonmatching func_8006B9FC, 0x37C

glabel func_8006B9FC
    /* 31FC 8006B9FC 0680033C */  lui        $v1, %hi(vs_main_scoredata)
    /* 3200 8006BA00 A0FE6224 */  addiu      $v0, $v1, %lo(vs_main_scoredata)
    /* 3204 8006BA04 9000428C */  lw         $v0, 0x90($v0)
    /* 3208 8006BA08 00000000 */  nop
    /* 320C 8006BA0C 5802422C */  sltiu      $v0, $v0, 0x258
    /* 3210 8006BA10 05004010 */  beqz       $v0, .L8006BA28
    /* 3214 8006BA14 B8000524 */   addiu     $a1, $zero, 0xB8
    /* 3218 8006BA18 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 321C 8006BA1C 00000000 */  nop
    /* 3220 8006BA20 02004234 */  ori        $v0, $v0, 0x2
    /* 3224 8006BA24 A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BA28:
    /* 3228 8006BA28 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 322C 8006BA2C DCB94224 */  addiu      $v0, $v0, %lo(vs_main_skills)
    /* 3230 8006BA30 60254324 */  addiu      $v1, $v0, 0x2560
  .L8006BA34:
    /* 3234 8006BA34 0C00628C */  lw         $v0, 0xC($v1)
    /* 3238 8006BA38 00000000 */  nop
    /* 323C 8006BA3C C2130200 */  srl        $v0, $v0, 15
    /* 3240 8006BA40 01004230 */  andi       $v0, $v0, 0x1
    /* 3244 8006BA44 06004010 */  beqz       $v0, .L8006BA60
    /* 3248 8006BA48 E0000224 */   addiu     $v0, $zero, 0xE0
    /* 324C 8006BA4C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3250 8006BA50 E000A228 */  slti       $v0, $a1, 0xE0
    /* 3254 8006BA54 F7FF4014 */  bnez       $v0, .L8006BA34
    /* 3258 8006BA58 34006324 */   addiu     $v1, $v1, 0x34
    /* 325C 8006BA5C E0000224 */  addiu      $v0, $zero, 0xE0
  .L8006BA60:
    /* 3260 8006BA60 0600A214 */  bne        $a1, $v0, .L8006BA7C
    /* 3264 8006BA64 16000524 */   addiu     $a1, $zero, 0x16
    /* 3268 8006BA68 0680033C */  lui        $v1, %hi(vs_main_scoredata)
    /* 326C 8006BA6C A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3270 8006BA70 00000000 */  nop
    /* 3274 8006BA74 00404234 */  ori        $v0, $v0, 0x4000
    /* 3278 8006BA78 A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BA7C:
    /* 327C 8006BA7C 21000824 */  addiu      $t0, $zero, 0x21
    /* 3280 8006BA80 24000724 */  addiu      $a3, $zero, 0x24
    /* 3284 8006BA84 26000624 */  addiu      $a2, $zero, 0x26
    /* 3288 8006BA88 27000424 */  addiu      $a0, $zero, 0x27
    /* 328C 8006BA8C 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 3290 8006BA90 DCB94224 */  addiu      $v0, $v0, %lo(vs_main_skills)
    /* 3294 8006BA94 78044324 */  addiu      $v1, $v0, 0x478
  .L8006BA98:
    /* 3298 8006BA98 0D00A810 */  beq        $a1, $t0, .L8006BAD0
    /* 329C 8006BA9C 00000000 */   nop
    /* 32A0 8006BAA0 0B00A710 */  beq        $a1, $a3, .L8006BAD0
    /* 32A4 8006BAA4 00000000 */   nop
    /* 32A8 8006BAA8 0900A610 */  beq        $a1, $a2, .L8006BAD0
    /* 32AC 8006BAAC 00000000 */   nop
    /* 32B0 8006BAB0 0700A410 */  beq        $a1, $a0, .L8006BAD0
    /* 32B4 8006BAB4 00000000 */   nop
    /* 32B8 8006BAB8 0C00628C */  lw         $v0, 0xC($v1)
    /* 32BC 8006BABC 00000000 */  nop
    /* 32C0 8006BAC0 C2130200 */  srl        $v0, $v0, 15
    /* 32C4 8006BAC4 01004230 */  andi       $v0, $v0, 0x1
    /* 32C8 8006BAC8 06004010 */  beqz       $v0, .L8006BAE4
    /* 32CC 8006BACC 36000224 */   addiu     $v0, $zero, 0x36
  .L8006BAD0:
    /* 32D0 8006BAD0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 32D4 8006BAD4 3600A228 */  slti       $v0, $a1, 0x36
    /* 32D8 8006BAD8 EFFF4014 */  bnez       $v0, .L8006BA98
    /* 32DC 8006BADC 34006324 */   addiu     $v1, $v1, 0x34
    /* 32E0 8006BAE0 36000224 */  addiu      $v0, $zero, 0x36
  .L8006BAE4:
    /* 32E4 8006BAE4 0700A214 */  bne        $a1, $v0, .L8006BB04
    /* 32E8 8006BAE8 0680023C */   lui       $v0, %hi(D_8006003A)
    /* 32EC 8006BAEC 0680033C */  lui        $v1, %hi(vs_main_scoredata)
    /* 32F0 8006BAF0 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 32F4 8006BAF4 00000000 */  nop
    /* 32F8 8006BAF8 00804234 */  ori        $v0, $v0, 0x8000
    /* 32FC 8006BAFC A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3300 8006BB00 0680023C */  lui        $v0, %hi(D_8006003A)
  .L8006BB04:
    /* 3304 8006BB04 3A004294 */  lhu        $v0, %lo(D_8006003A)($v0)
    /* 3308 8006BB08 00000000 */  nop
    /* 330C 8006BB0C 07004014 */  bnez       $v0, .L8006BB2C
    /* 3310 8006BB10 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 3314 8006BB14 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 3318 8006BB18 A0FE438C */  lw         $v1, %lo(vs_main_scoredata)($v0)
    /* 331C 8006BB1C 0100043C */  lui        $a0, (0x10000 >> 16)
    /* 3320 8006BB20 25186400 */  or         $v1, $v1, $a0
    /* 3324 8006BB24 A0FE43AC */  sw         $v1, %lo(vs_main_scoredata)($v0)
    /* 3328 8006BB28 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
  .L8006BB2C:
    /* 332C 8006BB2C 98154524 */  addiu      $a1, $v0, %lo(vs_main_stateFlags)
    /* 3330 8006BB30 B700A290 */  lbu        $v0, 0xB7($a1)
    /* 3334 8006BB34 00000000 */  nop
    /* 3338 8006BB38 05004014 */  bnez       $v0, .L8006BB50
    /* 333C 8006BB3C 0680023C */   lui       $v0, %hi(vs_main_scoredata)
    /* 3340 8006BB40 A0FE438C */  lw         $v1, %lo(vs_main_scoredata)($v0)
    /* 3344 8006BB44 0200043C */  lui        $a0, (0x20000 >> 16)
    /* 3348 8006BB48 25186400 */  or         $v1, $v1, $a0
    /* 334C 8006BB4C A0FE43AC */  sw         $v1, %lo(vs_main_scoredata)($v0)
  .L8006BB50:
    /* 3350 8006BB50 B800A290 */  lbu        $v0, 0xB8($a1)
    /* 3354 8006BB54 00000000 */  nop
    /* 3358 8006BB58 05004014 */  bnez       $v0, .L8006BB70
    /* 335C 8006BB5C 0680023C */   lui       $v0, %hi(vs_main_scoredata)
    /* 3360 8006BB60 A0FE438C */  lw         $v1, %lo(vs_main_scoredata)($v0)
    /* 3364 8006BB64 0400043C */  lui        $a0, (0x40000 >> 16)
    /* 3368 8006BB68 25186400 */  or         $v1, $v1, $a0
    /* 336C 8006BB6C A0FE43AC */  sw         $v1, %lo(vs_main_scoredata)($v0)
  .L8006BB70:
    /* 3370 8006BB70 B900A290 */  lbu        $v0, 0xB9($a1)
    /* 3374 8006BB74 00000000 */  nop
    /* 3378 8006BB78 06004014 */  bnez       $v0, .L8006BB94
    /* 337C 8006BB7C 21300000 */   addu      $a2, $zero, $zero
    /* 3380 8006BB80 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 3384 8006BB84 A0FE438C */  lw         $v1, %lo(vs_main_scoredata)($v0)
    /* 3388 8006BB88 0800043C */  lui        $a0, (0x80000 >> 16)
    /* 338C 8006BB8C 25186400 */  or         $v1, $v1, $a0
    /* 3390 8006BB90 A0FE43AC */  sw         $v1, %lo(vs_main_scoredata)($v0)
  .L8006BB94:
    /* 3394 8006BB94 2128C000 */  addu       $a1, $a2, $zero
    /* 3398 8006BB98 01000924 */  addiu      $t1, $zero, 0x1
    /* 339C 8006BB9C 0E80023C */  lui        $v0, %hi(D_800DB7D4)
    /* 33A0 8006BBA0 D4B74824 */  addiu      $t0, $v0, %lo(D_800DB7D4)
    /* 33A4 8006BBA4 0680023C */  lui        $v0, %hi(vs_main_mapStatus)
    /* 33A8 8006BBA8 D8FF4724 */  addiu      $a3, $v0, %lo(vs_main_mapStatus)
  .L8006BBAC:
    /* 33AC 8006BBAC 0000E38C */  lw         $v1, 0x0($a3)
    /* 33B0 8006BBB0 0000028D */  lw         $v0, 0x0($t0)
    /* 33B4 8006BBB4 21200000 */  addu       $a0, $zero, $zero
    /* 33B8 8006BBB8 24186200 */  and        $v1, $v1, $v0
    /* 33BC 8006BBBC 04108900 */  sllv       $v0, $t1, $a0
  .L8006BBC0:
    /* 33C0 8006BBC0 24106200 */  and        $v0, $v1, $v0
    /* 33C4 8006BBC4 02004010 */  beqz       $v0, .L8006BBD0
    /* 33C8 8006BBC8 00000000 */   nop
    /* 33CC 8006BBCC 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BBD0:
    /* 33D0 8006BBD0 01008424 */  addiu      $a0, $a0, 0x1
    /* 33D4 8006BBD4 20008228 */  slti       $v0, $a0, 0x20
    /* 33D8 8006BBD8 F9FF4014 */  bnez       $v0, .L8006BBC0
    /* 33DC 8006BBDC 04108900 */   sllv      $v0, $t1, $a0
    /* 33E0 8006BBE0 04000825 */  addiu      $t0, $t0, 0x4
    /* 33E4 8006BBE4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 33E8 8006BBE8 1000A228 */  slti       $v0, $a1, 0x10
    /* 33EC 8006BBEC EFFF4014 */  bnez       $v0, .L8006BBAC
    /* 33F0 8006BBF0 0400E724 */   addiu     $a3, $a3, 0x4
    /* 33F4 8006BBF4 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 33F8 8006BBF8 A0FE4324 */  addiu      $v1, $v0, %lo(vs_main_scoredata)
    /* 33FC 8006BBFC 9400628C */  lw         $v0, 0x94($v1)
    /* 3400 8006BC00 00000000 */  nop
    /* 3404 8006BC04 2B104600 */  sltu       $v0, $v0, $a2
    /* 3408 8006BC08 02004010 */  beqz       $v0, .L8006BC14
    /* 340C 8006BC0C 00000000 */   nop
    /* 3410 8006BC10 940066AC */  sw         $a2, 0x94($v1)
  .L8006BC14:
    /* 3414 8006BC14 21300000 */  addu       $a2, $zero, $zero
    /* 3418 8006BC18 2128C000 */  addu       $a1, $a2, $zero
    /* 341C 8006BC1C 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 3420 8006BC20 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 3424 8006BC24 2110A300 */  addu       $v0, $a1, $v1
  .L8006BC28:
    /* 3428 8006BC28 C0034290 */  lbu        $v0, 0x3C0($v0)
    /* 342C 8006BC2C 00000000 */  nop
    /* 3430 8006BC30 02004010 */  beqz       $v0, .L8006BC3C
    /* 3434 8006BC34 00000000 */   nop
    /* 3438 8006BC38 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BC3C:
    /* 343C 8006BC3C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 3440 8006BC40 4000A228 */  slti       $v0, $a1, 0x40
    /* 3444 8006BC44 F8FF4014 */  bnez       $v0, .L8006BC28
    /* 3448 8006BC48 2110A300 */   addu      $v0, $a1, $v1
    /* 344C 8006BC4C 0680033C */  lui        $v1, %hi(vs_main_scoredata)
    /* 3450 8006BC50 A0FE6424 */  addiu      $a0, $v1, %lo(vs_main_scoredata)
    /* 3454 8006BC54 9800828C */  lw         $v0, 0x98($a0)
    /* 3458 8006BC58 00000000 */  nop
    /* 345C 8006BC5C 2B104600 */  sltu       $v0, $v0, $a2
    /* 3460 8006BC60 02004010 */  beqz       $v0, .L8006BC6C
    /* 3464 8006BC64 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 3468 8006BC68 980086AC */  sw         $a2, 0x98($a0)
  .L8006BC6C:
    /* 346C 8006BC6C 98154424 */  addiu      $a0, $v0, %lo(vs_main_stateFlags)
    /* 3470 8006BC70 CC008290 */  lbu        $v0, 0xCC($a0)
    /* 3474 8006BC74 00000000 */  nop
    /* 3478 8006BC78 05004010 */  beqz       $v0, .L8006BC90
    /* 347C 8006BC7C 00000000 */   nop
    /* 3480 8006BC80 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3484 8006BC84 00000000 */  nop
    /* 3488 8006BC88 10004234 */  ori        $v0, $v0, 0x10
    /* 348C 8006BC8C A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BC90:
    /* 3490 8006BC90 CD008290 */  lbu        $v0, 0xCD($a0)
    /* 3494 8006BC94 00000000 */  nop
    /* 3498 8006BC98 05004010 */  beqz       $v0, .L8006BCB0
    /* 349C 8006BC9C 00000000 */   nop
    /* 34A0 8006BCA0 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 34A4 8006BCA4 00000000 */  nop
    /* 34A8 8006BCA8 20004234 */  ori        $v0, $v0, 0x20
    /* 34AC 8006BCAC A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BCB0:
    /* 34B0 8006BCB0 CE008290 */  lbu        $v0, 0xCE($a0)
    /* 34B4 8006BCB4 00000000 */  nop
    /* 34B8 8006BCB8 05004010 */  beqz       $v0, .L8006BCD0
    /* 34BC 8006BCBC 00000000 */   nop
    /* 34C0 8006BCC0 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 34C4 8006BCC4 00000000 */  nop
    /* 34C8 8006BCC8 40004234 */  ori        $v0, $v0, 0x40
    /* 34CC 8006BCCC A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BCD0:
    /* 34D0 8006BCD0 CF008290 */  lbu        $v0, 0xCF($a0)
    /* 34D4 8006BCD4 00000000 */  nop
    /* 34D8 8006BCD8 05004010 */  beqz       $v0, .L8006BCF0
    /* 34DC 8006BCDC 00000000 */   nop
    /* 34E0 8006BCE0 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 34E4 8006BCE4 00000000 */  nop
    /* 34E8 8006BCE8 80004234 */  ori        $v0, $v0, 0x80
    /* 34EC 8006BCEC A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BCF0:
    /* 34F0 8006BCF0 D0008290 */  lbu        $v0, 0xD0($a0)
    /* 34F4 8006BCF4 00000000 */  nop
    /* 34F8 8006BCF8 05004010 */  beqz       $v0, .L8006BD10
    /* 34FC 8006BCFC 00000000 */   nop
    /* 3500 8006BD00 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3504 8006BD04 00000000 */  nop
    /* 3508 8006BD08 00014234 */  ori        $v0, $v0, 0x100
    /* 350C 8006BD0C A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BD10:
    /* 3510 8006BD10 D1008290 */  lbu        $v0, 0xD1($a0)
    /* 3514 8006BD14 00000000 */  nop
    /* 3518 8006BD18 05004010 */  beqz       $v0, .L8006BD30
    /* 351C 8006BD1C 00000000 */   nop
    /* 3520 8006BD20 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3524 8006BD24 00000000 */  nop
    /* 3528 8006BD28 00024234 */  ori        $v0, $v0, 0x200
    /* 352C 8006BD2C A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BD30:
    /* 3530 8006BD30 83038290 */  lbu        $v0, 0x383($a0)
    /* 3534 8006BD34 00000000 */  nop
    /* 3538 8006BD38 05004010 */  beqz       $v0, .L8006BD50
    /* 353C 8006BD3C 00000000 */   nop
    /* 3540 8006BD40 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3544 8006BD44 00000000 */  nop
    /* 3548 8006BD48 00104234 */  ori        $v0, $v0, 0x1000
    /* 354C 8006BD4C A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BD50:
    /* 3550 8006BD50 87038290 */  lbu        $v0, 0x387($a0)
    /* 3554 8006BD54 00000000 */  nop
    /* 3558 8006BD58 05004010 */  beqz       $v0, .L8006BD70
    /* 355C 8006BD5C 00000000 */   nop
    /* 3560 8006BD60 A0FE628C */  lw         $v0, %lo(vs_main_scoredata)($v1)
    /* 3564 8006BD64 00000000 */  nop
    /* 3568 8006BD68 00204234 */  ori        $v0, $v0, 0x2000
    /* 356C 8006BD6C A0FE62AC */  sw         $v0, %lo(vs_main_scoredata)($v1)
  .L8006BD70:
    /* 3570 8006BD70 0800E003 */  jr         $ra
    /* 3574 8006BD74 00000000 */   nop
endlabel func_8006B9FC
