/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

namespace somm22
{
    void peqLog()
    {
        soProbe(302, "%s()\n", __func__);

        logPrint("+===============================+\n");
        logPrint("|      Process Event Queue      |\n");
        logPrint("+-----------+-----------+-------+\n");
        logPrint("| Time | Type |  PID  |\n");
        logPrint("+-----------+-----------+-------+\n");

        for (Event e : peq::peq){ 
            logPrint("| %4d | %-4s | %5d |\n", e.time, peqEventTypeAsString(e.type), e.pid);
        }

            logPrint("+===============================+\n\n");
    }
}
