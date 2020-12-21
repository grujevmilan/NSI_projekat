#include <iostream>
#include "Person.h"
#include "Parent.h"
#include "Son.h"
#include "Daughter.h"

using namespace std;

void foo(int)
{
	cout << "INFO: call foo(int)" << endl;
}

void foo(char*)
{
	cout << "INFO: call foo(char*)" << endl;
}

int main()
{
	//foo(nullptr);
	//foo(NULL);
	{
		char ross[] = "Ross";
		shared_ptr<Parent> Ross = make_shared<Parent>(5, ross);
		Ross->SayHello();

		char rachel[] = "Rachel";
		shared_ptr<Parent> Rachel = make_shared<Parent>(28, rachel);
		Rachel->SayHello();

		char chandler[] = "Chandler";
		shared_ptr<Son> Chandler = make_shared<Son>(2, chandler);
		Chandler->SayHello();

		char monica[] = "Monica";
		shared_ptr<Daughter> Monica = make_shared<Daughter>(9, monica);
		Monica->SayHello();

		Ross->AddChild(Chandler);
		Chandler->AddParent(Ross);
		Rachel->AddChild(Monica);
		Monica->AddParent(Ross);
		Monica->AddParent(Rachel);
	}
	system("pause");
}