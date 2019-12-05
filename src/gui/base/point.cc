#include <gui/base/point.hh>

BEGIN_GUI_NAMESPACE

base::Point::Point()
{
}

base::Point::~Point()
{
}

base::Point::Point(double x, double y)
{
}

void base::Point::goByX(double path)
{
	_x += path;
}

void base::Point::goByY(double path)
{
	_y += path;
}

void base::Point::fromPolar(double r, double sitha)
{
	_x = r * std::cos(sitha);
	_y = r * std::sin(sitha);
}

double base::distance(Point& a, Point& b)
{
	if (a._x == b._x)
	{
		return std::abs(a._y - b._y);
	}
	else if (a._y == b._y)
	{
		return std::abs(a._x - b._x);
	}
	else
	{
		return std::sqrt(std::pow(a._x - b._x, 2) + std::pow(a._y - b._y, 2));
	}
}
