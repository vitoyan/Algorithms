#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits>

#include "./util/util.h"

enum direction {zero, leftUp, left, up};


std::vector<std::vector<direction> > longestCommonSub(const std::string &s1, const std::string &s2)
{
	std::vector<std::vector<int> > m(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
	std::vector<std::vector<direction> > n(s1.size() + 1, std::vector<direction>(s2.size() + 1, zero));
	for(int i = 1; i <= (int)s1.size(); i++)
		for(int j = 1; j <= (int)s2.size(); j++)
		{
			if(s1[i] == s2[j])
			{
				m[i][j] = m[i - 1][j - 1] + 1;
				n[i][j] = leftUp;
			}
			else
			{
				if(m[i-1][j] >= m[i][j-1])
				{
					m[i][j] = m[i-1][j];
					n[i][j] = up;
				}
				else
				{
					m[i][j] = m[i][j-1];
					n[i][j] = left;
				}
			}
		}
	return n;
}

void printLongestCommonSub(std::vector<std::vector<direction> > r, const std::string &str, int x, int y)
{
	if(r.empty())
		return;

	if(x == 0 || y == 0)
		return;

	if(r[x][y] == leftUp)
	{
		printLongestCommonSub(r, str, x - 1, y - 1);
		std::cout<<str[x-1];
	}
	else if(r[x][y] == left)
	{
		printLongestCommonSub(r, str, x - 1, y);
	}
	else if(r[x][y] == up)
	{
		printLongestCommonSub(r, str, x, y - 1);
	}
}

int main()
{
	std::string input1;
	getInputStringFromConsole(input1);
	std::string input2;
	getInputStringFromConsole(input2);

	std::vector<std::vector<direction> > r = longestCommonSub(input1, input2);
	printLongestCommonSub(r, input1, input1.size(), input2.size());
	std::cout<<std::endl;
}