/*
Exercício 3 do exame de 2016/17

Alínea a) - Image.h (getPixel)
Alínea b) - Image.cpp (getRegion)
Alínea c) - multimap<Date,Image>
Alínea d) - main.cpp (main)
Alínea e) - Image.h (template <class T>)
*/

#include "Date.h"
#include "Image.h"
#include <fstream>
#include <map>

using namespace std;

//Alínea d)
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
