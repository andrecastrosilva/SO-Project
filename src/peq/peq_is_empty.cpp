/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

#include <stdint.h>

namespace somm22
{
    bool peqIsEmpty() 
    {
        soProbe(303, "%s()\n", __func__);

        return peq::peq.empty();
    }
}

