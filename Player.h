#include <istream>
#include <ostream>
#include "Card.h"
#include "CardFactory.h"

class Player {
    private:
        Hand;
    public:
        Player(std::string&);
        Player(std::istream&, const CardFactory*);
        ~Player();
        std::string getName();
        int getNumCoins();
        Player& operator+=(int);
        int getMaxNumChains();
        int getNumChains();
        Chain& operator[](int);
        void buyThirdChain();
        std::ostream& printHand(std::ostream&, bool);
        friend std::ostream& operator<<(std::ostream&, const Player&);
};
