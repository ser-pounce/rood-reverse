/* Shared ribbon-segment orienter.
 *
 * Each node in the caller's list carries two source points; this works out the
 * vector between them, samples the effect's curves by how far along the ribbon
 * the node sits, jitters the radius and the twist, then uses the GTE to swing
 * the offsets into the node's own frame and write the transformed points back.
 *
 * Every reference is to a shared battle symbol, so the twenty-one copies across
 * the overlays compile to the same code -- the overlay supplies only the entry
 * point name. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/32154.h"
#include "vs_inline_c.h"
#include "gpu.h"
#include <inline_c.h>
#include <rand.h>

/* One ribbon segment. The two source points bracket the two transformed points
 * the orienter writes back. */
typedef struct {
    SVECTOR from;
    SVECTOR outA;
    SVECTOR outB;
    SVECTOR to;
} vs_ribbonNode;

typedef struct {
    short unk0;
    short count;
    vs_ribbonNode* nodes;
    int unk8;
    int distance;
} vs_ribbonList;

/* Load the look-at matrix into $0-$4 and the eye vector into $5-$7. The staging
 * registers and the coprocessor indices are all part of the original encoding,
 * so they are pinned here rather than left to the allocator.
 *
 * `eye` is deliberately listed twice. GCC 2.8 ranks a value for a callee-saved
 * register by log2(uses) * uses / lifetime, and the original keeps the eye in
 * $s7 and the ribbon list in $fp -- a margin of about seven percent. The second
 * operand is the notch that makes the allocator agree; it is unreferenced in the
 * template, so it emits nothing. */
#define vs_ribbon_setMatEye(mat, eye) \
    __asm__ volatile("lw $t4,0x0(%0);" \
                    "lw $t5,0x4(%0);" \
                    "ctc2 $t4,$0;" \
                    "ctc2 $t5,$1;" \
                    "lw $t4,0x8(%0);" \
                    "lw $t5,0xc(%0);" \
                    "lw $t6,0x10(%0);" \
                    "ctc2 $t4,$2;" \
                    "ctc2 $t5,$3;" \
                    "ctc2 $t6,$4;" \
                    "lw $t4,0x0(%1);" \
                    "lw $t5,0x4(%1);" \
                    "ctc2 $t4,$5;" \
                    "lw $t6,0x8(%1);" \
                    "ctc2 $t5,$6;" \
                    "ctc2 $t6,$7" \
                    : \
                    : "r"(mat), "r"(eye), "r"(eye) \
                    : "$12", "$13", "$14")

/* Push one offset through the coprocessor. The matrix and eye loaded above are
 * still resident, so neither is needed again. */
#define vs_ribbon_gtePush(src) \
    __asm__ volatile("lwc2 $0,0x0(%0);" \
                    "lwc2 $1,0x4(%0);" \
                    "nop;" \
                    "nop;" \
                    "mvmva 1,0,0,0,0" \
                    : \
                    : "r"(src))

/* Read the transformed vector back out of the coprocessor. Kept separate from the
 * push so the destination pointer is materialised only when the stores want it --
 * that is where the original's load-delay filler comes from. */
#define vs_ribbon_gtePull(out) \
    __asm__ volatile("swc2 $25,0x0(%0);" \
                    "swc2 $26,0x4(%0);" \
                    "swc2 $27,0x8(%0)" \
                    : \
                    : "r"(out) \
                    : "memory")

