#include <ostream>
#include <algorithm>
#include "Deck.hpp"

using namespace std;

Deck::Deck() : cards(new std::vector<cardT>(52))
{
	for_each(cards->begin(), cards->end(), generateCard);
	srand(time(NULL));
}

Deck::~Deck()
{
	delete(cards);
}

void  Deck::generateCard(cardT& crd)
{
	std::string colors[] = { "trefl", "karo", "kier", "pik" };
	std::string figures[] = { "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "walet", "dama", "król", "as" };
	static int colorIdx;
	static int figureIdx;

	crd = cardT(figures[figureIdx], colors[colorIdx]);

	figureIdx++;
	if(figureIdx > 12) {
		figureIdx = 0;
		colorIdx++;
	}
}

void Deck::shuffle()
{
	random_shuffle(cards->begin(), cards->end());
}

cardT Deck::getCard()
{
	cardT card = cards->back();
	cards->pop_back();
	return card;
}

ostream& operator<< (ostream &out, const Deck& src)
{
	for(unsigned i = 0; i < src.cards->size(); ++i) {
		out << "Card: ";
		out << (*src.cards)[i].first << " " << (*src.cards)[i].second << endl;
	}
	return out;
}
