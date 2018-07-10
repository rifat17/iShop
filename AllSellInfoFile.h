#ifndef ALLSELLINFOFILE_H_INCLUDED
#define ALLSELLINFOFILE_H_INCLUDED
#include <ctime>


#include "HeaderMain.h"
#include <fstream>
#include <iomanip>



void WriteFileCashier( Product_Info &, string , string );

void readFileCashier( string );
void readFileForTotal( string );

void OutputCashier( Cashier & );

void CurrentInfo( Product_Info & , string );

    //Timer();



void WriteFileCashier( Cashier &C, string Path,string msg )
{
    Cashier c;
    c.setCost( C.getCost() );
    c.setPname( C.getPname() );
    c.setQuantity( C.getQuantity() );

    ofstream Out(Path.c_str() , ios::out | ios::binary | ios::app );
    Out.write( reinterpret_cast< char *> (&c) , sizeof( Cashier ) );
    Out.close();
}

void readFileCashier( string Path)
{
    Cashier c;
    ifstream In( Path.c_str() , ios::in | ios::binary );

    if(!In){
        cerr << "\n\tNo Data here\n\tPlease insert data first\n";
    }
    In.read( reinterpret_cast< char *> (&c) , sizeof( Cashier ) );

    while( !In.eof() && In ){
        OutputCashier( c );
        In.read( reinterpret_cast< char *> (&c) , sizeof( Cashier ) );
    }

    In.close();
}

void OutputCashier( Cashier &C )
{
    cout << setw(10) << left << C.getPname() << ": " << C.getQuantity() << " kg.\n"
    << setw(10) << left  << "Price/kg" << ": " << C.getCost() << " tk/kg\n";
}

 void Timer()
 {
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result));
 }

 void readFileForTotal( string Path)
{
    Cashier c;
    int mTk , rTk , mC , rC;
     mTk = rTk = mC = rC = 0;
    ifstream In( Path.c_str() , ios::in | ios::binary );

    if(!In){
        cerr << "\n\tNo Data here\n\tPlease insert data first\n";
    }
    In.read( reinterpret_cast< char *> (&c) , sizeof( Cashier ) );

    while( !In.eof() && In ){
        //OutputCashier( c );
        if(c.getPname() == "Misty"){
            mTk += c.getCost();
            mC += c.getQuantity();
        }
        else{
            rTk += c.getCost();
            rC += c.getQuantity();
        }
        In.read( reinterpret_cast< char *> (&c) , sizeof( Cashier ) );
    }

    In.close();

    Product_Info M;
    Product_Info R;

    M.setCost( mTk );
    M.setQuantity( mC );

    R.setCost( rTk );
    R.setQuantity( rC );

    cout << "\n== Main -> All Transaction -> Total ==\n";

    CurrentInfo( M , "Misty");
    CurrentInfo( R , "Rosmalai");
}

void CurrentInfo( Product_Info &P , string Msg )
{
    cout << "\n== Main -> Current State - > " << Msg << " ==\n"
        << setw(10) << left << Msg << ": " << P.getQuantity() << " kg.\n"
    << setw(10) << left  << "Price/kg" << ": " << P.getCost() << " tk/kg\n";
}



#endif // ALLSELLINFOFILE_H_INCLUDED
