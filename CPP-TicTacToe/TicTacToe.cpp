#pragma once

#include "TicTacToe.h"
#include <iostream>

//Game implementation

//Constructor to initialize or start the board
TicTacToe::TicTacToe() : m_Player(0)
{
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = '1' + i;
	}
}

//Function ovverides when the player has won or the board is full 
bool TicTacToe::IsGameOver() const
{
	//Check winner for - horizontal win
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ')
	{
		std::cout << "Player " << m_board[0] << " is the winner!" << std::endl;
		return true;
	}
	else if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ')
	{
		std::cout << "Player " << m_board[3] << " is the winner!" << std::endl;
		return true;
	}
	else if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ')
	{
		std::cout << "Player " << m_board[6] << " is the winner!" << std::endl;
		return true;
	}

	//Check winner for - vertical win
	if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ')
	{
		std::cout << "Player " << m_board[0] << " is the winner!" << std::endl;
		return true;
	}
	else if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ')
	{ 
		std::cout << "Player " << m_board[1] << " is the winner!" << std::endl;
		return true;
	}
	else if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ')
	{
		std::cout << "Player " << m_board[2] << " is the winner!" << std::endl;
		return true;
	}

	//Check winner for - diagonal win
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ')
	{
		std::cout << "Player " << m_board[0] << " is the winner!" << std::endl;
		return true;
	}
	else if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' ')
	{
		std::cout << "Player " << m_board[2] << " is the winner!" << std::endl;
		return true;
	}

	//If the whole board is filled and no winner - Tie record
	bool wholeBoard = true;
	for (int i = 0; i < 9; i++)
	{
		//If the position is not 'X' or 'O'
		if (m_board[i] != 'X' && m_board[i] != 'O')
		{
			wholeBoard = false;
			break;
		}
	}
	//If everything in the board is filled, display message "TIE"
	if (wholeBoard)
	{
		std::cout << "The score is a tie!" << std::endl;
		return true;
	}
	return false;
}

//Display the game to the console window - 3x3
void TicTacToe::Display() const
{
	std::cout << "Let's play Tic Tac Toe!" << '\n';
	std::cout << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << m_board[0] << "  |  " << m_board[1] << "  |  " << m_board[2] << "\n";
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << m_board[3] << "  |  " << m_board[4] << "  |  " << m_board[5] << "\n";
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << m_board[6] << "  |  " << m_board[7] << "  |  " << m_board[8] << "\n";
	std::cout << '\n';
}

//Allows the current player to take their turn (enter the position 1-9), prompt player to enter in valid position
void TicTacToe::TakeTurn()
{
	int number;
	do
	{
		//Display the character on the board as 'X' or 'O'
		char Player = (m_Player % 2 == 0) ? 'X' : 'O';

		//Display the player's turn and enter in a number
		std::cout << "Player " << Player << " 's turn. Enter a spot to place a marker (1-9): ";

		//Allow the player to type in the number value of 1-9
		std::cin >> number;

		//Verify that the input number is valid and within range of 1-9
		if (number < 1 || number > 9)
		{
			std::cout << "Invalid move! Please choose a empty spot between 1 and 9." << '\n';
		}
		//Verify that the spot selected is an open spot 
		else if (m_board[number - 1] == 'X' || m_board[number - 1] == 'O')
		{
			std::cout << "Spot is already choosen, please pick a different spot." << '\n';
		}
		else
		{
			//Place the player on the board
			m_board[number - 1] = Player;
			break; //End the loop
		}
	}
	while (true);

	//Allow the next player to play 
	m_Player++;

}

