/*
 *  \author ...
 */

#include "pct_module.h"

#include <stdio.h>

#include <map>
#include <string>
#include <regex>
#include <vector>


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
            char* new_line=NULL;
            
            while (getline(&line, &sz, fin) != -1){
                
                //remove spaces
                new_line = line;
                while(*new_line != '\0'){
                    if(*new_line == ' '){
                        for(char* i = new_line; *i != '\0'; i++){
                            *i = *(i+1);
                        }
                    }
                    else{
                        new_line++;
                    }
                }

                //remove comments
                int commentPosition = -1;
                for(size_t i=0;i<strlen(line);i++)
                {
                    if(line[0] == '#') commentPosition = i;
                    break;
                }
                if(commentPosition == -1){
                    //find all ";" positions
                    std::vector<std::string> fields;
                    size_t start_pos = 0;
                    for (size_t i = 0; i < strlen(line); i++) {
                        if (line[i] == ';') {
                            size_t field_length = i - start_pos;
                            std::string field(line + start_pos, field_length);
                            fields.push_back(field);
                            start_pos = i + 1;
                        }
                    }
                    //add last field
                    size_t field_length = strlen(line) - start_pos;
                    std::string field(line + start_pos, field_length);
                    fields.push_back(field);

                    //separate fiels[2] by ","
                    std::vector<std::string> fields2;
                    start_pos = 0;
                    for (size_t j = 0; j < fields[2].length(); j++) {
                        if (fields[2][j] == ',') {
                            size_t field2_length = j - start_pos;
                            std::string field2(fields[2].c_str() + start_pos, field2_length);
                            fields2.push_back(field2);
                            start_pos = j + 1;
                        }
                    }
                    //add last field
                    size_t field2_length = fields[2].length() - start_pos;
                    std::string field2(fields[2].c_str() + start_pos, field2_length);
                    fields2.push_back(field2);

                    //process data structure fields
                    uint32_t pid;
                    uint32_t arrivalTime;
                    std::vector<double> burstProfile;

                    pid = std::stoi(fields[0]);
                    arrivalTime = std::stoi(fields[1]);
                    for(size_t i=0;i<fields2.size();i++){
                        burstProfile.push_back(std::stod(fields2[i]));
                    }
                    
                    /*
                    printf("pid: %d,   arrivalTime: %d: ", pid, arrivalTime);
                    printf("burstProfile: ");
                    for(size_t i=0;i<burstProfile.size();i++){
                        printf("%g ", burstProfile[i]);
                    }
                    printf("\n");
                    */

                    //add to pct
                    pct::pct[pid].pid = pid;
                    pct::pct[pid].arrivalTime = arrivalTime;
                    //add burstProfile
                    for(size_t k=0;k<burstProfile.size();k++){
                        pct::pct[pid].burstProfile.push_back(burstProfile[k]);
                    }
                    
                }else{
                    continue;
                }
            }
    }
} // end of namespace somm22

