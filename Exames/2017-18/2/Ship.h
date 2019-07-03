#pragma once

#include <iostream>

using namespace std;

struct Position {
	int lin, col;
};

class Ship {
public:
	Ship(unsigned int identifier, char symbol,
		Position position, char direction,
		size_t size);
	unsigned int id() const; //returns identifier
	Position pos() const; //returns position   
	char dir() const;  //returns direction  
	size_t size() const; //returns size
	// ... OTHER METHODS
private:
	unsigned int identifier; // ship id number
	char symbol;
	Position position;
	char direction;
	size_t size_of_ship;
};