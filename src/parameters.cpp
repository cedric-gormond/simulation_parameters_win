//
// Created by Cedric Gormond on 2019-02-12.
//

#include "parameters.h"
#include "categories.h"
#include "idle.h"

void initParameters(parameter *p){
    p->category_trafic = 0;
    p->source = 0;
    p->destination = 0;
    p->packet_size = 0;
    p->num_of_packets= 0;
    p->idle_time = 0;
}

scenario* initScenario(std::vector<categories> vect){
    auto s = new scenario[vect.size()]; //vect.size <=> size_scenario

    for (int i = 0; i < vect.size(); ++i) {
        s[i].audio = new parameter[vect.size()];
        initParameters(s[i].audio);

        s[i].video = new parameter[vect.size()];
        initParameters(s[i].video);

        s[i].data  = new parameter[vect.size()];
        initParameters(s[i].data);
    }
    return s;
}

all_scenarios* initAllScenarios(const int size_scenario, std::vector<categories> vect){
    auto all_s = new all_scenarios[size_scenario];

    for (int i = 0; i < size_scenario; ++i) {
        all_s[i].s = initScenario(vect);
    }
    return all_s;
}

void CreateAllScenarios(all_scenarios *as, int size, std::vector<categories> vect, float charge, int dimensions[2]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < vect[i].categories[0]; ++j) {
            if(vect[i].categories[0] != 0){
                as->s[i].audio[j].category_trafic = 1;
                as->s[i].audio[j].source          = setSource(dimensions);
                as->s[i].audio[j].destination     = setDestination(as->s->audio[i], dimensions);
                as->s[i].audio[j].num_of_packets  = vect[i].packet[0];
                as->s[i].audio[j].packet_size     = vect[i].packet[1];
                as->s[i].audio[j].idle_time       = get_idle_time(vect[i].idle, as->s[i].audio[j]);
            }
            else{
                continue;
            }
        }

        for (int j = 0; j < vect[i].categories[1]; ++j) {
            if(vect[i].categories[1] != 0){
                as->s[i].video[j].category_trafic = 2;
                as->s[i].video[j].source          = setSource(dimensions);
                as->s[i].video[j].destination     = setDestination(as->s->video[i], dimensions);
                as->s[i].video[j].num_of_packets  = vect[i].packet[0];
                as->s[i].video[j].packet_size     = vect[i].packet[1];
                as->s[i].video[j].idle_time       = get_idle_time(vect[i].idle, as->s[i].video[j]);
            }
            else{
                continue;
            }
        }

        for (int j = 0; j < vect[i].categories[2]; ++j) {
            if(vect[i].categories[2] != 0){
                as->s[i].data[j].category_trafic = 3;
                as->s[i].data[j].source          = setSource(dimensions);
                as->s[i].data[j].destination     = setDestination(as->s->data[i], dimensions);
                as->s[i].data[j].num_of_packets  = vect[i].packet[0];
                as->s[i].data[j].packet_size     = vect[i].packet[1];
                as->s[i].data[j].idle_time       = get_idle_time(vect[i].idle, as->s[i].data[j]);
            }
            else{
                continue;
            }
        }
    }
}

int setSource(int dimensions[2]) {
    int s = random_at_most(dimensions[0]*dimensions[1]);
    return s;
}

int setDestination(parameter p, int dimensions[2]) {
    int d = random_at_most(dimensions[0]*dimensions[1]);
    while(d == p.source){
        d = random_at_most(dimensions[0]*dimensions[1]);
    }
    return d;
}
