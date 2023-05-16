#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"
#include <stdexcept>

namespace ariel{
    class Character{
        protected:
            Point* location;
            int _hp;
            std::string name;

        public:
            Character(std::string, Point&, int hp);
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