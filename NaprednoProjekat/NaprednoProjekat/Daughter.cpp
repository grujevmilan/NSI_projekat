#include "Daughter.h"

Daughter::Daughter(int id, string name)
	:Person(id, name)
{
}

Daughter::~Daughter()
{
	cout << "Delete daughter " << Name << endl;
}

void Daughter::SayHello()
{
	cout << "Hello! I'm " << Name << endl;
	cout << "My ID: " << ID << endl;
	cout << "I'm daughter." << endl;
}

void Daughter::AddParent(weak_ptr<Parent> parent)
{
	if (parents.first.expired())
		parents.first = parent;
	else
		parents.second = parent;
}