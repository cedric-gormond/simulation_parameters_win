//
// Created by Cedric Gormond on 2019-02-12.
//

#ifndef SIMULATION_PARAMETERS_CATEGORIES_H
#define SIMULATION_PARAMETERS_CATEGORIES_H

#include <stdlib.h>
#include <vector>
#include <array>

typedef struct {
    int categories[3]; // [0]Audio [1]Video [2]Data
    int packet[2]; // [0] Num.Packets [1]Packet Size
    float idle; //idle
}categories;


long random_at_most(long max);

long random_between_numbers(long min, long max);


/*
 * initCategories : returns a vector of categories which contain initialized categories (zeros) 
 */
std::vector<categories> initCategories(const int size);

/*
 * initRandomness : returns a vector of int arrays (size 2) which contain initialized ramdoness parameters
 */
std::vector<std::array<int, 2>> initRandomness(const int size, const int min = 1, const int max = 10);

/*
 * RandomCategories : returns a vector of categories which contain randomized categories
 */
std::vector<categories> RandomCategories(
        const int size,
        std::vector<std::array<int,2>>,
        std::vector<std::array<int,2>>,
        std::vector<std::array<int,2>>,
        std::vector<std::array<int,2>>,
        std::vector<std::array<int,2>>);

#endif //SIMULATION_PARAMETERS_CATEGORIES_H
