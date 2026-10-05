#include "common.h"
#include <libspu.h>

typedef struct {
    long mode;
    SpuVolume depth;
    long delay;
    long feedback;
} SpuRevAttr;

extern u_short* D_80030860; /* _spu_RXX */
extern SpuRevAttr D_80030804; /* _spu_rev_attr */

void SpuSetReverbModeDepth(short depth_left, short depth_right)
{
    D_80030860[0xC2] = depth_left;
    D_80030860[0xC3] = depth_right;
    D_80030804.depth.left = depth_left;
    D_80030804.depth.right = depth_right;
}
