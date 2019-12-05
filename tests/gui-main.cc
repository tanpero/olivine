#include <iostream>
#include <gui/base/segment.hh>

using namespace olivine::gui::base;

int main(int argc, char* argv[])
{
	Point p1(20, 15);
	Segment s1(12, 25, 14, 36);
	std::cout << "Hello Olivine\n-----------------\n\n"
		<< "Testing of `class Point`:\n"
		<< "Point(20, 15): " << p1.toString()
		<< "\nTesting of `class Segment`:\n"
		<< "Segment(12, 25, 14, 36): " << s1.toString()
		
		<< std::endl;
	return 0;
}
