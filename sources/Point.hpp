#pragma once

#include <string>

namespace ariel
{
    class Point
    {
        private:
            double x_cor;
            double y_cor;

        public:
            
            Point(double pt_x, double pt_y);
            Point();
            Point(const Point&) = default;
            Point& operator=(const Point&) = default;
            Point(Point&&) = default;
            Point& operator=(Point&&) = default;
            ~Point() = default;
            double getX() const;
            double getY() const;
            double distance(Point other) const;
            std::string print() const;
            static const Point &moveTowards(const Point &curr, const Point &other, double dist);
    };
}
