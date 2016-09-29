#include "../util/util.h"

#include <iostream>
#include <vector>

int w[20][20][20]={0};

int calcu(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return calcu(20, 20, 20);
	else if(w[a][b][c] == 0)
	{
		if( a < b && b < c)
		{
			w[a][b][c] =  calcu(a, b, c-1) + calcu(a, b-1, c-1) - calcu(a, b-1, c);
		}
		else
		{
			w[a][b][c] = calcu(a-1, b, c) + calcu(a-1, b-1, c) + calcu(a-1, b, c-1) - calcu(a-1, b-1, c-1);
		}
	}

	return w[a][b][c];
}

int main()
{
	std::vector<int> input;

	while(!getIntArrayFromConsole(input) || input.size() != 3)
		std::cout<<"pls input correctly"<<std::endl;

	int result = calcu(input[0], input[1], input[2]);

	std::cout<<"w("<<input[0]<<", "<<input[1]<<", "<<input[2]<<")"<<" = "<<result<<std::endl;
}