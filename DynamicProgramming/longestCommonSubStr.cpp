#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <set>
#include <limits>
#include <algorithm>

#include "./util/util.h"

 void longestCommonSubStr(const std::string &str1, const std::string &str2, int &longestSize, int &a)
 {
 	if(str1.empty() || str2.empty())
 		return;

 	std::vector<std::vector<int> > s(str1.size(), std::vector<int>(str2.size(), 0));
 	longestSize = 0;
 	for(int i = 0; i < (int)str1.size(); i++)
 		for(int j = 0; j < (int)str2.size(); j++)
 		{
 			if(i == 0 || j == 0)
 			{
 				if(str2[i] == str2[j])
 				{
 					s[i][j] = 1;
 					a = i;
 					longestSize = s[i][j];
 				}
 				continue;
 			}
 			if(str1[i] == str2[j])
 			{
 				s[i][j] = s[i - 1][j - 1] + 1;
 				if(s[i][j] >= longestSize)
 				{
 					a = i;
 					longestSize = s[i][j];
 				}
 			}
 		}
 }

int main()
{
	std::string str1, str2;
	getInputStringFromConsole(str1);
	getInputStringFromConsole(str2);
	int finish = 0;
	int longestSize = 0;
	longestCommonSubStr(str1, str2, longestSize, finish);
	std::cout<<"the longest sub string is:"<<std::endl;
	std::cout<<str1.substr(finish - longestSize + 1, longestSize)<<std::endl;
    
}