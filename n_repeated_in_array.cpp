//	William Sullivan
//	From: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
//
//	In a array A of size 2N, there are N + 1 unique elements, and exactly one
//	of these elements is repeated N times.
//
//	Return the element repeated N times.
//
//	Example 1:
//	Input: [1, 2, 3, 3]
//	Output : 3
//
//	Example 2 :
//	Input : [2, 1, 2, 5, 3, 2]
//	Output : 2
//
//	Example 3 :
//	Input : [5, 1, 5, 2, 5, 3, 5, 4]
//	Output : 5
//
//	Note :
//	4 <= A.length <= 10000
//	0 <= A[i] < 10000
//	A.length is even

#include <iostream>
#include <vector>
#include <map>
#include <set>

class Solution 
{
public:
	int repeatedNTimes(std::vector<int>& A)
	{
		std::set<int> num_set = {};
		for (unsigned int i = 0; i < A.size(); i++)
		{
			if (num_set.insert(A[i]).second == false)
				return A[i];
		}
	}

	// Map version.  Slow
	int repeatedNTimesMap(std::vector<int>& A) 
	{
		int n = A.size() / 2;

		std::map<int, int> num_map;

		for (unsigned int i = 0; i < A.size(); i++)
		{
			if (num_map.count(A[i]) > 0)
				num_map[A[i]] += 1;
			else
				num_map.insert(std::pair<int, int>(A[i], 1));
		}

		std::map<int, int>::iterator it = num_map.begin();
		while (it != num_map.end())
		{
			if (it->second == n)
				return it->first;
			it++;
		}
		return 0;
	}
};

void showVector(std::vector<int> nums);

int main()
{
	Solution solution;
	std::vector<int> input = { 5, 1, 5, 2, 5, 3, 5, 4 };

	int result = solution.repeatedNTimes(input);

	std::cout << "Array: " << std::flush;
	showVector(input);
	std::cout << "Result: " << result << std::endl;

	return 0;
}

void showVector(std::vector<int> nums)
{
	std::cout << "{ " << std::flush;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " " << std::flush;
	}
	std::cout << "}" << std::endl;
}