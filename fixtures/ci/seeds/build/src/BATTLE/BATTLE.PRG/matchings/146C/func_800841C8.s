nonmatching func_800841C8, 0x60

glabel func_800841C8
    /* 1B9C8 800841C8 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1B9CC 800841CC 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1B9D0 800841D0 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1B9D4 800841D4 80100200 */  sll        $v0, $v0, 2
    /* 1B9D8 800841D8 21104300 */  addu       $v0, $v0, $v1
    /* 1B9DC 800841DC 0000428C */  lw         $v0, 0x0($v0)
    /* 1B9E0 800841E0 00000000 */  nop
    /* 1B9E4 800841E4 3C00428C */  lw         $v0, 0x3C($v0)
    /* 1B9E8 800841E8 00000000 */  nop
    /* 1B9EC 800841EC 4809438C */  lw         $v1, 0x948($v0)
    /* 1B9F0 800841F0 1800C28C */  lw         $v0, 0x18($a2)
    /* 1B9F4 800841F4 00E06330 */  andi       $v1, $v1, 0xE000
    /* 1B9F8 800841F8 25104300 */  or         $v0, $v0, $v1
    /* 1B9FC 800841FC 08006010 */  beqz       $v1, .L80084220
    /* 1BA00 80084200 1800C2AC */   sw        $v0, 0x18($a2)
    /* 1BA04 80084204 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1BA08 80084208 1C00C38C */  lw         $v1, 0x1C($a2)
    /* 1BA0C 8008420C FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1BA10 80084210 24186200 */  and        $v1, $v1, $v0
    /* 1BA14 80084214 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1BA18 80084218 25186200 */  or         $v1, $v1, $v0
    /* 1BA1C 8008421C 1C00C3AC */  sw         $v1, 0x1C($a2)
  .L80084220:
    /* 1BA20 80084220 0800E003 */  jr         $ra
    /* 1BA24 80084224 00000000 */   nop
endlabel func_800841C8
