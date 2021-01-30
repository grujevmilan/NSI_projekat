#include <iostream>
#include <bitset>

#include "Game.h"

using namespace std;

void foo(int)
{
	cout << "info: call foo(int)" << endl;
}

void foo(char*)
{
	cout << "info: call foo(char*)" << endl;
}


void CandleSwitching() //bitset
{
	/*If the observed candle is let then states of this candle and all candles before it are changed to the opposite.*/
	constexpr int NumberOfCandles = 5;
	bitset<NumberOfCandles> Candles;
	Candles.set();
	cout << "Candles before:" << Candles.to_string() << endl;
	int counter = 0;
	for (int i = NumberOfCandles - 1; i >= 0; i--)
	{
		if (Candles[i] == 1)
			counter++;
		if (counter % 2 == 1)
			Candles.flip(i);
	}
	cout << "Candles after: " << Candles.to_string() << endl;
}

constexpr int fibonacci(const int n)
{
	return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int foo()
{
	return 10;
}


int main()
{
	//foo(NULL);
	//foo(nullptr);

	int niz1[fibonacci(5)];
	//float niz2[foo()];

	//CandleSwitching();

	{
		std::unique_ptr<Game> game = make_unique<Game>();
		game->PlayGame();
	}

	system("pause");
}