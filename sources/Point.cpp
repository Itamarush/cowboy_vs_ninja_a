#include "Point.hpp"

using namespace ariel;
using namespace std;

Point::Point(double pt_x, double pt_y) : x_cor(pt_x), y_cor(pt_y) {}

Point::Point(){}

double Point::getX() const
{
    return x_cor;
}

double Point::getY() const
{
    return y_cor;
}

double Point::distance(Point other) const
{
    return 0.0;
}

std::string Point::print() const
{
    return "hello";
}

const Point &Point::moveTowards(const Point &curr, const Point &other,  double dist)
{
    return curr;
}