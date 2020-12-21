#include "Person.h"

Person::Person()
{
}

Person::Person(int id)
{
	ID = id;
}

Person::Person(int id, string name)
	:Person(id)
{
	Name = name;
}

Person::~Person()
{
	cout << "Delete person "<< Name << endl;
}

void Person::SayHello()
{

}