void VS_RIBBON_FUNCTION(func_800FA098_arg0* effect, func_800FA098_arg1* scratch,
    int unused, vs_ribbonList* list)
{
    vs_ribbonNode* node;
    int i;
    int rsqrt;
    int curve;
    int scaleA;
    int scaleB;
    int angleA;
    int angleB;
    int alongA;
    int alongB;
    VECTOR* eye;
    VECTOR* target;
    SVECTOR offsets[2];

    for (i = 0; i < list->count; ++i) {
        node = &list->nodes[i];

        /* The span between the two source points goes into the eye vector, which
         * the conversion below overwrites. The reciprocal root works off the
         * squares, which never land in memory. */
        scratch->unk34.vx = node->to.vx - node->from.vx;
        scratch->unk34.vy = node->to.vy - node->from.vy;
        scratch->unk34.vz = node->to.vz - node->from.vz;
        rsqrt = vs_gte_rsqrt(scratch->unk34.vx * scratch->unk34.vx
            + scratch->unk34.vy * scratch->unk34.vy
            + scratch->unk34.vz * scratch->unk34.vz);

        curve = vs_battle_sampleCurve(effect->unk12, list->distance);
        vs_battle_lerp2DVector(&effect->unk94[0][0], curve, &scratch->unk124[0]);
        curve = vs_battle_sampleCurve(effect->unk13, list->distance);
        vs_battle_lerp2DVector(&effect->unk94[1][0], curve, &scratch->unk12C[0]);
        curve = vs_battle_sampleCurve(effect->unkC, list->distance);
        vs_battle_lerp2DVector(&effect->unk94[2][0], curve, &scratch->unk118[0]);
        curve = vs_battle_sampleCurve(effect->unkB, list->distance);
        vs_battle_lerpVector(&effect->unk34[1][0], curve, &scratch->unkC8);
        curve = vs_battle_sampleCurve(effect->unkA, list->distance);
        vs_battle_lerpVector(&effect->unk34[0][0], curve, &scratch->unkE8);
        curve = vs_battle_sampleCurve(effect->unkD, list->distance);
        vs_battle_lerpSvector(&effect->unk34[2][0], curve, &scratch->unkF8);

        /* The two offsets the GTE swings are each (cos, sin, along) -- the trig
         * lands in x and y and the jittered span rides in z. */
        /* The test reads the short directly; the arithmetic reloads it widened,
         * which is why the two loads do not collapse into one. */
        if (scratch->unkF8.vx != 0) {
            alongA = scratch->unk118[0] + rand() % scratch->unkF8.vx
                - scratch->unkF8.vx / 2;
        } else {
            alongA = scratch->unk118[0];
        }
        offsets[0].vz = (rsqrt * alongA) / 256;

        if (scratch->unkF8.vy != 0) {
            alongB = scratch->unk118[1] + rand() % scratch->unkF8.vy
                - scratch->unkF8.vy / 2;
        } else {
            alongB = scratch->unk118[1];
        }
        offsets[1].vz = rsqrt + ((rsqrt * alongB) / 256);

        /* Scale and angle for each of the two offsets. */
        scaleA = scratch->unk124[0];
        if (scratch->unk124[1] != 0) {
            scaleA += rand() % scratch->unk124[1];
        }
        scaleB = scratch->unk12C[0];
        if (scratch->unk12C[1] != 0) {
            scaleB += rand() % scratch->unk12C[1];
        }
        angleA = scratch->unkE8.vx;
        if (scratch->unkC8.vx != 0) {
            angleA += rand() % (scratch->unkC8.vx * 2) - scratch->unkC8.vx;
        }
        angleB = scratch->unkE8.vy;
        if (scratch->unkC8.vy != 0) {
            angleB += rand() % (scratch->unkC8.vy * 2) - scratch->unkC8.vy;
        }

        /* Both offsets are (cos, sin, along) in the same handedness. */
        offsets[0].vx = (rcos(angleA) * scaleA) >> 12;
        offsets[0].vy = (rsin(angleA) * scaleA) >> 12;
        offsets[1].vx = (rcos(angleB) * scaleB) >> 12;
        offsets[1].vy = (rsin(angleB) * scaleB) >> 12;

        eye = &scratch->unk34;
        target = &scratch->unk44;
        vs_battle_svecToVec((SVECTOR*)node, eye);
        vs_battle_svecToVec((SVECTOR*)&node->to, target);
        vs_battle_lookAt(eye, target, &scratch->unk64);
        vs_ribbon_setMatEye(&scratch->unk64, eye);
        vs_ribbon_gtePush(&offsets[0]);
        vs_ribbon_gtePull(eye);
        vs_battle_vecToSvec(eye, &node->outA);
        vs_ribbon_gtePush(&offsets[1]);
        vs_ribbon_gtePull(target);
        vs_battle_vecToSvec(target, &node->outB);
    }
}
