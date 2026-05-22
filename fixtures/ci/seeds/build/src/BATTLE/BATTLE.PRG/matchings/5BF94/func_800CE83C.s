nonmatching func_800CE83C, 0xB8

glabel func_800CE83C
    /* 6603C 800CE83C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 66040 800CE840 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66044 800CE844 21888000 */  addu       $s1, $a0, $zero
    /* 66048 800CE848 5C0D0424 */  addiu      $a0, $zero, 0xD5C
    /* 6604C 800CE84C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 66050 800CE850 8F0F010C */  jal        vs_main_allocHeapR
    /* 66054 800CE854 1000B0AF */   sw        $s0, 0x10($sp)
    /* 66058 800CE858 21202002 */  addu       $a0, $s1, $zero
    /* 6605C 800CE85C 21804000 */  addu       $s0, $v0, $zero
    /* 66060 800CE860 C539030C */  jal        func_800CE714
    /* 66064 800CE864 21280002 */   addu      $a1, $s0, $zero
    /* 66068 800CE868 0F80043C */  lui        $a0, %hi(D_800F53B8)
    /* 6606C 800CE86C B853858C */  lw         $a1, %lo(D_800F53B8)($a0)
    /* 66070 800CE870 00000000 */  nop
    /* 66074 800CE874 0700A010 */  beqz       $a1, .L800CE894
    /* 66078 800CE878 00000000 */   nop
    /* 6607C 800CE87C 0900A390 */  lbu        $v1, 0x9($a1)
    /* 66080 800CE880 1000228E */  lw         $v0, 0x10($s1)
    /* 66084 800CE884 00000000 */  nop
    /* 66088 800CE888 2A104300 */  slt        $v0, $v0, $v1
    /* 6608C 800CE88C 04004010 */  beqz       $v0, .L800CE8A0
    /* 66090 800CE890 00000000 */   nop
  .L800CE894:
    /* 66094 800CE894 000005AE */  sw         $a1, 0x0($s0)
    /* 66098 800CE898 373A0308 */  j          .L800CE8DC
    /* 6609C 800CE89C B85390AC */   sw        $s0, %lo(D_800F53B8)($a0)
  .L800CE8A0:
    /* 660A0 800CE8A0 0000A48C */  lw         $a0, 0x0($a1)
    /* 660A4 800CE8A4 00000000 */  nop
    /* 660A8 800CE8A8 07008010 */  beqz       $a0, .L800CE8C8
    /* 660AC 800CE8AC 00000000 */   nop
    /* 660B0 800CE8B0 09008390 */  lbu        $v1, 0x9($a0)
    /* 660B4 800CE8B4 1000228E */  lw         $v0, 0x10($s1)
    /* 660B8 800CE8B8 00000000 */  nop
    /* 660BC 800CE8BC 2A104300 */  slt        $v0, $v0, $v1
    /* 660C0 800CE8C0 04004010 */  beqz       $v0, .L800CE8D4
    /* 660C4 800CE8C4 00000000 */   nop
  .L800CE8C8:
    /* 660C8 800CE8C8 000004AE */  sw         $a0, 0x0($s0)
    /* 660CC 800CE8CC 373A0308 */  j          .L800CE8DC
    /* 660D0 800CE8D0 0000B0AC */   sw        $s0, 0x0($a1)
  .L800CE8D4:
    /* 660D4 800CE8D4 283A0308 */  j          .L800CE8A0
    /* 660D8 800CE8D8 21288000 */   addu      $a1, $a0, $zero
  .L800CE8DC:
    /* 660DC 800CE8DC 21100002 */  addu       $v0, $s0, $zero
    /* 660E0 800CE8E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 660E4 800CE8E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 660E8 800CE8E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 660EC 800CE8EC 0800E003 */  jr         $ra
    /* 660F0 800CE8F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CE83C
