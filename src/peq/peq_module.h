/*
 *  \author ...
 */

#ifndef __SOMM22__MODULE__PEQ__
#define __SOMM22__MODULE__PEQ__

#include "somm22.h"

#include <list>
#include <stdio.h>

namespace somm22
{   
    namespace peq
    {
        uint32_t currentTime;
        extern std::list<Event> peq;
    }
}

#endif /* __SOMM22__MODULE__PEQ__ */

