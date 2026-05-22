nonmatching _diskReadCommandCallback, 0x7C

glabel _diskReadCommandCallback
    /* 34948 80044148 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3494C 8004414C FF008430 */  andi       $a0, $a0, 0xFF
    /* 34950 80044150 02000224 */  addiu      $v0, $zero, 0x2
    /* 34954 80044154 0E008210 */  beq        $a0, $v0, .L80044190
    /* 34958 80044158 1000BFAF */   sw        $ra, 0x10($sp)
    /* 3495C 8004415C 03008228 */  slti       $v0, $a0, 0x3
    /* 34960 80044160 05004010 */  beqz       $v0, .L80044178
    /* 34964 80044164 05000224 */   addiu     $v0, $zero, 0x5
    /* 34968 80044168 12008010 */  beqz       $a0, .L800441B4
    /* 3496C 8004416C 0580033C */   lui       $v1, %hi(vs_main_disk)
    /* 34970 80044170 6C100108 */  j          .L800441B0
    /* 34974 80044174 04000224 */   addiu     $v0, $zero, 0x4
  .L80044178:
    /* 34978 80044178 0B008210 */  beq        $a0, $v0, .L800441A8
    /* 3497C 8004417C 06000224 */   addiu     $v0, $zero, 0x6
    /* 34980 80044180 0C008210 */  beq        $a0, $v0, .L800441B4
    /* 34984 80044184 0580033C */   lui       $v1, %hi(vs_main_disk)
    /* 34988 80044188 6C100108 */  j          .L800441B0
    /* 3498C 8004418C 04000224 */   addiu     $v0, $zero, 0x4
  .L80044190:
    /* 34990 80044190 0480043C */  lui        $a0, %hi(_diskReadCallback)
    /* 34994 80044194 B43F8424 */  addiu      $a0, $a0, %lo(_diskReadCallback)
    /* 34998 80044198 9998000C */  jal        DsStartReadySystem
    /* 3499C 8004419C FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 349A0 800441A0 6D100108 */  j          .L800441B4
    /* 349A4 800441A4 00000000 */   nop
  .L800441A8:
    /* 349A8 800441A8 0580033C */  lui        $v1, %hi(vs_main_disk)
    /* 349AC 800441AC 04000224 */  addiu      $v0, $zero, 0x4
  .L800441B0:
    /* 349B0 800441B0 105D62A0 */  sb         $v0, %lo(vs_main_disk)($v1)
  .L800441B4:
    /* 349B4 800441B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 349B8 800441B8 00000000 */  nop
    /* 349BC 800441BC 0800E003 */  jr         $ra
    /* 349C0 800441C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _diskReadCommandCallback
