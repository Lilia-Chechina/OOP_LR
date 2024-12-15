#include "../include/werewolf.hpp"
#include "../include/bear.hpp"
#include "../include/thug.hpp"
#include <algorithm>

Werewolf::Werewolf(const int &_x, const int &_y, const std::string &_name)
{
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

void Werewolf::print(std::ostream &out)
{
    out << *this;
}

void Werewolf::accept(NPC *attacker, const int &distance)
{
    if (alive && attacker->is_alive() && dynamic_cast<Bear *>(attacker))
    {
        bool win = is_close(*attacker, distance);
        if (win)
            alive = false;
        notify(attacker, win);
    }
}

std::ostream &operator<<(std::ostream &out, const Werewolf &other)
{
    return out << "Werewolf " << other.name << " {" << other.x << ", " << other.y << '}';
}