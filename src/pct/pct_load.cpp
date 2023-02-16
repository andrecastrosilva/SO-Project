/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdio.h>

#include <map>
#include <string>
#include <regex>
#include <stdint.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace somm22
{
    void pctLoad(const char* fname) 
    {
        soProbe(203, "%s(\"%s\")\n", __func__, fname);

        /* replace with your code */
        std::string line;
        std::ifstream in_file;
        in_file.open(fname);

        if (!in_file.is_open()){
            throw Exception(EIO, "Error opening the file");
        }
        
        size_t l_value = 0;
        while(std::getline(in_file , line)){
            l_value++;
            
            //remove comments
            int comment = -1;
            for(size_t i=0;i<line.size();i++)
            {
                if(line[i] == '#'){
                    comment = i;
                }
                break;
            }
            if(comment != -1)
                line = line.substr(0 , comment);
            if(comment == 0)
                continue;
            
            //remove spaces
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace),line.end());

            //find all ";" positions
            std::vector<int> pos;
            for(size_t i=0;i<line.length();i++)
                if(line[i] == ';')
                    pos.push_back(i);

            //process data structure fields
            uint32_t pid;
            uint32_t arrivalTime;
            std::vector<uint32_t> burstProfile;
            
            //find arguments
            pid = (uint32_t)std::stoi(line.substr(0 , pos[0]));
            arrivalTime = (uint32_t)std::stoi(line.substr(pos[0]+1 , pos[1]));
            burstProfile = (std::vector<uint32_t>)std::stoi(line.substr(pos[1]+1 , pos[2])); 
                 
            //test if the pid already exists
            if(pct::pct.count(pid) > 0){
                throw Exception(EINVAL, (std::string(__func__) + std::string(" This pid aldready exists")).c_str());
            }else{
                pct::pct[pid].pid = pid;
                pct::pct[pid].arrivalTime = arrivalTime;
                pct::pct[pid].burstProfile = burstProfile;
                pct::pct[pid].currentState = 0;
            }                
        }
        in_file.close();

    }
} // end of namespace somm22

