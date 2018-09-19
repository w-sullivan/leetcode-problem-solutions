//	William Sullivan
//
//	From:  https://leetcode.com/problems/reverse-integer/description/
//
//	Given a 32-bit signed integer, reverse digits of an integer.
//
//	Example 1:
//
//	Input: 123
//	Output : 321
//
//	Example 2 :
//
//	Input : -123
//	Output : -321
//
//	Example 3 :
//
//	Input : 120
//	Output : 21
//
//	Note:
//	Assume we are dealing with an environment which could only store integers
//	within the 32-bit signed integer range : [-2^31, 2^31 - 1].For the purpose
//	of this problem, assume that your function returns 0 when the reversed 
//	integer overflows.	-2,147,483,648 to 2,147,483,647


#include <iostream>
#include <string>


class Solution 
{
public:
	int reverse(int x) 
	{
		// Take care of the sign
		int sign;
		if (x < 0)
			sign = -1;
		else
			sign = 1;

		// Convert number to a string.
		std::string string_num = std::to_string(x);

		// Reverse the string
		for (unsigned int i = 0; i < string_num.size() / 2; i++)
		{
			char temp = string_num[i];
			string_num[i] = string_num[(string_num.size() - 1) - i];
			string_num[(string_num.size() - 1) - i] = temp;
		}

		// Try to convert the string to a number.
		int num;
		try
		{
			num = std::stoi(string_num);
		}
		catch (std::out_of_range)
		{
			return 0;
		}

		// Multiply sign
		num = num * sign;

		return num;
	}
};


int main()
{
	Solution solution;
	int input = 1534236469;
	int output = solution.reverse(input);

	std::cout << input << std::endl;
	std::cout << output << std::endl;

	return 0;
}

