#include <iostream>
#include <bitset>
#include "Person.h"
#include "Parent.h"
#include "Son.h"
#include "Daughter.h"

#include "Game.h"

using namespace std;

//void foo(int)
//{
//	cout << "INFO: call foo(int)" << endl;
//}
//
//void foo(char*)
//{
//	cout << "INFO: call foo(char*)" << endl;
//}
//
//void friends()
//{
//	char ross[] = "Ross";
//	shared_ptr<Parent> Ross = make_shared<Parent>(5, ross);
//	Ross->SayHello();
//
//	char rachel[] = "Rachel";
//	shared_ptr<Parent> Rachel = make_shared<Parent>(28, rachel);
//	Rachel->SayHello();
//
//	char chandler[] = "Chandler";
//	shared_ptr<Son> Chandler = make_shared<Son>(2, chandler);
//	Chandler->SayHello();
//
//	char monica[] = "Monica";
//	shared_ptr<Daughter> Monica = make_shared<Daughter>(9, monica);
//	Monica->SayHello();
//
//	char joey[] = "Joey";
//	shared_ptr<Parent> Joey = make_shared<Parent>(17, joey);
//	Joey->SayHello();
//
//	char phoebe[] = "Phoebe";
//	shared_ptr<Daughter> Phoebe = make_shared<Daughter>(20, phoebe);
//	Phoebe->SayHello();
//
//	Ross->AddChild(Chandler);
//	Chandler->AddParent(Ross);
//	Rachel->AddChild(Monica);
//	Monica->AddParent(Ross);
//	Rachel->AddChild(Chandler);
//	Chandler->AddParent(Rachel);
//	Rachel->ShowChildren();
//	Rachel->ChildrenSort();
//	Rachel->ShowChildren();
//	Joey->AddChild(Phoebe);
//	Phoebe->AddParent(Joey);
//}

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

int foo()
{
	return 1;
}

int main()
{
	//CandleSwitching();

	std::unique_ptr<Game> game = make_unique<Game>();
	game->PlayGame();

	system("pause");
}