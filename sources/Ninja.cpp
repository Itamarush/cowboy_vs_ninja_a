#include "Ninja.hpp"

	Ninja::Ninja(std::string name, Point location, int hp, int speed) :
    Character::Character(name, location, hp), speed(speed){} 
    
	Ninja::~Ninja(){}

	void Ninja::move(Character *enemy){}

	void Ninja::slash(Character *enemy){}
	
    std::string Ninja::print()
    {
        return "hello";
    }

	int Ninja::getSpeed()
    {
        return 0;
    }    

    int Ninja::getHp()
    {
        return 0;
    }