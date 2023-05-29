#pragma once
#include <iostream>
#include <string>

void display(char topBoard[10][10], char bottomBoard[10][10])
{
	std::cout << "\n\n\n\n\n" << "      1 2 3 4 5 6 7 8 9 10\n" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		bool hasB = false; //checks if x is 10 to make the board print on-line
		std::cout << " " << i + 1 << ":   ";
		for (int j = 0; j < 10; j++)
		{
			if (i == 9 && hasB == false)
			{
				std::cout << "\b";
				hasB = true;
			}
			std::cout << topBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "___________________________\n\n";
	for (int i = 0; i < 10; i++)
	{
		bool hasB = false;
		std::cout << " " << i + 1 << ":   ";
		for (int j = 0; j < 10; j++)
		{
			if (i == 9 && hasB == false)
			{
				std::cout << "\b";
				hasB = true;
			}
			std::cout << bottomBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
