#ifndef CASHIER_H
#define CASHIER_H

#include "Product_Info.h"
#include <string>

using namespace std;


class Cashier : public Product_Info
{
    public:
        Cashier( int = 0 );

        void setTotal( int );
        void setPname( string );
        int getTotal();
        string getPname() const;
        virtual ~Cashier();
        Cashier(const Cashier& other);
        Cashier& operator=(const Cashier& other);
        bool operator==(const Cashier& other);

    protected:

    private:
        int _total;
        char _pName[ 9 ];
};

#endif // CASHIER_H
