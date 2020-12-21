#include "Son.h"



Son::Son(int id, string name)
	:Person(id, name)
{
}

Son::~Son()
{
	cout << "Delete son " << Name << endl;
}

void Son::SayHello()
{
	cout << "Hello! I'm " << Name << endl;
	cout << "My ID: " << ID << endl;
	cout << "I'm son." << endl;
}

void Son::AddParent(shared_ptr<Parent> parent)
{
	if (parents.first == nullptr)
		parents.first = parent;
	else
		parents.second = parent;
}