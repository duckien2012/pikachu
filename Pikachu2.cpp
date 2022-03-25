#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
//#include "printBoard.h"
//#include "defineStruct.h"

using namespace std;

struct MAP{
    char** board;
    int row, column;
    int cursor = 0;
    int mark = 0;
};

MAP MapP; //MapPointer

void colorCheck(int);
void printHorizontalLine(int, int, int, int);
void printVerticalLine(int, int, int, int);
bool IsRowAndColumnValid(int, int);
void setMapPointer();
void input();
void printBoard();

void printMap(){ // use for test
    for(int i = 0; i < MapP.row; i++){
        for(int j = 0; j < MapP.column; j++)
            cout << MapP.board[i][j] << " ";
        cout << endl;
    }
}

int main(){
    //char board[100][1];
    srand(time(NULL));
    char c = ' ';
    MapP.cursor = 0; 
    input();
    setMapPointer();
    //printMap();
    while (c != 'x')
    {
        system("cls");
        printBoard();
        c = _getch();
        switch (c)
        {
        case 'W' :
        case 'w' :
        case 72:
            if ( MapP.cursor >= MapP.column)
            { 
                MapP.cursor -= MapP.column;
            }
            break;
        
        case 'S' :
        case 's' :
        case 80:
            if(MapP.cursor < MapP.column * (MapP.row - 1))
            {
                MapP.cursor += MapP.column;
            }
            break;

        case 'A' :
        case 'a' :
        case 75:
            if (MapP.cursor > 0)
            {
                MapP.cursor -= 1;
            }
            break; 

        case 'D' :
        case 'd' :
        case 77:
            if (MapP.cursor < MapP.column * MapP.row - 1)
            {
                MapP.cursor += 1;
            }
            break;
        case 13: // key Enter, use to fill the cursor cell
            break;
        }
    }
    delete[] MapP.board;
    return 0;
}



bool IsRowAndColumnValid(int row, int column){
    if(row % 2 == 0 || column % 2 == 0) return true;
    return false;
}

char getChar(int Char[]){
    int round = MapP.column * MapP.row / 2;
    int get;
    do{
        get = rand() % (round);
    }while(Char[get] == 0);
    Char[get]--;
    //cout << char(65 + get) << " " << Char[get] << endl;
    return char(65 + get);
}

void setMapPointer()
{
    MapP.board = new char*;
    int Char[26];
    //cout << "before" << endl;
    for(int i = 0; i < 26; i++) Char[i] = 2;
    //cout << "after" << endl;
    for(int i = 0; i < MapP.row; i++){
        MapP.board[i] = new char;
        for(int j = 0; j < MapP.column; j++){
            MapP.board[i][j] = getChar(Char);
        }
    }
}

void input()
{
    cout << "Input row and column: ";
    do{
        cin >> MapP.row >> MapP.column;
        if(!IsRowAndColumnValid(MapP.row, MapP.column))
            cout << "Input row and column again: ";
    }while(!IsRowAndColumnValid(MapP.row, MapP.column));
}

void colorCheck(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

void printBoard()
{
    int i;
    int wid = MapP.cursor % MapP.column;
    int len = MapP.cursor / MapP.column;
    int space ;
    for (i = 0; i < MapP.row; i++)
    {
	    printHorizontalLine (MapP.column, i , len , wid );
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
                   if(j == wid - 1){
                       cout << "   " << MapP.board[i][j];
                        colorCheck ( 1 ) ;
                        cout << "   |";
                        colorCheck (15) ;
                   }else{
                       colorCheck ( 1 ) ;
                    cout << "   " << MapP.board[i][j] << "   |";
                    colorCheck (15) ;
                   }
                }
                else 
                cout << "   " << MapP.board[i][j] << "   |";
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