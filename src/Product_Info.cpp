#include "Product_Info.h"
#include <iostream>
using namespace std;

Product_Info::Product_Info( int cost, int quan )
{
    //ctor

    setCost( cost );
    setQuantity( quan );
}


void Product_Info::setCost( int  cost )
{
    _cost = cost;
}
void Product_Info::setQuantity( int quan )
{
    _quantity = quan;
}

void Product_Info::setProductInfo()
{
    int cost;
    int quan;

    cout << "\nCost (cost/kg) :";
    cin >> cost;
    setCost( cost );

    cout << "\n Quantity (kg) : ";
    cin >> quan;
    setQuantity( quan );
}

void Product_Info::setProductCostForCustomer()
{
    int quan;

    cout << "\n You are paying : ";
    cin >> quan;
    setQuantity( quan );

}
void Product_Info::setProductQuantityForCustomer()
{
    int cost;

    cout << "\n Quantity (kg) : ";
    cin >> cost;
    setQuantity( cost );

}
int Product_Info::getCost()
{
    return _cost;
}
int Product_Info::getQuantity()
{
    return _quantity;
}

void Product_Info::displayPdoductInfo()
{
    cout << "\nCost : " << getCost() << "\nQuantity : " << getQuantity() << "\n";
}

Product_Info::~Product_Info()
{
    //dtor
}

Product_Info::Product_Info(const Product_Info& other)
{
    //copy ctor
}

//Product_Info& Product_Info::operator=(const Product_Info& rhs)
Product_Info& Product_Info::operator=(const Product_Info& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    return *this;
}
