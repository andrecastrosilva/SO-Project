/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

#include <list>
#include <stdio.h>

namespace somm22
{

// ================================================================================== //

    namespace peq
    {
        std::list<Event> peq = std::list<Event>();
    }

// ================================================================================== //

    void peqInit()
    {
        soProbe(301, "%s()\n", __func__);

        
    }

}


