#include <iostream>
#include <gui/base/segment.hh>

using namespace olivine::gui::base;

int main(int argc, char* argv[])
{
	Point p1(20, 15);
	Segment s1(12, 25, 14, 36);
	Segment s2 = { {13, 20}, {17, 12} };
	std::cout << std::boolalpha << "Hello Olivine\n-----------------"
		<< "\n\nTesting of `class Point`:"
		<< "\nPoint(20, 15): " << p1.toString()
		<< "\n\nTesting of `class Segment`:"
		<< "\ns1 [(12, 25) -> (14, 36)]: " << s1.toString()
		<< "\ns2 [(13, 20) -> (17, 12)]: " << s2.toString()
		<< "\nIs s1 parallel to s2? " << s1.beParallelTo(s2)
		<< "\nDoes s1 intersect at s2? " << s1.intersectAt(s2)
		<< std::endl;
	return 0;
}
