#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <memory>
#include "../include/bear.hpp"
#include "../include/thug.hpp"
#include "../include/werewolf.hpp"
#include "../include/factory.hpp"

TEST(Constructors, Werewolf)
{
    Werewolf w(3, 3, "Lupus");
    std::stringstream out;
    w.print(out);
    ASSERT_EQ(out.str(), "Werewolf Lupus {3, 3}");
}

TEST(Constructors, Bear)
{
    Bear s(0, 0, "Medved");
    std::stringstream out;
    s.print(out);
    ASSERT_EQ(out.str(), "Bear Medved {0, 0}");
}

TEST(Constructors, Thug)
{
    Thug t(1, 1, "Robin");
    std::stringstream out;
    t.print(out);
    ASSERT_EQ(out.str(), "Thug Robin {1, 1}");
}

TEST(Fabric, basic)
{
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Bear", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    persons.push_back(factory("Werewolf", "Name", 0, 0));

    std::stringstream out;
    for (auto &elem : persons)
    {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Bear Name {0, 0}Thug Name {0, 0}Werewolf Name {0, 0}");
}

TEST(Fabric, Digits)
{
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Bear", "Name", 8, 29));
    persons.push_back(factory("Thug", "Name", 65, 198));
    persons.push_back(factory("Werewolf", "Name", 457, 35));

    std::stringstream out;
    for (auto &elem : persons)
    {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Bear Name {8, 29}Thug Name {65, 198}Werewolf Name {457, 35}");
}

TEST(FactoryTest, CreateFromStream)
{
    std::istringstream input_bear("Bear Name x 100 y 200");
    std::istringstream input_thug("Thug Name x 150 y 250");
    std::istringstream input_werewolf("Werewolf Name x 200 y 300");

    auto bear = factory(input_bear);
    auto thug = factory(input_thug);
    auto werewolf = factory(input_werewolf);

    std::stringstream out;

    bear->print(out);
    ASSERT_EQ(out.str(), "Bear Name {100, 200}");

    out.str(""); 
    thug->print(out);
    ASSERT_EQ(out.str(), "Thug Name {150, 250}");

    out.str(""); 
    werewolf->print(out);
    ASSERT_EQ(out.str(), "Werewolf Name {200, 300}");
}

TEST(Fighting, 1_varinat)
{
    // Во внешнем цикле перебираются защитники
    // Во внутреннем цикле нападающие
    // Медведя в 1 внешнем цикле убил разбойник
    // Во 2 внешнем цикле разбойника убил оборотень
    // В 3 цикле оборотня никто не убил
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Bear", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    persons.push_back(factory("Werewolf", "Name", 0, 0));

    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), 0);
        }
    }
    for (int elem = 0; elem < 3; ++elem)
    {
        if (elem == 0) // проверка на то, что медведь мёртв
        {
            ASSERT_FALSE(persons[elem]->is_alive());
        }
        else if (elem == 1)  // проверка на то, что разбойник мёртв
        {ASSERT_FALSE(persons[elem]->is_alive());}
        else if (elem == 2){  // оборотень жив
            {ASSERT_TRUE(persons[elem]->is_alive());}
        }
    }
}

TEST(Fighting, 2_varinat)
{   
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Werewolf", "Name", 0, 0));
    persons.push_back(factory("Bear", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), 0);
        }
    }
    for (int elem = 0; elem < 3; ++elem)
    {
        if (elem == 0) // Оборотня убил медвед
        {
            ASSERT_FALSE(persons[elem]->is_alive());
        }
        else if (elem == 1)  // Медведя убил разбойник
        {ASSERT_FALSE(persons[elem]->is_alive());}
        else if (elem == 2){  // Разбойник жив
            {ASSERT_TRUE(persons[elem]->is_alive());}
        }
    }
}

TEST(Fighting, 3_varinat)
{   
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Thug", "Name", 0, 6));
    persons.push_back(factory("Werewolf", "Name", 7, 0));
    persons.push_back(factory("Bear", "Name", 0, 8));
    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), 20);
        }
    }
    for (int elem = 0; elem < 3; ++elem)
    {
        if (elem == 0) // Разбойника убил оборотень
        {
            ASSERT_FALSE(persons[elem]->is_alive());
        }
        else if (elem == 1)  // Оборотня убил медведь
        {ASSERT_FALSE(persons[elem]->is_alive());}
        else if (elem == 2){  // Медведь жив
            {ASSERT_TRUE(persons[elem]->is_alive());}
        }
    }
}

TEST(Fighting, 4_varinat)
{   
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Thug", "Name", 0, 200));
    persons.push_back(factory("Werewolf", "Name", 7, 0));
    persons.push_back(factory("Bear", "Name", 0, 8));
    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), 20);
        }
    }
    for (int elem = 0; elem < 3; ++elem)
    {
        if (elem == 0) // Разбойник далеко, его не убивают
        {
            ASSERT_TRUE(persons[elem]->is_alive());
        }
        else if (elem == 1)  // Оборотня убил медведь
        {ASSERT_FALSE(persons[elem]->is_alive());}
        else if (elem == 2){  // Медведь жив
            {ASSERT_TRUE(persons[elem]->is_alive());}
        }
    }
}

TEST(Fighting, 5_varinat)
{   
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Thug", "Name", 0, 200));
    persons.push_back(factory("Werewolf", "Name", 7, 0));
    persons.push_back(factory("Bear", "Name", 0, 201));
    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), 20);
        }
    }
    for (int elem = 0; elem < 3; ++elem)
    {
        if (elem == 0) // Разбойник далеко, его не убивают
        {
            ASSERT_TRUE(persons[elem]->is_alive());
        }
        else if (elem == 1)  // Оборотень далеко от медведя. Тоже живёт
        {ASSERT_TRUE(persons[elem]->is_alive());}
        else if (elem == 2){  // Медведя убивает разбойник
            {ASSERT_FALSE(persons[elem]->is_alive());}
        }
    }
}

TEST(FactoryTest, CreateUnknownType) {
    std::shared_ptr<NPC> npc = factory("Ptincess", "Fiona", 30, 30);
    ASSERT_EQ(npc, nullptr);
}

TEST(FactoryTest, CreateBear) {
    std::shared_ptr<NPC> npc = factory("Bear", "Grizzly", 0, 0);
    ASSERT_NE(npc, nullptr);
    ASSERT_TRUE(dynamic_cast<Bear*>(npc.get()));
}

TEST(FactoryTest, CreateThug) {
    std::shared_ptr<NPC> npc = factory("Thug", "Bandit", 10, 10);
    ASSERT_NE(npc, nullptr);
    ASSERT_TRUE(dynamic_cast<Thug*>(npc.get()));
}

TEST(FactoryTest, CreateWerewolf) {
    std::shared_ptr<NPC> npc = factory("Werewolf", "Wolf", 20, 20);
    ASSERT_NE(npc, nullptr);
    ASSERT_TRUE(dynamic_cast<Werewolf*>(npc.get()));
}