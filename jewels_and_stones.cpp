//	William Sullivan
//
// From: https://leetcode.com/problems/jewels-and-stones/description/
// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
// Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
//
// The letters in J are guaranteed distinct, and all characters in J and S are letters.Letters are case sensitive, 
// so "a" is considered a different type of stone from "A".
//
// S and J will consist of letters and have length at most 50.
//The characters in J are distinct.
//
// Example 1:
//
// Input: J = "aA", S = "aAAbbbb"
//	Output : 3


#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:

	int numJewelsInStones(string J, string S) 
	{
		int count = 0;

		for (unsigned int i = 0; i < J.length(); i++)
		{
			for (unsigned int j = 0; j < S.length(); j++)
			{
				if (J.at(i) == S.at(j))
				{
					count++;
				}
			}
		}
		return count;
	}
};

int main()
{
	string jewels;
	string stones;

	jewels = "aA";
	stones = "aAAbbbb";

	Solution solution;

	cout << jewels << " and " << stones << endl;
	cout << solution.numJewelsInStones(jewels, stones) << " Jewels in stones." << endl;

	return 0;
}