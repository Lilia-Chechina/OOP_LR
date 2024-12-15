#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "include/bear.hpp"
#include "include/thug.hpp"
#include "include/observer.hpp"
#include "include/factory.hpp"
#include "include/werewolf.hpp"

void load(std::vector<std::shared_ptr<NPC>> &array, std::ifstream &file)
{
    while (file)
    {
        auto tmp = factory(file);
        if (tmp)
            array.push_back(tmp);
    }
}

void save(std::vector<std::shared_ptr<NPC>> &array, std::ofstream &file)
{
    for (std::shared_ptr<NPC> &elem : array)
    {
        elem->print(file);
        file << std::endl;
    }
}

int main()
{
    ConsoleObserver cobs;
    std::ofstream filelog("log.txt");
    FileObserver fobs(filelog);

    std::vector<std::shared_ptr<NPC>> persons;

    std::string query;
    do
    {
        std::cin >> query;
        if (query == "load")
        {
            std::ifstream file_for_load;
            std::string filename;
            std::cin >> filename;
            file_for_load.open(filename);
            load(persons, file_for_load);
        }
        else if (query == "save")
        {
            std::ofstream file_for_save;
            std::string filename;
            std::cin >> filename;
            file_for_save.open(filename);
            save(persons, file_for_save);
        }
         else if (query == "add")
        {
            std::cout << "Sucess first word";
            std::string input_line;
            while (std::getline(std::cin, input_line)) {  
            std::istringstream input(input_line);
            auto new_npc = factory(input);
            if (new_npc) {
                persons.push_back(new_npc);
                std::cout << "Sucess second word";
                break;
            }
        }
    }
        else if (query == "show")
        {
            if (persons.size() > 0) {
                for (auto &elem : persons) {
                    elem->print(std::cout); 
                    std::cout << std::endl;
                }
            } else {
                std::cout << "No NPCs to display." << std::endl;
            }
        }
    } while (query != "fight");

    for (auto &elem : persons)
    {
        elem->attach(&cobs);
        elem->attach(&fobs);
    }

    std::cout << "Enter a distance" << std::endl;

    int distance;
    std::cin >> distance;

    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), distance);
        }
    }
    std::cout << "Survivors:" << std::endl;
    for (auto &elem : persons)
    {
        if (elem->is_alive())
        {
            elem->print(std::cout);
            std::cout << std::endl;
        }
    }

    return 0;
}