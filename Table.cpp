#include "Table.h"

/*
* is a constructor which accepts an istream and reconstruct the Table from file.
*/
Table::Table(std::istream& is, const CardFactory* factory) {

}

Table::Table(const Player1* p1, const Player2* p2, const CardFactory* factory) {
    Player1 = p1;
    Player2 = p2;
}