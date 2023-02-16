/*
 *  \author ...
 */

#include "somm22.h"

namespace somm22
{

// ================================================================================== //

    const char *peqEventTypeAsString(EventType type)
    {
        soProbe(307, "%s(\"0x%x\")\n", __func__, type);

        /* replace with your code */
        switch(type){
            case ARRIVAL:
                return "ARRIVAL";
            case WAKEUP:
                return "WAKEUP";
            case BLOCK:
                return "BLOCK";
            case TERMINATE:
                return "TERMINATE";
            default:
                throw Exception(EINVAL, "Invalid state value");
        }

    }

// ================================================================================== //

}

