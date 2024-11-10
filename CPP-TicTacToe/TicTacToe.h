#pragma once 

#include "Game.h"

class TicTacToe : public Game
{

private:
	//Fields
	char m_board[9]; //Allow the game board for 9 positions 
	int m_currentPlayer;

public:
	TicTacToe();

	//Check if the game is over
	virtual bool IsGameOver() const override;

	//Allows the player to take turn
	virtual void TakeTurn() override;

	//Display the score
	virtual void Display() const override;

};