#pragma once

#include "TicTacToe.h"
#include <iostream>

//Game implementation 

//Constructor to initialize the board 
TicTacToe::TicTacToe() : m_currentPlayer(0)
{
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = '1' + i;
	}
}

//Function ovverides when the play has won or the board is full 
bool TicTacToe::IsGameOver() const
{
	//Check winner for - horizontal
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ')
	{
		std::cout << "Player" << m_board[0] << " WINNER!" << std::endl;
		return true;
	}
	else if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ')
	{
		std::cout << "Player" << m_board[3] << " WINNER!" << std::endl;
		return true;
	}
	else if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ')
	{
		std::cout << "Player" << m_board[6] << " WINNER!" << std::endl;
		return true;
	}

	//Check winner for - vertical
	if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ')
	{
		std::cout << "Player" << m_board[0] << " WINNER!" << std::endl;
		return true;
	}
	else if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ')
	{ 
		std::cout << "Player" << m_board[1] << " WINNER!" << std::endl;
		return true;
	}
	else if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ')
	{
		std::cout << "Player" << m_board[2] << " WINNER!" << std::endl;
		return true;
	}

	//Check winner for - diagonial wins
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ')
	{
		std::cout << "Player" << m_board[0] << " WINNER!" << std::endl;
		return true;
	}
	else if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' ')
	{
		std::cout << "Player" << m_board[2] << " WINNER!" << std::endl;
		return true;
	}

	//If the whole board is filled and no winner - it's a tie
	bool wholeBoard = true;
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] != 'X' && m_board[i] != 'O')
		{
			wholeBoard = false;
			break;
		}
	}

	//// Only checking if the first cell is filled.
	//bool wholeBoard = true;
	//for (int i = 0; i < 9; i++)
	//{
	//	if (m_board[i] != 'X' && m_board[i] != 'O')
	//		wholeBoard = false;
	//	break;
	//}
	if (wholeBoard)
	{
		std::cout << "It's a tie!" << std::endl;
		return true;
	}
	return false;
}

//Display the game to the console window 
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
	char key;

	do
	{
		char Player = (m_currentPlayer % 2 == 0) ? 'X' : 'O';
		std::cout << "Player " << Player << " 's turn. Enter a spot to place a marker (1-9): ";
		std::cin >> number;

		//Verify that the input is valid  
		if (number < 1 || number > 9 || m_board[number - 1] == 'X' || m_board[number - 1] == 'O')
		{
			std::cout << "Invalid move! Choose a empty spot between 1 and 9." << '\n';
		}
		else
		{
			m_board[number - 1] = Player;
			break;
		}
	}
	while (true);

	m_currentPlayer++;

	
}

