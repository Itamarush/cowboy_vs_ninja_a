#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

namespace ariel{
    class Character{
        private:
            Point* location;
            int _hp;
            std::string name;

        public:
            Character(std::string, Point&, int _hp);
            Character();
            Character(const Character&) = default;
            Character& operator=(const Character&) = default;
            Character(Character&&) = default;
            Character& operator=(Character&&) = default;
            virtual ~Character() = default;
            bool isAlive();
            double distance(Character*);
            void hit(int);
            virtual std::string print();
            std::string getName();
            Point* getLocation();
            void setLocation(Point* location);
    };
}

#endif