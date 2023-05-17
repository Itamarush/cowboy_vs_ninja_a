#include "Character.hpp"

using namespace std;

namespace ariel{
    
    Character::Character(string name, Point& location, int _hp):
    name(name), location(&location), _hp(_hp){}

    Character::Character(){}

    bool Character::isAlive()
    {
        return true;
    }

    double Character::distance(Character* other)
    {
        return 0.0;
    }

    void Character::hit(int damage)
    {

    }

    std::string Character::print()
    {
        return "hello";
    }

    std::string Character::getName()
    {
        return "itamar";
    }

    Point* Character::getLocation()
    {
        return location;
    }

    void Character::setLocation(Point* location)
    {

    }
}