//C++ libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <array>

//GUI Library
#include "imgui.h"
#include "imgui-SFML.h"

//Framework
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

//Source files
#include "parameters.h"
#include "categories.h"
#include "create_output_file.h"
#include "idle.h"

#include "get_time.h"
#include "log.h"

using namespace std;

//Global
string current_time;

int main() {

    srand (time(NULL));
    cout << "Welcome ! " << endl;
    cout << "This program contains some memory leaks and may crashed."
            "\"Please re-run the application if it happened !\" " <<endl;

    /*
     * ---------------------------------------------------------------
     *                             SFML
     * ---------------------------------------------------------------
     */
    // (SFML) is a cross-platform software development library designed to provide 
    // a simple application programming interface (API)
    
    //Window settings
    sf::RenderWindow window(sf::VideoMode(700, 800), "Simulation Parameters", sf::Style::Close);
    window.setFramerateLimit(30);

    // Clock
    sf::Clock deltaClock;

    /*
     * ---------------------------------------------------------------
     *                             SFML/IMGUI
     * ---------------------------------------------------------------
     */
    //ImGui is a bloat-free graphical user interface library for C++.
    
    //Init ImGUI
    ImGui::SFML::Init(window);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    //Theme and frame rounding
    ImGui::StyleColorsLight();
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3.0f);

    // ImGUI - variables
    static ExampleAppLog my_log; //log variable
    static auto * p_open = new bool; //window variable
    *p_open = true;
    my_log.AddLog("%s [info] Welcome \n", &current_time[0]);

    //Font
    ImFont* font = io.Fonts->AddFontFromFileTTF("misc/fonts/Roboto-Regular.ttf", 16.0, nullptr);
    ImGui::SFML::UpdateFontTexture(); // important call: updates font texture

    /*
     *  User's variables
     */
    // Basic variables
    static int size_scenario    = 2;
    static int choice_scenario  = 1;
    static float charge         = 0.5;
    static int idle_time        = 0;

    // Vectors
    
    //scenario_categories : vector which contains the categories (Audio, Video, Data), that is the size of audio, video and data of every scenario.
    std::vector<categories> scenario_categories(size_scenario); 
    
    // RandomX : vectors which contain the randomness bounds of N
    // Exemple : RandomNbPacketsBound[0]._elem[0] : min nb_packets
    //           RandomNbPacketsBound[0]._elem[1] : max nb_packets
    std::vector<std::array<int,2>> RandomNbPacketsBound(size_scenario);
    std::vector<std::array<int,2>> RandomPacketSizeBound(size_scenario);
    std::vector<std::array<int,2>> RandomAudioBound(size_scenario);
    std::vector<std::array<int,2>> RandomVideoBound(size_scenario);
    std::vector<std::array<int,2>> RandomDataBound(size_scenario);



    // Initialisation of vectors
    scenario_categories     = initCategories(size_scenario);
    RandomNbPacketsBound    = initRandomness(size_scenario, 1, 10); //min max
    RandomPacketSizeBound   = initRandomness(size_scenario, 1, 200);
    RandomAudioBound        = initRandomness(size_scenario, 1, 10);
    RandomVideoBound        = initRandomness(size_scenario, 1, 10);
    RandomDataBound         = initRandomness(size_scenario, 1, 10);

    // Arrays
    int dimensions[2] = {3, 3}; //Dimensions (dimX and dimY) useful for generating source and destination of every category
    
    /*
     * ---------------------------------------------------------------
     *                      MAIN LOOP
     * ---------------------------------------------------------------
     */
    // Infinite loop
    while (window.isOpen()) {
        current_time = currentDateTime(); //get time
        sf::Event evt;
        while (window.pollEvent(evt)) {
            ImGui::SFML::ProcessEvent(evt);

            if (evt.type == sf::Event::Closed) {
                window.close();
            }
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        /*
         * ---------------------------------------------------------------
         *                      ImGUI - User Interface
         * ---------------------------------------------------------------
         */

        /*
         *  BEGIN
         */
        ImGui::PushFont(font);
        ImGui::Begin("Settings",p_open,ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

        /*
         *  SCENARIOS
         */
        ImGui::Text("Number of scenario (total) :");
        ImGui::InputInt("  ", &size_scenario);
        
        //Init categories and randomness bounds with a new size of scenarios
        if(ImGui::Button("Size changed (clear everything)")){
            scenario_categories     = initCategories(size_scenario);
            RandomNbPacketsBound    = initRandomness(size_scenario, 1, 10);
            RandomPacketSizeBound   = initRandomness(size_scenario, 1, 200);
            RandomAudioBound        = initRandomness(size_scenario, 1, 10);
            RandomVideoBound        = initRandomness(size_scenario, 1, 10);
            RandomDataBound         = initRandomness(size_scenario, 1, 10);
        }

        //Resizing all vector with the size of scenario
        scenario_categories.resize(size_scenario);
        RandomNbPacketsBound.resize(size_scenario);
        RandomPacketSizeBound.resize(size_scenario);
        RandomAudioBound.resize(size_scenario);
        RandomVideoBound.resize(size_scenario);
        RandomDataBound.resize(size_scenario);

        /*
         *  DIMENSIONS : dimX and dimY
         */
        ImGui::Text("\n"); //spacing
        ImGui::Text("DimX : "); ImGui::SameLine(235); ImGui::Text("DimY : ");
        ImGui::InputInt2("##", dimensions);

        /*
         *  CATEGORIES
         */
        ImGui::Separator();
        ImGui::Separator();

        ImGui::Text("Choose scenario : ");
        ImGui::SliderInt(" ", &choice_scenario, 1, size_scenario);
        if(choice_scenario <= size_scenario){
            //Display scenario
            ImGui::Text("Scenario No.%d", choice_scenario);

            //Audio
            ImGui::PushID(1);
            ImGui::InputInt(" Audio",&scenario_categories[choice_scenario - 1].categories[0]);
            ImGui::PopID();

            //Video
            ImGui::PushID(2);
            ImGui::InputInt(" Video",&scenario_categories[choice_scenario - 1].categories[1]);
            ImGui::PopID();

            //Data
            ImGui::PushID(3);
            ImGui::InputInt(" Data",&scenario_categories[choice_scenario - 1].categories[2]);
            ImGui::PopID();

            //Num of packets
            ImGui::PushID(4);
            ImGui::Text("\n Packets :");
            ImGui::InputInt(" Number of packets",&scenario_categories[choice_scenario - 1].packet[0]);
            ImGui::PopID();

            //Packet size
            ImGui::PushID(5);
            ImGui::InputInt(" Size packet",&scenario_categories[choice_scenario - 1].packet[1]);
            ImGui::PopID();

            //Charge
            ImGui::Text("\n");
            ImGui::Text("Charge :");ImGui::SameLine(390);ImGui::Text("Idle time : %d", idle_time);
            ImGui::SliderFloat("##",&scenario_categories[choice_scenario - 1].idle,0.01,1,"%.2f"); ImGui::SameLine();
            ImGui::Text("(%d %%)",static_cast<int>(scenario_categories[choice_scenario - 1].idle*100));

            //Idle
            idle_time = get_idle_time(scenario_categories[choice_scenario - 1].idle,scenario_categories,choice_scenario-1); //The idle time is calculated from the charge

            //Random Button
            ImGui::Text("\n"); //spacing
            if(ImGui::Button("Random scenarios")){
                scenario_categories = RandomCategories(size_scenario, RandomNbPacketsBound, RandomPacketSizeBound, RandomAudioBound, RandomVideoBound, RandomDataBound);
            }

            //Random
            if (ImGui::TreeNode("Random Bound"))
            {
                //Graphic Array with 2 columns
                ImGui::Columns(2, NULL, false);

                //First Column
                ImGui::PushID(9);
                ImGui::Text("Audio : ");
                ImGui::PushItemWidth(100);
                ImGui::InputInt2("(min) (max)", RandomAudioBound[choice_scenario - 1]._M_elems);
                ImGui::PopItemWidth();
                ImGui::PopID();

                ImGui::PushID(10);
                ImGui::Text("Video : ");
                ImGui::PushItemWidth(100);
                ImGui::InputInt2("(min) (max)", RandomVideoBound[choice_scenario - 1]._M_elems);
                ImGui::PopItemWidth();
                ImGui::PopID();

                ImGui::PushID(11);
                ImGui::Text("Data : ");
                ImGui::PushItemWidth(100);
                ImGui::InputInt2("(min) (max)", RandomDataBound[choice_scenario - 1]._M_elems);
                ImGui::PopItemWidth();
                ImGui::PopID();

                //Second Column
                ImGui::NextColumn();

                ImGui::PushID(6);
                ImGui::Text("Number of packets : ");
                ImGui::PushItemWidth(100);
                ImGui::InputInt2("(min) (max)", RandomNbPacketsBound[choice_scenario - 1]._M_elems);
                ImGui::PopItemWidth();
                ImGui::PopID();

                ImGui::PushID(7);
                ImGui::Text("Size packets : ");
                ImGui::PushItemWidth(100);
                ImGui::InputInt2("(min) (max)", RandomPacketSizeBound[choice_scenario - 1]._M_elems);
                ImGui::PopItemWidth();
                ImGui::PopID();

                //End graphic array
                ImGui::Columns(1);
                ImGui::TreePop();
            }
        }
        ImGui::Separator();
        ImGui::Separator();


        /*
         *  GENERATION
         */
        ImGui::Text("Number of files : %d", size_scenario);
        if(ImGui::Button("Generate simulation parameters files")){
            //pointer of all scenarios
            all_scenarios* ALL_SCENARIOS;

            //initialisation of scenario
            ALL_SCENARIOS = initAllScenarios(size_scenario, scenario_categories);

            //create scenarios
            CreateAllScenarios(ALL_SCENARIOS, size_scenario, scenario_categories, charge, dimensions);

            //log
            my_log.AddLog("%s [info] Success \n", &current_time[0]);
            my_log.AddLog("%s [info] %d output files : \n", &current_time[0], size_scenario);

            //output files
            for (int i = 0; i < size_scenario; ++i) {
                //file
                ofstream file_output;

                //output file's path
                std::string  output_path_temp = "io/Simulation Parameters " + std::to_string(i) + ".txt";

                //wrinting in file
                file_output.open(output_path_temp);
                create_txt_file(file_output, ALL_SCENARIOS, i, scenario_categories);
                file_output.close();

                //log
                my_log.AddLog("%s [info] %s \n", &current_time[0], &output_path_temp[0]);
            }
            //DO NOT FORGET TO FREE A POINTER !
            delete[]ALL_SCENARIOS;
        }
        /*
         *  LOG
         */
        ImGui::Separator();
        ImGui::Separator();
        ImGui::Text("Log :"); ImGui::SameLine();
        my_log.DrawInCurrentWindow("Log");

        ImGui::End(); // end window
        /*
         *  RENDER
         */
        ImGui::PopFont();
        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    cout << "* Exit"<<endl;
    return 0;
}
