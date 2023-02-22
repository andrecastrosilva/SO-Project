/*
 *  \author ... 
 */ 

#include "somm22.h"
#include "peq_module.h"
#include "string"

namespace somm22
{
    Event peqFetchNext()
    {
        soProbe(305, "%s()\n", __func__);

        /* replace with your code */
        std::list<Event>::iterator selected = peq::peq.begin();
        if(selected == peq::peq.end()){
            throw Exception(EINVAL, (std::string(__func__) + std::string(": No Event in peq list.")).c_str());
        }else{
            Event rEvent = *selected;
            peq::peq.erase(selected);
            return rEvent;
        }
    }

    Event peqPeekNext()
    {
        soProbe(306, "%s()\n", __func__);

        std::list<Event>::iterator first = peq::peq.begin();
        if(first == peq::peq.end()){
            throw Exception(EINVAL, (std::string(__func__) + std::string(": No Event in peq list.")).c_str());
        }else{
            Event rEvent = *first;
            return rEvent;
        }
    }
}
