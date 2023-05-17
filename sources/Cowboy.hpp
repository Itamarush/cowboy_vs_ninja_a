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
        ~Cowboy() override = default;
        void shoot(Character *ninjaToShoot);
        bool hasBullets();
        void reload();
        int getBulletCounter();
    };
}