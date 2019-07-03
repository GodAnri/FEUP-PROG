#include "Board.h"

using namespace std;

//Alínea e)
int main()
{
	unsigned int id;
	char symbol;
	Position pos;
	char dir;
	size_t size;
	Board b(10,20);
	cout << "Insert the ship data: (Id, symbol, position, direction and size): ";
	cin >> id >> symbol >> pos.lin >> pos.col >> dir >> size;
	Ship s(id, symbol, pos, dir, size);
	if (!b.putShip(s))
		throw exception("Can't put ship");
	else
		b.putShip(s);
	return 0;
}