#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include <array>

#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace ariel;
using namespace std;

namespace ariel
{
    class Team 
    {
        vector <Character*> fighters;
        Character *leader;
        
        public:
        Team(Character *leader);
        ~Team();
        void add(Character *player);
        Character *closetMemberIsAlive(std::vector<Character *> &members, Character *leader);
        Character *closetEnemyIsAlive(std::vector<Character *> &members, Character *leader);
        void attackEnemy(Character *attacker, Character *victim);
        void setLeader(Character *newLeader);
        void attack(Team * enemy);
        int stillAlive();
        void print();
    };

}