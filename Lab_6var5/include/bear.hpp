#pragma once
#include "NPC.hpp"

class Bear : public NPC
{
public:
    Bear(const int &, const int &, const std::string &);

    void print(std::ostream &) override;

    void accept(NPC *, const int &) override;

    friend std::ostream &operator<<(std::ostream &, const Bear &);
};