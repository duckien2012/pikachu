#include <iostream>
#include <cstring>
using namespace std ; 
void printHorizontalLine(int n)
{
	
	for (int i = 0; i < n; i++)
		cout << " -------";
	cout << endl;
	}
void printVerticalLine(int n)
{
		
	for (int i = 0; i < n; i++)
		cout << "       |";
	cout << endl;
}
void printBoard(char board[][1], int size )
{
for (int i = 0; i < size; i++)
{
	printHorizontalLine(size);
	cout << "|";
	printVerticalLine(size);
	cout << "|";
	for (int j = 0; j < size; j++)
	cout << "    "   << "   |";
	cout << endl << "|";
	printVerticalLine(size);
}
printHorizontalLine(size);

}

int main ()
{   
    int size = 4 ; 
    char board [4*4][1] ;  
    printBoard (board , 4 );
}