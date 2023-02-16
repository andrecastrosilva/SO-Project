/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdint.h>

namespace somm22
{
    namespace pct
    {
        std::map<uint32_t, processData> pct = std::map<uint32_t , processData>();
    }

    void pctInit(const char* fname) 
    {
        soProbe(201, "%s()\n", __func__);

    }

} // end of namespace somm22

