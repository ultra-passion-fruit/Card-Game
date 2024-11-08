#include "Deck.h"

class CardFactory {
    private:
        CardFactory();
        static CardFactory;
    public:
        ~CardFactory();
        static CardFactory* getFactory();
        Deck getDeck();
};
