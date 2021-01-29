#include "Game.h"

#define GAMENUM 10

Game::Game()
{
	PrepareGame();
}


Game::~Game()
{
	cout << "Delete game" << endl;
}


void Game::PrepareGame()
{
	table = make_shared<Table>();
	cout << "Enter name player 1:" << endl;
	string namePlayer;
	cin >> namePlayer;
	players.first = make_shared<Player>(namePlayer);
	cout << "Enter name player 2:" << endl;
	cin >> namePlayer;
	players.second = make_shared<Player>(namePlayer);
	
	players.first->AssignTable(table);
	players.second->AssignTable(table);
}

void Game::PlayGame()
{
	for (int matchCounter = 0; matchCounter < GAMENUM; matchCounter++)
	{
		table->InitializeTable();
		table->PrintTable();
		for (int moveCounter = 0; moveCounter < 9; moveCounter++)
		{
			if (matchCounter % 2 == 0 )
			{
				if (moveCounter % 2 == 0)
					players.first->EnterMove('X');
				else
					players.second->EnterMove('O');
			}
			else
			{
				if (moveCounter % 2 == 0)
					players.second->EnterMove('X');
				else
					players.first->EnterMove('O');
			}
			table->PrintTable();
			if (moveCounter > 3)
			{
				decltype(table->CheckWin()) winner = table->CheckWin();

				if (winner == 'X')
				{
					players.first->SetScore(matchCounter, (matchCounter % 2 == 0) ? true : false);
					players.second->SetScore(matchCounter, (matchCounter % 2 == 0) ? false : true);
					break;
				}
				if (winner == 'O')
				{
					players.first->SetScore(matchCounter, (matchCounter % 2 == 0) ? false : true);
					players.second->SetScore(matchCounter, (matchCounter % 2 == 0) ? true : false);
					break;
				}
				if (winner == '-' && moveCounter == 8)
				{
					players.first->SetScore(matchCounter, false);
					players.second->SetScore(matchCounter, false);
				}
			}
		}


		auto[player1Name, player1Score] = players.first->GetPlayerInfo();
		auto[player2Name, player2Score] = players.second->GetPlayerInfo();

		cout << "RESULT: " << player1Name << "  " << player1Score << ":" << player2Score<< "  " << player2Name<< endl;

		if (matchCounter == 9)
		{
			if (player1Score > player2Score)
				cout << player1Name << " is WINNER!" << endl;
			else if (player1Score < player2Score)
				cout << player2Score << " is WINNER!" << endl;
			else
				cout << "TIE" << endl;
		}

	}
}
