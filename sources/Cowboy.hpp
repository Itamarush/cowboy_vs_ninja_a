#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsCounter;

    public:
        Cowboy(std::string name, Point location);
        ~Cowboy();
        void shoot(Character *ninjaToShoot);
        bool hasBullets();
        void reload();
        int getBulletCounter();
    };
}