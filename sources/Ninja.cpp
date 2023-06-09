#include "Ninja.hpp"

	Ninja::Ninja(std::string name, Point location, int _hp, int speed, int isPlaying, int isCowboy) :
    Character::Character(name, location, _hp, 0, 0), speed(speed){}
void Ninja::move(Character *enemy){
    if(!this->isAlive())
    {
        throw runtime_error("a dead Character can't move"); // throw an exception
    }
    Point new_loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), speed);
    this->setLocation(new_loc);
}
	// void Ninja::move(Character *enemy)
    // {
    //     Point newLocation = Point::moveTowards(getLocation(), (enemy->getLocation()), speed);
    //     this->setLocation(newLocation);
    // }

void Ninja::slash(Character *enemy)
{
    if (!this->isAlive())
    {
        throw std::runtime_error("The attacking chararcter is dead");
    }
    if (enemy == nullptr)
    {
        throw std::runtime_error("The enemy is already dead");
    }
    if (!enemy->isAlive())
    {
        throw std::runtime_error("The target is dead");
    }
    if (this == enemy)
    {
        throw std::runtime_error("The attacking and attacked player is the same character");
    }
    if (this->isAlive() && getLocation().distance(enemy->getLocation()) < 1)
    {
        enemy->hit(40);
    }
}
	
    std::string Ninja::print()
    {
        return "hello";
    }

	int Ninja::getSpeed()
    {
        return this->speed;
    }    

    // int Ninja::getHp()
    // {
    //     retur
    // }
