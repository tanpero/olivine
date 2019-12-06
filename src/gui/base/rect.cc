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
		return Point();
	}
	Point Rect::getRightTop()
	{
		return Point();
	}
	Point Rect::getLeftBottom()
	{
		return Point();
	}
	Point Rect::getRightBottom()
	{
		return Point();
	}
	Segment Rect::getTop()
	{
		return Segment();
	}
	Segment Rect::getBottom()
	{
		return Segment();
	}
	Segment Rect::getLeft()
	{
		return Segment();
	}
	Segment Rect::getRight()
	{
		return Segment();
	}
	double Rect::getWidth()
	{
		return 0.0;
	}
	double Rect::getHeight()
	{
		return 0.0;
	}
}

END_GUI_NAMESPACE
