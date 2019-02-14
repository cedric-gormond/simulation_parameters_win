//
// Created by Cedric Gormond on 2019-02-11.
//

#include "create_output_file.h"

void create_txt_file(std::ofstream &file_output, all_scenarios *as, int index, std::vector<categories> vect)
{
    std::cout << " * Writing in file " << std::endl << std::endl;
    int counter = 0;
    for (int i=0; i < vect[index].categories[0]; i++) {
        file_output << "#No." << counter++<<std::endl;
        file_output << "category_trafic " << as->s[index].audio[i].category_trafic << std::endl;
        file_output << std::endl;

        file_output << "source "          << as->s[index].audio[i].source << std::endl;
        file_output << std::endl;

        file_output << "destination "     << as->s[index].audio[i].destination << std::endl;
        file_output << std::endl;

        file_output << "packet_size "     << as->s[index].audio[i].packet_size << std::endl;
        file_output << std::endl;

        file_output << "num_of_packets "  << as->s[index].audio[i].num_of_packets << std::endl;
        file_output << std::endl;

        file_output << "idle_time "       << as->s[index].audio[i].idle_time << std::endl;
        file_output << std::endl;
    }

    for (int i=0; i < vect[index].categories[1]; i++) {
        file_output << "#No." << counter++<<std::endl;
        file_output << "category_trafic " << as->s[index].video[i].category_trafic << std::endl;
        file_output << std::endl;

        file_output << "source "          << as->s[index].video[i].source << std::endl;
        file_output << std::endl;

        file_output << "destination "     << as->s[index].video[i].destination << std::endl;
        file_output << std::endl;

        file_output << "packet_size "     << as->s[index].video[i].packet_size << std::endl;
        file_output << std::endl;

        file_output << "num_of_packets "  << as->s[index].video[i].num_of_packets << std::endl;
        file_output << std::endl;

        file_output << "idle_time "       << as->s[index].video[i].idle_time << std::endl;
        file_output << std::endl;
    }

    for (int i=0; i < vect[index].categories[2]; i++) {
        file_output << "#No." << counter++<<std::endl;
        file_output << std::endl;

        file_output << "category_trafic " << as->s[index].data[i].category_trafic << std::endl;
        file_output << std::endl;

        file_output << "source "          << as->s[index].data[i].source << std::endl;
        file_output << std::endl;

        file_output << "destination "     << as->s[index].data[i].destination << std::endl;
        file_output << std::endl;

        file_output << "packet_size "     << as->s[index].data[i].packet_size << std::endl;
        file_output << std::endl;

        file_output << "num_of_packets "  << as->s[index].data[i].num_of_packets << std::endl;
        file_output << std::endl;

        file_output << "idle_time "       << as->s[index].data[i].idle_time << std::endl;
        file_output << std::endl;
    }
}