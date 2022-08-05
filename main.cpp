#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cstdlib>
#include <ctime>

#define COLUMNS 9
#define ROWS 9

using namespace std;

int StarFunction(int arr[9][9])
{
	initializeGrid(arr);
	return generateGrid(arr);
}

void initializeGrid(int grid[9][9])
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			grid[i][j] = 0;
		}
	}
}
//void drawGridWindow(sf::RenderWindow window, sf::Text number, int arr[9][9])
//{
//	number.setPosition(25, 25);
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			number.setString(to_string(arr[i][j]));
//			window.draw(number);
//			number.move(25, 0);
//		}
//		number.setPosition(25, (25 + 25*i));
//	}
//}
void inputRandom(int arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp = rand() % 9 + 1;
			if (isSafe(arr, i, j, temp))
			{
				arr[i][j] = temp;

			}
		}
	}
}
void reinitializeRow(int arr[9])
{
	for (int i = 0; i < COLUMNS; i++)
	{
		arr[i] = i + 1;
	}
}
void createSudoku(int arr[9][9])
{
	int emptyPosition = 81;
	//fillDiagnoals(arr);
	//fillPerimeter(arr);
	int filled[COLUMNS];
	int j = 0;
	for (int i = 0; i < COLUMNS; i++)
	{
		reinitializeRow(filled);
		while (j < COLUMNS)
		{
			int tempR = rand() % 9 + 1;
			//cout << tempR << " ";
			if (isSafe(arr, i, j, tempR))
			{
				arr[i][j] = tempR;
				cout << tempR << " ";
				j++;
			}
		}
		cout << endl;
		// copy(begin(filled), end(filled), begin(unfilled));
		//cout << j << " ";
		j = 0;
	}
	//fillRemainder(arr);
}

bool FindUnassignedLocation(int grid[9][9], int& row, int& col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (grid[row][col] == 0)
				return true;
		}
	}

	return false;
}

bool generateGrid(int grid[9][9])
{
	int row, col;

	if (!FindUnassignedLocation(grid, row, col))
		return true; // success!

	int guessNum[] = { 1,2,3,4,5,6,7,8,9 };
	random_shuffle(guessNum, guessNum + COLUMNS);
	for (int i = 0; i < 9; i++)
	{
		if (isSafe(grid, row, col, guessNum[i]))
		{
			grid[row][col] = guessNum[i];

			if (generateGrid(grid))
				return true;

			grid[row][col] = 0;
		}
	}

	return false;

}

void printSudoku(int arr[9][9])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
bool isSafe(int grid[9][9], int row, int col, int num)
{
	return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num);
}
bool UsedInRow(int grid[9][9], int row, int num)
{
	for (int col = 0; col < 9; col++)
	{
		if (grid[row][col] == num)
			return true;
	}

	return false;
}

bool UsedInCol(int grid[9][9], int col, int num)
{
	for (int row = 0; row < 9; row++)
	{
		if (grid[row][col] == num)
			return true;
	}

	return false;
}

bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
		}
	}

	return false;
}

extern "C" {
    __declspec(dllexport) int StarFunction(int grid[9][9]){
		return grid}
}