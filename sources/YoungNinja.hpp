#include "Ninja.hpp"
using namespace ariel;

class YoungNinja : public Ninja{
public:
	YoungNinja(std::string name, ariel::Point location);
	YoungNinja();
	YoungNinja(const YoungNinja&) = default;
	YoungNinja& operator=(const YoungNinja&) = default;
	YoungNinja(YoungNinja&&) = default;
	YoungNinja& operator=(YoungNinja&&) = default;
	~YoungNinja() override = default;
};