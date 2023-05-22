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
    double distance = std::sqrt(std::pow(other.getX() - this->getX(), 2) + std::pow(other.getY() - this->getY(), 2));
    return distance;
}

std::string Point::print() const
{
    std::string formattedString = "(" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")";
    return formattedString;
}

const Point &Point::moveTowards(const Point &curr, const Point &other, double dist)
{
    if (distance == 0)
        return other;
    if (other.distance(curr) <= dist)
        return other;
    if (dist < 0)
        throw invalid_argument("distance cant be negative");
    double dx = other.x_cor - curr.x_cor;
    double dy = other.y_cor - curr.y_cor;
    double scale = dist / other.distance(other);

    return Point(other.x_cor + scale * dx, other.y_cor + scale * dy);
}