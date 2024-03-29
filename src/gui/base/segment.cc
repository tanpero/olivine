#include <gui/base/segment.hh>

using olivine::gui::base::Point;
using olivine::gui::base::Segment;

BEGIN_GUI_NAMESPACE

namespace base
{
    Segment::Segment()
    {
        _a = Point();
        _b = Point();
    }
    Segment::~Segment()
    {
    }
    Segment::Segment(Point & a, Point & b)
    {
        _a = a;
        _b = b;
    }
    Segment::Segment(double ax, double ay, double bx, double by)
    {
        _a = { ax, ay };
        _b = { bx, by };
    }
    Segment::Segment(std::pair<double, double> a, std::pair<double, double> b)
    {
        _a = a;
        _b = b;
    }

    bool isLineSegmentCross(Point& p1, Point& p2, Point& q1, Point& q2)
    {
        if (
            ((q1.getX() - p1.getX()) * (q1.getY() - q2.getY()) - (q1.getY() - p1.getY()) * (q1.getX() - q2.getX()))
            * ((q1.getX() - q2.getX()) * (q1.getY() - q2.getY()) - (q1.getY() - q2.getY()) * (q1.getX() - q2.getX())) < 0 ||
            ((p1.getX() - q1.getX()) * (p1.getY() - q2.getY()) - (p1.getY() - q1.getY()) * (p1.getX() - q2.getX()))
            * ((p1.getX() - q2.getX()) * (p1.getY() - q2.getY()) - (p1.getY() - q2.getY()) * (p1.getX() - p2.getX())) < 0
        )
            return true;
        else
            return false;
    }

    bool Segment::intersectAt(Segment & dest)
    {
        return isLineSegmentCross(_a, _b, dest.getA(), dest.getB());
    }
    bool Segment::beParallelTo(Segment & dest)
    {
        Point p1 = _a;
        Point p2 = _b;
        Point q1 = dest.getA();
        Point q2 = dest.getB();

        if (p1.getX() - q1.getX() == p2.getX() - q2.getX())
        {
            return true;
        }
        else if (p1.getY() - q1.getY() == p2.getY() - q2.getY())
        {
            return true;
        }
        return false;
    }
    Segment Segment::rotate(Point center, double angle)
    {
        Point p1 = _a;
        Point p2 = _b;
        const double pi = 3.14159265358979323;

        p1.setX((p1.getX() - center.getX()) * std::cos(pi / 180. * angle)
            - (p1.getY() - center.getY()) * std::sin(pi / 180. * angle) + center.getX());
        p1.setY((p1.getX() - center.getX()) * std::sin(pi / 180. * angle)
            + (p1.getY() - center.getY()) * std::cos(pi / 180. * angle) + center.getY());

        p2.setX((p2.getX() - center.getX()) * std::cos(pi / 180. * angle)
            - (p2.getY() - center.getY()) * std::sin(pi / 180. * angle) + center.getX());
        p2.setY((p2.getX() - center.getX()) * std::sin(pi / 180. * angle)
            + (p2.getY() - center.getY()) * std::cos(pi / 180. * angle) + center.getY());

        _a = p1;
        _b = p2;
        return *this;
    }
}


END_GUI_NAMESPACE
