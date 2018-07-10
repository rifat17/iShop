#ifndef FUNCTIONHEADER_01_H_INCLUDED
#define FUNCTIONHEADER_01_H_INCLUDED

#include "AllSellInfoFile.h"
#include "Product_Info.h"
#include "FunctionHeader_myFiles.h"

#include <iostream>
#include <iomanip>

using namespace std;


Product_Info CellProduct( Product_Info &, string );

Product_Info UpdateInfo( Product_Info & , string );

void AllTranInfo( Product_Info & , string );


Product_Info CellProduct( Product_Info &P, string Msg )
{
            Cashier C;

            int cost,quan;
            int HaveToPaym;
            cout << "\n\tYou Chose -> " << Msg << "\n";
            cout << "Celling Price : " << P.getCost() << " In Stock : " << P.getQuantity() << "kg" << "\n";
            cout << "\nHow kg do you want?\n";
            //cout << "\n Quantity (kg) : ";
            cin >> quan;

            if( P.getQuantity() >= quan ){
                    P.setQuantity( P.getQuantity() - quan );
                    HaveToPaym = P.getCost() * quan;
                    cout << "\nPay : " << HaveToPaym << " Tk \n";
                    cin >> cost;

                    if( cost < HaveToPaym ){
                        cout << "\npay " << HaveToPaym - cost << " tk more\n";
                    }
                    else if(cost > HaveToPaym){
                        cout << "\nCustomer will get back " << cost - HaveToPaym << " tk\n";
                    }
                    cout << "\n Thank you.\n";

                    C.setCost( quan * P.getCost() );
                    C.setQuantity( quan );
                    C.setPname( Msg );

                    WriteFileCashier( C , "AllSellinfo.txt" , Msg );

            }
            else{
                cout << "\n" << Msg << " Stoke Out\nCome Later Please\n";
            }

            return P;
}



Product_Info UpdateInfo( Product_Info &P , string Msg )
{
    cout << "\n\t=== === Updating " << Msg << " Info === === \n";
    //P.setProductInfo();
    Cashier C;
    int cost,quan;

    cout << "\nCurrent Price : " << P.getCost() << "\nCurrent Quantity : " << P.getQuantity() << "\n\n";

    cout << "\nEnter New Price ( per kg ) [ 0 for Old Price ] ";
    cin >> cost;
    cout << "\nEnter Quantity ( as kg ) : ";
    cin >> quan;

    C.setCost( cost );
    C.setQuantity( quan );
    C.setPname( Msg );
    WriteFileCashier( C , "AllUpdateinfo.txt" , Msg );


    if( cost )P.setCost( cost );

    P.setQuantity( P.getQuantity() + quan );

    string Path = "Old" + Msg + "Info.txt";


    WriteFile( P , Path.c_str() ); // OldMistyInfo.txt

    cout << "\n\t== Updated Status ==\n"
    << setw(10) << left << Msg << ": " << P.getQuantity() << " kg.\n"
    << setw(10) << left  << "Price/kg" << ": " << P.getCost() << " tk/kg\n";


    cout << "\n===\t===\t===Updated===\t===\t===\n\n";

    return P;
}


void AllTranInfo( Product_Info &P , string Msg )
{
    cout << "\n\t== Main -> Current Info ==\n"
    << setw(10) << left << Msg << ": " << P.getQuantity() << " kg.\n"
    << setw(10) << left  << "Price/kg" << ": " << P.getCost() << " tk/kg\n";
}




#endif // FUNCTIONHEADER_01_H_INCLUDED
