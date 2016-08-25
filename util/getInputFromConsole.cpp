#include "util.h"

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>

bool getIntArrayFromConsole(std::vector<int> &intArry)
{
    std::vector<std::string> input;
    std::cout<<"pls input array:\t"<<std::endl;
    std::string inputStr;

    std::getline(std::cin, inputStr);

	std::stringstream inputStream(inputStr);
	std::string item;   
    while(std::getline(inputStream, item, ' '))
    {
    	input.push_back(item);
    }
    
    std::vector<int> inputArry;

    try
    {
    	std::vector<std::string>::iterator it = input.begin();
    	while(it != input.end())
    	{
    		std::string str = *it;
    		inputArry.push_back(std::stoi(*it));
    		it++;
    	}
    }
    catch (const std::invalid_argument& ia) 
    {
    	std::cerr << "Invalid argument: " << ia.what() << '\n';
  	    return false;
    }
  	
    intArry = inputArry;
    /*
  	copy(inputArry.begin(), inputArry.end(), std::ostream_iterator<int>(std::cout, ","));
  	std::cout<<std::endl;
  	*/
    return true;
}
