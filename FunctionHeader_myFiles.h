#ifndef FUNCTIONHEADER_MYFILES_H_INCLUDED
#define FUNCTIONHEADER_MYFILES_H_INCLUDED

#include "FunctionHeader_01.h"
#include "Product_Info.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

Product_Info readFile( Product_Info &, string );

void WriteFile( Product_Info &, string );


Product_Info readFile( Product_Info &P, string Path)
{
    ifstream In( Path.c_str() , ios::in | ios::binary );

    if(!In){
        WriteFile( P , Path );
    }
    In.read( reinterpret_cast< char *> (&P) , sizeof( Product_Info ) );
    In.close();
    return P;
}

void WriteFile( Product_Info &P, string Path )
{
    ofstream Out(Path.c_str() , ios::out | ios::binary );
    Out.write( reinterpret_cast< char *> (&P) , sizeof( Product_Info ) );
    Out.close();
}


#endif // FUNCTIONHEADER_MYFILES_H_INCLUDED
