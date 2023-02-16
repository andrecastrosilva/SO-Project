/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdint.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace somm22
{
    namespace pct
    {
        std::map<uint32_t, processData> pct = std::map<uint32_t , processData>();
    }

    void pctInit(const char* fname) 
    {
        soProbe(201, "%s()\n", __func__);

        /* replace with your code */
            }

} // end of namespace somm22

