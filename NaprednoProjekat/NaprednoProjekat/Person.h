#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	int ID;
	string Name;
public:
	Person();
	Person(int);
	Person(int, string); //delegate constructor
	virtual ~Person();
	virtual void SayHello();
};

