#include "Parent.h"


Parent::Parent()
{
}

Parent::Parent(int id, string name)
	:Person(id, name)
{
}

Parent::~Parent()
{
	cout << "Delete parent " << Name << endl;
}

void Parent::AddChild(std::shared_ptr<Person> child)
{
	children.push_back(child);
}

void Parent::SayHello()
{
	cout << "Hello! I'm " << Name << endl;
	cout << "My ID: " << ID << endl;
	cout << "I'm parent." << endl;
}
