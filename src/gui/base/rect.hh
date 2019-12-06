#ifndef _OLIVINE_GUI_BASE_RECT_HH_
#define _OLIVINE_GUI_BASE_RECT_HH_

#include <gui/base/segment.hh>

BEGIN_GUI_NAMESPACE

namespace base
{
	class Rect
	{
	public:
		Rect();
		~Rect();

	public:
		Rect(Point& lt, double width, double height);
		Rect(Point& lt, double length);

	public:
		Point getLeftTop();
		Point getRightTop();
		Point getLeftBottom();
		Point getRightBottom();

	public:
		Segment getTop();
		Segment getBottom();
		Segment getLeft();
		Segment getRight();
		double getWidth();
		double getHeight();
		inline std::string toString()
		{
			return "Left Top: " + lt.toString() + " Right Top: " + rt.toString()
				+ "\nLeft Bottom: " + lb.toString() + " Right Bottom: " + rb.toString();
		}

	private:
		Point _lt;
		Point _rt;
		Point _lb;
		Point _rb;
	};
}

END_GUI_NAMESPACE

#endif // !_OLIVINE_GUI_BASE_RECT_HH_
