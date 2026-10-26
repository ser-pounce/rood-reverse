#include "1F0.h"

#define VS_EFFECT_NAME vs_effect_apocalypse

#define VS_SURFACE_TEXTURE_COLUMNS 4
#include "src/EFFECT/surfaces.h"

#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

#include "src/EFFECT/grids.h"

#include "src/EFFECT/trails5.h"

#define VS_PARTICLE_UNTEXTURED
#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleLineRender.h"
#include "src/EFFECT/particleDispatch.h"
