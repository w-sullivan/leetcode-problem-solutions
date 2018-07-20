//	William Sullivan
//
// From: https://leetcode.com/problems/number-complement/description/
// Given a positive integer, output its complement number.The complement strategy is to flip the bits of its binary representation.
//
// Note:
// The given integer is guaranteed to fit within the range of a 32 - bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
//
// Example 1:
// Input: 5
//	Output : 2
//	Explanation : The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution 
{
private:
	string toBinary(int num)
	{
		string result = "";
		int remainder;
		int div = num;

		while (div != 0)
		{
			remainder = div % 2;
			div = (div / 2);

			result = to_string(remainder) + result;
		}

		return result;
	}

	int fromBinary(string num)
	{
		int decResult = 0;
		
		for (unsigned int i = num.size() - 1; i > 0; i--)
		{
			if (num.at(i) == '1')
			{
				decResult += (int)pow(2, (num.size() -1) - i );
			}
		}

		return decResult;
	}

	string bitInverter(string binNum)
	{
		string invertNum = binNum;

		for (unsigned int i = 0; i < invertNum.size(); i++)
		{
			if (invertNum.at(i) == '0')
			{
				invertNum.at(i) = '1';
			}
			else
			{
				invertNum.at(i) = '0';
			}
		}

		return invertNum;
	}

public:
	int findComplement(int num) 
	{
		// convert the number to binary
		string binNum = toBinary(num);
		// invert the bits
		binNum = bitInverter(binNum);
		// convert the number to decimal
		int result = fromBinary(binNum);
		// return the number
		return result;
	}
};


int main()
{
	Solution solution;

	cout << solution.findComplement(2) << endl;

	return 0;
}