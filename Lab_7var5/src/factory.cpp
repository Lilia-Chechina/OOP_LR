#include "../include/factory.hpp"
#include "../include/bear.hpp"
#include "../include/thug.hpp"
#include "../include/werewolf.hpp"

std::shared_ptr<NPC> factory(std::istream &in)
{
    std::string type, name;
    int x, y;
    char c;
    in >> type >> name >> c >> x >> c >> y >> c;
    std::shared_ptr<NPC> res;
    if (type == "Bear")
    {
        res = std::make_shared<Bear>(x, y, name);
    }
    else if (type == "Thug")
    {
        res = std::make_shared<Thug>(x, y, name);
    }
    else if (type == "Werewolf")
    {
        res = std::make_shared<Werewolf>(x, y, name);
    }
    else if (type != "")
    {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}

std::shared_ptr<NPC> factory(const std::string &type, const std::string &name, const int &x, const int &y)
{
    std::shared_ptr<NPC> res;
    if (type == "Bear")
    {
        res = std::make_shared<Bear>(x, y, name);
    }
    else if (type == "Thug")
    {
        res = std::make_shared<Thug>(x, y, name);
    }
    else if (type == "Werewolf")
    {
        res = std::make_shared<Werewolf>(x, y, name);
    }
    else
    {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}