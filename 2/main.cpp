/*
Exercício 2 do exame de 2016/17
Alínea a) e b) - Date.cpp
Adicionei também as outras funções para ser possível correr o programa.
*/

#include <iostream>
#include "Date.h"

int main()
{
	Date date1, date2;
	try
	{
		cout << "Date 1 ? " << endl;
		cin >> date1;
		cout << "Date 2 ? " << endl;
		cin >> date2;
	}
	catch (runtime_error &err)
	{
		cerr << err.what();
		return 1;
	}
	if (date1 < date2)
		cout << date1 << " is before " << date2;
	else if (date1 == date2)
		cout << date1 << " is equal to " << date2;
	else
		cout << date1 << " is after " << date2;
	return 0;
}