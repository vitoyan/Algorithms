#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "../util/util.h"

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    for(std::size_t i = 1; i < input.size(); i++)
    {
        int temp = input[i];
        for(std::size_t j = i - 1; j >= 0; j--)
        {
            if(input[j] > temp)
            {
                input[j+1] = input[j];                                
            }
            else
            {
                input[j+1] = temp;
                break;
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
