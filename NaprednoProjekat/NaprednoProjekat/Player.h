#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include "Table.h"

using namespace std;

class Player
{
	string name;
	bitset<10> score;
	std::shared_ptr<Table> table;
public:
	Player();
	Player(string); //delegate constructor
	Player(const Player& player) = delete;
	~Player();
	void EnterMove(char);
	void SetScore(int, bool);

	inline decltype(auto) GetCount() { return score.count(); };

	std::tuple<string, int> GetPlayerInfo();

	void AssignTable(shared_ptr<Table> t); //smart pointer
};

