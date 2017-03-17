#include <iostream>

void printMatrixCricle(int** matrix, int row, int columns, int start)
{
	if(!matrix || columns < 0 || row < 0 || start < 0)
		return;
	int endX = columns - 1 - start;
	int endY = row - 1 - start;

	for(int i = start; i <= endX; i++)
	{
		std::cout<<matrix[start][i]<<" ";
	}

	if(start < endY)
	{
		for(int i = start + 1; i <= endY; i++)
		{
			std::cout<<matrix[i][endX]<<" ";
		}
	}

	if(start < endX && start < endY)
	{
		for(int i = endX - 1; i >= start; i--)
		{
			std::cout<<matrix[endY][i]<<" ";
		}
	}

	if(start <endX && start < endY - 1)
	{
		for(int i= endY - 1; i >= start + 1; i--)
		{
			std::cout<<matrix[i][start]<<" ";
		}
	}
}

void printMatrix(int** matrix, int row, int column)
{
	if(!matrix || row < 0 || column < 0)
		return;
	int starts = 0;
	while(row > starts*2 && column > starts*2)
	{
		printMatrixCricle(matrix, row, column, starts);
		starts++;
	}

}

int main()
{
	int atr1[5] = {1, 2, 3, 4, 5};
	int atr2[5] = {16, 17, 18, 19, 6};
	int atr3[5] = {15, 24, 25, 20, 7};
	int atr4[5] = {14, 23, 22, 21, 8};
	int atr5[5] = {13, 12, 11, 10, 9};
	
	int *a[5] = {atr1, atr2, atr3, atr4, atr5};
	printMatrix(a, 5, 5);
}


