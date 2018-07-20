//	William Sullivan
//
//	From: https://leetcode.com/problems/number-of-lines-to-write-string/description/
//  We are to write the letters of a given string S, from left to right into lines.
//  Each line has maximum width 100 units, and if writing a letter would cause 
//  the width of the line to exceed 100 units, it is written on the next line.
//  We are given an array widths, an array where widths[0] is the width of 'a', 
//  widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.
//
//  Now answer two questions : how many lines have at least one character from S, and 
//  what is the width used by the last such line ? 
//  Return your answer as an integer list of length 2.
//
//  Example:
//  Input:
//  widths = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
//  S = "abcdefghijklmnopqrstuvwxyz"
//  Output : [3, 60]
//	Explanation :
//	  All letters have the same length of 10. To write all 26 letters,
//    we need two full lines and one line with 60 units.

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution 
{
public:
	vector<int> numberOfLines(vector<int>& widths, string S) 
	{
		// Max line size = 100

		int numOfLines = 1;
		int lineWidth = 0;

		// For each character in the string
		for (unsigned int i = 0; i < S.length(); i++)
		{
			// get the width of the character
			int charWidth = widths[S.at(i) - 'a'];
			// if it will fit
			if (lineWidth + charWidth <= 100)
			{
				// add it to the total width of the line
				lineWidth += charWidth;
			}
			else
			{
				// add it to a new line
				numOfLines++;
				lineWidth = charWidth;
			}
		}

		// return number of lines with at least one character
		// return last line length
		return { numOfLines, lineWidth };
	}
};


int main()
{
	Solution solution;
	vector<int> result;
	vector<int> widths = { 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	string charString = "abcdefghijklmnopqrstuvwxyz";

	result = solution.numberOfLines(widths, charString);

	cout << "Number of lines with a character: " << result[0] << endl;
	cout << "Width of last line:               " << result[1] << endl;

	return 0;
}