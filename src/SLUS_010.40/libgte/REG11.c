#include "common.h"
#include <libgte.h>
#include <inline_c.h>

void SetFarColor(long rfc, long gfc, long bfc)
{
    gte_ldfcdir(rfc << 4, gfc << 4, bfc << 4);
}
