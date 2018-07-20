//	William Sullivan
//
//	From: https://leetcode.com/problems/subdomain-visit-count/description/
//
//  A website domain like "discuss.leetcode.com" consists of various subdomains.At the top level,
//  we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com".
//  When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
//
//  Now, call a "count-paired domain" to be a count(representing the number of visits this domain received), followed by a space,
//  followed by the address.An example of a count - paired domain might be "9001 discuss.leetcode.com".
//  
//  We are given a list cpdomains of count - paired domains.We would like a list of count - paired domains, 
//  (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
//
//  Example 2:
//  Input:
//  ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
//  Output :
//	["901 mail.com", "50 yahoo.com", "900 google.mail.com", "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"]
//	   Explanation :
//		   We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times.For the subdomains, 
//		   we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.


#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<string> subdomainVisits(vector<string>& cpdomains)
	{
		vector<string> result;
		map<string, int> subMap;

		//for each domain in cpdomains
		for (unsigned int i = 0; i < cpdomains.size(); i++)
		{
			// get number of visits
			int white_space = cpdomains[i].find(' ', 0);
			int visits = stoi(cpdomains[i].substr(0, white_space));

			// get the domain
			string subdomain = cpdomains[i].substr(white_space + 1, cpdomains[i].size() - 1);

			// Add info to the map of sub domains
			while (subdomain != "")
			{
				// if the domain doesnt exist in maps
				if (subMap.count(subdomain) == 0)
				{
					// add the domain to the map and number of visits
					subMap[subdomain] = visits;
				}
				else
				{
					subMap[subdomain] += visits;
				}

				// cut off the first bit
				if ( subdomain.find_first_of('.') != string::npos )
				{
					subdomain = subdomain.substr(subdomain.find_first_of('.') + 1, subdomain.size());
				}
				else
				{
					subdomain = "";
				}
			}
		}

		// for each mapped subdomain and visits
		for (map<string, int>::iterator  i = subMap.begin(); i != subMap.end(); i++)
		{	
			// add both to a string and push back to vector result
			string entry = to_string(i->second) + " " + i->first;
			result.push_back(entry);
		}

		return result;
	}
};

int main()
{
	Solution solution;
	vector<string> input = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	vector<string> result;

	result = solution.subdomainVisits(input);

	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}


	return 0;
}