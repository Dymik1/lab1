#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	srand(argc == 3 ? atoi(argv[2]) : time(NULL));
	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	int x;
    char **square = new char* [n];
    
	for (int i = 0; i < n; i++)
	{
		square[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
			x=(rand() % 25 ) + 97;
   			square[i][j]=char(x);
		}
	}	
	return square;
}

void drawCharSquare(char **square, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(j != 0 && j + 1 == n) || n == 1 ? printf("%c\n", square[i][j]) : printf("%c ",square[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		delete square[i];
	}

	delete square;
}