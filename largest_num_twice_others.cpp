//	William Sullivan
//
//	From: https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
//
//	In a given integer array nums, there is always exactly one largest element.
//	Find whether the largest element in the array is at least twice as much as every other number
//	in the array.
//
//	If it is, return the index of the largest element, otherwise return -1.
//
//	Example 1:
//
//	Input: nums = [3, 6, 1, 0]
//	Output : 1
//	Explanation : 6 is the largest integer, and for every other number in the array x,
//	6 is more than twice as big as x.The index of value 6 is 1, so we return 1.
//
//	Note:
//	nums will have a length in the range[1, 50].
//	Every nums[i] will be an integer in the range[0, 99].

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
	int dominantIndex(vector<int>& nums) 
	{
		// Find the largest number.
		int largest_value_index = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > nums[largest_value_index])
			{
				largest_value_index = i;
			}
		}

		// check every number to see if two times the number is less
		//	than the dominant number.
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			// If one is found, there is no dominant number.
			if (i != largest_value_index && nums[i] * 2 > nums[largest_value_index])
			{
				return -1;
			}
		}

		// If none are found, return the index of the dominant number.
		return largest_value_index;
	}
};


int main()
{
	Solution solution;
	vector<int> input = { 3, 6, 1, 0 };
	int result = solution.dominantIndex(input);

	cout << "In the array:  [ " << flush;
	for (unsigned int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " " << flush;
	}
	cout << "]" << endl;

	if (result == -1)
	{
		cout << "No dominant number exists." << endl;
	}
	else 
	{
		cout << "The index of the dominant number is: " << result << endl;
	}

	return 0;
}