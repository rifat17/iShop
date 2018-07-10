#include "Cashier.h"
#include <string>

using namespace std;

Cashier::Cashier(int total)
{
    //ctor
    setTotal( total );
}

void Cashier::setTotal( int total )
{
    _total = total;
}
int Cashier::getTotal()
{
    return _total;
}
void Cashier::setPname( string name )
{
    int length = name.length();
    length = ( length < 9 ? length : 8 );
    name.copy(_pName,length );
    _pName[ length ] = '\0';
}

string Cashier::getPname() const
{
    return _pName;
}

Cashier::~Cashier()
{
    //dtor
}

Cashier::Cashier(const Cashier& other)
{
    //copy ctor
}
bool Cashier::operator==(const Cashier& other)
{
    bool Result = false;
    if( this->getPname() == other.getPname() ){
        Result = true;
        return Result;
    }
    return Result;
}

Cashier& Cashier::operator=(const Cashier& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
