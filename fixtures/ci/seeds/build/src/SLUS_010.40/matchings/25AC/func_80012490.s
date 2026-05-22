nonmatching func_80012490, 0x6C

glabel func_80012490
    /* 2C90 80012490 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C94 80012494 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C98 80012498 0F008210 */  beq        $a0, $v0, .L800124D8
    /* 2C9C 8001249C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2CA0 800124A0 0300822C */  sltiu      $v0, $a0, 0x3
    /* 2CA4 800124A4 05004010 */  beqz       $v0, .L800124BC
    /* 2CA8 800124A8 01000224 */   addiu     $v0, $zero, 0x1
    /* 2CAC 800124AC 08008210 */  beq        $a0, $v0, .L800124D0
    /* 2CB0 800124B0 99000424 */   addiu     $a0, $zero, 0x99
    /* 2CB4 800124B4 39490008 */  j          .L800124E4
    /* 2CB8 800124B8 00000000 */   nop
  .L800124BC:
    /* 2CBC 800124BC 03000224 */  addiu      $v0, $zero, 0x3
    /* 2CC0 800124C0 07008210 */  beq        $a0, $v0, .L800124E0
    /* 2CC4 800124C4 99000424 */   addiu     $a0, $zero, 0x99
    /* 2CC8 800124C8 39490008 */  j          .L800124E4
    /* 2CCC 800124CC 00000000 */   nop
  .L800124D0:
    /* 2CD0 800124D0 39490008 */  j          .L800124E4
    /* 2CD4 800124D4 9B000424 */   addiu     $a0, $zero, 0x9B
  .L800124D8:
    /* 2CD8 800124D8 39490008 */  j          .L800124E4
    /* 2CDC 800124DC 9D000424 */   addiu     $a0, $zero, 0x9D
  .L800124E0:
    /* 2CE0 800124E0 9F000424 */  addiu      $a0, $zero, 0x9F
  .L800124E4:
    /* 2CE4 800124E4 0C63000C */  jal        func_80018C30
    /* 2CE8 800124E8 00000000 */   nop
    /* 2CEC 800124EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2CF0 800124F0 00000000 */  nop
    /* 2CF4 800124F4 0800E003 */  jr         $ra
    /* 2CF8 800124F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012490
