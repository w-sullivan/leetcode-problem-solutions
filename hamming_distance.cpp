//	William Sullivan
//
//	From: https://leetcode.com/problems/hamming-distance/description/
//  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//  Given two integers x and y, calculate the Hamming distance.


#include <iostream>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) 
	{
		int n = x ^ y;
		int count = 0;
		while (n > 0)
		{
			if (n & 1)
			{
				count++;
			}

			n >>= 1;
		}
		return count;
	}
};

int main()
{
	Solution solution;
	cout << solution.hammingDistance(6, 13) << endl;
	return 0;
}