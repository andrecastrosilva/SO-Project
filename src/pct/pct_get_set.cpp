/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdint.h>

namespace somm22
{
    double pctGetNextBurstDuration(uint32_t pid)
    {
        soProbe(204, "%s(%u)\n", __func__, pid);

        return pct::pct[pid].burstProfile[pct::pct[pid].currentState];
    }

    uint32_t pctGetProcessState(uint32_t pid)
    {
        soProbe(205, "%s(%d)\n", __func__, pid);

        return pct::pct[pid].currentState;
    }

    void pctSetProcessState(uint32_t pid, uint32_t state)
    {
        soProbe(206, "%s(%u, %u)\n", __func__, pid, state);

        pct::pct[pid].currentState = state;
    }

} // end of namespace somm22
