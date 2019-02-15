//
// Created by Cedric Gormond on 2019-02-11.
//

#ifndef SIMULATION_PARAMETERS_CREATE_OUTPUT_FILE_H
#define SIMULATION_PARAMETERS_CREATE_OUTPUT_FILE_H

#include <iostream>
#include <fstream>
#include <string>

#include "parameters.h"

/*
 * Create txt text : create an output file "Simulation Parameter i.txt" according to the parameters at the index i
 */
void create_txt_file(std::ofstream &file_output, all_scenarios *as, int index, std::vector<categories> vect);

#endif //SIMULATION_PARAMETERS_CREATE_OUTPUT_FILE_H
