#include "Character.hpp"

using namespace std;

namespace ariel{
    
    Character::Character(string name, Point& location, int _hp):
    name(name), location(&location), _hp(_hp){}

    Character::Character(){}

    bool Character::isAlive()
    {
        if(this->_hp > 0)
            return true;
        return false;
    }

    double Character::distance(Character* other)
    {
        return distance(other);
    }

    void Character::hit(int damage)
    {
        this->_hp -= damage;
    }

    std::string Character::print()
    {
        std::ostringstream oss;
        if (!isAlive())
        {
            oss << "(" << name << ")" << std::endl;
        }
        else
        {
            oss << name << " " << _hp << " " << location << std::endl;
        }
        return oss.str();
    }

    std::string Character::getName()
    {
        return this->name;
    }

    Point* Character::getLocation()
    {
        return this->location;
    }

    void Character::setLocation(Point* location)
    {
        this->location = location;
    }
}