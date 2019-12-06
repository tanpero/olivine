#include <iostream>
#include <gui/base/rect.hh>

using namespace olivine::gui::base;

int main(int argc, char* argv[])
{
    Point p1(20, 15);
	Point p2(18, 30);
    Segment s1(12, 25, 14, 36);
    Segment s2 = { {13, 20}, {17, 12} };
	Rect r1(p1, 30, 40);
    std::cout << std::boolalpha << "Hello Olivine\n-----------------"
        << "\n\nTesting of `class Point`:"
        << "\np1 (20, 15): " << p1.toString()
		<< "\np2 (18, 30): " << p2.toString()
		<< "\nDistance between p1 and p2: " << distance(p1, p2)
        << "\n\nTesting of `class Segment`:"
        << "\ns1 [(12, 25) -> (14, 36)]: " << s1.toString()
        << "\ns2 [(13, 20) -> (17, 12)]: " << s2.toString()
        << "\nIs s1 parallel to s2? " << s1.beParallelTo(s2)
        << "\nDoes s1 intersect at s2? " << s1.intersectAt(s2)
        << "\nRotate s1 (center: p1, angle: 30): " << s1.rotate(p1, 30).toString()
        << "\nRotate s2 (center: p1, angle: 45): " << s2.rotate(p1, 45).toString()
		<< "\n\nTesting of `class Rect`:"
		<< "\nr1 [(20, 15), Width: 30, Height: 40]: " << r1.toString()
		<< "\nDoes it include p1? " << r1.includes(p1)
		<< "\nDoes it include p2? " << r1.includes(p2)
        << std::endl;
    return 0;
}
