//	William Sullivan
//	From: https://leetcode.com/problems/longest-common-prefix/
//
//	Write a function to find the longest common prefix string amongst an array of strings.
//
//	If there is no common prefix, return an empty string "".
//
//	Example 1:
//	Input: ["flower", "flow", "flight"]
//	Output : "fl"
//	Example 2 :
//
//	Input : ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.
//
//	Note :
//	All given inputs are in lowercase letters a - z.

#include <iostream>
#include <vector>
#include <string>

class Solution 
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) 
	{
		int list_size = strs.size();

		// If no strings in string list, return ""
		if (list_size == 0)
			return "";

		std::string result = "";
		bool matching = true;
		int string_index = 0;

		while (matching)
		{
			if (string_index >= strs[0].size())
				break;

			char char_to_match = strs[0][string_index];

			// For each string in the list
			for (int i = 1; i < list_size; i++)
			{
				if (strs[i][string_index] != char_to_match)
				{
					matching = false;
				}
			}
			if (matching)
			{
				result.push_back(char_to_match);
				string_index++;
			}	
		}

		return result;
	}
};

void print_list(std::vector<std::string>& strs);

int main()
{
	Solution solution;
	std::vector<std::string> input = { "flower", "flow", "flight" };
	std::string result;

	print_list(input);
	result = solution.longestCommonPrefix(input);

	std::cout << "Longest common prefix = " << result << std::endl;

	return 0;
}

void print_list(std::vector<std::string>& strs)
{
	std::cout << "[ " << std::flush;
	for (unsigned int i = 0; i < strs.size(); i++)
	{
		std::cout << strs[i] << " " << std::flush;
	}
	std::cout << "]" << std::endl;
}