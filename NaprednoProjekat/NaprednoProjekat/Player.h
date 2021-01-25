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
	void EnterMove(char);
	inline string Name() { return name; };
	void SetScore(int, bool);
	int Count();
	~Player();
	void AssignTable(shared_ptr<Table> t); //smart pointer
};

