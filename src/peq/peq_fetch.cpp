/*
 *  \author ... retirar o begin depois de o tirar
 */ 

#include "somm22.h"
#include "peq_module.h"

#include <stdint.h>
#include <bits/stdc++.h>
#include <string>

namespace somm22
{
    Event peqFetchNext()
    {
        soProbe(305, "%s()\n", __func__);

        /* replace with your code */
        std::list<Event>::iterator selected = peq::peq.end();
            for (std::list<Event>::iterator it = peq::peq.begin() ; it != peq::peq.end(); ++it){
                if (it->time)
                {
                    break;
                }
                
            }

            if(selected == peq::peq.end()){
                throw Exception(EINVAL, (std::string(__func__) + std::string(": No Event with that mask")).c_str());
            }else{
                Event rEvent = *selected;
                peq::peq.erase(selected);
                return rEvent;
            }
    }


    Event peqPeekNext()
    {
        soProbe(306, "%s()\n", __func__);

        /* replace with your code */
        throw Exception(ENOSYS, __func__);
    }
}
