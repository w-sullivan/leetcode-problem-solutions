//	William Sullivan
//  From: https://leetcode.com/problems/single-number/description/
//
//  Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
//	Note:
//
//	Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//
//	Example 1 :
//
//	Input : [2, 2, 1]
//	Output : 1
//	Example 2 :
//
//  Example 2 :
//	Input : [4, 1, 2, 1, 2]
//	Output : 4

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	//----------------------------------------
	// Okay, I didn't come up with this one.
	// I just loved this solution so much,
	// I had to implement it and play around
	// with it a bit.
	//----------------------------------------
	int singleNumber(vector<int>& nums) 
	{
		int result = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			result ^= nums[i];
		}
		return result;
	}
};



int main()
{
	Solution solution;
	vector<int> input = { 4, 1, 2, 1, 2 };

	int output = solution.singleNumber(input);

	cout << output << endl;
	return 0;
}