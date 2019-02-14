//
// Created by Cedric Gormond on 2019-02-11.
//

#ifndef SIMULATION_PARAMETERS_PARAMETERS_H
#define SIMULATION_PARAMETERS_PARAMETERS_H

#include <vector>
#include "categories.h"

// all_scenarios is a struct which contains n scenarios which contain themselves
// m_a parameters audio, m_v parameters video and m_d parameters data
typedef struct {
    int category_trafic;
    int source;
    int destination;
    int packet_size;
    int num_of_packets;
    int idle_time;
} parameter;

typedef struct {
    parameter *audio;
    parameter *video;
    parameter *data;
} scenario;

typedef struct {
    scenario* s;
}all_scenarios;


/*
 * initAllScenarios :
 */
all_scenarios* initAllScenarios(const int size_scenario, std::vector<categories> vect);

/*
 * initScenario :
 */
scenario* initScenario(std::vector<categories> vect);

/*
 * initParameters :
 */
void initParameters(parameter *p);

/*
 * CreateAllScenarios :
 */
void CreateAllScenarios(all_scenarios *as, int size, std::vector<categories> vect, float charge, int dimensions[2]);

/*
 * setSource :
 */
int setSource(int dimensions[2]);

/*
 * setDestination :
 */
int setDestination(parameter p, int dimensions[2]);


#endif //SIMULATION_PARAMETERS_PARAMETERS_H

