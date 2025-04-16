.ifndef .L_MACRO_INC
.L_MACRO_INC:

.macro glabel label
    .global \label
    \label:
.endm

.macro jumpFunc name, target
    glabel \name
    addu   $t0, $a0, $0
    lw     $sp, 0x0($t0)
    j      \target
    .nop
.endm;

.macro cop2op pseudo, op, sf = 1, mx = 0, v = 0, cv = 0, lm = 0
    cop2 \pseudo << 20 | \sf << 19 | \mx << 17 | \v << 15 | \cv << 13 | \lm << 10 | \op
.endm

.macro RTPS
    cop2op 1, 0x01
.endm

.macro RTPT
    cop2op 2, 0x30
.endm

.macro MVMVA sf, mx, v, cv, lm
    cop2op 4, 0x12, sf = \sf, mx = \mx, v = \v, cv = \cv, lm = \lm
.endm

.macro DPCL
    cop2op 6, 0x29
.endm

.macro DPCS
    cop2op 7, 0x10
.endm

.macro DPCT
    cop2op 8, 0x2A
.endm

.macro INTPL
    cop2op 9, 0x11
.endm

.macro SQR sf
    cop2op 10, 0x28, sf = \sf, lm = 1
.endm

.macro NCS
    cop2op 12, 0x1E, lm = 1
.endm

.macro NCT
    cop2op 13, 0x20, lm = 1
.endm

.macro NCDS
    cop2op 14, 0x13, lm = 1
.endm

.macro NCDT
    cop2op 15, 0x16, lm = 1
.endm

.macro NCCS
    cop2op 16, 0x1B, lm = 1
.endm

.macro NCCT
    cop2op 17, 0x3F, lm = 1
.endm

.macro CDP
    cop2op 18, 0x14, lm = 1
.endm

.macro CC
    cop2op 19, 0x1C, lm = 1
.endm

.macro NCLIP
    cop2op 20, 0x06, sf = 0
.endm

.macro AVSZ3
    cop2op 21, 0x2D
.endm

.macro AVSZ4
    cop2op 22, 0x2E
.endm

.macro OP sf
    cop2op 23, 0x0C, sf = \sf
.endm

.macro GPF sf
    cop2op 25, 0x3D, sf = \sf
.endm

.macro GPL sf
    cop2op 26, 0x3E, sf = \sf
.endm

.endif
