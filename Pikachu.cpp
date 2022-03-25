#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>

using namespace std;
struct MAP{
    string** board;
    int row, column;
    int cursor ;
    int L,W ;
};
void colorCheck(int color )
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}	
void printHorizontalLine(int row , int r , int l , int w)
{
	for (int i = 0; i < row; i++)
    {
        if ( i == w  && (r ==l  || r== l +1 ))
        {
            colorCheck ( 1 ) ;
		    cout << " -------";
            colorCheck ( 15 ) ;
        }
        else 
            cout << " -------";
	}
    cout << endl;
}
void printVerticalLine(int column , int r , int l ,  int w)
{
	for (int i = 0; i < column; i++)
    {
        if ( r == l && ( i == w || i == w -1 ))
        {
            colorCheck ( 1 ) ;
		    cout << "       |";
            colorCheck ( 15) ;
        }
        else 
            cout << "       |";
    }
    cout << endl;
}


MAP MapP; //MapPointer

bool IsRowAndColumnValid(int row, int column){
    if(row % 2 == 0 || column % 2 == 0) return true;
    return false;
}

void setMapPointer(){
    MapP.board = new string*;
    for(int i = 0; i < MapP.row; i++){
        MapP.board[i] = new string;
    }
}

void input(){
    cout << "Input row and column: ";
    do{
        cin >> MapP.row >> MapP.column;
        if(!IsRowAndColumnValid(MapP.row, MapP.column))
            cout << "Input row and column again: ";
    }while(!IsRowAndColumnValid(MapP.row, MapP.column));
}

void printBoard( )
{
int i ;
int wid  = MapP.cursor % MapP.row ;
int len = MapP.cursor / MapP.column ;
int space ;
for (i = 0; i < MapP.row; i++)
    {
	    printHorizontalLine (MapP.column , i , len , wid );
        if ( i == len && wid == 0 )
        {
            colorCheck ( 1 ) ;
            cout << "|" ;
            colorCheck ( 15 ) ;
        }
        else 
            cout << "|" ;
        printVerticalLine (MapP.column , i , len , wid );
        if ( i == len && wid == 0 )
        {
            colorCheck ( 1 ) ;
            cout << "|" ;
            colorCheck ( 15 ) ;
        }
        else 
            cout << "|" ;
        for (int j = 0 ; j< MapP.column ; j++)  // ki tu nhap o day 
        {
            if ( i == len &&  ( j == wid ||  j == wid -1 ))
                {
                    colorCheck ( 1 ) ;
                    cout << "       |";
                    colorCheck (15) ;
                }
                else 
                cout << "       |";
        }
        cout << endl ;
        if ( i == len && wid == 0 )
        {
            colorCheck ( 1 ) ;
            cout << "|" ;
            colorCheck ( 15 ) ;
        }
        else 
            cout << "|" ;
        printVerticalLine  ( MapP.column , i , len , wid ) ;
    }
    printHorizontalLine (MapP.column , i , len , wid );
}
int main(){
    char board[100][1] ;
    char c = ' ' ;
    MapP.cursor = 0 ; 
    input();
    while ( c != 'x' )
    {
        system("cls") ;
        printBoard () ;
        c = _getch () ;
        switch (c)
        {
        case 'W' :
        case 'w' : {
            if ( MapP.cursor >= MapP.column  )
               { 
                    MapP.cursor -= MapP.row ;
               }
                 break;
        }
        
        case 'S' :
        case 's' : {
            if ( MapP.cursor <= MapP.column* (MapP.row -1 ) -1 )
                {
                    MapP.cursor += MapP.row;
                }
                break;
        }

        case 'A' :
        case 'a' : {
            if ( MapP.cursor > 0 )
            {
                MapP.cursor -= 1 ;
            }
            break ; 
        }

        case 'D' :
        case 'd' : {
            if ( MapP.cursor < MapP.column*MapP.row -1  )
                {
                    MapP.cursor += 1  ;
                }
                break;
        }

        }
    }
    return 0;
}