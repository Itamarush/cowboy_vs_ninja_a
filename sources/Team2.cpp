#include "Team.hpp"

Team2::Team2(Character *leader) : Team(leader) 
{
    if(leader->getIsPlaying())
    {
        fighters.clear();
        leader->setIsPlaying(false);
    }
    add(leader);
}

Team2::~Team2()
{
    for (const auto& fighter : fighters2)
    {
        delete fighter;   
    }
}
// change!!!!!!!!11
void Team2::add(Character *character)
{
    if (character->getIsPlaying())
    {
        throw std::runtime_error(character->getName() + " is already in a team!");
    }
    if (fighters2.size() >= 10)
    {
        throw std::runtime_error("The team is full, cannot add more members!");
    }
    if (std::find(fighters2.begin(), fighters2.end(), character) != fighters2.end())
    {
        throw std::runtime_error(character->getName() + " is already in the team!");
    }
    fighters2.push_back(character);
    character->setIsPlaying(true);
}
    std::vector<Character *> Team2::getMembers()
    {
        return fighters2;
    }

    std::vector<Character *> Team2::getAliveMembers(const std::vector<Character *> &characters)
    {
        std::vector<Character *> aliveMembers;
        for (auto character : characters)
        {
            if (character->isAlive())
            {
                aliveMembers.push_back(character);
            }
        }
        return aliveMembers;
    }

    int Team2::stillAlive()
    {
        int count = 0;
        for (auto member : fighters2)
        {
            if (member->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team2::print()
    {
        for (auto member : fighters2)
        {
            std::cout << "    " << member->print() << std::endl;
        }
    }
