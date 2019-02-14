//
// Created by Cedric Gormond on 2019-02-12.
//

#include "idle.h"
#include "parameters.h"

int get_idle_time(float charge, parameter p){
    int idle;
    idle = ((1-charge)/charge)*p.packet_size*2;
    return idle;
}

int get_idle_time(float charge, std::vector<categories> vect, int index) {
    int idle;
    idle = ((1-charge)/charge)*vect[index].packet[1]*2;
    return idle;
}
