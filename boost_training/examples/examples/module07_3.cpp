#include <iostream>
#include <utility>
#include <queue>
// Definicja prostej pracy...
class Work {
public:
	Work(unsigned int prio) : _prio(prio) {}
	void operator() (){
		std::cout << "Wykonanie pracy z priorytetem " 
			<< _prio << ".\n";
	}
private:
	unsigned int _prio;
};
// Definicja typu pary: Work* i prio
typedef std::pair<Work*, unsigned int> myWorkT;
// Klasyfikator priorytetow
struct myPrioPolicy {
	bool operator() (const myWorkT& lhs, const myWorkT& rhs) const {
		return (lhs.second > rhs.second );
	}
};
// ...
