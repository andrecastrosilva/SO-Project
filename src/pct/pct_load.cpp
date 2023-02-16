/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdio.h>

#include <map>
#include <string>
#include <regex>
#include <cstdio>   // for scanf()
#include <vector>
#include <fstream>  // for std::ifstream



namespace somm22
{
    void pctLoad(const char* fname) 
    {
        soProbe(203, "%s(\"%s\")\n", __func__, fname);

        /* replace with your code */
        std::string line;
        std::ifstream in_file;
        in_file.open(fname);
        if(in_file.is_open()){

            size_t line_val = 0;

            while (std::getline(in_file, line)){

                line_val++;

                //remove comments
                int commentPosition = -1;
                if (sscanf(line.c_str(), "%*[^\n]#%n", &commentPosition) == 1) {
                    line.erase(commentPosition);
                }
                if (commentPosition == 0) {
                    continue;
                }

                // remove spaces
                line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

                // find all ";" positions
                std::vector<int> positions;
                int position;
                while (scanf("%*[^;]%n", &position) == 1) {
                    positions.push_back(position);
                    line[position] = ' ';
                    scanf("%*c");
                }


                uint32_t pid;
                uint32_t arrivalTime;
                std::vector<double> burstProfile;

                if (sscanf(line.c_str(), "%u%u%u", &pid, &arrivalTime, &burstProfile) != 3 ){
                    throw Exception(EINVAL, (std::string(__func__) + std::string(" Invalid line: ") + std::to_string(line_val)).c_str());
                }   

                pid = (uint32_t)std::stoi(line.substr(0 , positions[0]));
                arrivalTime = (uint32_t)std::stoi(line.substr(positions[0]+1 , positions[1]));
                burstProfile = (std::vector<double>)std::stod(line.substr(positions[1]+1 , positions[2]));

                // insert process in pct
                pct::pct.insert(std::pair<int, pct::processData>(pid, {pid, arrivalTime, burstProfile}));

            }
            
        }else{
                throw Exception(EIO,"Error opening the file");
        }
        in_file.close();

    }

} // end of namespace somm22

