#include "Board.h"

//Alínea b)
Board::Board(size_t numLines, size_t numColumns)
{
	vector<int> line;
	for (size_t x = 0; x < numLines; x++)
	{
		for (size_t y = 0; y < numColumns; y++)
			line.push_back(-1);
		board.push_back(line);
		line.clear();
	}
	this->numLines = numLines;
	this->numColumns = numColumns;
}

//Alínea c)
bool Board::canPutShip(Position pos, char dir, size_t size) {
	switch (dir)
	{
	case 'H':
		if (pos.col < 0 || pos.col + size >= numColumns || pos.lin < 0 || pos.lin >= numLines)
			return false;
		for (size_t i = pos.col; i < pos.col + size; i++)
			if (board[pos.lin][i] != -1)
				return false;
		break;
	case 'V':
		if (pos.col < 0 || pos.col >= numColumns || pos.lin < 0 || pos.lin + size >= numLines)
			return false;
		for (size_t i = pos.lin; i < pos.lin + size; i++)
			if (board[i][pos.col] != -1)
				return false;
		break;
	}
	return true;
}

//Alínea d)
bool Board::putShip(const Ship &s)
{
	if (!canPutShip(s.pos(), s.dir(), s.size()))
		return false;
	else
	{
		ships.push_back(s);
		switch (s.dir())
		{
		case 'H':
			for (size_t i = s.pos().col; i < s.pos().col + s.size(); i++)
				board[s.pos().lin][i] = s.id();
			return true;
		case 'V':
			for (size_t i = s.pos().lin; i < s.pos().lin + s.size(); i++)
				board[i][s.pos().col] = s.id();
			return true;
		}
	}
}