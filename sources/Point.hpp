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
            Point();
            Point(double pt_x, double pt_y);
            double getX() const;
            double getY() const;
            double distance(Point other) const;
            std::string print() const;
            static const Point &moveTowards(const Point &curr, const Point &other, const double dist);
    };
}
