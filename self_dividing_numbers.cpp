// William Sullivan
//
// From: https://leetcode.com/problems/self-dividing-numbers/description/
//
// A self - dividing number is a number that is divisible by every digit it contains.
// For example, 128 is a self - dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
// Also, a self - dividing number is not allowed to contain the digit zero.
// Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
//
// Example:
// Input: 
// left = 1, right = 22
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> selfDividingNumbers(int left, int right) 
	{
		bool divisable;
		vector<int> divisable_numbers;

		for (int i = left; i <= right; i++)
		{
			string num = to_string(i);
			divisable = true;

			for (unsigned int j = 0; j < num.size() && divisable; j++)
			{
				if (num.at(j) == '0')
				{
					divisable = false;
				}
				else
				{
					if (i % ((int)num.at(j) - '0' ) == 0)
					{
						divisable = true;
					}
					else
					{
						divisable = false;
					}
				}
			}

			if (divisable)
			{
				divisable_numbers.push_back(i);
			}
		}
		return divisable_numbers;
	}
};


int main()
{
	Solution solution;
	vector<int> result;

	result = solution.selfDividingNumbers(1, 256);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " " << flush;
	}
	cout << endl;
	return 0;
}