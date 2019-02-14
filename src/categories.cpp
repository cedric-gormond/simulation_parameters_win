//
// Created by Cedric Gormond on 2019-02-12.
//

#include "categories.h"
#include "parameters.h"

std::vector<categories> initCategories(const int size){
    std::vector<categories> vect_temp(size);
    for (int i = 0; i < size; ++i) {
        vect_temp[i].categories[0] = 0; //Audio
        vect_temp[i].categories[1] = 0; //Video
        vect_temp[i].categories[2] = 0; //Data
        vect_temp[i].packet[0]     = 0;
        vect_temp[i].packet[1]     = 0;
        vect_temp[i].idle          = 0.01;
    }
    return vect_temp;
}

std::vector<std::array<int, 2>> initRandomness(const int size, const int min, const int max) {
    std::vector<std::array<int,2>> vect_temp(size);
    for (int i = 0; i < size; ++i) {
        vect_temp[i]._M_elems[0] = min;
        vect_temp[i]._M_elems[1] = max;
    }
    return vect_temp;
}


std::vector<categories> RandomCategories(const int size, std::vector<std::array<int,2>> RandomNbPacketsBound, std::vector<std::array<int,2>> RandomPacketSizeBound, std::vector<std::array<int,2>> RandomAudioBound, std::vector<std::array<int,2>> RandomVideoBound, std::vector<std::array<int,2>> RandomDataBound){
    std::vector<categories> vect_temp(size);
    for (int i = 0; i < size; ++i) {
        vect_temp[i].categories[0] = random_between_numbers(RandomAudioBound[i]._M_elems[0],RandomAudioBound[i]._M_elems[1]); //Audio
        vect_temp[i].categories[1] = random_between_numbers(RandomVideoBound[i]._M_elems[0],RandomVideoBound[i]._M_elems[1]); //Video
        vect_temp[i].categories[2] = random_between_numbers(RandomDataBound[i]._M_elems[0],RandomDataBound[i]._M_elems[1]); //Data
        //Reminder :
        // RandomNbPacketsBound[i]._M_elems[0] <=> min
        // RandomNbPacketsBound[i]._M_elems[1] <=> max
        // RandomNbPacketsBound[i]._M_elems[0] <=> min
        // RandomNbPacketsBound[i]._M_elems[1] <=> max

        vect_temp[i].packet[0]     = random_between_numbers(RandomNbPacketsBound[i]._M_elems[0],RandomNbPacketsBound[i]._M_elems[1]);
        vect_temp[i].packet[1]     = random_between_numbers(RandomPacketSizeBound[i]._M_elems[0],RandomPacketSizeBound[i]._M_elems[1]);
        vect_temp[i].idle          = 0.5;
    }
    return vect_temp;
}


long random_at_most(long max)
{
    unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
            num_bins = (unsigned long) max + 1,
            num_rand = (unsigned long) RAND_MAX + 1,
            bin_size = num_rand / num_bins,
            defect = num_rand % num_bins;

    long x;
    do {
        x = rand();
    }

    // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);

    // Truncated division is intentional
    return x/bin_size;
}

long random_between_numbers(long min, long max)
{
    int r = (rand()%(max-min)) + min;
    return r;
}