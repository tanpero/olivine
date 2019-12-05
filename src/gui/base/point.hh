#ifndef _OLIVINE_GUI_BASE_POINT_HH_
#define _OLIVINE_GUI_BASE_POINT_HH_

#include <gui/base/def.hh>

#include <cmath>

BEGIN_GUI_NAMESPACE

namespace base
{
	class Point
	{
	public:
		Point();
		~Point();

	public:
		Point(double x, double y);

	public:
		bool operator==(Point& rhs);
		bool operator!=(Point& rhs);
		void goByX(double path);
		void goByY(double path);
		void fromPolar(double r, double sitha);

	public:
		friend double distance(Point& a, Point& b);

	private:
		double _x;
		double _y;
	};
}

END_GUI_NAMESPACE


#endif // !_OLIVINE_GUI_BASE_POINT_HH_
