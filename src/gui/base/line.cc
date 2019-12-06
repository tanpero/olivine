#include <gui/base/line.hh>

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
}


END_GUI_NAMESPACE
