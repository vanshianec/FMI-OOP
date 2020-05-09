#include <iostream>
#include <vector>


struct ChessPosition
{
	int row, col;
};

class ChessPiece
{
private:
	ChessPosition position;

public:
	ChessPiece(const int row, const int col)
	{
		position.row = row;
		position.col = col;
	}

	ChessPosition getPosition()
	{
		return position;
	}

	virtual std::vector<ChessPosition> allowedMoves() = 0;

	bool wins(const ChessPosition& pos)
	{
		std::vector<ChessPosition> moves = allowedMoves();
		for (size_t i = 0; i < moves.size(); i++)
		{
			if (moves[i].row == pos.row && moves[i].col == pos.col)
			{
				return true;
			}
		}
		return false;
	}
};

class Knight : public ChessPiece
{
public:

	Knight(const int row, const int col) : ChessPiece::ChessPiece(row, col) {}

	std::vector<ChessPosition> allowedMoves()
	{
		std::vector<ChessPosition> allowedMoves;
		int row = getPosition().row;
		int col = getPosition().col;

		ChessPosition pos;

		if (row + 2 <= 7 && col + 1 <= 7)
		{
			pos.row = row + 2;
			pos.col = col + 1;
			allowedMoves.push_back(pos);
		}
		if (row + 2 <= 7 && col - 1 >= 0)
		{
			pos.row = row + 2;
			pos.col = col - 1;
			allowedMoves.push_back(pos);
		}
		if (row + 1 <= 7 && col + 2 <= 7)
		{
			pos.row = row + 1;
			pos.col = col + 2;
			allowedMoves.push_back(pos);
		}
		if (row + 1 <= 7 && col - 2 >= 0)
		{
			pos.row = row + 1;
			pos.col = col - 2;
			allowedMoves.push_back(pos);
		}
		if (row - 2 >= 0 && col + 1 <= 7)
		{
			pos.row = row - 2;
			pos.col = col + 1;
			allowedMoves.push_back(pos);
		}
		if (row - 2 >= 0 && col - 1 >= 0)
		{
			pos.row = row - 2;
			pos.col = col - 1;
			allowedMoves.push_back(pos);
		}
		if (row - 1 >= 0 && col + 2 <= 7)
		{
			pos.row = row - 1;
			pos.col = col + 2;
			allowedMoves.push_back(pos);
		}
		if (row - 1 >= 0 && col - 2 >= 0)
		{
			pos.row = row - 1;
			pos.col = col - 2;
			allowedMoves.push_back(pos);
		}

		return allowedMoves;
	}
};

class Rook : public ChessPiece
{
public:
	Rook(const int row, const int col) : ChessPiece::ChessPiece(row, col) {}

	std::vector<ChessPosition> allowedMoves()
	{
		std::vector<ChessPosition> allowedMoves;
		int row = getPosition().row;
		int col = getPosition().col;

		ChessPosition pos;
		pos.row = row;
		pos.col = col;

		for (size_t i = row + 1; i < 8; i++)
		{
			pos.row = i;
			allowedMoves.push_back(pos);
		}

		pos.row = row;

		for (int i = row - 1; i >= 0; i--)
		{
			pos.row = i;
			allowedMoves.push_back(pos);
		}

		pos.row = row;

		for (size_t i = col + 1; i < 8; i++)
		{
			pos.col = i;
			allowedMoves.push_back(pos);
		}

		pos.col = col;

		for (int i = col - 1; i >= 0; i--)
		{
			pos.col = i;
			allowedMoves.push_back(pos);
		}

		return allowedMoves;
	}
};

int main()
{
	ChessPiece* knight = new Knight(3, 3);

	std::vector<ChessPosition> moves = knight->allowedMoves();

	for (size_t i = 0; i < moves.size(); i++)
	{
		std::cout << moves[i].row << " " << moves[i].col << std::endl;
	}

	std::cout << std::endl;

	ChessPiece* rook = new Rook(3, 3);

	moves = rook->allowedMoves();

	for (size_t i = 0; i < moves.size(); i++)
	{
		std::cout << moves[i].row << " " << moves[i].col << std::endl;
	}

	delete knight;
	delete rook;
	return 0;
}