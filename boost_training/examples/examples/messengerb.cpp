class VectorA2D { // Wektor z azymutem
public:
	int azimuth, module;
	VectorA2D(int a, int m):
		azimuth(a), module(m) {}
};
class Space2D { // Przestrzen 2 wymiarowa
public:
	static Point2D translate(Point2D p, VectorA2D v) {
		// FIXME: Te obliczenia nie sa oczywiscie
		// prawidlowe. Powinny byc sin/cos itp...
		p.x += v.azimuth * v.module;
		p.y += v.azimuth * v.module;
		return p;
	}
};
int main(int argc, char* argv[]) {
	Point2D p1(2, 4);
	Point2D p2 = Space2D::translate(p1, VectorA2D(10,20));
	std::cout << "p1: " << p1 << "\np2: " << p2 << "\n";
	return 0;
}
