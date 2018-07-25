//	William Sullivan
//
//	From: https://leetcode.com/problems/find-pivot-index/description/
//
//	Given an array of integers nums, write a method that returns the "pivot" index of this array.
//
//	We define the pivot index as the index where the sum of the numbers to the left of the index
//	is equal to the sum of the numbers to the right of the index.
//
//	If no such index exists, we should return -1. If there are multiple pivot indexes, 
//	you should return the left-most pivot index.
//
//	Example:
//	Input: 
//	nums = [1, 7, 3, 6, 5, 6]
//	Output: 3
//	Explanation :
//	The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
//	Also, 3 is the first index where this occurs.
//
//	Note:
//	The length of nums will be in the range[0, 10000].
//	Each element nums[i] will be an integer in the range[-1000, 1000].

#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
	int pivotIndex(vector<int>& nums) 
	{
		// If nums has zero elements, return -1.
		if (nums.size() == 0)
		{
			return -1;
		}

		// If nums has one element, return that index.
		if (nums.size() == 1)
		{
			return 0;
		}

		// Find sum of all values in nums
		int total_sum = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			total_sum += nums[i];
		}

		// Compare the left and right sums for every potential pivot index.
		int left_sum = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			// If left sum equals the right sum, return the index.
			if (left_sum == total_sum - left_sum - nums[i])
			{
				return i;
			}

			left_sum += nums[i];
		}

		// If no pivot found, return -1
		return -1;
	}
};


int main()
{
	Solution solution;
	vector<int> input = { 1, 7, 3, 6, 5, 6 };

	cout << "For array:  [ " << flush;
	for (unsigned int i = 0; i < input.size(); i++)
		cout << input[i] << " " << flush;
	cout << "]" << endl;

	int result = solution.pivotIndex(input);

	if (result < 0)
		cout << "No pivot index exists." << endl;
	else
		cout << "The pivot index is: " << result << endl;

	return 0;
}