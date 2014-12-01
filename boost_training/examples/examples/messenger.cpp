#include <iostream>
#include <cmath>
class Point2D { // To jest posłaniec
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
class VectorA2D { // Wektor z azymutem
public:
	int azimuth, module;
	VectorA2D(int a, int m):
		azimuth(a), module(m) {}
};

class Space2D { // Przestrzeń 2 wymiarowa
public:
	static Point2D translate(Point2D p, VectorA2D v) {
		// FIXME: Te obliczenia nie są oczywiście
		// prawidłowe. Powinny być sin/cos itp...
		p.x += v.azimuth * v.module;
		p.y += v.azimuth * v.module;
		return p;
	}
};

int main(int argc, char* argv[])
{
	Point2D p1(2, 4);
	Point2D p2 = Space2D::translate(p1, VectorA2D(10,20));
	std::cout << "p1: " << p1 << "\np2: " << p2 << "\n";
	 
	return 0;
}
