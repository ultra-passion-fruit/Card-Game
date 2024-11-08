#include <vector>
#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

class DiscarPile : std::vector<Card*> {
    public:
        DiscarPile(std::istream&, const CardFactory*);
        ~DiscardPile();
        DicardPile& operator+=(Card*);
        Card* pickUp();
        Card* top();
        void print(std::ostream&);
        friend std::ostream& operator<<(std::ostream&, const Card&);
};
