#pragma once

#include "Character.hpp"
using namespace ariel;

namespace ariel
{
	class Ninja : public ariel::Character{
		int speed;

	protected:
		Ninja(std::string name, ariel::Point location, int hp, int speed);
		~Ninja();

	public:
		void move(ariel::Character *enemy);
		void slash(ariel::Character *enemy);
		std::string print();
		int getSpeed();
		int getHp();
	};
}
