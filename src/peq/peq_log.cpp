/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

#include <stdio.h>

namespace somm22
{
    void peqLog()
    {
        soProbe(302, "%s()\n", __func__);

        /* replace with your code */
        throw Exception(ENOSYS, __func__);
    }
}
