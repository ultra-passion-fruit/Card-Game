#include <istream>
#include "Chain_Base.h"
#include "CardFactory.h"

// Chain is also a container and will have to grow and shrink as the game progresses. Again
// insertion is only to one end of the chain and a std::vector is fine (see below).

// A template class will have to created for Chain being parametric in the type of card. In this
// project, we will instantiate Chain for the corresponding bean card.

template <class T> class Chain : public Chain_Base {
private:
    std::vector<T*> chain;
public:
    Chain(std::istream&, const CardFactory*);
    // ~Chain();
    virtual int sell() override;
    Chain<T>& operator+=(Card*);
    friend std::ostream& operator<<(std::ostream&, const Chain&);
};


template <class T>
Chain<T> &Chain<T>::operator+=(Card * c) {
    T* type = dynamic_cast<T*>(c);
    if(!type){
        throw IllegalType();
    } else {
        chain.push_back(type);
        return *this;
    }

}

template <class T>
int Chain<T>::sell() {
    int coins = 0;
    if(chain.empty()){
        return coins;
    }

    int numChain = chain.size();
    for(int i = 1; i <= 4; i++){
        if(chain.front()->getName() == "garden" && i == 1){
            continue;
        } else if(chain.front()-> getName() == "garden" && i > 3){
            break;
        } else {
            int numReference = chain.front() -> getCardsPerCoin(coins);
            if (numChain >= numReference){
                coins = i;
            } else {
                break;
            }
        }
    }
    return coins;
}