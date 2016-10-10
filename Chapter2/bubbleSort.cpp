#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "./util/util.h"

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    for(std::size_t i = 0; i < input.size()-1; i++)
    {
       for(std::size_t j = 0; j < input.size() - i - 1; j++) 
       {
            if(input[j] > input[j+1])
            {
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
        std::vector<int>::iterator it = input.begin();
        while(it != input.end())
        {
         std::cout<<*it<<" ";
            it++;
        }
        std::cout<<std::endl;
    }
    return 0;
}