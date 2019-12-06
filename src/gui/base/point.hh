#ifndef _OLIVINE_GUI_BASE_POINT_HH_
#define _OLIVINE_GUI_BASE_POINT_HH_

#include <gui/base/def.hh>

#include <cmath>
#include <tuple>
#include <string>

BEGIN_GUI_NAMESPACE

namespace base
{
    class Point
    {
    public:
        Point();
        ~Point();

    public:
        Point(double x, double y);
        Point(std::pair<double, double> pair);

    public:
        bool operator==(Point& rhs);
        bool operator!=(Point& rhs);
        void goByX(double path);
        void goByY(double path);
        void fromPolar(double r, double sitha);
        std::pair<double, double> toPair();

    public:
        inline std::string toString()
        {
            return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
        }
        inline double getX()
        {
            return _x;
        }
        inline double getY()
        {
            return _y;
        }
        inline void setX(double x)
        {
            _x = x;
        }
        inline void setY(double y)
        {
            _y = y;
        }

    public:
        friend double distance(Point& a, Point& b);

    private:
        double _x;
        double _y;
    };
}

END_GUI_NAMESPACE


#endif // !_OLIVINE_GUI_BASE_POINT_HH_
