#include <gui/base/rect.hh>

BEGIN_GUI_NAMESPACE

namespace base
{
	Rect::Rect()
	{
	}
	Rect::~Rect()
	{
	}
	Rect::Rect(Point & lt, double width, double height)
	{
		_width = width;
		_height = height;
		_lt = lt;
		_rt = { lt.getX() + width, lt.getY() };
		_lb = { lt.getX(), lt.getY() + height };
		_rb = { lt.getX() + width, lt.getY() + height };
	}
	Rect::Rect(Point & lt, double length)
	{
		*this = Rect(lt, length, length);
	}
	Point Rect::getLeftTop()
	{
		return _lt;
	}
	Point Rect::getRightTop()
	{
		return _rt;
	}
	Point Rect::getLeftBottom()
	{
		return _lb;
	}
	Point Rect::getRightBottom()
	{
		return _rb;
	}
	std::tuple<Point, Point, Point, Point> Rect::getVertices()
	{
		return { _lt, _rt, _lb, _rb };
	}
	std::tuple<Segment, Segment, Segment, Segment> Rect::getEdges()
	{
		return { getTop(), getBottom(), getLeft(), getRight() };
	}
	Segment Rect::getTop()
	{
		return { _lt, _rt };
	}
	Segment Rect::getBottom()
	{
		return { _lb, _rb };
	}
	Segment Rect::getLeft()
	{
		return { _lt, _lb };
	}
	Segment Rect::getRight()
	{
		return { _rt, _rb };
	}
	double Rect::getWidth()
	{
		return _width;
	}
	double Rect::getHeight()
	{
		return _height;
	}
	bool Rect::includes(Point & dest)
	{
		return dest.getX() >= _lt.getX() && dest.getX() <= _rt.getX()
			&& dest.getY() <= _lt.getY() && dest.getY() >= _rb.getY();
	}
}

END_GUI_NAMESPACE
