#include "Player.h"


Player::Player()
{
	name = "John Doe";
	score.reset();
}


Player::Player(string n)
	:Player()
{
	name = n;
}


Player::~Player()
{
	cout << "Delete player " << name << endl;
}

void Player::AssignTable(shared_ptr<Table> t)
{
	table = t;
}

void Player::EnterMove(char c)
{
	cout << "Enter your move (row , column)" << endl;
	int row, column;
	cin >> row >> column;
	table->DoMove(row, column, c);
}

void Player::SetScore(int gameNumber, bool flag)
{
	if (flag)
		score.set(gameNumber);
	else
		score.reset(gameNumber);
}

int Player::Count()
{
	return score.count();
}
