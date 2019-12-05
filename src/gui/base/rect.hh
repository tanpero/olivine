#ifndef _OLIVINE_GUI_BASE_RECT_HH_
#define _OLIVINE_GUI_BASE_RECT_HH_

#include <gui/base/point.hh>

BEGIN_GUI_NAMESPACE

namespace base
{
	class Line
	{
	public:
		Line();
		~Line();

	public:
		Line(Point& a, Point& b);

	private:
		Point _a;
		Point _b;
	};
}

END_GUI_NAMESPACE

#endif // !_OLIVINE_GUI_BASE_RECT_HH_
