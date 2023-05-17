#pragma once

#include "Ninja.hpp"
	
namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(std::string name, Point location);
        TrainedNinja();
        TrainedNinja(const TrainedNinja&) = default;
        TrainedNinja& operator=(const TrainedNinja&) = default;
        TrainedNinja(TrainedNinja&&) = default;
        TrainedNinja& operator=(TrainedNinja&&) = default;
        ~TrainedNinja() override = default;
    };
}