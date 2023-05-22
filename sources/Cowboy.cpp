#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

using namespace ariel;

Cowboy::Cowboy(std::string name, Point location)
    : Character(name, location, 110)
{
    this->bulletsCounter = 6;
}

Cowboy::Cowboy(){}

void Cowboy::shoot(Character *target)
{
    if(this->isAlive() && bulletsCounter)
    {
        target->hit(10);
        this->bulletsCounter--;
    }
}

bool Cowboy::hasBullets()
{
    return this->bulletsCounter;
}

void Cowboy::reload()
{
    this->bulletsCounter = 6;
}

int Cowboy::getBulletCounter()
{
    return this->bulletsCounter;
}
