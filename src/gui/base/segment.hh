#ifndef _OLIVINE_GUI_BASE_LINE_HH_
#define _OLIVINE_GUI_BASE_LINE_HH_

#include <gui/base/point.hh>

BEGIN_GUI_NAMESPACE

namespace base
{
	class Segment
	{
	public:
		Segment();
		~Segment();

	public:
		Segment(Point& a, Point& b);

	public:
		// 是否与另一线段平行
		bool beParallelTo(Segment& dest);

		// 是否与另一线段相交
		bool intersectAt(Segment& dest);

		// 是否与另一线段垂直
		bool bePerpendicularTo(Segment& dest);

	public:
		// 长度关系比较
		bool operator<(Segment& rhs);
		bool operator>(Segment& rhs);
		bool operator<=(Segment& rhs);
		bool operator>=(Segment& rhs);
		bool operator==(Segment& rhs);
		bool operator!=(Segment& rhs);

	private:
		Point _a;
		Point _b;
	};
}

END_GUI_NAMESPACE

#endif // !_OLIVINE_GUI_BASE_LINE_HH_
