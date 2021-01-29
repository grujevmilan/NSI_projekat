#include "Table.h"


Table::Table()
{
	InitializeTable();
}


Table::~Table()
{
	cout << "Delete table" << endl;
}


void Table::InitializeTable()
{
	for (int i = 0; i < DIMENSION; i++)
		for (int j = 0; j < DIMENSION; j++)
			tableFields[i][j] = '-';
}


char Table::CheckWin()
{
  //rows
	bool win = true;
	char winner = '-';

	for(int i = 0; i< DIMENSION; i++)
	{
		winner = [fields = tableFields](int x) {
			return fields[x][0] & fields[x][1] & fields[x][2];
		}(i);
		if (winner == 'X' || winner == 'O')
			return winner;

		winner = [fields = tableFields](int x) {
			return fields[0][x] & fields[1][x] & fields[2][x];
		}(i);
		if (winner == 'X' || winner == 'O')
			return winner;
	}

	bool win_md = true;
	bool win_sd = true;
	winner = '-';

	for (int i = 0; i < DIMENSION - 1; i++)
	{
		if (tableFields[i][i] != tableFields[i + 1][i + 1])
			win_md = false;
		if (tableFields[i][DIMENSION - i - 1] != tableFields[i + 1][DIMENSION - i - 2])
			win_sd = false;
	}
	if (win_md == true || win_sd == true)
	{
		winner = tableFields[1][1];
		if (winner != '-')
			return winner;
	}
	return '-';
}

void Table::DoMove(int i, int j, char c)
{
	tableFields.at(i).at(j) = c;
}


void Table::PrintTable()
{
	cout << "TABLE:" << endl;
	cout << "   0 1 2" << endl;
	int i = 0;
	for (auto row = tableFields.begin(); row != tableFields.end(); ++row)
	{
		cout << " " << i++ << " ";
		for (auto cell : *row)
			cout << cell << " ";
		cout << endl;
	}
}
