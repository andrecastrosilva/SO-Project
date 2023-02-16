/*
 *  \author ...
 */

#ifndef __SOMM22__MODULE__PCT__
#define __SOMM22__MODULE__PCT__

#include "somm22.h"
#include <map>
#include <vector>
#include <stdint.h>

namespace somm22 
{
    namespace pct
    {
        struct processData {
            uint32_t pid;
            uint32_t arrivalTime;
            std::vector<uint32_t> burstProfile;
            uint32_t currentState;
        };

    extern std::map<uint32_t, processData> pct;

    }

} // end of namespace somm22

#endif /* __SOMM22__MODULE__PCT__ */