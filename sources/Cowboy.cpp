#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

using namespace ariel;

Cowboy::Cowboy(std::string name, Point location)
    : Character(name, location, 110)
{
    bulletsCounter = 6;
}

Cowboy::Cowboy(){}

void Cowboy::shoot(Character *target){}

bool Cowboy::hasBullets()
{
    return true;
}

void Cowboy::reload(){}

int Cowboy::getBulletCounter()
{
    return 1;
}
