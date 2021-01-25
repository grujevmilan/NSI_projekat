#include "Game.h"

#define GAMENUM 10

Game::Game()
{
	PrepareGame();
}


Game::~Game()
{
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

		std::tuple<string, string, int, int> result = make_tuple(players.first->Name(), players.second->Name(), players.first->Count(), players.second->Count());

		auto printResult = [result, matchCounter]() {
			string p1name = std::get<0>(result);
			string p2name = std::get<1>(result);
			int p1win = std::get<2>(result);
			int p2win = std::get<3>(result);
			cout << "RESULT: " << p1name <<"  "<< p1win <<":"<< p2win <<"  "<< p2name << endl;
			if (matchCounter == 9)
			{
				if (p1win > p2win)
					cout << p1name << " is WINNER!" << endl;
				else if (p1win < p2win)
					cout << p2name << " is WINNER!" << endl;
				else
					cout << "TIE" << endl;
			}
		};

		printResult();
	}
}
