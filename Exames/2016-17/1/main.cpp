/*
Exercício 1 do exame de 2016/17
Alínea a) - main()
Alínea b) - simplify()
Alínea c) - (A), (B), (C)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//(A)
#include <map>
//
using namespace std;

//Alínea b)
//Escrever o código da função simplify
void simplify(const string &name, string &sName)
{
	vector<string> name_vec, simplified_names;
	string temp = "";
	for (size_t i = 0; i < name.length(); i++)
	{
		if (name[i] == ' ' && temp.length() > 0)
		{
			name_vec.push_back(temp);
			temp = "";
		}
		else
			temp += name[i];
	}
	name_vec.push_back(temp);
	if (name_vec.size() != 1)
		sName = name_vec[0] + " " + name_vec[name_vec.size() - 1];
	else
		sName = name_vec[0] + " aaaaa";
	name_vec.clear();
}

//Alínea a)
//Escrever o programa considerando que a função simplify é fornecida.
int main()
{
//(B)
	multimap<string, string> simplified_names;
	string first, last, name;
//
	string full_name, simplified_name;
	ifstream names("people1.txt");
	if (!names.is_open())
	{
		cout << "people1.txt not found";
		return 1;
	}
	ofstream simplified("people2.txt");

	while (getline(names, full_name))
	{
		simplify(full_name, simplified_name);
//(C)	
		//simplified << simplified_name << endl;
		for (size_t i = 0; i < simplified_name.length(); i++)
			if (simplified_name[i] == ' ')
			{
				first = simplified_name.substr(0, i);
				last = simplified_name.substr(i + 1, simplified_name.length());
			}
		simplified_names.insert(pair <string, string>(first, last));
	}

	for (auto name : simplified_names)
	{
		if (name.second != "aaaaa")
			simplified << name.first << " " << name.second << endl;
		else
			simplified << name.first << endl;
	}
//

	return 0;
}