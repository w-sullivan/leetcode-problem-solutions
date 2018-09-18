//	William Sullivan
//
//	From: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
//	Given a string, find the length of the longest substring without repeating characters.
//	
//	Example 1:
//
//	Input: "abcabcbb"
//	Output : 3
//	Explanation : The answer is "abc", with the length of 3.
//
//	Example 2:
//
//	Input: "bbbbb"
//	Output : 1
//	Explanation : The answer is "b", with the length of 1.
//
//	Example 3:
//
//	Input: "pwwkew"
//	Output : 3
//	Explanation : The answer is "wke", with the length of 3.
//	Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <string>
#include <set>

class Solution 
{
public:
	int lengthOfLongestSubstring(std::string s) 
	{
		std::set<char> subset;
		int max_size = 0;
		int i = 0;
		int j = 0;

		// While window is not at the end of the string
		while (i < s.size() && j < s.size())
		{
			// If the character is not in the set window
			if (subset.count(s[j]) == 0)
			{
				// Insert it into the set window
				subset.insert(s[j]);
				j++;
			}
			// If it is in the window
			else
			{
				// Remove the left most element
				subset.erase(s[i]);
				// Move the left edge of the window right
				i++;
			}

			// Check if the window size is greater than max.
			if (subset.size() > max_size)
				max_size = subset.size();
		}
		
		return max_size;
	}
};

int main()
{
	Solution solution;
	std::string input = "a";

	int result = solution.lengthOfLongestSubstring(input);

	std::cout << "String: " << input << std::endl;
	std::cout << "Longest substring is: " << result << std::endl;
	return 0;
}