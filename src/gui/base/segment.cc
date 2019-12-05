#include <gui/base/segment.hh>

BEGIN_GUI_NAMESPACE

static int crossProduct(Segment& v1, Segment& v2)
{
	Segment vt1, vt2;
	double result = 0;

	vt1.start.getX() = 0;
	vt1._a.getY() = 0;
	vt1._b.getX() = v1._b.getX() - v1._a.getX();
	vt1._b.getY() = v1._b.getY() - v1._a.getY();

	vt2._a.getX() = 0;
	vt2._a.getY() = 0;
	vt2._b.getX() = v2._b.getX() - v2._a.getX();
	vt2._b.getY() = v2._b.getY() - v2._a.getY();

	result = vt1._b.getX() * vt2._b.getY() - vt2._b.getX() * vt1._b.getY();
	return result;
}


static double direction(Point& pi, Point& pj, Point& pk)
{
	double p1, p2;

	p1.getX() = pk.getX() - pi.getX();
	p1.getY() = pk.getY() - pi.getY();

	p2.getX() = pj.getX() - pi.getX();
	p2.getY() = pj.getY() - pi.getY();

	return crossProduct(&p1, &p2);
}

static double onSegment(Point& pi, Point& pj, Point& pk)
{
	double minx, miny, maxx, maxy;
	if (pi.getX() > pj.getX())
	{
		minx = pj.getX();
		maxx = pi.getX();
	}
	else
	{
		minx = pi.getX();
		maxx = pj.getX();
	}

	if (pi.getY() > pj.getY())
	{
		miny = pj.getY();
		maxy = pi.getY();
	}
	else
	{
		miny = pi.getY();
		maxy = pj.getY();
	}

	if (minx <= pk.getX() && pk.getX() <= maxx && miny <= pk.getY() && pk.getY() <= maxy)
		return 1;
	else
		return 0;
}

static double segmentdoubleersect(Point& p1, Point& p2, Point& p3, Point& p4)
{
	double d1 = direction(p3, p4, p1);
	double d2 = direction(p3, p4, p2);
	double d3 = direction(p1, p2, p3);
	double d4 = direction(p1, p2, p4);
	if (d1 * d2 < 0 && d3 * d4 < 0)
		return 1;
	else if (!d1 && onSegment(p3, p4, p1))
		return 1;
	else if (!d2 && onSegment(p3, p4, p2))
		return 1;
	else if (!d3 && onSegment(p1, p2, p3))
		return 1;
	else if (!d4 && onSegment(p1, p2, p4))
		return 1;
	else
		return 0;
}

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
}


END_GUI_NAMESPACE
