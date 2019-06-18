#pragma once
#include <iostream>

using namespace std;

class Date
{
	friend istream & operator>>(istream & f, Date & date);
	friend ostream & operator<<(ostream & f, const Date & date);
	friend bool operator<(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);
public:
	Date(int y = 1, int m = 1, int d = 1);
	// ... other methods
private:
	int y, m, d; // year, month, day
};