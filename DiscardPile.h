#include <vector>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"
using namespace std;
class DiscardPile : vector<Card*> {
    public:
        DiscardPile(std::istream&, const CardFactory*);
        ~DiscardPile();
        DiscardPile& operator+=(Card*);
        Card* pickUp();
        Card* top() const;
        void print(std::ostream&) const;
        friend std::ostream& operator<<(std::ostream&, const Card&);
};
