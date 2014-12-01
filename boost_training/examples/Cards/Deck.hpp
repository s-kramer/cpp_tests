#ifndef DECK_HPP_
#define DECK_HPP_

#include <vector>
#include <string>
#include <utility>
#include <ostream>

typedef std::pair<std::string, std::string> cardT;

class Deck
{
	std::vector<cardT*> * cards;
	static cardT *  generateCard();
public:
	Deck();
	~Deck();
	void shuffle();
	cardT * getCard();
    friend std::ostream& operator<< (std::ostream &out, const Deck&);
};

#endif /* DECK_HPP_ */
