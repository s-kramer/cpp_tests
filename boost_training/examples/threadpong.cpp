#include <iostream>
#include <cstdlib>
// Naiwna implementacja pude³ka z pi³k±.
class Table {
private:
	size_t width;
	size_t height;
	size_t xPosition;
	size_t yPosition;
	int dx;
	int dy;
public:
	Table(size_t w, size_t h)
	: width(w), height(h), xPosition(0), yPosition(0), dx(1), dy(1) {}
	void showTable();
	void animateBall();
};

void Table::showTable() {
	system("clear");		// 1 czyszczenie planszy.
	const int loops = 200;		// Ilo¶æ kroków symulacji
	for(int z = 0; z < loops; ++z) {
		for(unsigned j = 0; j <= height; ++j) {
			for(unsigned i = 0; i <= width; ++i) {
				if((j == yPosition) && (i == xPosition)) {
					std::cout << '*';
				} else { 
					std::cout << '.';
				}
			}
			std::cout << '\n';
		}
		animateBall();
		system("sleep 0.1; clear");
	}
}
void Table::animateBall() {
	xPosition += dx;
	yPosition += dy;
	if((xPosition <= 0) || (xPosition >= width)) {
		std::cout << '\a';
		dx = -dx;
	}
	if((yPosition <= 0) || (yPosition >= height)) {
		std::cout << '\a';
		dy = -dy;
	}
	std::cout << "x = " << xPosition << '\t';
	std::cout << "y = " << yPosition << '\t';
	std::cout << "dx = " << dx << '\t';
	std::cout << "dy = " << dy << '\n';
}
int main(int argc, char* argv[])
{
	Table * myTable = new Table(78,22);
	myTable->showTable();
	return 0;
}
