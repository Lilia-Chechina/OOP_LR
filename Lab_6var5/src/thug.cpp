#include "../include/werewolf.hpp"
#include "../include/thug.hpp"
#include "../include/bear.hpp"
#include <algorithm>

Thug::Thug(const int &_x, const int &_y, const std::string &_name)
{
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

void Thug::print(std::ostream &out)
{
    out << *this;
}

void Thug::accept(NPC *attacker, const int &distance)
{
    if (alive && attacker->is_alive() && dynamic_cast<Werewolf *>(attacker))
    {
        bool win = is_close(*attacker, distance);
        if (win)
            alive = false;
        notify(attacker, win);
    }
}

std::ostream &operator<<(std::ostream &out, const Thug &other)
{
    return out << "Thug " << other.name << " {" << other.x << ", " << other.y << '}';
}