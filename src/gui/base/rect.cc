#include <gui/base/rect.hh>

BEGIN_GUI_NAMESPACE

namespace base
{
	Line::Line()
	{
		_a = Point();
		_b = Point();
	}
	Line::~Line()
	{
	}
	Line::Line(Point & a, Point & b)
	{
		_a = a;
		_b = b;
	}
}

END_GUI_NAMESPACE
