#pragma once

#include <iostream>
#include <array>
#include <bitset>

#define DIMENSION 3
using namespace std;

class Table
{
	std::array<array<char, DIMENSION>, DIMENSION> tableFields; //array
public:
	Table();
	~Table();
	void InitializeTable();
	char CheckWin();
	void DoMove(int, int, char); //array
	void PrintTable(); //range-based for loop 

};

