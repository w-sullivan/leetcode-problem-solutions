//	William Sullivan
//
//	From: https://leetcode.com/problems/shortest-distance-to-a-character/description/
//
//  Given a string S and a character C, 
//  return an array of integers representing the shortest distance from the character C in the string.
//
//  Example 1:
//
//  Input: S = "loveleetcode", C = 'e'
//	Output : [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//
//	S string length is in [1, 10000].
//	C is a single character, and guaranteed to be in string S.
//	All letters in S and C are lowercase.

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:

	vector<int> shortestToChar(string S, char C) 
	{
		vector<int> result;
		bool found;

		// for each character in string S
		for (unsigned int i = 0; i < S.size(); i++)
		{
			// find the closest match to the right
			int right_distance;
			found = false;
			for (unsigned int j = i; j < S.size() && !found; j++)
			{
				if (S.at(j) == C)
				{
					found = true;
					right_distance = j - i;
				}
			}
			// if the character is not found, set it to -1 (meaning not in string)
			if (!found)
			{
				right_distance = -1;
			}

			// Find the closest match to the left
			int left_distance;
			found = false;
			for (int j = i; j >= 0 && !found; j--)
			{
				if (S.at(j) == C)
				{
					found = true;
					left_distance = i - j;
				}
			}
			// if the character is not found, set it to -1 (meaning not in string)
			if (!found)
			{
				left_distance = -1;
			}

			// Compare distances and push to result the smallest
			// if only the left distance was found
			if (right_distance < 0 && left_distance >= 0)
			{
				result.push_back(left_distance);
			}
			// if only the right distance was found
			else if (right_distance >= 0 && left_distance < 0)
			{
				result.push_back(right_distance);
			}
			// Compare the two distances and push the smallest one to result.
			else if (right_distance <= left_distance)
			{
				result.push_back(right_distance);
			}
			else
			{
				result.push_back(left_distance);
			}
		}

		return result;
	}
};

int main()
{
	Solution solution;
	vector<int> result;
	string S = "loveleetcode";
	char c = 'e';

	result = solution.shortestToChar(S, c);

	cout << "[ " << flush;

	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " " << flush;
	}
	cout << "]" << endl;

	return 0;
}