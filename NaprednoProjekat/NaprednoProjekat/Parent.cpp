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

void Parent::ChildrenSort()
{
	auto PersonCompare = [](shared_ptr<Person> left, shared_ptr<Person> right) {return left->GetId() < right->GetId(); };
	sort(children.begin(), children.end(), PersonCompare);
}

void Parent::ShowChildren()
{
	SayHello();
	cout << "My children:" << endl;
	for (auto child : children)
		child->SayHello();
}
