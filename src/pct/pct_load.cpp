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
#include <iostream> // for std::cout


namespace somm22
{
    void pctLoad(const char* fname) 
    {
        soProbe(203, "%s(\"%s\")\n", __func__, fname);

        

        /* replace with your code */
        
            FILE* fin = fopen(fname, "r");

            if(fin == NULL){
                throw Exception(EINVAL, (std::string(__func__) + std::string(" Invalid file: ") + std::string(fname)).c_str());
            }

            char* line=NULL;
            size_t sz =0;
            
            while (getline(&line, &sz, fin) != 0){

                //remove comments
                int commentPosition = -1;
                char* line= strdup(line);
                if (sscanf(line, "%*[^\n]#%n", &commentPosition) == 1) {
                    line.erase(commentPosition);
                }
                if (commentPosition == 0) {
                    continue;
                }
                
                // remove spaces
                line.erase(std::remove_if(line, line.end(), ::isspace), line.end());
                // find all ";" positions
                std::vector<int> positions;
                for(size_t i=0;i<line.length();i++){
                    if(line[i] == ';')
                        positions.push_back(i);
                }
                


                uint32_t pid;
                uint32_t arrivalTime;
                std::vector<double> burstProfile;

                if (sscanf(line.c_str(), "%u ;%u ;%g", &pid, &arrivalTime, &burstProfile) != 3 ){
                    throw Exception(EINVAL, (std::string(__func__) + std::string(" Invalid line: ") + std::to_string(line_val)).c_str());
                    std::cout << "Test \n";
                }   

                pid = (uint32_t)std::stoi(line.substr(0 , positions[0]));
                arrivalTime = (uint32_t)std::stoi(line.substr(positions[0]+1 , positions[1]));
                burstProfile = (std::vector<double>)std::stod(line.substr(positions[1]+1 , positions[2]));

                // insert process in pct
                pct::pct.insert(std::pair<int, pct::processData>(pid, {pid, arrivalTime, burstProfile}));

            }
        in_file.close();

    }
} // end of namespace somm22

