/*
 *  \author ...
 */

#include "somm22.h"
#include "peq_module.h"

#include <stdint.h>
#include <algorithm>

namespace somm22
{
    void peqInsert(EventType type, uint32_t time, uint32_t pid)
    {
        soProbe(304, "%s(%u, %u, %u)\n", __func__, type, time, pid);

        if (pid == 0)
            throw Exception(EINVAL, __func__);
        
        //check if the event is already in the queue
        for (Event e : peq::peq){
            if (e.pid == pid && e.type == type){
                throw Exception(EINVAL, "Event already in the queue");
            }
        }

        Event evento = {time , type , pid};
            
            try{
                auto it = std::upper_bound(peq::peq.begin(), peq::peq.end(), evento, [](Event a, Event b) -> bool{return a.time < b.time;});
                peq::peq.insert(it, evento);
            } catch(std::exception& e){
                throw Exception(EINVAL, __func__);
            }
    }
}