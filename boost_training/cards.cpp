#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <boost/bind.hpp>

class Cards;
typedef std::pair<int, int> Card;
void displayCard(Card card);

struct cardsGen {
    static int index;
    static int color;

    typedef std::pair<int, int> Card;

    cardsGen(void) 
    {
    }
    std::pair<int, int> operator()(void)
    {
        index++;

        if (index == 14) {
            color++;
            index = 1;
        }

        return std::make_pair(color, index);
    }
};

int cardsGen::index = 0;
int cardsGen::color = 1;

class Cards
{
public:
    explicit Cards () : cardSet(52)
    {
        std::generate_n(cardSet.begin(), 52, cardsGen());
        std::random_shuffle(cardSet.begin(), cardSet.end());
    };

    Card getCard(int color, int index)
    {
        std::vector<Card>::iterator it = std::find(cardSet.begin(), cardSet.end(), std::make_pair(color, index));
        if (it == cardSet.end()) {
            std::cout << "Card not available" << '\n';
            return Card(0, 0);
        }

        cardSet.erase(it);
        return *it;
    }

    void printCards(void)
    {
        std::for_each(cardSet.begin(), cardSet.end(), boost::bind(&displayCard, _1));
    }

    void sort(void)
    {
        std::sort(cardSet.begin(), cardSet.end());
    }

    
private:
    std::vector<std::pair<int, int> > cardSet;
};

void displayCard(Card card)
{
    std::cout << card.first << " " << card.second << "\t";
}

int main()
{
    Cards cards;
    cards.printCards();
    std::cout << std::endl;
    cards.sort();
    cards.printCards();
    std::cout << std::endl;

    displayCard(cards.getCard(1, 4));
    std::cout << std::endl;
    displayCard(cards.getCard(1, 4));
    std::cout << std::endl;
    cards.printCards();
    std::cout << std::endl;
    return 0;
}
