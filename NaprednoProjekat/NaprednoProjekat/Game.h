#pragma once

#include "Table.h"
#include "Player.h"
#include <iostream>
#include <bitset>

using namespace std;

class Game
{
	std::shared_ptr<Table> table; //smart pointer
	std::pair<std::shared_ptr<Player>, std::shared_ptr<Player>> players; //std::pair
public:
	Game();
	~Game();
	void PlayGame();
	void PrepareGame();
};

