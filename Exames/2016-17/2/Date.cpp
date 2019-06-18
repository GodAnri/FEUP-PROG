#include "Date.h"

//Alínea a)
Date::Date(int y, int m, int d)
{
	this->y = y;
	this->m = m;
	this->d = d;
}

//Alínea b)
bool operator<(const Date& left, const Date& right)
{
	int date_left, date_right;
	date_left = left.y * 10000 + left.m * 100 + left.d;
	date_right = right.y * 10000 + right.m * 100 + right.d;
	if (date_left < date_right)
		return 1;
	return 0;
}

bool operator==(const Date& left, const Date& right)
{
	if (left.y == right.y && left.m == right.m && left.d == right.d)
		return 1;
	return 0;
}

istream & operator>>(istream & f, Date & date)
{
	char h1, h2;
	f >> date.y >> h1 >> date.m >> h2 >> date.d;
	if (date.d < 1 || date.m < 1 || date.y < 0 || h1 != '-' || h2 != '-')
	{
		runtime_error invDate("invalid Date");
		throw invDate;
	}
	return f;
}

ostream & operator<<(ostream & f, const Date & date)
{
	f << date.y << '-' << date.m << '-' << date.d;
	return f;
}