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
    bool ascending(uint32_t value1, uint32_t value2){return (pct::pct[value1].pid<pct::pct[value2].pid);}

    void pctLog()
    {
        soProbe(202, "%s()\n", __func__);

        logPrint("+====================================================================================+\n");
        logPrint("|                               Process Control Table                                |\n");
        logPrint("+-------+-------------+----------+---------------+-----------+-----------------------+\n");
        logPrint("|  PID  | arrivalTime | burstProfile | \n");
        logPrint("+-------+-------------+----------+---------------+-----------+-----------------------+\n");
        
        std::vector<uint32_t> keys;
        for (auto i = pct::pct.begin(); i != pct::pct.end(); i++){
            keys.push_back(i->first);
        }
        std::sort(keys.begin(), keys.end(), ascending);
        
        for (uint32_t i = 0; i<keys.size(); i++){
            logPrint("| %5d | %11d | %12d | \n", pct::pct[keys[i]].pid, pct::pct[keys[i]].arrivalTime, pct::pct[keys[i]].burstProfile);
        }
        logPrint("+====================================================================================+\n\n");
    }

} // end of namespace somm22
