nonmatching func_800AECA0, 0x224

glabel func_800AECA0
    /* 464A0 800AECA0 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 464A4 800AECA4 3800B2AF */  sw         $s2, 0x38($sp)
    /* 464A8 800AECA8 801F123C */  lui        $s2, (0x1F80035C >> 16)
    /* 464AC 800AECAC 5C035236 */  ori        $s2, $s2, (0x1F80035C & 0xFFFF)
    /* 464B0 800AECB0 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 464B4 800AECB4 801F133C */  lui        $s3, (0x1F800064 >> 16)
    /* 464B8 800AECB8 21300000 */  addu       $a2, $zero, $zero
    /* 464BC 800AECBC 0680023C */  lui        $v0, %hi(D_8005E218)
    /* 464C0 800AECC0 4800A4AF */  sw         $a0, 0x48($sp)
    /* 464C4 800AECC4 18E24424 */  addiu      $a0, $v0, %lo(D_8005E218)
    /* 464C8 800AECC8 21186002 */  addu       $v1, $s3, $zero
    /* 464CC 800AECCC 5C036334 */  ori        $v1, $v1, (0x1F80035C & 0xFFFF)
    /* 464D0 800AECD0 4000BFAF */  sw         $ra, 0x40($sp)
    /* 464D4 800AECD4 3400B1AF */  sw         $s1, 0x34($sp)
    /* 464D8 800AECD8 3000B0AF */  sw         $s0, 0x30($sp)
  .L800AECDC:
    /* 464DC 800AECDC 00008294 */  lhu        $v0, 0x0($a0)
    /* 464E0 800AECE0 00000000 */  nop
    /* 464E4 800AECE4 640062A4 */  sh         $v0, 0x64($v1)
    /* 464E8 800AECE8 02008294 */  lhu        $v0, 0x2($a0)
    /* 464EC 800AECEC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 464F0 800AECF0 6A0062A4 */  sh         $v0, 0x6A($v1)
    /* 464F4 800AECF4 04008294 */  lhu        $v0, 0x4($a0)
    /* 464F8 800AECF8 06008424 */  addiu      $a0, $a0, 0x6
    /* 464FC 800AECFC 700062A4 */  sh         $v0, 0x70($v1)
    /* 46500 800AED00 0300C228 */  slti       $v0, $a2, 0x3
    /* 46504 800AED04 F5FF4014 */  bnez       $v0, .L800AECDC
    /* 46508 800AED08 02006324 */   addiu     $v1, $v1, 0x2
    /* 4650C 800AED0C 5C00648E */  lw         $a0, (0x1F80005C & 0xFFFF)($s3)
    /* 46510 800AED10 C903010C */  jal        rcos
    /* 46514 800AED14 23200400 */   negu      $a0, $a0
    /* 46518 800AED18 5C00648E */  lw         $a0, (0x1F80005C & 0xFFFF)($s3)
    /* 4651C 800AED1C 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 46520 800AED20 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 46524 800AED24 CA03010C */  jal        rsin
    /* 46528 800AED28 23200400 */   negu      $a0, $a0
    /* 4652C 800AED2C 64005026 */  addiu      $s0, $s2, 0x64
    /* 46530 800AED30 21200002 */  addu       $a0, $s0, $zero
    /* 46534 800AED34 8C005126 */  addiu      $s1, $s2, 0x8C
    /* 46538 800AED38 21282002 */  addu       $a1, $s1, $zero
    /* 4653C 800AED3C 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 46540 800AED40 23100200 */  negu       $v0, $v0
    /* 46544 800AED44 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 46548 800AED48 00100224 */  addiu      $v0, $zero, 0x1000
    /* 4654C 800AED4C 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 46550 800AED50 380E0224 */  addiu      $v0, $zero, 0xE38
    /* 46554 800AED54 1E00A0A7 */  sh         $zero, 0x1E($sp)
    /* 46558 800AED58 1C00A0A7 */  sh         $zero, 0x1C($sp)
    /* 4655C 800AED5C 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 46560 800AED60 1400A0A7 */  sh         $zero, 0x14($sp)
    /* 46564 800AED64 8C0042AE */  sw         $v0, 0x8C($s2)
    /* 46568 800AED68 00100224 */  addiu      $v0, $zero, 0x1000
    /* 4656C 800AED6C 900042AE */  sw         $v0, 0x90($s2)
    /* 46570 800AED70 0305010C */  jal        func_8004140C
    /* 46574 800AED74 940042AE */   sw        $v0, 0x94($s2)
    /* 46578 800AED78 21200002 */  addu       $a0, $s0, $zero
    /* 4657C 800AED7C 1A07010C */  jal        func_80041C68
    /* 46580 800AED80 1000A527 */   addiu     $a1, $sp, 0x10
    /* 46584 800AED84 1000A28F */  lw         $v0, 0x10($sp)
    /* 46588 800AED88 1400A38F */  lw         $v1, 0x14($sp)
    /* 4658C 800AED8C 1800A48F */  lw         $a0, 0x18($sp)
    /* 46590 800AED90 1C00A58F */  lw         $a1, 0x1C($sp)
    /* 46594 800AED94 640042AE */  sw         $v0, 0x64($s2)
    /* 46598 800AED98 680043AE */  sw         $v1, 0x68($s2)
    /* 4659C 800AED9C 6C0044AE */  sw         $a0, 0x6C($s2)
    /* 465A0 800AEDA0 700045AE */  sw         $a1, 0x70($s2)
    /* 465A4 800AEDA4 2000A28F */  lw         $v0, 0x20($sp)
    /* 465A8 800AEDA8 2400A38F */  lw         $v1, 0x24($sp)
    /* 465AC 800AEDAC 2800A48F */  lw         $a0, 0x28($sp)
    /* 465B0 800AEDB0 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 465B4 800AEDB4 740042AE */  sw         $v0, 0x74($s2)
    /* 465B8 800AEDB8 780043AE */  sw         $v1, 0x78($s2)
    /* 465BC 800AEDBC 7C0044AE */  sw         $a0, 0x7C($s2)
    /* 465C0 800AEDC0 800045AE */  sw         $a1, 0x80($s2)
    /* 465C4 800AEDC4 6400638E */  lw         $v1, (0x1F800064 & 0xFFFF)($s3)
    /* 465C8 800AEDC8 0001023C */  lui        $v0, (0x1000000 >> 16)
    /* 465CC 800AEDCC 1A004300 */  div        $zero, $v0, $v1
    /* 465D0 800AEDD0 12300000 */  mflo       $a2
    /* 465D4 800AEDD4 21200002 */  addu       $a0, $s0, $zero
    /* 465D8 800AEDD8 21282002 */  addu       $a1, $s1, $zero
    /* 465DC 800AEDDC 8C0046AE */  sw         $a2, 0x8C($s2)
    /* 465E0 800AEDE0 900046AE */  sw         $a2, 0x90($s2)
    /* 465E4 800AEDE4 0305010C */  jal        func_8004140C
    /* 465E8 800AEDE8 940046AE */   sw        $a2, 0x94($s2)
    /* 465EC 800AEDEC 0F80023C */  lui        $v0, %hi(D_800F4910)
    /* 465F0 800AEDF0 10494624 */  addiu      $a2, $v0, %lo(D_800F4910)
    /* 465F4 800AEDF4 4800A38F */  lw         $v1, 0x48($sp)
    /* 465F8 800AEDF8 4C00A48F */  lw         $a0, 0x4C($sp)
    /* 465FC 800AEDFC 5000A58F */  lw         $a1, 0x50($sp)
    /* 46600 800AEE00 0000C3AC */  sw         $v1, 0x0($a2)
    /* 46604 800AEE04 0400C4AC */  sw         $a0, 0x4($a2)
    /* 46608 800AEE08 0800C5AC */  sw         $a1, 0x8($a2)
    /* 4660C 800AEE0C 5400A38F */  lw         $v1, 0x54($sp)
    /* 46610 800AEE10 5800A48F */  lw         $a0, 0x58($sp)
    /* 46614 800AEE14 5C00A58F */  lw         $a1, 0x5C($sp)
    /* 46618 800AEE18 0C00C3AC */  sw         $v1, 0xC($a2)
    /* 4661C 800AEE1C 1000C4AC */  sw         $a0, 0x10($a2)
    /* 46620 800AEE20 1400C5AC */  sw         $a1, 0x14($a2)
    /* 46624 800AEE24 6000A38F */  lw         $v1, 0x60($sp)
    /* 46628 800AEE28 6400A48F */  lw         $a0, 0x64($sp)
    /* 4662C 800AEE2C 1800C3AC */  sw         $v1, 0x18($a2)
    /* 46630 800AEE30 1C00C4AC */  sw         $a0, 0x1C($a2)
    /* 46634 800AEE34 0F80033C */  lui        $v1, %hi(D_800F49B8)
    /* 46638 800AEE38 4800A48F */  lw         $a0, 0x48($sp)
    /* 4663C 800AEE3C B8496724 */  addiu      $a3, $v1, %lo(D_800F49B8)
    /* 46640 800AEE40 6400428E */  lw         $v0, 0x64($s2)
    /* 46644 800AEE44 6800458E */  lw         $a1, 0x68($s2)
    /* 46648 800AEE48 6C00468E */  lw         $a2, 0x6C($s2)
    /* 4664C 800AEE4C 0000E2AC */  sw         $v0, 0x0($a3)
    /* 46650 800AEE50 0400E5AC */  sw         $a1, 0x4($a3)
    /* 46654 800AEE54 0800E6AC */  sw         $a2, 0x8($a3)
    /* 46658 800AEE58 7000428E */  lw         $v0, 0x70($s2)
    /* 4665C 800AEE5C 7400458E */  lw         $a1, 0x74($s2)
    /* 46660 800AEE60 7800468E */  lw         $a2, 0x78($s2)
    /* 46664 800AEE64 0C00E2AC */  sw         $v0, 0xC($a3)
    /* 46668 800AEE68 1000E5AC */  sw         $a1, 0x10($a3)
    /* 4666C 800AEE6C 1400E6AC */  sw         $a2, 0x14($a3)
    /* 46670 800AEE70 7C00428E */  lw         $v0, 0x7C($s2)
    /* 46674 800AEE74 8000458E */  lw         $a1, 0x80($s2)
    /* 46678 800AEE78 1800E2AC */  sw         $v0, 0x18($a3)
    /* 4667C 800AEE7C 1C00E5AC */  sw         $a1, 0x1C($a3)
    /* 46680 800AEE80 1400828C */  lw         $v0, 0x14($a0)
    /* 46684 800AEE84 B8496324 */  addiu      $v1, $v1, %lo(D_800F49B8)
    /* 46688 800AEE88 140062AC */  sw         $v0, 0x14($v1)
    /* 4668C 800AEE8C 1800828C */  lw         $v0, 0x18($a0)
    /* 46690 800AEE90 00000000 */  nop
    /* 46694 800AEE94 180062AC */  sw         $v0, 0x18($v1)
    /* 46698 800AEE98 1C00828C */  lw         $v0, 0x1C($a0)
    /* 4669C 800AEE9C 00000000 */  nop
    /* 466A0 800AEEA0 1C0062AC */  sw         $v0, 0x1C($v1)
    /* 466A4 800AEEA4 4000BF8F */  lw         $ra, 0x40($sp)
    /* 466A8 800AEEA8 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 466AC 800AEEAC 3800B28F */  lw         $s2, 0x38($sp)
    /* 466B0 800AEEB0 3400B18F */  lw         $s1, 0x34($sp)
    /* 466B4 800AEEB4 3000B08F */  lw         $s0, 0x30($sp)
    /* 466B8 800AEEB8 4800BD27 */  addiu      $sp, $sp, 0x48
    /* 466BC 800AEEBC 0800E003 */  jr         $ra
    /* 466C0 800AEEC0 00000000 */   nop
endlabel func_800AECA0
