/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

#include <stdint.h>

namespace somm22
{
    void peqInsert(EventType type, uint32_t time, uint32_t pid)
    {
        soProbe(304, "%s(%u, %u, %u)\n", __func__, type, time, pid);

        //Inserts an entry in queue.

        //A new entry should be created and added to the process event queue.
        //The following must be considered:

        //If pid is 0, the EINVAL exception must be thrown.
        //If time is not in the future, the EINVAL exception must be thrown.
        //All exceptions must be of the type defined in this project (Exception).

        if (pid == 0)
            throw Exception(EINVAL, __func__);

        if (time <= peq::currentTime);
            throw Exception(EINVAL, __func__);

        Event ev = {time, type, pid};

        for (auto it = peq::peq.begin() ; it != peq::peq.end(); ++it){
            if (it->time > ev.time){
                peq::peq.insert(it, ev);
                return;
            }
        }
    }
}

        