//	William Sullivan
//	From: https://leetcode.com/problems/implement-strstr/
//
//	Implement strStr().
//	Return the index of the first occurrence of needle in haystack, or -1 if 
//	needle is not part of haystack.
//
//	Example 1:
//	Input: haystack = "hello", needle = "ll"
//	Output : 2
//
//	Example 2 :
//	Input : haystack = "aaaaa", needle = "bba"
//	Output : -1
//
//	Clarification :
//	What should we return when needle is an empty string ?
//	For the purpose of this problem, we will return 0 when needle is an empty string.
//	This is consistent to C's strstr() and Java's indexOf().

#include <iostream>
#include <string>

class Solution 
{
public:
	int strStr(std::string haystack, std::string needle)
	{
		if(needle == "")
			return 0;
		if (needle.size() > haystack.size())
			return -1;
		if (needle.size() == haystack.size())
		{
			if (needle == haystack)
				return 0;
			else
				return -1;
		}

		for (unsigned int i = 0; i < haystack.size(); i++)
		{
			// If the haystack matches the first character of the needle.
			if (haystack[i] == needle[0])
			{
				int j = 0;

				// Check if it keeps matching.
				while (haystack[i + j] == needle[j])
				{
					if (j + 1 == needle.size())
					{
						return i;
					}
					j++;
				}
			}
		}
		return -1;
	}
};

int main()
{
	Solution solution;
	std::string haystack = "aaa";
	std::string needle = "a";
	int result;

	std::cout << "Haystack = \"" << haystack << "\"  Needle = \"" << needle << "\"" << std::endl;
	result = solution.strStr(haystack, needle);
	std::cout << "Index of " << "\"" << needle << "\" is " << result << std::endl;
	return 0;
}