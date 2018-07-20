//	William Sullivan
//
//	From: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
//  Let's call an array A a mountain if the following properties hold:
//  A.length >= 3
//  There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
//  Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1].
//
//  3 <= A.length <= 10000
//  0 <= A[i] <= 10 ^ 6
//  A is a mountain, as defined above.

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A)
	{
		int i = 0;
		for (i = 0; i < A.size() - 1; i++)
		{
			if (A[i] >= A[i + 1])
			{
				return i;
			}
		}
		return -1;  // Error
	}
};

int main()
{
	Solution solution;
	vector<int> mountain = { 0, 1, 2, 3, 5, 8, 3, 2, 1, 0 };
	
	cout << solution.peakIndexInMountainArray(mountain);

	return 0;
}