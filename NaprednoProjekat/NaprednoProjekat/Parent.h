#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;

class Parent final : public Person
{
	std::vector<std::shared_ptr<Person>> children;
public:
	Parent();
	Parent(int, string);
	~Parent();
	void AddChild(std::shared_ptr<Person>);
	void SayHello() override;
};

