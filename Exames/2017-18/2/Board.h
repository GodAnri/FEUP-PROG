#pragma once

#include <vector>
#include "Ship.h"

class Board {
public:
	Board(size_t numLines = 10, size_t numColumns = 10);
	bool putShip(const Ship &s); //add ship to board, if possible
	// ... OTHER METHODS
private:
	bool canPutShip(Position pos, char dir, size_t size);
	size_t numLines, numColumns;
	vector<vector<int>> board; // each element = ship id or -1  
	vector<Ship> ships;
	// ... OTHER ATTRIBUTES AND/OR METHODS
};