#pragma once

#include "Character.hpp"
using namespace ariel;
using namespace std;

namespace ariel
{
	class Ninja : public ariel::Character{
		int speed;

	public:
		Ninja(string name, Point location, int _hp, int speed, int isPlaying, int isCowboy);
		Ninja() ;
		Ninja(const Ninja&) = default;
		Ninja& operator=(const Ninja&) = default;
		Ninja(Ninja&&) = default;
		Ninja& operator=(Ninja&&) = default;
		void move(ariel::Character *enemy);
		void slash(ariel::Character *enemy);
		std::string print() override;
		int getSpeed();
		
	};
}
