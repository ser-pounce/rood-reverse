nonmatching func_800D61AC, 0xEC

glabel func_800D61AC
    /* 6D9AC 800D61AC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6D9B0 800D61B0 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6D9B4 800D61B4 21A0A000 */  addu       $s4, $a1, $zero
    /* 6D9B8 800D61B8 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6D9BC 800D61BC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6D9C0 800D61C0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 6D9C4 800D61C4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6D9C8 800D61C8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6D9CC 800D61CC 06008286 */  lh         $v0, 0x6($s4)
    /* 6D9D0 800D61D0 0000838E */  lw         $v1, 0x0($s4)
    /* 6D9D4 800D61D4 C0100200 */  sll        $v0, $v0, 3
    /* 6D9D8 800D61D8 21906200 */  addu       $s2, $v1, $v0
    /* 6D9DC 800D61DC 4C0D828C */  lw         $v0, 0xD4C($a0)
    /* 6D9E0 800D61E0 00004386 */  lh         $v1, 0x0($s2)
    /* 6D9E4 800D61E4 02004284 */  lh         $v0, 0x2($v0)
    /* 6D9E8 800D61E8 00000000 */  nop
    /* 6D9EC 800D61EC 22006214 */  bne        $v1, $v0, .L800D6278
    /* 6D9F0 800D61F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D9F4 800D61F4 0F80023C */  lui        $v0, %hi(D_800F5230)
    /* 6D9F8 800D61F8 30524324 */  addiu      $v1, $v0, %lo(D_800F5230)
    /* 6D9FC 800D61FC 03006290 */  lbu        $v0, 0x3($v1)
    /* 6DA00 800D6200 00000000 */  nop
    /* 6DA04 800D6204 1A004010 */  beqz       $v0, .L800D6270
    /* 6DA08 800D6208 21880000 */   addu      $s1, $zero, $zero
    /* 6DA0C 800D620C 21986000 */  addu       $s3, $v1, $zero
    /* 6DA10 800D6210 21803302 */  addu       $s0, $s1, $s3
  .L800D6214:
    /* 6DA14 800D6214 D0000492 */  lbu        $a0, 0xD0($s0)
    /* 6DA18 800D6218 F882020C */  jal        func_800A0BE0
    /* 6DA1C 800D621C 00000000 */   nop
    /* 6DA20 800D6220 02004230 */  andi       $v0, $v0, 0x2
    /* 6DA24 800D6224 0D004010 */  beqz       $v0, .L800D625C
    /* 6DA28 800D6228 00000000 */   nop
    /* 6DA2C 800D622C 07004492 */  lbu        $a0, 0x7($s2)
    /* 6DA30 800D6230 02004586 */  lh         $a1, 0x2($s2)
    /* 6DA34 800D6234 D0000692 */  lbu        $a2, 0xD0($s0)
    /* 6DA38 800D6238 05004292 */  lbu        $v0, 0x5($s2)
    /* 6DA3C 800D623C 04004792 */  lbu        $a3, 0x4($s2)
    /* 6DA40 800D6240 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 6DA44 800D6244 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6DA48 800D6248 06004292 */  lbu        $v0, 0x6($s2)
    /* 6DA4C 800D624C 80FFE724 */  addiu      $a3, $a3, -0x80
    /* 6DA50 800D6250 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 6DA54 800D6254 A7EC010C */  jal        func_8007B29C
    /* 6DA58 800D6258 1400A2AF */   sw        $v0, 0x14($sp)
  .L800D625C:
    /* 6DA5C 800D625C 03006292 */  lbu        $v0, 0x3($s3)
    /* 6DA60 800D6260 01003126 */  addiu      $s1, $s1, 0x1
    /* 6DA64 800D6264 2A102202 */  slt        $v0, $s1, $v0
    /* 6DA68 800D6268 EAFF4014 */  bnez       $v0, .L800D6214
    /* 6DA6C 800D626C 21803302 */   addu      $s0, $s1, $s3
  .L800D6270:
    /* 6DA70 800D6270 E055030C */  jal        func_800D5780
    /* 6DA74 800D6274 21208002 */   addu      $a0, $s4, $zero
  .L800D6278:
    /* 6DA78 800D6278 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6DA7C 800D627C 2800B48F */  lw         $s4, 0x28($sp)
    /* 6DA80 800D6280 2400B38F */  lw         $s3, 0x24($sp)
    /* 6DA84 800D6284 2000B28F */  lw         $s2, 0x20($sp)
    /* 6DA88 800D6288 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6DA8C 800D628C 1800B08F */  lw         $s0, 0x18($sp)
    /* 6DA90 800D6290 0800E003 */  jr         $ra
    /* 6DA94 800D6294 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800D61AC
