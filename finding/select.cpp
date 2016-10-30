#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>

#include "./util/util.h"

void swap(int *a, int *b)
{
	if(*a == *b)
		return;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertionSort(std::vector<int> &input, int p, int q)
{
	if(p == q)
		return;

	for(int i = p+1; i <= q; i++)
	{
		int temp = input[i];
		int j = i - 1;
		while(j >= p && temp < input[j])
		{			
			input[j + 1] = input[j];
			j--;
		}
		if(j != i - 1)
			input[j+1] = temp;
	}
}

int partition(std::vector<int> &input, int p, int q, int pivot)
{
	if(p == q)
		return p;
	
	int i = p -1;
	int j = p;
	int mid;
	while(j <= q)
	{
		if(input[j] <= pivot)
		{
			i++;
			swap(&input[i], &input[j]);			
		}
		if(input[i] == pivot)
			mid = i;
		j++;
	}
	swap(&input[i], &input[mid]);

	return i;	
}

int select(std::vector<int> input, int p, int q, int i)
{
	if(p == q)
		return input[p];

	int size = q - p + 1;
	int count = size/5;
	int tail = size%5;
	std::vector<int> middle;
	middle.resize(count + (tail?1:0));

	auto m = middle.begin();
	for(int i = 0; i < count; i++)
	{
		insertionSort(input, p + i*5, p + i*5 + 4);
		*m = input[p + i*5 +2];
		m++;
	}

	if(tail)
	{
		insertionSort(input, p + count*5, q);
		*m = input[p + count*5 + tail/2];
	}	

	int mid = select(middle, 0, (count + (tail?1:0)) - 1, (count + (tail?1:0))/2);

	int k = partition(input, p, q, mid);

	if(i == (k + 1))
		return input[k];
	if(i < (k + 1))
		return select(input, p, k - 1, i);
	else
		return select(input, k + 1, q, i);
}

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    int middle = select(input, 0, (int)input.size() - 1, input.size()/2);
    std::cout<<"the middle sequnce is "<<(input.size()/2)<<" the middle is "<<middle<<std::endl;
}