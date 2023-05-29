#include <string>
#include <iostream>
#include "BSFuncs.h"
#include <stdlib.h>



	void altMain();
	int BattlePlacer(int x, int y, bool orient, char board[10][10]);
	int CarrierPlacer(int x, int y, bool orient, char board[10][10]);
	int SubPlacer(int x, int y, bool orient, char board[10][10]);
	int DesPlacer(int x, int y, bool orient, char board[10][10]);
	int PBPlacer(int x, int y, bool orient, char board[10][10]);
	void arrShipMaster(char board[10][10], int retry, char hitBoard[10][10]);
	int validator(int loopIndex, char board[10][10]);
	bool Shooter(char hitBoard[10][10], char shipBoard[10][10]);
	int ShipCounter(char board[10][10]);

	typedef int (*bunkass)(int x, int y, bool orient, char board[10][10]);


int main()
{
	altMain();
	return 0;
}


int BattlePlacer(int x, int y, bool orient, char board[10][10])
{
	if (orient == 0)
	{
		if (((x - 2) | (x - 1) | (x)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 1;
		}
		else if (((x) | (x + 1)) > 10)
		{
			std::cout << "Invalid Placement\n";
				return 1;
		}
		else
		{
			board[x][y] = 'B';
			board[x - 1][y] = 'B';
			board[x + 1][y] = 'B';
			board[x - 2][y] = 'B';
			return 0;
		}
	}
	else
	{
		if (((y - 2) | (y - 1) | (y)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 1;
		}
		else if (((y) | (y + 1)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 1;
		}
		else
		{
			board[x][y] = 'B';
			board[x][y - 1] = 'B';
			board[x][y - 2] = 'B';
			board[x][y + 1] = 'B';
			return 0;
		}
	}
}

int CarrierPlacer(int x, int y, bool orient, char board[10][10])
{
	if (orient == 0)
	{
		if (((x - 2) | (x - 1) | (x)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 2;
		}
		else if (((x) | (x + 1) | (x + 2)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 2;
		}
		else
		{
			board[x][y] = 'C';
			board[x - 1][y] = 'C';
			board[x + 1][y] = 'C';
			board[x - 2][y] = 'C';
			board[x + 2][y] = 'C';
			return 0;
		}
	}
	else
	{
		if (((y - 2) | (y - 1) | (y)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 2;
		}
		else if (((y) | (y + 1) | (y + 2)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 2;
		}
		else
		{
			board[x][y] = 'C';
			board[x][y - 1] = 'C';
			board[x][y - 2] = 'C';
			board[x][y + 1] = 'C';
			board[x][y + 2] = 'C';
			return 0;
		}
	}
}

int SubPlacer(int x, int y, bool orient, char board[10][10])
{
	if (orient == 0)
	{
		if (( (x - 1) | (x)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 3;
		}
		else if (((x) | (x + 1)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 3;
		}
		else
		{
			board[x][y] = 'S';
			board[x - 1][y] = 'S';
			board[x + 1][y] = 'S';
			return 0;
		}
	}
	else
	{
		if (( (y - 1) | (y)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 3;
		}
		else if (((y) | (y + 1)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 3;
		}
		else
		{
			board[x][y] = 'S';
			board[x][y - 1] = 'S';
			board[x][y + 1] = 'S';
			return 0;
		}
	}
}

int DesPlacer(int x, int y, bool orient, char board[10][10])
{
	if (orient == 0)
	{
		if (((x - 1) | (x)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 4;
		}
		else if (((x) | (x + 1)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 4;
		}
		else
		{
			board[x][y] = 'D';
			board[x - 1][y] = 'D';
			board[x + 1][y] = 'D';
			return 0;
		}
	}
	else
	{
		if (((y - 1) | (y)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 4;
		}
		else if (((y) | (y + 1)) > 10)
		{
			std::cout << "Invalid Placement\n";
			return 4;
		}
		else
		{
			board[x][y] = 'D';
			board[x][y - 1] = 'D';
			board[x][y + 1] = 'D';
			return 0;
		}
	}
}

int PBPlacer(int x, int y, bool orient, char board[10][10])
{
	if (orient == 0)
	{
		if (((x - 1) | (x)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 5;
		}
		else
		{
			board[x][y] = 'P';
			board[x - 1][y] = 'P';
			return 0;
		}
	}
	else
	{
		if (((y - 1) | (y)) < 0)
		{
			std::cout << "Invalid Placement\n";
			return 5;
		}
		else
		{
			board[x][y] = 'P';
			board[x][y - 1] = 'P';
			return 0;
		}
	}
}


void altMain()
{
	bool PlayerTurn = 0;
	bool Player1Hit, Player2Hit;
	int P2SR = 1, P1SR = 1;
	char yn = 'n';
	char playerOneShips[10][10]
	{
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'}
	};
	char playerOneHits[10][10]
	{
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'}
	};
	char playerTwoShips[10][10]
	{
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'}
	};
	char playerTwoHits[10][10]
	{
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
		{'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'}
	};

	
	display(playerOneHits, playerOneShips);
	std::cout << "\n\n Player One place ships now." << std::endl;
	arrShipMaster(playerOneShips, 0, playerOneHits);
	display(playerOneHits, playerOneShips);
	std::cout << "\n\n\nFinal Board for Player One" << std::endl;
	std::cout << "Input \'y\' to continue to Player 2\n";
	while (yn != 'y')
	{
		std::cin >> yn;
	}
	system("clear");
	display(playerTwoHits, playerTwoShips);
	std::cout << "\n\n Player Two place ships now." << std::endl;
	arrShipMaster(playerTwoShips, 0, playerTwoHits);
	display(playerTwoHits, playerTwoShips);
	std::cout << "\n\n\n Final Board for Player Two" << std::endl;
	std::cout << "Input \'y\' to continue to gameplay\n";
	while (yn != 'y')
	{
		std::cin >> yn;
	}
	system("clear");

	if (PlayerTurn == 0)
	{
		std::cout << "Begin Player One Turn";
		Player1Hit = Shooter(playerOneHits, playerTwoShips);
		if (Player1Hit == true)
		{
			P2SR = ShipCounter(playerTwoShips);
			if (P2SR == 0)
			{
			system("clear");
			std::cout << "Player 1 Wins";
			}
		}
		else{}
		display(playerOneShips, playerOneHits);
		std::cout << "Input y to end turn\n";
		while (yn != 'y')
		{
			std::cin >> yn;
		}
		system("clear");
		PlayerTurn = 1;
	}
	else
	{
		std::cout << "Begin Player Two Turn";
		Player2Hit = Shooter(playerTwoHits, playerOneShips);
		if (Player2Hit == true)
		{
			P1SR = ShipCounter(playerOneShips);
			if (P1SR == 0)
			{
				system("clear");
				std::cout << "Player 2 Wins";
			}
		}
		else {}
		display(playerTwoShips, playerTwoHits);
		std::cout << "Input y to end turn\n";
		while (yn != 'y')
		{
			std::cin >> yn;
		}
		system("clear");
		PlayerTurn = 0;
	}

}

void arrShipMaster(char shipBoard[10][10], int retry, char hitBoard[10][10])
{

	int x = 0, y = 0;
	bool orient = 0;
	bunkass functions[]
	{
		BattlePlacer, CarrierPlacer, SubPlacer, DesPlacer, PBPlacer
	};
	std::string ships[5] = { "Battleship", "Carrier", "Submarine", "Destroyer", "Patrol Boat" };
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Where would you like your " << ships[i] << "? (Row/Column for ship center) \n";
		std::cin >> x;
		std::cin >> y;
		std::cout << "Horizontal (1) or Vertical (0) \n";
		std::cin >> orient;
		retry = functions[i](x-1, y-1, orient, shipBoard);
		if (retry != 0)
		{
			validator(retry, shipBoard);
		}
		else
		{
			display(hitBoard, shipBoard);
		}
	}
}
int validator(int loopIndex, char board[10][10])
{
	int x = 0, y = 0;
	bool orient = 0;
	bunkass functions[]
	{
		BattlePlacer, CarrierPlacer, SubPlacer, DesPlacer, PBPlacer
	};
	std::string ships[5] = { "Battleship", "Carrier", "Submarine", "Destroyer", "Patrol Boat" };
	std::cout << "Where would you like your " << ships[loopIndex - 1] << "? (Row/Column for ship center)\n";
	std::cin >> x;
	std::cin >> y;
	std::cout << "Horizontal (1) or Vertical (0)\n";
	std::cin >> orient;
	loopIndex = functions[loopIndex - 1](x - 1, y - 1, orient, board);
	if (loopIndex != 0)
	{
		validator(loopIndex, board);
	}
	return 0;
}
bool Shooter(char hitBoard[10][10], char shipBoard[10][10])
{
	int x = 0, y = 0;
	std::cout << "Where would you like to fire?\n";
	std::cin >> x; std::cin >> y;
	if (shipBoard[x][y] == 'X')
	{
		std::cout << "Previous Hit";
		return false;
	}
	else if (shipBoard[x][y] == 'O')
	{
		std::cout << "Previous Miss";
		return false;
	}
	else if (shipBoard[x][y] != '?')
	{
		std::cout << "Hit!";
		shipBoard[x][y] = 'X'; hitBoard[x][y] = 'X';
		return true;
	}
	else
	{
		std::cout << "Miss!";
		shipBoard[x][y] = 'X'; hitBoard[x][y] = 'O';
		return false;
	}
}
int ShipCounter(char board[10][10])
{
	int carParts = 0, batParts = 0, desParts = 0, subParts = 0, PBParts = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 'C')
			{
				carParts++;
			}
			else if (board[i][j] == 'B')
			{
				batParts++;
			}
			else if (board[i][j] == 'S')
			{
				subParts++;
			}
			else if (board[i][j] == 'D')
			{
				desParts++;
			}
			else if (board[i][j] == 'P')
			{
				PBParts++;
			}
		}
	}
	if (carParts == 0)
	{
		std::cout << "Carrier Sunk";
	}
	else if (batParts == 0)
	{
		std::cout << "Battleship Sunk!";
	}
	else if (desParts == 0)
	{
		std::cout << "Destroyer Sunk!";
	}
	else if (subParts == 0)
	{
		std::cout << "Submarine Sunk!";
	}
	else if (PBParts == 0)
	{
		std::cout << "Patrol Boat Sunk!";
	}
	return carParts + batParts + desParts + subParts + PBParts;
}


