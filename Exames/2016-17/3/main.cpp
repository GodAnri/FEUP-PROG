/*
Exercício 3 do exame de 2016/17

Alínea a) - Image.h
Alínea b) - Image.cpp
Alínea c) - multimap<Date,Image>
*/

#include "Date.h"
#include "Image.h"
#include <fstream>
#include <map>

using namespace std;

int main()
{
	Image img;
	multimap<Date, Image> images;
	string line;
	Date date;
	try
	{
		cout << "Insert the date: ";
		cin >> date;
	}
	catch (runtime_error &invDate)
	{
		cerr << invDate.what();
		return 1;
	}
	cin.ignore(1000, '\n');
	cout << "Insert all the files (Enter after each, double Enter to end): ";
	do
	{
		getline(cin, line);
		img.read(line);
		images.insert(pair<Date,Image> (date,img));
	} while (line != "");
	return 0;
}