nonmatching func_8002BE50, 0x190

glabel func_8002BE50
    /* 1C650 8002BE50 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1C654 8002BE54 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1C658 8002BE58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C65C 8002BE5C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C660 8002BE60 0A006294 */  lhu        $v0, 0xA($v1)
    /* 1C664 8002BE64 00000000 */  nop
    /* 1C668 8002BE68 02004230 */  andi       $v0, $v0, 0x2
    /* 1C66C 8002BE6C 03004010 */  beqz       $v0, .L8002BE7C
    /* 1C670 8002BE70 00000000 */   nop
    /* 1C674 8002BE74 F4AF0008 */  j          .L8002BFD0
    /* 1C678 8002BE78 0A0060A4 */   sh        $zero, 0xA($v1)
  .L8002BE7C:
    /* 1C67C 8002BE7C 0380033C */  lui        $v1, %hi(D_800335EC)
    /* 1C680 8002BE80 EC35638C */  lw         $v1, %lo(D_800335EC)($v1)
    /* 1C684 8002BE84 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C688 8002BE88 0380013C */  lui        $at, %hi(D_80033604)
    /* 1C68C 8002BE8C 09006010 */  beqz       $v1, .L8002BEB4
    /* 1C690 8002BE90 043622AC */   sw        $v0, %lo(D_80033604)($at)
    /* 1C694 8002BE94 0480043C */  lui        $a0, %hi(D_8003FC10)
    /* 1C698 8002BE98 10FC8424 */  addiu      $a0, $a0, %lo(D_8003FC10)
    /* 1C69C 8002BE9C 0000838C */  lw         $v1, 0x0($a0)
    /* 1C6A0 8002BEA0 00000000 */  nop
    /* 1C6A4 8002BEA4 96006228 */  slti       $v0, $v1, 0x96
    /* 1C6A8 8002BEA8 02004010 */  beqz       $v0, .L8002BEB4
    /* 1C6AC 8002BEAC 01006224 */   addiu     $v0, $v1, 0x1
    /* 1C6B0 8002BEB0 000082AC */  sw         $v0, 0x0($a0)
  .L8002BEB4:
    /* 1C6B4 8002BEB4 0380023C */  lui        $v0, %hi(D_800335F0)
    /* 1C6B8 8002BEB8 F035428C */  lw         $v0, %lo(D_800335F0)($v0)
    /* 1C6BC 8002BEBC 00000000 */  nop
    /* 1C6C0 8002BEC0 09004014 */  bnez       $v0, .L8002BEE8
    /* 1C6C4 8002BEC4 00000000 */   nop
    /* 1C6C8 8002BEC8 0480043C */  lui        $a0, %hi(D_8003FC14)
    /* 1C6CC 8002BECC 14FC8424 */  addiu      $a0, $a0, %lo(D_8003FC14)
    /* 1C6D0 8002BED0 0000838C */  lw         $v1, 0x0($a0)
    /* 1C6D4 8002BED4 00000000 */  nop
    /* 1C6D8 8002BED8 96006228 */  slti       $v0, $v1, 0x96
    /* 1C6DC 8002BEDC 02004010 */  beqz       $v0, .L8002BEE8
    /* 1C6E0 8002BEE0 01006224 */   addiu     $v0, $v1, 0x1
    /* 1C6E4 8002BEE4 000082AC */  sw         $v0, 0x0($a0)
  .L8002BEE8:
    /* 1C6E8 8002BEE8 0380023C */  lui        $v0, %hi(D_800335D4)
    /* 1C6EC 8002BEEC D435428C */  lw         $v0, %lo(D_800335D4)($v0)
    /* 1C6F0 8002BEF0 00000000 */  nop
    /* 1C6F4 8002BEF4 36004010 */  beqz       $v0, .L8002BFD0
    /* 1C6F8 8002BEF8 00000000 */   nop
    /* 1C6FC 8002BEFC 0380033C */  lui        $v1, %hi(D_800335EC)
    /* 1C700 8002BF00 EC35638C */  lw         $v1, %lo(D_800335EC)($v1)
    /* 1C704 8002BF04 0380023C */  lui        $v0, %hi(D_800335F0)
    /* 1C708 8002BF08 F035428C */  lw         $v0, %lo(D_800335F0)($v0)
    /* 1C70C 8002BF0C 00000000 */  nop
    /* 1C710 8002BF10 2A104300 */  slt        $v0, $v0, $v1
    /* 1C714 8002BF14 2E004014 */  bnez       $v0, .L8002BFD0
    /* 1C718 8002BF18 00210300 */   sll       $a0, $v1, 4
    /* 1C71C 8002BF1C 23208300 */  subu       $a0, $a0, $v1
    /* 1C720 8002BF20 0380023C */  lui        $v0, %hi(D_800335D0)
    /* 1C724 8002BF24 D035428C */  lw         $v0, %lo(D_800335D0)($v0)
    /* 1C728 8002BF28 00210400 */  sll        $a0, $a0, 4
    /* 1C72C 8002BF2C 0380013C */  lui        $at, %hi(D_800335E0)
    /* 1C730 8002BF30 E03520AC */  sw         $zero, %lo(D_800335E0)($at)
    /* 1C734 8002BF34 0380013C */  lui        $at, %hi(D_800335DC)
    /* 1C738 8002BF38 DC3523AC */  sw         $v1, %lo(D_800335DC)($at)
    /* 1C73C 8002BF3C 41B0000C */  jal        _padInitSioMode
    /* 1C740 8002BF40 21204400 */   addu      $a0, $v0, $a0
    /* 1C744 8002BF44 06004014 */  bnez       $v0, .L8002BF60
    /* 1C748 8002BF48 00000000 */   nop
    /* 1C74C 8002BF4C 0380023C */  lui        $v0, %hi(D_8003359C)
    /* 1C750 8002BF50 9C35428C */  lw         $v0, %lo(D_8003359C)($v0)
    /* 1C754 8002BF54 00000000 */  nop
    /* 1C758 8002BF58 09F84000 */  jalr       $v0
    /* 1C75C 8002BF5C FFFF0434 */   ori       $a0, $zero, 0xFFFF
  .L8002BF60:
    /* 1C760 8002BF60 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1C764 8002BF64 DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1C768 8002BF68 0380023C */  lui        $v0, %hi(D_800335F0)
    /* 1C76C 8002BF6C F035428C */  lw         $v0, %lo(D_800335F0)($v0)
    /* 1C770 8002BF70 0380013C */  lui        $at, %hi(D_800335E4)
    /* 1C774 8002BF74 E43520AC */  sw         $zero, %lo(D_800335E4)($at)
    /* 1C778 8002BF78 2A104300 */  slt        $v0, $v0, $v1
    /* 1C77C 8002BF7C 10004014 */  bnez       $v0, .L8002BFC0
    /* 1C780 8002BF80 00000000 */   nop
  .L8002BF84:
    /* 1C784 8002BF84 00210300 */  sll        $a0, $v1, 4
    /* 1C788 8002BF88 23208300 */  subu       $a0, $a0, $v1
    /* 1C78C 8002BF8C 0380023C */  lui        $v0, %hi(D_800335D0)
    /* 1C790 8002BF90 D035428C */  lw         $v0, %lo(D_800335D0)($v0)
    /* 1C794 8002BF94 00210400 */  sll        $a0, $a0, 4
    /* 1C798 8002BF98 0EB1000C */  jal        func_8002C438
    /* 1C79C 8002BF9C 21204400 */   addu      $a0, $v0, $a0
    /* 1C7A0 8002BFA0 0380033C */  lui        $v1, %hi(D_800335DC)
    /* 1C7A4 8002BFA4 DC35638C */  lw         $v1, %lo(D_800335DC)($v1)
    /* 1C7A8 8002BFA8 0380023C */  lui        $v0, %hi(D_800335F0)
    /* 1C7AC 8002BFAC F035428C */  lw         $v0, %lo(D_800335F0)($v0)
    /* 1C7B0 8002BFB0 00000000 */  nop
    /* 1C7B4 8002BFB4 2A104300 */  slt        $v0, $v0, $v1
    /* 1C7B8 8002BFB8 F2FF4010 */  beqz       $v0, .L8002BF84
    /* 1C7BC 8002BFBC 00000000 */   nop
  .L8002BFC0:
    /* 1C7C0 8002BFC0 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1C7C4 8002BFC4 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1C7C8 8002BFC8 88000224 */  addiu      $v0, $zero, 0x88
    /* 1C7CC 8002BFCC 0E0062A4 */  sh         $v0, 0xE($v1)
  .L8002BFD0:
    /* 1C7D0 8002BFD0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C7D4 8002BFD4 21100000 */  addu       $v0, $zero, $zero
    /* 1C7D8 8002BFD8 0800E003 */  jr         $ra
    /* 1C7DC 8002BFDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002BE50
