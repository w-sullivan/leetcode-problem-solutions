//	William Sullivan
//
//	From: https://leetcode.com/problems/plus-one/description/
//
//	Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//	The digits are stored such that the most significant digit is at the head of the list, and each
//	element in the array contain a single digit.
//	You may assume the integer does not contain any leading zero, except the number 0 itself.
//
//	Example 1:
//	Input: [1, 2, 3]
//	Output : [1, 2, 4]
//	Explanation : The array represents the integer 123.

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
	vector<int> plusOne(vector<int>& digits) 
	{
		// Start at the end
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			// If the last number isn't 9
			if (digits[i] != 9)
			{
				digits[i] += 1;
				return digits;
			}
			// If its 9, set it to zero and continue loop
			digits[i] = 0;
		}

		// If all the numbers were nine. Put a one on the front.
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	Solution solution;
	vector<int> input = { 9, 9 };
	vector<int> result;

	cout << "The array [ " << flush;
	for (unsigned int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " " << flush;
	}
	cout << "] +1 is:" << endl;

	result = solution.plusOne(input);

	cout << "[ " << flush;
	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " " << flush;
	}
	cout << "]" << endl;



	return 0;
}