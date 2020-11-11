#include "Compulsory 3.h"

void Battleship::makeEmptyBoard()
{
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			board[x][y] = BLANK;
		}
	}
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			playerBoard[x][y] = BLANK;
		}
	}
}
void Battleship::makeBoard(int numberOfShips)
{
	remainingShips = 0;
	numberOfHits = 0;
	int x;
	int y;
	for (int i = 0; i < numberOfShips; i++)
	{
	Retry:
		y = randomRow();
		x = randomColumn();
		if (board[x][y] == SHIP)
		{
			goto Retry;
		}
		board[x][y] = SHIP;
		remainingShips++;
	}
}
void Battleship::printBoard()
{
	system("CLS");
	for (int y = 0; y < M; y++)
	{
		std::cout << y + 1 << " ";
		for (int x = 0; x < N; x++)
		{
			std::cout << "|" << board[x][y];
		}
		std::cout << "|\n";
	}
	writeLetters();
}
void Battleship::printPlayerBoard()
{
	system("CLS");
	for (int y = 0; y < M; y++)
	{
		std::cout << y + 1 << " ";
		for (int x = 0; x < N; x++)
		{
			std::cout << "|" << playerBoard[x][y];
		}
		std::cout << "|\n";
	}
	writeLetters();

	std::cout << "Ammo : " << numberOfShots << "\n";
	//std::cout << "Remaining Ships : " << remainingShips << "\n\n";
}
void Battleship::printGameBoard()
{

}
void Battleship::writeLetters()
{
	std::cout << "  -------------\n";
	std::cout << "  ";
		for (int i = 0; i < N; i++)
	{
		std::cout << "|" << (char)(65 + i);
	}
	std::cout << "|\n";
}
void Battleship::Shoot()
{
	int xCoord = 0;
	int yCoord = 0;

	std::cout << "Where would you like to shoot, Captain? \n";
	std::cout << "First select a letter, then select a number. I.E : B3\n" << "FIRE ON : ";
	//std::string targetCoord;
retry:
	char xVal;
	std::cin >> xVal >> yCoord;
	
	xCoord = letterToNumber(toupper(xVal));
	yCoord--;
	if (xCoord < 0 || yCoord < 0 || yCoord > M-1 || xCoord > N-1)
	{
		std::cin.clear();
		std::cin.ignore(8000, '\n');
		std::cout << "We can't shoot there! : ";
		goto retry;
	}
	

	numberOfShots--;
	//Checks if what is on the coord, and that it has not already been hit.
	if (board[xCoord][yCoord] == SHIP && playerBoard[xCoord][yCoord] != HIT)
	{
		playerBoard[xCoord][yCoord] = HIT;
		remainingShips--;
		numberOfHits++;
	}
	else if (board[xCoord][yCoord] != SHIP)
	{ 
		playerBoard[xCoord][yCoord] = MISS;
	}
}
void Battleship::AIShoot()
{

}
void Battleship::MakeBoardThree( int numberOfShips)
{
	//Player Placement Loop
	int x = 0;
	do 
	{
		int rndCol = randomColumn();
		int rndRow = randomRow();

		if (AttemptToPlaceShip(playerShipBoard ,rndCol, rndRow, rand() & 1))
		{
			x++;
		}
	} while (x < numberOfShips);

	x = 0;
	//Computer placement loop
	do
	{
		int rndCol = randomColumn();
		int rndRow = randomRow();

		if (AttemptToPlaceShip(computerBoard, rndCol, rndRow, rand() & 1))
		{
			x++;
		}
	} while (x < numberOfShips);

}

//int Direction determines whether to check horizontal[0] or vertical[1]. 
bool Battleship::AttemptToPlaceShip(char boardarr[][N], int Column, int Row, int direction)
{ 
	if (direction == 0)
	{
		if ((Column - 1 >= 0 && boardarr[Column - 1][Row] != SHIP)
			&& (boardarr[Column][Row] != SHIP) && (boardarr[Column + 1][Row] != SHIP && Column + 1 < N))
		{
			boardarr[Column + 1][Row] = SHIP;
			boardarr[Column - 1][Row] = SHIP;
			boardarr[Column][Row] = SHIP;
			return true;
		}
		else
		{
			return false;
		}
	}
	if(direction == 1)
	{
		if ((Row-1 >= 0 && boardarr[Column][Row-1] != SHIP)
			&& (boardarr[Column][Row] != SHIP) && (boardarr[Column][Row+1] != SHIP && Row+1 < M))
		{
			boardarr[Column][Row + 1] = SHIP;
			boardarr[Column][Row - 1] = SHIP;
			boardarr[Column][Row] = SHIP;
			return true;
		}
		else
		{
			return false;
		}
	}         
	return false;
}