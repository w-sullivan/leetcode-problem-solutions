//	William Sullivan
//
// From: https://leetcode.com/problems/unique-morse-code-words/description/
//
// [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
// Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.
// For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-").
// We'll call such a concatenation, the transformation of a word.
// Return the number of different transformations among all words we have.

// The length of words will be at most 100.
// Each words[i] will have length in range[1, 12].
// words[i] will only consist of lowercase letters.

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
private:
	map<char, string> morseMap;

	string toMorseCode(string word)
	{
		string morseWord = "";

		for (unsigned int i = 0; i < word.size(); i++)
		{
			morseWord += morseMap[word.at(i)];
		}

		return morseWord;
	}
public:
	Solution()
	{
		morseMap['a'] = ".-";
		morseMap['b'] = "-...";
		morseMap['c'] = "-.-.";
		morseMap['d'] = "-..";
		morseMap['e'] = ".";
		morseMap['f'] = "..-.";
		morseMap['g'] = "--.";
		morseMap['h'] = "....";
		morseMap['i'] = "..";
		morseMap['j'] = ".---";
		morseMap['k'] = "-.-";
		morseMap['l'] = ".-..";
		morseMap['m'] = "--";
		morseMap['n'] = "-.";
		morseMap['o'] = "---";
		morseMap['p'] = ".--.";
		morseMap['q'] = "--.-";
		morseMap['r'] = ".-.";
		morseMap['s'] = "...";
		morseMap['t'] = "-";
		morseMap['u'] = "..-";
		morseMap['v'] = "...-";
		morseMap['w'] = ".--";
		morseMap['x'] = "-..-";
		morseMap['y'] = "-.--";
		morseMap['z'] = "--..";
	}

	int uniqueMorseRepresentations(vector<string>& words) 
	{
		vector<string> uniqueWords;

		// For each word in the Words array
		for(int i = 0; i < words.size(); i++)
		{
			string morseWord = toMorseCode(words[i]);
			// check if morse word is in the unique array
			bool found = false;
			for (int j = 0; j < uniqueWords.size() && found == false; j++)
			{
				if (morseWord == uniqueWords[j])
				{
					found = true;
				}
			}
			if (!found)  // if not found add it to the list of unique words
			{
				uniqueWords.push_back(morseWord);
			}
		}
		// Return how many unique words found
		return (int)uniqueWords.size();
	}
};

int main()
{
	Solution solution;

	vector<string> words = { "gin", "zen", "gig", "msg" };


	cout << solution.uniqueMorseRepresentations(words) << endl;
}