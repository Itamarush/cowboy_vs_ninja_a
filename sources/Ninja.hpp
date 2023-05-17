#pragma once

#include "Character.hpp"
using namespace ariel;

namespace ariel
{
	class Ninja : public ariel::Character{
		int speed;

	public:
		Ninja(std::string name, ariel::Point location, int _hp, int speed);
		Ninja() ;
		Ninja(const Ninja&) = default;
		Ninja& operator=(const Ninja&) = default;
		Ninja(Ninja&&) = default;
		Ninja& operator=(Ninja&&) = default;
		~Ninja() override = default;
		void move(ariel::Character *enemy);
		void slash(ariel::Character *enemy);
		std::string print() override;
		int getSpeed();
		int getHp();
	};
}
