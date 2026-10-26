#include "110.h"

#define VS_EFFECT_NAME vs_effect_plg300

#include "src/EFFECT/mirroredSurfaces.h"

#include "src/EFFECT/particleSetup.h"
#include "src/EFFECT/particleRender.h"
#include "src/EFFECT/particleDispatch.h"

#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"

// This ring links every quad into the same ordering table slot
#define VS_CLOSED_RING_OT_SLOT -15
#define VS_CLOSED_RING_TEXTURE_COLUMNS 4
#include "src/EFFECT/closedRings.h"
