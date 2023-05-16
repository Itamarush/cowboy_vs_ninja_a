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
        public:
        std::vector <Character> team;
        Character *leader;

        Team(Character *leader);
        void add(Character *player);
        void attack(Team * enemy);
        int stillAlive();
        void print();
    };
}