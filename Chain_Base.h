#pragma once
#ifndef CHAIN_BASE_H
#define CHAIN_BASE_H
#include <istream>
#include "CardFactory.h"

/*
* Chain_Base is an interface to the Chain class.
*/
class Chain_Base {
    public:
        Chain_Base() = default;
        ~Chain_Base() = default;

        virtual int sell() = 0;
        virtual Chain_Base& operator+=(Card*) = 0;
        // Print the chain according to specified format.
        virtual void print(std::ostream&) = 0;
};
#endif
