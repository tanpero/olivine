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
		std::tuple<Point, Point, Point, Point> getVertices();
		std::tuple<Segment, Segment, Segment, Segment> getEdges();

	public:
		Segment getTop();
		Segment getBottom();
		Segment getLeft();
		Segment getRight();
		double getWidth();
		double getHeight();
		inline std::string toString()
		{
			return "Left Top: " + _lt.toString() + " - Width: "
				+ std::to_string(_width) + " - Height: " + std::to_string(_height);
		}

	public:
		double distanceOf(Rect& dest);
		bool isOverlapWith(Rect& dest);
		bool includes(Point& dest);

	private:
		double _width;
		double _height;
		Point _lt;
		Point _rt;
		Point _lb;
		Point _rb;
	};
}

END_GUI_NAMESPACE

#endif // !_OLIVINE_GUI_BASE_RECT_HH_
