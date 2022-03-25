#include<iostream>
#include<string>

using namespace std;
struct MAP{
    string** board;
    int row, column;
};
void printHorizontalLine(int row)
{
	for (int i = 0; i < row; i++)
		cout << " -------";
	cout << endl;
	}
void printVerticalLine(int column)
{
		
	for (int i = 0; i < column; i++)
		cout << "       |";
	cout << endl;
}
void printBoard(char board[][1], int row , int column )
{
for (int i = 0; i < row ; i++)
{
	printHorizontalLine(column);
	cout << "|";
	printVerticalLine(column);
	cout << "|";
	for (int j = 0; j < column; j++)
	cout << "    "   << "   |";
	cout << endl << "|";
	printVerticalLine(column);
}
printHorizontalLine(column);

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

int main(){
    char board[100][1] ;
    input();
    printBoard (board , MapP.row , MapP.column) ;
    return 0;
}