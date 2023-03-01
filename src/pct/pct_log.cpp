/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

namespace somm22
{

    void pctLog()
    {
        soProbe(202, "%s()\n", __func__);

        logPrint("+==================================================================+\n");
        logPrint("|                     Process Control Table                        |\n");
        logPrint("+-----------------+---------------------+--------------------------+\n");
        logPrint("|       PID       |     arrivalTime     |       burstProfile       |\n");
        logPrint("+-----------------+---------------------+--------------------------+\n");
        
        std::vector<uint32_t> keys;
        for (auto i = pct::pct.begin(); i != pct::pct.end(); i++){
            keys.push_back(i->first);
        }
        
        for (uint32_t i = 0; i<keys.size(); i++){
            std::ostringstream burstProfileStr;
            for (auto burst : pct::pct[keys[i]].burstProfile) {
                burstProfileStr << std::fixed << std::setprecision(1) << burst << " ";
            }
            logPrint("| %15d | %19d | %25s|\n", pct::pct[keys[i]].pid, pct::pct[keys[i]].arrivalTime, burstProfileStr.str().c_str());
        }
        logPrint("+==================================================================+\n\n");
    }

} // end of namespace somm22
  