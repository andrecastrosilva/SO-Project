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

        if (pid == 0)
            throw Exception(EINVAL, __func__);

        //If time is not in the future, the EINVAL exception must be thrown.

        Event ev = {time, type, pid};

        for (auto it = peq::peq.begin() ; it != peq::peq.end(); ++it){
            if (it->time > ev.time){
                peq::peq.insert(it, ev);
                return;
            }
        }
        throw Exception(EINVAL, __func__);
    }
}