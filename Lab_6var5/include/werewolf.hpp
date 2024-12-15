#pragma once
#include "NPC.hpp"

class Werewolf : public NPC
{
public:
    Werewolf(const int &, const int &, const std::string &);

    void print(std::ostream &) override;

    void accept(NPC *, const int &) override;

    friend std::ostream &operator<<(std::ostream &, const Werewolf &);
};
