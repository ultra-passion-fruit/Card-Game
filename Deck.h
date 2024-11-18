#include <vector>
#include <istream>
#include <algorithm>
#include <random>

#include "Card.h"
#include "CardFactory.h"

using namespace std;
class Deck : public vector<Card*> {
    void shuffle_cards();
    public:
        Deck(istream&, const CardFactory*);
        ~Deck();
        Card* draw();
        friend ostream& operator<<(ostream&, const Deck&);
};
