nonmatching vs_mainMenu_printInformation, 0xA4

glabel vs_mainMenu_printInformation
    /* 61E4 800FF9E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 61E8 800FF9E8 1000A528 */  slti       $a1, $a1, 0x10
    /* 61EC 800FF9EC 2200A014 */  bnez       $a1, .L800FFA78
    /* 61F0 800FF9F0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 61F4 800FF9F4 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 61F8 800FF9F8 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 61FC 800FF9FC 80100400 */  sll        $v0, $a0, 2
    /* 6200 800FFA00 21104300 */  addu       $v0, $v0, $v1
    /* 6204 800FFA04 0000428C */  lw         $v0, 0x0($v0)
    /* 6208 800FFA08 00000000 */  nop
    /* 620C 800FFA0C 01004230 */  andi       $v0, $v0, 0x1
    /* 6210 800FFA10 0D004010 */  beqz       $v0, .L800FFA48
    /* 6214 800FFA14 0680023C */   lui       $v0, %hi(D_80060028)
    /* 6218 800FFA18 28004290 */  lbu        $v0, %lo(D_80060028)($v0)
    /* 621C 800FFA1C 00000000 */  nop
    /* 6220 800FFA20 0D004014 */  bnez       $v0, .L800FFA58
    /* 6224 800FFA24 01000424 */   addiu     $a0, $zero, 0x1
    /* 6228 800FFA28 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
    /* 622C 800FFA2C 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 6230 800FFA30 00000000 */  nop
    /* 6234 800FFA34 00504230 */  andi       $v0, $v0, 0x5000
    /* 6238 800FFA38 07004010 */  beqz       $v0, .L800FFA58
    /* 623C 800FFA3C 00000000 */   nop
    /* 6240 800FFA40 9EFE0308 */  j          .L800FFA78
    /* 6244 800FFA44 00000000 */   nop
  .L800FFA48:
    /* 6248 800FFA48 28004290 */  lbu        $v0, %lo(D_80060028)($v0)
    /* 624C 800FFA4C 00000000 */  nop
    /* 6250 800FFA50 07004010 */  beqz       $v0, .L800FFA70
    /* 6254 800FFA54 02000424 */   addiu     $a0, $zero, 0x2
  .L800FFA58:
    /* 6258 800FFA58 8123030C */  jal        func_800C8E04
    /* 625C 800FFA5C 00000000 */   nop
    /* 6260 800FFA60 0F80033C */  lui        $v1, %hi(D_800F514C)
    /* 6264 800FFA64 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6268 800FFA68 9EFE0308 */  j          .L800FFA78
    /* 626C 800FFA6C 4C5162A4 */   sh        $v0, %lo(D_800F514C)($v1)
  .L800FFA70:
    /* 6270 800FFA70 0F80023C */  lui        $v0, %hi(D_800F514C)
    /* 6274 800FFA74 4C5140A4 */  sh         $zero, %lo(D_800F514C)($v0)
  .L800FFA78:
    /* 6278 800FFA78 1000BF8F */  lw         $ra, 0x10($sp)
    /* 627C 800FFA7C 00000000 */  nop
    /* 6280 800FFA80 0800E003 */  jr         $ra
    /* 6284 800FFA84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_printInformation
