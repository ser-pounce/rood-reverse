#include "spu.h"

void SpuSetReverbModeDepth(short depth_left, short depth_right)
{
    _spu_RXX->rvolL = depth_left;
    _spu_RXX->rvolR = depth_right;
    _spu_rev_attr.depth.left = depth_left;
    _spu_rev_attr.depth.right = depth_right;
}
