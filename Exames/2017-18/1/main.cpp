#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//Alínea a)
void toUpperStr(string &s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = toupper(s[i]);
}

string transformLine(const string &s)
{
	string result;
	char ch;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isalpha(s[i]))
		{
			ch = ' ';
			result += ch;
		}
		else
		{
			result += s[i];
		}
	}
	toUpperStr(result);
	return result;
}

void decomposeLine(string line, vector<string> &words)
{
	stringstream ss;
	line = transformLine(line);
	ss << line;
	line = "";
	while (ss >> line)
	{
		words.push_back(line);
	}
}

int main()
{
	ifstream texttxt("C:\\docs\\text.txt");
	ofstream wordstxt("words.txt");
	vector <string> words;
	string line, previous;
	while (getline(texttxt, line))
	{
		decomposeLine(line, words);
	}
	sort(words.begin(), words.end());
	for (string s : words)
	{
		if (previous != s)				//Alínea e)
			wordstxt << s << endl;
		previous = s;					//Alínea e)
	}
	return 0;
}