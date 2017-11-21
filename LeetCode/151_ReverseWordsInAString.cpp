Q: Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
============================================================

class Solution {
public:
	void reverseWords(string &s) {
		vector<string> strArray;

		string str = "";
		for (int i = 0; i < (int)s.length(); ++i)
		{
			if (s[i] != ' ')
			{
				str += s[i];
			}
			
			if (s[i] == ' ' || i == (int)s.length() - 1)
			{
				if (str != "")
				{
					strArray.push_back(str);
					str = "";
				}
			}
		}

		s = "";
		for (auto it = strArray.rbegin(); it != strArray.rend(); ++it)
		{
			s += *it;
			if (it != strArray.rend() - 1)
			{
				s += " ";
			}
		}
	}
};