//
// Created by Cedric Gormond on 2019-02-12.
//

#ifndef SIMULATION_PARAMETERS_IDLE_H
#define SIMULATION_PARAMETERS_IDLE_H

#include "parameters.h"

int get_idle_time(float charge, parameter p);

int get_idle_time(float charge, std::vector<categories> vect, int index);

#endif //SIMULATION_PARAMETERS_IDLE_H
