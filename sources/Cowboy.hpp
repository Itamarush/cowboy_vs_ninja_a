#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsCounter;

    public:
        Cowboy(std::string name, Point location);
        Cowboy();
        Cowboy(const Cowboy&) = default;
        Cowboy& operator=(const Cowboy&) = default;
        Cowboy(Cowboy&&) = default;
        Cowboy& operator=(Cowboy&&) = default;
        void shoot(Character *ninjaToShoot);
        bool hasboolets();
        void reload();
        int getBulletCounter();
    };
}