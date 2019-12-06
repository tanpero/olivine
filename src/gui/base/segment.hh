#ifndef _OLIVINE_GUI_BASE_SEGMENT_HH_
#define _OLIVINE_GUI_BASE_SEGMENT_HH_

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
		Segment(double ax, double ay, double bx, double by);
		Segment(std::pair<double, double> a, std::pair<double, double> b);

	public:
		// �Ƿ�����һ�߶�ƽ��
		bool beParallelTo(Segment& dest);

		// �Ƿ�����һ�߶��ཻ
		bool intersectAt(Segment& dest);

		// �Ƿ�����һ�߶δ�ֱ
		bool bePerpendicularTo(Segment& dest);

		// ���߶���һ����תָ��������0 �� n �� 360��
		Segment rotate(Point center, double angle);

	public:
		// ���ȹ�ϵ�Ƚ�
		bool operator<(Segment& rhs);
		bool operator>(Segment& rhs);
		bool operator<=(Segment& rhs);
		bool operator>=(Segment& rhs);
		bool operator==(Segment& rhs);
		bool operator!=(Segment& rhs);

	public:
		inline std::string toString()
		{
			return "[" + _a.toString() + " -> " + _b.toString() + "]";
		}
		inline Point& getA()
		{
			return _a;
		}
		inline Point& getB()
		{
			return _b;
		}

	private:
		Point _a;
		Point _b;
	};
}

END_GUI_NAMESPACE

#endif // !_OLIVINE_GUI_BASE_SEGMENT_HH_