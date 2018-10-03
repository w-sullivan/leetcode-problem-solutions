//	William Sullivan
//	From: https://leetcode.com/problems/valid-parentheses/description/
//
//	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
//	determine if the input string is valid.
//
//	An input string is valid if:
//
//	Open brackets must be closed by the same type of brackets.
//	Open brackets must be closed in the correct order.
//	Note that an empty string is also considered valid.
//
//	Example 1:
//
//	Input: "()"
//	Output : true
//
//	Example 2 :
//
//	Input : "()[]{}"
//	Output : true
//
//	Example 3 :
//
//	Input : "(]"
//	Output : false
//
//	Example 4 :
//
//	Input : "([)]"
//	Output : false
//
//	Example 5 :
//
//	Input : "{[]}"
//	Output : true

#include <iostream>
#include <string>
#include <stack>

class Solution 
{
public:
	bool isValid(std::string s) 
	{
		// If empty, return true
		if (s == "")
			return true;

		std::stack<char> brackets;

		// For each character in the string
		for (unsigned int i = 0; i < s.size(); i++)
		{
			// If it is an opening bracket, push it to the stack
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				brackets.push(s[i]);
			}
			// If it is a closing bracket and it matches the top of the stack,
			// pop the top bracket 
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (s[i] == ')' && !brackets.empty() && brackets.top() == '(' )
				{
					brackets.pop();
				}
				else if (s[i] == ']' && !brackets.empty() && brackets.top() == '[')
				{
					brackets.pop();
				}
				else if (s[i] == '}' && !brackets.empty() && brackets.top() == '{')
				{
					brackets.pop();
				}
				else
					return false;
			}
			// If it is an unrecognized character, return false
			else
				return false;
		}

		// Check if stack is empty
		if (brackets.empty())
			return true;
		else
			return false;
	}
};


int main()
{
	Solution solution;
	std::string input = "]";
	bool result;

	result = solution.isValid(input);
	std::cout << input << std::endl;
	if (result)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}