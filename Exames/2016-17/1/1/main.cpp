#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

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
		temp += name[i];
	}
	name_vec.push_back(temp);
	if (name_vec.size() != 1)
		sName = name_vec[0] + name_vec[name_vec.size() - 1];
	else
		sName = name_vec[0];
	name_vec.clear();
}

//Alínea a)
//Escrever o programa considerando que a função simplify é fornecida.
int main()
{
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
		simplified << simplified_name << endl;
	}

	return 0;
}