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
		// �Ƿ�����һ�߶�ƽ��
		bool beParallelTo(Segment& dest);

		// �Ƿ�����һ�߶��ཻ
		bool intersectAt(Segment& dest);

		// �Ƿ�����һ�߶δ�ֱ
		bool bePerpendicularTo(Segment& dest);

	public:
		// ���ȹ�ϵ�Ƚ�
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