#include <iostream>
#include <cmath>
class Point2D { // To jest pos³aniec
public:
	int x, y;
	Point2D(int _x, int _y):
		x(_x), y(_y) {}
	Point2D(const Point2D& p):
		x(p.x), y(p.y) {}
	Point2D& operator=(const Point2D& p) {
		x = p.x;
		y = p.y;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& ostr,
		const Point2D& p) {
		return ostr << "x=" << p.x << " y=" << p.y;
	}
};
