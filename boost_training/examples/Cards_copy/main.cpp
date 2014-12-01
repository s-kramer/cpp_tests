#include <iostream>
#include "Deck.hpp"

using namespace std;

int main(void)
{
	Deck myDeck;
	myDeck.shuffle();
	cout << myDeck;
	cout << "------------------------\n";
	cardT myCard = myDeck.getCard();
	cout << myCard.first << "|" << myCard.second << std::endl;
	cout << "------------------------\n";
	cout << myDeck;
}
