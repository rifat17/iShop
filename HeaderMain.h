#ifndef HEADERMAIN_H_INCLUDED
#define HEADERMAIN_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

//#include "AllSellInfoFile.h"
#include "Cashier.h"
#include "Product_Info.h"
#include "FunctionHeader_01.h"
#include "FunctionHeader_myFiles.h"

using namespace std;

enum { MISTY = 1,ROSMALAI , BOTH ,BACK , PreviousAllUpdats };

void Intro()
{
    Product_Info m;
    Product_Info r;
    Cashier c;


    int temp;

    m = readFile( m , "OldMistyInfo.txt" );
    r = readFile( r , "OldRosmalaiInfo.txt" );

    while(1){

        if( m.getQuantity() <= 0 || r.getQuantity() <= 0 ){
            if( m.getQuantity() <= 0 ){
                UpdateInfo(m,"Misty");
            }
            if( r.getQuantity() <= 0 ){
                UpdateInfo( r ,"Rosmalai");
            }
        }
        cout << "\n\n===\t===\t===Customer Service===\t===\t===\n";
        cout << "\nChoice Your Option\n";
        cout << "\n1 - Misty\n2 - Rosmalai\n3 - Update Info\n4 - Current State\n5 - All Transaction\n6 - End Program\n";
        int cho;
        scanf("%d",&cho);

        switch(cho)
        {
        case MISTY:
                m = CellProduct( m , "Misty" );
                WriteFile( m , "OldMistyInfo.txt" );
            break;
        case ROSMALAI:
                r = CellProduct( r , "Rosmalai" );
                WriteFile( r , "OldRosmalaiInfo.txt" );

            break;
        case 3:
            do{
                cout << "\n== Main -> Update ==\n";
                cout << "\n\t1 - Update Misty\n\t2 - Update Rosmalai\n\t3 - Both\n\t4 - \tBack to Main\n\t5 - Update History\n";
                scanf("%d",&temp);
            }while(temp < 1 || temp > 5);
            switch(temp)
            {
            case MISTY:
                m = UpdateInfo( m , "Misty");
                break;
            case ROSMALAI:
                r = UpdateInfo( r , "Rosmalai");
                break;
            case BOTH:
                m = UpdateInfo( m , "Misty");
                r = UpdateInfo( r , "Rosmalai");
                break;
            case BACK:
                break;
            case PreviousAllUpdats:
                readFileCashier( "AllUpdateinfo.txt" );
                break;

            }
            break;
            case 4 :
                //SeeCurrentStatus
            do{
                cout << "\n== Main -> Current State ==\n";
                cout << "\n\t1 - Misty\n\t2 - Rosmalai\n\t3 - Both\n\t4 - Back to Main\n";
                scanf("%d",&temp);
            }while(temp < 1 || temp > 4);
            switch(temp)
            {
            case MISTY:
                CurrentInfo( m , "Misty");
                break;
            case ROSMALAI:
                CurrentInfo( r , "Rosmalai");
                break;
            case BOTH:
                CurrentInfo( m , "Misty");
                CurrentInfo( r , "Rosmalai");
                break;
            case BACK:
                break;
            }
            break;
            case 5:
                do{
                cout << "\n\t1 - Total Transaction\n\t2 - Transaction History\n";
                scanf("%d",&temp);
            }while(temp < 1 || temp > 2);
            switch(temp)
            {
            case 1: //Total
                readFileForTotal( "AllSellinfo.txt" );
                break;
            case 2: //All
                cout << "\n== Main -> All Transaction -> All ==\n";
                readFileCashier( "AllSellinfo.txt" );
            }
                break;
            case 6:

                return ;
        }
    }
}


#endif // HEADERMAIN_H_INCLUDED
