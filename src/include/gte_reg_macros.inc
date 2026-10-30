.ifndef .L_GTE_REG_MACROS_INC
.L_GTE_REG_MACROS_INC:

## Macros loading GTE data registers from CPU registers

# Load GTE V0 (VXY0, VZ0) from registers
.macro mtv0 vxy0, vz0
    mtc2       \vxy0, $0
    mtc2       \vz0, $1
.endm

# Load GTE V0-V2 (VXY0-2, VZ0-2) from registers
.macro mtv3 vxy0, vz0, vxy1, vz1, vxy2, vz2
    mtc2       \vxy0, $0
    mtc2       \vz0, $1
    mtc2       \vxy1, $2
    mtc2       \vz1, $3
    mtc2       \vxy2, $4
    mtc2       \vz2, $5
.endm

# Load GTE IR0 (scalar) and IR1-IR3 (vector)
.macro ldir0123 ir0, ir1, ir2, ir3
    mtc2       \ir0, $8
    mtc2       \ir1, $9
    mtc2       \ir2, $10
    mtc2       \ir3, $11
.endm

# Load GTE SXY0-SXY2 (screen coordinates)
.macro ldsxy3 sxy0, sxy1, sxy2
    mtc2       \sxy0, $12
    mtc2       \sxy1, $13
    mtc2       \sxy2, $14
.endm

# Load GTE SZ1-SZ3 (screen depths)
.macro ldsz3 sz1, sz2, sz3
    mtc2       \sz1, $17
    mtc2       \sz2, $18
    mtc2       \sz3, $19
.endm

.endif
