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
 * initAllScenarios : returns a pointer all_scenario initialized with size_scenario
 */
all_scenarios* initAllScenarios(const int size_scenario, std::vector<categories> vect);

/*
 * initScenario : returns a pointer of scenarios
 */
scenario* initScenario(std::vector<categories> vect);

/*
 * initParameters : init the parameters of a scenario
 */
void initParameters(parameter *p);

/*
 * CreateAllScenarios : set the parameters of every scenarios according to the vector vect and arguments charge, dimensions
 */
void CreateAllScenarios(all_scenarios *as, int size, std::vector<categories> vect, float charge, int dimensions[2]);

/*
 * setSource : returns a int between 0 and size[0]*[1]
 */
int setSource(int dimensions[2]);

/*
 * setDestination : setSource : returns a int between 0 and size[0]*[1] different to source
 */
int setDestination(parameter p, int dimensions[2]);


#endif //SIMULATION_PARAMETERS_PARAMETERS_H

