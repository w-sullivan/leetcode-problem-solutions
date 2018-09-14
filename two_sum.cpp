//	William Sullivan
//
//	From: https://leetcode.com/problems/two-sum/description/
//
//	Given an array of integers, return indices of the two numbers such that they add up to
//	a specific target.
//
//	You may assume that each input would have exactly one solution, and you may not use	
//	the same element twice.
//
//	Example:
//
//	Given nums = [2, 7, 11, 15], target = 9,
//
//	Because nums[0] + nums[1] = 2 + 7 = 9,
//	return[0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void showVector(vector<int> nums);

class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;

		if (nums.empty())
			return result;

		unordered_map<int, int> myMap;
		unordered_map<int, int>::iterator it;
		int difference;

		for (int i = 0; i < nums.size(); i++)
		{
			difference = target - nums[i];

			// check if the difference is in the map
			it = myMap.find(difference);
			if (it != myMap.end() && it->second != i)
			{
				result.push_back(i);
				result.push_back(it->second);
				return result;
			}
			// if not, add it
			myMap[nums[i]] = i;
		}
	}
};


int main()
{
	Solution solution;
	vector<int> input = { 2, 7, 11, 15 };
	int target = 9;

	cout << "Given nums = " << flush;
	showVector(input);
	cout << ", target = " << target << endl;

	vector<int> result = solution.twoSum(input, target);

	showVector(result);
	cout << endl;

	return 0;
}

void showVector(vector<int> nums)
{
	cout << "[ " << flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " " << flush;
	}
	cout << "]" << flush;
}


