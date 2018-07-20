//	William Sullivan
//
// From: https://leetcode.com/problems/distribute-candies/description/
// Given an integer array with even length, where different numbers in this array represent 
// different kinds of candies. Each number means one candy of the corresponding kind. 
// You need to distribute these candies equally in number to brother and sister. 
// Return the maximum number of kinds of candies the sister could gain.
//
//	EXAMPLE 1:
//	Input: candies = [1, 1, 2, 2, 3, 3]
//	Output : 3
//	Explanation :
//	There are three different kinds of candies(1, 2 and 3), and two candies for each kind.
//	Optimal distribution : The sister has candies[1, 2, 3] and the brother has candies[1, 2, 3], too.
//	The sister has three different kinds of candies.
//
//	EXAMPLE 2:
//	Input: candies = [1, 1, 2, 3]
//	Output : 2
//	Explanation : For example, the sister has candies[2, 3] and the brother has candies[1, 1].
//	The sister has two different kinds of candies, the brother has only one kind of candies.
//
// Note:
// The length of the given array is in range[2, 10,000], and will be even.
// The number in given array is in range[-100,000, 100,000].


#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution 
{
public:
	int distributeCandies(vector<int>& candies)
	{
		set<int> sisters_candy;
		int brothers_candy_size = 0;

		// For candy in the candies array
		for (int i = 0; i < candies.size(); i++)
		{
			bool giveToSister = false;

			// Give sister the type of candy if she doesn't have it.
			giveToSister = sisters_candy.insert(candies[i]).second;

			// If she does have the type of candy, give it to the brother
			if (!giveToSister)
			{
				brothers_candy_size++;
			}

		}
		// Compare candy pile sizes.  If hers is bigger give away half the difference so that they are equal.
		//  If bothers is bigger, it makes no difference to the amount of different types, since she already has
		//  every unique candy type.  
		int candy_types = sisters_candy.size();

		if (candy_types > brothers_candy_size)
		{
			// since all her candy is unique, she loses half the difference from here candy type amount.
			candy_types -= (candy_types - brothers_candy_size) / 2;
		}

		//Return the maximum number of kinds of candies the sister could gain.
		return candy_types;
	}
};

int main()
{
	Solution solution;
	vector<int> input = { 1, 1, 2, 3 };
	int answer;

	answer = solution.distributeCandies(input);
	cout << "ANSWER: " << answer << endl;

	return 0;
}