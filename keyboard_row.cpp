//	William Sullivan
// From: https://leetcode.com/problems/keyboard-row/description/
// Given a List of words, return the words that can be typed using letters of alphabet
// on only one row's of American keyboard.
//
// Example:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output : ["Alaska", "Dad"]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct letter_row
{
	char letter;
	int row;

	letter_row(char l, int r) { letter = l; row = r; }
};


class Solution 
{
private:
	vector<letter_row> letters;

	int binarySearch(int first, int last, char search_letter)
	{
		// If there is at least one element in searched area.
		if (last >= 1)
		{
			// Get midpoint
			int mid = (last + first) / 2;

			// Check if midpoint is the letter we need, if so return it.
			if (letters[mid].letter == search_letter)
			{
				return letters[mid].row;
			}

			// If the midpoint is larger than the searched for letter.
			if (letters[mid].letter > search_letter)
			{
				// split the search area in half at the midpoint and search the lower area.
				return binarySearch(first, mid - 1, search_letter);
			}

			// If the midpoint is snaller than the searched for letter.
			if (letters[mid].letter < search_letter)
			{
				// split the search area in half at the midpoint and search the upper area.
				return binarySearch(mid + 1, last, search_letter);
			}

		}

		// If not found return -1 (shouldn't happen)
		return -1;
	}

public:
	Solution()
	{
		letters.push_back(letter_row('a', 1));
		letters.push_back(letter_row('b', 2));
		letters.push_back(letter_row('c', 2));
		letters.push_back(letter_row('d', 1));
		letters.push_back(letter_row('e', 0));
		letters.push_back(letter_row('f', 1));
		letters.push_back(letter_row('g', 1));
		letters.push_back(letter_row('h', 1));
		letters.push_back(letter_row('i', 0));
		letters.push_back(letter_row('j', 1));
		letters.push_back(letter_row('k', 1));
		letters.push_back(letter_row('l', 1));
		letters.push_back(letter_row('m', 2));
		letters.push_back(letter_row('n', 2));
		letters.push_back(letter_row('o', 0));
		letters.push_back(letter_row('p', 0));
		letters.push_back(letter_row('q', 0));
		letters.push_back(letter_row('r', 0));
		letters.push_back(letter_row('s', 1));
		letters.push_back(letter_row('t', 0));
		letters.push_back(letter_row('u', 0));
		letters.push_back(letter_row('v', 2));
		letters.push_back(letter_row('w', 0));
		letters.push_back(letter_row('x', 2));
		letters.push_back(letter_row('y', 0));
		letters.push_back(letter_row('z', 2));
	}

	vector<string> findWords(vector<string>& words) 
	{
		vector<string> results;
		bool matched = true;

		// for each word in the words list
		for (unsigned int i = 0; i < words.size(); i++)
		{
			// get first characters keyboard location
			int first_char_location = getKeyboardLocation(words[i].at(0));

			matched = true;

			// while each letter in words[i] matches the first character's
			//   keyboard location or while its not the end of the word
			for (unsigned int j = 1; j < words[i].size() && matched == true; j++)
			{
				// find the letters keyboard location
				int next_char_location = getKeyboardLocation(words[i].at(j));

				if (next_char_location != first_char_location)
				{
					matched = false;
				}
			}

			// if all matched
			if (matched)
			{
				// push it to results
				results.push_back(words[i]);
			}
		}
			
		return results;
	}

	int getKeyboardLocation(char letter)
	{
		return binarySearch(0, letters.size() - 1, tolower(letter));
	}

};

int main()
{
	Solution solution;
	vector<string> input = { "Hello", "Alaska", "Dad", "Peace" };
	vector<string> output;

	output = solution.findWords(input);

	cout << "[ " << flush;
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " " << flush;
	}
	cout << "]" << endl;

	return 0;
}