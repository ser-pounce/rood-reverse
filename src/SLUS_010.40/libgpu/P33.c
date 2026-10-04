#include "common.h"
#include <libgte.h>
#include <libgpu.h>

void SetDrawTPage(DR_TPAGE* p, int dfe, int dtd, int tpage)
{
    setDrawTPage(p, dfe, dtd, tpage);
}
