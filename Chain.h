#include <istream>

template <class T> class Chain : Chain_Base {
    private:
        std::vector<T*>;
    public:
        Chain(std::istream&, const CardFactory*);
        ~Chain();
        Chain<T>& oeperator+=(Card*);
        int sell();
        friend std::ostream& operator<<(std::ostream&, const Chain&);
};
