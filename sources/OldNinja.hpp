#include "Ninja.hpp"
using namespace ariel;

class OldNinja : public Ninja{
public:
	OldNinja(std::string name, ariel::Point location);
	OldNinja();
	OldNinja(const OldNinja&) = default;
	OldNinja& operator=(const OldNinja&) = default;
	OldNinja(OldNinja&&) = default;
	OldNinja& operator=(OldNinja&&) = default;
	~OldNinja() override = default;
};