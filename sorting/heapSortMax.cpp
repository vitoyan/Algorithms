#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "./util/util.h"

template <typename T>
class Heap
{
public:
	std::vector<T> heap;
	int length;
};

template <typename T>
void maxHeapIFY(Heap<T> &input, int i)
{
	if(i >= input.length/2)
		return;
	int leftIndex = ((i + 1 )<<1) - 1;
	int rightIndex = ((i + 1)<<1);
	
	int largest = i;

	if(leftIndex < input.length && input.heap[leftIndex] > input.heap[largest])
	{
		largest = leftIndex;
	}

	if(rightIndex < input.length && input.heap[rightIndex] > input.heap[largest])
	{
		largest = rightIndex;
	}

	if(largest != i)
	{
		int temp = input.heap[i];
		input.heap[i] = input.heap[largest];
		input.heap[largest] = temp;
		maxHeapIFY(input, largest);
	}
}

template<typename T>
void buildMaxHeap(Heap<T> &input)
{
	int middle = input.length/2;
	
	for(int i = (middle - 1); i >= 0; i--)
	{
		maxHeapIFY(input, i);	
		
	}
}

template<typename T>
void heapSort(Heap<T> &input)
{
	buildMaxHeap(input);
	for(int i = input.length - 1; i > 0;i = input.length - 1)
	{
		int temp = input.heap[0];
		input.heap[0] = input.heap[i];
		input.heap[i] = temp;
		input.length--;
		maxHeapIFY(input, 0);		
	}
}


int main() 
{

	Heap<int> input;
    while(!getIntArrayFromConsole(input.heap));

    input.length = (int)input.heap.size();
    heapSort(input);

    for(auto i = input.heap.begin(); i != input.heap.end(); i++)
    {
    	std::cout<<*i<< " ";
    }
    std::cout<<std::endl;

}