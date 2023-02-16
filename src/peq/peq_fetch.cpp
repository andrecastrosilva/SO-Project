/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

#include <stdint.h>

namespace somm22
{
    Event peqFetchNext()
    {
        soProbe(305, "%s()\n", __func__);

        /* replace with your code */
        throw Exception(ENOSYS, __func__);
    }

    Event peqPeekNext()
    {
        soProbe(306, "%s()\n", __func__);

        /* replace with your code */
        throw Exception(ENOSYS, __func__);
    }
};
