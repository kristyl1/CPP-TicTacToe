#pragma once 

#include "Game.h"

class TicTacToe : public Game
{

private:
	//Fields
	char m_board[9]; //The position of the tictactoe board
	int m_Player; //Display the character - 0 for 'X' and 1 for '0'

public:
	//Constructor - Intialize the game
	TicTacToe();

	//Check if the game is over
	virtual bool IsGameOver() const;

	//Allows the player to take turn
	virtual void TakeTurn();

	//Display the score
	virtual void Display() const;

};